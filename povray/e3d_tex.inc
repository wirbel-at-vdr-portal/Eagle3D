/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * This is the global texture definition file. All texture definitions
 * for parts have to be taken from here or have to be defined here.
 ******************************************************************************/

#declare e3d_tex_gold                      = texture { T_Gold_5E                finish { F_MetalA ambient(0.35 * global_ambient_mul) } }
#declare e3d_tex_silver                    = texture { T_Silver_5A              finish { F_MetalA ambient(0.35 * global_ambient_mul) } }
#declare e3d_tex_ic_body_1                 = texture { pigment { Gray30 }       finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_ic_body_2                 = texture { pigment { Gray30 }       finish {          ambient(0.10 * global_ambient_mul) phong 0.1 phong_size 25 } }
#declare e3d_tex_ic_marking_bright         = texture { pigment { Gray60 }       finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_ic_marking_black          = texture { pigment { Black }        finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_cap_block_blue            = texture { pigment {rgb<0.3,0.3,1>} finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_cap_wima                  = texture { pigment { Red }          finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_cap_smd_electrolytic_base = texture { pigment { Gray30 }       finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_cap_smd_ceramic_1         = texture { pigment { DarkWood }     finish {          ambient(0.10 * global_ambient_mul) } }
#declare e3d_tex_heatsink_silver           = texture { T_Silver_5A              finish {          ambient(0.10 * global_ambient_mul)  phong 0.1 phong_size 10 } }

/*******************************************************************************
 * alias names
 ******************************************************************************/
#declare e3d_tex_cap_marking_black         = e3d_tex_ic_marking_black
#declare col_gold                          = e3d_tex_gold
#declare col_silver                        = e3d_tex_silver


/*******************************************************************************
 * for backward compatibility (Will try to get rid of them)
 ******************************************************************************/
#declare e3d_tex_con_IDC                   = texture { pigment { Gray70 }       finish {          ambient(0.10 * global_ambient_mul) } }  
