/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * PCB Standard Terminal Block, Wire to Board, 3.5mm grid
 * Author(s): Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
 *            Carsten Koegler, FTZ-Leipzig <koegler@ftz-leipzig.de>
 *
 * 20220422 wk: renamed macro from CON_ARK_350MM (Anreihklemme) to
 *              CON_THT_RIA59_<N>, converted to GRID()
 *              fix number label
 *
 * NOTE: available from multiple suppliers,
 *       ie. RIA AKL 059-xx (Reichelt AKL 059-02, AKL059#RIA.pdf)
 *
 * NOTE: not assigned to any eagle .lbr, but nicely done,
 *       so may be create some library later for it.
 ******************************************************************************/

#macro RIA_series59_single()
  union {
     // Einloetstift
     cylinder{<0,-3.0,0><0,1.0,0>0.45 texture{col_silver}}
     cone{<0,-3.0,0>0.45<0,-3.4,0>0.1 texture{col_silver}}
     // Plastikkoerper
     difference {
        box{<-1.75,0,-3.7><1.75,8.2,2.8>}                                     // Hauptbox
        box{<-1.4 ,0.6,-4><1.4 ,5.1,2.2>}                                     // Loch fuer Drahteinfuehrung
        box{<-0.75,-0.1,-4.01><0.75,1.1,1>}                                   // Schlitz in der unteren Mitte
        box{<-1.5 ,-0.1,-1.5><1.5,0.7,1.5> rotate<0,45,0> translate<0,0,-4.8>}// Schlitz etwas abrunden
        box{<-2.6,5,0><2.6,0,-3> rotate<30,0,0> translate<0,4.6,-4>}          // Klemme vorne oben abschraegen
        cylinder{<0,5.2,0><0,10,0>1.5}                                        // Senkrechte Loecher fuer die Schraube - oben etwas weiter
        cylinder{<0,2.2,0><0,5.2,0>1.1}                                       //                                      - unten kleiner
        }
     // Abgeschraegten Innenteil hinzufuegen (siehe Datenblatt)
     box{<-1.4 , 4.6,-1.9><1.4,5.1,2.8>}
     difference {
        box{<-1.4 , -0.25,-0.25><1.4,0.25,0.25>}
        box{<-1.5 , -0.35,-0.35><1.5,0.35,0.35>rotate<45,0,0> translate<0,-0.25,-0.25>}
        translate<0,4.85,-2.15>
        }
     // Schraube
     superellipsoid{<1,0.1> rotate<90,0,0> scale<0.9,2.0,1> texture{col_silver} translate<0,5.0,0>}
     difference {
        superellipsoid{<1,0.1> rotate<90,0,0> scale<1.3,0.5,1.3> texture{col_silver} translate<0,7.3,0>}
        box{<0.25,0,-2><-0.25,1,2>rotate<0,rand(global_seed)*180,0> translate<0,7.6,0>}
        }
     // metallenes Innenleben
     difference {
        box{<-1.35,0.65,-1.9><1.35,4.4,2.5>}   // Hauptkoerper
        cylinder{<0,2.2,-2.0><0,2.2,2.6>1.1}   // Loch
        cylinder{<0,2.2,0><0,5.2,0>1.1}
        texture{col_silver}
        }
     // Drahtschutz
     box{<-0.95,4.45,-2.0><0.95,4.5,2.5>texture{col_silver}} // oberer Teil
     difference {                                            // oberer Bogen
        cylinder {<-0.95,-0.1 ,0>,< 0.95,-0.1 ,0>,0.1 }
        cylinder {<-1.0 ,-0.1 ,0>,< 1.0 ,-0.1 ,0>,0.05}
        box{<-1,-1.0,-2><1,-0.1,2>}
        box{<-1,-1.0,0><1, 1.0,1>}
        texture{col_silver}
        rotate<0,0,0>
        translate<0,4.5,-2.0 >
        }
     box{<-0.95,2.2,-2.1><0.95,4.4,-2.05>texture{col_silver}}   // vorderer Teil
        difference {                                                // unterer Bogen
           cylinder {<-0.95,-0.1 ,0>,< 0.95,-0.1 ,0>,0.1 }
           cylinder {<-1.0 ,-0.1 ,0>,< 1.0 ,-0.1 ,0>,0.05}
           box{<-1,-1.0,-2><1,-0.1,2>}
           box{<-1,-1.0,0><1, 1.0,1>}
           texture{col_silver}
           rotate<0,0,180>
           translate<0,2.1,-2.0 >
           }
     box{<-0.95,2.1,-2.0><0.95,2.15,2>texture{col_silver}}    // unterer Teil
     pigment{Gray30}
     }
#end



/*******************************************************************************
 * Grundmakro fuer Anreihklemme 3.5mm
 ******************************************************************************/
#macro RIA_series59(j)
  union {
     GRID(RIA_series59_single(),3.5,j,1)
     union {
        #local i = 0;
        #while(i<j)
           text {
              ttf besch_font str(j-i,0,0) 0.2,0
              scale <2,2,2>
              rotate <30,0,0>
              translate <-i*3.5-1,6.6,-2.9>
              pigment {
                 Black
                 }
              }
           #local i=i+1;
        #end
        translate <(i-1)*3.5-j*1.75+1.75,0,0>
        }
     }
#end

#macro CON_THT_RIA59_2()  RIA_series59(2)  #end
#macro CON_THT_RIA59_3()  RIA_series59(3)  #end
#macro CON_THT_RIA59_4()  RIA_series59(4)  #end
#macro CON_THT_RIA59_5()  RIA_series59(5)  #end
#macro CON_THT_RIA59_6()  RIA_series59(6)  #end
#macro CON_THT_RIA59_7()  RIA_series59(7)  #end
#macro CON_THT_RIA59_8()  RIA_series59(8)  #end
#macro CON_THT_RIA59_9()  RIA_series59(9)  #end
#macro CON_THT_RIA59_10() RIA_series59(10) #end
#macro CON_THT_RIA59_11() RIA_series59(11) #end
#macro CON_THT_RIA59_12() RIA_series59(12) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_RIA59_2(:PCB terminal block 3.5mm
//=CON_THT_RIA59_3(:PCB terminal block 3.5mm
//=CON_THT_RIA59_4(:PCB terminal block 3.5mm
//=CON_THT_RIA59_5(:PCB terminal block 3.5mm
//=CON_THT_RIA59_6(:PCB terminal block 3.5mm
//=CON_THT_RIA59_7(:PCB terminal block 3.5mm
//=CON_THT_RIA59_8(:PCB terminal block 3.5mm
//=CON_THT_RIA59_9(:PCB terminal block 3.5mm
//=CON_THT_RIA59_10(:PCB terminal block 3.5mm
//=CON_THT_RIA59_11(:PCB terminal block 3.5mm
//=CON_THT_RIA59_12(:PCB terminal block 3.5mm
// end assignment
