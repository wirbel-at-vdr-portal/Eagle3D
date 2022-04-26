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


#macro IC_SMD_SSOP14(value,logo)
  IC_SMD_BASE(6.2,5.3,1.7,7.7,7,7,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.85,0,logo)
#end

#macro IC_SMD_SSOP16(value,logo)
  IC_SMD_BASE(6.2,5.3,1.7,7.7,8,8,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.85,0,logo)
#end

#macro IC_SMD_SSOP20(value,logo)
  IC_SMD_BASE(7.2,5.3,1.7,7.7,10,10,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end

#macro IC_SMD_SSOP24(value,logo)
  IC_SMD_BASE(8.2,5.3,1.7,7.7,12,12,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end

#macro IC_SMD_SSOP28(value,logo)
  IC_SMD_BASE(10.2,5.3,1.7,7.7,14,14,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end

#macro IC_SMD_SSOP30(value,logo)
  IC_SMD_BASE(10.2,6.1,1.2,8.1,15,15,0.65,0.65,0.24,0.24,0.15,0.1,0,1,0,0.5,0.95,0,logo)
#end

#macro IC_SMD_SSOP48(value,logo)
  IC_SMD_BASE(15.8,7.5,2.25,10.2,24,24,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end

#macro IC_SMD_SSOP56(value,logo)
  IC_SMD_BASE(23.7,13.3,2.25,10.2,28,28,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end

#macro IC_SMD_SSOP56DL(value,logo) // Joseph Zeglinski
  IC_SMD_BASE(18.4,7.5,2.25,10.2,28,28,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
