/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * based on WIMA caps: Andreas Rebmann <A.Rebmann-Elektrotechnik@t-online.de>
 * Breite=B , Tiefe = T, Hoehe = H, Raster = Ra
 ******************************************************************************/
#macro CAP_DIS_BLOCK_BASE(B,T,H,Ra)
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
        #local block_pin_length = -1*(pin_length+pcb_height);
     #else
        #local block_pin_length = -5;
     #end

     #if (Ra=10.16)    //d=0.7mm
        cylinder { <-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.35 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,block_pin_length,0> 0.35 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<2.4,2.4,2.4> texture{col_black_marking} rotate<0,180,0> translate<B/2-2.5, H-6.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
     #end

     #if (Ra=15.24)    //d=0.8mm
        cylinder { <-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.40 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,block_pin_length,0> 0.40 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<3.0,3.0,3.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-4.0, H-7.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
     #end

     #if (Ra=22.5)    //d=0.8mm
        cylinder { <-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.40 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,block_pin_length,0> 0.40 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<3.5,3.5,3.5> texture{col_black_marking} rotate<0,180,0> translate<B/2-6.5, H-9.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
     #end

     #if (Ra=27.5)    //d=1.0mm
        cylinder { <-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.50 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,block_pin_length,0> 0.50 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<4.0,4.0,4.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-10.0, H-12.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
     #end

     #if (Ra=32.5)    //d=1.0mm
        cylinder { <-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.50 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,block_pin_length,0> 0.50 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<4.0,4.0,4.0> texture{col_black_marking} rotate<0,180,0> translate<B/2-10.0, H-12.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
     #end

     #if (Ra=37.5)    //d=1.0mm
        cylinder { <-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.50 texture{col_silver}}   // Draht rechts senkrecht
        cylinder { < Ra/2 ,0> < Ra/2,block_pin_length,0> 0.50 texture{col_silver}}   // Draht links senkrecht
        text { ttf besch_font  value   0.1, 0 scale<4.5,4.5,4.5> texture{col_black_marking} rotate<0,180,0> translate<B/2-15.0, H-15.0, T/2+0.1> rotate<0,0,0> } //Beschriftung Value
     #end

     texture {
        pigment {
           rgb<0.3,0.3,1>
           }
        finish {
           ambient (0.10 * global_ambient_mul)
           }
        }
     }
#end

#macro CAP_DIS_BLOCK_100_040_130_095(value)
  CAP_DIS_BLOCK_BASE(13.2, 4.2, 9.5, 10.16)
#end

#macro CAP_DIS_BLOCK_100_050_130_110(value)
  CAP_DIS_BLOCK_BASE(13.2, 5.3, 11.0, 10.16)
#end

#macro CAP_DIS_BLOCK_100_060_130_120(value)
  CAP_DIS_BLOCK_BASE(13.2, 6.3, 12.0, 10.16)
#end

#macro CAP_DIS_BLOCK_150_050_180_110(value)
  CAP_DIS_BLOCK_BASE(18.2,5.3,11.0,15.24)
#end

#macro CAP_DIS_BLOCK_150_060_180_125(value)
  CAP_DIS_BLOCK_BASE(18.2,6.3,12.5,15.24)
#end

#macro CAP_DIS_BLOCK_150_070_180_140(value)
  CAP_DIS_BLOCK_BASE(18.2,7.1,14.0,15.24)
#end

#macro CAP_DIS_BLOCK_150_080_180_150(value)
  CAP_DIS_BLOCK_BASE(18.2,8.3,15.0,15.24)
#end

#macro CAP_DIS_BLOCK_150_090_180_160(value)
  CAP_DIS_BLOCK_BASE(18.1,9.0,16.0,15.24)
#end

#macro CAP_DIS_BLOCK_225_060_265_150(value)
  CAP_DIS_BLOCK_BASE(26.7,6.1,15.0,22.5)
#end

#macro CAP_DIS_BLOCK_225_070_265_165(value)
  CAP_DIS_BLOCK_BASE(26.7,7.3,16.5,22.5)
#end

#macro CAP_DIS_BLOCK_225_085_265_185(value)
  CAP_DIS_BLOCK_BASE(26.7,8.6,18.5,22.5)
#end

#macro CAP_DIS_BLOCK_225_105_265_190(value)
  CAP_DIS_BLOCK_BASE(26.7,10.7,19.0,22.5)
#end

#macro CAP_DIS_BLOCK_225_110_265_210(value)
  CAP_DIS_BLOCK_BASE(26.7,11.2,21.0,22.5)
#end

#macro CAP_DIS_BLOCK_275_090_315_210(value)
  CAP_DIS_BLOCK_BASE(31.5,9.2,21.0,27.5)
#end

#macro CAP_DIS_BLOCK_275_110_315_210(value)
  CAP_DIS_BLOCK_BASE(31.5,11.2,21.0,27.5)
#end

#macro CAP_DIS_BLOCK_275_130_315_240(value)
  CAP_DIS_BLOCK_BASE(31.5,13.3,24.0,27.5)
#end

#macro CAP_DIS_BLOCK_275_150_315_260(value)
  CAP_DIS_BLOCK_BASE(31.5,15.1,26.0,27.5)
#end

#macro CAP_DIS_BLOCK_275_170_315_345(value)
  CAP_DIS_BLOCK_BASE(31.5,17.2,34.5,27.5)
#end

#macro CAP_DIS_BLOCK_275_200_315_395(value)
  CAP_DIS_BLOCK_BASE(31.5,20.4,39.5,27.5)
#end

#macro CAP_DIS_BLOCK_325_140_415_260(value)
  CAP_DIS_BLOCK_BASE(41.5,15.0,26.0,32.5)
#end

#macro CAP_DIS_BLOCK_325_160_415_320(value)
  CAP_DIS_BLOCK_BASE(41.5,19.0,32.0,32.5)
#end

#macro CAP_DIS_BLOCK_325_180_415_395(value)
  CAP_DIS_BLOCK_BASE(41.5,20.0,39.5,32.5)
#end

#macro CAP_DIS_BLOCK_375_150_415_260(value)
  CAP_DIS_BLOCK_BASE(41.7,15.4,26.0,37.5)
#end

#macro CAP_DIS_BLOCK_375_190_415_320(value)
  CAP_DIS_BLOCK_BASE(41.7,19.1,32.0,37.5)
#end

#macro CAP_DIS_BLOCK_375_200_415_395(value)
  CAP_DIS_BLOCK_BASE(41.7,20.2,39.5,37.5)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:C102-043X133=CAP_DIS_BLOCK_100_040_130_095(:THT cap grid 10.2mm outline 4.3x13.3mm
//rcl:C102-054X133=CAP_DIS_BLOCK_100_050_130_110(:THT cap grid 10.2mm outline 5.4x13.3mm
//rcl:C102-064X133=CAP_DIS_BLOCK_100_060_130_120(:THT cap grid 10.2mm outline 6.4x13.3mm
//rcl:C150-054X183=CAP_DIS_BLOCK_150_050_180_110(:THT cap grid 15mm outline 5.4x18.3mm
//rcl:C150-064X183=CAP_DIS_BLOCK_150_060_180_125(:THT cap grid 15mm outline 6.4x18.3mm
//rcl:C150-072X183=CAP_DIS_BLOCK_150_070_180_140(:THT cap grid 15mm outline 7.2x18.3mm
//rcl:C150-084X183=CAP_DIS_BLOCK_150_080_180_150(:THT cap grid 15mm outline 8.4x18.3mm
//rcl:C150-091X182=CAP_DIS_BLOCK_150_090_180_160(:THT cap grid 15mm outline 9.1x18.2mm
//rcl:C225-062X268=CAP_DIS_BLOCK_225_060_265_150(:THT cap grid 22.5mm outline 6.2x26.8mm
//rcl:C225-074X268=CAP_DIS_BLOCK_225_070_265_165(:THT cap grid 22.5mm outline 7.4x26.8mm
//rcl:C225-087X268=CAP_DIS_BLOCK_225_085_265_185(:THT cap grid 22.5mm outline 8.7x26.8mm
//rcl:C225-108X268=CAP_DIS_BLOCK_225_105_265_190(:THT cap grid 22.5mm outline 10.8x26.8mm
//rcl:C225-113X268=CAP_DIS_BLOCK_225_110_265_210(:THT cap grid 22.5mm outline 11.3x26.8mm
//rcl:C275-093X316=CAP_DIS_BLOCK_275_090_315_210(:THT cap grid 27.5mm outline 9.3x31.6mm
//rcl:C275-113X316=CAP_DIS_BLOCK_275_110_315_210(:THT cap grid 27.5mm outline 11.3x31.6mm
//rcl:C275-134X316=CAP_DIS_BLOCK_275_130_315_240(:THT cap grid 27.5mm outline 13.4x31.6mm
//rcl:C275-154X316=CAP_DIS_BLOCK_275_150_315_260(:THT cap grid 27.5mm outline 15.4x31.6mm
//rcl:C275-173X316=CAP_DIS_BLOCK_275_170_315_345(:THT cap grid 27.5mm outline 17.3x31.6mm
//rcl:C275-205X316=CAP_DIS_BLOCK_275_200_315_395(:THT cap grid 27.5mm outline 20.5x31.6mm
//rcl:C325-137X374=CAP_DIS_BLOCK_325_140_415_260(:THT cap grid 32.5mm outline 13.7x37.4mm
//rcl:C325-162X374=CAP_DIS_BLOCK_325_160_415_320(:THT cap grid 32.5mm outline 16.2x37.4mm
//rcl:C325-182X374=CAP_DIS_BLOCK_325_180_415_395(:THT cap grid 32.5mm outline 18.2x37.4mm
//rcl:C375-155X418=CAP_DIS_BLOCK_375_150_415_260(:THT cap grid 37.5mm outline 15.5x41.8 mm
//rcl:C375-192X418=CAP_DIS_BLOCK_375_190_415_320(:THT cap grid 37.5mm outline 19.2x41.8 mm
//rcl:C375-203X418=CAP_DIS_BLOCK_375_200_415_395(:THT cap grid 37.5mm outline 20.3x41.8 mm
// end assignment
