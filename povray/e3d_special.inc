/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


#ifndef(__special_inc)
#declare __special_inc = true;

#include "e3d_tools.inc"
#include "BOARDS/digilent.inc"            // 06.04.2022, add Digilent S6 FPGA devboard
#include "BUZZER/TDB.inc"                 // 29.03.2023, move SPC_BUZZER_TDB to BUZZER/TDB.inc
#include "CONNECTOR/wirejumper.inc"       // 02.04.2023, move wire jumpers to CONNECTOR/wirejumper.inc
#include "CRYSTAL/ceramic_resonator.inc"  // 29.03.2023, move ceramic resonators to CRYSTAL/ceramic_resonator.inc
#include "CRYSTAL/crystal.inc"            // 30.03.2023, move crystals to CRYSTAL/crystal.inc
#include "CRYSTAL/oscillator.inc"         // 25.03.2023, add 3.2 x 2.5mm oscillator
#include "DCDC/Murata.inc"                // 02.04.2023, move DC/DC to DCDC/Murata.inc
#include "DCDC/Traco.inc"                 // 06.04.2022, move DC/DC to DCDC/traco.inc
#include "FUSE/SHK20L.inc"                // 30.03.2023, move fuses to subfolder
#include "FUSE/SHK20Q.inc"                // 30.03.2023, move fuses to subfolder
#include "HEATSINK/KL195.inc"             // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/RAxx.inc"              // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/SK96.inc"              // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/SK104.inc"             // 30.03.2023, move heatsinks to subfolder
#include "HEATSINK/viewcom.inc"           // 30.03.2023, move heatsinks to subfolder
#include "INDUCTOR/L_5MM_S.inc"           // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/L_EF_core.inc"         // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/Murata.inc"            // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/toroids.inc"           // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/Tyco.inc"              // 03.04.2023, move inductors to subfolder
#include "INDUCTOR/WuerthElektronik.inc"  // 03.04.2023, move inductors to subfolder


#include "OPTO/lightpipe.inc"             // 02.04.2023, move lightpipe to subfolder
#include "RELAY/Celduc.inc"               // 31.03.2023, move relays to subfolder
#include "RELAY/Omron.inc"                // 31.03.2023, move relays to subfolder
#include "RELAY/Panasonic.inc"            // 31.03.2023, move relays to subfolder
#include "RELAY/Schrack.inc"              // 31.03.2023, move relays to subfolder
#include "RELAY/SIL.inc"                  // 31.03.2023, move relays to subfolder
















/*******************************************************************************
//  by Anderas Fecht
*******************************************************************************/
#macro SPC_L_WE_PD4_GRND(value)

/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment {White*.3}
}
/** Objekte des Spulenkoerpers ************************************/
#local L_QUAD=
union
{
 cylinder {<0,-0.175,0> <0,0.175,0> 1.15 texture { OBERFLAECHE } }
 torus { 1.15 0.175 texture { OBERFLAECHE } }
}

#local Drahtstaerke = .025;

#local L_Boden=

difference
{
 union
 {
   box {<-1.5,0,-1.45> <1.5,0.275,1.45> texture { OBERFLAECHE }}
   box {<-2,0,-1.5> <-1.5,0.3,1.5> texture{T_Silver_1A}}
   box {<2,0,-1.5> <1.5,0.325,1.5> texture{T_Silver_1A}}
   union {
   difference {
        cylinder {<0,0,0> <0,0.45,0>1.4 texture{ OBERFLAECHE }}
        cylinder {<-2,0.45,1> <0,0.45,0.5> 0.2}
        cylinder {<2,0.45,-1> <0,0.45,-0.5> 0.2}
   }
   cylinder {<-1.8,0.2,1> <0,0.5,0.5> Drahtstaerke texture{T_Gold_1A }}
   cylinder {<1.8,0.2,-1> <0,0.5,-0.5> Drahtstaerke texture{T_Gold_1A }}
   }
 }

 box {<3,-0.5,-1.5> <1.5,0.5,1.5> rotate <0,60,0>  texture { OBERFLAECHE }}
 box {<3,-0.5,-1.5> <1.5,0.5,1.5> rotate <0,-60,0> texture { OBERFLAECHE }}
 box {<-3,-0.5,-1.5> <-1.5,0.5,1.5> rotate <0,60,0> texture { OBERFLAECHE }}
 box {<-3,-0.5,-1.5> <-1.5,0.5,1.5> rotate <0,-60,0> texture { OBERFLAECHE }}

}

#local L_CORE=
    cylinder {<0, 0, 0> <0, 1, 0>1 texture {OBERFLAECHE }
    }

#local L_KERN=
union {
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
union {
      object{L_KERN}
      object{L_SPULE translate (0.3+Drahtstaerke/2)*y}
      text { ttf besch_font value 0.1, 0 pigment {White} scale 0.5 rotate 90*x rotate 180*y translate <0.7,1.45,0.2>}
      scale 3
     }

object{L_BAUTEIL}
#end


#macro SPC_L_WE_PD4(value)
SPC_L_WE_PD4_GRND(value)
#end


/*******************************************************************************
//  by Anderas Fecht
*******************************************************************************/
#macro SPC_L_WE_PDM_GRND(value)

union
{
difference
{
 union
 {
   difference
   {
    box {<-3.65,0.5,-3.65> <3.65,4,3.65> }
    cylinder { < 3.65,0, 3.65> < 3.65,5, 3.65> 1 }
    cylinder { <-3.65,0, 3.65> <-3.65,5, 3.65> 1 }
    cylinder { < 3.65,0,-3.65> < 3.65,5,-3.65> 1 }
    cylinder { <-3.65,0,-3.65> <-3.65,5,-3.65> 1 }
   }

   cylinder { < 2.65,0.5, 2.65> < 2.65,4, 2.65> 1 }
   cylinder { <-2.65,0.5, 2.65> <-2.65,4, 2.65> 1 }
   cylinder { < 2.65,0.5,-2.65> < 2.65,4,-2.65> 1 }
   cylinder { <-2.65,0.5,-2.65> <-2.65,4,-2.65> 1 }

   pigment {rgb <0.3, 0.3, 0.3>}
 }
 box {<-3.5,3.9,-0.7> <3.5,4.5,0.7> rotate <0, 45, 0>}
 box {<-3.5,3.9,-0.7> <3.5,4.5,0.7> rotate <0, -45, 0>}
 cylinder { <0,3.9,0> <0,5,0> 2.7 }
 pigment {rgb <0.3, 0.3, 0.3>}
}
text { ttf besch_font value 0, 0 pigment {White} scale<1.5,2,2> rotate <90,-90,0> translate <1,3.95,-2>}
}

#end



#macro SPC_L_WE_PDM(value)
SPC_L_WE_PDM_GRND(value)
#end


/*******************************************************************************
//dahamm(at)gmx.net
*******************************************************************************/
#macro SPC_L_WE_PD_GRND(value, A, B, C, D)
#local r = 2; //Kantenradius
#local s = 0.5; //Gehaeuseanhebung
#local ri = A / 2 - 1; //Kernradius
#local rx = A / 10;

   union
   {
      difference
      {
         union
         {
            cylinder {<A/2 - r, s, A/2 - r> <A/2 - r, s + B, A/2 - r> r}
            cylinder {<-A/2 + r, s, A/2 - r> <-A/2 + r, s + B, A/2 - r> r}
            cylinder {<A/2 - r, s, -A/2 + r> <A/2 - r, s + B, -A/2 + r> r}
            cylinder {<-A/2 + r, s, -A/2 + r> <-A/2 + r, s + B, -A/2 + r> r}
            box {<A/2, s, A/2 - r> <-A/2, s + B, -A/2 + r>}
            box {<A/2 - r, s, A/2> <-A/2 + r, s + B, -A/2>}
         }

         cylinder {<0.707 * ri, 0, 0.7 * ri> <0.7 * ri, s + B + 1, 0.7 * ri> rx}
         cylinder {<-0.707 * ri, 0, 0.7 * ri> <-0.7 * ri, s + B + 1, 0.7 * ri> rx}
         cylinder {<0.707 * ri, 0, -0.7 * ri> <0.7 * ri, s + B + 1, -0.7 * ri> rx}
         cylinder {<-0.707 * ri, 0, -0.7 * ri> <-0.7 * ri, s + B + 1, -0.7 * ri> rx}
      }

      torus {ri - 0.5, 0.5 translate <0, s + B, 0>}
      cylinder {<0, s + B, 0> <0, s + B + 0.5, 0> ri - 0.5}

      box {<-D/2, 0, A/2> <D/2, s, A/2 - C/2> texture{col_silver}}
      box {<-D/2, 0, -A/2> <D/2, s, -A/2 + C/2> texture{col_silver}}

      text { ttf besch_font value 1, 0 pigment {Gray80} scale 2  rotate <90,0,0> translate <-2,s + B + 0.8, 0>}


      pigment {Gray20}
      rotate <0, 90, 0>
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


/*******************************************************************************
//Macros for MURATA NFE61P EMI FILTERS
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/01/06
*******************************************************************************/
#macro SPC_MURATA_CSTCC_G_A_GRND(value)
union {
    difference {
        union {
            superellipsoid { <0.09, 0.09> scale <3.6,0.25,1.5> translate <0,0.25,0> }
            intersection{
                superellipsoid { <0.09, 0.09> scale <3.6,0.25,1.5> translate <0,0.25,0> }
                union {
                    box {<-4,-0.1,-1.6> <-3.1,1,+1.6>}
                    box {<-1.9,-0.1,-1.6> <-0.7,1,+1.6>}
                    box {<+0.7,-0.1,-1.6> <+1.9,1,+1.6>}
                    box {<+4,-0.1,-1.6> <+3.1,1,+1.6>}
                }
                pigment {color red 0.85 green 0.85 blue 0.71}
            }     
        }
        union {
            cylinder {<-2.5,0,-1.5> <-2.5,0.6,-1.5> 0.23 }
            cylinder {<+2.5,0,-1.5> <+2.5,0.6,-1.5> 0.23 }
            cylinder {<0,0,-1.5> <0,0.6,-1.5> 0.23 }
            cylinder {<-2.5,0,+1.5> <-2.5,0.6,+1.5> 0.23 }
            cylinder {<+2.5,0,+1.5> <+2.5,0.6,+1.5> 0.23 }
            cylinder {<0,0,+1.5> <0,0.6,+1.5> 0.23 }
        }
        texture{col_silver}
    }
    difference {
        superellipsoid { <0.2, 0.2> scale <3.3,1.55,1.05> translate <0,0,0>  }
        union {
            box {<-3.4,0,-1.6> <+3.4,-2,+1.6> texture{col_silver}}
            text { ttf global_fontfile_arial value 0.08, 0 scale 1 rotate <90,0,0> translate <-2,1.6,-0.45>}     // Ref Marking
        }
        texture{col_silver}
    }
}
#end
#macro SPC_MURATA_CSTCC_G_A(value)
SPC_MURATA_CSTCC_G_A_GRND(value)
#end


/*******************************************************************************
//Macros for MURATA NFE61P EMI FILTERS
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/01/06
*******************************************************************************/
#macro SPC_MURATA_NFE61P_GRND()
union {
    difference {
        superellipsoid { <0.09, 0.09> scale <3.4,0.8,0.8> translate <0,0.8,0> texture{col_silver} }
        cylinder {<-2.7,0.8,0> <+2.7,0.8,0> 1.2 texture{col_silver}}
    }
    superellipsoid { <0.09, 0.09> scale <1.3,0.8,0.8> translate <0,0.8,0> texture{col_silver} }
    cylinder {<-2.7,0.8,0> <+2.7,0.8,0> 0.7 pigment {Gray30}}
}
#end
#macro SPC_MURATA_NFE61P()
SPC_MURATA_NFE61P_GRND()
#end













/*******************************************************************************
// SMD-Drossel von CTC
// http://www.ctccoils.com
// L - Gesamt Laenge der Drossel
// B - Gesamt Breite der Drossel
// H - Gesamt Hoehe der Drossel
// value - Aufschrift
// everyone1@freenet.de
*******************************************************************************/
#macro SPC_SMD_INDUCTOR_SMSL_GRND(L,B,H,value)

#local PX = 2.54;       // Pad-Groesse

#local U = 0.1;         // Überlappung Differenzebildung
#local R = B*0.9/2;     // Radius Spulenkoerper
#local R1 = 0.2;        // Radius Draht
#local H1 = 0.8;        // Hoehe Grundplatte
#local H2 = 0.6;        // Dicke der Deckplatten der Spule
#local L1 = L*0.95/2;   // Halbe Laenge der Grundplatte
#local X1 = L1*0.2;     // Halbe Laenge der geraden Seite
#local Z1 = B*0.33/2;   // Halbe Breite der geraden Seite

#declare Draht =  torus { R-R1-0.3, R1 
                        texture{Copper_Metal
                                pigment {color rgb<0.7,0.2,0>}
                                finish {metallic brilliance 4  ambient (0.1 * global_ambient_mul)}
                        }            
                  }
#local H3 = H-0.1-H1-2*H2;
#local A = int(H3 / (2*R1)) + 1;    // Anzahl der Windungen
#local C = H3 / A;
#local Y2 = H1+H2+R1;

union {
        box { <-L/2+H1/4, 0, -B*0.30/2> <-L/2+PX, H1+0.2, B*0.30/2> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
        cylinder { < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
                scale< 0.5, 1, 1>
                translate <-L/2+H1/4, H1/2+0.1, 0>
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }
        box { < L/2-H1/4, 0, -B*0.30/2> < L/2-PX, H1+0.2, B*0.30/2> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
        cylinder { < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
                scale< 0.5, 1, 1>
                translate < L/2-H1/4, H1/2+0.1, 0>
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }


        prism{ 0.1, H1, 9
                <-X1,-B/2>, < X1,-B/2>, < L1,-Z1>, < L1, Z1>, < X1, B/2>, 
                <-X1, B/2>, <-L1, Z1>, <-L1,-Z1>, <-X1,-B/2>
                texture{pigment { Gray20 }}
        }
        
        cylinder { < 0, 0.1+H1, 0> < 0, 0.1+H1+H2, 0> R-H2/2 
                texture{pigment { Gray10 }}
        }
        torus { R-H2/2, H2/2
                texture{pigment { Gray10 }}
                translate < 0, 0.1+H1+H2/2, 0>
        }

        cylinder { < 0, H, 0> < 0, H-H2, 0> R-H2/2 
                texture{pigment { Gray10 }}
        }
        torus { R-H2/2, H2/2
                texture{pigment { Gray10 }}
                translate < 0, H-H2/2, 0>
        }
        
        #while ( A >= 0 )
                object{ Draht translate < 0, Y2, 0> }
                #declare Y2 = Y2 + C;
                #declare A = A -1;
        #end
        
        text{ ttf global_fontfile_arial value 0.1,0 rotate <90,0,0> scale<1.8,1,1.8> translate <-R+1, H+0.01, 0.0> pigment {Gray60}}

}
#end

#macro SPC_SMD_INDUCTOR_SMSL_1305(value)
SPC_SMD_INDUCTOR_SMSL_GRND(12.95, 9.4, 5.21, value)
#end


/*******************************************************************************
//Macros for horizontal laser tranceiver/receiver TORX173/TOTX173 Toshiba
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  05/06/07
*******************************************************************************/
#macro SPC_TOXX173_GRND(value)
union {
    union {
        difference {
            box {<-6.5,0.5,+5.5> <+6.5,8.5,-10>}
            box {<-6.1,-0.1,+3.3> <-6.6,8.6,+4.5>}
            box {<+6.1,-0.1,+3.3> <+6.6,8.6,+4.5>}
            box {<-6.6,+8.1,+3.3> <+6.6,8.6,+4.5>}
            cylinder {<-5.2,1,-4.2> <-5.1,8.6,-4.2>,0.3}
            cylinder {<+5.2,1,-4.2> <+5.1,8.6,-4.2>,0.3}
            box {<-1.35,-0.1,-6.5> <+1.35,8.6,-7.7>}
            box {<-5.1,+1.6,-5.4> <-6.6,7.5,-10.1>}
            box {<+5.1,+1.6,-5.4> <+6.6,7.5,-10.1>}
            box {<-4.3,-0.1,-5.4> <-5.101,6.5,-8.4>}
            box {<+4.3,-0.1,-5.4> <+5.101,6.5,-8.4>}
            box {<+3.1,+2.7,-4.2> <-3.1,+7.5,-10.1>}
            box {<+1.7,+1.3,-4.2> <-1.7,+7.5,-10.1>}
            box {<-1,-1,-4.2> <+1,+1,-10.1> rotate 45*z translate <+1.7,2.7,0>} 
            box {<-1,-1,-4.2> <+1,+1,-10.1> rotate 45*z translate <-1.7,2.7,0>} 
            cylinder {<-3,+4.5,-4.2> <-3,+4.5,-10.1>,1}
            cylinder {<+3,+4.5,-4.2> <+3,+4.5,-10.1>,1}
        }
        difference {
            box {<-2,6.5,-8.1> <+2,2.5,0>}
            box {<-1,-0.5,-4.2> <+1,+0.5,-10.1> rotate 45*z translate <+2,2.7,0>}
            box {<-1,-0.5,-4.2> <+1,+0.5,-10.1> rotate -45*z translate <-2,2.7,0>}
            cylinder {<0,+4.3,-4.2> <0,+4.3,-10.1>,1}
            pigment {Gray20}
        }
        box {<-3.81-0.6,0,+5.5,> <-3.81+0.6,0.5,-10>}
        box {<+3.81-0.6,0,+5.5,> <+3.81+0.6,0.5,-10>}
        pigment {Gray30}
    }
    #if (value = 0)
    text{ ttf global_fontfile_arial_bold "TORX173" 0.5,0 pigment {Gray60} scale<2.5,4,0.1> rotate <90,180,0> translate <+5,8.51,-0>}
    #else
    text{ ttf global_fontfile_arial_bold "TOTX173" 0.5,0 pigment {Gray60} scale<2.5,4,0.1> rotate <90,180,0> translate <+5,8.51,-0>}
    #end
    text{ ttf global_fontfile_arial_bold "JAPAN" 0.5,0 pigment {Gray60} scale<1,2,0.1> rotate <90,180,0> translate <+1.5,8.51,2>}
    union {
        cylinder {<-5.2,-3.5,-4.2> <-5.1,1,-4.2>,0.3}
        cylinder {<+5.2,-3.5,-4.2> <+5.1,1,-4.2>,0.3}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate +1.27*x}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate +3.81*x}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate -1.27*x}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate -3.81*x}
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
