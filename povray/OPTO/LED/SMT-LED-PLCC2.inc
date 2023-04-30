/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * SMT LED PLCC2 && Osram Mini-TopLED
 ******************************************************************************/
#macro PLCC2_BASE(Type)
  union {
     //default to PLCC2
     #local L = 3.7;
     #local W = 3.0;
     #local H = 2.0;
     #local LT = 3.3;
     #local WT = 2.6;
     #local HT = 1.6;
     #local P = 2;

     #if (Type = "PLCC2")
        #local L = 3.7;
        #local W = 3.0;
        #local H = 2.0;
        #local LT = 3.3;
        #local WT = 2.6;
        #local HT = 1.6;
        #local P = 2;
     #end

     #if (Type = "MiniTopled")
        #local L = 2.3;
        #local W = 1.5;
        #local H = 1.4;
        #local LT = 2.1;
        #local WT = 1.3;
        #local HT = 1.2;
        #local P = 2;
     #end

     difference {
        object {
           Round_Box(<0,0,0>, <LT,H,W>, 0.1, no)
           translate <-LT/2,(L-LT)/2,-W/2>
           }
        cylinder {
           <0,H+(L-LT)/2-0.4,0> <0,H+(L-LT)/2+0.1,0> W/3.5
           }
        cone {
           <0,H+(L-LT)/2-0.4,0> W/2.9 <0,H+(L-LT)/2+0.1,0> W/2.2
           }
        pigment {
           White
           }
        }
     box {
        <-0.2,H+(L-LT)/2-0.4,-0.2> <0.2,H+(L-LT)/2-0.3,0.2>
        pigment {
           Gray80
           }
        }
     //rechter Anschluss
     difference {
        box {
           <0,0,0> <-P,HT,WT>
           }
        box {
           <0,(L-LT)/2,-0.002> <-P-0.002,HT-(L-LT)/2,WT+0.002>
           translate <-(L-LT)/2,0,0>
           }
        cylinder {
           <0,HT,-0.002> <0,HT,WT+0.002> (L-LT)/2
           }
        cylinder {
           <0,0,-0.002> <0,0,WT+0.002> (L-LT)/2
           }
        texture {
           col_silver
           }
        translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
     //rechter Anschluss
     difference {
        cylinder {
           <-(L-LT)/2,HT-(L-LT)/2,> <-(L-LT)/2,HT-(L-LT)/2,WT> (L-LT)/2
           }
        cylinder {
           <-3*(L-LT)/4,HT-3*(L-LT)/4,-0.04> <-3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002> (L-LT)/4
           }
        box {
           <-(L-LT)/2,HT-3*(L-LT)/4,-0.04> <-(L-LT),HT-5,WT+0.002>
           }
        box {
           <-3*(L-LT)/4,HT-(L-LT)/2,-0.04> <-(L-LT),HT-5,WT+0.002>
           }
        texture {
           col_silver
           }
        translate <LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
     //rechter Anschluss
     difference {
        cylinder {
           <-(L-LT)/2,(L-LT)/2,0> <-(L-LT)/2,(L-LT)/2,WT> (L-LT)/2
           }
        cylinder {
           <-3*(L-LT)/4,3*(L-LT)/4,-0.04> <-3*(L-LT)/4,3*(L-LT)/4,WT+0.002> (L-LT)/4
           }
        box {
           <(-L-LT)/2,3*(L-LT)/4,-0.04> <-(L-LT),5,WT+0.002>
           }
        box {
           <0,0,-0.04> <(L-LT)/2,(L-LT)/2,WT+0.002>
           translate<-(L-LT),0.75*(L-LT),0>
           }
        box {
           <(L-LT)/2,(L-LT)/2,-0.04> <(L-LT),L-LT,WT+0.002>
           translate <-1.75*(L-LT),0,0>
           }
        texture {
           col_silver
           }
        translate <LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
     //linker (positiver) Anschluss
     difference {
        box {
           <0,0,0> <P,HT,WT>
           }
        box {
           <(L-LT)/2,(L-LT)/2,-0.002> <P+0.002,HT-(L-LT)/2,WT+0.002>
           }
        cylinder {
           <0,HT,-0.002> <0,HT,WT+0.002> (L-LT)/2
           }
        cylinder {
           <0,0,-0.002> <0,0,WT+0.002> (L-LT)/2
           }
        box {
           <-0.002,HT/2,0> <P+0.002,HT+0.002,WT*0.3>
           translate <0,0,WT*0.35>
           }
        texture {
           col_silver
           }
        translate <-L/2-0.02,0,-WT/2>
        }
     //linker (positiver) Anschlus
     difference {
        cylinder {
           <(L-LT)/2,HT-(L-LT)/2,-0.002> <(L-LT)/2,HT-(L-LT)/2,WT+0.002> (L-LT)/2
           }
        cylinder {
           <3*(L-LT)/4,HT-3*(L-LT)/4,-0.04> <3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002> (L-LT)/4
           }
        box {
           <(L-LT)/2,HT-3*(L-LT)/4,-0.04> <L-LT,HT-5,WT+0.002>
           }
        box {
           <3*(L-LT)/4,HT-(L-LT)/2,-0.04> <L-LT,HT-5,WT+0.002>
           }
        box {
           <-0.002,HT/2,0> <P+0.002,HT+0.002,WT*0.3>
           translate <0,0,WT*0.35>
           }
        texture {
           col_silver
           }
        translate <-L/2-0.02,0,-WT/2>
        }
     //linker (positiver) Anschlus
     difference {
        cylinder {
           <(L-LT)/2,(L-LT)/2,-0.002> <(L-LT)/2,(L-LT)/2,WT+0.002> (L-LT)/2
           }
        cylinder {
           <3*(L-LT)/4,3*(L-LT)/4,-0.04> <3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002> (L-LT)/4
           }
        box {
           <(L-LT)/2,3*(L-LT)/4,-0.04> <L-LT,5,WT+0.002>
           }
        box {
           <3*(L-LT)/4,(L-LT)/2,-0.04> <L-LT,L-LT,WT+0.002>
           }
        texture {
           col_silver
           }
        translate <-L/2-0.02,0,-WT/2>
        }
     }
#end

#macro LED_SMT_PLCC2()
  PLCC2_BASE("PLCC2")
#end

#macro LED_SMT_PLCC2_rotate()
  PLCC2_BASE("PLCC2")
  rotate <0,90,0>
#end

#macro LED_SMT_MINITOPLED()
  PLCC2_BASE("MiniTopled")
#end

#macro LED_SMT_MINITOPLED_rotate()
  PLCC2_BASE("MiniTopled")
  rotate <0,90,0>
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//led:KA-3528ASYC=LED_SMT_PLCC2(:SMT LED PLCC2
//led:P-LCC-2=LED_SMT_PLCC2_rotate(:SMT LED PLCC2
//led:P-LCC-2-TOPLED-RG=LED_SMT_PLCC2_rotate(:SMT LED PLCC2
//led:PLCC2=LED_SMT_PLCC2_rotate(:SMT LED PLCC2
//led:KA3528=LED_SMT_MINITOPLED(:SMT LED Mini TopLED
//led:OSRAM-MINI-TOP-LED=LED_SMT_MINITOPLED_rotate(:SMT LED Mini TopLED
// end assignment
