
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
     object { SWITCH_ALPS_SKHH_V_GRND(4,1.3, color rgb <10/255, 51/255, 61/255>) rotate<0,0,0> translate<0,0.0,29.8>}
     object { SWITCH_ALPS_SKHH_V_GRND(4,1.3, color rgb <10/255, 51/255, 61/255>) rotate<0,0,0> translate<0,0.0,21.7>}
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
         object { IC_SMD_MLF_64_050MM("MEGA16U2") scale 0.6 rotate<0,-90,0> translate<0,0,-21>}
         union{   
            text {ttf global_fontfile_arial "IC3" 0.2, 0 scale 1.8 rotate<90,-90,0> translate<-3,0.05,-19>}
            texture{col_slk}
            }
         }
      union {
         #macro CMODS6_FPGA_XILINX(value)
            IC_SMD_MLF_GRND(
              8.0, //LK    = Laenge des Kunststoff (x-Achse)
              8.0, //BK    = Breite des Kunststoff (z-Achse)
              0.8, //H     = Hoehe des Kunststoff (Y-Achse)
                0, //pin_l = Anzahl Pins links
                0, //pin_r = Anzahl Pins rechts
                0, //pin_o = Anzahl Pins "oben"
                0, //pin_u = Anzahl Pins "unten"
              0.5, //pitch = Abstand der einzelnen Pins
              0.1, //pin_br= Breite eines Pins
              0.1, //pin_h = HÃ¶he eines Pins
              0.1, //pin_t = Tiefe eines Pins
              0.2, //HKoP  = Hoehe des Kunststoffs ueber der Platine (Y-Achse)
                0, //KORW  = Korrekturwinkel
                1, //kp1ab = Wenn 0, wird Abschraegung an Pin1 erzeugt
                0, //cool_x= KÃŒhlflÃ€che unter dem Chip (X-Achse)
                0, //cool_z= KÃŒhlflÃ€che unter dem Chip (Z-Achse)
                )
         #end
         object { CMODS6_FPGA_XILINX("XC6SLX4") rotate<0,-90,0> translate<0,0,2.5>}
         union{   
            text {ttf global_fontfile_arial "IC5" 0.2, 0 scale 1.8 rotate<90,-90,0> translate<4,0.05,-5>}
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
           texture{e3d_tex_silver}
           }
        box{ <-3/2,1.2,-2> <+3/2,2,2.5,> pigment { Gray20 } finish { Shiny  ambient (0.1 * global_ambient_mul)} }
        texture{e3d_tex_silver}
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
