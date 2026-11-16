// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"
#include "Vsim_top___024root.h"

VL_ATTR_COLD void Vsim_top___024root___eval_static(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_static\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vsim_top___024root___eval_initial__TOP(Vsim_top___024root* vlSelf);

VL_ATTR_COLD void Vsim_top___024root___eval_initial(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_initial\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsim_top___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vsim_top___024root___eval_initial__TOP(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_initial__TOP\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i;
    sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__inv_rom[0U] = 0x7fffU;
    vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__inv_rom[1U] = 0x7fffU;
    vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__inv_rom[2U] = 0x7fffU;
    sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i = 3U;
    while (VL_GTS_III(32, 0x100U, sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__inv_rom[(0xffU 
                                                               & sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i)] 
            = (0xffffU & VL_DIV_III(32, (IData)(0x10000U), sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i));
        sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + sim_top__DOT__carve_ctrl_inst__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vsim_top___024root___eval_final(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_final\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__stl(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsim_top___024root___eval_phase__stl(Vsim_top___024root* vlSelf);

VL_ATTR_COLD void Vsim_top___024root___eval_settle(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_settle\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsim_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("sim_top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsim_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__stl(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__stl\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___stl_sequent__TOP__0(Vsim_top___024root* vlSelf);

VL_ATTR_COLD void Vsim_top___024root___eval_stl(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_stl\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vsim_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<SData/*15:0*/, 64> Vsim_top__ConstPool__TABLE_h061db8b3_0;

VL_ATTR_COLD void Vsim_top___024root___stl_sequent__TOP__0(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___stl_sequent__TOP__0\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_x;
    sim_top__DOT__raymarch_inst__DOT__norm_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_y;
    sim_top__DOT__raymarch_inst__DOT__norm_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_z;
    sim_top__DOT__raymarch_inst__DOT__norm_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_sphere_x;
    sim_top__DOT__raymarch_inst__DOT__norm_sphere_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_sphere_y;
    sim_top__DOT__raymarch_inst__DOT__norm_sphere_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_sphere_z;
    sim_top__DOT__raymarch_inst__DOT__norm_sphere_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_carve_x;
    sim_top__DOT__raymarch_inst__DOT__norm_carve_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_carve_y;
    sim_top__DOT__raymarch_inst__DOT__norm_carve_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__norm_carve_z;
    sim_top__DOT__raymarch_inst__DOT__norm_carve_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_x;
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_y;
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_x;
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_y;
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_z;
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_x;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_y;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_z;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_x;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_y;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_z;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_x;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_y;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_z;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_x;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_x = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_y;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_y = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_z;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_z = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_carve;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_carve = 0;
    IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 = 0;
    SData/*11:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 = 0;
    IData/*25:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 = 0;
    SData/*11:0*/ sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product = 0;
    SData/*15:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__half_dot_product;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__half_dot_product = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__diffuse;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__diffuse = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__specular;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__specular = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_base;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_base = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_base;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_base = 0;
    CData/*4:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_add;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_add = 0;
    CData/*4:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_sum;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_sum = 0;
    CData/*4:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_sum;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_sum = 0;
    CData/*4:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__b_sum;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__b_sum = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__red;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__red = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__green;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__green = 0;
    CData/*3:0*/ sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__blue;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__blue = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_x 
        = (0xffffU & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x) 
                      - (IData)(0xa0U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__u_val 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, (IData)(0x222U), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_x))), 8U));
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_y 
        = (0xffffU & ((IData)(0x78U) - (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__v_val 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, (IData)(0x222U), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__diff_y))), 8U));
    __Vtableidx1 = (0x3fU & (((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_S) 
                              - (IData)(0x240U)) >> 4U));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__lut_out 
        = Vsim_top__ConstPool__TABLE_h061db8b3_0[__Vtableidx1];
    vlSelfRef.frame_done = ((0x13fU == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x)) 
                            & ((0xefU == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y)) 
                               & (6U == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))));
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_x 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx)), 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx))), 8U));
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_y 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy)), 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy))), 8U));
    sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_z 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz)), 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz))), 8U));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__S 
        = (0xffffU & (((IData)(sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_x) 
                       + (IData)(sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_y)) 
                      + (IData)(sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__sq_z)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere 
        = (0xffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [0xbU] - (IData)(0x100U)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_carve 
        = (0xffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [0xbU] - (IData)(vlSelfRef.carve_radius)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_dist 
        = (0xffffU & ((IData)(vlSelfRef.carve_en) ? 
                      (VL_GTS_III(16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere), 
                                  (0xffffU & (- (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_carve))))
                        ? (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere)
                        : (- (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_carve)))
                       : (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_x 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_y 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_z 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_x 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_x)), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_x))), 8U));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_y 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_y)), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_y))), 8U));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_z 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_z)), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__diff_z))), 8U));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_D 
        = (0xffffU & (((IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_x) 
                       + (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_y)) 
                      + (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_z)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_x 
        = (0xffffU & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x) 
                      - (IData)(vlSelfRef.carve_x)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_y 
        = (0xffffU & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y) 
                      - (IData)(vlSelfRef.carve_y)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_z 
        = (0xffffU & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z) 
                      - (IData)(vlSelfRef.carve_z)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_x 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_x)), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_x))), 8U));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_y 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_y)), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_y))), 8U));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_z 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_z)), 
                                                          VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_diff_z))), 8U));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_D 
        = (0xffffU & (((IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_x) 
                       + (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_y)) 
                      + (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_z)));
    sim_top__DOT__raymarch_inst__DOT__norm_sphere_x 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x;
    sim_top__DOT__raymarch_inst__DOT__norm_carve_x 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          (VL_EXTENDS_II(32,16, (IData)(vlSelfRef.carve_x)) 
                                                           - 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x))), 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__inv_carve_radius))), 8U));
    sim_top__DOT__raymarch_inst__DOT__norm_x = (0xffffU 
                                                & (((VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_sphere_x)) 
                                                     * 
                                                     ((IData)(0x100U) 
                                                      - (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg))) 
                                                    + 
                                                    (VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_carve_x)) 
                                                     * (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg))) 
                                                   >> 8U));
    sim_top__DOT__raymarch_inst__DOT__norm_sphere_y 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y;
    sim_top__DOT__raymarch_inst__DOT__norm_carve_y 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          (VL_EXTENDS_II(32,16, (IData)(vlSelfRef.carve_y)) 
                                                           - 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y))), 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__inv_carve_radius))), 8U));
    sim_top__DOT__raymarch_inst__DOT__norm_y = (0xffffU 
                                                & (((VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_sphere_y)) 
                                                     * 
                                                     ((IData)(0x100U) 
                                                      - (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg))) 
                                                    + 
                                                    (VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_carve_y)) 
                                                     * (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg))) 
                                                   >> 8U));
    sim_top__DOT__raymarch_inst__DOT__norm_sphere_z 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z;
    sim_top__DOT__raymarch_inst__DOT__norm_carve_z 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                          (VL_EXTENDS_II(32,16, (IData)(vlSelfRef.carve_z)) 
                                                           - 
                                                           VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z))), 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__inv_carve_radius))), 8U));
    sim_top__DOT__raymarch_inst__DOT__norm_z = (0xffffU 
                                                & (((VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_sphere_z)) 
                                                     * 
                                                     ((IData)(0x100U) 
                                                      - (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg))) 
                                                    + 
                                                    (VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_carve_z)) 
                                                     * (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg))) 
                                                   >> 8U));
    vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__tick_pulse 
        = ((~ (IData)(vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__tick_dly)) 
           & (IData)(vlSelfRef.frame_done));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__d_diff 
        = (0xffffU & ((- (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_carve)) 
                      - (IData)(sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__dist_sphere)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[0U] 
        = (3U & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_D) 
                 >> 0xeU));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[0U] = 1U;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[0U] 
        = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                         [0U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                         [0U]));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[0U] 
        = (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                    [0U] >> 0x19U)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [0U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [0U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[1U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [0U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [0U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [1U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [1U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [0U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [1U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [1U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [0U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [1U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[1U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [1U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [1U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[2U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [1U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [1U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [2U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [2U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [1U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [2U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [2U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [1U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [2U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[2U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [2U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [2U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[3U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [2U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [2U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [3U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [3U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [2U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [3U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [3U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [2U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [3U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[3U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [3U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [3U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[4U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [3U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [3U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [4U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [4U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [3U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [4U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [4U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [3U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [4U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[4U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [4U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [4U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[5U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [4U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [4U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [5U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [5U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [4U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [5U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [5U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [4U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [5U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[5U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [5U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [5U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[6U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [5U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [5U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [6U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [6U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [5U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [6U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [6U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [5U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [6U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[6U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [6U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [6U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[7U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [6U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [6U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [7U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [7U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [6U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [7U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [7U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [6U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [7U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[7U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [7U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [7U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[8U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [7U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [7U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [8U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [8U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [7U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [8U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [8U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [7U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [8U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[8U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [8U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [8U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[9U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [8U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [8U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [9U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [9U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [8U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [9U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [9U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [8U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [9U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[9U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [9U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                [9U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[0xaU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [9U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [9U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [0xaU] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [0xaU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [9U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [0xaU] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [0xaU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [9U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                               [0xaU] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[0xaU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
                          [0xaU] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                                                  [0xaU] 
                                                  >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[0xbU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe
         [0xaU])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [0xaU] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [0xbU] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [0xbU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                     [0xaU] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted
                             [0xbU] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val
                             [0xbU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe
                      [0xaU] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
                                                 [0xbU] 
                                                 >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[0xbU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[0U] 
        = (3U & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_D) 
                 >> 0xeU));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[0U] = 1U;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[0U] 
        = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                         [0U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                         [0U]));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[0U] 
        = (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                    [0U] >> 0x19U)));
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [0U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [0U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[1U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [0U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [0U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [1U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [1U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [0U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [1U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [1U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[1U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [0U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [1U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[1U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [1U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [1U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[2U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [1U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [1U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [2U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [2U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [1U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [2U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [2U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[2U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [1U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [2U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[2U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [2U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [2U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[3U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [2U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [2U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [3U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [3U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [2U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [3U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [3U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[3U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [2U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [3U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[3U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [3U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [3U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[4U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [3U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [3U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [4U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [4U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [3U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [4U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [4U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[4U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [3U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [4U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[4U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [4U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [4U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[5U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [4U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [4U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [5U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [5U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [4U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [5U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [5U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[5U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [4U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [5U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[5U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [5U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [5U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[6U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [5U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [5U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [6U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [6U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [5U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [6U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [6U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[6U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [5U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [6U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[6U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [6U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [6U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[7U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [6U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [6U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [7U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [7U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [6U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [7U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [7U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[7U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [6U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [7U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[7U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [7U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [7U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[8U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [7U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [7U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [8U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [8U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [7U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [8U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [8U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[8U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [7U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [8U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[8U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [8U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [8U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[9U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [8U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [8U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [9U] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [9U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [8U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [9U] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [9U]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[9U] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [8U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [9U] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[9U] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [9U] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                [9U] 
                                                >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[0xaU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [9U])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [9U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [0xaU] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [0xaU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [9U] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [0xaU] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [0xaU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[0xaU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [9U] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                               [0xaU] 
                                               >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[0xaU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0 
        = ((0x3fffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
                          [0xaU] << 2U)) | (3U & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                                                  [0xaU] 
                                                  >> 0x16U)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[0xbU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h1767388c__0;
    if ((0x2000000U & vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe
         [0xaU])) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 
            = (3U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [0xaU] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [0xbU] + vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [0xbU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 
            = (1U | (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                     [0xaU] << 2U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 
            = (0x3ffffffU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted
                             [0xbU] - vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val
                             [0xbU]));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[0xbU] 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1;
    }
    sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0 
        = ((0xffeU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe
                      [0xaU] << 1U)) | (1U & (~ (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
                                                 [0xbU] 
                                                 >> 0x19U))));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[0xbU] 
        = sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hd45e256f__0;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, ((VL_MULS_III(32, (IData)(0x80U), 
                                                            VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_x))) 
                                                + VL_MULS_III(32, (IData)(0x99U), 
                                                              VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_y)))) 
                                               + VL_MULS_III(32, (IData)(0xffffff60U), 
                                                             VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_z)))), 8U));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__half_dot_product 
        = (0xffffU & VL_SHIFTRS_III(16,32,32, ((VL_MULS_III(32, (IData)(0x47U), 
                                                            VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_x))) 
                                                + VL_MULS_III(32, (IData)(0x55U), 
                                                              VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_y)))) 
                                               + VL_MULS_III(32, (IData)(0xffffff19U), 
                                                             VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__norm_z)))), 8U));
    if ((0x8000U & (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__half_dot_product))) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s1 = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s2 = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s4 = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s8 = 0U;
    } else {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s1 
            = sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__half_dot_product;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s2 
            = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s1)), 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s1))), 8U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s4 
            = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s2)), 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s2))), 8U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s8 
            = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s4)), 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s4))), 8U));
    }
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__specular 
        = ((VL_LTS_III(32, 0U, VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product))) 
            & (~ ((IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__half_dot_product) 
                  >> 0xfU))) ? (VL_LTES_III(16, 0x100U, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s8))
                                 ? 0xfU : (0xfU & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s8) 
                                                   >> 4U)))
            : 0U);
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__diffuse 
        = (VL_LTES_III(16, 0x100U, (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product))
            ? 0xfU : (VL_LTS_III(32, 0U, VL_EXTENDS_II(32,16, (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product)))
                       ? (0xfU & ((IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__dot_product) 
                                  >> 4U)) : 0U));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_add 
        = (0x1fU & ((IData)(3U) + (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__diffuse)));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_base 
        = ((0xfU < (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_add))
            ? 0xfU : (0xfU & (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_add)));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_base 
        = (0xfU & VL_SHIFTR_III(4,4,32, (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__diffuse), 2U));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_sum 
        = (0x1fU & ((IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_base) 
                    + (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__specular)));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_sum 
        = (0x1fU & ((IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_base) 
                    + (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__specular)));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__b_sum 
        = sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__specular;
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__red 
        = ((0xfU < (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_sum))
            ? 0xfU : (0xfU & (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__r_sum)));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__green 
        = ((0xfU < (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_sum))
            ? 0xfU : (0xfU & (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__g_sum)));
    sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__blue 
        = ((0xfU < (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__b_sum))
            ? 0xfU : (0xfU & (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__b_sum)));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__shaded_output 
        = (((IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__red) 
            << 8U) | (((IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__green) 
                       << 4U) | (IData)(sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__blue)));
}

VL_ATTR_COLD void Vsim_top___024root___eval_triggers__stl(Vsim_top___024root* vlSelf);

VL_ATTR_COLD bool Vsim_top___024root___eval_phase__stl(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_phase__stl\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsim_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vsim_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__act\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__nba(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__nba\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___ctor_var_reset(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___ctor_var_reset\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->reset = 0;
    vlSelf->keycode = 0;
    vlSelf->fb_addr = 0;
    vlSelf->fb_din = 0;
    vlSelf->fb_we = 0;
    vlSelf->frame_done = 0;
    vlSelf->carve_x = 0;
    vlSelf->carve_y = 0;
    vlSelf->carve_z = 0;
    vlSelf->carve_radius = 0;
    vlSelf->carve_en = 0;
    vlSelf->sim_top__DOT__inv_carve_radius = 0;
    vlSelf->sim_top__DOT__carve_ctrl_inst__DOT__tick_dly = 0;
    vlSelf->sim_top__DOT__carve_ctrl_inst__DOT__tick_pulse = 0;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->sim_top__DOT__carve_ctrl_inst__DOT__inv_rom[__Vi0] = 0;
    }
    vlSelf->sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__render_x = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__render_y = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_dir_x = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_dir_y = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_dir_z = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__pos_x = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__pos_y = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__pos_z = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_dist = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_t = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__step_cnt = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__hit = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__blend_w_reg = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__shaded_output = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__u_val = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__v_val = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_u = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_v = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__S = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dx = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dy = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dz = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_S = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__lut_out = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dx = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dy = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dz = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_valid = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_D = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_D = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__d_diff = 0;
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_shifted[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__test_val[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next[__Vi0] = 0;
    }
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h05461e2c__1 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb4dda816__1 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_shifted[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__test_val[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next[__Vi0] = 0;
    }
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h05461e2c__1 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb4dda816__1 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s1 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s2 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s4 = 0;
    vlSelf->sim_top__DOT__raymarch_inst__DOT__sphere_shader_inst__DOT__s8 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
}
