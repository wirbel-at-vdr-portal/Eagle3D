/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * SMT bridge DF...S from International Rectifier
 *   - DF005S DF01S DF02S DF04S DF06S DF08S DF10S
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  26/03/06
 *
 * Modified: - height changed to 3.1mm
 *           - add chamfer
 *           - rounded edges
 *           20220426, wk
 ******************************************************************************/
#macro DIODE_SMT_BRIDGE_DFS()
  union {
     //Body
     difference {
        Round_Box(
           <-4.1,0.3,-3.1> <+4.1,3.2,+3.1> 0.2 0
           )
        cylinder{<3,1.8,0><3,2,0> 0.4}
        box {
           <-1.5/2,-1.5/2,-3.3>
           <+1.5/2,+1.5/2,+3.3>
           rotate <0,0,45>
           translate <4.3,3.2,0>
           }
        texture {
           col_ic_body_1
           }
        }

     // Marking
     union {
        text {
           ttf global_fontfile_eagle3d "j" 0.02, 0
           scale 2
           rotate <90,0,0>
           translate <-2.8,3.21,-0.8>
           }
        text {
           ttf global_fontfile_arial_bold "+" 0.02, 0
           scale 1
           rotate <90,0,0>
           translate <+2.3,3.21,+2>
           }
        text {
           ttf global_fontfile_arial_bold "-" 0.02, 0
           scale 1
           rotate <90,0,0>
           translate <-2.7,3.21,+2>
           }
        text {
           ttf global_fontfile_arial_bold "~" 0.02, 0
           scale 1
           rotate <90,0,0>
           translate <+2.3,3.21,-3>
           }
        text {
           ttf global_fontfile_arial_bold "~" 0.02, 0
           scale 1
           rotate <90,0,0>
           translate <-2.7,3.21,-3>
           }
        texture {
           col_bright_marking
           }
        }

     //Pins
     union {
        object {
           IC_SMD_PIN(1.5,1.5,1.2,0.3)
           rotate -90*y
           translate <-2.5,0,3>
           }
        object {
           IC_SMD_PIN(1.5,1.5,1.2,0.3)
           rotate -90*y
           translate <+2.5,0,3>
           }
        object {
           IC_SMD_PIN(1.5,1.5,1.2,0.3)
           rotate +90*y
           translate <-2.5,0,-3>
           }
        object {IC_SMD_PIN(1.5,1.5,1.2,0.3)
           rotate +90*y
           translate <+2.5,0,-3>
           }
        texture {
           col_silver
           }
        }
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=DIODE_SMT_BRIDGE_DFS(:SMT Full Bridge rectifier
// end assignment
