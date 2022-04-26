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


#macro IC_SMD_TSSOP8(value,logo)
  IC_SMD_BASE(2.9,4.4,1,6.4,4,4,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.6,1,logo)
#end

#macro IC_SMD_TSSOP14(value,logo)
  IC_SMD_BASE(5,4.4,1.1,6.375,7,7,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.8,0,logo)
#end

#macro IC_SMD_TSSOP16(value,logo)
  IC_SMD_BASE(5.2,4.4,1.1,6.375,8,8,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.8,0,logo)
#end

#macro IC_SMD_TSSOP20(value,logo)
  IC_SMD_BASE(6.5,4.4,1.1,6.375,10,10,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.0,0,logo)
#end

#macro IC_SMD_TSSOP24(value,logo)
  IC_SMD_BASE(7.8,4.4,1.1,6.375,12,12,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end

#macro IC_SMD_TSSOP28(value,logo)
  IC_SMD_BASE(9.7,4.4,1.1,6.375,14,14,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end

#macro IC_SMD_TSSOP38(value,logo)
  IC_SMD_BASE(9.7,4.4,1.1,6.4,19,19,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end

#macro IC_SMD_TSSOP48(value,logo)
  IC_SMD_BASE(12.5,6.1,0.95,8.1,24,24,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end

#macro IC_SMD_TSSOP56(value,logo)
  IC_SMD_BASE(14,6.1,0.95,8.1,28,28,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
