/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Molex series 6373, 7395, 6410
 * KK 254 Solid Headers with Friction Lock
 * 16.05.2023 wk
 *
 * library: con-molex
 * 
 * part-numbers  0022232021, 0022232031, 0022232041, 0022232051,
 *               0022232061, 0022232071, 0022232081, 0022232091,
 *               0022232101, 0022232111, 0022232121,
 *               0022057028, 0022057038, 0022057048, 0022057058,
 *               0022057068, 0022057078, 0022057088, 0022057098,
 *               0022057108, 0022057118, 0022057128,
 *               0022272021, 0022272031, 0022272041, 0022272051,
 *               0022272061, 0022272071, 0022272081, 0022272091,
 *               0022272101, 0022272111, 0022272121,
 *
 ******************************************************************************/


/*******************************************************************************
 * Nylon plastic case
 ******************************************************************************/
#macro KK254_case(pins,Width,height)
  union {
     #local Nylon = texture {
         pigment {Wheat}
         finish { ambient(0.1 * global_ambient_mul)}
         };
     #local y1 = -(Width-3.10);
     difference {
        box {
           <-2.54/2*pins,0   ,y1>
           <+2.54/2*pins,3.18,+3.1>
           }
        #local slot = box {
           <-1.74/2,-0.1,y1-0.1>
           <+1.74/2,+0.8,+3.2>
           };
        GRID(slot,2.54,pins,1)
        }
     difference {
        prism {
           linear_sweep
           linear_spline
           -2.54*(pins-1)/2, +2.54*(pins-1)/2,
           8,
           <3.10,3.10>
           <3.10,height>
           <2.25,height>
           <1.40,7.22>
           <1.40,6.45>
           <2.25,5.00>
           <2.25,3.10>
           <3.10,3.10>
           rotate <-90,-90,0>
           }
        #local edge = box {
           <-0.3,-0.3,-1.6>
           <+0.3,+0.3,+1.6>
           rotate <0,0,45>
           };
        object {
           GRID(edge,2.54*(pins-1),2,1)
           translate <0,height,1.6>
           }
        }
     texture {
        Nylon
        }
     }
#end

/*******************************************************************************
 * Straight version, series 6373
 ******************************************************************************/
#macro KK254_6373(pins)
  union {
     difference {
        KK254_case(pins,6.35,8.18)
        #local slot = box {
           <-0.7/2,3.19,+2.5/2> <+0.7/2,8.19,+7/2>
           texture {
              pigment {
                 Wheat
                 }
              finish {
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           };
        #local Pin0 = -(pins+1)/2 * 2.54;
        #switch(pins)
           #range(6,10)
             object { slot translate <Pin0 + 4.5*2.54,0,0> }
             #break
           #range(11,14)
             object { slot translate <Pin0 + 4.5*2.54,0,0> }
             object { slot translate <Pin0 + 8.5*2.54,0,0> }
             #break
           #range(15,18)
             object { slot translate <Pin0 + 4.5*2.54,0,0> }
             object { slot translate <Pin0 + 12.5*2.54,0,0> }
             #break
           #range(19,22)
             object { slot translate <Pin0 + 4.5*2.54,0,0> }
             object { slot translate <Pin0 + 16.5*2.54,0,0> }
             #break
           #range(23,26)
             object { slot translate <Pin0 + 4.5*2.54,0,0> }
             object { slot translate <Pin0 + 20.5*2.54,0,0> }
             #break
           #range(27,28)
             object { slot translate <Pin0 + 4.5*2.54,0,0> }
             object { slot translate <Pin0 + 24.5*2.54,0,0> }
             #break
        #end
        rotate <0,0,0>
        }
     object{
        PIN_STRAIGHT_ROW(pins,2.54,0.635,11,3,col_silver)
        }
     }
#end

/*******************************************************************************
 * Straight version, series 6410
 ******************************************************************************/
#macro KK254_6410(pins)
  union {
     difference {
        KK254_case(pins,5.8,11.70)
        #if (pins > 6)
           #local cut = (pins - 5) * 2.54;
           box {
              <-cut/2, 3.19,0>
              <+cut/2,11.71,4>
              texture {
                 pigment {
                    Wheat
                    }
                 finish {
                    ambient (0.1 * global_ambient_mul)
                    }
                 }
              }
        #end
        }
     object{
        PIN_STRAIGHT_ROW(pins,2.54,0.635,11,3,col_silver)
        }
     }
#end

/*******************************************************************************
 * Right Angle version, series 7395
 ******************************************************************************/
#macro KK254_7395(pins)
  union {
     difference {
        KK254_case(pins,5.08,11.70)
        #if (pins > 5)
           #local cut = (pins - 5) * 2.54;
           box {
              <-cut/2, 3.19,0>
              <+cut/2,11.71,4>
              texture {
                 pigment {
                    Wheat
                    }
                 finish {
                    ambient (0.1 * global_ambient_mul)
                    }
                 }
              }
        #end
        rotate <-90,0,0>
        translate <0,2.5,-1.8>
        }
     object {
        PIN_BENDED_ROW(pins,2.54,0.635,0.8,2.5,3,12.5,col_silver)
        translate <0,0,0>
        }
     }
#end


#macro CON_THT_MOLEX_0022232021()  KK254_6373(2)  #end
#macro CON_THT_MOLEX_0022232031()  KK254_6373(3)  #end
#macro CON_THT_MOLEX_0022232041()  KK254_6373(4)  #end
#macro CON_THT_MOLEX_0022232051()  KK254_6373(5)  #end
#macro CON_THT_MOLEX_0022232061()  KK254_6373(6)  #end
#macro CON_THT_MOLEX_0022232071()  KK254_6373(7)  #end
#macro CON_THT_MOLEX_0022232081()  KK254_6373(8)  #end
#macro CON_THT_MOLEX_0022232091()  KK254_6373(9)  #end
#macro CON_THT_MOLEX_0022232101()  KK254_6373(10) #end
#macro CON_THT_MOLEX_0022232111()  KK254_6373(11) #end
#macro CON_THT_MOLEX_0022232121()  KK254_6373(12) #end
//---
#macro CON_THT_MOLEX_0022057028()  KK254_7395(2)  #end
#macro CON_THT_MOLEX_0022057038()  KK254_7395(3)  #end
#macro CON_THT_MOLEX_0022057048()  KK254_7395(4)  #end
#macro CON_THT_MOLEX_0022057058()  KK254_7395(5)  #end
#macro CON_THT_MOLEX_0022057068()  KK254_7395(6)  #end
#macro CON_THT_MOLEX_0022057078()  KK254_7395(7)  #end
#macro CON_THT_MOLEX_0022057088()  KK254_7395(8)  #end
#macro CON_THT_MOLEX_0022057098()  KK254_7395(9)  #end
#macro CON_THT_MOLEX_0022057108()  KK254_7395(10) #end
#macro CON_THT_MOLEX_0022057118()  KK254_7395(11) #end
#macro CON_THT_MOLEX_0022057128()  KK254_7395(12) #end
//---
#macro CON_THT_MOLEX_0022272021()  KK254_6410(2)  #end
#macro CON_THT_MOLEX_0022272031()  KK254_6410(3)  #end
#macro CON_THT_MOLEX_0022272041()  KK254_6410(4)  #end
#macro CON_THT_MOLEX_0022272051()  KK254_6410(5)  #end
#macro CON_THT_MOLEX_0022272061()  KK254_6410(6)  #end
#macro CON_THT_MOLEX_0022272071()  KK254_6410(7)  #end
#macro CON_THT_MOLEX_0022272081()  KK254_6410(8)  #end
#macro CON_THT_MOLEX_0022272091()  KK254_6410(9)  #end
#macro CON_THT_MOLEX_0022272101()  KK254_6410(10) #end
#macro CON_THT_MOLEX_0022272111()  KK254_6410(11) #end
#macro CON_THT_MOLEX_0022272121()  KK254_6410(12) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-molex:22-23-2021=CON_THT_MOLEX_0022232021(:Molex series 6373 header with friction lock
//con-molex:22-23-2031=CON_THT_MOLEX_0022232031(:Molex series 6373 header with friction lock
//con-molex:22-23-2041=CON_THT_MOLEX_0022232041(:Molex series 6373 header with friction lock
//con-molex:22-23-2051=CON_THT_MOLEX_0022232051(:Molex series 6373 header with friction lock
//con-molex:22-23-2061=CON_THT_MOLEX_0022232061(:Molex series 6373 header with friction lock
//con-molex:22-23-2071=CON_THT_MOLEX_0022232071(:Molex series 6373 header with friction lock
//con-molex:22-23-2081=CON_THT_MOLEX_0022232081(:Molex series 6373 header with friction lock
//con-molex:22-23-2091=CON_THT_MOLEX_0022232091(:Molex series 6373 header with friction lock
//con-molex:22-23-2101=CON_THT_MOLEX_0022232101(:Molex series 6373 header with friction lock
//con-molex:22-23-2111=CON_THT_MOLEX_0022232111(:Molex series 6373 header with friction lock
//con-molex:22-23-2121=CON_THT_MOLEX_0022232121(:Molex series 6373 header with friction lock
//con-molex:7395-02=CON_THT_MOLEX_0022057028(:Molex series 7395 header with friction lock
//con-molex:7395-03=CON_THT_MOLEX_0022057038(:Molex series 7395 header with friction lock
//con-molex:7395-04=CON_THT_MOLEX_0022057048(:Molex series 7395 header with friction lock
//con-molex:7395-05=CON_THT_MOLEX_0022057058(:Molex series 7395 header with friction lock
//con-molex:7395-06=CON_THT_MOLEX_0022057068(:Molex series 7395 header with friction lock
//con-molex:7395-07=CON_THT_MOLEX_0022057078(:Molex series 7395 header with friction lock
//con-molex:7395-08=CON_THT_MOLEX_0022057088(:Molex series 7395 header with friction lock
//con-molex:7395-09=CON_THT_MOLEX_0022057098(:Molex series 7395 header with friction lock
//con-molex:7395-10=CON_THT_MOLEX_0022057108(:Molex series 7395 header with friction lock
//con-molex:7395-11=CON_THT_MOLEX_0022057118(:Molex series 7395 header with friction lock
//con-molex:7395-12=CON_THT_MOLEX_0022057128(:Molex series 7395 header with friction lock
//con-molex:6410-02=CON_THT_MOLEX_0022272021(:Molex series 6410 header with friction lock
//con-molex:6410-03=CON_THT_MOLEX_0022272031(:Molex series 6410 header with friction lock
//con-molex:6410-04=CON_THT_MOLEX_0022272041(:Molex series 6410 header with friction lock
//con-molex:6410-05=CON_THT_MOLEX_0022272051(:Molex series 6410 header with friction lock
//con-molex:6410-06=CON_THT_MOLEX_0022272061(:Molex series 6410 header with friction lock
//con-molex:6410-07=CON_THT_MOLEX_0022272071(:Molex series 6410 header with friction lock
//con-molex:6410-08=CON_THT_MOLEX_0022272081(:Molex series 6410 header with friction lock
//con-molex:6410-09=CON_THT_MOLEX_0022272091(:Molex series 6410 header with friction lock
//con-molex:6410-10=CON_THT_MOLEX_0022272101(:Molex series 6410 header with friction lock
//con-molex:6410-11=CON_THT_MOLEX_0022272111(:Molex series 6410 header with friction lock
//con-molex:6410-12=CON_THT_MOLEX_0022272121(:Molex series 6410 header with friction lock
// end assignment
