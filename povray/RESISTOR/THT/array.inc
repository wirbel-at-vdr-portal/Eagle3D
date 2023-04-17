/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT SIL (single in line) resistor network
 * reformatted: 17.04.2023, wk
 ******************************************************************************/
#macro RES_THT_ARRAY_SILBASE(pin)
  union {
     box {
        <-pin*1.27+0.5,0.5,-0.5> <pin*1.27-0.5,3,0.5>
        pigment {
           rgb<1,0.83,0.61>
           }
        }
     sphere_sweep {
        linear_spline,5,
        <-pin*1.27+0.5,0.5,0>, 0.5
        <-pin*1.27+0.5,3,0>, 0.5
        <pin*1.27-0.5,3,0>, 0.5
        <pin*1.27-0.5,0.5,0>, 0.5
        <-pin*1.27+0.5,0.5,0>, 0.5
        pigment {
           rgb<1,0.83,0.61>
           }
        }
     union {
        #local i = 0;
        #while(i<pin)
           box {
              <-0.2,-4,-0.1> <0.2,-1,0.1>
              translate <2.54*i,0,0>
              }
           box {
              <-0.3,-1,-0.1> <0.3,0,0.1>
              translate <2.54*i,0,0>
              }
           #local i = i + 1;
        #end
        translate <-(pin-1)/2*2.54,0,0>
        }
     intersection {
        box {
           <-pin*1.27+0.5,0.5,-0.501> <pin*1.27-0.5,3,0.501>
           }
        union {
           text {
              ttf besch_font value 0.8, 0
              scale <2,2,1>
              translate <-pin/2*2.54+2.5,1.2,-0.7>
              }
           cylinder {
              <0,0,0> <0,0,-2> 0.4
              translate <-(pin-1)*1.27,1.2,0>
              }
           }
        pigment {
           Black
           }
        }
     texture {
        col_silver
        }
     translate <0,1.2,0>
     }
#end


#macro RES_THT_ARRAY_SIL4(value)
  RES_THT_ARRAY_SILBASE(4)
#end

#macro RES_THT_ARRAY_SIL5(value)
  RES_THT_ARRAY_SILBASE(5)
#end

#macro RES_THT_ARRAY_SIL6(value)
  RES_THT_ARRAY_SILBASE(6)
#end

#macro RES_THT_ARRAY_SIL7(value)
  RES_THT_ARRAY_SILBASE(7)
#end

#macro RES_THT_ARRAY_SIL8(value)
  RES_THT_ARRAY_SILBASE(8)
#end

#macro RES_THT_ARRAY_SIL9(value)
  RES_THT_ARRAY_SILBASE(9)
#end

#macro RES_THT_ARRAY_SIL10(value)
  RES_THT_ARRAY_SILBASE(10)
#end

#macro RES_THT_ARRAY_SIL11(value)
  RES_THT_ARRAY_SILBASE(11)
#end

#macro RES_THT_ARRAY_SIL12(value)
  RES_THT_ARRAY_SILBASE(12)
#end

#macro RES_THT_ARRAY_SIL13(value)
  RES_THT_ARRAY_SILBASE(13)
#end

#macro RES_THT_ARRAY_SIL14(value)
  RES_THT_ARRAY_SILBASE(14)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//resistor-net:RN-5=RES_THT_ARRAY_SIL5(:THT SIL resistor network
//resistor-net:RN-6=RES_THT_ARRAY_SIL6(:THT SIL resistor network
//resistor-net:RN-7=RES_THT_ARRAY_SIL7(:THT SIL resistor network
//resistor-net:RN-8=RES_THT_ARRAY_SIL8(:THT SIL resistor network
//resistor-net:RN-9=RES_THT_ARRAY_SIL9(:THT SIL resistor network
//resistor-net:RN-10=RES_THT_ARRAY_SIL10(:THT SIL resistor network
//resistor-net:RN-11=RES_THT_ARRAY_SIL11(:THT SIL resistor network
//resistor-sil:SIL4=RES_THT_ARRAY_SIL4(:THT SIL resistor network
//resistor-sil:SIL5=RES_THT_ARRAY_SIL5(:THT SIL resistor network
//resistor-sil:SIL6=RES_THT_ARRAY_SIL6(:THT SIL resistor network
//resistor-sil:SIL7=RES_THT_ARRAY_SIL7(:THT SIL resistor network
//resistor-sil:SIL8=RES_THT_ARRAY_SIL8(:THT SIL resistor network
//resistor-sil:SIL9=RES_THT_ARRAY_SIL9(:THT SIL resistor network
//resistor-sil:SIL10=RES_THT_ARRAY_SIL10(:THT SIL resistor network
//resistor-sil:SIL11=RES_THT_ARRAY_SIL11(:THT SIL resistor network
//resistor-sil:SIL12=RES_THT_ARRAY_SIL12(:THT SIL resistor network
//resistor-sil:SIL13=RES_THT_ARRAY_SIL13(:THT SIL resistor network
//resistor-sil:SIL14=RES_THT_ARRAY_SIL14(:THT SIL resistor network
//resistor-sil:SIL05A=RES_THT_ARRAY_SIL5(:THT SIL resistor network
//resistor-sil:SIL05C=RES_THT_ARRAY_SIL5(:THT SIL resistor network
//resistor-sil:SIL08A=RES_THT_ARRAY_SIL8(:THT SIL resistor network
//resistor-sil:SIL08C=RES_THT_ARRAY_SIL8(:THT SIL resistor network
//resistor-sil:SIL09A=RES_THT_ARRAY_SIL9(:THT SIL resistor network
//resistor-sil:SIL09C=RES_THT_ARRAY_SIL9(:THT SIL resistor network
// end assignment
