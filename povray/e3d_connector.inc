/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/********************************************************************************************************************************************
//AK-700 Klemme ohne Mittelanschluss RM 5.0 Uwe Lorenz <u.lorenz@er-dresden.net>
********************************************************************************************************************************************/
#macro CON_AK700_3_5_BASE()
union {
cylinder{<-5,-4,0><-5,1.1,0>0.6 texture{col_silver}}
cylinder{<5,-4,0><5,1.1,0>0.6 texture{col_silver}}
//  Grundkoerper
difference {
box{<-7.5,0,-5><7.5,19,5>}
// mittlerer Anschluss
box{<-2,3.9,-5.01><2,9.5,3.5>}
// linker Anschluss
box{<-6.5,3.9,-5.01><-2.5,9.5,3.5>}
// rechter Anschluss
box{<2.5,3.9,-5.01><6.5,9.5,3.5>}
//  vordere Schraege
box{<-7.6,9,-6.0><7.6,25,-1.1> rotate<20,0,0> translate<0,0,-8.7>}
//  hintere Kante
box{<-7.6,10,3><7.6,19.1,5.1> }
//  Aussparungen hinten
box{<-1.4,6,3.4><1.4,10.1,5.1> }
box{<-6.2,6,3.4><-3.1,10.1,5.1> }
box{<3.1,6,3.4><6.2,10.1,5.1> }
//  mittleres Borhloch
cylinder{<0,15.9,0><0,19.1,0>1.8}
//  linkes Borhloch
cylinder{<-5,15.9,0><-5,19.1,0>1.8}
//  rechtes Borhloch
cylinder{<5,15.9,0><5,19.1,0>1.8}
//  Nut an der rechten Seite
box{<7.0,0.0,-3.4><7.6,13.0,-4.0> }
}
//  Ende Grundkoerper
//
//  Steg an der linken Seite
box{<-7.4,1.0,-3.4><-8.0,13.0,-4.0> }
//  Silberfahnen hinten
box{<-6.0,6,3.8><-3.4,9.1,4.5> texture{col_silver} }
box{<3.4,6,3.8><6.0,9.1,4.5> texture{col_silver} }
//Silberknubbeln an den Silberfahnen
box{<-5.4,6.3,3.8><-4.0,7.3,4.8> texture{col_silver} }
box{<4.0,6.3,3.8><5.4,7.3,4.8> texture{col_silver} }
//  Ende hintere Silberfahnen
//
//  rechter Schraubenkopf
difference {
superellipsoid{<1,0.1> rotate<90,0,0> scale<1.5,0.5,1.5> texture{col_silver} translate<-5,18.2,0>}
box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> texture{col_silver} translate<-5,18.2,0>}}
//  linker Schraubenkopf
difference {
superellipsoid{<1,0.1> rotate<90,0,0> scale<1.5,0.5,1.5> texture{col_silver} translate<5,18.2,0>}
box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> texture{col_silver} translate<5,18.2,0>}}
//  Ende Schraubenkoepfe
//
//  linke Zugbuegelklemme
difference {
box{<-6.4,4.1,-3.5><-2.6,9.4,2.5>}
box{<-6.2,4.2,-3.6><-2.8,9.4,2.6>}
texture{col_silver}}
cylinder{<-5.8,9.0,-3.3><-3.1,9.0,-3.3>1.0 texture{col_silver}}
//  rechte Zugbuegelklemme
difference {
box{<2.6,4.1,-3.5><6.4,9.4,2.5>}
box{<2.8,4.2,-3.6><6.2,9.4,2.6>}
texture{col_silver}}
cylinder{<3.2,9.0,-3.3><5.8,9.0,-3.3>1.0 texture{col_silver}}
//  Ende Zugbuegelklemme
//
pigment{LimeGreen} translate<0,0.2,0>}
#end

#macro CON_AK700_3_5()
CON_AK700_3_5_BASE()
#end



/********************************************************************************************************************************************
//DC-Power-Connector by Nigel Eke
********************************************************************************************************************************************/
#macro CON_DCPOWERCONNECTOR_BASE()
  #local endcutaway = union { cylinder { <10,5,3> <11.01,5,3> 3.01 }
                              box { <10,1.99,-.01> <11.01,5,6.01> }
                              box { <10,-.01,2> <11.01,2.01,4> }
                              pigment { Gray20} }
  #local innercutaway = cylinder { <-.01,5,3> <9,5,3> 2 pigment { Gray75} }
  #local housing_rough = union { box { <0,0,0> <2,8,6> }
                                 cylinder { <2,5,3> <11,5,3> 3 }
                                 box { <2,0,0> <11,5,6> }
                                 pigment { Gray20 }
                                 finish { Shiny  ambient (0.1 * global_ambient_mul)} }
  #local housing_refined = difference { object { housing_rough }
                                        object { endcutaway }
                                        object { innercutaway } }
  #local innerconnector = union { cylinder { <1,5,3> <8.5,5,3> .25 }
                                  cylinder { <8.5,5,3> <9,5,3> .75 }
                                   texture { Silver_Metal } }
  #local pin = box { <-1,-4,-.25> <1,3.5,.25> texture { Silver_Metal } }
  #local endconnector = difference { union { cylinder { <0,0,-.25><0,0,.25> 2 }
                                             cylinder { <0,0,-.99><0,0,.7> .8 } }
                                     cylinder { <0,0,-1> <0,0,.71> .6 }
                                     texture { Silver_Metal }
                                     translate <0,5,0> }

  union { object { housing_refined }
          object { innerconnector }
          object { pin rotate<0,90,0> translate<6,0,3> }
          object { pin translate<8,0,1> }
          union { difference { object { pin }
                               cylinder { <0,2,-.26> <0,2,.26> .2
texture { Silver_Metal} } }
                  object { endconnector }
                  rotate<0,90,0>
                  translate<10,0,3> } }

  translate<-5.5,0,-3>
  rotate<0,-90,0>
  scale 2.54/2
#end
#macro CON_DCPOWERCONNECTOR()
CON_DCPOWERCONNECTOR_BASE()
#end

/*******************************************************************************
 * similar to CON_DCPOWERCONNECTOR
 ******************************************************************************/
#macro CON_DC21MM()
  union {
     difference {
        union {
           Round_Box( <-9/2,0,-7.5>, <9/2,11,-7.5+3>, 0.5, 0 )
           Round_Box( <-9/2,0,-7.5>, <9/2,6.5,3.2+2.5/2>, 0.5, 0 )
           cylinder { <0,6.5,-7.5> <0,6.5,3.2+2.5/2> 4.5 }
           box { <-8.8/2,0,3.2+2.5/2> <8.8/2,6.5,-7.5+14.2> }
           cylinder { <0,6.5,3.2+2.5/2> <0,6.5,-7.5+14.2> 4.4 }
           }
        box { <-9/2,3.5,-7.5+13.2> <9/2,11.2,-7.5+14.3> }
        box { <-2.5/2,-0.1,-7.5+13.2> <2.5/2,4,-7.5+14.3> }
        cylinder { <0,6.5,-8> <0,6.5,-7.5+10> 5.5/2 }
        pigment { Gray20 } finish { Shiny  ambient (0.1 * global_ambient_mul) }
        }
     union {
        cylinder { <0,6.5,-1.0> <0,6.5,3.2+2.5/2> 2.1/2 }
        sphere   { <0,6.5,-1.0> 2.1/2 }
        cylinder { <0,6.5,3.2+2.8-0.5/2> <0,6.5,3.2+2.8+0.5/2> 4/2 }
        cylinder { <0,6.5,3.2+2.8-0.5/2> <0,6.5,3.2+2.8+0.5  > 1.5/2 }

        difference {
           union {
              box      { <-2.5/2,6,3.2+2.8-0.5/2> <2.5/2,-4.1-2.5/2,3.2+2.8+0.5/2> }
              cylinder { <0,-4.1-2.5/2,3.2+2.8-0.5/2> <0,-4.1-2.5/2,3.2+2.8+0.5/2> 2.5/2 }
              }
           cylinder { <0,-4.1-2.5/2,3.2+2.8-0.6/2> <0,-4.1-2.5/2,3.2+2.8+0.6/2> 1.2/2 }
           }
        difference {
           union {
              box      { <-2.5/2,6,3.2+2.8-0.5/2> <2.5/2,-4.1-2.5/2,3.2+2.8+0.5/2> }
              cylinder { <0,-4.1-2.5/2,3.2+2.8-0.5/2> <0,-4.1-2.5/2,3.2+2.8+0.5/2> 2.5/2 }
              }
           cylinder { <0,-4.1-2.5/2,3.2+2.8-0.6/2> <0,-4.1-2.5/2,3.2+2.8+0.6/2> 1.2/2 }
           translate<0,0,-2.8-3.2>
           }
        difference {
           union {
              Round_Box( <4.8-0.5  ,0,3.2-2.5/2>, <4.8+0.5/2,2.5,3.2+2.5/2>  , 0.25, 0)
              box      { <4.8-0.5/2,1.0,3.2-2.5/2>, <4.8+0.5/2,-4.1-2.5/2,3.2+2.5/2> }
              cylinder { <4.8-0.5/2,-4.1-2.5/2,3.2> <4.8+0.5/2,-4.1-2.5/2,3.2> 2.5/2 }
              }
           cylinder { <4.8-0.5,-4.1-2.5/2,3.2> <4.8+0.5,-4.1-2.5/2,3.2> 1.2/2 }
           }
        texture { Silver_Metal }
        }
     rotate<0,180,0>
     }
#end

/********************************************************************************************************************************************
//Macro fuer Hohlstecker-Printeinbau (HEBO 13 - Reichelt.de)
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro CON_DC_JACK_HEBO_13_BASE()
union { 
 //Stift 
 union {
       cylinder{<0, 4.5, 0><5.5, 4.5, 0> 0.65}
       cylinder{<0, 4.5, 0><0.2, 4.5, 0> 0.9} 
       sphere {<5.5, 4.5, 0> 0.65}
       texture{col_silver}
       translate<-0.7, 0, 0>
 } 
 //Gehaeuse
 difference {
        union {
        box{<-5.75,0,-2.5><5.75,4.5,2.5>}
        cylinder{<-5.75, 4.5, 0><5.75, 4.5, 0> 2.5}
  }
  box{<-5.25,2.5,-10><-10, 20, 10>}
  box{<-0.75,2.5,-10><10, 20, 10>}
 } 
 //PIN
 union {
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<0,0,-90>
       translate<-1.05,0,0>
       texture{col_silver}
 }
 //PIN
 union {
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<0,0,-90>
       translate<-5.75,0,0>
       texture{col_silver}
 }
 //PIN
 union {
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<-90,0,-90>
       translate<-3.2,0,3.25>
       texture{col_silver}
 } 
 difference {
            cylinder{<0,0,0><1.8,0,0>0.75}
            cylinder{<-1,0,0><2.8,0,0>0.45} 
            box{<-10,0,-10><10,-10,10>}
            box{<-10,-10,0><10,10,-10>}
            texture{col_silver}
            translate<-4.1,0,2.5>
 }
 //Feder
 union { 
       difference {
                  cylinder{<0,0,0><2.6,0,0>0.75}
                  cylinder{<-1,0,0><3.6,0,0>0.45} 
                  box{<-10,0,-10><10,-10,10>}
                  box{<-10,-10,0><10,10,-10>}
       }
       box{<2.6,0,0.45><0,-3,0.75>}
       box{<0,0.45,0><2.6,0.75,-3>}
       texture{col_silver}
       rotate<0,90,45>
       translate<2.5,3,1.3>
 }
 //Heckplatte
 difference {
           union {
                 cylinder{<0,0,0><0,0.3,0>1.5}
                 cylinder{<0,0,0><0,0.4,0>0.75}
                 box{<0,0,-1.5><2.5,0.3,1.5>}
                 texture{col_silver}
           }
           cylinder{<0,-1,0><0,1,0>0.3}
           rotate<0,180,90>
           translate<-5.45,4.5,0>
 }
 translate<0,0.2,0>
}
#end

#macro CON_DC_JACK_HEBO_13()
CON_DC_JACK_HEBO_13_BASE()
#end


/********************************************************************************************************************************************
// Wolfgang Moser <womo (a) d81.de>
// DIN-Buchse(n) Hirschmann MAx-XX
// 10.02.2006 ... 21.02.2006
********************************************************************************************************************************************/
#macro CON_DIN_MA_XX_BASE(MA_Typ, MA_Subtyp)

#macro CON_DIN_MA_Inlet_Kontaktfeder(Oesenlaenge, Verschraenkungsart, VSchraenkungwinkel)
   // Oesenlaenge:        Laenge der Kontaktoese oder des Kontaktpins,
   //                     bei Buchsen mit direktem Drahtanschluss
   // Verschraenkungsart: Art der "Verriegelung" der Kontaktfeder in
   //                     der Buchse. Ende gedreht oder abgewinkelt
   // VSchraenkungwinkel: Drehwinkel der Verschraenkung fuer beide
   //                     Arten

union {

   #local Federdicke=0.5;
      // Hauptteil der Kontaktfeder
   union {
      difference {
            // Basis: box
         box { <1.7,Federdicke/2,0>, <-1.7,-Federdicke/2,8.4> }
            // Ausschnitt: box 45 Grad gedreht, Einfuehrung fuer Stift vom Stecker
         box { <1,Federdicke/2+0.01,1>, <-1,-(Federdicke/2+0.01),-1> rotate<0,45,0>}
            // Ausschnitt: Freihaltung Innenbereich, Abrundung
         cylinder { <0,Federdicke/2+0.01,2.5> <0,-(Federdicke/2+0.01),2.5> 0.75 }
            // Ausschnitt: Freihaltung fuer Stift vom Stecker, Innenbereich
         box { <0.75,Federdicke/2+0.01,2.5>, <-0.75,-(Federdicke/2+0.01),7>}
            // Ausschnitt: Freihaltung Innenbereich, Abrundung
         cylinder { <0,Federdicke/2+0.01,7> <0,-(Federdicke/2+0.01),7> 0.75 }
            // Ausschnitt: Freihaltung fuer Stift vom Stecker im Kontaktbereich
         box { <0.5,Federdicke/2+0.01,0>, <-0.5,-(Federdicke/2+0.01),2.5>}
         }
         // Ergaenzung: box, Fuehrung der Kontaktfeder im Durchsteckbereich
      box { <1.15,Federdicke/2,8.0>, <-1.15,-Federdicke/2,10.5> }
         // Ergaenzung: box, Stummel des Oesenanschlusses im Durchsteckbereich
      box { <0.35,Federdicke/2,8.0>, <-0.35,-Federdicke/2,11.85> }
      }

      // Endstueck der Kontaktfeder

   difference {
      union {
            // Ergaenzung: box, Weiterfuehrung des Stummels (ohne Ueberschneidung!)
         box { <0.35,Federdicke/2,0>, <-0.35,-Federdicke/2,1.15> }
            // Ergaenzung: box, Koerper der Oese, variable Laenge
         box { <1.15,Federdicke/2,1.15>, <-1.15,-Federdicke/2,2.15+Oesenlaenge> }
            // Ergaenzung: cylinder, Abschluss der Oese, variable Position
         cylinder { <0,Federdicke/2,2.15+Oesenlaenge> <0,-Federdicke/2,2.15+Oesenlaenge> 1.15 }
         }
            // Ausschnitt: Freihaltung Innenbereich Oese, Abrundung
      cylinder { <0,Federdicke/2+0.01,2.15> <0,-(Federdicke/2+0.01),2.15> 0.5 }
            // Ausschnitt: Freihaltung fuer Oesenanschluss, Innenbereich
      box { <0.5,Federdicke/2+0.01,2.15>, <-0.5,-(Federdicke/2+0.01),2.15+Oesenlaenge>}
            // Ausschnitt: Freihaltung Innenbereich Oese, Abrundung
      cylinder { <0,Federdicke/2+0.01,2.15+Oesenlaenge> <0,-(Federdicke/2+0.01),2.15+Oesenlaenge> 0.5 }


      #switch(Verschraenkungsart)                                                         
         #case(0) // Verdrehung (Schraube)
            translate<0,0, 11.85>
            rotate <0,0,VSchraenkungwinkel>
         #break
         #case(4) // sowohl Abwinkelung als auch zusaetzlich zweifache Verdrehung
            rotate <-VSchraenkungwinkel,0,0>
            rotate <0,0,2*VSchraenkungwinkel>
            translate<0,0, 11.85>
         #break
         #case(3) // sowohl Abwinkelung als auch zusaetzlich Verdrehung (invers)
            rotate <-VSchraenkungwinkel,0,0>
            rotate <0,0,-VSchraenkungwinkel>
            translate<0,0, 11.85>
         #break
         #case(2) // sowohl Abwinkelung als auch zusaetzlich Verdrehung
            rotate <-VSchraenkungwinkel,0,0>
            rotate <0,0,VSchraenkungwinkel>
            translate<0,0, 11.85>
         #break
         #case(1) // Abwinkelung
            rotate <-VSchraenkungwinkel,0,0>
         #else
            translate<0,0, 11.85>
      #end
      }

   #switch(Verschraenkungsart)                                                         
      #range(1, 4)   // Abwinkelung (nicht perfekt bei cases 2 und 3)
            // bei Abwinkelung noch zusaetzlich Abrundung und Auffuellen des "Biegeloches"
         cylinder { <0.35,0,11.85> <-0.35,0,11.85> Federdicke/2 }
      #break
   #end

   translate <0,0,1.0>
   #ifdef(CON_DIN_MA_Debug_Viewmode)
      pigment{Yellow}
   #else
      texture {col_silver}
   #end
   }
#end

#macro CON_DIN_MA_Inlet_Basebody(Einsatzart)
      // Einsatzart: Auspraegung des "Wulstes" am Ende zwecks Befestigung
      //             in einem Metallbecher oder zwei Metallhalbschalen
      //             einer Kupplung
#local Gesamtlaenge=13;
difference {
   union {
      cylinder { <0,0,0>  <0,0,Gesamtlaenge> 5.85 }

      #switch(Einsatzart)
         #case(0) // Scheibenwulst fuer Metallbechermontage
            cylinder { <0,0,Gesamtlaenge-3>  <0,0,Gesamtlaenge-2> 7 }
               // Stuetzwulst in Durchfuehrung von Metallbecher
            cylinder { <0,0,Gesamtlaenge-2.001>  <0,0,Gesamtlaenge> 6.15 }
         #break
         #case(1) // unterteilter Wulst fuer Metallhalbschalenmontage
                  // in Kupplungen (wie auch Steckern)
               // "duenner" Stuetzwulst
            cylinder { <0,0,Gesamtlaenge-4>  <0,0,Gesamtlaenge> 6 }

            difference {
                  // "dickerer" Haltewulst
               cylinder { <0,0,Gesamtlaenge-3>  <0,0,Gesamtlaenge-1> 6.55 }

                  // "gerade" Begrenzug des Wulstes fuer abnehmbare Metallabschirmung
               box      { < 5.5, 2.5,Gesamtlaenge-3.001>, <    7,-4,Gesamtlaenge-0.999>}
               box      { <-5.5, 2.5,Gesamtlaenge-3.001>, <   -7,-4,Gesamtlaenge-0.999>}

                  // "abgeschraegte" Begrenzug des Wulstes fuer die nicht abnehmbare
                  // Metallabschirmung mit der aufgenieteten Massekontaktzunge
               box      { <0.75,   0,Gesamtlaenge-3.001>, <-0.75,-3,Gesamtlaenge-0.999>
                  translate< -6.25,0,0>
                  rotate   < 0,0,-30>
                  }
               box      { <0.75,   0,Gesamtlaenge-3.001>, <-0.75,-3,Gesamtlaenge-0.999>
                  translate<  6.25,0,0>
                  rotate   < 0,0, 30>
                  }
               }
         #break
         #else    // keine Veraenderung
               // Dummy: duenner Stuetzwulst fuer Metallhalbschalenmontage
            cylinder { <0,0,Gesamtlaenge-4>  <0,0,Gesamtlaenge> 6 }
      #end
      }

   #switch(Einsatzart)
      #case(0)
            // Ausschnitt fuer Massefederkontakt (etwas kuerzer)
         box { <1.3,3.4,-0.01>, <-1.3,7.001,Gesamtlaenge-1.998> }
               // Breiterer Ausschnitt fuer Befestigung des
               // Massefederkontaktes am Metallbecher
         box { <2.1,3.45,Gesamtlaenge-1.999>, <-2.1,6.201,Gesamtlaenge+0.01> }
      #break
      #else
            // Ausschnitt fuer Massefederkontakt
         box { <1.3,3.4,-0.01>, <-1.3,7.001,Gesamtlaenge+0.01> }
   #end

   #ifdef(CON_DIN_MA_Debug_Viewmode)
      texture {col_Kerko}
   #else
      texture {pigment{Gray15} finish{F_MetalB  ambient (0.1 * global_ambient_mul)}}
   #end
   }
#end

#macro CON_DIN_MA_Inlet_Millbody()
#local Gesamtlaenge=13;
#local Stanzlochbreite=3.9;
union {
      // Basisbox bis 3mm vor Grund
   box { <Stanzlochbreite/2,0.4,-0.001>, <-Stanzlochbreite/2,-0.4,Gesamtlaenge-3> }
      // Roehre fuer Pin vom Stecker
   cylinder { <  0,  0,-0.001>  <   0,   0,Gesamtlaenge-3> 0.8 }
      // Durchbruch fuer Pinanschluss
   box { <1.25,0.4,Gesamtlaenge-3.001>, <-1.25,-0.4,Gesamtlaenge+0.001> }

   #ifdef(CON_DIN_MA_Debug_Viewmode)
      texture {col_Kerko}
   #else
      texture {pigment{Gray15} finish{F_MetalB  ambient (0.1 * global_ambient_mul)}}
   #end
   }
#end

#macro TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(Major Minor, Dicke, Quadrant)
   // Parametrisierung aehnlich zu der eines Torus
   // Major:    Radius des Ringes zur gedachten Mittellinie des zu
   //           einem Viertel aufgeschnittenen Ringtoruses
   // Minor:    Radius zur Aussenkante des zu einem Viertel
   //           aufgeschnittenen Torusringes
   // Dicke:    Die Blechdicke bestimmt abhaengig vom Minor-Aussenradius
   //           in der Folge den Innenradius des zu einem Viertel
   //           aufgeschnittenen Torusringes. Dicke sollte im Bereich
   //           0<=Dicke<=Minor  liegen.
   //           Ist  Dicke<0  oder  Dicke>2*Minor, dann wird kein
   //           Torus dargestellt, weil die Schnittmenge leer wird.
   // Quadrant: Wahl des Viertels des Torusringes (1, 2, 3, 4)

#local SelectioningCylinder1 = cylinder { <0,0,0>   <0,Minor+0.001,0> Major+Minor+0.001 }
#local SelectioningCylinder2 = cylinder { <0,Minor+0.001,0>  <0,-(Minor+0.001),0> Major }
#if(Quadrant=3)
   object{
#else
   intersection{
#end
      difference {
         torus{Major, Minor}
         torus{Major, Minor-Dicke}

         #if(Quadrant=4 | Quadrant=3)
            SelectioningCylinder1
         #end
         #if(Quadrant=2 | Quadrant=3)
            SelectioningCylinder2
         #end
         }

      #if(Quadrant=1 | Quadrant=2)
         SelectioningCylinder1
      #end
      #if(Quadrant=1 | Quadrant=4)
         SelectioningCylinder2
      #end
      }
#end

#macro CON_DIN_MA_Outlet_BecherBase()
#local Gesamtlaenge=13;
union {
      // Hauptteil des Metallbechers, aufgebaut aus
      // ausgeschnittenen Ringtori und Zylinderringen
   difference {
      union {
         cylinder { <0,1,0>  <0,Gesamtlaenge-2,0> 7.4 }
         cylinder { <0,Gesamtlaenge-1.4,0>  <0,Gesamtlaenge-1,0> 6.4 }
         }
      cylinder { <0, 0.999,0>  <0,Gesamtlaenge-1.999,0> 7.0 }
      cylinder { <0,Gesamtlaenge-1.4001,0>  <0,Gesamtlaenge-0.999,0> 6.2 }
      }

   object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(8.0, 1.0, 0.4, 4) translate<0,1,0> }
   object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(6.4, 1.0, 0.4, 2) translate<0,Gesamtlaenge-2,0> }

      // Winkelstueck zur Befestigung der Massekontakzunge
   union {
         // Viertelrohr als Biegeradius des Winkelstueckes
      intersection{
         cylinder { <2,0.5,-0.5>  <-2,0.5,-0.5> 0.5 }
         cylinder { <2.001,0.5,-0.5>  <-2.001,0.5,-0.5> 0.1 inverse}
         box{<2.001,-0.001,-0.001>, <-2.001,0.5,-0.5>}
         }

         // Anschluss an den Metallbecher inklusive radialer Begrenzung
      intersection{
         box{<2,0,-0.5>, <-2,0.4,-2.5> }
         cylinder { <0,-0.001,0>  <0,0.401,0> 6.201 translate<0,0,4.0> }
         }

         // Kombination der Konstruktion von abgewinkeltem Anschlussstueck
         // und der Massekontaktzunge in einer difference/union-Sektion,
         // was ein paar Anweisungen spart, die ganze Beschreibung
         // allerdings etwas unuebersichtlich macht.
      difference {
         union {
               // Haltezunge fuer Niet
            box{<2,3.5,-0.4>, <-2,0.5,0>}

               // Kontaktzunge fuer Massekontaktierung als Cubic-Spline
            prism {
               linear_sweep cubic_spline
               -1.15, 1.15, 14, // the number of points making up the shape ...
               <2.45-Gesamtlaenge,-4.0>, < 2.45-Gesamtlaenge,0.5>,
               
               <5.4-Gesamtlaenge,-1.65>,

               <11.4-Gesamtlaenge,-0.02>, <12.4-Gesamtlaenge,0.2>, <13.4-Gesamtlaenge,0.2>, <16.4-Gesamtlaenge,0.175>,
               <16.4-Gesamtlaenge, 0.025>, <13.4-Gesamtlaenge,0.0>, <12.4-Gesamtlaenge,0.0>, <11.4-Gesamtlaenge,-0.22>,

               <5.4-Gesamtlaenge,-1.85>,
               
               < 2.45-Gesamtlaenge,0.5>, <6.95-Gesamtlaenge,0.5>
               rotate<0,0,90>
               }
               // Ergaenzung des Cubic-Spline am hinteren Ende
            box  { <-1.15,13.30-(Gesamtlaenge),0.2>, <1.15,19.65-Gesamtlaenge,0> }
            cylinder { <0,19.65-(Gesamtlaenge),0.2>     <0,19.65-Gesamtlaenge,0> 1.15 }
   #ifdef(CON_DIN_MA_Debug_Viewmode)
      pigment{White}
   #end     
            }

            // Abschraegen der Haltezunge
         box{< 2.05,-0.501,0.001>, < 3.0,3.075,-0.401> rotate <0,0, 15> }
         box{<-2.05,-0.501,0.001>, <-3.0,3.075,-0.401> rotate <0,0,-15> }

            // Ausschneiden des Langloches in der Massekontaktzunge        
         box   { <-0.5,18.15-Gesamtlaenge,0.201>, <0.5,19.65-Gesamtlaenge,-0.001> }
         cylinder { <0,19.65-Gesamtlaenge,0.201>  <0,  19.65-Gesamtlaenge,-0.001> 0.5 }
         cylinder { <0,18.15-Gesamtlaenge,0.201>  <0,  18.15-Gesamtlaenge,-0.001> 0.5 }
   #ifdef(CON_DIN_MA_Debug_Viewmode)
      pigment{Red}
   #end     
         }

         // Messingniet zur Verbindung von Haltezunge und Massekontaktzunge
      cylinder { <0,2,0.25>  <0,2,-0.45> 0.875 texture {T_Gold_5E}}  // Messing!

      translate<0,Gesamtlaenge-1.4,-4.0>
      }
   }
#end

#macro CON_DIN_MA_Outlet_FrontHlpr1(Winkel, Bauteil)
   #local ZielLaenge = (2*(Winkel>=0)-1)*9.138 ;
   #local ZielWinkel = Winkel+(2*(Winkel>=0)-1)*34.58078 ;
   #switch(Bauteil)
      #case(0) // Boxen fuer "difference" der Viertel-Torusse, allerdings
               // nur oberhalb Blechdicke, nicht (mehr) komplett
         box {
            <0, -0.001,  -5.0   >, <ZielLaenge,1.001,0.001>
            #ifdef(CON_DIN_MA_Debug_Viewmode)
               pigment{Green}
            #end     
      #break

         // Teile zur Konstruktion der geraden Randboegen vom Tiefziehen
      #case(1) // Zylinder als Blechkante fuer Montagefluegel
         cylinder{
            <0,1,-1>, <ZielLaenge,1,  -1  > 1.0
            #ifdef(CON_DIN_MA_Debug_Viewmode)
               pigment{Red}
            #end     
      #break
      #case(2) // Innenzylinder fuer "intersection" mit Modifizierer
               // "inverse", Radius weniger Blechdicke (0.4)
               //
               // Realisierung der Ueberstaende fuer "difference" (aka
               // inverse intersection) hier nicht absolut (+/- 0.001),
               // sondern relativ:  +/- FinLen * 0.001
         cylinder{
            <-ZielLaenge*0.001,1,-1>, <ZielLaenge*1.001,1,-1> 0.6
            #ifdef(CON_DIN_MA_Debug_Viewmode)
               pigment{Yellow}
            #end     
      #break
      #case(3) // Box fuer "intersection" zum Freischneiden des richtigen Viertels
               // inklusive Ueberstaende fuer Nicht-Schnittflaechen
         box {
            <-0.001,0,  -1.001  >, <ZielLaenge+0.001,1.001,  0  >
            #ifdef(CON_DIN_MA_Debug_Viewmode)
               pigment{Pink}
            #end     
      #break

      #else
       // Box zum Ausfuellen mit Blechdicke bis zur Biegekante
         box {
            <0,0,-7.5>, <ZielLaenge,0.4,-1>
   #end

            translate <0,0,   9.5  >
            rotate <0,ZielWinkel,0>
            }
#end

#macro CON_DIN_MA_Outlet_FrontHlpr2(Winkel)
intersection{
   CON_DIN_MA_Outlet_FrontHlpr1(Winkel, 1)
   object{ CON_DIN_MA_Outlet_FrontHlpr1(Winkel, 2) inverse }
   CON_DIN_MA_Outlet_FrontHlpr1(Winkel, 3)
   }
#end

#macro CON_DIN_MA_Outlet_FrontFlansch()
   // Dazu kommt die Frontplatte mit den beiden Flansch"ohren", welche
   // wiederum die beiden Befestigungsloecher enthalten
difference {
   union {
         // Der vorne ueberstehende Ring
      cylinder { <0,0,0>  <0,0.4,0> 8.5 }

         // Das Freischneiden der Ringtori an den Uebergaengen zu
         // den geraden Randstuecken kann "schlierenfrei" nur
         // durch eine weitere explizite difference/union-
         // Beschreibung durchgefuehrt werden
      difference {
         union {
               // Der vorne ueberstehende Torus am Ring
            object{TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(8.5, 1.0, 0.4, 3) translate<0,1,0> }
         
               // Die Flanschohren
            object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(2.2, 1.0, 0.4, 3) translate< 11.1,1,0> }
            object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(2.2, 1.0, 0.4, 3) translate<-11.1,1,0> }
            }

            // Abschneiden der Tori an den Uebergaengen
            // zu den geraden Kantenverbindern
         CON_DIN_MA_Outlet_FrontHlpr1(   0, 0)
         CON_DIN_MA_Outlet_FrontHlpr1( 180, 0)
         CON_DIN_MA_Outlet_FrontHlpr1(-180, 0)
         CON_DIN_MA_Outlet_FrontHlpr1(-360, 0)
         #ifdef(CON_DIN_MA_Debug_Viewmode)
            pigment{Magenta}
         #end     
         }

         // Ausfuellung der Ohrentori
      object{ cylinder { <0,0,0>  <0,0.4,0> 2.2 } translate< 11.1,0,0> }
      object{ cylinder { <0,0,0>  <0,0.4,0> 2.2 } translate<-11.1,0,0> }

         // Die gebogenen Raender zu den Ohren hin
      CON_DIN_MA_Outlet_FrontHlpr2(   0)
      CON_DIN_MA_Outlet_FrontHlpr2( 180)
      CON_DIN_MA_Outlet_FrontHlpr2(-180)
      CON_DIN_MA_Outlet_FrontHlpr2(-360)
      
         // Verlaengerung der gebogenen Raender zu den Ohren mit Blech
      CON_DIN_MA_Outlet_FrontHlpr1(   0, 4)
      CON_DIN_MA_Outlet_FrontHlpr1( 180, 4)
      CON_DIN_MA_Outlet_FrontHlpr1(-180, 4)
      CON_DIN_MA_Outlet_FrontHlpr1(-360, 4)
      #ifdef(CON_DIN_MA_Debug_Viewmode)
         pigment{Cyan}
      #end     
      }

      // Ausschneiden des grossen Loches in der Mitte
   cylinder { <0,-0.001,0>  <0,0.401,0> 8.0 }

      // Ausschneiden der beiden kleinen Befestigungsbohrloecher in den Ohren
   object{ cylinder { <0,-0.001,0>  <0,0.401,0> 1.6 } translate< 11.1,0,0> }
   object{ cylinder { <0,-0.001,0>  <0,0.401,0> 1.6 } translate<-11.1,0,0> }
   }
#end

#macro CON_DIN_MA_Outlet_Becher(Flansch)
   // Flansch: on/off

#if(Flansch=on)
   union {
         // Hauptbecher
      CON_DIN_MA_Outlet_BecherBase()
         // Frontflansch
      CON_DIN_MA_Outlet_FrontFlansch()
#else
   object{
      CON_DIN_MA_Outlet_BecherBase()
#end
   
         // Hier lediglich noch Positionierarbeiten
      rotate<90,0,0>
   
      #ifdef(CON_DIN_MA_Debug_Viewmode)
         // pigment{Green}
         texture {col_gold}
      #else
         texture {col_silver}
      #end
      }
#end

/*##########################################################################*/
/*##########################################################################*/
/*# Ende der Bauteildefinitionen, Anwendung durch Gruppierungen und Muster #*/
/*##########################################################################*/
/*##########################################################################*/

#macro CON_DIN_MA_InletAction(Typ, LochRotWinkel, LochPosWinkel)
   // Typ:           Art der Bearbeitung, derzeit definiert sind:
   //                0 - Fraesen bzw. Ausstanzen des kontaktfederloches
   //                1 - Kontaktfedereinsatz, Anschluss gebogen, Oese lang
   //                2 - Kontaktfedereinsatz, Anschluss gedreht, Oese lang
   //                3 - Kontaktfedereinsatz, Anschluss gedreht, Oese kurz
   //                4 - Kontaktfedereinsatz, Anschluss gebogen und
   //                    gedreht, Oese lang
   //                5 - Kontaktfedereinsatz, Anschluss gebogen und
   //                    invers gedreht, Oese lang
   //                6 - Kontaktfedereinsatz, Anschluss gebogen und
   //                    zweifach gedreht (60° statt 30°), Oese lang
   //
   // LochRotWinkel: Rotation des Stanzloches um die eigene Achse
   //                (dieser wird gegen "LochPosWinkel" kompensiert
   // LochPosWinkel: Rotation des Loches auf einem Radius von 3.5
   //                innerhalb des Buchseninlets
   //
   // Spezialfall: Wenn  LochPosWinkel=180  dann wird das Stanzloch
   // Mitelloch    genau in der Mitte des Inlets positioniert. Da
   //              das Loch ansonsten im Ausschnitt fuer den
   //              Massekontakt zu liegen kaeme, ist das "Fehlen" des
   //              180'er Winkels daher nicht tragisch.
   //
#local PositionRadius=3.5;
object{
   #switch(Typ)
      #case(6) // Anschluss gebogen und zweifach verdreht, Oese lang
         CON_DIN_MA_Inlet_Kontaktfeder(3, 4, 30)
      #break
      #case(5) // Anschluss gebogen und invers verdreht, Oese lang
         CON_DIN_MA_Inlet_Kontaktfeder(3, 3, 30)
      #break
      #case(4) // Anschluss gebogen und verdreht, Oese lang
         CON_DIN_MA_Inlet_Kontaktfeder(3, 2, 30)
      #break
      #case(1) // Anschluss gebogen, Oese lang
         CON_DIN_MA_Inlet_Kontaktfeder(3, 1, 30)
      #break
      #case(2) // Anschluss gedreht, Oese lang
         CON_DIN_MA_Inlet_Kontaktfeder(3, 0,-30)
      #break
      #case(3) // Anschluss gedreht, Oese kurz
         CON_DIN_MA_Inlet_Kontaktfeder(1, 0,-30)
      #break
      #else    // wie #case(0), Fraesen bzw. Ausstanzen der Loecher
         CON_DIN_MA_Inlet_Millbody()
   #end

   rotate<0,0,90+LochRotWinkel-LochPosWinkel>
   #if(LochPosWinkel!=180)
      translate<0,-3.5,0>
      rotate<0,0,LochPosWinkel>
   #end
   }
#end

#macro CON_DIN_MA_InletPinComposition(MA_Typ, PinAction, MidPinAct)
   // MA_Typ:    Selektion der Buchsenart, Anzahl der Pins,
   //            Winkelstellung der Pins usw. ueber Typcodes.
   //
   //    Derzeit definitiert:
   //       30 - Anordnung wie bei:          MAB_3_S
   //       40 - Anordnung wie bei:          MAB_4
   //       51 - Anordnung wie bei:          MAB_5_S
   //       52 - Anordnung wie bei:          MAB_5
   //       53 - Anordnung wie bei: (kreuzfoermig, nicht Hirschmann)
   //       61 - Anordnung wie bei:          MAB_6
   //       62 - Anordnung wie bei (exklusiv):  MAB_6_V
   //       63 - Anordnung wie bei (exklusiv):  MAB_6_H
   //       71 - Anordnung wie bei (exklusiv):  MAB_7_SH
   //       72 - Anordnung wie bei:          MAB_7_S
   //       81 - Anordnung wie bei:          MAB_8_S
   //       82 - Anordnung wie bei:          MAB_8_SN
   //
   //       39 - Fuer rekursive Aufrufe benoetigt
   //       58 - Fuer rekursive Aufrufe benoetigt
   //       59 - Fuer rekursive Aufrufe benoetigt
   //
   //    "Vererbungshierarchien":
   //          30 <|-- 51 <|-- 81
   //          59 <|-- 72 <|-- 82
   //          39 <|-- 58 <|-- 61
   //          ohne: 40, 52, 53, 62, 63, 71
   //
   // PinAction: Art der Bearbeitung, derzeit definiert sind:
   //            0 - Fraesen bzw. Ausstanzen des Kontaktfederloches
   //            1 - Kontaktfedereinsatz, Anschluss gebogen, Oese lang
   //            2 - Kontaktfedereinsatz, Anschluss gedreht, Oese lang
   //            3 - Kontaktfedereinsatz, Anschluss gedreht, Oese kurz
   //
   // MidPinAct: Gesondert definierbare Bearbeitungsart fuer das Mittelloch
   //
   // ACHTUNG: Der aeussere aufrufende Kontext sollte diesem Makro eine
   //          klammernde Struktur umstellen, wie z.B.:  union {}
   //

   #switch(MA_Typ)
      #case(81)
            // Mittelloch ausstanzen, exzentrisch (0.9 mm) positioniert
         object{CON_DIN_MA_InletAction(MidPinAct, 0,180) translate<0,0.9,0>}
            // Die beiden speziell ausgerichteten Kontaktbohrungen unten
         object{CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45,-135) translate<-1, 0.5, 0>}
         object{CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135, 135) translate< 1, 0.5, 0>}
         // fall through to next case, adding more pins
      #case(51)
            // 45° links
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45,-45)
            // 45° rechts
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135, 45)
      #case(30)
            // 90° links
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45,-90)
            // 90° rechts
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135, 90)
            // center
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:6),   0,  0)
      #break;
      //############################################

      #case(82)
            // Mittelloch ausstanzen, exzentrisch (0.7 mm) positioniert
         object{CON_DIN_MA_InletAction(MidPinAct, 0,180) translate<0,0.7,0>}

      #case(72)
            // Kontakte 6 und 7 unten ergaenzen
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:6),-135,-135)
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), 135, 135)

      #case(59)
            // virtuelle 5'er Buchse, da nicht nach Norm
         #local Rotator=-90;
         #while (Rotator<=90)
            CON_DIN_MA_InletAction((PinAction!=1?PinAction:6), Rotator, Rotator)
            #local Rotator=Rotator+45;
         #end
      #break;
      //############################################

      #case(61)
            // Loch rechts unten ausstanzen und befuellen
         CON_DIN_MA_InletAction(PinAction, 300,-120)
      #case(58)
            // Mittelloch ausstanzen (6'er Buchse)
         CON_DIN_MA_InletAction(MidPinAct,  60, 180)
            // Loch rechts unten ausstanzen und befuellen
         CON_DIN_MA_InletAction(PinAction, 240, 120)
      #case(39)
            // 3 Loecher mit 60°-"Abstaenden" ausstanzen (fuer 6'er Buchse)
         #local Rotator=-60;
         #while (Rotator<=60)
            CON_DIN_MA_InletAction(PinAction, Rotator+120, Rotator)
            #local Rotator=Rotator+60;
         #end
      #break;
      //############################################

      #case(40)
            // Loch links unten ausstanzen und befuellen
         CON_DIN_MA_InletAction(PinAction, -18,-108)
            // Links oben
         CON_DIN_MA_InletAction(PinAction,  72, -36)
            // Rechts oben
         CON_DIN_MA_InletAction(PinAction, 108,  36)
            // Loch rechts unten ausstanzen und befuellen
         CON_DIN_MA_InletAction(PinAction, 198, 108)
      #break;
      //############################################

      #case(52)
            // rekursives "Holen" der 3'er Basis
         CON_DIN_MA_InletPinComposition(39, (PinAction!=1?PinAction:5), MidPinAct)
            // Loch rechts unten ausstanzen und befuellen
            //   diese Ausrichtung (nach Spec!!!) kann so nicht
            //   sein (Ueberschneidungen), muesste eigentlich einer
            //   62'er ohne Mittelpin entsprechen, bzw. der Anw.:
            //     CON_DIN_MA_InletAction(PinAction, 240, 120)
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:6), 120, 120)
            // Loch links unten ausstanzen und befuellen
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),   0,-120)
      #break;
      //############################################

      #case(53)
            // Mittelloch ausstanzen (5'er Kreuz-Buchse)
         CON_DIN_MA_InletAction(MidPinAct,  0, 180)
            // 2 Loecher oben mit 90°-"Abstand" ausstanzen
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45, -45)
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135,  45)
            // 2 Loecher unten mit 90°-"Abstand" ausstanzen
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:4),-82.5,-135)
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-97.5, 135)
      #break;
      //############################################

      #case(62)
            // rekursives "Holen" der 5'er Basis
         CON_DIN_MA_InletPinComposition(58, PinAction, MidPinAct)
            // Loch links unten ausstanzen und befuellen
         CON_DIN_MA_InletAction(PinAction, 0,-120)
      #break;
      //############################################

      #case(63)
            // Mittelloch ausstanzen (6'er Buchse)
         CON_DIN_MA_InletAction(MidPinAct,  90, 180)


            // 5 Loecher mit 60°-"Abstaenden" ausstanzen (fuer 6'er Buchse)
         CON_DIN_MA_InletAction(PinAction,   0, -120)
         CON_DIN_MA_InletAction(PinAction, 120,   60)
         CON_DIN_MA_InletAction(PinAction, 180,  120)

            // bei Abwinkelung zusaetzlich Verdrehung
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:6),   0,    0)
            // bei Abwinkelung zusaetzlich inverse Verdrehung
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),  60,  -60)
      #break;
      //############################################

      #case(71)
            // rekursives "Holen" der 5'er Basis
         CON_DIN_MA_InletPinComposition(59, PinAction, MidPinAct)
            // Ergaenzen der beiden Pins 6 und 7
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:4),-90,-135)
         CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-90, 135)
      #break;
      //############################################
   #end
#end

   // MA_Typ:    Selektion der Buchsenart, Anzahl der Pins,
   //            Winkelstellung der Pins usw. ueber Typcodes.
   //            Die Typcodes sind derzeit noch nicht mit dem
   //            DIN-Standard abgestimmt
   //
   // MA_Subtyp: Selektion der weiteren Auspraegung, derzeit definiert:
   //            0 - Buchse im Metallbecher mit Flansch
   //                 (es fehlt noch der Masseanschluss)
   //            1 - Buchse im Metallbecher ohne Flansch
   //                (nicht fertiggestellt, Oesen statt Pins)
   //            2 - Kupplung (nicht fertiggestellt, Metallabschirmung
   //                [Becher] und Ummantelung fehlen noch komplett)

union {
   #local AllParts=3;
   #switch(MA_Subtyp)
      #case(1)
         #if(AllParts>=3)
            CON_DIN_MA_Outlet_Becher(off)
            #end

         #local Wulst=0;      // Metallbechermontage

            // die folgenden Definitionen verlangen eigentlich
            // einen Pin. Leider ist anhand der Specs nicht
            // ersichtlich, wie die Verankerung im Gehaeuse
            // stattfindet, noch wie gross der Offset des
            // Anschlusspins vom Mittelpunkt ist.
            // Daher zunaechst Verwendung langer Oesen mit
            // Verriegelung durch Verdrehen.
         #local PinEnde=2;    // Oese lang, verdreht
         #local MLPEnde=2;    // Oese lang, verdreht
      #break
      #case(2)
         // Makro fuer Kupplungs-/Steckergehaeuse fehlt (noch)
         #if(AllParts>=3)
            #end

         #local Wulst=1;      // Halbschalenmontage
         #local PinEnde=3;    // Oese kurz, verdreht
         #local MLPEnde=2;    // Oese lang, verdreht
      #break
      #else // selbe wie case(0)
         #if(AllParts>=3)
            CON_DIN_MA_Outlet_Becher(on)
            #end

         #local Wulst=0;      // Metallbechermontage
         #local PinEnde=1;    // Oese lang, abgebogen
         #local MLPEnde=2;    // Oese lang, verdreht
      #end

      // noch eine extra union, damit nur ein Objekt
      // "translationiert" (verschoben) werden braucht
   union {
      #if(AllParts>=2)
         difference {
            CON_DIN_MA_Inlet_Basebody(Wulst)
               // Ausfraesungen fuer die Kontaktfedern: 0,0
            CON_DIN_MA_InletPinComposition(MA_Typ, 0, 0)
            }
         #end

      #if(AllParts>=1)
            // Einbringen der Kontaktfedern
         CON_DIN_MA_InletPinComposition(MA_Typ, PinEnde, MLPEnde)
         #end

         // Gesamtlaenge ueber alles ohne Pins laut Hirschmann-Spec: 13.6
         // Body ist aber nur 13.0, wobei jenes Inlet aber etwas im
         // Gehaeuse (Becher) versenkt ist. Daher Positionierung desselben
      translate<0,0,0.6>
      }
   }
#end


#macro CON_DIN_MAB_3S()   CON_DIN_MA_XX_BASE(30, 0) #end
#macro CON_DIN_MAB_4()    CON_DIN_MA_XX_BASE(40, 0) #end
#macro CON_DIN_MAB_5()    CON_DIN_MA_XX_BASE(52, 0) #end
#macro CON_DIN_MAB_5S()   CON_DIN_MA_XX_BASE(51, 0) #end
#macro CON_DIN_MAB_6()    CON_DIN_MA_XX_BASE(61, 0) #end
#macro CON_DIN_MAB_7S()   CON_DIN_MA_XX_BASE(72, 0) #end
#macro CON_DIN_MAB_8S()   CON_DIN_MA_XX_BASE(81, 0) #end
#macro CON_DIN_MAB_8SN()  CON_DIN_MA_XX_BASE(82, 0) #end
#macro CON_DIN_MAB_5SV()  CON_DIN_MA_XX_BASE(51, 1) #end
#macro CON_DIN_MAB_6V()   CON_DIN_MA_XX_BASE(62, 1) #end
#macro CON_DIN_MAB_7SV()  CON_DIN_MA_XX_BASE(72, 1) #end
#macro CON_DIN_MAB_8SV()  CON_DIN_MA_XX_BASE(81, 1) #end
#macro CON_DIN_MAB_8SNV() CON_DIN_MA_XX_BASE(82, 1) #end


/********************************************************************************************************************************************
// Grundmakro: Stiftleiste nach DIN41617.
// J.Bartels@arcor.de, www.mec-krefeld.de
********************************************************************************************************************************************/
#macro CON_DIS_DIN41617_BASE(Pins)
// Grundmakro: Um 90° gebogener, runder Stift eines Steckverbinders nach DIN41617.
// Parameter: Staerke ueber/unter PCB, Biegeradius (Mitte), Hoehe ueber/unter PCB-Oberkante, Laenge nach vorn (-Z), Farbe
// J.Bartels@arcor.de, www.mec-krefeld.de
#macro PIN41617 (DO,DU,R,HO,HU,L,col)
union {
   intersection{ 
      torus{ R, DO/2 rotate<0,0,90> translate<0,HO-R,-R> }
      box{ <DO/2,HO-R,DO/2><-DO/2,HO+DO/2,-R> }
   }
   cylinder{<0,-HU,0><0,HO-R-0.1,0> DU/2}
   cone{ <0,HO-R-0.1,0> DU/2 <0,HO-R,0> DO/2 }
   cylinder{<0,HO,-L+1><0,HO,-R> DO/2}
   cone{ <0, HO,-L+1>,DO/2,<0,HO,-L>,DO/2-0.3}
   texture{col}
} 
#end

// Grundmakro: Reihe von Stiften eines Steckverbinders nach DIN41617.
// J.Bartels@arcor.de, www.mec-krefeld.de
#macro PIN41617_ROW (Pins)
union {
   #local i=0;
   #while(i<Pins) 
      object{PIN41617 (1,0.8,1.2,1.6,3.3,13.9,col_gold) translate<i*2.5,0,-1.25>} 
      #local i=i+2; 
   #end
   #local i=1;
   #while(i<Pins) 
      object{PIN41617 (1,0.8,1.2,1.6+3.8,3.3,13.9+2.5,col_gold) translate<i*2.5,0,1.25>} 
      #local i=i+2; 
   #end
   translate<-(Pins/2)*2.5+1.25,0,4.5/2+2.5>
}
#end

#local A=(Pins-1)*2.5+15.6;
#local D=(Pins-1)*2.5+10;
#local E=Pins*2.5;
union {
 PIN41617_ROW( Pins )
 box{ <-E/2,0,-4.5/2><E/2,8.5,4.5/2> }
 //Befestigungs-Ohr
difference { 
 box{ <A/2,0,-4.5/2><E/2,4.2,8.1-4.5/2> }
 intersection{
   cylinder{<D/2,-1,4.5/2><D/2,1+4.2,4.5/2>,1.6}
   box{ <D/2-1.6,-1,4.5/2-1.4><D/2+1.6,1+4.2,4.5/2+1.4>}
 }  
 box{ <-(A-E-5)/2,-1,0><0,1+4.2,8.1-4.5+10> rotate<0,20,0> translate<E/2,0,4.5/2> }
}
 //Befestigungs-Ohr
difference { 
 box{ <-A/2,0,-4.5/2><-E/2,4.2,8.1-4.5/2> }
 intersection{
   cylinder{<-D/2,-1,4.5/2><-D/2,1+4.2,4.5/2>,1.6}
   box{ <-D/2+1.6,-1,4.5/2-1.4><-D/2-1.6,1+4.2,4.5/2+1.4>}
 }  
 box{ <(A-E-5)/2,-1,0><0,1+4.2,8.1-4.5+10> rotate<0,-20,0> translate<-E/2,0,4.5/2> }
}
pigment{Gray80}
}
#end

#macro CON_DIS_DIN41617_13() CON_DIS_DIN41617_BASE(13) #end
#macro CON_DIS_DIN41617_21() CON_DIS_DIN41617_BASE(21) #end
#macro CON_DIS_DIN41617_31() CON_DIS_DIN41617_BASE(31) #end


/********************************************************************************************************************************************
//Macros for connector MATE-N-LOK vertical 9263 serie from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 31-12-05
********************************************************************************************************************************************/
#macro CON_DIS_MATNLOK_9263_BASE(n,c)
#switch(c)
#case(1)
#local col=Gray90;
#break
#case(2)
#local col=Gray10;
#break
#case(3)
#local col=Brown;
#break
#case(4)
#local col=Gray90;
#break
#case(5)
#local col=Orange;
#break
#end

union {
    
    difference {
        merge {
            //body
         box{<-6.35*n/2-.5,-3.8,0><6.35*n/2+.5,3.8,14>}

         
         //lateral grips
         box{<-6.35*n/2,-1.5,6><-6.35*n/2-2.5,1.5,13.99>}
         box{<6.35*n/2,-1.5,6><6.35*n/2+2.5,1.5,13.99>}
         

         //little blocs 
            #local i=0; #while (i<n+1) box{<-(6.35*n/2)+(i*6.35)-.5,-3.8,0><-(6.35*n/2)+(i*6.35)+.5,-4.6,2> } #local i=i+1; #end
         }
         
         merge {
            //Cylindrical holes
            #local i=0; #while (i<n) cylinder{<-(6.35/2*(n-1))+(i*6.35),0,1><-(6.35/2*(n-1))+(i*6.35),0,15> 3 } #local i=i+1; #end
            //Half square holes in the first hole
            #local i=0; 
            box{<-(6.35/2*(n-1))+(i*6.35)+3,0,1><-(6.35/2*(n-1))+(i*6.35)-3,-3,15> }
            //Half square holes in the last hole
            #local i=n-1;
            box{<-(6.35/2*(n-1))+(i*6.35)+3,0,1><-(6.35/2*(n-1))+(i*6.35)-3,-3,15> }
                        
         //lateral grips
         box{<-6.35*n/2-1.5,-1.6,5><-6.35*n/2-3.5,1.6,7.5> }
         box{<+6.35*n/2+1.5,-1.6,5><+6.35*n/2+3.5,1.6,7.5> }
         
         box{<-2.5,-1.6,5><+2.5,1.6,20>  rotate -25*y translate +(6.35*n/2+9.8)*x}
         box{<-2.5,-1.6,5><+2.5,1.6,20>  rotate +25*y translate -(6.35*n/2+9.8)*x}
         }
        #if(c=1)
             texture{
               pigment { rgbf <1,1,1,0.3> }
               normal{
                 agate 0.05
                 scale 0.1
               }
               finish{ phong 0.8 phong_size 200  ambient (0.1 * global_ambient_mul)}
             }
        #else
            pigment{col}
        #end
    }
    #local i=0; #while (i<n)
        difference {
            union {
                //Pin
                cylinder{<-(6.35/2*(n-1))+(i*6.35),0,-2><-(6.35/2*(n-1))+(i*6.35),0,4> 0.85  }
                cylinder{<-(6.35/2*(n-1))+(i*6.35),0,4><-(6.35/2*(n-1))+(i*6.35),0,10.5> 1.05  }
                //Top
                cone {<-(6.35/2*(n-1))+(i*6.35),0,+10.5>, 1.05, <-(6.35/2*(n-1))+(i*6.35),0,+12>, 0.3 }
                //Base
                cone {<-(6.35/2*(n-1))+(i*6.35),0,-2>, 0.85, <-(6.35/2*(n-1))+(i*6.35),0,-4>, 0.5 }
                
                texture { pigment{P_Silver2}}
            }
            //gap
            box{<+1,-0.1,7><-1,+0.1,14> texture{pigment{P_Silver2}} rotate(rand(global_seed)*180)*z translate<-(6.35/2*(n-1))+(i*6.35),0,0>   }
        }
    #local i=i+1; #end
    rotate <-90, 180,0>
}
#end


#macro CON_DIS_MATNLOK_9263_10_1() CON_DIS_MATNLOK_9263_BASE(2,1)  #end
#macro CON_DIS_MATNLOK_9263_10_2() CON_DIS_MATNLOK_9263_BASE(2,2)  #end
#macro CON_DIS_MATNLOK_9263_10_3() CON_DIS_MATNLOK_9263_BASE(2,3)  #end
#macro CON_DIS_MATNLOK_9263_10_4() CON_DIS_MATNLOK_9263_BASE(2,4)  #end
#macro CON_DIS_MATNLOK_9263_10_5() CON_DIS_MATNLOK_9263_BASE(2,5)  #end
#macro CON_DIS_MATNLOK_9263_11_1() CON_DIS_MATNLOK_9263_BASE(3,1)  #end
#macro CON_DIS_MATNLOK_9263_11_2() CON_DIS_MATNLOK_9263_BASE(3,2)  #end
#macro CON_DIS_MATNLOK_9263_11_3() CON_DIS_MATNLOK_9263_BASE(3,3)  #end
#macro CON_DIS_MATNLOK_9263_11_4() CON_DIS_MATNLOK_9263_BASE(3,4)  #end
#macro CON_DIS_MATNLOK_9263_11_5() CON_DIS_MATNLOK_9263_BASE(3,5)  #end
#macro CON_DIS_MATNLOK_9263_12_1() CON_DIS_MATNLOK_9263_BASE(4,1)  #end
#macro CON_DIS_MATNLOK_9263_12_2() CON_DIS_MATNLOK_9263_BASE(4,2)  #end
#macro CON_DIS_MATNLOK_9263_12_3() CON_DIS_MATNLOK_9263_BASE(4,3)  #end
#macro CON_DIS_MATNLOK_9263_12_4() CON_DIS_MATNLOK_9263_BASE(4,4)  #end
#macro CON_DIS_MATNLOK_9263_12_5() CON_DIS_MATNLOK_9263_BASE(4,5)  #end
#macro CON_DIS_MATNLOK_9263_13_1() CON_DIS_MATNLOK_9263_BASE(5,1)  #end
#macro CON_DIS_MATNLOK_9263_13_2() CON_DIS_MATNLOK_9263_BASE(5,2)  #end
#macro CON_DIS_MATNLOK_9263_13_3() CON_DIS_MATNLOK_9263_BASE(5,3)  #end
#macro CON_DIS_MATNLOK_9263_13_4() CON_DIS_MATNLOK_9263_BASE(5,4)  #end
#macro CON_DIS_MATNLOK_9263_13_5() CON_DIS_MATNLOK_9263_BASE(5,5)  #end
#macro CON_DIS_MATNLOK_9263_14_1() CON_DIS_MATNLOK_9263_BASE(6,1)  #end
#macro CON_DIS_MATNLOK_9263_14_2() CON_DIS_MATNLOK_9263_BASE(6,2)  #end
#macro CON_DIS_MATNLOK_9263_14_3() CON_DIS_MATNLOK_9263_BASE(6,3)  #end
#macro CON_DIS_MATNLOK_9263_14_4() CON_DIS_MATNLOK_9263_BASE(6,4)  #end
#macro CON_DIS_MATNLOK_9263_14_5() CON_DIS_MATNLOK_9263_BASE(6,5)  #end
#macro CON_DIS_MATNLOK_9263_15_1() CON_DIS_MATNLOK_9263_BASE(8,1)  #end
#macro CON_DIS_MATNLOK_9263_15_2() CON_DIS_MATNLOK_9263_BASE(8,2)  #end
#macro CON_DIS_MATNLOK_9263_15_3() CON_DIS_MATNLOK_9263_BASE(8,3)  #end
#macro CON_DIS_MATNLOK_9263_15_4() CON_DIS_MATNLOK_9263_BASE(8,4)  #end
#macro CON_DIS_MATNLOK_9263_15_5() CON_DIS_MATNLOK_9263_BASE(8,5)  #end
#macro CON_DIS_MATNLOK_9263_16_1() CON_DIS_MATNLOK_9263_BASE(10,1) #end
#macro CON_DIS_MATNLOK_9263_16_2() CON_DIS_MATNLOK_9263_BASE(10,2) #end
#macro CON_DIS_MATNLOK_9263_16_3() CON_DIS_MATNLOK_9263_BASE(10,3) #end
#macro CON_DIS_MATNLOK_9263_16_4() CON_DIS_MATNLOK_9263_BASE(10,4) #end
#macro CON_DIS_MATNLOK_9263_16_5() CON_DIS_MATNLOK_9263_BASE(10,5) #end









/********************************************************************************************************************************************
//Eurocard Verbinder
//Duane Clark <dclark@akamail.com>
********************************************************************************************************************************************/
#macro CON_EUROCARD_BASE(pins, rows)
union
{
  #local j = pins/rows;   // number of pins in row
  #local hs = 2.54;       // horizontal pin spacing
  #local hc = 0.9;        // horizontal centerline
  #local vs = 2.54;       // vertical pin spacing
  #local vc = 5.475;      // vertical centerline
  #local po = 7.63;       // offset to first pin
  #local ps = (j-1)*hs;   // total pin spacing
  #local mo = 2.55;       // offset to first mounting hole
  #local d = hc+10.1;     // overall body depth
  #local id = 6.4;        // inside depth
  #local w = ps+po*2;     // overall body width
  #local h = 10.95;       // overall body height
  #local io = 4.4;        // inner housing offset
  #local r = 0.5;         // pin inner radius
  #local pw = 0.60;       // pin width
  #local ph = 0.60;       // pin height
  #local pl = 8.5+vs;     // length of lower pins
  #local pcb = 1.625;     // pc board cutout height
  #local kh = 0.4;        // key height

  difference
  {
    union {
      box{<0,0,0><d,h,w> }
      // mounting hole tabs
      box{<d-12.5,0,0><0,7.125,5.1> }
      box{<d-12.5,0,w><0,7.125,w-5.1> }
    }
    // mounting hole cutouts
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> }
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> translate<0,0,w-5> }
    // mounting holes
    cylinder{<hc,-0.1,mo><hc,h,mo>1.4 }
    cylinder{<hc,-0.1,w-mo><hc,h,w-mo>1.4 }
    // pc board cutout
    box{<d-12.6,-0.1,-0.1><d-id-0.7,pcb,w+0.1> }
    // pin area cutout
    box{<d-id-0.001,1.125,io><d+0.1,h-3.625,w-io> }
    box{<d-id,2,io+1><d+0.1,h-1.125,w-io-1> }
    // upper side key outer cutouts
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> }
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> translate<0,0,w-4.175> }
    // front side cutouts
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> }
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> translate<0,0,w-3.175> }
    // front notches
    box{<d-1,-0.1,po+hs*0.5><d+0.1,h+0.1,po+hs*2.5> }
    box{<d-1,-0.1,po+hs*6.5><d+0.1,h+0.1,po+hs*8.5> }
    box{<d-1,-0.1,po+hs*16.5><d+0.1,h+0.1,po+hs*18.5> }
    box{<d-1,-0.1,po+ps-hs*6.5><d+0.1,h+0.1,po+ps-hs*8.5> }
    box{<d-1,-0.1,po+ps-hs*0.5><d+0.1,h+0.1,po+ps-hs*2.5> }
    // lower keys
    box{<d-id,1.126,po+hs*1><d,1.125-kh,po+hs*2> }
    box{<d-id,1.126,po+hs*7><d,1.125-kh,po+hs*8> }
    box{<d-id,1.126,po+hs*17><d,1.125-kh,po+hs*18> }
    box{<d-id,1.126,po+ps-hs*7><d,1.125-kh,po+ps-hs*8> }
    box{<d-id,1.126,po+ps-hs*1><d,1.125-kh,po+ps-hs*2> }
    // upper keys
    box{<d-id,h-1.126,po+hs*1><d,h-1.125+kh,po+hs*2> }
    box{<d-id,h-1.126,po+hs*7><d,h-1.125+kh,po+hs*8> }
    box{<d-id,h-1.126,po+hs*17><d,h-1.125+kh,po+hs*18> }
    box{<d-id,h-1.126,po+ps-hs*7><d,h-1.125+kh,po+ps-hs*8> }
    box{<d-id,h-1.126,po+ps-hs*1><d,h-1.125+kh,po+ps-hs*2> }
    pigment{Gray85}
  }

  // pins
  union
  {
    #local k = 0;
    #while(k<rows)
      #if (rows<3)
        #if (k>0)
          // if only two rows, then the center row is the one that is missing
          #local k = k+1;
        #end
      #end
      #local i = 0;
      #while(i<j)
        // horizontal pin
        box{<r+ph/2-pl-k*vs,0-ph/2,0-pw/2><0,ph/2,pw/2> translate<hc+8.5,vc+(k-1)*vs,po+i*hs>}
        // pin radius
        difference {
          cylinder{<0,0,0><0,0,pw>r+ph}
          cylinder{<0,0,-0.1><0,0,pw+0.1>r}
          box{<0,-2,-0.1><2,2,pw+0.1>}
          box{<-2,-2,-0.1><2,0,pw+0.1>}
          translate<hc-(k+1)*vs+r+ph/2,vc+(k-1)*vs-r-ph/2,po+i*hs-pw/2>
        }
        // vertical pin
        box{<-ph/2,-2,-pw/2><ph/2,vc+(k-1)*vs-r-ph/2,pw/2> translate<hc-(k+1)*vs,0,po+i*hs>}
        #local i = i+1;
      #end
      #local k = k+1;
    #end
    texture{col_gold}
  }

  translate<0-hc,0-pcb,0-w/2>
  translate<0,2,0>
}
#end
#macro CON_EUROCARD_96M_3_L()
CON_EUROCARD_BASE(96,3)
#end
#macro CON_EUROCARD_64M_2_L()
CON_EUROCARD_BASE(64,2)
#end




/********************************************************************************************************************************************
//FEMALE PRINT CONNECTOR DIN 45323 (34V/3A), ROKA, distributor Conrad
// Friedrich Bleikamp <fbleikamp@web.de>
********************************************************************************************************************************************/
#macro CON_FPCON65_BASE()
union {
//Kunstoff
difference {
merge {
cylinder{<0,6.5,0><10.5,6.5,0>4.25}
box {<0,0,-6>,<5.2,6.2,6>}
box {<0,0,-4>,<1.6,13,4> translate<-1.6,0,0>}
box {<0,0,-6>,<1.1,14,6> translate<-2.7,0,0>}
cylinder{<10.0,6.5,0><14.0,6.5,0>2.5}
}
cylinder{<-3,6.5,0><8.7,6.5,0>3.25}
cylinder{<8.5,6.5,0><14.6,6.5,0>2.25}
box {<0.1,-0.1,-3>,<9,14,3>}
box {<0.1,-0.1,-4.5>,<9,4.5,-5.5>}
box {<0.1,-0.1,4.5>,<9,4.5,5.5>}
pigment{Gray30}}

difference {
merge {
cylinder{<12.6,6.5,0><14,6.5,0>4.5}
box {<12.6,0,-4.5>,<14,6.5,4.5>}
box {<14,0,-4.5>,<15.5,2.5,4.5>}
}
cylinder{<12.5,6.5,0><14.1,6.5,0>2.55}
box {<0,0,-4.6>,<2,3.5,4.6> rotate <0, 0, 20> translate<15.4,-0.2,0>}
pigment{Gray30}}

//Mittenkontakt
difference {
merge {
sphere { <0, 6.5, 0>, 1.05}
cylinder{<0,6.5,0><6,6.5,0>1.05}
cylinder{<6,6.5,0><6.6,6.5,0>3}
cylinder{<6.6,6.5,0><12.1,6.5,0>2.1}
//Vernietung
difference {
torus { 2.1, 0.5 }
box {<-10,0,-10>,<10,-2.5,10> }
rotate <0, 0, -90> translate<12.0,6.5,0>}
translate<2.6,0,0> }
cone { <14.01, 6.5, 0>, 1.7, <13, 6.5, 0>, 0.0 }
cylinder{<14.0,6.5,0><18,6.5,0>1.7 }
texture{col_silver}}

//Loetanschluss Mitte
difference {
merge {
cylinder{<14,6.5,0><14.5,6.5,0>4}
box {<14,2.5,-4>,<14.5,6.5,4>}
object {TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25) rotate <90,90,180> translate<14.25,3.5,5.25>}
cylinder{<0.5,3.5,5><0.5,3.5,5.5>1 }
box {<1.25,0,5>,<3.75,2.5,5.5> }
object {TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25) rotate <-90,-90,180> translate<14.25,3.5,-5.25>}
box {<2,-2.5,5>,<3,0,5.5> }
cylinder{<0,3.5,-5><0,3.5,-5.5>1 translate<0.5,0,0>}
box {<1.25,0,-5>,<3.75,2.5,-5.5> }
box {<2,-2.5,-5>,<3,0,-5.5> }
}
cylinder{<13.9,6.5,0><14.6,6.5,0>2 }
texture{col_silver} }

//Loetanschluss Schalter
difference {
merge {
cylinder{<10.5,6.5,0><11.0,6.5,0>4 }
object {TOOLS_RECT_BOGEN(0.3,85,0.5,4,3,5) rotate <0,180,90> translate<10.75,11.75,0>}
sphere { <6.5, 11.6, 0>, 0.5 translate<0,0,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.5,3,3,2.2) rotate <0,0.0,90> translate<10.75,1.8,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.51,1,2.5,0.3) rotate <0,0,-90> translate<8.4,0.6,0>}
}
cylinder{<10.4,6.5,0><11.1,6.5,0>2.55}
texture{col_silver}}

//Isolierscheibe
difference {
cylinder{<11.0,6.5,0><11.5,6.5,0>4.5 }
cylinder{<10.9,6.5,0><11.6,6.5,0>2.51 }
pigment{Sienna}}

//Federkontakt Aussen
difference {
merge {
cylinder{<11.5,6.5,0><12.0,6.5,0>4 }
box {<11.5,4.5,-3.25>,<12.0,1.0,3.25>}
}
cylinder{<11.4,6.5,0><12.1,6.5,0>2.55 }
texture{col_silver}}

//Loetanschluss Aussen u. Schalter
difference {
merge {
cylinder{<12.05,6.5,0><12.6,6.5,0>4 }
object {TOOLS_RECT_BOGEN(0.75,39.85,0.5,4,4,0) rotate <0,180,90> translate<12.3,13.5,0>}
object {TOOLS_RECT_BOGEN(0.3,132.0,0.5,4,7.98,0) rotate <0,180,7.5> translate<10.7,13,0>}
object {TOOLS_RECT_BOGEN(0.3,90,0.5,4,0,1.65) rotate <180,0,7.5> translate<1.8,11.83,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.5,4,2,0) rotate <0,0,-27.5> translate<1.88,9.52,0>}
object {TOOLS_RECT_BOGEN(0.5,125,0.5,4,2,0) rotate <0,0,22.5> translate<4.08,8.03,0>}
box {<12.05,4.5,-1.5>,<12.6,0,1.5>}
box {<12.05,0,-0.5>,<12.5,-2.5,0.5>}
}
cylinder{<11.9,6.5,0><12.7,6.5,0>2.55 }
texture{col_silver}}
}
#end
#macro CON_FPCON65()
CON_FPCON65_BASE()
#end


/********************************************************************************************************************************************
//Macros for L115 100 junction bloc by LMI
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 du 04/01/06
********************************************************************************************************************************************/
#macro CON_LMI_L115_BASE(n)
// Macro for pin
#local CosseL115 =
union {
    difference {
        union {
            box{<-0.25,-4.5,-1.4><+0.25,+15,+1.4>  } 
            box{<-0.25,-4.5,-1.8><+0.25,+6.8,+1.4> }
        }
        
        union {  
            //connexion side pin bisel
            //length bisel
            box{<-1,-1,-3><+1,+1,+3>        rotate<0,0,45> translate<-1.1,15.4,0> }
            box{<-1,-1,-3><+1,+1,+3>        rotate<0,0,45> translate<+1.1,15.4,0> }
            //width bisel
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,15,+2.5> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,15,-2.5> }
            //solder side pin bisel
            box{<-0.8,0,-0.65><+0.8,-5,-5>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-0.8,0,+0.65><+0.8,-5,+5>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-1,-1,-1><+1,+1,+1>        rotate<120,0,0> translate<0,-4.5,+1.3> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<60,0,0> translate<0,-4.55,-1.3> }
            //holes
            cylinder { -2*x, +2*x, .4       translate <0, 12, 0> }
            cylinder { -2*x, +2*x, 1.1      translate <0, 3, 0> }
        }
    }
    texture{ pigment{P_Silver2} }
    rotate 90*y
}

#local PAS = 5.08;
union {
    //terminals
    #local i=0; 
    #while (i<n)
        //Pins
        object{CosseL115 translate<0,0,-(PAS/2*(n-1))+(i*PAS)>}
    #local i=i+1; #end
    //body
    difference {
        union {
            difference {
                box{<2.75,5,-PAS*n/2><-2.75,6,+PAS*n/2> }
                box{<1.6,5.6,-PAS*n/2-0.01><-2.0,6.01,+PAS*n/2+0.01> }
            }
            box{<-2.75,0,-PAS*n/2><-1.8,5,+PAS*n/2> }
        }  
        #local i=1; 
        #while (i<n)
            //rectangular holes
            box{<-1.2,4,-0.25><+0.8,7,+0.25> translate<0,0,-(PAS/2*(n-1))+(i*PAS)-PAS/2>}
        #local i=i+1; #end
    }
    pigment{Gray80}
    rotate 90*y

}
#end
#macro CON_LMI_L115_2()
CON_LMI_L115_BASE(2)
#end
#macro CON_LMI_L115_3()
CON_LMI_L115_BASE(3)
#end
#macro CON_LMI_L115_5()
CON_LMI_L115_BASE(5)
#end
#macro CON_LMI_L115_10()
CON_LMI_L115_BASE(10)
#end
#macro CON_LMI_L115_20()
CON_LMI_L115_BASE(20)
#end


/********************************************************************************************************************************************
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Loetoese 1.0mm Drill fuer Drahtanschluss oder Testklemme
********************************************************************************************************************************************/
#macro CON_LSP_BASE(s)
union {
   difference {
      box { <-0.8,0,-0.2>,<0.8,5,0.2> texture{col_silver} translate<0,0,0>}
      box { <-0.8,-0.2,-0.3>,<0.8,5.2,0.3> texture{col_silver} rotate<0,0,-3> translate<1.1,0,0>}
      box { <-0.8,-0.2,-0.3>,<0.8,5.2,0.3> texture{col_silver} rotate<0,0,3> translate<-1.1,0,0>}
      translate<0,-5.0,0>
   }
   difference {
      box { <-1.5,0,-0.2>,<1.5,3,0.2> texture{col_silver} translate<0,0,0>}
      box { <-0.5,1.5,-0.3>,<0.5,3.1,0.3> texture{col_silver} translate<0,0,0>}
      cylinder{<0,0,-0.3><0,0,0.3>0.5 texture{col_silver} translate<0,1.5,0>}
   }
   difference {
      cylinder{<0,0,-0.2><0,0,0.2>1.5 texture{col_silver} translate<0,3,0>}
      cylinder{<0,0,-0.3><0,0,0.3>0.5 texture{col_silver} translate<0,3,0>}
      box { <-1.5,0,-0.3>,<1.5,3,0.3> texture{col_silver} translate<0,0,0>}
   }
   scale (s/13)
}
#end
#macro CON_LSP_10()
CON_LSP_BASE(10)
#end
#macro CON_LSP_11()
CON_LSP_BASE(11)
#end
#macro CON_LSP_13()
CON_LSP_BASE(13)
#end


/********************************************************************************************************************************************
//Macros for Micro-Match female from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  16/12/07
********************************************************************************************************************************************/
#macro CON_MICROMATCH_FEMALE_BASE(pin)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6}};
#local pitch=1.27;
#local plastic_z=5;

#local plastic_x=pitch*(pin-1)+3.37;

union {
    difference {
        union {
            box{<-plastic_x/2,0.5,-plastic_z/2><plastic_x/2,2.1,plastic_z/2> } //Main box
            box{<-plastic_x/2+0.5,0.5,-plastic_z/2+0.5><plastic_x/2-0.5,4,plastic_z/2-0.5> } //Main box
        }
        box{<-plastic_x/2+0.5,0,-plastic_z/2+1><-plastic_x/2-0.1,4.1,plastic_z/2-1>}//Main box hollowing out
        box{<+plastic_x/2-0.5,0,-plastic_z/2+1><+plastic_x/2+0.1,4.1,plastic_z/2-1>}//Main box hollowing out
                #local i=0;
                #while(i<(pin/2)) //contacts apertures
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    #local i=0;
    #while(i<(pin/2))
    //pins
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        
        cylinder{<0,1,-1.4><0,3.9,-1.4> 0.15 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
        cylinder{<0,1,1.4><0,3.9,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
        difference {
            box{<-0.15,1,0><0.15,3.9,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
            box{<-0.2,1,0.5><0.2,4,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
        }
        difference {
            box{<-0.15,1,0><0.15,3.9,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> }
            box{<-0.2,1,-0.5><0.2,4,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> }
        }
        #local i=i+1;
    #end
    pigment {Silver}
}
        
#end


#macro CON_MICROMATCH_FEMALE_4()
CON_MICROMATCH_FEMALE_BASE(4)
#end
#macro CON_MICROMATCH_FEMALE_6()
CON_MICROMATCH_FEMALE_BASE(6)
#end
#macro CON_MICROMATCH_FEMALE_8()
CON_MICROMATCH_FEMALE_BASE(8)
#end
#macro CON_MICROMATCH_FEMALE_10()
CON_MICROMATCH_FEMALE_BASE(10)
#end
#macro CON_MICROMATCH_FEMALE_12()
CON_MICROMATCH_FEMALE_BASE(12)
#end
#macro CON_MICROMATCH_FEMALE_14()
CON_MICROMATCH_FEMALE_BASE(14)
#end
#macro CON_MICROMATCH_FEMALE_16()
CON_MICROMATCH_FEMALE_BASE(16)
#end
#macro CON_MICROMATCH_FEMALE_18()
CON_MICROMATCH_FEMALE_BASE(18)
#end
#macro CON_MICROMATCH_FEMALE_20()
CON_MICROMATCH_FEMALE_BASE(20)
#end


/********************************************************************************************************************************************
// Makro fuer AMP-tyco MicroMatch-Federleiste SMD-Ausfuehrung
// pin  - Anzahl Kontakte
// frm = 0 - smd, != 0 - Bedrahtet
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro CON_MICROMATCH_BASE(pin, frm)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6} finish{ambient (0.1 * global_ambient_mul)}};
#local pitch=1.27;
#local plastic_z=5;
#local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet
#if (frm = 0)
        #local plastic_Y=5.3;
#else
        #local plastic_Y=4.0;
#end

union   {
        difference {
                union   {
                        // Grundkoerper
                        box{<-plastic_x/2+0.5, 0 ,-plastic_z/2+0.5> <plastic_x/2-0.5, plastic_Y, plastic_z/2-0.5> }
                        
                        // Kranz

                        #if (frm = 0)
                                // SMD
                                difference {
                                        box{<-plastic_x/2,1.9,-plastic_z/2> <plastic_x/2    ,3.3,plastic_z/2>}
                                        #local i=0;
                                        #while(i<(pin/2))
                                                box{<-0.5,2.4,0><0.5,3.5,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                                box{<-0.5,2.4,-5><0.5,3.5,0> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                                #local i=i+1;
                                        #end
                                        box{<0,0,-plastic_z/4><plastic_x+1,5,plastic_z/4>}
                                }
                        #else                   
                                // Bedrahtet
                                box{<-plastic_x/2, 0.4 ,-plastic_z/2> <plastic_x/2, 2.0, -1.2>}
                                box{<-plastic_x/2, 0.4 , plastic_z/2> <plastic_x/2, 2.0, 1.2>}
                        #end
                }
                        
                // Ausschnitte im Kunststoff fuer SMD Pins
                #if (frm = 0)
                        #local i=0;
                        #while(i<(pin/2))
                                box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                #local i=i+1;
                        #end
                #end

                // Loecher fuer Stecker
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end

                texture{CON_MMTCH_PLASTIC_TEXTURE}
        }

        #if (frm = 0)
                // SMD Pins
                #local i=0;
                #while(i<(pin/2))
                        object{TOOLS_PCB_SMD(1,6,0.25,8) translate<0.5,-0.125,0.5> rotate<0,0,90> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture{col_silver}}
                        object{TOOLS_PCB_SMD(1,6,0.25,8) translate<-0.5,-0.125,-0.5> rotate<0,0,-90> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture{col_silver}}        
                        #local i=i+1;
                #end
        #else
                // Anschlussdraht
                #if(pin_short=off)
                        #local pp=3.0;
                #else
                        #local pp=pcb_height+pin_length;
                #end
        
                #local i=0;
                #local j=1;
                #while(i<(pin/2))
                        box{ <-pitch/2-pitch*i-0.1, 1,-pitch*j-0.25> <-pitch/2-pitch*i+0.1, -pp,-pitch*j+0.25> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
                        box{ < pitch/2+pitch*i+0.1, 1, pitch*j+0.25> < pitch/2+pitch*i-0.1, -pp, pitch*j-0.25> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
                        #local j=j*-1;
                        #local i=i+1;
                #end
        #end
}
        
#end
#macro CON_MICROMATCH_4()
CON_MICROMATCH_BASE(4,1)
#end
#macro CON_MICROMATCH_6()
CON_MICROMATCH_BASE(6,1)
#end
#macro CON_MICROMATCH_8()
CON_MICROMATCH_BASE(8,1)
#end
#macro CON_MICROMATCH_10()
CON_MICROMATCH_BASE(10,1)
#end
#macro CON_MICROMATCH_12()
CON_MICROMATCH_BASE(12,1)
#end
#macro CON_MICROMATCH_14()
CON_MICROMATCH_BASE(14,1)
#end
#macro CON_MICROMATCH_16()
CON_MICROMATCH_BASE(16,1)
#end
#macro CON_MICROMATCH_18()
CON_MICROMATCH_BASE(16,1)
#end
#macro CON_MICROMATCH_20()
CON_MICROMATCH_BASE(20,1)
#end


/********************************************************************************************************************************************
//Macros for Micro-Match male from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  16/12/07
********************************************************************************************************************************************/
#macro CON_MICROMATCH_MALE_BASE(pin)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6}};
#local pitch=1.27;
#local plastic_z=5;

#local plastic_x=pitch*(pin-1)+3.37;

union {
    difference {
        union {
            box{<-plastic_x/2,0,-plastic_z/2><plastic_x/2,3.6,plastic_z/2> } //Main box
            difference {//left hook
                box{<-0.5,-1,-0.5><0.5,1,0.5> rotate<0,0,30> translate<-plastic_x/2+0.2,2,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<-plastic_x/2,3.5,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<-plastic_x/2-1.5,2.5,0> }
            }
            difference {//right hook
                box{<-0.5,-1,-0.5><0.5,1,0.5> rotate<0,0,-30> translate<+plastic_x/2-0.2,2,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<+plastic_x/2,3.5,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<+plastic_x/2+1.5,2.5,0> }
            }
        }
        box{<-plastic_x/2+0.65,1.7,-plastic_z/2+0.5><plastic_x/2-0.65,3.61,plastic_z/2-0.5>}//Main box hollowing out
        box{<-plastic_x/2+0.65,-0.1,-plastic_z/2-0.5><plastic_x/2-0.65,0.4,plastic_z/2+0.5>}//Base hollowing out
        box{<-plastic_x/2-0.65,-0.1,-0.65><plastic_x/2+0.65,0.4,+0.65>}//Base hollowing out
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    difference {//Detrompeur
        union {
            box{<-plastic_x/2,3.6,-1.16><-plastic_x/2+0.65,7.1,1.16> } //top part
            box{<-plastic_x/2,3.6,-1.16-0.3><-plastic_x/2+0.65,3.6+0.3,1.16+0.3> } //down part        
        }
        cylinder{<-plastic_x/2-0.1,3.6+0.3,-1.16-0.3><-plastic_x/2+0.66,3.6+0.3,-1.16-0.3> 0.3}
        cylinder{<-plastic_x/2-0.1,3.6+0.3,+1.16+0.3><-plastic_x/2+0.66,3.6+0.3,+1.16+0.3> 0.3}
        box{<-plastic_x/2-0.1,5.5,0><-plastic_x/2+0.66,7.11,+1.161>}
        box{<-0.5,-0.82,-0.82><+0.5,+0.82,+0.82> rotate<45,0,0> translate<-plastic_x/2+0.3,5.5,+1.16>}                        
        box{<-0.5,-0.2,-0.2><+0.5,+0.2,+0.2> rotate<45,0,0> translate<-plastic_x/2+0.3,7.1+0.1,+0.1>}//biseaux
        box{<-0.5,-0.2,-0.2><+0.5,+0.2,+0.2> rotate<45,0,0> translate<-plastic_x/2+0.3,7.1+0.1,-1.16-0.1>}
        rotate 180*y    
            
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    #local i=0;
    #while(i<(pin/2))
    //pins
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
    //contacts    
        difference {
            box{<-0.35,1,-0.2><+0.35,3.6-0.2,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,0,0> translate<-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75+0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<+10,0,0> translate<-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75-0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,90,0> translate<-(plastic_x-3.37)/2+i*2.54+0.5,3.6-0.2,-0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,-90,0> translate<-(plastic_x-3.37)/2+i*2.54-0.5,3.6-0.2,-0.75> }
        }
        difference {
            box{<-0.35,1,-0.2><+0.35,3.6-0.2,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+0.75>}
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,0,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75+0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<+10,0,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75-0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,90,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54+0.5,3.6-0.2,+0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,-90,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54-0.5,3.6-0.2,+0.75> }
        }
        #local i=i+1;
    #end
    pigment {Silver}
}
        
#end


#macro CON_MICROMATCH_MALE_4()
CON_MICROMATCH_MALE_BASE(4)
#end
#macro CON_MICROMATCH_MALE_6()
CON_MICROMATCH_MALE_BASE(6)
#end
#macro CON_MICROMATCH_MALE_8()
CON_MICROMATCH_MALE_BASE(8)
#end
#macro CON_MICROMATCH_MALE_10()
CON_MICROMATCH_MALE_BASE(10)
#end
#macro CON_MICROMATCH_MALE_12()
CON_MICROMATCH_MALE_BASE(12)
#end
#macro CON_MICROMATCH_MALE_14()
CON_MICROMATCH_MALE_BASE(14)
#end
#macro CON_MICROMATCH_MALE_16()
CON_MICROMATCH_MALE_BASE(16)
#end
#macro CON_MICROMATCH_MALE_18()
CON_MICROMATCH_MALE_BASE(18)
#end
#macro CON_MICROMATCH_MALE_20()
CON_MICROMATCH_MALE_BASE(20)
#end


/********************************************************************************************************************************************
// Makro fuer AMP-tyco MicroMatch-Federleiste SMD-Ausfuehrung
// pin  - Anzahl Kontakte
********************************************************************************************************************************************/
#macro CON_MICROMATCH_SMD_BASE(pin)
#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6} finish{ambient (0.1 * global_ambient_mul)}};
#local pitch=1.27;
#local plastic_z=5;
#local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet

union   {
        difference {
                union   {
                        box{<-plastic_x/2+0.5,0,-plastic_z/2+0.5><plastic_x/2-0.5,5.3,plastic_z/2-0.5>}
                        difference {
                                box{<-plastic_x/2,1.9,-plastic_z/2>      <plastic_x/2    ,3.3,plastic_z/2>}
                                #local i=0;
                                #while(i<(pin/2))
                                        box{<-0.5,2.4,0><0.5,3.5,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                        box{<-0.5,2.4,-5><0.5,3.5,0> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                        #local i=i+1;
                                #end
                                box{<0,0,-plastic_z/4><plastic_x+1,5,plastic_z/4>}
                                }
                        }
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
                texture{CON_MMTCH_PLASTIC_TEXTURE}
                }
        #local i=0;
        #while(i<(pin/2))
                object{TOOLS_PCB_SMD(1,6,0.25,8) translate<0.5,-0.125,0.5> rotate<0,0,90> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture{col_silver}}
                object{TOOLS_PCB_SMD(1,6,0.25,8) translate<-0.5,-0.125,-0.5> rotate<0,0,-90> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture{col_silver}}        
                #local i=i+1;
        #end
        }
        
#end
#macro CON_MICROMATCH_SMD_4()
CON_MICROMATCH_SMD_BASE(4)
#end
#macro CON_MICROMATCH_SMD_6()
CON_MICROMATCH_SMD_BASE(6)
#end
#macro CON_MICROMATCH_SMD_8()
CON_MICROMATCH_SMD_BASE(8)
#end
#macro CON_MICROMATCH_SMD_10()
CON_MICROMATCH_SMD_BASE(10)
#end
#macro CON_MICROMATCH_SMD_12()
CON_MICROMATCH_SMD_BASE(12)
#end
#macro CON_MICROMATCH_SMD_14()
CON_MICROMATCH_SMD_BASE(14)
#end
#macro CON_MICROMATCH_SMD_16()
CON_MICROMATCH_SMD_BASE(16)
#end
#macro CON_MICROMATCH_SMD_18()
CON_MICROMATCH_SMD_BASE(16)
#end
#macro CON_MICROMATCH_SMD_20()
CON_MICROMATCH_SMD_BASE(20)
#end


/********************************************************************************************************************************************
// Makro fuer einfache MODULAR-Buchsen RJ-45 (8pol) RJ-12 (6pol) RJ11 (4pol) u.ae.,    con-amp.lib ,     Joerg Bredendiek <sprut(replace with at)sprut.de>   
//
// plastik schwarz, Schirmung Silber
// Darstellung ist vereinfacht 
// 
//
// pins   = Anzahl der Pins , 2, 4, 6, 8
// a      = Abstand zwischen den Mitten der Montagestifte  
// o      = Abstand zwischen Mittlepunkt und Verbindungslinie der Befestigungszapfen (Offset)  
// schirm = 0-kein, 1-voll, 2-teilweise  
// stop   = 0-kein, 1-panel-stop
********************************************************************************************************************************************/
#macro CON_MODULAR_BASE(pins,a,o,schirm,stop)
#local tex_rj45_pastic1= texture { pigment{White*0.3} finish {specular 1 roughness 0.001 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;   //etwas glatter/glaenzender
#local tex_rj45_pastic = texture { pigment{White*0.3} finish {specular 0.1 roughness 0.1 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;
// Aussenabmasse 6 pins : 13.4  x  12.8  x  18.0 BHT   
// Breite ist bauformabhaengig

#local bb = a+3;
#local bh = 12.8;
#local bt = 18.0;          


// Ausbruch im Kunststoff
// 4 pin ??
// 6 pin - 10 mm
// 8 pin - 12 mm
#local stecker2 = 
      difference
      {
         union
         {
            box{<-bb/2+1.5,  3.7, -11.7><bb/2-1.5, 11.5, 4.8>}
            box{<-bb/2+3.1,  2.5, -11.7><bb/2-3.1, 11.5, 4.8>}
            box{<-bb/2+5.6,  0.7, -11.7><bb/2-5.6, 11.5, 4.8>}
            box{<-1  , -1  , -2><16      ,  1  ,  2  >rotate<-30,0,0>translate<-bb/2,4.4,-21.4/2> pigment{White*0.5}}
            box{<-1  ,  0  , -1><16      ,  0.5,  1  >rotate<-30,0,0>translate<-bb/20,2.0,-21.4/2> pigment{White*0.5}}
         }
         box{<-bb/2-1   , -1  ,  4.3 >< -bb/2+ 16  ,15 , 5.3>}
         box{<-bb/2-1   , -1  ,-11.7 >< -bb/2+ 1.6 ,15 , 5.3>}
         box{<-bb/2+14.2, -1  ,-11.7 >< -bb/2+ 16  ,15 , 5.3>}
      }; 
      

#local pin_intern =
   sphere_sweep {
      b_spline
      9,
      <-0.635, 10.0,  17-21.4/2>,   0.2
      <-0.635, 12.0,  17-21.4/2>,   0.2
      <-0.635, 12.5,  17-21.4/2>,   0.2
      <-0.635, 12.5,  6-21.4/2>,   0.2
      <-0.635, 11.7,  6-21.4/2>,   0.2
      <-0.635, 11.0,  6.5-21.4/2>, 0.2
      <-0.635, 10.3, 10-21.4/2>,  0.2
      <-0.635, 8.0, 16-21.4/2>,  0.2
      <-0.635, 8.0, 18-21.4/2>,  0.2
      texture{col_gold} 
   }              
   
#local pin_channel = box{<-0.635-0.31 , bh-0.5, -5>< -0.635+0.31 , bh+1 , -8+bt> texture{tex_rj45_pastic}}  
           
           
union
{                 
        #if (schirm=1)  
        // voll geschrimt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local bb = a+3;
        #local bh = 12.8;
        #local bt = 18.0;  
        #local sb = 14+1;
        #if (a>11)
                #local sb = 15.5+1;
        #end        
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten        
        union {          
                difference {
                        box{<-sb/2, 0, -8.5 > < sb/2, bh+1 , -8+bt+1> texture{T_Chrome_5B}}                      //Ummantelung                      
                        box{<-bb/2, 0, -8   > < bb/2, bh   , -8+bt  > texture{T_Chrome_5B}}                      //Aushoehlung
                        box{<-sb/2-0.1, bh+0.5, -8.6 > < -sb/2+0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}      //obere Seitenkannten ausfraesen                  
                        box{< sb/2+0.1, bh+0.5, -8.6 > <  sb/2-0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}  
                        box{<-sb/2-0.1, bh+0.5, -8+bt+1.1 > <  sb/2+0.1, bh+1.1, -8+bt+0.5> texture{T_Chrome_5B}}//obere hinterkannte     
                        box{<-sb/2-0.1, bh+0.5, -8        > <  sb/2+0.1, bh+1.1, -8.6   > texture{T_Chrome_5B}}  //obere vorderkannte
                        box{< sb/2+0.1, bh+1.1, -8+bt+0.5 > <  sb/2-0.5, -0.1, -8+bt+1.1> texture{T_Chrome_5B}}  //senkrechte hinterkannten
                        box{<-sb/2-0.1, bh+1.1, -8+bt+0.5 > < -sb/2+0.5, -0.1, -8+bt+1.1> texture{T_Chrome_5B}}                        
                        box{< sb/2+0.1, bh+1.1, -8        > <  sb/2-0.5, -0.1, -8.6> texture{T_Chrome_5B}}  //senkrechte vordererkannten
                        box{<-sb/2-0.1, bh+1.1, -8        > < -sb/2+0.5, -0.1, -8.6> texture{T_Chrome_5B}}  
                        stecker2                                           
                }                           
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                     // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                     // rechte Loetasche                   
                cylinder{<-sb/2+0.5, bh+0.5, -8        > < -sb/2+0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}  // obere Seitenkannten abrunden       
                cylinder{< sb/2-0.5, bh+0.5, -8        > <  sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}    
                cylinder{<-sb/2+0.5, bh+0.5, -8+bt+0.5 > <  sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}  // obere hinterkannte 
                cylinder{<-sb/2+0.5, bh+0.5, -8        > <  sb/2-0.5, bh+0.5, -8       > 0.5 texture{col_silver}}  // obere vorderkannte                                
                cylinder{<-sb/2+0.5, bh+0.5, -8+bt+0.5 > < -sb/2+0.5, 0, -8+bt+0.5> 0.5 texture{col_silver}}       // senkrechte hinterkannten   
                cylinder{< sb/2-0.5, bh+0.5, -8+bt+0.5 > <  sb/2-0.5, 0, -8+bt+0.5> 0.5 texture{col_silver}}  
                cylinder{<-sb/2+0.5, bh+0.5, -8        > < -sb/2+0.5, 0, -8       > 0.5 texture{col_silver}}       // senkrechte vorderkannten   
                cylinder{< sb/2-0.5, bh+0.5, -8        > <  sb/2-0.5, 0, -8       > 0.5 texture{col_silver}}  
                sphere{< sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5  texture{col_silver}} 
                sphere{<-sb/2+0.5, bh+0.5, -8+bt+0.5> 0.5  texture{col_silver}}                                    // Eck-Kugeln hinten
                sphere{< sb/2-0.5, bh+0.5, -8       > 0.5  texture{col_silver}} 
                sphere{<-sb/2+0.5, bh+0.5, -8       > 0.5  texture{col_silver}}                                    // Eck-Kugeln vorn
        }                                   
        #end
        
                   
           
        
        #if (schirm=2)        
        //teilgeschirmt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local sb = bb+0.8;
        #if (a>11)
                #local sb = 15.5+1;
        #end           
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten       
        union {          
                difference {
                        box{<-sb/2+0.5, 0, -8.5 > < sb/2-0.5, bh+0.5 ,  -8  > texture{T_Chrome_5B}}                // Frontplatte                                            
                        stecker2                                                                                   // Durchbrueche
                }                                                                                                     
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                     // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                     // rechte Loetasche        
                cylinder{<-sb/2+0.5, bh, -8        > <  sb/2-0.5, bh, -8       > 0.5 texture{col_silver}}  // obere vorderkannte                                
                cylinder{<-sb/2+0.5, bh, -8        > < -sb/2+0.5, 0, -8       > 0.5 texture{col_silver}}       // senkrechte vorderkannten   
                cylinder{< sb/2-0.5, bh, -8        > <  sb/2-0.5, 0, -8       > 0.5 texture{col_silver}}  

                box{<-sb/2, 0, -8 > < -sb/2+0.4, bh ,  -2  > texture{T_Chrome_5B}}                         // linkes Seitenblech                                    
                box{< sb/2, 0, -8 > <  sb/2-0.4, bh ,  -2  > texture{T_Chrome_5B}}                         // rechtes Seitenblech  
                
                box{<-sb/2+0.5, bh, -8 > < -sb/2+2.5, bh+0.5 ,  -2  > texture{T_Chrome_5B}}                // oben links
                box{< sb/2-2.5, bh, -8 > <  sb/2-0.5, bh+0.5 ,  -2  > texture{T_Chrome_5B}}                // oben rechts      
                
                box{<sb/2-2.7, -0.50, 0><-sb/2+2.7, 0, 6> rotate<-15,0,0> translate<0, bh+0.5, -8.3> texture{T_Chrome_5B} }                
        }               
        #end
        
           
           
        
        #if (schirm=3)        
        //teilgeschirmt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local sb = bb+0.8;
        #if (a>11)
                #local sb = 15.5+1;
        #end           
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten       
        union {          
                difference {
                        box{<-sb/2, 0, -8.2 > < sb/2, bh+0.4 ,  -2  > texture{T_Chrome_5B}}                      //Ummantelung                      
                        box{<-bb/2, 0, -8   > < bb/2, bh   , -8+bt  > texture{T_Chrome_5B}}                      //Aushoehlung
                        box{<-sb/2-0.1, bh+0.5, -8 > < -sb/2+0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}        //obere Seitenkannten ausfraesen                  
                        box{< sb/2+0.1, bh+0.5, -8 > <  sb/2-0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}} 
                        stecker2 
                }                           
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                  // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                  // rechte Loetasche 
        }               
        #end
        
           
           
           
   // Plastik
   difference
   {         
           union
           {             
              box{<-bb/2 , 0, -5>< bb/2 , bh , -8+bt> texture{tex_rj45_pastic}}  // hinterer Teil matter
              box{<-bb/2 , 0, -8>< bb/2 , bh , -5   > texture{tex_rj45_pastic1}} // vordere 3mm glaenzen mehr         
      }
      stecker2                                                                   // Ausspartungen fuer Stecker
      box{<-bb/2-1 , -2, -8+bt+5>< bb/2+1 , bh+2 , -8+bt+1> rotate<-20,0,0> texture{tex_rj45_pastic}}  //hintere Abschaegung  
      // Kanaele fuer Anschlussdraehte an der Oberseite der Buchse
           pin_channel  
           object{pin_channel  translate<+1.27     , 0, 0>}
           #if (pins>2)
           object { pin_channel  translate<+1.27-2.54, 0, 0>}
           object { pin_channel  translate< 2.54     , 0, 0>}                                                             
           #end
           #if (pins>4)
           object { pin_channel  translate<+1.27+2.54,0,0>}
           object { pin_channel  translate<-2.54,0,0>}
           #end                                                                                                   
           #if (pins=8)
           object { pin_channel  translate<+5.08,0,0>}
           object { pin_channel  translate<+1.27-5.08,0,0>}
                #end
   }       
       
   //Panel-stops 
   #if (schirm>1)  
             #local stop=1;
        #end

   #if (stop=1)   
   //seitliche plastik-laschen 1.4mm dick
   box{<-bb/2-1 , 3, -6.4>< -bb/2 , bh-3 , -5>  texture{tex_rj45_pastic}}
   box{< bb/2+1 , 3, -6.4><  bb/2 , bh-3 , -5>  texture{tex_rj45_pastic}}   
   #end
   
   
 
   // Plastikfuesse zur Befestigung
   difference
   {
      cylinder{< a/2, -3.5, 0>< a/2, 1, 0> 1.4}
      box{<a/2-0.3,-4,-5><a/2+0.3,-0.5,5>}
      texture{tex_rj45_pastic}
   }
   difference
   {
      cylinder{<-a/2, -3.5, 0><-a/2, 1, 0> 1.4}
      box{<-a/2-0.3,-4,-5><-a/2+0.3,-0.5,5>}
      texture{tex_rj45_pastic}
   }
     
   // Pins auf der Platine   
   // hintere Pinreihe liegt 8.89 mm hinter den Befestigungsstiften
   cylinder{<-0.635     , 1, 8.89     ><-0.635     , -3.5, 8.89     > 0.25 texture{col_gold}}   
   cylinder{<+0.635     , 1, 8.89-2.54><+0.635     , -3.5, 8.89-2.54> 0.25 texture{col_gold}}   
   #if (pins>2)   
   cylinder{<-0.635+2.54, 1, 8.89     ><-0.635+2.54, -3.5, 8.89     > 0.25 texture{col_gold}}
   cylinder{<+0.635-2.54, 1, 8.89-2.54><+0.635-2.54, -3.5, 8.89-2.54> 0.25 texture{col_gold}}  
   #end
   #if (pins>4)
   cylinder{<+0.635+2.54, 1, 8.89-2.54><+0.635+2.54, -3.5, 8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<-0.635-2.54, 1, 8.89     ><-0.635-2.54, -3.5, 8.89     > 0.25 texture{col_gold}}
   #end
   #if (pins=8)
   cylinder{<-0.635+5.08, 1, 8.89     ><-0.635+5.08, -3.5, 8.89     > 0.25 texture{col_gold}}
   cylinder{<+0.635-5.08, 1, 8.89-2.54><+0.635-5.08, -3.5, 8.89-2.54> 0.25 texture{col_gold}}
   #end
        
        //Pins innerhalb der Buchse
   object { pin_intern }   
   object { pin_intern  translate<+1.27     , 0, 0>}
   #if (pins>2)
   object { pin_intern  translate<+1.27-2.54, 0, 0>}
   object { pin_intern  translate< 2.54     , 0, 0>}                                                             
   #end
   #if (pins>4)
   object { pin_intern  translate<+1.27+2.54,0,0>}
   object { pin_intern  translate<-2.54,0,0>}
   #end                                                                                                   
   #if (pins=8)
   object { pin_intern  translate<+5.08,0,0>}
   object { pin_intern  translate<+1.27-5.08,0,0>}
   #end      
   
   translate<0, 0, -o>
}
#end



#macro CON_MODULAR_RJ45()
CON_MODULAR_BASE(8, 11.43, 0, 0, 0)
#end
#macro CON_MODULAR_RJ12()
CON_MODULAR_BASE(6, 11.43, 0, 0, 0)
#end
#macro CON_MODULAR_RJ11()
CON_MODULAR_BASE(4, 11.43, 0, 0, 0)
#end
#macro CON_MODULAR_RJ45_SCH()
CON_MODULAR_BASE(8, 11.43, 0, 1, 0)
#end
#macro CON_MODULAR_RJ12_SCH()
CON_MODULAR_BASE(6, 11.43, 0, 1, 0)
#end
#macro CON_MODULAR_RJ11_SCH()
CON_MODULAR_BASE(4, 11.43, 0, 1, 0)
#end
#macro CON_MODULAR_215875_3()
CON_MODULAR_BASE(4, 6*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215876_6()
CON_MODULAR_BASE(4, 8*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215876_7()
CON_MODULAR_BASE(2, 8*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215877_4()
CON_MODULAR_BASE(8, 9*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215877_7()
CON_MODULAR_BASE(8, 9*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215878_2()
CON_MODULAR_BASE(8, 9*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_555164_1()
CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555165_1()
CON_MODULAR_BASE(6, 8*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555165_2()
CON_MODULAR_BASE(4, 8*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555165_5()
CON_MODULAR_BASE(2, 8*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555166_1()
CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555165_3()
CON_MODULAR_BASE(4, 9*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555167_1()
CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555167_2()
CON_MODULAR_BASE(6, 9*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555162_1()
CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555163_1()
CON_MODULAR_BASE(6, 8*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555163_2()
CON_MODULAR_BASE(4, 8*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555140_1()
CON_MODULAR_BASE(6, 8*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555140_2()
CON_MODULAR_BASE(4, 8*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555153_1()
CON_MODULAR_BASE(8, 9*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555154_1()
CON_MODULAR_BASE(6, 8*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555154_2()
CON_MODULAR_BASE(4, 8*1.27, 0, 2, 1)
#end


/********************************************************************************************************************************************
//Molex 53047 ( 1.25 pitch, vertical feeding, through holes )
//antoine.drouin@free.fr
//n      Number of Pins
********************************************************************************************************************************************/
#macro CON_MOLEX_53047_BASE(n)
union {
  #local L = n * 1.25 + 1.75;
  #local l = 3.2;
  #local h = 4.2;
   difference {
     box {<-L/2, 0, -l/2><L/2, h, l/2> }
     box {<-L/2+0.6, 1.3, -l/2+0.45><L/2-0.6, h+0.1, l/2-0.45>}
     box {<-L/2+1, 2.7, 0><L/2-1, h+0.1, l/2+0.1>}
     box {<-L/2+0.35, 1.31, -0.35><L/2-0.35, h+0.1, 0.35>}
     box {<-L/2-0.1, 3.21, l/2-0.46><L/2+0.1, h+0.1, l/2+0.1>}
     #local j = 0;
     #while(j<n)
     box {<-0.35, -0.1, -l/2-0.1><0.35, 0.3, l/2+0.1>  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
     #local j = j + 1;
     #end
     box {<-L/2+1.6, 1.6, -l/2+0.46><-L/2+2.9, 2.9, -l/2-0.1>}
     box {<L/2-1.6, 1.6, -l/2+0.46><L/2-2.9, 2.9, -l/2-0.1>}
     pigment{White}
   }
  #local pin =
  union {
    cylinder {<0, 0, -0.5> <0, -2, -0.5> 0.18}
    box{<-0.2, 0 , -1 > <0.2, 3.1, 0 > }
    cylinder {<0, 1.555, -1.> <0, 1.555, 0.> 0.2 scale < 1, 2, 1>}
    texture{col_gold}
  }  
  #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*1.25/2+i*1.25, 0, 0>}
  #local i = i + 1;
  #end

}
#end

#macro CON_MOLEX_53047_2()
CON_MOLEX_53047_BASE(2)
#end
#macro CON_MOLEX_53047_3()
CON_MOLEX_53047_BASE(3)
#end
#macro CON_MOLEX_53047_4()
CON_MOLEX_53047_BASE(4)
#end
#macro CON_MOLEX_53047_5()
CON_MOLEX_53047_BASE(5)
#end
#macro CON_MOLEX_53047_6()
CON_MOLEX_53047_BASE(6)
#end
#macro CON_MOLEX_53047_7()
CON_MOLEX_53047_BASE(7)
#end
#macro CON_MOLEX_53047_8()
CON_MOLEX_53047_BASE(8)
#end
#macro CON_MOLEX_53047_9()
CON_MOLEX_53047_BASE(9)
#end
#macro CON_MOLEX_53047_10()
CON_MOLEX_53047_BASE(10)
#end
#macro CON_MOLEX_53047_11()
CON_MOLEX_53047_BASE(11)
#end
#macro CON_MOLEX_53047_12()
CON_MOLEX_53047_BASE(12)
#end
#macro CON_MOLEX_53047_13()
CON_MOLEX_53047_BASE(13)
#end
#macro CON_MOLEX_53047_14()
CON_MOLEX_53047_BASE(14)
#end
#macro CON_MOLEX_53047_15()
CON_MOLEX_53047_BASE(15)
#end


/********************************************************************************************************************************************
// Molex 53048 ( 1.25 pitch, horizontal feeding, through holes )
//antoine.drouin@free.fr
//n      Number of Pins
********************************************************************************************************************************************/
#macro CON_MOLEX_53048_BASE(n)
union {
  #local L = n * 1.25 + 1.75;
  #local l = 5.5;
  #local h = 3.5;
  difference {
    box {<-L/2, 0, -2.3><L/2, h, 3.2> }
    box {<-L/2+0.6, 0.8, 0.3><L/2-0.6, h-0.4, 3.3>}
    box {<-L/2+1, h-0.5, 1.6><L/2-1, h+0.1, 3.3>}
    box {<-L/2-0.1, h-0.41, 2.3><L/2+0.1, h+0.1, 3.3>}
    box {<-L/2+0.6, -0.1, -2.4><L/2-0.6, 0.3, 3.3>}
    box {<-L/2+0.8, -0.1, -2.4><L/2-0.8, h+0.1, -1.58>}
    box {<-L/2+0.81, 1.3, -2.4><L/2-0.81, h+0.1, -1.>}
    box {<-L/2-0.1, h-1, -2.4><L/2+0.1, h+0.1, -1.01>}
    #local j = 0;
    #while(j<n)
        box {<-0.3, h-0.6, -1.1><0.3, h+0.1, -0.7>  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
   cylinder {<0, -0.1, -1.3> <0, h+0.1, -1.3> 0.3  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
    #local j = j + 1;
    #end
        box {<-L/2+1.6, 0, 2.7><-L/2+2.9, 0.9, 1.1>}
        box {<L/2-1.6, 0, 2.7><L/2-2.9, 2.9, 1.1>}
    pigment{White}
  }
  #local pin =
  union {
    cylinder {<0, -2.3, -1.25> <0, 1.27, -1.25> 0.18}
    cylinder {<0, 1.52, -1> <0, 1.52, -0.75> 0.18}
    intersection {
      torus { 0.25 0.18 rotate < 0, 0, 90> }
      box { < 1, 0, 0> <-1, 1, -11> }
      translate < 0, 1.27, -1>
    }
    union {
      box{<-0.2, 1.2 , -0.75 > <0.2, 2, 1.95 > }
      cylinder {<0, 1.2, 1.02> <0, 2., 1.02> 0.2 scale < 1, 1, 2>}
    }
    texture{col_gold}
  }  
  #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*1.25/2+i*1.25, 0, 0>}
  #local i = i + 1;
  #end

}
#end

#macro CON_MOLEX_53048_2()
CON_MOLEX_53048_BASE(2)
#end
#macro CON_MOLEX_53048_3()
CON_MOLEX_53048_BASE(3)
#end
#macro CON_MOLEX_53048_4()
CON_MOLEX_53048_BASE(4)
#end
#macro CON_MOLEX_53048_5()
CON_MOLEX_53048_BASE(5)
#end
#macro CON_MOLEX_53048_6()
CON_MOLEX_53048_BASE(6)
#end
#macro CON_MOLEX_53048_7()
CON_MOLEX_53048_BASE(7)
#end
#macro CON_MOLEX_53048_8()
CON_MOLEX_53048_BASE(8)
#end
#macro CON_MOLEX_53048_9()
CON_MOLEX_53048_BASE(9)
#end
#macro CON_MOLEX_53048_10()
CON_MOLEX_53048_BASE(10)
#end
#macro CON_MOLEX_53048_11()
CON_MOLEX_53048_BASE(11)
#end
#macro CON_MOLEX_53048_12()
CON_MOLEX_53048_BASE(12)
#end
#macro CON_MOLEX_53048_13()
CON_MOLEX_53048_BASE(13)
#end
#macro CON_MOLEX_53048_14()
CON_MOLEX_53048_BASE(14)
#end
#macro CON_MOLEX_53048_15()
CON_MOLEX_53048_BASE(15)
#end








/********************************************************************************************************************************************
// PC power connector male
********************************************************************************************************************************************/
#macro CON_PCPWR514M_BASE()
union {
        difference {
        box{<0,0,0><23.2,10,8.4> translate <-11.6,0.5,-4.20> }
        box{<0,0,0><21,8,6.4> translate <-10.5,2.6,-3.20> }
        }
     box{<0,0,0><1,3,3> translate <-12.6,0.5,-1.5> }
     box{<0,0,0><1,3,3> translate <11.6,0.5,-1.5> }

     box{<0,0,0><3,10,1.5> rotate <0,-45,0> translate <-10.5,0.5,1> }
     box{<0,0,0><3,10,1.5> rotate <0,45,0> translate <8.5,0.5,3.1> }


     #local p = 0;
     #while(p<5)    
        box{<0,0,0><1.5,3,1> translate <-11.6+p*5,0.5,-5.2> }
     #local p = p+1;
     #end


     #local p = 0;
     #while(p<4)    
             cylinder {<0,0,0><0,12.5,0> 0.8 translate <-7.5+p*5.08,-3.5,0> texture{col_gold}}
             sphere {<-7.5+p*5.08,9,0> 0.8 texture{col_gold}}   
     #local p = p+1;
     #end
 }        

 pigment{VLightGray}
 rotate <0,-90,0>
 
#end
#macro CON_PCPWR514M()
CON_PCPWR514M_BASE()
#end






/********************************************************************************************************************************************
//Macros for connector PHOENIX type MINICONNEC 5.08
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1  06/01/06
********************************************************************************************************************************************/
#macro CON_PHOENIX_508_BASE(n,vertical,a)
// n = pins ; Vertical = 1 if yes ; With border a = 1 / Whithout border a = 0
union {
    difference {
        union {
            #local PAS = 5.08;
            //body
         box{<-PAS*n/2-a,-4.15,0><+PAS*n/2+a,4.15,12> }
         //up additional thickness
         box{<-PAS*n/2-a,+4.15,9><+PAS*n/2+a,4.15+0.5,12> }
         }
         
         union {
            
            #local i=0; 
            #while (i<n)
                //Half Cylindrical holes
                intersection{
                    cylinder{<-(PAS/2*(n-1))+(i*PAS),0.35,2.5><-(PAS/2*(n-1))+(i*PAS),0.35,12.1> 4 }
                    box{<-(PAS/2*(n-1))+(i*PAS)+2.541,+0.1,2.51><-(PAS/2*(n-1))+(i*PAS)-2.541,-5.1,12.1> }
                }
                //Crenels at the top
                box{<-(PAS/2*(n-1))+(i*PAS)+1,3,11><-(PAS/2*(n-1))+(i*PAS)-1,6,12.5> }
                //Crenels for pins
                box{<-(PAS/2*(n-1))+(i*PAS)+0.5,0,-0.1><-(PAS/2*(n-1))+(i*PAS)-0.5,-6,2> }
                box{<-(PAS/2*(n-1))+(i*PAS)+1.5,-4,-0.1><-(PAS/2*(n-1))+(i*PAS)-1.5,-6,3> }
             #local i=i+1; #end
          
             //Half squared hole               
             box{<-PAS*n/2-0.01,0,2.5><+PAS*n/2+0.01,3.25,12.1> }
                                     
            //bisel   
         box{<-PAS*n/2-a-0.1,+4.15,9><+PAS*n/2+a+0.1,4.15+0.7,12> rotate 20*x translate 4*y}
         
         }
         pigment{ForestGreen}
    }
    #if(vertical)
        #local i=0; #while (i<n)
            union {
                //pin body
                box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,-4><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,9> }
                //pin top
                intersection{
                    box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,9><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,10> }
                    cone{<-(PAS/2*(n-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(n-1))+(i*PAS),0,10.01>, 0.25}
                }
                texture { pigment{P_Silver2} }
            }
        #local i=i+1; #end
        rotate <-90,180,0>
    #else
        #local i=0; #while (i<n)
            //inside part pin
            union {
                //pin body
                box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,2><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,9> texture { pigment{P_Silver2} }}
                //pin top
                intersection{
                    box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,9><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,10> }
                    cone{<-(PAS/2*(n-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(n-1))+(i*PAS),0,10.01>, 0.25}
                }
                texture { pigment{P_Silver2} }
            }


            //outside part pin
            box{<-(PAS/2*(n-1))+(i*PAS)-0.4,0,1.1><-(PAS/2*(n-1))+(i*PAS)+0.4,-7.5,1.9> texture { pigment{P_Silver2} }}
        #local i=i+1; #end
        translate <0,4.1,-5.08-1.5> //-1.5>
        rotate 180*y
    #end
}
#end
// Vertical whithout border
#macro CON_PHOENIX_508_MSTBV_2()
CON_PHOENIX_508_BASE(2,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_3()
CON_PHOENIX_508_BASE(3,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_4()
CON_PHOENIX_508_BASE(4,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_5()
CON_PHOENIX_508_BASE(5,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_6()
CON_PHOENIX_508_BASE(6,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_7()
CON_PHOENIX_508_BASE(7,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_8()
CON_PHOENIX_508_BASE(8,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_9()
CON_PHOENIX_508_BASE(9,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_10()
CON_PHOENIX_508_BASE(10,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_11()
CON_PHOENIX_508_BASE(11,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_12()
CON_PHOENIX_508_BASE(12,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_13()
CON_PHOENIX_508_BASE(13,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_14()
CON_PHOENIX_508_BASE(14,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_15()
CON_PHOENIX_508_BASE(15,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_16()
CON_PHOENIX_508_BASE(16,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_17()
CON_PHOENIX_508_BASE(17,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_18()
CON_PHOENIX_508_BASE(18,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_19()
CON_PHOENIX_508_BASE(19,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_20()
CON_PHOENIX_508_BASE(20,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_21()
CON_PHOENIX_508_BASE(21,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_22()
CON_PHOENIX_508_BASE(22,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_23()
CON_PHOENIX_508_BASE(23,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_24()
CON_PHOENIX_508_BASE(24,1,0)
#end
// Horizontal whithout border
#macro CON_PHOENIX_508_MSTB_2()
CON_PHOENIX_508_BASE(2,0,0)
#end
#macro CON_PHOENIX_508_MSTB_3()
CON_PHOENIX_508_BASE(3,0,0)
#end
#macro CON_PHOENIX_508_MSTB_4()
CON_PHOENIX_508_BASE(4,0,0)
#end
#macro CON_PHOENIX_508_MSTB_5()
CON_PHOENIX_508_BASE(5,0,0)
#end
#macro CON_PHOENIX_508_MSTB_6()
CON_PHOENIX_508_BASE(6,0,0)
#end
#macro CON_PHOENIX_508_MSTB_7()
CON_PHOENIX_508_BASE(7,0,0)
#end
#macro CON_PHOENIX_508_MSTB_8()
CON_PHOENIX_508_BASE(8,0,0)
#end
#macro CON_PHOENIX_508_MSTB_9()
CON_PHOENIX_508_BASE(9,0,0)
#end
#macro CON_PHOENIX_508_MSTB_10()
CON_PHOENIX_508_BASE(10,0,0)
#end
#macro CON_PHOENIX_508_MSTB_11()
CON_PHOENIX_508_BASE(11,0,0)
#end
#macro CON_PHOENIX_508_MSTB_12()
CON_PHOENIX_508_BASE(12,0,0)
#end
#macro CON_PHOENIX_508_MSTB_13()
CON_PHOENIX_508_BASE(13,0,0)
#end
#macro CON_PHOENIX_508_MSTB_14()
CON_PHOENIX_508_BASE(14,0,0)
#end
#macro CON_PHOENIX_508_MSTB_15()
CON_PHOENIX_508_BASE(15,0,0)
#end
#macro CON_PHOENIX_508_MSTB_16()
CON_PHOENIX_508_BASE(16,0,0)
#end
#macro CON_PHOENIX_508_MSTB_17()
CON_PHOENIX_508_BASE(17,0,0)
#end
#macro CON_PHOENIX_508_MSTB_18()
CON_PHOENIX_508_BASE(18,0,0)
#end
#macro CON_PHOENIX_508_MSTB_19()
CON_PHOENIX_508_BASE(19,0,0)
#end
#macro CON_PHOENIX_508_MSTB_20()
CON_PHOENIX_508_BASE(20,0,0)
#end
#macro CON_PHOENIX_508_MSTB_21()
CON_PHOENIX_508_BASE(21,0,0)
#end
#macro CON_PHOENIX_508_MSTB_22()
CON_PHOENIX_508_BASE(22,0,0)
#end
#macro CON_PHOENIX_508_MSTB_23()
CON_PHOENIX_508_BASE(23,0,0)
#end
#macro CON_PHOENIX_508_MSTB_24()
CON_PHOENIX_508_BASE(24,0,0)
#end
// Vertical whith border
#macro CON_PHOENIX_508_MSTBVA_2()
CON_PHOENIX_508_BASE(2,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_3()
CON_PHOENIX_508_BASE(3,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_4()
CON_PHOENIX_508_BASE(4,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_5()
CON_PHOENIX_508_BASE(5,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_6()
CON_PHOENIX_508_BASE(6,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_7()
CON_PHOENIX_508_BASE(7,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_8()
CON_PHOENIX_508_BASE(8,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_9()
CON_PHOENIX_508_BASE(9,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_10()
CON_PHOENIX_508_BASE(10,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_11()
CON_PHOENIX_508_BASE(11,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_12()
CON_PHOENIX_508_BASE(12,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_13()
CON_PHOENIX_508_BASE(13,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_14()
CON_PHOENIX_508_BASE(14,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_15()
CON_PHOENIX_508_BASE(15,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_16()
CON_PHOENIX_508_BASE(16,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_17()
CON_PHOENIX_508_BASE(17,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_18()
CON_PHOENIX_508_BASE(18,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_19()
CON_PHOENIX_508_BASE(19,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_20()
CON_PHOENIX_508_BASE(20,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_21()
CON_PHOENIX_508_BASE(21,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_22()
CON_PHOENIX_508_BASE(22,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_23()
CON_PHOENIX_508_BASE(23,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_24()
CON_PHOENIX_508_BASE(24,1,1)
#end
// Horizontal whith border
#macro CON_PHOENIX_508_MSTBA_2()
CON_PHOENIX_508_BASE(2,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_3()
CON_PHOENIX_508_BASE(3,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_4()
CON_PHOENIX_508_BASE(4,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_5()
CON_PHOENIX_508_BASE(5,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_6()
CON_PHOENIX_508_BASE(6,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_7()
CON_PHOENIX_508_BASE(7,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_8()
CON_PHOENIX_508_BASE(8,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_9()
CON_PHOENIX_508_BASE(9,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_10()
CON_PHOENIX_508_BASE(10,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_11()
CON_PHOENIX_508_BASE(11,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_12()
CON_PHOENIX_508_BASE(12,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_13()
CON_PHOENIX_508_BASE(13,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_14()
CON_PHOENIX_508_BASE(14,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_15()
CON_PHOENIX_508_BASE(15,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_16()
CON_PHOENIX_508_BASE(16,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_17()
CON_PHOENIX_508_BASE(17,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_18()
CON_PHOENIX_508_BASE(18,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_19()
CON_PHOENIX_508_BASE(19,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_20()
CON_PHOENIX_508_BASE(20,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_21()
CON_PHOENIX_508_BASE(21,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_22()
CON_PHOENIX_508_BASE(22,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_23()
CON_PHOENIX_508_BASE(23,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_24()
CON_PHOENIX_508_BASE(24,0,1)
#end


/********************************************************************************************************************************************
//ChristophGraf@web.de
********************************************************************************************************************************************/
#macro CON_PHONE_JACK_BASE(value)

union {
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference {
                box{<-7.1882,-0.1,5.9182><7.1882,5,-5.9182> pigment{Black}}
                box{<-6.4882,-0.2,5.2182><6.4882,6,-5.2182> pigment{Black}}}

               box{<-7.1882,5,5.9182><7.1882,6,-5.9182> pigment{White filter 0.91}}
               box{<-7.1882,0,5.9182><7.1882,1,-5.9182> pigment{Black}}
           

        
        difference {
        cylinder { < -7.1882 , 3 , 0 >,< -10.7442, 3 , 0 >,2.6  pigment{White}}
        cylinder { < -7.1882 , 3 , 0 >,< -11.7442, 3 , 0 >,1.75  pigment{White}}
          }
        union {
                lathe { linear_spline 13,<2.6, -10.7442>,<2.9, -10.4442>, <2.6, -10.1442>,<2.9, -9.8442>,<2.6, -9.5442>,
                <2.9, -9.2442>,<2.6, -8.9442>,<2.9, -8.6442>,<2.6, -8.3442>,<2.9, -8.0442>,
                <2.6, -7.7442>,<2.9, -7.4442>,<2.6, -7.1442>pigment {Silver} } 
                rotate<0,0,-90>
                translate<0,3,0> 
             }

        
        union {
                cylinder{<2.8494,2,4.8996>,<2.8494,-pp,4.8996>,0.25 }
                cylinder{<-4.9979,2,-0.2035>,<-4.9979,-pp,-0.2035>,0.25 }
                cylinder{<1.4575,2,2.3985>,<1.4575,-pp,2.3985>,0.25 }  
                cylinder{<-1.75,2,-4.9032>,<-1.75,-pp,-4.9032>,0.25 }
                cylinder{<5.7543,2,-4.3787>,<5.7543,-pp,-4.3787>,0.25 }
                pigment{Silver}
        }
        union {
               box{<3.5543,1,-1.3><5.85,5,-1.6> pigment{Silver}}
               box{<5.5543,1,-4.3787><5.85,5,-0.4787> pigment{Silver}} 
               prism{linear_sweep 0,5,11,            // segment "A"
                <-1.45,-4.6032>,<-5.55,-4.6032>,<-1.25,-0.5332>,<-0.55,-2.1332>,<4.75,-2.1332>,
                <4.75,-1.8332>,<-0.35,-1.8332>,<-1.1436,-0.0194>,<-5.9492,-4.568>,<-5.8324,-4.9032>,<-1.45,-4.9032>
                pigment{Silver}}
               prism{linear_sweep 0,5,13,            // segment "A"
                <2.8494,5.1996>,<6.6829,5.1996>,<6.6829,2.8981>,<-2.2639,2.812>,<-3.2967,0.7465>,
                <-4.5539,3.0096>,<-4.2139,3.0152>,<-3.3106,1.3894>,<-2.4502,3.1104>,<6.2829,3.1954>,<6.2829,4.8996>,<2.8494,4.8996>,<2.8494,5.1996>
                pigment{Silver}} 
                 prism{linear_sweep 0,5,5,            // segment "A"
                <-2.2125,2.3985>,<2.5575,2.3985>,<2.5575,2.6985>,<-2.2125,2.6985>,<-2.2125,2.3985>
                pigment{Silver}}
        }

}
#end

#macro CON_PHONE_JACK(value)
CON_PHONE_JACK_BASE(value)
#end






/********************************************************************************************************************************************
// Makro fuer geschirmte Ethernet-Buchse RJ-45 8-polig
// Designed by Carsten Koegler, FTZ-Leipzig <koegler(replace with at)ftz-leipzig.de>
// Vorlage: MEBP 8-8PG Reichelt Elektronik
********************************************************************************************************************************************/
#macro CON_RJ45_BASE()
//#local tex_rj45_metal = texture { T_Chrome_3D } ;
#local tex_rj45_metal = texture { T_Chrome_5B } ;
#local tex_rj45_pastic = texture { pigment{White*0.3} finish {specular 1 roughness 0.001 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;

#macro body(B,H,T,R)
union {

    // Grundkoerper
    box{<-B/2+R,0  , T/2  > <B/2-R,H-R,-T/2  >}
    box{<-B/2  ,0  ,-T/2+R> <B/2  ,H-R, T/2-R>}
    box{<-B/2+R,0  ,-T/2+R> <B/2-R,H    , T/2-R>}


    // senkrechte Seiten als Zylinder
    // linke hintere Ecke
    cylinder{<-B/2+R, 0, 0> <-B/2+R, H-R> R
             translate <0, 0, T/2-R>}
    // linke vordere Ecke
    cylinder{<-B/2+R, 0, 0> <-B/2+R, H-R> R
             translate <0, 0,-T/2+R>}
    // rechte hintere Ecke
    cylinder{< B/2-R, 0, 0> < B/2-R, H-R> R
             translate <0, 0, T/2-R>}
    // rechte vordere Ecke
    cylinder{< B/2-R, 0, 0> < B/2-R, H-R> R
             translate <0, 0,-T/2+R>}

    sphere{< B/2-R, H-R, T/2-R> R scale <1,1,1>}
    sphere{< B/2-R, H-R,-T/2+R> R scale <1,1,1>}
    sphere{<-B/2+R, H-R, T/2-R> R scale <1,1,1>}
    sphere{<-B/2+R, H-R,-T/2+R> R scale <1,1,1>}


    cylinder{<-B/2+R,  H-R> < B/2-R, H-R> R
             translate <0, 0, T/2-R>}

    cylinder{<-B/2+R,  H-R> < B/2-R, H-R> R
             translate <0, 0,-T/2+R>}
    cylinder{<-T/2+R,  H-R> < T/2-R, H-R> R rotate<0, 90,0>
             translate < B/2-R, 0, 0>}
    cylinder{<-T/2+R,  H-R> < T/2-R, H-R> R rotate<0, 90,0>
             translate < -B/2+R, 0, 0>}
  }
#end 

// Ausbruch in der metallenen Vorderseite
#local stecker1 = 
      difference
      {
         box{<1.5,0.5,-1><15.8-1.5,11.5,15.0>}
         box{<0  ,0  ,-2><3.0     ,3.3 ,15.0>}
         box{<16 ,0  ,-2><15.8-3.0,3.3 ,15.0>}
         box{<0  ,0  ,-2><5.5     ,2.1 ,15.0>}
         box{<16 ,0  ,-2><15.8-5.5,2.1 ,15.0>}
      };

// Ausbruch im Kunststoff
#local stecker2 = 
      difference
      {
         union
         {
            box{<1.5, 3.7, -1><15.8-1.5, 11.5, 15.5>}
            box{<3.1, 2.5, -1><15.8-3.1, 11.5, 15.5>}
            box{<5.6, 0.7, -1><15.8-5.6, 11.5, 15.5>}
            box{<-1,-1,-2><16,1  ,2>rotate<-30,0,0>translate<0,4.4,0> pigment{White*0.5}}
            box{<-1,0 ,-1><16,0.5,1>rotate<-30,0,0>translate<0,2.0,0> pigment{White*0.5}}
         }
         box{<-1      ,-1  ,15.0><16  ,15 ,16.0>}
         box{<-1      ,-1  ,-1  ><1.6 ,15 ,16.0>}
         box{<15.8-1.6,-1  ,-1  ><16  ,15 ,16.0>}
      };

#local pin_intern =
   sphere_sweep {
      b_spline
      6,
      <15.8/2-0.635, 14.0, 6>,   0.2
      <15.8/2-0.635, 12.7, 6>,   0.2
      <15.8/2-0.635, 12.0, 6.5>, 0.2
      <15.8/2-0.635, 11.3, 10>,  0.2
      <15.8/2-0.635, 11.0, 16>,  0.2
      <15.8/2-0.635, 11.0, 18>,  0.2
      texture{col_gold}
   }

union
{
   difference
   {
      // Aussenabmasse : 15.8  x  13.0  x  21.4 mm
      union
      {
         object {body(15.8,13.0,21.4,0.3) translate<7.9,0,10.7>  }
         box{<0,12.0,0.2><0.5,13,7.7> }
         box{<15.5,12.0,0.2><15.8,13,7.7>}
      }
      // das Ganze aushoehlen
      box{<0.25 ,-1 , 0.2><15.8-0.25 ,13.0-0.25,21.4-0.25>}
      
      // Vorne typischer Ausbruch fuer Stecker
      stecker1

      // kleiner Schlitz hinten oben
      box{<3.5,13-0.35,21.4-0.35><15.8-3.5,13+0.35,21.4+0.35> }

      // Schlitze an den Seiten
      // Schraegen hinten (links und rechts)
      box{<-0.3,-0.1,-1.64><0.3,0.1,2.0> rotate<-45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02+11.2>}
      box{<15.8-0.3,-0.1,-1.64><16,0.1,2.0> rotate<-45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02+11.2>}
      // Senkrechten
      box{<-1,-1,18.8><20,10.6,19.00>}
      // waagerechte hinten
      box{<-1,10.45,10><20,10.65,18.8> }
      // Schraegen vorne
      box{<-1,-0.1,-1.52><20,0.1,1.64> rotate<45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02> }
      // waagerechte vorn
      box{<-1,12.6,0.2><20,12.8,7.82>}

      // Verbindungspunkte hinten
      box{<-1,1,19.7><20,1.8,20.5>}
      box{<-1,8,19.7><20,8.8,20.5>}
      texture{tex_rj45_metal}
   }

   // Verbindungspunkte hinten
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<     0.35,1.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<     0.35,8.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<15.8-0.35,1.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<15.8-0.35,8.4,20.1> texture{tex_rj45_metal}}

   // Schirmanschluesse
   box     {<0   , 1, 14-0.75><0.2     , -4,14+0.75> texture{tex_rj45_metal}}
   cylinder{<0   ,-4, 14     ><0.2     , -4,14     > 0.75 texture{tex_rj45_metal}}
   box     {<15.8, 1, 14-0.75><15.8-0.2, -4,14+0.75> texture{tex_rj45_metal}}
   cylinder{<15.8,-4, 14     ><15.8-0.2, -4,14     > 0.75 texture{tex_rj45_metal}}

   // Plastikinnenleben
   difference
   {
      box{<0.4 ,0 , 0.3><15.8-0.4 ,13.0-0.4,21.4-0.4>}
      stecker2

      texture{tex_rj45_pastic}
    }
 
   // Plastikfuesse zur Befestigung
   difference
   {
      cylinder{<2,-3.5,14-3.05><2,1,14-3.05> 1.5}
      box{<2-0.3,-4,0><2+0.3,-0.5,20>}
      texture{tex_rj45_pastic}
   }
   difference
   {
      cylinder{<15.8-2,-3.5,14-3.05><15.8-2,1,14-3.05> 1.5}
      box{<15.8-2-0.3,-4,0><15.8-2+0.3,-0.5,20>}
      texture{tex_rj45_pastic}
   }
   cylinder{<2,0,5><2,0,15> 0.5 texture{tex_rj45_pastic}}
   cylinder{<15.8-2,0,5><15.8-2,0,15> 0.5 texture{tex_rj45_pastic}}
   
      
   object {TOOLS_RECT_BOGEN(0.2, // i_radius
                            90 , // winkel
                            0.2, // dicke
                            2  , // breite
                            1 , // laenge1
                            5)  // laenge2
                            rotate<90,0,0>
                            translate <15.8-1.5-0.2,7,0.1>
                            texture{tex_rj45_metal}}
   object {TOOLS_RECT_BOGEN(0.2, // i_radius
                            90 , // winkel
                            0.2, // dicke
                            2  , // breite
                            5 , // laenge1
                            1)  // laenge2
                            rotate<90,0,0>
                            rotate<0,-90,0>
                            translate <1.5+0.2,7,0.1>
                            texture{tex_rj45_metal}}

   // Pins (8)
   cylinder{<15.8/2-0.635     ,1,14-3.05+8.89     ><15.8/2-0.635     ,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635+2.54,1,14-3.05+8.89     ><15.8/2-0.635+2.54,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635-2.54,1,14-3.05+8.89     ><15.8/2-0.635-2.54,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635+5.08,1,14-3.05+8.89     ><15.8/2-0.635+5.08,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}

   cylinder{<15.8/2+0.635     ,1,14-3.05+8.89-2.54><15.8/2+0.635     ,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635+2.54,1,14-3.05+8.89-2.54><15.8/2+0.635+2.54,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635-2.54,1,14-3.05+8.89-2.54><15.8/2+0.635-2.54,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635-5.08,1,14-3.05+8.89-2.54><15.8/2+0.635-5.08,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   
   object { pin_intern }
   object { pin_intern  translate< 2.54,0,0>}
   object { pin_intern  translate<-2.54,0,0>}
   object { pin_intern  translate<+5.08,0,0>}
   
   object { pin_intern  translate<+1.27,0,0>}
   object { pin_intern  translate<+1.27+2.54,0,0>}
   object { pin_intern  translate<+1.27-2.54,0,0>}
   object { pin_intern  translate<+1.27-5.08,0,0>}
 
   translate<0,0.5,0>  // Anhebung um hoehe der Plastikrollen
   translate<-15.8/2,0,-21.4/2>  // 0-Punkt in die Mitte der Buchse platzieren
}
#end
#macro CON_RJ45()
CON_RJ45_BASE()
#end



/********************************************************************************************************************************************
//Macro fuer USB-Buchse USB-787616 aus der con-amp.lib
//12.10.2004
//Designed by hebel23 <hebel(replace with at)hebel23.de> 
********************************************************************************************************************************************/
#macro CON_USB_A_001_BASE()
union {
        // Blechgehaeuse
        difference {
                box { <-7,2,0>,<7,8,14>} // Aussenhuelle
                box { <-6.5, 2.5, -1>, <6.5, 7.5, 14> } // Aussparung in der Mitte
                box { <-6.5, 0, 12>, <6.5, 7.5, 15> }  // Aussparung hinten
                difference {                                      // Feder links oben                                      
                           cone {<-3,8,8> , 1.5 , <-3,8,1> , 1.0}
                           cone {<-3,8,8> , 1 , <-3,8,2> , 0.5}
                          }
                difference {                                      // Feder rechts oben                                      
                           cone {<3,8,8> , 1.5 , <3,8,1> , 1.0}
                           cone {<3,8,8> , 1 , <3,8,2> , 0.5}
                          }
                difference {                                      // Feder links unten                                     
                           cone {<-3,2,8> , 1.5 , <-3,2,1> , 1.0}
                           cone {<-3,2,8> , 1 , <-3,2,2> , 0.5}
                          }
                difference {                                      // Feder rechts unten                                      
                           cone {<3,2,8> , 1.5 , <3,2,1> , 1.0}
                           cone {<3,2,8> , 1 , <3,2,2> , 0.5}
                          }
                difference {                                      // Feder links                                      
                           cone {<-7,5,8> , 1.5 , <-7,5,1> , 1.0}
                           cone {<-7,5,8> , 1 , <-7,5,2> , 0.5}
                          }
                difference {                                      // Feder rechts                                      
                           cone {<7,5,8> , 1.5 , <7,5,1> , 1.0}
                           cone {<7,5,8> , 1 , <7,5,2> , 0.5}
                          }
                texture{col_silver}
                } 
        union {
                box { <-7, -2, 9.5>, <-6.5, 3, 11> }            // linke Loetlasche
                box { <7, -2, 9.5>, <6.5, 3, 11> }              // rechte Loetasche
                texture{col_silver}
               }
        union {       
                union {TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,0>translate<6.75,5,-0.5>}
                union {TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,270,0>translate<-6.75,5,-0.5>}
                union {TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,90>translate<-3.5,7.75,-0.5>}
                union {TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,90>translate<3.5,7.75,-0.5>}
                union {TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,270>translate<-3.5,2.25,-0.5>}
                union {TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,270>translate<3.5,2.25,-0.5>}
                texture{col_silver}
               }
        // weisser Kontakttraeger
        difference {
                box { <-5,4,1>,<5,6,12>} // Quader in der Mitte
                union {
                      box{<-6,5.3,0>,<6,7,5>}
                      rotate <-10, 0, 0>        // Abflachung oben
                      }
                union {
                      box{<-6,4.3,0>,<6,3.5,5>}
                      rotate <10, 0, 0>        // Abflachung unten
                     }
                 texture{pigment{color White}}
                }  
        // Kontakte
        difference {    
                  union {
                        box { <-3.8,3.5,3>,<-3,4,8>} // Kontakt 1
                        box { <-1.8,3.5,3>,<-0.8,4,8>} // Kontakt 2
                        box { <1.8,3.5,3>,<0.8,4,8>} // Kontakt 3
                        box { <3.8,3.5,3>,<3,4,8>} // Kontakt 4
                        texture{col_gold}
                        }   
                  union {
                        box{<-4,4,1>,<4,3.5,5>}
                        rotate <5, 0, 0> // Abflachung der Kontakte
                        }
                }
        union {
                box { <-3.8,-2,12.5>,<-3.2,5,13>} // Kontakt 1 hinten
                box { <-1.3,-2,12.5>,<-0.7,5,13>} // Kontakt 2 hinten
                box { <0.7,-2,12.5>,<1.3,5,13>} // Kontakt 3 hinten
                box { <3.2,-2,12.5>,<3.8,5,13>} // Kontakt 4 hinten
                texture{col_gold}
             }
        // weisser Sockel
        union {      
                difference {
                        box { <-6,0,2>,<6,2,12>} // Sockel links
                        box { <-1,0,1>,<1,2,12>} // Sockel rechts
                        union {
                                box{<1.5,0,0>,<7,2,12>}
                                rotate <-10, 0, 0>        // Abflachung links
                                }
                         union {
                                box{<-1.5,0,0>,<-7,2,12>}
                                rotate <-10, 0, 0>        // Abflachung links
                                }
                               }                
                        difference {
                        box { <-6.5, 0.5, 12>, <6.5, 7.5, 14> } // Sockel hinten
                        box { <-6, 2.5, 12.5>, <6, 8, 15> }  // Aussparung fuer Kontakte
                        box { <-3.8,-2,12>,<-3.2,5,15> }  // Aussparung fuer Kontakte
                        box { <-1.3,-2,12>,<-0.7,5,15> }  // Aussparung fuer Kontakte
                        box { <0.7,-2,12>,<1.3,5,15> }  // Aussparung fuer Kontakte
                        box { <3.2,-2,12>,<3.8,5,15> }  // Aussparung fuer Kontakte
                texture{pigment{color White}}
                                }
             }  
}
#end
#macro CON_USB_A_001()
CON_USB_A_001_BASE()
#end


/********************************************************************************************************************************************
//Macro fuer USB-Stecker, flach, Platinenmontage,   keine eagle-library,     Joerg Bredendiek <sprut(replace with at)sprut.de>    
//
// Nullpunkt zwischen den Massestiften
// pinabstand 2   mm
// pinbreite  1   mm
// pindicke   0.4 mm
// Loetpunkte 2   mm hinter Mittlepunkt
// Befestigungspunkte seitlich je 6 mm von Mitte entfernt  
********************************************************************************************************************************************/
#macro CON_USB_A_002_BASE()
#local tex_usb_metal = texture { T_Chrome_5B } ;
union {                          
        #local a = -9;
        // Blechgehaeuse  0.3mm dickes Blech               
        difference {                                                                   
                union {
                        box{<-5.7, 4.2, 1><+5.7, 4.5, a-8.65>}            //oben
                        box{<-5.7, 0, 1><-0.1, 0.3, a-8.65>}              //unten links
                        box{< 0.1, 0, 1><+5.7, 0.3, a-8.65>}              //unten rechts
                        box{<-6, 4.2, 1><-5.7, 0.3, a-8.65>}              //links
                        box{< 6, 4.2, 1>< 5.7, 0.3, a-8.65>}              //rechts
                        cylinder{<-5.7, 4.2, 1><-5.7, 4.2, a-8.65> 0.3 }  //runde Kanten
                        cylinder{< 5.7, 4.2, 1>< 5.7, 4.2, a-8.65> 0.3 }
                        cylinder{<-5.7, 0.3, 1><-5.7, 0.3, a-8.65> 0.3 }
                        cylinder{< 5.7, 0.3, 1>< 5.7, 0.3, a-8.65> 0.3 }
                } 
                box { <-5.7, 0.3, 1.1> <5.7, 4.2, a-8.7> } // Aussparung in der Mitte       
                box { <-3.5, -0.1, -11>, <-1, 4.6, -13> }  // Aussparung oben und unten
                box { < 3.5, -0.1, -11>, < 1, 4.6, -13> }  // Aussparung oben und unten 
                sphere {<0, 4.75, a> 0.5}                  // Delle in oberem Blech
                texture{ T_Chrome_5B}
                }             

         union {
                box { <-5.75, -2, -0.75>, <-6.25, 3, 0.75> }            // linke Loetlasche
                box { < 5.75, -2, -0.75>, < 6.25, 3, 0.75> }            // rechte Loetasche
                texture{col_silver}
               }

        // weisser Kontakttraeger 
        box { <-5.6, 0.3,a>,<5.6, 2.25,a-8.65> texture{pigment{color White}}}// Zunge vorn
        box { <-5.7, 0.3,a>,<5.7, 4.2 , 1>     texture{pigment{color White}}}// Quader hinten
     

        // Kontakte 
       union {
                box { <-3.8, 2, a>,<-3  , 2.4, a-7.41>} // Kontakt 1
                box { <-1.8, 2, a>,<-0.8, 2.4, a-6.41>} // Kontakt 2
                box { < 1.8, 2, a>,< 0.8, 2.4, a-6.41>} // Kontakt 3
                box { < 3.8, 2, a>,< 3,   2.4, a-7.41>} // Kontakt 4
                texture{col_gold}
        }   
        union {
      box { <-3.8, 2, 2>,<-3.2, 2.4, a-7.41>} // Kontakt 1
      box { <-1.3, 2, 2>,<-0.7, 2.4, a-6.41>} // Kontakt 2
      box { < 0.7, 2, 2>,< 1.3, 2.4, a-6.41>} // Kontakt 3
      box { < 3.2, 2, 2>,< 3.8, 2.4, a-7.41>} // Kontakt 4

                box { <-3.8, -4, 2.25>,<-3.2, 2.4, 1.75>} // Kontakt 1 hinten
                box { <-1.3, -4, 2.25>,<-0.7, 2.4, 1.75>} // Kontakt 2 hinten
                box { < 0.7, -4, 2.25>,< 1.3, 2.4, 1.75>} // Kontakt 3 hinten
                box { < 3.2, -4, 2.25>,< 3.8, 2.4, 1.75>} // Kontakt 4 hinten
                texture{col_gold}
             }
}
#end

#macro CON_USB_A_002()
CON_USB_A_002_BASE()
#end


/********************************************************************************************************************************************
// Desc: USB Connector Type B, AMP 787780
// Date: 22.03.2004
// Auth: Friedrich Bleikamp, <fbleikamp(replace with at)web.de>
********************************************************************************************************************************************/
#macro CON_USB_B_001_BASE()
union {

#macro SHELL_PIN_USB_B()
   merge {
      difference {
         box { <-0.2,-3.5,-1.15> <0.2,0.5,1.15>}
         box { <-0.21,-4,-1.15> <0.21,1,1.15> translate <0,0,2.3> rotate<6.5,0,0>}
         box { <-0.21,-4,-1.15> <0.21,1,1.15> translate <0,0,-2.3> rotate<-6.5,0,0>}
      }
      cylinder { <-0.2,0,0> <0.2,0,0>, 0.75 translate <0,-3.5,0>}
   }texture{col_silver}
#end

   //Metall shell
   union {
      difference {
         union {
            box { <0,0.5,-5.6> <0.4,10.7,5.6>}                 // front
            box { <0.6,0.5,5.8> <11.5,10.8,6.2>}               // left side
            box { <0.6,0.5,-5.8> <11.5,10.8,-6.2>}             // right side
            object{ TOOLS_RECT_BOGEN(0.2,90,0.4,10.0,0,0) rotate<0,90,-90> translate<0.2,5.5,6.0>}      
            object{ TOOLS_RECT_BOGEN(0.2,90,0.4,10.0,0,0) rotate<0,-90,-90> translate<0.2,5.5,-6.0>}      
         }    
         box { <-1,-1,-6.5> <1,1,6.5> translate<8.5,3.6,0>}       // cutout bottom
         box { <-1,-1,-6.5> <1,1,6.5> translate<8.5,7.6,0>}       // cutout top
         box { <-0.4,-0.25,-6.5> <0.4,0.25,6.5> translate<0.35,2.75,0>}// cutout front
         cylinder { <0,0,-6.5> <0,0,6.5>, 0.25 translate <0.75,2.75,0>} 
         box { <-0.4,-0.25,-6.5> <0.4,0.25,6.5> translate<0.35,6.25,0>}// cutout front
         cylinder { <0,0,-6.5> <0,0,6.5>, 0.25 translate <0.75,6.25,0>} 
         prism {linear_sweep linear_spline 0, 0.6, 7,             // cutout front
         < 0,-4.85>, < 6,-4.85>, < 7.85,-3.0>, < 7.85,3.0>, < 6,4.85>, <0,4.85>,< 0,-4.85>
         rotate<0,0,90> translate <0.5,1.5,0>}
      }
   box { <0.6,10.9,-5.8> <11.5,11.3,5.8>}                      // top
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,11.2,0,0) rotate<0,0,-90> translate<0.2,11.1,0>}      
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,3,3,1) rotate<90,0,0> translate<0.2,4.5,4.2>}      
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,3,3,1) rotate<-90,0,0> translate<0.2,4.5,-4.2>}      
   object{ SHELL_PIN_USB_B() rotate<0,90,0> translate<10.3,0.5,6.0>}
   object{ SHELL_PIN_USB_B() rotate<0,90,0> translate<10.3,0.5,-6.0>}   
   texture{col_silver}
   }
   
   //Housing: Thermoplastic, glass filled (UL94V-0)
   union { 
      difference {
         TOOLS_ROUNDED_BAR(<-5.5,0.4,0>,<5.5,10.9,15.3>,0.5)
         box { <-4.0,1.5,-0.1> <4.0,8.5,3.5> } 
         box { <-1.7,0,-0.1> <-0.8,8.5,4.5> }
         box { <0.8,0,-0.1> <1.7,8.5,4.5> }
         box { <-5.6,4.2,-0.1> <5.6,7.7,3.4> }   
         object{ TOOLS_ROUNDED_BAR(<-4.25,2.0,8.5>,<4.25,7.0,16.1>,0.5)} 
         object{ TOOLS_ROUNDED_BAR(<-2.90,7.0,8.5>,<2.90,8.5,16.1>,0.5)} 
         object{ TOOLS_ROUNDED_BAR( <-1.41,-1.41,8.5> <1.41,1.41,16.1>,0.5) rotate<0,0,45> translate<2.45,6.6,0>}
         object{ TOOLS_ROUNDED_BAR( <-1.41,-1.41,8.5> <1.41,1.41,16.1>,0.5) rotate<0,0,45> translate<-2.45,6.6,0>}
      }
   object{ Round_Box_Union( <-2.8,3.7,8.5> <2.8,6.7,15.5>,0.5)}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<5.7,2.0,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<-5.7,2.0,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<5.7,9.75,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<-5.7,9.75,0>} 
   box { <-6.0,-0.7,-1> <6.0,0.7,0.6> translate<0,3.5,7>}
   box { <-6.0,-0.7,-1> <6.0,0.7,0.6> translate<0,7.5,7>}
   pigment{Gray25} rotate<0,-90,0> translate<15.7,0,0>
   } 

   //Contacts
   union {
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,12.2,7.25) rotate<0,0,180> translate<13.0,3.6,-1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,12.2,7.25) rotate<0,0,180> translate<13.0,3.6,1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,14.2,10.25) rotate<0,0,180> translate<15.0,6.8,-1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,14.2,10.25) rotate<0,0,180> translate<15.0,6.8,1.25>}
      texture{col_gold}     
   }
}     
#end
#macro CON_USB_B_001()
CON_USB_B_001_BASE()
#end


/********************************************************************************************************************************************
//Macro fuer USB-Mini-Buchse MOLEX 54919-0578 (RS-Components Artikel: 418-0172)
//Designed by hebel23 <hebel(replace with at)hebel23.de>
//24.10.2004
********************************************************************************************************************************************/
#macro CON_USB_B_002_BASE()
union {
    union {      
     // Blechgehaeuse                    
    difference {      
    union {      
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)translate<-3.355,0.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,180,0>translate<3.355,0.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1)translate<-3.85,2.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1)rotate<0,180,0>translate<3.85,2.15,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1.3)rotate<0,0,180>translate<-3.35,2.2,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1.3)rotate<0,180,180>translate<3.35,2.2,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,0,180>translate<3.85,3.85,-4>}
          union {TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,180,180>translate<-3.85,3.85,-4>}
         }     
          box { <-4.5, -0.1, -2.9>, <4.5,2.75,-9> }       
             difference {                                                                           
             cone {<-2.5,4,-4.5> , 0.75 , <-2.5,4,-1> , 0.5}
             cone {<-2.5,4,-4.5> , 0.5 , <-2.5,4,-2> , 0.25}
                }
             difference {                                                                          
             cone {<2.5,4,-4.5> , 0.75 , <2.5,4,-1> , 0.5}
             cone {<2.5,4,-4.5> , 0.5 , <2.5,4,-2> , 0.25}
                }
             difference {                                                                           
             box { <-0.75, 3, -1>, <0.75,5,-6> }      
             box { <-0.5, 3, -1>, <0.5,5,-5> }      
                }
          }
     // Loetfahnen
     difference {     
     union {
          union {TOOLS_RECT_BOGEN(0.5,90,0.25,5.5,0.5,2.5)translate<3.85,0.1,-5.75>}
          union {TOOLS_RECT_BOGEN(0.5,90,0.25,5.5,0.5,2.5)rotate<0,180,0>translate<-3.85,0.1,-5.75>}
          }
                box { <-4.01, -0.1, -5>, <-5.1,1,-7> }     
                box { <4.01, -0.1, -5>, <5.1,1,-7> }       
          }
          texture{col_silver}
         }
     // schwarzer Kontakttraeger in der Mitte
        difference {
                box { <-2.5,1,-1>,<2.5,2,-7>} 
                box { <-0.25,1.25,0>,<0.25,1.75,-8>} 
                box { <-1.00,1.25,0>,<-0.50,1.75,-8>} 
                box { <-1.75,1.25,0>,<-1.25,1.75,-8>} 
                box { <1.00,1.25,0>,<0.50,1.75,-8>} 
                box { <1.75,1.25,0>,<1.25,1.75,-8>} 
                texture{pigment{color rgb <0.1, 0.1, 0.1>}}
                }
     // schwarzer Kontakttraeger Hinten
         difference {
                box { <-3.75,0,-6>,<3.75,3.75,-8.5>} 
                box { <-2,1.9,-7>,<3,4,-8.6>} 
                box { <-4,3,-8>,<4,4,-8.6>} 
                box { <-3,-0.1,-7.5>,<3,4,-8.6>} 
                box { <-0.25,-0.1,0>,<0.25,2,-8.6>} 
                box { <-1.00,-0.1,0>,<-0.50,2,-8.6>} 
                box { <-1.75,-0.1,0>,<-1.25,2,-8.6>} 
                box { <1.00,-0.1,0>,<0.50,2,-8.6>} 
                box { <1.75,-0.1,0>,<1.25,2,-8.6>} 
                texture{pigment{color rgb <0.1, 0.1, 0.1>}}
                }                
        // Kontakte
                difference {
                union {
                      union {TOOLS_RECT_BOGEN(0.25,90,0.25,3.5,1,0.65)rotate<0,90,0>translate<0,0.125,-7.3>}
                      union {TOOLS_RECT_BOGEN(0.25,90,0.25,3.5,0,0)rotate<180,270,0>translate<0,1.5,-7.3>}
                      box { <-0.25,1.5,-1>,<0.25,1.75,-7>rotate<7,0,0>} 
                      box { <-1.00,1.5,-1>,<-0.50,1.75,-7>rotate<7,0,0>} 
                      box { <-1.25,1.5,-1>,<-1.75,1.75,-7>rotate<7,0,0>} 
                      box { <1.00,1.5,-1>,<0.50,1.75,-7>rotate<7,0,0>} 
                      box { <1.25,1.5,-1>,<1.75,1.75,-7>rotate<7,0,0>} 
                     }   
                box { <-0.5,-0.1,-7>,<-0.25,1.25,-9.5>}      
                box { <0.5,-0.1,-7>,<0.25,1.25,-9.5>}      
                box { <-1.0,-0.1,-7>,<-1.25,1.25,-9.5>}      
                box { <1.0,-0.1,-7>,<1.25,1.25,-9.5>}      
                texture{col_silver}
                }
        // Aufkleber
                union {
                box{<-3.2,3.9,-0.5><3.2,4.05,-7>}
                pigment{color rgbf <1, 0, 0, 0.9>}
               }
}
#end
#macro CON_USB_B_002()
CON_USB_B_002_BASE()
#end

/*******************************************************************************
 * AMPHENOL 61729-0010BLF, 20220417, wk
 * USB-B, 4-pol, THT 90deg
 ******************************************************************************/
#macro CON_USB_B_61729()
union {
  object { CON_USB_B_001_BASE() rotate<0,-90,0> translate<0,0,-10.3> }
  box { <-11.6/2,10.8, 0> < 11.6/2, 11.3,16-10.3-0.3> } // top side
  box { <-12.4/2, 0.5,-8> <-11.6/2, 10.8,16-10.3-0.3> } // left side
  box { <+12.4/2, 0.5,-8> <+11.6/2, 10.8,16-10.3-0.3> } // right side
  box { <-12.4/2, 0.5,16-10.3-0.3> <+12.4/2, 10.8,16-10.3> } // back side
  cylinder { <-12.4/2, 0.5,16-10.3-0.3> <-12.4/2,10.8,16-10.3-0.3> 0.25}
  cylinder { <+12.4/2, 0.5,16-10.3-0.3> <+12.4/2,10.8,16-10.3-0.3> 0.25}
  box      { <-12.4/2, 0.5,16-10.3-0.3-2> <-12.9/2, 10.8,16-10.3-0.3> } // left side
  box      { <+12.4/2, 0.5,16-10.3-0.3-2> <+12.9/2, 10.8,16-10.3-0.3> } // left side
  texture{col_silver}
  }
#end





#include "CONNECTOR/_Buchsenleiste_Praezision_long.inc"
#include "CONNECTOR/_Buchsenleiste_Praezison_short.inc"
#include "CONNECTOR/_Pfostenwanne_THT.inc"
#include "CONNECTOR/_Pinheader_200_SMT.inc"
#include "CONNECTOR/_Pinheader_254_90deg.inc"
#include "CONNECTOR/_Pinheader_THT_straight.inc"
