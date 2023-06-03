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
     difference {
        BevelHousing(A,8.80,8.80,
                     B,6.35,6.30,
                     0.15)
        box {
           <-4.5/2,2.0,-6.35/2+0.25>
           <+4.5/2,9.0,-8.80/2-0.10>
           }
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


