/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Micro-Match THT female from AMP (TE connectivity)
 * Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
 * Rev. 1.1  16/12/07
 ******************************************************************************/
#macro MicroMatch_THT_F(pin)
  union {
     #local pitch=1.27;
     #local plastic_z=5;
     #local plastic_x=pitch*(pin-1)+3.37;
     difference {
        union {
           box {
              <-plastic_x/2, 0.5, -plastic_z/2>
              <+plastic_x/2, 2.1, +plastic_z/2>
              }
           //Main box
           box {
              <-plastic_x/2+0.5, 0.5, -plastic_z/2+0.5>
              <+plastic_x/2-0.5, 4.0, +plastic_z/2-0.5>
              }
           //Main box
           }
        box {
           <-plastic_x/2+0.5,0,-plastic_z/2+1>
           <-plastic_x/2-0.1,4.1,plastic_z/2-1>
           }
        //Main box hollowing out
        box {
           <+plastic_x/2-0.5,0,-plastic_z/2+1>
           <+plastic_x/2+0.1,4.1,plastic_z/2-1>
           }
        //Main box hollowing out
        #local i=0;
        #while(i<(pin/2)) //contacts apertures
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
           }
        }
     #local i=0;
     #while(i<(pin/2))
        //pins
        box {
           <-0.25,-3.15+.25,-0.2> <+0.25,1,+0.2>
           translate <-(plastic_x-3.37)/2+i*2.54,0,-1.27>
           }
        cylinder {
           <0,-3.15+0.25,-0.2> <0,-3.15+0.25,+0.2> 0.25
           translate <-(plastic_x-3.37)/2+i*2.54,0,-1.27>
           }
        box {
           <-0.25,-3.15+.25,-0.2> <+0.25,1,+0.2>
           translate <-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>
           }
        cylinder {
           <0,-3.15+0.25,-0.2> <0,-3.15+0.25,+0.2> 0.25
           translate <-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>
           }
        cylinder {
           <0,1,-1.4> <0,3.9,-1.4> 0.15
           translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
           }
        cylinder {
           <0,1,1.4> <0,3.9,1.4> 0.2
           translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
           }
        difference {
           box {
              <-0.15,1,0> <0.15,3.9,1.5>
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.2,1,0.5> <0.2,4,1>
              translate <-(pin/2-0.5)*pitch+pitch*i*2,0,0>
              }
           }
        difference {
           box {
              <-0.15,1,0> <0.15,3.9,-1.5>
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           box {
              <-0.2,1,-0.5> <0.2,4,-1>
              translate <-(pin/2-1.5)*pitch+pitch*i*2,0,0>
              }
           }
        #local i=i+1;
     #end
     pigment {
        Silver
        }
     }
#end

#macro CON_THT_MICROMATCH_F04() MicroMatch_THT_F( 4) #end
#macro CON_THT_MICROMATCH_F06() MicroMatch_THT_F( 6) #end
#macro CON_THT_MICROMATCH_F08() MicroMatch_THT_F( 8) #end
#macro CON_THT_MICROMATCH_F10() MicroMatch_THT_F(10) #end
#macro CON_THT_MICROMATCH_F12() MicroMatch_THT_F(12) #end
#macro CON_THT_MICROMATCH_F14() MicroMatch_THT_F(14) #end
#macro CON_THT_MICROMATCH_F16() MicroMatch_THT_F(16) #end
#macro CON_THT_MICROMATCH_F18() MicroMatch_THT_F(18) #end
#macro CON_THT_MICROMATCH_F20() MicroMatch_THT_F(20) #end


/*******************************************************************************
 * Micro-Match male THT from AMP (TE connectivity)
 * Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
 * Rev. 1.1  16/12/07
 ******************************************************************************/
#macro MicroMatch_THT_M(pin)
  union {
     #local pitch=1.27;
     #local plastic_z=5;
     #local plastic_x=pitch*(pin-1)+3.37;
     difference {
        union {
           box {
              <-plastic_x/2,0,-plastic_z/2> <plastic_x/2,3.6,plastic_z/2>
              }
           //Main box
           difference {
              //left hook
              box {
                 <-0.5,-1,-0.5> <0.5,1,0.5>
                 rotate <0,0,30> translate <-plastic_x/2+0.2,2,0>
                 }
              box {
                 <-1,-1,-1> <1,1,1>
                 rotate <0,0,0> translate <-plastic_x/2,3.5,0>
                 }
              box {
                 <-1,-1,-1> <1,1,1>
                 rotate <0,0,0> translate <-plastic_x/2-1.5,2.5,0>
                 }
              }
           difference {
              //right hook
              box {
                 <-0.5,-1,-0.5> <0.5,1,0.5>
                 rotate <0,0,-30> translate <+plastic_x/2-0.2,2,0>
                 }
              box {
                 <-1,-1,-1> <1,1,1>
                 rotate <0,0,0> translate <+plastic_x/2,3.5,0>
                 }
              box {
                 <-1,-1,-1> <1,1,1>
                 rotate <0,0,0> translate <+plastic_x/2+1.5,2.5,0>
                 }
              }
           }
        box {
           <-plastic_x/2+0.65,1.7,-plastic_z/2+0.5> <plastic_x/2-0.65,3.61,plastic_z/2-0.5>
           }
        //Main box hollowing out
        box {
           <-plastic_x/2+0.65,-0.1,-plastic_z/2-0.5> <plastic_x/2-0.65,0.4,plastic_z/2+0.5>
           }
        //Base hollowing out
        box {
           <-plastic_x/2-0.65,-0.1,-0.65> <plastic_x/2+0.65,0.4,+0.65>
           }
        //Base hollowing out
        pigment {
           Red * 0.6
           }
        }
     difference {
        //Detrompeur
        union {
           box {
              <-plastic_x/2,3.6,-1.16> <-plastic_x/2+0.65,7.1,1.16>
              }
           //top part
           box {
              <-plastic_x/2,3.6,-1.16-0.3> <-plastic_x/2+0.65,3.6+0.3,1.16+0.3>
              }
           //down part
           }
        cylinder {
           <-plastic_x/2-0.1,3.6+0.3,-1.16-0.3> <-plastic_x/2+0.66,3.6+0.3,-1.16-0.3> 0.3
           }
        cylinder {
           <-plastic_x/2-0.1,3.6+0.3,+1.16+0.3> <-plastic_x/2+0.66,3.6+0.3,+1.16+0.3> 0.3
           }
        box {
           <-plastic_x/2-0.1,5.5,0> <-plastic_x/2+0.66,7.11,+1.161>
           }
        box {
           <-0.5,-0.82,-0.82> <+0.5,+0.82,+0.82>
           rotate <45,0,0> translate <-plastic_x/2+0.3,5.5,+1.16>
           }
        box {
           <-0.5,-0.2,-0.2> <+0.5,+0.2,+0.2>
           rotate <45,0,0> translate <-plastic_x/2+0.3,7.1+0.1,+0.1>
           }
        //biseaux
        box {
           <-0.5,-0.2,-0.2> <+0.5,+0.2,+0.2>
           rotate <45,0,0> translate <-plastic_x/2+0.3,7.1+0.1,-1.16-0.1>
           }
        rotate 180*y
        pigment {
           Red*0.6
           }
        }
     #local i=0;
     #while(i<(pin/2))
        //pins
        box {
           <-0.25,-3.15+.25,-0.2> <+0.25,1,+0.2>
           translate <-(plastic_x-3.37)/2+i*2.54,0,-1.27>
           }
        cylinder {
           <0,-3.15+0.25,-0.2> <0,-3.15+0.25,+0.2> 0.25
           translate <-(plastic_x-3.37)/2+i*2.54,0,-1.27>
           }
        box {
           <-0.25,-3.15+.25,-0.2> <+0.25,1,+0.2>
           translate <-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>
           }
        cylinder {
           <0,-3.15+0.25,-0.2> <0,-3.15+0.25,+0.2> 0.25
           translate <-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>
           }
        //contacts
        difference {
           box {
              <-0.35,1,-0.2> <+0.35,3.6-0.2,+0.2>
              translate <-(plastic_x-3.37)/2+i*2.54,0,-0.75>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <-10,0,0> translate <-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75+0.32>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <+10,0,0> translate <-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75-0.32>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <-10,90,0> translate <-(plastic_x-3.37)/2+i*2.54+0.5,3.6-0.2,-0.75>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <-10,-90,0> translate <-(plastic_x-3.37)/2+i*2.54-0.5,3.6-0.2,-0.75>
              }
           }
        difference {
           box {
              <-0.35,1,-0.2> <+0.35,3.6-0.2,+0.2>
              translate <-(plastic_x-3.37)/2+1.27+i*2.54,0,+0.75>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <-10,0,0> translate <-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75+0.32>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <+10,0,0> translate <-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75-0.32>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <-10,90,0> translate <-(plastic_x-3.37)/2+1.27+i*2.54+0.5,3.6-0.2,+0.75>
              }
           box {
              <-0.36,-0.5,-0.2> <+0.36,+0.5,+0.2>
              rotate <-10,-90,0> translate <-(plastic_x-3.37)/2+1.27+i*2.54-0.5,3.6-0.2,+0.75>
              }
           }
        #local i=i+1;
     #end
     pigment {
        Silver
        }
     }
#end

#macro CON_THT_MICROMATCH_M04() MicroMatch_THT_M( 4) #end
#macro CON_THT_MICROMATCH_M06() MicroMatch_THT_M( 6) #end
#macro CON_THT_MICROMATCH_M08() MicroMatch_THT_M( 8) #end
#macro CON_THT_MICROMATCH_M10() MicroMatch_THT_M(10) #end
#macro CON_THT_MICROMATCH_M12() MicroMatch_THT_M(12) #end
#macro CON_THT_MICROMATCH_M14() MicroMatch_THT_M(14) #end
#macro CON_THT_MICROMATCH_M16() MicroMatch_THT_M(16) #end
#macro CON_THT_MICROMATCH_M18() MicroMatch_THT_M(18) #end
#macro CON_THT_MICROMATCH_M20() MicroMatch_THT_M(20) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_MICROMATCH_F04(:MicroMatch female 4
//=CON_THT_MICROMATCH_F06(:MicroMatch female 6
//=CON_THT_MICROMATCH_F08(:MicroMatch female 8
//=CON_THT_MICROMATCH_F10(:MicroMatch female 10
//=CON_THT_MICROMATCH_F12(:MicroMatch female 12
//=CON_THT_MICROMATCH_F14(:MicroMatch female 14
//=CON_THT_MICROMATCH_F16(:MicroMatch female 16
//=CON_THT_MICROMATCH_F18(:MicroMatch female 18
//=CON_THT_MICROMATCH_F20(:MicroMatch female 20
//con-amp-micromatch:MICROMATCH-4=CON_THT_MICROMATCH_M04(:MicroMatch male 4
//con-amp-micromatch:MICROMATCH-6=CON_THT_MICROMATCH_M06(:MicroMatch male 6
//con-amp-micromatch:MICROMATCH-8=CON_THT_MICROMATCH_M08(:MicroMatch male 8
//con-amp-micromatch:MICROMATCH-10=CON_THT_MICROMATCH_M10(:MicroMatch male 10
//con-amp-micromatch:MICROMATCH-12=CON_THT_MICROMATCH_M12(:MicroMatch male 12
//con-amp-micromatch:MICROMATCH-14=CON_THT_MICROMATCH_M14(:MicroMatch male 14
//con-amp-micromatch:MICROMATCH-16=CON_THT_MICROMATCH_M16(:MicroMatch male 16
//con-amp-micromatch:MICROMATCH-18=CON_THT_MICROMATCH_M18(:MicroMatch male 18
//con-amp-micromatch:MICROMATCH-20=CON_THT_MICROMATCH_M20(:MicroMatch male 20
// end assignment
