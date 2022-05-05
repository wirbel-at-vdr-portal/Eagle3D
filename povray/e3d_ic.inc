/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

#include "IC/THT/DIL.inc"
#include "IC/THT/SIL.inc"
#include "IC/THT/multiwatt.inc"
#include "IC/SMT/MICROMAX.inc"
#include "IC/SMT/MSOP.inc"
#include "IC/SMT/PLCC.inc"
#include "IC/SMT/PSO.inc"
#include "IC/SMT/QFN.inc"
#include "IC/SMT/QSOP.inc"
#include "IC/SMT/SO.inc"
#include "IC/SMT/SOT223.inc"
#include "IC/SMT/SOT23.inc"
#include "IC/SMT/SOT363.inc"
#include "IC/SMT/SSOP.inc"
#include "IC/SMT/TO252_DPAK.inc"
#include "IC/SMT/TO253_SOT143.inc"
#include "IC/SMT/TO263_D2PAK.inc"
#include "IC/SMT/TSOP.inc"
#include "IC/SMT/TSOP-II.inc"
#include "IC/SMT/TSSOP.inc"
#include "IC/SMT/VSO.inc"
















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




//MLF-32 aus ATmega8 Datasheet
#macro IC_SMD_MLF_32_050MM(value)
IC_SMD_MLF_GRND(5,5,0.9,8,8,8,8,0.5,0.23,0.25,0.60,0.02,0,1,3.1,3.1)
#end









