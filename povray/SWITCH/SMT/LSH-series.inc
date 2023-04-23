/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Schurter SMT push button, LSH series (http://www.schurter.de/)
 * Oliver Saal (osaal@gmx.de) 22.09.2003
 * height  = height of button above pcb
 * dia_top = diameter at top end
 *
 * Replaced large internal macro by Round_Box(), 23.04.2023, wk
 * *****************************************************************************/
#macro SW_LSH_BASE(height,dia_top)
  union {
     object {
       Round_Box(
          <-6/2,0,-6/2>
          <+6/2,3,+6/2>
          0.2 0
          )
       }
     object {
       Round_Box(
          <-6/2,0,-6/2>
          <+6/2,0.6,+6/2>
          0.2 0
          )
       translate <0,3,0>
       texture {
          col_silver
          }
       }
     cylinder {
       <0,0,0> <0,0.2,0> 0.3
       translate <-2,3.6,-2>
       }
     cylinder {
       <0,0,0> <0,0.2,0> 0.3
       translate <-2,3.6,2>
       }
     cylinder {
       <0,0,0> <0,0.2,0> 0.3
       translate <2,3.6,-2>
       }
     cylinder {
       <0,0,0> <0,0.2,0> 0.3
       translate <2,3.6,2>
       }
     cone {
       <0,3.6,0> 1.7 <0,height-0.2,0> dia_top/2
       }
     torus {
       dia_top/2-0.2, 0.2
       translate <0,height-0.2,0>
       }
     cylinder {
       <0, height-0.2,0> <0, height,0>, dia_top/2-0.2
       }
     object {
       IC_SMD_PIN(1.5,2.0,0.7,0.3)
       translate <3,0,2.25>
       }
     object {
       IC_SMD_PIN(1.5,2.0,0.7,0.3)
       translate <3,0,-2.25>
       }
     object {
       IC_SMD_PIN(1.5,2.0,0.7,0.3)
       rotate <0,180,0>
       translate <-3,0,-2.25>
       }
     object {
       IC_SMD_PIN(1.5,2.0,0.7,0.3)
       rotate <0,180,0>
       translate <-3,0,2.25>
       }
     pigment {
       Gray30
       }
     }
#end

// Schurter LSH 1301.9314, Reichelt Taster 9314 Hoehe 4,3mm
#macro SWITCH_SMT_LSH43()
  SW_LSH_BASE(4.3, 3.4)
#end

// Schurter LSH 1301.9315, Reichelt Taster 9315 Hoehe 5,0mm
#macro SWITCH_SMT_LSH50()
  SW_LSH_BASE(5.0, 3.4)
#end

// Schurter LSH 1301.9316, Reichelt Taster 9316 Hoehe 7,0mm
#macro SWITCH_SMT_LSH70()
  SW_LSH_BASE(7.0, 3.2)
#end

// Schurter LSH 1301.9318, Reichelt Taster 9318 Hoehe 8,0mm
#macro SWITCH_SMT_LSH80()
  SW_LSH_BASE(8.0, 3.2)
#end

// Schurter LSH 1301.9319, Reichelt Taster 9319 Hoehe 9,5mm
#macro SWITCH_SMT_LSH95()
  SW_LSH_BASE(9.5, 3.0)
#end

// Schurter LSH 1301.9320, Reichelt Taster 9320 Hoehe 12,5mm
#macro SWITCH_SMT_LSH125()
  SW_LSH_BASE(12.5, 3.0)
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//???:LSH43=SWITCH_SMT_LSH43(:SMT push btn Schurter LSH 1301.9314 h=4.3mm
//???:LSH50=SWITCH_SMT_LSH50(:SMT push btn Schurter LSH 1301.9315 h=5.0mm
//???:LSH70=SWITCH_SMT_LSH70(:SMT push btn Schurter LSH 1301.9316 h=7.0mm
//???:LSH80=SWITCH_SMT_LSH80(:SMT push btn Schurter LSH 1301.9318 h=8.0mm
//???:LSH95=SWITCH_SMT_LSH95(:SMT push btn Schurter LSH 1301.9319 h=9.5mm
//???:LSH125=SWITCH_SMT_LSH125(:SMT push btn Schurter LSH 1301.9320 h=12.5mm
// end assignment
