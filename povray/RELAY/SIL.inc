/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * A reed relay by Stefan Seegel (dahamm@gmx.net)
 * *****************************************************************************/
#macro REED_RELAY_SIL_BASE(value,L,W,H)
  #local pin_l = 3.5;

  union {
     union {
        difference {
           box {
              <0,2,0> <0.6,-pin_l,0.25>
              }
           box {
              <0,0,-1> <1,1,1>
              rotate<0,0,-45> translate<0.3,-pin_l,0>
              }
           box {
              <0,0,-1> <-1,1,1>
              rotate<0,0,45> translate<0.3,-pin_l,0>
              }
           translate<L/2-7.92,0,W/2-0.125>
           }
        difference {
           box {
              <0,2,0> <0.6,-pin_l,0.25>
              }
           box {
              <0,0,-1> <1,1,1>
              rotate<0,0,-45> translate<0.3,-pin_l,0>
              }
           box {
              <0,0,-1> <-1,1,1>
              rotate<0,0,45> translate<0.3,-pin_l,0>
              }
           translate<L/2-2.84,0,W/2-0.125>
           }
        difference {
           box {
              <0,2,0> <0.6,-pin_l,0.25>
              }
           box {
              <0,0,-1> <1,1,1>
              rotate<0,0,-45> translate<0.3,-pin_l,0>
              }
           box {
              <0,0,-1> <-1,1,1>
              rotate<0,0,45> translate<0.3,-pin_l,0>
              }
           translate<L/2+2.24,0,W/2-0.125>
           }
        difference {
           box {
              <0,2,0> <0.6,-pin_l,0.25>
              }
           box {
              <0,0,-1> <1,1,1>
              rotate<0,0,-45> translate<0.3,-pin_l,0>
              }
           box {
              <0,0,-1> <-1,1,1>
              rotate<0,0,45> translate<0.3,-pin_l,0>
              }
           translate<L/2+7.32,0,W/2-0.125>
           }
        texture {
           col_silver
           }
        }
     difference {
        box {
           <0,0,0> <L,H,W>
           }
        box {
           <0,-1,0> <-2,H+2,W>
           rotate<0,11,0> translate<0,0,W/2+0.3>
           }
        box {
           <0,-1,0> <-2,H+2,-W>
           rotate<0,-11,0> translate<0,0,W/2-0.3>
           }
        box {
           <0,-1,0> <2,H+2,-W>
           rotate<0,11,0> translate<L,0,W/2-0.3>
           }
        box {
           <0,-1,0> <2,H+2,W>
           rotate<0,-11,0> translate<L,0,W/2+0.3>
           }
        box {
           <-1,0,0> <L+2,2,-W>
           rotate<-15,0,0> translate<0,H,W/2-0.3>
           }
        box {
           <-1,0,0> <L+2,2,W>
           rotate<15,0,0> translate<0,H,W/2+0.3>
           }
        box {
           <0,0,-1> <-3,3,1>
           translate<1.4,H-2.6,0>
           }
        box {
           <0,0,0> <L-3,-2,-W>
           rotate<11,0,0> translate<1.5,0.5,W/2-0.1>
           }
        box {
           <0,0,0> <L-3,-2,W>
           rotate<-11,0,0> translate<1.5,0.5,W/2+0.1>
           }
        pigment {
           Gray20
           }
        }
     text {
        ttf besch_font "MEDER electronic" 0.5,0
        pigment {
           White
           }
        scale<1.7,2,1.7> translate<2,5,0>
        }
     text {
        ttf besch_font value 0.5,0
        pigment {
           White
           }
        scale<1.7,2,1.7> translate<2,2,0>
        }
     translate<-L/2, 0, -W/2>
     rotate<0,0,0>
     }
#end

#macro SPC_RELAY_SIL(value)
  REED_RELAY_SIL_BASE(value,19.8,5.08,7.8)
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//relay:HE3621=SPC_RELAY_SIL(:Reed relay SIL package
// end assignment
