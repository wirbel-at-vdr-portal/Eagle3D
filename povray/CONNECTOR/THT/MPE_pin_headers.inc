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
     #local CircuitSize = Cols * Rows;

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
     GRID(object { PIN_STRAIGHT(0.64,B+L,C) texture { col_tin } },Grid,Cols,Rows)
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
 * no typos below please.
 ******************************************************************************/
// begin assignment
//pinheader:1X01=CON_THT_PINHDR_MPE087_01x1(:pin header 2.54mm
//pinheader:1X02=CON_THT_PINHDR_MPE087_02x1(:pin header 2.54mm
//pinheader:1X03=CON_THT_PINHDR_MPE087_03x1(:pin header 2.54mm
//pinheader:1X04=CON_THT_PINHDR_MPE087_04x1(:pin header 2.54mm
//pinheader:1X05=CON_THT_PINHDR_MPE087_05x1(:pin header 2.54mm
//pinheader:1X06=CON_THT_PINHDR_MPE087_06x1(:pin header 2.54mm
//pinheader:1X07=CON_THT_PINHDR_MPE087_07x1(:pin header 2.54mm
//pinheader:1X08=CON_THT_PINHDR_MPE087_08x1(:pin header 2.54mm
//pinheader:1X09=CON_THT_PINHDR_MPE087_09x1(:pin header 2.54mm
//pinheader:1X10=CON_THT_PINHDR_MPE087_10x1(:pin header 2.54mm
//pinheader:1X11=CON_THT_PINHDR_MPE087_11x1(:pin header 2.54mm
//pinheader:1X12=CON_THT_PINHDR_MPE087_12x1(:pin header 2.54mm
//pinheader:1X13=CON_THT_PINHDR_MPE087_13x1(:pin header 2.54mm
//pinheader:1X14=CON_THT_PINHDR_MPE087_14x1(:pin header 2.54mm
//pinheader:1X15=CON_THT_PINHDR_MPE087_15x1(:pin header 2.54mm
//pinheader:1X16=CON_THT_PINHDR_MPE087_16x1(:pin header 2.54mm
//pinheader:1X17=CON_THT_PINHDR_MPE087_17x1(:pin header 2.54mm
//pinheader:1X18=CON_THT_PINHDR_MPE087_18x1(:pin header 2.54mm
//pinheader:1X19=CON_THT_PINHDR_MPE087_19x1(:pin header 2.54mm
//pinheader:1X20=CON_THT_PINHDR_MPE087_20x1(:pin header 2.54mm
//pinheader:1X21=CON_THT_PINHDR_MPE087_21x1(:pin header 2.54mm
//pinheader:1X22=CON_THT_PINHDR_MPE087_22x1(:pin header 2.54mm
//pinheader:1X23=CON_THT_PINHDR_MPE087_23x1(:pin header 2.54mm
//pinheader:1X24=CON_THT_PINHDR_MPE087_24x1(:pin header 2.54mm
//pinheader:1X25=CON_THT_PINHDR_MPE087_25x1(:pin header 2.54mm
//pinheader:1X26=CON_THT_PINHDR_MPE087_26x1(:pin header 2.54mm
//pinheader:1X27=CON_THT_PINHDR_MPE087_27x1(:pin header 2.54mm
//pinheader:1X28=CON_THT_PINHDR_MPE087_28x1(:pin header 2.54mm
//pinheader:1X29=CON_THT_PINHDR_MPE087_29x1(:pin header 2.54mm
//pinheader:1X30=CON_THT_PINHDR_MPE087_30x1(:pin header 2.54mm
//pinheader:1X31=CON_THT_PINHDR_MPE087_31x1(:pin header 2.54mm
//pinheader:1X32=CON_THT_PINHDR_MPE087_32x1(:pin header 2.54mm
//pinheader:1X33=CON_THT_PINHDR_MPE087_33x1(:pin header 2.54mm
//pinheader:1X34=CON_THT_PINHDR_MPE087_34x1(:pin header 2.54mm
//pinheader:1X35=CON_THT_PINHDR_MPE087_35x1(:pin header 2.54mm
//pinheader:1X36=CON_THT_PINHDR_MPE087_36x1(:pin header 2.54mm
//pinheader:1X37=CON_THT_PINHDR_MPE087_37x1(:pin header 2.54mm
//pinheader:1X38=CON_THT_PINHDR_MPE087_38x1(:pin header 2.54mm
//pinheader:1X39=CON_THT_PINHDR_MPE087_39x1(:pin header 2.54mm
//pinheader:1X40=CON_THT_PINHDR_MPE087_40x1(:pin header 2.54mm
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



// end assignment
