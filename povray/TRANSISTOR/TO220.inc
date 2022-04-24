/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO220_(3,5)_(H,V)(,1,2,X):
 * Author: Joerg Bredendiek <sprut(replace with at)sprut.de> 
 *******************************************************************************
 * TR_TO220_T05A_S:
 *    dahamm@gmx.net
 ******************************************************************************/


/*******************************************************************************
 * TO220 plastic body
 ******************************************************************************/
#macro TR_TO220_BODY()
  // plastik grundkoerper
  difference{
     box{<-5.1, 13.5, 0><5.1, 22.6, 4.5>}
     box{<-5.5, 0, 0><5.5, 3.5, -2> rotate<80, 0, 0> translate<0, 22.6-0.6, 0> }
     box{<-5.5, 0, 0><5.5, -1, 2> rotate<-20, 0, 0> translate<0, 13.5, 3.7> }
     cone{<-5.4,16.5,-0.01>1.4<-5.4,16.5,3.23>1.2}
     cone{<5.4,16.5,-0.01>1.4<5.4,16.5,3.23>1.2}
     #if (pins>3)
         cylinder{<-3.5, 14.5, 0.1><-3.5, 14.5, -0.05>0.7}
     #else
         cylinder{<0, 14.5, 0.1><0, 14.5, -0.05>0.7}
     #end
     pigment{Gray30}
     }
#end


/*******************************************************************************
 * TO220 pin vertical
 ******************************************************************************/
#macro TR_TO220_PIN_V(shift)
  union {
     #local lshift = shift+lang;
     // unterer teil
     union {
        difference{
           box{<0,tr_to220_s_pin,0><0.75, 9, 0.6>}
           box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
           box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
           }
        #if (inline=0)
            #if (lshift>0)
               // biegung
               difference{
                  cylinder{< 0,  8.5, 0.6><0.75, 8.5, 0.6> 0.6}
                  cylinder{<-0.1,8.0, 1.1><0.76, 8.0, 1.1> 0.5}
                  translate<0, 0.5, 0>}
               translate<0,0,-shift*2.54-lang>
            #end
        #end
        }

     //oberer teil
     box{<0,9.6,0><0.75,13.5,0.6>}
     #if (inline=0)
         #if (lshift>0)
             difference {
                cylinder{< 0,   9.6,   0  ><0.75, 9.6,   0> 0.6}
                cylinder{<-0.1,10.1,  -0.5><0.76,10.1,-0.5> 0.5}
                }
         #end
     #end

     //mittlerer teil
     #if (lshift>0)
         #if (inline=1)
             box{<0,9,0><0.75,9.6,0.6>}
         #else
             box{<0,9.6,-shift*2.54-lang+0.6><0.75,9,0.6-0.6>}
         #end
     #else
         box{<0,9.6,-shift*2.54-lang+0.6><0.75,9,0.6-0.6>}
     #end

     #if (pins<5)
         box{<0,0,0><1.5, 3.7, 0.6> translate<-0.375, 9.8, 0>}
     #end
     translate<-0.75/2, -8.5  , -2.54-0.3>
     }
#end


/*******************************************************************************
 * TO220 pin horizontal
 ******************************************************************************/
#macro TR_TO220_PIN_H(shift)
  union {
     union {
        #local tr_to220_v_pin = tr_to220_s_pin -2;
        // senkrechter spitzer teil
        difference{
           box{<-0.375,tr_to220_v_pin ,0><0.375,8.5,0.6>}
           box{<0,0,0>< 1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_to220_v_pin ,-0.2>}
           box{<0,0,0><-1,1,1> rotate<0,0, 25> translate< 0.3-0.375,tr_to220_v_pin ,-0.2>}
           }
        // biegung
        difference{
           cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
           cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}
           }
        // horizontal zum koerper
        box{<-0.375,8.5,0.6><0.375,9.1,4.0+2.54*shift>}
        translate<0, -5.98,-6.7>
        translate<0,     0, 5.08-lang>
        #if (inline=0)
           translate<0,0,-2.54*shift>
        #end
        }
     #if (pins<5)
         #if (lang>1)
             box{<-0.75, 8.5, 2><0.75, 9.1, 6> translate<0, -5.98, -6.7> translate<0,0,(5.08-lang)/2>}
         #end
     #end
     }
#end


/*******************************************************************************
 * TO220 pin
 ******************************************************************************/
#macro TR_TO220_PIN(shift)
  #if (hor=1)
      TR_TO220_PIN_H(shift)
  #else
      TR_TO220_PIN_V(shift)
  #end
#end


/*******************************************************************************
 * metal back plate
 ******************************************************************************/
#macro TR_TO220_BACK()
  union {
     // metallische Rueckplatte
     difference{
        box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
        cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
        box{<0,0,0><1,3,3> rotate<0,0,20> translate<5.1,26.5,2>}
        box{<0,0,0><-1,3,3> rotate<0,0,-20> translate<-5.1,26.5,2>}
        }
     box{<-4,22.6,4.5><4,16,4.501>}
     texture{col_silver}
     }
#end


#macro TR_TO220_base(value, pins, hor, inline, lang, shift)
  union {
     #if (pin_short=off)
         #local tr_to220_s_pin = -2;
     #else
         #local tr_to220_s_pin = 9.5-(pcb_height+pin_length)-2;
     #end

    //Pins
    union {
       #switch (pins)
          #case(2)
             GRID_BASE(TR_TO220_PIN(0), 2*2.54, pins, 1)
             #break
          #case(3)
             GRID_BASE(TR_TO220_PIN(0), 2.54, pins, 1)
             #break
          #case(5)
             GRID_BASE(TR_TO220_PIN(0)  , 2.54 , 2, 1)
             GRID_BASE(TR_TO220_PIN(1.5), 3.556, 3, 1)
             #break
          #end
       texture{col_silver}
       }

    // Koerper
    union {
       // metallische Rueckplatte
       object{TR_TO220_BACK()}
       // plastik grundkoerper
       object{TR_TO220_BODY()}
       // Beschriftung
       text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
       translate<0,-9.5,-4.5>
       #if (hor=1)
           translate< 0, -4, 4.5>
           rotate<90,0,0>
           translate< 0, 4.6, -1.4>
       #end
       }
    }
#end


#macro TR_TO220_3_H(value)
  TR_TO220_base(value, 3, 1, 1, 5.08, 0)
#end

#macro TR_TO220_2_H(value)
  TR_TO220_base(value, 2, 1, 1, 5.08, 0)
#end

#macro TR_TO220_3_H1(value)
  TR_TO220_base(value, 3, 1, 1, 2.54, 0)
#end

#macro TR_TO220_3_H2(value)
  TR_TO220_base(value, 3, 1, 1, 2.54, 5.08)
#end

#macro TR_TO220_3_H3(value)
  TR_TO220_base(value, 3, 1, 1, 0.5, 0)
#end

#macro TR_TO220_3_HX(value)
  TR_TO220_base(value, 3, 1, 0, 2.54, 0)
#end

#macro TR_TO220_2_V(value)
  TR_TO220_base(value, 2, 0, 1, 0, 0)
#end

#macro TR_TO220_3_V(value)
  TR_TO220_base(value, 3, 0, 1, 0, 0)
#end

#macro TR_TO220_3_VX(value)
  TR_TO220_base(value, 3, 0, 0, 0, 0)
#end

#macro TR_TO220_5_V(value)
  TR_TO220_base(value, 5, 0, 0, 2, 0)
#end





/*******************************************************************************
 * TO220 5-Pin vertical, straight pins
 * dahamm@gmx.net
 ******************************************************************************/
#macro TR_TO220_T05A_S(value)
  union {
     union {
        union {
           #if (pin_short=off)
               #local tr_to220_s_pin = 9.5;
           #else
               #local tr_to220_s_pin = 9.5-(pcb_height+pin_length);
           #end

           #local obj = union {
             difference {
                box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
                box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
                box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
                }
             box{<0,0,0><1.5,3.7,0.6> translate<-0.375,9.8,0>}
             };
           GRID_BASE(obj, 1.778, 5, 1)
           translate<-0.75/2,0,1.6>
           }
        difference{
           box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
           cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
           box{<0,0,0><1,3,3> rotate<0,0,20> translate<5.1,26.5,2>}
           box{<0,0,0><-1,3,3> rotate<0,0,-20> translate<-5.1,26.5,2>}
           }
        box{<-4,22.6,4.5><4,16,4.501>}
        texture{col_silver}
        }

     difference{
        box{<-5.1,13.5,0><5.1,22.6,4.5>}
        box{<-5.5,0,0><5.5,3,-2> rotate<45,0,0> translate<0,22.6-1.8,0> }
        box{<-5.5,0,0><5.5,-1,2> rotate<-20,0,0> translate<0,13.5,3.7> }
        cone{<-5.4,16.5,-0.01>1.4<-5.4,16.5,3.23>1.2}
        cone{<5.4,16.5,-0.01>1.4<5.4,16.5,3.23>1.2}
        cylinder{<0,14.5,0.1><0,14.5,-0.05>0.7}
        pigment{Gray30}
        }

     text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
     translate<0,-9.5,-4.5>
     }
#end
