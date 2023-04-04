/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Toshiba horizontal laser transceiver/receiver TORX173/TOTX173
 * Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * wk: simplify value print
 * Rev. 1.1  04.04.2023
 ******************************************************************************/
#macro TOxX173(value)
  union {
     union {
        difference {
           box { <-6.5,0.5,+5.5> <+6.5,8.5,-10> }
           box { <-6.1,-0.1,+3.3> <-6.6,8.6,+4.5> }
           box { <+6.1,-0.1,+3.3> <+6.6,8.6,+4.5> }
           box { <-6.6,+8.1,+3.3> <+6.6,8.6,+4.5> }
           cylinder {<-5.2,1,-4.2> <-5.1,8.6,-4.2>,0.3 }
           cylinder {<+5.2,1,-4.2> <+5.1,8.6,-4.2>,0.3 }
           box { <-1.35,-0.1,-6.5> <+1.35,8.6,-7.7> }
           box { <-5.1,+1.6,-5.4> <-6.6,7.5,-10.1> }
           box { <+5.1,+1.6,-5.4> <+6.6,7.5,-10.1> }
           box { <-4.3,-0.1,-5.4> <-5.101,6.5,-8.4> }
           box { <+4.3,-0.1,-5.4> <+5.101,6.5,-8.4> }
           box { <+3.1,+2.7,-4.2> <-3.1,+7.5,-10.1> }
           box { <+1.7,+1.3,-4.2> <-1.7,+7.5,-10.1> }
           box { <-1,-1,-4.2> <+1,+1,-10.1> rotate 45*z translate <+1.7,2.7,0> } 
           box { <-1,-1,-4.2> <+1,+1,-10.1> rotate 45*z translate <-1.7,2.7,0> } 
           cylinder { <-3,+4.5,-4.2> <-3,+4.5,-10.1>,1 }
           cylinder { <+3,+4.5,-4.2> <+3,+4.5,-10.1>,1 }
           }
        difference {
           box { <-2,6.5,-8.1> <+2,2.5,0> }
           box { <-1,-0.5,-4.2> <+1,+0.5,-10.1> rotate  45*z translate <+2,2.7,0> }
           box { <-1,-0.5,-4.2> <+1,+0.5,-10.1> rotate -45*z translate <-2,2.7,0> }
           cylinder {<0,+4.3,-4.2> <0,+4.3,-10.1>,1 }
           pigment {
              Gray20
              }
           }
        box { <-3.81-0.6,0,+5.5,> <-3.81+0.6,0.5,-10> }
        box { <+3.81-0.6,0,+5.5,> <+3.81+0.6,0.5,-10> }
        pigment {
           Gray30
           }
        }
     text {
        ttf global_fontfile_arial_bold value 0.5,0
        pigment {
           Gray60
           }
        scale <2.0,4,0.1>
        rotate <90,180,0>
        translate <+5,8.51,-0>
        }
     text {
        ttf global_fontfile_arial_bold "JAPAN" 0.5,0
        pigment {
           Gray60
           }
        scale <1,2,0.1>
        rotate <90,180,0>
        translate <+1.5,8.51,2>
        }
     union {
        cylinder {<-5.2,-3.5,-4.2> <-5.1,1,-4.2>,0.3}
        cylinder {<+5.2,-3.5,-4.2> <+5.1,1,-4.2>,0.3}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate +1.27*x}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate +3.81*x}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate -1.27*x}
        box {<-0.25,-3.5,-0.125> <+0.25,1,+0.125> translate -3.81*x}
        texture {
           col_silver
           }
        }
     }
#end

#macro SPC_TOTX173()
  TOxX173("TOTX173")
#end

#macro SPC_TORX173()
  TOxX173("TORX173")
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_OPTO_TOTX173(:Laser transmitter
//=SPC_OPTO_TORX173(:Laser receiver
// end assignment
