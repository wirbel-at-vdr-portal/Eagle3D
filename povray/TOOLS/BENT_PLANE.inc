/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Convienience wrappers to TOOLS_RECT_BOGEN
 ******************************************************************************/




/*******************************************************************************
 * Draws a bent rectangular profile, by it's outer dimensions.
 *
 * The profile is drawn on positive x-axis from 0 to xLength and
 * the bent part is rotated upward from x-axis towards y - axis by Angle.
 ******************************************************************************/
#macro BENT_PLANE_OUTER(xLength,BendLength,Width,Thickness,R,Angle)
  object {
     #local dX = xLength    -R -Thickness;
     #local dY = BendLength -R -Thickness;
     TOOLS_RECT_BOGEN(R,Angle,Thickness,Width,dX,dY)
     translate <Thickness/2,Thickness/2,0>
     }
#end

/*******************************************************************************
 * Draws a bent rectangular profile, by it's inner dimensions.
 *
 * The profile is drawn on positive x-axis from 0 to xLength and
 * the bent part is rotated upward from x-axis towards y - axis by Angle.
 ******************************************************************************/
#macro BENT_PLANE_INNER(xLength,BendLength,Width,Thickness,R,Angle)
  BENT_PLANE_OUTER(xLength+Thickness,BendLength+Thickness,Width,Thickness,R,Angle)
#end
