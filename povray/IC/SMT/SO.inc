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


#macro IC_SMD_SO8(value,logo)
  IC_SMD_BASE(4.9,3.9,1.35,6,4,4,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/5,0,logo)
#end

#macro IC_SMD_SO14(value,logo)
  IC_SMD_BASE(8.65,3.9,1.35,6,7,7,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/4,0,logo)
#end

#macro IC_SMD_SO16(value,logo)
  IC_SMD_BASE(9.9,3.9,1.35,6,8,8,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/4,0,logo)
#end

//---

#macro IC_SMD_SO16W(value,logo)
  IC_SMD_BASE(10.3,7.5,2.35,10.3,8,8,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end

#macro IC_SMD_SO18W(value,logo)//Rudi Hofer <rudi.hofer@t-online.de>
IC_SMD_BASE(11.6,7.5,2.35,10.3,9,9,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end

#macro IC_SMD_SO20W(value,logo)
IC_SMD_BASE(12.8,7.5,2.35,10.3,10,10,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end

#macro IC_SMD_SO24W(value,logo)
IC_SMD_BASE(15.4,7.5,2.35,10.3,12,12,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end

#macro IC_SMD_SO28W(value,logo)
IC_SMD_BASE(17.9,7.5,2.35,10.3,14,14,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end

//---

#macro IC_SMD_SO32_400(value,logo)
IC_SMD_BASE(20.5,7.5,2.35,10.3,16,16,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end

#macro IC_SMD_SO32_525(value,logo)
IC_SMD_BASE(20.5,11.43,2.74,14.12,16,16,1.27,1.27,0.4,0.4,0.2,0.05,0,1,1,7.5/5,7.5/5,0,logo)
#end
