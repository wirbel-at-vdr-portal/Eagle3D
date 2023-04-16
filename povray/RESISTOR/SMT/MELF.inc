/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMT MELF resistor. Arguments
 *   - Value1
 *   - Value2
 *   - Multiplier
 *   - Tolerance
 * are 4 band resistor value colour codes,
 *   see -> doc/Resistor Color Codes/resistor_color_codes_chart.png
 *   see -> TOOLS/colors.inc, "Resistor value color codes"
 ******************************************************************************/
#macro MELF_resistor(Value1, Value2, Multiplier, Tolerance)
  union {
     object {
        Round_Cylinder_Union(<-1.75,0,0> <-0.9,0>0.7,0.2)
        texture {
           col_silver
           }
        }
     object {
        Round_Cylinder_Union(<0.9,0> <1.75,0,0>0.7,0.2)
        texture {
           col_silver
           }
        }
     cylinder {
        <-1.2,0,0> <1.2,0,0>0.69
        pigment {
           rgb <0.36,0.42,0.42>
           }
        finish {
           phong 0.5
           ambient (0.1 * global_ambient_mul)
           }
        }
     // 4-band resistor color coding:
     union {
        torus {
           0.69, 0.01
           texture {
              Value1
              }
           scale <1,12,1>
           rotate <90,90,0>
           translate <0.8,0,0>
           }
        torus {
           0.69, 0.01
           texture {
              Value2
              }
           scale <1,12,1>
           rotate <90,90,0>
           translate <0.35,0,0>
           }
        torus {
           0.69, 0.01
           texture {
              Multiplier
              }
           scale <1,12,1>
           rotate <90,90,0>
           translate <-0.12,0,0>
           }
        torus {
           0.685, 0.01
           texture {
              Tolerance
              }
           scale <1,20,1>
           rotate <90,90,0>
           translate <-0.7,0,0>
           }
        finish {
           phong 1.0
           ambient (0.1 * global_ambient_mul)
           }
        }
     }
#end

#macro RES_SMD_MELF_0102(Value1, Value2, Multiplier, Tolerance)
   MELF_resistor(Value1, Value2, Multiplier, Tolerance)
   scale <0.6143,0.786,0.786>
   translate <0,0.55,0>
#end

#macro RES_SMD_MELF_0204(Value1, Value2, Multiplier, Tolerance)
   MELF_resistor(Value1, Value2, Multiplier, Tolerance)
   translate <0,0.7,0>
#end

#macro RES_SMD_MELF_0207(Value1, Value2, Multiplier, Tolerance)
  MELF_resistor(Value1, Value2, Multiplier, Tolerance)
  scale <1.614,1.5715,1.5715>
  translate <0,1.1,0>
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:MINI_MELF-0102R=RES_SMD_MELF_0102(:SMT resistor MELF MMU 0102
//rcl:MINI_MELF-0102W=RES_SMD_MELF_0102(:SMT resistor MELF MMU 0102
//rcl:MINI_MELF-0204R=RES_SMD_MELF_0204(:SMT resistor MELF MMA 0204
//rcl:MINI_MELF-0204W=RES_SMD_MELF_0204(:SMT resistor MELF MMA 0204
//rcl:MINI_MELF-0207R=RES_SMD_MELF_0207(:SMT resistor MELF MMB 0207
//rcl:MINI_MELF-0207W=RES_SMD_MELF_0207(:SMT resistor MELF MMB 0207
// end assignment
