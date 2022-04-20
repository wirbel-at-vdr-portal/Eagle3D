/*
 * Copyright 2005-2010 Matthias Weisser <matthias@matwei.de>
 *
 * This file is part of Eagle3D
 *
 * Eagle3D is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * Eagle3D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef(__e3d_tools_inc)
#declare __e3d_tools_inc = true;

global_settings{charset utf8}

//POVRay include files
#include "arrays.inc"
#include "chars.inc"
#include "colors.inc"
#include "finish.inc"
#include "functions.inc"
#include "glass.inc"
#include "golds.inc"
#include "math.inc"
#include "metals.inc"
#include "rand.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "shapesq.inc"
#include "skies.inc"
#include "stoneold.inc"
#include "stones.inc"
#include "stones1.inc"
#include "stones2.inc"
#include "strings.inc"
#include "textures.inc"
#include "transforms.inc"

//Library files
#include "TOOLS/fonts.inc"
#include "TOOLS/default_colors.inc"
#include "TOOLS/ARC.inc"
#include "TOOLS/BENTPIPE.inc"
#include "TOOLS/PCB_SMD.inc"
#include "TOOLS/PCB_VIA.inc"
#include "TOOLS/RECT_BOGEN.inc"
#include "TOOLS/ROUNDED_BAR.inc"
#include "TOOLS/TORUS_SPLINE.inc"
#include "TOOLS/WIRE_LEADS.inc"
#include "e3d_logo.inc"
#include "e3d_tex.inc"
#include "e3d_ic.inc"
#include "e3d_resistor.inc"
#include "e3d_trafo.inc"
#include "e3d_transistor.inc"
#include "e3d_connector.inc"
#include "e3d_cap.inc"
#include "e3d_diode.inc"
#include "e3d_special.inc"
#include "e3d_socket.inc"
#include "e3d_qfp.inc"
#include "e3d_switch.inc"
#include "FUSE/ptcfuse.inc"

//******************************************************************************************************
#if(inc_testmode=true)
    #declare pin_short = on;
    #declare pcb_height = 1.500000;
    #declare pin_length = 2.5;

    #declare global_res_colselect=1;
    #declare global_res_col=1;
    #declare global_res_shape=1;
    #declare global_res_bend_radius=1;

    #declare global_diode_bend_radius=1;

    #declare global_seed=seed(1234);

    #declare global_show_screws = on;
    #declare global_show_washers = on;
    #declare global_show_nuts = on;
    #declare global_ambient_mul = 1.0;
#end










/********************************************************************************************************************************************
//Macros for Screws : M2 M2.5 M3 M4 M5
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
//Lg=lenght Col= color
//Hd:0=PAN 1=PHILIPS-ROUND-PAN 10=SLOTTED HEXA 11=FULL-BEARING 20=CHEESE 21=RAISED-CHEESE
//30=RAISED-COUNTER-SUNK 31=PHILIPS-RAISED-COUNTER-SUNK 32=COUNTER-SUNK 33=PHILIPS-COUNTER-SUNK  34=COUNTER-SUNK-HEXA-SOCKET
//zero is under head for #0 to #21 headed screws and on top for all counter sunk headed screws
********************************************************************************************************************************************/
#macro TOOLS_SCREW (M,lg,Hd,Col)

#switch (M)
    #case(2)
        #local R = 1.6;  //4 0.8
        #local r = 0.4;
        #local ep = 1.3;
        #local r1 = 0.65;
        #local A = 3.6;
        #local delta = 1.12;
        #local B = 1.2;
        #local H = 1.5;
        #local T = 0.4;
        #local S = 1.3;
    #break
    #case(2.5)
        #local R = 2;
        #local r = 0.5; //5  0.8
        #local ep = 1.6;
        #local r1 = 0.8;
        #local A = 4.4;
        #local delta = 1.32;
        #local B = 1.5;
        #local H = 2;
        #local T = 0.45;
        #local S = 1.6;
    #break
    #case(3)
        #local R = 2.4;  // 6  0.8
        #local r = 0.6;
        #local ep = 2;
        #local r1 = 1;
        #local A = 5.3;
        #local delta = 1.52;
        #local B = 1.65;
        #local H = 2.5;
        #local T = 0.5;
        #local S = 1.94;
    #break
    #case(4)
        #local R = 3.2; //8 0.8
        #local r = 0.8;
        #local ep = 2.6;
        #local r1 = 1.3;
        #local A = 6.6;
        #local delta = 1.82;
        #local B = 2.2;
        #local H = 3;
        #local T = 0.7;
        #local S = 2.42;
    #break
    #case(5)
        #local R = 4; //10 0.8
        #local r = 1;
        #local ep = 3.3;
        #local r1 = 1.65;
        #local A = 8;
        #local delta = 2.05;
        #local B = 2.5;
        #local H = 4;
        #local T = 0.8;
        #local S = 2.92;
    #break
#end

union{

    #if(Hd > -1)

        difference //head
        {
            #switch (Hd)
                #range(0,1) // PAN HEAD & PHILIPS ROUND-PAN
                    union
                    {
                        torus {R+r-r1,r1 translate (ep-r1)*y}        // round edge
                        cylinder {<0,0,0>, <0,ep,0>, R+r-r1}       // base
                        cylinder {<0,0.1,0>, <0,ep-r1,0>, R+r}   // top
                    }
                    #if(Hd=0)
                        box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                    #else
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep*y  } // Grove
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep*y  rotate 90*y} // Grove
                    #end
                #break

                #range(10,11) // SLOTTED HEXA HEAD & FULL BEARING HEAD
                    intersection {
                        //3 boxes for Hexa nut
                        box {<-A/2,0,-2*M>, <+A/2,+ep+0.1,+2*M> }
                        box {<-A/2,0,-2*M>, <+A/2,+ep+0.1,+2*M> rotate -60*y}
                        box {<-A/2,0,-2*M>, <+A/2,+ep+.01,+2*M> rotate +60*y}
                        sphere {  <0, -delta, 0>  0.83*A }
                    }
                    union{
                        cylinder {<0,+ep,0>, <0,+ep+0.2,0> A/2+r } // to get spotless surface
                        #if(Hd=10)
                            box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  rotate -30*y } // Grove
                        #end
                    }

                #break

                #case(20) // CHEESE
                    #local R=0.8*R;
                    cylinder {<0,0,0>, <0,ep,0>, R+r}       // base
                    box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                #break

                #case(21) // RAISED CHEESE
                    #local R=0.8*R;
                    intersection{
                        sphere{<0,-R/2,0> 1.7*R}
                        cylinder {<0,0,0>, <0,2*ep,0>, R+r}       // base
                    }
                    box {<-r,ep*.4,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                #break

                #range(30,31) // RAISED-COUNTER-SUNK & PHILIPS-RAISED-COUNTER-SUNK
                    union{
                        intersection{
                            sphere{<0,-A/2-S,0> A}
                            cylinder {<0,0,0>, <0,2*ep,0>, A*0.5}       // base
                        }
                        cone{0*y, A*0.5, -B*y,M/2}
                    }
                    #if(Hd=30)
                        box {<-r,-ep*.4,-R-2*r>, <+r,A,R+2*r>  } // Grove
                    #else
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep/3*y  } // Grove
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep/3*y  rotate 90*y} // Grove
                    #end
                #break

                #range(32,34) // COUNTER SUNK
                    cone{0*y, A*0.5, -B*y, M/2.1 }
                    #switch(Hd)
                        #case(32)
                            box {<-r,-ep*.4,-R-2*r>, <+r,0.1,R+2*r>  } // Grove
                        #break
                        #case(33)
                            box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate 0*y  } // Grove
                            box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate 0*y  rotate 90*y} // Grove
                        #break
                        #case(34)
                            difference{
                                intersection{
                                    box {<-H/2,0.1,-2*M>, <+H/2,-ep,+2*M> }
                                    box {<-H/2,0.1,-2*M>, <+H/2,-ep,+2*M> rotate -60*y}
                                    box {<-H/2,0.1,-2*M>, <+H/2,-ep,+2*M> rotate +60*y}
                                }
                                cylinder {<0,-ep*.6,0>, <0,-ep,0> A/2+r } // to get spotless surface
                            }
                        #break
                    #end
                #break
            #end

            rotate(rand(global_seed)*180)*y
        }
    #end

    #if(Hd<30)
        #local B1=0;
        #local N=2;
    #else
        #local B1=B;
        #local N=0;
    #end
    difference //body
    {
        union
        {
            cylinder {<0,-B1,0>, <0,-lg+r,0>, M/2}
            cone
            {
              <0,-lg+r,0>, M/2,
              <0,-lg,0>, M/3
            }
        }
        union
        {
            #while (N < (lg/T+1))
                torus {M/1.95,T/2.6 translate (-B1-N*T)*y}
                #local N = N + 1;
            #end
        }
    }

    pigment{Col}
}
#end


/********************************************************************************************************************************************
//Macros for Washers : diameter 2, 2.5, 3, 4, 5
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
//Col= color Type: 0=Z, 1=M, 2=L, 3=LL
********************************************************************************************************************************************/

#macro TOOLS_WASHER (d,Type,Col)
#switch (d)
    #case(2)
        #local AZ = 4;
        #local AM = 6;
        #local AL = 8;
        #local ALL = 10;
        #local C = 0.6;
        #local B = 2.25;
    #break
    #case(2.5)
        #local AZ = 5;
        #local AM = 7;
        #local AL = 9;
        #local ALL = 11;
        #local C = 0.7;
        #local B = 2.75;
    #break
    #case(3)
        #local AZ = 6;
        #local AM = 8;
        #local AL = 12;
        #local ALL = 14;
        #local C = 0.8;
        #local B = 3.25;
    #break
    #case(4)
        #local AZ = 8;
        #local AM = 10;
        #local AL = 14;
        #local ALL = 16;
        #local C = 0.8;
        #local B = 4.25;
    #break
    #case(5)
        #local AZ = 10;
        #local AM = 12;
        #local AL = 16;
        #local ALL = 20;
        #local C = 1;
        #local B = 5.25;
    #break
#end
#switch (Type)
    #case(0)
        #local A=AZ;
    #break
    #case(1)
        #local A=AM;
    #break
    #case(2)
        #local A=AL;
    #break
    #case(3)
        #local A=ALL;
    #break
#end

difference
{
    cylinder {<0,0,0>, <0,C,0>, A/2}
    cylinder {<0,-0.1,0>, <0,C+0.1,0>, B/2}
    pigment{Col}
}
#end

/********************************************************************************************************************************************
//Macros for Nuts : M2, M2.5, M3, M4, M5
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
//Col= color Type: 0=Hu, 1=Hh
********************************************************************************************************************************************/
#macro TOOLS_NUT (M, Type, Col)
#switch (M)
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

#if(Type=1)
    #local Delta = Delta-(M-B)/2;
    #local B=M;
#end

difference
    {
        intersection {
            //3 boxes for hexagonal shape
            box {<-A/2,-2*M,-B/2-0.1>, <+A/2,+2*M,+B/2+0.1> }
            box {<-A/2,-2*M,-B/2-0.1>, <+A/2,+2*M,+B/2+0.1> rotate -60*z}
            box {<-A/2,-2*M,-B/2-0.1>, <+A/2,+2*M,+B/2+0.1> rotate +60*z}
            //make some roundness
            sphere {  <0, 0, +Delta>  0.83*A }
            sphere {  <0, 0, -Delta>  0.83*A }
        }

        union {
            //hole
            cylinder {<0,0,-B>, <0,0,+B>, M/2}
            //thread
            union
            {
                #local N=0;
                # while (N < 10)
                    torus {M/1.95,T/2.6 rotate 90*x translate (-M/2+N*T)*z}
                #local N = N + 1;
                #end
            }
            cylinder {<0,0,+B/2+0.2>, <0,0,+B/2> A/2+T } // to get spotless surface
            cylinder {<0,0,-B/2-0.2>, <0,0,-B/2> A/2+T } // to get spotless surface
        }
        pigment{Col}
        rotate 90*x
        translate B/2*y
        rotate(rand(global_seed)*180)*y
    }
#end



/**********************************************************************
This macro is used for simple object generation
**********************************************************************/
#macro TOOLS_SSDL_BOX( corner1, corner2, trans, rot, sca, c)
  #ifdef(global_create_ssdl_file)
     #local corner1 = vrotate(corner1,B)
     #write( ssdl_file, "BOX:", corner1, corner2, c, "\n")
  #end
#end

#end
