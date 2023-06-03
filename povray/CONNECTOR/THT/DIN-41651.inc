/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * the most basic male DIN-41651 header.
 * 03.06.2023, -wk
 ******************************************************************************/
#macro DIN41651_M(CircuitSize)
  union {
     #local Grid = 2.54;
     #local Rows = 2;
     #local Cols = CircuitSize/Rows;
     #local C = (Cols-1)*Grid;
     #local A = C + 10.16;
     #local B = C + 7.86;
     #local D = (A - B)/2;
     #local E = (A + B)/2;
     #local F = 1.5;
     #local G = min(-(Cols - 1)/2 * Grid, -4.5/2 - F/2 - 0.5);
     #local H = 1;
     #if (CircuitSize > 59)
         #local H = 3;
     #end
     difference {
        BevelHousing(A,8.80,8.80,
                     B,6.35,6.30,
                     0.15)
        GRID(
           box {
              <-4.5/2,2.0,-6.35/2+0.25>
              <+4.5/2,9.0,-8.80/2-0.10>
              },
           22,H,1
           )
        GRID(
           box {
              <-D/2-0.25,-0.10,-Grid/2>
              <+D/2+0.25,+6.35,+Grid/2>
              },
           E,2,1
           )
        prism {
           8.7/2,9.0/2
           4,
           <G      , 8.5 - F>,
           <G - F/2, 8.5    >,
           <G + F/2, 8.5    >,
           <G      , 8.5 - F>
           rotate <-90,0,0>
           }
        translate <0,0.20,0>
        }
     GRID (
        union {
           cylinder {
             <0,0.30,+8.80/2>
             <0,8.90,+8.80/2>
             0.20
             }
           cylinder {
             <0,0.20,-8.80/2+0.1>
             <0,0.20,+8.80/2-0.1>
             0.20
             }
          },
          (B-Grid)/2,3,1
        )
     text {
        ttf global_fontfile_arial str(CircuitSize,0,0) 1, 0
        scale <1,1,0.5>
        rotate <90,0,0>
        translate <-0.5,2.35,-8.80/2+0.20>
        }

     GRID (
        object {
           PIN_STRAIGHT(0.64,8.30,0.5)
           texture {
              col_gold
              }
           },
        Grid,Cols,Rows
        )
     pigment {
        White * 0.82
        }
     }
#end

#macro DIN41651_M_THT(CircuitSize)
  union {
     #local Grid = 2.54;
     #local Rows = 2;
     #local Cols = CircuitSize/Rows;
     DIN41651_M(CircuitSize)
     GRID (
        object {
           PIN_STRAIGHT(0.64,2.0,3.0)
           texture {
              col_gold
              }
           },
        Grid,Cols,Rows
        )
     }
#end

#macro CON_THT_DIN41651_M06() DIN41651_M_THT(06) #end
#macro CON_THT_DIN41651_M08() DIN41651_M_THT(08) #end
#macro CON_THT_DIN41651_M10() DIN41651_M_THT(10) #end
#macro CON_THT_DIN41651_M12() DIN41651_M_THT(12) #end
#macro CON_THT_DIN41651_M14() DIN41651_M_THT(14) #end
#macro CON_THT_DIN41651_M16() DIN41651_M_THT(16) #end
#macro CON_THT_DIN41651_M20() DIN41651_M_THT(20) #end
#macro CON_THT_DIN41651_M24() DIN41651_M_THT(24) #end
#macro CON_THT_DIN41651_M26() DIN41651_M_THT(26) #end
#macro CON_THT_DIN41651_M30() DIN41651_M_THT(30) #end
#macro CON_THT_DIN41651_M34() DIN41651_M_THT(34) #end
#macro CON_THT_DIN41651_M40() DIN41651_M_THT(40) #end
#macro CON_THT_DIN41651_M44() DIN41651_M_THT(44) #end
#macro CON_THT_DIN41651_M50() DIN41651_M_THT(50) #end
#macro CON_THT_DIN41651_M60() DIN41651_M_THT(60) #end
#macro CON_THT_DIN41651_M64() DIN41651_M_THT(64) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
//con-ml:ML6=CON_THT_DIN41651_M06(:DIN-41651 straight
//con-ml:ML8=CON_THT_DIN41651_M08(:DIN-41651 straight
//con-ml:ML10=CON_THT_DIN41651_M10(:DIN-41651 straight
//con-ml:ML12=CON_THT_DIN41651_M12(:DIN-41651 straight
//con-ml:ML14=CON_THT_DIN41651_M14(:DIN-41651 straight
//con-ml:ML16=CON_THT_DIN41651_M16(:DIN-41651 straight
//con-ml:ML20=CON_THT_DIN41651_M20(:DIN-41651 straight
//con-ml:ML24=CON_THT_DIN41651_M24(:DIN-41651 straight
//con-ml:ML26=CON_THT_DIN41651_M26(:DIN-41651 straight
//con-ml:ML30=CON_THT_DIN41651_M30(:DIN-41651 straight
//con-ml:ML34=CON_THT_DIN41651_M34(:DIN-41651 straight
//con-ml:ML40=CON_THT_DIN41651_M40(:DIN-41651 straight
//con-ml:ML44=CON_THT_DIN41651_M44(:DIN-41651 straight
//con-ml:ML50=CON_THT_DIN41651_M50(:DIN-41651 straight
//con-ml:ML60=CON_THT_DIN41651_M60(:DIN-41651 straight
//con-ml:ML64=CON_THT_DIN41651_M64(:DIN-41651 straight
// end assignment
