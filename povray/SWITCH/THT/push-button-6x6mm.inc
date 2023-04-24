/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT push button 6mm x 6mm
 * franz.riedmueller@web.de
 ******************************************************************************/
#macro SWITCH_THT_PUSHBUTTON_6x6mm()
  union {
     box {
        <-3,   0, -3>
        < 3, 3.4,  3>
        pigment {
           Gray30 * 0.4
           }
        }
     box {
        <-3, 3.4, -3>
        < 3, 3.5,  3>
        texture {
           col_silver
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           reflection 0.35
           phong 1.0
           phong_size 70
           brilliance 10
           }
        }
     cone {
        <0, 3.4, 0>,  1.65,
        <0, 9.5, 0>, 1.45
        pigment {
           Gray30 * 0.3
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
        <-2.3, 3.4, 2.3>,
        <-2.3, 3.7, 2.3>,  0.5
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        }
     cylinder {
        <-2.3, 3.4, -2.3>,
        <-2.3, 3.7, -2.3>,  0.5
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        }
     cylinder {
        <2.3, 3.4, 2.3>,
        <2.3, 3.7, 2.3>,  0.5
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        }
     cylinder {
        <2.3, 3.4, -2.3>,
        <2.3, 3.7, -2.3>,  0.5
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        }
     box {
        <-3.01, -2.5, -0.1>
        < -2.5,  1.0,  0.1>
        texture {
           col_silver
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           reflection 0.35
           phong 1.0
           phong_size 70
           brilliance 10
           }
        }
     box {
        <3.01, -2.5, -0.1>
        < 2.5,  1.0,  0.1>
        texture {
           col_silver
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           reflection 0.35
           phong 1.0
           phong_size 70
           brilliance 10
           }
        }
     }
#end


/*******************************************************************************
 * THT Push Button Omron B3F-10xx
 * THT Push Button Alps Alpine SKHH Series
 * Tobias Mueller <Tobias_Mueller(replace with at)twam.info>
 * M. Weisser <mattias@matwei.de>
 *
 * dia:    diameter of button
 * height: height of button over case of button
 * c:      color of actual button
 * *****************************************************************************/
#macro SW_SKHH_BASE(dia, height, c)
  union {
     box {
        <-3,0,-3> <3,2.9,3>
        pigment {
           Gray30 * 0.4
           }
        }
     box {
        <-3,2.9,-3> <3,3,3>
        texture {
           col_silver
           }
        }
     object {
        Round_Cylinder_Union(
           <0,3,0>, <0,3+height,0>, dia/2, (dia/2)/10
           )
        texture {
           pigment {
              Gray30 * 0.3
              }
           finish {
              phong 0.4 reflection {
                 0.2
                 }
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     cylinder {
        <0,3,0> <0,3.2,0> 0.4
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        translate<-2.5,0,-2.5>
        }
     cylinder {
        <0,3,0> <0,3.2,0> 0.4
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        translate <-2.5,0,2.5>
        }
     cylinder {
        <0,3,0> <0,3.2,0> 0.4
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        translate <2.5,0,-2.5>
        }
     cylinder {
        <0,3,0> <0,3.2,0> 0.4
        pigment {
           Gray30 * 0.1
           }
        finish {
           ambient (0.15 * global_ambient_mul)
           diffuse 0.85
           }
        translate <2.5,0,2.5>
        }
     union {
        box {
           <-0.2,-1,-0.4> <0.2,1,0.4>
           }
        cylinder {
           <-0,1,-0.4> <0,1,0.4> 0.2
           }
        translate <3,0,2.2>
        }
     union {
        box {
           <-0.2,-1,-0.4> <0.2,1,0.4>
           }
        cylinder {
           <-0,1,-0.4>  <0,1,0.4> 0.2
           }
        translate <3,0,-2.2>
        }
     union {
        box {
           <-0.2,-1,-0.4> <0.2,1,0.4>
           }
        cylinder {
           <-0,1,-0.4>  <0,1,0.4> 0.2
           }
        translate <-3,0,2.2>
        }
     union {
        box {
           <-0.2,-1,-0.4> <0.2,1,0.4>
           }
        cylinder {
           <-0,1,-0.4>  <0,1,0.4> 0.2
           }
        translate <-3,0,-2.2>
        }
     texture {
        col_silver
        }
     finish {
        ambient (0.15 * global_ambient_mul)
        diffuse 0.85
        reflection 0.35
        phong 1.0
        phong_size 70
        brilliance 10
        }
     }
#end

#macro SWITCH_THT_B3F10XX()
  SW_SKHH_BASE(4,1,Black)
#end

#macro SWITCH_SKHH_V_4_3MM_YELL()
  SW_SKHH_BASE(4,1.3,Yellow)
#end

#macro SWITCH_SKHH_V_5MM_YELL()
  SW_SKHH_BASE(4,2,Yellow)
#end

#macro SWITCH_SKHH_V_7MM_YELL()
  SW_SKHH_BASE(4,4,Yellow)
#end

#macro SWITCH_SKHH_V_9_5MM_YELL()
  SW_SKHH_BASE(4,6.5,Yellow)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SWITCH_THT_PUSHBUTTON_6x6mm:THT push button 6mm x 6mm
//switch-omron:B3F-10XX=SWITCH_THT_B3F10XX(:THT Push Button 6mm x 6mm
//=SWITCH_THT_SKHH043VY(:THT Push Button 6mm x 6mm
//=SWITCH_THT_SKHH050VY(:THT Push Button 6mm x 6mm
//=SWITCH_THT_SKHH070VY(:THT Push Button 6mm x 6mm
//=SWITCH_THT_SKHH095VY(:THT Push Button 6mm x 6mm
// end assignment 
