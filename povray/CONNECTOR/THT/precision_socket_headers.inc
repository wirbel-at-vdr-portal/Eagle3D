/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * precision female header 2.54mm grid, 90deg 7.0mm long
 * drawing: w+p WP154-010-2-50-00_DB-DE.pdf
 * 29.05.2023, -wk
 ******************************************************************************/
#macro Precision_7mm_R90(CircuitSize, Rows, Grid)
  union {
     #local Cols = CircuitSize/Rows;
     union {
        object {
           GRID(PrecisionContactFemale(1.0,6.5),Grid,Cols,Rows)
           translate <0,-2.9,0>
           }
        difference {
           Round_Box (
              <-Cols*Grid/2,-7/2,-Rows*Grid/2>
              <+Cols*Grid/2,+7/2,+Rows*Grid/2>
              0.2 0
              )
           box {
              <-Cols*Grid/2-0.1,-7/2-0.1,-Rows*Grid/2+0.37>
              <+Cols*Grid/2+0.1,-7/2+0.5,+Rows*Grid/2-0.37>
              }
           box {
              <-Cols*Grid/2-0.1,-0.5,-0.5>
              <+Cols*Grid/2+0.1,+0.5,+0.5>
              rotate <+45,0,0>
              translate <0,-7/2-0.25,+Rows*Grid/2-0.5>
              }
           box {
              <-Cols*Grid/2-0.1,-0.5,-0.5>
              <+Cols*Grid/2+0.1,+0.5,+0.5>
              rotate <-45,0,0>
              translate <0,-7/2-0.25,-Rows*Grid/2+0.5>
              }
           GRID(cylinder { <0,-7.1/2,0> <0,+7.1/2,0> 1.5/2},Grid,Cols,Rows)
           #local X = 0.3;
           GRID (
              GRID (
                 box { <-X,-7.1/2-0.1,-X> <+X,+7.1/2+0.1,+X> rotate <0,45,0> },
                 Grid,Cols+1,1
                 ), Grid*Rows,1,2
              )
           }
        rotate <90,0,0>
        translate <0,Rows/2*Grid,Rows*Grid/2+3.5>
        texture {
           pigment {
              White * 0.2
              }
           }
        }
     GRID(
        object {
           BENT_WIRE_OUTER(1.9,3.5,0.6,0.8,90)
           texture {
              col_gold
              }
           rotate <180,-90,0>
           translate <0,Grid/2+0.6/2,-0.6/2+(Rows-1)*Grid/2>
           },
        Grid,Cols,1)
     #if (Rows > 1)
        GRID(
           union {
              BENT_WIRE_OUTER(1.9+Grid,Grid,0.7,1.5,90)
              cylinder {
                 <0,-7.2,-Grid/2+0.9> <0,-3,-Grid/2+0.9> 0.6/2
                 rotate <-180,90,0>
                 }
              texture {
                 col_gold
                 }
              rotate <180,-90,0>
              translate <0,1.5*Grid+0.6/2,-0.6/2-Grid/2>
              },
           Grid,Cols,1)
     #end
     }
#end

#macro CON_THT_SOCKET_Precision_7mm_R90_1x02_254() Precision_7mm_R90(02,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x03_254() Precision_7mm_R90(03,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x04_254() Precision_7mm_R90(04,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x05_254() Precision_7mm_R90(05,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x06_254() Precision_7mm_R90(06,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x07_254() Precision_7mm_R90(07,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x08_254() Precision_7mm_R90(08,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x09_254() Precision_7mm_R90(09,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x10_254() Precision_7mm_R90(10,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x11_254() Precision_7mm_R90(11,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x12_254() Precision_7mm_R90(12,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x13_254() Precision_7mm_R90(13,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x14_254() Precision_7mm_R90(14,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x15_254() Precision_7mm_R90(15,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x16_254() Precision_7mm_R90(16,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x17_254() Precision_7mm_R90(17,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x18_254() Precision_7mm_R90(18,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x19_254() Precision_7mm_R90(19,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x20_254() Precision_7mm_R90(20,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_1x25_254() Precision_7mm_R90(25,1,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x02_254() Precision_7mm_R90(04,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x03_254() Precision_7mm_R90(06,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x04_254() Precision_7mm_R90(08,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x05_254() Precision_7mm_R90(10,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x06_254() Precision_7mm_R90(12,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x07_254() Precision_7mm_R90(14,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x08_254() Precision_7mm_R90(16,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x09_254() Precision_7mm_R90(18,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x10_254() Precision_7mm_R90(20,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x11_254() Precision_7mm_R90(22,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x12_254() Precision_7mm_R90(24,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x13_254() Precision_7mm_R90(26,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x14_254() Precision_7mm_R90(28,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x15_254() Precision_7mm_R90(30,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x16_254() Precision_7mm_R90(32,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x17_254() Precision_7mm_R90(34,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x18_254() Precision_7mm_R90(36,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x19_254() Precision_7mm_R90(38,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x20_254() Precision_7mm_R90(40,2,2.54) #end
#macro CON_THT_SOCKET_Precision_7mm_R90_2x25_254() Precision_7mm_R90(50,2,2.54) #end


/*******************************************************************************
 * precision female header 2.54mm grid, 2.54mm long
 * drawing: Samtec ss-2854739.pdf
 * 29.05.2023, -wk
 ******************************************************************************/
#macro Precision_254mm(CircuitSize, Rows, Grid)
  union {
     #local Cols = CircuitSize/Rows;
     union {
        object {
           GRID(PrecisionContactFemale(3.0,4.4),Grid,Cols,Rows)
           }
        difference {
           Round_Box (
              <-Cols*Grid/2,4.40-2.55,-Rows*Grid/2>
              <+Cols*Grid/2,4.40-0.01     ,+Rows*Grid/2>
              0.2 0
              )
           GRID(cylinder { <0,1.5,0> <0,4.5,0> 1.5/2},Grid,Cols,Rows)
           #local X = 0.3;
           GRID (
              GRID (
                 box { <-X,1.5,-X> <+X,4.5,+X> rotate <0,45,0> },
                 Grid,Cols+1,1
                 ), Grid*Rows,1,2
              )
           }
        texture {
           pigment {
              White * 0.2
              }
           }
        }
     }
#end

#macro CON_THT_SOCKET_Precision_254mm_1x02_254() Precision_254mm(02,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x03_254() Precision_254mm(03,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x04_254() Precision_254mm(04,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x05_254() Precision_254mm(05,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x06_254() Precision_254mm(06,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x07_254() Precision_254mm(07,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x08_254() Precision_254mm(08,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x09_254() Precision_254mm(09,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x10_254() Precision_254mm(10,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x11_254() Precision_254mm(11,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x12_254() Precision_254mm(12,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x13_254() Precision_254mm(13,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x14_254() Precision_254mm(14,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x15_254() Precision_254mm(15,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x16_254() Precision_254mm(16,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x17_254() Precision_254mm(17,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x18_254() Precision_254mm(18,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x19_254() Precision_254mm(19,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x20_254() Precision_254mm(20,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_1x25_254() Precision_254mm(25,1,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x02_254() Precision_254mm(04,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x03_254() Precision_254mm(06,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x04_254() Precision_254mm(08,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x05_254() Precision_254mm(10,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x06_254() Precision_254mm(12,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x07_254() Precision_254mm(14,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x08_254() Precision_254mm(16,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x09_254() Precision_254mm(18,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x10_254() Precision_254mm(20,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x11_254() Precision_254mm(22,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x12_254() Precision_254mm(24,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x13_254() Precision_254mm(26,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x14_254() Precision_254mm(28,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x15_254() Precision_254mm(30,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x16_254() Precision_254mm(32,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x17_254() Precision_254mm(34,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x18_254() Precision_254mm(36,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x19_254() Precision_254mm(38,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x20_254() Precision_254mm(40,2,2.54) #end
#macro CON_THT_SOCKET_Precision_254mm_2x25_254() Precision_254mm(50,2,2.54) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-pinheader-precision:PREC070F02X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x02_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F03X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x03_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F04X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x04_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F05X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x05_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F06X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x06_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F07X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x07_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F08X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x08_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F09X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x09_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F10X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x10_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F11X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x11_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F12X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x12_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F13X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x13_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F14X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x14_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F15X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x15_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F16X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x16_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F17X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x17_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F18X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x18_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F19X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x19_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F20X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x20_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F25X1R90=CON_THT_SOCKET_Precision_7mm_R90_1x25_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F02X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x02_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F03X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x03_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F04X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x04_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F05X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x05_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F06X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x06_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F07X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x07_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F08X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x08_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F09X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x09_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F10X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x10_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F11X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x11_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F12X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x12_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F13X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x13_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F14X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x14_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F15X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x15_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F16X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x16_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F17X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x17_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F18X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x18_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F19X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x19_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F20X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x20_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC070F25X2R90=CON_THT_SOCKET_Precision_7mm_R90_2x25_254(:Precision 7mm header 2.54mm R90
//con-pinheader-precision:PREC02X1-2.54=CON_THT_SOCKET_Precision_254mm_1x02_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC03X1-2.54=CON_THT_SOCKET_Precision_254mm_1x03_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC04X1-2.54=CON_THT_SOCKET_Precision_254mm_1x04_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC05X1-2.54=CON_THT_SOCKET_Precision_254mm_1x05_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC06X1-2.54=CON_THT_SOCKET_Precision_254mm_1x06_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC07X1-2.54=CON_THT_SOCKET_Precision_254mm_1x07_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC08X1-2.54=CON_THT_SOCKET_Precision_254mm_1x08_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC09X1-2.54=CON_THT_SOCKET_Precision_254mm_1x09_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC10X1-2.54=CON_THT_SOCKET_Precision_254mm_1x10_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC11X1-2.54=CON_THT_SOCKET_Precision_254mm_1x11_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC12X1-2.54=CON_THT_SOCKET_Precision_254mm_1x12_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC13X1-2.54=CON_THT_SOCKET_Precision_254mm_1x13_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC14X1-2.54=CON_THT_SOCKET_Precision_254mm_1x14_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC15X1-2.54=CON_THT_SOCKET_Precision_254mm_1x15_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC16X1-2.54=CON_THT_SOCKET_Precision_254mm_1x16_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC17X1-2.54=CON_THT_SOCKET_Precision_254mm_1x17_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC18X1-2.54=CON_THT_SOCKET_Precision_254mm_1x18_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC19X1-2.54=CON_THT_SOCKET_Precision_254mm_1x19_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC20X1-2.54=CON_THT_SOCKET_Precision_254mm_1x20_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC25X1-2.54=CON_THT_SOCKET_Precision_254mm_1x25_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC02X2-2.54=CON_THT_SOCKET_Precision_254mm_2x02_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC03X2-2.54=CON_THT_SOCKET_Precision_254mm_2x03_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC04X2-2.54=CON_THT_SOCKET_Precision_254mm_2x04_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC05X2-2.54=CON_THT_SOCKET_Precision_254mm_2x05_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC06X2-2.54=CON_THT_SOCKET_Precision_254mm_2x06_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC07X2-2.54=CON_THT_SOCKET_Precision_254mm_2x07_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC08X2-2.54=CON_THT_SOCKET_Precision_254mm_2x08_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC09X2-2.54=CON_THT_SOCKET_Precision_254mm_2x09_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC10X2-2.54=CON_THT_SOCKET_Precision_254mm_2x10_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC11X2-2.54=CON_THT_SOCKET_Precision_254mm_2x11_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC12X2-2.54=CON_THT_SOCKET_Precision_254mm_2x12_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC13X2-2.54=CON_THT_SOCKET_Precision_254mm_2x13_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC14X2-2.54=CON_THT_SOCKET_Precision_254mm_2x14_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC15X2-2.54=CON_THT_SOCKET_Precision_254mm_2x15_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC16X2-2.54=CON_THT_SOCKET_Precision_254mm_2x16_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC17X2-2.54=CON_THT_SOCKET_Precision_254mm_2x17_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC18X2-2.54=CON_THT_SOCKET_Precision_254mm_2x18_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC19X2-2.54=CON_THT_SOCKET_Precision_254mm_2x19_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC20X2-2.54=CON_THT_SOCKET_Precision_254mm_2x20_254(:Precision 2.54mm header 2.54mm
//con-pinheader-precision:PREC25X2-2.54=CON_THT_SOCKET_Precision_254mm_2x25_254(:Precision 2.54mm header 2.54mm
// end assignment
