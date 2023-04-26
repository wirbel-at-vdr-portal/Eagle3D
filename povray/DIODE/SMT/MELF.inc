/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * MELF, MiniMELF, MicroMELF
 * 26.04.2023 written from scratch. wk
 *
 * MELF Synonyms:
 *  - MMB
 *  - SOD-106
 *  - DO-213AB
 *  - MLL41
 * MiniMELF Synonyms:
 *  - MMA
 *  - SOD-80 (Small-outline Diode 80)
 *  - DO-213AA
 *  - 100H01 (IEC package outline code)
 *  - LL-34 (Littelfuse)
 *  - LLDS (Nexperia)
 *  - SOD-80C (Nexperia)
 * MicroMELF Synonyms:
 *  - none known
 ******************************************************************************/

#macro MELF_BASE(value, Type)
  // MiniMELF as default.
  #local A = 3.50;
  #local B = 1.60;
  #local C = 0.43;

  #if (Type = "MELF")
     #local A = 5.00;
     #local B = 2.50;
     #local C = 0.55;
  #end

  #if (Type = "MicroMELF")
     #local A = 1.90;
     #local B = 1.15;
     #local C = 0.20;
  #end

  union {
     object {
        Round_Cylinder(
           <-(A-2*C)/2,B/2,0>,
           <+(A-2*C)/2,B/2,0>,
           B/2, B/4, 0
           )
        material {
           texture {
              NBglass
              }
           interior {
              I_Glass
              }
           }
        }
     difference {
        object {
           Round_Cylinder(
              <-(A-4*C)/2,B/2,0>,
              <+(A-4*C)/2,B/2,0>,
              (B*0.6)/2, B/8, 0
              )
           }
        cylinder {
           <-C/5,B/2,0>
           <+C/5,B/2,0>
           A
           }
        texture {
           T_Copper_3A
           finish {
              phong 1
              }
           }
        }
     object {
        Round_Cylinder(
           <-(A-2*C)/2-0.01,B/2,0>,
           <-(A-2*C)/2+2.5*C ,B/2,0>,
           B/2+0.01, B/4, 0
           )
        pigment {
          White * 0.10 // this is actually dark grey
          }
        }
     GRID(
        object {
           Round_Cylinder(
              <-C/2,B/2,0>,
              <+C/2,B/2,0>,
              B/2, C/4, 0
              )
           texture {
              col_silver
              }
           },
        A-C,2,1
        )
     }
#end

#macro DIODE_SMT_MELF(value)
  MELF_BASE(value, "MELF")
#end

#macro DIODE_SMT_MINIMELF(value)
  MELF_BASE(value, "MiniMELF")
#end

#macro DIODE_SMT_MICROMELF(value)
  MELF_BASE(value, "MicroMELF")
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//diode:SOD106-R=DIODE_SMT_MELF(:SMT diode MELF
//diode:SOD106-W=DIODE_SMT_MELF(:SMT diode MELF
//diode:SOD106A-R=DIODE_SMT_MELF(:SMT diode MELF
//diode:SOD106A-W=DIODE_SMT_MELF(:SMT diode MELF
//diode:MELF-MLL41=DIODE_SMT_MELF(:SMT diode MELF
//diode:MINIMELF=DIODE_SMT_MINIMELF(:SMT diode MiniMELF
//diode:MELF-MLL34=DIODE_SMT_MINIMELF(:SMT diode MiniMELF
//diode:SOD80=DIODE_SMT_MINIMELF(:SMT diode MiniMELF
//diode:SOD80C=DIODE_SMT_MINIMELF(:SMT diode MiniMELF
//diode:MICROMELF-R=DIODE_SMT_MICROMELF(:SMT diode MicroMELF
//diode:MICROMELF-W=DIODE_SMT_MICROMELF(:SMT diode MicroMELF
// end assignment
