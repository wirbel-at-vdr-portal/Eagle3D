/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO39 metal cup
 * Author: daniel cardona<dancardona50@hotmail.com>
 * Modified: Joerg Bredendiek <sprut(replace with at)sprut.de>
 ******************************************************************************/
#macro TR_TO39_BASE(value, pins)
  union {
     #if (pin_short=off)
         #local tr_to39_pin = 0;
     #else
         #local tr_to39_pin = 11-(pcb_height+pin_length);
     #end

     #if (pins=4)
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0,-1.8>} // linker Pin
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0, 1.8>} // hinterer Pin
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate< 1.8,0,0>} // rechter Pin
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<-1.8,0,0>} // vorderer Pin
     #else
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0,-2.54>} // linker Pin
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0, 2.54>} // hinterer Pin Gehaeuse
        cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate< 2.54,0,0>} // rechter Pin
     #end

     union {
        // Transistorkoerper
        torus{4.2 0.8 pigment {P_Silver3} translate <0.12,19.3,0>}
        cylinder{<0,14,0><0,19.3,0>5     pigment{P_Silver3} translate<0.12,0,0>}
        cylinder{<0,19.3,0><0,20.1,0>4.2 pigment{P_Silver3} translate<0.12,0,0>}
        cylinder{<0,13.9,0><0,14,0>5.6   pigment{P_Silver3} translate<0.12,0,0>}
        box {<-0.56,0,2.6><0.56,0.1,6.2> pigment{P_Silver3} translate <0.12,13.9,0> rotate <0,-135,0> }
        }

     // Beschriftung
     text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,20.2,-.5>}
     finish {
        ambient (0.25 * global_ambient_mul) brilliance 4 diffuse 0.5 metallic specular 0.80 roughness 1/80 reflection 0.5
        }
     pigment{P_Silver3}
     translate<0,-11,0>
     #if (pins=4)
         rotate<0,45,0>
     #end
     }
#end

#macro TR_TO39(value)
  TR_TO39_BASE(value, 3)
#end

#macro TR_TO39_4(value)
  TR_TO39_BASE(value, 4)
#end

