/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * USB-Mini-Buchse, MOLEX 54919-0578
 * hebel23 <hebel(replace with at)hebel23.de>
 * 24.10.2004
 * RS 418-0172
 ******************************************************************************/
#macro CON_USB_B_002()
union {
    union {      
     // Blechgehaeuse                    
    difference {      
    union {      
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)translate<-3.355,0.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,180,0>translate<3.355,0.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1)translate<-3.85,2.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1)rotate<0,180,0>translate<3.85,2.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1.3)rotate<0,0,180>translate<-3.35,2.2,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1.3)rotate<0,180,180>translate<3.35,2.2,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,0,180>translate<3.85,3.85,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,180,180>translate<-3.85,3.85,-4>}
         }     
          box { <-4.5, -0.1, -2.9>, <4.5,2.75,-9> }       
             difference {                                                                           
             cone {<-2.5,4,-4.5> , 0.75 , <-2.5,4,-1> , 0.5}
             cone {<-2.5,4,-4.5> , 0.5 , <-2.5,4,-2> , 0.25}
                }
             difference {                                                                          
             cone {<2.5,4,-4.5> , 0.75 , <2.5,4,-1> , 0.5}
             cone {<2.5,4,-4.5> , 0.5 , <2.5,4,-2> , 0.25}
                }
             difference {                                                                           
             box { <-0.75, 3, -1>, <0.75,5,-6> }      
             box { <-0.5, 3, -1>, <0.5,5,-5> }      
                }
          }
     // Loetfahnen
     difference {     
     union {
          union {TOOLS_RECT_BOGEN(0.5,90,0.25,5.5,0.5,2.5)translate<3.85,0.1,-5.75>}
          union {TOOLS_RECT_BOGEN(0.5,90,0.25,5.5,0.5,2.5)rotate<0,180,0>translate<-3.85,0.1,-5.75>}
          }
                box { <-4.01, -0.1, -5>, <-5.1,1,-7> }     
                box { <4.01, -0.1, -5>, <5.1,1,-7> }       
          }
          texture{col_silver}
         }
     // schwarzer Kontakttraeger in der Mitte
        difference {
                box { <-2.5,1,-1>,<2.5,2,-7>} 
                box { <-0.25,1.25,0>,<0.25,1.75,-8>} 
                box { <-1.00,1.25,0>,<-0.50,1.75,-8>} 
                box { <-1.75,1.25,0>,<-1.25,1.75,-8>} 
                box { <1.00,1.25,0>,<0.50,1.75,-8>} 
                box { <1.75,1.25,0>,<1.25,1.75,-8>} 
                texture{pigment{color rgb <0.1, 0.1, 0.1>}}
                }
     // schwarzer Kontakttraeger Hinten
         difference {
                box { <-3.75,0,-6>,<3.75,3.75,-8.5>} 
                box { <-2,1.9,-7>,<3,4,-8.6>} 
                box { <-4,3,-8>,<4,4,-8.6>} 
                box { <-3,-0.1,-7.5>,<3,4,-8.6>} 
                box { <-0.25,-0.1,0>,<0.25,2,-8.6>} 
                box { <-1.00,-0.1,0>,<-0.50,2,-8.6>} 
                box { <-1.75,-0.1,0>,<-1.25,2,-8.6>} 
                box { <1.00,-0.1,0>,<0.50,2,-8.6>} 
                box { <1.75,-0.1,0>,<1.25,2,-8.6>} 
                texture{pigment{color rgb <0.1, 0.1, 0.1>}}
                }                
        // Kontakte
                difference {
                union {
                      union {TOOLS_RECT_BOGEN(0.25,90,0.25,3.5,1,0.65)rotate<0,90,0>translate<0,0.125,-7.3>}
                      union {TOOLS_RECT_BOGEN(0.25,90,0.25,3.5,0,0)rotate<180,270,0>translate<0,1.5,-7.3>}
                      box { <-0.25,1.5,-1>,<0.25,1.75,-7>rotate<7,0,0>} 
                      box { <-1.00,1.5,-1>,<-0.50,1.75,-7>rotate<7,0,0>} 
                      box { <-1.25,1.5,-1>,<-1.75,1.75,-7>rotate<7,0,0>} 
                      box { <1.00,1.5,-1>,<0.50,1.75,-7>rotate<7,0,0>} 
                      box { <1.25,1.5,-1>,<1.75,1.75,-7>rotate<7,0,0>} 
                     }   
                box { <-0.5,-0.1,-7>,<-0.25,1.25,-9.5>}      
                box { <0.5,-0.1,-7>,<0.25,1.25,-9.5>}      
                box { <-1.0,-0.1,-7>,<-1.25,1.25,-9.5>}      
                box { <1.0,-0.1,-7>,<1.25,1.25,-9.5>}      
                texture{col_silver}
                }
        // Aufkleber
                union {
                box{<-3.2,3.9,-0.5><3.2,4.05,-7>}
                pigment{color rgbf <1, 0, 0, 0.9>}
               }
}
#end


     //BENT_PLANE_OUTER(xLength,BendLength,Width,Thickness,R,Angle)


#macro CON_SMT_USB_Mini_B()
  union {
     #local R = 0.3;
     #local Thickness = (7.7-6.9)/2;
     #local PadLength = 1.5;
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
                 object {
                     ROTATE(S5,2,180)
                     rotate <-90,0,0>
                     translate <0,N,1.4>
                     }
                 translate <0,0,-2.0/2>
                 }
              box {
                 <-8/2,-0.1     ,-(4.25+2/2+0.75*Thickness)>
                 <+8/2,3.55-1.22,+1.5/2+0.1>
                 }
              }
           GRID(
              box {
                 <-Thickness/2,      0.1,-4.25-2/2>
                 <+Thickness/2,3.55-1.22,+1.5/2>
                 },
              7.7-Thickness,2,1
              )
           object {
              ROTATE(
                 object {
                    BENT_PLANE_OUTER(1.5,1,2,Thickness,R,90)
                    translate <6.9/2,0,0>
                    },
                 2,180
                 )
              translate <0,0,-4.25>
              }
           object {
              ROTATE(
                 object {
                    BENT_PLANE_OUTER(1.5,1,1.5,Thickness,R,90)
                    translate <6.9/2,0,0>
                    },
                 2,180
                 )
              translate <0,0,0>
              }
           }
        union {
           Round_Box (
              <-8/2,-0.1    ,-(4.25+2/2+0.75*Thickness)>
              <+8/2,3.55-0.9,-(4.25+2/2)               >
              0.2 0
              )
           Round_Box (
              <-8/2,-0.1       ,-4.25+2/2               >
              <+8/2,2*Thickness,-4.25+2/2+0.75*Thickness>
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
     box {
        <-5.8/2,3.95,-1.5>
        <+5.8/2,4.03,-7.5>
        pigment {
           rgbf <1,0,0,0.9>
           }
        }
     intersection {
        box {
           <-8/2,3.95-Thickness,-8>
           <+8/2,3.951         , 0>
           }
        union {
           cone {
              <0,3.95-Thickness/2,-7.0> 1.2/2
              <0,3.95-Thickness/2,-3.7> 0.9/2
              }
           cone {
              <+4.8/2,3.95,-4.25> 1.0/2
              <+4.8/2,3.95,-6.8>  0.6/2
              }
           cone {
              <-4.8/2,3.95,-4.25> 1.0/2
              <-4.8/2,3.95,-6.8>  0.6/2
              }
           }
        }


     difference {
        union {
           box {
              <-4.8/2,3.55-1.22,-(9-1.5/2-1.0)>
              <+4.8/2,    +0.60,   -1.5/2     >
              }
           Round_Box (
              <-7.2/2,Thickness,-0.1>
              <+7.2/2,3.55     ,-1.5>
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
           translate <0,0.5,-5>
           }
        box {
           <-5/2,-1,-1.0>
           <+5/2,+1,+1.0>
           rotate <-20,0,0>
           translate <0,0.5,-8>
           }
        box {
           <-5.8/2,1.0, 0>
           <+5.8/2,3.6,-1>
           }
        box {
           <-4.8/2,-0.1, 0.1>
           <+4.8/2,+3.6,-0.8>
           }

        pigment {
           White*0.3
           }
        }


     GRID(
        object {
/*
 * H: pin height
 * B: pin width
 * T: pin depth
 * S: material strength
*/
           IC_SMD_PIN(2.0,1.5,0.35,0.35)
           rotate <0,-90,0>
           translate <0,0,-1.5>
           },
        0.8,5,1
        )


     texture {
        col_silver
        }
     }

#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
// end assignment
