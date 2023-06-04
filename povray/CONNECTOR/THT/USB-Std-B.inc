/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * USB Connector Type B, AMP 787780
 * Friedrich Bleikamp, <fbleikamp(replace with at)web.de>
 * 22.03.2004
 ******************************************************************************/
#macro CON_USB_B_001()
union {

#macro SHELL_PIN_USB_B()
   merge {
      difference {
         box { <-0.2,-3.5,-1.15> <0.2,0.5,1.15>}
         box { <-0.21,-4,-1.15> <0.21,1,1.15> translate <0,0,2.3> rotate<6.5,0,0>}
         box { <-0.21,-4,-1.15> <0.21,1,1.15> translate <0,0,-2.3> rotate<-6.5,0,0>}
      }
      cylinder { <-0.2,0,0> <0.2,0,0>, 0.75 translate <0,-3.5,0>}
   }texture{col_silver}
#end

   //Metall shell
   union {
      difference {
         union {
            box { <0,0.5,-5.6> <0.4,10.7,5.6>}                 // front
            box { <0.6,0.5,5.8> <11.5,10.8,6.2>}               // left side
            box { <0.6,0.5,-5.8> <11.5,10.8,-6.2>}             // right side
            object{ TOOLS_RECT_BOGEN(0.2,90,0.4,10.0,0,0) rotate<0,90,-90> translate<0.2,5.5,6.0>}      
            object{ TOOLS_RECT_BOGEN(0.2,90,0.4,10.0,0,0) rotate<0,-90,-90> translate<0.2,5.5,-6.0>}      
         }    
         box { <-1,-1,-6.5> <1,1,6.5> translate<8.5,3.6,0>}       // cutout bottom
         box { <-1,-1,-6.5> <1,1,6.5> translate<8.5,7.6,0>}       // cutout top
         box { <-0.4,-0.25,-6.5> <0.4,0.25,6.5> translate<0.35,2.75,0>}// cutout front
         cylinder { <0,0,-6.5> <0,0,6.5>, 0.25 translate <0.75,2.75,0>} 
         box { <-0.4,-0.25,-6.5> <0.4,0.25,6.5> translate<0.35,6.25,0>}// cutout front
         cylinder { <0,0,-6.5> <0,0,6.5>, 0.25 translate <0.75,6.25,0>} 
         prism {linear_sweep linear_spline 0, 0.6, 7,             // cutout front
         < 0,-4.85>, < 6,-4.85>, < 7.85,-3.0>, < 7.85,3.0>, < 6,4.85>, <0,4.85>,< 0,-4.85>
         rotate<0,0,90> translate <0.5,1.5,0>}
      }
   box { <0.6,10.9,-5.8> <11.5,11.3,5.8>}                      // top
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,11.2,0,0) rotate<0,0,-90> translate<0.2,11.1,0>}      
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,3,3,1) rotate<90,0,0> translate<0.2,4.5,4.2>}      
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,3,3,1) rotate<-90,0,0> translate<0.2,4.5,-4.2>}      
   object{ SHELL_PIN_USB_B() rotate<0,90,0> translate<10.3,0.5,6.0>}
   object{ SHELL_PIN_USB_B() rotate<0,90,0> translate<10.3,0.5,-6.0>}   
   texture{col_silver}
   }
   
   //Housing: Thermoplastic, glass filled (UL94V-0)
   union { 
      difference {
         TOOLS_ROUNDED_BAR(<-5.5,0.4,0>,<5.5,10.9,15.3>,0.5)
         box { <-4.0,1.5,-0.1> <4.0,8.5,3.5> } 
         box { <-1.7,0,-0.1> <-0.8,8.5,4.5> }
         box { <0.8,0,-0.1> <1.7,8.5,4.5> }
         box { <-5.6,4.2,-0.1> <5.6,7.7,3.4> }   
         object{ TOOLS_ROUNDED_BAR(<-4.25,2.0,8.5>,<4.25,7.0,16.1>,0.5)} 
         object{ TOOLS_ROUNDED_BAR(<-2.90,7.0,8.5>,<2.90,8.5,16.1>,0.5)} 
         object{ TOOLS_ROUNDED_BAR( <-1.41,-1.41,8.5> <1.41,1.41,16.1>,0.5) rotate<0,0,45> translate<2.45,6.6,0>}
         object{ TOOLS_ROUNDED_BAR( <-1.41,-1.41,8.5> <1.41,1.41,16.1>,0.5) rotate<0,0,45> translate<-2.45,6.6,0>}
      }
   object{ Round_Box_Union( <-2.8,3.7,8.5> <2.8,6.7,15.5>,0.5)}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<5.7,2.0,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<-5.7,2.0,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<5.7,9.75,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<-5.7,9.75,0>} 
   box { <-6.0,-0.7,-1> <6.0,0.7,0.6> translate<0,3.5,7>}
   box { <-6.0,-0.7,-1> <6.0,0.7,0.6> translate<0,7.5,7>}
   pigment{Gray25} rotate<0,-90,0> translate<15.7,0,0>
   } 

   //Contacts
   union {
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,12.2,7.25) rotate<0,0,180> translate<13.0,3.6,-1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,12.2,7.25) rotate<0,0,180> translate<13.0,3.6,1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,14.2,10.25) rotate<0,0,180> translate<15.0,6.8,-1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,14.2,10.25) rotate<0,0,180> translate<15.0,6.8,1.25>}
      texture{col_gold}     
   }
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
 * USB-B THT 90deg, AMPHENOL 61729-0010BLF
 * 20220417, -wk
 ******************************************************************************/
#macro CON_THT_USB_B_61729()
union {
  object { CON_USB_B_001() rotate<0,-90,0> translate<0,0,-10.3> }
  box { <-11.6/2,10.8, 0> < 11.6/2, 11.3,16-10.3-0.3> } // top side
  box { <-12.4/2, 0.5,-8> <-11.6/2, 10.8,16-10.3-0.3> } // left side
  box { <+12.4/2, 0.5,-8> <+11.6/2, 10.8,16-10.3-0.3> } // right side
  box { <-12.4/2, 0.5,16-10.3-0.3> <+12.4/2, 10.8,16-10.3> } // back side
  cylinder { <-12.4/2, 0.5,16-10.3-0.3> <-12.4/2,10.8,16-10.3-0.3> 0.25}
  cylinder { <+12.4/2, 0.5,16-10.3-0.3> <+12.4/2,10.8,16-10.3-0.3> 0.25}
  box      { <-12.4/2, 0.5,16-10.3-0.3-2> <-12.9/2, 10.8,16-10.3-0.3> } // left side
  box      { <+12.4/2, 0.5,16-10.3-0.3-2> <+12.9/2, 10.8,16-10.3-0.3> } // left side
  texture{col_silver}
  }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
// end assignment
