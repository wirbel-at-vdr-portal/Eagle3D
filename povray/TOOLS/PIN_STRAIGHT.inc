/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Gerader, quadratischer Stift eines Steckverbinders.
 * Tilmann Reh <tilmann.reh@autometer.de>
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
     box {
        <-0.6*Thickness, 0            , 0            >
        <+0.6*Thickness, 0.6*Thickness, 0.6*Thickness>
        rotate <+45,0,0>
        translate <0,Top,Thickness/4>
        }
     box {
        <-0.6*Thickness, 0            , 0             >
        <+0.6*Thickness, 0.6*Thickness, -0.6*Thickness>
        rotate <-45,0,0>
        translate <0,Top,-Thickness/4>
        }
     box {
        <0            , 0            , -0.6*Thickness>
        <0.6*Thickness, 0.6*Thickness, +0.6*Thickness>
        rotate <0,0,-45>
        translate <Thickness/4,Top,0>
        }
     box {
        <0             ,             0, -0.6*Thickness>
        <-0.6*Thickness, 0.6*Thickness, +0.6*Thickness>
        rotate <0,0,+45>
        translate <-Thickness/4,Top,0>
        }
     box {
        <0            ,             0, -0.6*Thickness>
        <0.6*Thickness, 0.6*Thickness, +0.6*Thickness>
        rotate <0,0,-45>
        translate <Thickness/4,-Bottom,0>
        }
     box {
        <0             , 0            , -0.6*Thickness>
        <-0.6*Thickness, 0.6*Thickness, +0.6*Thickness>
        rotate <0,0,45>
        translate <-Thickness/4,-Bottom,0>
        }
     box {
        <-0.6*Thickness, 0            ,             0>
        <+0.6*Thickness, 0.6*Thickness, 0.6*Thickness>
        rotate <45,0,0>
        translate <0,-Bottom,Thickness/4>
        }
     box {
        <-0.6*Thickness, 0            , 0             >
        <+0.6*Thickness, 0.6*Thickness, -0.6*Thickness>
        rotate <-45,0,0>
        translate <0,-Bottom,-Thickness/4>
        }
     }
#end
