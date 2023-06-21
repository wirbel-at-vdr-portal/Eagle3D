/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * This macro draws a box with 45deg chamfered edges.
 *
 * - p1,p2   edge points, as povray box {} command
 * - chamfer size of the chamfer
 * Author: 20230621, wk
 ******************************************************************************/
#macro ChamferBox(p1, p2, chamfer)
  difference {
     #local x1 = min(p1.x,p2.x);
     #local x2 = max(p1.x,p2.x);
     #local y1 = min(p1.y,p2.y);
     #local y2 = max(p1.y,p2.y);
     #local z1 = min(p1.z,p2.z);
     #local z2 = max(p1.z,p2.z);
     #local L = 1.414 * chamfer;
     #local Center = <+(x2+x1)/2,+(y2+y1)/2,+(z2+z1)/2>;
     #local dx = abs(x2-x1);
     #local dy = abs(y2-y1);
     #local dz = abs(z2-z1);
     #local A = box {
        <-L/2,-L/2,-L/2>
        <+L/2,+L/2,+L/2>
        scale y*1.1*dy/L
        rotate y*45
        translate Center
        };
     #local B = box {
        <-L/2,-L/2,-L/2>
        <+L/2,+L/2,+L/2>
        scale x*1.1*dx/L
        rotate x*45
        translate Center
        };
     #local C = box {
        <-L/2,-L/2,-L/2>
        <+L/2,+L/2,+L/2>
        scale z*1.1*dz/L
        rotate z*45
        translate Center
        };
     box { p1 p2 }
     object { A translate <-dx/2,0,-dz/2> }
     object { A translate <-dx/2,0,+dz/2> }
     object { A translate <+dx/2,0,-dz/2> }
     object { A translate <+dx/2,0,+dz/2> }
     object { B translate <0,-dy/2,-dz/2> }
     object { B translate <0,-dy/2,+dz/2> }
     object { B translate <0,+dy/2,-dz/2> }
     object { B translate <0,+dy/2,+dz/2> }
     object { C translate <-dx/2,-dy/2,0> }
     object { C translate <-dx/2,+dy/2,0> }
     object { C translate <+dx/2,-dy/2,0> }
     object { C translate <+dx/2,+dy/2,0> }
     }
#end
