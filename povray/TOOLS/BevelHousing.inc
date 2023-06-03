/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Draws a rounded case (or housing) of a box header or similar connectors.
 * the edges have a 45deg bevel towards the inner opening.
 * Orientation is looking from top into the opening of the housing.
 *
 * 03.06.2023, -wk
 *
 *
 * Xa - outer dimension in x
 * Ya - outer dimension in y
 * Ha - outer dimension in z, height is from zero to Ha
 * Xi - inner dimension in x, smaller than Xa
 * Yi - inner dimension in y, smaller than Ya
 * Hi - inner dimension in z, inner height is (Ha-Hi)..Ha
 * R  - rounding radius for outer dimension, try 0.1..0.15
 ******************************************************************************/
#macro BevelHousing(Xa,Ya,Ha,Xi,Yi,Hi,R)
  difference {
     #local dY = (Ya-Yi)/4;
     Round_Box(
        <-Xa/2, 0,-Ya/2>
        <+Xa/2,Ha,+Ya/2>
        R 0
        )
     box {
        <-Xi/2,Ha-Hi  ,-Yi/2>
        <+Xi/2,Ha+0.10,+Yi/2>
        }
     ROTATE(
        union {
           box {
              <-Xi/2,-dY/2,-dY/2>
              <+Xi/2,+dY/2,+dY/2>
              rotate <+45,0,0>
              translate <0,Ha,+Yi/2>
              }
           box {
              <-dY/2,-dY/2,-Yi/2>
              <+dY/2,+dY/2,+Yi/2>
              rotate <0,0,+45>
              translate <+Xi/2,Ha,0>
              }
           object {
              Pyramid_N(4, (dY/2)*1.42, 0, dY*(1.42/2))
              rotate <180,0,0>
              translate <+Xi/2,Ha+0.01,+Yi/2>
              }
           object {
              Pyramid_N(4, (dY/2)*1.42, 0, dY*(1.42/2))
              rotate <180,0,0>
              translate <-Xi/2,Ha+0.01,+Yi/2>
              }
           },
        2,180
        )
     }
#end
