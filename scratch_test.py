import numpy as np

# Exact LUT from lut_inv_sqrt.sv
LUT_INV_SQRT = [
    0xA97E, 0xA738, 0xA508, 0xA2EE, 0xA0E8, 0x9EF5, 0x9D13, 0x9B42,
    0x9981, 0x97CF, 0x962B, 0x9494, 0x930A, 0x918C, 0x9019, 0x8EB1,
    0x8D53, 0x8C00, 0x8AB5, 0x8974, 0x883B, 0x870B, 0x85E2, 0x84C1,
    0x83A7, 0x8293, 0x8187, 0x8081, 0x7F81, 0x7E87, 0x7D92, 0x7CA3,
    0x7BB9, 0x7AD5, 0x79F5, 0x791A, 0x7843, 0x7771, 0x76A3, 0x75D9,
    0x7514, 0x7452, 0x7393, 0x72D9, 0x7221, 0x716E, 0x70BD, 0x7010,
    0x6F66, 0x6EBE, 0x6E1A, 0x6D78, 0x6CDA, 0x6C3D, 0x6BA4, 0x6B0D,
    0x6A78, 0x69E6, 0x6956, 0x68C9, 0x683E, 0x67B4, 0x672D, 0x66A8
]

def to_int16(v):
    v = v & 0xFFFF
    return v - 0x10000 if v >= 0x8000 else v

def q8_8_mul(a, b):
    # 16'((32'(a) * 32'(b)) >>> 8)
    res = (a * b) >> 8
    return to_int16(res)

def fixed_sqrt(radicand):
    if radicand <= 0:
        return 0
    # math_sqrt.sv Q8.8 non-restoring sqrt
    # radicand_ext = {radicand, 8'd0} -> 24 bits
    val = radicand << 8
    root = int(np.sqrt(val)) & 0xFFF
    return root # Q4.8 zero-extended to Q8.8

def ray_gen(drawX, drawY, interpolate=False):
    diff_x = drawX - 160
    diff_y = 120 - drawY

    u_val = to_int16((diff_x * 0x0222) >> 8)
    v_val = to_int16((diff_y * 0x0222) >> 8)

    dx = u_val
    dy = v_val
    dz = 0x0180 # 384 = 1.5

    sq_x = to_int16((dx * dx) >> 8)
    sq_y = to_int16((dy * dy) >> 8)
    sq_z = to_int16((dz * dz) >> 8)
    S = sq_x + sq_y + sq_z

    if S <= 576:
        lut_addr = 0
        frac = 0
    elif S >= 1584:
        lut_addr = 63
        frac = 0
    else:
        delta = S - 576
        lut_addr = delta >> 4
        frac = delta & 0xF

    if not interpolate:
        lut_out = LUT_INV_SQRT[lut_addr]
    else:
        v0 = LUT_INV_SQRT[lut_addr]
        v1 = LUT_INV_SQRT[lut_addr + 1] if lut_addr < 63 else LUT_INV_SQRT[63]
        lut_out = v0 - (((v0 - v1) * frac) >> 4)

    r_dx = to_int16((dx * lut_out) >> 16)
    r_dy = to_int16((dy * lut_out) >> 16)
    r_dz = to_int16((dz * lut_out) >> 16)
    return r_dx, r_dy, r_dz

def run_sim(interpolate_ray=False, bevel_mode=0, carve_z_in=0xFF26, carve_r_in=0x005A, filename="output.ppm"):
    W, H = 320, 240
    img = np.zeros((H, W, 3), dtype=np.uint8)

    carve_x = 0x005A
    carve_y = 0x005A
    carve_z = to_int16(carve_z_in)
    carve_radius = carve_r_in
    inv_carve_radius = 65536 // (carve_radius & 0xFF)

    origin_x = 0
    origin_y = 0
    origin_z = to_int16(0xFD80) # -640 = -2.5

    light_dir_x = 0x0080
    light_dir_y = 0x0099
    light_dir_z = to_int16(0xFF60)

    half_x = 0x0047
    half_y = 0x0055
    half_z = to_int16(0xFF19)

    for y in range(H):
        for x in range(W):
            rx, ry, rz = ray_gen(x, y, interpolate=interpolate_ray)

            ray_t = 0x0100 # 256 = 1.0
            hit = False
            is_carve = False
            blend_w = 0
            pos_x, pos_y, pos_z = 0, 0, 0

            for step in range(32): # test step limit
                pos_x = origin_x + to_int16((rx * ray_t) >> 8)
                pos_y = origin_y + to_int16((ry * ray_t) >> 8)
                pos_z = origin_z + to_int16((rz * ray_t) >> 8)

                # SDF sphere
                sq_x = to_int16((pos_x * pos_x) >> 8)
                sq_y = to_int16((pos_y * pos_y) >> 8)
                sq_z = to_int16((pos_z * pos_z) >> 8)
                dist_sphere = fixed_sqrt(sq_x + sq_y + sq_z) - 0x0100

                # SDF carve
                cd_x = pos_x - carve_x
                cd_y = pos_y - carve_y
                cd_z = pos_z - carve_z
                csq_x = to_int16((cd_x * cd_x) >> 8)
                csq_y = to_int16((cd_y * cd_y) >> 8)
                csq_z = to_int16((cd_z * cd_z) >> 8)
                dist_carve = fixed_sqrt(csq_x + csq_y + csq_z) - carve_radius

                d_diff = (-dist_carve) - dist_sphere
                d_rel = to_int16((d_diff * inv_carve_radius) >> 8)

                sdf_dist = dist_sphere if dist_sphere > -dist_carve else -dist_carve

                if sdf_dist < 5:
                    hit = True
                    is_carve = (-dist_carve >= dist_sphere)
                    if d_rel <= -0x0010:
                        blend_w = 0
                    elif d_rel >= 0x0030:
                        blend_w = 256
                    else:
                        blend_w = (d_rel + 0x0010) << 2
                    break
                elif ray_t > 0x0600 or step > 24:
                    hit = False
                    break
                else:
                    ray_t += sdf_dist

            if not hit:
                img[y, x] = [17, 17, 34] # 12'h112
            else:
                norm_sphere_x = pos_x
                norm_sphere_y = pos_y
                norm_sphere_z = pos_z

                norm_carve_x = to_int16(((carve_x - pos_x) * inv_carve_radius) >> 8)
                norm_carve_y = to_int16(((carve_y - pos_y) * inv_carve_radius) >> 8)
                norm_carve_z = to_int16(((carve_z - pos_z) * inv_carve_radius) >> 8)

                if bevel_mode == 0:
                    # Current HDL
                    norm_x = to_int16((norm_sphere_x * (256 - blend_w) + norm_carve_x * blend_w) >> 8)
                    norm_y = to_int16((norm_sphere_y * (256 - blend_w) + norm_carve_y * blend_w) >> 8)
                    norm_z = to_int16((norm_sphere_z * (256 - blend_w) + norm_carve_z * blend_w) >> 8)

                # Shading
                dot_product = to_int16((norm_x * light_dir_x + norm_y * light_dir_y + norm_z * light_dir_z) >> 8)
                half_dot = to_int16((norm_x * half_x + norm_y * half_y + norm_z * half_z) >> 8)

                if half_dot > 0:
                    s1 = half_dot
                    s2 = to_int16((s1 * s1) >> 8)
                    s4 = to_int16((s2 * s2) >> 8)
                    s8 = to_int16((s4 * s4) >> 8)
                else:
                    s8 = 0

                if dot_product > 0 and half_dot > 0:
                    specular = 15 if s8 >= 256 else (s8 >> 4)
                else:
                    specular = 0

                diffuse = 15 if dot_product >= 256 else ((dot_product >> 4) if dot_product > 0 else 0)

                r_add = 3 + diffuse
                r_base = 15 if r_add > 15 else r_add
                g_base = diffuse >> 2
                b_base = 0

                red = min(15, r_base + specular)
                green = min(15, g_base + specular)
                blue = min(15, b_base + specular)

                img[y, x] = [(red << 4) | red, (green << 4) | green, (blue << 4) | blue]

    with open(filename, "wb") as f:
        f.write(f"P6\n{W} {H}\n255\n".encode())
        f.write(img.tobytes())
    print(f"Saved {filename}")

if __name__ == "__main__":
    # Test current baseline with shallow carve (Q)
    run_sim(interpolate_ray=False, bevel_mode=0, carve_z_in=to_int16(0xFEA0), filename="sim_shallow.ppm")
    # Test current baseline with deep embedded carve (E)
    run_sim(interpolate_ray=False, bevel_mode=0, carve_z_in=to_int16(0xFF80), filename="sim_deep.ppm")
