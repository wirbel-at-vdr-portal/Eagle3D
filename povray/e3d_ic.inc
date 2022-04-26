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
#include "IC/SMT/MICROMAX.inc"
#include "IC/SMT/PLCC.inc"
#include "IC/SMT/QFN.inc"
#include "IC/SMT/QSOP.inc"
#include "IC/SMT/SO.inc"
#include "IC/SMT/SSOP.inc"
#include "IC/SMT/TSOP.inc"
#include "IC/SMT/TSOP-II.inc"
#include "IC/SMT/TSSOP.inc"




//Tilmann Reh <tilmann.reh@autometer.de>
#macro IC_SMD_VSO40(value,logo)
IC_SMD_BASE(15.4,7.55,2.35,12.05,20,20,0.762,0.762,0.36,0.36,0.18,0.2,0,2,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_VSO56(value,logo)
IC_SMD_BASE(21.7,11.05,2.9,15.5,28,28,0.75,0.75,0.36,0.36,0.18,0.2,0,2,0,11/6,11/5,0,logo)
#end
#macro IC_SMD_PSO20(value,logo)
IC_SMD_BASE(15.9,11,3.3,14.2,10,10,1.27,1.27,0.47,0.47,0.28,0.2,0,3,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_PSO36(value,logo)
IC_SMD_BASE(15.9,11,3.3,14.2,18,18,0.65,0.65,0.3,0.3,0.28,0.2,0,3,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_MSOP10(value,logo)
IC_SMD_BASE(3,3,0.85,4.9,5,5,0.5,0.5,0.25,0.25,0.15,0.1,0,1,0,0.5,0.65,0,logo)
#end
#macro IC_SMD_SOT23(value,logo)
IC_SMD_BASE(2.9,1.3,1,2.8,2,1,1.9,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_SMD_SOT23_5(value,logo)
IC_SMD_BASE(2.9,1.6,1,2.8,3,2,0.95,1.90,0.35,0.35,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_SMD_SOT23_6(value,logo)
IC_SMD_BASE(2.9,1.6,1,2.8,3,3,0.95,0.95,0.35,0.35,0.13,0.1,0,1,0,0.3,0.7,0,logo)
#end
#macro IC_SMD_SOT223(value,logo)
IC_SMD_BASE(6.5,3.5,1.6,7,3,1,2.3,2.3,0.75,3,0.2,0.2,0,0,0,0,1.0,0,logo)
#end
#macro IC_SMD_SOT363(value,logo)
IC_SMD_BASE(2.0,1.25,1.0,2.1,3,3,0.65,0.65,0.25,0.25,0.15,0.1,0,1,0,0,0.5,0,logo)
#end
//SMD-Transistoren aus SIC_GRND abgeleitet
#macro IC_TR_SOT23(value,logo)
IC_SMD_BASE(2.9,1.3,1,2.8,2,1,1.9,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_TR_TO252(value,logo)
IC_SMD_BASE(6.1,6.5,2.2,10,2,1,4.5,1.9,0.9,5.3,0.5,0.1,0,0,0,1.5,1.0,0,logo)
#end
#macro IC_TR_TO263(value,logo)
IC_SMD_BASE(10.2,8.7,4.2,15.2,2,1,5.1,1.9,1.4,10.2,0.5,0.1,0,0,0,1.5,1.0,0,logo)
#end
// Friedrich Bleikamp
#macro IC_SMD_DPAK_369C(value,logo)
IC_SMD_BASE(6.1,6.5,2.2,11,2,0,4.5,0,0.8,0,0.5,0.1,0,4,0,1.5,1.0,0,logo)
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
