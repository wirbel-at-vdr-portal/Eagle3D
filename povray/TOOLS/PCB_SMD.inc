/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Generates an SMD pad
 * xsize:    x-size of the SMD pad
 * ysize:    y-size of the SMD pad
 * thick:    the thikness of the copper
 * r:        roundness (0%-100%)
 ******************************************************************************/
#macro TOOLS_PCB_SMD(xsize,ysize,thick,r)
  #if (r=0)
      box { <-xsize/2,0,-ysize/2> <xsize/2,thick,ysize/2> }
  #else
      union {
         #if (xsize > ysize)
             #local xsmall = xsize - (ysize)*(r/100);
             #local ysmall = ysize - (ysize)*(r/100);
             #local cyldif = ysize * (r/100);
         #else
             #local xsmall = xsize - (xsize)*(r/100);
             #local ysmall = ysize - (xsize)*(r/100);
             #local cyldif = xsize * (r/100);
         #end

         box { <-xsmall/2,0,-ysize/2> <xsmall/2,thick,ysize/2> }
         box { <-xsize/2,0,-ysmall/2> <xsize/2,thick,ysmall/2> }

         cylinder { <-xsize/2+cyldif/2,0,-ysize/2+cyldif/2> <-xsize/2+cyldif/2,thick,-ysize/2+cyldif/2> cyldif/2 }
         cylinder { <-xsize/2+cyldif/2,0, ysize/2-cyldif/2> <-xsize/2+cyldif/2,thick, ysize/2-cyldif/2> cyldif/2 }
         cylinder { < xsize/2-cyldif/2,0,-ysize/2+cyldif/2> < xsize/2-cyldif/2,thick,-ysize/2+cyldif/2> cyldif/2 }
         cylinder { < xsize/2-cyldif/2,0, ysize/2-cyldif/2> < xsize/2-cyldif/2,thick, ysize/2-cyldif/2> cyldif/2 }
         }
  #end
#end
