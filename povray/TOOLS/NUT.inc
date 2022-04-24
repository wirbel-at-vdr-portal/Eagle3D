/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Macros for Screw Nuts :
 * Author: Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 - 04/01/06
 *
 * SCREWSIZE  : {2,2.5,3,4,5} for M2 M2.5 M3 M4 M5
 * NUTTYPE    : 0=Hu, 1=Hh
 * NUTCOLOR   : color
 ******************************************************************************/

#macro TOOLS_NUT (SCREWSIZE, NUTTYPE, NUTCOLOR)
  difference {
     #switch (SCREWSIZE)
         #case(2)
            #local A = 3.6;
            #local B = 1.4;
            #local T = 0.4;
            #local Delta = 1.75;
            #break

         #case(2.5)
            #local A = 4.5;
            #local B = 1.7;
            #local T = 0.45;
            #local Delta = 2.2;
            #break

         #case(3)
            #local A = 5.5;
            #local B = 2.4;
            #local T = 0.5;
            #local Delta = 2.5;
            #break

         #case(4)
            #local A = 7;
            #local B = 3.2;
            #local T = 0.7;
            #local Delta = 3.1;
            #break

         #case(5)
            #local A = 8;
            #local B = 4;
            #local T = 0.8;
            #local Delta = 3.35;
            #break

         #end

     #if (NUTTYPE=1)
         #local Delta = Delta-(SCREWSIZE-B)/2;
         #local B=SCREWSIZE;
     #end


     intersection {
        //3 boxes for hexagonal shape
        box {<-A/2,-2*SCREWSIZE,-B/2-0.1>, <+A/2,+2*SCREWSIZE,+B/2+0.1> }
        box {<-A/2,-2*SCREWSIZE,-B/2-0.1>, <+A/2,+2*SCREWSIZE,+B/2+0.1> rotate -60*z}
        box {<-A/2,-2*SCREWSIZE,-B/2-0.1>, <+A/2,+2*SCREWSIZE,+B/2+0.1> rotate +60*z}
        //make some roundness
        sphere {  <0, 0, +Delta>  0.83*A }
        sphere {  <0, 0, -Delta>  0.83*A }
        }

     union {
        //hole
        cylinder {<0,0,-B>, <0,0,+B>, SCREWSIZE/2}

        //thread
        union {
           #local N=0;
           # while (N < 10)
                torus {SCREWSIZE/1.95,T/2.6 rotate 90*x translate (-SCREWSIZE/2+N*T)*z}
                #local N = N + 1;
           #end
           }

        cylinder {<0,0,+B/2+0.2>, <0,0,+B/2> A/2+T } // to get spotless surface
        cylinder {<0,0,-B/2-0.2>, <0,0,-B/2> A/2+T } // to get spotless surface
        }

     pigment{NUTCOLOR}
     rotate 90*x
     translate B/2*y
     rotate(rand(global_seed)*180)*y
     }
#end
