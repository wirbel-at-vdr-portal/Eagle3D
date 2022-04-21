/*******************************************************************************
 * TEXTOOL Socket.
 * Author: Joerg Bredendiek <sprut(replace with at)sprut.de>
 *
 * - lever actuated zero insertion force mechanism,  con-3m.lbr
 * - based of SOCKET_DIP_GRND from Joseph Zeglinski
 * Args:
 *   pin   : number of pins
 *   breite: interspace between the lines of pins in mm
 ******************************************************************************/
#macro SOCKET_TEX_base(pin,breite)
  #local texcolor = color red 0.15 green 0.5 blue 0.4;  //typical green color of the plastic body

  union {
     #local links=-pin/4*2.54-8.73;   //linker gehaeuserand (mit hebel)  10.5mm vom pin  10-1.27=8.73
     #local rechts=pin/4*2.54+5.73;   //rechter gehaeuserand 7 mm vom pin 7-1.27=5.73
     #local a=pin;
     #local srand = 3.8;              //seitenrand , Abstand vom Pin zum Gehaeuserand
     #if (breite>20)
         #local srand = (33-breite) / 2;
         #local links =-pin/4*2.54-11.36;
         #local rechts= pin/4*2.54+7.36;

         // beim 40WW (240-3639-00-0602J) ist das Gehaeuse etwas kuerzer
         #if (pin=40)
             #local links  = -35.5;
             #local rechts = 31;
         #end
     #end

     // beim 48W (248-1282-00-0602J) ist das Gehaeuse um ca 2,5 mm in Richtung zum Hebel verschoben
     #if (pin=48) 
         #local links  = links - 2.5;
         #local rechts = rechts - 2.5;
     #end

     difference {
        union {
           // der gruene grundkoerper
           // Laenge: 2.54*pin/2 + 14.63
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

        // different width of the contacts (slots)
        #local ii=0;

        #if (breite>10)
            #local ii=2;
        #end

        #if (breite>20)
            #local ii=4.5;
        #end

        // die Aussparung fuer den Hebel
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
        #declare slot = box{<-0.7,-0,-breite/4.4> <+0.7,15,breite/4.4>};
        object { GRID_BASE(slot, 2.54,div(pin,2),1) translate<0,0,+breite/2-ii> }
        object { GRID_BASE(slot, 2.54,div(pin,2),1) translate<0,0,-breite/2+ii> }
        pigment{texcolor}
        } //difference fuer den gruenen plastik-koerper endet hier

     // der Hebel
     union {
        cylinder{<  0,0,0><  0,0,3>0.8 texture{col_silver}}
        sphere{<    0,0,0>0.8 texture{col_silver}}
        cylinder{<  0,0,0><-14,0,0>0.8 texture{col_silver}}
        cylinder{<-14,0,0><-16.5,0,0>2.4 pigment{texcolor}}
        sphere{<-14,0,0>2.4 pigment{texcolor}}
        sphere{<-16.5,0,0>2.4 pigment{texcolor}}
        translate<links+5, 7, -breite/2-srand+1>
        }

     //schrauben  Durchmesser 3mm, kreuz mit 2mm
     #local screw = TOOLS_SCREW(3,4, 33,Silver);
     object{ screw scale 0.55 translate<links +2, 11.5,0> }
     object{ screw scale 0.55 translate<rechts-2, 11.5,0> }

     //kontaktfedern
     #local texsocket_cont =
         union {
            box{<-0.0,5,-breite/4.4><0.1,10,breite/4.4>}
            box{< 0.2,5,-breite/4.4><0.3,10,breite/4.4>}
            texture{col_silver}
            };
     object { GRID_BASE(texsocket_cont, 2.54,div(pin,2),1) translate<0,0,+breite/2-ii> }
     object { GRID_BASE(texsocket_cont, 2.54,div(pin,2),1) translate<0,0,-breite/2+ii> }

     // nun die pins, in Form flacher Blechstreifen
     #local texsocket_dip_pin =  box{<-0.2,0,-0.45><0.2,7,0.45> texture{col_silver}};
     object { GRID_BASE(texsocket_dip_pin, 2.54,div(pin,2),1) translate<0,-7.15+2.9,+breite/2> }
     object { GRID_BASE(texsocket_dip_pin, 2.54,div(pin,2),1) translate<0,-7.15+2.9,-breite/2> }

     translate<0,0.1,0>
     }
#end


#macro SOCKET_TEX14()
  SOCKET_TEX_base(14,7.62)
#end

#macro SOCKET_TEX16()
  SOCKET_TEX_base(16,7.62)
#end

#macro SOCKET_TEX18()
  SOCKET_TEX_base(18,7.62)
#end

#macro SOCKET_TEX20()
  SOCKET_TEX_base(20,7.62)
#end

#macro SOCKET_TEX22()
  SOCKET_TEX_base(22,10.16)
#end

#macro SOCKET_TEX24()
  SOCKET_TEX_base(24,7.62)
#end

#macro SOCKET_TEX24W()
  SOCKET_TEX_base(24,15.24)
#end

#macro SOCKET_TEX28()
  SOCKET_TEX_base(28,10.16)
#end

#macro SOCKET_TEX28W()
  SOCKET_TEX_base(28,15.24)
#end

#macro SOCKET_TEX32W()
  SOCKET_TEX_base(32,15.24)
#end

#macro SOCKET_TEX40W()
  SOCKET_TEX_base(40,15.24)
#end

#macro SOCKET_TEX40WW()
  SOCKET_TEX_base(40,25.4)
#end

#macro SOCKET_TEX42W()
  SOCKET_TEX_base(42,15.24)
#end

#macro SOCKET_TEX48W()
  SOCKET_TEX_base(48,15.24)
#end

#macro SOCKET_TEX64WW()
  SOCKET_TEX_base(64,22.86)
#end
