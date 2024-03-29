/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO247
 * Author: Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * Rev. 1.0  26/10/07
 ******************************************************************************/


/*******************************************************************************
 * pin dir: pin direction, 0=up 1=down 3=straight
 * Lt     : pin length, Lt = Lh + (pi/2)r + Lv
 * Lh     : horizontal part length without rounded part
 * xp     : pin Width
 * yp     : thickness
 * cutpins: 1=enable short pins cutting, 0=disable it
 ******************************************************************************/
#macro TO247_BENDED_PIN (pindir,Lt,Lh,xp,yp,cutpins,xxp)
  #if (cutpins=0)
      #local cutpins = 0;
  #else
      #local cutpins = pin_short;
  #end

  union {
     #local r=0.6;
     #local Lv=Lt-Lh-1.57*r;

     #if (pindir=3) //straight pin
        #if (cutpins=off)
            box {<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>} //horizontal part
        #else
            box {<-xp/2,+yp/2,-yp/2-Lh+(pcb_height+pin_length)+3><+xp/2,-yp/2,-yp/2-Lh-1>}//shorted horizontal part
        #end
     #else
        difference {
           #if (cutpins=off)
               box {<-xp/2,-r+yp/2,-yp/2><xp/2,-r+yp/2-Lv,+yp/2>} //vertical part
               box {<0,0,-1><1,1,1> rotate<0,0,-25> translate<0.45-0.375,-r+yp/2-Lv,0>} //terminal V shape
               box {<0,0,-1><-1,1,1> rotate<0,0,25> translate<0.30-0.375,-r+yp/2-Lv,0> }
           #else
               box {<-xp/2,-r+yp/2,-yp/2><xp/2,-2.5-(pcb_height+pin_length),+yp/2>}//shorted vertical part
           #end
           }
        difference { //curved part
           cylinder {<-xp/2,-r+yp/2,-r+yp/2><xp/2,-r+yp/2,-r+yp/2>r}
           box {<-xp/2-0.1,-yp/2,-yp/2><+xp/2+0.1,-yp/2-1,-yp/2-1>}
           }
        box {<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>}//short horizontal part next case
     #end

     prism {
        linear_sweep linear_spline +yp/2, -yp/2,5,
        < -xxp/2, -yp/2-Lh-1.0>,
        < +xxp/2, -yp/2-Lh-1.0>,
        < +xxp/2, -yp/2-Lh+1.7>,
        < 0, -yp/2-Lh+1.7+1>,
        < -xxp/2, -yp/2-Lh+1.7>
        }

     rotate 180*y
     #if (pindir=0) // up/down pins
         rotate 180*z
     #end
     translate <0,2.75,-Lh-yp/2> // offset to mid thickness case and change zero to fixation hole
     }
#end



#macro TR_TO247_base(value,pindir,Lh,pinsnb,cutpins,pRot,pTra)
  union {
     difference {
        union {
           difference { //plastic case
              box {<-7.75,0,-6.35><7.75,5,+13.65>} //main part
              box {<-7.8,-3,-5.5><7.8,6,-8> rotate<-6,0,0> translate<0,2,0>} //pins side bevel
              box {<-7.8,-3,-5.5><7.8,6,-8> rotate<+6,0,0> translate<0,2,0>} //pins side bevel
              box {<-7.8,-3,+14><7.8,6,+18> rotate<-6,0,0> translate<0,2,0>} //top side bevel
              box {<-7.8,-3,+14><7.8,6,+18> rotate<+6,0,0> translate<0,2,0>} //top side bevel
              box {<-7.5,-3,-7><-10,6,+15> rotate<0,0,+6> translate<0,2,0> } //right side bevel
              box {<-7.5,-3,-7><-10,6,+15> rotate<0,0,-6> translate<0,2,0> } //right side bevel
              box {<+7.5,-3,-7><+10,6,+15> rotate<0,0,+6> translate<0,2,0> } //left side bevel
              box {<+7.5,-3,-7><+10,6,+15> rotate<0,0,-6> translate<0,2,0> } //left side bevel
              cone{<+7.75,2,+8.15>,2.25,<+7.75,5.1,+8.15> 2.75}
              cone{<-7.75,2,+8.15>,2.25,<-7.75,5.1,+8.15> 2.75}
              pigment{Gray30}
              }
           text{ttf global_fontfile_arial value 0.5,0 pigment{White} scale<2,2.5,2> rotate 90*x translate<-5,5.05,0>}
           box {<-6.75,-0.01,-4><+6.75,+0.5,+13.5>}//heatsink under case
           }
        cylinder {<0,-10,+8.15><0,+10,+8.15>3.6/2}//Hole
        }
     union {
        object{TO247_BENDED_PIN(pindir,14.5,Lh,1.2,0.5,cutpins,2.2) translate<-5.45,0,-6.3>} //left pin
        #if (pinsnb=3)
            object{TO247_BENDED_PIN(pindir,14.5,Lh,1.2,0.5,cutpins,3.2) translate<0,0,-6.3>}//center pin
        #end
        object{TO247_BENDED_PIN(pindir,14.5,Lh,1.2,0.5,cutpins,2.2) translate<+5.45,0,-6.3>} //right pin
        }
     texture{col_silver}
     #if (pindir=3) //straight pin
         rotate<-90,0,0>
         translate<0,8,0>
     #end
     translate pTra 
     }
#end


#macro TR_TO247_H(value)
  TR_TO247_base(value,1,3,3,on,0,0)
#end

#macro TR_TO247_H1(value)
  TR_TO247_base(value,1,13,3,on,0,<0,0,-8.0>)
#end

#macro TR_TO247_2H(value)
  TR_TO247_base(value,1,3,2,on,0,0)
#end

#macro TR_TO247_V(value)
  TR_TO247_base(value,3,10,3,on,-90*x,9*y)
#end

#macro TR_TO247_2V(value)
  TR_TO247_base(value,3,10,2,on,-90*x,9*y)
#end
