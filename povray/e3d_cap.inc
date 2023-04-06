/***  ****************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

#include "e3d_tools.inc"









/********************************************************************************************************************************************
//(Tiefe, Breite, Hoehe, Breite Loetflaechen, Abstand Pin zu Pin, Anzahl Kondensatoren,Farbe des Koerpers)
********************************************************************************************************************************************/
#macro CAP_SMD_CHIP_ARRAY_BASE(b,l,h,blf,pitch,n)
union {    
    //Body
    object{
        Round_Box_Union(<0,0.05,0>, <l,h,b>, min(b,l,h)/6)
        translate<-l/2,0,-b/2>
        texture{col_ceramic_cap}
    }
        
    //Pins
    #local i = 0;
    #local x_pos = -(n-1)/2*pitch;        
    union {    
        #while(i<n)
        
            box { <-blf/2,0,b/2+0.01> <blf/2,h,b/2-b/10> translate<x_pos,0,0> }
            box { <-blf/2,0,-b/2-0.01> <blf/2,h,-b/2+b/10> translate<x_pos,0,0> }
            
            #local i = i+1;
            #local x_pos = x_pos + pitch;
        
        #end
        texture{col_silver}
    }    
}
#end

#macro CAP_SMD_CHIP_ARRAY_4X0603_0612()
CAP_SMD_CHIP_ARRAY_BASE(1.60,3.20,0.8,0.4,0.8,4)
#end


/********************************************************************************************************************************************
//Grundmakro fuer SMD-Keramik-Chip-Kondensator (neu Parameter K = Anschlussbreite)
//basiert auf Makro von Walter Muecke
********************************************************************************************************************************************/
#macro CAP_SMD_CHIP_BASE(L,W,T,K)
union {
    //Body
    superellipsoid{ <0.25-(L+W)/150, 0.25-(L+W)/150> texture{col_ceramic_cap} scale<L/2,W/2,T/2> }     //Grundkoerper braun
    
    //Contacts
    union {
        superellipsoid{ <0.25-(L+W)/200, 0.25-(L+W)/200> scale<(K+L/100)/2,W/2,T/2> translate <(L-K)/2,0,0> }
        superellipsoid{ <0.25-(L+W)/200, 0.25-(L+W)/200> scale<(K+L/100)/2,W/2,T/2> translate <-(L-K)/2,0,0> }
        texture{col_silver}
    }
    rotate<90,0,0>
    translate<0,T/2,0>
}
#end

//2220
#macro CAP_SMD_CHIP_2220()
CAP_SMD_CHIP_BASE(5.7,5.0,2.7,0.5)
#end
//1825
#macro CAP_SMD_CHIP_1825()
CAP_SMD_CHIP_BASE(4.5,6.4,1.7,0.5)
#end
//1812
#macro CAP_SMD_CHIP_1812()
CAP_SMD_CHIP_BASE(4.5,3.2,1.7,0.5)
#end
//1210
#macro CAP_SMD_CHIP_1210()
CAP_SMD_CHIP_BASE(3.2,2.5,1.7,0.5)
#end
#macro CAP_SMD_CHIP_1206()
CAP_SMD_CHIP_BASE(3.2,1.6,1.5,0.5)
#end
#macro CAP_SMD_CHIP_0805()
CAP_SMD_CHIP_BASE(2.0,1.25,1.3,0.5)
#end
#macro CAP_SMD_CHIP_0603()
CAP_SMD_CHIP_BASE(1.6,0.8,0.9,0.3)
#end
#macro CAP_SMD_CHIP_0402()
CAP_SMD_CHIP_BASE(1.0,0.5,0.6,0.2)
#end


/********************************************************************************************************************************************
//Grundmakro fuer SMD-Tantal-Chip-Kondensator
//basiert auf Makro von Walter Muecke
********************************************************************************************************************************************/
#macro CAP_SMD_CHIP_TT_BASE(L,W,H,LT,WT,HT,P,value)
union {
    
    //Body
    box { <0,0,0> <LT,H,W> pigment{rgb(<0.400, 0.320, 0.220>)*1.2} translate<-LT/2,(L-LT)/2,-W/2> }            //Grundkoerper braun
    
    //Marking
    text{ ttf besch_font value 0.1,0 scale L/8 rotate<90,0,0> translate<-LT/4,H+(L-LT)/2+0.01,0> pigment{DarkWood*0.7}}
    
    //
    box { <0,0,0> <(L-2*P)-0.3,(L-LT)/2,W> pigment{rgb(<0.400, 0.320, 0.220>)*1.2} translate<-((L-2*P)-0.3)/2,0,-W/2> }
    box { <0,0,0> <0.4/exp(-LT/10),0.002,W> pigment{DarkWood*0.7} translate<-LT/2.1,H+(L-LT)/2,-W/2> }        //Markierung
    
    union {
        //rechter Anschluss
        difference {
            box { <0,0,0> <-P,HT,WT> }
            box { <0,(L-LT)/2,-0.002> <-P-0.002,HT-(L-LT)/2,WT+0.002> translate<-(L-LT)/2,0,0> }
            cylinder { <0,HT,-0.002> <0,HT,WT+0.002>(L-LT)/2}
            cylinder { <0,0,-0.002> <0,0,WT+0.002>(L-LT)/2}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //rechter Anschlus
        difference {
            cylinder { <-(L-LT)/2,HT-(L-LT)/2,> <-(L-LT)/2,HT-(L-LT)/2,WT>(L-LT)/2}
            cylinder { <-3*(L-LT)/4,HT-3*(L-LT)/4,-0.04> <-3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box { <-(L-LT)/2,HT-3*(L-LT)/4,-0.04> <-(L-LT),HT-5,WT+0.002> }
            box { <-3*(L-LT)/4,HT-(L-LT)/2,-0.04> <-(L-LT),HT-5,WT+0.002> }
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //rechter Anschlus
        difference {
            cylinder { <-(L-LT)/2,(L-LT)/2,0> <-(L-LT)/2,(L-LT)/2,WT>(L-LT)/2}
            cylinder { <-3*(L-LT)/4,3*(L-LT)/4,-0.04> <-3*(L-LT)/4,3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box { <(-L-LT)/2,3*(L-LT)/4,-0.04> <-(L-LT),5,WT+0.002> }
            box { <0,0,-0.04> <(L-LT)/2,(L-LT)/2,WT+0.002> translate<-(L-LT),0.75*(L-LT),0> }
            box { <(L-LT)/2,(L-LT)/2,-0.04> <(L-LT),L-LT,WT+0.002> translate<-1.75*(L-LT),0,0> }
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference {
            box { <0,0,0> <P,HT,WT> }
            box { <(L-LT)/2,(L-LT)/2,-0.002> <P+0.002,HT-(L-LT)/2,WT+0.002> }
            cylinder { <0,HT,-0.002> <0,HT,WT+0.002>(L-LT)/2}
            cylinder { <0,0,-0.002> <0,0,WT+0.002>(L-LT)/2}
            box { <-0.002,HT/2,0> <P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35> }
            translate<-L/2-0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference {
            cylinder { <(L-LT)/2,HT-(L-LT)/2,-0.002> <(L-LT)/2,HT-(L-LT)/2,WT+0.002>(L-LT)/2}
            cylinder { <3*(L-LT)/4,HT-3*(L-LT)/4,-0.04> <3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box { <(L-LT)/2,HT-3*(L-LT)/4,-0.04> <L-LT,HT-5,WT+0.002> }
            box { <3*(L-LT)/4,HT-(L-LT)/2,-0.04> <L-LT,HT-5,WT+0.002> }
            box { <-0.002,HT/2,0> <P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35> }
            translate<-L/2-0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference {
            cylinder { <(L-LT)/2,(L-LT)/2,-0.002> <(L-LT)/2,(L-LT)/2,WT+0.002>(L-LT)/2}
            cylinder { <3*(L-LT)/4,3*(L-LT)/4,-0.04> <3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box { <(L-LT)/2,3*(L-LT)/4,-0.04> <L-LT,5,WT+0.002> }
            box { <3*(L-LT)/4,(L-LT)/2,-0.04> <L-LT,L-LT,WT+0.002> }
            translate<-L/2-0.02,0,-WT/2>
        }
        texture{col_silver}
    }
    
    rotate<0,180,0>
}
#end                                                                                                                 

#macro CAP_SMD_CHIP_TT_SCT_A(value)
CAP_SMD_CHIP_TT_BASE(3.2,1.6,1.6,3.0,1.2,1.0,0.8,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_B(value)
CAP_SMD_CHIP_TT_BASE(3.5,2.8,1.9,3.3,2.2,1.2,0.8,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_C(value)
CAP_SMD_CHIP_TT_BASE(6.0,3.2,2.5,5.8,2.2,1.5,1.3,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_D(value)
CAP_SMD_CHIP_TT_BASE(7.3,4.3,2.8,7.1,2.4,1.6,1.3,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_E(value)
CAP_SMD_CHIP_TT_BASE(7.3,4.3,4.1,7.1,2.4,1.6,1.3,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_R(value)
CAP_SMD_CHIP_TT_BASE(2.0,1.6,1.0,1.9,1.2,0.6,0.5,value)
#end


