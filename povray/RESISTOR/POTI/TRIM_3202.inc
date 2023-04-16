/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * rcl.lib: R-TRIMM3202
 * A. Zihlmann - berti@wueschomania.org
 * 12.12.2002
 *
 * 18.04.2023, wk: completely restructured - may be should be thrown away.
 ******************************************************************************/
#macro RES_SMT_TRIM_3202()
  union {
     union {
        box {
           <0,0.1,0> <3,1,3.2>
           pigment {
              White * 0.8
              }
           }
        box {
           <0,0,0> <0.8,0.5,0.5>
           texture {
              Gold_Metal
              }
           translate <0.2,0,-0.2>
           }
        box {
           <0,0,0> <0.8,0.5,0.5>
           texture {
              Gold_Metal
              }
           translate <2,0,-0.2>
           }
        box {
           <0,0,0> <1,0.5,0.5>
           texture {
              Gold_Metal
              }
           translate <1,0,2.9>
           }
        }
     union {
        difference {
          difference {
             cylinder {
                <0,0,0><0,1,0>,1.5
                }
             union {
                cone {
                   <0,-0.01,0> 0.5
                   <0,1.1,0> 1
                   }
                difference {
                   cylinder {
                      <0,-0.02,0> <0,0.8,0> 1.6
                      }
                   cone {
                      <0,0.03,0>, 0.8
                      <0,0.8,0>, 1.2
                      }
                   }
                }
             }
          union {
             box {
                <-1,0,-0.25>,<1,1,0.25>
                translate 0.3*y
                }
             box {
                <-1,0,-0.25>,<1,1,0.25>
                rotate 90*y
                translate 0.3*y
                }
             box {
                <-1,-3,-1> <1,3,1>
                translate <-1.7,0,1.9>
                }
             box {
                <-1,-3,-1> <1,3,1>
                translate <1.7,0,1.9>
                }
             }
          }
       difference {
          union {
             cylinder {
                <0,0,0><0,0.15,0>1.5
                }
             cylinder {
                <0,0.15,-1.5><0,0.15,-0.5>0.45
                }
             }
          union {
             cylinder {
                <0,-0.01,0><0,0.16,0>1
                }
             cylinder {
                <0,0.3,-1.51><0,0.3,-0.5>0.45
                }
             cylinder {
                <0,0.15,0><0,0.5,0>1.6
                }
             cone {
                <0,0.03,0>, 0.8
                <0,0.8,0>,1.2}
                }
             translate 0.3*y
             }
          pigment {
             Gray70
             }
          finish {
             F_MetalA
             ambient (0.1 * global_ambient_mul)
             }
          rotate 180*y
          translate <1.5,1.0,1.6>
          }
     difference {
        union {
           cylinder {
              <0,0,0> <0,0.05,0>1.5
              }
           box {
              <-1.5,0,-1.5> <1.5,0.05,0>
              }
           }
        union {
           cylinder {
              <0,-1,0> <0,0.10,0> 1
              }
           box {
              <-0.5,-1,-1.6> <0.5,0.1,0>
              }
           }
        texture {
           pigment {
              White * 0.2
              }
           }
        translate <1.5,1,1.6>
        }
     translate<-1.5,0,-1.6>
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:RTRIM3202=RES_SMT_TRIM_3202(:smd trim resistor
// end assignment
