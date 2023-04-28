/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * A - pin length
 * B - body length
 * C - pin diameter
 * D - body diameter
 * E - min distance from body where D is expected
 *   for drawing, see https://en.wikipedia.org/wiki/DO-204
 ******************************************************************************/
#macro axial_diode(value,A,B,C,D,E,pitch,CaseMaterial)
  union {
     #local Orientation = "horizontal";
     #if (pitch < (B+2*E))
        #local Orientation = "vertical";
     #end

     #if (pitch = 0)
        GRID(
           cylinder {
              <-A/2,D/2,0>
              <+A/2,D/2,0>
              C/2             
              texture {
                 col_silver
                 }
             },
           A+B-0.01,
           2,1
           )
     #else
         #if (Orientation = "horizontal")
            union {
               intersection {
                  torus {
                     2*C, C/2
                     rotate -90*x
                     }
                  box {
                     <  0,  0,-C>
                     <4*C,4*C,+C>
                     }
                  translate <pitch/2-2*C,D/2-2*C,0>
                  }
               intersection {
                  torus {
                     2*C, C/2
                     rotate -90*x
                     }
                  box {
                     <  0,  0,-C>
                     <-4*C,4*C,+C>
                     }
                  translate <-pitch/2+2*C,D/2-2*C,0>
                  }
               cylinder {
                  <+B/2,+D/2,0>
                  <+pitch/2-2*C,+D/2,0>
                  C/2
                  }
               cylinder {
                  <-B/2,+D/2,0>
                  <-pitch/2+2*C,+D/2,0>
                  C/2
                  }
               cylinder {
                  <+pitch/2,+D/2-2*C,0>
                  <+pitch/2,-2.8,0>
                  C/2
                  }
               cylinder {
                  <-pitch/2,+D/2-2*C,0>
                  <-pitch/2,-2.8,0>
                  C/2
                  }
               texture {
                  col_silver
                  }
               }
         #else
            union {
               intersection {
                  torus {
                     2*C, C/2
                     rotate -90*x
                     }
                  box {
                     <  0,  0,-C>
                     <4*C,4*C,+C>
                     }
                  translate <pitch/2-2*C,-2*C + B + 2*E,0>
                  }
               intersection {
                  torus {
                     2*C, C/2
                     rotate -90*x
                     }
                  box {
                     <  0,  0,-C>
                     <-4*C,4*C,+C>
                     }
                  translate <-pitch/2+2*C,-2*C + B + 2*E,0>
                  }
               cylinder {
                  <-pitch/2+2*C,B + 2*E,0>
                  <+pitch/2-2*C,B + 2*E,0>
                  C/2
                  }
               cylinder {
                  <+pitch/2,-2*C + B + 2*E,0>
                  <+pitch/2,-2.8,0>
                  C/2
                  }
               cylinder {
                  <-pitch/2,E,0>
                  <-pitch/2,-2.8,0>
                  C/2
                  }
               texture {
                  col_silver
                  }
               }
         #end
     #end

     union {
        Round_Cylinder_Union (
           <-B/2,D/2,0>
           <+B/2,D/2,0>
           D/2
           (D/2)*0.1
           )
        #for(i,1,strlen(value))
           text {
              ttf besch_font substr(value,i,1), 0.075, 0
              scale D/2.5
              pigment {
                 White
                 }
              rotate <90,-90,0>
              translate <+0.5,D/2+0.01,-0.3>
              rotate <-75+i*30,0,0>
              translate <0,D/2,0>
              }
        #end
        cylinder {
           <-C/2,D/2,0>
           <+C/2,D/2,0>
           D/2+0.02
           translate <-(B/2)*0.6,0,0>
           texture {
              col_Rcode_silver
              }
           }
        #if (CaseMaterial = "Glass")
           object {
              Round_Cylinder_Union (
                 <-B/2,D/2,0>
                 <+B/2,D/2,0>
                 D/2
                 (D/2)*0.1
                 )
              scale 0.7
              texture {
                 T_Copper_3A
                 finish {
                    phong 1
                    }
                 }
              }
           material {
              texture {
                 NBglass
                 }
              interior {
                 I_Glass
                 }
              }
        #end
        #if (CaseMaterial = "Plastic")
           pigment {
              Gray10
              }
        #end
        #if (Orientation = "vertical")
           rotate z*90
           translate <-pitch/2+D/2,B/2+E,0>
        #end
        }
     }
#end
