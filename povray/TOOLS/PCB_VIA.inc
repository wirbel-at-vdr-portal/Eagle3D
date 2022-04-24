/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Generates a VIA
 * dia_min:  diameter of the hole
 * dia_max:  diameter of the via
 * upper:    the upper layer which the via contains to
 * lower:    the lower layer which the via contains to
 * shape:    the shape of the via.
 *           if shape >= 100 solder will be added to the via (add 100)
 *             0 square
 *             1 octagon
 *             2 round
 *             3 long
 *             4 offset
 ******************************************************************************/
#macro TOOLS_PCB_VIA(dia_max,dia_min,upper,lower,shape,elongation)
  #if ((global_solder=on) & (shape>=100))
     union{
  #else
     object{
  #end

  #local lupper = -global_pcb_layer_dis[upper-1]+pcb_cuheight+0.002;
  #local llower = -global_pcb_layer_dis[lower-1]             -0.002;

  #if (shape>=100)
     #local shape = shape - 100;
     #if (global_solder=on)
         difference{
            #local dia = dia_max*0.5;
            cylinder{<0,lupper,0>, <0,lupper+dia,0>dia}
            torus{ dia,dia translate<0,dia,0> scale<1,2,1> translate<0,lupper,0>}
            }
         difference{
            #local dia = dia_max*0.5;
            cylinder{<0,llower,0>, <0,llower-dia,0>dia}
            torus{ dia,dia translate<0,-dia,0> scale<1,2,1> translate<0,llower,0>}
            }
         #end
     #end

  #if(dia_min>=global_pcb_real_hole)
  difference{
  #end

  #if(shape=0) //square
     box{<dia_max/2,lupper,dia_max/2><-dia_max/2,llower,-dia_max/2>}
  #end

  #if(shape=1) //round
     cylinder{<0,lupper,0><0,llower,0>dia_max/2}
  #end

  #if(shape=2) //octagon
     prism {
        linear_spline
        lupper, llower, 9,
        #local i = 0;
        #while(i<9)
           <vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).x,vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).z>
           #local i = i + 1;
        #end
     }
  #end

  #if(shape=3) //long
     prism {
        linear_spline
        lupper, llower, 9,
        #local i = 0;
        #while(i<9)
           #local pos = <vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).x,0,vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).z>;
           #if((i=0)|(i=1)|(i=6)|(i=7)|(i=8))
               <pos.x+(dia_max/2)*(elongation/100),pos.z>
           #else
               <pos.x-(dia_max/2)*(elongation/100),pos.z>
           #end
           #local i = i + 1;
        #end
        }
  #end

  #if(shape=4) //offset
     prism {
        linear_spline
        lupper, llower, 9,
        #local i = 0;
        #while(i<9)
           #local pos = <vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).x,0,vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).z>;
           #if((i=2)|(i=3)|(i=4)|(i=5))
               <pos.x,pos.z>
           #else
               <pos.x+(dia_max)*(elongation/100),pos.z>
           #end
           #local i = i + 1;
        #end
        }
  #end

  #if(dia_min>=global_pcb_real_hole)
     cylinder{<0,lupper+0.1,0><0,llower-0.1,0> dia_min/2-0.001}
     }
  #end

  }
#end
