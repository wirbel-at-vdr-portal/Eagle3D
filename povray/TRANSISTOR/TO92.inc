/*******************************************************************************
 * TO92 & SOT54 packages, vertical
 * Author: Joerg Bredendiek <sprut(replace with at)sprut.de>
 *    pin: number of pins (2 or 3)
 *    L  : Pin 1 shift along X
 *    M  : Pin 2 shift along Z
 *    R  : Pin 3 shift along X
 *    D  : Rotation of the whole package around Y
 ******************************************************************************/
#macro TR_TO92_G_base(value, pin, L, M, R, D)
  union {
     //lower part of pin
     #if (pin_short=off)
         box{<-0.24,0,-0.22><0.24,10,0.22> translate< L,0,0>}       //linker Pin
         #if (pin=3)
             box{<-0.24,0,-0.22><0.24,10,0.22> translate< 0,0,M>}   //mittlerer Pin
         #end
         box{<-0.24,0,-0.22><0.24,10,0.22> translate< R,0,0>}       //rechter Pin
     #else
         box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< L,0,0>} //linker Pin
         #if (pin=3)
             box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< 0,0,M>} //mittlerer Pin
         #end
         box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< R,0,0>} //rechter Pin
     #end

    // bended middle part of pin
    #local M1=sqrt( (1.5*1.5) + (L+1.27-0.48)*(L+1.27-0.48) );
    #local M2=sqrt( (1.5*1.5) + (M+0.44)*(M+0.44) );
    #local M3=sqrt( (1.5*1.5) + (R-1.27+0.48)*(R-1.27+0.48) );

    #local L1=sqrt((M1*M1) - (0.48*0.48) );
    #local L2=sqrt((M2*M2) - (0.44*0.44) );
    #local L3=sqrt((M3*M3) - (0.48*0.48) );

    #local A1= (asin( (L+1.27-0.48)/M1 ) + asin(0.48/M1) ) / 3.1415 * 180;
    #local A2= (asin( (M+0.44)/M2 )      - asin(0.44/M2) ) / 3.1415 * 180;
    #local A3= (asin( (R-1.27+0.48)/M3 ) - asin(0.48/M3) ) / 3.1415 * 180;

    box{<-0.24,-L1/2,-0.22><0.24,L1/2,0.22> rotate<0,0,A1> translate<(L+1.27)/2-1.27 ,10.75,0>} //linker Pin Schraege
    #if (pin=3)
        box{<-0.24,-L2/2,-0.22><0.24,L2/2,0.22> rotate<-A2,0,0> translate< 0,10.75,(M/2)>}      //mittlerer Pin Schraege
    #end
    box{<-0.24,-L3/2,-0.22><0.24,L3/2,0.22> rotate<0,0, A3> translate<(R-1.27)/2+1.27,10.75,0>} //rechter Pin Schraege


    // upper part of pin at the housing
    box{<-0.24,11.5,-0.22><0.24,14,0.22> translate<-1.27,0,0>}  //linker Pin
    #if (pin=3)
        box{<-0.24,11.5,-0.22><0.24,14,0.22> }                  //mittlerer Pin
    #end
    box{<-0.24,11.5,-0.22><0.24,14,0.22> translate< 1.27,0,0>}  //rechter Pin

    // wider part of pin close to the housing
    box{<-0.34,12,-0.22><0.34,13,0.22> translate<-1.27,0,0>}    //Abstandhalter links
    #if (pin=3)
        box{<-0.34,12,-0.22><0.34,13,0.22> }                    //Abstandhalter mitte
    #end
    box{<-0.34,12,-0.22><0.34,13,0.22> translate< 1.27,0,0>}    //Abstandhalter rechts

    // plastic body
    difference { //Transistorkoerper
       cylinder {<0,14,0> <0,19.2,0> 2.4 translate<0.12,0,0>}
       box { <-3,13.9,-1> <3,20,-3> }
       pigment{ Gray30}
       }

    // label
    text {ttf besch_font value 1, 0 pigment { White } translate<-1.8,17,-1.01>}

    texture{col_silver}
    translate<0, -9.3, 0>
    rotate<0,D,0>
    }
#end

#macro TR_TO92_L(value)
  TR_TO92_G_base(value, 3, -2.54, 0.00, 2.54, 0)
#end

#macro TR_TO92_G(value)
  TR_TO92_G_base(value, 3, -1.27, 1.905,1.27, 0)
#end

#macro TR_TO92_G2(value)
  TR_TO92_G_base(value, 3, -2.54, 2.54, 2.54, 90)
#end

#macro TR_TO92_G3(value)
  TR_TO92_G_base(value, 3, -2.00, 2.00, 2.00, 0)
#end

#macro TR_TO92_G4(value)
  TR_TO92_G_base(value, 3, -1.80, 1.80, 1.80, 0)
#end

#macro TR_TO92_G5(value)
  TR_TO92_G_base(value, 3, -2.18, 2.55, 2.18, 0)
#end

#macro TR_TO92_2(value)
  TR_TO92_G_base(value, 2, -1.27, 0.00, 1.27, 0)
#end
