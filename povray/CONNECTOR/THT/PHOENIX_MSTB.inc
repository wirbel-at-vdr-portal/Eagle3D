/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * PHOENIX connector type MINICONNEC 5.08
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1  06/01/06
 *
 * - Vertical: 1 vertical, 0 horizontal
 * - Border: 1 with border, 0 whithout border
 ******************************************************************************/
#macro Phoenix_MSTB(Pins,Vertical,Border)
  union {
     #local a = Border;
     difference {
        union {
           #local PAS = 5.08;
           //body
           box {
              <-PAS*Pins/2-a,-4.15,0> <+PAS*Pins/2+a,4.15,12>
              }
           //up additional thickness
           box {
              <-PAS*Pins/2-a,+4.15,9> <+PAS*Pins/2+a,4.15+0.5,12>
              }
           }
        union {
           #local i=0;
           #while (i<Pins)
              //Half Cylindrical holes
              intersection {
                 cylinder {
                    <-(PAS/2*(Pins-1))+(i*PAS),0.35,2.5> <-(PAS/2*(Pins-1))+(i*PAS),0.35,12.1> 4
                    }
                 box {
                    <-(PAS/2*(Pins-1))+(i*PAS)+2.541,+0.1,2.51> <-(PAS/2*(Pins-1))+(i*PAS)-2.541,-5.1,12.1>
                    }
                 }
              //Crenels at the top
              box {
                 <-(PAS/2*(Pins-1))+(i*PAS)+1,3,11> <-(PAS/2*(Pins-1))+(i*PAS)-1,6,12.5>
                 }
              //Crenels for pins
              box {
                 <-(PAS/2*(Pins-1))+(i*PAS)+0.5,0,-0.1> <-(PAS/2*(Pins-1))+(i*PAS)-0.5,-6,2>
                 }
              box {
                 <-(PAS/2*(Pins-1))+(i*PAS)+1.5,-4,-0.1> <-(PAS/2*(Pins-1))+(i*PAS)-1.5,-6,3>
                 }
              #local i=i+1;
           #end
           //Half squared hole
           box {
              <-PAS*Pins/2-0.01,0,2.5> <+PAS*Pins/2+0.01,3.25,12.1>
              }
           //bisel
           box {
              <-PAS*Pins/2-a-0.1,+4.15,9> <+PAS*Pins/2+a+0.1,4.15+0.7,12>
              rotate 20*x translate 4*y
              }
           }
        pigment {
           ForestGreen
           }
        }
     #if (Vertical)
        #local i=0;
        #while (i<Pins)
           union {
              //pin body
              box {
                 <-(PAS/2*(Pins-1))+(i*PAS)-0.4,-0.4,-4> <-(PAS/2*(Pins-1))+(i*PAS)+0.4,+0.4,9>
                 }
              //pin top
              intersection {
                 box {
                    <-(PAS/2*(Pins-1))+(i*PAS)-0.4,-0.4,9> <-(PAS/2*(Pins-1))+(i*PAS)+0.4,+0.4,10>
                    }
                 cone {
                    <-(PAS/2*(Pins-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(Pins-1))+(i*PAS),0,10.01>, 0.25
                    }
                 }
              texture {
                 pigment {
                    P_Silver2
                    }
                 }
              }
           #local i=i+1;
        #end
        rotate <-90,180,0>
     #else
        #local i=0;
        #while (i<Pins)
           //inside part pin
           union {
              //pin body
              box {
                 <-(PAS/2*(Pins-1))+(i*PAS)-0.4,-0.4,2> <-(PAS/2*(Pins-1))+(i*PAS)+0.4,+0.4,9>
                 texture {
                    pigment {
                       P_Silver2
                       }
                    }
                 }
              //pin top
              intersection {
                 box {
                    <-(PAS/2*(Pins-1))+(i*PAS)-0.4,-0.4,9> <-(PAS/2*(Pins-1))+(i*PAS)+0.4,+0.4,10>
                    }
                 cone {
                    <-(PAS/2*(Pins-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(Pins-1))+(i*PAS),0,10.01>, 0.25
                    }
                 }
              texture {
                 pigment {
                    P_Silver2
                    }
                 }
              }
           //outside part pin
           box {
              <-(PAS/2*(Pins-1))+(i*PAS)-0.4,0,1.1> <-(PAS/2*(Pins-1))+(i*PAS)+0.4,-7.5,1.9>
              texture {
                 pigment {
                    P_Silver2
                    }
                 }
              }
           #local i=i+1;
        #end
        translate <0,4.1,-5.08-1.5> //-1.5>
        rotate 180*y
     #end
     }
#end

// Vertical whithout border
#macro CON_THT_PHOENIX_MSTB_V02()  Phoenix_MSTB( 2,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V03()  Phoenix_MSTB( 3,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V04()  Phoenix_MSTB( 4,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V05()  Phoenix_MSTB( 5,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V06()  Phoenix_MSTB( 6,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V07()  Phoenix_MSTB( 7,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V08()  Phoenix_MSTB( 8,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V09()  Phoenix_MSTB( 9,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V10()  Phoenix_MSTB(10,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V11()  Phoenix_MSTB(11,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V12()  Phoenix_MSTB(12,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V13()  Phoenix_MSTB(13,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V14()  Phoenix_MSTB(14,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V15()  Phoenix_MSTB(15,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V16()  Phoenix_MSTB(16,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V17()  Phoenix_MSTB(17,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V18()  Phoenix_MSTB(18,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V19()  Phoenix_MSTB(19,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V20()  Phoenix_MSTB(20,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V21()  Phoenix_MSTB(21,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V22()  Phoenix_MSTB(22,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V23()  Phoenix_MSTB(23,1,0) #end
#macro CON_THT_PHOENIX_MSTB_V24()  Phoenix_MSTB(24,1,0) #end

// Horizontal whithout border
#macro CON_THT_PHOENIX_MSTB_H02()  Phoenix_MSTB( 2,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H03()  Phoenix_MSTB( 3,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H04()  Phoenix_MSTB( 4,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H05()  Phoenix_MSTB( 5,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H06()  Phoenix_MSTB( 6,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H07()  Phoenix_MSTB( 7,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H08()  Phoenix_MSTB( 8,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H09()  Phoenix_MSTB( 9,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H10()  Phoenix_MSTB(10,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H11()  Phoenix_MSTB(11,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H12()  Phoenix_MSTB(12,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H13()  Phoenix_MSTB(13,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H14()  Phoenix_MSTB(14,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H15()  Phoenix_MSTB(15,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H16()  Phoenix_MSTB(16,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H17()  Phoenix_MSTB(17,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H18()  Phoenix_MSTB(18,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H19()  Phoenix_MSTB(19,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H20()  Phoenix_MSTB(20,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H21()  Phoenix_MSTB(21,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H22()  Phoenix_MSTB(22,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H23()  Phoenix_MSTB(23,0,0) #end
#macro CON_THT_PHOENIX_MSTB_H24()  Phoenix_MSTB(24,0,0) #end

// Vertical whith border
#macro CON_THT_PHOENIX_MSTB_VB02() Phoenix_MSTB( 2,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB03() Phoenix_MSTB( 3,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB04() Phoenix_MSTB( 4,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB05() Phoenix_MSTB( 5,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB06() Phoenix_MSTB( 6,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB07() Phoenix_MSTB( 7,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB08() Phoenix_MSTB( 8,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB09() Phoenix_MSTB( 9,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB10() Phoenix_MSTB(10,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB11() Phoenix_MSTB(11,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB12() Phoenix_MSTB(12,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB13() Phoenix_MSTB(13,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB14() Phoenix_MSTB(14,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB15() Phoenix_MSTB(15,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB16() Phoenix_MSTB(16,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB17() Phoenix_MSTB(17,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB18() Phoenix_MSTB(18,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB19() Phoenix_MSTB(19,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB20() Phoenix_MSTB(20,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB21() Phoenix_MSTB(21,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB22() Phoenix_MSTB(22,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB23() Phoenix_MSTB(23,1,1) #end
#macro CON_THT_PHOENIX_MSTB_VB24() Phoenix_MSTB(24,1,1) #end

// Horizontal whith border
#macro CON_THT_PHOENIX_MSTB_HB02() Phoenix_MSTB( 2,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB03() Phoenix_MSTB( 3,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB04() Phoenix_MSTB( 4,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB05() Phoenix_MSTB( 5,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB06() Phoenix_MSTB( 6,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB07() Phoenix_MSTB( 7,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB08() Phoenix_MSTB( 8,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB09() Phoenix_MSTB( 9,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB10() Phoenix_MSTB(10,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB11() Phoenix_MSTB(11,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB12() Phoenix_MSTB(12,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB13() Phoenix_MSTB(13,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB14() Phoenix_MSTB(14,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB15() Phoenix_MSTB(15,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB16() Phoenix_MSTB(16,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB17() Phoenix_MSTB(17,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB18() Phoenix_MSTB(18,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB19() Phoenix_MSTB(19,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB20() Phoenix_MSTB(20,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB21() Phoenix_MSTB(21,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB22() Phoenix_MSTB(22,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB23() Phoenix_MSTB(23,0,1) #end
#macro CON_THT_PHOENIX_MSTB_HB24() Phoenix_MSTB(24,0,1) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-phoenix-508:MSTBV2=CON_THT_PHOENIX_MSTB_V02(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV3=CON_THT_PHOENIX_MSTB_V03(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV4=CON_THT_PHOENIX_MSTB_V04(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV5=CON_THT_PHOENIX_MSTB_V05(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV6=CON_THT_PHOENIX_MSTB_V06(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV7=CON_THT_PHOENIX_MSTB_V07(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV8=CON_THT_PHOENIX_MSTB_V08(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV9=CON_THT_PHOENIX_MSTB_V09(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV10=CON_THT_PHOENIX_MSTB_V10(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV11=CON_THT_PHOENIX_MSTB_V11(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV12=CON_THT_PHOENIX_MSTB_V12(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV13=CON_THT_PHOENIX_MSTB_V13(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV14=CON_THT_PHOENIX_MSTB_V14(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV15=CON_THT_PHOENIX_MSTB_V15(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV16=CON_THT_PHOENIX_MSTB_V16(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV17=CON_THT_PHOENIX_MSTB_V17(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV18=CON_THT_PHOENIX_MSTB_V18(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV19=CON_THT_PHOENIX_MSTB_V19(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV20=CON_THT_PHOENIX_MSTB_V20(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV21=CON_THT_PHOENIX_MSTB_V21(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV22=CON_THT_PHOENIX_MSTB_V22(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV23=CON_THT_PHOENIX_MSTB_V23(:Connector Phoenix MSTB vertical
//con-phoenix-508:MSTBV24=CON_THT_PHOENIX_MSTB_V24(:Connector Phoenix MSTB vertical
//=CON_THT_PHOENIX_MSTB_H02(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H03(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H04(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H05(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H06(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H07(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H08(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H09(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H10(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H11(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H12(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H13(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H14(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H15(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H16(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H17(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H18(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H19(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H20(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H21(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H22(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H23(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_H24(:Connector Phoenix MSTB horizontal
//=CON_THT_PHOENIX_MSTB_VB02(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB03(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB04(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB05(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB06(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB07(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB08(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB09(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB10(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB11(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB12(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB13(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB14(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB15(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB16(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB17(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB18(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB19(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB20(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB21(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB22(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB23(:Connector Phoenix MSTB vertical:
//=CON_THT_PHOENIX_MSTB_VB24(:Connector Phoenix MSTB vertical:
//con-phoenix-508:MSTBA2=CON_THT_PHOENIX_MSTB_HB02(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA3=CON_THT_PHOENIX_MSTB_HB03(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA4=CON_THT_PHOENIX_MSTB_HB04(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA5=CON_THT_PHOENIX_MSTB_HB05(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA6=CON_THT_PHOENIX_MSTB_HB06(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA7=CON_THT_PHOENIX_MSTB_HB07(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA8=CON_THT_PHOENIX_MSTB_HB08(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA9=CON_THT_PHOENIX_MSTB_HB09(Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA10=CON_THT_PHOENIX_MSTB_HB10(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA11=CON_THT_PHOENIX_MSTB_HB11(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA12=CON_THT_PHOENIX_MSTB_HB12(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA13=CON_THT_PHOENIX_MSTB_HB13(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA14=CON_THT_PHOENIX_MSTB_HB14(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA15=CON_THT_PHOENIX_MSTB_HB15(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA16=CON_THT_PHOENIX_MSTB_HB16(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA17=CON_THT_PHOENIX_MSTB_HB17(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA18=CON_THT_PHOENIX_MSTB_HB18(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA19=CON_THT_PHOENIX_MSTB_HB19(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA20=CON_THT_PHOENIX_MSTB_HB20(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA21=CON_THT_PHOENIX_MSTB_HB21(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA22=CON_THT_PHOENIX_MSTB_HB22(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA23=CON_THT_PHOENIX_MSTB_HB23(:Connector Phoenix MSTB horizontal
//con-phoenix-508:MSTBA24=CON_THT_PHOENIX_MSTB_HB24(:Connector Phoenix MSTB horizontal
// end assignment
