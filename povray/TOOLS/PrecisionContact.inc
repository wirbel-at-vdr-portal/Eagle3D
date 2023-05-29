/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * contact for precision female headers
 * 28.05.2023, -wk
 *
 * BodyLength is usually 4.90mm (length inside plastic body)
 * PinLength is usually 3.20mm (length from zero plane trough PCB)
 ******************************************************************************/
#macro PrecisionContactFemale(PinLength, BodyLength)
  lathe {
    linear_spline
    13,
    <     0,-PinLength>,
    <0.64/3,-PinLength>,
    <0.64/2,-PinLength+0.8>,
    <0.64/2,0>,
    <1.32/2,0.5>,
    <1.32/2,BodyLength-0.76>,
    <1.83/2,BodyLength-0.76>,
    <1.83/2,BodyLength>,
    <1.50/2,BodyLength>,
    <1.00/2,BodyLength-0.6>,
    <0.80/2,BodyLength-0.6>,
    <0.80/2,1.00>,
    <0     ,1.00>
    texture {
       col_gold
       }
    }
#end
