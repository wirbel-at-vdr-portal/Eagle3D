/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * molex MILLIGRID 2mm pitch, SMT vertical shrouded header.
 * 20230325, wk
 ******************************************************************************/




/*******************************************************************************
 * SMT pin macro for 87832 series
 ******************************************************************************/
#macro CON_MOLEX_87832_pin()
  PIN_BENDED(0.5,        // pin width
             0.5,        // bending radius
             6.3,        // top
             0,          // bot
             1.85,       // pad len
             col_gold)   // colour
     rotate <180,180,0>
     translate <0,6.3+0.5/2,0>
#end

/*******************************************************************************
 * Molex 87832 base macro.
 * For meaning of CircuitSize, DualLock, CenterLock, SideSlot, CenterPol, Pegs,
 * A..H, see pdf drawing.
 ******************************************************************************/
#macro CON_MOLEX_87832(CircuitSize, DualLock, CenterLock, SideSlot, CenterPol, Pegs)
  #local A = CircuitSize + 2.65;
  #local B = CircuitSize + 0.85;
  #local C = CircuitSize - 2;
  #local F = CircuitSize + 1.00;
  #local H = 3.60;
  #if (CircuitSize < 14)
      #local D = 0.00;
      #local G = 0.10;
  #else
      #local D = CircuitSize - 6.00;
      #local G = 0.15;
  #end
  #if (CircuitSize < 6)
      #local E = 0.00;
  #else
      #local E = CircuitSize - 4.00;
  #end



  union {
    // pin rows
    GRID(object {CON_MOLEX_87832_pin() rotate<0,180,0> translate<0,0,+2/2>}, 2, CircuitSize/2,1)
    GRID(object {CON_MOLEX_87832_pin()                 translate<0,0,-2/2>}, 2, CircuitSize/2,1)

    union {
       #if (Pegs > 0)
          GRID(cylinder{<0,+7.6-4.6,0>
                        <0,      -1,0>
                        0.85/2},E,2,1)
       #end
       // Ribs inside.
       GRID(box{<+0.7/2,+7.6    ,+1/2>
                <-0.7/2,+7.6-4.6,-1/2>
                translate<0,0,+5/2>
                }, 2, CircuitSize/2,1)
       GRID(box{<+0.7/2,+7.6    ,+1/2>
                <-0.7/2,+7.6-4.6,-1/2>
                translate<0,0,+5/2>
                }, B, 2,1)
       GRID(box{<+0.7/2,+7.6    ,+1/2>
                <-0.7/2,+7.6-4.6,-1/2>
                translate<0,0,-5/2>
                }, B, 2,1)
       // top part of housing
       difference {
          union {
             box{<+A/2,+7.6    ,+6.3/2>
                 <-A/2,+7.6-4.7,-6.3/2>
                }

             } // union
          box{<+B/2,+7.7    ,+5/2>
              <-B/2,+7.6-3.9,-5/2>
             }
          #if (CenterLock > 0)
             box{<+2.2/2,+7.6-2.5,-4.9/2>
                 <-2.2/2,+7.6-4.8,-7/2>
                }
             box{<+2.6/2,+7.6-1.3,-4.9/2>
                 <+1.8/2,+7.6-4.8,-7/2>
                rotate<0,0,+2>
                }
             box{<-2.6/2,+7.6-1.3,-4.9/2>
                 <-1.8/2,+7.6-4.8,-7/2>
                rotate<0,0,-2>
                }
          #end

          #if (DualLock > 0)
             GRID(union {
                box{<+2.2/2,+7.6-2.5,-4.9/2>
                    <-2.2/2,+7.6-4.8,-7/2>
                   }
                box{<+2.6/2,+7.6-1.3,-4.9/2>
                    <+1.8/2,+7.6-4.8,-7/2>
                   rotate<0,0,+2>
                   }
                box{<-2.6/2,+7.6-1.3,-4.9/2>
                    <-1.8/2,+7.6-4.8,-7/2>
                   rotate<0,0,-2>
                   }
                },D,2,1)
          #end

          #if (CenterPol > 0)
             box{<+2.5/2,+7.7    ,-4.9/2>
                 <-2.5/2,+7.6-3.9,-7/2>
                }
          #end

          #if (SideSlot > 0)
             box{<+A/2+0.1,+7.7    ,1.5>
                 <+B/2-0.1,+7.6-3.9,0  >
                }
             box{<-A/2-0.1,+7.7    ,-1.5>
                 <-B/2+0.1,+7.6-3.9,0  >
                }
          #end

          // circuit identification mark
          #if (CircuitSize > 6)
             prism { -0.1, 0.1, 4
                     <-0.50, 0.00>, // first prism point
                     < 0.50, 0.00>, 
                     < 0.00,-1.50>,
                     <-0.50, 0.00>  // last prism point = first prism point !!!
                   rotate <-90,0,0>
                   translate<-2 * (CircuitSize/4-0.5),7.7,-6.3/2>
                   }
          #end

          } // end top part of housing

       // bot part of housing
       difference {
          box{<+F/2,+7.6-4.7,+4/2>
              <-F/2,    +1.2,-4/2>
             }
          GRID(box {<+1.5/2,+1.2+0.6,+6.3/2>
                    <-1.5/2,       0,-6.3/2>
                    }, 2, CircuitSize/2,1)
          } // end bot part of housing

       pigment{Gray50}//
       }
     }
#end







/*******************************************************************************
 * IMPORTANT!!!
 *
 * As there are way too much different versions of MOLEX 87832, only mechanical
 * different versions are modelled here. If you need, just include the most
 * perfect fitting variant.
 ******************************************************************************/


/*******************************************************************************
 * 4 circuits
 ******************************************************************************/

#macro CON_MOLEX_87832_0460()
  CON_MOLEX_87832(4,0,0,1,0,0)
#end

#macro CON_MOLEX_87832_0410()
  CON_MOLEX_87832(4,0,1,1,0,0)
#end


/*******************************************************************************
 * 6 circuits
 ******************************************************************************/

#macro CON_MOLEX_87832_0660()
  CON_MOLEX_87832(6,0,0,1,0,1)
#end

#macro CON_MOLEX_87832_0612()
  CON_MOLEX_87832(6,0,0,1,0,0)
#end

#macro CON_MOLEX_87832_0613()
  CON_MOLEX_87832(6,0,0,1,1,0)
#end

#macro CON_MOLEX_87832_0624()
  CON_MOLEX_87832(6,0,1,1,0,0)
#end

#macro CON_MOLEX_87832_0610()
  CON_MOLEX_87832(6,0,1,1,0,1)
#end

/*******************************************************************************
 * 8 to 12 circuits
 ******************************************************************************/

#macro CON_MOLEX_87832_0860()
  CON_MOLEX_87832(8,0,0,1,1,1)
#end

#macro CON_MOLEX_87832_0812()
  CON_MOLEX_87832(8,0,0,1,1,0)
#end

#macro CON_MOLEX_87832_0824()
  CON_MOLEX_87832(8,0,1,1,0,0)
#end

#macro CON_MOLEX_87832_0810()
  CON_MOLEX_87832(8,0,1,1,0,1)
#end

#macro CON_MOLEX_87832_1060()
  CON_MOLEX_87832(10,0,0,1,1,1)
#end

#macro CON_MOLEX_87832_1012()
  CON_MOLEX_87832(10,0,0,1,1,0)
#end

#macro CON_MOLEX_87832_1024()
  CON_MOLEX_87832(10,0,1,1,0,0)
#end

#macro CON_MOLEX_87832_1010()
  CON_MOLEX_87832(10,0,1,1,0,1)
#end

#macro CON_MOLEX_87832_1260()
  CON_MOLEX_87832(12,0,0,1,1,1)
#end

#macro CON_MOLEX_87832_1224()
  CON_MOLEX_87832(12,0,1,1,0,0)
#end

#macro CON_MOLEX_87832_1210()
  CON_MOLEX_87832(12,0,1,1,0,1)
#end

#macro CON_MOLEX_87832_1212()
  CON_MOLEX_87832(12,0,0,1,1,0)
#end

/*******************************************************************************
 * 14 to 50 circuits
 ******************************************************************************/

#macro CON_MOLEX_87832_1460()
  CON_MOLEX_87832(14,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_1412()
  CON_MOLEX_87832(14,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_1420() // the most wanted for me.
  CON_MOLEX_87832(14,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_1660()
  CON_MOLEX_87832(16,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_1612()
  CON_MOLEX_87832(16,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_1860()
  CON_MOLEX_87832(18,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_1812()
  CON_MOLEX_87832(18,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_2060()
  CON_MOLEX_87832(20,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_2012()
  CON_MOLEX_87832(20,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_2260()
  CON_MOLEX_87832(22,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_2460()
  CON_MOLEX_87832(24,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_2412()
  CON_MOLEX_87832(24,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_2660()
  CON_MOLEX_87832(26,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_2612()
  CON_MOLEX_87832(26,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_2860()
  CON_MOLEX_87832(28,1,0,1,1,1)
#end

/* 2816! - 2812 does not exist */
#macro CON_MOLEX_87832_2816()
  CON_MOLEX_87832(28,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_3060()
  CON_MOLEX_87832(30,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_3012()
  CON_MOLEX_87832(30,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_3260()
  CON_MOLEX_87832(30,1,0,1,1,1)
#end

/* 87832-3212 does not exist:
#macro CON_MOLEX_87832_3212()
  CON_MOLEX_87832(32,1,0,1,1,0)
#end
 */

#macro CON_MOLEX_87832_3460()
  CON_MOLEX_87832(34,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_3412()
  CON_MOLEX_87832(34,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_3660()
  CON_MOLEX_87832(36,1,0,1,1,1)
#end

/* 87832-3612 does not exist:
#macro CON_MOLEX_87832_3612()
  CON_MOLEX_87832(36,1,0,1,1,0)
#end
 */

#macro CON_MOLEX_87832_3860()
  CON_MOLEX_87832(38,1,0,1,1,1)
#end

/* 87832-3812 does not exist:
#macro CON_MOLEX_87832_3812()
  CON_MOLEX_87832(38,1,0,1,1,0)
#end
 */

#macro CON_MOLEX_87832_4060()
  CON_MOLEX_87832(40,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_4012()
  CON_MOLEX_87832(40,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_4260()
  CON_MOLEX_87832(42,1,0,1,1,1)
#end

/* 87832-4212 does not exist:
#macro CON_MOLEX_87832_4212()
  CON_MOLEX_87832(42,1,0,1,1,0)
#end
 */

#macro CON_MOLEX_87832_4460()
  CON_MOLEX_87832(44,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_4412()
  CON_MOLEX_87832(44,1,0,1,1,0)
#end

#macro CON_MOLEX_87832_4660()
  CON_MOLEX_87832(46,1,0,1,1,1)
#end

/* 87832-4612 does not exist:
#macro CON_MOLEX_87832_4612()
  CON_MOLEX_87832(46,1,0,1,1,0)
#end
 */

#macro CON_MOLEX_87832_4860()
  CON_MOLEX_87832(48,1,0,1,1,1)
#end

/* 87832-4812 does not exist:
#macro CON_MOLEX_87832_4812()
  CON_MOLEX_87832(48,1,0,1,1,0)
#end
 */

#macro CON_MOLEX_87832_5060()
  CON_MOLEX_87832(50,1,0,1,1,1)
#end

#macro CON_MOLEX_87832_5012()
  CON_MOLEX_87832(50,1,0,1,1,0)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=CON_MOLEX_87832_0460(:Molex 87832 series connector
//con-molex:87832-04=CON_MOLEX_87832_0410(:Molex 87832 series connector
//=CON_MOLEX_87832_0660(:Molex 87832 series connector
//=CON_MOLEX_87832_0612(:Molex 87832 series connector
//=CON_MOLEX_87832_0613(:Molex 87832 series connector
//=CON_MOLEX_87832_0624(:Molex 87832 series connector
//con-molex:87832-06=CON_MOLEX_87832_0610(:Molex 87832 series connector
//con-molex:87832-08=CON_MOLEX_87832_0860(:Molex 87832 series connector
//=CON_MOLEX_87832_0812(:Molex 87832 series connector
//=CON_MOLEX_87832_0824(:Molex 87832 series connector
//=CON_MOLEX_87832_0810(:Molex 87832 series connector
//con-molex:87832-10=CON_MOLEX_87832_1060(:Molex 87832 series connector
//=CON_MOLEX_87832_1012(:Molex 87832 series connector
//=CON_MOLEX_87832_1024(:Molex 87832 series connector
//=CON_MOLEX_87832_1010(:Molex 87832 series connector
//con-molex:87832-12=CON_MOLEX_87832_1260(:Molex 87832 series connector
//=CON_MOLEX_87832_1224(:Molex 87832 series connector
//=CON_MOLEX_87832_1210(:Molex 87832 series connector
//=CON_MOLEX_87832_1212(:Molex 87832 series connector
//con-molex:87832-14=CON_MOLEX_87832_1460(:Molex 87832 series connector
//=CON_MOLEX_87832_1412(:Molex 87832 series connector
//Molex - 87832-1420:MOLEX_87832-1420_0=CON_MOLEX_87832_1420(:Molex 87832 series connector
//con-molex:87832-16=CON_MOLEX_87832_1660(:Molex 87832 series connector
//=CON_MOLEX_87832_1612(:Molex 87832 series connector
//con-molex:87832-18=CON_MOLEX_87832_1860(:Molex 87832 series connector
//=CON_MOLEX_87832_1812(:Molex 87832 series connector
//con-molex:87832-20=CON_MOLEX_87832_2060(:Molex 87832 series connector
//=CON_MOLEX_87832_2012(:Molex 87832 series connector
//con-molex:87832-22=CON_MOLEX_87832_2260(:Molex 87832 series connector
//con-molex:87832-24=CON_MOLEX_87832_2460(:Molex 87832 series connector
//=CON_MOLEX_87832_2412(:Molex 87832 series connector
//con-molex:87832-26=CON_MOLEX_87832_2660(:Molex 87832 series connector
//=CON_MOLEX_87832_2612(:Molex 87832 series connector
//con-molex:87832-28=CON_MOLEX_87832_2860(:Molex 87832 series connector
//=CON_MOLEX_87832_2816(:Molex 87832 series connector
//con-molex:87832-30=CON_MOLEX_87832_3060(:Molex 87832 series connector
//=CON_MOLEX_87832_3012(:Molex 87832 series connector
//con-molex:87832-32=CON_MOLEX_87832_3260(:Molex 87832 series connector
//=CON_MOLEX_87832_3460(:Molex 87832 series connector
//=CON_MOLEX_87832_3412(:Molex 87832 series connector
//=CON_MOLEX_87832_3660(:Molex 87832 series connector
//=CON_MOLEX_87832_3860(:Molex 87832 series connector
//=CON_MOLEX_87832_4060(:Molex 87832 series connector
//=CON_MOLEX_87832_4012(:Molex 87832 series connector
//=CON_MOLEX_87832_4260(:Molex 87832 series connector
//=CON_MOLEX_87832_4460(:Molex 87832 series connector
//=CON_MOLEX_87832_4412(:Molex 87832 series connector
//=CON_MOLEX_87832_4660(:Molex 87832 series connector
//=CON_MOLEX_87832_4612(:Molex 87832 series connector
//=CON_MOLEX_87832_4860(:Molex 87832 series connector
//=CON_MOLEX_87832_5060(:Molex 87832 series connector
//=CON_MOLEX_87832_5012(:Molex 87832 series connector
// end assignment
