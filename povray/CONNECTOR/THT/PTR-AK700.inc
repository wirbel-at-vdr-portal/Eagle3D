/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * AK-700 PCB Terminal connector, 5.0mm pitch and 10.0mm pitch
 * original: Uwe Lorenz <u.lorenz@er-dresden.net> (2-pin 10mm pitch only)
 *
 * completly rewritten from scratch, 02.07.2023, -wk
 * - make it scalable
 * - different pitches
 * - fix a few dimensions
 * - use GRID()
 * - assign it to a lbr
 ******************************************************************************/
#macro AK700_V(Pitch, Pins)
  union {
     #if (Pitch = 5)
         #local Holes = Pins;
     #else
         #local Holes = (2*Pins - 1);
     #end
     #local X1 = Holes * 5.0;
     #local Y1 = +5.5;
     #local Y2 = -5;
     #local Y3 = Y1 - 2.0;
     #local Y4 = Y2 + 0.32;
     #local H1 = 19;
     #local H2 = 10;   // step
     #local H3 = 12.5; // chamfer
     #local W1 = 4;
     #local W2 = 2.8;
     #local dH = 3.6;
     #local chamfer = 0.2;
     #local Conn = prism {
        0, H3,
        5,
        <-0.5,-4.2>,
        <-0.5,-3.2>,
        < 0  ,-3.4>,
        < 0  ,-4.0>,
        <-0.5,-4.2>
        };
     // Grundkoerper
     difference {
        box {
           <-X1/2, 0,Y2>
           <+X1/2,H1,Y1>
           }
        //  vordere Schraege
        union {
           box {
              <-X1/2-0.1,12.8,-6.0>
              <+X1/2+0.1,20,-1.1>
              rotate<19,0,0> translate<0,0,-8>
              }
           box {
              <-X1/2-0.1,H3    ,Y2-0.1>
              <+X1/2+0.1,H1+0.1,Y4>
              }
           }
        //  hintere Kante
        box {
           <-X1/2-0.1,H2    ,Y3>
           <+X1/2+0.1,H1+0.1,Y1+0.1>
           }
        #local Hole = union {
           box {
              <-W1/2,3.9,Y2-0.1>
              <+W1/2,9.5,Y1-2.5>
              }
           ChamferBox(
              <-W1/2-chamfer,3.9-chamfer,Y2-chamfer>
              <+W1/2+chamfer,9.5+chamfer,Y2+chamfer>
              chamfer
              )
           box {
              <-W2/2,     6,Y4    >
              <+W2/2,H2+0.1,Y1+0.1>
              }
           cylinder {
              <0,4     ,0>
              <0,H1+0.1,0>
              dH/2
              }
           };
        GRID(Hole,5.0,Holes,1)
        // Nut an der rechten Seite
        object {
           Conn
           translate <+X1/2+0.03,0,0>
           }
        }
     // Steg an der linken Seite
     object {
        Conn
        translate <-X1/2,0,0>
        }
     union {
        // Kaefigzugklemme mit Pin und Schraube
        #local KL = union {
           Round_Box (
              <-W2/2,     6,Y1-2.0>
              <+W2/2,H2-1.0,Y1-1.0>
              0.1 0
              )
           object {
              Round_Box (
                 <-1/2,-2/2,Y1-1.5>
                 <+1/2,+2/2,Y1-0.5>
                 0.1 0
                 )
              rotate <-20,0,0>
              translate <0,5,0>
              }
           object {
              TOOLS_SCREW(1.6,3,0,Silver)
              translate <0,17.5,0>
              }
           difference {
              box {
                 <-W1/2-0.0,3.0,Y2+1.0>
                 <+W1/2+0.0,9.8,Y1-1.0>
                 }
              box {
                 <-W1/2+0.1,4.0,Y2+0.5>
                 <+W1/2-0.1,9.5,Y1-2.6>
                 }
              }
           cylinder {
              <-2/2,9,-3.3>
              <+2/2,9,-3.3>
              1.0
              }
           box {
              <-W1/2+0.3,9-1,-3.3>
              <+W1/2-0.3,9+1,2>
              }
           PIN_STRAIGHT(0.9,1.5,4)
           };
        GRID(KL, Pitch, Pins, 1)
        texture {
           col_silver
           }
        }
     pigment {
        rgb <97,153,59> / 255 // RAL6018
        }
     rotate <0,180,0>
     }
#end


/* Pins|Grid| Part               | Art-No
 *    2|  5 |AK700/2-5.0-V-GREEN |50700020201
 *    3|  5 |AK700/3-5.0-V-GREEN |50700030201
 *    4|  5 |AK700/4-5.0-V-GREEN |50700040201
 *    5|  5 |AK700/5-5.0-V-GREEN |50700050201
 *    6|  5 |AK700/6-5.0-V-GREEN |50700060201
 *    7|  5 |AK700/7-5.0-V-GREEN |50700070201
 *    8|  5 |AK700/8-5.0-V-GREEN |50700080201
 *    9|  5 |AK700/9-5.0-V-GREEN |50700090201
 *   10|  5 |AK700/10-5.0-V-GREEN|50700100201
 *   11|  5 |AK700/11-5.0-V-GREEN|50700110201
 *   12|  5 |AK700/12-5.0-V-GREEN|50700120201
 *    2| 10 |AK700/2-10.0-V-GREEN|50700020241
 *    3| 10 |AK700/3-10.0-V-GREEN|50700030241
 *    4| 10 |AK700/4-10.0-V-GREEN|50700040241
 *    5| 10 |AK700/5-10.0-V-GREEN|50700050241
 *    6| 10 |AK700/6-10.0-V-GREEN|50700060241
 */
#macro CON_THT_PTR_AK700_50700020201() AK700_V(05,02) #end
#macro CON_THT_PTR_AK700_50700030201() AK700_V(05,03) #end
#macro CON_THT_PTR_AK700_50700040201() AK700_V(05,04) #end
#macro CON_THT_PTR_AK700_50700050201() AK700_V(05,05) #end
#macro CON_THT_PTR_AK700_50700060201() AK700_V(05,06) #end
#macro CON_THT_PTR_AK700_50700070201() AK700_V(05,07) #end
#macro CON_THT_PTR_AK700_50700080201() AK700_V(05,08) #end
#macro CON_THT_PTR_AK700_50700090201() AK700_V(05,09) #end
#macro CON_THT_PTR_AK700_50700100201() AK700_V(05,10) #end
#macro CON_THT_PTR_AK700_50700110201() AK700_V(05,11) #end
#macro CON_THT_PTR_AK700_50700120201() AK700_V(05,12) #end
#macro CON_THT_PTR_AK700_50700020241() AK700_V(10,02) #end
#macro CON_THT_PTR_AK700_50700030241() AK700_V(10,03) #end
#macro CON_THT_PTR_AK700_50700040241() AK700_V(10,04) #end
#macro CON_THT_PTR_AK700_50700050241() AK700_V(10,05) #end
#macro CON_THT_PTR_AK700_50700060241() AK700_V(10,06) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-ptr-AK700:AK700/2-5.0-V-GREEN=CON_THT_PTR_AK700_50700020201(:PCB terminal AK700
//con-ptr-AK700:AK700/3-5.0-V-GREEN=CON_THT_PTR_AK700_50700030201(:PCB terminal AK700
//con-ptr-AK700:AK700/4-5.0-V-GREEN=CON_THT_PTR_AK700_50700040201(:PCB terminal AK700
//con-ptr-AK700:AK700/5-5.0-V-GREEN=CON_THT_PTR_AK700_50700050201(:PCB terminal AK700
//con-ptr-AK700:AK700/6-5.0-V-GREEN=CON_THT_PTR_AK700_50700060201(:PCB terminal AK700
//con-ptr-AK700:AK700/7-5.0-V-GREEN=CON_THT_PTR_AK700_50700070201(:PCB terminal AK700
//con-ptr-AK700:AK700/8-5.0-V-GREEN=CON_THT_PTR_AK700_50700080201(:PCB terminal AK700
//con-ptr-AK700:AK700/9-5.0-V-GREEN=CON_THT_PTR_AK700_50700090201(:PCB terminal AK700
//con-ptr-AK700:AK700/10-5.0-V-GREEN=CON_THT_PTR_AK700_50700100201(:PCB terminal AK700
//con-ptr-AK700:AK700/11-5.0-V-GREEN=CON_THT_PTR_AK700_50700110201(:PCB terminal AK700
//con-ptr-AK700:AK700/12-5.0-V-GREEN=CON_THT_PTR_AK700_50700120201(:PCB terminal AK700
//con-ptr-AK700:AK700/2-10.0-V-GREEN=CON_THT_PTR_AK700_50700020241(:PCB terminal AK700
//con-ptr-AK700:AK700/3-10.0-V-GREEN=CON_THT_PTR_AK700_50700030241(:PCB terminal AK700
//con-ptr-AK700:AK700/4-10.0-V-GREEN=CON_THT_PTR_AK700_50700040241(:PCB terminal AK700
//con-ptr-AK700:AK700/5-10.0-V-GREEN=CON_THT_PTR_AK700_50700050241(:PCB terminal AK700
//con-ptr-AK700:AK700/6-10.0-V-GREEN=CON_THT_PTR_AK700_50700060241(:PCB terminal AK700
// end assignment
