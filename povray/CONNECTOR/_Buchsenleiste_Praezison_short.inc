// ////////////////////////////////////////////////////////////
// Pin fuer Buchsenleiste (flache Bauform), hinzugefuegt von B.Redemann www.b-redemann.de
// //////////
#macro CON_PBL_F()
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
      box{<-1.27,0,-1.27><1.27,3,1.27>}
      box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate<-1.95,0,-1.95> }
      box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate< 1.95,0,-1.95> }
      box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate<-1.95,0, 1.95> }
      box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate< 1.95,0, 1.95> }
   }
   cylinder{<0,1,0><0,3.1,0>1.0}
}

difference {
   cylinder{<0,2.5,0><0,3.03,0>1.0}
   cylinder{<0,1.9,0><0,3.2,0>0.9}
   texture{col_silver}
}

difference {
   cylinder{<0,0.5,0><0,2.55,0>0.9}
   cylinder{<0,0.4,0><0,2.6,0>0.7}
   texture{col_gold}
}
pigment{Gray30}}
#end

#macro CON_BL_F_BASE(pin,row)

union {

#local i=0;
#while(i<pin)
object{ CON_PBL_F() translate<i*2.54,0,0>}
#local i=i+1;
#end
#if(row=2)
#local i=0;
#while(i<pin)
object{CON_PBL_F() translate<i*2.54,0,-2.54>}
#local i=i+1;
#end
translate<0,0,1.27>
#end
translate<pin*-1.27+1.27,0,0>}
#end

#macro CON_BL_F_1X5()  CON_BL_F_BASE(5,1)  #end
#macro CON_BL_F_1X6()  CON_BL_F_BASE(6,1)  #end
#macro CON_BL_F_1X7()  CON_BL_F_BASE(7,1)  #end
#macro CON_BL_F_1X8()  CON_BL_F_BASE(8,1)  #end
#macro CON_BL_F_1X9()  CON_BL_F_BASE(9,1)  #end
#macro CON_BL_F_1X10() CON_BL_F_BASE(10,1) #end
#macro CON_BL_F_1X12() CON_BL_F_BASE(12,1) #end
#macro CON_BL_F_1X13() CON_BL_F_BASE(13,1) #end
#macro CON_BL_F_1X15() CON_BL_F_BASE(15,1) #end
#macro CON_BL_F_1X17() CON_BL_F_BASE(17,1) #end
#macro CON_BL_F_1X18() CON_BL_F_BASE(18,1) #end
#macro CON_BL_F_1X20() CON_BL_F_BASE(20,1) #end
#macro CON_BL_F_2X5()  CON_BL_F_BASE(5,2)  #end
#macro CON_BL_F_2X6()  CON_BL_F_BASE(6,2)  #end
#macro CON_BL_F_2X7()  CON_BL_F_BASE(7,2)  #end
#macro CON_BL_F_2X8()  CON_BL_F_BASE(8,2)  #end
#macro CON_BL_F_2X9()  CON_BL_F_BASE(9,2)  #end
#macro CON_BL_F_2X10() CON_BL_F_BASE(10,2) #end
#macro CON_BL_F_2X12() CON_BL_F_BASE(12,2) #end
#macro CON_BL_F_2X13() CON_BL_F_BASE(13,2) #end
#macro CON_BL_F_2X15() CON_BL_F_BASE(15,2) #end
#macro CON_BL_F_2X17() CON_BL_F_BASE(17,2) #end
#macro CON_BL_F_2X18() CON_BL_F_BASE(18,2) #end
#macro CON_BL_F_2X20() CON_BL_F_BASE(20,2) #end

/********************************************************************************************************************************************
//Macro fuer Praezisions Buchsenleisten
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro CON_BL_PRECISION_BASE(row,pin)
//Single Pin
#macro CON_BL_PRECISION_PIN()
union {
  difference {
             box{<0,0,0><2.54,2,2.54> pigment{Gray10} translate<-1.27,0,-1.27>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,45,0> translate<0.635,0,1.27>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,-45,0> translate<-1.27,0,0.635>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,45,0> translate<0.635,0,-1.27>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,-135,0> translate<-0.635,0,-1.27>} 
             cylinder{<0,-0.5,0> <0,2.5,0> 0.7 pigment{Gray10} finish {ambient (0.1 * global_ambient_mul)}}
  translate<0,5.10,0>
  }
  
 difference {
    union {
        cylinder{<0,0,0><0,2.95,0>0.25}
        sphere{<0,0,0>0.25}
        cone{<0,2.95,0>0.25<0,3.45,0>0.6}
        cylinder{<0,3.45,0><0,7.15,0>0.6}
        cylinder{<0,6.3,0><0,7.15,0>0.85}
        }
    cylinder{<0,4,0><0,7.16,0>0.5}
    Round_Cylinder (
       <0,6.5,0> <0,7.5,0> 0.70 0.3 0
       )
    texture { T_Silver_5E finish { reflection 0.5 ambient (0.1 * global_ambient_mul) } }
  }
  translate<0,-2.95,0>
 } 
#end

union {
   #local i=0;
   #while(i<pin)
      object{CON_BL_PRECISION_PIN() translate<i*2.54,0,0>}
      #local i=i+1;
   #end
   
   #if(row=2)
      #local i=0;
      #while(i<pin)
         object{CON_BL_PRECISION_PIN() translate<i*2.54,0,-2.54>}
      #local i=i+1;
      #end
      translate<0,0,1.27>
   #end
   translate<pin*-1.27+1.27,0,0>}
#end

#macro CON_BL_PRECISION_1X1()  CON_BL_PRECISION_BASE(1, 1) #end
#macro CON_BL_PRECISION_1X2()  CON_BL_PRECISION_BASE(1, 2) #end
#macro CON_BL_PRECISION_1X3()  CON_BL_PRECISION_BASE(1, 3) #end
#macro CON_BL_PRECISION_1X4()  CON_BL_PRECISION_BASE(1, 4) #end
#macro CON_BL_PRECISION_1X5()  CON_BL_PRECISION_BASE(1, 5) #end
#macro CON_BL_PRECISION_1X6()  CON_BL_PRECISION_BASE(1, 6) #end
#macro CON_BL_PRECISION_1X7()  CON_BL_PRECISION_BASE(1, 7) #end
#macro CON_BL_PRECISION_1X8()  CON_BL_PRECISION_BASE(1, 8) #end
#macro CON_BL_PRECISION_1X9()  CON_BL_PRECISION_BASE(1, 9) #end
#macro CON_BL_PRECISION_1X10() CON_BL_PRECISION_BASE(1,10) #end
#macro CON_BL_PRECISION_1X11() CON_BL_PRECISION_BASE(1,11) #end
#macro CON_BL_PRECISION_1X12() CON_BL_PRECISION_BASE(1,12) #end
#macro CON_BL_PRECISION_1X13() CON_BL_PRECISION_BASE(1,13) #end
#macro CON_BL_PRECISION_2X2()  CON_BL_PRECISION_BASE(2, 2) #end
#macro CON_BL_PRECISION_2X3()  CON_BL_PRECISION_BASE(2, 3) #end
#macro CON_BL_PRECISION_2X4()  CON_BL_PRECISION_BASE(2, 4) #end
#macro CON_BL_PRECISION_2X5()  CON_BL_PRECISION_BASE(2, 5) #end
#macro CON_BL_PRECISION_2X6()  CON_BL_PRECISION_BASE(2, 6) #end
#macro CON_BL_PRECISION_2X7()  CON_BL_PRECISION_BASE(2, 7) #end
#macro CON_BL_PRECISION_2X8()  CON_BL_PRECISION_BASE(2, 8) #end
#macro CON_BL_PRECISION_2X9()  CON_BL_PRECISION_BASE(2, 9) #end
#macro CON_BL_PRECISION_2X10() CON_BL_PRECISION_BASE(2,10) #end
#macro CON_BL_PRECISION_2X11() CON_BL_PRECISION_BASE(2,11) #end
#macro CON_BL_PRECISION_2X12() CON_BL_PRECISION_BASE(2,12) #end
#macro CON_BL_PRECISION_2X13() CON_BL_PRECISION_BASE(2,13) #end


