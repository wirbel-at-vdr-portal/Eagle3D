/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * generic 3.5mm 4-Pole Jack Socket (de: Klinkenbuchse 3.5mm)
 * not assigned to any eagle lib
 ******************************************************************************/
#macro CON_THT_JACKSOCKET_035()
  union {
     difference {
        union {
           box {
              <0,0,0> <7,5,12>
              translate <-3.5,1,2>
              }
           box {
              <0,0,0> <5,1,10>
              translate <-2.5,1,2>
              }
           cylinder {
              <0,0,0> <0,0,2> 3
              translate <0,3,0>
              }
           }
        cylinder {
           <0,0,12> <0,0,-0.1> 1.75
           translate <0,3,0>
           }
        box {
           <0,0,0> <3.5,2.5,3.5>
           translate <-1.75,3.6,8>
           }
        box {
           <0,0,0> <6,4.5,10.5>
           translate <-3,1,4>
           }
        }
     cylinder {
        <0,0,0> <0,1,0> 0.5
        translate <0,0,4.5>
        }
     cylinder {
        <0,0,0> <0,1,0> 0.5
        translate <0,0,11.5>
        }
     union {
        // Legs front
        box {
           <0,0,0> <0.3,8.5,1.1>
           translate <-3.65,-2.5,4>
           }
        box {
           <0,0,0> <0.3,8.5,1.1>
           translate <3.35,-2.5,4>
           }
        // legs rear
        box {
           <0,0,0> <0.3,8.4,1.1>
           translate <-3.5,-2.5,12.9>
           }
        box {
           <0,0,0> <0.3,8.4,1.1>
           translate <3.2,-2.5,12.9>
           }
        // left,right side
        box {
           <0,0,0> <0.3,5,3.5>
           translate <-3.65,1,2.7>
           }
        box {
           <0,0,0> <0.3,5,3.5>
           translate <3.35,1,2.7>
           }
        // top
        box {
           <0,0,0> <7,0.3,3.5>
           translate <-3.65,5.8,2.7>
           }
        box {
           <0,0,0> <2.5,0.3,8>
           translate <-1.25,5.8,2.7>
           }
        box {
           <0,0,0> <2.5,0.3,5>
           translate <-1.25,3.8,8>
           }
        texture {
           T_Chrome_5A
           }
        }
     }
  pigment {
     Gray20
     }
  translate <0,0,-8>
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_JACKSOCKET_035:generic THT jack socket 4-pole
// end assignment
