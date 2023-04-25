/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT DIP switch
 * Nigel Eke <nigel@eke.name>
 ******************************************************************************/
#macro SWITCH_THT_DIP_BASE(nrSwitches)
  #local pin = cylinder {
     <0,-3,0> <0,0,0> 0.25
     texture {
        T_Gold_5E
        }
     }

  #local offSwitch = union {
     box {
        <0.1,3.71,2.01> <0.9,3.71,5.9>
        }
     box {
        <0.1,3.71,2.01> <0.9,4.5,3>
        }
     pigment {
        NewTan
        }
     }

  #local onSwitch = union {
     box {
        <0.1,3.71,2.01> <0.9,3.71,5.9>
        }
     box {
        <0.1,3.71,5> <0.9,4.5,5.9>
        }
     pigment {
        NewTan
        }
     }

  union {
     difference {
        difference {
           box {
              <0,0,0> <2*nrSwitches+1,3.9,7.8>
              }
           box {
              <0,3.7,2> <.3,3.91,6>
              }
           pigment {
              color red 197/255 green 42/255 blue 43/255
              }
           }
        #for(i,0,nrSwitches-1)
           box {
              <0,3.7,2> <1,3.91,6>
              pigment {
                 MediumWood
                 }
              translate <i*2+1,0,0>
              }
        #end
        }
     #for(i,0,nrSwitches-1)
        #local xShift = (i*2)+1;
        object {
           pin
           translate <xShift+0.5,0,1>
           }
        object {
           pin
           translate <xShift+0.5,0,7>
           }
        #local onOff = SRand(1);
        #if (onOff < 0)
           object {
              offSwitch
              translate <xShift,0,0>
              }
        #else
           object {
              onSwitch
              translate <xShift,0,0>
              }
        #end
        text {
           ttf besch_font str(i+1,2,0) 0.01, 0
           pigment {
              NewTan
              }
           scale 1.5
           rotate <90,0,0>
           translate <xShift-0.2,3.91,0.5>
           }
     #end
     text {
        ttf besch_font "ON" 0.01, 0
        pigment {
           NewTan
           }
        scale 1.5
        rotate <90,0,0>
        translate <0.5,3.91,6.3>
        }
     translate <-nrSwitches-.5,0,-3.9>
     scale 2.54/2
     }
#end

#macro SWITCH_THT_DIP01()
  SWITCH_THT_DIP_BASE(1)
#end

#macro SWITCH_THT_DIP02()
  SWITCH_THT_DIP_BASE(2)
#end

#macro SWITCH_THT_DIP03()
  SWITCH_THT_DIP_BASE(3)
#end

#macro SWITCH_THT_DIP04()
  SWITCH_THT_DIP_BASE(4)
#end

#macro SWITCH_THT_DIP05()
  SWITCH_THT_DIP_BASE(5)
#end

#macro SWITCH_THT_DIP06()
  SWITCH_THT_DIP_BASE(6)
#end

#macro SWITCH_THT_DIP07()
  SWITCH_THT_DIP_BASE(7)
#end

#macro SWITCH_THT_DIP08()
  SWITCH_THT_DIP_BASE(8)
#end

#macro SWITCH_THT_DIP09()
  SWITCH_THT_DIP_BASE(9)
#end

#macro SWITCH_THT_DIP10()
  SWITCH_THT_DIP_BASE(10)
#end

#macro SWITCH_THT_DIP12()
  SWITCH_THT_DIP_BASE(12)
#end


/*******************************************************************************
 * DIP switches, SMT and THT
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * Nigel Eke <nigel@eke.name>
 *
 * pintyp=0  SMT nach aussen gewinkelt
 * pintyp=1  SMT nach innen gewinkelt
 * pintyp=2  THT
 ******************************************************************************/
#macro SWITCH_VAR_DIP_BASE(nrSwitches, pintyp, abmasse)

  // Pin Typ 0, SMT normal
  #macro SWITCH_DIP_SM_PIN0(H,B,T,S)
     //H = Hoehe des Pins
     //B = Breite des Pins
     //T = Tiefe des Pins
     //S = Materialstaerke des Pins
     union {
        box {
           <0,H,T/2> <B/4,H-S,-T/2>
           }
        difference {
           cylinder {
              <B/4,H-S,-T/2> <B/4,H-S,T/2>S
              }
           box {
              <-1,H-S,-T/2-0.01> <B/2,H-S-3,T/2+0.01>
              }
           }
        box {
           <B/4,H-S,-T/2> <B/4+S,S,T/2>
           }
        difference {
           cylinder {
              <B/4+S,S,-T/2> <B/4+S,S,T/2>S
              }
           box {
              <0,S,-T/2-0.01> <B,S+3,T/2+0.01>
              }
           }
        box {
           <B/4+S,0,-T/2> <B,S,T/2>
           }
        difference {
           box {
              <B/4+S,S,-T/2> <B/4+S+S/2,1.5*S,T/2>
              }
           cylinder {
              <B/4+S+S/2,S+S/2,T/2+0.01> <B/4+S+S/2,S+S/2,-T/2-0.01>, S/2
              }
           }
        rotate <0,90,0>
        texture {
           col_silver
           }
        }
  #end

  // Pin Typ 1, SMT J-type
  #macro SWITCH_DIP_SM_PIN1()
     union {
        intersection {
           difference {
              box {
                 <0,0,0> <1.8,0.9,0.45>
                 }
              cylinder {
                 <0.9,0.9,-0.1> <0.9,0.9,0.5> 0.7
                 }
              }
           cylinder {
              <0.9,0.9,-0.1> <0.9,0.9,0.5> 0.9
              }
           }
        box {
           <1.6,0.8,0> <1.8,1.2,0.45>
           }
        difference {
           box {
              <1.6,1.2,-0.125> <1.8,2.5,0.45+0.125>
              }
           box {
              <-0.1,0,0> <0.3,0.5,-0.5>
              rotate <-20,0,0>
              translate <1.55,1.2,0>
              }
           box {
              <-0.1,0,0> <0.3,0.5,0.5>
              rotate <20,0,0>
              translate <1.55,1.2,0.45>
              }
           }
        difference {
           cylinder {
              <1.5,2.5,-0.125> <1.5,2.5,0.45+0.125> 0.3
              }
           box {
              <1.6,2.9,-1> <1,2,1>
              }
           }
        difference {
           box {
              <1.6,2.5,-0.125> <1.4,2.8,0.45+0.125>
              }
           cylinder {
              <1.45,2.45,-1> <1.45,2.45,1> 0.15
              }
           }
        texture {
           col_silver
           }
        translate <-1.4,0,0>
        rotate <0,90,0>
        translate <-0.225,0,0>
        }
  #end

  // Pin Typ 2, THT
  #macro SWITCH_DIP_SM_PIN2()
     union {
        //unterstes Ende durch das Loch der Platine
        difference {
           box {
              <0,0,0> <0.455,3.4,0.3>
              }
           box {
              <0,0,0> <0.5,0.5,0.5>
              rotate <0,0,-20>
              translate <0.305,0,-0.1>
              }
           box {
              <0,0,0> <-0.5,0.5,0.5>
              rotate <0,0,20>
              translate <0.15,0,-0.1>
              }
           }
        box {
           <0,0,0> <1.43,0.3,0.33>
           translate <-0.4875,5.3,0.5>
           }
        difference {
           box {
              <0,0,0> <1.43,0.25,0.25>
              translate <-0.4875,5.05,0.3>
              }
           cylinder {
              <0,0,0> <2,0,0> 0.25
              translate <-0.6,5.05,0.55>
              }
           }
        // breiter senkrechter Streifen mit Verjuengung
        difference {
           box {
              <0,0,0> <1.43,1.7,0.3>
              translate <-0.4875,3.4,0>
              }
           box {
              <0,0,0> <1,2.2,0.5>
              rotate <0,0,-20>
              translate <0.55,3.4,-0.1>
              }
           box {
              <0,0,0> <-1,2.2,0.5>
              rotate <0,0,20>
              translate <-0.095,3.40,-0.1>
              }
           }
        // obere Biegung des breiten Streifens
        difference {
           cylinder {
              <0,0,0> <1.43,0,0> 0.5
              translate <-0.4875,5.1,0.5>
              }
           box {
              <0,0,0> <2,2.2,2>
              translate <-0.8,3.1,0.3>
              }
           box {
              <0,0,0> <2,2.2,2>
              translate <-0.7,4,0.5>
              }
           }
        texture {
           col_silver
           }
        translate <-0.455/2,-3,-0.15>
        }
  #end

  // Pin
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

  // body
  #macro SWITCH_DIP_SM_HOUSING(seitenrand, tiefe)
     difference {
        box {
           <0,1,-tiefe> <2.54*(nrSwitches-1)+2*seitenrand, 4, tiefe>
           }
        box {
           <0,3.7,-2> <.2,4.2,2>
           }
        translate <-seitenrand,0,0>
        }
  #end

  //Grundkoerper
  #local seitenrand = 2.2;   //CTS
  #local tiefe = 3.5;

  #if (abmasse = 1)
     #local seitenrand = 1.5;
     #local tiefe = 3.5;
  #end
  #if (abmasse = 2)         // DIPxxYL
     #local seitenrand = 2.5;
  #end
  #if (abmasse = 3)         // DIPxxS
     #local seitenrand = 1.5;
     #local tiefe = 3.5;
  #end
  #if (abmasse = 4)         // SD-xx
     #local seitenrand = 2.1;
     #local tiefe = 3.5;
  #end

  union {
     difference {
        object {
           SWITCH_DIP_SM_HOUSING(seitenrand, tiefe)
           }
        #for(i,0,nrSwitches-1)
           union {
              box {
                 <-0.5, 3.9, -2>  <0.5, 4.1, 2>
                 }
              box {
                 <-0.5, 2,   -1> <0.5,  4.1, 1>
                 }
              translate <i*2.54,0,0>
              }
        #end
        pigment {
           color red 0.15 green 0.1 blue 0.1
           }
        }
     text {
        ttf besch_font "ON" 0.01, 0
        pigment {
           NewTan
           }
        rotate <90,0,0>
        translate <-0.5, 4.01, 2.5>
        }

     #for(i,0,nrSwitches-1)
        #local xShift = i*2.54;
        //pins
        object {
           SWITCH_DIP_SM_PIN(pintyp)
           rotate <0,180,0>
           translate <xShift, 0, 3.81>
           }
        object {
           SWITCH_DIP_SM_PIN(pintyp)
           translate <xShift, 0, -3.81>
           }
        // schalter
        box {
           <-0.6, 2, -2>  <0.6, 3, 2>
           texture {
              T_Gold_5E
              }
           translate <xShift,0,0>
           }
        #local onOff = SRand(1);
        #if (onOff < 0)
           box {
              <-0.5, 3,-1> <0.5, 4.1, 0>
              pigment {
                 Red
                 }
              translate <xShift,0,0>
              }
        #else
           box {
              <-0.5, 3, 1> <0.5, 4.1, 0>
              pigment {
                 Red
                 }
              translate <xShift,0,0>
              }
        #end
        //beschriftung
        text {
           ttf besch_font str(i+1,2,0) 0.01, 0
           pigment {
              NewTan
              }
           rotate <90,0,0>
           translate <xShift-1, 4.01,-3>
           #if (i> 8)
              translate <0.5, 0, 0>
           #end
           }
        #if (i < (nrSwitches-1))
           cylinder {
              <0,4,0> <0,4.01,0> 0.25
              translate <xShift+1.27, 0, -0.5>
              pigment {
                 NewTan
                 }
              }
        #end
     #end // end for loop

     translate <(-nrSwitches+1)*2.54/2,0,0>
     }
#end


#macro SWITCH_SMT_DIP01F()
  SWITCH_VAR_DIP_BASE(1,0, 0)
#end

#macro SWITCH_SMT_DIP02F()
  SWITCH_VAR_DIP_BASE(2,0, 0)
#end

#macro SWITCH_SMT_DIP03F()
  SWITCH_VAR_DIP_BASE(3,0, 0)
#end

#macro SWITCH_SMT_DIP04F()
  SWITCH_VAR_DIP_BASE(4,0, 0)
#end

#macro SWITCH_SMT_DIP05F()
  SWITCH_VAR_DIP_BASE(5,0, 0)
#end

#macro SWITCH_SMT_DIP06F()
  SWITCH_VAR_DIP_BASE(6,0, 0)
#end

#macro SWITCH_SMT_DIP07F()
  SWITCH_VAR_DIP_BASE(7,0, 0)
#end

#macro SWITCH_SMT_DIP08F()
  SWITCH_VAR_DIP_BASE(8,0, 0)
#end

#macro SWITCH_SMT_DIP09F()
  SWITCH_VAR_DIP_BASE(9,0, 0)
#end

#macro SWITCH_SMT_DIP10F()
  SWITCH_VAR_DIP_BASE(10,0, 0)
#end

#macro SWITCH_SMT_DIP12F()
  SWITCH_VAR_DIP_BASE(12,0, 0)
#end

#macro SWITCH_SMT_DIP01J()
  SWITCH_VAR_DIP_BASE(1,1, 1)
#end

#macro SWITCH_SMT_DIP02J()
  SWITCH_VAR_DIP_BASE(2,1, 1)
#end

#macro SWITCH_SMT_DIP03J()
  SWITCH_VAR_DIP_BASE(3,1, 1)
#end

#macro SWITCH_SMT_DIP04J()
  SWITCH_VAR_DIP_BASE(4,1, 1)
#end

#macro SWITCH_SMT_DIP05J()
  SWITCH_VAR_DIP_BASE(5,1, 1)
#end

#macro SWITCH_SMT_DIP06J()
  SWITCH_VAR_DIP_BASE(6,1, 1)
#end

#macro SWITCH_SMT_DIP07J()
  SWITCH_VAR_DIP_BASE(7,1, 1)
#end

#macro SWITCH_SMT_DIP08J()
  SWITCH_VAR_DIP_BASE(8,1, 1)
#end

#macro SWITCH_SMT_DIP09J()
  SWITCH_VAR_DIP_BASE(9,1, 1)
#end

#macro SWITCH_SMT_DIP10J()
  SWITCH_VAR_DIP_BASE(10,1, 1)
#end

#macro SWITCH_SMT_DIP12J()
  SWITCH_VAR_DIP_BASE(12,1, 1)
#end

#macro SWITCH_THT_DIP01YL()
  SWITCH_VAR_DIP_BASE(1,2, 2)
#end

#macro SWITCH_THT_DIP02YL()
  SWITCH_VAR_DIP_BASE(2,2, 2)
#end

#macro SWITCH_THT_DIP03YL()
  SWITCH_VAR_DIP_BASE(3,2, 2)
#end

#macro SWITCH_THT_DIP04YL()
  SWITCH_VAR_DIP_BASE(4,2, 2)
#end

#macro SWITCH_THT_DIP05YL()
  SWITCH_VAR_DIP_BASE(5,2, 2)
#end

#macro SWITCH_THT_DIP06YL()
  SWITCH_VAR_DIP_BASE(6,2, 2)
#end

#macro SWITCH_THT_DIP07YL()
  SWITCH_VAR_DIP_BASE(7,2, 2)
#end

#macro SWITCH_THT_DIP08YL()
  SWITCH_VAR_DIP_BASE(8,2, 2)
#end

#macro SWITCH_THT_DIP09YL()
  SWITCH_VAR_DIP_BASE(9,2, 2)
#end

#macro SWITCH_THT_DIP10YL()
  SWITCH_VAR_DIP_BASE(10,2, 2)
#end

#macro SWITCH_THT_DIP12YL()
  SWITCH_VAR_DIP_BASE(12,2, 2)
#end

#macro SWITCH_THT_DIP04S()
  SWITCH_VAR_DIP_BASE(4,2, 3)
#end

#macro SWITCH_THT_DIP08S()
  SWITCH_VAR_DIP_BASE(8,2, 3)
#end

#macro SWITCH_THT_DIP01SD4()
  SWITCH_VAR_DIP_BASE(1,2, 4)
#end

#macro SWITCH_THT_DIP02SD4()
  SWITCH_VAR_DIP_BASE(2,2, 4)
#end

#macro SWITCH_THT_DIP03SD4()
  SWITCH_VAR_DIP_BASE(3,2, 4)
#end

#macro SWITCH_THT_DIP04SD4()
  SWITCH_VAR_DIP_BASE(4,2, 4)
#end

#macro SWITCH_THT_DIP05SD4()
  SWITCH_VAR_DIP_BASE(5,2, 4)
#end

#macro SWITCH_THT_DIP06SD4()
  SWITCH_VAR_DIP_BASE(6,2, 4)
#end

#macro SWITCH_THT_DIP07SD4()
  SWITCH_VAR_DIP_BASE(7,2, 4)
#end

#macro SWITCH_THT_DIP08SD4()
  SWITCH_VAR_DIP_BASE(8,2, 4)
#end

#macro SWITCH_THT_DIP09SD4()
  SWITCH_VAR_DIP_BASE(9,2, 4)
#end

#macro SWITCH_THT_DIP10SD4()
  SWITCH_VAR_DIP_BASE(10,2, 4)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//switch-dil:DS-01=SWITCH_THT_DIP01(:THT DIP switch
//switch-dil:DS-02=SWITCH_THT_DIP02(:THT DIP switch
//switch-dil:DS-03=SWITCH_THT_DIP03(:THT DIP switch
//switch-dil:DS-04=SWITCH_THT_DIP04(:THT DIP switch
//switch-dil:DS-05=SWITCH_THT_DIP05(:THT DIP switch
//switch-dil:DS-06=SWITCH_THT_DIP06(:THT DIP switch
//switch-dil:DS-07=SWITCH_THT_DIP07(:THT DIP switch
//switch-dil:DS-08=SWITCH_THT_DIP08(:THT DIP switch
//switch-dil:DS-09=SWITCH_THT_DIP09(:THT DIP switch
//switch-dil:DS-10=SWITCH_THT_DIP10(:THT DIP switch
//switch-dil:DS-12=SWITCH_THT_DIP12(:THT DIP switch
//special:EDG-01=SWITCH_THT_DIP01(:Dip switch:
//special:EDG-02=SWITCH_THT_DIP02(:Dip switch:
//special:EDG-03=SWITCH_THT_DIP03(:Dip switch:
//special:EDG-04=SWITCH_THT_DIP04(:Dip switch:
//special:EDG-05=SWITCH_THT_DIP05(:Dip switch:
//special:EDG-06=SWITCH_THT_DIP06(:Dip switch:
//special:EDG-07=SWITCH_THT_DIP07(:Dip switch:
//special:EDG-08=SWITCH_THT_DIP08(:Dip switch:
//special:EDG-09=SWITCH_THT_DIP09(:Dip switch:
//special:EDG-10=SWITCH_THT_DIP10(:Dip switch:
//special:EDG-12=SWITCH_THT_DIP12(:Dip switch:
//switch-dil:CTS-219-02=SWITCH_SMT_DIP02F(:SMT DIP switch std pin
//switch-dil:CTS-219-03=SWITCH_SMT_DIP03F(:SMT DIP switch std pin
//switch-dil:CTS-219-04=SWITCH_SMT_DIP04F(:SMT DIP switch std pin
//switch-dil:CTS-219-05=SWITCH_SMT_DIP05F(:SMT DIP switch std pin
//switch-dil:CTS-219-06=SWITCH_SMT_DIP06F(:SMT DIP switch std pin
//switch-dil:CTS-219-07=SWITCH_SMT_DIP07F(:SMT DIP switch std pin
//switch-dil:CTS-219-08=SWITCH_SMT_DIP08F(:SMT DIP switch std pin
//switch-dil:CTS-219-09=SWITCH_SMT_DIP09F(:SMT DIP switch std pin
//switch-dil:CTS-219-10=SWITCH_SMT_DIP10F(:SMT DIP switch std pin
//switch-dil:CTS-219-12=SWITCH_SMT_DIP12F(:SMT DIP switch std pin
//switch-dil:CTS-219-02J=SWITCH_SMT_DIP02J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-03J=SWITCH_SMT_DIP03J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-04J=SWITCH_SMT_DIP04J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-05J=SWITCH_SMT_DIP05J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-06J=SWITCH_SMT_DIP06J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-07J=SWITCH_SMT_DIP07J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-08J=SWITCH_SMT_DIP08J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-09J=SWITCH_SMT_DIP09J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-10J=SWITCH_SMT_DIP10J(:SMT DIP switch J-type pin
//switch-dil:CTS-219-12J=SWITCH_SMT_DIP12J(:SMT DIP switch J-type pin
//switch-dil:DIP02YL=SWITCH_THT_DIP02YL(:THT DIP switch
//switch-dil:DIP03YL=SWITCH_THT_DIP03YL(:THT DIP switch
//switch-dil:DIP04YL=SWITCH_THT_DIP04YL(:THT DIP switch
//switch-dil:DIP05YL=SWITCH_THT_DIP05YL(:THT DIP switch
//switch-dil:DIP06YL=SWITCH_THT_DIP06YL(:THT DIP switch
//switch-dil:DIP07YL=SWITCH_THT_DIP07YL(:THT DIP switch
//switch-dil:DIP08YL=SWITCH_THT_DIP08YL(:THT DIP switch
//switch-dil:DIP09YL=SWITCH_THT_DIP09YL(:THT DIP switch
//switch-dil:DIP10YL=SWITCH_THT_DIP10YL(:THT DIP switch
//switch-dil:DIP04S=SWITCH_THT_DIP04S(:THT Dip switch
//switch-dil:DIP08S=SWITCH_THT_DIP08S(:THT Dip switch
//switch-dil:SD4-01=SWITCH_THT_DIP01SD4(:THT DIP switch
//switch-dil:SD4-02=SWITCH_THT_DIP02SD4(:THT DIP switch
//switch-dil:SD4-03=SWITCH_THT_DIP03SD4(:THT DIP switch
//switch-dil:SD4-04=SWITCH_THT_DIP04SD4(:THT DIP switch
//switch-dil:SD4-05=SWITCH_THT_DIP05SD4(:THT DIP switch
//switch-dil:SD4-06=SWITCH_THT_DIP06SD4(:THT DIP switch
//switch-dil:SD4-07=SWITCH_THT_DIP07SD4(:THT DIP switch
//switch-dil:SD4-08=SWITCH_THT_DIP08SD4(:THT DIP switch
//switch-dil:SD4-09=SWITCH_THT_DIP09SD4(:THT DIP switch
//switch-dil:SD4-10=SWITCH_THT_DIP10SD4(:THT DIP switch
// end assignment
