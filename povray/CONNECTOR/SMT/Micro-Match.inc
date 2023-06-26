/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Micro-Match SMT female from AMP (TE connectivity)
 * pin - number of pins
 ******************************************************************************/
#macro MicroMatch_SMT_F(pin)
  union {
     #local pitch=1.27;
     #local plastic_z=5;
     #local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet
     difference {
        union {
           box {
              <-plastic_x/2+0.5,0,-plastic_z/2+0.5> <plastic_x/2-0.5,5.3,plastic_z/2-0.5>
              }
           difference {
              box {
                 <-plastic_x/2,1.9,-plastic_z/2>      <plastic_x/2    ,3.3,plastic_z/2>
                 }
              #local i=0;
              #while(i<(pin/2))
                 box {
                    <-0.5,2.4,0> <0.5,3.5,5>
                    translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
                    }
                 box {
                    <-0.5,2.4,-5> <0.5,3.5,0>
                    translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
                    }
                 #local i=i+1;
              #end
              box {
                 <0,0,-plastic_z/4> <plastic_x+1,5,plastic_z/4>
                 }
              }
           }
        #local i=0;
        #while(i<(pin/2))
           box {
              <-0.18,-1,-5> <0.18,1.8,5>
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.18,-1,-5> <0.18,1.8,5>
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           #local i=i+1;
        #end
        #local i=0;
        #while(i<(pin/2))
           box {
              <-0.2,-1,0> <0.2,6,1.5>
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.35,-1,0.5> <0.35,6,1>
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.4,-1,-0.4> <0.4,6,-0.9>
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           cylinder {
              <0,-1,-1.4> <0,6,-1.4> 0.2
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.2,-1,0> <0.2,6,-1.5>
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.35,-1,-0.5> <0.35,6,-1>
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.4,-1,0.4> <0.4,6,0.9>
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           cylinder {
              <0,-1,1.4> <0,6,1.4> 0.2
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           #local i=i+1;
        #end
        texture {
           pigment {
              Red*0.6
              }
           finish {
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     #local i=0;
     #while(i<(pin/2))
        object {
           TOOLS_PCB_SMD(1,6,0.25,8)
           translate <0.5,-0.125,0.5> rotate <0,0,90> translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture {
              col_silver
              }
           }
        object {
           TOOLS_PCB_SMD(1,6,0.25,8)
           translate <-0.5,-0.125,-0.5> rotate <0,0,-90> translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture {
              col_silver
              }
           }
        #local i=i+1;
     #end
     }
#end

#macro CON_SMT_MICROMATCH_F04() MicroMatch_SMT_F(4)  #end
#macro CON_SMT_MICROMATCH_F06() MicroMatch_SMT_F(6)  #end
#macro CON_SMT_MICROMATCH_F08() MicroMatch_SMT_F(8)  #end
#macro CON_SMT_MICROMATCH_F10() MicroMatch_SMT_F(10) #end
#macro CON_SMT_MICROMATCH_F12() MicroMatch_SMT_F(12) #end
#macro CON_SMT_MICROMATCH_F14() MicroMatch_SMT_F(14) #end
#macro CON_SMT_MICROMATCH_F16() MicroMatch_SMT_F(16) #end
#macro CON_SMT_MICROMATCH_F18() MicroMatch_SMT_F(16) #end
#macro CON_SMT_MICROMATCH_F20() MicroMatch_SMT_F(20) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_SMT_MICROMATCH_F04(:SMT MicroMatch female 4
//=CON_SMT_MICROMATCH_F06(:SMT MicroMatch female 6
//=CON_SMT_MICROMATCH_F08(:SMT MicroMatch female 8
//=CON_SMT_MICROMATCH_F10(:SMT MicroMatch female 10
//=CON_SMT_MICROMATCH_F12(:SMT MicroMatch female 12
//=CON_SMT_MICROMATCH_F14(:SMT MicroMatch female 14
//=CON_SMT_MICROMATCH_F16(:SMT MicroMatch female 16
//=CON_SMT_MICROMATCH_F18(:SMT MicroMatch female 18
//=CON_SMT_MICROMATCH_F20(:SMT MicroMatch female 20
// end assignment
