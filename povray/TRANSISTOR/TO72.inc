/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TO72
 * Joerg Bredendiek <sprut(replace with at)sprut.de>,
 *    based on TO52 by Philippe Boucheny
 *                     <philippe.boucheny(replace with at)free.fr>
 ******************************************************************************/
#macro TR_TO72_base(value,npin)
  union {
     //case
     cylinder{<0,0,0><0,3.5-0.3 +1.5 ,0>2.35 pigment{P_Silver3} }
     cylinder{<0,3.5-0.3 +1.5 ,0><0,3.5 +1.5 ,0>2.05 pigment{P_Silver3}}
     torus{2.05 0.3 pigment {P_Silver3} translate (3.5-0.3 +1.5 )*y}
     torus{2.45 0.3 pigment {P_Silver3} translate 0.3*y}
     cylinder{<0,0,0><0,0.6,0>2.45 pigment{P_Silver3}}
     box {<-0.5,0,0><0.5,0.6,3.3> pigment{P_Silver3}  translate <0,0,0> rotate <0,-90,0> }
     text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,3.52 +1.5 ,-.4>}

     //pins
     #if (npin>=3)
         #if (pin_short=off)
             cylinder{<+1.27, 0, -1.27> <+1.27,-12.7,-1.27> 0.2 pigment{ P_Silver3}}
             cylinder{<-1.27, 0, -1.27> <-1.27,-12.7,-1.27> 0.2 pigment{ P_Silver3}}
             cylinder{<-1.27, 0, +1.27> <-1.27,-12.7,+1.27> 0.2 pigment{ P_Silver3}}
         #else
            cylinder{<+1.27, 0,-1.27> <+1.27,-(pin_length+pcb_height),-1.27> 0.2 pigment{ P_Silver3}}
            cylinder{<-1.27, 0,-1.27> <-1.27,-(pin_length+pcb_height),-1.27> 0.2 pigment{ P_Silver3}}
            cylinder{<-1.27, 0,+1.27> <-1.27,-(pin_length+pcb_height),+1.27> 0.2 pigment{ P_Silver3}}
         #end
     #end

     #if (npin=4)
         #if (pin_short=off)
             cylinder{<+1.27, 0, +1.27> <+1.27,-12.7,+1.27> 0.2 pigment{ P_Silver3}}
         #else
            cylinder{<+1.27, 0,+1.27> <+1.27,-(pin_length+pcb_height),+1.27> 0.2 pigment{ P_Silver3}}
         #end
     #end
     translate<0,1,0>
     }
#end

#macro TR_TO72_3(value)
  TR_TO72_base(value,3)
#end

#macro TR_TO72_4(value)
  TR_TO72_base(value,4)
#end
