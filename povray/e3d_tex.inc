/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * This is the global texture definition file. All texture definitions
 * for parts have to be taken from here or have to be defined here.
 ******************************************************************************/

#declare col_gold           = texture { T_Gold_5E             finish { F_MetalA ambient(0.35 * global_ambient_mul) } }
#declare col_silver         = texture { T_Silver_5A           finish { F_MetalA ambient(0.35 * global_ambient_mul) } }
#declare col_bright_marking = texture { pigment { Gray60 }    finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_black_marking  = texture { pigment { Black }     finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_ic_body_1      = texture { pigment { Gray30 }    finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_ic_body_2      = texture { pigment { Gray30 }    finish {          ambient(0.10 * global_ambient_mul) phong 0.1 phong_size 25 } }
#declare col_ceramic_cap    = texture { pigment { DarkWood }  finish {          ambient(0.10 * global_ambient_mul) } }
