/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO66 metal cup
 * Author: daniel cardona<dancardona50@hotmail.com>
 *  - remove unwanted holes in shape, fix straight to rounding. 20220421, wk
 ******************************************************************************/
#macro TR_TO66(value)
  union {
     difference {
        union {
           cylinder { <0, 0, 0>, <0, 1, 0>, 3.6 translate <+0.96*25.4/2,0,0>}
           cylinder { <0, 0, 0>, <0, 1, 0>, 3.6 translate <-0.96*25.4/2,0,0>}
           box {<0, 0, 0> < 12,  1,  4.7> translate <-11.5,0,3.85> rotate <0,-24.5,0>} //lo
           box {<0, 0, 0> < 12,  1,  4.7> translate <-11.5,0,-8.6> rotate <0,+24.5,0>} //lu        
           box {<0, 0, 0> < 12,  1,  4.7> translate <-0.4,0 ,-8.6> rotate <0,-24.5,0>} //ru
           box {<0, 0, 0> < 12,  1,  4.7> translate <-0.4,0,3.85>  rotate <0,+24.5,0>} //ro
        
           cylinder{<0,0,0><0,4,0>0.6 translate<-2.6,-3,-2.8>} 
           cylinder{<0,0,0><0,4,0>0.6 translate<-2.6,-3,+2.8>} 
           cylinder{<0,0,0><0,1,0>8.6}
           cylinder{<0,1,0><0,2,0>7.6}
           cylinder{<0,2,0><0,8,0> 0.485*25.4/2} 
           torus{5.35 0.8  translate <0,8,0>}
           cylinder{<0,8,0><0,8.8,0>5.2} 
           text {ttf besch_font value 0.5, 0 pigment { Black } scale <2,1,2> rotate <90,0,0> translate<-4,8.81,0>}
           translate<0,0,0>
           }
        cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 1.8 translate <+0.96*25.4/2,0,0>}
        cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 1.8 translate <-0.96*25.4/2,0,0>}
        }
     pigment{P_Silver3}
     finish { ambient (0.1 * global_ambient_mul) }
     }
#end
