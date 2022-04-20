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
#include "TOOLS/NUT.inc"
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
