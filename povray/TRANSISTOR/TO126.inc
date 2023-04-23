/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO126 horizontal pin
 ******************************************************************************/
#macro TO126_PIN_H()
  union {
     union {
        // senkrechter spitzer teil
        difference {
           box{<-0.375,tr_to126_s_pin ,0><0.375,8.5,0.6>}
           box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_to126_s_pin ,-0.2>}
           box{<0,0,0><-1,1,1> rotate<0,0,25> translate< 0.3-0.375,tr_to126_s_pin ,-0.2>}
           }
        // biegung
        difference {
           cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
           cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}
           }
        // horizontal zum koerper
        box{<-0.375,8.5,0.6><0.375,9.1,5.0>}
        translate<0, -7, -5.08>
        }
     //verdickung
     box{<-0.75, 8.5, 0><0.75, 9.1, 2> translate<0, -7, -4>}
     }
#end


/*******************************************************************************
 * TO126 horizontal
 ******************************************************************************/
#macro TR_TO126_L(value)
  union {
     #if (pin_short=off)
         #local tr_to126_s_pin = 0;
     #else
         #local tr_to126_s_pin = 7-(pcb_height+pin_length);
     #end

   //Pins
   object { GRID(TO126_PIN_H(),2.54,3,1) texture{col_silver} }

   //body
   union {
      difference { 
         //Body ground
         box{<-2.8,4.5,1.8><2.8,12,2.551>}              
         cylinder{<0,0,0><0,0,1>1.549 translate<0,9.35,1.7>}
         texture{col_silver}
         }
      difference {
         //Body
         box{<-3.6,2.5,0><3.6,13.15,2.55>}
         cylinder{<0,0,0><0,0,3>1.55 translate<0,9.35,-0.1>}
         cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<-2.5,11.5,0>}
         cylinder{<0,0,0.1><0,0,-0.4>0.7 translate< 2.5,11.5,0>}
         cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<0,6.5,0>}
         box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> translate<0,9.35,0>}
         box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0, 120> translate<0,9.35,0>}
         box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0,-120> translate<0,9.35,0>}
         pigment{Gray30}
         }
      text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3, 5, -0.01>}
      rotate<90,0,0>
      translate<0,2.55,-3.81>
      }
   }
#end



/*******************************************************************************
 * TO126 vertical
 ******************************************************************************/
#macro TR_TO126_S(value)
  union {
     union {
        union {
           #if (pin_short=off)
               #local tr_to126_s_pin = -14;
           #else
               #local tr_to126_s_pin = 0-(pcb_height+pin_length);
           #end

           #local obj = union {
               difference{    
                  box{<0,tr_to126_s_pin,0><0.8,2.5,0.62>}
                  box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to126_s_pin,-0.2>}
                  box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to126_s_pin,-0.2>}
                  }
               box{<0,0,0><1.5,1,0.6> translate<-0.375,0.8,0>}
               };

           //Pins
           object { GRID(obj,2.54,3,1) texture{col_silver} }
           translate<-0.8/2,0,0.84>
           }//END union3

        difference{ 
        //Body ground
        box{<-2.8,4.5,1.8><2.8,12,2.551>}              
        cylinder{<0,0,0><0,0,1>1.549 translate<0,9.35,1.7>}}
        texture{col_silver}
        } //END union2

     difference {
        //Body
        box{<-3.6,2.5,0><3.6,13.15,2.55>}
        cylinder{<0,0,0><0,0,3>1.55 translate<0,9.35,-0.1>}
        cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<-2.5,11.5,0>}
        cylinder{<0,0,0.1><0,0,-0.4>0.7 translate< 2.5,11.5,0>}
        cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<0,6.5,0>}
        box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> translate<0,9.35,0>}
        box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0, 120> translate<0,9.35,0>}
        box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0,-120> translate<0,9.35,0>}
        pigment{Gray30}
        }

     text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> 
     translate<-3,5,-0.01>}
     translate<0,0,-2.55>
     } //END union1
#end
