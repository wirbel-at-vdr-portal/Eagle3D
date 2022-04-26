/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Authors: Matthias Weisser <matthias@matwei.de>
 *          Tilmann Reh <tilmann.reh(replace with at)autometer.de>
 *          Friedrich Bleikamp <fbleikamp(replace with at)web.de>
 ******************************************************************************/


/*******************************************************************************
 * Makro fuer SMD-IC's die Pins nur auf 2-Seiten haben(SO, TSOP, TSSOP usw.)
 * LK     : Laenge des Kunststoff(Seite der Pins)
 * BK     : Breite des Kunststoff(Seite ohne Pins)
 * HK     : Hoehe des Kunststoff
 * B      : Laenge der Seite ohne Pins ueber alles
 * pin_u  : Pins auf der "unteren" Seite
 * pin_o  : Pins auf der "oberen" Seite
 * ptch_u : Pitch der Pins auf der "unteren" Seite
 * ptch_o : Pitch der Pins auf der "oberen" Seite
 * pinb_u : Breite der Pins auf der "unteren" Seite
 * pinb_o : Breite der Pins auf der  "oberen" Seite
 * pin_s  : Staerke des Pinmaterials
 * di_pcb : Abstand des Kunststoff zur Platine
 * kor_w  : Korrekturwinkel
 * pin0_m : Pin-1-Markierung:
 *            0 = keine,
 *            1 = Farbklecks
 *            2 = Kerbe wie bei DIP
 *            3 = PowerSO
 *            4 = DPAK
 * pin0_45: Wenn != 0 wird an der unteren Seite ein Winkel am Koerper
 *          von 45° statt 10° verwendet (SO)
 * pin0_a : Abstand des Pin0-Kennzeichners vom Rand
 * besch_s: Scalefaktor der Beschriftung
 * besch_w: Wenn != 0 wird Beschriftung gedreht
 * logo   : Name of the logo
 ******************************************************************************/
#macro IC_SMD_BASE(LK,BK,HK,B,pin_u,pin_o,ptch_u,ptch_o,pinb_u,pinb_o,pin_s,di_pcb,kor_w,pin0_m,pin0_45,pin0_a,besch_s,besch_w,logo)
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
