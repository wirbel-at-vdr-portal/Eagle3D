/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * TYCO H38 inductor
 ******************************************************************************/



/*******************************************************************************
 * MURATA NFE61P EMI FILTERS
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  13/01/06
 ******************************************************************************/
#macro SPC_FILTER_MURATA_NFE61P()
  union {
     difference {
        superellipsoid {
           <0.09, 0.09>
           scale <3.4,0.8,0.8>
           translate <0,0.8,0>
           texture {
              col_silver
              }
           }
        cylinder {
           <-2.7,0.8,0> <+2.7,0.8,0> 1.2
           texture {
              col_silver
              }
           }
        }
     superellipsoid {
        <0.09, 0.09>
        scale <1.3,0.8,0.8>
        translate <0,0.8,0>
        texture {
           col_silver
           }
        }
     cylinder {
        <-2.7,0.8,0> <+2.7,0.8,0> 0.7
        pigment {
           Gray30
           }
        }
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_FILTER_MURATA_NFE61P(:MURATA EMI FILTER
// end assignment
