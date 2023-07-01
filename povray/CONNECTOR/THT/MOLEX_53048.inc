/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Molex 53048
 * 1.25 pitch, horizontal
 *
 * 30.06.2023, wk
 ******************************************************************************/
#macro Molex53048(Pins)
  union {
     #local L = Pins * 1.25 + 1.75;
     difference {
        #local l = 3.2;
        object {
           Molex53047(Pins)
           rotate <90,0,0>
           translate <0,l/2 + 0.3,-1>
           }
        box {
           <-L/2-0.1,+1.0,-5>
           <+L/2+0.1,+4.5,-1.1>
           }
        }
     #local C = prism {
        0.3, 1.3,
        5,
        <-(1.25-0.4)/2,0>,
        <+(1.25-0.4)/2,0>,
        <+(1.25-0.7)/2,-1>,
        <-(1.25-0.7)/2,-1>,
        <-(1.25-0.4)/2,0>
        translate <0,0,-0.70>
        };
     GRID(C, 1.25, Pins+1, 1)

     #local w = 0.6;
     #local standoff = difference {
        Round_Box (
           <-w/2,  0, -2.3>
           <+w/2,2.5, +3.2>
           0.1 0
           )
        box {
           <-w/2-0.1,-1, -3>
           <+w/2+0.1,+1, +3>
           rotate <-30,0,0>
           translate <0,3.0,-2>
           }
        };
     GRID(standoff,L-w,2,1)
     #local pin = object {
        PIN_90deg(0.32,1.0/2,1.425 + 0.32/2,2.3,1)
        rotate <0,180,0>
        translate <0,0,-1.25>
        texture {
           col_gold
           }
        };
     GRID(pin, 1.25, Pins, 1)
     texture {
        col_nylon
        }
     }
#end


#macro CON_THT_MOLEX_53048_02() Molex53048( 2) #end
#macro CON_THT_MOLEX_53048_03() Molex53048( 3) #end
#macro CON_THT_MOLEX_53048_04() Molex53048( 4) #end
#macro CON_THT_MOLEX_53048_05() Molex53048( 5) #end
#macro CON_THT_MOLEX_53048_06() Molex53048( 6) #end
#macro CON_THT_MOLEX_53048_07() Molex53048( 7) #end
#macro CON_THT_MOLEX_53048_08() Molex53048( 8) #end
#macro CON_THT_MOLEX_53048_09() Molex53048( 9) #end
#macro CON_THT_MOLEX_53048_10() Molex53048(10) #end
#macro CON_THT_MOLEX_53048_11() Molex53048(11) #end
#macro CON_THT_MOLEX_53048_12() Molex53048(12) #end
#macro CON_THT_MOLEX_53048_13() Molex53048(13) #end
#macro CON_THT_MOLEX_53048_14() Molex53048(14) #end
#macro CON_THT_MOLEX_53048_15() Molex53048(15) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-molex:53048-02=CON_THT_MOLEX_53048_02(:Molex 53048
//con-molex:53048-03=CON_THT_MOLEX_53048_03(:Molex 53048
//con-molex:53048-04=CON_THT_MOLEX_53048_04(:Molex 53048
//con-molex:53048-05=CON_THT_MOLEX_53048_05(:Molex 53048
//con-molex:53048-06=CON_THT_MOLEX_53048_06(:Molex 53048
//con-molex:53048-07=CON_THT_MOLEX_53048_07(:Molex 53048
//con-molex:53048-08=CON_THT_MOLEX_53048_08(:Molex 53048
//con-molex:53048-09=CON_THT_MOLEX_53048_09(:Molex 53048
//con-molex:53048-10=CON_THT_MOLEX_53048_10(:Molex 53048
//con-molex:53048-11=CON_THT_MOLEX_53048_11(:Molex 53048
//con-molex:53048-12=CON_THT_MOLEX_53048_12(:Molex 53048
//con-molex:53048-13=CON_THT_MOLEX_53048_13(:Molex 53048
//con-molex:53048-14=CON_THT_MOLEX_53048_14(:Molex 53048
//con-molex:53048-15=CON_THT_MOLEX_53048_15(:Molex 53048
// end assignment
