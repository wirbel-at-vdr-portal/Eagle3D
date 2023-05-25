

// ////////////////////////////////////////////////////////////
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Um 90° gebogener, quadratischer Stift eines Steckverbinders.
// Verwendung fuer abgewinkelte Pfostenwannen sowie z.B. Wago-Steckerleisten.
// Parameter: Staerke, Biegeradius (Mitte), Hoehe ueber/unter PCB-Oberkante, Laenge nach vorn (-Z), Farbe
// //////////
#macro PIN_BENDED(D,R,HO,HU,L,col)
union {
difference {
cylinder{<0,-D/2,0><0,D/2,0> R+D/2}
cylinder{<0,-D,0><0,D,0> R-D/2}
box{<-R-D,-D,-R-D><0,D,R+D>}
box{<-R-D,-D,-R-D><R+D,D,0>}
rotate<0,0,90> translate<0,HO-R,-R>}
difference {
box{<-D/2,-HU,-D/2><D/2,HO-R,D/2>}
box{<0,0,-0.6*D><0.6*D,0.6*D,0.6*D> rotate<0,0,-45> translate<D/4,-HU,0>}
box{<0,0,-0.6*D><-0.6*D,0.6*D,0.6*D> rotate<0,0,45> translate<-D/4,-HU,0>}
box{<-0.6*D,0,0><0.6*D,0.6*D,0.6*D> rotate<45,0,0> translate<0,-HU,D/4>}
box{<-0.6*D,0,0><0.6*D,0.6*D,-0.6*D> rotate<-45,0,0> translate<0,-HU,-D/4>}}
difference {
box{<-D/2,HO-D/2,-L><D/2,HO+D/2,-R>}
box{<0,-0.6*D,0><0.6*D,0.6*D,0.6*D> rotate<0,45,0> translate<D/4,HO,-L>}
box{<0,-0.6*D,0><-0.6*D,0.6*D,0.6*D> rotate<0,-45,0> translate<-D/4,HO,-L>}
box{<-0.6*D,0,0><0.6*D,-0.6*D,-0.6*D> rotate<-45,0,0> translate<0,HO-D/4,-L>}
box{<-0.6*D,0,0><0.6*D,0.6*D,-0.6*D> rotate<45,0,0> translate<0,HO+D/4,-L>}}
texture{col}}
#end


// ////////////////////////////////////////////////////////////
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Reihe gebogener quadratischer Stifte z.B. fuer Pfostenwannen oder Wago-Stecker.
// Parameter: Anzahl Pins, Pitch, Staerke, Radius, Hoehen ueber/unter PCB, Laenge, Farbe.
// Bezugspunkt: Mitte der Pinreihe.
// Reihe gebogener quadratischer Stifte
// //////////
#macro PIN_BENDED_ROW(Pins,Pitch,D,R,HO,HU,L,col)
union {
#local i=0;
#while(i<Pins) object{PIN_BENDED (D,R,HO,HU,L,col) translate<i*Pitch,0,0>} #local i=i+1; #end
translate<-(Pins-1)*Pitch/2,0,0>}
#end

/********************************************************************************************************************************************
//Stefan Seegel <post(replace with at)seegel-systeme.de
//SMD Stiftleisten 2-reihig RM 2.0
********************************************************************************************************************************************/
#macro CON_PH2SMD_2MM_BASE(Pins)
union
{
   object{PIN_BENDED_ROW (Pins, 2.00, 0.5, 0.8, 1.75, 0, 6.77, col_gold) rotate<90,0,0> translate<0,0.25,-2.75>}
   object{PIN_BENDED_ROW (Pins, 2.00, 0.5, 0.8, 1.75, 0, 6.77, col_gold) rotate<90,180,0> translate<0,0.25,2.75>}
   difference
   {
      box{<-Pins, 0.6, -2><Pins,2.6, 2> pigment{Gray30} translate<0,0,0>}
      box{<-Pins-0.5,0.9,-1.7><Pins + 0.5, 2.3,1.7> pigment{Gray30} rotate<45,0,0> translate<0,1.5,1.5>}
      box{<-Pins-0.5,0.9,-1.7><Pins + 0.5, 2.3,1.7> pigment{Gray30} rotate<-45,0,0> translate<0,1.5,-1.5>}
   }
}
#end


#macro CON_PHSMD_2MM_2X2()  CON_PH2SMD_2MM_BASE(2)  #end
#macro CON_PHSMD_2MM_2X3()  CON_PH2SMD_2MM_BASE(3)  #end
#macro CON_PHSMD_2MM_2X4()  CON_PH2SMD_2MM_BASE(4)  #end
#macro CON_PHSMD_2MM_2X5()  CON_PH2SMD_2MM_BASE(5)  #end
#macro CON_PHSMD_2MM_2X6()  CON_PH2SMD_2MM_BASE(6)  #end
#macro CON_PHSMD_2MM_2X7()  CON_PH2SMD_2MM_BASE(7)  #end
#macro CON_PHSMD_2MM_2X8()  CON_PH2SMD_2MM_BASE(8)  #end
#macro CON_PHSMD_2MM_2X9()  CON_PH2SMD_2MM_BASE(9)  #end
#macro CON_PHSMD_2MM_2X10() CON_PH2SMD_2MM_BASE(10) #end
#macro CON_PHSMD_2MM_2X11() CON_PH2SMD_2MM_BASE(11) #end
#macro CON_PHSMD_2MM_2X12() CON_PH2SMD_2MM_BASE(12) #end
#macro CON_PHSMD_2MM_2X13() CON_PH2SMD_2MM_BASE(13) #end
#macro CON_PHSMD_2MM_2X14() CON_PH2SMD_2MM_BASE(14) #end
#macro CON_PHSMD_2MM_2X15() CON_PH2SMD_2MM_BASE(15) #end
#macro CON_PHSMD_2MM_2X16() CON_PH2SMD_2MM_BASE(16) #end
