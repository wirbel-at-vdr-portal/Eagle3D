/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


#ifndef(__ic_inc)
#declare __ic_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end

#include "IC/THT/DIL.inc"
#include "IC/THT/SIL.inc"
#include "IC/THT/multiwatt.inc"
#include "IC/SMT/PLCC.inc"
#include "IC/SMT/QFN.inc"



















/********************************************************************************************************************************************
//Makro fuer SMD-IC's die Pins nur auf 2-Seiten haben(SO, TSOP, TSSOP usw.)
//ueberarbeitet von Tilmann Reh <tilmann.reh(replace with at)autometer.de>
//erweitert fuer DPAK Friedrich Bleikamp <fbleikamp(replace with at)web.de>
//LK      = Laenge des Kunststoff(Seite der Pins)
//BK      = Breite des Kunststoff(Seite ohne Pins)
//HK      = Hoehe des Kunststoff
//B       = Laenge der Seite ohne Pins ueber alles
//pin_u   = Pins auf der "unteren" Seite
//pin_o   = Pins auf der "oberen" Seite
//ptch_u  = Pitch der Pins auf der "unteren" Seite
//ptch_o  = Pitch der Pins auf der "oberen" Seite
//pinb_u  = Breite der Pins auf der "unteren" Seite
//pinb_o  = Breite der Pins auf der  "oberen" Seite
//pin_s   = Staerke des Pinmaterials
//di_pcb  = Abstand des Kunststoff zur Platine
//kor_w   = Korrekturwinkel
//pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
//pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45° statt 10° verwendet (SO)
//pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
//besch_s = Scalefaktor der Beschriftung
//besch_w = Wenn != 0 wird Beschriftung gedreht
//logo  = Name of the logo
********************************************************************************************************************************************/
#macro IC_SMD_GRND(LK,BK,HK,B,pin_u,pin_o,ptch_u,ptch_o,pinb_u,pinb_o,pin_s,di_pcb,kor_w,pin0_m,pin0_45,pin0_a,besch_s,besch_w,logo)
union{
    difference{
        box{<LK/2,di_pcb,BK/2><-LK/2,di_pcb+HK,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,-1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,-BK/2>}
        #if(pin0_45!=0)
            box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<45,0,0> translate<0,(di_pcb+HK)/2+pin_s/2+pin_s*1.5,-BK/2>}
        #end
        box{<0,0,-BK/2-0.1><1,HK,BK/2+0.1>  rotate<0,0,10> translate<LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,HK,BK/2+0.1>  rotate<0,0,-10> translate<-LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><1,-HK,BK/2+0.1>  rotate<0,0,-10> translate<LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,-HK,BK/2+0.1>  rotate<0,0,10> translate<-LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        #if(pin0_m = 0)
            #local TextX = -LK/2+0.1*LK;
        #end // ohne Pin-1-Markierung
        #if(pin0_m = 1)  // SO-Farbmarkierung
            #local TextX = -LK/2+0.1*LK;
            #if((((pin_u-1)/2*ptch_u)+0.3)>LK/2)
                #local i = -(pin_u-1)/2*ptch_u+0.3;
            #else
                #local i = -(pin_u-1)/2*ptch_u;
            #end
            sphere{<i,HK+di_pcb+0.1,-BK/2+pin0_a>0.15 texture{e3d_tex_ic_marking_bright}}
        #end
        #if(pin0_m = 2)  // VSO-Kerbe
            #local TextX = -LK/2+0.15*LK;
            cylinder{<-LK/2,di_pcb+0.7*HK,0><-LK/2,di_pcb+HK+0.1,0> 1}
        #end
        #if(pin0_m = 3)  // PSO-Kerben und Fase (vereinfacht rechteckig)
            #local TextX = -LK/2+0.25*LK;
            box{<3,di_pcb-0.1,-3> <-3,HK+di_pcb+0.1,0> rotate<0,45,0> translate<1-LK/2,0,1-BK/2>}
            box{<0,di_pcb-0.1,-1.45> <-2,HK+di_pcb+0.1,1.45> translate<1.45-LK/2,0,0>}
            box{<0,di_pcb-0.1,-1.45> <2,HK+di_pcb+0.1,1.45> translate<-1.45+LK/2,0,0>}
        #end

        #if(pin0_m = 4) // fuer DPAK ohne Pin-1-Markierung
            #local TextX = -LK/2+0.15*LK;
        #end
    }
    #if(pin0_m = 3)  // PSO-Metallboden (vereinfacht, da der Rest sowieso unsichtbar bleibt)
        box{<-LK/2,0,-1.5> <LK/2,1,1.5> texture{e3d_tex_silver}}
    #end

    #if(pin0_m = 4)  // DPAK-SEATING PLANE & BLIND PIN
            box{<-pinb_u/2,(HK+di_pcb)/2+pin_s/2,-(BK/2+1)> <pinb_u/2,(HK+di_pcb)/2-pin_s/2,-(BK/2-0.1)> texture{e3d_tex_silver}}
            box{<-0.57,0,-5.25> <0.57,0.5,-4.5> translate<ptch_u/2,0,0> texture{e3d_tex_silver}}
            box{<-0.57,0,-5.25> <0.57,0.5,-4.5> translate<-ptch_u/2,0,0> texture{e3d_tex_silver}}
            difference{
                box{<-2.5,0,-0.85> <2.5,0.55,4.5>}
                box{<-0.5,-0.1,-0.5> <0.5,1.1,0.5> rotate <0,45,0> translate<-2.5,0,4.5>}
                box{<-0.5,-0.1,-0.5> <0.5,0.6,0.5> rotate <0,45,0> translate<2.5,0,4.5>}
                texture{e3d_tex_silver}
            }
    #end

    union{
        #local i=0;
        #while(i<(pin_u/2))
            #if((pin_u/2)=div(pin_u,2))
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<ptch_u*i+ptch_u/2,0,-BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<-ptch_u*i-ptch_u/2,0,-BK/2>}
            #else
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<ptch_u*i,0,-BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<-ptch_u*i,0,-BK/2>}
            #end
            #local i=i+1;
        #end

        #local i=0;
        #while(i<(pin_o/2))
            #if((pin_o/2)=div(pin_o,2))
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<ptch_o*i+ptch_o/2,0,BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<-ptch_o*i-ptch_o/2,0,BK/2>}
            #else
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<ptch_o*i,0,BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<-ptch_o*i,0,BK/2>}
            #end
        #local i=i+1;
        #end
        texture{e3d_tex_silver}
    }

    #local value_arial_size_min = 0.0;
    #local value_arial_size_max = 0.0;
    #local value_arial_size = 0.0;
    #local value_courier_size_min = 0.0;
    #local value_courier_size_max = 0.0;
    #local value_courier_size = 0.0;
    #local value_arial_bold =  text{ttf global_fontfile_arial_bold value 0.2,0 rotate<90,-90,0>}
    #local value_courier_bold = text{ttf global_fontfile_courier_bold value 0.2,0 rotate<90,-90,0>}
    Extents(value_arial_bold, value_arial_size_min, value_arial_size_max)
    Extents(value_courier_bold, value_courier_size_min, value_courier_size_max)
    #local value_arial_size = value_arial_size_max - value_arial_size_min;
    #local value_courier_size = value_courier_size_max - value_courier_size_min;
    #local value_scale_factor_arial = LK/value_arial_size.z * 0.5;
    #local value_scale_factor_courier = LK/value_courier_size.z * 0.5;

    #if(value_arial_size.x*value_scale_factor_arial > LK/6.0)
                #local value_scale_factor_arial = LK/6.0 / value_arial_size.x;
    #end
    #if(value_courier_size.x*value_scale_factor_courier > LK/6.0)
                #local value_scale_factor_courier = LK/6.0 / value_courier_size.x;
    #end

    #local value_arial_size = value_arial_size * value_scale_factor_arial;
    #local value_courier_size = value_courier_size * value_scale_factor_courier;
    //a random datecode string
    #local value_datecode_arial_size_min = 0.0;
    #local value_datecode_arial_size_max = 0.0;
    #local value_datecode_arial_size = 0.0;
    #local value_datecode_courier_size_min = 0.0;
    #local value_datecode_courier_size_max = 0.0;
    #local value_datecode_courier_size = 0.0;
    #local value_datecode_string = concat(str(rand(global_seed)*52.9, -2, 0),str(rand(global_seed)*3.9+2, -2, 0));
    #local value_datecode_arial_bold = text{ttf global_fontfile_arial_bold value_datecode_string 0.2,0 rotate<90,-90,0>}
    #local value_datecode_courier_bold = text{ttf global_fontfile_arial_bold value_datecode_string 0.2,0 rotate<90,-90,0>}
    Extents(value_datecode_arial_bold, value_datecode_arial_size_min, value_datecode_arial_size_max)
    Extents(value_datecode_courier_bold, value_courier_size_min, value_courier_size_max)
    #local value_datecode_arial_size = value_datecode_arial_size_max - value_datecode_arial_size_min;
    #local value_datecode_courier_size = value_courier_size_max - value_courier_size_min;
    #local value_datecode_scale_factor_arial = value_scale_factor_arial;
    #local value_datecode_scale_factor_courier = value_scale_factor_courier;
    #local value_datecode_arial_size = value_datecode_arial_size * value_scale_factor_arial;
    #local value_datecode_courier_size = value_datecode_courier_size * value_scale_factor_courier;

    // added logos. now with Atmel, FTDI, Microchip, Philips, and ST
    // by xocas

    #local logo_assigned = 0;

    union{
        #if(strcmp(logo,"PHILIPS")=0.0)
                #local logo_assigned = 1;
                #local label = union{
                    text{ttf global_fontfile_eagle3d "p" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                    text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                    translate<0,HK+di_pcb+0.001,0>
                }
        #end

        #if(strcmp(logo,"MICROCHIP")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "m" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
         #end
         #if(strcmp(logo,"ST")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "s" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/2.5,0,-BK/3>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,value_arial_size.x/2>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(strcmp(logo,"ATMEL")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "a" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(strcmp(logo,"FTDI")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "f" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(strcmp(logo,"TEXAS")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "t" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(logo_assigned < 0.5)
            #local label = text{ttf besch_font value 0.2,0 rotate<90,0,0> scale<besch_s,1,besch_s> translate<TextX,HK+di_pcb+0.01,-besch_s/2> }
        #end

        #if(besch_w=0)
            object{label}
        #else
            object{label rotate<0,270,0>}
        #end
        texture{e3d_tex_ic_marking_bright}
    }
    rotate<0,kor_w,0>
    texture{e3d_tex_ic_body_1}
}
#end

// JEDEC MO-193AA
#macro IC_SMD_TSOP6(value,logo)
IC_SMD_GRND(2.9,1.6,0.9, 2.8, 3,3, 0.95,0.95, 0.4,0.4,0.2, 0.1,0, 1,0,0.3,0.6,0,logo)
#end
#macro IC_SMD_SO8(value,logo)
IC_SMD_GRND(4.9,3.9,1.35,6,4,4,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/5,0,logo)
#end
#macro IC_SMD_SO14(value,logo)
IC_SMD_GRND(8.65,3.9,1.35,6,7,7,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/4,0,logo)
#end
#macro IC_SMD_SO16(value,logo)
IC_SMD_GRND(9.9,3.9,1.35,6,8,8,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/4,0,logo)
#end
#macro IC_SMD_SO16W(value,logo)
IC_SMD_GRND(10.3,7.5,2.35,10.3,8,8,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_UMAX10(value,logo)
IC_SMD_GRND(3,3,0.8,4.9,5,5,0.5,0.5,0.22,0.22,0.13,0.1,0,1,0,0.4,0.7,0,logo)
#end
#macro IC_SMD_UMAX8(value,logo)
IC_SMD_GRND(3,3,0.8,4.9,4,4,0.65,0.65,0.3,0.3,0.13,0.1,0,1,0,0.4,0.7,0,logo)
#end
//Rudi Hofer <rudi.hofer@t-online.de>
#macro IC_SMD_SO18W(value,logo)
IC_SMD_GRND(11.6,7.5,2.35,10.3,9,9,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO20W(value,logo)
IC_SMD_GRND(12.8,7.5,2.35,10.3,10,10,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO24W(value,logo)
IC_SMD_GRND(15.4,7.5,2.35,10.3,12,12,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO28W(value,logo)
IC_SMD_GRND(17.9,7.5,2.35,10.3,14,14,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO32_400(value,logo)
IC_SMD_GRND(20.5,7.5,2.35,10.3,16,16,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO32_525(value,logo)
IC_SMD_GRND(20.5,11.43,2.74,14.12,16,16,1.27,1.27,0.4,0.4,0.2,0.05,0,1,1,7.5/5,7.5/5,0,logo)
#end
#macro IC_SMD_TSSOP8(value,logo)
IC_SMD_GRND(2.9,4.4,1,6.4,4,4,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.6,1,logo)
#end
#macro IC_SMD_TSSOP14(value,logo)
IC_SMD_GRND(5,4.4,1.1,6.375,7,7,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.8,0,logo)
#end
#macro IC_SMD_TSSOP16(value,logo)
IC_SMD_GRND(5.2,4.4,1.1,6.375,8,8,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.8,0,logo)
#end
#macro IC_SMD_TSSOP20(value,logo)
IC_SMD_GRND(6.5,4.4,1.1,6.375,10,10,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.0,0,logo)
#end
#macro IC_SMD_TSSOP24(value,logo)
IC_SMD_GRND(7.8,4.4,1.1,6.375,12,12,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP28(value,logo)
IC_SMD_GRND(9.7,4.4,1.1,6.375,14,14,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP38(value,logo)
IC_SMD_GRND(9.7,4.4,1.1,6.4,19,19,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP48(value,logo)
IC_SMD_GRND(12.5,6.1,0.95,8.1,24,24,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP56(value,logo)
IC_SMD_GRND(14,6.1,0.95,8.1,28,28,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP64(value,logo)
IC_SMD_GRND(17,6.1,0.95,8.1,32,32,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_QSOP16(value,logo)
IC_SMD_GRND(4.9,3.9,1.45,6,8,8,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,0.7,0,logo)
#end
#macro IC_SMD_QSOP20(value,logo)
IC_SMD_GRND(8.65,3.9,1.45,6,10,10,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,1.1,0,logo)
#end
#macro IC_SMD_QSOP24(value,logo)
IC_SMD_GRND(8.65,3.9,1.45,6,12,12,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,1.1,0,logo)
#end
#macro IC_SMD_QSOP28(value,logo)
IC_SMD_GRND(9.9,3.9,1.45,6,14,14,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,1.1,0,logo)
#end
#macro IC_SMD_SSOP14(value,logo)
IC_SMD_GRND(6.2,5.3,1.7,7.7,7,7,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.85,0,logo)
#end
#macro IC_SMD_SSOP16(value,logo)
IC_SMD_GRND(6.2,5.3,1.7,7.7,8,8,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.85,0,logo)
#end
#macro IC_SMD_SSOP20(value,logo)
IC_SMD_GRND(7.2,5.3,1.7,7.7,10,10,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP24(value,logo)
IC_SMD_GRND(8.2,5.3,1.7,7.7,12,12,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP28(value,logo)
IC_SMD_GRND(10.2,5.3,1.7,7.7,14,14,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP30(value,logo)
IC_SMD_GRND(10.2,6.1,1.2,8.1,15,15,0.65,0.65,0.24,0.24,0.15,0.1,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP48(value,logo)
IC_SMD_GRND(15.8,7.5,2.25,10.2,24,24,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
//Joseph Zeglinski
#macro IC_SMD_SSOP56DL(value,logo)
IC_SMD_GRND(18.4,7.5,2.25,10.2,28,28,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_SSOP56(value,logo)
IC_SMD_GRND(23.7,13.3,2.25,10.2,28,28,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSOPII28(value,logo)
IC_SMD_GRND(18.4,10.1,1,11.7,14,14,1.27,1.27,0.4,0.4,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII32(value,logo)
IC_SMD_GRND(20.95,10.1,1,11.7,16,16,1.27,1.27,0.4,0.4,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII44(value,logo)
IC_SMD_GRND(18.3,10.1,1,11.7,22,22,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII50(value,logo)
IC_SMD_GRND(20.95,10.1,1,11.7,25,25,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII54(value,logo)
IC_SMD_GRND(22.22,10.1,1,11.7,27,27,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII86(value,logo)
IC_SMD_GRND(22.22,10.1,1,11.7,43,43,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOP28_13MM(value,logo)
IC_SMD_GRND(8,11.8,1,13.4,14,14,0.55,0.55,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP32_13MM(value,logo)
IC_SMD_GRND(8,11.8,1,13.4,16,16,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP32(value,logo)
IC_SMD_GRND(8,18.4,1.1,20,16,16,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP48(value,logo)
IC_SMD_GRND(12,18.4,1.1,20,24,24,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP56(value,logo)
IC_SMD_GRND(14,18.4,1.1,20,28,28,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
//Tilmann Reh <tilmann.reh@autometer.de>
#macro IC_SMD_VSO40(value,logo)
IC_SMD_GRND(15.4,7.55,2.35,12.05,20,20,0.762,0.762,0.36,0.36,0.18,0.2,0,2,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_VSO56(value,logo)
IC_SMD_GRND(21.7,11.05,2.9,15.5,28,28,0.75,0.75,0.36,0.36,0.18,0.2,0,2,0,11/6,11/5,0,logo)
#end
#macro IC_SMD_PSO20(value,logo)
IC_SMD_GRND(15.9,11,3.3,14.2,10,10,1.27,1.27,0.47,0.47,0.28,0.2,0,3,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_PSO36(value,logo)
IC_SMD_GRND(15.9,11,3.3,14.2,18,18,0.65,0.65,0.3,0.3,0.28,0.2,0,3,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_MSOP10(value,logo)
IC_SMD_GRND(3,3,0.85,4.9,5,5,0.5,0.5,0.25,0.25,0.15,0.1,0,1,0,0.5,0.65,0,logo)
#end
#macro IC_SMD_SOT23(value,logo)
IC_SMD_GRND(2.9,1.3,1,2.8,2,1,1.9,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_SMD_SOT23_5(value,logo)
IC_SMD_GRND(2.9,1.6,1,2.8,3,2,0.95,1.90,0.35,0.35,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_SMD_SOT23_6(value,logo)
IC_SMD_GRND(2.9,1.6,1,2.8,3,3,0.95,0.95,0.35,0.35,0.13,0.1,0,1,0,0.3,0.7,0,logo)
#end
#macro IC_SMD_SOT223(value,logo)
IC_SMD_GRND(6.5,3.5,1.6,7,3,1,2.3,2.3,0.75,3,0.2,0.2,0,0,0,0,1.0,0,logo)
#end
#macro IC_SMD_SOT363(value,logo)
IC_SMD_GRND(2.0,1.25,1.0,2.1,3,3,0.65,0.65,0.25,0.25,0.15,0.1,0,1,0,0,0.5,0,logo)
#end
//SMD-Transistoren aus SIC_GRND abgeleitet
#macro IC_TR_SOT23(value,logo)
IC_SMD_GRND(2.9,1.3,1,2.8,2,1,1.9,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_TR_TO252(value,logo)
IC_SMD_GRND(6.1,6.5,2.2,10,2,1,4.5,1.9,0.9,5.3,0.5,0.1,0,0,0,1.5,1.0,0,logo)
#end
#macro IC_TR_TO263(value,logo)
IC_SMD_GRND(10.2,8.7,4.2,15.2,2,1,5.1,1.9,1.4,10.2,0.5,0.1,0,0,0,1.5,1.0,0,logo)
#end
// Friedrich Bleikamp
#macro IC_SMD_DPAK_369C(value,logo)
IC_SMD_GRND(6.1,6.5,2.2,11,2,0,4.5,0,0.8,0,0.5,0.1,0,4,0,1.5,1.0,0,logo)
#end
#macro IC_SMD_TSOP86(value,logo)
IC_SMD_GRND(22.22,10.16,1.2,11.76,43,43,0.5,0.5,0.2,0.2,0.12,0.1,0,2,0,3.9/5,3.9/5,0,logo)
#end


/********************************************************************************************************************************************
//Macros for SMD bridge MB2S from Vishay TO
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  16/12/06
********************************************************************************************************************************************/
#macro IC_SMD_MB2S_GRND(code)
union{
    
    //Body
    difference{
        box{<-2.35,0.3,-1.95><+2.35,2.65,+1.95>}
        box{<-2.36,-0.5,0.5><+2.36,0.5,-0.5> rotate +45*x translate<0,2.65+0.1,-1.95-0.1>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate +80*x translate<0,2.65-0.5,+1.95+0.4>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate -80*x translate<0,2.65-0.5,-1.95-0.4>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate -80*x translate<0,1.325-0.5,+1.95+0.4>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate +80*x translate<0,1.325-0.5,-1.95-0.4>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate +80*z translate<-2.5-0.2,2.65-0.5,0>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate -80*z translate<-2.5-0.2,1.325-0.5,0>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate -80*z translate<+2.5+0.2,2.65-0.5,0>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate +80*z translate<+2.5+0.2,1.325-0.5,0>}
        texture{e3d_tex_ic_body_1}
    }
    
    // Marking
    union{
        text {ttf global_fontfile_arial_bold code 0.02, 0  scale 1.2 rotate<90,180,0> translate<+0.45,2.66,-0.2>}  
        text {ttf global_fontfile_arial_bold "2N3" 0.02, 0 scale 1.2 rotate<90,180,0> translate<+1.2,2.66,+1.3>}
        text {ttf global_fontfile_arial_bold "-" 0.02, 0   scale 1 rotate<90,0,0> translate<+1.07,2.66,-1.35>}
        text {ttf global_fontfile_arial_bold "+" 0.02, 0   scale 1 rotate<90,0,0> translate<-1.27,2.66,-1.4>}
        texture{e3d_tex_ic_marking_bright}
    }
    
    //Pins
    union
    {
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate -90*y translate<-1.27,0,1.9>}
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate -90*y translate<+1.27,0,1.9>}
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate +90*y translate<-1.27,0,-1.9>}
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate +90*y translate<+1.27,0,-1.9>}
        texture{e3d_tex_silver}
    }
}
#end

#macro IC_SMD_MB2S()
IC_SMD_MB2S_GRND("2")
#end
#macro IC_SMD_MB4S()
IC_SMD_MB2S_GRND("4")
#end
#macro IC_SMD_MB6S()
IC_SMD_MB2S_GRND("6")
#end


/********************************************************************************************************************************************
//LK    = Laenge des Kunststoff (x-Achse)
//BK    = Breite des Kunststoff (z-Achse)
//H     = Hoehe des Kunststoff (Y-Achse)
//pin_l = Anzahl Pins links
//pin_r = Anzahl Pins rechts
//pin_o = Anzahl Pins "oben"
//pin_u = Anzahl Pins "unten"
//pitch = Abstand der einzelnen Pins
//pin_br= Breite eines Pins
//pin_h = Höhe eines Pins
//pin_t = Tiefe eines Pins
//HKoP  = Hoehe des Kunststoffs ueber der Platine (Y-Achse)
//KORW  = Korrekturwinkel
//kp1ab = Wenn 0, wird Abschraegung an Pin1 erzeugt
//cool_x= Kühlfläche unter dem Chip (X-Achse)
//cool_z= Kühlfläche unter dem Chip (Z-Achse)
********************************************************************************************************************************************/
#macro IC_SMD_MLF_GRND(LK,BK,H,pin_l,pin_r,pin_o,pin_u,pitch,pin_br,pin_h,pin_t,HKoP,KORW,kp1ab,cool_x,cool_z)
/********************************************************************************************************************************************
//Makro fuer Pins von MLF-Gehaeusen
//H = Hoehe des Pins
//B = Breite des Pins
//T = Tiefe des Pins
********************************************************************************************************************************************/
union{

    #macro MLF_PIN(H,B,T)
        union{
            box{<-B/2,0,0><+B/2,H,T-B/2>}
            cylinder{<0,0,T-B/2><0,H,T-B/2>,B/2}
            texture{e3d_tex_silver}
        }
    #end
    
    union{
        difference{
            box{<-LK/2,HKoP,-BK/2><LK/2,HKoP+H,BK/2>}
            #if(kp1ab=0)
                box{<0,0,-3><-2,5,3> rotate<0,-45,0> translate<-LK/2+LK/40,0,-BK/2+BK/40>}
            #end
            cylinder{<0,H+HKoP-0.1,0><0,H+HKoP+1,0>0.4 translate<-LK/2+LK/10,0,-BK/2+BK/10>}
            texture{e3d_tex_ic_body_1}
            }
        }
    
    #local scl_fa = BK/10;
    text{ttf besch_font value 0.2,0 scale<scl_fa,scl_fa,1> rotate<90,-90,0> translate<-LK/2+LK/4,H+HKoP+0.001,-BK/2+BK/6> texture{e3d_tex_ic_marking_bright} }

    // Kühlfläche des Dies unter dem Chip
    #if((cool_x!=0) & (cool_z!=0))
        object{TOOLS_PCB_SMD(cool_x,cool_z,H/2,15) texture{e3d_tex_silver}}
    #end

    // Pins auf linker Seite
    #local i=0;
    #while(i<(pin_l/2))
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_l,2)-i)*pitch,0,-BK/2-0.01> rotate<0,90,0> }
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_l,2)-i)*pitch,0,-BK/2-0.01> rotate<0,90,0> }
        #local i=i+1;
    #end
    // Pins auf rechter Seite
    #local i=0;
    #while(i<(pin_r/2))
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_r,2)-i)*pitch,0,-BK/2-0.01> rotate<0,-90,0> }
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_r,2)-i)*pitch,0,-BK/2-0.01> rotate<0,-90,0> }
        #local i=i+1;
    #end
    // Pins auf vorderen/"unteren" Seite
    #local i=0;
    #while(i<pin_u)
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_u,2)-i)*pitch,0,-LK/2-0.01>}
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_u,2)-i)*pitch,0,-LK/2-0.01>}
        #local i=i+1;
    #end
    // Pins auf hinteren/"oberen" Seite
    #local i=0;
    #while(i<pin_o)
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_o,2)-i)*pitch,0,-LK/2-0.01> rotate<0,180,0> }
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_o,2)-i)*pitch,0,-LK/2-0.01> rotate<0,180,0> }
        #local i=i+1;
    #end
    rotate<0,KORW,0>
}
#end

//MLP-28 aus CP2102-GM Datasheet
#macro IC_SMD_MLF_28_050MM(value)
IC_SMD_MLF_GRND(5,5,0.9,7,7,7,7,0.5,0.23,0.25,0.55,0.02,0,1,3.15,3.15)
#end
//MLF-32 aus ATmega8 Datasheet
#macro IC_SMD_MLF_32_050MM(value)
IC_SMD_MLF_GRND(5,5,0.9,8,8,8,8,0.5,0.23,0.25,0.60,0.02,0,1,3.1,3.1)
#end
//MLF-44 aus ATmega16 Datasheet
#macro IC_SMD_MLF_44_050MM(value)
IC_SMD_MLF_GRND(7,7,0.9,11,11,11,11,0.5,0.23,0.25,0.64,0.02,0,1,5,5)
#end
//MLF-32 aus ATmega128 Datasheet
#macro IC_SMD_MLF_64_050MM(value)
IC_SMD_MLF_GRND(9,9,0.9,16,16,16,16,0.5,0.23,0.25,0.60,0.02,0,1,5.4,5.4)
#end






/********************************************************************************************************************************************
//Makro fuer 4-pin SMD-IC's mit Pins nur auf 2-Seiten (SO, TSOP, TSSOP usw.)
//Bas Laarhoven <aesmail@xs4all.nl>
//LK      = Laenge des Kunststoff(Seite der Pins)
//BK      = Breite des Kunststoff(Seite ohne Pins)
//HK      = Hoehe des Kunststoff
//B       = Laenge der Seite ohne Pins ueber alles
//pinb_1  = Breite der Pin 1
//pinb_x  = Breite der anderen Pins
//pin_s   = Staerke des Pinmaterials
//di_pcb  = Abstand des Kunststoff zur Platine
//kor_w   = Korrekturwinkel
//pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
//pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45° statt 10° verwendet (SO)
//pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
//besch_s = Scalefaktor der Beschriftung
********************************************************************************************************************************************/
#macro IC_SMD_SOT143_GRND(LK,BK,HK,B,pinb_1,pinb_x,pin_s,di_pcb,kor_w,pin0_m,pin0_45,pin0_a,besch_s)
union{
    difference{
        box{<LK/2,di_pcb,BK/2><-LK/2,di_pcb+HK,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,-1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,-BK/2>}
        #if(pin0_45!=0)
            box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<45,0,0> translate<0,(di_pcb+HK)/2+pin_s/2+pin_s*1.5,-BK/2>}
        #end
        box{<0,0,-BK/2-0.1><1,HK,BK/2+0.1>  rotate<0,0,10> translate<LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,HK,BK/2+0.1>  rotate<0,0,-10> translate<-LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><1,-HK,BK/2+0.1>  rotate<0,0,-10> translate<LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,-HK,BK/2+0.1>  rotate<0,0,10> translate<-LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        #if(pin0_m = 0)
            #local TextX = -LK/2+0.1*LK;
        #end // ohne Pin-1-Markierung
    }
    
    union{       
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_x,pin_s) rotate<0,90,0> translate<0.95,0,-BK/2>}
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_1,pin_s) rotate<0,90,0> translate<-0.75,0,-BK/2>}
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_x,pin_s) rotate<0,-90,0> translate<0.95,0,BK/2>}
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_x,pin_s) rotate<0,-90,0> translate<-0.95,0,BK/2>}
        texture{e3d_tex_silver}
    }
      
    text{ttf besch_font value 0.2,0 rotate<90,0,0> scale<besch_s,1,besch_s> translate<TextX,HK+di_pcb+0.01,-besch_s/2> texture{e3d_tex_ic_marking_bright} }
    
    rotate<0,kor_w,0>
    
    texture{e3d_tex_ic_body_1}
}
#end

#macro IC_SMD_SOT143(value)
IC_SMD_SOT143_GRND(3.0,1.4,1.1,2.9,0.88,0.48,0.12,0.1,0,0,30,0,0.7)
#end


/**********************************************************************
Testing
**********************************************************************/
#ifndef(inc_testmode)
          
//Size of the Grid Plane (+/- span)
#local XYZ_span=20;

//Orientation axes
cylinder{<-XYZ_span,0,0><XYZ_span,0,0>0.1 pigment{Blue}}	//X
cylinder{<0,-XYZ_span,0><0,XYZ_span,0>0.1 pigment{Red}}		//Y
cylinder{<0,0,-XYZ_span><0,0,XYZ_span>0.1 pigment{Yellow}}	//Z

// Useful GRIDS:
#local XYZ_step= 1 ;          // axis increment
#local XYZ_cnt = 0;           //  loop counter
#local xyz_thick = 0.05;     // grid line thickness

// GRID PLANES: Remove comment begin/end to activate & select PLANES:
#while (XYZ_cnt <= XYZ_span)

	cylinder{<-XYZ_span,0,XYZ_cnt><XYZ_span,0,XYZ_cnt>xyz_thick pigment{Blue}}		// Positive Z-Lines
	cylinder{<-XYZ_span,0,-XYZ_cnt><XYZ_span,0,-XYZ_cnt>xyz_thick pigment{Blue}}	// Negative Z-Lines
	
	//cylinder{<0,XYZ_cnt,-XYZ_span><0,XYZ_cnt,XYZ_span>xyz_thick pigment{Red}}		// Positive Y-Z Plane Lines
	//cylinder{<0,-XYZ_cnt,-XYZ_span><0,-XYZ_cnt,XYZ_span>xyz_thick pigment{Red}}	// Negative Y-Z Plane Lines
	
	//cylinder{<-XYZ_span,XYZ_cnt,0><XYZ_span,XYZ_cnt,0>xyz_thick pigment{Red}}		// Positive Y-X Plane Lines
	//cylinder{<-XYZ_span,-XYZ_cnt,0><XYZ_span,-XYZ_cnt,0>xyz_thick pigment{Red}}	// Negative Y-X Plane Lines
	
	cylinder{<XYZ_cnt,0,-XYZ_span><XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}	// Positive X-Lines
	cylinder{<-XYZ_cnt,0,-XYZ_span><-XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}	// Negative X-Lines

	#local XYZ_cnt = XYZ_cnt+XYZ_step;
#end

camera
{       
	#local tt = 40;				//let's you change the distance easily
	location <-tt,tt,-tt>
	//location<0,5,-50>			//alternate location
	look_at <0,0,0>				//best to select the approximate centre of the object
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

#end
//End of Macros
