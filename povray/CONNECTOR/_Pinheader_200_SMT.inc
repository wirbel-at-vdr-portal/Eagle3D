






/********************************************************************************************************************************************
//Stefan Seegel <post(replace with at)seegel-systeme.de
//SMD Stiftleisten 2-reihig RM 2.0
********************************************************************************************************************************************/
#macro CON_PH2SMD_2MM_BASE(Pins)
  union {
     #local row = object {
         GRID(PIN_90deg(0.5, 0.8, 1.75, 0, 6.77),2.00,Pins,1)
         rotate <90,180,0>
         translate <0,0.25,2.75>
         };
     ROTATE(row,2,180)

     difference {
        box{<-Pins, 0.6, -2><Pins,2.6, 2> pigment{Gray30} translate<0,0,0>}
        box{<-Pins-0.5,0.9,-1.7><Pins + 0.5, 2.3,1.7> pigment{Gray30} rotate<45,0,0> translate<0,1.5,1.5>}
        box{<-Pins-0.5,0.9,-1.7><Pins + 0.5, 2.3,1.7> pigment{Gray30} rotate<-45,0,0> translate<0,1.5,-1.5>}
        }
     texture {
        col_gold
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
