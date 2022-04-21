//Eagle3D 20110101 INC-File e3d_transistor.inc
//created by: INC SRC Compiler v2.02
//created on: 01.01.2011 17:33:58
//(c) 2011 by M. Weisser
//or the author of the macro

/*
 * Copyright 2005-2010 Matthias Weisser <matthias@matwei.de>
 *
 * This file is part of Eagle3D
 *
 * Eagle3D is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * Eagle3D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "e3d_tools.inc"
#include "TRANSISTOR/SOT82.inc"
#include "TRANSISTOR/SOT93.inc"
#include "TRANSISTOR/TO126.inc"
#include "TRANSISTOR/TO18.inc"
#include "TRANSISTOR/TO18D.inc"
#include "TRANSISTOR/TO202.inc"
#include "TRANSISTOR/TO220.inc"
#include "TRANSISTOR/TO247.inc"
#include "TRANSISTOR/TO39.inc"








/********************************************************************************************************************************************
//TO3 metal cup
//daniel cardona<dancardona50@hotmail.com>
********************************************************************************************************************************************/
#macro TR_TO3_GRND(value)
union{
union{
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 5   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 2.3   }
translate <15,0,0>
} 
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 5   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 2.3   } 
translate <-15,0,0> 
}    
translate<0,0,0>}
union{  
box {<0, 0, 0> < 13,  1,  3> translate <-11.8,0,9.5>rotate <0,-30,0>}
box {<0, 0, 0> < 13,  1,  3> translate <0.2,0,-12.7>rotate <0,-30,0>}
box {<0, 0, 0> < 13,  1,  3> translate <-2,0,9.4>rotate <0,30,0>}
box {<0, 0, 0> < 13,  1,  3> translate <-13.2,0,-12.7>rotate <0,30,0>}
 cylinder{<0,0,0><0,4,0>0.6 translate<-1.8,-3,-5.4>} 
 cylinder{<0,0,0><0,4,0>0.6 translate<-1.8,-3,5.4>} 
cylinder{<0,0,0><0,1,0>12.7}
  cylinder{<0,1,0><0,2,0>11.6}
   cylinder{<0,2,0><0,8,0>10} 
    torus{9.2 0.8  translate <0,8,0>}
     cylinder{<0,8,0><0,8.8,0>9.2} 
text {ttf besch_font value 0.5, 0 pigment { Black } scale <5,1,5> rotate <90,0,0> translate<-5,8.81,0>} 
translate<0,0,0>} 


pigment{P_Chrome5}

finish {
    ambient (0.25 * global_ambient_mul)
    brilliance 4
    diffuse 0.5
    metallic
    specular 0.80
    roughness 1/80
    reflection 0.5
}

}
#end

#macro TR_TO3(value)
TR_TO3_GRND(value)
#end


/********************************************************************************************************************************************
//TO52 metal case
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1  20/12/05
********************************************************************************************************************************************/
#macro TR_TO52_GRND(value,npin)
union{
    //case
    cylinder{<0,0,0><0,3.5-0.3,0>2.35 pigment{P_Silver3} }
    cylinder{<0,3.5-0.3,0><0,3.5,0>2.05 pigment{P_Silver3}}
    torus{2.05 0.3 pigment {P_Silver3} translate (3.5-0.3)*y}
    torus{2.45 0.3 pigment {P_Silver3} translate 0.3*y}
    cylinder{<0,0,0><0,0.6,0>2.45 pigment{P_Silver3}}
    box {<-0.5,0,0><0.5,0.6,3.3> pigment{P_Silver3}  translate <0,0,0> rotate <0,135,0> }
    text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,3.52,-.4>}
    //pins
    #if(npin=2)
        #if(pin_short=off)
            cylinder{<+1.27,0,0><+1.27,-12.7,0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-12.7,0>0.2 pigment{ P_Silver3}}
        #else
            cylinder{<+1.27,0,0><+1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
        #end
    #else
        #if(pin_short=off)
            cylinder{<+1.27,0,0><+1.27,-12.7,0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-12.7,0>0.2 pigment{ P_Silver3}}
            cylinder{<0,0,+1.27><0,-12.7,+1.27>0.2 pigment{ P_Silver3}}
        #else
            cylinder{<+1.27,0,0><+1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
            cylinder{<0,0,+1.27><0,-(pin_length+pcb_height),+1.27>0.2 pigment{ P_Silver3}}
        #end
    #end
    }
    translate<0,1,0>
#end

#macro TR_TO51(value)
TR_TO52_GRND(value,2)
#end
#macro TR_TO52(value)
TR_TO52_GRND(value,3)
#end
#macro TR_TO52A(value)
TR_TO52_GRND(value,3)
#end


/********************************************************************************************************************************************
//TO66 metal cup
//daniel cardona<dancardona50@hotmail.com>
********************************************************************************************************************************************/
#macro TR_TO66_GRND(value)
union{
union{
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 3.6   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 1.8   }
translate <12,0,0>
} 
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 3.6   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 1.8   } 
translate <-12,0,0> 
}    
translate<0,0,0>}
union{  
box {<0, 0, 0> < 10,  1,  3.7> translate <-9,0,5.>rotate <0,-25,0>}
box {<0, 0, 0> < 10,  1,  3.7> translate <-1.4,0,-8.7>rotate <0,-25,0>}
box {<0, 0, 0> < 10,  1,  3.7> translate <-1,0,4.6>rotate <0,25,0>}
box {<0, 0, 0> < 10,  1,  3.7> translate <-9.4,0,-8.7>rotate <0,25,0>}
 cylinder{<0,0,0><0,4,0>0.6 translate<-2.6,-3,-2.8>} 
 cylinder{<0,0,0><0,4,0>0.6 translate<-2.6,-3,2.8>} 
cylinder{<0,0,0><0,1,0>8.6}
  cylinder{<0,1,0><0,2,0>7.6}
   cylinder{<0,2,0><0,8,0>6} 
    torus{5.2 0.8  translate <0,8,0>}
     cylinder{<0,8,0><0,8.8,0>5.2} 
text {ttf besch_font value 0.5, 0 pigment { Black } scale <2,1,2> rotate <90,0,0> translate<-4,8.81,0>} 
translate<0,0,0>} 


pigment{P_Chrome5}

finish {
    ambient (0.25 * global_ambient_mul)
    brilliance 4
    diffuse 0.5
    metallic
    specular 0.80
    roughness 1/80
    reflection 0.5
}

}
#end

#macro TR_TO66(value)
TR_TO66_GRND(value)
#end


/********************************************************************************************************************************************
//TO72 metal case
//Joerg Bredendiek <sprut(replace with at)sprut.de>   
//based on TO52 Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
********************************************************************************************************************************************/
#macro TR_TO72_GRND(value,npin)
union{
    //case
    cylinder{<0,0,0><0,3.5-0.3 +1.5 ,0>2.35 pigment{P_Silver3} }                                      
    cylinder{<0,3.5-0.3 +1.5 ,0><0,3.5 +1.5 ,0>2.05 pigment{P_Silver3}}   
    torus{2.05 0.3 pigment {P_Silver3} translate (3.5-0.3 +1.5 )*y}
    torus{2.45 0.3 pigment {P_Silver3} translate 0.3*y}
    cylinder{<0,0,0><0,0.6,0>2.45 pigment{P_Silver3}}   
    box {<-0.5,0,0><0.5,0.6,3.3> pigment{P_Silver3}  translate <0,0,0> rotate <0,-90,0> }
    text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,3.52 +1.5 ,-.4>}

    //pins
    #if(npin>=3)
        #if(pin_short=off)
            cylinder{<+1.27, 0, -1.27> <+1.27,-12.7,-1.27> 0.2 pigment{ P_Silver3}}   
            cylinder{<-1.27, 0, -1.27> <-1.27,-12.7,-1.27> 0.2 pigment{ P_Silver3}}  
            cylinder{<-1.27, 0, +1.27> <-1.27,-12.7,+1.27> 0.2 pigment{ P_Silver3}}    
        #else
            cylinder{<+1.27, 0,-1.27> <+1.27,-(pin_length+pcb_height),-1.27> 0.2 pigment{ P_Silver3}}   
            cylinder{<-1.27, 0,-1.27> <-1.27,-(pin_length+pcb_height),-1.27> 0.2 pigment{ P_Silver3}}   
            cylinder{<-1.27, 0,+1.27> <-1.27,-(pin_length+pcb_height),+1.27> 0.2 pigment{ P_Silver3}}   
        #end
    #end

    #if(npin=4)
        #if(pin_short=off)
            cylinder{<+1.27, 0, +1.27> <+1.27,-12.7,+1.27> 0.2 pigment{ P_Silver3}}   
        #else
            cylinder{<+1.27, 0,+1.27> <+1.27,-(pin_length+pcb_height),+1.27> 0.2 pigment{ P_Silver3}}  
        #end
    #end

    }
    translate<0,1,0>
#end

#macro TR_TO72_3(value)
TR_TO72_GRND(value,3)
#end
#macro TR_TO72_4(value)
TR_TO72_GRND(value,4)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>
// replacement for all TR_TO92 and DIODE_TO92 macros
//
//TO92 & SOT54 packages, vertical
// pin - number of pins (2 or 3)
// L - Pin 1 shift along X
// M - Pin 2 shift along Z
// R - Pin 3 shift along X
// D - Rotation of the whole package around Y
//
//
********************************************************************************************************************************************/
#macro TR_TO92_G_GRND(value, pin, L, M, R, D)
union{
   //lower part of pin
   #if(pin_short=off)
      box{<-0.24,0,-0.22><0.24,10,0.22> translate< L,0,0>}                                      //linker Pin
      #if (pin=3)
      box{<-0.24,0,-0.22><0.24,10,0.22> translate< 0,0,M>}                                      //mittlerer Pin
      #end
      box{<-0.24,0,-0.22><0.24,10,0.22> translate< R,0,0>}                                      //rechter Pin
   #else
      box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< L,0,0>}            //linker Pin
      #if (pin=3)
      box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< 0,0,M>}            //mittlerer Pin
      #end
      box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< R,0,0>}            //rechter Pin
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

   box{<-0.24,-L1/2,-0.22><0.24,L1/2,0.22> rotate<0,0,A1> translate<(L+1.27)/2-1.27 ,10.75,0>}          //linker Pin Schraege
   #if (pin=3)
   box{<-0.24,-L2/2,-0.22><0.24,L2/2,0.22> rotate<-A2,0,0> translate< 0,10.75,(M/2)>}                   //mittlerer Pin Schraege
   #end
   box{<-0.24,-L3/2,-0.22><0.24,L3/2,0.22> rotate<0,0, A3> translate<(R-1.27)/2+1.27,10.75,0>}          //rechter Pin Schraege


   // upper part of pin at the housing
   box{<-0.24,11.5,-0.22><0.24,14,0.22> translate<-1.27,0,0>}                                     //linker Pin
   #if (pin=3)
   box{<-0.24,11.5,-0.22><0.24,14,0.22> }                                                         //mittlerer Pin
   #end
   box{<-0.24,11.5,-0.22><0.24,14,0.22> translate< 1.27,0,0>}                                     //rechter Pin

   // wider part of pin close to the housing
   box{<-0.34,12,-0.22><0.34,13,0.22> translate<-1.27,0,0>}                                        //Abstandhalter links
   #if (pin=3)
   box{<-0.34,12,-0.22><0.34,13,0.22> }                                                            //Abstandhalter mitte
   #end
   box{<-0.34,12,-0.22><0.34,13,0.22> translate< 1.27,0,0>}                                        //Abstandhalter rechts

   // plastic body
   difference{                                                                                  //Transistorkoerper
      cylinder{<0,14,0><0,19.2,0>2.4 pigment{ Gray30}translate<0.12,0,0>}
            box{<-3,13.9,-1><3,20,-3> pigment{ Gray30}}}

   // label
   text {ttf besch_font value 1, 0 pigment { White } translate<-1.8,17,-1.01>}                  //Beschriftung

   texture{col_silver}
   translate<0, -9.3, 0>
   rotate<0,D,0>
}
#end

#macro TR_TO92_L(value)
TR_TO92_G_GRND(value, 3, -2.54, 0.00, 2.54, 0)
#end
#macro TR_TO92_G(value)
TR_TO92_G_GRND(value, 3, -1.27, 1.905,1.27, 0)
#end
#macro TR_TO92_G2(value)
TR_TO92_G_GRND(value, 3, -2.54, 2.54, 2.54, 90)
#end
#macro TR_TO92_G3(value)
TR_TO92_G_GRND(value, 3, -2.00, 2.00, 2.00, 0)
#end
#macro TR_TO92_G4(value)
TR_TO92_G_GRND(value, 3, -1.80, 1.80, 1.80, 0)
#end
#macro TR_TO92_G5(value)
TR_TO92_G_GRND(value, 3, -2.18, 2.55, 2.18, 0)
#end
#macro TR_TO92_2(value)
TR_TO92_G_GRND(value, 2, -1.27, 0.00, 1.27, 0)
#end


/**********************************************************************
Testing
**********************************************************************/
#ifndef(inc_testmode)
          
     //Size of the Grid Plane (+/- span)
     #local XYZ_span=20;
     
     //Orientation axes
     cylinder{<-XYZ_span,0,0><XYZ_span,0,0>0.1 pigment{Blue}} //X
     cylinder{<0,-XYZ_span,0><0,XYZ_span,0>0.1 pigment{Red}}     //Y
     cylinder{<0,0,-XYZ_span><0,0,XYZ_span>0.1 pigment{Yellow}}  //Z
     
     // Useful GRIDS:
     #local XYZ_step= 1 ;          // axis increment
     #local XYZ_cnt = 0;           //  loop counter
     #local xyz_thick = 0.05;     // grid line thickness
     
     // GRID PLANES: Remove comment begin/end to activate & select PLANES:
     #while (XYZ_cnt <= XYZ_span)
     
        cylinder{<-XYZ_span,0,XYZ_cnt><XYZ_span,0,XYZ_cnt>xyz_thick pigment{Blue}}    // Positive Z-Lines
        cylinder{<-XYZ_span,0,-XYZ_cnt><XYZ_span,0,-XYZ_cnt>xyz_thick pigment{Blue}}  // Negative Z-Lines
        
        //cylinder{<0,XYZ_cnt,-XYZ_span><0,XYZ_cnt,XYZ_span>xyz_thick pigment{Red}}      // Positive Y-Z Plane Lines
        //cylinder{<0,-XYZ_cnt,-XYZ_span><0,-XYZ_cnt,XYZ_span>xyz_thick pigment{Red}} // Negative Y-Z Plane Lines
        
        //cylinder{<-XYZ_span,XYZ_cnt,0><XYZ_span,XYZ_cnt,0>xyz_thick pigment{Red}}      // Positive Y-X Plane Lines
        //cylinder{<-XYZ_span,-XYZ_cnt,0><XYZ_span,-XYZ_cnt,0>xyz_thick pigment{Red}} // Negative Y-X Plane Lines
        
        cylinder{<XYZ_cnt,0,-XYZ_span><XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}  // Positive X-Lines
        cylinder{<-XYZ_cnt,0,-XYZ_span><-XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}   // Negative X-Lines
     
        #local XYZ_cnt = XYZ_cnt+XYZ_step;
     #end
     
     camera
     {       
        #local tt = 40;            //let's you change the distance easily
        location <-tt,tt,-tt>
        //location<0,5,-50>        //alternate location
        look_at <0,0,0>            //best to select the approximate centre of the object
        angle 30
     }
     
     light_source { <100, 100, -100> White}
     light_source { <-100, 100, -100> White }
     light_source { <-100, 100, 100> White }
     light_source { <100, 100, 100> White }
     //light_source { <-tt,tt,-tt> White }
     //light_source { <-tt,tt,-tt> White }
     //light_source { <-tt,tt,-tt> White }
     background{Grey}
     
#end
