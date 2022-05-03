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
 *
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
          texture{e3d_tex_ic_body_1} }


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
        texture{e3d_tex_silver}
        }

     // pins
     difference {
        union {
           #local pin = union {
              object { TOOLS_RECT_BOGEN(0.5,100,0.5,pinwidth2,2.8,0.0) rotate <0,-90,180> translate <0,1.6-0.5/2,-6.5> }
              object { TOOLS_RECT_BOGEN(0.5,100,0.5,pinwidth2,2.0,0.0) rotate <0,90,   0> translate <0,    0.5/2,-6.4> }
              box { <-pinwidth/2,1.6-0.5,-5.7-0.6/2>
                    <+pinwidth/2,1.6    ,-5.7+2.6/2> }
              texture{e3d_tex_silver}
              };
           GRID_BASE(pin, grid, npins, 1)
           }
        #if (centercut = 1)
            #local diff = box { <-pinwidth/2-0.3,-0.1,-10> <+pinwidth/2+0.3,2,-5.7> }
            object { diff }
        #end
        texture{e3d_tex_silver}
        }

     translate <0,0,+2.54>
     }
#end
    



/*******************************************************************************
 * TO-263 3 pin; 2L Center Lead Trimmed (TO-263AA, TO-263AB or SOT404)
 * 20220503, full rewrite, wk
 ******************************************************************************/
#macro IC_SMD_TO263_3LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,3,2.54,1.25,0.75,1)
#end



/*******************************************************************************
 * TO-263 7 pin; 7L Center Lead NOT Trimmed
 * 20220503, full rewrite, wk
 ******************************************************************************/
#macro IC_SMD_TO263_7LEAD(value,logo)
  IC_SMD_TO263_BASE(value,logo,7,1.27,0.6,0.6,0)
#end









/*******************************************************************************
 * This is IC_SMD_TO263_3LEAD(), but moved in y by 7.25 mm.
 * diode.lbr:TO263AB
 *
 * deprecated package, part no longer available.
 * DO NOT USE FOR NEW DEVELOPMENT.
 * 20220503, wk
 ******************************************************************************/
#macro IC_SMD_TO263AB_3LEAD(value,logo)
  object { IC_SMD_TO263_3LEAD(value,logo) translate<0,0,7.25> }
#end


/*******************************************************************************
 * This is IC_SMD_TO263_7LEAD(), but moved in y by 7.25 mm.
 * diode.lbr:TO263AB
 *
 * deprecated package, part no longer available.
 * DO NOT USE FOR NEW DEVELOPMENT.
 * 20220503, wk
 ******************************************************************************/
#macro IC_SMD_TO263_3LEAD_1(value,logo)
  IC_SMD_TO263_BASE(value,logo,7,1.27,0.6,0.6,0)
#end





















/*

OK  : diode.lbr:4963:                    package: 'TO263AB'            description: 'DIODEPackage: TO263AB'                                                                devices: BY229B,
nOK : infineon.lbr:1485:                 package: 'P-TO263-7-1'        description: 'Plastic Transistor Single Outline Package P-TO263-7-1 Option E3180Source: www.infineon.com .. tle5205-2.pdf'devices: TLE5205-2,
nOK : infineon.lbr:1693:                 package: 'PG-TO263-7-3'       description: 'PG-TO263-7-3Source: 1859075.pdf (Farnell)'                                            devices: IPB180N06S4-H1,
nOK : led.lbr:2863:                      package: 'P-TO263-7-1'        description: 'P-TO263-7-1 (Plastic Transistor Single Outline)Source: Infineon .. tle4242.pdf'       devices: TLE4242,
nOK : linear.lbr:2275:                   package: 'TO263-3'            description: 'TO-263 3-Lead Plastic Surface Mount Package NS Package Number TS3BSource. cache.national.com/ds/LM/LM2937-2.5.pdf'devices: LM340?-*,LM2937,
nOK : on-semiconductor.lbr:156:          package: 'TO263_5'            description: 'TO-263 5-LEAD (TV)Source: ON Semiconductor .. 4101.pdf'                               devices: CAT4101,
nOK : transistor-fet.lbr:965:            package: 'TO263'              description: 'SMALL OUTLINE TRANSISTORTS-005'                                                       devices: SPB80P06P,


https://www.topline.tv/DPAK_D2PAK.html
TO-263-4  4L Center Lead Trimmed SOT426
TO-263-5  5L Full 5 Leads Untrimmed 1.27mm
TO-263-7     Center Lead Trimmed SOT427
TO-263-7F 7L Full 7 Leads Untrimmed 0.85mm
 	

    TO-263-X1X2 (where X1 is the lead count and X2 is the length of the centre pin).
             ^^ nothing: middle lead
                short cut off: S

TO-263 (Transistor Outline 263, JEDEC)
TO-263AB (TO-263-3S only)
TO-279 (TO-263 THIN only, by Texas Instruments)

Variants

    TO-263-X1X2 (where X1 is the lead count and X2 is the length of the centre pin).
    TO-263 THIN (a thinner variant of the standard TO-263 package by Texas Instruments).

Pin Count
  Depends on variant.
  3, 5, 7, or 9 (this is X1). All packages also have a thermal pad.
Pitch
  Depends on variant.
  TO-263-3, TO-263-3S: 2.54mm

    TO-263-7, TO-263-7S: 1.7mm

Package LxWxH
Height:

    All except TO-263 THIN: 4.57mm
    TO-263 THIN: 2.00mm





diode.lbr:4963:                    package: 'TO263AB'            description: 'DIODEPackage: TO263AB'                                                                devices: BY229B,
infineon.lbr:1485:                 package: 'P-TO263-7-1'        description: 'Plastic Transistor Single Outline Package P-TO263-7-1 Option E3180Source: www.infineon.com .. tle5205-2.pdf'devices: TLE5205-2,
infineon.lbr:1693:                 package: 'PG-TO263-7-3'       description: 'PG-TO263-7-3Source: 1859075.pdf (Farnell)'                                            devices: IPB180N06S4-H1,
led.lbr:2863:                      package: 'P-TO263-7-1'        description: 'P-TO263-7-1 (Plastic Transistor Single Outline)Source: Infineon .. tle4242.pdf'       devices: TLE4242,
linear.lbr:2275:                   package: 'TO263-3'            description: 'TO-263 3-Lead Plastic Surface Mount Package NS Package Number TS3BSource. cache.national.com/ds/LM/LM2937-2.5.pdf'devices: LM340?-*,LM2937,
on-semiconductor.lbr:156:          package: 'TO263_5'            description: 'TO-263 5-LEAD (TV)Source: ON Semiconductor .. 4101.pdf'                               devices: CAT4101,
transistor-fet.lbr:965:            package: 'TO263'              description: 'SMALL OUTLINE TRANSISTORTS-005'                                                       devices: SPB80P06P,

*/

