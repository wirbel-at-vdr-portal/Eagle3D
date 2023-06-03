


// //////////
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Kunststoffkoerper von Pfostenwannen.
// Verwendung fuer gerade und abgewinkelte Bauform jeweils in Verbindung mit entspr. Pinreihen.
// Parameter: Breite. (Hoehe/Tiefe sind konstant fuer alle Groessen.)
// Bezugspunkt: Mitte der Auflageflaeche (gerade Ausfuehrung).
// Kunststoffkoerper von Pfostenwannen
#macro PFOSTENWANNE(B)
union {
difference {
box{<-B/2,0.3,-4.2><B/2,9,4.5>}
box{<-B/2+1,2.5,-3.2><B/2-1,10,3.5>}
box{<-2.2,2,2.5><2.2,10,5>}
box{<B/2-1.1,0,-1.75><B/2+0.1,6.5,1.75>}
box{<-B/2+1.1,0,-1.75><-B/2-0.1,6.5,1.75>}}
difference {
box{<B/2-6.08,6,4><B/2-4.08,8,4.6>}
box{<0,0,0><2,3,0.7> rotate<0,0,-30> translate<B/2-5.08,6,4>}
box{<0,0,0><-2,3,0.7> rotate<0,0,30> translate<B/2-5.08,6,4>}}
cylinder{<0,0.3,-4.2><0,8.5,-4.2> 0.3}
sphere{<0,0.3,-3.2> 0.3}
sphere{<0,0.3,3.2> 0.3}
#local xc=7.62;
#while (xc<B/2-1)
cylinder{<xc,0.3,-4.2><xc,8.5,-4.2> 0.3}
cylinder{<-xc,0.3,-4.2><-xc,8.5,-4.2> 0.3}
sphere{<xc,0.3,-3.2> 0.3}
sphere{<xc,0.3,3.2> 0.3}
sphere{<-xc,0.3,-3.2> 0.3}
sphere{<-xc,0.3,3.2> 0.3}
#local xc=xc+7.62;
#end

  
texture{pigment { Gray70 }
     finish { ambient(0.10 * global_ambient_mul) }}
}
#end










/*******************************************************************************
 * box header 2.54mm
 * (abgewinkelte Pfostenwannen 2.54mm, ie. Reichelt "WSL 16W")
 * Tilmann Reh <tilmann.reh@autometer.de>
 * Bezugspunkt mittig, 5.08mm vor der unteren/inneren Pinreihe
 ******************************************************************************/
#macro BH1R_XX_L(Pins)
union {
  object {
     PFOSTENWANNE(7.62+Pins*1.27)
     rotate <-90,0,0>
     translate<0,4.5,3.3>
     }
  object {
     GRID(PIN_90deg(0.635,0.8,4.5-1.27,3,10.5),2.54,Pins/2,1)
     translate <0,0,5.08>
     }
  object {
     GRID(PIN_90deg(0.635,0.8,4.5+1.27,3,13.04),2.54,Pins/2,1)
     translate <0,0,7.62>
     }
  rotate <0,180,0>
  translate <0,0,+6.35>
  texture {
     col_gold
     }
  }
#end

#macro CON_DIS_WS10W() BH1R_XX_L(10) #end
#macro CON_DIS_WS14W() BH1R_XX_L(14) #end
#macro CON_DIS_WS16W() BH1R_XX_L(16) #end
#macro CON_DIS_WS20W() BH1R_XX_L(20) #end
#macro CON_DIS_WS26W() BH1R_XX_L(26) #end
#macro CON_DIS_WS34W() BH1R_XX_L(34) #end
#macro CON_DIS_WS40W() BH1R_XX_L(40) #end
#macro CON_DIS_WS50W() BH1R_XX_L(50) #end
#macro CON_DIS_WS64W() BH1R_XX_L(64) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
//con-ml:ML10L=CON_THT_WSL10W(:Shrouded Header bended 10Pin
//con-ml:ML14L=CON_THT_WSL14W(:Shrouded Header bended 14Pin
//con-ml:ML16L=CON_THT_WSL16W(:Shrouded Header bended 16Pin
//con-ml:ML20L=CON_THT_WSL20W(:Shrouded Header bended 20Pin
//con-ml:ML26L=CON_THT_WSL26W(:Shrouded Header bended 26Pin
//con-ml:ML34L=CON_THT_WSL34W(:Shrouded Header bended 34Pin
//con-ml:ML40L=CON_THT_WSL40W(:Shrouded Header bended 40Pin
//con-ml:ML50L=CON_THT_WSL50W(:Shrouded Header bended 50Pin
//con-ml:ML64L=CON_THT_WSL64W(:Shrouded Header bended 64Pin
// end assignment
