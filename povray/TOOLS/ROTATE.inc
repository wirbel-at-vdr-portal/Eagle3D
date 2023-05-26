/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * This macro repeats the povray object OBJ counter-clockwise rotated N-times.
 * Axis is 90deg to pcb.
 *
 * N     - number of repeats, N > 0
 * Angle - rotation angle per repeat, 0..360
 *
 * Note: for N <= 0, the object is not drawn.
 *       You may change rotation direction with the sign of Angle.
 *
 * Note: First OBJ is not rotated (easier to handle.)
 * Author: 20230526, wk
 ******************************************************************************/

#macro ROTATE(OBJ, N, Angle)
  union {
     #for(i,0,N-1)
        object { OBJ rotate -y*i*Angle }
     #end
     }
#end
