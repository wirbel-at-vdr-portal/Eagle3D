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
#include "TOOLS/SCREW.inc"
#include "TOOLS/TORUS_SPLINE.inc"
#include "TOOLS/WASHER.inc"
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
