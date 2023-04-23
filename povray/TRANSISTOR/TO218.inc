/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO218AB with up or down bended pin
 * Author: Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * Rev. 1.0  12/05/06
 ******************************************************************************/


/*******************************************************************************
 * pin dir: pin direction, 0=up 1=down 3=straight
 * Lt     : pin length, Lt = Lh + (pi/2)r + Lv
 * Lh     : horizontal part length without rounded part
 * xp     : pin Width
 * yp     : thickness
 * cutpins: 1=enable short pins cutting, 0=disable it
 ******************************************************************************/
#macro TR_TO218_BENDED_PIN(pindir,Lt,Lh,xp,yp,cutpins)
  #if (cutpins=0)
      #local cutpins = 0;
  #else
      #local cutpins = pin_short;
  #end

  #declare r=0.6;
  #declare Lv=Lt-Lh-1.57*r;
  union {
    #if (pindir=3) //straight pin
        #if (cutpins=off)
            box{<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>} //horizontal part
        #else
            box{<-xp/2,+yp/2,-yp/2-Lh+(pcb_height+pin_length)+3><+xp/2,-yp/2,-yp/2-Lh-1>}//shorted horizontal part
        #end
    #else
        difference {
           #if (cutpins=off)
               box{<-xp/2,-r+yp/2,-yp/2><xp/2,-r+yp/2-Lv,+yp/2>} //vertical part
               box{<0,0,-1><1,1,1> rotate<0,0,-25> translate<0.45-0.375,-r+yp/2-Lv,0>} //terminal V shape
               box{<0,0,-1><-1,1,1> rotate<0,0,25> translate<0.30-0.375,-r+yp/2-Lv,0> }
           #else
               box{<-xp/2,-r+yp/2,-yp/2><xp/2,-2.5-(pcb_height+pin_length),+yp/2>}//shorted vertical part
           #end
           }
        difference { //curved part
           cylinder{<-xp/2,-r+yp/2,-r+yp/2><xp/2,-r+yp/2,-r+yp/2>r}
           box{<-xp/2-0.1,-yp/2,-yp/2><+xp/2+0.1,-yp/2-1,-yp/2-1>}
           }
        box{<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>}//short horizontal part next case
    #end

    box{<-0.75,+yp/2,-yp/2-Lh-1.0><+0.75,-yp/2,-yp/2-Lh+1.7>}//large horizontal part next case
    box{<-0.90,+yp/2,-yp/2-Lh+0.7><+0.90,-yp/2,-yp/2-Lh+1.7>}//extra large horizontal part next case
    rotate 180*y
    #if (pindir=0) // up/down pins
        rotate 180*z
    #end
    translate <0,2.75,-Lh-yp/2> // offset to mid thickness case and change zero to fixation hole
    }
#end




#macro TR_TO218_base(value,pindir,Lh,pinsnb,cutpins,pRot,pTra)
  union {
     union {
        difference { //plastic case
            box{<-7.4,0,-3.8><7.4,4.9,-16.3>} //main part
            box{<-7.5,-3,-3.8><7.5,6,0> rotate<-1,0,0> } //heatsink side shaping
            box{<-7.4,-3,-3.7><-10,6,-16.4> rotate<0,0,-1> }//right side shaping
            box{<+7.4,-3,-3.7><+10,6,-16.4> rotate<0,0,+1> }//left side shaping
            box{<-7.5,-3,-16.3><7.5,6,-20> rotate<+2,0,0> translate 2.75*y }//pins side up shaping
            box{<-7.5,-3,-16.3><7.5,6,-20> rotate<-2,0,0> translate 2.75*y}//pins side down shaping
            cylinder{<0,4.8,-10.05><0,5,-10.05>2}//light printed round
            pigment{Gray30}
            }

        text { ttf besch_font value 0.5,0 pigment{White} scale<2.5,2.5,2> rotate 90*x translate<-4.5,4.95,-7> }

        difference { 
           box{<-7.4,-0.01,-3.8><7.4,2,4>}//heatsink base
           cylinder{<0,-0.1,0><0,2.1,0>2.02}//hole
           box{<-1,-0.1,-2><+1,2.1,+2> rotate<0,+45,0> translate<-7.4,0,4>}//right corner
           box{<-1,-0.1,-2><+1,2.1,+2> rotate<0,-45,0> translate<+7.4,0,4>}//left corner
           }
        box{<-7.5,-0.01,-3><+7.5,2,-2>}//extra side heatsink
        box{<-5.5,-0.01,-3.7><+5.5,0,-12>}//heatsink under case
        }

     union {
        #if (pinsnb = 3)
            GRID(TR_TO218_BENDED_PIN(pindir,14.5,Lh,1.1,0.5,cutpins),5.5,3,1)
        #else
            GRID(TR_TO218_BENDED_PIN(pindir,14.5,Lh,1.1,0.5,cutpins),5.5,2,1)
        #end   
        }
     texture{col_silver}
     translate 10.05*z
     rotate pRot
     translate pTra
     }
#end


#macro TR_TO218(value)
  TR_TO218_base(value,1,3,3,on,0,0)
#end

#macro TR_TO218V(value)
  TR_TO218_base(value,3,10,3,on,-90*x,9*y)
#end

#macro TR_TO218_2(value)
  TR_TO218_base(value,1,3,2,on,0,0)
#end

#macro TR_TO218_2V(value)
  TR_TO218_base(value,3,10,2,on,-90*x,9*y)
#end
