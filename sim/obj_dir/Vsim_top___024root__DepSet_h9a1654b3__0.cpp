// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"
#include "Vsim_top___024root.h"

void Vsim_top___024root___eval_act(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_act\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vsim_top___024root___nba_sequent__TOP__0(Vsim_top___024root* vlSelf);

void Vsim_top___024root___eval_nba(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_nba\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsim_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<SData/*15:0*/, 64> Vsim_top__ConstPool__TABLE_h061db8b3_0;

VL_INLINE_OPT void Vsim_top___024root___nba_sequent__TOP__0(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___nba_sequent__TOP__0\n"); );
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
    CData/*0:0*/ __Vdly__carve_en;
    __Vdly__carve_en = 0;
    SData/*15:0*/ __Vdly__carve_radius;
    __Vdly__carve_radius = 0;
    SData/*15:0*/ __Vdly__carve_z;
    __Vdly__carve_z = 0;
    SData/*15:0*/ __Vdly__carve_y;
    __Vdly__carve_y = 0;
    SData/*15:0*/ __Vdly__carve_x;
    __Vdly__carve_x = 0;
    CData/*2:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0;
    SData/*15:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t = 0;
    SData/*15:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__hit;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 0;
    CData/*0:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 0;
    SData/*8:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x = 0;
    CData/*7:0*/ __Vdly__sim_top__DOT__raymarch_inst__DOT__render_y;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__render_y = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v0 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22 = 0;
    CData/*0:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v0 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v0 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v0 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v0 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22 = 0;
    IData/*25:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v0 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22 = 0;
    IData/*23:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v0;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v0 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22 = 0;
    SData/*11:0*/ __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23;
    __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23 = 0;
    CData/*0:0*/ __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23 = 0;
    // Body
    __Vdly__carve_en = vlSelfRef.carve_en;
    __Vdly__carve_radius = vlSelfRef.carve_radius;
    __Vdly__carve_z = vlSelfRef.carve_z;
    __Vdly__carve_y = vlSelfRef.carve_y;
    __Vdly__carve_x = vlSelfRef.carve_x;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23 = 0U;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__step_cnt;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__hit;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_in_valid;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x;
    __Vdly__sim_top__DOT__raymarch_inst__DOT__render_y 
        = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v0 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22 = 0U;
    __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23 = 0U;
    if (vlSelfRef.reset) {
        __Vdly__carve_en = 1U;
        __Vdly__carve_radius = 0x5aU;
        __Vdly__carve_z = 0xff26U;
        __Vdly__carve_y = 0x5aU;
        __Vdly__carve_x = 0x5aU;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v0 = 1U;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v0 = 1U;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v0 = 1U;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v0 = 1U;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v0 = 1U;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v0 = 1U;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v0 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_S = 0U;
        vlSelfRef.sim_top__DOT__inv_carve_radius = 0x2d8U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t = 0x100U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z = 0xfd80U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 0U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 1U;
        vlSelfRef.fb_we = 0U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x = 0U;
        __Vdly__sim_top__DOT__raymarch_inst__DOT__render_y = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_z = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_x = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_y = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dz = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dx = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dy = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dz = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dx = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dy = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_u = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_v = 0U;
    } else {
        if (vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__tick_pulse) {
            if ((1U & (~ ((((((((0x1aU == (IData)(vlSelfRef.keycode)) 
                                | (0x16U == (IData)(vlSelfRef.keycode))) 
                               | (7U == (IData)(vlSelfRef.keycode))) 
                              | (4U == (IData)(vlSelfRef.keycode))) 
                             | (8U == (IData)(vlSelfRef.keycode))) 
                            | (0x14U == (IData)(vlSelfRef.keycode))) 
                           | (0x15U == (IData)(vlSelfRef.keycode))) 
                          | (9U == (IData)(vlSelfRef.keycode)))))) {
                if ((0x2cU == (IData)(vlSelfRef.keycode))) {
                    __Vdly__carve_en = (1U & (~ (IData)(vlSelfRef.carve_en)));
                }
            }
            if (((((((((0x1aU == (IData)(vlSelfRef.keycode)) 
                       | (0x16U == (IData)(vlSelfRef.keycode))) 
                      | (7U == (IData)(vlSelfRef.keycode))) 
                     | (4U == (IData)(vlSelfRef.keycode))) 
                    | (8U == (IData)(vlSelfRef.keycode))) 
                   | (0x14U == (IData)(vlSelfRef.keycode))) 
                  | (0x15U == (IData)(vlSelfRef.keycode))) 
                 | (9U == (IData)(vlSelfRef.keycode)))) {
                if ((0x1aU != (IData)(vlSelfRef.keycode))) {
                    if ((0x16U != (IData)(vlSelfRef.keycode))) {
                        if ((7U != (IData)(vlSelfRef.keycode))) {
                            if ((4U != (IData)(vlSelfRef.keycode))) {
                                if ((8U != (IData)(vlSelfRef.keycode))) {
                                    if ((0x14U != (IData)(vlSelfRef.keycode))) {
                                        if ((0x15U 
                                             == (IData)(vlSelfRef.keycode))) {
                                            if (VL_GTS_III(16, 0xdaU, (IData)(vlSelfRef.carve_radius))) {
                                                __Vdly__carve_radius 
                                                    = 
                                                    (0xffffU 
                                                     & ((IData)(0x10U) 
                                                        + (IData)(vlSelfRef.carve_radius)));
                                            }
                                        } else if (
                                                   VL_LTS_III(16, 0x1aU, (IData)(vlSelfRef.carve_radius))) {
                                            __Vdly__carve_radius 
                                                = (0xffffU 
                                                   & ((IData)(vlSelfRef.carve_radius) 
                                                      - (IData)(0x10U)));
                                        }
                                    }
                                }
                                if ((8U == (IData)(vlSelfRef.keycode))) {
                                    __Vdly__carve_z 
                                        = (0xffffU 
                                           & ((IData)(0x10U) 
                                              + (IData)(vlSelfRef.carve_z)));
                                } else if ((0x14U == (IData)(vlSelfRef.keycode))) {
                                    __Vdly__carve_z 
                                        = (0xffffU 
                                           & ((IData)(vlSelfRef.carve_z) 
                                              - (IData)(0x10U)));
                                }
                            }
                        }
                        if ((7U == (IData)(vlSelfRef.keycode))) {
                            __Vdly__carve_x = (0xffffU 
                                               & ((IData)(0x10U) 
                                                  + (IData)(vlSelfRef.carve_x)));
                        } else if ((4U == (IData)(vlSelfRef.keycode))) {
                            __Vdly__carve_x = (0xffffU 
                                               & ((IData)(vlSelfRef.carve_x) 
                                                  - (IData)(0x10U)));
                        }
                    }
                }
                if ((0x1aU == (IData)(vlSelfRef.keycode))) {
                    __Vdly__carve_y = (0xffffU & ((IData)(0x10U) 
                                                  + (IData)(vlSelfRef.carve_y)));
                } else if ((0x16U == (IData)(vlSelfRef.keycode))) {
                    __Vdly__carve_y = (0xffffU & ((IData)(vlSelfRef.carve_y) 
                                                  - (IData)(0x10U)));
                }
            }
        }
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [0U];
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [1U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [2U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [3U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [4U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [5U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [6U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [7U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [8U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [9U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [0xaU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_next
            [0xbU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23 = 1U;
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [0U];
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [1U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [2U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [3U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [4U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [5U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [6U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [7U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [8U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [9U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [0xaU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_next
            [0xbU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_hb802e738__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23 = 1U;
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12 
            = (0xfffc00U & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sq_D) 
                            << 0xaU));
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [0U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [1U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [2U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [3U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [4U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [5U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [6U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [7U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [8U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [9U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe
                            [0xaU] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23 = 1U;
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12 
            = (0xfffc00U & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sq_D) 
                            << 0xaU));
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [0U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [1U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [2U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [3U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [4U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [5U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [6U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [7U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [8U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [9U] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0 
            = (0xfffffcU & (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe
                            [0xaU] << 2U));
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h820ed32e__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23 = 1U;
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [0U];
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [1U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [2U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [3U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [4U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [5U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [6U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [7U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [8U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [9U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [0xaU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_next
            [0xbU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23 = 1U;
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [0U];
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [1U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [2U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [3U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [4U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [5U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [6U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [7U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [8U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [9U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [0xaU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_next
            [0xbU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT____Vlvbound_h87f99e75__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23 = 1U;
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [0U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [1U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [2U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [3U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [4U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [5U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [6U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [7U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [8U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [9U];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
            [0xaU];
        __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT____Vlvbound_h5b2e96bf__0;
        __VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23 = 1U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_S 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__S;
        vlSelfRef.sim_top__DOT__inv_carve_radius = 
            vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__inv_rom
            [(0xffU & (IData)(vlSelfRef.carve_radius))];
        if ((4U & (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))) {
            if ((2U & (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))) {
                if ((1U & (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))) {
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0U;
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t = 0x100U;
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt = 0U;
                    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x = 0U;
                    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y = 0U;
                    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z = 0xfd80U;
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 0U;
                    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 0U;
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 0U;
                    vlSelfRef.fb_we = 0U;
                } else {
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0U;
                    vlSelfRef.fb_din = ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__hit)
                                         ? (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__shaded_output)
                                         : 0x112U);
                    vlSelfRef.fb_we = 1U;
                    vlSelfRef.fb_addr = (0x1ffffU & 
                                         ((((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y) 
                                            << 8U) 
                                           + ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y) 
                                              << 6U)) 
                                          + (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x)));
                    __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 1U;
                    if ((0x13fU == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x))) {
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__render_y 
                            = ((0xefU == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y))
                                ? 0U : (0xffU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y))));
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x = 0U;
                    } else {
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x)));
                    }
                }
            } else {
                __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t = 0x100U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z = 0xfd80U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 0U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 0U;
                vlSelfRef.fb_we = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))) {
            if ((1U & (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))) {
                __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 0U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t = 0x100U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z = 0xfd80U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 0U;
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 0U;
                __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 0U;
                vlSelfRef.fb_we = 0U;
            } else {
                vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 0U;
                if (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe
                    [0xbU]) {
                    if (VL_GTS_III(16, 5U, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_dist))) {
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 6U;
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 1U;
                        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__blend_w_reg 
                            = ((1U & ((~ (IData)(vlSelfRef.carve_en)) 
                                      | VL_GTES_III(16, 0xfff0U, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__d_diff))))
                                ? 0U : (VL_LTES_III(16, 0x30U, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__d_diff))
                                         ? 0x100U : 
                                        (0x1ffU & VL_SHIFTL_III(9,9,32, 
                                                                ((IData)(0x10U) 
                                                                 + 
                                                                 VL_EXTENDS_II(9,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__d_diff))), 2U))));
                    } else if ((VL_LTS_III(16, 0x600U, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t)) 
                                | VL_LTS_III(16, 0x18U, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__step_cnt)))) {
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 6U;
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__hit = 0U;
                    } else {
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t 
                            = (0xffffU & ((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t) 
                                          + (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_dist)));
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__step_cnt)));
                        __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 1U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))) {
            __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 2U;
            vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_x 
                = (0xffffU & VL_SHIFTRS_III(16,32,32, 
                                            VL_MULS_III(32, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_x)), 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t))), 8U));
            vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_in_valid = 1U;
            vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_y 
                = (0xffffU & VL_SHIFTRS_III(16,32,32, 
                                            VL_MULS_III(32, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_y)), 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t))), 8U));
            vlSelfRef.sim_top__DOT__raymarch_inst__DOT__pos_z 
                = (0xffffU & ((IData)(0xfd80U) + VL_SHIFTRS_III(16,32,32, 
                                                                VL_MULS_III(32, 
                                                                            VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_z)), 
                                                                            VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t))), 8U)));
        } else {
            if (vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_valid) {
                __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state = 1U;
            }
            __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t = 0x100U;
            __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt = 0U;
            __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid = 0U;
            vlSelfRef.fb_we = 0U;
        }
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_z 
            = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dz)), 
                                                              VL_EXTENDS_II(32,17, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm))), 0x10U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_x 
            = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dx)), 
                                                              VL_EXTENDS_II(32,17, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm))), 0x10U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_dir_y 
            = (0xffffU & VL_SHIFTRS_III(16,32,32, VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dy)), 
                                                              VL_EXTENDS_II(32,17, (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm))), 0x10U));
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dz 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dz;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dx 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dx;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_inv_norm 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__lut_out;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_dy 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dy;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dz 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dx 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_dy 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dz = 0x180U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dx 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_u;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_dy 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_v;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_u 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__u_val;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_v 
            = vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__v_val;
    }
    vlSelfRef.sim_top__DOT__carve_ctrl_inst__DOT__tick_dly 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.frame_done));
    vlSelfRef.carve_z = __Vdly__carve_z;
    vlSelfRef.carve_y = __Vdly__carve_y;
    vlSelfRef.carve_x = __Vdly__carve_x;
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__rem_pipe__v23;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__rem_pipe__v23;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__x_pipe__v23;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__x_pipe__v23;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__q_pipe__v23;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__carve_sqrt_inst__DOT__q_pipe__v23;
    }
    vlSelfRef.carve_radius = __Vdly__carve_radius;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_t 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_t;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__step_cnt 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__step_cnt;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__hit 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__hit;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__raymarch_state;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__render_x;
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__render_y;
    vlSelfRef.carve_en = __Vdly__carve_en;
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v0) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[0U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[1U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[2U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[3U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[4U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[5U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[6U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[7U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[8U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[9U] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[0xaU] = 0U;
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[0xbU] = 0U;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[0U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v12;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[1U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v13;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[2U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v14;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[3U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v15;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[4U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v16;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[5U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v17;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[6U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v18;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[7U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v19;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[8U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v20;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[9U] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v21;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[0xaU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v22;
    }
    if (__VdlySet__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23) {
        vlSelfRef.sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe[0xbU] 
            = __VdlyVal__sim_top__DOT__raymarch_inst__DOT__sdf_scene_inst__DOT__sqrt_inst__DOT__valid_pipe__v23;
    }
    vlSelfRef.frame_done = ((0x13fU == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_x)) 
                            & ((0xefU == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__render_y)) 
                               & (6U == (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__raymarch_state))));
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
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_valid 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_valid));
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
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r4_valid 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_valid));
    __Vtableidx1 = (0x3fU & (((IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_S) 
                              - (IData)(0x240U)) >> 4U));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__lut_out 
        = Vsim_top__ConstPool__TABLE_h061db8b3_0[__Vtableidx1];
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r3_valid 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_valid));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r2_valid 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_valid));
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_gen_inst__DOT__r1_valid 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_in_valid));
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
    vlSelfRef.sim_top__DOT__raymarch_inst__DOT__ray_in_valid 
        = __Vdly__sim_top__DOT__raymarch_inst__DOT__ray_in_valid;
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
}

void Vsim_top___024root___eval_triggers__act(Vsim_top___024root* vlSelf);

bool Vsim_top___024root___eval_phase__act(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_phase__act\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsim_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsim_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsim_top___024root___eval_phase__nba(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_phase__nba\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsim_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__nba(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim_top___024root___eval(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsim_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sim_top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsim_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sim_top.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsim_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsim_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsim_top___024root___eval_debug_assertions(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_debug_assertions\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
