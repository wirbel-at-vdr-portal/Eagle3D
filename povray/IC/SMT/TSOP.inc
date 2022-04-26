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


// TSOP6 = JEDEC MO-193AA
#macro IC_SMD_TSOP6(value,logo)
  IC_SMD_BASE(2.9,1.6,0.9, 2.8, 3,3, 0.95,0.95, 0.4,0.4,0.2, 0.1,0, 1,0,0.3,0.6,0,logo)
#end

#macro IC_SMD_TSOP32(value,logo)
  IC_SMD_BASE(8,18.4,1.1,20,16,16,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end

#macro IC_SMD_TSOP48(value,logo)
  IC_SMD_BASE(12,18.4,1.1,20,24,24,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end

#macro IC_SMD_TSOP56(value,logo)
  IC_SMD_BASE(14,18.4,1.1,20,28,28,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end

#macro IC_SMD_TSOP86(value,logo)
  IC_SMD_BASE(22.22,10.16,1.2,11.76,43,43,0.5,0.5,0.2,0.2,0.12,0.1,0,2,0,3.9/5,3.9/5,0,logo)
#end




#macro IC_SMD_TSOP28_13MM(value,logo)
  IC_SMD_BASE(8,11.8,1,13.4,14,14,0.55,0.55,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end

#macro IC_SMD_TSOP32_13MM(value,logo)
  IC_SMD_BASE(8,11.8,1,13.4,16,16,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
