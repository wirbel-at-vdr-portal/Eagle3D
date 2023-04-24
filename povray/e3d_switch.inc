/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/




/********************************************************************************************************************************************
//Nigel Eke <nigel@eke.name>
//Dipswitch
********************************************************************************************************************************************/
#macro SWITCH_DIP_BASE(nrSwitches)
  #local pin   = cylinder { <0,-3,0> <0,0,0> .25 texture {T_Gold_5E} }
  #local well  = box { <0,3.7,2> <1,3.91,6> pigment { MediumWood } }
  #local housing = difference { box { <0,0,0> <2*nrSwitches+1,3.9,7.8> }
                                box { <0,3.7,2> <.3,3.91,6> }
                                pigment { color red 0.7 green 0.15 blue 0.15 } } //SteelBlue
  #local offSwitch = union { box { <0.1,3.71,2.01> <.9,3.71,5.9> }
                             box { <0.1,3.71,2.01> <.9,4.5,3> }
                             pigment { NewTan }}
  #local onSwitch = union { box { <0.1,3.71,2.01> <.9,3.71,5.9> }
                            box { <0.1,3.71,5> <.9,4.5,5.9> }
                            pigment { NewTan }}
  union {
    difference {
      object { housing }

      #local wellNr = 0;
      #while (wellNr < nrSwitches)
        object { well translate<wellNr*2+1,0,0> }
        #local wellNr = wellNr + 1;
      #end
    }
    #local switchNr = 0;
    #while (switchNr < nrSwitches)
      #local xShift = (switchNr*2)+1;
      object { pin translate<xShift+0.5,0,1> }
      object { pin translate<xShift+0.5,0,7> }
      #local onOff = SRand(1);
      #if (onOff < 0)
        object { offSwitch translate<xShift,0,0> }
      #else
        object { onSwitch translate<xShift,0,0> }
      #end
      text {
        ttf besch_font str(switchNr+1,2,0) .01, 0
        pigment { NewTan }
        scale 1.5
        rotate<90,0,0>
        translate<xShift-.2,3.91,.5>
      }
      #local switchNr = switchNr + 1;
    #end
    text {
      ttf besch_font "ON" .01, 0
      pigment { NewTan }
      scale 1.5
      rotate<90,0,0>
      translate<0.5,3.91,6.3>}
    translate<-nrSwitches-.5,0,-3.9>
    scale 2.54/2}
#end

#macro SWITCH_DIP01()
SWITCH_DIP_BASE(1)
#end
#macro SWITCH_DIP02()
SWITCH_DIP_BASE(2)
#end
#macro SWITCH_DIP03()
SWITCH_DIP_BASE(3)
#end
#macro SWITCH_DIP04()
SWITCH_DIP_BASE(4)
#end
#macro SWITCH_DIP05()
SWITCH_DIP_BASE(5)
#end
#macro SWITCH_DIP06()
SWITCH_DIP_BASE(6)
#end
#macro SWITCH_DIP07()
SWITCH_DIP_BASE(7)
#end
#macro SWITCH_DIP08()
SWITCH_DIP_BASE(8)
#end
#macro SWITCH_DIP09()
SWITCH_DIP_BASE(9)
#end
#macro SWITCH_DIP10()
SWITCH_DIP_BASE(10)
#end
#macro SWITCH_DIP12()
SWITCH_DIP_BASE(12)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>  
// based on Nigel Eke <nigel@eke.name> ans some Pin-macros
//Dipswitch  small and smd
// pintyp=0  smd nach außen gewinkelt
// pintyp=1  smd nach innen gewinkelt
// pintyp=2  normal
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_BASE(nrSwitches, pintyp, abmasse)
/********************************************************************************************************************************************
// Pin Typ 0,  smd nach außen gewinkelt
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN0(H,B,T,S)
//H = Höhe des Pins
//B = Breite des Pins
//T = Tiefe des Pins
//S = Materialstärke des Pins
union{
   box{<0,H,T/2><B/4,H-S,-T/2>}
   difference{
      cylinder{<B/4,H-S,-T/2><B/4,H-S,T/2>S}
      box{<-1,H-S,-T/2-0.01><B/2,H-S-3,T/2+0.01>}}
   box{<B/4,H-S,-T/2><B/4+S,S,T/2>}
   difference{
      cylinder{<B/4+S,S,-T/2><B/4+S,S,T/2>S}
      box{<0,S,-T/2-0.01><B,S+3,T/2+0.01>}}
   box{<B/4+S,0,-T/2><B,S,T/2>}
   difference{
      box{<B/4+S,S,-T/2><B/4+S+S/2,1.5*S,T/2>}
      cylinder{<B/4+S+S/2,S+S/2,T/2+0.01><B/4+S+S/2,S+S/2,-T/2-0.01>,S/2}}
   //box{<0,0,-T/2><B,H,T/2> pigment{White filter 0.9}}
   rotate<0,90,0>
   texture{col_silver}
}
#end
/********************************************************************************************************************************************
// Pin Typ 1,  smd nach innen gewinkelt
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN1()

union{
   intersection{
      difference{
         box{<0,0,0><1.8,0.9,0.45>}
         cylinder{<0.9,0.9,-0.1><0.9,0.9,0.5>0.7}}
      cylinder{<0.9,0.9,-0.1><0.9,0.9,0.5>0.9}}
   box{<1.6,0.8,0><1.8,1.2,0.45>}
   difference{
      box{<1.6,1.2,-0.125><1.8,2.5,0.45+0.125>}
      box{<-0.1,0,0><0.3,0.5,-0.5> rotate<-20,0,0> translate<1.55,1.2,0>}
      box{<-0.1,0,0><0.3,0.5,0.5> rotate<20,0,0> translate<1.55,1.2,0.45>}}
   difference{
      cylinder{<1.5,2.5,-0.125><1.5,2.5,0.45+0.125>0.3}
      box{<1.6,2.9,-1><1,2,1>}}
   difference{
      box{<1.6,2.5,-0.125><1.4,2.8,0.45+0.125>}
      cylinder{<1.45,2.45,-1><1.45,2.45,1>0.15}}
   texture{col_silver}
   translate<-1.4,0,0>
   rotate<0,90,0>
   translate<-0.225,0,0>
}
#end
/********************************************************************************************************************************************
// Pin Typ 2, normal
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN2()
union{
   //unterstes Ende durch das Loch der Platine
   difference{
      box{<0,0,0><0.455,3.4,0.3>}
      box{<0,0,0><0.5,0.5,0.5> rotate<0,0,-20> translate<0.305,0,-0.1>}
      box{<0,0,0><-0.5,0.5,0.5> rotate<0,0,20> translate<0.15,0,-0.1>}
   }
   box{<0,0,0><1.43,0.3,0.33> translate<-0.4875,5.3,0.5>}
   difference{
      box{<0,0,0><1.43,0.25,0.25> translate<-0.4875,5.05,0.3>}
      cylinder{<0,0,0><2,0,0>0.25 translate<-0.6,5.05,0.55>}
   }
   // breiter senkrechter Streifen mit Verjuengung
   difference{
      box{<0,0,0><1.43,1.7,0.3> translate<-0.4875,3.4,0>}
      box{<0,0,0><1,2.2,0.5> rotate<0,0,-20> translate<0.55,3.4,-0.1>}
      box{<0,0,0><-1,2.2,0.5> rotate<0,0,20> translate<-0.095,3.40,-0.1>}
   }
   // obere Biegung des breiten Streifens
   difference{
      cylinder{<0,0,0><1.43,0,0>0.5 translate<-0.4875,5.1,0.5> }
      box{<0,0,0><2,2.2,2> translate<-0.8,3.1,0.3>}
      box{<0,0,0><2,2.2,2> translate<-0.7,4,0.5>}
   }
   texture{col_silver}
   translate<-0.455/2,-3,-0.15>
}
#end
/********************************************************************************************************************************************
// Pin 
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN(pintyp)
#if (pintyp=0)
   SWITCH_DIP_SM_PIN0(2.5, 1.5, 0.75, 0.3)
#end

#if (pintyp=1)
   SWITCH_DIP_SM_PIN1()
#end

#if (pintyp=2)
   SWITCH_DIP_SM_PIN2()
#end

#end

/********************************************************************************************************************************************
// body
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_HOUSING(seitenrand, tiefe)
difference { 
   box { <0,1,-tiefe> <2.54*(nrSwitches-1)+2*seitenrand, 4, tiefe> }
   box { <0,3.7,-2> <.2,4.2,2> }
   translate <-seitenrand,0,0> 
} 
#end


#local well  = union{
   box { <-0.5, 3.9, -2>  <0.5, 4.1, 2>  }
   box { <-0.5, 2,   -1> <0.5,  4.1, 1>  }
   }



   //Grundkoerper
   #local seitenrand = 2.2;   //CTS
   #local tiefe = 3.5;
   #if (abmasse=1)
      #local seitenrand = 1.5;
      #local tiefe = 3.5;
   #end
   #if (abmasse=2)         // DIPxxYL
      #local seitenrand = 2.5;
//    #local tiefe = 4.4;
   #end
   #if (abmasse=3)         // DIPxxS
      #local seitenrand = 1.5;
      #local tiefe = 3.5;
   #end
   #if (abmasse=4)         // SD-xx 
      #local seitenrand = 2.1;
      #local tiefe = 3.5;
   #end
   union {
   difference {
      object { SWITCH_DIP_SM_HOUSING(seitenrand, tiefe) }
      #local wellNr = 0;
      #while (wellNr < nrSwitches)
         object { well translate<wellNr*2.54,0,0> }
         #local wellNr = wellNr + 1;
      #end
   pigment { color red 0.15 green 0.1 blue 0.1 } 
   }


   text {
      ttf besch_font "ON" .01, 0
      pigment { NewTan }
      rotate<90,0,0>
      translate<-0.5, 4.01, 2.5>}


   #local switchNr = 0;
   #while (switchNr < nrSwitches)
      #local xShift = switchNr*2.54;
      //pins
      object { SWITCH_DIP_SM_PIN(pintyp) rotate <0,180,0>  translate<xShift, 0, 3.81> }
      object { SWITCH_DIP_SM_PIN(pintyp)                   translate<xShift, 0, -3.81> }
      // schalter
      box { <-0.6, 2, -2>  <0.6, 3, 2> texture {T_Gold_5E} translate<xShift,0,0>}
      #local onOff = SRand(1);
      #if (onOff < 0)
         box { <-0.5, 3,-1> <0.5, 4.1, 0> pigment {Red} translate<xShift,0,0>}
      #else
         box { <-0.5, 3, 1> <0.5, 4.1, 0> pigment {Red} translate<xShift,0,0>}
      #end
      //beschriftung
      text {
         ttf besch_font str(switchNr+1,2,0) .01, 0
         pigment { NewTan }
         rotate<90,0,0>
         translate<xShift-1, 4.01,-3>
         #if (switchNr>8)
            translate<0.5, 0, 0>
         #end
      }
      #if (switchNr < (nrSwitches-1))
         cylinder{<0,4,0><0,4.01,0> 0.25 translate<xShift+1.27, 0, -0.5> pigment { NewTan }}
      #end
      #local switchNr = switchNr + 1;
   #end

    translate<(-nrSwitches+1)*2.54/2,0,0>
}
#end

#macro SWITCH_DIP01_SM()
SWITCH_DIP_SM_BASE(1,0, 0)
#end
#macro SWITCH_DIP02_SM()
SWITCH_DIP_SM_BASE(2,0, 0)
#end
#macro SWITCH_DIP03_SM()
SWITCH_DIP_SM_BASE(3,0, 0)
#end
#macro SWITCH_DIP04_SM()
SWITCH_DIP_SM_BASE(4,0, 0)
#end
#macro SWITCH_DIP05_SM()
SWITCH_DIP_SM_BASE(5,0, 0)
#end
#macro SWITCH_DIP06_SM()
SWITCH_DIP_SM_BASE(6,0, 0)
#end
#macro SWITCH_DIP07_SM()
SWITCH_DIP_SM_BASE(7,0, 0)
#end
#macro SWITCH_DIP08_SM()
SWITCH_DIP_SM_BASE(8,0, 0)
#end
#macro SWITCH_DIP09_SM()
SWITCH_DIP_SM_BASE(9,0, 0)
#end
#macro SWITCH_DIP10_SM()
SWITCH_DIP_SM_BASE(10,0, 0)
#end
#macro SWITCH_DIP12_SM()
SWITCH_DIP_SM_BASE(12,0, 0)
#end
#macro SWITCH_DIP01_SMJ()
SWITCH_DIP_SM_BASE(1,1, 1)
#end
#macro SWITCH_DIP02_SMJ()
SWITCH_DIP_SM_BASE(2,1, 1)
#end
#macro SWITCH_DIP03_SMJ()
SWITCH_DIP_SM_BASE(3,1, 1)
#end
#macro SWITCH_DIP04_SMJ()
SWITCH_DIP_SM_BASE(4,1, 1)
#end
#macro SWITCH_DIP05_SMJ()
SWITCH_DIP_SM_BASE(5,1, 1)
#end
#macro SWITCH_DIP06_SMJ()
SWITCH_DIP_SM_BASE(6,1, 1)
#end
#macro SWITCH_DIP07_SMJ()
SWITCH_DIP_SM_BASE(7,1, 1)
#end
#macro SWITCH_DIP08_SMJ()
SWITCH_DIP_SM_BASE(8,1, 1)
#end
#macro SWITCH_DIP09_SMJ()
SWITCH_DIP_SM_BASE(9,1, 1)
#end
#macro SWITCH_DIP10_SMJ()
SWITCH_DIP_SM_BASE(10,1, 1)
#end
#macro SWITCH_DIP12_SMJ()
SWITCH_DIP_SM_BASE(12,1, 1)
#end
#macro SWITCH_DIP01_SMV()
SWITCH_DIP_SM_BASE(1,2, 2)
#end
#macro SWITCH_DIP02_SMV()
SWITCH_DIP_SM_BASE(2,2, 2)
#end
#macro SWITCH_DIP03_SMV()
SWITCH_DIP_SM_BASE(3,2, 2)
#end
#macro SWITCH_DIP04_SMV()
SWITCH_DIP_SM_BASE(4,2, 2)
#end
#macro SWITCH_DIP05_SMV()
SWITCH_DIP_SM_BASE(5,2, 2)
#end
#macro SWITCH_DIP06_SMV()
SWITCH_DIP_SM_BASE(6,2, 2)
#end
#macro SWITCH_DIP07_SMV()
SWITCH_DIP_SM_BASE(7,2, 2)
#end
#macro SWITCH_DIP08_SMV()
SWITCH_DIP_SM_BASE(8,2, 2)
#end
#macro SWITCH_DIP09_SMV()
SWITCH_DIP_SM_BASE(9,2, 2)
#end
#macro SWITCH_DIP10_SMV()
SWITCH_DIP_SM_BASE(10,2, 2)
#end
#macro SWITCH_DIP12_SMV()
SWITCH_DIP_SM_BASE(12,2, 2)
#end
#macro SWITCH_DIP04_SMV1()
SWITCH_DIP_SM_BASE(4,2, 3)
#end
#macro SWITCH_DIP08_SMV1()
SWITCH_DIP_SM_BASE(8,2, 3)
#end
#macro SWITCH_DIP01_SMV2()
SWITCH_DIP_SM_BASE(1,2, 4)
#end
#macro SWITCH_DIP02_SMV2()
SWITCH_DIP_SM_BASE(2,2, 4)
#end
#macro SWITCH_DIP03_SMV2()
SWITCH_DIP_SM_BASE(3,2, 4)
#end
#macro SWITCH_DIP04_SMV2()
SWITCH_DIP_SM_BASE(4,2, 4)
#end
#macro SWITCH_DIP05_SMV2()
SWITCH_DIP_SM_BASE(5,2, 4)
#end
#macro SWITCH_DIP06_SMV2()
SWITCH_DIP_SM_BASE(6,2, 4)
#end
#macro SWITCH_DIP07_SMV2()
SWITCH_DIP_SM_BASE(7,2, 4)
#end
#macro SWITCH_DIP08_SMV2()
SWITCH_DIP_SM_BASE(8,2, 4)
#end
#macro SWITCH_DIP09_SMV2()
SWITCH_DIP_SM_BASE(9,2, 4)
#end
#macro SWITCH_DIP10_SMV2()
SWITCH_DIP_SM_BASE(10,2, 4)
#end



