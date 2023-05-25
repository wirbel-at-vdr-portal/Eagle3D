
/********************************************************************************************************************************************
//Grundmakro fuer Buchsenleisten abgewinkelt ,     con-lsta.lib,    Joerg Bredendiek <sprut(replace with at)sprut.de>   
// 2.54mm  Pinabstand
//
// pin = pins pro Reihe
// row = Reihen (1 oder 2)
********************************************************************************************************************************************/
#macro CON_BLW_BASE(row,pin)
//Pin fuer 1- & 2-reihige Buchsenleiste abgewinkelt obere Reihe  ,     con-lsta.lib,    Joerg Bredendiek <sprut(replace with at)sprut.de>  
// 
// a=0 untere Reihe
// a=1 obere  Reihe
#macro CON_BLW_PIN(a)
#local ii = a*2.54;
union {
union {
   //PIN Loetseite 4mm, etwas angespitzt
   difference {
      box{<0,0,0><0.4,4.1+ii,0.4> texture{col_silver} translate<-0.2,0,-0.2>}
      box{<0,0,-0.5><0.5,0.5,0.5> texture{col_silver} rotate<0,0,-30> translate<0.1,0,0>}
      box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_silver} rotate<0,0,30> translate<-0.1,0,0>}
      box{<-0.5,0,0><0.5,0.5,0.5> texture{col_silver} rotate<30,0,0> translate<0,0,0.1>}
      box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_silver} rotate<-30,0,0> translate<0,0,-0.1>}
      translate<0,-3.22,0>
   }
   //PIN vom Bogen zum Plastik
   #if(ii>0)
      box{<0,0,0><0.4,5,0.4> texture{col_silver} translate<-0.2,0,-0.2> rotate<0,0,-90> translate<0.4,3.81,0> }
   #end

   //PIN Bogen 
   //innenkurve
   difference {
      box{<0,0,0><0.4,0.4,0.4> texture{col_silver} translate<0,0.0,0.0>}
      cylinder{<-0.1,0,0><0.8,0,0>0.2 texture{col_silver} translate<0,0.0,0.0>}
      rotate<0,-90,0> translate<0.5,0.77+ii,-0.2>
      translate<-0.1,0.1,0> 
   }
   //aussenkurve
   difference {
      cylinder{<0,0,0><0.4,0,0>0.6 texture{col_silver} translate<0,0,0> }
      box{<0,0,0><2,2.2,-2> texture{col_silver} translate<-0.1,0,-0.1>}
      box{<0,0,0><2,2.2,-2> texture{col_silver} translate<-0.1,-1.8,0.4>}
      rotate<0,-90,0> translate<0.5,0.77+ii,-0.2>
      translate<-0.1,0.1,0> 
   } 
   rotate<0,-90,0>
}
union {
   //schwarzes plastik mit loch 8mm lang   
   // wird vertikal gebaut                        
   difference {
      difference {
         box{<-1.27,0,-1.27><1.27,8,1.27>}
         box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate<-1.95,0,-1.95> }
         box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate< 1.95,0,-1.95> }
         box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate<-1.95,0, 1.95> }
         box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate< 1.95,0, 1.95> }
      }
      cylinder{<0,1,0><0,8.1,0>1.0}
   }
   //rundes buchsenloch versilbert
   difference {
      cylinder{<0,7.5,0><0,8.03,0>1.0}
      cylinder{<0,6.9,0><0,8.2,0>0.9}  
      texture{col_silver}
   }
   //vergoldeter Kontakt im siblernen Buchsenloch
   difference {
      cylinder{<0,0.5,0><0,7.55,0>0.9}
      cylinder{<0,0.4,0><0,7.6,0>0.7}  
      texture{col_gold}
   }
   pigment{Gray30}
   rotate<90,0,0>    //in die horizontale drehen
   translate<0,1.27,0>  //auf die platine legen

   #if(ii>0)
      translate<0,2.54,2.54>  //in 2. ebene und um 1 Raster noch von schieben
   #end
}
}
#end

union {
   #local i=0;
   #while(i<pin)
      object{CON_BLW_PIN(0) translate<i*2.54,0,0>}
      #local i=i+1;
   #end
   #if(row=2)
      #local i=0;
      #while(i<pin)
         object{CON_BLW_PIN(1) translate<i*2.54,0,-2.54>}
         #local i=i+1;
      #end
      translate<0,0,1.27>
   #end
   translate<pin*-1.27+1.27,0,0>}
#end



#macro CON_BLW_1X2()  CON_BLW_BASE(1, 2) #end
#macro CON_BLW_1X5()  CON_BLW_BASE(1, 5) #end
#macro CON_BLW_1X6()  CON_BLW_BASE(1, 6) #end
#macro CON_BLW_1X7()  CON_BLW_BASE(1, 7) #end
#macro CON_BLW_1X8()  CON_BLW_BASE(1, 8) #end
#macro CON_BLW_1X9()  CON_BLW_BASE(1, 9) #end
#macro CON_BLW_1X10() CON_BLW_BASE(1,10) #end
#macro CON_BLW_1X12() CON_BLW_BASE(1,12) #end
#macro CON_BLW_1X13() CON_BLW_BASE(1,13) #end
#macro CON_BLW_1X15() CON_BLW_BASE(1,15) #end
#macro CON_BLW_1X17() CON_BLW_BASE(1,17) #end
#macro CON_BLW_1X18() CON_BLW_BASE(1,18) #end
#macro CON_BLW_1X20() CON_BLW_BASE(1,20) #end
#macro CON_BLW_2X5()  CON_BLW_BASE(2, 5) #end
#macro CON_BLW_2X6()  CON_BLW_BASE(2, 6) #end
#macro CON_BLW_2X7()  CON_BLW_BASE(2, 7) #end
#macro CON_BLW_2X8()  CON_BLW_BASE(2, 8) #end
#macro CON_BLW_2X9()  CON_BLW_BASE(2, 9) #end
#macro CON_BLW_2X10() CON_BLW_BASE(2,10) #end
#macro CON_BLW_2X12() CON_BLW_BASE(2,12) #end
#macro CON_BLW_2X13() CON_BLW_BASE(2,13) #end
#macro CON_BLW_2X15() CON_BLW_BASE(2,15) #end
#macro CON_BLW_2X17() CON_BLW_BASE(2,17) #end
#macro CON_BLW_2X18() CON_BLW_BASE(2,18) #end
#macro CON_BLW_2X20() CON_BLW_BASE(2,20) #end
