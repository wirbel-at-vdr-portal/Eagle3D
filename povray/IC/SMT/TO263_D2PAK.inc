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
 * TO263 = D2PAK
 * 20220502, full rewrite, wk
 ******************************************************************************/

#macro IC_SMD_TO263_BASE(value,logo,npins,grid,pinwidth,pinwidth2,centercut)
  union {
     // plastic base without pins.
     IC_SMD_BASE((10.41+9.78)/2,
                 (9.40+8.38)/2,
                 (4.65+4.32)/2,
                 (15.37+15.11)/2,
                 0,0,4.57,4.57,0.75,0.75,0.5,0.075,0,0,0,6.5/2,1.5,0,logo)
     box {<-(10.41+9.78)/4,0.075,-(9.40+8.38)/4>
          <+(10.41+9.78)/4,(4.65+4.32)/4,+(9.40+8.38)/4>
          texture{col_ic_body_1} }


     // backside/cooling plate
     difference {
        union {
           box { <-(10.41+9.78)/4,0.05,(9.40+8.38)/4>
                 <+(10.41+9.78)/4,0.55,(9.40+8.38)/4+(1.587+1.485)/2> }
           box { <-7.62/2,0.05,8/2+1.27-8> <+7.62/2,0.55,9/2+0.1> }
           }
        box { <-3/2,0,-1> <+3/2,0.6,+1> translate <0,0,8> rotate<0,+35,0>}
        box { <-3/2,0,-1> <+3/2,0.6,+1> translate <0,0,8> rotate<0,-35,0>}

        box { <-1.5/2,0.0,+1.5/2> <+1.5/2,0.6,-1.5/2> translate<-3.7,0,+3.7>}
        box { <-1.5/2,0.0,+1.5/2> <+1.5/2,0.6,-1.5/2> translate<+3.7,0,+3.7>}
        texture{col_silver}
        }

     // pins
     difference {
        union {
           #local pin = union {
              object { TOOLS_RECT_BOGEN(0.5,100,0.5,pinwidth2,2.8,0.0) rotate <0,-90,180> translate <0,1.6-0.5/2,-6.5> }
              object { TOOLS_RECT_BOGEN(0.5,100,0.5,pinwidth2,2.0,0.0) rotate <0,90,   0> translate <0,    0.5/2,-6.4> }
              box { <-pinwidth/2,1.6-0.5,-5.7-0.6/2>
                    <+pinwidth/2,1.6    ,-5.7+2.6/2> }
              texture{col_silver}
              };
           GRID(pin, grid, npins, 1)
           }
        #if (centercut = 1)
            #local diff = box { <-pinwidth/2-0.3,-0.1,-10> <+pinwidth/2+0.3,2,-5.7> }
            object { diff }
        #end
        texture{col_silver}
        }

     translate <0,0,+2.54>
     }
#end
    



/*******************************************************************************
 * TO-263 2 pin; 2L Center Lead Trimmed (TO-263AA, TO-263AB or SOT404)
 * 20220503, full rewrite, wk
 ******************************************************************************/
#macro IC_SMD_TO263_2LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,3,2.54,1.25,0.75,1)
#end


/*******************************************************************************
 * TO-263 3 pin; 3L Center Lead NOT Trimmed
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_3LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,3,2.54,1.25,0.75,0)
#end


/*******************************************************************************
 * TO-263 4 pin; 5L Center Lead Trimmed
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_4LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,5,1.70,0.75,0.75,1)
#end


/*******************************************************************************
 * TO-263 5 pin; 5L Center Lead NOT Trimmed
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_5LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,5,1.70,0.75,0.75,0)
#end


/*******************************************************************************
 * TO-263 6 pin; 7L Center Lead Trimmed, ie. IPB180N06S4-H1
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_6LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,7,1.27,0.6,0.6,1)
#end


/*******************************************************************************
 * TO-263 7 pin; 7L Center Lead NOT Trimmed, ie. OPA552
 * 20220504, full rewrite, wk
 ******************************************************************************/
#macro IC_SMD_TO263_7LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,7,1.27,0.6,0.6,0)
#end







/*******************************************************************************
 *
 * IMPORTANT:  DO NOT USE ANYTHING BELOW FOR NEW DEVELOPMENT.
 *
 ******************************************************************************/


/*******************************************************************************
 * This is IC_SMD_TO263_2LEAD(), but moved in y.
 * diode.lbr:TO263AB
 *
 * deprecated package: DO NOT USE FOR NEW DEVELOPMENT.
 * 20220503, wk
 ******************************************************************************/
#macro IC_SMD_TO263_2LEAD_1(value,logo)
  object { IC_SMD_TO263_2LEAD(value,logo) translate<0,0,7.25> }
#end


/*******************************************************************************
 * This is IC_SMD_TO263_5LEAD(), but moved in y.
 * on-semiconductor.lbr:CAT4101
 *
 * deprecated package: DO NOT USE FOR NEW DEVELOPMENT.
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_5LEAD_1(value,logo)
  object { IC_SMD_TO263_5LEAD(value,logo) translate<0,0,-2.5> }
#end


/*******************************************************************************
 * This is IC_SMD_TO263_6LEAD(), but moved in y.
 * infineon.lbr:IPB180N06S4
 *
 * deprecated package: DO NOT USE FOR NEW DEVELOPMENT.
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_6LEAD_1(value,logo)
  object { IC_SMD_TO263_6LEAD(value,logo) translate<0,0,-3.5> }
#end


/*******************************************************************************
 * This is IC_SMD_TO263_7LEAD(), but moved in y.
 * infineon.lbr:TLE5205-2G
 *
 * deprecated package: DO NOT USE FOR NEW DEVELOPMENT.
 * 20220504, wk
 ******************************************************************************/
#macro IC_SMD_TO263_7LEAD_1(value,logo)
  object { IC_SMD_TO263_7LEAD(value,logo) translate<0,0,-3.5> }
#end
