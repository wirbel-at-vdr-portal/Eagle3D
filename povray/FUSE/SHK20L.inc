/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Fuse Holder SHK20L
 * (c) 2003 Juraj Rojko
 * *****************************************************************************/
#macro SPC_FUSE_SHK20L(value)
  union {
     #macro SPC_FUSE1_HOLDER()
        union {
           // base plate
           box {
              <-.1,0,-2>, <4.3,.2,2>
              }
           box {
              <4.6,0,-2>, <-.4,.2,-1.4>
              }
           box {
              <4.6,0,2>, <-.4,.2,1.4>
              }
           // 1st pin
           box {
              <-.5,-5,-.4>, <-.3,-.2,.4>
              }
           intersection {
              difference {
                 cylinder {
                    <-.1,-.2,-.4> <-.1,-.2,.4> .4
                    }
                 cylinder {
                    <-.1,-.2,-.4> <-.1,-.2,.4> .2 open
                    }
                 }
              box {
                 <-.5,-.2,-.4>, <-0.1,.2,.4>
                 }
              }
           // 2nd pin
           box {
              <4.5,-5,-.4>, <4.7,-.2,.4>
              }
           intersection {
              difference {
                 cylinder {
                    <4.3,-.2,-.4> <4.3,-.2,.4> .4
                    }
                 cylinder {
                    <4.3,-.2,-.4> <4.3,-.2,.4> .2 open
                    }
                 }
              box {
                 <4.3,-.2,-.4>, <4.7,.2,.4>
                 }
              }
           // 1st holder arm
           box {
              <0,0,-2>, <4.25,4.4,-2.2>
              rotate<3,0,0>
              }
           intersection {
              difference {
                 cylinder {
                    <0,6,.65> <4.25,6,.65>3
                    }
                 cylinder {
                    <0,6,.65> <4.25,6,.65> 2.8 open
                    }
                 }
              box {
                 <-.1,4.4,-1.8>, <4.3,8,-3>
                 }
              }
           intersection {
              box {
                 <0,7.3,-1.8>, <4.25,9.2,-2>
                 }
              cylinder {
                 <2.125,7,-5> <2.125,7,5> 2.5
                 }
              }
           // 2st holder arm
           box {
              <0,0,2>, <4.25,4.4,2.2>
              rotate<-3,0,0>
              }
           intersection {
              difference {
                 cylinder {
                    <0,6,-.65> <4.25,6,-.65>3
                    }
                 cylinder {
                    <0,6,-.65> <4.25,6,-.65> 2.8 open
                    }
                 }
              box {
                 <-.1,4.4,1.8>, <4.3,8,3>
                 }
              }
           intersection {
              box {
                 <0,7.3,1.8>, <4.25,9.2,2>
                 }
              cylinder {
                 <2.125,7,-5> <2.125,7,5> 2.5
                 }
              }
           texture {
              col_silver
              }
           }
     #end

     #macro SPC_FUSE1_CUP()
       union {
       difference {
          cylinder {
             <0,6,0> <3.5,6,0> 2.15
             }
          cylinder {
             <0.2,6,0> <3.5,6,0> 2 open
             }
          }
       torus {
          2.15-.3,.3
          rotate<0,0,90> translate<0,6,0>
          }
       // drop of solder
       difference {
          sphere {
             <.8,6,0> 1.2
             }
          box {
             <0,4,-2> <3,8,2>
             }
          }
       translate<.3,0,0>
       texture {
          col_silver
          }
       }
     #end

     #if (on) // draw holder on/off
       object {
          SPC_FUSE1_HOLDER()
          rotate<0,0,0> translate<-10,0,0>
          texture {
             col_silver
             }
          }
       object {
          SPC_FUSE1_HOLDER()
          rotate<0,180,0> translate<10,0,0>
          texture {
             col_silver
             }
          }
     #end

     #if (on) // draw fuse on/off
        object {
           SPC_FUSE1_CUP()
           rotate<0,0,0> translate<-10,0,0>
           texture {
              col_silver
              }
           }

        // glass tube
        difference {
           cylinder {
              <-9,6,0> <9,6,0>2
              }
           cylinder {
              <-9,6,0> <9,6,0> 1.8
              }
           texture {
              T_Green_Glass
              }
           }
        // fiber
        cylinder {
           <-9,6,0> <9,6,0> .07
           texture {
              col_silver
              }
           translate<0,0,0>
           }
        object {
           SPC_FUSE1_CUP()
           rotate<0,180,0> translate<10,0,0>
           texture {
             col_silver
             }
           }
        // value
        intersection {
          difference {
             cylinder {
                <-9,6,0> <9,6,0> 2.01
                }
             cylinder {
                <-9,6,0> <9,6,0>2
                }
             }
          text {
             ttf besch_font value 2, 0
             scale 2 rotate<90,0,0> translate<-2,10,-.6>
             }
          pigment {
             White
             }
          }
     #end

}
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//fuse:SHK20L=SPC_FUSE_SHK20L(:Fuse Holder SHK20L
//special:FUSE1=SPC_FUSE_SHK20L(:Fuse Holder SHK20L
// end assignment
