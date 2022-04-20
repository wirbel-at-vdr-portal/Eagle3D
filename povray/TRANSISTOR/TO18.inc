/*******************************************************************************
 * TO18
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * based on Robert Eckelmann <dc6xs@dc6xs.de>
 ******************************************************************************/
#macro TR_TO18(value)
  union {
     #if (pin_short=off)
         #local tr_to18_pin=0;
     #else
         #local tr_to18_pin=11-(pcb_height+pin_length);
     #end

     cylinder{<0,tr_to18_pin,0><0,14,0>0.24 texture{col_silver} translate<-1.27,0,-1.27>} //linker Pin
     cylinder{<0,tr_to18_pin,0><0,14,0>0.24 texture{col_silver} translate<1.27,0,1.27>}   //hinterer Pin Gehaeuse
     cylinder{<0,tr_to18_pin,0><0,14,0>0.24 texture{col_silver} translate<1.27,0,-1.27>}  //rechter Pin

     union { //Transistorkoerper
        torus{1.6 0.8 pigment {Silver} translate <0.12,19.3,0>}
        cylinder{<0,14,0><0,19.3,0>2.4 pigment{ Silver}translate<0.12,0,0>}
        cylinder{<0,19.3,0><0,20.1,0>1.6 pigment{ Silver}translate<0.12,0,0>}
        cylinder{<0,13.9,0><0,14,0>2.9 pigment{ Silver}translate<0.12,0,0>}
        }

     box {<-0.58,0,2.6><0.58,0.1,4.07> pigment {Silver}  translate <0,13.9,0> rotate <0,-90,0> }
     text {ttf besch_font value 1, 0 pigment { Black } scale <0.7,1,0.7> rotate <90,0,0> translate<-1.5,20.101,-.5>}
     translate<0,-11,0>
     }
#end
