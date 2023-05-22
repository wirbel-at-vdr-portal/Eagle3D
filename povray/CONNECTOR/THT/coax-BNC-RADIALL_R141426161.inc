/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * BNC socket straight, 12mm x 12mm, 10.16mm grid
 * 22.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_R141426161()
  union {
     difference {
        object {
           CON_THT_AMP_112536()
           translate <0,-2.9,0>
           }
        box {
           <-18/2,-10,-18/2>
           <+18/2,2.2,+18/2>
           }
        }
     intersection {
        #local OuterPin = union {
           box {
              <-1.08/2,+0.5,-1.08/2>
              <+1.08/2,-3.5,+1.08/2>
              }
           box {
              <-1.08/2,+0.5,-1.50>
              <+1.08/2,+0.0,+1.00>
              }
           rotate <0,45,0>
           translate <+10.16/2,0,+10.16/2>
           };
        union {
           box {
              <-12/2,0.5,-12/2>
              <+12/2,2.2,+12/2>
              }
           #for(i,0,3)
              object { OuterPin rotate <0,i*90,0> }
           #end
           }
        sphere {
           <0,-4.3,0>
           10
           scale <1,1,1>
           }
        cylinder {
           <0,-4.0,0>
           <0,+2.3,0>
           8.0
           }        
        }
     cylinder {
        <0,+1,0>
        <0,-3,0>
        1/2
        texture {
           col_gold
           }
        }
     texture {
        T_Silver_1A
        finish {
           phong 1
           ambient (0.1 * global_ambient_mul)
           }
        }
     }
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-coax:R141426=CON_THT_R141426161(:BNC socket straight
// end assignment
