// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim_top.h for the primary calling header

#ifndef VERILATED_VSIM_TOP___024ROOT_H_
#define VERILATED_VSIM_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vsim_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(keycode,7,0);
        VL_OUT8(fb_we,0,0);
        VL_OUT8(frame_done,0,0);
        VL_OUT8(carve_en,0,0);
        CData/*0:0*/ sim_top__DOT__carve_ctrl_inst__DOT__tick_dly;
        CData/*0:0*/ sim_top__DOT__carve_ctrl_inst__DOT__tick_pulse;
        CData/*2:0*/ sim_top__DOT__raymarch_inst__DOT__raymarch_state;
        CData/*7:0*/ sim_top__DOT__raymarch_inst__DOT__render_y;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__ray_in_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__ray_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_in_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__hit;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_valid;
        CData/*0:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(fb_din,11,0);
        VL_OUT16(carve_x,15,0);
        VL_OUT16(carve_y,15,0);
        VL_OUT16(carve_z,15,0);
        VL_OUT16(carve_radius,15,0);
        SData/*15:0*/ sim_top__DOT__inv_carve_radius;
        SData/*8:0*/ sim_top__DOT__raymarch_inst__DOT__render_x;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_dir_x;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_dir_y;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_dir_z;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__pos_x;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__pos_y;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__pos_z;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_dist;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_t;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__step_cnt;
        SData/*8:0*/ sim_top__DOT__raymarch_inst__DOT__blend_w_reg;
        SData/*11:0*/ sim_top__DOT__raymarch_inst__DOT__shaded_output;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__u_val;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__v_val;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_u;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_v;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__S;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dx;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dy;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dz;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_S;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__lut_out;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dx;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dy;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dz;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_D;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_D;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__d_diff;
        SData/*11:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        SData/*11:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s1;
    };
    struct {
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s2;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s4;
        SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s8;
        VL_OUT(fb_addr,16,0);
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        IData/*23:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
        IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        IData/*23:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<SData/*15:0*/, 256> sim_top__DOT__carve_ctrl_inst__DOT__inv_rom;
        VlUnpacked<CData/*0:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe;
        VlUnpacked<IData/*23:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe;
        VlUnpacked<SData/*11:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next;
        VlUnpacked<SData/*11:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe;
        VlUnpacked<IData/*23:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe;
        VlUnpacked<SData/*11:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val;
        VlUnpacked<IData/*25:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next;
        VlUnpacked<SData/*11:0*/, 12> sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsim_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsim_top___024root(Vsim_top__Syms* symsp, const char* v__name);
    ~Vsim_top___024root();
    VL_UNCOPYABLE(Vsim_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
