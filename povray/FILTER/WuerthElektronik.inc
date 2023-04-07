/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMT common-mode line filter Wuerth Elektronik WE-SL2 
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0 13/04/06
 ******************************************************************************/
#macro FILTER_WE_SL2(value)
  union {
    difference {
       superellipsoid {
          <0.05, 0.05>
          scale <4.6, 2.5,3>
          translate <0, 2.5, 0>
          }
       box {
          <-4.7, -0.1, -4>, <+4.7, 1, 4>
          }
       box {
          <-4.7, -0.1, -3>, <+4.7, 1.4, -2.8>
          }
       box {
          <-4.7, -0.1, +3>, <+4.7, 1.4, +2.8>
          }
       text { // Marking
          ttf global_fontfile_arial value 0.2, 0
          pigment {
             Black
             }
          scale 3
          rotate <90,0,0>
          translate <-3.25,+5.1,-2>
          }
       }
    difference {
       box {
          <-4.3, 0, -2.8>, <+4.3, 1, 2.8>
          }
       box {
          <-4.7, -0.1, -3.8>, <-2, 0.2, 3.8>
          }
       box {
          <+4.7, -0.1, -3.8>, <+2, 0.2, 3.8>
          }
       }
    union {
       box {
          <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5>
          translate <-4.5,0,+1.27>
          }
       box {
          <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5>
          translate <-4.5,0,-1.27>
          }
       box {
          <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5>
          translate <+4.5,0,+1.27>
          }
       box {
          <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5>
          translate <+4.5,0,-1.27>
          }
       box {
          <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5>
          translate <-4.6+0.7,0,+1.27>
          }
       box {
          <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5>
          translate <-4.6+0.7,0,-1.27>
          }
       box {
          <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5>
          translate <+4.6-0.7,0,+1.27>
          }
       box {
          <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5>
          translate <+4.6-0.7,0,-1.27>
          }
       pigment {
          Silver
          }
       }
    pigment {
       Gray15
       }
    }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//:WE-SL2=FILTER_WE_SL2(:Common mode filter Wuerth-Elektronik WE-SL2
// end assignment
