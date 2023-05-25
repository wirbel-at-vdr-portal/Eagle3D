





// ////////////////////////////////////////////////////////////
// Original file: ./1_PBL.inc.src
// Pin fuer Buchsenleiste
// //////////
#macro PBL()
union {

difference {
   box{<0,0,0><0.5,3,0.3> translate<-0.25,-3,-0.15>}
   box{<0,0,-0.5><0.5,0.5,0.5> rotate<0,0,-30> translate<0.1,-3,0>}
   box{<0,0,-0.5><-0.5,0.5,0.5> rotate<0,0,30> translate<-0.1,-3,0>}
   box{<-0.5,0,0><0.5,0.5,0.5> rotate<30,0,0> translate<0,-3,0.05>}
   box{<-0.5,0,0><0.5,0.5,-0.5> rotate<-30,0,0> translate<0,-3,-0.05>}
   texture{col_gold}
}
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

difference {
   cylinder{<0,7.5,0><0,8.03,0>1.0}
   cylinder{<0,6.9,0><0,8.2,0>0.9}
   texture{col_silver}
}

difference {
   cylinder{<0,0.5,0><0,7.55,0>0.9}
   cylinder{<0,0.4,0><0,7.6,0>0.7}
   texture{col_gold}
}

pigment{Gray30}
finish {ambient (0.1 * global_ambient_mul)}
}
#end



/********************************************************************************************************************************************
//Grundmakro fuer Buchsenleisten
********************************************************************************************************************************************/
#macro CON_BL_BASE(pin,row)
union {
#local i=0;
#while(i<pin)
object{PBL() translate<i*2.54,0,0>}
#local i=i+1;
#end
#if(row=2)
#local i=0;
#while(i<pin)
object{PBL() translate<i*2.54,0,-2.54>}
#local i=i+1;
#end
translate<0,0,1.27>
#end
translate<pin*-1.27+1.27,0,0>}
#end

#macro CON_BL_1X5()  CON_BL_BASE(5,1)  #end
#macro CON_BL_1X6()  CON_BL_BASE(6,1)  #end
#macro CON_BL_1X7()  CON_BL_BASE(7,1)  #end
#macro CON_BL_1X8()  CON_BL_BASE(8,1)  #end
#macro CON_BL_1X9()  CON_BL_BASE(9,1)  #end
#macro CON_BL_1X10() CON_BL_BASE(10,1) #end
#macro CON_BL_1X12() CON_BL_BASE(12,1) #end
#macro CON_BL_1X13() CON_BL_BASE(13,1) #end
#macro CON_BL_1X15() CON_BL_BASE(15,1) #end
#macro CON_BL_1X17() CON_BL_BASE(17,1) #end
#macro CON_BL_1X18() CON_BL_BASE(18,1) #end
#macro CON_BL_1X20() CON_BL_BASE(20,1) #end
#macro CON_BL_2X5()  CON_BL_BASE(5,2)  #end
#macro CON_BL_2X6()  CON_BL_BASE(6,2)  #end
#macro CON_BL_2X7()  CON_BL_BASE(7,2)  #end
#macro CON_BL_2X8()  CON_BL_BASE(8,2)  #end
#macro CON_BL_2X9()  CON_BL_BASE(9,2)  #end
#macro CON_BL_2X10() CON_BL_BASE(10,2) #end
#macro CON_BL_2X12() CON_BL_BASE(12,2) #end
#macro CON_BL_2X13() CON_BL_BASE(13,2) #end
#macro CON_BL_2X15() CON_BL_BASE(15,2) #end
#macro CON_BL_2X17() CON_BL_BASE(17,2) #end
#macro CON_BL_2X18() CON_BL_BASE(18,2) #end
#macro CON_BL_2X20() CON_BL_BASE(20,2) #end
