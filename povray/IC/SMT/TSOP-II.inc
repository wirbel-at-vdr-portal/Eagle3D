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


#macro IC_SMD_TSOPII28(value,logo)
  IC_SMD_BASE(18.4,10.1,1,11.7,14,14,1.27,1.27,0.4,0.4,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end

#macro IC_SMD_TSOPII32(value,logo)
  IC_SMD_BASE(20.95,10.1,1,11.7,16,16,1.27,1.27,0.4,0.4,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end

#macro IC_SMD_TSOPII44(value,logo)
  IC_SMD_BASE(18.3,10.1,1,11.7,22,22,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end

#macro IC_SMD_TSOPII50(value,logo)
  IC_SMD_BASE(20.95,10.1,1,11.7,25,25,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end

#macro IC_SMD_TSOPII54(value,logo)
  IC_SMD_BASE(22.22,10.1,1,11.7,27,27,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end

#macro IC_SMD_TSOPII86(value,logo)
  IC_SMD_BASE(22.22,10.1,1,11.7,43,43,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
