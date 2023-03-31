/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Schrack Relay RY2
 * Anderas Fecht
 * *****************************************************************************/
#macro SPC_RELAY_RY2(value)
  union {
     // begin Loetstifte
     cylinder {
        <-3.76,-3.5,-12.5>  <-3.76,1.1,-12.5> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        < 3.76,-3.5,-12.5>  < 3.76,1.1,-12.5> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <-3.76,-3.5,13>  <-3.76,1.1,13> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <-3.76,-3.5,7> <-3.76,1.1,7> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,9.5> < 3.76,1.1,9.5> 0.5
        texture {
           col_silver
           }
        }
     // end Loetstifte

     // Grundkoerper
     difference {
        box {
           <-5,0.5,-14> <5,12.0,14>
           }
        box {
           <-2.0,10.8,11.5> <3.0,12.1,14.1>
           }
        box {
           <-2.0 ,7,13.9> <-1.0,12,14.1>
           }
        box {
           <-0.66,7,13.9> <0.33,12,14.1>
           }
        box {
           <0.66,7,13.9> <1.66,12,14.1>
           }
        box {
           <2,7,13.9> <3,12,14.1>
           }
        box {
           <0,10,16> <6,12,20>
           rotate<45,0,0>
           translate <3,17,-6.5>
           }
        cylinder {
           <-3.5,10.7,12.5> <-3.5,12.5,12.5>1
           }
        sphere {
           <0,14.5,0>3
           }
        }
     cylinder {
        <0,10,0> <0,12,0> 0.4
        }
     cylinder {
        <0.0,10.7,13> <0.0,11.5,13> 0.6
        }
     cylinder {
        <-3.5,10.7,12.5> <-3.5,12,12.5> 0.4
        }
     // Ende Grundkoerper

     text {
        ttf besch_font "SCHRACK" 0, 0
        pigment {
           Black
           }
        scale<2,3,3> rotate<90,-90,0>
        translate<-1.5,12.05,-13>
        }
     text {
        ttf besch_font value 0, 0
        pigment {
           Black
           }
        scale<2,2,2> rotate<90,-90,0>
        translate<1.5,12.05,-13>
        }
     text {
        ttf besch_font "10A250V~" 0, 0
        pigment {
           Black
           }
        scale<1.5,1.5,1.5> rotate<90,-90,0>
        translate<4.0,12.05,-13>
        }
     pigment {
        rgb <1, 0.25, 0.10>
        }
     translate<0,0.2,0>
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_RELAY_RY2(:Schrack Relay RY2
// end assignment
