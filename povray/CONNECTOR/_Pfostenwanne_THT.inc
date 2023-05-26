






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




/********************************************************************************************************************************************
// Tilmann Reh <tilmann.reh@autometer.de>
// gerade Pfostenwannen
// Bezugspunkt: geometrische Mitte der Pins auf PCB-Oberflaeche
********************************************************************************************************************************************/
#macro CON_WS_XX_G_BASE(Pins)
  union {
     object{
        PFOSTENWANNE(7.62+Pins*1.27)
        }
     GRID(object { PIN_STRAIGHT(0.635,8.5,3) texture { col_gold } },2.54,Pins/2,2)
     }
#end


#macro CON_DIS_WS6G()  CON_WS_XX_G_BASE(6)  #end
#macro CON_DIS_WS10G() CON_WS_XX_G_BASE(10) #end
#macro CON_DIS_WS14G() CON_WS_XX_G_BASE(14) #end
#macro CON_DIS_WS16G() CON_WS_XX_G_BASE(16) #end
#macro CON_DIS_WS20G() CON_WS_XX_G_BASE(20) #end
#macro CON_DIS_WS26G() CON_WS_XX_G_BASE(26) #end
#macro CON_DIS_WS34G() CON_WS_XX_G_BASE(34) #end
#macro CON_DIS_WS40G() CON_WS_XX_G_BASE(40) #end
#macro CON_DIS_WS50G() CON_WS_XX_G_BASE(50) #end
#macro CON_DIS_WS64G() CON_WS_XX_G_BASE(64) #end