/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * male header 2.54mm, 1-row, 2-row, 3-row.
 ******************************************************************************/
#macro MPE_087(Cols,Rows,A,B,C,L)
  union {
     #local Grid = 2.54;

     difference {
        Round_Box(
           <-Cols*Grid/2,0,-Rows*Grid/2>
           <+Cols*Grid/2,L,+Rows*Grid/2>
           0.1 0
           )
        #local X = 0.3;
        GRID (
           GRID (
              box { <-X,-0.1,-X> <+X,L+0.1,+X> rotate <0,45,0> },
              Grid,Cols+1,1
              ), Grid*Rows,1,2
           )
        box {
           <-Cols*Grid/2-0.1,-0.1,-Rows*Grid/2+X>
           <+Cols*Grid/2+0.1,L/4 ,+Rows*Grid/2-X>
           }
        pigment {
           White * 0.2
           }
        }
     GRID(object { PIN_STRAIGHT(0.64,B+L,C) texture { col_gold } },Grid,Cols,Rows)
     }
#end


/*******************************************************************************
 * male header 2.54mm, 1-row, 2-row, 3-row.
 * - https://www.mpe-connector.de/de/produkte/
 *           stiftleisten/stiftleiste-254-mm-1/087-1
 *     parts 087-1, 087-2, 087-3 (with choosen common lengths)
 ******************************************************************************/
#macro CON_THT_PINHDR_MPE087_01x1() MPE_087(01,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_02x1() MPE_087(02,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_03x1() MPE_087(03,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_04x1() MPE_087(04,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_05x1() MPE_087(05,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_06x1() MPE_087(06,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_07x1() MPE_087(07,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_08x1() MPE_087(08,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_09x1() MPE_087(09,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_10x1() MPE_087(10,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_11x1() MPE_087(11,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_12x1() MPE_087(12,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_13x1() MPE_087(13,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_14x1() MPE_087(14,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_15x1() MPE_087(15,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_16x1() MPE_087(16,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_17x1() MPE_087(17,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_18x1() MPE_087(18,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_19x1() MPE_087(19,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_20x1() MPE_087(20,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_21x1() MPE_087(21,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_22x1() MPE_087(22,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_23x1() MPE_087(23,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_24x1() MPE_087(24,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_25x1() MPE_087(25,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_26x1() MPE_087(26,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_27x1() MPE_087(27,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_28x1() MPE_087(28,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_29x1() MPE_087(29,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_30x1() MPE_087(30,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_31x1() MPE_087(31,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_32x1() MPE_087(32,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_33x1() MPE_087(33,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_34x1() MPE_087(34,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_35x1() MPE_087(35,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_36x1() MPE_087(36,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_37x1() MPE_087(37,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_38x1() MPE_087(38,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_39x1() MPE_087(39,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_40x1() MPE_087(40,1,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_01x2() MPE_087(01,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_02x2() MPE_087(02,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_03x2() MPE_087(03,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_04x2() MPE_087(04,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_05x2() MPE_087(05,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_06x2() MPE_087(06,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_07x2() MPE_087(07,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_08x2() MPE_087(08,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_09x2() MPE_087(09,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_10x2() MPE_087(10,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_11x2() MPE_087(11,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_12x2() MPE_087(12,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_13x2() MPE_087(13,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_14x2() MPE_087(14,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_15x2() MPE_087(15,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_16x2() MPE_087(16,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_17x2() MPE_087(17,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_18x2() MPE_087(18,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_19x2() MPE_087(19,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_20x2() MPE_087(20,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_21x2() MPE_087(21,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_22x2() MPE_087(22,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_23x2() MPE_087(23,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_24x2() MPE_087(24,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_25x2() MPE_087(25,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_26x2() MPE_087(26,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_27x2() MPE_087(27,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_28x2() MPE_087(28,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_29x2() MPE_087(29,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_30x2() MPE_087(30,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_31x2() MPE_087(31,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_32x2() MPE_087(32,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_33x2() MPE_087(33,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_34x2() MPE_087(34,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_35x2() MPE_087(35,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_36x2() MPE_087(36,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_37x2() MPE_087(37,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_38x2() MPE_087(38,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_39x2() MPE_087(39,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_40x2() MPE_087(40,2,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_01x3() MPE_087(01,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_02x3() MPE_087(02,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_03x3() MPE_087(03,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_04x3() MPE_087(04,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_05x3() MPE_087(05,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_06x3() MPE_087(06,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_07x3() MPE_087(07,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_08x3() MPE_087(08,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_09x3() MPE_087(09,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_10x3() MPE_087(10,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_11x3() MPE_087(11,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_12x3() MPE_087(12,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_13x3() MPE_087(13,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_14x3() MPE_087(14,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_15x3() MPE_087(15,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_16x3() MPE_087(16,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_17x3() MPE_087(17,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_18x3() MPE_087(18,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_19x3() MPE_087(19,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_20x3() MPE_087(20,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_21x3() MPE_087(21,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_22x3() MPE_087(22,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_23x3() MPE_087(23,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_24x3() MPE_087(24,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_25x3() MPE_087(25,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_26x3() MPE_087(26,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_27x3() MPE_087(27,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_28x3() MPE_087(28,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_29x3() MPE_087(29,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_30x3() MPE_087(30,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_31x3() MPE_087(31,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_32x3() MPE_087(32,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_33x3() MPE_087(33,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_34x3() MPE_087(34,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_35x3() MPE_087(35,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_36x3() MPE_087(36,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_37x3() MPE_087(37,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_38x3() MPE_087(38,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_39x3() MPE_087(39,3,  12.60,6.80,3.30,2.50) #end
#macro CON_THT_PINHDR_MPE087_40x3() MPE_087(40,3,  12.60,6.80,3.30,2.50) #end



/*******************************************************************************
 * male header 2.54mm, 1-row, 2-row, 3-row; 90 deg
 ******************************************************************************/
#macro MPE_088(Cols,Rows,A,B,C,W)
  union {
     #local Grid = 2.54;
     #local L = 2.50;

     difference {
        Round_Box(
           <-Cols*Grid/2,0,-Rows*Grid/2>
           <+Cols*Grid/2,L,+Rows*Grid/2>
           0.1 0
           )
        #local X = 0.3;
        GRID (
           GRID (
              box { <-X,-0.1,-X> <+X,L+0.1,+X> rotate <0,45,0> },
              Grid,Cols+1,1
              ), Grid*Rows,1,2
           )
        box {
           <-Cols*Grid/2-0.1,-0.1,-Rows*Grid/2+X>
           <+Cols*Grid/2+0.1,L/4 ,+Rows*Grid/2-X>
           }
        pigment {
           White * 0.2
           }
        //translate <0,-L/2,0>
        rotate <-90,0,0>
        translate <0,Grid*Rows/2,-Grid*Rows/2>
        }
     GRID(
        object {
           PIN_90deg(0.64,0.5,Grid/2,C,A+0.64/2)
           rotate <0,0,0>
           translate <0,0,-(Rows-1)*Grid/2>
           texture {
              col_gold
              }
           },
        Grid,Cols,1
        )
     #if (Rows > 1)
     GRID(
        object {
           PIN_90deg(0.64,1.0,1.5*Grid,C,A+0.64/2+Grid)
           rotate <0,0,0>
           translate <0,0,+(Rows-1)*Grid/2>
           texture {
              col_gold
              }
           },
        Grid,Cols,1
        )
     #end
     rotate <0,180,0>
     }
#end

/*******************************************************************************
 * male header 2.54mm, 1-row, 2-row, 3-row; 90 deg.
 * - https://www.mpe-connector.de/de/produkte/
 *           stiftleiste-abgewinkelt-254-mm/088-1
 *     parts 088-1, 088-2, 088-3 (with choosen common lengths)
 ******************************************************************************/
#macro CON_THT_PINHDR_MPE088_01x1R90() MPE_088(01,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_02x1R90() MPE_088(02,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_03x1R90() MPE_088(03,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_04x1R90() MPE_088(04,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_05x1R90() MPE_088(05,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_06x1R90() MPE_088(06,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_07x1R90() MPE_088(07,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_08x1R90() MPE_088(08,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_09x1R90() MPE_088(09,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_10x1R90() MPE_088(10,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_11x1R90() MPE_088(11,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_12x1R90() MPE_088(12,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_13x1R90() MPE_088(13,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_14x1R90() MPE_088(14,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_15x1R90() MPE_088(15,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_16x1R90() MPE_088(16,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_17x1R90() MPE_088(17,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_18x1R90() MPE_088(18,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_19x1R90() MPE_088(19,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_20x1R90() MPE_088(20,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_21x1R90() MPE_088(21,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_22x1R90() MPE_088(22,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_23x1R90() MPE_088(23,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_24x1R90() MPE_088(24,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_25x1R90() MPE_088(25,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_26x1R90() MPE_088(26,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_27x1R90() MPE_088(27,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_28x1R90() MPE_088(28,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_29x1R90() MPE_088(29,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_30x1R90() MPE_088(30,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_31x1R90() MPE_088(31,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_32x1R90() MPE_088(32,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_33x1R90() MPE_088(33,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_34x1R90() MPE_088(34,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_35x1R90() MPE_088(35,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_36x1R90() MPE_088(36,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_37x1R90() MPE_088(37,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_38x1R90() MPE_088(38,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_39x1R90() MPE_088(39,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_40x1R90() MPE_088(40,1,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_01x2R90() MPE_088(01,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_02x2R90() MPE_088(02,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_03x2R90() MPE_088(03,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_04x2R90() MPE_088(04,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_05x2R90() MPE_088(05,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_06x2R90() MPE_088(06,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_07x2R90() MPE_088(07,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_08x2R90() MPE_088(08,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_09x2R90() MPE_088(09,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_10x2R90() MPE_088(10,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_11x2R90() MPE_088(11,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_12x2R90() MPE_088(12,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_13x2R90() MPE_088(13,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_14x2R90() MPE_088(14,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_15x2R90() MPE_088(15,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_16x2R90() MPE_088(16,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_17x2R90() MPE_088(17,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_18x2R90() MPE_088(18,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_19x2R90() MPE_088(19,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_20x2R90() MPE_088(20,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_21x2R90() MPE_088(21,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_22x2R90() MPE_088(22,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_23x2R90() MPE_088(23,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_24x2R90() MPE_088(24,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_25x2R90() MPE_088(25,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_26x2R90() MPE_088(26,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_27x2R90() MPE_088(27,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_28x2R90() MPE_088(28,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_29x2R90() MPE_088(29,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_30x2R90() MPE_088(30,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_31x2R90() MPE_088(31,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_32x2R90() MPE_088(32,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_33x2R90() MPE_088(33,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_34x2R90() MPE_088(34,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_35x2R90() MPE_088(35,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_36x2R90() MPE_088(36,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_37x2R90() MPE_088(37,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_38x2R90() MPE_088(38,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_39x2R90() MPE_088(39,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_40x2R90() MPE_088(40,2,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_01x3R90() MPE_088(01,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_02x3R90() MPE_088(02,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_03x3R90() MPE_088(03,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_04x3R90() MPE_088(04,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_05x3R90() MPE_088(05,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_06x3R90() MPE_088(06,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_07x3R90() MPE_088(07,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_08x3R90() MPE_088(08,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_09x3R90() MPE_088(09,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_10x3R90() MPE_088(10,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_11x3R90() MPE_088(11,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_12x3R90() MPE_088(12,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_13x3R90() MPE_088(13,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_14x3R90() MPE_088(14,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_15x3R90() MPE_088(15,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_16x3R90() MPE_088(16,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_17x3R90() MPE_088(17,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_18x3R90() MPE_088(18,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_19x3R90() MPE_088(19,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_20x3R90() MPE_088(20,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_21x3R90() MPE_088(21,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_22x3R90() MPE_088(22,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_23x3R90() MPE_088(23,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_24x3R90() MPE_088(24,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_25x3R90() MPE_088(25,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_26x3R90() MPE_088(26,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_27x3R90() MPE_088(27,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_28x3R90() MPE_088(28,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_29x3R90() MPE_088(29,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_30x3R90() MPE_088(30,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_31x3R90() MPE_088(31,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_32x3R90() MPE_088(32,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_33x3R90() MPE_088(33,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_34x3R90() MPE_088(34,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_35x3R90() MPE_088(35,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_36x3R90() MPE_088(36,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_37x3R90() MPE_088(37,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_38x3R90() MPE_088(38,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_39x3R90() MPE_088(39,3,  10.00,6.10,3.30,3.90) #end
#macro CON_THT_PINHDR_MPE088_40x3R90() MPE_088(40,3,  10.00,6.10,3.30,3.90) #end

/*******************************************************************************
 * offset variants, for bugs in eagle libs
 ******************************************************************************/
#macro CON_THT_PINHDR_MPE088_03x1R90_127() CON_THT_PINHDR_MPE088_03x1R90() translate <0,0,-1.27> #end
#macro CON_THT_PINHDR_MPE088_01x1R90_381() CON_THT_PINHDR_MPE088_01x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_02x1R90_381() CON_THT_PINHDR_MPE088_02x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_03x1R90_381() CON_THT_PINHDR_MPE088_03x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_04x1R90_381() CON_THT_PINHDR_MPE088_04x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_05x1R90_381() CON_THT_PINHDR_MPE088_05x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_06x1R90_381() CON_THT_PINHDR_MPE088_06x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_07x1R90_381() CON_THT_PINHDR_MPE088_07x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_08x1R90_381() CON_THT_PINHDR_MPE088_08x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_09x1R90_381() CON_THT_PINHDR_MPE088_09x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_10x1R90_381() CON_THT_PINHDR_MPE088_10x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_11x1R90_381() CON_THT_PINHDR_MPE088_11x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_12x1R90_381() CON_THT_PINHDR_MPE088_12x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_13x1R90_381() CON_THT_PINHDR_MPE088_13x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_14x1R90_381() CON_THT_PINHDR_MPE088_14x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_15x1R90_381() CON_THT_PINHDR_MPE088_15x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_16x1R90_381() CON_THT_PINHDR_MPE088_16x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_17x1R90_381() CON_THT_PINHDR_MPE088_17x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_18x1R90_381() CON_THT_PINHDR_MPE088_18x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_19x1R90_381() CON_THT_PINHDR_MPE088_19x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_20x1R90_381() CON_THT_PINHDR_MPE088_20x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_21x1R90_381() CON_THT_PINHDR_MPE088_21x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_22x1R90_381() CON_THT_PINHDR_MPE088_22x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_23x1R90_381() CON_THT_PINHDR_MPE088_23x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_24x1R90_381() CON_THT_PINHDR_MPE088_24x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_25x1R90_381() CON_THT_PINHDR_MPE088_25x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_26x1R90_381() CON_THT_PINHDR_MPE088_26x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_27x1R90_381() CON_THT_PINHDR_MPE088_27x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_28x1R90_381() CON_THT_PINHDR_MPE088_28x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_29x1R90_381() CON_THT_PINHDR_MPE088_29x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_30x1R90_381() CON_THT_PINHDR_MPE088_30x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_31x1R90_381() CON_THT_PINHDR_MPE088_31x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_32x1R90_381() CON_THT_PINHDR_MPE088_32x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_33x1R90_381() CON_THT_PINHDR_MPE088_33x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_34x1R90_381() CON_THT_PINHDR_MPE088_34x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_35x1R90_381() CON_THT_PINHDR_MPE088_35x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_36x1R90_381() CON_THT_PINHDR_MPE088_36x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_37x1R90_381() CON_THT_PINHDR_MPE088_37x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_38x1R90_381() CON_THT_PINHDR_MPE088_38x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_39x1R90_381() CON_THT_PINHDR_MPE088_39x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_40x1R90_381() CON_THT_PINHDR_MPE088_40x1R90() translate <0,0,-3.81> #end
#macro CON_THT_PINHDR_MPE088_01x2R90_508() CON_THT_PINHDR_MPE088_01x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_02x2R90_508() CON_THT_PINHDR_MPE088_02x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_03x2R90_508() CON_THT_PINHDR_MPE088_03x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_04x2R90_508() CON_THT_PINHDR_MPE088_04x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_05x2R90_508() CON_THT_PINHDR_MPE088_05x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_06x2R90_508() CON_THT_PINHDR_MPE088_06x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_07x2R90_508() CON_THT_PINHDR_MPE088_07x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_08x2R90_508() CON_THT_PINHDR_MPE088_08x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_09x2R90_508() CON_THT_PINHDR_MPE088_09x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_10x2R90_508() CON_THT_PINHDR_MPE088_10x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_11x2R90_508() CON_THT_PINHDR_MPE088_11x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_12x2R90_508() CON_THT_PINHDR_MPE088_12x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_13x2R90_508() CON_THT_PINHDR_MPE088_13x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_14x2R90_508() CON_THT_PINHDR_MPE088_14x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_15x2R90_508() CON_THT_PINHDR_MPE088_15x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_16x2R90_508() CON_THT_PINHDR_MPE088_16x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_17x2R90_508() CON_THT_PINHDR_MPE088_17x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_18x2R90_508() CON_THT_PINHDR_MPE088_18x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_19x2R90_508() CON_THT_PINHDR_MPE088_19x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_20x2R90_508() CON_THT_PINHDR_MPE088_20x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_21x2R90_508() CON_THT_PINHDR_MPE088_21x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_22x2R90_508() CON_THT_PINHDR_MPE088_22x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_23x2R90_508() CON_THT_PINHDR_MPE088_23x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_24x2R90_508() CON_THT_PINHDR_MPE088_24x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_25x2R90_508() CON_THT_PINHDR_MPE088_25x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_26x2R90_508() CON_THT_PINHDR_MPE088_26x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_27x2R90_508() CON_THT_PINHDR_MPE088_27x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_28x2R90_508() CON_THT_PINHDR_MPE088_28x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_29x2R90_508() CON_THT_PINHDR_MPE088_29x2R90() translate <0,0,-5.08> #end
#macro CON_THT_PINHDR_MPE088_30x2R90_508() CON_THT_PINHDR_MPE088_30x2R90() translate <0,0,-5.08> #end


/*******************************************************************************
 * male header 2.00mm, 1-row, 2-row, 3-row, 4-row.
 ******************************************************************************/
#macro MPE_150(Cols,Rows,A,B,C)
  union {
     #local Grid = 2.00;
     #local L = 1.50;

     difference {
        Round_Box(
           <-Cols*Grid/2,0,-Rows*Grid/2>
           <+Cols*Grid/2,L,+Rows*Grid/2>
           0.1 0
           )
        #local X = 0.2;
        GRID (
           GRID (
              box { <-X,-0.1,-X> <+X,L+0.1,+X> rotate <0,45,0> },
              Grid,Cols+1,1
              ), Grid*Rows,1,2
           )
        box {
           <-Cols*Grid/2-0.1,-0.1,-Rows*Grid/2+X>
           <+Cols*Grid/2+0.1,L/4 ,+Rows*Grid/2-X>
           }
        pigment {
           White * 0.2
           }
        }
     GRID(object { PIN_STRAIGHT(0.50,B+L,C) texture { col_gold } },Grid,Cols,Rows)
     }
#end

/*******************************************************************************
 * male header 2.00mm, 1-row, 2-row, 3-row, 4-row.
 * - https://www.mpe-connector.de/de/produkte/
 *           stiftleisten/stiftleiste-200-mm/150-1
 *     parts 150-1, 150-2, 150-3, 150-4 (with choosen common lengths)
 ******************************************************************************/
#macro CON_THT_PINHDR_MPE150_01x1() MPE_150(01,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_02x1() MPE_150(02,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_03x1() MPE_150(03,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_04x1() MPE_150(04,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_05x1() MPE_150(05,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_06x1() MPE_150(06,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_07x1() MPE_150(07,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_08x1() MPE_150(08,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_09x1() MPE_150(09,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_10x1() MPE_150(10,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_11x1() MPE_150(11,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_12x1() MPE_150(12,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_13x1() MPE_150(13,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_14x1() MPE_150(14,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_15x1() MPE_150(15,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_16x1() MPE_150(16,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_17x1() MPE_150(17,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_18x1() MPE_150(18,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_19x1() MPE_150(19,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_20x1() MPE_150(20,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_21x1() MPE_150(21,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_22x1() MPE_150(22,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_23x1() MPE_150(23,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_24x1() MPE_150(24,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_25x1() MPE_150(25,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_26x1() MPE_150(26,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_27x1() MPE_150(27,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_28x1() MPE_150(28,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_29x1() MPE_150(29,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_30x1() MPE_150(30,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_31x1() MPE_150(31,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_32x1() MPE_150(32,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_33x1() MPE_150(33,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_34x1() MPE_150(34,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_35x1() MPE_150(35,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_36x1() MPE_150(36,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_37x1() MPE_150(37,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_38x1() MPE_150(38,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_39x1() MPE_150(39,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_40x1() MPE_150(40,1,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_01x2() MPE_150(01,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_02x2() MPE_150(02,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_03x2() MPE_150(03,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_04x2() MPE_150(04,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_05x2() MPE_150(05,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_06x2() MPE_150(06,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_07x2() MPE_150(07,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_08x2() MPE_150(08,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_09x2() MPE_150(09,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_10x2() MPE_150(10,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_11x2() MPE_150(11,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_12x2() MPE_150(12,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_13x2() MPE_150(13,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_14x2() MPE_150(14,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_15x2() MPE_150(15,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_16x2() MPE_150(16,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_17x2() MPE_150(17,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_18x2() MPE_150(18,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_19x2() MPE_150(19,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_20x2() MPE_150(20,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_21x2() MPE_150(21,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_22x2() MPE_150(22,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_23x2() MPE_150(23,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_24x2() MPE_150(24,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_25x2() MPE_150(25,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_26x2() MPE_150(26,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_27x2() MPE_150(27,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_28x2() MPE_150(28,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_29x2() MPE_150(29,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_30x2() MPE_150(30,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_31x2() MPE_150(31,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_32x2() MPE_150(32,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_33x2() MPE_150(33,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_34x2() MPE_150(34,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_35x2() MPE_150(35,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_36x2() MPE_150(36,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_37x2() MPE_150(37,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_38x2() MPE_150(38,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_39x2() MPE_150(39,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_40x2() MPE_150(40,2,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_01x3() MPE_150(01,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_02x3() MPE_150(02,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_03x3() MPE_150(03,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_04x3() MPE_150(04,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_05x3() MPE_150(05,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_06x3() MPE_150(06,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_07x3() MPE_150(07,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_08x3() MPE_150(08,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_09x3() MPE_150(09,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_10x3() MPE_150(10,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_11x3() MPE_150(11,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_12x3() MPE_150(12,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_13x3() MPE_150(13,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_14x3() MPE_150(14,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_15x3() MPE_150(15,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_16x3() MPE_150(16,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_17x3() MPE_150(17,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_18x3() MPE_150(18,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_19x3() MPE_150(19,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_20x3() MPE_150(20,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_21x3() MPE_150(21,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_22x3() MPE_150(22,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_23x3() MPE_150(23,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_24x3() MPE_150(24,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_25x3() MPE_150(25,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_26x3() MPE_150(26,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_27x3() MPE_150(27,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_28x3() MPE_150(28,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_29x3() MPE_150(29,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_30x3() MPE_150(30,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_31x3() MPE_150(31,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_32x3() MPE_150(32,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_33x3() MPE_150(33,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_34x3() MPE_150(34,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_35x3() MPE_150(35,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_36x3() MPE_150(36,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_37x3() MPE_150(37,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_38x3() MPE_150(38,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_39x3() MPE_150(39,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_40x3() MPE_150(40,3,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_01x4() MPE_150(01,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_02x4() MPE_150(02,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_03x4() MPE_150(03,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_04x4() MPE_150(04,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_05x4() MPE_150(05,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_06x4() MPE_150(06,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_07x4() MPE_150(07,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_08x4() MPE_150(08,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_09x4() MPE_150(09,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_10x4() MPE_150(10,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_11x4() MPE_150(11,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_12x4() MPE_150(12,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_13x4() MPE_150(13,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_14x4() MPE_150(14,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_15x4() MPE_150(15,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_16x4() MPE_150(16,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_17x4() MPE_150(17,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_18x4() MPE_150(18,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_19x4() MPE_150(19,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_20x4() MPE_150(20,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_21x4() MPE_150(21,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_22x4() MPE_150(22,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_23x4() MPE_150(23,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_24x4() MPE_150(24,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_25x4() MPE_150(25,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_26x4() MPE_150(26,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_27x4() MPE_150(27,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_28x4() MPE_150(28,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_29x4() MPE_150(29,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_30x4() MPE_150(30,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_31x4() MPE_150(31,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_32x4() MPE_150(32,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_33x4() MPE_150(33,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_34x4() MPE_150(34,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_35x4() MPE_150(35,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_36x4() MPE_150(36,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_37x4() MPE_150(37,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_38x4() MPE_150(38,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_39x4() MPE_150(39,4,  8.70,4.40,2.80) #end
#macro CON_THT_PINHDR_MPE150_40x4() MPE_150(40,4,  8.70,4.40,2.80) #end









/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//pinhead:1X01=CON_THT_PINHDR_MPE087_01x1(:pin header 2.54mm
//pinhead:1X02=CON_THT_PINHDR_MPE087_02x1(:pin header 2.54mm
//pinhead:1X03=CON_THT_PINHDR_MPE087_03x1(:pin header 2.54mm
//pinhead:1X04=CON_THT_PINHDR_MPE087_04x1(:pin header 2.54mm
//pinhead:1X05=CON_THT_PINHDR_MPE087_05x1(:pin header 2.54mm
//pinhead:1X06=CON_THT_PINHDR_MPE087_06x1(:pin header 2.54mm
//pinhead:1X07=CON_THT_PINHDR_MPE087_07x1(:pin header 2.54mm
//pinhead:1X08=CON_THT_PINHDR_MPE087_08x1(:pin header 2.54mm
//pinhead:1X09=CON_THT_PINHDR_MPE087_09x1(:pin header 2.54mm
//pinhead:1X10=CON_THT_PINHDR_MPE087_10x1(:pin header 2.54mm
//pinhead:1X11=CON_THT_PINHDR_MPE087_11x1(:pin header 2.54mm
//pinhead:1X12=CON_THT_PINHDR_MPE087_12x1(:pin header 2.54mm
//pinhead:1X13=CON_THT_PINHDR_MPE087_13x1(:pin header 2.54mm
//pinhead:1X14=CON_THT_PINHDR_MPE087_14x1(:pin header 2.54mm
//pinhead:1X15=CON_THT_PINHDR_MPE087_15x1(:pin header 2.54mm
//pinhead:1X16=CON_THT_PINHDR_MPE087_16x1(:pin header 2.54mm
//pinhead:1X17=CON_THT_PINHDR_MPE087_17x1(:pin header 2.54mm
//pinhead:1X18=CON_THT_PINHDR_MPE087_18x1(:pin header 2.54mm
//pinhead:1X19=CON_THT_PINHDR_MPE087_19x1(:pin header 2.54mm
//pinhead:1X20=CON_THT_PINHDR_MPE087_20x1(:pin header 2.54mm
//pinhead:1X21=CON_THT_PINHDR_MPE087_21x1(:pin header 2.54mm
//pinhead:1X22=CON_THT_PINHDR_MPE087_22x1(:pin header 2.54mm
//pinhead:1X23=CON_THT_PINHDR_MPE087_23x1(:pin header 2.54mm
//pinhead:1X24=CON_THT_PINHDR_MPE087_24x1(:pin header 2.54mm
//pinhead:1X25=CON_THT_PINHDR_MPE087_25x1(:pin header 2.54mm
//pinhead:1X26=CON_THT_PINHDR_MPE087_26x1(:pin header 2.54mm
//pinhead:1X27=CON_THT_PINHDR_MPE087_27x1(:pin header 2.54mm
//pinhead:1X28=CON_THT_PINHDR_MPE087_28x1(:pin header 2.54mm
//pinhead:1X29=CON_THT_PINHDR_MPE087_29x1(:pin header 2.54mm
//pinhead:1X30=CON_THT_PINHDR_MPE087_30x1(:pin header 2.54mm
//pinhead:1X31=CON_THT_PINHDR_MPE087_31x1(:pin header 2.54mm
//pinhead:1X32=CON_THT_PINHDR_MPE087_32x1(:pin header 2.54mm
//pinhead:1X33=CON_THT_PINHDR_MPE087_33x1(:pin header 2.54mm
//pinhead:1X34=CON_THT_PINHDR_MPE087_34x1(:pin header 2.54mm
//pinhead:1X35=CON_THT_PINHDR_MPE087_35x1(:pin header 2.54mm
//pinhead:1X36=CON_THT_PINHDR_MPE087_36x1(:pin header 2.54mm
//pinhead:1X37=CON_THT_PINHDR_MPE087_37x1(:pin header 2.54mm
//pinhead:1X38=CON_THT_PINHDR_MPE087_38x1(:pin header 2.54mm
//pinhead:1X39=CON_THT_PINHDR_MPE087_39x1(:pin header 2.54mm
//pinhead:1X40=CON_THT_PINHDR_MPE087_40x1(:pin header 2.54mm
//pinhead:2x01=CON_THT_PINHDR_MPE087_01x2(:pin header 2.54mm 2-row
//pinhead:2X02=CON_THT_PINHDR_MPE087_02x2(:pin header 2.54mm 2-row
//pinhead:2X03=CON_THT_PINHDR_MPE087_03x2(:pin header 2.54mm 2-row
//pinhead:2X04=CON_THT_PINHDR_MPE087_04x2(:pin header 2.54mm 2-row
//pinhead:2X05=CON_THT_PINHDR_MPE087_05x2(:pin header 2.54mm 2-row
//pinhead:2X06=CON_THT_PINHDR_MPE087_06x2(:pin header 2.54mm 2-row
//pinhead:2X07=CON_THT_PINHDR_MPE087_07x2(:pin header 2.54mm 2-row
//pinhead:2X08=CON_THT_PINHDR_MPE087_08x2(:pin header 2.54mm 2-row
//pinhead:2X09=CON_THT_PINHDR_MPE087_09x2(:pin header 2.54mm 2-row
//pinhead:2X10=CON_THT_PINHDR_MPE087_10x2(:pin header 2.54mm 2-row
//pinhead:2X11=CON_THT_PINHDR_MPE087_11x2(:pin header 2.54mm 2-row
//pinhead:2X12=CON_THT_PINHDR_MPE087_12x2(:pin header 2.54mm 2-row
//pinhead:2X13=CON_THT_PINHDR_MPE087_13x2(:pin header 2.54mm 2-row
//pinhead:2X14=CON_THT_PINHDR_MPE087_14x2(:pin header 2.54mm 2-row
//pinhead:2X15=CON_THT_PINHDR_MPE087_15x2(:pin header 2.54mm 2-row
//pinhead:2X16=CON_THT_PINHDR_MPE087_16x2(:pin header 2.54mm 2-row
//pinhead:2X17=CON_THT_PINHDR_MPE087_17x2(:pin header 2.54mm 2-row
//pinhead:2X18=CON_THT_PINHDR_MPE087_18x2(:pin header 2.54mm 2-row
//pinhead:2X19=CON_THT_PINHDR_MPE087_19x2(:pin header 2.54mm 2-row
//pinhead:2X20=CON_THT_PINHDR_MPE087_20x2(:pin header 2.54mm 2-row
//pinhead:2X21=CON_THT_PINHDR_MPE087_21x2(:pin header 2.54mm 2-row
//pinhead:2X22=CON_THT_PINHDR_MPE087_22x2(:pin header 2.54mm 2-row
//pinhead:2X23=CON_THT_PINHDR_MPE087_23x2(:pin header 2.54mm 2-row
//pinhead:2X24=CON_THT_PINHDR_MPE087_24x2(:pin header 2.54mm 2-row
//pinhead:2X25=CON_THT_PINHDR_MPE087_25x2(:pin header 2.54mm 2-row
//pinhead:2X26=CON_THT_PINHDR_MPE087_26x2(:pin header 2.54mm 2-row
//pinhead:2X27=CON_THT_PINHDR_MPE087_27x2(:pin header 2.54mm 2-row
//pinhead:2X28=CON_THT_PINHDR_MPE087_28x2(:pin header 2.54mm 2-row
//pinhead:2X29=CON_THT_PINHDR_MPE087_29x2(:pin header 2.54mm 2-row
//pinhead:2X30=CON_THT_PINHDR_MPE087_30x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_31x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_32x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_33x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_34x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_35x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_36x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_37x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_38x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_39x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_40x2(:pin header 2.54mm 2-row
//=CON_THT_PINHDR_MPE087_01x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_02x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_03x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_04x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_05x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_06x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_07x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_08x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_09x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_10x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_11x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_12x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_13x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_14x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_15x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_16x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_17x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_18x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_19x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_20x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_21x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_22x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_23x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_24x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_25x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_26x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_27x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_28x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_29x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_30x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_31x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_32x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_33x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_34x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_35x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_36x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_37x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_38x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_39x3(:pin header 2.54mm 3-row
//=CON_THT_PINHDR_MPE087_40x3(:pin header 2.54mm 3-row
//con-lstb:MA03-1=CON_THT_PINHDR_MPE087_03x1(:pin header 2.54mm
//con-lstb:MA04-1=CON_THT_PINHDR_MPE087_04x1(:pin header 2.54mm
//con-lstb:MA05-1=CON_THT_PINHDR_MPE087_05x1(:pin header 2.54mm
//con-lstb:MA06-1=CON_THT_PINHDR_MPE087_06x1(:pin header 2.54mm
//con-lstb:MA07-1=CON_THT_PINHDR_MPE087_07x1(:pin header 2.54mm
//con-lstb:MA08-1=CON_THT_PINHDR_MPE087_08x1(:pin header 2.54mm
//con-lstb:MA09-1=CON_THT_PINHDR_MPE087_09x1(:pin header 2.54mm
//con-lstb:MA10-1=CON_THT_PINHDR_MPE087_10x1(:pin header 2.54mm
//con-lstb:MA11-1=CON_THT_PINHDR_MPE087_11x1(:pin header 2.54mm
//con-lstb:MA12-1=CON_THT_PINHDR_MPE087_12x1(:pin header 2.54mm
//con-lstb:MA13-1=CON_THT_PINHDR_MPE087_13x1(:pin header 2.54mm
//con-lstb:MA14-1=CON_THT_PINHDR_MPE087_14x1(:pin header 2.54mm
//con-lstb:MA15-1=CON_THT_PINHDR_MPE087_15x1(:pin header 2.54mm
//con-lstb:MA16-1=CON_THT_PINHDR_MPE087_16x1(:pin header 2.54mm
//con-lstb:MA17-1=CON_THT_PINHDR_MPE087_17x1(:pin header 2.54mm
//con-lstb:MA18-1=CON_THT_PINHDR_MPE087_18x1(:pin header 2.54mm
//con-lstb:MA19-1=CON_THT_PINHDR_MPE087_19x1(:pin header 2.54mm
//con-lstb:MA20-1=CON_THT_PINHDR_MPE087_20x1(:pin header 2.54mm
//con-lstb:MA03-2=CON_THT_PINHDR_MPE087_03x2(:pin header 2.54mm 2-row
//con-lstb:MA04-2=CON_THT_PINHDR_MPE087_04x2(:pin header 2.54mm 2-row
//con-lstb:MA05-2=CON_THT_PINHDR_MPE087_05x2(:pin header 2.54mm 2-row
//con-lstb:MA06-2=CON_THT_PINHDR_MPE087_06x2(:pin header 2.54mm 2-row
//con-lstb:MA07-2=CON_THT_PINHDR_MPE087_07x2(:pin header 2.54mm 2-row
//con-lstb:MA08-2=CON_THT_PINHDR_MPE087_08x2(:pin header 2.54mm 2-row
//con-lstb:MA09-2=CON_THT_PINHDR_MPE087_09x2(:pin header 2.54mm 2-row
//con-lstb:MA10-2=CON_THT_PINHDR_MPE087_10x2(:pin header 2.54mm 2-row
//con-lstb:MA11-2=CON_THT_PINHDR_MPE087_11x2(:pin header 2.54mm 2-row
//con-lstb:MA12-2=CON_THT_PINHDR_MPE087_12x2(:pin header 2.54mm 2-row
//con-lstb:MA13-2=CON_THT_PINHDR_MPE087_13x2(:pin header 2.54mm 2-row
//con-lstb:MA14-2=CON_THT_PINHDR_MPE087_14x2(:pin header 2.54mm 2-row
//con-lstb:MA15-2=CON_THT_PINHDR_MPE087_15x2(:pin header 2.54mm 2-row
//con-lstb:MA16-2=CON_THT_PINHDR_MPE087_16x2(:pin header 2.54mm 2-row
//con-lstb:MA17-2=CON_THT_PINHDR_MPE087_17x2(:pin header 2.54mm 2-row
//con-lstb:MA18-2=CON_THT_PINHDR_MPE087_18x2(:pin header 2.54mm 2-row
//con-lstb:MA19-2=CON_THT_PINHDR_MPE087_19x2(:pin header 2.54mm 2-row
//con-lstb:MA20-2=CON_THT_PINHDR_MPE087_20x2(:pin header 2.54mm 2-row
//jumper:JP1=CON_THT_PINHDR_MPE087_01x2(:pin header 2.54mm 2-row
//jumper:JP2Q=CON_THT_PINHDR_MPE087_02x2(:pin header 2.54mm 2-row
//jumper:JP3Q=CON_THT_PINHDR_MPE087_03x2(:pin header 2.54mm 2-row
//jumper:JP4Q=CON_THT_PINHDR_MPE087_04x2(:pin header 2.54mm 2-row
//jumper:JP5Q=CON_THT_PINHDR_MPE087_05x2(:pin header 2.54mm 2-row
//jumper:JP6Q=CON_THT_PINHDR_MPE087_06x2(:pin header 2.54mm 2-row
//jumper:JP7Q=CON_THT_PINHDR_MPE087_07x2(:pin header 2.54mm 2-row
//jumper:JP8Q=CON_THT_PINHDR_MPE087_08x2(:pin header 2.54mm 2-row
//jumper:JP9Q=CON_THT_PINHDR_MPE087_09x2(:pin header 2.54mm 2-row
//jumper:JP10Q=CON_THT_PINHDR_MPE087_10x2(:pin header 2.54mm 2-row
//jumper:JP2=CON_THT_PINHDR_MPE087_03x1(:pin header 2.54mm
//jumper:JP4=CON_THT_PINHDR_MPE087_04x1(:pin header 2.54mm
//pinhead:1X01/90=CON_THT_PINHDR_MPE088_01x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X02/90=CON_THT_PINHDR_MPE088_02x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X03/90=CON_THT_PINHDR_MPE088_03x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X04/90=CON_THT_PINHDR_MPE088_04x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X05/90=CON_THT_PINHDR_MPE088_05x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X06/90=CON_THT_PINHDR_MPE088_06x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X07/90=CON_THT_PINHDR_MPE088_07x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X08/90=CON_THT_PINHDR_MPE088_08x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X09/90=CON_THT_PINHDR_MPE088_09x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X10/90=CON_THT_PINHDR_MPE088_10x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X11/90=CON_THT_PINHDR_MPE088_11x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X12/90=CON_THT_PINHDR_MPE088_12x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X13/90=CON_THT_PINHDR_MPE088_13x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X14/90=CON_THT_PINHDR_MPE088_14x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X15/90=CON_THT_PINHDR_MPE088_15x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X16/90=CON_THT_PINHDR_MPE088_16x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X17/90=CON_THT_PINHDR_MPE088_17x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X18/90=CON_THT_PINHDR_MPE088_18x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X19/90=CON_THT_PINHDR_MPE088_19x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X20/90=CON_THT_PINHDR_MPE088_20x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X21/90=CON_THT_PINHDR_MPE088_21x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X22/90=CON_THT_PINHDR_MPE088_22x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X23/90=CON_THT_PINHDR_MPE088_23x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X24/90=CON_THT_PINHDR_MPE088_24x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X25/90=CON_THT_PINHDR_MPE088_25x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X26/90=CON_THT_PINHDR_MPE088_26x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X27/90=CON_THT_PINHDR_MPE088_27x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X28/90=CON_THT_PINHDR_MPE088_28x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X29/90=CON_THT_PINHDR_MPE088_29x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X30/90=CON_THT_PINHDR_MPE088_30x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X31/90=CON_THT_PINHDR_MPE088_31x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X32/90=CON_THT_PINHDR_MPE088_32x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X33/90=CON_THT_PINHDR_MPE088_33x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X34/90=CON_THT_PINHDR_MPE088_34x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X35/90=CON_THT_PINHDR_MPE088_35x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X36/90=CON_THT_PINHDR_MPE088_36x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X37/90=CON_THT_PINHDR_MPE088_37x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X38/90=CON_THT_PINHDR_MPE088_38x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X39/90=CON_THT_PINHDR_MPE088_39x1R90_381(:pin header 2.54mm 90deg
//pinhead:1X40/90=CON_THT_PINHDR_MPE088_40x1R90_381(:pin header 2.54mm 90deg
//pinhead:2X01/90=CON_THT_PINHDR_MPE088_01x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X02/90=CON_THT_PINHDR_MPE088_02x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X03/90=CON_THT_PINHDR_MPE088_03x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X04/90=CON_THT_PINHDR_MPE088_04x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X05/90=CON_THT_PINHDR_MPE088_05x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X06/90=CON_THT_PINHDR_MPE088_06x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X07/90=CON_THT_PINHDR_MPE088_07x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X08/90=CON_THT_PINHDR_MPE088_08x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X09/90=CON_THT_PINHDR_MPE088_09x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X10/90=CON_THT_PINHDR_MPE088_10x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X11/90=CON_THT_PINHDR_MPE088_11x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X12/90=CON_THT_PINHDR_MPE088_12x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X13/90=CON_THT_PINHDR_MPE088_13x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X14/90=CON_THT_PINHDR_MPE088_14x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X15/90=CON_THT_PINHDR_MPE088_15x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X16/90=CON_THT_PINHDR_MPE088_16x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X17/90=CON_THT_PINHDR_MPE088_17x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X18/90=CON_THT_PINHDR_MPE088_18x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X19/90=CON_THT_PINHDR_MPE088_19x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X20/90=CON_THT_PINHDR_MPE088_20x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X21/90=CON_THT_PINHDR_MPE088_21x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X22/90=CON_THT_PINHDR_MPE088_22x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X23/90=CON_THT_PINHDR_MPE088_23x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X24/90=CON_THT_PINHDR_MPE088_24x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X25/90=CON_THT_PINHDR_MPE088_25x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X26/90=CON_THT_PINHDR_MPE088_26x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X27/90=CON_THT_PINHDR_MPE088_27x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X28/90=CON_THT_PINHDR_MPE088_28x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X29/90=CON_THT_PINHDR_MPE088_29x2R90_508(:pin header 2.54mm 2-row 90deg
//pinhead:2X30/90=CON_THT_PINHDR_MPE088_30x2R90_508(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_31x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_32x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_33x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_34x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_35x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_36x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_37x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_38x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_39x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_40x2R90(:pin header 2.54mm 2-row 90deg
//=CON_THT_PINHDR_MPE088_01x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_02x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_03x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_04x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_05x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_06x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_07x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_08x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_09x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_10x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_11x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_12x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_13x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_14x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_15x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_16x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_17x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_18x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_19x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_20x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_21x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_22x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_23x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_24x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_25x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_26x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_27x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_28x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_29x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_30x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_31x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_32x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_33x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_34x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_35x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_36x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_37x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_38x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_39x3R90(:pin header 2.54mm 3-row 90deg
//=CON_THT_PINHDR_MPE088_40x3R90(:pin header 2.54mm 3-row 90deg
//con-lstb:MA03-1W=CON_THT_PINHDR_MPE088_03x1R90(:pin header 2.54mm 90deg
//con-lstb:MA04-1W=CON_THT_PINHDR_MPE088_04x1R90(:pin header 2.54mm 90deg
//con-lstb:MA05-1W=CON_THT_PINHDR_MPE088_05x1R90(:pin header 2.54mm 90deg
//con-lstb:MA06-1W=CON_THT_PINHDR_MPE088_06x1R90(:pin header 2.54mm 90deg
//con-lstb:MA07-1W=CON_THT_PINHDR_MPE088_07x1R90(:pin header 2.54mm 90deg
//con-lstb:MA08-1W=CON_THT_PINHDR_MPE088_08x1R90(:pin header 2.54mm 90deg
//con-lstb:MA09-1W=CON_THT_PINHDR_MPE088_09x1R90(:pin header 2.54mm 90deg
//con-lstb:MA10-1W=CON_THT_PINHDR_MPE088_10x1R90(:pin header 2.54mm 90deg
//con-lstb:MA11-1W=CON_THT_PINHDR_MPE088_11x1R90(:pin header 2.54mm 90deg
//con-lstb:MA12-1W=CON_THT_PINHDR_MPE088_12x1R90(:pin header 2.54mm 90deg
//con-lstb:MA13-1W=CON_THT_PINHDR_MPE088_13x1R90(:pin header 2.54mm 90deg
//con-lstb:MA14-1W=CON_THT_PINHDR_MPE088_14x1R90(:pin header 2.54mm 90deg
//con-lstb:MA15-1W=CON_THT_PINHDR_MPE088_15x1R90(:pin header 2.54mm 90deg
//con-lstb:MA16-1W=CON_THT_PINHDR_MPE088_16x1R90(:pin header 2.54mm 90deg
//con-lstb:MA17-1W=CON_THT_PINHDR_MPE088_17x1R90(:pin header 2.54mm 90deg
//con-lstb:MA18-1W=CON_THT_PINHDR_MPE088_18x1R90(:pin header 2.54mm 90deg
//con-lstb:MA19-1W=CON_THT_PINHDR_MPE088_19x1R90(:pin header 2.54mm 90deg
//con-lstb:MA20-1W=CON_THT_PINHDR_MPE088_20x1R90(:pin header 2.54mm 90deg
//con-lstb:MA03-2W=CON_THT_PINHDR_MPE088_03x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA04-2W=CON_THT_PINHDR_MPE088_04x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA05-2W=CON_THT_PINHDR_MPE088_05x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA06-2W=CON_THT_PINHDR_MPE088_06x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA07-2W=CON_THT_PINHDR_MPE088_07x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA08-2W=CON_THT_PINHDR_MPE088_08x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA09-2W=CON_THT_PINHDR_MPE088_09x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA10-2W=CON_THT_PINHDR_MPE088_10x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA11-2W=CON_THT_PINHDR_MPE088_11x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA12-2W=CON_THT_PINHDR_MPE088_12x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA13-2W=CON_THT_PINHDR_MPE088_13x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA14-2W=CON_THT_PINHDR_MPE088_14x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA15-2W=CON_THT_PINHDR_MPE088_15x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA16-2W=CON_THT_PINHDR_MPE088_16x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA17-2W=CON_THT_PINHDR_MPE088_17x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA18-2W=CON_THT_PINHDR_MPE088_18x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA19-2W=CON_THT_PINHDR_MPE088_19x2R90(:pin header 2.54mm 2-row 90deg
//con-lstb:MA20-2W=CON_THT_PINHDR_MPE088_20x2R90(:pin header 2.54mm 2-row 90deg
//jumper:JP2W=CON_THT_PINHDR_MPE088_03x1R90_127(:pin header 2.54mm 90deg
//=CON_THT_PINHDR_MPE150_01x1(:pin header 2.00mm
//con-pinheader-standard:STD020M02X1-2.00=CON_THT_PINHDR_MPE150_02x1(:pin header 2.00mm
//con-pinheader-standard:STD020M03X1-2.00=CON_THT_PINHDR_MPE150_03x1(:pin header 2.00mm
//con-pinheader-standard:STD020M04X1-2.00=CON_THT_PINHDR_MPE150_04x1(:pin header 2.00mm
//con-pinheader-standard:STD020M05X1-2.00=CON_THT_PINHDR_MPE150_05x1(:pin header 2.00mm
//con-pinheader-standard:STD020M06X1-2.00=CON_THT_PINHDR_MPE150_06x1(:pin header 2.00mm
//con-pinheader-standard:STD020M07X1-2.00=CON_THT_PINHDR_MPE150_07x1(:pin header 2.00mm
//con-pinheader-standard:STD020M08X1-2.00=CON_THT_PINHDR_MPE150_08x1(:pin header 2.00mm
//con-pinheader-standard:STD020M09X1-2.00=CON_THT_PINHDR_MPE150_09x1(:pin header 2.00mm
//con-pinheader-standard:STD020M10X1-2.00=CON_THT_PINHDR_MPE150_10x1(:pin header 2.00mm
//con-pinheader-standard:STD020M11X1-2.00=CON_THT_PINHDR_MPE150_11x1(:pin header 2.00mm
//con-pinheader-standard:STD020M12X1-2.00=CON_THT_PINHDR_MPE150_12x1(:pin header 2.00mm
//con-pinheader-standard:STD020M13X1-2.00=CON_THT_PINHDR_MPE150_13x1(:pin header 2.00mm
//con-pinheader-standard:STD020M14X1-2.00=CON_THT_PINHDR_MPE150_14x1(:pin header 2.00mm
//con-pinheader-standard:STD020M15X1-2.00=CON_THT_PINHDR_MPE150_15x1(:pin header 2.00mm
//con-pinheader-standard:STD020M16X1-2.00=CON_THT_PINHDR_MPE150_16x1(:pin header 2.00mm
//con-pinheader-standard:STD020M17X1-2.00=CON_THT_PINHDR_MPE150_17x1(:pin header 2.00mm
//con-pinheader-standard:STD020M18X1-2.00=CON_THT_PINHDR_MPE150_18x1(:pin header 2.00mm
//con-pinheader-standard:STD020M19X1-2.00=CON_THT_PINHDR_MPE150_19x1(:pin header 2.00mm
//con-pinheader-standard:STD020M20X1-2.00=CON_THT_PINHDR_MPE150_20x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_21x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_22x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_23x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_24x1(:pin header 2.00mm
//con-pinheader-standard:STD020M25X1-2.00=CON_THT_PINHDR_MPE150_25x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_26x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_27x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_28x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_29x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_30x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_31x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_32x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_33x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_34x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_35x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_36x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_37x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_38x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_39x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_40x1(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_01x2(:pin header 2.00mm
//con-pinheader-standard:STD020M02X2-2.00=CON_THT_PINHDR_MPE150_02x2(:pin header 2.00mm
//con-pinheader-standard:STD020M03X2-2.00=CON_THT_PINHDR_MPE150_03x2(:pin header 2.00mm
//con-pinheader-standard:STD020M04X2-2.00=CON_THT_PINHDR_MPE150_04x2(:pin header 2.00mm
//con-pinheader-standard:STD020M05X2-2.00=CON_THT_PINHDR_MPE150_05x2(:pin header 2.00mm
//con-pinheader-standard:STD020M06X2-2.00=CON_THT_PINHDR_MPE150_06x2(:pin header 2.00mm
//con-pinheader-standard:STD020M07X2-2.00=CON_THT_PINHDR_MPE150_07x2(:pin header 2.00mm
//con-pinheader-standard:STD020M08X2-2.00=CON_THT_PINHDR_MPE150_08x2(:pin header 2.00mm
//con-pinheader-standard:STD020M09X2-2.00=CON_THT_PINHDR_MPE150_09x2(:pin header 2.00mm
//con-pinheader-standard:STD020M10X2-2.00=CON_THT_PINHDR_MPE150_10x2(:pin header 2.00mm
//con-pinheader-standard:STD020M11X2-2.00=CON_THT_PINHDR_MPE150_11x2(:pin header 2.00mm
//con-pinheader-standard:STD020M12X2-2.00=CON_THT_PINHDR_MPE150_12x2(:pin header 2.00mm
//con-pinheader-standard:STD020M13X2-2.00=CON_THT_PINHDR_MPE150_13x2(:pin header 2.00mm
//con-pinheader-standard:STD020M14X2-2.00=CON_THT_PINHDR_MPE150_14x2(:pin header 2.00mm
//con-pinheader-standard:STD020M15X2-2.00=CON_THT_PINHDR_MPE150_15x2(:pin header 2.00mm
//con-pinheader-standard:STD020M16X2-2.00=CON_THT_PINHDR_MPE150_16x2(:pin header 2.00mm
//con-pinheader-standard:STD020M17X2-2.00=CON_THT_PINHDR_MPE150_17x2(:pin header 2.00mm
//con-pinheader-standard:STD020M18X2-2.00=CON_THT_PINHDR_MPE150_18x2(:pin header 2.00mm
//con-pinheader-standard:STD020M19X2-2.00=CON_THT_PINHDR_MPE150_19x2(:pin header 2.00mm
//con-pinheader-standard:STD020M20X2-2.00=CON_THT_PINHDR_MPE150_20x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_21x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_22x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_23x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_24x2(:pin header 2.00mm
//STD020M25X1-2.00=CON_THT_PINHDR_MPE150_25x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_26x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_27x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_28x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_29x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_30x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_31x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_32x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_33x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_34x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_35x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_36x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_37x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_38x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_39x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_40x2(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_01x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_02x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_03x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_04x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_05x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_06x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_07x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_08x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_09x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_10x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_11x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_12x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_13x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_14x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_15x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_16x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_17x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_18x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_19x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_20x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_21x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_22x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_23x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_24x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_25x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_26x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_27x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_28x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_29x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_30x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_31x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_32x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_33x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_34x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_35x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_36x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_37x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_38x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_39x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_40x3(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_01x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_02x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_03x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_04x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_05x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_06x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_07x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_08x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_09x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_10x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_11x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_12x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_13x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_14x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_15x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_16x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_17x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_18x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_19x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_20x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_21x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_22x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_23x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_24x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_25x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_26x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_27x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_28x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_29x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_30x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_31x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_32x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_33x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_34x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_35x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_36x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_37x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_38x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_39x4(:pin header 2.00mm
//=CON_THT_PINHDR_MPE150_40x4(:pin header 2.00mm
// end assignment
