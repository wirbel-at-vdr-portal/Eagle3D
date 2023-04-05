/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * precision style dip headers.
 * The following is a modified module section by Joseph Zeglinski,
 * Aug. 20, 2003
 * 20220421: rewrite to use GRID_BASE(), instead of local while loops. wk
 * -----------------------------------------------------------------------------
 * produces either a fully pin populated DIL SOCKET, or, a DIL SOCKET with
 * fewer "quads" of pins, ie. some IC's, FET's, Optoisolators and Crystal
 * Oscillators - (8, 14, 16, or 24) pin body, with only 4, 6 or 12 outer pins.
 *
 * pin: pin count of a full DIL in that size
 * a  : available pin positions, <= pin; modulo 4
 * w  : width (in grid)
 ******************************************************************************/
#macro SOCKET_DIP_BASE(pin,a,w)
union{
   difference {
      union {
         box{<-pin/4*2.54, 0, +w/2+1.2> <pin/4*2.54, 2.8, +w/2-1.2>}
         box{<-pin/4*2.54, 0, -w/2-1.2> <pin/4*2.54, 2.8, -w/2+1.2>}
         }

      difference {
         // a number of holes, to be cut out of the union above.
         #local pinhole = cylinder{<0,-0.1,0><0,8,0>0.51};
         union {
            // for any pin in the grid, drill a hole:
            object {GRID_BASE(pinhole, 2.54, div(pin,2),1) translate<0,-7.15+2.9,+w/2>}
            object {GRID_BASE(pinhole, 2.54, div(pin,2),1) translate<0,-7.15+2.9,-w/2>}
            }
         #if (a < pin)
             // but, for pins that are not available, *dont* drill a hole:
             #local no_pinhole = cylinder{<0,-0.1,0><0,8.1,0> 0.6};
             union {
                #local fillpins = (pin - a);
                object {GRID_BASE(no_pinhole, 2.54, div(pin-a,2),1)  translate<0,-7.15+2.9,+w/2> }
                object {GRID_BASE(no_pinhole, 2.54, div(pin-a,2),1)  translate<0,-7.15+2.9,-w/2> }
                }
         #end
         }
      }
  
   difference {
      // the pins inside the holes.
      #local dip_pin = difference {
           union {
              cylinder{<0,0,0><0,2.95,0>0.25}
              sphere{<0,0,0>0.25}
              cone{<0,2.95,0>0.25<0,3.45,0>0.6}
              cylinder{<0,3.45,0><0,7.15,0>0.6}
              cylinder{<0,6.4,0><0,7.15,0>0.85}
              }
           cylinder{<0,4,0><0,7.16,0>0.5}
           texture{col_silver}
           };

      union {
         // for any pin in the grid, draw a pin:
         object {GRID_BASE(dip_pin, 2.54, div(pin,2),1) translate<0,-7.15+2.9,+w/2>}
         object {GRID_BASE(dip_pin, 2.54, div(pin,2),1) translate<0,-7.15+2.9,-w/2>}
         }
      union {
         #if (a < pin)
             // but, for pins that are not available, *dont* draw a pin:
             #local no_pinhole = cylinder{<0,-3,0><0,10,0> 0.9};
             union {
                #local fillpins = (pin - a);
                object {GRID_BASE(no_pinhole, 2.54, div(pin-a,2),1)  translate<0,-7.15+2.9,+w/2> }
                object {GRID_BASE(no_pinhole, 2.54, div(pin-a,2),1)  translate<0,-7.15+2.9,-w/2> }
                }
         #end
         }
      }
   difference {
      box{<-pin/4*2.54,0,w/2-1.2><-pin/4*2.54+2,2,-w/2+1.2>}
      cylinder{<0,-0.1,0><0,3,0>1 translate<-pin/4*2.54-0.4,0,0>}
      }

   box {<pin/4*2.54,0,w/2-1.2> <pin/4*2.54-2,2,-w/2+1.2> }
   #if ((pin>19) & (pin<33))
       box{<-1,0,w/2-1.2><1,2,-w/2+1.2>}
   #end

   #if (pin>32)
       box{<-pin/12*2.54+1,0,w/2-1.2><-pin/12*2.54-1,2,-w/2+1.2>}
       box{<pin/12*2.54+1,0,w/2-1.2><pin/12*2.54-1,2,-w/2+1.2>}
   #end

   translate<0,0.1,0> 
   pigment{Gray10}
   }
#end

#macro SOCKET_DIP8A4() // ok: DIP8 with 4 corner pin sockets
  SOCKET_DIP_BASE(8,4,7.62)
#end

#macro SOCKET_DIP14A4() // ok: DIP14 with 4 corner pin sockets
  SOCKET_DIP_BASE(14,4,7.62)
#end

#macro SOCKET_DIP14A8() // ok: DIP14 with 8 corner pin sockets
  SOCKET_DIP_BASE(14,8,7.62)
#end

#macro SOCKET_DIP16A4() // ok: DIP16 with 4 corner pin sockets
  SOCKET_DIP_BASE(16,4,7.62)
#end

#macro SOCKET_DIP16A8() // ok: DIP16 with 8 corner pin sockets
  SOCKET_DIP_BASE(16,8,7.62)
#end

#macro SOCKET_DIP24A12() // ok: DIP24 with 12 corner pin sockets
  SOCKET_DIP_BASE(24,12,7.62)
#end

#macro SOCKET_DIP2()
  SOCKET_DIP_BASE(2,2,7.62)
#end

#macro SOCKET_DIP4()
  SOCKET_DIP_BASE(4,4,7.62)
#end

#macro SOCKET_DIP6()
  SOCKET_DIP_BASE(6,6,7.62)
#end

#macro SOCKET_DIP6_4() // ok.
  SOCKET_DIP_BASE(6,6,10.16)
#end

#macro SOCKET_DIP8()
  SOCKET_DIP_BASE(8,8,7.62)
#end

#macro SOCKET_DIP14()
  SOCKET_DIP_BASE(14,14,7.62)
#end

#macro SOCKET_DIP16()
  SOCKET_DIP_BASE(16,16,7.62)
#end

#macro SOCKET_DIP18()
  SOCKET_DIP_BASE(18,18,7.62)
#end

#macro SOCKET_DIP20()
  SOCKET_DIP_BASE(20,20,7.62)
#end

#macro SOCKET_DIP22()
  SOCKET_DIP_BASE(22,22,7.62)
#end

#macro SOCKET_DIP22_4()
  SOCKET_DIP_BASE(22,22,10.16)
#end

#macro SOCKET_DIP24()
  SOCKET_DIP_BASE(24,24,7.62)
#end

#macro SOCKET_DIP24_4()
  SOCKET_DIP_BASE(24,24,10.16)
#end

#macro SOCKET_DIP24W()
  SOCKET_DIP_BASE(24,24,15.24)
#end

#macro SOCKET_DIP24_9()
  SOCKET_DIP_BASE(24,24,22.86)
#end

#macro SOCKET_DIP28()
  SOCKET_DIP_BASE(28,28,7.62)
#end

#macro SOCKET_DIP28_4()
  SOCKET_DIP_BASE(28,28,10.16)
#end

#macro SOCKET_DIP28W()
  SOCKET_DIP_BASE(28,28,15.24)
#end

#macro SOCKET_DIP32_3()
  SOCKET_DIP_BASE(32,32,7.62)
#end

#macro SOCKET_DIP32W()
  SOCKET_DIP_BASE(32,32,15.24)
#end

#macro SOCKET_DIP36W()
  SOCKET_DIP_BASE(36,36,15.24)
#end
 
#macro SOCKET_DIP40W()
  SOCKET_DIP_BASE(40,40,15.24)
#end

#macro SOCKET_DIP42W()
  SOCKET_DIP_BASE(42,42,15.24)
#end

#macro SOCKET_DIP48W()
  SOCKET_DIP_BASE(48,48,15.24)
#end

#macro SOCKET_DIP52W()
  SOCKET_DIP_BASE(52,52,15.24)
#end

#macro SOCKET_DIP64_9()
  SOCKET_DIP_BASE(64,64,22.86)
#end

#macro SOCKET_DIP68_9()
  SOCKET_DIP_BASE(68,68,22.86)
#end
