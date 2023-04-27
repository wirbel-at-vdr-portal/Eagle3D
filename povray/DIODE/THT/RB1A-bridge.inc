/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT full bridge rectifier RB1A
 * franz.riedmueller@web.de
 *
 * 27.04.2023 modified, wk
 * - change body color
 * - replace cone by Round_Box_Union()
 * - reduce height above PCB
 * - increase font size
 * - code formatting
 ******************************************************************************/
#macro DIODE_THT_BRIDGE_RB1A(value)
  union {
     difference {
        union {
           Round_Cylinder_Union(
              <0, 0, 0>,
              <0, 5, 0>,
              4.8 0.2
              )
           }
        box {
           <-4.1, -0.1, 4.0>
           < -20, 5.1,  -3.8>
           }
        pigment {
           White * 0.075
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           reflection 0.05
           phong 1.0
           phong_size 40
           }
        }
     cylinder {
        <-2.55, 0, 2.55>
        <-2.55, -3, 2.55>, 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <2.55, 0, 2.55>
        <2.55, -3, 2.55>, 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <2.55, 0, -2.55>
        <2.55, -3, -2.55>, 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <-2.55, 0, -2.55>
        <-2.55, -3, -2.55>, 0.3
        texture {
           col_silver
           }
        }
     text {
        ttf besch_font "+  ~", 0.2, 0
        pigment {
           Gray30
           }
        scale 2
        rotate <90,0,0>
        translate <-2.5,5.01,2.5>
        }
     text {
        ttf besch_font "~  -", 0.2, 0
        pigment {
           Gray30
           }
        scale 2
        rotate <90,0,0>
        translate <-2.5,5.01,-3>
        }
     text {
        ttf besch_font value, 0.2, 0
        pigment {
           Gray30
           }
        scale 2
        rotate <90,0,0>
        translate <-2.5,5.01,0>
        }
     translate<0,1,0>
     }
#end

/*******************************************************************************
*  no typos below please.
 * *****************************************************************************/
// begin assignment
//rectifier:RB1A=DIODE_THT_BRIDGE_RB1A(:THT full bridge rectifier
// end assignment
