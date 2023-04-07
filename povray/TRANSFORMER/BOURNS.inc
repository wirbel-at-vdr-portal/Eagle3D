/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Bourns 600ohm 1:1 SMT Transformer SM-LP-5001
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1  12/04/06
 ******************************************************************************/
#macro TRAFO_SM_LP_500X()
  #macro TRAFO_SMD_PIN(H,B,T,S)
     union {
        box {
           <0,H,T/2> <B/4,H-S,-T/2>
           }
        difference {
           cylinder {
              <B/4,H-S,-T/2> <B/4,H-S,T/2> S
              }
           box {
              <-1,H-S,-T/2-0.01> <B/2,H-S-3,T/2+0.01>
              }
           }
        box {
           <B/4,H-S,-T/2> <B/4+S,S,T/2>
           }
        difference {
           cylinder {
              <B/4+S,S,-T/2> <B/4+S,S,T/2> S
              }
           box {
              <0,S,-T/2-0.01> <B,S+3,T/2+0.01>
              }
           }
        box {
           <B/4+S,0,-T/2> <B,S,T/2>
           }
        difference {
           box {
              <B/4+S,S,-T/2> <B/4+S+S/2,1.5*S,T/2>
              }
           cylinder {
              <B/4+S+S/2,S+S/2,T/2+0.01> <B/4+S+S/2,S+S/2,-T/2-0.01>, S/2
              }
           }
        texture {
           col_silver
           }
        }
  #end

  union {
     box {
        <-6.25,1,-4.8> <+6.25,7.1,+4.8>
        pigment {
           Gray20
           }
        }
     text {
        ttf global_fontfile_eagle3d "<" 0.05, 0
        pigment {
           White
           }
        scale 1.8
        rotate <90,0,0>
        translate <-1,7.1+0.05,+2.1>
        } // Marking
     text {
        ttf global_fontfile_courier_bold value 0.05, 0
        pigment {
           White
           }
        scale 2
        rotate <90,0,0>
        translate <-5.8,7.1+0.05,-0.8>
        } // Marking
     text {
        ttf global_fontfile_courier_bold "9545" 0.05, 0
        pigment {
           White
           }
        scale 2
        rotate <90,0,0>
        translate <-2,7.1+0.05,-3.5>
        } // Marking
     object {
        TRAFO_SMD_PIN(1.5,2.0,0.7,0.3)
        translate<4.5,0,-2.54>
        }
     object {
        TRAFO_SMD_PIN(1.5,2.0,0.7,0.3)
        translate<4.5,0,0>
        }
     object {
        TRAFO_SMD_PIN(1.5,2.0,0.7,0.3)
        translate<4.5,0,+2.54>
        }
     object {
        TRAFO_SMD_PIN(1.5,2.0,0.7,0.3)
        rotate 180*y
        translate <-4.5,0,-2.54>
        }
     object {
        TRAFO_SMD_PIN(1.5,2.0,0.7,0.3)
        rotate 180*y
        translate<-4.5,0,0>
        }
     object {
        TRAFO_SMD_PIN(1.5,2.0,0.7,0.3)
        rotate 180*y
        translate<-4.5,0,+2.54>
        }
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=TRAFO_MYRRA_EI_30_1_005(:IE30-5 Transformer 1 secondary wiring
// end assignment
