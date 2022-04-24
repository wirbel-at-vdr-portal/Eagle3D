/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * HE14 serie Right-Angle and Straight, Single-Row
 * Author: Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
 * Rev. 1.0  09/02/08
 ******************************************************************************/

#macro AMP_HE14_1S(Pins)
  union {
     #local HE14Blue = color green 0.5 blue 1;
     difference {
        union {
           box{<0,0.8,-2.54><Pins*2.54,2.6,2.54>}
           #local i=0; #while (i<Pins) box{<0.87+i*2.54,0,2.1><1.67+i*2.54,0.8,+2.54>} #local i=i+1; #end

           difference {
              box{<0,0,-2.1><Pins*2.54,2.6,-2.54>}
              #local i=0; #while (i<Pins) box{<0.4+i*2.54,-0.1,-2><2.14+i*2.54,0.8,-3>} #local i=i+1; #end
              box{<-0.01,-0.01,0><0.41,0.8,-3>}
              box{<Pins*2.54+0.01,-0.01,0><Pins*2.54-0.41,0.8,-3>}
              }
           }
        union {
           cylinder{<0,-2,-2.54+0.2><0,3,-2.54+0.2> 1.2}
           box{<Pins*2.54-0.4,-2,+2.541><Pins*2.55,3,+2.54-0.4>}
           box{<Pins*2.54-0.4,-2,-2.541><Pins*2.55,3,-2.54+1.2>}//front right
           box{<Pins*2.54-1.27,-2,-2.541><Pins*2.55,3,-2.54+0.4>}//front right
           box{<+0.4,-2,+2.541><-0.01,3,+2.54-0.4>} //back right
           }
        }

     difference {
        box{<1.27,2.6,-2.54><(Pins-0.5)*2.54,11.4,-1.9>}
        box{<1.27-1,9,-2.54><(Pins-0.5)*2.54+1,13,-1.9> rotate -8.5*x translate 2*z}
        }
     box{<1.27,8,-2.54><(Pins-0.5)*2.54,8.5,-1.7>}
     box{<1.27,8,-2><(Pins-0.5)*2.54,8.5,-1.7> rotate -30*x translate <0,2.45,3.75>}

     difference {
        box{<0.4,2.6,+2.54><Pins*2.54-0.4,11.4,+1.9>}
        box{<0.4-1,9,+2.54><Pins*2.54-0.4+1,13,+1.9> rotate 8.5*x translate -2*z}
        }
     translate <-Pins*1.27,0,0> pigment {HE14Blue}
     }
#end



/*******************************************************************************
 * HE14 serie Right-Angle and Straight, Single-Row
 * Author: Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
 * Rev. 1.0  09/02/08
 ******************************************************************************/
#macro CON_AMP_HE14_1R_base(Pins)
  union {
     object{AMP_HE14_1S(Pins) rotate<90,180,0> translate<0,2.54,-1.2>}
     object{PIN_BENDED_ROW (Pins,2.54,0.63,0.8,2.5,3,12.5,col_silver) translate<0,0,0>}}
     rotate 180*y
#end

#macro CON_AMP_HE14_1S_base(Pins)
  union {
     object{AMP_HE14_1S(Pins)}
     object{PIN_STRAIGHT_ROW (Pins,2.54,0.635,11,3,col_silver)}}
#end


#macro CON_AMP_HE14_1R_02()
CON_AMP_HE14_1R_base(2)
#end

#macro CON_AMP_HE14_1R_03()
CON_AMP_HE14_1R_base(3)
#end

#macro CON_AMP_HE14_1R_04()
CON_AMP_HE14_1R_base(4)
#end

#macro CON_AMP_HE14_1R_05()
CON_AMP_HE14_1R_base(5)
#end

#macro CON_AMP_HE14_1R_06()
CON_AMP_HE14_1R_base(6)
#end

#macro CON_AMP_HE14_1R_07()
CON_AMP_HE14_1R_base(7)
#end

#macro CON_AMP_HE14_1R_08()
CON_AMP_HE14_1R_base(8)
#end

#macro CON_AMP_HE14_1R_09()
CON_AMP_HE14_1R_base(9)
#end

#macro CON_AMP_HE14_1R_10()
CON_AMP_HE14_1R_base(10)
#end




#macro CON_AMP_HE14_1S_02()
CON_AMP_HE14_1S_base(2)
#end

#macro CON_AMP_HE14_1S_03()
CON_AMP_HE14_1S_base(3)
#end

#macro CON_AMP_HE14_1S_04()
CON_AMP_HE14_1S_base(4)
#end

#macro CON_AMP_HE14_1S_05()
CON_AMP_HE14_1S_base(5)
#end

#macro CON_AMP_HE14_1S_06()
CON_AMP_HE14_1S_base(6)
#end

#macro CON_AMP_HE14_1S_07()
CON_AMP_HE14_1S_base(7)
#end

#macro CON_AMP_HE14_1S_08()
CON_AMP_HE14_1S_base(8)
#end

#macro CON_AMP_HE14_1S_09()
CON_AMP_HE14_1S_base(9)
#end

#macro CON_AMP_HE14_1S_10()
CON_AMP_HE14_1S_base(10)
#end
