/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * DO-214 case
 * Tilmann Reh <tilmann.reh@autometer.de>
 * heavily modified, 26.04.2023, wk
 * four variants
 *   -AC (SMA)
 *   -AA (SMB)
 *   -AB (SMC)
 *   -BA (GF1)
 * Params
 *   - value text on device
 *   - Type text identifier for dimensions
 ******************************************************************************/
#macro DO214_BASE(value,Type)
  #if (Type = "SMA")
     #local A = (2.29+2.92)/2;
     #local B = (4.00+4.60)/2;
     #local C = (1.27+1.63)/2;
     #local D = (0.15+0.31)/2;
     #local E = (4.80+5.59)/2;
     #local G = (0.05+0.20)/2;
     #local H = (0.76+1.52)/2;
     #local J = (2.01+2.30)/2;
  #end
  #if (Type = "SMB")
     #local A = (3.30+3.94)/2;
     #local B = (4.06+4.57)/2;
     #local C = (1.96+2.21)/2;
     #local D = (0.15+0.31)/2;
     #local E = (5.00+5.59)/2;
     #local G = (0.05+0.20)/2;
     #local H = (0.76+1.52)/2;
     #local J = (2.00+2.50)/2;
  #end
  #if (Type = "SMC")
     #local A = (5.59+6.22)/2;
     #local B = (6.60+7.11)/2;
     #local C = (2.75+3.18)/2;
     #local D = (0.15+0.31)/2;
     #local E = (7.75+8.13)/2;
     #local G = (0.10+0.20)/2;
     #local H = (0.76+1.52)/2;
     #local J = (2.00+2.50)/2;
  #end
  #if (Type = "GF1")
     #local A = (2.39+2.90)/2;
     #local B = (4.24+4.75)/2;
     #local C = (1.02+1.68)/2;
     #local D = (0.17+0.38)/2;
     #local E = (4.98+5.74)/2;
     #local G = 0.152;
     #local H = (0.76+1.52)/2;
     #local J = (2.54+3.00)/2;
  #end

  #macro DO214_PIN(H,LP,C,D,R)
     union {
        difference {
           cylinder {
              <0,-C/2,0> <0,C/2,0> R+D/2
              }
           cylinder {
              <0,-C,0> <0,C,0> R-D/2
              }
           box {
              <-R-D,-C,-R-D> <0,C,R+D>
              }
           box {
              <-R-D,-C,-R-D> <R+D,C,0>
              }
           rotate <0,0,90>
           translate <0,H-R,-R>
           }
        difference {
           cylinder {
              <0,-C/2,0> <0,C/2,0> R+D/2
              }
           cylinder {
              <0,-C,0> <0,C,0> R-D/2
              }
           box {
              <-R-D,-C,-R-D> <0,C,R+D>
              }
           box {
              <-R-D,-C,-R-D> <R+D,C,0>
              }
           rotate <0,0,90>
           rotate <90,0,0>
           translate <0,R+D/2,-R>
           }
        box {
           <-C/2,R+D/2,-D/2> <C/2,H-R,D/2>
           }
        box {
           <-C/2,0,-LP> <C/2,D,-R>
           }
        box {
           <-C/2,H-D/2,-LP> <C/2,H+D/2,-R>
           }
        texture {
           col_silver
           }
        }
  #end

  union {
     difference {
        box {
           <-B/2,G,-A/2> <B/2,J,A/2>
           }
        box {
           <0,0,-A> <J,J,A>
           rotate <0,0,10>
           translate <B/2,J/2+D/2,0>
           }
        box {
           <0,0,-A> <-J,J,A>
           rotate <0,0,-10>
           translate <-B/2,J/2+D/2,0>
           }
        box {
           <0,0,-A> <J,-J,A>
           rotate <0,0,-10>
           translate <B/2,J/2-D/2,0>
           }
        box {
           <0,0,-A> <-J,-J,A>
           rotate <0,0,10>
           translate <-B/2,J/2-D/2,0>
           }
        box {
           <-B,0,0> <B,J,J>
           rotate <-10,0,0>
           translate <0,J/2+D/2,A/2>
           }
        box {
           <-B,0,0> <B,J,-J>
           rotate <10,0,0>
           translate <0,J/2+D/2,-A/2>
           }
        box {
           <-B,0,0> <B,-J,J>
           rotate <10,0,0>
           translate <0,J/2-D/2,A/2>
           }
        box {
           <-B,0,0> <B,-J,-J>
           rotate <-10,0,0>
           translate <0,J/2-D/2,-A/2>
           }
        box {
           <0,0,-A> <1.2,1.5*D,A>
           translate <-B/2,0,0>
           }
        box {
           <0,0,-A> <-1.2,1.5*D,A>
           translate <B/2,0,0>
           }
        }
     box {
        <-B/2+B/10,J,-A/2+A/10> <-B/2+B/10+B/10,J+0.01,A/2-A/10>
        pigment {
           White
           }
        }
     object {
        DO214_PIN (J/2,1.14,C,D,0.2)
        rotate <0,90,0>
        translate <E/2-D/2,0,0>
        }
     object {
        DO214_PIN (J/2,1.14,C,D,0.2)
        rotate <0,-90,0>
        translate <-E/2+D/2,0,0>
        }
      text {
        ttf besch_font value, 0.075, 0
        scale 0.75
        pigment {
           White
           }
        rotate <90,0,0>
        translate <-1,J+0.01,-0.3>
        }

     pigment {
        Gray20
        }
     }
#end

#macro DIODE_SMT_DO214AC(value)
  DO214_BASE(value,"SMA")
#end

#macro DIODE_SMT_DO214AA(value)
  DO214_BASE(value,"SMB")
#end

#macro DIODE_SMT_DO214AB(value)
  DO214_BASE(value,"SMC")
#end

#macro DIODE_SMT_DO214BA(value)
  DO214_BASE(value,"GF1")
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//diode:DO214AC=DIODE_SMT_DO214AC(:SMT diode DO-214AC (SMA)
//diode:DO214AA=DIODE_SMT_DO214AA(:SMT diode DO-214AA (SMB)
//diode:DO214BA=DIODE_SMT_DO214BA(:SMT diode DO-214BA (GF1)
//diode:SMA:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:DIODE_SMT_DO214AC(:SMT diode DO-214AC (SMA)
//diode:SMB:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:DIODE_SMT_DO214AA(:SMT diode DO-214AA (SMB)
//diode:SMC:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:DIODE_SMT_DO214AB(:SMT diode DO-214AB (SMC)
//diode:SMBG:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:DIODE_SMT_DO214AA(:SMT diode DO-214AA (SMB)
//diode:SMBJ:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:DIODE_SMT_DO214AA(:SMT diode DO-214AA (SMB)
// end assignment
