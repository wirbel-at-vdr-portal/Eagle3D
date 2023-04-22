/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * RCD Components, Inc. vertical mount ceramic resistors, PV series
 * Joseph Zeglinski
 *  - A  front width  (see datasheet)
 *  - C  front height (see datasheet)
 *  - lw pin length
 *  - dw pin diameter (E in datasheet)
 * *****************************************************************************/
#macro RES_PVSERIES_BASE(value, A, C, Depth, Wire_Sep, lw, dw, WATTS)
  union {
     #local B = Depth;
     #local L = C/2;
     #local W = A/2;
     #local d = Depth/2;
     #local Stub = max( 0.8, dw );
     #local Horizontal=no;

     union {
        difference {
           Round_Box(<W,d,L> <-W,-d,-L> d/8 0)
           Round_Box(<W-1,3*d,L-1> <-(W-1),(d-0.1),-(L-3.81-1)> d/8 0)
           Round_Box(<W-1,-3*d,L-1> <-(W-1),-(d-0.1),-(L-3.81-1)> d/8 0)
           prism {
              -(d+0.01), (d+0.01), 4,
              <A/2-0.5, -0.01>
              <(A/2-2.0), 3.81>,
              <-(A/2-2.0), 3.81>,
              <-(A/2-0.5), -0.01>
              translate<0,0,-L>
              }
           texture {
              T_Grnt1
              }
           rotate <-90,0,0>
           translate <0,L,0>
           }
        union {
           #local Pwr1 = concat( "RCD   PV",  str(WATTS,0,0) );
           #local Pwr2 = concat( value,  str(WATTS,3,0), "W" );
           #local S = 2;
           text {
              ttf besch_font Pwr1 0.01, 0
              scale <S,S,S>
              translate <-6,d-S,-(d-0.08)>
              rotate <180,0,90>
              pigment {
                 Black
                 }
              }
           text {
              ttf besch_font Pwr2 0.01, 0
              scale <S,S,S>
              translate <-5,-(d-S),-(d-0.08)>
              rotate <180,0,90>
              pigment {
                 Black
                 }
              }
           text {
              ttf besch_font Pwr1 0.01, 0
              scale <S,S,S>
              translate <-6,d-S,-(d-0.08 )>
              rotate <0,0,(Horizontal ? 0:90)>
              pigment {
                 Black
                 }
              }
           text {
              ttf besch_font Pwr2 0.01, 0
              scale <S,S,S>
              translate <-5,-(d-S),-(d-0.08)>
              rotate <0,0,(Horizontal ? 0:90)>
              pigment {
                 Black
                 }
              }
           rotate <0,0,180>
           translate <0,(L+3.81/2),0>
           }
        translate < 0,-L,0>
        }
     object {
        TOOLS_WIRE_LEADS(A, C, lw, dw,  Wire_Sep, global_res_bend_radius, 0.0, "H")
        }
     translate< 0,L,0>
     }
  pigment {
     Gray50
     }
  finish {
     phong 1  ambient (0.1 * global_ambient_mul)
     }
#end


#macro RES_THT_PV2(value) //A     C     B     D      lw     E     WATT
  RES_PVSERIES_BASE(value, 11.4, 20.3,  7.6,  5.08,  3.81,  0.7,  2)
#end

#macro RES_THT_PV3(value)
  RES_PVSERIES_BASE(value, 12.1, 24.9,  8.9,  5.08,  3.81,  0.8,  3)
#end

#macro RES_THT_PV5(value)
  RES_PVSERIES_BASE(value, 12.7, 25.4,  9.2,  5.08,  3.81,  0.8,  5)
#end

#macro RES_THT_PV7(value)
  RES_PVSERIES_BASE(value, 12.7, 38.6,  10.0, 5.08,  3.81,  0.8,  7)
#end

#macro RES_THT_PV10(value)
  RES_PVSERIES_BASE(value, 12.7, 51.3,  10.0, 5.08,  3.81,  0.8,  10)
#end

#macro RES_THT_PV10S(value)
  RES_PVSERIES_BASE(value, 15.9, 35.0,  12.7, 7.62,  3.81,  0.9,  10)
#end

#macro RES_THT_PV10A(value)
  RES_PVSERIES_BASE(value, 15.9, 35.0,  12.7, 5.08,  3.81,  0.9,  10)
#end



/*******************************************************************************
 * RCD components PW series general purpose 1W to 25W ceramic-encased resistors
 * Joseph Zeglinski
 * - A, B, E see datasheet
 * - lw wire length
 *******************************************************************************/
#macro RES_PWSERIES_BASE(value, A, B, lw, E, grid, Type)
  union {
     union {
        #local Stub = max(0.8, E);

        union {
           Round_Box(
              <+A/2,+B/2,+B/2>
              <-A/2,-B/2,-B/2>
              B/16 0
              )
           box {
              <-(A/2 - 1.0), -(B/2 + 0.005), -(B/2 - 1.0)>
              <+(A/2 - 1.0), -B/2          , +(B/2 - 1.0)>
              pigment {
                 Gray65
                 }
              }
           box {
              <-(A/2 + 0.01), -(B/2 + 0.01), -E/2>
              <+(A/2 + 0.01),             E, +E/2>
              pigment {
                 Gray65
                 }
              }
           texture {
              T_Grnt1
              }
           }
        union {
           text {
              ttf besch_font Type 0.01, 0
              scale 2
              translate <-5,+(B/2 - 2)-1,-(B/2 + 0.01)>
              rotate <270,0,180>
              pigment {
                 Black
                 }
              }
           text {
              ttf besch_font value 0.01, 0
              scale 2
              translate <-5,-(B/2 - 2)-1,-(B/2 + 0.01)>
              rotate <270,0,180>
              pigment {
                 Black
                 }
              }
           }
        pigment {
           Black
           }
        rotate <0,180,0>
        }
     object {
        TOOLS_WIRE_LEADS(A, B, lw, E, grid, global_res_bend_radius, 1.5, "H")
        }
     translate <0, B/2 + 1.5, 0>
     pigment {
        Gray50
        }
     finish {
        phong 1
        ambient (0.1 * global_ambient_mul)
        }
     }
#end 

#macro RES_THT_PW1_228mm(value)
  RES_PWSERIES_BASE(value, 15.8, 6.4, 25.4, 0.7, 22.86, "RCD PW1")
#end

#macro RES_THT_PW2_254mm(value)
  RES_PWSERIES_BASE(value, 18.3, 6.8, 25.4, 0.7, 25.40, "RCD PW2")
#end

#macro RES_THT_PW3_304mm(value)
  RES_PWSERIES_BASE(value, 23.1, 7.9, 28.4, 0.8, 30.48, "RCD PW3")
#end

#macro RES_THT_PW5_330mm(value)
  RES_PWSERIES_BASE(value, 23.1, 9.7, 28.4, 0.8, 33.02, "RCD PW51")
#end

#macro RES_THT_PW7_457mm(value)
  RES_PWSERIES_BASE(value, 36.0, 9.7, 31.8, 0.8, 45.72, "RCD PW7")
#end

#macro RES_THT_PW10_609mm(value)
  RES_PWSERIES_BASE(value, 50.0, 9.7, 31.8, 0.8, 60.96, "RCD PW10")
#end

#macro RES_THT_PW15_635mm(value)
  RES_PWSERIES_BASE(value, 50.0, 12.7, 31.8, 0.8, 63.50, "RCD PW15")
#end

#macro RES_THT_PW20_812mm(value)
  RES_PWSERIES_BASE(value, 65.0, 14.7, 31.8, 0.8, 81.28, "RCD PW20")
#end

#macro RES_THT_PW22_812mm(value)
  RES_PWSERIES_BASE(value, 65.0, 14.7, 31.8, 0.8, 81.28, "RCD PW22")
#end

#macro RES_THT_PW25_812mm(value)
  RES_PWSERIES_BASE(value, 65.0, 14.7, 31.8, 0.8, 81.28, "RCD PW25")
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=RES_THT_PV2(:vertical mount ceramic resistor
//=RES_THT_PV3(:vertical mount ceramic resistor
//=RES_THT_PV5(:vertical mount ceramic resistor
//=RES_THT_PV7(:vertical mount ceramic resistor
//=RES_THT_PV10(:vertical mount ceramic resistor
//=RES_THT_PV10S(:vertical mount ceramic resistor
//=RES_THT_PV10A(:vertical mount ceramic resistor
//=RES_THT_PW1_228mm(:RCD components PW series resistor:
//=RES_THT_PW2_254mm(:RCD components PW series resistor:
//=RES_THT_PW3_304mm(:RCD components PW series resistor:
//=RES_THT_PW5_330mm(:RCD components PW series resistor:
//=RES_THT_PW7_457mm(:RCD components PW series resistor:
//=RES_THT_PW10_609mm(:RCD components PW series resistor:
//=RES_THT_PW15_635mm(:RCD components PW series resistor:
//=RES_THT_PW20_812mm(:RCD components PW series resistor:
//=RES_THT_PW22_812mm(:RCD components PW series resistor:
//=RES_THT_PW25_812mm(:RCD components PW series resistor:
// end assignment
