/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


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
#include "shapes3.inc"
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
#include "TOOLS/GRID_BASE.inc"
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

#end
