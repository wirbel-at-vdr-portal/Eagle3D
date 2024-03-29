/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * 5 x 20 mm FUSE HOLDER SHK20Q, SH contact, E1207
 * Buerklin 46G6061
 * fbleikamp(replace with at)web.de 
 * *****************************************************************************/
#macro SPC_FUSE_SHK20Q(value)
  #macro SPC_FUSE2_PART()
     union {
        object {
           TOOLS_RECT_BOGEN(0.25,167.5,0.3,4,3.0,2.8507)
           rotate<0,0,0> translate <0,0,0>
           }
        object {
           TOOLS_RECT_BOGEN(0.25,125.428,0.3,4,0,0)
           rotate<180,0,-12.5> translate <-2.85631,0.712,0>
           }
        object {
           TOOLS_RECT_BOGEN(2.5,84.144,0.3,4,0,0)
           rotate<0,0,42.072> translate <-4.785 ,-1.242, 0>
           }
        object {
           TOOLS_RECT_BOGEN(0.25,125.428,0.3,4,0.7,0)
           rotate<180,180,0> translate <-6.6585,1.10,0>
           }
        difference {
           box {
              <3.125,-0.15,-0.6> <7,0.15,0.6>
              }
           box {
              <3.125,-0.16,-0.6> <7,0.16,0.6>
              rotate <0,-10,0> translate <0.5,0,-2.0>
              }
           box {
              <3.125,-0.16,-0.6> <7,0.16,0.6>
              rotate <0,10,0> translate <0.5,0,2.0>
              }
           }
        texture {
           col_silver
           }
        rotate<0,0,-90> translate <-2.50,3.4,0>
        }
  #end
  #macro SPC_FUSE2_HOLDER()
     union {
        object {
           SPC_FUSE2_PART()
           }
        object {
           SPC_FUSE2_PART()
           rotate <0,180,0>
           }
        object {
           TOOLS_RECT_BOGEN(0.1,90,0.3,2,2.25,0)
           rotate<90,0,0> translate <-2.5,1.2,-2.25>
           }
        object {
           TOOLS_RECT_BOGEN(0.1,90,0.3,2,2.25,0)
           rotate<-90,180,0> translate <2.5,1.2,-2.25>
           }
        intersection {
           merge {
              cylinder {
                 <-0.3,0,0> <0.3,0,0> 2.5
                 }
              torus {
                 2.5,.3
                 rotate<0,0,90>
                 }
              box {
                 <-0.3,-2.5,0> <0.3,2.5,-1>
                 }
              }
           box {
              <-0.31,-1,3> <0,1,-0.5>
              }
           texture {
              col_silver
              }
           rotate <20,-90,0> translate <0,8,-2>
           }
        rotate <0,90,0>  texture {
           col_silver
           }
        }
  #end
  #macro SPC_FUSE2_CUP()
     union {
        difference {
           cylinder {
              <0.0,0,0> <4.8,0,0> 2.5
              }
           cylinder {
              <0.1,0,0> <4.9,0,0> 2.25 open
              }
           }
        cylinder {
           <-0.2,0,0> <0,0,0> 2.3
           }
        torus {
           2.3,.2
           rotate<0,0,90>
           }
        texture {
           col_silver
           }
        translate<0,0,0>
        }
  #end
  #macro SPC_FUSE_20X5(value)
     union {
        object {
        SPC_FUSE2_CUP()
        rotate<0,0,0> translate<-9.8,0,0>
        texture {
           col_silver
           }
        }
     // glass tube
     difference {
        cylinder {
           <-9,0,0> <9,0,0> 2.2
           }
        cylinder {
           <-9,0,0> <9,0,0> 1.9
           }
        texture {
           T_Glass3
           }
        }
     // fiber
     cylinder {
        <-9,-1.3,-1.5> <9,1.3,1.5> .07
        texture {
           col_silver
           }
        }
     object {
     SPC_FUSE2_CUP()
     rotate<0,180,0> translate<9.8,0,0>
     texture {
        col_silver
        }
     }
  // value
  #if (strlen(value)> 0)
     intersection {
        difference {
           cylinder {
              <-9,0,0> <9,0,0> 2.21
              }
           cylinder {
              <-9,0,0> <9,0,0> 2.2
              }
           }
        text {
           ttf besch_font value 2, 0
           scale 2 rotate<90,0,0> translate<-4,4,-.6>
           }
        pigment {
           White
           }
        }
  #end
  }
#end

union {
  object {
     SPC_FUSE2_HOLDER()
     rotate <0,180,0> translate <8,0,0>
     }
  object {
     SPC_FUSE2_HOLDER()
     rotate <0,0,0> translate <-8,0,0>
     }
  object {
     SPC_FUSE_20X5(value)
     translate <0,8,0>
     }
  }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//fuse:SHK20Q=SPC_FUSE_SHK20Q(:Fuse Holder SHK20Q
// end assignment
