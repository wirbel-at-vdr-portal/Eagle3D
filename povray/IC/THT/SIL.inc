/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Sharp SIL-type solid-state-relay, relay.lib
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 *
 * s2xxEx = S202SE1, S202SE2, (S202S12, S216S02), S216SE1, S216SE2, S102S11,
 *          S102S12
 * Mittelpunkt: geometrische Mitte zwischen den Aussenpins
 ******************************************************************************/
#macro IC_DIS_S2XXEX(value)
   // macro for one pin
   #macro S2XXEX_PIN()
      difference {
         union {
            box{<-0.4,  S2xxEx_s_pin, -0.3><0.4  , 4.2, 0.3>} 
            box{<-0.625, 0.5, -0.3><0.625, 3  , 0.3>}
            box{<-0.55,  2.2, -0.3><0.55 , 4.2, 0.3>}
            }
         box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate<  0, 0,-25> translate< 0.65,S2xxEx_s_pin, -0.0>}
         box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate<  0, 0, 25> translate<-0.65,S2xxEx_s_pin, -0.0>}
         box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate< 25, 0,  0> translate< 0   ,S2xxEx_s_pin, -0.6>}
         box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate<-25, 0,  0> translate< 0   ,S2xxEx_s_pin,  0.6>}
         }
   // end: S2XXEX_PIN
   #end

   #if(pin_short=off)
      #local S2xxEx_s_pin = -7;
   #else
      #local S2xxEx_s_pin = -(pcb_height+pin_length);
   #end

union {
   union {
      union {
         // pins
         object{S2XXEX_PIN() translate<-7.62,0,0>}
         object{S2XXEX_PIN() translate<-2.54,0,0>}
         object{S2XXEX_PIN() translate< 5.08,0,0>}
         object{S2XXEX_PIN() translate< 7.62,0,0>}
         }
      // metal plate inside the plastic body
      difference {
         box{<-8.2, 4.5, 0.3><8.2, 28.8, -0.3>}
         cylinder{<0,0,-2><0,0,2>2 translate<0,28.8-3.2,0>}
         }
      texture{col_silver}
      }
   // plastic body
   // front part
   #local front = 0.3+1.4-5.5;
   #local top   = 28.8;
   difference {
      box{<-9.25, 4.2, front+5.5><9.25, top, front>}        
      box{<-5,-3,-5><5,3,5> rotate<0,-60,0> translate< 10,top-2.5, -4> }
      box{<-5,-3,-5><5,3,5> rotate<0, 60,0> translate<-10,top-2.5, -4> }
      cylinder{<0,0,-7><0,0,2>1.6 translate<0, top-3.2, 0>}
      cylinder{<0,0,front-0.1><0,0,front+0.1>1 translate< 0,  6, 0>}
      cylinder{<0,0,front-0.1><0,0,front+0.1>1 translate<-7.5, 21, 0>}
      cylinder{<0,0,front-0.1><0,0,front+0.1>1 translate< 7.5, 21, 0>}
      texture{col_ic_body_2}
      }
   // plastic at the back of the metal plate
   difference {
      box{<-8.2, 4.2, -0.4><8.2, top, front+5.5>} 
      cylinder{<0,0,-7><0,0,2>1.6 translate<0, top-3.2, 0>}         
      cylinder{<-9, top-3.2, 0><9, top-3.2, 0>0.5 translate<0, 0, -0.5>}           
      texture{col_ic_body_2}
      }    
   // labels
   union {    
      text{ttf besch_font value            0.5,0 scale<3,3,1.7>   translate<-6, 15,   front-0.01>}
      text{ttf besch_font "SHARP"          0.5,0 scale<3,2.5,1.7> translate<-4.5, 12, front-0.01>}
      text{ttf besch_font "~         + -"  0.5,0 scale<1.7,2,1.7> translate<-5.7, 5,  front-0.01>}
      texture{col_bright_marking}
      }
   } // end: IC_DIS_S2XXEX
#end
