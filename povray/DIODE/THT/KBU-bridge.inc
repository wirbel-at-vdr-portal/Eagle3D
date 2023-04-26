/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Vishay KBU full bridge rectifier (4/6/8 amps)
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0 30/12/05
 ******************************************************************************/
#macro DIODE_THT_BRIDGE_KBU(value)
  union {
     difference {
        union {
           box {
              <-11,0,-3.19> <11,+19.3,+3.81>
              }
           }
        union {
           box {
              <-0,-5,-4> <+5,+5,+6>
              rotate -60*z
              translate <-15,+22,0>
              }
           box {
              <-0,-5,-4> <+5,+5,+6>
              rotate 45*z
              translate <+9,+17.3,0>
              }
           intersection {
              cylinder {
                 <0,10,-5> <0,10,+5> 2.5
                 }
              box {
                 <-2,5,-5> <+2,15,+5>
                 }
              }
           box {
              <-8.9,-.1,-5> <8.9,+1.5,+5>
              }
           box {
              <-0,-5,-4> <+5,+5,+6>
              rotate -30*z
              translate <-11.5,-2.8,0>
              }
           box {
              <-0,-5,-4> <+5,+5,+6>
              rotate -30*z
              translate <-11.5,-2.8,0>
              rotate 180*y
              }
           }
        pigment {
           Gray25
           }
        }
     cylinder {
        <-7.5,2,2.54> <-7.5,-min(25,(pin_length+pcb_height)),2.54> .5
        texture {
           pigment {
              P_Silver2
              }
           }
        }
     cylinder {
        <-2.5,2,2.54> <-2.5,-min(25,(pin_length+pcb_height)),2.54> .5
        texture {
           pigment {
              P_Silver2
              }
           }
        }
     cylinder {
        <+2.5,2,2.54> <+2.5,-min(25,(pin_length+pcb_height)),2.54> .5
        texture {
           pigment {
              P_Silver2
              }
           }
        }
     cylinder {
        <+7.5,2,2.54> <+7.5,-min(30,(pin_length+pcb_height)),2.54> .5
        texture {
           pigment {
              P_Silver2
              }
           }
        }
     text {
        ttf global_fontfile_eagle3d "1" -0.05, 0
        pigment {
           White
           }
        scale 5  translate<3,4,-2.95>
        }
     text {
        ttf global_fontfile_arial "+" -0.05, 0
        pigment {
           White
           }
        scale 2
        translate <7,2,-3.1>
        }
     text {
        ttf global_fontfile_arial "~" -0.05, 0
        pigment {
           White
           }
        scale 2
        translate <7-5,2,-3.1>
        }
     text {
        ttf global_fontfile_arial "~" -0.05, 0
        pigment {
           White
           }
        scale 2
        translate <7-10,2,-3.1>
        }
     text {
        ttf global_fontfile_arial "-" -0.05, 0
        pigment {
           White
           }
        scale 2
        translate <7-15,2,-3.1>
        }
     text {
        ttf global_fontfile_arial_bold value -0.05, 0
        pigment {
           White
           }
        scale 2.5
        translate <7-12,15,-3.1>
        }
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rectifier:KBU=DIODE_THT_BRIDGE_KBU(:DIODE_THT_BRIDGE_KBU
// end assignment
