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


#macro IC_SMD_SOT23(value,logo)
  IC_SMD_BASE(2.9,1.3,1,2.8,2,1,1.9  ,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end

#macro IC_SMD_SOT23_5(value,logo)
  IC_SMD_BASE(2.9,1.6,1,2.8,3,2,0.95,1.9,0.35,0.35,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end

#macro IC_SMD_SOT23_6(value,logo)
  IC_SMD_BASE(2.9,1.6,1,2.8,3,3,0.95,0.95,0.35,0.35,0.13,0.1,0,1,0,0.3,0.7,0,logo)
#end
