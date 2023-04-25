/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Vishay SMT full bridge rectifier MB...S
 *   - MB1S, MB2S, MB4S, MB6S, MB8S
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  16/12/06
 *
 * modified && renamend: 20220504, wk
 ******************************************************************************/
#macro DIODE_SMT_BRIDGE_MBS(value)
  union {
     //Body
     difference {
        box {
           <-2.35,0.3,-1.95><+2.35,2.65,+1.95>
           }
        box {
           <-2.36,-0.5,0.5><+2.36,0.5,-0.5>
           rotate +45*x
           translate <0,2.65+0.1,-1.95-0.1>
           }
        box {
           <-2.36,-0.5,0.8><+2.36,0.5,-0.8>
           rotate +80*x
           translate <0,2.65-0.5,+1.95+0.4>
           }
        box {
           <-2.36,-0.5,0.8><+2.36,0.5,-0.8>
           rotate -80*x
           translate <0,2.65-0.5,-1.95-0.4>
           }
        box {
           <-2.36,-0.5,0.8><+2.36,0.5,-0.8>
           rotate -80*x
           translate <0,1.325-0.5,+1.95+0.4>
           }
        box {
           <-2.36,-0.5,0.8><+2.36,0.5,-0.8>
           rotate +80*x
           translate
           <0,1.325-0.5,-1.95-0.4>
           }
        box {
           <-1,-0.5,2><+1,0.5,-2>
           rotate +80*z
           translate <-2.5-0.2,2.65-0.5,0>
           }
        box {
           <-1,-0.5,2><+1,0.5,-2>
           rotate -80*z
           translate <-2.5-0.2,1.325-0.5,0>
           }
        box {
           <-1,-0.5,2><+1,0.5,-2>
           rotate -80*z
           translate <+2.5+0.2,2.65-0.5,0>
           }
        box {
           <-1,-0.5,2><+1,0.5,-2>
           rotate +80*z
           translate <+2.5+0.2,1.325-0.5,0>
           }
        texture {
           col_ic_body_1
           }
        }

     // Marking
     union {
        #local code = value;

        #if (value = "MB1S")
           #local code = "1";
        #end
        #if (value = "MB2S")
           #local code = "2";
        #end
        #if (value = "MB4S")
           #local code = "4";
        #end
        #if (value = "MB6S")
           #local code = "6";
        #end
        #if (value = "MB8S")
           #local code = "8";
        #end

        text {
           ttf global_fontfile_arial_bold code 0.02, 0
           scale 1.2
           rotate<90,180,0>
           translate<+0.45,2.66,-0.2>
           }  
        text {
           ttf global_fontfile_arial_bold "2N3" 0.02, 0
           scale 1.2
           rotate <90,180,0>
           translate <+1.2,2.66,+1.3>
           }
        text {
           ttf global_fontfile_arial_bold "-" 0.02, 0
           scale 1
           rotate <90,0,0>
           translate <+1.07,2.66,-1.35>
           }
        text {
           ttf global_fontfile_arial_bold "+" 0.02, 0
           scale 1
           rotate <90,0,0>
           translate <-1.27,2.66,-1.4>
           }
        texture {
           col_bright_marking
           }
        }

     //Pins
     union {
        object {
           IC_SMD_PIN(1.5,1.5,0.6,0.3)
           rotate -90*y
           translate <-1.27,0,1.9>
           }
        object {
           IC_SMD_PIN(1.5,1.5,0.6,0.3)
           rotate -90*y
           translate <+1.27,0,1.9>
           }
        object {
           IC_SMD_PIN(1.5,1.5,0.6,0.3)
           rotate +90*y
           translate <-1.27,0,-1.9>
           }
        object {
           IC_SMD_PIN(1.5,1.5,0.6,0.3)
           rotate +90*y
           translate <+1.27,0,-1.9>
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
//rectifier:SOIC-4=DIODE_SMT_BRIDGE_MBS(:SMT Full Bridge rectifier
// end assignment
