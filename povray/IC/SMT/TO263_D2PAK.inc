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

#macro IC_SMD_TO263_BASE(value,logo,npins,grid,pinwidth,centercut)
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





//SMD-Transistoren aus SIC_GRND abgeleitet

#macro IC_TR_TO263(value,logo)
  IC_SMD_BASE(  //10.2,8.7,4.2,15.2,2,1,5.1,1.9,1.4,10.2,0.5,0.1,0,0,0,1.5,1.0,0,
              10.05,8.635,4.18,15.4,
              1,3,
              (2.67+2.41)/2,(2.67+2.41)/2,
              (0.94+0.69)/2,(9.65+6.22)/2,
               0.5,
               0.005,
               0,
               4,
               0,
               1,
               1,
               0,

        logo)
#end

/*
TO263:0:1:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:1:0:0:0:0:0:0:0:0:0:0:IC_TR_TO263(:TO263:
TO263-3:0:1:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:1:0:0:0:0:0:0:0:0:0:0:IC_TR_TO263(:TO263:

 	

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



/*******************************************************************************
 * 2 pin, short middle cut off
 * https://www.infineon.com/cms/en/product/packages/PG-TO252/PG-TO252-3-11/
 * fdd4141-348236.pdf
 ******************************************************************************/
#macro IC_SMD_TO263_2S(value,logo)
  IC_SMD_BASE(value,logo,3,2.29,0.75,1)
#end


/*******************************************************************************
 * 3 pin
 * https://www.infineon.com/cms/en/product/packages/PG-TO252/PG-TO252-3-11/
 * fdd4141-348236.pdf
 ******************************************************************************/
//#macro IC_SMD_TO252_3(value,logo)
//   IC_SMD_TO252_BASE(value,logo,3,2.29,0.75,1)
//#end

/*******************************************************************************
 * 5 pin
 * https://www.infineon.com/dgdl/PG-TO252-5-13-PO.eps?fileId=5546d462580663ef015807046a6f1080
 ******************************************************************************/
//#macro IC_SMD_TO252_5(value,logo)
//   IC_SMD_TO252_BASE(value,logo,5,1.14,0.6,1)
//#end

/*******************************************************************************
 * 5 pin, moved by 0.833mm in y
 ******************************************************************************/
//#macro IC_SMD_TO252_5_11(value,logo)
//   object { IC_SMD_TO252_5(value,logo) translate<0,0,-0.833> }
//#end

/*******************************************************************************
 * TO-252-5-P2, as IC_SMD_TO252_5, but with center pin.
 ******************************************************************************/
//#macro IC_SMD_TO252_5_P2(value,logo)
//   IC_SMD_TO252_BASE(value,logo,5,1.14,0.6,0)
//#end
