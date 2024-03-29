/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMT tantalum capacitor
 ******************************************************************************/
#macro CAP_SMD_CHIP_TT_BASE(L,W,H,LT,WT,HT,P,value)
  union {
     box { //Body
        <0,0,0> <LT,H,W>
        pigment {
           rgb(<0.400, 0.320, 0.220>) * 1.2
           }
        translate <-LT/2,(L-LT)/2,-W/2>
        } //Grundkoerper braun

     //Marking
     text {
        ttf besch_font value 0.1,0
        scale L/8
        rotate <90,0,0>
        translate <-LT/4,H+(L-LT)/2+0.01,0>
        pigment {
           DarkWood * 0.7
           }
        }
     //
     box {
        <0,0,0> <(L-2*P)-0.3,(L-LT)/2,W>
        pigment {
           rgb (<0.400, 0.320, 0.220>)*1.2
           }
        translate <-((L-2*P)-0.3)/2,0,-W/2>
        }
     box {
        <0,0,0> <0.4/exp(-LT/10),0.002,W>
        pigment {
           DarkWood * 0.7
           }
        translate <-LT/2.1,H+(L-LT)/2,-W/2>
        } //Markierung
     union {
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
              <0,HT,-0.002> <0,HT,WT+0.002>(L-LT)/2
              }
           cylinder {
              <0,0,-0.002> <0,0,WT+0.002>(L-LT)/2
              }
           translate <LT/2+(L-LT)/2+0.02,0,-WT/2>
           }
        //rechter Anschlus
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
           translate <LT/2+(L-LT)/2+0.02,0,-WT/2>
           }
        //rechter Anschlus
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
              translate <-(L-LT),0.75*(L-LT),0>
              }
           box {
              <(L-LT)/2,(L-LT)/2,-0.04> <(L-LT),L-LT,WT+0.002>
              translate <-1.75*(L-LT),0,0>
              }
           translate <LT/2+(L-LT)/2+0.02,0,-WT/2>
           }
        //linker (positiver) Anschlus
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
           translate <-L/2-0.02,0,-WT/2>
           }
        texture {
           col_silver
           }
        }
     rotate<0,180,0>
     }
#end

#macro CAP_SMD_CHIP_TT_SCT_A(value)
  CAP_SMD_CHIP_TT_BASE(3.2,1.6,1.6,3.0,1.2,1.0,0.8,value)
#end

#macro CAP_SMD_CHIP_TT_SCT_B(value)
  CAP_SMD_CHIP_TT_BASE(3.5,2.8,1.9,3.3,2.2,1.2,0.8,value)
#end

#macro CAP_SMD_CHIP_TT_SCT_C(value)
  CAP_SMD_CHIP_TT_BASE(6.0,3.2,2.5,5.8,2.2,1.5,1.3,value)
#end

#macro CAP_SMD_CHIP_TT_SCT_D(value)
  CAP_SMD_CHIP_TT_BASE(7.3,4.3,2.8,7.1,2.4,1.6,1.3,value)
#end

#macro CAP_SMD_CHIP_TT_SCT_E(value)
  CAP_SMD_CHIP_TT_BASE(7.3,4.3,4.1,7.1,2.4,1.6,1.3,value)
#end

#macro CAP_SMD_CHIP_TT_SCT_R(value)
  CAP_SMD_CHIP_TT_BASE(2.0,1.6,1.0,1.9,1.2,0.6,0.5,value)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:CT3216=CAP_SMD_CHIP_TT_SCT_A(:SMT tantalum cap size A
//rcl:CT3528=CAP_SMD_CHIP_TT_SCT_B(:SMT tantalum cap size B
//rcl:CT6032=CAP_SMD_CHIP_TT_SCT_C(:SMT tantalum cap size C
//rcl:CT7343=CAP_SMD_CHIP_TT_SCT_D(:SMT tantalum cap size D
//=CAP_SMD_CHIP_TT_SCT_E(:SMT tantalum cap size E
//=CAP_SMD_CHIP_TT_SCT_R(:SMT tantalum cap size R
// end assignment
