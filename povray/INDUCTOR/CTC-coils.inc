/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMD inductor C.T.C. Coils SMSL1305,  http://www.ctccoils.com
 * everyone1@freenet.de
 * L - Gesamt Laenge der Drossel
 * B - Gesamt Breite der Drossel
 * H - Gesamt Hoehe der Drossel
 * value - Aufschrift
 ******************************************************************************/
#macro SMSL1305_BASE(L,B,H,value)
  #local PX = 2.54;       // Pad-Groesse
  #local U = 0.1;         // Ueberlappung Differenzebildung
  #local R = B*0.9/2;     // Radius Spulenkoerper
  #local R1 = 0.2;        // Radius Draht
  #local H1 = 0.8;        // Hoehe Grundplatte
  #local H2 = 0.6;        // Dicke der Deckplatten der Spule
  #local L1 = L*0.95/2;   // Halbe Laenge der Grundplatte
  #local X1 = L1*0.2;     // Halbe Laenge der geraden Seite
  #local Z1 = B*0.33/2;   // Halbe Breite der geraden Seite

  #declare Draht = torus {
     R-R1-0.3, R1 
     texture {
        Copper_Metal
        pigment {
           color rgb <0.7,0.2,0>
           }
        finish {
           metallic
           brilliance 4
           ambient (0.1 * global_ambient_mul)
           }
        }            
     }
  #local H3 = H-0.1-H1-2*H2;
  #local A = int(H3 / (2*R1)) + 1; // Anzahl der Windungen
  #local C = H3 / A;
  #local Y2 = H1+H2+R1;

  union {
     box {
        <-L/2+H1/4,      0, -B*0.30/2>
        <-L/2+PX  , H1+0.2, +B*0.30/2>
        texture {
           col_silver
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     cylinder {
        < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
        scale < 0.5, 1, 1>
        translate <-L/2+H1/4, H1/2+0.1, 0>
        texture {
           col_silver
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     box {
        < L/2-H1/4, 0, -B*0.30/2> < L/2-PX, H1+0.2, B*0.30/2>
        texture {
           col_silver
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     cylinder {
        < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
        scale < 0.5, 1, 1>
        translate < L/2-H1/4, H1/2+0.1, 0>
        texture {
           col_silver
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     prism {
        0.1, H1, 9
        <-X1,-B/2>, < X1,-B/2>, < L1,-Z1>, < L1, Z1>, < X1, B/2>, 
        <-X1, B/2>, <-L1, Z1>, <-L1,-Z1>, <-X1,-B/2>
        texture {
           pigment {
              Gray20
              }
           }
        }
     cylinder {
        < 0, 0.1+H1, 0> < 0, 0.1+H1+H2, 0> R-H2/2 
        texture {
           pigment {
              Gray10
              }
           }
        }
     torus {
        R-H2/2, H2/2
        texture {
           pigment {
              Gray10
              }
           }
        translate < 0, 0.1+H1+H2/2, 0>
        }
     cylinder {
        < 0, H, 0> < 0, H-H2, 0> R-H2/2 
        texture {
           pigment {
              Gray10
              }
           }
        }
     torus {
        R-H2/2, H2/2
        texture {
           pigment {
              Gray10
              }
           }
        translate < 0, H-H2/2, 0>
        }
     #while ( A >= 0 )
        object { Draht translate < 0, Y2, 0> }
        #declare Y2 = Y2 + C;
        #declare A = A -1;
     #end
     text {
        ttf global_fontfile_arial value 0.1,0
        rotate <90,0,0>
        scale<1.8,1,1.8>
        translate <-R+1, H+0.01, 0.0>
        pigment {
           Gray60
           }
        }
     }
#end

#macro SPC_L_CTC_SMSL1305(value)
  SMSL1305_BASE(12.95, 9.4, 5.21, value)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_L_CTC_SMSL1305(:SMD inductor SMSL1305
// end assignment
