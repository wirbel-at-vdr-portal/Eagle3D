/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Um 90° gebogener, quadratischer Stift eines Steckverbinders.
 * Tilmann Reh <tilmann.reh@autometer.de>
 *
 * rewritten and simplified: 26.05.2023, -wk
 *
 * Verwendung fuer abgewinkelte Pfostenwannen sowie z.B. Wago-Steckerleisten.
 *   Thickness - pin thickness
 *   R         - mean bending radius
 *   Top       - height above PCB
 *   Bottom    - height below PCB
 *   Length    - length of connectors pin part in -Z
 ******************************************************************************/
#macro PIN_90deg(Thickness,R,Top,Bottom,Length)
  difference {
     object {
        BENT_PLANE_OUTER(
           Length+Thickness/2,     // outer vs centered
           Top+Bottom+Thickness/2, // outer vs centered
           Thickness,Thickness,    // squared
           R-Thickness/2,          // mean diameter -> inner diameter
           90)
        rotate <0,90,180>
        translate <0,Top+Thickness/2,Thickness/2>
        }
     #local cut =
        box {
           <-1,-1,-1><1,1,1>
           scale Thickness*0.75
           };
     object {
        ROTATE(object { cut rotate z*+60 translate <1.1*Thickness,0,0> },4,90)
        rotate <90,0,0>
        translate <0,+Top,-Length>
        }
     ROTATE(object { cut rotate z*-30 translate <1.1*Thickness,-Bottom,0> },4,90)
     }
#end
