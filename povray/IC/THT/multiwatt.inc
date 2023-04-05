/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Heatsink
 ******************************************************************************/
#macro MWHeatSink_()
  #local heatsink_silver = texture {
     T_Silver_5A
     finish {
        ambient (0.10 * global_ambient_mul)
        phong 0.1
        phong_size 10
        }
     }

difference {
   box { <-9.8,0,0> <9.8,1.5,17.5> }
   cylinder { <0,-1,14.7> <0,2,14.7> 3.75/2 }
   box { <0,-1,0> <2,2,4> rotate -45*y translate <9.8,0,15> }
   box { <7.8,-1,-1> <10.8,2,2> } 
   cylinder { <5,-1,10> <5,2,10> 0.8 }
   box { <10, -1, 9.2> <5,2,10.8> }
   box { <8.5,-1,9.5> <11,2,7> }
   box { <8.8,-1,0> <10,2,10> }
   box { <0,-1,0> <-2,2,4> rotate 45*y translate <-9.8,0,15> }
   box { <-7.8,-1,-1> <-10.8,2,2> } 
   cylinder { <-5,-1,10> <-5,2,10> 0.8 }
   box { <-10, -1, 9.2> <-5,2,10.8> }
   box { <-8.5,-1,9.5> <-11,2,7> }
   box { <-8.8,-1,0> <-10,2,10> }
   box { <-0.5,-1,0> <0.5,2,2> }
   box { <-10,-1,-1> <10,2,1> }
   texture{heatsink_silver}
   }
#end

/*******************************************************************************
 * Plastic package with value engraved
 ******************************************************************************/
#macro MWPlastic_(value)
difference {
   box { <-9.8,0,0> <9.8,5,10.7> }
   box { <-10,0,-2> <10,6,0> rotate 7*x translate <0,1.5,0>}
   box { <0,0,0> <3,6,11> rotate 7*z translate <9.8,1.5,0> }
   cone { <9.8,5.01,5> 1.5 <9.8,1.4,5> 1.3 }
   cylinder { <6,4.9,5> <6,5.5,5> 1 }
   box { <-10,0,0> <10,6,2> rotate -7*x translate <0,1.5,10.7>}
   box { <0,0,0> <-2,6,11> rotate -7*z translate <-9.8,1.5,0> }
   cone { <-9.8,5.01,5> 1.5 <-9.8,1.4,5> 1.3 }
   cylinder { <-6,4.9,5> <-6,5.5,5> 1 }

   // Returns the lenght of a text
   #macro Length_( Text, Font, Size )
      #local T1 = text { ttf Font concat("|",Text,"|") 1 0 scale <Size, Size, 1> }
      #local T2 = text { ttf Font "||" 1 0 scale <Size, Size, 1> }
      ((max_extent(T1).x - min_extent(T1).x) - (max_extent(T2).x - min_extent(T2).x))
   #end
   text { ttf besch_font value 1, 0 scale <2,2,1> rotate 90*x translate <-Length_(value, besch_font, 2)/2,5.95,6> texture{col_bright_marking}}

   texture{col_ic_body_2}
}
#end


/*******************************************************************************
 * Bend of a pin
 ******************************************************************************/
#macro MWBend_(BWidth, BRadius, BSlope)
difference {
   cylinder { -BWidth/2*x BWidth/2*x BRadius   }
   cylinder { -BWidth*x   BWidth*x   BRadius/2 }
   box { <-BWidth,-2*BRadius,0>, <BWidth, 2*BRadius,2*BRadius> }
   box { <-BWidth,0,-2*BRadius>, <BWidth,-2*BRadius,2*BRadius> rotate BSlope*x }
   }
#end


/*******************************************************************************
 * Pins for MW15 H
 ******************************************************************************/
#macro MWPinH_(NpinF, NpinB)
   #local B = 2.5;
   #local D = 4;
   #local E = 0.52;
   #local F = 0.72;
   #local G = 1.27;
   #local R = 2*E;
   #local L2 = 2.54;
   #local L5 = 5.28;
   #local L6 = 2.38;
   #local Ls = 3.592;
   #local IFx = 1.498;
   #local IFy = 2.862;
    
   union {
      #local iF = 0;
      union {
         #while(iF < NpinF)
             union {
                box { <-F/2, -L5, -E/2>, <F/2, 1.04, E/2> }
                box { <-F/2, -E/2, 0>, <F/2, E/2, D> translate <0, 4.36, 3.32> }
                union {
                   box { <-F/2, -E/2, -Ls/2>, <F/2, E/2, Ls/2>  }
                   object { MWBend_(F, R, 45) translate <0, -R+E/2, -Ls/2> }
                   object { MWBend_(F, R, 45) translate <0, -R+E/2, -Ls/2> rotate 180*y }
                   rotate -45*x translate <0, IFy, IFx>
                   }
                translate iF*2*G*x
                }
             #local iF = iF + 1;
         #end
         translate -(NpinF-1)*G*x
         }

      #local iB = 0;
      union {
         #while (iB < NpinB)
            union {
               box { <-F/2, -(L6+B), -E/2>, <F/2, 0, E/2> }
               object { MWBend_(F, R, 0) translate (R-E/2)*z }
               box { <-F/2, -E/2, 0>, <F/2, E/2, D> translate <0, R-E/2, R-E/2> }
               translate <iB*2*G, 4.36-(R-E/2), L2>
               }
            #local iB = iB + 1;
         #end
         translate -(NpinB-1)*G*x
         }
      translate -1.27*z
      texture{col_silver}
      }
#end




/*******************************************************************************
 * Multiwatt15 H & V package.
 * Author: Christian Hostelet c.hostelet@wanadoo.fr
 * Reference: ST-Microelectronics web site (www.st.com)
 * 
 * The two macros defined are: 
 *  - Multiwatt15V (value)  - for vertical MW15 package
 *  - Multiwatt15H (value)  - for horizontal MW15 package
 ******************************************************************************/
#macro IC_MULTIWATT_GRND(value,H_V)
union {
   union {
      object { MWHeatSink_() translate -0.001*y }
      object { MWPlastic_(value) }
      translate -1.5*y
      #if(H_V=1)
         rotate -90*x translate <0,3.5,6.0>
      #else
                      translate <0,3.5,4.6>
      #end
      }
      object { MWPinH_(8, 7) }
   }
#end



/*******************************************************************************
 * produced packages
 ******************************************************************************/
#macro IC_MULTIWATT15V(value)
  IC_MULTIWATT_GRND(value,1)
#end

#macro IC_MULTIWATT15H(value) 
  IC_MULTIWATT_GRND(value,0)
#end
