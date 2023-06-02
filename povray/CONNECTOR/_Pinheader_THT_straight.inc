

// ////////////////////////////////////////////////////////////
// Pin fuer Stiftleisten
// //////////
#macro PH()
union {
object{PIN_STRAIGHT(0.5,9,3) texture {col_gold} }
difference {
box{<0,0,0><2.54,2,2.54> pigment{Gray30} translate<-1.27,0,-1.27>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,45,0> translate<0.635,0,1.27>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,-45,0> translate<-1.27,0,0.635>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,45,0> translate<0.635,0,-1.27>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,-135,0> translate<-0.635,0,-1.27>}
box{<-0.635,-0.1,-1.3><0.635,0.5,1.3> pigment{Gray30} rotate<0,0,0> translate<0,0,0>}
box{<-1.3,-0.1,-0.635><1.3,0.5,0.635> pigment{Gray30} rotate<0,0,0> translate<0,0,0>}
}}
#end

/********************************************************************************************************************************************
//Grundmakro Stiftleisten
//a = Rows
//b = Pins
//j = (0=no Jumper, 1=open, 2=closed)
//pitch = The space between two pins
********************************************************************************************************************************************/
#macro CON_PH_BASE(a,b,j,pitch)
#if((a>1)|(b>1))
union {
#else
object{
#end
#if(a=1)
#local i=0;
        #while(i<b)
                object{PH() translate<i*2.54,0,0>}
                #local i=i+1;
        #end
        translate<-(b-1)*(2.54/2),0,0>
#else
        #local i=0;
        #while(i<b)
                object{PH() translate<i*2.54,0,-(2.54/2)>}
                object{PH() translate<i*2.54,0,(2.54/2)>}

                #if(j=1)
                object{CON_JUMPER() rotate<0,90,0> translate<i*2.54,0,(2.54)>}
                #end

                #if(j=2)
                object{CON_JUMPER() rotate<0,90,0> translate<i*2.54,0,0>}
                #end

                #local i=i+1;
        #end
        translate<-(b-1)*(2.54/2),0,0>
#end
scale (pitch/2.54)
}
#end


//one row pinheader (2mm)  
#macro CON_PH_2MM_1X1()  CON_PH_BASE(1, 1,0,2.00) #end
#macro CON_PH_2MM_1X2()  CON_PH_BASE(1, 2,0,2.00) #end
#macro CON_PH_2MM_1X3()  CON_PH_BASE(1, 3,0,2.00) #end
#macro CON_PH_2MM_1X4()  CON_PH_BASE(1, 4,0,2.00) #end
#macro CON_PH_2MM_1X5()  CON_PH_BASE(1, 5,0,2.00) #end
#macro CON_PH_2MM_1X6()  CON_PH_BASE(1, 6,0,2.00) #end
#macro CON_PH_2MM_1X7()  CON_PH_BASE(1, 7,0,2.00) #end
#macro CON_PH_2MM_1X8()  CON_PH_BASE(1, 8,0,2.00) #end
#macro CON_PH_2MM_1X9()  CON_PH_BASE(1, 9,0,2.00) #end
#macro CON_PH_2MM_1X10() CON_PH_BASE(1,10,0,2.00) #end
#macro CON_PH_2MM_1X11() CON_PH_BASE(1,11,0,2.00) #end
#macro CON_PH_2MM_1X12() CON_PH_BASE(1,12,0,2.00) #end
#macro CON_PH_2MM_1X13() CON_PH_BASE(1,13,0,2.00) #end
#macro CON_PH_2MM_1X14() CON_PH_BASE(1,14,0,2.00) #end
#macro CON_PH_2MM_1X15() CON_PH_BASE(1,15,0,2.00) #end
#macro CON_PH_2MM_1X16() CON_PH_BASE(1,16,0,2.00) #end
#macro CON_PH_2MM_1X17() CON_PH_BASE(1,17,0,2.00) #end
#macro CON_PH_2MM_1X18() CON_PH_BASE(1,18,0,2.00) #end
#macro CON_PH_2MM_1X19() CON_PH_BASE(1,19,0,2.00) #end
#macro CON_PH_2MM_1X20() CON_PH_BASE(1,20,0,2.00) #end
#macro CON_PH_2MM_1X21() CON_PH_BASE(1,21,0,2.00) #end
#macro CON_PH_2MM_1X22() CON_PH_BASE(1,22,0,2.00) #end
#macro CON_PH_2MM_1X23() CON_PH_BASE(1,23,0,2.00) #end
#macro CON_PH_2MM_1X24() CON_PH_BASE(1,24,0,2.00) #end
#macro CON_PH_2MM_1X25() CON_PH_BASE(1,25,0,2.00) #end
#macro CON_PH_2MM_1X26() CON_PH_BASE(1,26,0,2.00) #end
#macro CON_PH_2MM_1X27() CON_PH_BASE(1,27,0,2.00) #end
#macro CON_PH_2MM_1X28() CON_PH_BASE(1,28,0,2.00) #end
#macro CON_PH_2MM_1X29() CON_PH_BASE(1,29,0,2.00) #end
#macro CON_PH_2MM_1X30() CON_PH_BASE(1,30,0,2.00) #end
#macro CON_PH_2MM_2X2()  CON_PH_BASE(2, 2,0,2.00) #end
#macro CON_PH_2MM_2X3()  CON_PH_BASE(2, 3,0,2.00) #end
#macro CON_PH_2MM_2X4()  CON_PH_BASE(2, 4,0,2.00) #end
#macro CON_PH_2MM_2X5()  CON_PH_BASE(2, 5,0,2.00) #end
#macro CON_PH_2MM_2X6()  CON_PH_BASE(2, 6,0,2.00) #end
#macro CON_PH_2MM_2X7()  CON_PH_BASE(2, 7,0,2.00) #end
#macro CON_PH_2MM_2X8()  CON_PH_BASE(2, 8,0,2.00) #end
#macro CON_PH_2MM_2X9()  CON_PH_BASE(2, 9,0,2.00) #end
#macro CON_PH_2MM_2X10() CON_PH_BASE(2,10,0,2.00) #end
#macro CON_PH_2MM_2X11() CON_PH_BASE(2,11,0,2.00) #end
#macro CON_PH_2MM_2X12() CON_PH_BASE(2,12,0,2.00) #end
#macro CON_PH_2MM_2X13() CON_PH_BASE(2,13,0,2.00) #end
#macro CON_PH_2MM_2X14() CON_PH_BASE(2,14,0,2.00) #end
#macro CON_PH_2MM_2X15() CON_PH_BASE(2,15,0,2.00) #end
#macro CON_PH_2MM_2X16() CON_PH_BASE(2,16,0,2.00) #end
#macro CON_PH_2MM_2X17() CON_PH_BASE(2,17,0,2.00) #end
#macro CON_PH_2MM_2X18() CON_PH_BASE(2,18,0,2.00) #end
#macro CON_PH_2MM_2X19() CON_PH_BASE(2,19,0,2.00) #end
#macro CON_PH_2MM_2X20() CON_PH_BASE(2,20,0,2.00) #end
#macro CON_PH_2MM_2X21() CON_PH_BASE(2,21,0,2.00) #end
#macro CON_PH_2MM_2X22() CON_PH_BASE(2,22,0,2.00) #end
#macro CON_PH_2MM_2X23() CON_PH_BASE(2,23,0,2.00) #end
#macro CON_PH_2MM_2X24() CON_PH_BASE(2,24,0,2.00) #end
#macro CON_PH_2MM_2X25() CON_PH_BASE(2,25,0,2.00) #end
#macro CON_PH_2MM_2X26() CON_PH_BASE(2,26,0,2.00) #end
#macro CON_PH_2MM_2X27() CON_PH_BASE(2,27,0,2.00) #end
#macro CON_PH_2MM_2X28() CON_PH_BASE(2,28,0,2.00) #end
#macro CON_PH_2MM_2X29() CON_PH_BASE(2,29,0,2.00) #end
#macro CON_PH_2MM_2X30() CON_PH_BASE(2,30,0,2.00) #end

//two row pinheader (2mm) with jumper
#macro CON_PH_2MM_2X1J(j)  CON_PH_BASE(2, 1,j,2.00) #end
#macro CON_PH_2MM_2X2J(j)  CON_PH_BASE(2, 2,j,2.00) #end
#macro CON_PH_2MM_2X3J(j)  CON_PH_BASE(2, 3,j,2.00) #end
#macro CON_PH_2MM_2X4J(j)  CON_PH_BASE(2, 4,j,2.00) #end
#macro CON_PH_2MM_2X5J(j)  CON_PH_BASE(2, 5,j,2.00) #end
#macro CON_PH_2MM_2X6J(j)  CON_PH_BASE(2, 6,j,2.00) #end
#macro CON_PH_2MM_2X7J(j)  CON_PH_BASE(2, 7,j,2.00) #end
#macro CON_PH_2MM_2X8J(j)  CON_PH_BASE(2, 8,j,2.00) #end
#macro CON_PH_2MM_2X9J(j)  CON_PH_BASE(2, 9,j,2.00) #end
#macro CON_PH_2MM_2X10J(j) CON_PH_BASE(2,10,j,2.00) #end
