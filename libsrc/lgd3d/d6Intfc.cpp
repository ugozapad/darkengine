#include <types.h>
#include <grs.h>
#include <r3ds.h>
#include <g2spoint.h>
#include <d6States.h>

#include <d3d.h>
#include <d3dtypes.h>

bool lgd3d_g_bInitialized = false;


void lgd3d_set_RGB();
void lgd3d_set_hardware();
void lgd3d_set_software();
int lgd3d_is_RGB();
int lgd3d_is_hardware();
void lgd3d_texture_set_RGB(uint8 is_RGB);
int lgd3d_init(lgd3ds_device_info *device_info);
int lgd3d_attach_to_lgsurface(ILGSurface *pILGSurface);
void lgd3d_clean_render_surface(int bDepthBuffToo);
void lgd3d_shutdown();
int lgd3d_set_poly_mode(ePolyMode eNewMode);
ePolyMode lgd3d_get_poly_mode();
void lgd3d_start_frame(int frame);
void lgd3d_end_frame();
int lgd3d_overlays_master_switch(int bOverlaysOn);
int lgd3d_release_indexed_primitives();
int lgd3d_rgb_indexed_poly(int n, r3s_point **ppl, r3ixs_info *info);
int lgd3d_rgba_indexed_poly(int n, r3s_point **ppl, r3ixs_info *info);
int lgd3d_indexed_poly(int n, r3s_point **vpl, r3ixs_info *info);
int lgd3d_indexed_spoly(int n, r3s_point **vpl, r3ixs_info *info);
int lgd3d_indexed_trifan(int n, r3s_point **vpl, r3ixs_info *info);
int lgd3d_lit_indexed_trifan(int n, r3s_point **vpl, r3ixs_info *info);
void lgd3d_tmap_setup(grs_bitmap *bm);
void lgd3d_rgblit_tmap_setup(grs_bitmap *bm);
int lgd3d_rgblit_trifan(int n, r3s_point **ppl);
int lgd3d_rgblit_indexed_trifan(int n, r3s_point **ppl, r3ixs_info *info);
void lgd3d_rgbalit_tmap_setup(grs_bitmap *bm);
int lgd3d_rgbalit_trifan(int n, r3s_point **ppl);
int lgd3d_rgbalit_indexed_trifan(int n, r3s_point **ppl, r3ixs_info *info);
void lgd3d_rgbafoglit_tmap_setup(grs_bitmap *bm);
int lgd3d_rgbafoglit_trifan(int n, r3s_point **ppl);
int lgd3d_rgbafoglit_indexed_trifan(int n, r3s_point **ppl, r3ixs_info *info);
void lgd3d_diffspecular_tmap_setup(grs_bitmap *bm);
int lgd3d_diffspecular_trifan(int n, r3s_point **ppl);
int lgd3d_diffspecular_indexed_trifan(int n, r3s_point **ppl, r3ixs_info *info);
void lgd3d_lit_tmap_setup(grs_bitmap *bm);
void lgd3d_poly_setup();
void lgd3d_spoly_setup();
void lgd3d_rgb_poly_setup();
int lgd3d_rgb_poly(int n, r3s_point **ppl);
void lgd3d_rgba_poly_setup();
int lgd3d_rgba_poly(int n, r3s_point **ppl);
int lgd3d_draw_point(r3s_point *p);
void lgd3d_set_zwrite(int zwrite);
void lgd3d_set_zcompare(int zwrite);
void lgd3d_zclear();
void lgd3d_set_znearfar(long double znear, long double zfar);
void setwbnf(IDirect3DDevice3 *lpDev, long double dvWNear, long double dvWFar);
void lgd3d_get_znearfar(long double *pdZNear, long double *pdZFar);
void lgd3d_set_pal(int start, int n, uint8 *pal_data);
void lgd3d_set_pal_slot(int start, int n, uint8 *pal_data, int slot);
void lgd3d_set_pal_slot_flags(int start, int n, uint8 *pal_data, int slot, char flags);
void lgd3d_get_trans_texture_bitmask(grs_rgb_bitmask *bitmask);
void lgd3d_get_opaque_texture_bitmask(grs_rgb_bitmask *bitmask);
void lgd3d_get_alpha_texture_bitmask(grs_rgb_bitmask *bitmask);
void lgd3d_set_texture_clut(uint8 *clut);
uint8 *lgd3d_set_clut(uint8 *clut);
void lgd3d_set_fog_level(float fog_level);
void lgd3d_set_fog_color(int r, int g, int b);
void lgd3d_set_fog_enable(int enable);
void lgd3d_set_fog_density(float density);
int lgd3d_use_linear_table_fog(int bUseIt);
void lgd3d_set_fog_start_end(float fStart, float fEnd);
void lgd3d_set_linear_fog_distance(float fDistance);
void lgd3d_set_alpha(float alpha);
void lgd3d_set_blend(int do_blend);
void lgd3d_blend_multiply(int blend_mode);
void lgd3d_clear_z_rect(int x0, int y0, int x1, int y1);
void lgd3d_blend_normal();
void lgd3d_set_offsets(int x, int y);
void lgd3d_get_offsets(int *x, int *y);
void lgd3d_set_z(float z);
void lgd3d_disable_palette();
void lgd3d_enable_palette();
void lgd3d_hack_light(r3s_point *p, float r);
void lgd3d_hack_light_extra(r3s_point *p, float r, grs_bitmap *bm);
void lgd3d_draw_line(r3s_point *p0, r3s_point *p1);
int lgd3d_trifan(int n, r3s_point **vpl);
int lgd3d_lit_trifan(int n, r3s_point **vpl);
int lgd3d_poly(int n, r3s_point **vpl);
int lgd3d_spoly(int n, r3s_point **vpl);
int lgd3d_g2upoly(int n, g2s_point **vpl);
int lgd3d_g2poly(int n, g2s_point **vpl);
int lgd3d_g2utrifan(int n, g2s_point **vpl);
int lgd3d_g2trifan(int n, g2s_point **vpl);
void lgd3d_set_light_map_method(unsigned int flag);
int lgd3d_TrifanMTD(int n, r3s_point **ppl, LGD3D_tex_coord **pptc);
int lgd3d_LitTrifanMTD(int n, r3s_point **ppl, LGD3D_tex_coord **pptc);
int lgd3d_RGBlitTrifanMTD(int n, r3s_point **ppl, LGD3D_tex_coord **pptc);
int lgd3d_RGBAlitTrifanMTD(int n, r3s_point **ppl, LGD3D_tex_coord **pptc);
int lgd3d_RGBAFoglitTrifanMTD(int n, r3s_point **ppl, LGD3D_tex_coord **pptc);
int lgd3d_DiffuseSpecularMTD(int n, r3s_point **ppl, LGD3D_tex_coord **pptc);
int lgd3d_g2UTrifanMTD(int n, g2s_point **vpl, LGD3D_tex_coord **vptc);
int lgd3d_g2TrifanMTD(int n, g2s_point **vpl, LGD3D_tex_coord **vptc);
void lgd3d_set_texture_level(int n);
double lgd3d_set_zbias(long double new_bias);
void lgd3d_push_zbias_i(unsigned int nZBias);
void lgd3d_pop_zbias();
void lgd3d_set_chromakey(int red, int green, int blue);
void lgd3d_set_alpha_pal(unsigned __int16 *pal);
void lgd3d_blit();
void lgd3d_clear(int color_index);
D3DZBUFFERTYPE lgd3d_get_depth_buffer_state();
int lgd3d_is_zwrite_on();
int lgd3d_is_zcompare_on();
int lgd3d_is_alpha_blending_on();
int lgd3d_set_shading(int bSmoothShading);
int lgd3d_is_smooth_shading_on();
int lgd3d_is_fog_on();
void lgd3d_set_texture_map_method(unsigned int flag);
void lgd3d_get_texblending_modes(unsigned int *pulLevel0Mode, unsigned int *pulLevel1Mode);
void lgd3d_set_dithering(int bOn);
int lgd3d_is_dithering_on();
void lgd3d_set_antialiasing(int bOn);
int lgd3d_is_antialiasing_on();
int lgd3d_enable_specular(int bUseIt);
int lgd3d_get_texture_wrapping(unsigned int dwLevel);
int lgd3d_set_texture_wrapping(unsigned int dwLevel, int bSetSmooth);