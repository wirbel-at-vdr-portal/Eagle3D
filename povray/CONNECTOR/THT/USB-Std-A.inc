/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * USB-connector USB-787616, con-amp.lbr
 * hebel23 <hebel(replace with at)hebel23.de>
 * 12.10.2004
 ******************************************************************************/
#macro CON_THT_USB_Std_A_AMP787616()
  union {
     difference { // Blechgehaeuse
        Round_Box ( // Aussenhuelle
           <-7,2,0 >
           <+7,8,14>
           0.5 0
           )
        box { // Aussparung in der Mitte
           <-6.5, 2.5, -1>
           <6.5, 7.5, 14>
           }
        box { // Aussparung hinten
           <-6.5, 0, 12>
           <6.5, 7.5, 15>
           }
        difference {
           cone {
              <-3,8,8> 1.5
              <-3,8,1> 1.0
              }
           cone {
              <-3,8,8> 1
              <-3,8,2> 0.5
              }
           }
        difference { // Feder rechts oben
           cone {
              <3,8,8> 1.5
              <3,8,1> 1.0
              }
           cone {
              <3,8,8> 1
              <3,8,2> 0.5
              }
           }
        difference { // Feder links unten
           cone {
              <-3,2,8> 1.5
              <-3,2,1> 1.0
              }
           cone {
              <-3,2,8> 1
              <-3,2,2> 0.5
              }
           }
        difference { // Feder rechts unten
           cone {
              <3,2,8> 1.5
              <3,2,1> 1.0
              }
           cone {
              <3,2,8> 1
              <3,2,2> 0.5
              }
           }
        difference { // Feder links
           cone {
              <-7,5,8> 1.5
              <-7,5,1> 1.0
              }
           cone {
              <-7,5,8> 1
              <-7,5,2> 0.5
              }
           }
        difference { // Feder rechts
           cone {
              <7,5,8> 1.5
              <7,5,1> 1.0
              }
           cone {
              <7,5,8> 1
              <7,5,2> 0.5
              }
           }
        texture {
           col_silver
           }
        } 
     union {
        box { // linke Loetlasche
           <-7, -2, 9.5>
           <-6.5, 3, 11>
           }
        box { // rechte Loetasche
           <7, -2, 9.5>
           <6.5, 3, 11>
           }              
        texture {
           col_silver
           }
        }
     union {
        object {
           TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)
           rotate <90,0,0>
           translate <6.75,5,-0.5>
           }
        object {
           TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)
           rotate <90,270,0>
           translate <-6.75,5,-0.5>
           }
        object {
           TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)
           rotate <90,0,90>
           translate <-3.5,7.75,-0.5>
           }
        object {
           TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)
           rotate <90,0,90>
           translate <3.5,7.75,-0.5>
           }
        object {
           TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)
           rotate <90,0,270>
           translate <-3.5,2.25,-0.5>
           }
        object {
           TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)
           rotate <90,0,270>
           translate <3.5,2.25,-0.5>
           }
        texture {
           col_silver
           }
        }
     // weisser Kontakttraeger
     difference {
        Round_Box ( // Quader in der Mitte
           <-5,4,1>
           <5,6,12>
           0.3 0
           )
        box { // Abflachung oben
           <-6,5.3,0>
           <+6,7  ,5>
           rotate <-10, 0, 0>
           }
        box { // Abflachung unten
           <-6,4.3,0>
           <+6,3.5,5>
           rotate <10, 0, 0>
           }
        pigment {
           White
           }
        }
     // Kontakte
     difference {
        union {
           box { // Kontakt 1
              <-3.8,3.5,3>
              <-3,4,8>
              }
           box { // Kontakt 2
              <-1.8,3.5,3>
              <-0.8,4,8>
              }
           box { // Kontakt 3
              <1.8,3.5,3>
              <0.8,4,8>
              }
           box { // Kontakt 4
              <3.8,3.5,3>
              <3,4,8>
              }
           texture {
              col_gold
              }
           }
        box { // Abflachung der Kontakte
           <-4,4,1>
           <4,3.5,5>
           rotate <5, 0, 0>
           }
        }
     union {
        box { // Kontakt 1 hinten
           <-3.8,-2,12.5>
           <-3.2,5,13>
           }
        box { // Kontakt 2 hinten
           <-1.3,-2,12.5>
           <-0.7,5,13>
           }
        box { // Kontakt 3 hinten
           <0.7,-2,12.5>
           <1.3,5,13>
           }
        box { // Kontakt 4 hinten
           <3.2,-2,12.5>
           <3.8,5,13>
           }
        texture {
           col_gold
           }
        }
     // weisser Sockel
     union {      
        difference {
           box { // Sockel links
              <-6,0,2>
              <6,2,12>
              }
           box { // Sockel rechts
              <-1,0,1 >
              <+1,2,12>
              }
           box { // Abflachung links
              <1.5,0, 0>
              <7.0,2,12>
              rotate <-10, 0, 0>
              }
           box { // Abflachung links
              <-1.5,0,0>
              <-7,2,12>}
              rotate <-10, 0, 0>
              }                
        difference {
           box { // Sockel hinten
              <-6.5, 0.5, 12>
              <6.5, 7.5, 14>
              }
           box { // Aussparung fuer Kontakte
              <-6, 2.5, 12.5>
              < 6, 8  , 15  >
              }
           box { // Aussparung fuer Kontakte
              <-3.8,-2,12>
              <-3.2, 5,15>
              }
           box { // Aussparung fuer Kontakte
              <-1.3,-2,12>
              <-0.7,5,15>
              }
           box { // Aussparung fuer Kontakte
              <0.7,-2,12>
              <1.3,5,15>
              }
           box { // Aussparung fuer Kontakte
              <3.2,-2,12>
              <3.8,5,15>
              }
           pigment {
              White
              }
           }
        }
     }
#end


/*******************************************************************************
 * USB-connector PN87520, con-berg.lbr
 * 04.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_USB_Std_A_AMP87520()
  object {
     CON_THT_USB_Std_A_AMP787616()
     translate <0,0,-10.29>
     }
#end


/*******************************************************************************
 * USB-connector PN87520-S, con-berg.lbr
 * 04.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_USB_Std_A_AMP87520S()
  union {
     CON_THT_USB_Std_A_AMP87520()
     difference {
        union {
           object {
              BENT_PLANE_OUTER(8.5,2,7.0,0.3,0.2,90)
              rotate <-90,0,0>
              translate <-7.3,+4.0,4.1>
              }
           object {
              BENT_PLANE_OUTER(8.5,2,7.0,0.3,0.2,90)
              rotate <+90,180,0>
              translate <+7.3,+4.0,4.1>
              }
           }
        box {
           <-16/2,-1,-1>
           <+16/2,+1,+1>
           rotate <45,0,0>
           translate <0,8,2>
           }
        box {
           <-16/2,-1,-1>
           <+16/2,+1,+1>
           rotate <45,0,0>
           translate <0,0,2>
           }
        }
     texture {
        col_silver
        }
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-amp:USB=CON_THT_USB_Std_A_AMP787616(:USB-A Amphenol 787616:
//con-berg:PN87520=CON_THT_USB_Std_A_AMP87520(:USB-A standard:
//con-berg:PN87520-S=CON_THT_USB_Std_A_AMP87520S(:USB-A standard:
// end assignment
