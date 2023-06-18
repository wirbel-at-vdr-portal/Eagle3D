/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * female DIN-41612 header.
 *
 * 16.06.2023, -wk
 ******************************************************************************/
#macro DIN41612(Positions,Loaded,RowA,RowB,RowC,RowD,RowE,RowZ,Termination,PostLen,BoardLocks,HighTemp,Type,Plug,RightAngle)
  union {
     #local Rows = RowA + RowB + RowC + RowD + RowE + RowZ;
     #local Cols = Positions / Rows;
     #local Spaces = (Cols-1);
     #if (Type = "C")
        #local E = Spaces;
        #switch(E)
           #case(49) #local D = 131.01; #local C = 133.48; #local B = 134.62; #local A = 139.70; #break
           #case(39) #local D = 105.61; #local C = 108.08; #local B = 109.22; #local A = 114.30; #break
           #case(31) #local D =  85.29; #local C =  87.76; #local B =  88.90; #local A =  94.00; #break
           #case(15) #local D =  44.65; #local C =  47.12; #local B =  48.26; #local A =  53.34; #break
        #end
        #local H1 = -(11.10 - 2*2.54 - 2*1.37)/2;
        #local H2 = H1 + 11.10;
        #local H3 = H1 + (11.10-8.74)/2;
        #local H4 = H3 + 8.74;
        #local H5 = H4 - 2.41;
        #local H6 = 2*2.54 + 2*1.37;
        #local Y1 = -3.76 + (0.80+0.60)/2;
        #local Y2 = +2.54 - 12.62;
        #local Y3 = +2.54 - 7.18;
        #local Y4 = +2.54;
        #local Y5 = -0.7;
        #local X1 = D - 2*0.94;
        #local X2 = (E+2)*2.54;
        #local dH = 2.59;

     #end

     #if (Plug = 1) 
        // housing
        difference {
           merge {
              Round_Box (
                 <-C/2,H1,Y1>
                 <+C/2,H2,Y2>
                 0.2 0
                 )
              Round_Box (
                 <-A/2, 0,Y3>
                 <+A/2,H6,Y4>
                 0.2 0
                 )
              #local h = prism {
                 Y3, (Y3+1.5), 5,
                 <-1.5/2,H5  >,
                 <-1.0/2,H5+1>,
                 <+1.0/2,H5+1>,
                 <+1.5/2,H5  >,
                 <-1.5/2,H5  >
                 };
              GRID(h,2.54,E+6,1)
              }
           merge {
              #local chamfer = 0.5;
              Round_Box (
                 <-D/2-chamfer,H3-chamfer,Y2-0.1+chamfer>
                 <+D/2+chamfer,H5+chamfer,Y2-0.1-chamfer>
                 chamfer 0
                 )
              Round_Box (
                 <-X1/2-chamfer,H5-chamfer,Y2-0.1+chamfer>
                 <+X1/2+chamfer,H4+chamfer,Y2-0.1-chamfer>
                 chamfer 0
                 )
              box {
                 <-D/2,H3,Y2>
                 <+D/2,H5,Y3>
                 }
              box {
                 <-X1/2,H5,Y2>
                 <+X1/2,H4,Y3>
                 }
              box {
                 <-X2/2,  -0.1,Y5    >
                 <+X2/2,H6+0.1,Y4+0.1>
                 }
              GRID (
                 cylinder {
                    <0,  -0.1,0>
                    <0,H2+0.1,0>
                    dH/2
                    },
                 B,2,1
                 )
              #local PinHole = union {
                 box {
                    <-1.3/2,-1.3/2,-5>
                    <+1.3/2,+1.3/2, 0>
                    }
                 };
              #if (RowA = 1) GRID(object { PinHole translate <0,1.37 + 0*2.54,0> },2.54,Cols,1) #end
              #if (RowB = 1) GRID(object { PinHole translate <0,1.37 + 1*2.54,0> },2.54,Cols,1) #end
              #if (RowC = 1) GRID(object { PinHole translate <0,1.37 + 2*2.54,0> },2.54,Cols,1) #end
              }

        
           pigment {
              White * 0.5
              }
           }
     #end

     #if (Plug = 1)
        #local pinA = object { PIN_90deg(0.7,1.5,1.37+0*2.54+0.8/2,2.64,0.8/2+1*2.54+3.76+4.9) translate <0,0,+1*2.54> };
        #local pinB = object { PIN_90deg(0.7,1.5,1.37+1*2.54+0.8/2,2.64,0.8/2+2*2.54+3.76+4.9) translate <0,0,+2*2.54> };
        #local pinC = object { PIN_90deg(0.7,1.5,1.37+2*2.54+0.8/2,2.64,0.8/2+3*2.54+3.76+4.9) translate <0,0,+3*2.54> };
        union {
           #if (RowA = 1) GRID(pinA,2.54,Cols,1) #end
           #if (RowB = 1) GRID(pinB,2.54,Cols,1) #end
           #if (RowC = 1) GRID(pinC,2.54,Cols,1) #end
           texture {
              col_gold
              }
           }
     #end

     }
#end







//Plugs, Right Angle          DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_5650907_5()   DIN41612(150      ,150   ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"C" ,1   ,1         ) #end 
#macro DIN41612_5650906_5()   DIN41612(120      ,120   ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650914_5()   DIN41612(120      ,120   ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650473_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5536010_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,1      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650913_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5536416_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,1      ,"C" ,1   ,1         ) #end
#macro DIN41612_5536146_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.113*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5536149_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.113*inch ,1         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650945_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5536742_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,1      ,"C" ,1   ,1         ) #end
#macro DIN41612_5536356_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650478_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650916_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5148020_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,1      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650946_5()   DIN41612(48       ,32    ,1,0,1,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_5650978_5()   DIN41612(48       ,32    ,1,0,1,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_6_1393644_9() DIN41612(30       ,30    ,1,1,1,0,0,0 ,"Posted"   ,0.118*inch ,0         ,0      ,"C" ,1   ,1         ) #end
#macro DIN41612_7_1393644_1() DIN41612(30       ,30    ,1,1,1,0,0,0 ,"Posted"   ,0.118*inch ,1         ,0      ,"C" ,1   ,1         ) #end
//Receptacles, Vertical       DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_5650405_5()   DIN41612(150      ,150   ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,0         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5535098_5()   DIN41612(120      ,120   ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,0         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5536494_5()   DIN41612(120      ,120   ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,1         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5535090_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,0         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5650963_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,1         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5536153_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.180*inch ,0         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5536155_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.180*inch ,1         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5650956_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.130*inch ,0         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5650983_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.130*inch ,1         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5535070_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,0         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5536484_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.130*inch ,1         ,0      ,"C" ,0   ,0         ) #end
#macro DIN41612_5650459_5()   DIN41612(48       ,32    ,1,0,1,0,0,0 ,"Posted"   ,0.098*inch ,0         ,0      ,"C" ,0   ,0         ) #end
//Plugs, Right Angle          DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_1551603_1()   DIN41612(48       ,32    ,1,0,1,0,0,0 ,"Posted"   ,0.118*inch ,0         ,0      ,"D" ,1   ,1         ) #end
//Receptacles, Vertical       DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_4_6437082_9() DIN41612(48       ,32    ,1,0,1,0,0,0 ,"Posted"   ,0.177*inch ,0         ,0      ,"D" ,0   ,0         ) #end
#macro DIN41612_5536053_5()   DIN41612(48       ,32    ,1,1,0,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"D" ,0   ,0         ) #end
//Plugs, Right Angle          DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_2_164045_4()  DIN41612(48       ,48    ,0,1,0,1,0,1 ,"Posted"   ,0.110*inch ,0         ,0      ,"F" ,1   ,1         ) #end
#macro DIN41612_2_164306_4()  DIN41612(48       ,32    ,0,0,0,1,0,1 ,"Posted"   ,0.110*inch ,0         ,0      ,"F" ,1   ,1         ) #end
//Receptacles, Vertical       DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_166733_4()    DIN41612(48       ,48    ,0,1,0,1,0,1 ,"Posted"   ,0.157*inch ,0         ,0      ,"F" ,0   ,0         ) #end
#macro DIN41612_166951_4()    DIN41612(48       ,32    ,0,0,0,1,0,1 ,"Posted"   ,0.157*inch ,0         ,0      ,"F" ,0   ,0         ) #end
//Receptacles, Right Angle    DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_5650875_5()   DIN41612(150      ,150   ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,0         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650959_5()   DIN41612(150      ,150   ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,1         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650874_5()   DIN41612(120      ,120   ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,0         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650461_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,0         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650895_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,1         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5148242_5()   DIN41612(96       ,96    ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,1         ,1      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650870_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.110*inch ,0         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650897_5()   DIN41612(96       ,64    ,1,0,1,0,0,0 ,"Posted"   ,0.110*inch ,1         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650868_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,0         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_5650893_5()   DIN41612(48       ,48    ,1,1,1,0,0,0 ,"Posted"   ,0.110*inch ,1         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_2_1393656_8() DIN41612(48       ,32    ,1,0,1,0,0,0 ,"Posted"   ,0.118*inch ,0         ,0      ,"R" ,0   ,1         ) #end
#macro DIN41612_2_1393656_2() DIN41612(30       ,30    ,1,1,1,0,0,0 ,"Posted"   ,0.118*inch ,1         ,0      ,"R" ,0   ,1         ) #end
//Plugs, Right Angle          DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_5536052_5()   DIN41612(64       ,64    ,1,1,0,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"B" ,1   ,1         ) #end
#macro DIN41612_5536385_5()   DIN41612(64       ,64    ,1,1,0,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"B" ,1   ,1         ) #end
#macro DIN41612_5536053_5()   DIN41612(32       ,32    ,1,1,0,0,0,0 ,"Posted"   ,0.104*inch ,0         ,0      ,"B" ,1   ,1         ) #end
#macro DIN41612_5536386_5()   DIN41612(32       ,32    ,1,1,0,0,0,0 ,"Posted"   ,0.104*inch ,1         ,0      ,"B" ,1   ,1         ) #end
#macro DIN41612_5_1393644_6() DIN41612(20       ,20    ,1,1,0,0,0,0 ,"Posted"   ,0.118*inch ,0         ,0      ,"B" ,1   ,1         ) #end
//Receptacles, Vertical       DIN41612(Positions,Loaded,Row A..EZ,  Termination,PostLen    ,BoardLocks,HighTemp,Type,Plug,RightAngle)
#macro DIN41612_5650860_5()   DIN41612(64       ,64    ,1,1,0,0,0,0 ,"Posted"   ,0.130*inch ,1         ,0      ,"B" ,0   ,0         ) #end
#macro DIN41612_5536446_5()   DIN41612(32       ,32    ,1,1,0,0,0,0 ,"Posted"   ,0.130*inch ,0         ,0      ,"B" ,0   ,0         ) #end
#macro DIN41612_7_1393640_2() DIN41612(20       ,20    ,1,1,0,0,0,0 ,"Posted"   ,0.114*inch ,0         ,0      ,"B" ,0   ,0         ) #end




#macro DIN41612_MABC96L() object { DIN41612_5650473_5() rotate <0,-90,0> } #end






/********************************************************************************************************************************************
Posted .130                                  //Eurocard Verbinder
— — 5650956-5                                //Duane Clark <dclark@akamail.com>
p — 5650983-5                                ********************************************************************************************************************************************
ACTION PIN — — — 5535059-5                   #macro CON_EUROCARD_BASE(pins, rows)
48 / 48 A, B, C                              union
Posted .130                                  {
— — 5535070-5                                  #local j = pins/rows;   // number of pins in row
p — 5536484-5                                  #local hs = 2.54;       // horizontal pin spacing
ACTION PIN — — — 5535034-5                     #local hc = 0.9;        // horizontal centerline
48 / 32 A, C Posted .098 — — 5650459-5         #local vs = 2.54;       // vertical pin spacing
  #local vc = 5.475;      // vertical centerline
  #local po = 7.63;       // offset to first pin
  #local ps = (j-1)*hs;   // total pin spacing
  #local mo = 2.55;       // offset to first mounting hole
  #local d = hc+10.1;     // overall body depth
  #local id = 6.4;        // inside depth
  #local w = ps+po*2;     // overall body width
  #local h = 10.95;       // overall body height
  #local io = 4.4;        // inner housing offset
  #local r = 0.5;         // pin inner radius
  #local pw = 0.60;       // pin width
  #local ph = 0.60;       // pin height
  #local pl = 8.5+vs;     // length of lower pins
  #local pcb = 1.625;     // pc board cutout height
  #local kh = 0.4;        // key height

  difference
  {
    union {
      box{<0,0,0><d,h,w> }
      // mounting hole tabs
      box{<d-12.5,0,0><0,7.125,5.1> }
      box{<d-12.5,0,w><0,7.125,w-5.1> }
    }
    // mounting hole cutouts
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> }
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> translate<0,0,w-5> }
    // mounting holes
    cylinder{<hc,-0.1,mo><hc,h,mo>1.4 }
    cylinder{<hc,-0.1,w-mo><hc,h,w-mo>1.4 }
    // pc board cutout
    box{<d-12.6,-0.1,-0.1><d-id-0.7,pcb,w+0.1> }
    // pin area cutout
    box{<d-id-0.001,1.125,io><d+0.1,h-3.625,w-io> }
    box{<d-id,2,io+1><d+0.1,h-1.125,w-io-1> }
    // upper side key outer cutouts
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> }
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> translate<0,0,w-4.175> }
    // front side cutouts
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> }
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> translate<0,0,w-3.175> }
    // front notches
    box{<d-1,-0.1,po+hs*0.5><d+0.1,h+0.1,po+hs*2.5> }
    box{<d-1,-0.1,po+hs*6.5><d+0.1,h+0.1,po+hs*8.5> }
    box{<d-1,-0.1,po+hs*16.5><d+0.1,h+0.1,po+hs*18.5> }
    box{<d-1,-0.1,po+ps-hs*6.5><d+0.1,h+0.1,po+ps-hs*8.5> }
    box{<d-1,-0.1,po+ps-hs*0.5><d+0.1,h+0.1,po+ps-hs*2.5> }
    // lower keys
    box{<d-id,1.126,po+hs*1><d,1.125-kh,po+hs*2> }
    box{<d-id,1.126,po+hs*7><d,1.125-kh,po+hs*8> }
    box{<d-id,1.126,po+hs*17><d,1.125-kh,po+hs*18> }
    box{<d-id,1.126,po+ps-hs*7><d,1.125-kh,po+ps-hs*8> }
    box{<d-id,1.126,po+ps-hs*1><d,1.125-kh,po+ps-hs*2> }
    // upper keys
    box{<d-id,h-1.126,po+hs*1><d,h-1.125+kh,po+hs*2> }
    box{<d-id,h-1.126,po+hs*7><d,h-1.125+kh,po+hs*8> }
    box{<d-id,h-1.126,po+hs*17><d,h-1.125+kh,po+hs*18> }
    box{<d-id,h-1.126,po+ps-hs*7><d,h-1.125+kh,po+ps-hs*8> }
    box{<d-id,h-1.126,po+ps-hs*1><d,h-1.125+kh,po+ps-hs*2> }
    pigment{Gray85}
  }

  // pins
  union
  {
    #local k = 0;
    #while(k<rows)
      #if (rows<3)
        #if (k>0)
          // if only two rows, then the center row is the one that is missing
          #local k = k+1;
        #end
      #end
      #local i = 0;
      #while(i<j)
        // horizontal pin
        box{<r+ph/2-pl-k*vs,0-ph/2,0-pw/2><0,ph/2,pw/2> translate<hc+8.5,vc+(k-1)*vs,po+i*hs>}
        // pin radius
        difference {
          cylinder{<0,0,0><0,0,pw>r+ph}
          cylinder{<0,0,-0.1><0,0,pw+0.1>r}
          box{<0,-2,-0.1><2,2,pw+0.1>}
          box{<-2,-2,-0.1><2,0,pw+0.1>}
          translate<hc-(k+1)*vs+r+ph/2,vc+(k-1)*vs-r-ph/2,po+i*hs-pw/2>
        }
        // vertical pin
        box{<-ph/2,-2,-pw/2><ph/2,vc+(k-1)*vs-r-ph/2,pw/2> translate<hc-(k+1)*vs,0,po+i*hs>}
        #local i = i+1;
      #end
      #local k = k+1;
    #end
    texture{col_gold}
  }

  translate<0-hc,0-pcb,0-w/2>
  translate<0,2,0>
}
#end
#macro CON_EUROCARD_96M_3_L()
CON_EUROCARD_BASE(96,3)
#end
#macro CON_EUROCARD_64M_2_L()
CON_EUROCARD_BASE(64,2)
#end

*/








/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-vg:M617-31=CON_THT_DIN41617_31_R90(:DIN-41617 connector
// end assignment
