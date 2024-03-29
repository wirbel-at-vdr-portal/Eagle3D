/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * ERA print transformer, EI-core
 * Thomas Wiens <thomas.wiens at twiens.de>
 * 5.11.2004
 * value          = Beschriftungsdruck
 * breite         = Gesamtbreite des Gehaeuses
 * tiefe          = Gesamttiefe des Gehaeuses
 * abs_oben       = Abstand des kleinen Quaders von oben
 * abs_seite      = Abstand des kleinen Quaders von der Seite
 * druck_hoehe    = Hoehe des Beschriftungsdrucks
 * druck_text     = aufgedruckter Text
 * anz_laschen    = Anzahl der Befestigungslaschen
 * la_laenge      = Laenge der Lasche
 * la_breite      = Breite der Lasche
 * la_hoehe       = Hoehe der Lasche
 * la_lochabstand = Lochabstand der Bohrungen in der Lasche
 * la_lochdurchm  = Durchmesser der Laschenbohrungen,
 * trafo_pin_laenge = Laenge der Pins
 * pinabstand       = Abstand der Pins von Primae zu Sekundaer
 * pin_aus          = Pinabstand von Mittellinie nach aeusserster Pin
 * pin_in           = Pinabstand von Mittellinie zum inneren Pin
 * dia_schraube     = Durchmesser der Schraube (M2.5, M3 oder M4)
 ******************************************************************************/
#macro TRAFO_ERA_EI_BASE(value, breite, tiefe, hoehe, abs_oben, abs_seite, druck_hoehe,
       druck_text, anz_laschen, la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm,
       trafo_pin_laenge, pinabstand, pin_aus, pin_in, dia_schraube)

  // Makro: Abgerundeter Quader
  // Breite=B , Tiefe = T, Hoehe = H
  #macro TRAFO_ERA_EI_ROUNDED_BOX(B,T,H)
     union {
        #local rundung = 0.8; // Staerke der Abrundung am Gehaeuse
        box { <-B/2+rundung, 0,     T/2>     <B/2-rundung,H-rundung,-T/2>      rotate <0,0,0> translate <0,0,0> } //Grundkoerper
        box { <-B/2,     0,    -T/2+rundung> <B/2,    H-rundung, T/2-rundung>  rotate <0,0,0> translate <0,0,0> } //Kleine Box innen
        box { <-B/2+rundung, H-rundung,-T/2+rundung> <B/2-rundung,H    , T/2-rundung>  rotate <0,0,0> translate <0,0,0> } //Kleine Box oben
        cylinder { <-B/2+rundung,0,0> <-B/2+rundung, H-rundung> rundung rotate <0,0,0> translate <0, 0,  T/2-rundung> } //Rundungen rechts
        cylinder { <-B/2+rundung,0,0> <-B/2+rundung, H-rundung> rundung rotate <0,0,0> translate <0, 0, -T/2+rundung> } //Rundungen rechts
        cylinder { < B/2-rundung,0,0> < B/2-rundung, H-rundung> rundung rotate <0,0,0> translate <0, 0,  T/2-rundung> } //Rundungen links
        cylinder { < B/2-rundung,0,0> < B/2-rundung, H-rundung> rundung rotate <0,0,0> translate <0, 0, -T/2+rundung> } //Rundungen links
        sphere { < B/2-rundung, H-rundung, T/2-rundung> rundung scale <1,1,1> translate <0,0,0> }  //Rundungen oben
        sphere { < B/2-rundung, H-rundung,-T/2+rundung> rundung scale <1,1,1> translate <0,0,0> }  //Rundungen oben
        sphere { <-B/2+rundung, H-rundung, T/2-rundung> rundung scale <1,1,1> translate <0,0,0> }  //Rundungen oben
        sphere { <-B/2+rundung, H-rundung,-T/2+rundung> rundung scale <1,1,1> translate <0,0,0> }  //Rundungen oben
        cylinder { <-B/2+rundung, H-rundung> < B/2-rundung, H-rundung> rundung rotate <0,0,0> translate <0, 0, T/2-rundung> }   //Rundungen vorne
        cylinder { <-B/2+rundung, H-rundung> < B/2-rundung, H-rundung> rundung rotate <0,0,0> translate <0, 0,-T/2+rundung> }   //Rundungen hinten
        cylinder { <-T/2+rundung, H-rundung> < 0, H-rundung> rundung rotate <0, 90,0> translate <-B/2+rundung, 0, 0> }  //Rundungen rechts kurz
        cylinder { <-T/2+rundung, H-rundung> < 0, H-rundung> rundung rotate <0,-90,0> translate <-B/2+rundung, 0, 0> }  //Rundungen rechts kurz
        cylinder { <-T/2+rundung, H-rundung> < 0, H-rundung> rundung rotate <0, 90,0> translate < B/2-rundung, 0, 0> }  //Rundungen links kurz
        cylinder { <-T/2+rundung, H-rundung> < 0, H-rundung> rundung rotate <0,-90,0> translate < B/2-rundung, 0, 0> }  //Rundungen links kurz
        }
  #end

  // Makro fuer die Befestigungslaschen der groesseren Transformatoren
  // Gesamtlaenge = ges_l, Breite, Hoehe der Platte, Lochabstand = hole_dist, Lochdurchmesser = hole
  #macro TRAFO_ERA_EI_BEF_LASCHE(ges_l, breite, hoehe, hole_dist, hole)
     #local D = 0.001;
     union {
        difference {
           box { <- breite/2, 0, - ges_l/2> < breite/2, hoehe, ges_l/2>      rotate <0,0,0> translate <0 ,0,0> }
           union { 
           cylinder { <0, -D, 0> , <0, hoehe + D, 0>, hole/2 translate <0,0,hole_dist/2>  }
           cylinder { <0, -D, 0> , <0, hoehe + D, 0>, hole/2 translate <0,0,- hole_dist/2>  }
           }
        }
     // Versteifungen
     prism {
        -hoehe/2, hoehe/2, 4
        < 0.00, 0.00>,
        < 10.00, 0.00>,
        < 0.00, 20.00>,
        < 0.00, 0.00>
        rotate <-90,90,0>
        translate <breite/2 - hoehe /2 ,0,-ges_l/2 + 10.0>
        }
     prism {
        -hoehe/2, hoehe/2, 4
        < 0.00, 0.00>,
        < 10.00, 0.00>,
        < 0.00, 20.00>,
        < 0.00, 0.00>
        rotate <-90,90,0>
        translate <-breite/2 + hoehe /2,0,-ges_l/2 + 10.0>
        }
     prism {
        -hoehe/2, hoehe/2, 4
        < 0.00, 0.00>,
        < 10.00, 0.00>,
        < 0.00, 20.00>,
        < 0.00, 0.00>
        rotate <-90,-90,0>
        translate <breite/2 - hoehe /2,0, ges_l/2 - 10.0>
        }
     prism {
        -hoehe/2, hoehe/2, 4
        < 0.00, 0.00>,
        < 10.00, 0.00>,
        < 0.00, 20.00>,
        < 0.00, 0.00>
        rotate <-90,-90,0>
        translate <-breite/2 + hoehe /2,0,ges_l/2 - 10.0>
        }
     }
  #end

  // Schraube M2,5, M3 oder M4 mit Mutter
  #macro TRAFO_ERA_EI_SCHRAUBE (RotY, Gewinde, Hoe_Kopf, Hoe_Mutt)
     #if (Gewinde = 2.5) #local SW = 4.0; #local Height = 2.0; #end
     #if (Gewinde = 3.0) #local SW = 5.5; #local Height = 2.5; #end
     #if (Gewinde = 4.0) #local SW = 7.0; #local Height = 3.0; #end
     union {
        union {
           // Kopf mit Kreuzschlitz
           difference {
              union {
                 cylinder {
                    <0, 0.1, 0>, <0, Gewinde / 2 - 0.05, 0>, SW / 2
                    }
                 sphere {
                    0, SW / 2 scale <1, 0.5, 1>
                    translate (Gewinde / 2 - 0.05 )* y
                    }
                 torus {
                    SW / 2 - 0.1, 0.1
                    translate 0.1 * y
                    }
                 cylinder {
                    <0, 0.0, 0>, <0, 0.1, 0>, SW / 2 - 0.1
                    }
                 cylinder {
                    <0, 0.0, 0>, <0, -(Hoe_Kopf + Hoe_Mutt + Height + 0.5), 0>, Gewinde / 2 - 0.05
                    }
                 }
              box {
                 <-0.4, 0, 0>, <+0.4, 5, 5>
                 rotate -45 * x
                 translate 0.5 * y
                 }
              box {
                 <0, 0, -0.4>, <+5, 5, +0.4>
                 rotate 45 * z
                 translate 0.5 * y
                 }
              }
           texture {
              pigment {
                 rgb 0.5
                 }
              finish {
                 phong 0.6
                 phong_size 7
                 reflection 0.3
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           translate <0, Hoe_Kopf, 0>
           // Gesamtposition
           rotate RotY * y
           }
           // Mutter
        intersection {
           prism {
              linear_spline
              linear_sweep
              0, -Height, 7
              < 0, +sqrt(1 / 3) * 2>,
              <+1, +sqrt(1 / 3)>,
              <+1, -sqrt(1 / 3)>,
              < 0, -sqrt(1 / 3) * 2>,
              <-1, -sqrt(1 / 3)>,
              <-1, +sqrt(1 / 3)>,
              < 0, +sqrt(1 / 3) * 2>
              scale <SW / 2, 1, SW / 2>
              }
           cylinder {          // Innen
              <0, 2, 0>, <0, -(Height + 5), 0>,
              Gewinde / 2 + 0.1
              inverse
              }
           texture {
              pigment {rgb 0.5}
              finish {
                 phong 0.6
                 phong_size 7
                 reflection 0.3
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           translate <0, -Hoe_Mutt, 0>
           }
        }
  #end

  union {
     union {
        object {
           TRAFO_ERA_EI_ROUNDED_BOX (breite, tiefe, hoehe - abs_oben)
           } // Quader ohne Aufsatz
        object {
           TRAFO_ERA_EI_ROUNDED_BOX (breite - abs_seite, tiefe - abs_seite, hoehe)
           } // Aufsatz
        // Befestigungslaschen; falls vorhanden
        #if (anz_laschen = 1)
           object {
              TRAFO_ERA_EI_BEF_LASCHE ( la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm)
              }
        #end
        #if (anz_laschen = 2)
           object {
              TRAFO_ERA_EI_BEF_LASCHE ( la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm)
              translate < -tiefe/2 + la_breite, 0, 0>
              }
           object {
              TRAFO_ERA_EI_BEF_LASCHE ( la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm)
              translate <  tiefe/2 - la_breite, 0, 0>
              }
        #end

        texture {
           pigment {
              Blue
              }
           normal {
              bumps 0.02
              //scale 0.002
              }
           finish {
              ambient (0.15 * global_ambient_mul)
              diffuse 0.85
              phong 0.4
              phong_size 40
              reflection 0.01
              }
           }
        }
     // Schrauben
     #if (anz_laschen = 1)
        object {
           TRAFO_ERA_EI_SCHRAUBE( +30, dia_schraube, la_hoehe, pcb_height)
           translate <0, 0, la_lochabst / 2>
           }
        object {
           TRAFO_ERA_EI_SCHRAUBE( +30, dia_schraube, la_hoehe, pcb_height)
           translate <0, 0, -la_lochabst / 2>
           }
     #end
     #if (anz_laschen = 2)
        object {
           TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height)
           translate < tiefe/2 - la_breite, 0, la_lochabst / 2>
           }
        object {
           TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height)
           translate <-tiefe/2 + la_breite, 0, la_lochabst / 2>
           }
        object {
           TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height)
           translate < tiefe/2 - la_breite, 0, -la_lochabst / 2>
           }
        object {
           TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height)
           translate <-tiefe/2 + la_breite, 0, -la_lochabst / 2>
           }
     #end

     // Anschlussbeine
     #if(pin_short=on)
        #local trafo_pin_length = -1 * (pin_length+pcb_height);
     #else
        #local trafo_pin_length = -trafo_pin_laenge;
     #end

     cylinder { <-pinabstand/2 ,0, pin_aus> <-pinabstand/2,trafo_pin_length, pin_aus> 0.40 texture {col_silver} } // Draht links  prim1
     cylinder { < pinabstand/2 ,0, pin_aus> < pinabstand/2,trafo_pin_length, pin_aus> 0.40 texture {col_silver} } // Draht rechts sek1
     cylinder { < pinabstand/2 ,0,  pin_in> < pinabstand/2,trafo_pin_length,  pin_in> 0.40 texture {col_silver} } // Draht rechts sek1
     cylinder { < pinabstand/2 ,0, -pin_in> < pinabstand/2,trafo_pin_length, -pin_in> 0.40 texture {col_silver} } // Draht rechts sek2
     cylinder { < pinabstand/2 ,0,-pin_aus> < pinabstand/2,trafo_pin_length,-pin_aus> 0.40 texture {col_silver} } // Draht rechts sek2
     cylinder { <-pinabstand/2 ,0,-pin_aus> <-pinabstand/2,trafo_pin_length,-pin_aus> 0.40 texture {col_silver} } // Draht rechts prim1
     // Beschriftung
     text {
        ttf besch_font "era" 0.1, 0
        scale <druck_hoehe, druck_hoehe, druck_hoehe>
        pigment { White }
        rotate <0,90,0>
        translate <-breite/2 - 0.01 , hoehe - abs_oben - 2* druck_hoehe , tiefe/2 - druck_hoehe>
        } //Beschriftung era
     text {
        ttf besch_font druck_text 0.1, 0
        scale <druck_hoehe, druck_hoehe, druck_hoehe>
        pigment { White }
        rotate <0,90,0>
        translate <-breite/2 - 0.01 , hoehe - abs_oben - 3* druck_hoehe,  tiefe/2 - druck_hoehe>
        } //Beschriftung Typ 
     text {
        ttf besch_font value 0.1, 0
        scale <druck_hoehe, druck_hoehe, druck_hoehe>
        pigment { White }
        rotate <0,90,0>
        translate <-breite/2 - 0.01 , hoehe - abs_oben - 4* druck_hoehe,  tiefe/2 - druck_hoehe>
        } //Beschriftung Value
     } 
#end


// Printtransformator era EI30/23 2,8VA
#macro TRAFO_ERA_EI_30_2(value)
  TRAFO_ERA_EI_BASE(value, 27.5, 32.5, 34.0, 4, 10, 3.0, "Typ EI 30/23",
     0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 20.0, 10.0, 5.0, 4.0)
#end

// Printtransformator era EI38/13,6 3,2VA
#macro TRAFO_ERA_EI_38_2(value)
  TRAFO_ERA_EI_BASE(value, 35.5, 42.0, 28.0, 5, 12, 3.0, "Typ EI 38/13,6",
     0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 25.0, 10.0, 5.0, 4.0)
#end

// Printtransformator era EI42/14,8 5VA
#macro TRAFO_ERA_EI_42_2(value)
  TRAFO_ERA_EI_BASE(value, 38.5, 45.5, 32.0, 6, 13, 3.5, "Typ EI 42/14,8",
     0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 25.0, 12.5, 7.5, 4.0)
#end

// Printtransformator era EI42/14,8 5VA mit Befestigungslasche
#macro TRAFO_ERA_EI_42_2B(value)
  TRAFO_ERA_EI_BASE(value, 38.5, 45.5, 32.0, 6, 13, 3.5, "Typ EI 42/14,8",
     1, 64.0, 10.0, 2.0, 55.0, 4.2, 3.5, 25.0, 12.5, 7.5, 4.0)
#end

// Printtransformator era EI48/15,8 10VA
#macro TRAFO_ERA_EI_48_2(value)
  TRAFO_ERA_EI_BASE(value, 42.5, 50.5, 34.5, 6, 14, 4.0, "Typ EI 48/15,8",
     0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 27.5, 12.5, 7.5, 4.0)
#end

// Printtransformator era EI48/15,8 10VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_48_2B(value)
  TRAFO_ERA_EI_BASE(value, 42.5, 50.5, 34.5, 6, 14, 4.0, "Typ EI 48/15,8",
     1, 69.0, 10.0, 2.0, 60.0, 4.2, 3.5, 27.5, 12.5, 7.5, 4.0)
#end

// Printtransformator era EI54/18,8 16VA
#macro TRAFO_ERA_EI_54_2(value)
  TRAFO_ERA_EI_BASE(value, 48.0, 57.0, 39.0, 7, 16, 4.0, "Typ EI 54/18,8",
     0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 30.0, 15.0, 10.0, 4.0)
#end

// Printtransformator era EI54/18,8 16VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_54_2B(value)
  TRAFO_ERA_EI_BASE(value, 48.0, 57.0, 39.0, 7, 16, 4.0, "Typ EI 54/18,8",
     2, 75.3, 10.0, 2.0, 65.0, 4.2, 4.5, 30.0, 15.0, 10.0, 4.0)
#end

// Printtransformator era EI60/25,5 25VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_60_2(value)
  TRAFO_ERA_EI_BASE(value, 55.0, 66.0, 49.2, 9, 21, 4.0, "Typ EI 60/23",
     2, 81.5, 11.2, 2.0, 72.5, 4.2, 4.5, 32.5, 15.0, 10.0, 4.0)
#end

// Printtransformator era EI66/23 36VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_66_2(value)
  TRAFO_ERA_EI_BASE(value, 61.0, 71.0, 48.5, 9, 21, 4.0, "Typ EI 66/23",
     2, 87.2, 10.8, 2.0, 77.5, 4.2, 4.5, 35.0, 17.5, 12.5, 4.0)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=TRAFO_ERA_EI_30_2(:Transformer EI core 30-2 (trafo.lib)
//=TRAFO_ERA_EI_38_2(:Transformer EI core 38-2 (trafo.lib)
//=TRAFO_ERA_EI_42_2(:Transformer EI core 42-2 (trafo.lib)
//trafo:EI42-2B=TRAFO_ERA_EI_42_2B(:Transformer EI core 42-2B (trafo.lib)
//=TRAFO_ERA_EI_48_2(:Transformer EI core 48-2 (trafo.lib)
//trafo:EI48-2B=TRAFO_ERA_EI_48_2B(:Transformer EI core 48-2B (trafo.lib)
//=TRAFO_ERA_EI_54_2(:Transformer EI core 54-2 (trafo.lib)
//trafo:EI54-2B=TRAFO_ERA_EI_54_2B(:Transformer EI core 54-2B (trafo.lib)
//=TRAFO_ERA_EI_60_2(:Transformer EI core 60-2 (trafo.lib)
//=TRAFO_ERA_EI_66_2(:Transformer EI core 66-2 (trafo.lib)
// end assignment
