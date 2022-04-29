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


// https://www.infineon.com/cms/en/product/packages/PG-SOT223/PG-SOT223-3-1
// 3 terminal version. 20220429, wk
#macro IC_SMD_SOT223_3(value,logo)
  IC_SMD_BASE(6.5,3.5,1.66,7,2,1,4.6,2.3,0.70,3,0.25,0.25,0,0,0,0,1.0,0,logo)
#end

// similar to
// https://www.infineon.com/cms/en/product/packages/PG-SOT223/PG-SOT223-4-33/
#macro IC_SMD_SOT223(value,logo) // 4 terminal version
  IC_SMD_BASE(6.5,3.5,1.6,7,3,1,2.3,2.3,0.75,3,0.2,0.2,0,0,0,0,1.0,0,logo)
#end

// https://en.wikipedia.org/wiki/Small-outline_transistor#SOT223-5
// 5 terminal version. 20220429, wk
#macro IC_SMD_SOT223_5(value,logo)
  IC_SMD_BASE(6.5,3.5,1.66,7,4,1,1.27,1.27,0.46,3,0.25,0.25,0,0,0,0,1.0,0,logo)
#end

// https://en.wikipedia.org/wiki/Small-outline_transistor#SOT223-8
// 8 terminal version. 20220429, wk
#macro IC_SMD_SOT223_8(value,logo)
  IC_SMD_BASE(6.6,3.5,1.66,7,4,4,1.53,1.53,0.8,0.8,0.25,0.25,0,0,0,0,1.0,0,logo)
#end
