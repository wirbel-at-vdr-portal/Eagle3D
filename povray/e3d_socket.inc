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



/********************************************************************************************************************************************
// Eagle3D-Makro for TEXTOOL-Socket,   keine eagle-library,         Joerg Bredendiek <sprut(replace with at)sprut.de>   
// lever actuated zero insertion force mechanism,  con-3m.lbr

// based of SOCKET_DIP_GRND from Joseph Zeglinski
// TEXTOOL-Sockel mit 15.24mm Reihenabstand erhalten automatisch breite Kontaktfedern

//Basemakro for TEXTOOL SOCKETS
//pin    = number of pins
//breite = interspace between the lines of pins in mm
********************************************************************************************************************************************/
#macro SOCKET_TEX_GRND(pin,breite)
/********************************************************************************************************************************************
//Philips screw for Textool-Socket
//Kreuzschraube fuer Textool-Sockel
********************************************************************************************************************************************/
#macro TEXSOCKET_SCREWHEAD_CROSS()
#local w = RRand(0,89,1);
difference{
   superellipsoid{<1,0.1> rotate<90,0,0> scale<1.4,0.5,1.4> translate<0,0,0>}
   box{<0.25,0,-1><-0.25,1,1>rotate<0, w,   0> translate<0,0,0>}
   box{<0.25,0,-1><-0.25,1,1>rotate<0, w+90,0> translate<0,0,0>}
   texture{col_silver}
}
#end
/********************************************************************************************************************************************
//Textool-Socket Pin
********************************************************************************************************************************************/
#macro TEXSOCKET_DIP_PIN()
box{<-0.2,0,-0.45><0.2,7,0.45> texture{col_silver}}
#end
/********************************************************************************************************************************************
//Textool-Socket Contakt
********************************************************************************************************************************************/
#macro TEXSOCKET_CONT()
union{
   box{<-0.0,5,-breite/4.4><0.1,10,breite/4.4>}
   box{< 0.2,5,-breite/4.4><0.3,10,breite/4.4>}
   texture{col_silver}
}
#end
/********************************************************************************************************************************************

********************************************************************************************************************************************/

#local texcolor = color red 0.15 green 0.5 blue 0.4;  //typical green color of the plastic body
union{
   #local links=-pin/4*2.54-8.73;   //linker gehaeuserand (mit hebel)  10.5mm vom pin  10-1.27=8.73
   #local rechts=pin/4*2.54+5.73;   //rechter gehaeuserand 7 mm vom pin 7-1.27=5.73
   #local a=pin;
        #local srand = 3.8;      //seitenrand , Abstand vom Pin zum Gehauserand
        #if(breite>20) 
                #local srand = (33-breite) / 2;
                #local links =-pin/4*2.54-11.36;
                #local rechts= pin/4*2.54+7.36;
                // beim 40WW (240-3639-00-0602J) ist das Gehäuse etwas kürzer
                #if(pin=40) 
                        #local links  = -35.5;
                        #local rechts = 31;
                #end
        #end
   // beim 48W (248-1282-00-0602J) ist das Gehäuse um ca 2,5 mm in Richtung zum Hebel verschoben
        #if(pin=48) 
                #local links  = links - 2.5;
                #local rechts = rechts - 2.5;
        #end

   difference{
      union{
         // der gruene grundkoerper
         // Länge: 2.54*pin/2 + 14.63
         // Breite:  15.00=7.62+2x3.7   22.75=15.24+2x3.7
         // Hoehe:   11.50

         box{<links+1, 0, -breite/2-srand>  <rechts-1, 11.8  ,breite/2+srand>}
         box{<links,   0, -breite/2-srand+1>  <rechts, 11.8  ,breite/2+srand-1>}
         cylinder{<0,0,0><0,11.8,0>1 translate<links+1 , 0,  breite/2+srand-1>}
         cylinder{<0,0,0><0,   7,0>1 translate<links+1 , 0, -breite/2-srand+1>}
         cylinder{<0,0,0><0,11.8,0>1 translate<rechts-1, 0,  breite/2+srand-1>}
         cylinder{<0,0,0><0,11.8,0>1 translate<rechts-1, 0, -breite/2-srand+1>}

                        // Beschriftung      
                        text{ttf besch_font "3M" 0.5,0.1*x scale<3,4,1>  rotate<90,0,0> rotate<0,-90,0> translate<links+8,12,-2>}
      }
                // diferent width of the contacts (slots)
      #local ii=0;
      #if(breite>10) 
         #local ii=2;
      #end
      #if(breite>20) 
         #local ii=4.5;
      #end
      // die Ausspartung fuer den Hebel
      box{<links-1, 5, -breite/2-srand+2><links+6, 12 ,-breite/2-srand-2>}
      // Vertiefungen
      box{<-pin/4*2.54, 2, -breite/4><pin/4*2.54, 3, breite/4> translate<0, 9,  breite/2-ii>} 
      box{<-pin/4*2.54, 2, -breite/4><pin/4*2.54, 3, breite/4> translate<0, 9, -breite/2+ii>} 
      //loecher fuer die schrauben
      cylinder{<0,0,0><0,13,0>1.6 translate<links +2,0,0>}
      cylinder{<0,0,0><0,13,0>1.6 translate<rechts-2,0,0>}
      // fuer jedes Pin ein schlitz im Grundkoerper
      // Breite 1.4mm, Laenge 7mm=15,24/2.2 oder 3.5mm=7,62/2,2
      // Verschiebung breiter schlitze ist 2mm geringer
      #local i=0;
      #while(i<(a/4))
         #if((pin/4)=div(pin,4)) // pinzahl durch 4 teilbar
            #local k = div(pin,4)-i-1;
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54+1.27,-7.15+2.9+9, breite/2-ii>}
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54-1.27,-7.15+2.9+9, breite/2-ii>}
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54+1.27,-7.15+2.9+9,-breite/2+ii>}
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54-1.27,-7.15+2.9+9,-breite/2+ii>}
         #else       // pinzahl nicht durch 4 teilbar
            #local k = div(pin,4)-i;
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54,-7.15+2.9+9, breite/2-ii>}
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54,-7.15+2.9+9, breite/2-ii>}
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54,-7.15+2.9+9,-breite/2+ii>}
            box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54,-7.15+2.9+9,-breite/2+ii>}
         #end
         #local i=i+1;
      #end
      pigment{texcolor}
   } //difference fuer den gruenen plastik-koerper endet hier

   // der Hebel
   union{
      cylinder{<  0,0,0><  0,0,3>0.8 texture{col_silver}} 
      sphere{<    0,0,0>0.8 texture{col_silver}} 
      cylinder{<  0,0,0><-14,0,0>0.8 texture{col_silver}} 
      cylinder{<-14,0,0><-16.5,0,0>2.4 pigment{texcolor}}
      sphere{<-14,0,0>2.4 pigment{texcolor}} 
      sphere{<-16.5,0,0>2.4 pigment{texcolor}} 
      translate<links+5, 7, -breite/2-srand+1>
   }

   //schrauben  Durchmesser 3mm, kreuz mit 2mm
   object{TEXSOCKET_SCREWHEAD_CROSS() translate<links+2 , 11,0>}
   object{TEXSOCKET_SCREWHEAD_CROSS() translate<rechts-2, 11,0>}

   //kontaktfedern
   #local i=0;
   #while(i<(a/4))
      #if((pin/4)=div(pin,4)) // pinzahl durch 4 teilbar
            #local k = div(pin,4)-i-1;
         object{TEXSOCKET_CONT() translate< k*2.54+1.27, 0 ,breite/2-ii>}
         object{TEXSOCKET_CONT() translate<-k*2.54-1.27, 0, breite/2-ii>}
         object{TEXSOCKET_CONT() translate< k*2.54+1.27, 0,-breite/2+ii>}
         object{TEXSOCKET_CONT() translate<-k*2.54-1.27, 0,-breite/2+ii>}
      #else       // pinzahl nicht durch 4 teilbar
         #local k = div(pin,4)-i;
         object{TEXSOCKET_CONT() translate< k*2.54, 0 ,breite/2-ii>}
         object{TEXSOCKET_CONT() translate<-k*2.54, 0, breite/2-ii>}
         object{TEXSOCKET_CONT() translate< k*2.54, 0,-breite/2+ii>}
         object{TEXSOCKET_CONT() translate<-k*2.54, 0,-breite/2+ii>}
      #end
      #local i=i+1;
   #end

   // nun die pins, in Form flacher Blechstreifen
   #local i=0;
   #while(i<(a/4))
      #if((pin/4)=div(pin,4))
         #local k = div(pin,4)-i-1;
         object{TEXSOCKET_DIP_PIN() translate<k*2.54+1.27,-7.15+2.9,breite/2>}
         object{TEXSOCKET_DIP_PIN() translate<-k*2.54-1.27,-7.15+2.9,breite/2>}
         object{TEXSOCKET_DIP_PIN() translate<k*2.54+1.27,-7.15+2.9,-breite/2>}
         object{TEXSOCKET_DIP_PIN() translate<-k*2.54-1.27,-7.15+2.9,-breite/2>}
      #else
         #local k = div(pin,4)-i;
         object{TEXSOCKET_DIP_PIN() translate<k*2.54,-7.15+2.9,breite/2>}
         object{TEXSOCKET_DIP_PIN() translate<-k*2.54,-7.15+2.9,breite/2>}
         object{TEXSOCKET_DIP_PIN() translate<k*2.54,-7.15+2.9,-breite/2>}
         object{TEXSOCKET_DIP_PIN() translate<-k*2.54,-7.15+2.9,-breite/2>}
      #end
      #local i=i+1;
   #end
   translate<0,0.1,0> 
}
#end


#macro SOCKET_TEX14()
SOCKET_TEX_GRND(14,7.62)
#end
#macro SOCKET_TEX16()
SOCKET_TEX_GRND(16,7.62)
#end
#macro SOCKET_TEX18()
SOCKET_TEX_GRND(18,7.62)
#end
#macro SOCKET_TEX20()
SOCKET_TEX_GRND(20,7.62)
#end
#macro SOCKET_TEX22()
SOCKET_TEX_GRND(22,10.16)
#end
#macro SOCKET_TEX24()
SOCKET_TEX_GRND(24,7.62)
#end
#macro SOCKET_TEX24W()
SOCKET_TEX_GRND(24,15.24)
#end
#macro SOCKET_TEX28()
SOCKET_TEX_GRND(28,10.16)
#end
#macro SOCKET_TEX28W()
SOCKET_TEX_GRND(28,15.24)
#end
#macro SOCKET_TEX32W()
SOCKET_TEX_GRND(32,15.24)
#end
#macro SOCKET_TEX40W()
SOCKET_TEX_GRND(40,15.24)
#end
#macro SOCKET_TEX40WW()
SOCKET_TEX_GRND(40,25.4)
#end
#macro SOCKET_TEX42W()
SOCKET_TEX_GRND(42,15.24)
#end
#macro SOCKET_TEX48W()
SOCKET_TEX_GRND(48,15.24)
#end
#macro SOCKET_TEX64WW()
SOCKET_TEX_GRND(64,22.86)
#end


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
