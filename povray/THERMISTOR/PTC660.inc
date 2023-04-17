/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * TT Electronics/BC Components PTC660 thermistors
 * Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * Rev. 1.0  19/06/05
 ******************************************************************************/
#macro R_THERM_PTC660_BASE(value,D,ep)
  #macro RTH_PIN (Rot,D)
     #local R = D * 0.1;

     union {
        #if (D > 10.5)
           cylinder {
              <+1,-R,-ep/2+dp/2> <+1,-D/2,-ep/2+dp/2> dp/2
              translate (5+D/2)*y
              pigment {
                 Gray60
                 }
              }
           intersection {
              torus {
                 R,0.3
                 rotate <90,0,0>
                 }
              box {
                 <0,R+0.4,-2> <R+0.4,0,+2>
                 }
              translate <1-R,5+D/2-R,-ep/2+dp/2>
              pigment {
                 Gray60
                 }
              }
           cylinder {
              <-D/4,0,-ep/2+dp/2> <1-R,0,-ep/2+dp/2> dp/2
              translate (5+D/2)*y
              pigment {
                 Gray60
                 }
              }
        #else
           cylinder {
              <-D/4,D/8,-ep/2+dp/2> <+1,-D/2,-ep/2+dp/2> dp/2
              pigment {
                 Gray60
                 }
              translate (5+D/2)*y
              }
        #end
        sphere_sweep {
           cubic_spline
           7,
           <+1,5,-ep/2+dp/2+0.1>, 0.3
           <+1,5,-ep/2+dp/2>, 0.3
           <+1,4,-ep/2+dp/2>, 0.3
           <+1,2.5,0>, 0.3
           <+2.5,1,0>, 0.3
           <+2.54,-1*(pcb_height+pin_length),0>, 0.3
           <+2.54,-1*(pcb_height+pin_length)-0.1,0>, 0.3
           texture {
              col_silver
              }
           }
        rotate Rot*y
        }
  #end

  #local dp=0.6;
  #local pl=20;
  #local H2=4;
  #local F=5.08;
  union {
     union {
        superellipsoid {
           <1.0, 0.1>
           scale <D/2,D/2,ep/2-dp/2>
           pigment {
              Gray60
              }
           }
        #if (D > 7)
           text {
              ttf global_fontfile_alphalcd,value,0.05,0
              scale 1.5*D/14
              translate <-D/4,D/5,-ep/2+dp/2-0.05>
              }
        #end
        translate (5+D/2)*y
        }
     object {
        RTH_PIN(0,D)
        }
     object {
        RTH_PIN(180,D)
        }
     }
#end

#macro R_THERM_PTC660_5_3(value)
  R_THERM_PTC660_BASE(value,5,3)
#end

#macro R_THERM_PTC660_5_4(value)
  R_THERM_PTC660_BASE(value,5,4)
#end

#macro R_THERM_PTC660_5_5(value)
  R_THERM_PTC660_BASE(value,5,5)
#end

#macro R_THERM_PTC660_5_55(value)
  R_THERM_PTC660_BASE(value,5,5.5)
#end

#macro R_THERM_PTC660_7_3(value)
  R_THERM_PTC660_BASE(value,7,3)
#end

#macro R_THERM_PTC660_7_4(value)
  R_THERM_PTC660_BASE(value,7,4)
#end

#macro R_THERM_PTC660_7_5(value)
  R_THERM_PTC660_BASE(value,7,5)
#end

#macro R_THERM_PTC660_7_55(value)
  R_THERM_PTC660_BASE(value,7,5.5)
#end

#macro R_THERM_PTC660_85_3(value)
  R_THERM_PTC660_BASE(value,8.5,3)
#end

#macro R_THERM_PTC660_85_4(value)
  R_THERM_PTC660_BASE(value,8.5,4)
#end

#macro R_THERM_PTC660_85_5(value)
  R_THERM_PTC660_BASE(value,8.5,5)
#end

#macro R_THERM_PTC660_85_55(value)
  R_THERM_PTC660_BASE(value,8.5,5.5)
#end

#macro R_THERM_PTC660_105_3(value)
  R_THERM_PTC660_BASE(value,10.5,3)
#end

#macro R_THERM_PTC660_105_4(value)
  R_THERM_PTC660_BASE(value,10.5,4)
#end

#macro R_THERM_PTC660_105_5(value)
  R_THERM_PTC660_BASE(value,10.5,5)
#end

#macro R_THERM_PTC660_105_55(value)
  R_THERM_PTC660_BASE(value,10.5,5.5)
#end

#macro R_THERM_PTC660_125_3(value)
  R_THERM_PTC660_BASE(value,12.5,3)
#end

#macro R_THERM_PTC660_125_4(value)
  R_THERM_PTC660_BASE(value,12.5,4)
#end

#macro R_THERM_PTC660_125_5(value)
  R_THERM_PTC660_BASE(value,12.5,5)
#end

#macro R_THERM_PTC660_125_55(value)
  R_THERM_PTC660_BASE(value,12.5,5.5)
#end

#macro R_THERM_PTC660_165_3(value)
  R_THERM_PTC660_BASE(value,16.5,3)
#end

#macro R_THERM_PTC660_165_4(value)
  R_THERM_PTC660_BASE(value,16.5,4)
#end

#macro R_THERM_PTC660_165_5(value)
  R_THERM_PTC660_BASE(value,16.5,5)
#end

#macro R_THERM_PTC660_165_55(value)
  R_THERM_PTC660_BASE(value,16.5,5.5)
#end

#macro R_THERM_PTC660_205_3(value)
  R_THERM_PTC660_BASE(value,20.5,3)
#end

#macro R_THERM_PTC660_205_4(value)
  R_THERM_PTC660_BASE(value,20.5,4)
#end

#macro R_THERM_PTC660_205_5(value)
  R_THERM_PTC660_BASE(value,20.5,5)
#end

#macro R_THERM_PTC660_205_55(value)
  R_THERM_PTC660_BASE(value,20.5,5.5)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=R_THERM_PTC660_5_3(:PTC thermistor D=5 b=3
//=R_THERM_PTC660_5_4(:PTC thermistor D=5 b=4
//=R_THERM_PTC660_5_5(:PTC thermistor D=5 b=5
//=R_THERM_PTC660_5_55(:PTC thermistor D=5 b=5.5
//=R_THERM_PTC660_7_3(:PTC thermistor D=7 b=3
//=R_THERM_PTC660_7_4(:PTC thermistor D=7 b=4
//=R_THERM_PTC660_7_5(:PTC thermistor D=7 b=5
//=R_THERM_PTC660_7_55(:PTC thermistor D=7 b=5.5
//=R_THERM_PTC660_85_3(:PTC thermistor D=8.5 b=3
//=R_THERM_PTC660_85_4(:PTC thermistor D=8.5 b=4
//=R_THERM_PTC660_85_5(:PTC thermistor D=8.5 b=5
//=R_THERM_PTC660_85_55(:PTC thermistor D=8.5 b=5.5
//=R_THERM_PTC660_105_3(:PTC thermistor D=10.5 b=3
//=R_THERM_PTC660_105_4(:PTC thermistor D=10.5 b=4
//=R_THERM_PTC660_105_5(:PTC thermistor D=10.5 b=5
//=R_THERM_PTC660_105_55(:PTC thermistor D=10.5 b=5.5
//=R_THERM_PTC660_125_3(:PTC thermistor D=12.5 b=3
//=R_THERM_PTC660_125_4(:PTC thermistor D=12.5 b=4
//=R_THERM_PTC660_125_5(:PTC thermistor D=12.5 b=5
//=R_THERM_PTC660_125_55(:PTC thermistor D=12.5 b=5.5
//=R_THERM_PTC660_165_3(:PTC thermistor D=16.5 b=3
//=R_THERM_PTC660_165_4(:PTC thermistor D=16.5 b=4
//=R_THERM_PTC660_165_5(:PTC thermistor D=16.5 b=5
//=R_THERM_PTC660_165_55(:PTC thermistor D=16.5 b=5.5
//=R_THERM_PTC660_205_3(:PTC thermistor D=20.5 b=3
//=R_THERM_PTC660_205_4(:PTC thermistor D=20.5 b=4
//=R_THERM_PTC660_205_5(:PTC thermistor D=20.5 b=5
//=R_THERM_PTC660_205_55(:PTC thermistor D=20.5 b=5.5
// end assignment
