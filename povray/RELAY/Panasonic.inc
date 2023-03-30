/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Panasonic Relay DK1a-L2
 * Uwe Lorenz <u.lorenz@er-dresden.net>
 * *****************************************************************************/
#macro SPC_RELAY_DK1A_L2()
  union {
     // Loetstift
     cylinder {
        <-3.76,-3.5,-11.5> <-3.76,1.1,-11.5> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,-11.5> <3.76,1.1,-11.5> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <-3.76,-3.5,-8.96> <-3.76,1.1,-8.96> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,-8.96> <3.76,1.1,-8.96> 0.3
        texture {
           col_silver
           }
        }
     //
     cylinder {
        <-3.76,-3.5,11.5> <-3.76,1.1,11.5> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,11.5> <3.76,1.1,11.5> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <-3.76,-3.5,3.88> <-3.76,1.1,3.88> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,3.88> <3.76,1.1,3.88> 0.5
        texture {
           col_silver
           }
        }
     //  Ende Loetstifte


     difference { // Grundkoerper
        box {
           <-6.25,0.5,-12.5> <6.25,12.0,12.5>
           }
        box {
           <-2.0,10.8,8.5> <2.0,12.1,12.6>
           }
        }

     box {
        <-6.25,0.0,-6.5> <-6.25,0.5,-5.0>
        }
     box {
        <6.25,0.0,-6.5> <6.25,0.5,-5.0>
        }
     box {
        <-6.25,0.0,7.5> <-6.25,0.5,6.0>
        }
     box {
        <6.25,0.0,7.5> <6.25,0.5,6.0>
        }
     cylinder {
        <0.0,10.7,10.5> <0.0,11.5,10.5> 1.0
        }
     //
     text {
        ttf besch_font "NAIS" 0, 0
        pigment {
           Gray80
           }
        scale<4,4,4> rotate<90,-90,0>
        translate<-1.5,12.05,-10>
        }
     text {
        ttf besch_font "DK1a-L2-5V" 0, 0
        pigment {
           Gray80
           }
        scale<2,2,2> rotate<90,-90,0>
        translate<1.5,12.05,-10>
        }
     text {
        ttf besch_font "ADE129" 0, 0
        pigment {
           Gray80
           }
        scale<1,1,1> rotate<90,-90,0>
        translate<3.0,12.05,-10>
        }
     text {
        ttf besch_font "10A250V~(COS°=1.0)" 0, 0
        pigment {
           Gray80
           }
        scale<1,1,1> rotate<90,-90,0>
        translate<4.0,12.05,-10>
        }
     text {
        ttf besch_font "SPULE:5V=" 0, 0
        pigment {
           Gray80
           }
        scale<1,1,1> rotate<90,-90,0>
        translate<5.0,12.05,-10>
        }
     text {
        ttf besch_font "JAPAN" 0, 0
        pigment {
           Gray80
           }
        scale<2,2,2> rotate<90,-90,0>
        translate<-3.4,12.05,5>
        }
     pigment {
        Gray20
        }
     translate<0,0.2,0>
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_RELAY_DK1A_L2(:Panasonic Relay DK1a-L2
// end assignment
