/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/



/*******************************************************************************
 * LK     : Laenge des Kunststoff(Seite der Pins)
 * BK     : Breite des Kunststoff(Seite ohne Pins)
 * HK     : Hoehe des Kunststoff
 * B      : Laenge der Seite ohne Pins ueber alles
 * pin_u  : Pins auf der "unteren" Seite
 * pin_o  : Pins auf der "oberen" Seite
 * ptch_u : Pitch der Pins auf der "unteren" Seite
 * ptch_o : Pitch der Pins auf der "oberen" Seite
 * pinb_u : Breite der Pins auf der "unteren" Seite
 * pinb_o : Breite der Pins auf der  "oberen" Seite
 * pin_s  : Staerke des Pinmaterials
 * di_pcb : Abstand des Kunststoff zur Platine
 * kor_w  : Korrekturwinkel
 * pin0_m : Pin-1-Markierung:
 *            0 = keine,
 *            1 = Farbklecks
 *            2 = Kerbe wie bei DIP
 *            3 = PowerSO
 *            4 = DPAK
 * pin0_45: Wenn != 0 wird an der unteren Seite ein Winkel am Koerper
 *          von 45° statt 10° verwendet (SO)
 * pin0_a : Abstand des Pin0-Kennzeichners vom Rand
 * besch_s: Scalefaktor der Beschriftung
 * besch_w: Wenn != 0 wird Beschriftung gedreht
 * logo   : Name of the logo
 ******************************************************************************/



/*******************************************************************************
 * TO252 = DPAK
 *
 * 20220429, full rewrite, wk
 ******************************************************************************/

#macro IC_SMD_TO252_BASE(value,logo,npins,grid,pinwidth,centercut)
  union {
     // plastic base without pins.
     IC_SMD_BASE(6.5,6.1,2.3,11.74,0,0,4.57,4.57,0.75,0.75,0.5,0.075,0,0,0,6.5/2,1.0,0,logo)

     // backside/cooling plate
     difference {
        union {
           box { <-5.3/2,0.05,5/2> <+5.3/2,0.55,6.1/2+1> }
           box { <-4.4/2,0.05,6.1/2+1-5.21> <+4.4/2,0.55,6.1/2+0.1> }
           }

        box { <-3/2,0,-1> <+3/2,0.6,+1> translate <0,0,5.52> rotate<0,+35,0>}
        box { <-3/2,0,-1> <+3/2,0.6,+1> translate <0,0,5.52> rotate<0,-35,0>}
        cylinder { <+3.5/2,0,+2.5> <+3.5/2,0.6,+2.5> 0.3 }
        cylinder { <-3.5/2,0,+2.5> <-3.5/2,0.6,+2.5> 0.3 }
        box { <+6.0/2,0.0,+2.5-0.6/2> <+3.5/2,0.6,+2.5+0.6/2> }
        box { <-6.0/2,0.0,+2.5-0.6/2> <-3.5/2,0.6,+2.5+0.6/2> }
        texture{e3d_tex_silver}
        }
     // pins
     difference {
        union {
           #local pin = union {
              object { TOOLS_RECT_BOGEN(0.5,100,0.5,0.75,2.4,0.0) rotate <0,-90,180> translate <0,1.6-0.5/2,-4.5> }
              object { TOOLS_RECT_BOGEN(0.5,100,0.5,0.75,1.0,0.0) rotate <0,90,   0> translate <0,    0.5/2,-4.4> }
              box { <-0.9/2,1.6-0.5,-3.7-0.6/2> <+0.9/2,1.6    ,-3.7+0.6/2> }
              texture{e3d_tex_silver}
              };
           GRID_BASE(pin, grid, npins, 1)
           }
        #if (centercut = 1)
            #local diff = box { <-pinwidth/2-0.3,-0.1,-7> <+pinwidth/2+0.3,2,-3.9> }
            object { diff }
        #end
        texture{e3d_tex_silver}
        }

     translate <0,0,+0.833>
     }
#end

/*******************************************************************************
 * 3 pin
 * https://www.infineon.com/cms/en/product/packages/PG-TO252/PG-TO252-3-11/
 * fdd4141-348236.pdf
 ******************************************************************************/
#macro IC_SMD_TO252_3Lead(value,logo)
   IC_SMD_TO252_BASE(value,logo,3,2.29,0.75,1)
#end

/*******************************************************************************
 * 5 pin
 * https://www.infineon.com/dgdl/PG-TO252-5-13-PO.eps?fileId=5546d462580663ef015807046a6f1080
 ******************************************************************************/
#macro IC_SMD_TO252_5Lead(value,logo)
   IC_SMD_TO252_BASE(value,logo,5,1.14,0.6,1)
#end

/*******************************************************************************
 * 5 pin, moved by 0.833mm in y
 ******************************************************************************/
#macro IC_SMD_TO252_5Lead_11(value,logo)
   object { IC_SMD_TO252_5Lead(value,logo) translate<0,0,-0.833> }
#end

/*******************************************************************************
 * TO-252-5-P2, as IC_SMD_TO252_5Lead, but with center pin.
 ******************************************************************************/
#macro IC_SMD_TO252_5Lead_P2(value,logo)
   IC_SMD_TO252_BASE(value,logo,5,1.14,0.6,0)
#end
