/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Molex 53047
 * 1.25 pitch, vertical feeding, through holes
 * antoine.drouin@free.fr
 *
 * 29.06.2023, modified, wk
 *  - change pin shape and fix position
 *  - use PIN_STRAIGHT and GRID
 *  - assign to eagle libs
 *  - chamfered edges
 *  - outer shape Round_Box
 *  - change color
 *  - rotate by 180deg
 ******************************************************************************/
#macro Molex53047(Pins)
  union {
     #local L = Pins * 1.25 + 1.75;
     #local l = 3.2;
     #local h = 4.2;
     difference {
        Round_Box (
           <-L/2, 0, -l/2>
           <+L/2, h, +l/2>
           0.1 0
           )
        #local chamfer = 0.3;
        ChamferBox(
           <-L/2+chamfer, h-chamfer, -l/2+chamfer>
           <+L/2-chamfer, h+chamfer, +l/2-chamfer>
           chamfer
           )
        box {
           <-L/2+0.6, 1.3, -l/2+0.45> <L/2-0.6, h+0.1, l/2-0.45>
           }
        box {
           <-L/2+1, 2.7, 0> <L/2-1, h+0.1, l/2+0.1>
           }
        box {
           <-L/2+0.35, 1.31, -0.35> <L/2-0.35, h+0.1, 0.35>
           }
        box {
           <-L/2-0.1, 3.21, l/2-0.46> <L/2+0.1, h+0.1, l/2+0.1>
           }
        #local j = 0;
        #while(j<Pins)
           box {
              <-0.35, -0.1, -l/2-0.1>
              <+0.35,  0.3, +l/2+0.1>
              translate < -(Pins-1)*1.25/2+j*1.25, 0, 0>
              }
           #local j = j + 1;
        #end
        box {
           <-L/2+1.6, 1.6, -l/2+0.46> <-L/2+2.9, 2.9, -l/2-0.1>
           }
        box {
           <L/2-1.6, 1.6, -l/2+0.46> <L/2-2.9, 2.9, -l/2-0.1>
           }
        texture {
           col_nylon
           }
        }
     #local pin = union {
        object {
           PIN_STRAIGHT(0.32,2.25/2,1.5/2)
           scale <1,2,2.5>
           translate <0,1.5,-0.475>
           }
        object {
           PIN_STRAIGHT(0.32,1.50,2.3)
           translate <0,0,-0.475>
           }
        texture {
           col_gold
           }
        }
     GRID(pin,1.25,Pins,1)
     rotate <0,180,0>
     }
#end


#macro CON_THT_MOLEX_53047_02() Molex53047( 2) #end
#macro CON_THT_MOLEX_53047_03() Molex53047( 3) #end
#macro CON_THT_MOLEX_53047_04() Molex53047( 4) #end
#macro CON_THT_MOLEX_53047_05() Molex53047( 5) #end
#macro CON_THT_MOLEX_53047_06() Molex53047( 6) #end
#macro CON_THT_MOLEX_53047_07() Molex53047( 7) #end
#macro CON_THT_MOLEX_53047_08() Molex53047( 8) #end
#macro CON_THT_MOLEX_53047_09() Molex53047( 9) #end
#macro CON_THT_MOLEX_53047_10() Molex53047(10) #end
#macro CON_THT_MOLEX_53047_11() Molex53047(11) #end
#macro CON_THT_MOLEX_53047_12() Molex53047(12) #end
#macro CON_THT_MOLEX_53047_13() Molex53047(13) #end
#macro CON_THT_MOLEX_53047_14() Molex53047(14) #end
#macro CON_THT_MOLEX_53047_15() Molex53047(15) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-molex:53047-02=CON_THT_MOLEX_53047_02(:Molex 53047
//con-molex:53047-03=CON_THT_MOLEX_53047_03(:Molex 53047
//con-molex:53047-04=CON_THT_MOLEX_53047_04(:Molex 53047
//con-molex:53047-05=CON_THT_MOLEX_53047_05(:Molex 53047
//con-molex:53047-06=CON_THT_MOLEX_53047_06(:Molex 53047
//con-molex:53047-07=CON_THT_MOLEX_53047_07(:Molex 53047
//con-molex:53047-08=CON_THT_MOLEX_53047_08(:Molex 53047
//con-molex:53047-09=CON_THT_MOLEX_53047_09(:Molex 53047
//con-molex:53047-10=CON_THT_MOLEX_53047_10(:Molex 53047
//con-molex:53047-11=CON_THT_MOLEX_53047_11(:Molex 53047
//con-molex:53047-12=CON_THT_MOLEX_53047_12(:Molex 53047
//con-molex:53047-13=CON_THT_MOLEX_53047_13(:Molex 53047
//con-molex:53047-14=CON_THT_MOLEX_53047_14(:Molex 53047
//con-molex:53047-15=CON_THT_MOLEX_53047_15(:Molex 53047
// end assignment
