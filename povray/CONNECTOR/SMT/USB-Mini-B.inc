/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Mini USB-B connector.
 * 11.06.2023, wk
 * 
 * Type:
 *     Molex   54819-1572 = ""
 *     Molex   54819-0519 = "C32005_601"
 *     Cypress 32005-201  = "C32005_201"
 *     Cypress 32005-301  = "C32005_301"
 *     Cypress 32005-400  = "C32005_400"
 *     Cypress 32005-501  = "C32005_501"
 *     Cypress 32005-601  = "C32005_601"
 ******************************************************************************/
#macro CON_SMT_USB_Mini_B(Type)
  union {
     #local R = 0.3;
     #local Thickness = (7.7-6.9)/2;
     #local PadLength = 1.5;
     #local CutLen = 4.25+2/2+0.75*Thickness;
     #local PinWidth = 2.0;
     #local xOffset = 4.25;
     #local StubOffset = 0;
     #if ((Type = "C32005_201") | (Type = "C32005_301") | (Type = "C32005_400") | (Type = "C32005_501") | (Type = "C32005_601") |
          (Type = "Seeed013A"))
        #local CutLen = 9 - 1.5/2 - 2.2;
        #local PinWidth = 1.5;
        #local xOffset = 9 - 1.5/2 - 2.2 - 1.5/2;
     #end
     #if ((Type = "C32005_201") | (Type = "C32005_301"))
        #local StubOffset = 9 - 1.5/2 - 5.90;
     #end
     difference {
        union {
           difference {
              union {
                 #local A = 9;
                 #local B = A - PadLength/2;
                 #local C = 3;
                 #local D = 5.87+2*Thickness;
                 #local E = 7.7;
                 #local F = 3.95;
                 #local G = 1.22+Thickness;
                 #local H = 0.50;
                 #local I = 1.00;
                 #local J = 5.87;
                 #local K = 2.20;
                 #local L = 6.90+2*Thickness;
                 #local M = 0.5;
                 #local N = 2.8;
                 #local S1 = object {
                     BENT_PLANE_OUTER(E/2,G,B,Thickness,R,90)
                     translate <-E/2,-F,0>
                     rotate <0,180,180>
                     };
                 #local S2 = object {
                     BENT_PLANE_OUTER(D/2,G,A,Thickness,R,90)
                     translate <-D/2,0,0>
                     };
                 #local S3 = object {
                     BENT_PLANE_OUTER(H,I,B,Thickness,R,135)
                     rotate <0,0,-90>
                     translate <+J/2,K,0>
                     };
                 #local S4 = object {
                     BENT_PLANE_OUTER(H,I,B,Thickness,R,135)
                     rotate <0,0,+90>
                     translate <+L/2,K,0>
                     };
                 #local S5 = object {
                     BENT_PLANE_OUTER(1.2,1.2,0.7,Thickness,R,93)
                     rotate <0,0,90>
                     translate <+L/2,0,0>
                     };
                 object {
                     ROTATE(S1,2,180)
                     translate <0,0,-B/2+PadLength/2>
                     }
                 object {
                     ROTATE(S2,2,180)
                     translate <0,0,-A/2+PadLength>
                     }
                 object {
                     ROTATE(S3,2,180)
                     translate <0,0,-B/2+PadLength/2>
                     }
                 object {
                     ROTATE(S4,2,180)
                     translate <0,-M,-B/2+PadLength/2>
                     }
                 #if ((Type = "C32005_301") | (Type = "C32005_400"))
                    object {
                        ROTATE(S5,2,180)
                        rotate <-90,0,0>
                        translate <0,N,1.4>
                        }
                 #end
                 translate <0,0,-2.0/2>
                 }
              box {
                 <-8/2,-0.1     ,-CutLen>
                 <+8/2,3.55-1.22,+1.5/2+0.1>
                 }
              }
           GRID(
              box {
                 <-Thickness/2,      0.1,-(CutLen+0.75*Thickness)>
                 <+Thickness/2,3.55-1.22,+1.5/2>
                 },
              7.7-Thickness,2,1
              )
           #local GndPin1 = object {
              BENT_PLANE_OUTER(1.5,1,PinWidth,Thickness,R,90)
              translate <6.9/2,0,0>
              };
           #local GndPin2 = object {
              BENT_PLANE_OUTER(1.5,1,1.5,Thickness,R,90)
              translate <6.9/2,0,0>
              };
           #if ((Type = "C32005_501") | (Type = "Seeed013A"))
              #local GndPin1 = box {
                 <6.9/2+0        ,-1.7,-PinWidth/2>
                 <6.9/2+Thickness, 1.0,+PinWidth/2>
                 };
              #local GndPin2 = box {
                 <6.9/2+0        ,-1.7,-1.5/2>
                 <6.9/2+Thickness, 1.0,+1.5/2>
                 };
           #end
           #if (Type = "C32005_601")
              #local xOffset = 9 - 1.5/2 - 2.2 - 1.5/2 - 0.8;
              #local GndPin1 = box {
                 <6.9/2+0        ,-1.7,-2/2>
                 <6.9/2+Thickness, 1.0,+2/2>
                 };
              #local GndPin2 = union {};
           #end
           object {
              ROTATE(GndPin1,2,180)
              translate <0,0,-xOffset>
              }
           object {
              ROTATE(GndPin2,2,180)
              translate <0,0,0>
              }
           }
        union {
           Round_Box (
              <-8/2,-0.1    ,- CutLen>
              <+8/2,3.55-0.9,-(CutLen+0.75*Thickness)>
              0.2 0
              )
           Round_Box (
              <-8/2,-0.1       ,-CutLen+PinWidth               >
              <+8/2,2*Thickness,-CutLen+PinWidth+0.75*Thickness>
              0.2 0
              )
           Round_Box (
              <-8/2,-0.1       ,-1.5/2               >
              <+8/2,2*Thickness,-1.5/2-0.75*Thickness>
              0.2 0
              )
           Round_Box (
              <-8/2,1.8,-2.5/2>
              <+8/2,2.5,+2.5/2>
              0.3 0
              )
           Round_Cone (
              <0,3.95,-7.0> 2/2
              <0,3.95,-3.0> 1.8/2
              0.15 0)  
           Round_Cone (
              <+4.8/2,3.95,-4.25> 1.5/2
              <+4.8/2,3.95,-7.1>  1.2/2
              0.15 0) 
           Round_Cone (
              <-4.8/2,3.95,-4.25> 1.5/2
              <-4.8/2,3.95,-7.1>  1.2/2
              0.15 0)
           GRID (
              Round_Box (
                 <-2.5/2,4.0,+1.5/2-1.0>
                 <+2.5/2,3.2,+1.5/2+1.0>
                 0.2 0
                 ),
              7.7,2,1
              )
           Round_Box (
              <-3.2/2,4.0,+1.5/2-1.0>
              <+3.2/2,3.2,+1.5/2+1.0>
              0.2 0
              )
           }
        }
     union {
        prism {
           3.95-Thickness, 3.95, 
           5,<+1.2/2,-7.0>,<+0.9/2,-3.7>,<-0.9/2,-3.7>,<-1.2/2,-7.0>,<+1.2/2,-7.0>
           }
        prism {
           3.95-Thickness, 3.95, 
           5,<+1.0/2+4.8/2,-4.25>,<+0.6/2+4.8/2,-6.8>,<-0.6/2+4.8/2,-6.8>,<-1.0/2+4.8/2,-4.25>,<+1.0/2+4.8/2,-4.25>
           }
        prism {
           3.95-Thickness, 3.95, 
           5,<+1.0/2-4.8/2,-4.25>,<+0.6/2-4.8/2,-6.8>,<-0.6/2-4.8/2,-6.8>,<-1.0/2-4.8/2,-4.25>,<+1.0/2-4.8/2,-4.25>
           }
        }
     #if ((Type = "C32005_201") | (Type = "C32005_400"))
        #local A = 1.5;
        #local B = 2.4;
        #local C = 5.5;
        #local D = 3;
        #local S1 = object {
            BENT_PLANE_OUTER(A,B,C,Thickness,R,90)
            rotate <0,90,180>
            translate <0,3.95,1.2>
            };
        #local S2 = object {
            BENT_PLANE_OUTER(D,A,A,Thickness,R,90)
            rotate <0,0,90>
            translate <+4.25,0,0>
            };
        difference {
           object { S1 }
           box {
              <-3.5/2,3,-2>
              <+3.5/2,4,2>
              }
           texture {
              col_silver
              }
           }
        object {
           ROTATE(object{ S2 },2,180)
           rotate <-90,0,0>
           translate <0,2,1.2>
           }
     #end
     difference {
        union {
           box {
              <-4.8/2,3.55-1.22,-(9-1.5/2-1.0)>
              <+4.8/2,    +0.60,   -1.5/2     >
              }
           Round_Box (
              <-7.2/2,Thickness,-0.1>
              <+7.2/2,3.55     ,-1.5>//-1.5>
              R 0
              )
           }
        object {
           ROTATE(
              box {
                 <-2/2,-2/2,-4>
                 <+2/2,+2/2,+4>
                 rotate <0,0,-30>
                 translate <6.0/2,0,0>
                 },
              2,180
              )
           translate <0,0.5,-6>
           }
        box {
           <-5/2,-1,-1.0>
           <+5/2,+1,+1.0>
           rotate <-20,0,0>
           translate <0,0.5,-8>
           }
        box {
           <-5.8/2,1.0, 0>
           <+5.8/2,3.6,-1.2>
           }
        box {
           <-4.8/2,-0.1, 0.1>
           <+4.8/2,+3.6,-1.1>
           }
        object {
           GRID(
              box {
                 <-0.6/2,0.9,-8>
                 <+0.6/2,1.8,-2>
                 },
              0.8,5,1
              )
           }
        pigment {
           White*0.3
           }
        }
     #if ((Type = "C32005_201") | (Type = "C32005_301"))
        GRID(
           cylinder {
              <0,+0.20,-StubOffset>
              <0,-0.65,-StubOffset>
              0.8/2
              pigment {
                 White*0.3
                 }
              },
           4.40,2,1
           )
     #end
     box {
        <-5.8/2,3.95,-1.5>
        <+5.8/2,4.03,-7.5>
        pigment {
           rgbf <1,0,0,0.8>
           }
        }
     #if ((Type = "C32005_201") | (Type = "C32005_301") | (Type = "C32005_400") | (Type = "C32005_501") |
          (Type = "Seeed013A"))
        GRID(
           object {
              IC_SMD_PIN(2.0,2.5,0.35,0.35)
              rotate <0,-90,0>
              translate <0,0,-1.8>
              texture {
                 col_gold
                 }
              },
           0.8,5,1
           )
     #end
     #if (Type = "C32005_601")
        union {
           object {
              GRID(PIN_90deg(0.4,0.5,3.55-1.22,1.8,3),1.60,2,1)
              translate <0,0,-1.2/2>
              }
           object {
              GRID(PIN_90deg(0.4,0.5,3.55-1.22,1.8,3),1.60,3,1)
              translate <0,0,+1.2/2>
              }
           texture {
              col_gold
              }
           }
     #end
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * con-cypressindustries:32005-xxx has strange location && x-offset.
 ******************************************************************************/
#macro USB_Mini_B_32005(Type)
  object {
     CON_SMT_USB_Mini_B(Type)
     rotate <0,90,0>
     translate <1.8098+1.5/2-0.2,0,0>
     }
#end

#macro CON_SMT_USB_Mini_B_32005_201() USB_Mini_B_32005("C32005_201") #end
#macro CON_SMT_USB_Mini_B_32005_301() USB_Mini_B_32005("C32005_301") #end
#macro CON_SMT_USB_Mini_B_32005_400() USB_Mini_B_32005("C32005_400") #end
#macro CON_SMT_USB_Mini_B_32005_501() USB_Mini_B_32005("C32005_501") #end
#macro CON_THT_USB_Mini_B_32005_601() USB_Mini_B_32005("C32005_601") #end


/*******************************************************************************
 * con-hirose:UX60(*) has strange location && x-offset.
 ******************************************************************************/
#macro CON_SMT_USB_Mini_B_UX60AMB5ST() object { CON_SMT_USB_Mini_B_32005_400() translate <-0.4,0,0> } #end
#macro CON_SMT_USB_Mini_B_UX60MB5ST()  object { CON_SMT_USB_Mini_B_32005_301() translate <-0.4,0,0> } #end
#macro CON_THT_USB_Mini_B_UX60MB5S8()  object { CON_SMT_USB_Mini_B_32005_501() translate <+6.0,0,0> } #end

/*******************************************************************************
 * Seeed-OPL-Connector
 ******************************************************************************/
#macro USB_Mini_B_Seeed(Type)
  object {
     CON_SMT_USB_Mini_B(Type)
     rotate <0,-90,0>
     }
#end

#macro CON_SMT_USB_Mini_B_Seeed002A()  object { USB_Mini_B_Seeed("C32005_301") translate <+1.0,0,0> } #end
#macro CON_SMT_USB_Mini_B_Seeed013A()  object { USB_Mini_B_Seeed("Seeed013A")  translate <+0.5,0,0> } #end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-cypressindustries:32005-201=CON_SMT_USB_Mini_B_32005_201(:USB Mini-B
//con-cypressindustries:32005-301=CON_SMT_USB_Mini_B_32005_301(:USB Mini-B
//con-cypressindustries:32005-400=CON_SMT_USB_Mini_B_32005_400(:USB Mini-B
//con-cypressindustries:32005-501=CON_SMT_USB_Mini_B_32005_501(:USB Mini-B
//con-cypressindustries:32005-601=CON_THT_USB_Mini_B_32005_601(:USB Mini-B
//con-hirose:UX60A-MB-5ST=CON_SMT_USB_Mini_B_UX60AMB5ST(:USB Mini-B:
//con-hirose:UX60-MB-5ST=CON_SMT_USB_Mini_B_UX60MB5ST(:USB Mini-B:
//con-hirose:UX60-MB-5S8=CON_THT_USB_Mini_B_UX60MB5S8(:USB Mini-B:
//Seeed-OPL-Connector:MINIUSB5+4P-SMD-0.8-90D=CON_SMT_USB_Mini_B_Seeed002A(:USB Mini-B
//Seeed-OPL-Connector:MINIUSB5+4P-0.8-90D=CON_SMT_USB_Mini_B_Seeed013A(:USB Mini-B
// end assignment
