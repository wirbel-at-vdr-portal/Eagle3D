/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


#ifndef(__special_inc)
#declare __special_inc = true;

#include "e3d_tools.inc"
#include "DCDC/traco.inc"                 // 06.04.2022, move TRACO to DCDC/traco.inc
#include "BOARDS/digilent.inc"            // 06.04.2022, add Digilent S6 FPGA devboard
#include "BUZZER/TDB.inc"                 // 29.03.2023, move SPC_BUZZER_TDB to BUZZER/TDB.inc
#include "CRYSTAL/ceramic_resonator.inc"  // 29.03.2023, move ceramic resonators to CRYSTAL/ceramic_resonator.inc
#include "CRYSTAL/crystal.inc"            // 30.03.2023, move crystals to CRYSTAL/crystal.inc
#include "CRYSTAL/oscillator.inc"         // 25.03.2023, add 3.2 x 2.5mm oscillator
#include "FUSE/SHK20L.inc"                // 30.03.2023, move fuses to subfolder
#include "FUSE/SHK20Q.inc"                // 30.03.2023, move fuses to subfolder
#include "HEATSINK/KL195.inc"             // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/RAxx.inc"              // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/SK96.inc"              // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/SK104.inc"             // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/viewcom.inc"           // 30.03.2023, move heatsinks to subfolder
#include "RELAY/Celduc.inc"               // 31.03.2023, move relays to subfolder
#include "RELAY/Omron.inc"                // 31.03.2023, move relays to subfolder
#include "RELAY/Panasonic.inc"            // 31.03.2023, move relays to subfolder
#include "RELAY/Schrack.inc"              // 31.03.2023, move relays to subfolder
#include "RELAY/SIL.inc"                  // 31.03.2023, move relays to subfolder


/********************************************************************************************************************************************
// DC-DC CONVERTERs BY J. ZEGLINSKI
// DC-DC CONVERTER "NMA" D-series 6-pin DIP14  Package 1 Watt  Dual output voltage (e.g. NMA1205D)
// <JAZeglinski@rogers.com>
// C & D Technologies (formerly Newport Components) Dc-DC Converters:
********************************************************************************************************************************************/
#macro SPC_DC_DC_NMA_D_GRND(value)
union{
box{<-9.75,0,-4.9><9.75,6.8,4.9>}     // Body
cylinder{<-7.62,6.85,-3.81><-7.62,6.80,-3.81> 0.5 pigment{White} }   // Pin #1 marking
//
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.62,0,+3.81> } // six square leads
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.62,0,-3.81> } 
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<0,0,+3.81> } 
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<5.08,0,+3.81>  }
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<7.62,0,-3.81>  }
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<7.62,0,+3.81>  }
//
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-8.75,6.81,3>}  // Marking on top surface
text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1 rotate<90,0,0> translate<-8.75,6.81,2>} // Markings front surface 
text {ttf besch_font "C&D"  0.1, 0 pigment{White} scale<3.5,1.25,1> rotate<90,0,0> translate<2.41,6.81,-3.31>} 
text {ttf besch_font "TECHNOLOGIES"  0.1, 0 pigment{White} scale<0.85,1,1> rotate<90,0,0> translate<2.41,6.81,-4.31>} 
}
pigment{Gray20} 
#end
#macro SPC_DC_DC_NMA_D(value)
SPC_DC_DC_NMA_D_GRND(value)
#end


/********************************************************************************************************************************************
// DC-DC CONVERTERs BY J. ZEGLINSKI
// DC-DC CONVERTER "NMA" S-series 5-pin SIP7   Package 1 Watt  Dual output voltage (e.g. NMA1205S)
// <JAZeglinski@rogers.com>
// C & D Technologies (formerly Newport Components) Dc-DC Converters:
********************************************************************************************************************************************/
#macro SPC_DC_DC_NMA_S_GRND(value)
union{
box{<-9.75,0,-3><-9.25,0.5,3>}    // Feet left and right side
box{<9.75,0,-3><9.25,0.5,3>}
box{<-9.75,0.5,-3><9.75,10,3>}     // Body
cylinder{<-7.75,2.0,-3.05><-7.75,2.0,-3.00> 0.5 pigment{White} }   // Pin #1 marking
//
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.75,0,1.75> } // five square leads
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-5.21,0,1.75> } // NB: Different from the NME_S
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-0.13,0,1.75> } //  NMA_S pins along "back" edge
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<2.41,0,1.75>  }
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<4.95,0,1.75>  }
//
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-8.75,10.01,0>}  // Value on top surface
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 translate<-8.75,8,-3.05>}                // Markings on vertical front face
text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1 translate<-8.75,7,-3.05>} 
text {ttf besch_font "C&D"  0.1, 0 pigment{White} scale<3.5,1.25,1> translate<2.41,2.5,-3.05>} 
text {ttf besch_font "TECHNOLOGIES"  0.1, 0 pigment{White} scale<0.85,1,1> translate<2.41,1.5,-3.05>} 
}
pigment{Gray20}  translate<1.27,0,-1.75>  rotate<0,90,0>
#end
#macro SPC_DC_DC_NMA_S(value)
SPC_DC_DC_NMA_S_GRND(value)
#end


/********************************************************************************************************************************************
// DC-DC CONVERTERs BY J. ZEGLINSKI
// DC-DC CONVERTER "NME" S-series 4-pin SIP4   Package 2 Watts Single output voltage (e.g. NML0505S) 
// <JAZeglinski@rogers.com>
// C & D Technologies (formerly Newport Components) Dc-DC Converters:
********************************************************************************************************************************************/
#macro SPC_DC_DC_NME_S_GRND(value)
union{
box{<-7,0,-3.75><-6.5,0.5,3.75>}    // Feet left and right side
box{<7,0,-3.75><6.5,0.5,3.75>}
box{<-7,0.5,-3.75><7,10,3.75>}     // Body
cylinder{<-3.81,2.0,-3.80><-3.75,2.0,-3.0> 0.5 pigment{White} }   // Pin #1 marking
//
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-3.81,0,-2.5> } // four square leads
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-1.27,0,-2.5> } 
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<3.81,0,-2.5> } 
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<1.27,0,-2.5> }
//
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-6,10.01,0>}
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 translate<-6,8,-3.80>}
text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1 translate<-6,7,-3.80>} 
text {ttf besch_font "C&D"  0.1, 0 pigment{White} scale<3.5,1.25,1> translate<-1.27,2.5,-3.80>} 
text {ttf besch_font "TECHNOLOGIES"  0.1, 0 pigment{White} scale<0.85,1,1> translate<-1.27,1.5,-3.80>} 
}
pigment{Gray20}  translate<0,0,2.5>  rotate<0,90,0>
#end
#macro SPC_DC_DC_NME_S(value)
SPC_DC_DC_NME_S_GRND(value)
#end






/********************************************************************************************************************************************
//Macros for jumper such simple wire
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Modified by Adriano Gandolfo <adrirobot(at)yahoo.it>
//Rev. 1.1  30/10/08
//If value is set in Eagle (1 to 9), colors can be passed to POV, by Emil Crisbaseanu
//<emilcrisba(at)gmail.com>
********************************************************************************************************************************************/
#macro SPC_JUMPER_WIRE_GRND(Lg,value)
              

#local h=0.9;


#if (strcmp (value,"1")=0)
#local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Brown } finish { Shiny }}
#else
        #if (strcmp (value,"2")=0)
        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Red } finish { Shiny }}
        #else
                #if (strcmp (value,"3")=0)
                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Orange } finish { Shiny }}
                #else
                        #if (strcmp (value,"4")=0)
                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Yellow } finish { Shiny }}
                        #else
                                #if (strcmp (value,"5")=0)
                                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Blue } finish { Shiny }}
                                #else
                                        #if (strcmp (value,"6")=0)
                                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Green } finish { Shiny }}
                                        #else
                                                #if (strcmp (value,"7")=0)
                                                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Pink } finish { Shiny }}
                                                #else
                                                        #if (strcmp (value,"8")=0)
                                                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Gray60 } finish { Shiny }}
                                                        #else
                                                                #if (strcmp (value,"9")=0)
                                                                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { White } finish { Shiny }}
                                                                #else
                                                                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.1 pigment { Brown } finish { Shiny }}
                                                                #end
                                                        #end
                                                #end
                                        #end
                                #end
                        #end
                  
                #end
         #end
#end     

union {        
      object{ TOOLS_WIRE_LEADS(0, 1, 1, 0.4,  Lg,  0.5, 0, "H") translate<0,h,0> }
      object{gain}
}
#end



#macro SPC_JUMPER_WIRE_5MM(value)
SPC_JUMPER_WIRE_GRND(5.08,value)
#end
#macro SPC_JUMPER_WIRE_7MM(value)
SPC_JUMPER_WIRE_GRND(7.62,value)
#end
#macro SPC_JUMPER_WIRE_10MM(value)
SPC_JUMPER_WIRE_GRND(10.16,value)
#end
#macro SPC_JUMPER_WIRE_12MM(value)
SPC_JUMPER_WIRE_GRND(12.7,value)
#end
#macro SPC_JUMPER_WIRE_15MM(value)
SPC_JUMPER_WIRE_GRND(15.24,value)
#end
#macro SPC_JUMPER_WIRE_17MM(value)
SPC_JUMPER_WIRE_GRND(17.78,value)
#end
#macro SPC_JUMPER_WIRE_20MM(value)
SPC_JUMPER_WIRE_GRND(20.32,value)
#end
#macro SPC_JUMPER_WIRE_22MM(value)
SPC_JUMPER_WIRE_GRND(22.86,value)
#end
#macro SPC_JUMPER_WIRE_25MM(value)
SPC_JUMPER_WIRE_GRND(25.40,value)
#end
#macro SPC_JUMPER_WIRE_27MM(value)
SPC_JUMPER_WIRE_GRND(27.94,value)
#end
#macro SPC_JUMPER_WIRE_30MM(value)
SPC_JUMPER_WIRE_GRND(30.48,value)
#end


/********************************************************************************************************************************************
//Macros for light pipe from dialight
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  24/12/06
********************************************************************************************************************************************/
#macro SPC_LIGHTPIPE_5151049F_GRND()
#macro LPIPEFOOT ()
#local l1=0.8;
intersection{                               
        merge{
                cylinder{<0,-2.1,0><0,0.5,0> 0.97}
                cone{<0,-2.4,0>, 0.7,<0,-2.1,0> 0.97}
        }
        box{<-l1,-2.5,-l1><+l1,0.51,+l1> rotate 45*y}
}
#end

#local Ray=9;
#local Ray1=8.9;
#local rr1=0.6;
#local ff=1.7;
#local x1=-1.5;
merge{
        intersection{
                cylinder{<-4.13,2.62,0><-21.2,2.62,0> 1.75}
                sphere { <0, 0, 0>, 5.3 translate<-6.28,2.62,0>}
        }
        difference{
                merge{
                        intersection{
                                cylinder{<0,5.14-Ray,-1.74><0,5.14-Ray,+1.74> Ray}
                                box{<-4.13,0,-1.73><0,5.14,1.73>}
                               
                        }
                        cylinder{<-4.13,2.62,0><-11.2,2.62,0> 1.75}
                        intersection{
                                cylinder{<x1,5.14-Ray1,-1.74><x1,5.14-Ray1,+1.74> Ray}
                                box{<-0.01,0,-1.73><4.89,5.14,1.73>}
                        }
                }
                merge{
                        cylinder{< ff,2.35-rr1,-1.74><ff,2.35-rr1,+1.74> rr1}
                        box{<ff,-0.1,-1.74><5,2.35,+1.74>}
                        box{<ff-rr1,-0.1,-1.74><2,2.35-rr1,+1.74>}
                }
                box{<-5.6,-1,-1><0,+1,+1> rotate<45,0,40> translate<-1,7.8,-1.73>}
                box{<-5.6,-1,-1><0,+1,+1> rotate<45,0,40> translate<-1,7.8,+1.73>}
                box{<-5,-0.1,-1.3><+5,0.2,+1.3>}
        }
        object {LPIPEFOOT()}
        object {LPIPEFOOT() translate -2.9*x}
        
        texture {
            pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
            finish  {
                 ambient (0.6 * global_ambient_mul)
                diffuse 0.5
                reflection 0.7
                specular 0.8
                roughness 0.0003
                phong 0.3 
                phong_size 400
             }
        }
        rotate 180*y
        translate 3.76*x

}
#end
#macro SPC_LIGHTPIPE_5151049F()
SPC_LIGHTPIPE_5151049F_GRND()
#end


/********************************************************************************************************************************************
//Spule mit Kern: d=8mm,  h=10mm
//A. Zihlmann  - 12.2002 -  www.wueschomania.org
********************************************************************************************************************************************/
#macro SPC_L_5MM_S_GRND(value)
/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment{White*.3}
}
/** Objekte des Spulenkoeropers ************************************/
#local L_PHASE=
torus{
   4,0.5
   texture { OBERFLAECHE }
}
#local L_KABELNUT=
cylinder{
   <0, -4, 0>,
   <0,4,0>,
   0.75
   texture { OBERFLAECHE }
}

#local L_BODEN=
difference{
   cylinder {
       <0, 0, 0>,
       <0, 2, 0>,
        4
       texture { OBERFLAECHE }
   }
   union{
       object{L_PHASE}
       object{L_KABELNUT translate -4*x}
       object{L_KABELNUT translate 4*x}
   }
}

#local L_DECKEL=
   object{L_BODEN rotate x*180 translate 2*y}
#local L_CORE=

    cylinder {
       <0, 0, 0>,
       <0, 6, 0>,
        2
       texture {OBERFLAECHE }
    }

#local L_KERN=
union{
   object{L_BODEN}
   object{L_CORE translate y*2}
   object{L_DECKEL translate y*8}
}

/***** Kupferlackkabelemente ****************************************/
#local Drahtstaerke = .5;

#local L_WINDUNG =
torus {
   3, Drahtstaerke/2
   texture {T_Gold_1A }
}

#local L_ANSCHLUSS=
torus{
  0.5,Drahtstaerke/2
   texture{T_Gold_1A }
}

#local L_BOGEN=
difference {
    torus {
      1, Drahtstaerke/2
      rotate -90*x
    }
    union{
        box { <5, 5, -1>, <-5, 0, 1> }
        box { <0, 5, -1>, <5, -5, 1> }
    }
    texture{T_Gold_1A }
}
#local L_VERBINDUNG=
cylinder{
    <0,0,0>
    <0,2,0>
    Drahtstaerke/2
    texture{T_Gold_1A }
}

#local L_SPULE=

union {
    #local i=0;
    #while(i<11)
      object{L_WINDUNG translate i*Drahtstaerke*y}
      #local i=i+1;
    #end
}
/******* Die Beinchen ***************************************************/

#local L_Beinchen=
cylinder{
      <0,0,0>
      <0,6,0>
      0.25
      texture { T_Silver_1A }
}

/*** Zusammenbau der Spule: ***************************************************************/
#local L_BAUTEIL =
union{
   object{L_KERN}
   object{L_SPULE translate (2+Drahtstaerke/2)*y}
   object{L_Beinchen translate <-2.5,-6,0>}
   object{L_Beinchen translate <2.5,-6,0>}
   object{L_ANSCHLUSS translate <-2.5,-1,0>}
   object{L_ANSCHLUSS translate <-2.5,-0.5,0>}
   object{L_BOGEN translate -3*x}
   object{L_VERBINDUNG translate -4*x}
   object{L_BOGEN rotate -90*z translate <-3,2,0>}
   object{L_ANSCHLUSS translate <2.5,-1,0>}
   object{L_ANSCHLUSS translate <2.5,-0.5,0>}
   object{L_BOGEN rotate 180*y translate 3*x }
   object{L_VERBINDUNG translate 4*x}
   object{L_BOGEN rotate 180*z translate <3,2,0>}
   text {ttf besch_font value 0.01, 0 pigment{White}
           scale 2
           rotate 90*x rotate 180*y
           translate <2,10+0.1,-0.5>}
           }
object{L_BAUTEIL translate 2*y}
#end
#macro SPC_L_5MM_S(value)
SPC_L_5MM_S_GRND(value)
#end


/********************************************************************************************************************************************
// EF12 Spulenkern stehend by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_EF12_GRND(value)

union
{
 //***** Loetstifte
 cylinder{<-3.81,-3.5,-3.81><-3.81,1.1,-3.81>0.3 texture{col_silver}}
 cylinder{< 3.81,-3.5, 3.81>< 3.81,1.1, 3.81>0.3 texture{col_silver}}
 cylinder{< 3.81,-3.5,-3.81>< 3.81,1.1,-3.81>0.3 texture{col_silver}}
 cylinder{<-3.81,-3.5, 3.81><-3.81,1.1, 3.81>0.3 texture{col_silver}}


 //***** Kern
 union
 {
  difference
  {
   box{<-6,-1.75,-6><6,1.75,6>}
   box{<-4.5,-1.76,-4.5><4.5,1.76,4.5>}

   cylinder{< 6,-1.76, 6> < 6,1.76, 6> 1 }
   cylinder{<-6,-1.76,-6> <-6,1.76,-6> 1 }
   cylinder{<-6,-1.76, 6> <-6,1.76, 6> 1 }
   cylinder{< 6,-1.76,-6> < 6,1.76,-6> 1 }

  }
  cylinder{< 5,-1.75, 5> < 5,1.75, 5> 1 }
  cylinder{<-5,-1.75,-5> <-5,1.75,-5> 1 }
  cylinder{<-5,-1.75, 5> <-5,1.75, 5> 1 }
  cylinder{< 5,-1.75,-5> < 5,1.75,-5> 1 }

  pigment{rgb <0.3, 0.3, 0.3>}
  rotate<90,0,0>
  translate<0,6,0>
  }


 box{<-3,3,3><3,10,-3> texture {T_Gold_1A } }

 union  // Spulenkörper
 {


  difference
  {
   box{<-6, 0.5, 1.75>< 6,4, 5>}
   box{< 3, 0.4, 3><  1,4.1, 5.1>}
   box{<-1, 0.4, 3>< -3,4.1, 5.1>}

   cylinder{<  6, 0.4,5> <  6,4.1,5> 1 }
   cylinder{< -6, 0.4,5> < -6,4.1,5> 1 }

  }

  cylinder{<  5, 0.5,4> <  5,4,4> 1 }
  cylinder{< -5, 0.5,4> < -5,4,4> 1 }


  difference
  {
   box{<-6, 0.5, -1.75>< 6,4, -5>}
   box{< 3, 0.4, -3>< 1,4.1, -5.1>}
   box{<-1, 0.4, -3>< -3,4.1, -5.1>}
   cylinder{< 6,-0.4,-5> < 6,4.1,-5> 1 }
   cylinder{< -6,-0.4,-5> < -6,4.1,-5> 1 }
  }

  cylinder{<  5, 0.5,-4> <  5,4,-4> 1 }
  cylinder{< -5, 0.5,-4> < -5,4,-4> 1 }

  difference
  {
   box{<-5, 10, 5>< 5,11, -5>}
   box{< 3, 9, -3>< 1, 12, -5.1>}
   box{<-1, 9, -3>< -3,12, -5.1>}

   box{< 3, 9,  3>< 1, 12,  5.1>}
   box{<-1, 9,  3>< -3,12,  5.1>}

   cylinder{<  5, 9, 5> <  5,12, 5> 1 }
   cylinder{< -5, 9,-5> < -5,12,-5> 1 }
   cylinder{< -5, 9, 5> < -5,12, 5> 1 }
   cylinder{<  5, 9,-5> <  5,12,-5> 1 }
  }

  cylinder{<  4, 10, 4> <  4,11, 4> 1 }
  cylinder{< -4, 10,-4> < -4,11,-4> 1 }
  cylinder{< -4, 10, 4> < -4,11, 4> 1 }
  cylinder{<  4, 10,-4> <  4,11,-4> 1 }

  difference
  {
   box{<-4, 6.5, 4>< 4,7, -4>}
   cylinder{<  4, 5, 4> <  4,8, 4> 1 }
   cylinder{< -4, 5,-4> < -4,8,-4> 1 }
   cylinder{< -4, 5, 5> < -4,8, 4> 1 }
   cylinder{<  4, 5,-4> <  4,8,-4> 1 }
  }

  cylinder{<  3, 6.5, 3> <  3,7, 3> 1 }
  cylinder{< -3, 6.5,-3> < -3,7,-3> 1 }
  cylinder{< -3, 6.5, 3> < -3,7, 3> 1 }
  cylinder{<  3, 6.5,-3> <  3,7,-3> 1 }

  pigment{rgb <0.1, 0.1, 0.1>}

 }
}
#end


#macro SPC_L_EF12(value)
SPC_L_EF12_GRND(value)
#end


/********************************************************************************************************************************************
// EF16 Spulenkern liegend by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_EF16_GRND(value)

union
{
 //***** Loetstifte
 cylinder{<-7.62,-3.5,-7.62><-7.62,1.1,-7.62>0.3 texture{col_silver}}
 cylinder{< 7.62,-3.5, 7.62>< 7.62,1.1, 7.62>0.3 texture{col_silver}}
 cylinder{< 7.62,-3.5,-7.62>< 7.62,1.1,-7.62>0.3 texture{col_silver}}
 cylinder{<-7.62,-3.5, 7.62><-7.62,1.1, 7.62>0.3 texture{col_silver}}

 cylinder{<-2.54,-3.5,-7.62><-2.54,1.1,-7.62>0.3 texture{col_silver}}
 cylinder{<-2.54,-3.5, 7.62><-2.54,1.1, 7.62>0.3 texture{col_silver}}


 //***** Kern
 union
 {
  difference
  {
   box{<-8,3.5,-8><8,8,8>}
   box{<-6.5,3.4,-6.5><6.5,8.1,6.5>}

   cylinder{< 8,3.4, 8> < 8,8.1, 8> 1 }
   cylinder{<-8,3.4,-8> <-8,8.1,-8> 1 }
   cylinder{<-8,3.4, 8> <-8,8.1, 8> 1 }
   cylinder{< 8,3.4,-8> < 8,8.1,-8> 1 }

  }
  cylinder{< 7,3.5, 7> < 7,8, 7> 1 }
  cylinder{<-7,3.5,-7> <-7,8,-7> 1 }
  cylinder{<-7,3.5, 7> <-7,8, 7> 1 }
  cylinder{< 7,3.5,-7> < 7,8,-7> 1 }

  pigment{rgb <0.3, 0.3, 0.3>}
 }

 union  // Spulenkörper
 {

  difference
  {
   box{<-8,0.5,  9>< 8,3.5, 5.5>}
   box{<-7,0.4, 10><-5,3.6, 8>}
   box{<-4,0.4, 10><-2,3.6, 8>}
   box{<-1,0.4, 10>< 1,3.6, 8>}
   box{< 2,0.4, 10>< 4,3.6, 8>}
   box{< 5,0.4, 10>< 7,3.6, 8>}


  }

  difference
  {
   box{<-8,0.5,-9><8,3.5,-5.5>}
   box{<-7,0.4,-10><-5,3.6,-8>}
   box{<-4,0.4,-10><-2,3.6,-8>}
   box{<-1,0.4,-10>< 1,3.6,-8>}
   box{< 2,0.4,-10>< 4,3.6,-8>}
   box{< 5,0.4,-10>< 7,3.6,-8>}

  }


  difference
  {
   box{<-6,8,8><6,11,6>}
   box{<-7,8.5,8.1><-4,11.5,6.5>}
   box{<-3,8.5,8.1>< 3,11.5,6.5>}
   box{< 4,8.5,8.1>< 7,11.5,6.5>}
  }

  difference
  {
   box{<-6,8,-8><6,11,-6>}
   box{<-7,8.5,-8.1><-4,11.5,-6.5>}
   box{<-3,8.5,-8.1>< 3,11.5,-6.5>}
   box{< 4,8.5,-8.1>< 7,11.5,-6.5>}
  }

  pigment{rgb <0.5, 0.3, 0.3>}
 }


 box{<-4,3,6><4,10,-6> texture {T_Gold_1A } }

 union  // Draht
 {

  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,0> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,2> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,4> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,-2> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,-4> }

  pigment{rgb <0.6, 0.5, 0.2>}

 }

}
#end

#macro SPC_L_EF16(value)
SPC_L_EF16_GRND(value)
#end


/********************************************************************************************************************************************
//Murata Chip Coil: 2012 LQH3C/N
//R. Klenner
********************************************************************************************************************************************/
#macro SPC_L_MURATA_2012_LQH3C_GRND(value)
/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment{White*.3}
}
/** Objekte des Spulenkoerpers ************************************/
#local L_QUAD=
   box{<-1.3,0,-1.3><1.3,0.35,1.3> texture { OBERFLAECHE }
}

#local Drahtstaerke = .025;

#local L_Boden=
union{
   box{<-1.5,0,-1.45><1.5,0.275,1.45> texture { OBERFLAECHE }}
   box{<-2,0,-1.5><-1.5,0.3,1.5> texture{T_Silver_1A}}
   box{<2,0,-1.5><1.5,0.325,1.5> texture{T_Silver_1A}}
   union{
   difference{
        cylinder{<0,0,0><0,0.45,0>1.4 texture{ OBERFLAECHE }}
        cylinder{<-2,0.45,1><0,0.45,0.5> 0.2}
        cylinder{<2,0.45,-1><0,0.45,-0.5> 0.2}
   }
   cylinder{<-1.8,0.2,1><0,0.5,0.5> Drahtstaerke texture{T_Gold_1A }}
   cylinder{<1.8,0.2,-1><0,0.5,-0.5> Drahtstaerke texture{T_Gold_1A }}
   }
}

#local L_CORE=
    cylinder {<0, 0, 0><0, 1, 0>1 texture {OBERFLAECHE }
    }

#local L_KERN=
union{
   object{L_Boden}
   object{L_CORE translate y*0.25}
   object{L_QUAD translate y*1.25}
}

/***** Kupferlackkabelemente ****************************************/
#local L_WINDUNG =
torus {
   1.1, Drahtstaerke/2
   texture {T_Gold_1A }
}

#local L_SPULE=
union {
    #local i=0;
    #while(i<33)
      object{L_WINDUNG translate i*Drahtstaerke*y}
      #local i=i+1;
    #end
}
/*** Zusammenbau der Spule: ***************************************************************/
#local L_BAUTEIL =
union{
   object{L_KERN}
   object{L_SPULE translate (0.3+Drahtstaerke/2)*y}
   text {ttf besch_font value 0.01, 0 pigment{Red}
           scale 0.5
           rotate 90*x rotate 180*y
           translate <0.35,1.51,0>}
           }
object{L_BAUTEIL}
#end

#macro SPC_L_MURATA_2012_LQH3C(value)
SPC_L_MURATA_2012_LQH3C_GRND(value)
#end


/********************************************************************************************************************************************
//Macro fuer Spule, Kupferlackspule um Ringkern,     induktor.lib,      Joerg Bredendiek <sprut(replace with at)sprut.de>
//
// Nullpunkt:
//      stehende Spule: zwischen den Anschluessen
//      liegende Spule: in Ringkernmitte
//
// a = Abstand der Anschluesse
// b = Breite des Kerns
// d = Durchmesser des Kerns
// dd= Drahtdicke
// e = Abstand vom Ringkernmittelpunkt zum ersten Anschluss, nur bei liegender Spule
// o = 0 == liegend, sonst stehend
********************************************************************************************************************************************/
#macro SPC_L_TOROIDAL_GRND(a,b,d,dd,e,o)
// gelber Ringkern
#macro L_TOROIDAL_KERN(b,d)
union{
        object{
                torus{radmaj, radmin}
                translate<0, -delta/2, 0>
        }
        object{
                torus{radmaj, radmin}
                translate<0, delta/2, 0>
        }
        difference{
                cylinder{<0,-delta/2, 0><0,delta/2, 0>radmaj+radmin}
                cylinder{<0,-delta/2-0.1, 0><0,delta/2+0.1, 0>radmaj-radmin}
        }
        texture{pigment{color Yellow}}
}
#end

//eine einzelne Windung
#macro L_TOROIDAL_WINDUNG()
   torus { radmin+dd/2, dd/2 texture {T_Gold_1A }}
#end

//Windungen um den Kern
#macro L_TOROIDAL_SPULE()
   union {
      #local i=1;
           #local ss = 0;
           #local ss=int((radmaj-radmin-dd/2)*2*3.14/dd-0.5); //Anzahl der Windungen um den Kern zu fuellen
      #while(i<ss)
         union{
            difference{
               union{
            object{L_TOROIDAL_WINDUNG() translate <-delta/2, 0, 0>}
            object{L_TOROIDAL_WINDUNG() translate < delta/2, 0, 0>}
               }
               box{<-delta/2, -dd, radmin+dd><delta/2, dd, -radmin-dd>}
            }
            cylinder{<-delta/2, 0, radmin+dd/2>< delta/2, 0, radmin+dd/2> dd/2 texture {T_Gold_1A }}
            cylinder{<-delta/2, 0,-radmin-dd/2>< delta/2, 0,-radmin-dd/2> dd/2 texture {T_Gold_1A }}
            translate <0, 0, radmaj>
            rotate <90+i*360/ss, 0, 0>
            }
         #local i=i+1;
      #end
   }
#end

//Anschluesse fuer stehende Spule
#macro L_TOROIDAL_CONTV()
    #local ra=1;
    #local bends=array[5] {
    // <angle, radius, 0> or <0, distance, 0> for straight pipe,  negative angles bend left, positive bend right.
    <0, 3+1.5*dd-ra+2*radmin, 0>,  <-90, ra, 0>,  <0,a-2*ra,0>,  <-90,ra,0>,  <0, 3+1.5*dd-ra+2*radmin, 0> }

    // this pipe has a radius of dd/2, starts at the origin, and initially goes in the y direction
    TOOLS_BENTPIPE( dd/2, <0,0,0>, y, bends )
#end

//Anschluesse fuer liegende Spule
#macro L_TOROIDAL_CONTH()
    #local ra=a/2;
    #if (ra>b)
        #local ra=b;
    #end
    #local bends=array[5] {
    // <angle, radius, 0> or <0, distance, 0> for straight pipe, negative angles bend left, positive bend right.
    <0, 3+1.5*dd+b-ra, 0>,  <-90, ra, 0>,  <0,a-2*ra,0>,  <-90,ra,0>,  <0, 3+1.5*dd+b-ra, 0> }
    // this pipe has a radius of dd/2, starts at the origin, and initially goes in the y direction
    TOOLS_BENTPIPE( dd/2, <0,0,0>, y, bends )
#end

//Makro fuer stehende Spule
#macro L_TOROIDAL_SFT(a,b,d,dd)
   #local radmin = d/10;
   #local radmaj = d/2-radmin;
   #local delta  = b- 2*radmin;
   union {
      object {L_TOROIDAL_KERN(b,d) rotate<0,0,90> translate<0,radmaj+radmin+dd,0>}
      object {L_TOROIDAL_SPULE()                  translate<0,radmaj+radmin+dd,0>}
      object {L_TOROIDAL_CONTV()   translate<a/2, -3, 0> texture {T_Gold_1A }}
   }
#end

//Makro fuer liegende Spule
#macro L_TOROIDAL_ED(a,b,d,dd,e)
   #local radmin = d/10;
   #local radmaj = d/2-radmin;
   #local delta  = b- 2*radmin;
   union {
      object {L_TOROIDAL_KERN(b,d) rotate<0,0, 0>  translate<0,b/2+dd,0>}
      object {L_TOROIDAL_SPULE()   rotate<0,0,-90>  translate<0,b/2+dd,0>}
      object {L_TOROIDAL_CONTH()   translate<-e, -3, 0> texture {T_Gold_1A }}
   }
#end

#if(o=0)
    object{L_TOROIDAL_SFT(a,b,d,dd)}
#else
    object{L_TOROIDAL_ED(a,b,d,dd,e)}
#end

#end

#macro SPC_L_TOROIDAL_SFT830D()
SPC_L_TOROIDAL_GRND(10.16, 6.35, 15.875, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT830S()
SPC_L_TOROIDAL_GRND(10.16, 8.255, 15.875, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT840D()
SPC_L_TOROIDAL_GRND(12.7 , 8.89, 15.24, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT1030()
SPC_L_TOROIDAL_GRND(12.7 , 8.255, 20.32, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT1040()
SPC_L_TOROIDAL_GRND(15.24 , 10.8, 20.32, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT1240()
SPC_L_TOROIDAL_GRND(15.24 , 10.8, 22.86, 1,0,1)
#end
#macro SPC_L_TOROIDAL_ED16()
SPC_L_TOROIDAL_GRND(3.5*1.27 , 10.8, 12*1.27, 0.6, 3*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED22()
SPC_L_TOROIDAL_GRND(4*1.27 , 10.8, 16*1.27, 0.8, 4.5*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED26()
SPC_L_TOROIDAL_GRND(5.5*1.27 , 10.8, 19*1.27, 1, 5*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED38()
SPC_L_TOROIDAL_GRND(9*1.27 , 15, 26*1.27, 0.6, 6*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED43()
SPC_L_TOROIDAL_GRND(10*1.27 , 15, 30*1.27, 1.4, 7*1.27,0)
#end


/********************************************************************************************************************************************
// TYCO H38 inductor
********************************************************************************************************************************************/
#macro SPC_L_TYCO_H38_GRND(value)
union{
difference{
        box{<0,0,0><12,6,12>}     // Body
        cylinder{<6,-0.01,6><6,6.01,6> 5.5 }

        cylinder{<2,-0.01,2><2,6.01,2> 1.25 }
        cylinder{<2,-0.01,10><2,6.01,10> 1.25 }
        cylinder{<10,-0.01,2><10,6.01,2> 1.25 }
        cylinder{<10,-0.01,10><10,6.01,10> 1.25 }
}
        cylinder{<6,0,6><6,5.9,6> 5 }

text {ttf besch_font value 0.1, 0 pigment{Black} scale 2  rotate<90,0,0> translate<4,6,4>}
text {ttf besch_font "H38" 0.1, 0 pigment{Black} scale 2  rotate<90,0,0> translate<4,6,6>}
}
pigment{Gray20}
translate<-6,0,-6>
#end
#macro SPC_L_TYCO_H38(value)
SPC_L_TYCO_H38_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for LF type inductors from WE
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  17/01/08
//pin=pin diamenter ep=thickness
********************************************************************************************************************************************/
#macro SPC_L_WE_GI_LF_GRND(a,b,c,d1,ep,pin,value,lpin,dd,os)
#local dd=(b-ep)/2;//dd=(a-d1)/2; //pin holder diameter
#if(d1=0)
    #local d1=a-dd;
#end
#local d=1.5;//edge diameter
#local LA=c/4;//5; //bisel lenght
#local tc=7; //pin holder cylinders top
#local bc=1; //pin holder cylindres base
#local dm=0.2; //pin holder cylinder edge diameter
#local hb=4; //base height
#local lp=4.5; //wedge width
#local LT=a-d-(LA*sqrt(2));//top length
#local LH=c-d/2-(sqrt(2)*LA/2);//zero to bisel height
#local bends1=array[9] { <0,LH, 0>, <+45, 0.001, 0>, <0,LA,0>, <45,0.001,0>, <0, LT, 0>, <45, 0.001, 0>, <0,LA,0>, <45,0.001,0>,<0, LH, 0> }
#local bends2=array[9] { <0,LA/2, 0>, <+90, 0.001, 0>, <0,ep-d,0>, <90,0.001,0>, <0, LA, 0>, <90, 0.001, 0>, <0,ep-d,0>, <90,0.001,0>, <0,LA/2, 0> }

union{

    difference{
        union{
            object {
            TOOLS_BENTPIPE( d/2, <-a/2+d/2,0,0>, +y, bends1 )
            translate (-ep/2+d/2)*z
            }
            object {
            TOOLS_BENTPIPE( d/2, <-a/2+d/2,0,0>, +y, bends1 )
            translate (+ep/2-d/2)*z
            }
            object {
            TOOLS_BENTPIPE( d/2, <-ep/2+d/2,0,0>, +y, bends2 )
            rotate<45,90,0>
            translate<-a/2+d/2+(sqrt(2)/2*LA)/2,LH+(sqrt(2)/2*LA)/2,0>
            }
            object {
            TOOLS_BENTPIPE( d/2, <+ep/2-d/2,0,0>, +y, bends2 )
            rotate<45,-90,0>
            translate<+a/2-d/2-(sqrt(2)/2*LA)/2,LH+(sqrt(2)/2*LA)/2,-ep+d>
            }
            box{<-a/2+d/2,0,-ep/2><+a/2-d/2,LH,+ep/2>} //inside
            box{<-a/2,0,-ep/2+d/2><+a/2,LH,+ep/2-d/2>} //inside
            box{<-LT/2,0,-ep/2+d/2><+LT/2,c,+ep/2-d/2>}//top
            box{<-LT/2,0,-ep/2><+LT/2,c-d/2,+ep/2>}//top inside
            box{<-LA/2,LA/2,-ep/2><+LA/2,-LA/2,+ep/2> rotate 45*z translate<-a/2+(sqrt(2)/2*LA)+d/2,c-(sqrt(2)/2*LA)-d/2,0> }
            box{<-LA/2,LA/2,-ep/2><+LA/2,-LA/2,+ep/2> rotate 45*z translate<+a/2-(sqrt(2)/2*LA)-d/2,c-(sqrt(2)/2*LA)-d/2,0> }
            box{<-LA/2,-LA/2,-ep/2+d/2><+LA/2,LA/2,+ep/2-d/2> rotate 45*z translate<+a/2-(sqrt(2)/2*LA)-0.22,c-(sqrt(2)/2*LA)-0.22,0> }
            box{<-LA/2,-LA/2,-ep/2+d/2><+LA/2,LA/2,+ep/2-d/2> rotate 45*z translate<-a/2+(sqrt(2)/2*LA)+0.22,c-(sqrt(2)/2*LA)-0.22,0> }

            box{<-a/2+d/2,2,-ep/2-0.5><+a/2-d/2,hb,+ep/2-0.5>} //base

            box{<+a/2,0,-ep/2><+a/2-dd/2,tc-dm/2,+ep/2>}
            box{<-a/2,0,-ep/2><-a/2+dd/2,tc-dm/2,+ep/2>}
        }
        box{<-a/2-10,-0.1,-ep/2-10><+a/2+10,2,+ep/2+10>}
        text {ttf global_fontfile_arial_bold "WE" 0.07, 0  scale <3,5,4> rotate<45,90,0> translate<-a/2+0.7+os,c-(sqrt(2)/2*LA)-0.22+0.7+os,2.6>}
    }
    //wedges
    box{<-a/2+0.2,0,-lp/2><-a/2+1,3,+lp/2>}
    box{<+a/2+0.2,0,-lp/2><+a/2-1,3,+lp/2>}
    //pins
    cylinder{<-d1/2+dd/2+lpin,bc,-ep/2><-d1/2+dd/2+lpin,-4,-ep/2> pin/2 texture{col_silver}}
    cylinder{<+d1/2-dd/2-lpin,bc,-ep/2><+d1/2-dd/2-lpin,-4,-ep/2> pin/2 texture{col_silver}}
    cylinder{<-d1/2+dd/2+lpin,bc,+ep/2><-d1/2+dd/2+lpin,-4,+ep/2> pin/2 texture{col_silver}}
    cylinder{<+d1/2-dd/2-lpin,bc,+ep/2><+d1/2-dd/2-lpin,-4,+ep/2> pin/2 texture{col_silver}}
    #if(lpin=0)
    #local lpin=5.21;
    #end

    //pin holder cylinders
    cylinder{<-d1/2+dd/2,bc,-ep/2><-d1/2+dd/2,tc-dm/2,-ep/2>,dd}
    cylinder{<+d1/2-dd/2,bc,-ep/2><+d1/2-dd/2,tc-dm/2,-ep/2>,dd}
    cylinder{<-d1/2+dd/2,bc,+ep/2><-d1/2+dd/2,tc-dm/2,+ep/2>,dd}
    cylinder{<+d1/2-dd/2,bc,+ep/2><+d1/2-dd/2,tc-dm/2,+ep/2>,dd}

    cylinder{<-d1/2+dd/2+lpin,bc,-ep/2><-d1/2+dd/2+lpin,tc-dm/2,-ep/2>,dd}
    cylinder{<+d1/2-dd/2-lpin,bc,-ep/2><+d1/2-dd/2-lpin,tc-dm/2,-ep/2>,dd}
    cylinder{<-d1/2+dd/2+lpin,bc,+ep/2><-d1/2+dd/2+lpin,tc-dm/2,+ep/2>,dd}
    cylinder{<+d1/2-dd/2-lpin,bc,+ep/2><+d1/2-dd/2-lpin,tc-dm/2,+ep/2>,dd}
    //top of pin holder cylinders
    torus{dd-dm,dm translate<-d1/2+dd/2,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<-d1/2+dd/2,tc-dm/2,+ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2,tc-dm/2,+ep/2>}

    torus{dd-dm,dm translate<-d1/2+dd/2+lpin,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2-lpin,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<-d1/2+dd/2+lpin,tc-dm/2,+ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2-lpin,tc-dm/2,+ep/2>}

    cylinder{<-d1/2+dd/2,bc,-ep/2><-d1/2+dd/2,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2,bc,-ep/2><+d1/2-dd/2,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<-d1/2+dd/2,bc,+ep/2><-d1/2+dd/2,tc+dm/2,+ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2,bc,+ep/2><+d1/2-dd/2,tc+dm,+ep/2>,dd-dm}

    cylinder{<-d1/2+dd/2+lpin,bc,-ep/2><-d1/2+dd/2+lpin,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2-lpin,bc,-ep/2><+d1/2-dd/2-lpin,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<-d1/2+dd/2+lpin,bc,+ep/2><-d1/2+dd/2+lpin,tc+dm/2,+ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2-lpin,bc,+ep/2><+d1/2-dd/2-lpin,tc+dm/2,+ep/2>,dd-dm}

    //marks
    text {ttf global_fontfile_alphalcd value 0.01, 0  pigment{Black} scale <2.3,2.3,2> rotate<0,0,0> translate<-a/2+1+(a-18.5)/2,tc+1+(c-20.5)/2,-ep/2-0.05>}
    text {ttf global_fontfile_alphalcd " WE  1OO7" 0.01, 0  pigment{Black} scale <2.3,2.3,2> rotate<0,0,0> translate<-a/2+1+(a-18.5)/2,tc+3.8+(c-20.5)/2,-ep/2-0.05>}
    text {ttf global_fontfile_alphalcd "2*39mHO,4A" 0.01, 0  pigment{Black} scale <2.3,2.3,2> rotate<0,0,0> translate<-a/2+1+(a-18.5)/2,tc+6.6+(c-20.5)/2,-ep/2-0.05>}
    //solded wire
    sphere { <-d1/2+lpin,bc/2,-ep/2>, pin  texture{col_silver}}
    sphere { <-d1/2+lpin,bc/2,+ep/2>, pin  texture{col_silver}}
    sphere { <+d1/2-lpin,bc/2,-ep/2>, pin  texture{col_silver}}
    sphere { <+d1/2-lpin,bc/2,+ep/2>, pin  texture{col_silver}}

    pigment {Brown}

}
#end

#macro SPC_L_WE_612SV(value)
SPC_L_WE_GI_LF_GRND(18.5,13.5,20.5,15.5+1.5,10,0.6,value,0,3,0)
#end
#macro SPC_L_WE_SV(value)
SPC_L_WE_GI_LF_GRND(18.5,13.5,20.5,0,10,0.6,value,5.21,3,0)
#end
#macro SPC_L_WE_622MV(value)
SPC_L_WE_GI_LF_GRND(23.5,16,25.5,0,12.5,0.6,value,5,3,0.45)
#end
#macro SPC_L_WE_632LV(value)
SPC_L_WE_GI_LF_GRND(26.5,18.5,30.5,0,15,0.6,value,5.25,3,0.9)
#end
#macro SPC_L_WE_642XV(value)
SPC_L_WE_GI_LF_GRND(32.5,21.5,35.5,0,17.5,0.8,value,8,3.5,1.4)
#end


/********************************************************************************************************************************************
//  by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_WE_PD4_GRND(value)

/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment{White*.3}
}
/** Objekte des Spulenkoerpers ************************************/
#local L_QUAD=
union
{
 cylinder{<0,-0.175,0><0,0.175,0> 1.15 texture { OBERFLAECHE } }
 torus{ 1.15 0.175 texture { OBERFLAECHE } }
}

#local Drahtstaerke = .025;

#local L_Boden=

difference
{
 union
 {
   box{<-1.5,0,-1.45><1.5,0.275,1.45> texture { OBERFLAECHE }}
   box{<-2,0,-1.5><-1.5,0.3,1.5> texture{T_Silver_1A}}
   box{<2,0,-1.5><1.5,0.325,1.5> texture{T_Silver_1A}}
   union{
   difference{
        cylinder{<0,0,0><0,0.45,0>1.4 texture{ OBERFLAECHE }}
        cylinder{<-2,0.45,1><0,0.45,0.5> 0.2}
        cylinder{<2,0.45,-1><0,0.45,-0.5> 0.2}
   }
   cylinder{<-1.8,0.2,1><0,0.5,0.5> Drahtstaerke texture{T_Gold_1A }}
   cylinder{<1.8,0.2,-1><0,0.5,-0.5> Drahtstaerke texture{T_Gold_1A }}
   }
 }

 box{<3,-0.5,-1.5><1.5,0.5,1.5> rotate<0,60,0>  texture { OBERFLAECHE }}
 box{<3,-0.5,-1.5><1.5,0.5,1.5> rotate<0,-60,0> texture { OBERFLAECHE }}
 box{<-3,-0.5,-1.5><-1.5,0.5,1.5> rotate<0,60,0> texture { OBERFLAECHE }}
 box{<-3,-0.5,-1.5><-1.5,0.5,1.5> rotate<0,-60,0> texture { OBERFLAECHE }}

}

#local L_CORE=
    cylinder {<0, 0, 0><0, 1, 0>1 texture {OBERFLAECHE }
    }

#local L_KERN=
union{
   object{L_Boden}
   object{L_CORE translate y*0.25}
   object{L_QUAD translate y*1.25}
}

/***** Kupferlackkabelemente ****************************************/
#local L_WINDUNG =
torus {
   1.1, Drahtstaerke/2
   texture {T_Gold_1A }
}

#local L_SPULE=
union {
    #local i=0;
    #while(i<33)
      object{L_WINDUNG translate i*Drahtstaerke*y}
      #local i=i+1;
    #end
}
/*** Zusammenbau der Spule: ***************************************************************/
#local L_BAUTEIL =
union{
      object{L_KERN}
      object{L_SPULE translate (0.3+Drahtstaerke/2)*y}
      text {ttf besch_font value 0.1, 0 pigment{White} scale 0.5 rotate 90*x rotate 180*y translate <0.7,1.45,0.2>}
      scale 3
     }

object{L_BAUTEIL}
#end


#macro SPC_L_WE_PD4(value)
SPC_L_WE_PD4_GRND(value)
#end


/********************************************************************************************************************************************
//  by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_WE_PDM_GRND(value)

union
{
difference
{
 union
 {
   difference
   {
    box{<-3.65,0.5,-3.65><3.65,4,3.65> }
    cylinder{ < 3.65,0, 3.65> < 3.65,5, 3.65> 1 }
    cylinder{ <-3.65,0, 3.65> <-3.65,5, 3.65> 1 }
    cylinder{ < 3.65,0,-3.65> < 3.65,5,-3.65> 1 }
    cylinder{ <-3.65,0,-3.65> <-3.65,5,-3.65> 1 }
   }

   cylinder{ < 2.65,0.5, 2.65> < 2.65,4, 2.65> 1 }
   cylinder{ <-2.65,0.5, 2.65> <-2.65,4, 2.65> 1 }
   cylinder{ < 2.65,0.5,-2.65> < 2.65,4,-2.65> 1 }
   cylinder{ <-2.65,0.5,-2.65> <-2.65,4,-2.65> 1 }

   pigment{rgb <0.3, 0.3, 0.3>}
 }
 box{<-3.5,3.9,-0.7><3.5,4.5,0.7> rotate <0, 45, 0>}
 box{<-3.5,3.9,-0.7><3.5,4.5,0.7> rotate <0, -45, 0>}
 cylinder{ <0,3.9,0> <0,5,0> 2.7 }
 pigment{rgb <0.3, 0.3, 0.3>}
}
text {ttf besch_font value 0, 0 pigment{White} scale<1.5,2,2> rotate<90,-90,0> translate<1,3.95,-2>}
}

#end



#macro SPC_L_WE_PDM(value)
SPC_L_WE_PDM_GRND(value)
#end


/********************************************************************************************************************************************
//dahamm(at)gmx.net
********************************************************************************************************************************************/
#macro SPC_L_WE_PD_GRND(value, A, B, C, D)
#local r = 2; //Kantenradius
#local s = 0.5; //Gehäuseanhebung
#local ri = A / 2 - 1; //Kernradius
#local rx = A / 10;

   union
   {
      difference
      {
         union
         {
            cylinder{<A/2 - r, s, A/2 - r><A/2 - r, s + B, A/2 - r> r}
            cylinder{<-A/2 + r, s, A/2 - r><-A/2 + r, s + B, A/2 - r> r}
            cylinder{<A/2 - r, s, -A/2 + r><A/2 - r, s + B, -A/2 + r> r}
            cylinder{<-A/2 + r, s, -A/2 + r><-A/2 + r, s + B, -A/2 + r> r}
            box{<A/2, s, A/2 - r><-A/2, s + B, -A/2 + r>}
            box{<A/2 - r, s, A/2><-A/2 + r, s + B, -A/2>}
         }

         cylinder{<0.707 * ri, 0, 0.7 * ri><0.7 * ri, s + B + 1, 0.7 * ri> rx}
         cylinder{<-0.707 * ri, 0, 0.7 * ri><-0.7 * ri, s + B + 1, 0.7 * ri> rx}
         cylinder{<0.707 * ri, 0, -0.7 * ri><0.7 * ri, s + B + 1, -0.7 * ri> rx}
         cylinder{<-0.707 * ri, 0, -0.7 * ri><-0.7 * ri, s + B + 1, -0.7 * ri> rx}
      }

      torus{ri - 0.5, 0.5 translate<0, s + B, 0>}
      cylinder{<0, s + B, 0><0, s + B + 0.5, 0> ri - 0.5}

      box{<-D/2, 0, A/2><D/2, s, A/2 - C/2> texture{col_silver}}
      box{<-D/2, 0, -A/2><D/2, s, -A/2 + C/2> texture{col_silver}}

      text {ttf besch_font value 1, 0 pigment{Gray80} scale 2  rotate<90,0,0> translate<-2,s + B + 0.8, 0>}


      pigment{Gray20}
      rotate<0, 90, 0>
   }


#end


#macro SPC_L_WE_PD_S(value)
SPC_L_WE_PD_GRND(value, 7.3, 3.2, 1.5, 1.5)
#end
#macro SPC_L_WE_PD_M(value)
SPC_L_WE_PD_GRND(value, 7.3, 4.5, 2.0, 1.5)
#end
#macro SPC_L_WE_PD_L(value)
SPC_L_WE_PD_GRND(value, 12.0, 6.0, 8.0, 5.0)
#end
#macro SPC_L_WE_PD_XL(value)
SPC_L_WE_PD_GRND(value, 12.0, 8.0, 8.0, 5.0)
#end
#macro SPC_L_WE_PD_XXL(value)
SPC_L_WE_PD_GRND(value, 12.0, 10.0, 7.6, 5.0)
#end


/********************************************************************************************************************************************
//Macros for MURATA NFE61P EMI FILTERS
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/01/06
********************************************************************************************************************************************/
#macro SPC_MURATA_CSTCC_G_A_GRND(value)
union{
    difference{
        union{
            superellipsoid { <0.09, 0.09> scale <3.6,0.25,1.5> translate <0,0.25,0> }
            intersection{
                superellipsoid { <0.09, 0.09> scale <3.6,0.25,1.5> translate <0,0.25,0> }
                union{
                    box{<-4,-0.1,-1.6><-3.1,1,+1.6>}
                    box{<-1.9,-0.1,-1.6><-0.7,1,+1.6>}
                    box{<+0.7,-0.1,-1.6><+1.9,1,+1.6>}
                    box{<+4,-0.1,-1.6><+3.1,1,+1.6>}
                }
                pigment{color red 0.85 green 0.85 blue 0.71}
            }     
        }
        union{
            cylinder{<-2.5,0,-1.5><-2.5,0.6,-1.5> 0.23 }
            cylinder{<+2.5,0,-1.5><+2.5,0.6,-1.5> 0.23 }
            cylinder{<0,0,-1.5><0,0.6,-1.5> 0.23 }
            cylinder{<-2.5,0,+1.5><-2.5,0.6,+1.5> 0.23 }
            cylinder{<+2.5,0,+1.5><+2.5,0.6,+1.5> 0.23 }
            cylinder{<0,0,+1.5><0,0.6,+1.5> 0.23 }
        }
        texture{col_silver}
    }
    difference{
        superellipsoid { <0.2, 0.2> scale <3.3,1.55,1.05> translate <0,0,0>  }
        union{
            box{<-3.4,0,-1.6><+3.4,-2,+1.6> texture{col_silver}}
            text {ttf global_fontfile_arial value 0.08, 0 scale 1 rotate<90,0,0> translate<-2,1.6,-0.45>}     // Ref Marking
        }
        texture{col_silver}
    }
}
#end
#macro SPC_MURATA_CSTCC_G_A(value)
SPC_MURATA_CSTCC_G_A_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for MURATA NFE61P EMI FILTERS
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/01/06
********************************************************************************************************************************************/
#macro SPC_MURATA_NFE61P_GRND()
union{
    difference{
        superellipsoid { <0.09, 0.09> scale <3.4,0.8,0.8> translate <0,0.8,0> texture{col_silver} }
        cylinder{<-2.7,0.8,0><+2.7,0.8,0> 1.2 texture{col_silver}}
    }
    superellipsoid { <0.09, 0.09> scale <1.3,0.8,0.8> translate <0,0.8,0> texture{col_silver} }
    cylinder{<-2.7,0.8,0><+2.7,0.8,0> 0.7 pigment{Gray30}}
}
#end
#macro SPC_MURATA_NFE61P()
SPC_MURATA_NFE61P_GRND()
#end











/********************************************************************************************************************************************
// Auth: Gary French <gary@chromiteblue.com>
//
// Uses existing TOOLS_WIRE_LEADS macro to generate simple wire jumpers.
// SPC_SIMPLE_WIRE_JUMPER_GRND(l,d,r,lw,dw,op,w)
//   l:  length, passed to TOOLS_WIRE_LEADS:Length
//   d:  diameter, passed to TOOLS_WIRE_LEADS:Width
//   r:  raster, passed to TOOLS_WIRE_LEADS:Raster
//   lw: length of wire, 2 * value passed to TOOLS_WIRE_LEADS:Wirelength
//   dw:
//   op: offset?
//   w:
// Defined values:
//   jumper_diameter: wire diameter (currently defaults to the value of dim_mm_awg_24)
//   jumper_bend_radius: radius of jumper corners
//   jumper_seperation: distance of jumper from board surface
********************************************************************************************************************************************/
#macro SPC_SIMPLE_WIRE_JUMPER_GRND(l,d,r,lw,dw,op,w)
//general declarations
#local user_pcb_hole_pitch = 2.54;

//typical wire gauges scaled to Eagle3D
#local dim_mm_awg_16 = 1.290; //AWG-16
#local dim_mm_awg_18 = 1.024; //AWG-18 (standard)
#local dim_mm_awg_20 = 0.812; //AWG-20
#local dim_mm_awg_22 = 0.644; //AWG-22
#local dim_mm_awg_24 = 0.511; //AWG-24
#local dim_mm_awg_26 = 0.405; //AWG-26

#local jumper_diameter = dim_mm_awg_24;
#local jumper_bend_radius = 0.200;
#local jumper_seperation = 0.0;

object{
    TOOLS_WIRE_LEADS(l,d,lw*2,dim_mm_awg_24,r,jumper_bend_radius,jumper_seperation,"H")
    translate<0,dim_mm_awg_24/2+op,0>
}
#end

#macro SPC_SIMPLE_WIRE_JUMPER_05MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*2, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_07MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*3, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_10MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*4, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_12MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*5, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_15MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*6, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_20MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*8, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_25MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*10, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_30MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*12, 20, 0.6, 0, 0.3)
#end


/********************************************************************************************************************************************
// SMD-Drossel von CTC
// http://www.ctccoils.com
// L - Gesamt Länge der Drossel
// B - Gesamt Breite der Drossel
// H - Gesamt Höhe der Drossel
// value - Aufschrift
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro SPC_SMD_INDUCTOR_SMSL_GRND(L,B,H,value)

#local PX = 2.54;       // Pad-Größe

#local U = 0.1;         // Überlappung Differenzebildung
#local R = B*0.9/2;     // Radius Spulenkörper
#local R1 = 0.2;        // Radius Draht
#local H1 = 0.8;        // Höhe Grundplatte
#local H2 = 0.6;        // Dicke der Deckplatten der Spule
#local L1 = L*0.95/2;   // Halbe Länge der Grundplatte
#local X1 = L1*0.2;     // Halbe Länge der geraden Seite
#local Z1 = B*0.33/2;   // Halbe Breite der geraden Seite

#declare Draht =  torus{ R-R1-0.3, R1 
                        texture{Copper_Metal
                                pigment{color rgb<0.7,0.2,0>}
                                finish {metallic brilliance 4  ambient (0.1 * global_ambient_mul)}
                        }            
                  }
#local H3 = H-0.1-H1-2*H2;
#local A = int(H3 / (2*R1)) + 1;    // Anzahl der Windungen
#local C = H3 / A;
#local Y2 = H1+H2+R1;

union{
        box{ <-L/2+H1/4, 0, -B*0.30/2> <-L/2+PX, H1+0.2, B*0.30/2> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
        cylinder{ < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
                scale< 0.5, 1, 1>
                translate<-L/2+H1/4, H1/2+0.1, 0>
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }
        box{ < L/2-H1/4, 0, -B*0.30/2> < L/2-PX, H1+0.2, B*0.30/2> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
        cylinder{ < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
                scale< 0.5, 1, 1>
                translate< L/2-H1/4, H1/2+0.1, 0>
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }


        prism{ 0.1, H1, 9
                <-X1,-B/2>, < X1,-B/2>, < L1,-Z1>, < L1, Z1>, < X1, B/2>, 
                <-X1, B/2>, <-L1, Z1>, <-L1,-Z1>, <-X1,-B/2>
                texture{pigment{ Gray20 }}
        }
        
        cylinder{ < 0, 0.1+H1, 0> < 0, 0.1+H1+H2, 0> R-H2/2 
                texture{pigment{ Gray10 }}
        }
        torus{ R-H2/2, H2/2
                texture{pigment{ Gray10 }}
                translate< 0, 0.1+H1+H2/2, 0>
        }

        cylinder{ < 0, H, 0> < 0, H-H2, 0> R-H2/2 
                texture{pigment{ Gray10 }}
        }
        torus{ R-H2/2, H2/2
                texture{pigment{ Gray10 }}
                translate< 0, H-H2/2, 0>
        }
        
        #while ( A >= 0 )
                object{ Draht translate< 0, Y2, 0> }
                #declare Y2 = Y2 + C;
                #declare A = A -1;
        #end
        
        text{ttf global_fontfile_arial value 0.1,0 rotate<90,0,0> scale<1.8,1,1.8> translate<-R+1, H+0.01, 0.0> pigment{Gray60}}

}
#end

#macro SPC_SMD_INDUCTOR_SMSL_1305(value)
SPC_SMD_INDUCTOR_SMSL_GRND(12.95, 9.4, 5.21, value)
#end


/********************************************************************************************************************************************
//Macros for horizontal laser tranceiver/receiver TORX173/TOTX173 Toshiba
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  05/06/07
********************************************************************************************************************************************/
#macro SPC_TOXX173_GRND(value)
union{
    union{
        difference{
            box{<-6.5,0.5,+5.5><+6.5,8.5,-10>}
            box{<-6.1,-0.1,+3.3><-6.6,8.6,+4.5>}
            box{<+6.1,-0.1,+3.3><+6.6,8.6,+4.5>}
            box{<-6.6,+8.1,+3.3><+6.6,8.6,+4.5>}
            cylinder{<-5.2,1,-4.2><-5.1,8.6,-4.2>,0.3}
            cylinder{<+5.2,1,-4.2><+5.1,8.6,-4.2>,0.3}
            box{<-1.35,-0.1,-6.5><+1.35,8.6,-7.7>}
            box{<-5.1,+1.6,-5.4><-6.6,7.5,-10.1>}
            box{<+5.1,+1.6,-5.4><+6.6,7.5,-10.1>}
            box{<-4.3,-0.1,-5.4><-5.101,6.5,-8.4>}
            box{<+4.3,-0.1,-5.4><+5.101,6.5,-8.4>}
            box{<+3.1,+2.7,-4.2><-3.1,+7.5,-10.1>}
            box{<+1.7,+1.3,-4.2><-1.7,+7.5,-10.1>}
            box{<-1,-1,-4.2><+1,+1,-10.1> rotate 45*z translate<+1.7,2.7,0>} 
            box{<-1,-1,-4.2><+1,+1,-10.1> rotate 45*z translate<-1.7,2.7,0>} 
            cylinder{<-3,+4.5,-4.2><-3,+4.5,-10.1>,1}
            cylinder{<+3,+4.5,-4.2><+3,+4.5,-10.1>,1}
        }
        difference{
            box{<-2,6.5,-8.1><+2,2.5,0>}
            box{<-1,-0.5,-4.2><+1,+0.5,-10.1> rotate 45*z translate<+2,2.7,0>}
            box{<-1,-0.5,-4.2><+1,+0.5,-10.1> rotate -45*z translate<-2,2.7,0>}
            cylinder{<0,+4.3,-4.2><0,+4.3,-10.1>,1}
            pigment{Gray20}
        }
        box{<-3.81-0.6,0,+5.5,><-3.81+0.6,0.5,-10>}
        box{<+3.81-0.6,0,+5.5,><+3.81+0.6,0.5,-10>}
        pigment{Gray30}
    }
    #if (value = 0)
    text{ttf global_fontfile_arial_bold "TORX173" 0.5,0 pigment{Gray60} scale<2.5,4,0.1> rotate <90,180,0> translate<+5,8.51,-0>}
    #else
    text{ttf global_fontfile_arial_bold "TOTX173" 0.5,0 pigment{Gray60} scale<2.5,4,0.1> rotate <90,180,0> translate<+5,8.51,-0>}
    #end
    text{ttf global_fontfile_arial_bold "JAPAN" 0.5,0 pigment{Gray60} scale<1,2,0.1> rotate <90,180,0> translate<+1.5,8.51,2>}
    union{
        cylinder{<-5.2,-3.5,-4.2><-5.1,1,-4.2>,0.3}
        cylinder{<+5.2,-3.5,-4.2><+5.1,1,-4.2>,0.3}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate +1.27*x}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate +3.81*x}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate -1.27*x}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate -3.81*x}
        texture{col_silver}
    }
}
#end
#macro SPC_TOTX173()
SPC_TOXX173_GRND(1)
#end
#macro SPC_TORX173()
SPC_TOXX173_GRND(0)
#end


#end
//End of Macros
