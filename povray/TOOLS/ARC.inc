/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Draws an arc. Zeichnet einen Bogen
 *   rad    = radius
 *   wid    = width of the "line"
 *   st_wi  = start angle
 *   en_wi  = end angle
 *   height = well, the height
 ******************************************************************************/
#macro ARC(rad,wid,st_wi,en_wi,height)
   union {
      #local i = st_wi;
      #local l = ((rad*pi)/360) * 1.1;

      cylinder{<0,0,-rad> <0,height,-rad> wid/2 pigment{Red} rotate<0,-i-90,0> }

      #while (i<=en_wi)
          box{<-l,0,-rad-wid/2><l,height,-rad+wid/2> rotate<0,-i-90,0>}
          #declare i=i+1;
      #end

      cylinder{<0,0,-rad> <0,height,-rad> wid/2 pigment{Red} rotate<0,-i+1-90,0> }
      }
#end  
