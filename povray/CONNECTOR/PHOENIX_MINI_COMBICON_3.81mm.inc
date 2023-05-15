/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
 * Author: Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
 ******************************************************************************/


/*******************************************************************************
 * Stecker Gehaeuse (PCB part), eine Zelle.
 ******************************************************************************/
#macro CON_PHOENIX_381_PHGH()
  union {
     difference {
        box{<-1,0,-1.905><8,7,1.905> }
        cylinder{<-1.1,5,0><0.6,5,0>0.65 }
        box{<-1.1,6,-1.4><-0.8,6.5,1.4> }
        box{<-1.1,-0.1,-1.4><-0.8,4,1.4> }
        box{<-1.1,-0.1,-0.5><-0.2,3,0.5> }
        box{<-1.1,-0.1,-1.4><1.2,1.3,1.4> }
        box{<-1.1,-0.1,-1.4><2.4,0.3,1.4> }
        box{<2,0.6,-1.7><8.1,5.5,1.7> }
        box{<2,5.4,-0.6><8.1,6,0.6> }
        box{<2,5.9,-1.5><8.1,6.7,1.5> }
        pigment{ForestGreen}
        }
     //Rundung unten
     difference {
        cylinder{<2,-1.0,0><8,-1.0,0>2.0 }
        box{<1.9,-3.1,-2.1><8.1,0.1,2.1> }
        pigment{ForestGreen}
        }
     //Oben auf
     cylinder{<5,7,-1.905><5,7,1.905>0.2 pigment{ForestGreen}}
     //Links
     box{<6,2,-1.9><8,3.3,-2.1> pigment{ForestGreen}}
     box{<7.5,0.5,-1.9><8,6.5,-2.1> pigment{ForestGreen}}
     //Rechts
     box{<6,2,1.9><8,3.3,2.1> pigment{ForestGreen}}
     box{<7.5,0.5,1.9><8,6.5,2.1> pigment{ForestGreen}}
     }
#end


/*******************************************************************************
 * Phoenix - Gegenstecker Kunststoff MC 1,5/xx-ST-381
 ******************************************************************************/
#macro CON_PHOENIX_381_PHGSG()
  union {
     difference {
        merge {
           box{<0,0,-1.905><9,9.5,1.905> }
           box{<4,9.5,-1.905><9,11,1.905> }
           box{<-6.2,4,-1.5><0,8,1.5> }
           box{<-6.1,8,-0.4><-4,9,0.4> }
           sphere { <2.05, 9.5, 0>, 0.5 }
           cylinder{<4,9.5,0><4,11,0>1.905 }
           cylinder{<9,7.1,-1.905><9,7.1,1.905>0.3 }
           }
        box{<0.3,0.8,-0.75><9.5,5.5,0.75> }
        box{<8.5,0.5,-1.2><9.5,6.5,1.2> }
        box{<6.3,10.5,-0.9><7,11.1,0.9> }
        box{<-2,-2,-2><2,2,2> rotate<0,0,12> translate<9.9,9.5,0>}
        cylinder{<4,7,0><4,11.1,0>1.4 }
        cylinder{<-6.3,6.5,0><1.5,6.5,0>0.5}
        cylinder{<-6.3,6.5,0><-5.8,6.5,0>0.9}
        cylinder{<-6.3,2.5,0><0,2.5,0>2.0}
        }
     cylinder{<7.5,10.70,-1.905><7.5,10.70,1.905>0.3 }
     pigment{ForestGreen}
     }
#end


/*******************************************************************************
 * Phoenix - Gegenstecker   MCVW 1,5/xx-ST-381 (type =0) und
 *           Kunststoffteil MCVR 1,5/xx-ST-381 (type =1)
 ******************************************************************************/
#macro CON_PHOENIX_381_PHGSRW(typ)
  union {
     difference {
        union {
           box{<-1.5,0,-1.9><1.5,-6.6,2.2>}
           box{<-0.4,-6.5,-1.9><0.4,-4,-3.2> }
           }
        cylinder{<0,0.1,3.7><0,-6.7,3.7>2.0}
        cylinder{<0,0.1,0><0,-6.7,0>0.5}
        cylinder{<0,-6.0,0><0,-6.7,0>0.9}
        #if (typ = 1) //MVCR
            rotate <0,180,0>
        #end
        }
     difference {
        union {
           box{<-1.905,0,3.7><1.905,11.6,-4.6>}
           cylinder{<-1.905,7.3,4.9><1.905,7.3,4.9>0.3 }
           box{<-1.905,0,3.7><1.905,7.3,5.2>}
           box{<-1.905,7.3,3.7><1.905,7.6,4.9>}
           box{<-1.905,0,-4.6><1.905,2.45,-5.2>}
           }
        box{<-1.95,0,-2.2><1.95,2.0,2.2> rotate <70,0,0> translate <0,9.7,2.9>}
        box{<-0.9,2.7,5.3><0.9,5.5,-4>}
        box{<-1.5,2.5,5.3><1.5,6.6,4>}
        }
     difference {
        union {
           cylinder{<-1.905,12.2,2.7><1.905,12.2,2.7>0.3 }
           cylinder{<-1.905,12.2,-1.65><1.905,12.2,-1.65>0.3 }
           box{<-1.905,11.9,2.7><1.905,12.5,-1.65>}
           cylinder{<-1.905,11.9,-4.9><1.905,11.9,-4.9>0.3 }
           box{<-1.905,11.6,2.1><1.905,12.2,-4.9>}
           }
        cylinder{<0,10.6,0><0,12.6,0>1.4}
        }
     pigment{ForestGreen}
     }
#end


/*******************************************************************************
 * contact number plate
 ******************************************************************************/
#macro CON_PHOENIX_381_PHNR(n)
  union {
     box{<-1.905,0,-1.75><1.905,0.1,1.75> pigment{White}}
     box{<-1.89,0,-1.75><-1.905,0.25,1.75> pigment{Gray20}}
     box{<1.905,0,-1.75><1.89,0.25,1.75> pigment{Gray20}}
     #if (n < 10)
        text {ttf besch_font str(n,0,0) 0.2,0  scale<3.5,3.5,3.5> pigment{Gray20} rotate<90,180,0> translate<0.8,0.2,1.2> }
     #else
        text {ttf besch_font str(n,0,0) 0.2,0  scale<3.0,3.5,3.5> pigment{Gray20} rotate<90,180,0> translate<1.5,0.2,1.2> }
     #end
     }
#end


/*******************************************************************************
 * straight contact pin
 ******************************************************************************/
#macro CON_PHOENIX_381_PHPIN()
  difference {
     box{<-0.35,-3.5,-0.35><0.35,7.5,0.35>}
     // anspitzen oben
     box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,30> translate<0.4,7,0>}
     box{<0,0,-0.7><-0.7,0.7,0.7> rotate<0,0,-30> translate<-0.4,7,0>}
     box{<-0.7,0,0><0.7,0.7,0.7> rotate<-30,0,0> translate<0,7,0.4>}
     box{<-0.7,0,0><0.7,0.7,-0.7> rotate<30,0,0> translate<0,7,-0.4>}
     // anspitzen unten
     box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,-30> translate<0.1,-3.5,0>}
     box{<0,0,-0.7><-0.7,0.7,0.7> rotate<0,0,30> translate<-0.1,-3.5,0>}
     box{<-0.7,0,0><0.7,0.7,0.7> rotate<30,0,0> translate<0,-3.5,0.1>}
     box{<-0.7,0,0><0.7,0.7,-0.7> rotate<-30,0,0> translate<0,-3.5,-0.1>}
     texture{col_silver}
     }
#end


/*******************************************************************************
 * 90deg elbow contact pin
 ******************************************************************************/
#macro CON_PHOENIX_381_PHPINW()
  difference {
     object {TOOLS_RECT_BOGEN(0.1,90,0.7,0.7,6,7)}
     //laenge1 anspitzen
     box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,30> translate<0.4,7,0>}
     box{<0,0,-0.7><-0.7,0.7,0.7> rotate<0,0,-30> translate<-0.4,7,0>}
     box{<-0.7,0,0><0.7,0.7,0.7> rotate<-30,0,0> translate<0,7,0.4>}
     box{<-0.7,0,0><0.7,0.7,-0.7> rotate<30,0,0> translate<0,7,-0.4>}
     //laenge2 anspitzen
     box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,-30> translate<6,0.4,0>}
     box{<0,0,-0.7><0.7,-0.7,0.7> rotate<0,0,30> translate<6,-0.4,0>}
     box{<0,-0.7,0><0.7,0.7,0.7> rotate<0,30,0> translate<6,0,0.4>}
     box{<0,-0.7,0><0.7,0.7,-0.7> rotate<0,-30,0> translate<6,0,-0.4>}
     texture{col_silver} rotate<0,0,-90> translate<0,3.0,0>
     }
#end


#macro CON_PHOENIX_381_SCREWHEAD()
  difference {
     superellipsoid{<1,0.1> rotate<90,0,0> scale<1.4,0.5,1.4> translate<0,0,0>}
     box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> translate<0,0,0>}
     texture{col_silver}
     }
#end

/*******************************************************************************
 * Phoenix Mini-Combicon 3.81mm Klemmen Winkel (horizontal) mit Gegenstecker
 ******************************************************************************/
#macro CON_PHOENIX_381_PHGGHWS_base(j)
  union {
     #local i = 0;
     #while(i<j)
        object {CON_PHOENIX_381_PHPINW() translate<0,0,i*3.81>}
        object {CON_PHOENIX_381_PHGH() translate<0,0,i*3.81>}
        object {CON_PHOENIX_381_PHGSG() translate<8,-2.9,i*3.81>}
        object {CON_PHOENIX_381_SCREWHEAD()rotate<0,i*75,0> translate<12,7.2,i*3.81> texture{col_silver}}
        object {CON_PHOENIX_381_PHNR(i+1) rotate <78,0,0> translate <0,5.9,16.0> translate<-i*3.81,0,0> rotate<0,90,0> }
     #local i=i+1;
     #end
     translate<0,0,-j*1.905+1.905> rotate<0,90,0>
     }
#end


/*******************************************************************************
 * Phoenix Mini-Combicon 3.81mm Klemmen Winkel MC 1,5/xx-G-381 (horizontal)
 ******************************************************************************/
#macro CON_PHOENIX_381_PHGGHW_base(j)
  union {
     #local i = 0;
     #while(i<j)
        object {CON_PHOENIX_381_PHPINW() translate<0,0,i*3.81>}
        object {CON_PHOENIX_381_PHGH() translate<0,0,i*3.81>}
        #local i=i+1;
     #end
     translate<0,0,-j*1.905+1.905> rotate<0,90,0>
     }
#end


/*******************************************************************************
 * Phoenix Mini-Combicon 3.81mm Klemmen MCV 1,5/xx-G-381 (vertical)
 ******************************************************************************/
#macro CON_PHOENIX_381_PHGGH_base(j)
  union {
     #local i = 0;
     #while(i<j)
        object {CON_PHOENIX_381_PHPIN() translate<0,0,i*3.81>}
        object {CON_PHOENIX_381_PHGH()rotate<0,0,90> translate<3,0,i*3.81>}
        #local i=i+1;
     #end
     translate<0,1,-j*1.905+1.905>
     rotate<0,90,0>
     }
#end


/*******************************************************************************
 * Phoenix Mini-Combicon 3.81mm Gegenstecker (vertikal)
 * MCVW 1,5/xx-ST-381 (k=0) und MCVR 1,5/xx-ST-381 (k=1)
 ******************************************************************************/
#macro CON_PHOENIX_381_PHMCVRW_base(j,k)
  union {
     #local i = 0;
     #while(i<j)
        object {CON_PHOENIX_381_PHGSRW(k) translate<-i*3.81,0,0>}
        object {CON_PHOENIX_381_SCREWHEAD()rotate<0,i*75,0> translate<-i*3.81,11.7,0> texture{col_silver}}
        object {CON_PHOENIX_381_PHNR(i+1) rotate <70,0,0> translate <0,9.5,3.0> translate<-i*3.81,0,0> }
        #local i=i+1;
     #end
     translate<j*1.905-1.905,9.0,0>
     #if (k = 1) //MVCR
         rotate<0,0,0>
     #else
         rotate<0,180,0>
     #end
     }
#end


/*******************************************************************************
 * Phoenix Mini-Combicon 3.81mm Gegenstecker MC 1,5/xx-ST-381 (horizontal)
 ******************************************************************************/
#macro CON_PHOENIX_381_PHWS_base(j)
  union {
     #local i = 0;
     #while(i<j)
        object {CON_PHOENIX_381_PHGSG() translate<8,-2.9,i*3.81>}
        object {CON_PHOENIX_381_SCREWHEAD()rotate<0,i*75,0> translate<12,7.2,i*3.81> texture{col_silver}}
        object {CON_PHOENIX_381_PHNR(i+1) rotate <78,0,0> translate <0,5.9,16.0> translate<-i*3.81,0,0> rotate<0,90,0> }
        #local i=i+1;
     #end
     translate<0,0,-j*1.905+1.905> rotate<0,90,0>
     }
#end



/*******************************************************************************
 * produced parts here:
 ******************************************************************************/
#macro CON_PHOENIX_381_MC_2G()   CON_PHOENIX_381_PHGGHWS_base(2)    #end
#macro CON_PHOENIX_381_MC_3G()   CON_PHOENIX_381_PHGGHWS_base(3)    #end
#macro CON_PHOENIX_381_MC_4G()   CON_PHOENIX_381_PHGGHWS_base(4)    #end
#macro CON_PHOENIX_381_MC_5G()   CON_PHOENIX_381_PHGGHWS_base(5)    #end
#macro CON_PHOENIX_381_MC_6G()   CON_PHOENIX_381_PHGGHWS_base(6)    #end
#macro CON_PHOENIX_381_MC_7G()   CON_PHOENIX_381_PHGGHWS_base(7)    #end
#macro CON_PHOENIX_381_MC_8G()   CON_PHOENIX_381_PHGGHWS_base(8)    #end
#macro CON_PHOENIX_381_MC_9G()   CON_PHOENIX_381_PHGGHWS_base(9)    #end
#macro CON_PHOENIX_381_MC_10G()  CON_PHOENIX_381_PHGGHWS_base(10)   #end
#macro CON_PHOENIX_381_MC_11G()  CON_PHOENIX_381_PHGGHWS_base(11)   #end
#macro CON_PHOENIX_381_MC_12G()  CON_PHOENIX_381_PHGGHWS_base(12)   #end
#macro CON_PHOENIX_381_MC_13G()  CON_PHOENIX_381_PHGGHWS_base(13)   #end
//---
#macro CON_PHOENIX_381_MC_2()    CON_PHOENIX_381_PHGGHW_base(2)     #end
#macro CON_PHOENIX_381_MC_3()    CON_PHOENIX_381_PHGGHW_base(3)     #end
#macro CON_PHOENIX_381_MC_4()    CON_PHOENIX_381_PHGGHW_base(4)     #end
#macro CON_PHOENIX_381_MC_5()    CON_PHOENIX_381_PHGGHW_base(5)     #end
#macro CON_PHOENIX_381_MC_6()    CON_PHOENIX_381_PHGGHW_base(6)     #end
#macro CON_PHOENIX_381_MC_7()    CON_PHOENIX_381_PHGGHW_base(7)     #end
#macro CON_PHOENIX_381_MC_8()    CON_PHOENIX_381_PHGGHW_base(8)     #end
#macro CON_PHOENIX_381_MC_9()    CON_PHOENIX_381_PHGGHW_base(9)     #end
#macro CON_PHOENIX_381_MC_10()   CON_PHOENIX_381_PHGGHW_base(10)    #end
#macro CON_PHOENIX_381_MC_11()   CON_PHOENIX_381_PHGGHW_base(11)    #end
#macro CON_PHOENIX_381_MC_12()   CON_PHOENIX_381_PHGGHW_base(12)    #end
#macro CON_PHOENIX_381_MC_13()   CON_PHOENIX_381_PHGGHW_base(13)    #end
//---
#macro CON_PHOENIX_381_MCV_2()   CON_PHOENIX_381_PHGGH_base(2)      #end
#macro CON_PHOENIX_381_MCV_3()   CON_PHOENIX_381_PHGGH_base(3)      #end
#macro CON_PHOENIX_381_MCV_4()   CON_PHOENIX_381_PHGGH_base(4)      #end
#macro CON_PHOENIX_381_MCV_5()   CON_PHOENIX_381_PHGGH_base(5)      #end
#macro CON_PHOENIX_381_MCV_6()   CON_PHOENIX_381_PHGGH_base(6)      #end
#macro CON_PHOENIX_381_MCV_7()   CON_PHOENIX_381_PHGGH_base(7)      #end
#macro CON_PHOENIX_381_MCV_8()   CON_PHOENIX_381_PHGGH_base(8)      #end
#macro CON_PHOENIX_381_MCV_9()   CON_PHOENIX_381_PHGGH_base(9)      #end
#macro CON_PHOENIX_381_MCV_10()  CON_PHOENIX_381_PHGGH_base(10)     #end
#macro CON_PHOENIX_381_MCV_11()  CON_PHOENIX_381_PHGGH_base(11)     #end
#macro CON_PHOENIX_381_MCV_12()  CON_PHOENIX_381_PHGGH_base(12)     #end
#macro CON_PHOENIX_381_MCV_13()  CON_PHOENIX_381_PHGGH_base(13)     #end
//Phoenix Mini-Combicon 3.81mm Gegenstecker MCVW 1,5/xx-ST-381
#macro CON_PHOENIX_381_MCVW_2()  CON_PHOENIX_381_PHMCVRW_base(2,0)  #end
#macro CON_PHOENIX_381_MCVW_3()  CON_PHOENIX_381_PHMCVRW_base(3,0)  #end
#macro CON_PHOENIX_381_MCVW_4()  CON_PHOENIX_381_PHMCVRW_base(4,0)  #end
#macro CON_PHOENIX_381_MCVW_5()  CON_PHOENIX_381_PHMCVRW_base(5,0)  #end
#macro CON_PHOENIX_381_MCVW_6()  CON_PHOENIX_381_PHMCVRW_base(6,0)  #end
#macro CON_PHOENIX_381_MCVW_7()  CON_PHOENIX_381_PHMCVRW_base(7,0)  #end
#macro CON_PHOENIX_381_MCVW_8()  CON_PHOENIX_381_PHMCVRW_base(8,0)  #end
#macro CON_PHOENIX_381_MCVW_9()  CON_PHOENIX_381_PHMCVRW_base(9,0)  #end
#macro CON_PHOENIX_381_MCVW_10() CON_PHOENIX_381_PHMCVRW_base(10,0) #end
#macro CON_PHOENIX_381_MCVW_11() CON_PHOENIX_381_PHMCVRW_base(11,0) #end
#macro CON_PHOENIX_381_MCVW_12() CON_PHOENIX_381_PHMCVRW_base(12,0) #end
#macro CON_PHOENIX_381_MCVW_13() CON_PHOENIX_381_PHMCVRW_base(13,0) #end
//Phoenix Mini-Combicon 3.81mm Gegenstecker MCVR 1,5/xx-ST-381
#macro CON_PHOENIX_381_MCVR_2()  CON_PHOENIX_381_PHMCVRW_base(2,1)  #end
#macro CON_PHOENIX_381_MCVR_3()  CON_PHOENIX_381_PHMCVRW_base(3,1)  #end
#macro CON_PHOENIX_381_MCVR_4()  CON_PHOENIX_381_PHMCVRW_base(4,1)  #end
#macro CON_PHOENIX_381_MCVR_5()  CON_PHOENIX_381_PHMCVRW_base(5,1)  #end
#macro CON_PHOENIX_381_MCVR_6()  CON_PHOENIX_381_PHMCVRW_base(6,1)  #end
#macro CON_PHOENIX_381_MCVR_7()  CON_PHOENIX_381_PHMCVRW_base(7,1)  #end
#macro CON_PHOENIX_381_MCVR_8()  CON_PHOENIX_381_PHMCVRW_base(8,1)  #end
#macro CON_PHOENIX_381_MCVR_9()  CON_PHOENIX_381_PHMCVRW_base(9,1)  #end
#macro CON_PHOENIX_381_MCVR_10() CON_PHOENIX_381_PHMCVRW_base(10,1) #end
#macro CON_PHOENIX_381_MCVR_11() CON_PHOENIX_381_PHMCVRW_base(11,1) #end
#macro CON_PHOENIX_381_MCVR_12() CON_PHOENIX_381_PHMCVRW_base(12,1) #end
#macro CON_PHOENIX_381_MCVR_13() CON_PHOENIX_381_PHMCVRW_base(13,1) #end
//---
#macro CON_PHOENIX_381_MC_2ST()  CON_PHOENIX_381_PHWS_base(2)       #end
#macro CON_PHOENIX_381_MC_3ST()  CON_PHOENIX_381_PHWS_base(3)       #end
#macro CON_PHOENIX_381_MC_4ST()  CON_PHOENIX_381_PHWS_base(4)       #end
#macro CON_PHOENIX_381_MC_5ST()  CON_PHOENIX_381_PHWS_base(5)       #end
#macro CON_PHOENIX_381_MC_6ST()  CON_PHOENIX_381_PHWS_base(6)       #end
#macro CON_PHOENIX_381_MC_7ST()  CON_PHOENIX_381_PHWS_base(7)       #end
#macro CON_PHOENIX_381_MC_8ST()  CON_PHOENIX_381_PHWS_base(8)       #end
#macro CON_PHOENIX_381_MC_9ST()  CON_PHOENIX_381_PHWS_base(9)       #end
#macro CON_PHOENIX_381_MC_10ST() CON_PHOENIX_381_PHWS_base(10)      #end
#macro CON_PHOENIX_381_MC_11ST() CON_PHOENIX_381_PHWS_base(11)      #end
#macro CON_PHOENIX_381_MC_12ST() CON_PHOENIX_381_PHWS_base(12)      #end
#macro CON_PHOENIX_381_MC_13ST() CON_PHOENIX_381_PHWS_base(13)      #end
