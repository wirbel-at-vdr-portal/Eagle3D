/*******************************************************************************
 * TO202
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 ******************************************************************************/


/*******************************************************************************
 * plastic body for TO202
 ******************************************************************************/
#macro TR_TO202_BODY()
  // plastik grundkoerper
  difference{
     box{<-4.8, 10, -2.5><4.8, 18, 2>}
     box{<-2, 9, 4><0, 19, -4> rotate<0, 7, 0> translate<-4.8, 0, 0> }
     box{<-2, 9, 4><0, 19, -4> rotate<0,-7, 0> translate<-4.8, 0, 0> }
     box{< 2, 9, 4><0, 19, -4> rotate<0,45, 0> translate< 4.8, 0, 0> }
     box{< 2, 9, 4><0, 19, -4> rotate<0,-7, 0> translate< 4.8, 0, 0> }
     pigment{Gray30}
     }
#end


/*******************************************************************************
 * TO202 pin vertical
 ******************************************************************************/
#macro TR_TO202_PIN_V(shift)
  union {
     #local lshift = shift+lang;
     difference {
        box{<0,tr_to202_s_pin,0><0.66, 10.5, 0.5>}
        box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to202_s_pin,-0.2>}
        box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to202_s_pin,-0.2>}
        translate<-0.66/2, 0, -0.25>
        }
     box{<-0.375, 8, -0.25><0.375, 10.5, 0.25>}
     }
#end


/*******************************************************************************
 * TO202 pin horizontal
 ******************************************************************************/
#macro TR_TO202_PIN_H(shift)
  union {
     union {
        #local tr_to202_v_pin = tr_to202_s_pin -2;
        // senkrechter spitzer teil
        difference {
           box{<-0.375,tr_to202_v_pin ,0><0.375,8.5,0.6>}
           box{<0,0,0>< 1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_to202_v_pin ,-0.2>}
           box{<0,0,0><-1,1,1> rotate<0,0, 25> translate< 0.3-0.375,tr_to202_v_pin ,-0.2>}
           }
        // biegung
        difference {
           cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
           cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
           // horizontal zum koerper
           box{<-0.375, 8.5, 0.6> <0.375, 9.1, 5>}
           }
        box{<-0.75, 8.5, 3><0.75, 9.1, 5> translate<0,0,0> }
        translate<0, 0, -2.54-0.3>
     }
#end


/*******************************************************************************
 * TO202 pin
 ******************************************************************************/
#macro TR_TO202_PIN(shift)
  #if (hor=1)
      TR_TO202_PIN_H(shift)
  #else
      TR_TO202_PIN_V(shift)
  #end
#end


/*******************************************************************************
 * metal plate
 ******************************************************************************/
#macro TR_TO202_BACK()
  union {
     // metallische Kuehlfahne
     difference {
        box{<-3.1, 17, -0.25> <3.1, 32, 0.25>}
        cylinder{<0,0,-1><0,0,1>1.65 translate<0,29,0>}
        }  
     box{<-3.0, 20, -0.25> <-4.6, 32, 0.25>}
     box{< 3.0, 20, -0.25> < 4.6, 32, 0.25>}
     texture{col_silver}
     }
#end



/*******************************************************************************
 * TO202 base
 ******************************************************************************/
#macro TR_TO202_base(value, pins, hor, inline, lang, shift)
  union {
     #if (pin_short=off)
         #local tr_to202_s_pin = 0;
     #else
         #local tr_to202_s_pin = 9.5-(pcb_height+pin_length);
     #end

     //Pins
     union {
        object{TR_TO202_PIN(0) translate<-2.54,0,0>}
        object{TR_TO202_PIN(0) translate< 2.54,0,0>}
        object{TR_TO202_PIN(0)}
        texture{col_silver}
        translate<0,-7,-2.54>
        }

     // Koerper
     union {
        // metallische Rueckplatte
        object{TR_TO202_BACK()}
        // plastik grundkoerper
        object{TR_TO202_BODY()}
        // Beschriftung
        text{ttf besch_font value 0.5,0 pigment{White} scale<1,1.5,1> translate<-3.5,15,-0.01-2.5>}
        translate<0,-7,-2>      // rueckseite schliesst mit 0 ab    
        #if (hor=1)
           translate< 0, -3, 0>
           rotate<90,0,0>
           translate< 0, 0, -1>
        #end
        }
     }
#end


#macro TR_TO202_3_H(value)
  TR_TO202_base(value, 3, 1, 1, 5.08, 0)
#end

#macro TR_TO202_3_V(value)
  TR_TO202_base(value, 3, 0, 1, 0, 0)
#end
