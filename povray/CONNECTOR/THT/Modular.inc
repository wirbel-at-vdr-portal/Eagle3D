/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * modular jacks, con-amp.lib, simplified drawing.
 *   ie. RJ-45 (8pol)
 *       RJ-12 (6pol)
 *       RJ-11 (4pol)
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * reworked: 03.07.2023, -wk
 *
 * - pins     : Number of Pins: 2, 4, 6, 8
 * - a        : Abstand zwischen den Mitten der Montagestifte
 * - Offset   : Abstand zwischen Mittelpunkt und Verbindungslinie
 *              der Befestigungszapfen (Offset)
 * - Shield   : 0-kein, 1-voll, 2-teilweise
 * - PanelStop: 0-kein, 1-panel-stop
 * - LC       : Length correction.
 ******************************************************************************/
#macro ModularJack(pins,a,Offset,Shield,PanelStop, LC)
  #local BodyColor = texture {
     pigment {
        White*0.3
        }
     finish {
        specular 0.1
        roughness 0.1
        reflection 0.07
        ambient 0.1 * global_ambient_mul
        }
     };

  /* Aussenabmasse 6 pins : 13.4  x  12.8  x  18.0 BHT
   * Breite ist bauformabhaengig
   */
  #local bb = a+3;
  #local bh = 12.8;
  #local bt = 18.0 + LC;

  /* Ausbruch im Kunststoff
   * 4 pin - ??
   * 6 pin - 10 mm
   * 8 pin - 12 mm
   */
  #local stecker2 = difference {
     union {
        box {
           <-bb/2+1.5,  3.7, -11.7>
           <+bb/2-1.5, 11.5,  +4.8>
           }
        box {
           <-bb/2+3.1,  2.5, -11.7>
           <+bb/2-3.1, 11.5,  +4.8>
           }
        box {
           <-bb/2+5.6,  0.7, -11.7>
           <+bb/2-5.6, 11.5,  +4.8>
           }
        box {
           <-1 , -1, -2>
           <+16, +1, +2>
           rotate <-30,0,0>
           translate <-bb/2,4.4,-21.4/2>
           pigment {
              White*0.5
              }
           }
        box {
           <-1 , 0  , -1>
           <+16, 0.5, +1>
           rotate <-30,0,0>
           translate <-bb/20,2.0,-21.4/2>
           pigment {
              White*0.5
              }
           }
        }
     box {
       <-bb/2-1 , -1 , 4.3>
       <-bb/2+16, +15, 5.3>
       }
     box {
       <-bb/2-1  , -1 , -11.7>
       <-bb/2+1.6, +15,  +5.3>
       }
     box {
       <-bb/2+14.2, -1 , -11.7>
       <-bb/2+16  , +15,  +5.3>
       }
     };

  union {
     #if (Shield = 1) // voll geschirmt
        union {
           #local bb = a+3;
           #local sb = 14+1;
           #if (a > 11)
              #local sb = 15.5+1;
           #end
           // Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten
           difference {
              Round_Box ( // Ummantelung
                 <-sb/2, 0   , -8.5     >
                 <+sb/2, bh+1, -8  +bt+1>
                 1/2 0
                 )
              Round_Box ( // Aushoehlung
                 <-bb/2, 0 , -8   >
                 <+bb/2, bh, -8+bt>
                 1/2 0
                 )
              stecker2
              texture {
                 col_silver
                 }
              }
           // linke && rechte Loetlasche
           box {
              <-sb/2+1  , +3, -3.05-0.5>
              <-sb/2+0.5, -3, -3.05+0.5>
              texture {
                 col_silver
                 }
              }
           box {
              <+sb/2-1  , +3, -3.05-0.5>
              <+sb/2-0.5, -3, -3.05+0.5>
              texture {
                 col_silver
                 }
              }
           translate <0,0,-LC>
           }
     #end

     #if (Shield = 2) // teil geschirmt
       //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten
       union {
          #local sb = bb+0.8;
          #if (a > 11)
             #local sb = 15.5+1;
          #end
          difference {
             box { // Frontplatte
                <-sb/2+0.5, 0     , -8.5>
                <+sb/2-0.5, bh+0.5, -8  >
                }             
             stecker2 // Durchbrueche
             }
          box { // linke Loetlasche
             <-sb/2+1,  +3, -3.05-0.5>
             <-sb/2+0.5,-3, -3.05+0.5>
             }
          box { // rechte Loetlasche
             <+sb/2-1  , +3, -3.05-0.5>
             <+sb/2-0.5, -3, -3.05+0.5>
             }
          cylinder { // obere vorderkante
             <-sb/2+0.5, bh, -8>
             <+sb/2-0.5, bh, -8>
             0.5
             }          
          cylinder { // senkrechte vorderkanten
             <-sb/2+0.5, bh, -8>
             <-sb/2+0.5, 0 , -8>
             0.5
             }         
          cylinder {
             <+sb/2-0.5, bh, -8>
             <+sb/2-0.5, 0 , -8>
             0.5
             }
          box { // linkes Seitenblech
             <-sb/2    , 0 , -8>
             <-sb/2+0.4, bh, -2>
             }
          box { // rechtes Seitenblech
             <+sb/2    , 0 , -8>
             <+sb/2-0.4, bh, -2>
             }
          box { // oben links
             <-sb/2+0.5, bh    , -8>
             <-sb/2+2.5, bh+0.5, -2>
             }

          box { // oben rechts
             <+sb/2-2.5, bh    , -8>
             <+sb/2-0.5, bh+0.5, -2>
             }
          box {
             <+sb/2-2.7, -0.50, 0>
             <-sb/2+2.7, 0    , 6>
             rotate <-15,0,0>
             translate <0, bh+0.5, -8.3>
             }
          texture {
             col_silver
             }
          translate <0,0,-LC>
          }
     #end
     // Plastik
     difference {
        union {
           object {
              Round_Box (
                 <-bb/2, 0 , -5   >
                 <+bb/2, bh, -8+bt>
                 0.2 0
                 )
              texture {
                 BodyColor // hinterer Teil matter
                 }
              }
           object {
              Round_Box (
                 <-bb/2, 0 , -8>
                 <+bb/2, bh, -5>
                 0.2 0
                 )
              texture {
                 // vordere 3mm glaenzen mehr
                 pigment {
                    White*0.3
                    }
                 finish {
                    specular 1
                    roughness 0.001
                    reflection 0.07
                    ambient 0.1 * global_ambient_mul
                    }
                 }
             }
           }
        stecker2 // Aussparungen fuer Stecker
        box { // hintere Abschraegung
           <-bb/2-1,   -2, -8+bt+5>
           <+bb/2+1, bh+2, -8+bt+1>
           texture {
              BodyColor // hinterer Teil matter
              }
           rotate <-20,0,0>
           }
        // Kanaele fuer Anschlussdraehte an der Oberseite der Buchse
        GRID (
           box {
              <-0.31, bh-0.5, -5   >
              <+0.31, bh+1  , -8+bt>
              texture {
                 BodyColor // hinterer Teil matter
                 }
              },
           1.27, pins, 1
           )
        translate <0,0,-LC>
        }

     #if ((PanelStop = 1) | (Shield > 1))
        //seitliche plastiklaschen 1.4mm dick
        box {
           <-bb/2-1,   +3, -6.4>
           <-bb/2  , bh-3, -5  >
           texture {
              BodyColor
              }
           }
        box {
           <+bb/2+1,   +3, -6.4>
           <+bb/2  , bh-3, -5  >
           texture {
              BodyColor
              }
           }
     #end
     // Plastikfuesse zur Befestigung
     difference {
        union {
           cylinder {
              <+a/2, -3.5, 0>
              <+a/2, +1  , 0>
              1.4
              }
           cone {
              <+a/2, -1.5, 0>,1.7
              <+a/2, -3.5, 0> 1.4
              }
           }
        box {
           <+a/2-0.3,-4  ,-5>
           <+a/2+0.3,-0.5,+5>
           }
        texture {
           BodyColor
           }
        }
     difference {
        union {
           cylinder {
              <-a/2, -3.5, 0>
              <-a/2, +1  , 0>
              1.4
              }
           cone {
              <-a/2, -1.5, 0>,1.7
              <-a/2, -3.5, 0> 1.4
              }
           }
        box {
           <-a/2-0.3,-4  ,-5>
           <-a/2+0.3,-0.5,+5>
           }
        texture {
           BodyColor
           }
        }

     #if ((pins = 2) | (pins = 6))
        #local Dir = -1;
     #else
        #local Dir = +1;
     #end

     #local PcbPinPair = union {
        object {
           PIN_STRAIGHT(0.5,1,3.5)
           translate <Dir * +0.635, 0, 8.89>
           }
        object {
           PIN_STRAIGHT(0.5,1,3.5)
           translate <Dir * -0.635, 0, 8.89-2.54>
           }
        texture {
           col_gold
           }
        };
     GRID(PcbPinPair, 2.54, pins/2, 1)

     #local JackContact = sphere_sweep {
        b_spline
        9,
        <0, 10.0, 17  - 21.4/2>, 0.2
        <0, 12.0, 17  - 21.4/2>, 0.2
        <0, 12.5, 17  - 21.4/2>, 0.2
        <0, 12.5,  6  - 21.4/2>, 0.2
        <0, 11.7,  6  - 21.4/2>, 0.2
        <0, 11.0,  6.5- 21.4/2>, 0.2
        <0, 10.3, 10  - 21.4/2>, 0.2
        <0,  8.0, 16  - 21.4/2>, 0.2
        <0,  8.0, 18  - 21.4/2>, 0.2
        scale <1,1,(12+LC)/12>
        translate <0,0,-LC/2>
        texture {
           col_gold
           }
        };
     GRID(JackContact, 1.27, pins, 1)
     translate <0, 0, -Offset>
     }
#end


#macro CON_THT_MODULAR_RJ45()       ModularJack(8, 9*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_RJ12()       ModularJack(6, 9*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_RJ11()       ModularJack(4, 9*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_RJ45_S()     ModularJack(8, 9*1.27, 0   , 1, 0, 0  ) #end
#macro CON_THT_MODULAR_RJ12_S()     ModularJack(6, 9*1.27, 0   , 1, 0, 0  ) #end
#macro CON_THT_MODULAR_RJ11_S()     ModularJack(4, 9*1.27, 0   , 1, 0, 0  ) #end
#macro CON_THT_MODULAR_215875_3()   ModularJack(4, 6*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_215876_6()   ModularJack(4, 8*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_215876_7()   ModularJack(2, 8*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_215877_4()   ModularJack(8, 9*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_215877_7()   ModularJack(8, 9*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_215878_2()   ModularJack(8, 9*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_555140_1()   ModularJack(6, 8*1.27, 0   , 2, 1, 0  ) #end
#macro CON_THT_MODULAR_555140_2()   ModularJack(4, 8*1.27, 0   , 2, 1, 0  ) #end
#macro CON_THT_MODULAR_555153_1()   ModularJack(8, 9*1.27, 0   , 2, 1, 0  ) #end
#macro CON_THT_MODULAR_555154_1()   ModularJack(6, 8*1.27, 0   , 2, 1, 0  ) #end
#macro CON_THT_MODULAR_555154_2()   ModularJack(4, 8*1.27, 0   , 2, 1, 0  ) #end
#macro CON_THT_MODULAR_555162_1()   ModularJack(8, 9*1.27, 1.27, 0, 1, 0  ) #end
#macro CON_THT_MODULAR_555163_1()   ModularJack(6, 8*1.27, 1.27, 0, 1, 0  ) #end
#macro CON_THT_MODULAR_555163_2()   ModularJack(4, 8*1.27, 1.27, 0, 1, 0  ) #end
#macro CON_THT_MODULAR_555164_1()   ModularJack(8, 9*1.27, 1.27, 0, 0, 0  ) #end
#macro CON_THT_MODULAR_555165_1()   ModularJack(6, 8*1.27, 1.27, 0, 0, 0  ) #end
#macro CON_THT_MODULAR_555165_2()   ModularJack(4, 8*1.27, 1.27, 0, 0, 0  ) #end
#macro CON_THT_MODULAR_555165_5()   ModularJack(2, 8*1.27, 1.27, 0, 0, 0  ) #end
#macro CON_THT_MODULAR_555166_1()   ModularJack(8, 9*1.27, 1.27, 0, 1, 0  ) #end
#macro CON_THT_MODULAR_555166_3()   ModularJack(4, 9*1.27, 1.27, 0, 1, 0  ) #end
#macro CON_THT_MODULAR_555167_1()   ModularJack(8, 9*1.27, 1.27, 0, 0, 0  ) #end
#macro CON_THT_MODULAR_555167_2()   ModularJack(6, 9*1.27, 1.27, 0, 0, 0  ) #end
#macro CON_THT_MODULAR_RJ11_14867() ModularJack(4, 6*1.27, 0   , 0, 0, 2.5) #end
#macro CON_THT_MODULAR_TYCO_RJ11()  ModularJack(6, 8*1.27, 0   , 0, 0, 0  ) #end
#macro CON_THT_MODULAR_TYCO_RJ11S() ModularJack(6, 8*1.27, 0   , 1, 0, 2.5) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_MODULAR_RJ11(:RJ11 Modular Jack THT
//=CON_THT_MODULAR_RJ11_S(:RJ11 Modular Jack THT shielded
//=CON_THT_MODULAR_RJ12(:RJ12 Modular Jack THT
//=CON_THT_MODULAR_RJ12_S(:RJ12 Modular Jack THT shielded
//=CON_THT_MODULAR_RJ45(:RJ45 Modular Jack THT
//=CON_THT_MODULAR_RJ45_S(:RJ45 Modular Jack THT shielded
//con-4ucon:14867=CON_THT_MODULAR_RJ11_14867(:RJ11 Modular Jack THT
//con-tycoelectronics:RJ11-NO_SHIELD=CON_THT_MODULAR_TYCO_RJ11(:RJ11 Modular Jack THT
//con-tycoelectronics:RJ11-SHIELD1=CON_THT_MODULAR_TYCO_RJ11S(:RJ11 Modular Jack THT
//con-tycoelectronics:RJ11-SHIELD2=CON_THT_MODULAR_TYCO_RJ11S(:RJ11 Modular Jack THT
//con-amp:215875-3=CON_THT_MODULAR_215875_3(:Modular Jack THT 4-pol
//con-amp:215876-6=CON_THT_MODULAR_215876_6(:Modular Jack THT 4-pol
//con-amp:215876-7=CON_THT_MODULAR_215876_7(:Modular Jack THT 2-pol
//con-amp:215877-4=CON_THT_MODULAR_215877_4(:Modular Jack THT 8-pol
//con-amp:215877-7=CON_THT_MODULAR_215877_7(:Modular Jack THT 8-pol
//con-amp:215878-2=CON_THT_MODULAR_215878_2(:Modular Jack THT 8-pol
//com-amp:555140_1=CON_THT_MODULAR_555140_1(:Modular Jack THT 6-pol
//com-amp:555140_2=CON_THT_MODULAR_555140_2(:Modular Jack THT 4-pol
//com-amp:555153_1=CON_THT_MODULAR_555153_1(:Modular Jack THT 8-pol
//com-amp:555154_1=CON_THT_MODULAR_555154_1(:Modular Jack THT 6-pol
//com-amp:555154_2=CON_THT_MODULAR_555154_2(:Modular Jack THT 4-pol
//com-amp:555162_1=CON_THT_MODULAR_555162_1(:Modular Jack THT 8-pol
//com-amp:555163_1=CON_THT_MODULAR_555163_1(:Modular Jack THT 6-pol
//com-amp:555163_2=CON_THT_MODULAR_555163_2(:Modular Jack THT 4-pol
//com-amp:555164_1=CON_THT_MODULAR_555164_1(:Modular Jack THT 8-pol
//com-amp:555165_1=CON_THT_MODULAR_555165_1(:Modular Jack THT 6-pol
//com-amp:555165_2=CON_THT_MODULAR_555165_2(:Modular Jack THT 4-pol
//com-amp:555165_5=CON_THT_MODULAR_555165_5(:Modular Jack THT 2-pol
//com-amp:555166_1=CON_THT_MODULAR_555166_1(:Modular Jack THT 8-pol
//com-amp:555166_3=CON_THT_MODULAR_555166_3(:Modular Jack THT 4-pol
//com-amp:555167_1=CON_THT_MODULAR_555167_1(:Modular Jack THT 8-pol
//com-amp:555167_2=CON_THT_MODULAR_555167_2(:Modular Jack THT 6-pol
// end assignment
