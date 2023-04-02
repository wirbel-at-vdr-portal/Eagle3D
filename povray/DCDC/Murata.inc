/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Murata NMA series Isolated 1W Dual Output DC/DC Converters
 * J. ZEGLINSKI <JAZeglinski@rogers.com>
 * *****************************************************************************/
#macro SPC_DCDC_NMA_D(value)
  union {
     box {// Body
        <-9.75,0,-4.9>
        <+9.75,6.8,4.9>
        }
     cylinder { // Pin #1 marking
        <-7.62,6.85,-3.81>
        <-7.62,6.80,-3.81>
        0.5
        pigment {
           White
           }
     }

     box { <-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture { col_silver } translate<-7.62,0,+3.81> } // six square leads
     box { <-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture { col_silver } translate<-7.62,0,-3.81> }
     box { <-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture { col_silver } translate<    0,0,+3.81> }
     box { <-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture { col_silver } translate<+5.08,0,+3.81> }
     box { <-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture { col_silver } translate<+7.62,0,-3.81> }
     box { <-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture { col_silver } translate<+7.62,0,+3.81> }

     text { ttf besch_font value             0.1, 0 pigment{White} scale 1.75        rotate<90,0,0> translate<-8.75,6.81,+3   >} // Marking on top surface
     text { ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1           rotate<90,0,0> translate<-8.75,6.81,+2   >} // Markings front surface 
     text { ttf besch_font "C&D"             0.1, 0 pigment{White} scale<3.5,1.25,1> rotate<90,0,0> translate<+2.41,6.81,-3.31>}
     text { ttf besch_font "TECHNOLOGIES"    0.1, 0 pigment{White} scale<0.85,1,1>   rotate<90,0,0> translate<+2.41,6.81,-4.31>}
     }
  pigment {
     Gray20
     }
#end



/*******************************************************************************
 * Murata NMA series Isolated 1W Dual Output DC/DC Converters
 * J. ZEGLINSKI <JAZeglinski@rogers.com>
 * *****************************************************************************/
#macro SPC_DCDC_NMA_S(value)
  union {
     box { <-9.75,0  ,-3><-9.25,0.5,3> }    // Feet left and right side
     box { <+9.75,0  ,-3><+9.25,0.5,3> }
     box { <-9.75,0.5,-3><+9.75,10 ,3> }    // Body
     cylinder { <-7.75,2.0,-3.05><-7.75,2.0,-3.00> 0.5 pigment{White} }   // Pin #1 marking

     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)), 0.125> texture { col_silver } translate <-7.75,0,1.75> } // five square leads
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)), 0.125> texture { col_silver } translate <-5.21,0,1.75> } // NB: Different from the NME_S
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)), 0.125> texture { col_silver } translate <-0.13,0,1.75> } // NMA_S pins along "back" edge
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)), 0.125> texture { col_silver } translate <+2.41,0,1.75> }
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)), 0.125> texture { col_silver } translate <+4.95,0,1.75> }

     text { ttf besch_font value             0.1, 0 pigment { White } scale 1.75 rotate<90,0,0> translate<-8.75,10.01,0>}  // Value on top surface
     text { ttf besch_font value             0.1, 0 pigment { White } scale 1.75         translate<-8.75,8,-3.05>}         // Markings on vertical front face
     text { ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment { White }                    translate<-8.75,7,-3.05>}
     text { ttf besch_font "C&D"             0.1, 0 pigment { White } scale <3.5,1.25,1> translate<2.41,2.5,-3.05>}
     text { ttf besch_font "TECHNOLOGIES"    0.1, 0 pigment { White } scale <0.85,1,1>   translate<2.41,1.5,-3.05>}
     }
  pigment {
     Gray20
     }
  translate <1.27,0,-1.75>
  rotate <0,90,0>
#end



/*******************************************************************************
 * Murata NME series Isolated 1W Single Output DC/DC Converters (SIP Package)
 * J. ZEGLINSKI <JAZeglinski@rogers.com>
 * *****************************************************************************/
#macro SPC_DCDC_NME_S(value)
  union {
     box { <-7,0  ,-3.75> <-6.5,0.5,3.75> } // Feet left and right side
     box { <+7,0  ,-3.75> <+6.5,0.5,3.75> }
     box { <-7,0.5,-3.75> <+7  ,10 ,3.75> } // Body
     cylinder { // Pin #1 marking
        <-3.81,2.0,-3.8>
        <-3.75,2.0,-3.0>
        0.5
        pigment {
           White
           }
        }

     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125> texture { col_silver } translate <-3.81,0,-2.5> } // four square leads
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125> texture { col_silver } translate <-1.27,0,-2.5> }
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125> texture { col_silver } translate <+3.81,0,-2.5> }
     box { <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125> texture { col_silver } translate <+1.27,0,-2.5> }

     text {ttf besch_font value             0.1, 0 pigment { White } scale 1.75 rotate<90,0,0> translate<-6,10.01,0>}
     text {ttf besch_font value             0.1, 0 pigment { White } scale 1.75        translate<-6,8,-3.80>}
     text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment { White }                   translate<-6,7,-3.80>}
     text {ttf besch_font "C&D"             0.1, 0 pigment { White } scale<3.5,1.25,1> translate<-1.27,2.5,-3.80>}
     text {ttf besch_font "TECHNOLOGIES"    0.1, 0 pigment { White } scale<0.85,1,1>   translate<-1.27,1.5,-3.80>}
     }
  pigment {
     Gray20
     }
  translate <0,0,2.5>
  rotate <0,90,0>
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//dc-dc-converter:NMA-D=SPC_DCDC_NMA_D(:NMA-D Dual Output DC/DC Converter
//dc-dc-converter:NMA=SPC_DCDC_NMA_S(:NMA-S Dual Output DC/DC Converter
//dc-dc-converter:NME=SPC_DCDC_NME_S(:NME-S Single Output DC/DC Converter
// end assignment
