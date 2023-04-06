/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

#include "e3d_tools.inc"







/********************************************************************************************************************************************
//Wimakondenstor Grundmakro
//by Andreas Rebmann <A.Rebmann-Elektrotechnik@t-online.de>
//Grundmacro - Breite=B , Tiefe = T, Hoehe = H, Raster = Ra
********************************************************************************************************************************************/
#macro CAP_DIS_WIMA_BASE(B,T,H,Ra)
union {

    box { <-B/2+0.2, 0,     T/2>     <B/2-0.2,H-0.2,-T/2>      rotate<0,0,0> translate<0,0,0> } //Grundkoerper
    box { <-B/2,     0,    -T/2+0.2> <B/2,    H-0.2, T/2-0.2>  rotate<0,0,0> translate<0,0,0> } //Kleine Box innen
    box { <-B/2+0.2, H-0.2,-T/2+0.2> <B/2-0.2,H    , T/2-0.2>  rotate<0,0,0> translate<0,0,0> } //Kleine Box oben

    cylinder { <-B/2+0.2,0,0> <-B/2+0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,  T/2-0.2> } //Rundungen rechts
    cylinder { <-B/2+0.2,0,0> <-B/2+0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,-T/2+0.2> } //Rundungen rechts
    cylinder { < B/2-0.2,0,0> < B/2-0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,  T/2-0.2> } //Rundungen links
    cylinder { < B/2-0.2,0,0> < B/2-0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0, -T/2+0.2> } //Rundungen links

    sphere { < B/2-0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  translate<0,0,0> }  //Rundungen oben
    sphere { < B/2-0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  translate<0,0,0> }  //Rundungen oben
    sphere { <-B/2+0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  translate<0,0,0> }  //Rundungen oben
    sphere { <-B/2+0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  translate<0,0,0> }  //Rundungen oben

    cylinder { <-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 rotate<0,0,0> translate <0, 0, T/2-0.2> }   //Rundungen vorne
    cylinder { <-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 rotate<0,0,0> translate <0, 0,-T/2+0.2> }   //Rundungen hinten
    cylinder { <-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0, 90,0> translate <-B/2+0.2, 0, 0> }  //Rundungen rechts kurz
    cylinder { <-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0,-90,0> translate <-B/2+0.2, 0, 0> }  //Rundungen rechts kurz
    cylinder { <-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0, 90,0> translate < B/2-0.2, 0, 0> }  //Rundungen links kurz
    cylinder { <-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0,-90,0> translate < B/2-0.2, 0, 0> }  //Rundungen links kurz

    //Drahtdurchmesser und Beschriftung an die Kondensatorgroesse anpassen

    #if(pin_short=on)
        #local wima_pin_length = -1*(pin_length+pcb_height);
    #else
        #local wima_pin_length = -5;
    #end

    #if (Ra=2.54)    //d=0.4mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.20 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.20 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<1.0,1.0,1.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-0.6, H-4.3, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<1.4,1.4,1.4> texture{col_black_marking} rotate<0,180,0> translate<B/2-0.6, H-2.8, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=5.08)    //d=0.5mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.25 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.25 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<1.4,1.4,1.4> texture{col_black_marking} rotate<0,180,0> translate<B/2-1.2, H-4.3, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<2.0,2.0,2.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-1.2, H-2.8, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=7.50)    //d=0.7mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.35 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.35 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<2.0,2.0,2.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-1.8, H-5.5, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<2.7,2.7,2.7> texture{col_black_marking} rotate<0,180,0> translate<B/2-1.8, H-3.3, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=10.0)    //d=0.7mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.35 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.35 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<2.4,2.4,2.4> texture{col_black_marking} rotate<0,180,0> translate<B/2-2.5, H-6.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<3.1,3.1,3.1> texture{col_black_marking} rotate<0,180,0> translate<B/2-2.5, H-3.5, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=15.0)    //d=0.8mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.40 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.40 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<3.0,3.0,3.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-4.0, H-7.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<3.7,3.7,3.7> texture{col_black_marking} rotate<0,180,0> translate<B/2-4.0, H-4.0, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=22.5)    //d=0.8mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.40 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.40 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<3.5,3.5,3.5> texture{col_black_marking} rotate<0,180,0> translate<B/2-6.5, H-9.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<4.2,4.2,4.2> texture{col_black_marking} rotate<0,180,0> translate<B/2-6.5, H-6.0, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=27.5)    //d=1.0mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.50 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.50 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<4.0,4.0,4.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-10.0, H-12.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<4.7,4.7,4.7> texture{col_black_marking} rotate<0,180,0> translate<B/2-10.0, H- 8.0, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    #if (Ra=37.5)    //d=1.0mm
        cylinder { <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.50 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.50 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<4.5,4.5,4.5> texture{col_black_marking} rotate<0,180,0> translate<B/2-15.0, H-15.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
        text { ttf besch_font "WIMA"   0.1, 0 scale<5.2,5.2,5.2> texture{col_black_marking} rotate<0,180,0> translate<B/2-15.0, H-10.0, T/2+0.1> rotate<0,0,0> } //Beschriftung WIMA
    #end

    rotate<0,180,0>
    texture {
       pigment { Red }
       finish {
          ambient (0.10 * global_ambient_mul)
          }
       }    
}
#end

// Raster 2.54
#macro CAP_DIS_WIMA_25_025_046_075(value)
CAP_DIS_WIMA_BASE(4.6,2.5,7.5,2.54,)
#end
#macro CAP_DIS_WIMA_25_030_046_075(value)
CAP_DIS_WIMA_BASE(4.6,3.0,7.5,2.54,)
#end
#macro CAP_DIS_WIMA_25_040_046_090(value)
CAP_DIS_WIMA_BASE(4.6,4.6,9.0,2.54,)
#end
#macro CAP_DIS_WIMA_25_050_046_100(value)
CAP_DIS_WIMA_BASE(4.6,5.5,10.0,2.54,)
#end
#macro CAP_DIS_WIMA_25_060_046_100(value)
CAP_DIS_WIMA_BASE(4.6,6.5,10.0,2.54,)
#end
//Raster 5.08
#macro CAP_DIS_WIMA_5_025_072_065(value)
CAP_DIS_WIMA_BASE(7.2,2.5,6.5,5.08,)
#end
#macro CAP_DIS_WIMA_5_030_072_075(value)
CAP_DIS_WIMA_BASE(7.2,3.0,7.5,5.08,)
#end
#macro CAP_DIS_WIMA_5_035_072_085(value)
CAP_DIS_WIMA_BASE(7.2,3.5,8.5,5.08,)
#end
#macro CAP_DIS_WIMA_5_045_072_095(value)
CAP_DIS_WIMA_BASE(7.2,4.5,9.5,5.08)
#end
#macro CAP_DIS_WIMA_5_050_072_100(value)
CAP_DIS_WIMA_BASE(7.2,5.0,10.0,5.08)
#end
#macro CAP_DIS_WIMA_5_055_072_115(value)
CAP_DIS_WIMA_BASE(7.2,5.5,11.5,5.08)
#end
#macro CAP_DIS_WIMA_5_072_072_130(value)
CAP_DIS_WIMA_BASE(7.2,7.2,13.0,5.08)
#end
#macro CAP_DIS_WIMA_5_085_072_140(value)
CAP_DIS_WIMA_BASE(7.2,8.5,14.0,5.08)
#end
//Raster 7.5
#macro CAP_DIS_WIMA_75_030_100_085(value)
CAP_DIS_WIMA_BASE(10.0,3.0,8.5,7.5)
#end
#macro CAP_DIS_WIMA_75_040_100_090(value)
CAP_DIS_WIMA_BASE(10.0,4.0,9.0,7.5)
#end
#macro CAP_DIS_WIMA_75_050_103_105(value)
CAP_DIS_WIMA_BASE(10.3,5.0,10.5,7.5)
#end
#macro CAP_DIS_WIMA_75_057_100_125(value)
CAP_DIS_WIMA_BASE(10.3,5.7,12.5,7.5)
#end
//Raster 10
#macro CAP_DIS_WIMA_100_040_130_095(value)
CAP_DIS_WIMA_BASE(13.0,4.0,9.5,10.0)
#end
#macro CAP_DIS_WIMA_100_050_130_110(value)
CAP_DIS_WIMA_BASE(13.0,5.0,11.0,10.0)
#end
#macro CAP_DIS_WIMA_100_060_130_120(value)
CAP_DIS_WIMA_BASE(13.0,6.0,12.0,10.0)
#end
//Raster 15
#macro CAP_DIS_WIMA_150_050_180_110(value)
CAP_DIS_WIMA_BASE(18.0,5.0,11.0,15.0)
#end
#macro CAP_DIS_WIMA_150_060_180_125(value)
CAP_DIS_WIMA_BASE(18.0,6.0,12.5,15.0)
#end
#macro CAP_DIS_WIMA_150_070_180_140(value)
CAP_DIS_WIMA_BASE(18.0,7.0,14.0,15.0)
#end
#macro CAP_DIS_WIMA_150_080_180_150(value)
CAP_DIS_WIMA_BASE(18.0,8.0,15.0,15.0)
#end
#macro CAP_DIS_WIMA_150_090_180_160(value)
CAP_DIS_WIMA_BASE(18.0,9.0,16.0,15.0)
#end
//Raster 22.5
#macro CAP_DIS_WIMA_225_060_265_150(value)
CAP_DIS_WIMA_BASE(26.5,6.0,15.0,22.5)
#end
#macro CAP_DIS_WIMA_225_070_265_165(value)
CAP_DIS_WIMA_BASE(26.5,7.0,16.5,22.5)
#end
#macro CAP_DIS_WIMA_225_085_265_185(value)
CAP_DIS_WIMA_BASE(26.5,8.5,18.5,22.5)
#end
#macro CAP_DIS_WIMA_225_105_265_190(value)
CAP_DIS_WIMA_BASE(26.5,10.5,19.0,22.5)
#end
#macro CAP_DIS_WIMA_225_110_265_210(value)
CAP_DIS_WIMA_BASE(26.5,11.0,21.0,22.5)
#end
//Raster 27.5
#macro CAP_DIS_WIMA_275_090_315_210(value)
CAP_DIS_WIMA_BASE(31.5,9.0,21.0,27.5)
#end
#macro CAP_DIS_WIMA_275_110_315_210(value)
CAP_DIS_WIMA_BASE(31.5,11.0,21.0,27.5)
#end
#macro CAP_DIS_WIMA_275_130_315_240(value)
CAP_DIS_WIMA_BASE(31.5,13.0,24.0,27.5)
#end
#macro CAP_DIS_WIMA_275_150_315_260(value)
CAP_DIS_WIMA_BASE(31.5,15.0,26.0,27.5)
#end
#macro CAP_DIS_WIMA_275_170_315_345(value)
CAP_DIS_WIMA_BASE(31.5,17.0,34.5,27.5)
#end
#macro CAP_DIS_WIMA_275_200_315_395(value)
CAP_DIS_WIMA_BASE(31.5,20.0,39.5,27.5)
#end
//Raster 37.5
#macro CAP_DIS_WIMA_375_150_415_260(value)
CAP_DIS_WIMA_BASE(41.5,15.0,26.0,37.5)
#end
#macro CAP_DIS_WIMA_375_190_415_320(value)
CAP_DIS_WIMA_BASE(41.5,19.0,32.0,37.5)
#end
#macro CAP_DIS_WIMA_375_200_415_395(value)
CAP_DIS_WIMA_BASE(41.5,20.0,39.5,37.5)
#end


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


