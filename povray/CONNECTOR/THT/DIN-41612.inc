/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * female & male DIN-41612 headers.
 *
 * The following are supported:
 * B,B/2,B/3  64/32/20 pol, ab  , Stecker liegend, Buchse stehend
 * Q,Q/2,Q/3  64/32/20 pol, ab  , Stecker stehend, Buchse liegend
 * C,C/2,C/3  96/64/30 pol, abc , Stecker liegend, Buchse stehend
 * R,R/2,R/3  96/64/30 pol, abc , Stecker stehend, Buchse liegend
 *
 * 16.06.2023, -wk
 ******************************************************************************/
#macro DIN41612(Positions,Loaded,GridMulti,RowA,RowB,RowC,RowD,RowE,RowZ,BoardLocks,Type,Plug,RightAngle)
  union {
     #local Rows = RowA + RowB + RowC + RowD + RowE + RowZ;
     #local Cols = GridMulti * Loaded / Rows;
     #local Spaces = Cols - 1;

     #if ((Type = "B") | (Type = "Q") | (Type = "C") | (Type = "R"))
        #local w = Spaces * 2.54;
        #local A = w + 15.24;
        #if (Plug = 1)
           #local B = w + 10.16;
        #else
           #local B = w + 11.90;
        #end
        #local C = w + 9.02;
        #local D = w + 6.55;
        #local E = Spaces;
        #local F = w + 6.26;
        #local G = F - 2*1.0;

        #local Y1 = -3.76 + (0.80+0.60)/2;
        #local Y2 = +2.54 - 12.62;
        #local Y3 = +2.54 - 7.18;
        #local Y4 = +2.54;
        #local Y5 = 0.8;//-0.7;
        #local Y6 = -10.1;
        #local Y7 = Y6 + 7.4;
        #local Y8 = Y6 + 12.5;
        #local Y9 = Y6 + 11.6;
        #local Y10 = Y6 + 6.4;
        #local Y12 = -2.9;
        #local Y13 = -5.2;
        #local Y14 = -11.6;

        #local X1 = D - 2*0.94;
        #local X2 = (E+2)*2.54;
        #local dH = 2.59;
     #end

     #if ((Type = "B") | (Type = "Q"))
        #local H1 = -(8.56 - 1*2.54 - 2*1.37)/2;
        #local H2 = H1 + 8.56;
        #local H3 = H1 + (8.56-6.20)/2;
        #local H4 = H3 + 6.20;
        #local H5 = H4 - 2.41;
        #local H6 = 5.96;
        #local H7 = H6 - 3.0;
        #local Y11 = -1.27+0.3;
     #end

     #if ((Type = "C") | (Type = "R"))
        #local H1 = -(11.10 - 2*2.54 - 2*1.37)/2;
        #local H2 = H1 + 11.10;
        #local H3 = H1 + (11.10-8.74)/2;
        #local H4 = H3 + 8.74;
        #local H5 = H4 - 2.41;
        #local H6 = 8.50;
        #local H7 = H6 - 3.0;
        #local Y11 = 0.3;
     #end

     #if (Plug = 1 & ((Type = "B") | (Type = "C")))
        difference {
           union {
              Round_Box (
                 <-C/2,H1,Y1>
                 <+C/2,H2,Y2>
                 0.2 0
                 )
              Round_Box (
                 <-A/2, 0,Y3>
                 <+A/2,H2,Y4>
                 0.2 0
                 )
              }
           union {
              #local chamfer = 0.5;
              ChamferBox (
                 <-D/2-chamfer,H3-chamfer,Y2-0.1+chamfer>
                 <+D/2+chamfer,H5+chamfer,Y2-0.1-chamfer>
                 chamfer
                 )
              ChamferBox (
                 <-X1/2-chamfer,H5-chamfer,Y2-0.1+chamfer>
                 <+X1/2+chamfer,H4+chamfer,Y2-0.1-chamfer>
                 chamfer
                 )
              box {
                 <-D/2,H3,Y2>
                 <+D/2,H5+0.2,Y3>
                 }
              box {
                 <-X1/2,H5,Y2>
                 <+X1/2,H4,Y3>
                 }
              box {
                 <-X2/2,  -0.1,Y5    >
                 <+X2/2,H2+0.1,Y4+0.1>
                 }
              GRID (
                 union {
                    cylinder {
                       <0,  -0.1,0>
                       <0,H2+0.1,0>
                       dH/2
                       }
                    box {
                       <-5.2/2, 6,-5.2/2>
                       <+5.2/2,10,+5.2/2>
                       }
                    },
                 B,2,1
                 )
              #local PinHole = union {
                 box {
                    <-1.3/2,-1.3/2,-5>
                    <+1.3/2,+1.3/2, 0>
                    }
                 box {
                    <-1.8/2,-0.7/2,0>
                    <+1.8/2,+1.7/2,3>
                    }
                 };
              #if (RowA = 1) GRID(object { PinHole translate <0,1.37 + 0*2.54,0> },2.54,Cols,1) #end
              #if (RowB = 1) GRID(object { PinHole translate <0,1.37 + 1*2.54,0> },2.54,Cols,1) #end
              #if (RowC = 1) GRID(object { PinHole translate <0,1.37 + 2*2.54,0> },2.54,Cols,1) #end
              #if (RowD = 1) GRID(object { PinHole translate <0,1.37 + 3*2.54,0> },2.54,Cols,1) #end
              #if (RowE = 1) GRID(object { PinHole translate <0,1.37 + 4*2.54,0> },2.54,Cols,1) #end
              }
           translate <0,1.7,0>
           pigment {
              White * 0.5
              }
           }
     #end

     #if (Plug = 1 & ((Type = "Q") | (Type = "R")))
        difference {
           #local B = w + 11.90;
           union {
              Round_Box (
                 <-C/2,H1,Y13+1>
                 <+C/2,H2,Y14>
                 0.2 0
                 )
              Round_Box (
                 <-A/2,H1,0>
                 <+A/2,H2,Y13>
                 0.2 0
                 )
              }
           union {
              #local chamfer = 0.5;
              ChamferBox (
                 <-D/2-chamfer,H3-chamfer,Y14-0.1+chamfer>
                 <+D/2+chamfer,H5+chamfer,Y14-0.1-chamfer>
                 chamfer
                 )
              ChamferBox (
                 <-X1/2-chamfer,H5-chamfer,Y14-0.1+chamfer>
                 <+X1/2+chamfer,H4+chamfer,Y14-0.1-chamfer>
                 chamfer
                 )
              box {
                 <-D/2,H3,Y14>
                 <+D/2,H5+0.2,Y13>
                 }
              box {
                 <-X1/2,H5,Y14>
                 <+X1/2,H4,Y13>
                 }
              Round_Box (
                 <-D/2+0.5, -5,+0.1>
                 <+D/2-0.5,+10,-0.5>
                 0.5 0
                 )
              #local mount =
                 union {
                    cylinder {
                       <0,0, +1>
                       <0,0,-12>
                       dH/2
                       }
                    Round_Box (
                       <-5.35/2,-5.5/2,Y12>
                       <+5.30/2,+5.5/2,Y14-1>
                       0.5 0
                       )
                    };
              object { mount rotate <0,0,0>   translate <-B/2,(H1+H2)/2+0.3,0>}
              object { mount rotate <0,0,180> translate <+B/2,(H1+H2)/2+0.3,0>}
              }
           rotate <90,180,0>
           translate <0,0.5,H2/2-0.8>
           pigment {
              White * 0.5
              }
           }
     #end

     #if (Plug = 0 & ((Type = "Q") | (Type = "R")))
        difference {
           union {
              ChamferBox (
                 <-F/2, 0,Y6>
                 <+F/2,H7,0>
                 0.5
                 )
              ChamferBox (
                 <-G/2,H7,Y6>
                 <+G/2,H6,0>
                 0.5
                 )
              box {
                 <-G/2+0.5,H7-0.6,Y6>
                 <+G/2-0.5,H7+0.6,0>
                 }
              Round_Box (
                 <-A/2, 0,Y3>
                 <+A/2,H2,Y4>
                 0.2 0
                 )
              }
           union {
              GRID (
                 union {
                    cylinder {
                       <0,  -0.1,0>
                       <0,H2+0.1,0>
                       dH/2
                       }
                    box {
                       <-5.2/2, 6,-5.2/2>
                       <+5.2/2,10,+5.2/2>
                       }
                    },
                 B,2,1
                 )
              #local PinHole = box {
                 <-1.8/2,-0.7/2,Y6-1>
                 <+1.8/2,+1.7/2,0.5>
                 };
                               GRID(object { PinHole translate <0,1.37 + 0*2.54,0> },2.54,Cols,1)
                               GRID(object { PinHole translate <0,1.37 + 1*2.54,0> },2.54,Cols,1)
              #if (Type = "C") GRID(object { PinHole translate <0,1.37 + 2*2.54,0> },2.54,Cols,1) #end
              }
           pigment {
              White * 0.5
              }
           }
     #end
     #if (Plug = 0 & ((Type = "B") | (Type = "C")))
        difference {
           union {
              ChamferBox (
                 <-F/2,-0.5,Y6>
                 <+F/2,H7,0>
                 0.5
                 )
              ChamferBox (
                 <-G/2,H7,Y6>
                 <+G/2,H6,0>
                 0.5
                 )
              box {
                 <-G/2+0.5,H7-0.6,Y6>
                 <+G/2-0.5,H7+0.6,0>
                 }
              Round_Box (
                 <-A/2, -1,Y9>
                 <+A/2,H2,Y10>
                 0.3 0
                 )
              rotate <90,180,0>
              translate <0,1.5,H6/2>
              }
           union {
              GRID (
                 union {
                    cylinder {
                       <0,  -1.0,Y11>
                       <0,H2+0.1,Y11>
                       dH/2
                       }
                    Round_Box (
                       <-6/2,3.6   ,Y11-6/2>
                       <+6/2,H2+0.1,Y11+6/2>
                       0.3 0
                       )
                    },
                 B,2,1
                 )
              #local PinHole = box {
                 <-1.8/2,-0.7/2,Y6-1>
                 <+1.8/2,+1.7/2,0.5>
                 };
              union {
                                  GRID(object { PinHole translate <0,1.37 + 0*2.54,0> },2.54,Cols,1)
                                  GRID(object { PinHole translate <0,1.37 + 1*2.54,0> },2.54,Cols,1)
                 #if (Type = "C") GRID(object { PinHole translate <0,1.37 + 2*2.54,0> },2.54,Cols,1) #end
                 rotate <90,180,0>
                 translate <0,1.5,H6/2>
                 }
              }
           pigment {
              White * 0.5
              }
           }
     #end

     #if (RightAngle = 1)
        #if ((Type = "B") | (Type = "C"))
           #local dH = 1.5;
        #else
           #local dH = 0;
        #end
        #local pinA = object { PIN_90deg(0.7,1.5,dH+1.37+0*2.54+0.8/2,2.64,0.8/2+1*2.54+3.76+4.9) translate <0,0,+1*2.54> };
        #local pinB = object { PIN_90deg(0.7,1.5,dH+1.37+1*2.54+0.8/2,2.64,0.8/2+2*2.54+3.76+4.9) translate <0,0,+2*2.54> };
        #local pinC = object { PIN_90deg(0.7,1.5,dH+1.37+2*2.54+0.8/2,2.64,0.8/2+3*2.54+3.76+4.9) translate <0,0,+3*2.54> };
        union {
           #if (RowA = 1) GRID(pinA,2.54*GridMulti,Cols/GridMulti,1) #end
           #if (RowB = 1) GRID(pinB,2.54*GridMulti,Cols/GridMulti,1) #end
           #if (RowC = 1) GRID(pinC,2.54*GridMulti,Cols/GridMulti,1) #end
           #if (GridMulti = 2)
              translate <-2.54/2,0,0>
           #end
           texture {
              col_gold
              }
           }
     #else
        #if (Plug = 1 & ((Type = "Q") | (Type = "R"))) #local len = 10; #else #local len = 8; #end
        #local pinA = object { PIN_STRAIGHT(0.7,len,3) translate <0,0,+2.54> };
        #local pinB = object { PIN_STRAIGHT(0.7,len,3) };
        #local pinC = object { PIN_STRAIGHT(0.7,len,3) translate <0,0,-2.54> };
        union {
           #if (RowA = 1) GRID(pinA,2.54*GridMulti,Cols/GridMulti,1) #end
           #if (RowB = 1) GRID(pinB,2.54*GridMulti,Cols/GridMulti,1) #end
           #if (RowC = 1) GRID(pinC,2.54*GridMulti,Cols/GridMulti,1) #end
           #if ((Type = "B") | (Type = "Q"))
              translate <0,0,-1.27>
           #end
           texture {
              col_gold
              }
           }        
     #end

     }
#end


#macro CON_THT_DIN41612_MABC96L()  object { DIN41612( 96, 96,1, 1,1,1,0,0,0, 0,"C",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAC64L()   object { DIN41612( 96, 64,1, 1,0,1,0,0,0, 0,"C",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MABC48B2() object { DIN41612( 48, 48,1, 1,1,1,0,0,0, 0,"C",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAC32LH()  object { DIN41612( 48, 32,1, 1,0,1,0,0,0, 0,"C",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MABC30()   object { DIN41612( 30, 30,1, 1,1,1,0,0,0, 0,"C",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAC32C2()  object { DIN41612( 96, 32,2, 1,0,1,0,0,0, 0,"C",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAB32()    object { DIN41612( 64, 32,1, 1,0,0,0,0,0, 0,"B",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAB32B2()  object { DIN41612( 32, 32,1, 1,1,0,0,0,0, 0,"B",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAB64()    object { DIN41612( 64, 64,1, 1,1,0,0,0,0, 0,"B",1,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAB32Q2()  object { DIN41612( 32, 32,1, 1,1,0,0,0,0, 0,"Q",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAB64Q()   object { DIN41612( 64, 64,1, 1,1,0,0,0,0, 0,"Q",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MABC150R() object { DIN41612(150,150,1, 1,1,1,0,0,0, 0,"R",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MABC120R() object { DIN41612(120,120,1, 1,1,1,0,0,0, 0,"R",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MABC96R()  object { DIN41612( 96, 96,1, 1,1,1,0,0,0, 0,"R",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MABC48R2() object { DIN41612( 48, 48,1, 1,1,1,0,0,0, 0,"R",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAC64R()   object { DIN41612( 96, 64,1, 1,0,1,0,0,0, 0,"R",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_MAC32R2()  object { DIN41612( 48, 32,1, 1,0,1,0,0,0, 0,"R",1,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC150R() object { DIN41612(150,150,1, 1,1,1,0,0,0, 0,"R",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC120R() object { DIN41612(120,120,1, 1,1,1,0,0,0, 0,"R",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC96R()  object { DIN41612( 96, 96,1, 1,1,1,0,0,0, 0,"R",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAC64R()   object { DIN41612( 96, 64,1, 1,0,1,0,0,0, 0,"R",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC48R2() object { DIN41612( 48, 48,1, 1,1,1,0,0,0, 0,"R",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAC32R2()  object { DIN41612( 48, 32,1, 1,0,1,0,0,0, 0,"R",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAB16Q2()  object { DIN41612( 16, 16,2, 1,1,0,0,0,0, 0,"Q",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAB32Q2()  object { DIN41612( 32, 32,1, 1,1,0,0,0,0, 0,"Q",0,1) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAB64S()   object { DIN41612( 64, 64,1, 1,1,0,0,0,0, 0,"B",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAB32()    object { DIN41612( 64, 32,1, 1,0,0,0,0,0, 0,"B",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAB32B_2() object { DIN41612( 32, 32,1, 1,1,0,0,0,0, 0,"B",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC96S()  object { DIN41612( 96, 96,1, 1,1,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAC64S()   object { DIN41612( 96, 64,1, 1,0,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC48B2() object { DIN41612( 48, 48,1, 1,1,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> translate <+1.27,0,0> } #end
#macro CON_THT_DIN41612_FAC48SH()  object { DIN41612( 48, 48,1, 1,1,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FAC32B2()  object { DIN41612( 48, 32,1, 1,0,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> translate <+1.27,0,0> } #end
#macro CON_THT_DIN41612_FAC32SH()  object { DIN41612( 48, 32,1, 1,0,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> } #end
#macro CON_THT_DIN41612_FABC30()   object { DIN41612( 30, 30,1, 1,1,1,0,0,0, 0,"C",0,0) rotate <0,-90,0> } #end


/*******************************************************************************
 * 19 inch boards, 3HE & 6HE
 *
 * 26.06.2023, -wk
 ******************************************************************************/
#macro FPholder()
  union {
     #local X1 = 106;
     #local X2 = 81.75;
     #local X3 = 95.45;
     #local X4 = 99.88;
     #local X5 = 83.90;
     #local X6 = 95.10;
     #local X7 = 95.10;
     #local X8 = 103;
     #local X9 = 96.20;
     #local X10 = 98.88;
     #local X11 = 89.10;
     #local Y1 = +2.2;
     #local Y2 = Y1 - 3.95;
     #local Y3 = Y1 - 5.80;
     #local Y4 = Y1 - 8.95;
     #local H1 = -3;
     #local H2 = H1 + 1.27;
     #local H3 = H1 + 11;
     #local H4 = H1 + 9.20;
     #local H5 = H1 + 6.25;
     difference {
        union {
           box {
              <-X1/2,H1,Y1>
              <+X1/2, 0,Y2>
              }
           Round_Box (
              <-X1/2, 0,Y1>
              <-X5/2,H3,Y2>
              0.3 0
              )
           Round_Box (
              <+X1/2, 0,Y1>
              <+X5/2,H3,Y2>
              0.3 0
              )
           Round_Box (
              <+X9/2, 0, 0>
              <+X5/2,H3,Y4>
              0.5 0
              )
           Round_Box (
              <-X9/2, 0, 0>
              <-X5/2,H3,Y4>
              0.5 0
              )
           }
        box {
           <-X1/2-0.1, H2,     0>
           <+X1/2+0.1,0.1,Y2-0.1>
           }
        box {
           <-X3/2,     0,Y2+1.0>
           <-X2/2,H1-0.1,Y2-0.1>
           }
        box {
           <+X3/2,     0,Y2+1.0>
           <+X2/2,H1-0.1,Y2-0.1>
           }
        box {
           <-X1/2-0.1,H1-0.1,  -0.1>
           <-X4/2    ,H2+0.1,Y2-0.1>
           }
        box {
           <+X1/2+0.1,H1-0.1,  -0.1>
           <+X4/2    ,H2+0.1,Y2-0.1>
           }
        box {
           <-X1/2-0.1,H4    ,Y1+0.1>
           <-X5/2+0.1,H3+0.1,     0>
           }
        box {
           <+X1/2+0.1,H4    ,Y1+0.1>
           <+X5/2-0.1,H3+0.1,     0>
           }
        box {
           <-X8/2,H4    ,  +0.1>
           <-X7/2,H3+0.1,Y2-0.1>
           }
        box {
           <+X8/2,H4    ,  +0.1>
           <+X7/2,H3+0.1,Y2-0.1>
           }
        cylinder {
           <+X10/2,H5,Y1+0.1>
           <+X10/2,H5,Y2-0.1>
           2.6/2
           }
        cylinder {
           <-X10/2,H5,Y1+0.1>
           <-X10/2,H5,Y2-0.1>
           2.6/2
           }
        cylinder {
           <+X11/2,  -0.1,Y3>
           <+X11/2,H3+0.1,Y3>
           2.6/2
           }
        cylinder {
           <-X11/2,  -0.1,Y3>
           <-X11/2,H3+0.1,Y3>
           2.6/2
           }
        #local b1 = union {
           TOOLS_NUT(2.5,1,White*0.5)
           cylinder {
              <0,0,0>
              <0,2,0>
              3/2
              }
           rotate y*60
           scale <1.05,2,1.05>
           };
        object { b1 translate <+X11/2,H3-1.5,Y3> }
        object { b1 translate <-X11/2,H3-1.5,Y3> }
        #local b2 = union {
           TOOLS_NUT(2.5,1,White*0.5)
           cylinder {
              <0,0,0>
              <0,2.5,0>
              3/2
              }
           scale <1.05,2,1.05>
           rotate <90,0,30>
           };
        object { b2 translate <+X10/2,H5,Y2-2.5> }
        object { b2 translate <-X10/2,H5,Y2-2.5> }
        pigment {
           White * 0.5
           }
        }
     #local Screw = object {
        TOOLS_SCREW(2.5,10,1,Silver)
        rotate <180,0,0>
        };
     object { Screw translate <+X11/2,-1.5,Y3> }
     object { Screw translate <-X11/2,-1.5,Y3> }
     #local Nut = object {
        TOOLS_NUT(2.5,0,Silver)
        rotate <0,60,0>
        };
     object { Nut translate <+X11/2,+6.5,Y3> }
     object { Nut translate <-X11/2,+6.5,Y3> }
     }
#end

#macro CON_THT_6HE2xVG64AC()
  union {
     object { CON_THT_DIN41612_MAC64L() rotate <0,180,0> translate <2.54,0,50.80       > }
     object { CON_THT_DIN41612_MAC64L() rotate <0,180,0> translate <2.54,0,50.80+133.35> }
     }
#end

#macro CON_THT_3HEVGC32AC()
  object { CON_THT_DIN41612_MAC32C2() rotate <0,0,0> translate <157.48,0,0> }
#end

#macro CON_THT_3HEVGC32AC_M()
  union {
     CON_THT_3HEVGC32AC()
     object {
        FPholder()
        rotate <0,-90,0>
        translate <0,0,0>
        }
     }
#end

#macro CON_THT_3HEVGC64AC()
  object { CON_THT_DIN41612_MAC64L() rotate <0,0,0> translate <157.48,0,0> }
#end

#macro CON_THT_3HEVGC64AC_M()
  union {
     CON_THT_3HEVGC64AC()
     object {
        FPholder()
        rotate <0,-90,0>
        translate <0,0,0>
        }
     }
#end

#macro CON_THT_3HEVGC96ABC()
  object { CON_THT_DIN41612_MABC96L() rotate <0,0,0> translate <157.48,0,0> }
#end

#macro CON_THT_3HEVGC96ABC_M()
  union {
     CON_THT_3HEVGC96ABC()
     object {
        FPholder()
        rotate <0,-90,0>
        translate <0,0,0>
        }
     }
#end




/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-vg:MABC96LP=CON_THT_DIN41612_MABC96L(:Eurocard Connector
//con-vg:MABC96L=CON_THT_DIN41612_MABC96L(:Eurocard Connector
//con-vg:MAC64L=CON_THT_DIN41612_MAC64L(:Eurocard Connector
//con-vg:MAC32LH=CON_THT_DIN41612_MAC32LH(:Eurocard Connector
//con-vg:MAC32B2=CON_THT_DIN41612_MAC32LH(:Eurocard Connector
//con-vg:MAB32=CON_THT_DIN41612_MAB32(:Eurocard Connector
//con-vg:MAB32B2=CON_THT_DIN41612_MAB32B2(:Eurocard Connector
//con-vg:MAB64=CON_THT_DIN41612_MAB64(:Eurocard Connector
//con-vg:MABC30=CON_THT_DIN41612_MABC30(:Eurocard Connector
//con-vg:MABC48B2=CON_THT_DIN41612_MABC48B2(:Eurocard Connector
//con-vg:MAB32Q2=CON_THT_DIN41612_MAB32Q2(:Eurocard Connector
//con-vg:MAB64Q=CON_THT_DIN41612_MAB64Q(:Eurocard Connector
//con-vg:MABC150R=CON_THT_DIN41612_MABC150R(:Eurocard Connector
//con-vg:MABC120R=CON_THT_DIN41612_MABC120R(:Eurocard Connector
//con-vg:MABC96R=CON_THT_DIN41612_MABC96R(:Eurocard Connector
//con-vg:MABC96RS=CON_THT_DIN41612_MABC96R(:Eurocard Connector
//con-vg:MABC48R2=CON_THT_DIN41612_MABC48R2(:Eurocard Connector
//con-vg:MAC32R2=CON_THT_DIN41612_MAC32R2(:Eurocard Connector
//con-vg:MAC64R=CON_THT_DIN41612_MAC64R(:Eurocard Connector
//con-vg:MACR64S=CON_THT_DIN41612_MAC64R(:Eurocard Connector
//con-vg:FABC150R=CON_THT_DIN41612_FABC150R(:Eurocard Connector
//con-vg:FABC120R=CON_THT_DIN41612_FABC120R(:Eurocard Connector
//con-vg:FABC96R=CON_THT_DIN41612_FABC96R(:Eurocard Connector
//con-vg:FAC64R=CON_THT_DIN41612_FAC64R(:Eurocard Connector
//con-vg:FABC48R2=CON_THT_DIN41612_FABC48R2(:Eurocard Connector
//con-vg:FAC32R2=CON_THT_DIN41612_FAC32R2(:Eurocard Connector
//con-vg:FAB32Q2=CON_THT_DIN41612_FAB32Q2(:Eurocard Connector
//con-vg:FAB16Q2=CON_THT_DIN41612_FAB16Q2(:Eurocard Connector
//con-vg:FAB32=CON_THT_DIN41612_FAB32(:Eurocard Connector
//con-vg:FAB32B-2=CON_THT_DIN41612_FAB32B_2(:Eurocard Connector
//con-vg:FAB64S=CON_THT_DIN41612_FAB64S(:Eurocard Connector
//con-vg:FABC96S=CON_THT_DIN41612_FABC96S(:Eurocard Connector
//con-vg:FAC64S=CON_THT_DIN41612_FAC64S(:Eurocard Connector
//con-vg:FABC48B2=CON_THT_DIN41612_FABC48B2(:Eurocard Connector
//con-vg:FAC48SH=CON_THT_DIN41612_FAC48SH(:Eurocard Connector
//con-vg:FABC30=CON_THT_DIN41612_FABC30(:Eurocard Connector
//con-vg:FAC32B2=CON_THT_DIN41612_FAC32B2(:Eurocard Connector
//con-vg:FAC32SH=CON_THT_DIN41612_FAC32SH(:Eurocard Connector
//19inch:6HE_100-VG64AC=CON_THT_6HE2xVG64AC(:Eurocard with 2x VG64AC connector
//19inch:6HE_160-VG64AC=CON_THT_6HE2xVG64AC(:Eurocard with 2x VG64AC connector
//19inch:VG32=CON_THT_3HEVGC32AC(:Eurocard with VG C 32AC connector
//19inch:VG32B=CON_THT_3HEVGC32AC(:Eurocard with VG C 32AC connector
//19inch:VG32K=CON_THT_3HEVGC32AC(:Eurocard with VG C 32AC connector
//19inch:VG32KB=CON_THT_3HEVGC32AC(:Eurocard with VG C 32AC connector
//19inch:VG32P=CON_THT_3HEVGC32AC_M(:Eurocard with VG C 32AC connector
//19inch:VG64=CON_THT_3HEVGC64AC(:Eurocard with VG C 64AC connector
//19inch:VG64B=CON_THT_3HEVGC64AC(:Eurocard with VG C 64AC connector
//19inch:VG64K=CON_THT_3HEVGC64AC(:Eurocard with VG C 64AC connector
//19inch:VG64KB=CON_THT_3HEVGC64AC(:Eurocard with VG C 64AC connector
//19inch:VG64P=CON_THT_3HEVGC64AC_M(:Eurocard with VG C 64AC connector
//19inch:VG96=CON_THT_3HEVGC96ABC(:Eurocard with VG C 96ABC connector
//19inch:VG96B=CON_THT_3HEVGC96BABC(:Eurocard with VG C 96ABC connector
//19inch:VG96K=CON_THT_3HEVGC96ABC(:Eurocard with VG C 96ABC connector
//19inch:VG96KB=CON_THT_3HEVGC96ABC(:Eurocard with VG C 96ABC connector
//19inch:VG96P=CON_THT_3HEVGC96ABC_M(:Eurocard with VG C 96ABC connector
// end assignment
