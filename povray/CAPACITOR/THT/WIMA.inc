/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * WIMA cap
 * Andreas Rebmann <A.Rebmann-Elektrotechnik@t-online.de>
 * simplify: wk, 06.04.2023
 * Breite=B , Tiefe = T, Hoehe = H, Raster = Ra
 ******************************************************************************/
#macro CAP_DIS_WIMA_BASE(B,T,H,Ra)
  union {
     box {
        <-B/2+0.2, 0,     T/2>     <B/2-0.2,H-0.2,-T/2>
        rotate<0,0,0>
        translate<0,0,0>
        } //Grundkoerper
     box {
        <-B/2,     0,    -T/2+0.2> <B/2,    H-0.2, T/2-0.2>
        rotate<0,0,0>
        translate<0,0,0>
        } //Kleine Box innen
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

     #switch(Ra)
        #range (2.5,2.6) // 2.54
           #local d=0.4;
           #local sc1=1.0;
           #local sc2=1.4;
           #local dB=0.6;
           #local dH1=4.3;
           #local dH2=2.8;
           #break
        #range (5.0,5.1) // 5.08
           #local d=0.5;
           #local sc1=1.4;
           #local sc2=2.0;
           #local dB=1.2;
           #local dH1=4.3;
           #local dH2=2.8;
           #break
        #range (7.4,7.6) // 7.5
           #local d=0.7;
           #local sc1=2.0;
           #local sc2=2.7;
           #local dB=1.8;
           #local dH1=5.5;
           #local dH2=3.3;
           #break
        #range (9.9,10.1) //10.0
           #local d=0.7;
           #local sc1=2.4;
           #local sc2=3.1;
           #local dB=2.5;
           #local dH1=6.0;
           #local dH2=3.5;
           #break
        #range (14.9,15.1) //15.0
           #local d=0.8;
           #local sc1=3.0;
           #local sc2=3.7;
           #local dB=4.0;
           #local dH1=7.0;
           #local dH2=4.0;
           #break
        #range (22.4,22.6) //22.5
           #local d=0.8;
           #local sc1=3.5;
           #local sc2=4.2;
           #local dB=6.5;
           #local dH1=9.0;
           #local dH2=6.0;
           #break
        #range (27.4,27.6) //27.5
           #local d=1.0;
           #local sc1=4.0;
           #local sc2=4.7;
           #local dB=10.0;
           #local dH1=12.0;
           #local dH2=8.0;
           #break
        #range (37.4,37.6) //37.5
           #local d=1.0;
           #local sc1=4.5;
           #local sc2=5.2;
           #local dB=15.0;
           #local dH1=15.0;
           #local dH2=10.0;
           #break
        #end
     cylinder {
        <-Ra/2 ,0> <-Ra/2,wima_pin_length,0> d/2
        texture { col_silver }
        } // Draht rechts senkrecht
     cylinder {
        < Ra/2 ,0> < Ra/2,wima_pin_length,0> d/2
        texture { col_silver }
        } // Draht links senkrecht
     text {
        ttf besch_font value 0.1, 0
        scale sc1
        texture { col_black_marking }
        rotate <0,180,0>
        translate <B/2-dB, H-dH1, T/2+0.1>
        rotate<0,0,0>
        } //Beschriftung Value
     text {
        ttf besch_font "WIMA" 0.1, 0
        scale sc2
        texture { col_black_marking }
        rotate <0,180,0>
        translate <B/2-dB, H-dH2, T/2+0.1>
        rotate <0,0,0>
        } //Beschriftung WIMA
     rotate<0,180,0>
     texture {
        pigment { Red }
        finish {
           ambient (0.10 * global_ambient_mul)
           }
        }    
     }
#end


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

#macro CAP_DIS_WIMA_100_040_130_095(value)
  CAP_DIS_WIMA_BASE(13.0,4.0,9.5,10.0)
#end

#macro CAP_DIS_WIMA_100_050_130_110(value)
  CAP_DIS_WIMA_BASE(13.0,5.0,11.0,10.0)
#end

#macro CAP_DIS_WIMA_100_060_130_120(value)
  CAP_DIS_WIMA_BASE(13.0,6.0,12.0,10.0)
#end

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

#macro CAP_DIS_WIMA_375_150_415_260(value)
  CAP_DIS_WIMA_BASE(41.5,15.0,26.0,37.5)
#end

#macro CAP_DIS_WIMA_375_190_415_320(value)
  CAP_DIS_WIMA_BASE(41.5,19.0,32.0,37.5)
#end

#macro CAP_DIS_WIMA_375_200_415_395(value)
  CAP_DIS_WIMA_BASE(41.5,20.0,39.5,37.5)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//capacitator-wima:C2.5/5-2=CAP_DIS_WIMA_25_025_046_075(:WIMA cap grid 2.54
//capacitator-wima:C2.5/5-4=CAP_DIS_WIMA_25_040_046_090(:WIMA cap grid 2.54
//capacitator-wima:C2.5/5-5=CAP_DIS_WIMA_25_050_046_100(:WIMA cap grid 2.54
//capacitator-wima:C2.5/5-6=CAP_DIS_WIMA_25_060_046_100(:WIMA cap grid 2.54
//capacitator-wima:C2.5-2=CAP_DIS_WIMA_25_025_046_075(:WIMA cap grid 2.54
//capacitator-wima:C2.5-3=CAP_DIS_WIMA_25_030_046_075(:WIMA cap grid 2.54
//capacitator-wima:C2.5-4=CAP_DIS_WIMA_25_040_046_090(:WIMA cap grid 2.54
//capacitator-wima:C2.5-5=CAP_DIS_WIMA_25_050_046_100(:WIMA cap grid 2.54
//capacitator-wima:C2.5-6=CAP_DIS_WIMA_25_060_046_100(:WIMA cap grid 2.54
//capacitator-wima:C5B2.5=CAP_DIS_WIMA_5_025_072_065(:WIMA cap grid 5.08
//capacitator-wima:C5B3=CAP_DIS_WIMA_5_030_072_075(:WIMA cap grid 5.08
//capacitator-wima:C5B3.5=CAP_DIS_WIMA_5_035_072_085(:WIMA cap grid 5.08
//capacitator-wima:C5B4.5=CAP_DIS_WIMA_5_045_072_095(:WIMA cap grid 5.08
//capacitator-wima:C5B5=CAP_DIS_WIMA_5_050_072_100(:WIMA cap grid 5.08
//capacitator-wima:C5B5.5=CAP_DIS_WIMA_5_055_072_115(:WIMA cap grid 5.08
//capacitator-wima:C5B7.2=CAP_DIS_WIMA_5_072_072_130(:WIMA cap grid 5.08
//capacitator-wima:C5B8.5=CAP_DIS_WIMA_5_085_072_140(:WIMA cap grid 5.08
//capacitator-wima:C7.5B3=CAP_DIS_WIMA_75_030_100_085(:WIMA cap grid 7.5
//capacitator-wima:C7.5B4=CAP_DIS_WIMA_75_040_100_090(:WIMA cap grid 7.5
//capacitator-wima:C7.5B5=CAP_DIS_WIMA_75_050_103_105(:WIMA cap grid 7.5
//capacitator-wima:C7.5B6=CAP_DIS_WIMA_75_057_100_125(:WIMA cap grid 7.5
//capacitator-wima:C10B4=CAP_DIS_WIMA_100_040_130_095(:WIMA cap grid 10
//capacitator-wima:C10B5=CAP_DIS_WIMA_100_050_130_110(:WIMA cap grid 10
//capacitator-wima:C10B6=CAP_DIS_WIMA_100_060_130_120(:WIMA cap grid 10
//capacitator-wima:C15B5=CAP_DIS_WIMA_150_050_180_110(:WIMA cap grid 15
//capacitator-wima:C15B6=CAP_DIS_WIMA_150_060_180_125(:WIMA cap grid 15
//capacitator-wima:C15B7=CAP_DIS_WIMA_150_070_180_140(:WIMA cap grid 15
//capacitator-wima:C15B8=CAP_DIS_WIMA_150_080_180_150(:WIMA cap grid 15
//capacitator-wima:C15B9=CAP_DIS_WIMA_150_090_180_160(:WIMA cap grid 15
//capacitator-wima:C22.5B6=CAP_DIS_WIMA_225_060_265_150(:WIMA cap grid 22.5
//capacitator-wima:C22.5B7=CAP_DIS_WIMA_225_070_265_165(:WIMA cap grid 22.5
//capacitator-wima:C22.5B8=CAP_DIS_WIMA_225_085_265_185(:WIMA cap grid 22.5
//capacitator-wima:C22.5B10=CAP_DIS_WIMA_225_105_265_190(:WIMA cap grid 22.5
//capacitator-wima:C22.5B11=CAP_DIS_WIMA_225_110_265_210(:WIMA cap grid 22.5
//capacitator-wima:C27.5B9=CAP_DIS_WIMA_275_090_315_210(:WIMA cap grid 27.5
//capacitator-wima:C27.5B11=CAP_DIS_WIMA_275_110_315_210(:WIMA cap grid 27.5
//capacitator-wima:C27.5B13=CAP_DIS_WIMA_275_130_315_240(:WIMA cap grid 27.5
//capacitator-wima:C27.5B15=CAP_DIS_WIMA_275_150_315_260(:WIMA cap grid 27.5
//capacitator-wima:C27.5B17=CAP_DIS_WIMA_275_170_315_345(:WIMA cap grid 27.5
//capacitator-wima:C27.5B20=CAP_DIS_WIMA_275_200_315_395(:WIMA cap grid 27.5
//capacitator-wima:C37.5B15=CAP_DIS_WIMA_375_150_415_260(:WIMA cap grid 37.5
//capacitator-wima:C37.5B19=CAP_DIS_WIMA_375_190_415_320(:WIMA cap grid 37.5
//capacitator-wima:C37.5B20=CAP_DIS_WIMA_375_200_415_395(:WIMA cap grid 37.5
// end assignment
