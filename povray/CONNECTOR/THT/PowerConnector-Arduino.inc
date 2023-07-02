/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * similar to CON_DCPOWERCONNECTOR, -wk
 * no lbr known yet..
 ******************************************************************************/
#macro CON_THT_Power_ArduinoDC21()
  union {
     difference {
        union {
           Round_Box(
              <-9/2, 0,-7.5  >
              <+9/2,11,-7.5+3>
              0.5 0)
           Round_Box(
              <-9/2,  0,-7.5>
              <+9/2,6.5,3.2+2.5/2>
              0.5 0)
           cylinder {
              <0,6.5,-7.5>
              <0,6.5,3.2+2.5/2>
              4.5
              }
           box {
              <-8.8/2,  0, 3.2+2.5/2>
              <+8.8/2,6.5,-7.5+14.2 >
              }
           cylinder {
              <0,6.5, 3.2+2.5/2>
              <0,6.5,-7.5+14.2>
              4.4
              }
           }
        box {
           <-9/2,3.5,-7.5+13.2>
           <+9/2,11.2,-7.5+14.3>
           }
        box {
           <-2.5/2,-0.1,-7.5+13.2>
           <+2.5/2,   4,-7.5+14.3>
           }
        cylinder {
           <0,6.5,-8     >
           <0,6.5,-7.5+10>
           5.5/2
           }
        pigment {
           Gray20
           }
        finish {
           Shiny
           ambient 0.1*global_ambient_mul
           }
        }
     union {
        cylinder {
           <0,6.5,-1.0>
           <0,6.5,3.2+2.5/2>
           2.1/2
           }
        sphere {
           <0,6.5,-1.0>
           2.1/2
           }
        cylinder {
           <0,6.5,3.2+2.8-0.5/2>
           <0,6.5,3.2+2.8+0.5/2>
           4/2
           }
        cylinder {
           <0,6.5,3.2+2.8-0.5/2>
           <0,6.5,3.2+2.8+0.5  >
           1.5/2
           }
        difference {
           union {
              box {
                 <-2.5/2,         6,3.2+2.8-0.5/2>
                 <+2.5/2,-4.1-2.5/2,3.2+2.8+0.5/2>
                 }
              cylinder {
                 <0,-4.1-2.5/2,3.2+2.8-0.5/2>
                 <0,-4.1-2.5/2,3.2+2.8+0.5/2>
                 2.5/2
                 }
              }
           cylinder {
              <0,-4.1-2.5/2,3.2+2.8-0.6/2>
              <0,-4.1-2.5/2,3.2+2.8+0.6/2>
              1.2/2
              }
           }
        difference {
           union {
              box {
                 <-2.5/2,         6,3.2+2.8-0.5/2>
                 <+2.5/2,-4.1-2.5/2,3.2+2.8+0.5/2>
                 }
              cylinder {
                 <0,-4.1-2.5/2,3.2+2.8-0.5/2>
                 <0,-4.1-2.5/2,3.2+2.8+0.5/2>
                 2.5/2
                 }
              }
           cylinder {
              <0,-4.1-2.5/2,3.2+2.8-0.6/2>
              <0,-4.1-2.5/2,3.2+2.8+0.6/2>
              1.2/2
              }
           translate<0,0,-2.8-3.2>
           }
        difference {
           union {
              Round_Box (
                 <4.8-0.5  ,  0,3.2-2.5/2>
                 <4.8+0.5/2,2.5,3.2+2.5/2>
                 0.25 0
                 )
              box {
                 <4.8-0.5/2,       1.0,3.2-2.5/2>
                 <4.8+0.5/2,-4.1-2.5/2,3.2+2.5/2>
                 }
              cylinder {
                 <4.8-0.5/2,-4.1-2.5/2,3.2>
                 <4.8+0.5/2,-4.1-2.5/2,3.2>
                 2.5/2
                 }
              }
           cylinder {
              <4.8-0.5,-4.1-2.5/2,3.2>
              <4.8+0.5,-4.1-2.5/2,3.2>
              1.2/2
              }
           }
        texture {
           Silver_Metal
           }
        }
     rotate<0,180,0>
     }
#end


// collect a few DC power connectors here, as they don't fit
// somewhere
#macro CON_THT_Power_SPC4078() object { CON_THT_Power_ArduinoDC21() translate <0,0,+3>   rotate <0,-90,0> } #end
#macro CON_THT_Power_DCJ0x0x() object { CON_THT_Power_ArduinoDC21() translate <0,0,+3>   rotate <0,180,0> } #end
#macro CON_THT_Power_733980()  object { CON_THT_Power_ArduinoDC21() translate <0,0,-2.5> rotate <0,180,0> } #end
#macro CON_THT_Power_DCJ3P()   object { CON_THT_Power_ArduinoDC21() translate <0,0,+4>   rotate <0,-90,0> } #end /* slightly off */

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//POWERSUPPLY_DC-21MM=CON_THT_Power_ArduinoDC21(:Power Connector DIN 45323 5.5/2.1mm
//DC-21MM=CON_THT_Power_ArduinoDC21(:Power Connector DIN 45323 5.5/2.1mm
//con-jack:SPC4077=CON_THT_Power_SPC4078(:Power Connector DIN 45323 5.5/2.1mm
//con-jack:SPC4078=CON_THT_Power_SPC4078(:Power Connector DIN 45323 5.5/2.1mm
//con-jack:DCJ0202=CON_THT_Power_SPC4078(:Power Connector DIN 45323 5.5/2.1mm
//con-jack:DCJ0303=CON_THT_Power_SPC4078(:Power Connector DIN 45323 5.5/2.1mm
//con-conrad:733980-62=CON_THT_Power_733980(:Power Connector DIN 45323 5.5/2.1mm
//Seeed-OPL-Connector:DCJ3P-14.2X11.0X9.0MM=CON_THT_Power_DCJ3P(:Power Connector DIN 45323 5.5/2.1mm
// end assignment
