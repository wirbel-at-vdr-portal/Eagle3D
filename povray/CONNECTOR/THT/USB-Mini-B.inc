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





#macro CON_SMT_USB_Mini_B()
  union {
     #local R = 0.3;
     #local Thickness = (7.7-6.9)/2;
     //BENT_PLANE_OUTER(xLength,BendLength,Width,Thickness,R,Angle)

     /*
     intersection {
        union {
           Round_Box(
              <-7.7/2,3.95-2*d-1.22,-(2*R+9-1.5)>
              <+7.7/2,3.95         ,  2*R+1.5   >
              R 0
              )
        
           Round_Box(
              <-(5.87+2*d)/2,          0,-(2*R+9-1.5)>
              <+(5.87+2*d)/2,3.95-1.75+d,  2*R+1.5   >
              R 0
              )
           }
        union {
           box {
              <-7.8/2,3.95-d-1.74,-(9-1.5)>
              <+7.8/2,3.95+0.1   ,+1.5-d  >
              }
           box {
              <-(5.87+2*d)/2-0.01,-0.1       ,-(9-1.5)>
              <+(5.87+2*d)/2+0.01,3.95-1.22-d,+1.5    >
              }

           }
        }*/

     #local SOL = object {
         BENT_PLANE_OUTER(7.7/2,1.22+Thickness,9-1.5/2,Thickness,R,90)
         translate <-7.7/2,-3.95,0>
         rotate <0,180,180>
         };
     ROTATE(SOL,2,180)
     #local SUL = object {
         BENT_PLANE_OUTER(7.7/2,1.22+Thickness,9-1.5/2,Thickness,R,90)
         translate <-7.7/2,-3.95,0>
         rotate <0,0,180>
         };

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
