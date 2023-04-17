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
           Round_Box_Merge(<W,d,L> <-W,-d,-L> d/8)
           Round_Box_Merge(<W-1,3*d,L-1> <-(W-1),(d-0.1),-(L-3.81-1)> d/8)
           Round_Box_Merge(<W-1,-3*d,L-1> <-(W-1),-(d-0.1),-(L-3.81-1)> d/8)
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
// end assignment
