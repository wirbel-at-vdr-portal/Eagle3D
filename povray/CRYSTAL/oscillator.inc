/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * ASE series (ASEseries.pdf)
 * 3.3V CMOS compatible 3.2 x 2.5 mm SMD Crystal Oscillator
 * 20230325, wk
 ******************************************************************************/
#macro CRYSTAL_OSC_ASE()
union {
   object {
      Round_Box( <+2.8/2,+1.2,+2.0/2>,
                 <-2.8/2, 0.0,-2.0/2>,
                 0.25,0)
      texture { col_gold }
      }
   cylinder { <+2.0/2,+1.10,+1.1/2>
              <+2.0/2,+1.22,+1.1/2>
              0.1 rotate<0,180,0> translate<0,0,0>
              pigment { Black }
      }
   difference {
      union {
         box { <+3.2/2,+0.9,+2.5/2>
               <-3.2/2, 0.0,-2.5/2>
               pigment { Gray20 }
             }
         GRID_BASE( box { <+0.9/2,+0.2 ,+0.65/2> <-0.9/2,-0.01,-0.65/2> translate<0,0,+0.825> texture { col_silver }}, 2.1, 2,1)
         GRID_BASE( box { <+0.9/2,+0.2 ,+0.65/2> <-0.9/2,-0.01,-0.65/2> translate<0,0,-0.825> texture { col_silver }}, 2.1, 2,1)
         }

      GRID_BASE(cylinder { <0,-0.1,0> <0,2,0> 0.25 rotate<0,180,0> translate<0,0,+2.5/2> texture { col_silver }}, 3.2, 2,1)
      GRID_BASE(cylinder { <0,-0.1,0> <0,2,0> 0.25 rotate<0,180,0> translate<0,0,-2.5/2> texture { col_silver }}, 3.2, 2,1)
      GRID_BASE(box { <+0.5/2,-0.1,+0.2/2> <-0.5/2,+1.0,-0.2/2> }, 2.5, 1,2)
      }
   }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//crystal:ASE=CRYSTAL_OSC_ASE(:ASE series 3.2 x 2.5 mm SMD Crystal Oscillator
// end assignment

