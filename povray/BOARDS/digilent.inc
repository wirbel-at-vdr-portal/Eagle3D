/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

#macro _loc_PINHDR(nRows,nCols)
#include "shapes3.inc"
union {
  #if (nRows = 1)
      #local YOFFS = 0;
  #end
  #if (nRows = 2)
      #local YOFFS = -2.54/2;
  #end
  #if (nRows = 3)
      #local YOFFS = /*-2.54/2*/ - 2.54;
  #end

  #for (Row, 1, nRows)
     #for (Pin, 0, nCols-1)
        union {
          difference {
             box      { <-2.54/2,1,0       > <2.54/2,8.50,2.54>}
             box      { <-1/2,1,2.54/2-1/2> <1/2,9.50,2.54/2+1/2>}
             object{ Pyramid_N(4,2,0,2) rotate<180,0,0> translate <0,9.5,2.54/2> }
             pigment{Gray30}
             }
           union {
              box {<-0.40/2,-3.1,-0.65/2> <+0.40/2,1.5,+0.65/2> }
              texture{col_gold}
              translate <0,0,+2.54/2>
              }
           translate <YOFFS,0,2.54*Pin - (nCols/2)*2.54>
           }
     #end // end for
     #local YOFFS = YOFFS + 2.54;
  #end // end for
  box { <+2.54*nRows/2,0,-2.54*nCols/2> <+2.54*nRows/2-0.5,1,2.54*nCols/2> pigment{Gray30} translate<0,0,0>}
  box { <-2.54*nRows/2,0,-2.54*nCols/2> <-2.54*nRows/2+0.5,1,2.54*nCols/2> pigment{Gray30} translate<0,0,0>}
  }
#end

/********************************************************************************************************************************************
 * Digilent Cmod A7 FPGA Board
 *******************************************************************************************************************************************/
#macro FPGABOARD_CMOD_A7()

union {
  // pinheader und buchsenleisten
  object { CON_BL_1X12()  rotate<0,90,0> translate<+7.62,0,+6*2.54>}
  object { CON_BL_1X12()  rotate<0,90,0> translate<+7.62,0,-6*2.54>}
  object { CON_BL_1X12()  rotate<0,90,0> translate<-7.62,0,+6*2.54>}
  object { CON_BL_1X12()  rotate<0,90,0> translate<-7.62,0,-6*2.54>}
  object { CON_PH_1X24() rotate<0,90,180> translate<+7.62,10.0,0>}
  object { CON_PH_1X24() rotate<0,90,180> translate<-7.62,10.0,0>}

  union { // platine
    box{ <-9,-1.6,-31.75> <9,0,35.56> texture{ col_brd } }

   // durchkontaktierungen fuer pinheader und buchsenleisten
   #for (PinNumber, 1, 48)
      #local global_pcb_real_hole = 2;
      #local global_solder = on;
      #local Shape = 101;
      #local XPos  = 12.5*2.54;
      #local YPos  = -7.62;

      #if(PinNumber=1)
         #local Shape = 100;
      #end

      #if(PinNumber>24)
         #local YPos = 7.62;
         #local XPos = 36.5*2.54;
      #end

      object{TOOLS_PCB_VIA(1.308,0.8,1,16,Shape,0) rotate<0,-90,0> translate<YPos,0, XPos - PinNumber*2.54> texture{col_thl}}
   #end // end for
   union {
      text {ttf global_fontfile_arial "1"   0.18, 0 scale 1.8 rotate<90,180,0> translate<-7.5,0.05,32>}
      text {ttf global_fontfile_arial "48"  0.18, 0 scale 1.8 rotate<90,180,0> translate<+8.5,0.05,32>}
      text {ttf global_fontfile_arial "24"  0.18, 0 scale 1.8 rotate<90,180,0> translate<-6.5,0.05,-27.45>}
      text {ttf global_fontfile_arial "25"  0.18, 0 scale 1.8 rotate<90,180,0> translate<+8.5,0.05,-27.45>}
      text {ttf global_fontfile_arial "VU"  0.18, 0 scale 1.8 rotate<90,180,0> translate<-6.5,0.05,-30>}
      text {ttf global_fontfile_arial "GND" 0.18, 0 scale 1.8 rotate<90,180,0> translate<+8.5,0.05,-30>}
      texture{col_slk}
      }
   // two switch buttons.
   object { SWITCH_ALPS_SKHH_V_BASE(4,1.3, color rgb <10/255, 51/255, 61/255>) scale 0.75 rotate<0,0,0> translate<0,0.0,27.8>}
   object { SWITCH_ALPS_SKHH_V_BASE(4,1.3, color rgb <10/255, 51/255, 61/255>) scale 0.75 rotate<0,0,0> translate<0,0.0,21.7>}
   union {
      text {ttf global_fontfile_arial "BTN0" 0.18, 0 scale 1.5 rotate<90,180,0> translate<2,0.05,25.5>}
      text {ttf global_fontfile_arial "BTN1" 0.18, 0 scale 1.8 rotate<90,180,0> translate<2,0.05,19.5>}
      texture{col_slk}
      }

  // pinheader bestueckt.
  object{ _loc_PINHDR(2,6) rotate<0,-90,0> translate<0,0,34.00> } 

  // LEDs
  union {
    #local LED_Color = color rgb <237/255, 232/255, 213/255>;
    object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<-0.5,0, 16> }
    object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0, 0,0> translate<-0.5,0, 12> }
    object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0, 0,0> translate<+4.0,0 ,16> }
    object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0, 0,0> translate<+4.0,0, 12> }
    object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<-5.5,0,-30> }
    object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<+5.5,0,-30> }
    union{
       text {ttf global_fontfile_arial "DONE"  0.2, 0 scale 1.5 rotate<90,180,0> translate<+1.5,0.05,14>}
       text {ttf global_fontfile_arial "LD2"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+6.5,0.05,11>}
       text {ttf global_fontfile_arial "LD1"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+6.5,0.05,15>}
       text {ttf global_fontfile_arial "LD0"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+1.5,0.05,15>}
       text {ttf global_fontfile_arial "POWER" 0.2, 0 scale 1.5 rotate<90,-90,0> translate<-5.0,0.05,-28>}
       text {ttf global_fontfile_arial "STS"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+6.0,0.05,-28>}
       texture{col_slk}
       }
    }  // leds

  #macro _loc_QFN(N,e,A,A1,A3,E,E2,D,D2,b,L,K,value)
  union {
    union {
       box { <-D/2,A1,-E/2> <+D/2,A,+E/2> }
       texture { col_ic_body_1 }
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
    text { ttf besch_font value 0.2,0 rotate<90,0,0> scale 1*(E/9) translate<-E/4,A+0.02,-D/4> texture{col_bright_marking} }
  } // end: _loc_QFN
  #end

  object {_loc_QFN(
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
     "FT2232HQ")// value Text to be printed
     rotate<0,-90,0> translate<0,0,-20>
     }

  #macro _loc_BGA(N,e,A,A1,E,D,value)
  union {
    union {
       box { <-D/2,A1,-E/2> <+D/2,A,+E/2> }
       texture { col_ic_body_1 }
       }
    text { ttf besch_font value 0.2,0 rotate<90,0,0> scale 1*(E/9) translate<-E/4,A+0.02,-D/4> texture{col_bright_marking} }
    } // end: _loc_BGA
  #end

  union {
     object {_loc_BGA(
        236,  // N  - Number of Pins
        0.50, // e  - Pitch
        1.28, // A  - Overall Height
        0.22, // A1 - Standoff
       10.00, // E  - Overall Width
       10.00, // D  - Overall Length
        "cpg236-1")// value Text to be printed
       }
     text { ttf besch_font "ARTIX-7" 0.2,0 rotate<90,0,0> scale 1.5 translate<-3,1.30,+2> texture{col_bright_marking} }
     text { ttf besch_font "35T"     0.2,0 rotate<90,0,0> scale 1.5 translate<-1,1.30,+0> texture{col_bright_marking} }
     rotate<0,-90,0> translate<0,0,-2>
     }

  union {
     object {_loc_BGA(
        0,    // N  - Number of Pins
        0.50, // e  - Pitch
        1.28, // A  - Overall Height
        0.22, // A1 - Standoff
        5.00, // E  - Overall Width
        8.00, // D  - Overall Length
        "")   // value Text to be printed
       }
     rotate<0,-0,0> translate<+1,0,7.2>
     } 

  #macro _loc_TINYCHIP1(value,logo)
     IC_SMD_BASE(3,2.5,0.85, // Kunststoff LxBxH
                       3.9,      // Laenge der Seite ohne Pins ueber alles
                       4,4,      // Pins oben, unten
                       0.5,0.5,  // pitch oben, unten
                       0.25,0.25,// Pin breiten
                       0.15,     // pinst?rke
                       0.1,      //di_pcb  = Abstand des Kunststoff zur Platine
                       0,        //kor_w   = Korrekturwinkel
                       0,        //pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
                       0,        //pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45° statt 10° verwendet (SO)
                       0.5,      //pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
                       0.65,     //besch_s = Scalefaktor der Beschriftung
                       0,        //besch_w = Wenn != 0 wird Beschriftung gedreht
                       logo)
  #end

  #macro _loc_TINYCHIP2(value,logo)
     IC_SMD_BASE(3,2,0.85, // Kunststoff LxBxH
                       3.4,      // Laenge der Seite ohne Pins ueber alles
                       5,5,      // Pins oben, unten
                       0.5,0.5,  // pitch oben, unten
                       0.15,0.15,// Pin breiten
                       0.15,     // pinst?rke
                       0.1,      //di_pcb  = Abstand des Kunststoff zur Platine
                       0,        //kor_w   = Korrekturwinkel
                       0,        //pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
                       0,        //pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45° statt 10° verwendet (SO)
                       0.5,      //pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
                       0.65,     //besch_s = Scalefaktor der Beschriftung
                       0,        //besch_w = Wenn != 0 wird Beschriftung gedreht
                       logo)
  #end

  object { _loc_TINYCHIP1("","")  rotate<0,-0,0> translate<-5,0,14.5> }

  union {
     object { _loc_TINYCHIP2("","") }
     intersection {
        object { _loc_TINYCHIP2("","") }
        box { <-0.5,-1,-3> <0.5,2,3>}
        rotate <0,90,0>
        }
     scale 0.95
     rotate<0,-0,0> translate<+3.5,0,-12>
     }

  object { CAP_SMD_CHIP_1206()               translate<+2.5,0,-9 > }
  object { SPC_XTAL_OSZ_DIP14("") scale 0.15 translate<-2.5,0,-12> }

  // USB Buchse
  union {
    difference {
       object {Round_Box(<-7.5/2,0.2,2.45>,<7.5/2,3.0,-2.55>,0.55,0) }
       object {Round_Box(<-6.9/2,0.5,2.25>,<6.9/2,2.7,-2.75>,0.55,0) }
       box{ <-3,0,5> <5,5,-5> rotate<0,0,+110> translate<-3.0,0,0>  }
       box{ <-3,0,5> <5,5,-5> rotate<0,0,-110> translate<+3.0,0,0>  }
       box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<-2.5,0,0>  }
       box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<+2.5,0,0>  }
       box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<-2.0,0,3>  }
       box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<+2.0,0,3>  }
       texture{col_silver}
       }
    box{ <-3/2,1.2,-2> <+3/2,2,2.5,> pigment { Gray20 } finish { Shiny  ambient (0.1 * global_ambient_mul)} }
    texture{col_silver}
    translate<0,0,-30>
    }
 
  // andere Beschriftung.
  union {
     text {ttf global_fontfile_arial "CMOD A7"         0.2, 0 scale 2.50 rotate<90,-90,0> translate<-4.0,0.05,+19>}
     text {ttf global_fontfile_arial "Digilent  Inc."  0.2, 0 scale 1.50 rotate<90,-90,0> translate <+6.5,0.05,-5 >}
     text {ttf global_fontfile_eagle3d "#"             0.2, 0 scale 1.50 rotate<90,-90,0> translate <+6.5,0.05,-21>}
     texture{col_slk}
     }

    translate <0,10,0>
    } //union
}
// end: FPGABOARD_CMOD_A7
#end


/********************************************************************************************************************************************
 * Digilent Cmod S6 FPGA Board
 *******************************************************************************************************************************************/
#macro FPGABOARD_CMOD_S6()

union {
  // pinheader und buchsenleisten
  object { CON_BL_1X12()  rotate<0,90,0> translate<+7.62,0,+6*2.54>}
  object { CON_BL_1X12()  rotate<0,90,0> translate<+7.62,0,-6*2.54>}
  object { CON_BL_1X12()  rotate<0,90,0> translate<-7.62,0,+6*2.54>}
  object { CON_BL_1X12()  rotate<0,90,0> translate<-7.62,0,-6*2.54>}
  object { CON_PH_1X24() rotate<0,90,180> translate<+7.62,10.0,0>}
  object { CON_PH_1X24() rotate<0,90,180> translate<-7.62,10.0,0>}

  union {
     // platine
     box{ <-9,-1.6,-31.75> <9,0,35.56> texture{ col_brd } }

     // durchkontaktierungen fuer pinheader und buchsenleisten
     #for (PinNumber, 1, 48)
        #local global_pcb_real_hole = 2;
        #local global_solder = on;
        #local Shape = 101;
        #local XPos  = 12.5*2.54;
        #local YPos  = -7.62;

        #if(PinNumber=1)
           #local Shape = 100;
        #end

        #if(PinNumber>24)
           #local YPos = 7.62;
           #local XPos = 36.5*2.54;
        #end

        object{TOOLS_PCB_VIA(1.308,0.8,1,16,Shape,0) rotate<0,-90,0> translate<YPos,0, XPos - PinNumber*2.54> texture{col_thl}}
     #end // end for
     union {
        text {ttf global_fontfile_arial "1"  0.2, 0 scale 1.8 rotate<90,180,0> translate<-7.5,0.05,32>}
        text {ttf global_fontfile_arial "48" 0.2, 0 scale 1.8 rotate<90,180,0> translate<+8.5,0.05,32>}
        text {ttf global_fontfile_arial "24" 0.2, 0 scale 1.8 rotate<90,180,0> translate<-6.5,0.05,-30>}
        text {ttf global_fontfile_arial "25" 0.2, 0 scale 1.8 rotate<90,180,0> translate<+8.5,0.05,-30>}
        texture{col_slk}
        }


     // two switch buttons.
     object { SWITCH_ALPS_SKHH_V_BASE(4,1.3, color rgb <10/255, 51/255, 61/255>) rotate<0,0,0> translate<0,0.0,29.8>}
     object { SWITCH_ALPS_SKHH_V_BASE(4,1.3, color rgb <10/255, 51/255, 61/255>) rotate<0,0,0> translate<0,0.0,21.7>}
     union {
        text {ttf global_fontfile_arial "BTN0" 0.2, 0 scale 1.8 rotate<90,-90,0> translate<6,0.05,19>}
        text {ttf global_fontfile_arial "BTN1" 0.2, 0 scale 1.8 rotate<90,-90,0> translate<6,0.05,27>}
        texture{col_slk}
        }

    // pinheader unbestueckt.
    union {
       #local global_pcb_real_hole = 0;
       #local DeltaX = 2.5;
       object{TOOLS_PCB_VIA(1.308000,0.800000,1,16,  0,0) rotate<0,-90,0> translate<-DeltaX/2-2*DeltaX,0,34.00>}
       object{TOOLS_PCB_VIA(1.308000,0.800000,1,16,  1,0) rotate<0,-90,0> translate<-DeltaX/2-1*DeltaX,0,34.50>}
       object{TOOLS_PCB_VIA(1.308000,0.800000,1,16,  1,0) rotate<0,-90,0> translate<-DeltaX/2-0*DeltaX,0,34.00>}
       object{TOOLS_PCB_VIA(1.308000,0.800000,1,16,  1,0) rotate<0,-90,0> translate<+DeltaX/2+0*DeltaX,0,34.50>}
       object{TOOLS_PCB_VIA(1.308000,0.800000,1,16,  1,0) rotate<0,-90,0> translate<+DeltaX/2+1*DeltaX,0,34.00>}
       object{TOOLS_PCB_VIA(1.308000,0.800000,1,16,  1,0) rotate<0,-90,0> translate<+DeltaX/2+2*DeltaX,0,34.50>}
       union{
          box{<-7.5,0.036,35.5-0.0762><7.5,0,35.5+0.076200> rotate<0,0,0> translate<0,00> }
          box{<-7.5,0.036,33.0-0.0762><7.5,0,33.0+0.076200> rotate<0,0,0> translate<0,00> }
          box{<-7.5-0.0762,0.036,35.5+0.076200><-7.5+0.0762,0,33.0-0.076200> rotate<0,0,0> translate<0,00> }
          box{< 7.5-0.0762,0.036,35.5+0.076200>< 7.5+0.0762,0,33.0-0.076200> rotate<0,0,0> translate<0,00> }
          text {ttf global_fontfile_arial "1"  0.2, 0 scale 1.5 rotate<90,180,0> translate<-8.0,0.05,35>}
          text {ttf global_fontfile_arial "J4" 0.2, 0 scale 1.8 rotate<90,-90,0> translate<-4.5,0.05,31>}
          texture{col_slk}
          }
       texture{ Gold_Metal finish { phong 0.8  } scale 0.5 }
       }

    // LEDs
    union {
       #local LED_Color = color rgb <237/255, 232/255, 213/255>;
       object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<-4.0,0, 15> }
       object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<-1.5,0, 15> }
       object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<+1.5,0 ,15> }
       object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<+4.0,0, 15> }
       object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<-5.5,0,-30> }
       object {DIODE_SMD_LED_CHIP_0805(LED_Color,0.800000,0.000000,) rotate<0,90,0> translate<+5.5,0,-30> }
       union{
          text {ttf global_fontfile_arial "LD3"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<-2.0,0.05,14>}
          text {ttf global_fontfile_arial "LD2"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+0.5,0.05,14>}
          text {ttf global_fontfile_arial "LD1"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+3.0,0.05,14>}
          text {ttf global_fontfile_arial "LD0"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+5.5,0.05,14>}
          text {ttf global_fontfile_arial "POWER" 0.2, 0 scale 1.5 rotate<90,-90,0> translate<-5.0,0.05,-28>}
          text {ttf global_fontfile_arial "STS"   0.2, 0 scale 1.5 rotate<90,-90,0> translate<+6.0,0.05,-28>}
          texture{col_slk}
          }
       }

      union {
         object { IC_SMD_QFN64_050MM("MEGA16U2") scale 0.6 rotate<0,180,0> translate<0,0,-21>}
         union{
            text {ttf global_fontfile_arial "IC3" 0.2, 0 scale 1.8 rotate<90,-90,0> translate<-3,0.05,-19>}
            texture{col_slk}
            }
         }
      union {
         // we do not have an BGA macro yet, emulate CPG196 as a QFN.
         #local A  = 1.00; // A  - Overall Height
         #local A1 = 0.20; // A1 - Standoff
         #local A3 = 0.10; // A3 - Contact Thickness
         #local b  = 0.10; // b  - Contact Width
         #local D  = 8.00; // D  - Overall Length
         #local D2 = 0.00; // D2 - Exposed Pad Length
         #local e  = 0.00; // e  - Pitch
         #local E  = 8.00; // E  - Overall Width
         #local E2 = 0.00; // E2 - Exposed Pad Width
         #local L  = 0.00; // L  - Contact Length
         object { QFN_base(0,0,e,A,A1,A3,E,E2,D,D2,b,L,"","XC6SLX4")
            rotate<0,180,0> translate <0,0,2.5>
            }
         text { ttf global_fontfile_arial "IC5" 0.2, 0 scale 1.8
            rotate<90,-90,0> translate<4,0.05,-5>
            texture{col_slk}
            }
         }

      // USB Buchse
      union {
        difference {
           object {Round_Box(<-7.5/2,0.2,2.45>,<7.5/2,3.0,-2.55>,0.55,0) }
           object {Round_Box(<-6.9/2,0.5,2.25>,<6.9/2,2.7,-2.75>,0.55,0) }
           box{ <-3,0,5> <5,5,-5> rotate<0,0,+110> translate<-3.0,0,0>  }
           box{ <-3,0,5> <5,5,-5> rotate<0,0,-110> translate<+3.0,0,0>  }
           box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<-2.5,0,0>  }
           box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<+2.5,0,0>  }
           box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<-2.0,0,3>  }
           box{ <-0.25,2,-2.0> <0.25,5,0.0> rotate<0,0,0> translate<+2.0,0,3>  }
           texture{col_silver}
           }
        box{ <-3/2,1.2,-2> <+3/2,2,2.5,> pigment { Gray20 } finish { Shiny  ambient (0.1 * global_ambient_mul)} }
        texture{col_silver}
        translate<0,0,-30>
        }

      // andere Beschriftung.
      union {
         text {ttf global_fontfile_arial "Cmod S6"         0.2, 0 scale 2.75 rotate<90,-90,0> translate<-4.5,0.05,-14>}
         text {ttf global_fontfile_arial "Copyright  2013" 0.2, 0 scale 2.00 rotate<90,-90,0> translate<-5.0,0.05,  4>}
         text {ttf global_fontfile_arial "Digilent  Inc."  0.2, 0 scale 2.00 rotate<90,-90,0> translate<+6.5,0.05,-13>}
         text {ttf global_fontfile_arial "PB200-282"       0.2, 0 scale 2.00 rotate<90,-90,0> translate<+6.5,0.05,+ 3>}
         text {ttf global_fontfile_arial "REV A"           0.2, 0 scale 2.00 rotate<90,-90,0> translate<+4.6,0.05,+ 7>}
         texture{col_slk}
         }

      translate <0,10,0>
      } //union
}
// end: FPGABOARD_CMOD_S6
#end
