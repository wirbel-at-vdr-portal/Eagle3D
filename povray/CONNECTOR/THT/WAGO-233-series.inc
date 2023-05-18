/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * WAGO-233 series PCB TERMINAL STRIP, 2.50mm/2.54mm SPACING WITH PUSH BOTTONS
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * 18.05.2023, 100% rewritten from scratch, wk
 *
 * library: con-wago.lib
 *  WAGO 233-1xx   2.50mm grid, gray
 *  WAGO 233-2xx   2.50mm grid, gray    push button
 *  WAGO 233-4xx   2.54mm grid, orange
 *  WAGO 233-5xx   2.54mm grid, orange  push button
 * <0,0> = center of pins
 * pins - number of rows
 * *****************************************************************************/
#macro WAGO_233(Type,pins)
  union {
    #if ((Type = 4) | (Type = 5)) 
       #local CaseColor = color red 1 green 0.45 blue 0;
    #else
       #local CaseColor = color red 0.6 green 0.6 blue 0.6;
    #end

    #if ((Type = 1) | (Type = 2)) 
       #local pitch = 2.50; 
    #else
       #local pitch = 2.54;
    #end

    #if ((Type = 2) | (Type = 5))
       #local WithHandle = on;
    #else
       #local WithHandle = off;
    #end
  
    #local Slice =
       union {
          difference {
             merge {
                #local w = pitch - 0.10;
                prism {
                   linear_spline
                   -w/2, +w/2,
                   11,
                   <-2.80/2, +0.5>
                   <-3.35/2, +0.0>
                   <  -5.50, +0.0>
                   <  -7.20, +3.4>
                   <  -2.95,+11.41>
                   <  -2.11,+11.515>
                   <  +4.90, +7.5>
                   <  +4.90, +0.0>
                   <+3.35/2, +0.0>
                   <+2.80/2, +0.5>
                   <-2.80/2, +0.5>
                   }
                cylinder {
                   <-2.50,-w/2,+11.19>
                   <-2.50,+w/2,+11.19>
                   1/2
                   }
                rotate <0,-90,-90>
                }
             }
          };
  
    #local Clamp =
       union {
          difference {
             object {
                Slice
                }
             box {
                <-pitch/2      , 5.3,-9.2>
                <+(pitch-0.7)/2, 7.5,-5.0>
                rotate x*30
                }
             box {
                <-pitch/2      , 3.8,-9.2>
                <+(pitch-0.7)/2, 0.0,-5.0>
                rotate x*30
                }
             cylinder {
                <-pitch/2, 9.3, -3.0>
                <+pitch/2, 9.3, -3.0>
                1.1/2
                }
             }
          #if (WithHandle)
             union {
                object {
                   Round_Box(
                      <-pitch/2+0.3      , 7.5,-5.2>
                      <+(pitch-0.7)/2-0.3, 5.5,-7.8>
                      0.1 0)
                   rotate x*30
                   }
                cylinder {
                   <-pitch/2, 9.3, -3.0>
                   <+pitch/2, 9.3, -3.0>
                   1.0/2
                   }
                object {
                   Round_Box(
                      <-0.8, 10.2,-6.0>
                      <+0.3,  7.5,-7.0>
                      0.1 0)
                   rotate x*30
                   }
                object {
                   Round_Box(
                      <-0.3, -1/2, -1.5/2>
                      <+0.3, +1/2, +1.5/2>
                      0.1 0)
                   rotate x*0
                   translate <-0.25,11.7,0.7>
                   }
                difference {
                   Round_Box(
                      <-2.2/2, -1.5/2, -2.5/2>
                      <+2.2/2, +1.5/2, +2.5/2>
                      0.3 0)
                   Round_Box(
                      <-1.0/2, +0.5,   -1.5/2>
                      <+1.0/2, +1.6/2, +1.5/2>
                      0.3 0)
                   rotate x*-30
                   translate <-0.25,12.2,0.3>
                   }
                pigment {
                   White * 0.97
                   }
                }
          #else
             box {
                <-(pitch-0.6)/2, 6.1,-8.0>
                <+(pitch-0.6)/2, 7.5,-7.7>
                rotate x*30
                texture {
                   col_silver
                   }
                }
          #end
          difference {
             box {
                <-pitch/2      , 3.8,-5.2>
                <+(pitch-0.7)/2, 0.0,-1.0>
                rotate x*30
                }
             box {
                <-pitch/2      +0.1, 3.8-0.1,-5.3>
                <+(pitch-0.7)/2-0.1, 0.0+0.1,-1.0>
                rotate x*30
                }
             texture {
                col_silver
                }
             }
          union {
             box {
                <-pitch/2      , 3.8,-5.2>
                <+(pitch-0.7)/2, 0.0,-1.0>
                rotate x*30
                }
             box {
                <-pitch/2      +0.1, 3.8-0.1,-5.3>
                <+(pitch-0.7)/2-0.1, 0.0+0.1,-1.0>
                rotate x*30
                }
             GRID(
                box {
                   <-0.75/2, 0,-0.5/2>
                   <+0.75/2,-3,+0.5/2>
                   }
                5.0,1,2
                )
             texture {
                col_silver
                }
             }
          pigment {
             CaseColor
             }
          }; 
    GRID(Clamp,pitch,pins,1)
    object {
       Slice
       scale x*(1.0/2.54)
       translate <-pins/2*pitch-1.0/2,0,0>
       pigment {
          CaseColor
          }
       }
     }
#end


#macro CON_THT_WAGO233_102() WAGO_233(1,02) #end
#macro CON_THT_WAGO233_103() WAGO_233(1,03) #end
#macro CON_THT_WAGO233_104() WAGO_233(1,04) #end
#macro CON_THT_WAGO233_105() WAGO_233(1,05) #end
#macro CON_THT_WAGO233_106() WAGO_233(1,06) #end
#macro CON_THT_WAGO233_107() WAGO_233(1,07) #end
#macro CON_THT_WAGO233_108() WAGO_233(1,08) #end
#macro CON_THT_WAGO233_109() WAGO_233(1,09) #end
#macro CON_THT_WAGO233_110() WAGO_233(1,10) #end
#macro CON_THT_WAGO233_112() WAGO_233(1,12) #end
#macro CON_THT_WAGO233_116() WAGO_233(1,16) #end
#macro CON_THT_WAGO233_124() WAGO_233(1,24) #end
#macro CON_THT_WAGO233_136() WAGO_233(1,36) #end
#macro CON_THT_WAGO233_148() WAGO_233(1,48) #end
#macro CON_THT_WAGO233_202() WAGO_233(2,02) #end
#macro CON_THT_WAGO233_203() WAGO_233(2,03) #end
#macro CON_THT_WAGO233_204() WAGO_233(2,04) #end
#macro CON_THT_WAGO233_205() WAGO_233(2,05) #end
#macro CON_THT_WAGO233_206() WAGO_233(2,06) #end
#macro CON_THT_WAGO233_207() WAGO_233(2,07) #end
#macro CON_THT_WAGO233_208() WAGO_233(2,08) #end
#macro CON_THT_WAGO233_209() WAGO_233(2,09) #end
#macro CON_THT_WAGO233_210() WAGO_233(2,10) #end
#macro CON_THT_WAGO233_212() WAGO_233(2,12) #end
#macro CON_THT_WAGO233_216() WAGO_233(2,16) #end
#macro CON_THT_WAGO233_224() WAGO_233(2,24) #end
#macro CON_THT_WAGO233_236() WAGO_233(2,36) #end
#macro CON_THT_WAGO233_248() WAGO_233(2,48) #end
#macro CON_THT_WAGO233_402() WAGO_233(4,02) #end
#macro CON_THT_WAGO233_403() WAGO_233(4,03) #end
#macro CON_THT_WAGO233_404() WAGO_233(4,04) #end
#macro CON_THT_WAGO233_405() WAGO_233(4,05) #end
#macro CON_THT_WAGO233_406() WAGO_233(4,06) #end
#macro CON_THT_WAGO233_407() WAGO_233(4,07) #end
#macro CON_THT_WAGO233_408() WAGO_233(4,08) #end
#macro CON_THT_WAGO233_409() WAGO_233(4,09) #end
#macro CON_THT_WAGO233_410() WAGO_233(4,10) #end
#macro CON_THT_WAGO233_412() WAGO_233(4,12) #end
#macro CON_THT_WAGO233_416() WAGO_233(4,16) #end
#macro CON_THT_WAGO233_424() WAGO_233(4,24) #end
#macro CON_THT_WAGO233_436() WAGO_233(4,36) #end
#macro CON_THT_WAGO233_448() WAGO_233(4,48) #end
#macro CON_THT_WAGO233_502() WAGO_233(5,02) #end
#macro CON_THT_WAGO233_503() WAGO_233(5,03) #end
#macro CON_THT_WAGO233_504() WAGO_233(5,04) #end
#macro CON_THT_WAGO233_505() WAGO_233(5,05) #end
#macro CON_THT_WAGO233_506() WAGO_233(5,06) #end
#macro CON_THT_WAGO233_507() WAGO_233(5,07) #end
#macro CON_THT_WAGO233_508() WAGO_233(5,08) #end
#macro CON_THT_WAGO233_509() WAGO_233(5,09) #end
#macro CON_THT_WAGO233_510() WAGO_233(5,10) #end
#macro CON_THT_WAGO233_512() WAGO_233(5,12) #end
#macro CON_THT_WAGO233_516() WAGO_233(5,16) #end
#macro CON_THT_WAGO233_524() WAGO_233(5,24) #end
#macro CON_THT_WAGO233_536() WAGO_233(5,36) #end
#macro CON_THT_WAGO233_548() WAGO_233(5,48) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-wago:233-102=CON_THT_WAGO233_102(:WAGO-233 cage clamp
//con-wago:233-103=CON_THT_WAGO233_103(:WAGO-233 cage clamp
//con-wago:233-104=CON_THT_WAGO233_104(:WAGO-233 cage clamp
//con-wago:233-105=CON_THT_WAGO233_105(:WAGO-233 cage clamp
//con-wago:233-106=CON_THT_WAGO233_106(:WAGO-233 cage clamp
//con-wago:233-107=CON_THT_WAGO233_107(:WAGO-233 cage clamp
//con-wago:233-108=CON_THT_WAGO233_108(:WAGO-233 cage clamp
//con-wago:233-109=CON_THT_WAGO233_109(:WAGO-233 cage clamp
//con-wago:233-110=CON_THT_WAGO233_110(:WAGO-233 cage clamp
//con-wago:233-112=CON_THT_WAGO233_112(:WAGO-233 cage clamp
//con-wago:233-116=CON_THT_WAGO233_116(:WAGO-233 cage clamp
//con-wago:233-124=CON_THT_WAGO233_124(:WAGO-233 cage clamp
//con-wago:233-136=CON_THT_WAGO233_136(:WAGO-233 cage clamp
//con-wago:233-148=CON_THT_WAGO233_148(:WAGO-233 cage clamp
//con-wago:233-202=CON_THT_WAGO233_202(:WAGO-233 cage clamp
//con-wago:233-203=CON_THT_WAGO233_203(:WAGO-233 cage clamp
//con-wago:233-204=CON_THT_WAGO233_204(:WAGO-233 cage clamp
//con-wago:233-205=CON_THT_WAGO233_205(:WAGO-233 cage clamp
//con-wago:233-206=CON_THT_WAGO233_206(:WAGO-233 cage clamp
//con-wago:233-207=CON_THT_WAGO233_207(:WAGO-233 cage clamp
//con-wago:233-208=CON_THT_WAGO233_208(:WAGO-233 cage clamp
//con-wago:233-209=CON_THT_WAGO233_209(:WAGO-233 cage clamp
//con-wago:233-210=CON_THT_WAGO233_210(:WAGO-233 cage clamp
//con-wago:233-212=CON_THT_WAGO233_212(:WAGO-233 cage clamp
//con-wago:233-216=CON_THT_WAGO233_216(:WAGO-233 cage clamp
//con-wago:233-224=CON_THT_WAGO233_224(:WAGO-233 cage clamp
//con-wago:233-236=CON_THT_WAGO233_236(:WAGO-233 cage clamp
//con-wago:233-248=CON_THT_WAGO233_248(:WAGO-233 cage clamp
//con-wago:233-402=CON_THT_WAGO233_402(:WAGO-233 cage clamp
//con-wago:233-403=CON_THT_WAGO233_403(:WAGO-233 cage clamp
//con-wago:233-404=CON_THT_WAGO233_404(:WAGO-233 cage clamp
//con-wago:233-405=CON_THT_WAGO233_405(:WAGO-233 cage clamp
//con-wago:233-406=CON_THT_WAGO233_406(:WAGO-233 cage clamp
//con-wago:233-407=CON_THT_WAGO233_407(:WAGO-233 cage clamp
//con-wago:233-408=CON_THT_WAGO233_408(:WAGO-233 cage clamp
//con-wago:233-409=CON_THT_WAGO233_409(:WAGO-233 cage clamp
//con-wago:233-410=CON_THT_WAGO233_410(:WAGO-233 cage clamp
//con-wago:233-412=CON_THT_WAGO233_412(:WAGO-233 cage clamp
//con-wago:233-416=CON_THT_WAGO233_416(:WAGO-233 cage clamp
//con-wago:233-424=CON_THT_WAGO233_424(:WAGO-233 cage clamp
//con-wago:233-436=CON_THT_WAGO233_436(:WAGO-233 cage clamp
//con-wago:233-448=CON_THT_WAGO233_448(:WAGO-233 cage clamp
//con-wago:233-502=CON_THT_WAGO233_502(:WAGO-233 cage clamp
//con-wago:233-503=CON_THT_WAGO233_503(:WAGO-233 cage clamp
//con-wago:233-504=CON_THT_WAGO233_504(:WAGO-233 cage clamp
//con-wago:233-505=CON_THT_WAGO233_505(:WAGO-233 cage clamp
//con-wago:233-506=CON_THT_WAGO233_506(:WAGO-233 cage clamp
//con-wago:233-507=CON_THT_WAGO233_507(:WAGO-233 cage clamp
//con-wago:233-508=CON_THT_WAGO233_508(:WAGO-233 cage clamp
//con-wago:233-509=CON_THT_WAGO233_509(:WAGO-233 cage clamp
//con-wago:233-510=CON_THT_WAGO233_510(:WAGO-233 cage clamp
//con-wago:233-512=CON_THT_WAGO233_512(:WAGO-233 cage clamp
//con-wago:233-516=CON_THT_WAGO233_516(:WAGO-233 cage clamp
//con-wago:233-524=CON_THT_WAGO233_524(:WAGO-233 cage clamp
//con-wago:233-536=CON_THT_WAGO233_536(:WAGO-233 cage clamp
//con-wago:233-548=CON_THT_WAGO233_548(:WAGO-233 cage clamp
// end assignment
