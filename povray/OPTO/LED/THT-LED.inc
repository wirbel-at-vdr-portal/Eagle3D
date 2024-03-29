/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * THT LED 3mm diameter, round.
 * 29.04.2023, wk
 ******************************************************************************/
#macro LED_THT_3mm(Color,Alpha,Height)
  #local D = 2.93;
  #local H = 5.30;
  #local D2 = 3.80;
  #local H2 = 1.00;

  // the 3mm variant does not fit directly on PCB,
  // as the pins are z-shape bend.
  #if (Height < 0.6)
     #local Height = 0.6;
  #end

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
              <D/2 -0.05,Height-1,-D/2>
              <D2/2+1.0,Height+2,+D/2>
              }
           }
        sphere {
           <0,Height+H-D/2,0>
           D/2
           }
        sphere {
           <-1.54/2,Height+0.6,0>
           1.5/2
           }
        sphere {
           <+1.54/2,Height+0.6,0>
           1.5/2
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
                    <-(D-0.5)/2,0.50,-0.5/2>
                    <+(D-0.5)/2,3.50,+0.5/2>
                    0.18 0
                    )
                 box {
                    <-2.54/2-0.1,3.00,-0.6/2>
                    <+2.54/2+0.5,4.00,+0.6/2>
                    }
                 }
              cone {
                 <0.1,3.00,0> 1.4
                 <0.1,2.00,0> 0.5
                 }
              }
           cone {
              <0.1,3.00,0> 1.0
              <0.1,2.10,0> 0.2
              }
           box {
              <-2.54/2-0.5,2.50,-0.6/2>
              <-2.54/2    ,4.00,+0.6/2>
              }
           box {
              <-0.5/2,+1.8/2,-0.6/2>
              <+0.5/2,-1.8/2,+0.6/2>
              rotate <0,0,45>
              translate <-1,2,0>
              }
           box {
              <-2.54/2+0.5,0    ,-0.6/2>
              <-2.54/2+1.0,1.70,+0.6/2>
              }
           cylinder {
              <-2.54/2-1.0,1.50,-0.6/2>
              <-2.54/2-1.0,1.50,+0.6/2>
              0.9/2
              }
           cylinder {
              <+2.54/2+1.0,1.50,-0.6/2>
              <+2.54/2+1.0,1.50,+0.6/2>
              0.9/2
              }
           scale 0.7
           translate <0,Height+0.2,0>
           }
        box {
           <-0.5/2-2.54/2,-3        ,-0.5/2>
           <+0.5/2-2.54/2,Height-0.6,+0.5/2>
           }
        box {
           <-0.5/2+2.54/2,-3        ,-0.5/2>
           <+0.5/2+2.54/2,Height-0.6,+0.5/2>
           }
        box {
           <-0.5/2-2.54/2,Height-0.6-0.5/2,-0.5/2>
           <+0.5/2-1.50/2,Height-0.6+0.5/2,+0.5/2>
           }
        box {
           <+0.5/2+2.54/2,Height-0.6-0.5/2,-0.5/2>
           <-0.5/2+1.50/2,Height-0.6+0.5/2,+0.5/2>
           }
        box {
           <-0.5/2-1.50/2,Height-0.6,-0.5/2>
           <+0.5/2-1.50/2,Height+0.7,+0.5/2>
           }
        box {
           <-0.5/2+1.50/2,Height-0.6,-0.5/2>
           <+0.5/2+1.50/2,Height+0.7,+0.5/2>
           }
        #if (Height > 2.9)
           box {
              <-0.6/2+2.54/2-0.05,Height-3.5-1.2/2,-0.5/2>
              <+0.6/2+2.54/2-0.05,Height-3.5+1.2/2,+0.5/2>
              }
           box {
              <-0.6/2-2.54/2+0.05,Height-3.5-1.2/2,-0.5/2>
              <+0.6/2-2.54/2+0.05,Height-3.5+1.2/2,+0.5/2>
              }
        #end
        texture {
           col_silver
           }
        }
     }
#end


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
 * THT LED 10mm diameter, round.
 * 29.04.2023, wk
 ******************************************************************************/
#macro LED_THT_10mm(Color,Alpha,Height)
  #local D = 9.93;
  #local H = 13.50;
  #local D2 = 11.00;
  #local H2 = 2.00;

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
 * THT LED, rectangular 2.5mm x 2.5mm
 * BuFran <BuFran@hi-web.cz>
 * 29.04.2023 - switched case to Round_Box(), wk
 ******************************************************************************/
#macro LED_THT_025x025(Color,Alpha,height)
  union {
     #local w = 2.5;
     #local h = 2.5;
     object {
        Round_Box (
           <0,0,0> <h,7,w>
           0.05
           1
           )
        pigment {
           Color
           filter Alpha
           }
        translate <-h/2,height-7,-w/2>
        }
     #if (pin_short = off)
        #local pp = -30.0 + height;
     #else
        #local pp = -pcb_height - pin_length - 8;
     #end
     box {
        <0.24,height+3,0.24> <-0.24,pp,-0.24>
        translate <-1.27,-7,0>
        }
     box {
        <0.24,height+3,0.24> <-0.24,pp,-0.24>
        translate <1.27,-7,0>
        }
     box {
        <-0.34,0,-0.24> <0.34,1,0.24>
        translate <-1.27,height-9,0>
        }
     box {
        <-0.34,0,-0.24> <0.34,1,0.24>
        translate <1.27,height-9,0>
        }
     prism {
        linear_spline
        -0.24 0.24
        7
        <0,0>
        <0,6>
        <5,6>
        <3,1>
        <1,1>
        <1,0>
        <0,0>
        scale <0.48,1,0.48>
        rotate <-90,0,0>
        translate <-1.51,height-6,0>
        }
     prism {
        linear_spline
        -0.24 0.24
        7
        <0,0>
        <0,6>
        <-0.5,6>
        <-2.5,1>
        <-1,1>
        <-1,0>
        <0,0>
        scale <0.48,1,0.48>
        rotate <-90,0,0>
        translate <1.51,height-6,0>
        }
     cone {
        <0,-0.8,0>, 0,
        <0,0,0>, 0.6
        translate <0,height-3.1,0>
        }
     pigment {
        Silver
        }
     translate <0,8,0>
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//led:LED3MM=LED_THT_3mm(:THT LED 3mm
//led:LED5MM=LED_THT_5mm(:THT LED 5mm
//led:LED10MM=LED_THT_10mm(:THT LED 10mm
//led:LD260=LED_THT_025x025(:THT LED 2.5mm x 2.5mm
// end assignment
