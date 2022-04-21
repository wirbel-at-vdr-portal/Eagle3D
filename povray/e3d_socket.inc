//Eagle3D 20110101 INC-File e3d_socket.inc
//created by: INC SRC Compiler v2.02
//created on: 01.01.2011 17:33:58
//(c) 2011 by M. Weisser
//or the author of the macro

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
 
#ifndef(__socket_inc)
#declare __socket_inc = true;

#include "e3d_tools.inc" 
#include "SOCKET/DIP.inc"
#include "SOCKET/PLCC.inc"
#include "SOCKET/TEXTOOL.inc"




/**********************************************************************
Testing
**********************************************************************/
#ifndef(inc_testmode)
          
//Size of the Grid Plane (+/- span)
#local XYZ_span=20;

//Orientation axes
cylinder{<-XYZ_span,0,0><XYZ_span,0,0>0.1 pigment{Blue}} //X
cylinder{<0,-XYZ_span,0><0,XYZ_span,0>0.1 pigment{Red}}     //Y
cylinder{<0,0,-XYZ_span><0,0,XYZ_span>0.1 pigment{Yellow}}  //Z

// Useful GRIDS:
#local XYZ_step= 1 ;          // axis increment
#local XYZ_cnt = 0;           //  loop counter
#local xyz_thick = 0.05;     // grid line thickness

// GRID PLANES: Remove comment begin/end to activate & select PLANES:
#while (XYZ_cnt <= XYZ_span)

   cylinder{<-XYZ_span,0,XYZ_cnt><XYZ_span,0,XYZ_cnt>xyz_thick pigment{Blue}}    // Positive Z-Lines
   cylinder{<-XYZ_span,0,-XYZ_cnt><XYZ_span,0,-XYZ_cnt>xyz_thick pigment{Blue}}  // Negative Z-Lines
   
   //cylinder{<0,XYZ_cnt,-XYZ_span><0,XYZ_cnt,XYZ_span>xyz_thick pigment{Red}}      // Positive Y-Z Plane Lines
   //cylinder{<0,-XYZ_cnt,-XYZ_span><0,-XYZ_cnt,XYZ_span>xyz_thick pigment{Red}} // Negative Y-Z Plane Lines
   
   //cylinder{<-XYZ_span,XYZ_cnt,0><XYZ_span,XYZ_cnt,0>xyz_thick pigment{Red}}      // Positive Y-X Plane Lines
   //cylinder{<-XYZ_span,-XYZ_cnt,0><XYZ_span,-XYZ_cnt,0>xyz_thick pigment{Red}} // Negative Y-X Plane Lines
   
   cylinder{<XYZ_cnt,0,-XYZ_span><XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}  // Positive X-Lines
   cylinder{<-XYZ_cnt,0,-XYZ_span><-XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}   // Negative X-Lines

   #local XYZ_cnt = XYZ_cnt+XYZ_step;
#end

camera
{       
   #local tt = 40;            //let's you change the distance easily
   location <-tt,tt,-tt>
   //location<0,5,-50>        //alternate location
   look_at <0,0,0>            //best to select the approximate centre of the object
   angle 30
}

light_source { <100, 100, -100> White}
light_source { <-100, 100, -100> White }
light_source { <-100, 100, 100> White }
light_source { <100, 100, 100> White }
//light_source { <-tt,tt,-tt> White }
//light_source { <-tt,tt,-tt> White }
//light_source { <-tt,tt,-tt> White }
background{Grey}

#end

#end
//End of Macros
