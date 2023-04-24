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
           Gray30 * 0.1
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
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SWITCH_THT_PUSHBUTTON_6x6mm:THT push button 6mm x 6mm
// end assignment 
