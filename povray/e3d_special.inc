/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/
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
#include "INDUCTOR/CTC-coils.inc"         // 04.04.2023, move inductors to subfolder
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
