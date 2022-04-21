/*******************************************************************************
 * TO3 metal cup
 * Author: daniel cardona<dancardona50@hotmail.com>
 ******************************************************************************/
#macro TR_TO3(value)
  union {
     union {
        difference {
           cylinder { <0, 0, 0>, <0, 1, 0>, 5 }
           cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 2.3 }
           translate <15,0,0>
           }
        difference{
           cylinder { <0, 0, 0>, <0, 1, 0>, 5}
           cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 2.3}
           translate <-15,0,0> 
           }
        translate<0,0,0>
        }
     union {
        box {<0, 0, 0> < 13,  1,  3> translate <-11.8,0,9.5>rotate <0,-30,0>}
        box {<0, 0, 0> < 13,  1,  3> translate <0.2,0,-12.7>rotate <0,-30,0>}
        box {<0, 0, 0> < 13,  1,  3> translate <-2,0,9.4>rotate <0,30,0>}
        box {<0, 0, 0> < 13,  1,  3> translate <-13.2,0,-12.7>rotate <0,30,0>}
        cylinder{<0,0,0><0,4,0>0.6 translate<-1.8,-3,-5.4>}
        cylinder{<0,0,0><0,4,0>0.6 translate<-1.8,-3,5.4>}
        cylinder{<0,0,0><0,1,0>12.7}
        cylinder{<0,1,0><0,2,0>11.6}
        cylinder{<0,2,0><0,8,0>10}
        torus{9.2 0.8  translate <0,8,0>}
        cylinder{<0,8,0><0,8.8,0>9.2}
        text {ttf besch_font value 0.5, 0 pigment { Black } scale 4 rotate <90,0,0> translate<-5,8.81,0>}
        translate<0,0,0>}
        pigment{P_Silver3}
        finish { ambient (0.1 * global_ambient_mul) }
        }
#end
