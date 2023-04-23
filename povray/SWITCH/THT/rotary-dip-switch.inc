/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT Rotary DIP Switches
 * Nigel Eke <nigel@eke.name>
 * *****************************************************************************/
#macro SW_RDIP_BASE(nrPositions, V)
  #local pin = cylinder {
     <0,-3,0> <0,0,0> 0.25
     texture {
        col_gold
        }
     }
  #local dial = cylinder {
     <0,3.75,0> <0,3.91,0> 1.5
     pigment {
        NewTan
        }
     }
  #local arrow = union {
     box {
        <-0.25,3.76,-1> <0.25,4,0.75>
        }
     box {
        <-.35,3.76,-.35> <.35,4,0.35>
        rotate <0,45,0>
        translate <0,0,0.75>
        }
     pigment {
        MediumWood
        }
     }
  #local housing = difference {
     box {
        <-3.9,0,-3.9> <3.9,3.9,3.9>
        }
     #if (V = 0)
        box {
           <-3.91,-.01,3.65> <-3.65,3.91,3.91>
           }
     #else
        box {
           < 3.91,-0.01,3.65> < 3.65,3.91,3.91>
           }
     #end
     pigment {
        SteelBlue
        }
     }
  #local notch = cylinder {
     <0,0,0> <0,3.91,0> 0.2
     pigment {
        NewTan
        }
     }

  union {
     difference {
        object {
           housing
           }
        object {
           dial
           }
        }
     difference {
        object {
           dial
           }
        object {
           arrow
           }
        }
     #if (V=0)
        object {
           notch
           translate<-3.4,0,3.4>
           }
     #else
        object {
           notch
           translate< 3.4,0,3.4>
           }
     #end
     // pins
     #if (V = 0)
        #for(i,0,2)
           object {
              pin
              translate<-3,0,(i-1)*2>
              }
           #if (i != 1)
              object {
                 pin
                 translate <3,0,(i-1)*2>
                 }
           #end
        #end
     #else
        object {
           pin
           translate <-3,0,3>
           }
        object {
           pin
           translate <-1,0,3>
           }
        object {
           pin
           translate < 1,0,3>
           }
        object {
           pin
           translate < 3,0,3>
           }
        object {
           pin
           translate <-1,0,-3>
           }
     #end

     #local chars = "0123456789ABCDEF";
     #local i = 0;
     #for(i,0,nrPositions-1)
        text {
           ttf besch_font substr(chars, i+1, 1) .01, 0
           pigment {
              NewTan
              }
           scale 1.5
           rotate <90,0,0>
           translate <-.5,0,0>
           translate <0,0,2.2>
           rotate <0,i*360/nrPositions,0>
           translate <0,3.91,0>
           }
     #end
     rotate <0,180,0>
     scale 2.54/2
     }
#end

#macro SWITCH_THT_RDIP10()
  SW_RDIP_BASE(10, 0)
#end

#macro SWITCH_THT_RDIP16()
  SW_RDIP_BASE(16, 0)
#end

#macro SWITCH_THT_RDIP10_1()
  SW_RDIP_BASE(10, 1)
#end

#macro SWITCH_THT_RDIP16_1()
  SW_RDIP_BASE(16, 1)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//switch-dil:A1353BCD=SWITCH_THT_RDIP10(:Rotary-Dip BCD switch
//switch-dil:A1353HEX=SWITCH_THT_RDIP16(:Rotary-Dip HEX switch
//switch-dil:S20BCD=SWITCH_THT_RDIP10_1(:Rotary-Dip BCD switch
//=SWITCH_THT_RDIP10_1(:Rotary-Dip BCD switch
//switch-dil:S10HEX=SWITCH_THT_RDIP16_1(:Rotary-Dip HEX switch
//switch-dil:DRS3016=SWITCH_THT_RDIP16_1(:Rotary-Dip HEX switch
// end assignment
