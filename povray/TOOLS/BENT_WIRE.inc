/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Draws a bent circular profile, by it's outer dimensions.
 *
 * The profile is drawn on positive x-axis from 0 to xLength and
 * the bent part is rotated upward from x-axis towards y - axis by Angle.
 * 28.05.2023, -wk
 ******************************************************************************/
#macro BENT_WIRE_OUTER(xLength,BendLength,Thickness,R,Angle)
  union {
     object {
        Segment_of_Torus (R, Thickness/2, Angle)
        rotate <-90,0,-90>
        translate <R+Thickness/2,R+Thickness/2,0>
        }
     cylinder {
        <R+Thickness/2,Thickness/2,0>
        <xLength      ,Thickness/2,0>
        Thickness/2
        }
     cylinder {
        <0,-R,0>
        <-BendLength,-R,0>
        Thickness/2
        rotate <0,0,-Angle>
        translate <R+Thickness/2,R+Thickness/2,0>
        }
     }
#end

/*******************************************************************************
 * Draws a bent circular profile, by it's inner dimensions.
 *
 * The profile is drawn on positive x-axis from 0 to xLength and
 * the bent part is rotated upward from x-axis towards y - axis by Angle.
 * 28.05.2023, -wk
 ******************************************************************************/
#macro BENT_WIRE_INNER(xLength,BendLength,Thickness,R,Angle)
  BENT_WIRE_OUTER(xLength+Thickness,BendLength+Thickness,Thickness,R,Angle)
#end
