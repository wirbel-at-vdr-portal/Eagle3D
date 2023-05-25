/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * This is the global color definition file.
 ******************************************************************************/

#declare col_gold           = texture { T_Gold_5E             finish { F_MetalA ambient(0.35 * global_ambient_mul) } }
#declare col_silver         = texture { T_Silver_5A           finish { F_MetalA ambient(0.35 * global_ambient_mul) } }
#declare col_tin            = texture { pigment { Gray70 }    normal { bumps 0.01 scale 0.001 } finish { F_MetalB ambient (0.3 * global_ambient_mul) } }
#declare col_nylon          = texture { pigment { Wheat }     finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_bright_marking = texture { pigment { Gray60 }    finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_black_marking  = texture { pigment { Black }     finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_ic_body_1      = texture { pigment { Gray20 }    finish {          ambient(0.10 * global_ambient_mul) } }
#declare col_ic_body_2      = texture { pigment { Gray30 }    finish {          ambient(0.10 * global_ambient_mul) phong 0.1 phong_size 25 } }
#declare col_ceramic_cap    = texture { pigment { DarkWood }  finish {          ambient(0.10 * global_ambient_mul) } }


/*******************************************************************************
 * Resistor value color codes
 ******************************************************************************/
#declare col_Rcode_silver   = texture { T_Silver_5E                    finish { reflection 0.1 ambient (0.1 * global_ambient_mul) } } // 0.01
#declare col_Rcode_gold     = texture { T_Gold_5C                      finish { reflection 0.1 ambient (0.1 * global_ambient_mul) } } // 0.1
#declare col_Rcode_black    = texture { pigment{ Black               } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 0
#declare col_Rcode_brown    = texture { pigment{ DarkBrown           } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 1
#declare col_Rcode_red      = texture { pigment{ Red*0.7             } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 2
#declare col_Rcode_orange   = texture { pigment{ Orange              } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 3
#declare col_Rcode_yellow   = texture { pigment{ Yellow              } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 4
#declare col_Rcode_green    = texture { pigment{ Green*0.7           } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 5
#declare col_Rcode_blue     = texture { pigment{ Blue                } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 6
#declare col_Rcode_violet   = texture { pigment{ Violet*1.2          } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 7
#declare col_Rcode_grey     = texture { pigment{ Gray45              } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 8
#declare col_Rcode_white    = texture { pigment{ White               } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // 9
#declare col_Rcode_ERROR    = texture { pigment{ checker Black White } finish { phong 0.2      ambient (0.1 * global_ambient_mul) } } // wrong value
