/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Monacor PG203JN stereo microphone/headphone jack
 * original by ChristophGraf@web.de 
 *
 * complete rework, 27.06.2023, -wk
 *  - correct dimensions as per datasheet, not by pcb layout.
 *  - introduce variables
 *  - replace lathe for thread by a screw
 *  - replace inner contacts
 *  - replace cylindric pins by real pins
 *  (...)
 *
 * https://www.monacor.com/products/components/
 *         cables-and-plug-in-connectors/plugs-and-inline-jacks/pg-203jn/
 *
 * NOTE: library package is slightly off at the pins, compared to drawing.
 ******************************************************************************/
#macro CON_THT_StereoJack_PG203JN(value)
  union {
     #local w = 0.7;
     #local X1 = 17.8 - 3.5;
     #local X2 = 3.5;
     #local X3 = X1 - 2*w;
     #local Y1 = 11.5;
     #local Y2 = Y1 - 2*w;
     #local H1 = 6;
     #local H2 = 1;
     #local H3 = H1 - H2;
     union {
        difference {
           Round_Box (
              <-X1/2, 0,-Y1/2>
              <+X1/2,H3,+Y1/2>
              0.2 0
              )
           box {
              <-X3/2+1,     w,-Y2/2>
              <+X3/2  ,H3+0.1,+Y2/2>
              }
           cylinder {
              <-X1/2-1,H1/2,-0.3>
              <-X1/2+3,H1/2,-0.3>
              5.0/2
              }
           }
        Round_Box ( <-X1/2+1,  4,-4.6> <-X1/2+1,6.5,-4.6> 1.2/2 0 )
        Round_Box ( <-X1/2+1,  4,+4.6> <-X1/2+1,6.5,+4.6> 1.2/2 0 )
        Round_Box ( <+X1/2-2,0.1,   0> <+X1/2-2,6.5,   0> 1.2/2 0 )
        pigment {
           White * 0.1
           }
        }
     object {
        Round_Box (
           <-X1/2,H3+0.1,-Y1/2>
           <+X1/2,H1    ,+Y1/2>
           0.1 1
           )
        pigment {
           rgbf <1,1,1.05, 0.81>
           }
        }
     difference {
        object {
           TOOLS_SCREW(6,9,-1,Silver)
           scale y*0.5 // NOTE: M6x1 -> M6x0.5
           rotate <-90,-90,0>
           translate <-X1/2+1,H1/2,0>
           }
        cylinder {
           <-X1/2+2     ,H1/2,0>,
           <-X1/2-X2-0.1,H1/2,0>,
           3.6/2
           }
        translate <0,0,-0.3>
        pigment {
           Silver
           }
        }
     difference {
        Round_Cylinder (
           <0,-1.4/2,0>
           <0,+1.4/2,0>
           8.0/2 0.2 0
           )
        cylinder {
           <0,-1.5/2,0>
           <0,+1.5/2,0>
           5.8/2
           }
        box {
           <-9/2,-1.0,-0.7/2>
           <+9/2,-0.3,+0.7/2>
           rotate y*10
           }
        #local n = 20;
        ROTATE (
           cylinder {
              <+8/2,-1.5,0>
              <+8/2,+1.5,0>
              1/2
              },
           n,360/n
           )
        rotate <-90,-90,0>
        translate <-X1/2-1.5,H1/2,0>
        translate <0,0,-0.3>
        pigment {
           Silver
           }
        }
     #local pin = union {
        box {
           <-1.3/2,       1,-0.4/2>
           <+1.3/2,-3+1.3/2,+0.4/2>
           }
        cylinder {
           <0,-3+1.3/2,-0.4/2>
           <0,-3+1.3/2,+0.4/2>
           1.3/2
           }
        texture {
           col_silver
           }
        };
     union {
        object { pin rotate <0,90,0> translate <-X1/2+1.7        ,0,0       > }
        object { pin rotate <0,90,0> translate <-X1/2+5.2+7.8    ,0,-4.3    > }
        object { pin rotate <0, 0,0> translate <-X1/2+1.7+6.8    ,0,+5.6-2.9> }
        object { pin rotate <0, 0,0> translate <-X1/2+1.7+6.8+1.7,0,+5.6    > }
        object { pin rotate <0, 0,0> translate <-X1/2+5.2        ,0,-4.6    > }
        translate <0,0,-0.3>
        }
     union {
        object { BENT_PLANE_OUTER(4  ,8  ,3.5,0.4,0.8/2,  6) rotate <90,180,0> translate <+6.5,2.5,  +5> }
        object { BENT_PLANE_OUTER(2.5,2.0,3.5,0.4,1.5/2, 60) rotate <90,-60,0> translate <-2.3,2.5,+0.7> }
        object { BENT_PLANE_OUTER(4  ,4.6  ,3.5,0.4,0.8/2,8) rotate <90,  0,0> translate <-5.5,2.5,-4.8> }
        object { BENT_PLANE_OUTER(2.2,2.0,3.5,0.4,1.0/2,100) rotate <90,140,0> translate < 0.4,2.5,-1.3> }
        box {
           <-4/2,1.0,-0.4/2>
           <+4/2,4.0,+0.4/2>
           rotate y*-3
           translate <3.4,0.25,-2.6>
           }
        object { BENT_PLANE_OUTER(2.2,3.0,4.5,0.4,1.0/2, 90) rotate <0,+90,0> translate < 1.4,0.65,+2.7> }
        object { BENT_PLANE_OUTER(3.2,3.0,2.5,0.4,1.0/2, 90) rotate <0,-90,0> translate < 5.4,0.65,-2.3> }
        pigment {
           Silver
           }
        }
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-hirschmann:PG203J=CON_THT_StereoJack_PG203JN(:3.5 mm stereo panel jack PG203JN
// end assignment
