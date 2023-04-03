/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * TYCO H38 inductor
 ******************************************************************************/
#macro SPC_L_TYCO_H38(value)
  union {
     difference {
        box {<0,0,0> <12,6,12> } // Body
        cylinder {<6,-0.01,6> <6,6.01,6> 5.5 }
        cylinder {<2,-0.01,2> <2,6.01,2> 1.25 }
        cylinder {<2,-0.01,10> <2,6.01,10> 1.25 }
        cylinder {<10,-0.01,2> <10,6.01,2> 1.25 }
        cylinder {<10,-0.01,10> <10,6.01,10> 1.25 }
        }
     cylinder { <6,0,6> <6,5.9,6> 5 }
     text { ttf besch_font value 0.1, 0 pigment { Black } scale 2  rotate <90,0,0> translate <4,6,4> }
     text { ttf besch_font "H38" 0.1, 0 pigment { Black } scale 2  rotate <90,0,0> translate <4,6,6> }
     }
     pigment {
        Gray20
        }
     translate <-6,0,-6>
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_L_TYCO_H38(:TYCO H38 inductor
// end assignment
