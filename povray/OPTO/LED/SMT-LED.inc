/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Chip LED with Right Angle Lens, EVERLIGHT 12-215SURC/S530-A2/TR8
 * everyone1@freenet.de
 ******************************************************************************/
#macro LED_SMT_SIDE_021x060(Color,Alpha,unused)
  union {
     difference {
        merge {
           cylinder {
              <-0.35, 0.01, 0.25> <-0.35, 0.61, 0.25> 0.5
              }
           cylinder {
              < 0.35, 0.01, 0.25> < 0.35, 0.61, 0.25> 0.5
              }
           box {
              <-0.35, 0.01, 0.25> < 0.35, 0.61, 0.75>
              }
           texture {
              pigment {
                 Color
                 filter Alpha
                 }
              }
           }
        box {
           <-1.0, 0, -0.25> < 1.0, 0.62, 0.25>
           }
        texture {
           pigment {
              Color filter Alpha
              }
           }
        }
     difference {
        union {
           box {
              <-1.05, 0.015,-0.27> <-0.75, 0.605, 0.27>
              }
           box {
              < 1.05, 0.015,-0.27> < 0.75, 0.605, 0.27>
              }
           }
        box {
           <-1.03, 0.0, -0.25> < 1.03, 0.62, 0.25>
           }
        texture {
           col_silver
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     box {
        <-1.03, 0.01, -0.25> < 1.03, 0.61, 0.25>
        texture {
           pigment {
              White
              }
           }
        }
     box {
        <-0.65, 0.02,-0.251> < 0, 0.60,-0.25>
        texture {
           pigment {
              color rgb < 0, 0.5, 0>
              }
           }
        }
     }
#end


/*******************************************************************************
 * Chip LEDs 0603, 0805, 1206 with convex or concave style endcaps
 * 29.04.2023, wk
 ******************************************************************************/
#macro LED_CHIP_BASE(Type, Color, Alpha)
  #local A = 2.00;
  #local B = 1.25;
  #local C = 0.75;
  #local D = 0.25;
  #local E = 1.30;
  #local F = 1.20;
  #local G = 0.40;
  #local S = 0.40;
  #local T = 0.20;
  #local U = 0.70;

  #local termination = "convex";

  #if ((Type = "0603_concave") | (Type = "0805_concave") | (Type = "1206_concave"))
      #local termination = "concave";
  #end

  #if ((Type = "0603_concave") | (Type = "0603_convex"))
    #local A = 1.60;
    #local B = 0.80;
    #local C = 0.75;
    #local D = 0.25;
    #local E = 1.20;
    #local F = 1.10;
    #local G = 0.30;
  #end

  #if ((Type = "1206_concave") | (Type = "1206_convex"))
    #local A = 3.20;
    #local B = 1.60;
    #local C = 0.75;
    #local D = 0.25;
    #local E = 2.00;
    #local F = 1.90;
    #local G = 0.50;
  #end

  union {
     #if (termination = "convex")
        union {
           box {
              <-(A-0.1)/2, +0.05,-B/2>
              <+(A-0.1)/2,D-0.05,+B/2>
              pigment {
                 White * 0.8
                 }
              }
           GRID(
              box {
                 <-G/2,0,-B/2>
                 <+G/2,D,+B/2>
                 },
              A-G,2,1
              )
           texture {
              col_gold
              }
           }
     #else
        difference {
           union {
              box {
                 <-A/2, +0.05,-B/2>
                 <+A/2,D-0.05,+B/2>
                 pigment {
                    White * 0.8
                    }
                 }
              object {
                 GRID (
                    box {
                       <-G/2,0  ,-B/2>
                       <+G/2,0.1,+B/2>
                       },
                    A-G,2,1
                    )
                 texture {
                    col_gold
                    }
                 }
              difference {
                 GRID (
                    box {
                       <-G/2,D-0.02,-B/2>
                       <+G/2,D    ,+B/2>
                       },
                    A-G,2,1
                    )
                 Round_Box (
                    <-A/2-G  ,D-0.03,-B/2-0.1>
                    <-A/2+G/2,D     ,-B/8>
                    0.2 0
                    )
                 Round_Box (
                    <-A/2-G  ,D-0.03,+B/2+0.1>
                    <-A/2+G/2,D     ,+B/8>
                    0.2 0
                    )
                 Round_Box (
                    <+A/2+G  ,D-0.03,-B/2-0.1>
                    <+A/2-G/2,D     ,-B/8>
                    0.2 0
                    )
                 Round_Box (
                    <+A/2+G  ,D-0.03,+B/2+0.1>
                    <+A/2-G/2,D     ,+B/8>
                    0.2 0
                    )
                 texture {
                    col_gold
                    }
                 }
              }
           GRID (
              cylinder {
                 <0, -0.1,0>
                 <0,D+0.1,0>
                 B/6
                 },
              A,2,1
              ) 
           texture {
              col_gold
              }
           }
     #end
     box {
        <-S/2,-S/2,-S/2>
        <+S/2,+S/2,+S/2>
        translate <-0.13,D,0>
        pigment {
           Gray60
           }
        }
     box {
        <-T/2,-0.05/2,-T/2>
        <+T/2,+0.05/2,+T/2>
        translate <-0.13,D+S,0>
        texture {
           col_gold
           }
        }
     box {
        <-U/2,-0.05/2,-U/2>
        <+U/2,+0.05/2,+U/2>
        translate <0,D,0>
        texture {
           col_gold
           }
        }
     prism {
        -B/2, +B/2,
        5,
        <-E/2,D>,
        <-F/2,C>,
        <+F/2,C>,
        <+E/2,D>,
        <-E/2,D>
        rotate <-90,0,0>
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
     }
#end

#macro LED_SMT_1206_convex(Color, Alpha, unused)
  LED_CHIP_BASE("1206_convex", Color, Alpha)
#end

#macro LED_SMT_1206_concave(Color, Alpha, unused)
  LED_CHIP_BASE("1206_concave", Color, Alpha)
#end

#macro LED_SMT_0805_convex(Color, Alpha, unused)
  LED_CHIP_BASE("0805_convex", Color, Alpha)
#end

#macro LED_SMT_0805_concave(Color, Alpha, unused)
  LED_CHIP_BASE("0805_concave", Color, Alpha)
#end

#macro LED_SMT_0603_convex(Color, Alpha, unused)
  LED_CHIP_BASE("0603_convex", Color, Alpha)
#end

#macro LED_SMT_0603_concave(Color, Alpha, unused)
  LED_CHIP_BASE("0603_concave", Color, Alpha)
#end

#macro LED_SMT_1206_convex_rotate(Color, Alpha, unused)
  LED_CHIP_BASE("1206_convex", Color, Alpha)
  rotate <0,90,0>
#end

#macro LED_SMT_1206_concave_rotate(Color, Alpha, unused)
  LED_CHIP_BASE("1206_concave", Color, Alpha)
  rotate <0,90,0>
#end

#macro LED_SMT_0805_convex_rotate(Color, Alpha, unused)
  LED_CHIP_BASE("0805_convex", Color, Alpha)
  rotate <0,90,0>
#end

#macro LED_SMT_0805_concave_rotate(Color, Alpha, unused)
  LED_CHIP_BASE("0805_concave", Color, Alpha)
  rotate <0,90,0>
#end

#macro LED_SMT_0603_convex_rotate(Color, Alpha, unused)
  LED_CHIP_BASE("0603_convex", Color, Alpha)
  rotate <0,90,0>
#end

#macro LED_SMT_0603_concave_rotate(Color, Alpha, unused)
  LED_CHIP_BASE("0603_concave", Color, Alpha)
  rotate <0,90,0>
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=LED_SMT_SIDE_021x060(:SMT side LED 2.1mm x 0.6mm
//led:CHIPLED_0603=LED_SMT_0603_concave_rotate(:SMT LED 0603:
//led:CHIPLED-0603-TTW=LED_SMT_0603_concave_rotate(:SMT LED 0603:
//led:CHIPLED_0805=LED_SMT_0805_concave_rotate(:SMT LED 0805:
//led:CHIPLED_1206=LED_SMT_1206_concave_rotate(:SMT LED 1206:
//led:LED0805=LED_SMT_0805_concave_rotate(:SMT LED 0805:
//led:SMARTLED-TTW=LED_SMT_0603_convex_rotate(:SMT LED 0603:
//led:CHIP-LED0603=LED_SMT_0603_convex_rotate(:SMT LED 0603:
//led:CHIP-LED0805=LED_SMT_0805_convex_rotate(:SMT LED 0805:
//led:SML0603=LED_SMT_0603_concave(:SMT LED 0603:
//led:SML0805=LED_SMT_0805_concave(:SMT LED 0805:
//led:SML1206=LED_SMT_1206_concave(:SMT LED 1206:
// end assignment
