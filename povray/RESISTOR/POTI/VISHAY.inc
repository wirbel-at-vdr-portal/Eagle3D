/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Vishay T18 Resistor Trimmer
 * wk
 ******************************************************************************/
#macro R_POTI_SP19L(value)
  union {
  #local VishayBlue = color red 0.0 green 0.4453 blue 0.73;

  difference {
     cylinder {
        <-8.25,4.8,0> <-9.75,4.8,0> 1.25
        }
     box {
        <-9.15,5.1,-2> <-10,4.5,+2>
        }   
     texture {
        T_Brass_2A
        }
     }
  difference {
     box {
        <-8.25    ,   0,-2.35>       <+10.75    ,+6.4,+2.35>
        }  // case
     box {
        <-8.25+0.8,-0.1,-2.36>       <+10.75-0.8,+0.5,+2.36>
        }       
     pigment {
        VishayBlue
        }
     }

   #local hpin = -min(4.5,(pin_length+pcb_height));

   union {
      text {
         ttf global_fontfile_arial "T18" 0.1, 0
         scale 2
         rotate <90,180,0>
         translate <+8,6.45,-0.4>
         }
      text {
         ttf global_fontfile_arial value 0.1, 0
         scale 2
         rotate <90,180,0>
         translate <+8,6.45,+1.6>
         }
      text {
         ttf global_fontfile_arial "3" 0.1, 0
         scale 2
         rotate <90,180,0>
         translate <-5,6.45,-0.4>
         }
      text {
         ttf global_fontfile_arial "0302" 0.1, 0
         scale 2
         rotate <90,180,0>
         translate <-1.8,6.45,+1.6>
         }
      text {
         ttf global_fontfile_eagle3d "0" 0.1, 0
         scale 2
         rotate <90,180,0>
         translate <+2,6.45,-0>
         }
      pigment{Black}
      }
   scale x*19/18
   translate <-2,0,0>
   }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//pot:SP19L=R_POTI_SP19L(:Vishay T18 Resistor Trimmer
// end assignment
