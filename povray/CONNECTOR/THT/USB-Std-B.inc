/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * USB Connector Type B, AMP-61729
 * PN61729, con-berg.lbr
 * 05.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_USB_Std_B_AMP61729()
  union {
     #local R = 0.5;
     #local Thickness = 0.25;
     difference {
        Round_Box(
           <-12.2/2,    0, +2.0>
           <+12.2/2,10.30,-14.0>
           R 0
           )
        Round_Box(
           <-12.2/2+Thickness,              0, +2.0+Thickness>
           <+12.2/2-Thickness,10.30-Thickness,-14.0+Thickness>
           R 0
           )
        Round_Box(
           <-9.45/2,+5.69-7.78/2-Thickness,-14.0-2*Thickness>
           <+9.45/2,+5.69+2.00/2+1.0      ,-14.0+2*Thickness>
           R 0
           )
        box {
           <-12.5/2,-0.1,+3.0>
           <+12.5/2,+0.5,-4.0>
           }
        box {
           <-12.5/2,-0.1, -4.0>
           <+12.5/2,+0.7,-15.0>
           }
        box {
           <-2.5/2,-2.5/2,-14.0-2*Thickness>
           <+2.5/2,+2.5/2,-14.0+2*Thickness>
           rotate <0,0,45>
           translate <-3.0,7.5,0>
           }
        box {
           <-2.5/2,-2.5/2,-14.0-2*Thickness>
           <+2.5/2,+2.5/2,-14.0+2*Thickness>
           rotate <0,0,45>
           translate <+3.0,7.5,0>
           }
        box {
           <-6.00/2,+9.3,-14.0-2*Thickness>
           <+6.00/2,  +3,-14.0+2*Thickness>
           }
        box {
           <-10.5/2,5.69-0.8-4/2,-14.0-2*Thickness>
           <+10.5/2,5.69-0.8+4/2,-14.0+2*Thickness>
           }
        box {
           <-4/2,  8,-14.0-2*Thickness>
           <+4/2,9.8,-14.0+2*Thickness>
           }
        texture {
           col_silver
           }
        }
     union {
        object {
           BENT_PLANE_OUTER(1.5,2,3.5,Thickness,R,90)
           rotate <90,0,0>
           translate <+9.45/2-0.8,5.69-0.8,-14>
           }
        object {
           BENT_PLANE_OUTER(1.5,2,3.5,Thickness,R,90)
           rotate <-90,180,0>
           translate <-9.45/2+0.8,5.69-0.8,-14>
           }
        object {
           BENT_PLANE_OUTER(1.5,2,3.5,Thickness,R,90)
           rotate <90,0,90>
           translate <0,8.35,-14>
           }
        texture {
           col_silver
           }
        }
     union {
        #local pin =
            intersection {
               Round_Box(
                  <-1.8/2,   1,-1.8/2>
                  <+1.8/2,-2.1,+1.8/2>
                  R 0
                  )
               box {
                  <-Thickness/2,+2,-2>
                  <+Thickness/2,-3,+2>
                  }
               translate <0,0,-3.71>
               };
        GRID(pin,12.0,2,1)
        texture {
           col_silver
           }
        }
     difference {
        Round_Box(
           <-12.2/2+Thickness,              0, +2.0+Thickness>
           <+12.2/2-Thickness,10.30-Thickness,-14.0+Thickness>
           R 0
           )
        box {
           <-8.45/2,+5.69-3.18/2,-14.0-2*Thickness>
           <+8.45/2,        +1.9,-14.0+10>
           }
        box {
           <-5.70/2,+5.69+3.18/2,-14.0-2*Thickness>
           <+5.70/2,        +8.8,-14.0+10>
           }
        box {
           <-2.1/2,-1.2/2,-14.0-2*Thickness>
           <+2.1/2,+1.3/2,-14.0+10>
           rotate <0,0,45>
           translate <-3.1,7.6,0>
           }
        box {
           <-2.1/2,-1.3/2,-14.0-2*Thickness>
           <+2.1/2,+1.3/2,-14.0+10>
           rotate <0,0,-45>
           translate <+3.1,7.6,0>
           }
        box {
           <-8.45/2,+7.4 ,-14.0-2*Thickness>
           <-5.60/2,+1.91,-14.0+10>
           }
        box {
           <+8.45/2,+7.4 ,-14.0-2*Thickness>
           <+5.60/2,+1.91,-14.0+10>
           }
        box {
           <-6/2,-1.0/2,-1.0/2>
           <+6/2,+1.0/2,+1.0/2>
           rotate <45,0,0>
           translate <0,5.69+3.18/2,-14>
           }
        box {
           <-6/2,-1.0/2,-1.0/2>
           <+6/2,+1.0/2,+1.0/2>
           rotate <45,0,0>
           translate <0,5.69-3.18/2,-14>
           }
        box {
           <-1/2,-4.0/2,-1.0/2>
           <+1/2,+4.0/2,+1.0/2>
           rotate <0,45,0>
           translate <+5.6/2,5.69,-14>
           }
        box {
           <-1/2,-4.0/2,-1.0/2>
           <+1/2,+4.0/2,+1.0/2>
           rotate <0,45,0>
           translate <-5.6/2,5.69,-14>
           }
        texture {
           pigment { White * 0.6 }
           }
        }
     object {
        GRID(GRID(PIN_STRAIGHT(1.0,3,3),2.5,2,1),2.90,1,2)
        rotate <90,0,0>
        translate <0,5.69,-9.0>
        texture {
           col_gold
           }
        }
     GRID(
        GRID(
           object {
              PIN_STRAIGHT(0.40,1,2.84)
              texture {
                 col_gold
                 }
              },
           2.50,2,1),
        2.00,1,2
        )
     translate <0,0,3.71>
     }
#end

/*******************************************************************************
 * USB Connector Type B shielded, AMP 61729-0010BLF
 * PN61729-S, con-berg.lbr
 * 05.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_USB_Std_B_AMP61729S()
  union {
     CON_THT_USB_Std_B_AMP61729()
     difference {
        #local R = 0.5;
        #local Thickness = 0.25;
        #local Yt = +2.0+3.71+R;
        #local Yb = -1.5+3.71+R;
        Round_Box(
           <-(12.2+R)/2,    0,Yt>
           <+(12.2+R)/2,10.29,Yb>
           R 0
           )
        box {
           <-4/2, 9.7,Yt+R>
           <+4/2,10.5,Yt-R>
           }
        box {
           <+13/2, 9.7,Yt+R>
           < +9/2,10.5,Yt-R>
           }
        box {
           <-13/2, 9.7,Yt+R>
           < -9/2,10.5,Yt-R>
           }
        box {
           <-13/2,-0.1,Yt+R>
           <+13/2,+0.7,Yt-5>
           }
        box {
           <-13/2,-1.5,-1.5>
           <+13/2,+1.5,+1.5>
           rotate <30,0,0>
           translate <0,0.1,Yb>
           }
        box {
           <-13/2,-1.5,-1.5>
           <+13/2,+1.5,+1.5>
           rotate <60,0,0>
           translate <0,5.69+1.5,Yb-0.6>
           }
        box {
           <-13/2, 6.7,Yt-2.0>
           <+13/2,11.0,Yb-0.5>
           }
        box {
           <-13/2,2.7,Yt-1.0>
           <+13/2,4.7,Yb+1.0>
           }
        }
     Round_Box (
        <-12.6/2,2.8,Yt-1.1>
        <+12.6/2,4.5,Yb+1.1>
        0.4 0
        )
     texture {
        col_silver
        }
     }
#end


/*******************************************************************************
 * Cypress Industries 85-32004-10X
 * 85-32004-10x.pdf
 * con-cypressindustries
 * 05.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_USB_Std_B_85_32004_10X()
  object {
     CON_THT_USB_Std_B_AMP61729S()
     rotate <0,90,0>
     translate <0,0,0>
     }
#end





/*******************************************************************************
 * USB-Mini-Buchse, MOLEX 54919-0578
 * hebel23 <hebel(replace with at)hebel23.de>
 * 24.10.2004
 * RS 418-0172
 ******************************************************************************/
#macro CON_USB_B_002_BASE()
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
#macro CON_USB_B_002()
CON_USB_B_002_BASE()
#end




/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
// end assignment
