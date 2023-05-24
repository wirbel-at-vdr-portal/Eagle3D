/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Draws a bended rectangular profile, with angle 1-179 deg.
 * Author: Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
 *------------------------------------------------------------------------------
 * bend rectangular profile with bend angle = 1..179 deg
 * InnerRadius : inner radius, >= 0
 * BendAngle   : bend angle, greather than 0, less than 180
 * Thickness   : material thickness
 * Width       : width
 * xLength     : length on x axis
 * BendLength  : length of bend part. If InnerRadius = 90, this is the Height.
 *------------------------------------------------------------------------------
 * Der Schenkel mit der xLength liegt mittig auf der x-Achse
 * bei einem Winkel von 90Grad der andere auf der y-Achse
 * der Innenradius muss >= 0 sein,
 * der Winkel zwischen den Schenkeln 0 > Winkel <180,
 * mean radius = InnerRadius + Thickness/2
 ******************************************************************************/
#macro TOOLS_RECT_BOGEN(InnerRadius,BendAngle,Thickness,Width,xLength,BendLength)
union {
   difference {
      cylinder {
         <-Width/2,0,0>
         <+Width/2,0,0>
         InnerRadius + Thickness
         }
      cylinder {
         <-(Width/2 + 0.1),0,0>
         <+(Width/2 + 0.1),0,0>
         InnerRadius
         }
      box {
         <-(Width/2 + 0.1), -(InnerRadius + Thickness + 0.1),                               0>
         <+(Width/2 + 0.1), +(InnerRadius + Thickness + 0.1), (InnerRadius + Thickness + 0.1)>
         }
      box {
         <-(Width/2 + 0.1), -(InnerRadius + Thickness + 0.1),                               0>
         <+(Width/2 + 0.1), +(InnerRadius + Thickness + 0.1), (InnerRadius + Thickness + 0.1)>
         rotate <BendAngle,0,0>
         }
      }
   box {
      <-(Width/2),InnerRadius            ,       0>
      < (Width/2),InnerRadius + Thickness, xLength>
      }
   box {
      <-(Width/2),          0, -(InnerRadius)            >
      <+(Width/2),-BendLength, -(InnerRadius + Thickness)>
      rotate <-(90 - BendAngle),0,0>
      }
   translate <0,-(InnerRadius + Thickness/2),(InnerRadius + Thickness/2)>
   rotate <0,-90,180>
   }
#end
