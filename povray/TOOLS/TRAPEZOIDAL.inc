/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Draws an trapezoidal prism.
 * X1,Y1 - dimensions bottom plane
 * X2,Y2 - dimensions top plane
 * Z - height of prism
 ******************************************************************************/
#macro TRAPEZOIDAL(X1,Y1,X2,Y2,Z)
  union {
     intersection {
        prism {
           -X1/2, +X1/2, 5
           <-Y1/2, 0>,
           <+Y1/2, 0>,
           <+Y2/2, Z>,
           <-Y2/2, Z>,
           <-Y1/2, 0>
           rotate <-90,-90,0>
           }
        prism {
           -Y1/2, +Y1/2, 5
           <-X1/2, 0>,
           <-X2/2, Z>,
           <+X2/2, Z>,
           <+X1/2, 0>,
           <-X1/2, 0>
           rotate <-90,0,0>
           }
        }
     }
#end
