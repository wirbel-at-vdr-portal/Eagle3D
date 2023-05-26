/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Gerader, quadratischer Stift eines Steckverbinders.
 * Tilmann Reh <tilmann.reh@autometer.de>
 *
 * rewritten and simplified: 26.05.2023, -wk
 *
 * Verwendung fuer gerade Pfostenwannen sowie z.B. Wago-Steckerleisten.
 *   Thickness - pin thickness
 *   Top       - height above PCB
 *   Bottom    - height below PCB
 ******************************************************************************/
#macro PIN_STRAIGHT(Thickness,Top,Bottom)
  difference {
     box {
        <-Thickness/2, -Bottom, -Thickness/2>
        <+Thickness/2, +Top   , +Thickness/2>
        }
     #local cut =
        box {
           <-1,-1,-1><1,1,1>
           scale Thickness*0.75
           };
     ROTATE(object { cut rotate z*+30 translate <1.1*Thickness,+Top   ,0> },4,90)
     ROTATE(object { cut rotate z*-30 translate <1.1*Thickness,-Bottom,0> },4,90)
     }
#end
