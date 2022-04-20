/*******************************************************************************
 * TO18D metal cup
 * daniel cardona dancardona50@hotmail.com
 ******************************************************************************/
#macro TR_TO18D(value)
  union {
     cylinder{<0,0,0><0,14,0>0.24 texture{col_silver} translate<-0.8,0,-0.8>}  //linker Pin
     cylinder{<0,0,0><0,14,0>0.24 texture{col_silver} translate<1,0,1>}        //hinterer Pin Gehaeuse
     union {                                                                   //Transistorkoerper
        torus{1.6 0.8 pigment {Silver} translate <0.12,19.3,0>}
        cylinder{<0,14,0><0,19.3,0>2.4 pigment{ Silver}translate<0.12,0,0>}
        cylinder{<0,19.3,0><0,20.1,0>1.6 pigment{ Silver}translate<0.12,0,0>}
        cylinder{<0,13.9,0><0,14,0>2.9 pigment{ Silver}translate<0.12,0,0>}
        }
     box {<-0.56,0,2.6><0.56,0.1,4.2> pigment {Silver}  translate <0.12,13.9,0> rotate <0,-90,0> }
     text {ttf besch_font value 1, 0 pigment { Black } scale <0.7,1,0.7> rotate <90,135,0> translate<1,20.101,0.5>}
     translate<0,-11,-0.22>
     rotate <0,-135,0>
     }
#end
