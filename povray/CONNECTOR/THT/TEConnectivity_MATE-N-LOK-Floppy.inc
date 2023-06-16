/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TE connectivity 350211, 4-pol Floppy connector
 *
 * 16.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_MATE_N_LOK_Floppy()
  union {
     #local L1 = 23.24;
     #local L2 = 25.40;
     #local B1 = 8.26;
     #local B2 = 9.65;
     #local H1 = 0.76;
     #local H2 = 9.53;
     #local H3 = 3.6;
     difference {
        merge {
           Round_Box (
              <-L1/2,0.5,-B1/2>
              <+L1/2, H2,+B1/2>
              0.5 0
              )
           object {
              #local b = 1.0;
              GRID (
                 box {
                    <-b/2,H1,        0 >
                    <+b/2,H3,-(B2-B1/2)>
                    },
                 5.08,5,1
                 )
              translate <-1,0,0>
              }
           object {
              GRID (
                 box {
                    <-4.5/2, 0,-H1/2>
                    <+4.5/2,H1,+H1/2>
                    },
                 B1-H1,2,2
                 )
              scale x*1.8
              }
           GRID (
              box {
                 <-(L2-L1)/4,H1,-H3/2>
                 <+(L2-L1)/4,H3,+H3/2>
                 },
              L1+(L2-L1)/2,2,1
              )
           }
        merge {
           box {
              <-L1/2, 0,-B1/2>
              <+L1/2,H1,+B1/2>
              }
           difference {
              #local Wall = 1.0;
              box {
                 <-(L1-Wall)/2,H1+2.0,-(B1-Wall)/2>
                 <+(L1-Wall)/2,H2+0.1,+(B1-Wall)/2>
                 }
              #local cut = box {
                 <-3.8/2,H1+2.1,-3.8/2>
                 <+3.8/2,H2+0.2,+3.8/2>
                 rotate y*45
                 translate <0,0,B1/2>
                 };
              GRID(cut,L1,2,1)
              }
           #local CylindricalHole = cylinder {
              <0,H1+1.5,0>
              <0,H1+2.2,0>
              3/2
              };
           GRID(CylindricalHole,5.08,4,1)
           }
        texture {
           col_nylon
           }
        }
     #local pin = difference {
        union {
           Round_Cylinder (
              <0,H1+1.0,0>
              <0,H2-1.8,0>
              2.05/2
              2.00/2 0
              )
           object {
              PIN_STRAIGHT(1.0,2,(4.57+3.81)/2)
              texture {
                 col_silver
                 }
              }
           }
        ROTATE (
           box {
              <0,H1+1,+0.15/2>
              <2,H2  ,-0.15/2>
              },
           3,120
           )
        texture {
           col_gold
           }
        };
     GRID(pin,5.08,4,1)
     }
#end


#macro CON_THT_MATE_N_LOK_Floppy_R180()
   object {
      CON_THT_MATE_N_LOK_Floppy()
      rotate y*180
      }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//350211=CON_THT_MATE_N_LOK_Floppy_R180(:MATE-N-LOK Floppy connector
//FLOPPY-4=CON_THT_MATE_N_LOK_Floppy(:MATE-N-LOK Floppy connector
// end assignment
