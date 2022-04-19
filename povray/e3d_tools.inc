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
#include "TOOLS/RECT_BOGEN.inc"
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





/**********************************************************************
//Generates a VIA
//dia_min:  diameter of the hole
//dia_max:  diameter of the via
//upper:    the upper layer which the via contains to
//lower:    the lower layer which the via contains to
//shape:    the shape of the via
//      0 square
//      1 octagon
//      2 round
//      3 long
//      4 offset
//      if shape >= 100 solder will be added to the via
**********************************************************************/
#macro TOOLS_PCB_VIA(dia_max,dia_min,upper,lower,shape,elongation)

#if((global_solder=on)&(shape>=100))
union{
#else
object{
#end

#local lupper = -global_pcb_layer_dis[upper-1]+pcb_cuheight+0.002;
#local llower = -global_pcb_layer_dis[lower-1]-0.002;


#if(shape>=100)
    #local shape=shape-100;
    #if(global_solder=on)
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

//square
#if(shape=0)
    box{<dia_max/2,lupper,dia_max/2><-dia_max/2,llower,-dia_max/2>}
#end
//round
#if(shape=1)
    cylinder{<0,lupper,0><0,llower,0>dia_max/2}
#end
//octagon
#if(shape=2)
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
//long
#if(shape=3)
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
//offset
#if(shape=4)
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

/**********************************************************************
//Generates an SMD
//xsize:    x-size of the SMD
//ysize:    y-size of the SMD
//thick:    the thikness of the copper
//r:        roundness (0%-100%)
**********************************************************************/
#macro TOOLS_PCB_SMD(xsize,ysize,thick,r)

    #if(r=0)
        box{<-xsize/2,0,-ysize/2><xsize/2,thick,ysize/2>}
    #else
        union{

            #if(xsize>ysize)

                #local xsmall=xsize-(ysize)*(r/100);
                    #local ysmall=ysize-(ysize)*(r/100);
                    #local cyldif=(ysize)*(r/100);

            #else
                #local xsmall=xsize-(xsize)*(r/100);
                    #local ysmall=ysize-(xsize)*(r/100);
                    #local cyldif=(xsize)*(r/100);

            #end

            box{<-xsmall/2,0,-ysize/2><xsmall/2,thick,ysize/2>}
            box{<-xsize/2,0,-ysmall/2><xsize/2,thick,ysmall/2>}

            cylinder{<-xsize/2+cyldif/2,0,-ysize/2+cyldif/2><-xsize/2+cyldif/2,thick,-ysize/2+cyldif/2>cyldif/2}
            cylinder{<-xsize/2+cyldif/2,0, ysize/2-cyldif/2><-xsize/2+cyldif/2,thick, ysize/2-cyldif/2>cyldif/2}
            cylinder{< xsize/2-cyldif/2,0,-ysize/2+cyldif/2>< xsize/2-cyldif/2,thick,-ysize/2+cyldif/2>cyldif/2}
            cylinder{< xsize/2-cyldif/2,0, ysize/2-cyldif/2>< xsize/2-cyldif/2,thick, ysize/2-cyldif/2>cyldif/2}

        }
    #end
#end

/**********************************************************************
//By John van Sickle
//
//    This macro creates a bar with four of its edges rounded. It fills the same
//space as box { Startcorner,EndCorner }, except that the edges running along the
//y-axis are rounded. StartCorner and EndCorner are opposite corners of the box,
//and Radius is the radius of the rounded edges.
//   The bar is made up of a prism object and four cylinder objects that run
//parallel to the y-axis. If you want the bar to run along any other axis, you
//will have to transform it just as you would any prism object. There is no merge
//or union declared around them, to leave the choice up to the user; merge is
//better for applications with transparency, union is better for others. Here is
//an example of the macro's use:
//
//object {
//  TOOLS_ROUNDED_BAR(<-10,0,0>,<10,40,20>,2)
//  pigment { rgb .75 }
//}
//
//Although the example code uses vector literals for StartCorner and EndCorner,
//you can use any vector expression, and scalars will be promoted to full vectors.
//
//Modified by fbleikamp(replace with at)web.de for Eagle3D objects
//
**********************************************************************/

#macro TOOLS_ROUNDED_BAR(v_SP,v_EP,R)
  #local vSP=(v_SP)*<1,1,1>;
  #local vEP=(v_EP)*<1,1,1>;
#if (vSP.x > vEP.x)
  #local tSave=vSP.x;
  #local vSP=<vEP.x,vSP.y,vSP.z>;
  #local vEP=<tSave,vEP.y,vEP.z>;
#end
#if (vSP.y > vEP.y)
  #local tSave=vSP.y;
  #local vSP=<vSP.x,vEP.y,vSP.z>;
  #local vEP=<vEP.x,tSave,vEP.z>;
#end
#if (vSP.z > vEP.z)
  #local tSave=vSP.z;
  #local vSP=<vSP.x,vSP.y,vEP.z>;
  #local vEP=<vEP.x,vEP.y,tSave>;
#end
#union{
  box {<vSP.x+R,vSP.y,vSP.z>,<vEP.x-R,vEP.y,vEP.z>}
  box {<vSP.x,vSP.y+R,vSP.z>,<vEP.x,vEP.y-R,vEP.z>}

  cylinder { <vSP.x+R,vSP.y+R,vSP.z>,<vSP.x+R,vSP.y+R,vEP.z>,R }
  cylinder { <vEP.x-R,vSP.y+R,vSP.z>,<vEP.x-R,vSP.y+R,vEP.z>,R }
  cylinder { <vSP.x+R,vEP.y-R,vSP.z>,<vSP.x+R,vEP.y-R,vEP.z>,R }
  cylinder { <vEP.x-R,vEP.y-R,vSP.z>,<vEP.x-R,vEP.y-R,vEP.z>,R }
   }

#end

/**********************************************************************
//TOOLS_TORUS_SPLINE() By: Ron Parker
//
//    This macro is used to create a smooth spline of toruses connecting
//a sequence of points.  To use it, use code like the following:
//
//#declare Pts=array[5]{<0,0,0>, <1,1,1>, <-.5,1,2>, <.5,1,3>, <0,1,4>}
//object {
//  TOOLS_TORUS_SPLINE( .1, Pts, <1,0,.5> )
//  texture {...}
//  }
//
//The first parameter to the TorusSpline macro is the minor radius of
//the toruses to be used in creating the spline.
//
//The second parameter is the array of points through which the spline
//should pass.
//
//The third parameter is the direction vector to be used at the start
//of the spline.  Varying this vector can have surprising results on
//the resulting object.  If the spline should leave another object at
//a specific angle, as with a lamp cord or rope, use this vector to
//show the angle.  If it is zero, The first torus will be calculated to
//pass through the first three points.  This is usually what you want,
//but you can get some neat effects if you override the default.
//
//It is possible to specify invalid parameters.  If you do, you will
//likely get a parse error.
//
//Achtung!!! Axis in MyAxis umbenannt, konflikt mit macro-name in special.inc <fbleikamp(replace with at)web.de>
//Fehler in Verbindung mit bentpipe.mcr abgefangen bei vcross((B-A),V) = 0 und den daraus folgenden Fehlern.
*********************************************************************/

#macro TOOLS_TORUS_SPLINE( TorRadius, Points, StartVect )

  // promote the start vector to a vector, even if they gave us a scalar (e.g. 0)
  #local V=<0,0,0>+StartVect;
  #local Numpoints = dimension_size( Points, 1 );
  #local Cur = 0;

  union {

    #while (Cur < Numpoints-1 )
      #local A=Points[Cur];
      #local B=Points[Cur+1];
      #if (V.x=0&V.y=0&V.z=0)
        #local C=Points[Cur+2];
        #if (vlength(vcross(C-A,B-A))=0)
          #local V=B-A;
          #local Cos=0;
          #local MyAxis=<0,0,0>;
        #else
          #local MyAxis=vnormalize(vcross((C-A),(B-A)));
          #local Base1=vnormalize(C-A);
          #local Base2=vnormalize(vcross(MyAxis,Base1));
          #local VB=<0.5*vlength(C-A),0,0>;
          #local VA=vcross(VB,z);
          #local VD=.5*<vdot(B-A,Base1),vdot(B-A,Base2),0>;
          #local VC=vcross(VD,z);
          #local Beta=((VD-VB).y*VA.x-(VD-VB).x*VA.y)/(VC.x*VA.y-VC.y*VA.x);
          #local Center=A+VD.x*Base1+VD.y*Base2+Beta*(VC.x*Base1+VC.y*Base2);
          #local Radius=vlength(Center-A);
          #local Cos=1;
          #local V=vcross( MyAxis,Center-A );
        #end
        #local B=C;
        #local Cur=Cur+1;
      #else
         #local C=vcross((B-A),V);  // fbleikamp(replace with at)web.de
         #if ( C.x!=0|C.y!=0|C.z!=0)
            #local MyAxis=vnormalize(vcross((B-A),V));
            #local Dir=vnormalize(vcross(V, MyAxis ));
            #local Cos=vdot(vnormalize(B-A), Dir);
            #local Radius=abs(.5*vlength(B-A)/Cos);
            #local Center=A+Radius*Dir;
         #else
            #local MyAxis=<0,0,0>;
            #local Center=A;
            #local Cos=0;
         #end
      #end

      #local V1=V;

      #if ( Cos & (MyAxis.x!=0|MyAxis.y!=0|MyAxis.z!=0))
        #if (MyAxis.y = 0 & vlength(<MyAxis.x,0,MyAxis.z>) = 0)
          #local RZ=0;
        #else
          #local RZ=-degrees(atan2(vlength(<MyAxis.x,0,MyAxis.z>), MyAxis.y));
        #end
        #if (MyAxis.z = 0 & MyAxis.x = 0 )
          #local RY=0;
        #else
          #local RY=-degrees(atan2(MyAxis.z, MyAxis.x));
        #end
        #local V1=vcross(B-Center, MyAxis);

        #if ( vdot(vcross(V,A-Center),vcross(V, V1))>0 )
          #local Planes =  union{
            plane{-V, vdot( A-.0001*TorRadius*V, vnormalize(-V) ) }
            plane{V1, vdot( .0001*TorRadius*V1+B, vnormalize(V1))}
          }
        #else
          #local Planes =  intersection {
            plane{-V, vdot( A-.0001*TorRadius*V, vnormalize(-V) ) }
            plane{V1, vdot( .0001*TorRadius*V1+B, vnormalize(V1))}
          }
        #end

        intersection{
          object {Planes}
          torus{ Radius, TorRadius rotate RZ*z rotate RY*y translate Center }
        }
      #else
        cylinder {A-.0001*TorRadius*V, B+.0001*TorRadius*V, TorRadius}
      #end
      #declare Cur=Cur+1;
      #declare V=V1;
    #end
  }
#end

/**********************************************************************
//TOOLS_BENTPIPE() By: Ron Parker
//
//   This macro allows you to specify a TorusSpline as a series of "turtle-like" moves rather than as
//   a series of points.  You tell it to start at a particular position and orientation and give it
//   a series of commands (go straight x units, turn left/right x degrees with radius r)
//   and a radius for the pipe and it creates the specified pipe.
//   It does assume you are operating in the X-Y plane.
//   This macro requires my TorusSpline macro as well.  It is possible to provide bad arguments;
//   if you do, you'll get bad results.
//   For example, a 1-unit bend in a 2-unit radius pipe is probably not too smart.
//
//Sample usage:
//#declare bends=array[6] {
//    // <angle, radius, 0> or <0, distance, 0> for straight pipe
//    // negative angles bend left, positive bend right.
//    <0, 10, 0>,  <-45, 5, 0>,  <225,5,0>,  <-225,5,0>,  <45, 5, 0>,  <0, 10, 0>
//}
//
//object {
//    // this pipe has a radius of 1, starts at the origin, and initially goes in the x direction
//    TOOLS_BENTPIPE( 1, <0,0,0>, x, bends )
//    texture {pigment {color rgb 1}}
//}
**********************************************************************/

#macro TOOLS_BENTPIPE( PipeRadius, Loc, Dir, Bends )
  #local Pts=array[dimension_size( Bends, 1 )+1]
  #local Pts[0] = <0,0,0>+Loc;
  #local StartDir = <0,0,0>+Dir;
  #local Cur = 0;
  #while ( Cur < dimension_size( Bends, 1 ) )
    #if (Bends[Cur].u = 0 )
      #local Pts[Cur+1] = Pts[Cur]+Bends[Cur].v*vnormalize(Dir);
    #else
      #local Offset = Bends[Cur].v * vnormalize(vcross( Dir, -Bends[Cur].u*z ));
      #local Pts[Cur+1]=Pts[Cur]-Offset+vrotate(Offset, -Bends[Cur].u*z);
      #local Dir = vrotate( Dir, -Bends[Cur].u*z );
    #end
    #local Cur=Cur+1;
  #end

  TOOLS_TORUS_SPLINE( PipeRadius, Pts, StartDir )
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
