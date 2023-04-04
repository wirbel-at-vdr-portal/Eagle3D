/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Avago HFBR-x4x4TZ transmitter/receiver with ST connector.
 * wk
 ******************************************************************************/
#macro HFBR_x4x4(value)
  union {
     union {
        object {
           Round_Box(<-12.7/2, 0  ,-(3.81+2.54)     >,
                     < 12.7/2,10.2,-(3.81+2.54)+12.7>,
                     1.0, 0)
           }
        difference {
           union {
              object  {
                 Round_Cylinder(< 0,5.1,-(3.81+2.54)>,
                                < 0,5.1,-(3.81+2.54) +12.7 - 27.1>,
                                7.1/2, 0.5, 0)
                 }
           cylinder {
              <-8.4/2, 5.1,-15>
              < 8.4/2, 5.1,-15>
              1.5/2
              }
           union { // Gewinde
              cylinder { <0,5.1, -7.2>,<0,5.1, -7.5>, 9.4/2 }
              cylinder { <0,5.1, -7.8>,<0,5.1, -8.1>, 9.4/2 }
              cylinder { <0,5.1, -8.4>,<0,5.1, -8.7>, 9.4/2 }
              cylinder { <0,5.1, -9.0>,<0,5.1, -9.3>, 9.4/2 }
              cylinder { <0,5.1, -9.6>,<0,5.1, -9.9>, 9.4/2 }
              cylinder { <0,5.1,-10.2>,<0,5.1,-10.5>, 9.4/2 }
              cylinder { <0,5.1,-10.8>,<0,5.1,-11.1>, 9.4/2 }
              rotate <0,-1,-1>
              translate<-0.25,-0.25,0>
              }
           }
        object {
           Round_Cylinder(
              < 0,5.1,-(3.81+2.54) -1>,
              < 0,5.1,-(3.81+2.54) +12.7 - 27.1 -1>,
              5.5/2, 0.5, 0)
           }
        box {
           <-1/2,-20, -14.8>
           < 1/2, 20, -20.8>
           }
        cylinder {
           < 0,-20, -14.8>
           < 0, 20, -14.8>
           1.0/2
           }
        }
     texture {
        pigment {
           color rgb <0.721,0.686,0.651>
           }
        finish {
           phong 0.4
           }
        }
     }
  union {
     cylinder { <-2.54/2,0, 0  > <-2.54/2,-3.6, 0  > 0.46/2 }
     cylinder { <+2.54/2,0, 0  > <+2.54/2,-3.6, 0  > 0.46/2 }
     cylinder { <-2.54/2,0,2.54> <-2.54/2,-3.6,2.54> 0.46/2 }
     cylinder { <+2.54/2,0,2.54> <+2.54/2,-3.6,2.54> 0.46/2 }
     box { <-7.62/2 - 0.51/2,0,-0.38/2>  <-7.62/2 + 0.51/2,-3.6,+0.38/2> }
     box { <+7.62/2 - 0.51/2,0,-0.38/2>  <+7.62/2 + 0.51/2,-3.6,+0.38/2> }
     box { <-7.62/2 - 0.51/2,0,2.54-0.38/2>  <-7.62/2 + 0.51/2,-3.6,2.54+0.38/2> }
     box { <+7.62/2 - 0.51/2,0,2.54-0.38/2>  <+7.62/2 + 0.51/2,-3.6,2.54+0.38/2> }
     texture {
        Gold_Metal
        finish {
           phong 0.1
           }
        scale 0.5 }
        }
     text { ttf global_fontfile_arial "AVAGO" 0.2, 0 scale 1.8 rotate<90,0,0> translate<-3.5,10.22,2.6> }
     text { ttf global_fontfile_arial value   0.2, 0 scale 1.5 rotate<90,0,0> translate<-5,10.22,-1> }
     }
// end: HFBR_x4x4
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//fiber-optic-hp:HFBR-X41XT=SPC_OPTO_HFBR_x4x4(:Avago HFBR-x4x4TZ transmitter/receiver with ST connector
// end assignment
