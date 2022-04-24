/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * QFN base macro.
 * N  - Number of Pins
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
 * K  - Contact-To-Exposed Pad
 * value Text to be printed
 ******************************************************************************/

#macro QFN_base(N,e,A,A1,A3,E,E2,D,D2,b,L,K,value)
union {
  union {
     box { <-D/2,A1,-E/2> <+D/2,A,+E/2> }
     texture { e3d_tex_ic_body_1 }
     }
  #for (PinNumber, 1, N/4)
     union {
        cylinder { <0,0,0> <0,A3,0> b/2  translate<+D2/2+K+b/2,0,0> }
        box      { <+D2/2+K+b/2,0,-b/2> <+E/2+0.05,A3,+b/2> }
        translate<0,0,(PinNumber-N/8-0.5)*e>
        texture{col_silver}
        }
     union {
        cylinder { <0,0,0> <0,A3,0> b/2  translate<-D2/2-K-b/2,0,0> }
        box      { <-D2/2-K-b/2,0,-b/2> <-E/2-0.05,A3,+b/2> }
        translate<0,0,(PinNumber-N/8-0.5)*e>
        texture{col_silver}
        }
     union {
        cylinder { <0,0,0> <0,A3,0> b/2  translate<0,0,+D2/2+K+b/2> }
        box      { <-b/2,0,+D2/2+K+b/2> <+b/2,A3,+E/2+0.05> }
        translate<(PinNumber-N/8-0.5)*e,0,0>
        texture{col_silver}
        }
     union {
        cylinder { <0,0,0> <0,A3,0> b/2  translate<0,0,-D2/2-K-b/2> }
        box      { <-b/2,0,-D2/2-K-b/2> <+b/2,A3,-E/2-0.05> }
        translate<(PinNumber-N/8-0.5)*e,0,0>
        texture{col_silver}
        }
  #end

  text { ttf besch_font value 0.2,0 rotate<90,0,0> scale 1*(E/9) translate<-E/4,A+0.02,-D/4> texture{e3d_tex_ic_marking_bright} }

} // end: QFN_base
#end



#macro QFN64_090_090_009_054_054(value)
  QFN_base(
     64,   // N  - Number of Pins
     0.50, // e  - Pitch
     0.90, // A  - Overall Height
     0.02, // A1 - Standoff
     0.20, // A3 - Contact Thickness
     9.00, // E  - Overall Width
     5.40, // E2 - Exposed Pad Width
     9.00, // D  - Overall Length
     5.40, // D2 - Exposed Pad Length
     0.25, // b  - Contact Width
     0.40, // L  - Contact Length
     1.40, // K  - Contact-To-Exposed Pad
     value)// value Text to be printed
#end
