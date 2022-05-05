/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * QFN (Quad Flat No-Lead) base macro.
 * Nx - Number of Pins in x
 * Ny - Number of pins in y
 * e  - Pitch
 * A  - Overall Height
 * A1 - Standoff
 * A3 - Contact Thickness
 * E  - Overall Width
 * E2 - Exposed Pad Width
 * D  - Overall Length
 * D2 - Exposed Pad Length
 * b  - Contact Width
 * L  - Contact Length
 * ExposedPadCut - style of Exposed Pad pin1 marking
 *      "" - none
 *      "chamfer"            - 45deg cut
 *      "irregular corner"   - egde has round cut
 *      "corner square"      - rectangular extra pad
 *      "irregular edge"     - a round cut with small offset  
 * value Text to be printed
 *
 * 20220505, wk
 ******************************************************************************/

#macro QFN_base(Nx,Ny,e,A,A1,A3,E,E2,D,D2,b,L,ExposedPadCut,value)
union {
  difference {
     box { <-D/2,A1,-E/2> <+D/2,A,+E/2> }
     cylinder { <-D/2+L,A-0.075,+E/2-L>
                <-D/2+L,A+0.1,+E/2-L> b}
     texture { e3d_tex_ic_body_1 }
     }


  #local pin = union {
        cylinder { <0,0,0> <0,A3,0> b/2  translate<0,0,0> }
        box      { <0,0,-b/2> <L,A3,+b/2> }
        texture{col_silver}
        }
  object { GRID_BASE(object{ pin rotate<0,+90,0> }, e, Nx, 1) translate<0,0,-E/2+(L-b/2)> }
  object { GRID_BASE(object{ pin rotate<0,-90,0> }, e, Nx, 1) translate<0,0,+E/2-(L-b/2)> }
  object { GRID_BASE(object{ pin rotate<0,  0,0> }, e, 1, Ny) translate<+D/2-(L-b/2),0,0> }
  object { GRID_BASE(object{ pin rotate<0,180,0> }, e, 1, Ny) translate<-D/2+(L-b/2),0,0> }


  #if (D2 > 0)
      // exposed center pad
      #if (ExposedPadCut = "")
         object{TOOLS_PCB_SMD(D2,E2,0.035,13) texture{e3d_tex_silver}}
      #else
          #if (ExposedPadCut = "chamfer")
            difference {
                object{TOOLS_PCB_SMD(D2,E2,0.035,13)}
                box{ <-b,-0.1,-b> <+b,0.5,+b> rotate<0,45,0> translate<-D2/2,0,+E2/2> }
                texture{e3d_tex_silver}
                }
          #end
          #if (ExposedPadCut = "irregular corner")
            difference {
                object{TOOLS_PCB_SMD(D2,E2,0.035,13)}
                cylinder{ <0,-0.1,0> <0,0.5,0> e translate<-D2/2,0,+E2/2> }
                texture{e3d_tex_silver}
                }
          #end
          #if (ExposedPadCut = "corner square")
            union {
                object{TOOLS_PCB_SMD(D2,E2,0.035,13)}
                object{TOOLS_PCB_SMD(0.6*L,0.6*L,0.035,13) translate<-D/2+0.6*L,0,+E/2-0.6*L>}
                texture{e3d_tex_silver}
                }
          #end
          #if (ExposedPadCut = "irregular edge")
            difference {
                object{TOOLS_PCB_SMD(D2,E2,0.035,13)}
                cylinder{ <0,-0.1,0> <0,0.5,0> e/2 translate<-D2/2,0,+E2/2-e> }
                texture{e3d_tex_silver}
                }
          #end
      #end
  #end


  text { ttf besch_font value 0.2,0 rotate<90,0,0> scale 1*(E/9) translate<-E/4,A+0.02,-D/4> texture{e3d_tex_ic_marking_bright} }
  } // end: QFN_base
#end



















/*******************************************************************************
 * 11-pin (2x5, 4pins to exposed pad) MLP11 with 0.5mm pitch and chamfer
 * silabs.lbr:C8051F30x
 * 20220505, wk
 ******************************************************************************/
#macro IC_SMD_MLP11_050MM(value)
   object {
      #local A  = 0.90; // A  - Overall Height
      #local A1 = 0.07; // A1 - Standoff
      #local A3 = 0.25; // A3 - Contact Thickness
      #local b  = 0.23; // b  - Contact Width
      #local D  = 3.00; // D  - Overall Length
      #local D2 = 1.35; // D2 - Exposed Pad Length
      #local e  = 0.50; // e  - Pitch
      #local E  = 3.00; // E  - Overall Width
      #local E2 = 2.25; // E2 - Exposed Pad Width
      #local L  = 0.55; // L  - Contact Length
      QFN_base(2,5,e,A,A1,A3,E,E2,D,D2,b,L,"chamfer",value)
      }
#end


/*******************************************************************************
 * 20-pin (5x5) QFN20 with 0.5mm pitch and corner square
 * silabs.lbr:C8051F330*
 * 20220505, wk
 ******************************************************************************/
#macro IC_SMD_QFN20_050MM(value)
   object {
      #local A  = 0.90; // A  - Overall Height
      #local A1 = 0.02; // A1 - Standoff
      #local A3 = 0.25; // A3 - Contact Thickness
      #local b  = 0.23; // b  - Contact Width
      #local D  = 4.00; // D  - Overall Length
      #local D2 = 2.15; // D2 - Exposed Pad Length
      #local e  = 0.50; // e  - Pitch
      #local E  = 4.00; // E  - Overall Width
      #local E2 = 2.15; // E2 - Exposed Pad Width
      #local L  = 0.55; // L  - Contact Length
      QFN_base(5,5,e,A,A1,A3,E,E2,D,D2,b,L,"corner square",value)
      }
#end


/*******************************************************************************
 * 28-pin (7x7) QFN with 0.5mm pitch and chamfer
 * silabs.lbr:CP2102-GM
 * 20220505, wk
 ******************************************************************************/
#macro IC_SMD_QFN28_050MM(value)
   object {
      #local A  = 0.90; // A  - Overall Height
      #local A1 = 0.02; // A1 - Standoff
      #local A3 = 0.25; // A3 - Contact Thickness
      #local b  = 0.23; // b  - Contact Width
      #local D  = 5.00; // D  - Overall Length
      #local D2 = 3.15; // D2 - Exposed Pad Length
      #local e  = 0.50; // e  - Pitch
      #local E  = 5.00; // E  - Overall Width
      #local E2 = 3.15; // E2 - Exposed Pad Width
      #local L  = 0.55; // L  - Contact Length
      QFN_base(7,7,e,A,A1,A3,E,E2,D,D2,b,L,"chamfer",value)
      }
#end


/*******************************************************************************
 * 44-pin (11x11) QFN44 with 0.5mm pitch and chamfer
 * atmel.lbr:MEGA16-M,MEGA32-M,MEGA8515-M,MEGA8535_M,ATMEGA644*,XMEGA16A4
 * 20220505, wk
 ******************************************************************************/
#macro IC_SMD_QFP44_050MM(value)
   object {
      #local A  = 0.90; // A  - Overall Height
      #local A1 = 0.02; // A1 - Standoff
      #local A3 = 0.20; // A3 - Contact Thickness
      #local b  = 0.23; // b  - Contact Width
      #local D  = 7.00; // D  - Overall Length
      #local D2 = 5.20; // D2 - Exposed Pad Length
      #local e  = 0.50; // e  - Pitch
      #local E  = 7.00; // E  - Overall Width
      #local E2 = 5.20; // E2 - Exposed Pad Width
      #local L  = 0.64; // L  - Contact Length
      QFN_base(11,11,e,A,A1,A3,E,E2,D,D2,b,L,"chamfer",value)
      }
#end


/*******************************************************************************
 * 64-pin (16x16) QFN64 with 0.5mm pitch and chamfer
 * gennum.lbr:GS4910B; atmel.lbr:MEGA128-M
 * 20220505, wk
 ******************************************************************************/
#macro IC_SMD_QFN64_050MM(value)
   object {
      #local A  = 0.90; // A  - Overall Height
      #local A1 = 0.02; // A1 - Standoff
      #local A3 = 0.20; // A3 - Contact Thickness
      #local b  = 0.25; // b  - Contact Width
      #local D  = 9.00; // D  - Overall Length
      #local D2 = 5.40; // D2 - Exposed Pad Length
      #local e  = 0.50; // e  - Pitch
      #local E  = 9.00; // E  - Overall Width
      #local E2 = 5.40; // E2 - Exposed Pad Width
      #local L  = 0.40; // L  - Contact Length
      QFN_base(16,16,e,A,A1,A3,E,E2,D,D2,b,L,"chamfer",value)
      }
#end


/*******************************************************************************
 * 20-pin (5x5) QFN20 with 0.65mm pitch and chamfer
 * atmel.lbr:T7024
 * 20220505, wk
 ******************************************************************************/
#macro IC_SMD_QFN20_065MM(value)
   object {
      #local A  = 0.90; // A  - Overall Height
      #local A1 = 0.05; // A1 - Standoff
      #local A3 = 0.25; // A3 - Contact Thickness
      #local b  = 0.28; // b  - Contact Width
      #local D  = 5.00; // D  - Overall Length
      #local D2 = 3.10; // D2 - Exposed Pad Length
      #local e  = 0.65; // e  - Pitch
      #local E  = 5.00; // E  - Overall Width
      #local E2 = 3.10; // E2 - Exposed Pad Width
      #local L  = 0.60; // L  - Contact Length
      QFN_base(5,5,e,A,A1,A3,E,E2,D,D2,b,L,"chamfer",value)
      }
#end
