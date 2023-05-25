// ////////////////////////////////////////////////////////////
// Original file: ./1_PHW.inc.src
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Pin fuer Stiftleisten Winkel
// //////////
#macro PHW()
union {
//PIN Loetseite
difference {
box{<0,0,0><0.6,3,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-30> translate<0.1,0,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,30> translate<-0.1,0,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<30,0,0> translate<0,0,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-30,0,0> translate<0,0,-0.1>}
translate<0,-2.22,0>}
//PIN Steckseite
difference {
box{<0,0,0><0.6,9,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-60> translate<0.1,9,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,60> translate<-0.1,9,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<60,0,0> translate<0,9,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-60,0,0> translate<0,9,-0.1>}
rotate<0,0,-90> translate<0.5,1.27,0>}
//PIN Bogen
difference {
box{<0,0,0><0.6,0.4,0.4> texture{col_gold} translate<0,0.0,0.0>}
cylinder{<-0.1,0,0><0.8,0,0>0.2 texture{col_gold} translate<0,0.0,0.0>}
rotate<0,-90,0> translate<0.5,0.77,-0.3>}
difference {
cylinder{<0,0,0><0.6,0,0>0.8 texture{col_gold} translate<0,0,0> }
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,0,-0.1>}
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,-1.8,0.4>}
rotate<0,-90,0> translate<0.5,0.77,-0.3>}
//Kunststoff
difference {
box{<0,-1.27,-1.27><2,1.27,1.27> pigment{Gray30} translate<0,0,0>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,-1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,-1.76,-1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,-1.76,1.76>}
translate<1.5,1.27,0>}
rotate<0,-90,0>
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PHW2.inc.src
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Pin fuer Stiftleisten Winkel obere Reihe
// //////////
#macro PHW2()
union {
//PIN Loetseite
difference {
box{<0,0,0><0.6,5.54,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-30> translate<0.1,0,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,30> translate<-0.1,0,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<30,0,0> translate<0,0,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-30,0,0> translate<0,0,-0.1>}
translate<0,-2.22,0>}
//PIN Steckseite
difference {
box{<0,0,0><0.6,11.54,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-60> translate<0.1,11.54,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,60> translate<-0.1,11.54,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<60,0,0> translate<0,11.54,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-60,0,0> translate<0,11.54,-0.1>}
rotate<0,0,-90> translate<0.5,3.81,0>}
//PIN Bogen
difference {
box{<0,0,0><0.6,0.4,0.4> texture{col_gold} translate<0,0.0,0.0>}
cylinder{<-0.1,0,0><0.8,0,0>0.2 texture{col_gold} translate<0,0.0,0.0>}
rotate<0,-90,0> translate<0.5,3.31,-0.3>}
difference {
cylinder{<0,0,0><0.6,0,0>0.8 texture{col_gold} translate<0,0,0> }
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,0,-0.1>}
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,-1.8,0.4>}
rotate<0,-90,0> translate<0.5,3.31,-0.3>}
//Kunststoff
difference {
box{<0,-2,-1.27><2,1.27,1.27> pigment{Gray30} translate<0,0,0>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,-1.76>}
translate<4.04,3.81,0>}
rotate<0,-90,0>
}
#end

/********************************************************************************************************************************************
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmakro Stiftleisten Winkel (Macro aus connector.inc abgewandelt)
//a = Reihen
//b = Pins
********************************************************************************************************************************************/
#macro CON_PHW_BASE(a,b)
union {
#if(a=1)
#local i=0;
        #while(i<b)
                object{PHW() translate<i*2.54,0,0>}
                #local i=i+1;
        #end
        translate<-(b-1)*1.27,0,0>
#else
        #local i=0;
        #while(i<b)
                object{PHW() translate<i*2.54,0,1.27>}
                object{PHW2() translate<i*2.54,0,-1.27>}
                #local i=i+1;
        #end
        translate<-(b-1)*1.27,0,0>
#end
}
#end


#macro CON_PHW_1X1()  CON_PHW_BASE(1,1)  #end
#macro CON_PHW_1X2()  CON_PHW_BASE(1,2)  #end
#macro CON_PHW_1X3()  CON_PHW_BASE(1,3)  #end
#macro CON_PHW_1X4()  CON_PHW_BASE(1,4)  #end
#macro CON_PHW_1X5()  CON_PHW_BASE(1,5)  #end
#macro CON_PHW_1X6()  CON_PHW_BASE(1,6)  #end
#macro CON_PHW_1X7()  CON_PHW_BASE(1,7)  #end
#macro CON_PHW_1X8()  CON_PHW_BASE(1,8)  #end
#macro CON_PHW_1X9()  CON_PHW_BASE(1,9)  #end
#macro CON_PHW_1X10() CON_PHW_BASE(1,10) #end
#macro CON_PHW_1X11() CON_PHW_BASE(1,11) #end
#macro CON_PHW_1X12() CON_PHW_BASE(1,12) #end
#macro CON_PHW_1X13() CON_PHW_BASE(1,13) #end
#macro CON_PHW_1X14() CON_PHW_BASE(1,14) #end
#macro CON_PHW_1X15() CON_PHW_BASE(1,15) #end
#macro CON_PHW_1X16() CON_PHW_BASE(1,16) #end
#macro CON_PHW_1X17() CON_PHW_BASE(1,17) #end
#macro CON_PHW_1X18() CON_PHW_BASE(1,18) #end
#macro CON_PHW_1X19() CON_PHW_BASE(1,19) #end
#macro CON_PHW_1X20() CON_PHW_BASE(1,20) #end
#macro CON_PHW_1X21() CON_PHW_BASE(1,21) #end
#macro CON_PHW_1X22() CON_PHW_BASE(1,22) #end
#macro CON_PHW_1X23() CON_PHW_BASE(1,23) #end
#macro CON_PHW_1X24() CON_PHW_BASE(1,24) #end
#macro CON_PHW_1X25() CON_PHW_BASE(1,25) #end
#macro CON_PHW_1X26() CON_PHW_BASE(1,26) #end
#macro CON_PHW_1X27() CON_PHW_BASE(1,27) #end
#macro CON_PHW_1X28() CON_PHW_BASE(1,28) #end
#macro CON_PHW_1X29() CON_PHW_BASE(1,29) #end
#macro CON_PHW_1X30() CON_PHW_BASE(1,30) #end
#macro CON_PHW_2X2()  CON_PHW_BASE(2,2)  #end
#macro CON_PHW_2X3()  CON_PHW_BASE(2,3)  #end
#macro CON_PHW_2X4()  CON_PHW_BASE(2,4)  #end
#macro CON_PHW_2X5()  CON_PHW_BASE(2,5)  #end
#macro CON_PHW_2X6()  CON_PHW_BASE(2,6)  #end
#macro CON_PHW_2X7()  CON_PHW_BASE(2,7)  #end
#macro CON_PHW_2X8()  CON_PHW_BASE(2,8)  #end
#macro CON_PHW_2X9()  CON_PHW_BASE(2,9)  #end
#macro CON_PHW_2X10() CON_PHW_BASE(2,10) #end
#macro CON_PHW_2X11() CON_PHW_BASE(2,11) #end
#macro CON_PHW_2X12() CON_PHW_BASE(2,12) #end
#macro CON_PHW_2X13() CON_PHW_BASE(2,13) #end
#macro CON_PHW_2X14() CON_PHW_BASE(2,14) #end
#macro CON_PHW_2X15() CON_PHW_BASE(2,15) #end
#macro CON_PHW_2X16() CON_PHW_BASE(2,16) #end
#macro CON_PHW_2X17() CON_PHW_BASE(2,17) #end
#macro CON_PHW_2X18() CON_PHW_BASE(2,18) #end
#macro CON_PHW_2X19() CON_PHW_BASE(2,19) #end
#macro CON_PHW_2X20() CON_PHW_BASE(2,20) #end
#macro CON_PHW_2X21() CON_PHW_BASE(2,21) #end
#macro CON_PHW_2X22() CON_PHW_BASE(2,22) #end
#macro CON_PHW_2X23() CON_PHW_BASE(2,23) #end
#macro CON_PHW_2X24() CON_PHW_BASE(2,24) #end
#macro CON_PHW_2X25() CON_PHW_BASE(2,25) #end
#macro CON_PHW_2X26() CON_PHW_BASE(2,26) #end
#macro CON_PHW_2X27() CON_PHW_BASE(2,27) #end
#macro CON_PHW_2X28() CON_PHW_BASE(2,28) #end
#macro CON_PHW_2X29() CON_PHW_BASE(2,29) #end
#macro CON_PHW_2X30() CON_PHW_BASE(2,30) #end
