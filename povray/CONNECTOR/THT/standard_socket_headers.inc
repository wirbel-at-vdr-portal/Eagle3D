


/* reichelt.de
   BKL 10120972
   Buchsenleiste 2,54mm 1x14 gerade

*/




#macro SlotPinheaderFemale(CircuitSize, Rows, Grid)
  union {
     #local Cols = CircuitSize/Rows;
     #local Contact =
        prism {
           -0.875, 0.875,
           14
           < 7.9, 2.6>,
           <14.0, 2.6>,
           <25.0, 2.0>,
           <25.0, 1.8>,
           <21.5, 0.6>,
           <14.0, 1.4>,
           <11.0, 0.0>,
           <14.0,-1.4>,
           <21.5,-0.6>,
           <25.0,-1.8>,
           <25.0,-2.0>,
           <14.0,-2.6>,
           < 7.9,-2.6>,
           < 7.9, 2.6>
           scale (1.0/3.5)
           rotate <0,0,90>
           texture {
              col_silver
              }
           };
     #local ContactHole =
        union {
           box {
              <-0.9/2,1.0,-1.7/2>
              <+0.9/2,8.1,+1.7/2>
              }
           box {
              <-1.3/2,1.0,-0.9/2>
              <+1.3/2,7.5,+0.9/2>
              }
           };

     difference {
        union {
           Round_Box(
              <-Cols*Grid/2,0.5,-Rows*Grid/2>
              <+Cols*Grid/2,8.0,+Rows*Grid/2>
              0.2 0
              )
           GRID(
              Round_Box (
                 <Grid/2-0.4,0,-Grid/3>
                 <Grid/2-0.0,1,+Grid/3>
                 0.1 0
                 )
              Grid,Cols,Rows
              )
           }
        GRID(ContactHole,Grid,Cols,Rows)
        #local X = 0.3;
        #if (Rows > 1)
           GRID(
              Round_Box(
                 <-X/2,0.3,-Grid/3> <+X/2,9,+Grid/3>
                 0.2 0
                 )
              Grid,(Cols-1),(Rows-1)
              )
        #end
        GRID (
           GRID (
              box { <-X,-0.1,-X> <+X,+8.1,+X> rotate <0,45,0> },
              Grid,Cols+1,1
              ), Grid*Rows,1,2
           )

        pigment {
           White * 0.2
           }
        }
     GRID(Contact,Grid,Cols,Rows)
     }
#end


/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * standard grade female pinheader, 90deg
 * i.e. reichelt.de FIS BL4.72G Buchsenleiste 2,54mm, 2x36, trennbar, gewinkelt
 * 30.05.2023, -wk
 ******************************************************************************/
#macro Standard_8mm_R90(CircuitSize, Rows, Grid)
  union {
     #local Cols = CircuitSize/Rows;
     object {
        SlotPinheaderFemale(CircuitSize, Rows, Grid)
        rotate <-90,0,0>
        translate <0,Grid*Rows/2,-Grid*Rows/2>
        }
     GRID(
        object {
           PIN_90deg(0.5,0.5,Grid/2,3,3)
           rotate <0,0,0>
           translate <0,0,-(Rows-1)*Grid/2>
           texture {
              col_silver
              }
           },
        Grid,Cols,1
        )
     #if (Rows > 1)
     GRID(
        object {
           PIN_90deg(0.5,1.0,1.5*Grid,3,3+Grid)
           rotate <0,0,0>
           translate <0,0,+(Rows-1)*Grid/2>
           texture {
              col_silver
              }
           },
        Grid,Cols,1
        )
     #end
     }
#end

#macro CON_THT_Standard_8mm_R90_1x02_254() Standard_8mm_R90(02,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x03_254() Standard_8mm_R90(03,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x04_254() Standard_8mm_R90(04,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x05_254() Standard_8mm_R90(05,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x06_254() Standard_8mm_R90(06,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x07_254() Standard_8mm_R90(07,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x08_254() Standard_8mm_R90(08,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x09_254() Standard_8mm_R90(09,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x10_254() Standard_8mm_R90(10,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x11_254() Standard_8mm_R90(11,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x12_254() Standard_8mm_R90(12,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x13_254() Standard_8mm_R90(13,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x14_254() Standard_8mm_R90(14,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x15_254() Standard_8mm_R90(15,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x16_254() Standard_8mm_R90(16,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x17_254() Standard_8mm_R90(17,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x18_254() Standard_8mm_R90(18,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x19_254() Standard_8mm_R90(19,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x20_254() Standard_8mm_R90(20,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_1x25_254() Standard_8mm_R90(25,1,2.54) rotate <0,180,0> #end
#macro CON_THT_Standard_8mm_R90_2x02_254() Standard_8mm_R90(04,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x03_254() Standard_8mm_R90(06,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x04_254() Standard_8mm_R90(08,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x05_254() Standard_8mm_R90(10,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x06_254() Standard_8mm_R90(12,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x07_254() Standard_8mm_R90(14,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x08_254() Standard_8mm_R90(16,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x09_254() Standard_8mm_R90(18,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x10_254() Standard_8mm_R90(20,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x11_254() Standard_8mm_R90(22,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x12_254() Standard_8mm_R90(24,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x13_254() Standard_8mm_R90(26,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x14_254() Standard_8mm_R90(28,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x15_254() Standard_8mm_R90(30,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x16_254() Standard_8mm_R90(32,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x17_254() Standard_8mm_R90(34,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x18_254() Standard_8mm_R90(36,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x19_254() Standard_8mm_R90(38,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x20_254() Standard_8mm_R90(40,2,2.54) #end
#macro CON_THT_Standard_8mm_R90_2x25_254() Standard_8mm_R90(50,2,2.54) #end


/*******************************************************************************
 * standard grade female pinheader, straight
 * 30.05.2023, -wk
 ******************************************************************************/
#macro Standard_8mm(CircuitSize, Rows, Grid)
  union {
     #local Cols = CircuitSize/Rows;
     object {
        SlotPinheaderFemale(CircuitSize, Rows, Grid)
        //rotate <-90,0,0>
        //translate <0,Grid*Rows/2,-Grid*Rows/2>
        }
     GRID(
        object {
           PIN_STRAIGHT(0.5,1,3)
           texture {
              col_silver
              }
           },
        Grid,Cols,Rows
        )
     }
#end

#macro CON_THT_Standard_8mm_1x02_254() Standard_8mm(02, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x03_254() Standard_8mm(03, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x04_254() Standard_8mm(04, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x05_254() Standard_8mm(05, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x06_254() Standard_8mm(06, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x07_254() Standard_8mm(07, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x08_254() Standard_8mm(08, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x09_254() Standard_8mm(09, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x10_254() Standard_8mm(10, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x11_254() Standard_8mm(11, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x12_254() Standard_8mm(12, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x13_254() Standard_8mm(13, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x14_254() Standard_8mm(14, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x15_254() Standard_8mm(15, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x16_254() Standard_8mm(16, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x17_254() Standard_8mm(17, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x18_254() Standard_8mm(18, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x19_254() Standard_8mm(19, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x20_254() Standard_8mm(20, 1, 2.54) #end
#macro CON_THT_Standard_8mm_1x25_254() Standard_8mm(25, 1, 2.54) #end
#macro CON_THT_Standard_8mm_2x02_254() Standard_8mm(04, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x03_254() Standard_8mm(06, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x04_254() Standard_8mm(08, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x05_254() Standard_8mm(10, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x06_254() Standard_8mm(12, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x07_254() Standard_8mm(14, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x08_254() Standard_8mm(16, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x09_254() Standard_8mm(18, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x10_254() Standard_8mm(20, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x11_254() Standard_8mm(22, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x12_254() Standard_8mm(24, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x13_254() Standard_8mm(26, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x14_254() Standard_8mm(28, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x15_254() Standard_8mm(30, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x16_254() Standard_8mm(32, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x17_254() Standard_8mm(34, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x18_254() Standard_8mm(36, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x19_254() Standard_8mm(38, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x20_254() Standard_8mm(40, 2, 2.54) #end
#macro CON_THT_Standard_8mm_2x25_254() Standard_8mm(50, 2, 2.54) #end
