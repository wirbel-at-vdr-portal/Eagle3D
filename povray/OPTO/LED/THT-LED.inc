/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT LED 5mm diameter, round.
 * 29.04.2023, wk
 ******************************************************************************/
#macro LED_THT_5mm(Color,Alpha,Height)
  #local D = 4.93;
  #local H = 8.60;
  #local D2 = 5.80;
  #local H2 = 1.00;

  union {
     merge {
        cylinder {
           <0,Height,0>
           <0,Height+H-D/2,0>
           D/2
           }
        difference {
           Round_Cylinder (
              <0,Height,0>
              <0,Height+H2,0>
              D2/2
              0.18
              1
              )
           box {
              <D/2 -0.1,Height-1,-D/2>
              <D2/2+1.0,Height+2,+D/2>
              }
           }
        sphere {
           <0,Height+H-D/2,0>
           D/2
           }
        sphere {
           <-2.54/2,Height+1,0>
           2.5/2
           }
        sphere {
           <+2.54/2,Height+1,0>
           2.5/2
           }
        material {
           texture {
              pigment {
                 color rgbf <Color.red,Color.green,Color.blue,Alpha>
                 }
              finish {
                 diffuse 0.1
                 reflection 0.2
                 roughness 0.003
                 phong 1
                 phong_size 400
                 }
              }
           interior {
              ior 1.5
              caustics 0.5
              }
           }
        }
     union {
        difference {
           union {
              difference {
                 Round_Box (
                    <-(D-0.5)/2,Height+0.50,-0.5/2>
                    <+(D-0.5)/2,Height+3.50,+0.5/2>
                    0.18 0
                    )
                 box {
                    <-2.54/2-0.1,Height+3.00,-0.6/2>
                    <+2.54/2+0.5,Height+4.00,+0.6/2>
                    }
                 }
              cone {
                 <0.1,Height+3.00,0> 1.4
                 <0.1,Height+2.00,0> 0.5
                 }
              }
           cone {
              <0.1,Height+3.00,0> 1.0
              <0.1,Height+2.10,0> 0.2
              }
           box {
              <-2.54/2-0.5,Height+2.50,-0.6/2>
              <-2.54/2    ,Height+4.00,+0.6/2>
              }
           box {
              <-0.5/2,+1.8/2,-0.6/2>
              <+0.5/2,-1.8/2,+0.6/2>
              rotate <0,0,45>
              translate <-1,Height+2,0>
              }
           box {
              <-2.54/2+0.5,Height     ,-0.6/2>
              <-2.54/2+1.0,Height+1.70,+0.6/2>
              }
           cylinder {
              <-2.54/2-1.0,Height+1.50,-0.6/2>
              <-2.54/2-1.0,Height+1.50,+0.6/2>
              0.9/2
              }
           cylinder {
              <+2.54/2+1.0,Height+1.50,-0.6/2>
              <+2.54/2+1.0,Height+1.50,+0.6/2>
              0.9/2
              }
           }
        box {
           <-0.5/2-2.54/2,-3        ,-0.5/2>
           <+0.5/2-2.54/2,Height+0.6,+0.5/2>
           }
        box {
           <-0.5/2+2.54/2,-3        ,-0.5/2>
           <+0.5/2+2.54/2,Height+0.6,+0.5/2>
           }
        #if (Height > 2.9)
           box {
              <-0.6/2+2.54/2,Height-3.5-1.2/2,-0.5/2>
              <+0.6/2+2.54/2,Height-3.5+1.2/2,+0.5/2>
              }
           box {
              <-0.6/2-2.54/2,Height-3.5-1.2/2,-0.5/2>
              <+0.6/2-2.54/2,Height-3.5+1.2/2,+0.5/2>
              }
        #end
        texture {
           col_silver
           }
        }
     }
#end


/*******************************************************************************
*  no typos below please.
 * *****************************************************************************/
// begin assignment
//led:LED5MM=LED_THT_5mm(:THT LED 5mm
// end assignment
