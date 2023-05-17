/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * female header 2.54mm, 1-row, 2-row, 3-row.
 ******************************************************************************/
#macro MPE094_FEMALE(grid,H)
  union { 
     difference {
        box{<-grid/2,0,-grid/2>
            <+grid/2,H,+grid/2>}
        object{ Pyramid_N(4, grid, 0.0, grid)
                rotate <180,0,0>
                translate <0,H+grid/2,0>}
        box{<-1/2, -0.1,-1/2>
            <+1/2,H+0.1,+1/2>}
        }
     }
#end

#macro MPE094_FEMALE_PIN()
  intersection {
     box{<-0.65/2, 2.0,-0.4/2>
         <+0.65/2,-3.1,+0.4/2>}
     box{<-8/2,-8/2,-0.5/2>
         <+8/2,+8/2,+0.5/2>
        rotate <0,0,45>
        translate <0,2.4,0>
        }     
     texture{col_gold}
     }
#end

#macro MPE_094(X,Y)
#local grid = 2.54;
union {
  // plastic housing
  difference {
     GRID(MPE094_FEMALE(grid,8.5),grid,X,Y)
     box {<-X/2*grid -0.1,-0.1   ,-Y/2*grid+grid/3>
          <+X/2*grid +0.1,+grid/3,+Y/2*grid-grid/3>}
     pigment{Gray25}
     }
  // straight pin
  GRID(MPE094_FEMALE_PIN(),grid,X,Y)
  }
#end


/*******************************************************************************
 * female header 2.54mm, 1-row, 2-row, 3-row.
 * - https://www.mpe-connector.de/de/produkte/
 *           buchsenleisten/buchsenleiste-850-bauhoehe-254-mm
 *     parts 094-1, 094-2, 094-3
 * or
 * - https://docs.rs-online.com/ed68/0900766b80da4106.pdf p.277,p.279
 *     Assmann A-BL-254-E G-x xx D (1-row)
 *     Assmann A-BL-254-D G-x xx D (2-row)
 *     see also: samtec ssw-th.pdf
 ******************************************************************************/
#macro CON_THT_MPE094_1x1()  MPE_094(1,1)  #end
#macro CON_THT_MPE094_2x1()  MPE_094(2,1)  #end
#macro CON_THT_MPE094_3x1()  MPE_094(3,1)  #end
#macro CON_THT_MPE094_4x1()  MPE_094(4,1)  #end
#macro CON_THT_MPE094_5x1()  MPE_094(5,1)  #end
#macro CON_THT_MPE094_6x1()  MPE_094(6,1)  #end
#macro CON_THT_MPE094_7x1()  MPE_094(7,1)  #end
#macro CON_THT_MPE094_8x1()  MPE_094(8,1)  #end
#macro CON_THT_MPE094_9x1()  MPE_094(9,1)  #end
#macro CON_THT_MPE094_10x1() MPE_094(10,1) #end
#macro CON_THT_MPE094_11x1() MPE_094(11,1) #end
#macro CON_THT_MPE094_12x1() MPE_094(12,1) #end
#macro CON_THT_MPE094_13x1() MPE_094(13,1) #end
#macro CON_THT_MPE094_14x1() MPE_094(14,1) #end
#macro CON_THT_MPE094_15x1() MPE_094(15,1) #end
#macro CON_THT_MPE094_16x1() MPE_094(16,1) #end
#macro CON_THT_MPE094_17x1() MPE_094(17,1) #end
#macro CON_THT_MPE094_18x1() MPE_094(18,1) #end
#macro CON_THT_MPE094_19x1() MPE_094(19,1) #end
#macro CON_THT_MPE094_20x1() MPE_094(20,1) #end
#macro CON_THT_MPE094_21x1() MPE_094(21,1) #end
#macro CON_THT_MPE094_22x1() MPE_094(22,1) #end
#macro CON_THT_MPE094_23x1() MPE_094(23,1) #end
#macro CON_THT_MPE094_24x1() MPE_094(24,1) #end
#macro CON_THT_MPE094_25x1() MPE_094(25,1) #end
#macro CON_THT_MPE094_26x1() MPE_094(26,1) #end
#macro CON_THT_MPE094_27x1() MPE_094(27,1) #end
#macro CON_THT_MPE094_28x1() MPE_094(28,1) #end
#macro CON_THT_MPE094_29x1() MPE_094(29,1) #end
#macro CON_THT_MPE094_30x1() MPE_094(30,1) #end
#macro CON_THT_MPE094_31x1() MPE_094(31,1) #end
#macro CON_THT_MPE094_32x1() MPE_094(32,1) #end
#macro CON_THT_MPE094_33x1() MPE_094(33,1) #end
#macro CON_THT_MPE094_34x1() MPE_094(34,1) #end
#macro CON_THT_MPE094_35x1() MPE_094(35,1) #end
#macro CON_THT_MPE094_36x1() MPE_094(36,1) #end
#macro CON_THT_MPE094_37x1() MPE_094(37,1) #end
#macro CON_THT_MPE094_38x1() MPE_094(38,1) #end
#macro CON_THT_MPE094_39x1() MPE_094(39,1) #end
#macro CON_THT_MPE094_40x1() MPE_094(40,1) #end
#macro CON_THT_MPE094_1x2()  MPE_094(1,2)  #end
#macro CON_THT_MPE094_2x2()  MPE_094(2,2)  #end
#macro CON_THT_MPE094_3x2()  MPE_094(3,2)  #end
#macro CON_THT_MPE094_4x2()  MPE_094(4,2)  #end
#macro CON_THT_MPE094_5x2()  MPE_094(5,2)  #end
#macro CON_THT_MPE094_6x2()  MPE_094(6,2)  #end
#macro CON_THT_MPE094_7x2()  MPE_094(7,2)  #end
#macro CON_THT_MPE094_8x2()  MPE_094(8,2)  #end
#macro CON_THT_MPE094_9x2()  MPE_094(9,2)  #end
#macro CON_THT_MPE094_10x2() MPE_094(10,2) #end
#macro CON_THT_MPE094_11x2() MPE_094(11,2) #end
#macro CON_THT_MPE094_12x2() MPE_094(12,2) #end
#macro CON_THT_MPE094_13x2() MPE_094(13,2) #end
#macro CON_THT_MPE094_14x2() MPE_094(14,2) #end
#macro CON_THT_MPE094_15x2() MPE_094(15,2) #end
#macro CON_THT_MPE094_16x2() MPE_094(16,2) #end
#macro CON_THT_MPE094_17x2() MPE_094(17,2) #end
#macro CON_THT_MPE094_18x2() MPE_094(18,2) #end
#macro CON_THT_MPE094_19x2() MPE_094(19,2) #end
#macro CON_THT_MPE094_20x2() MPE_094(20,2) #end
#macro CON_THT_MPE094_21x2() MPE_094(21,2) #end
#macro CON_THT_MPE094_22x2() MPE_094(22,2) #end
#macro CON_THT_MPE094_23x2() MPE_094(23,2) #end
#macro CON_THT_MPE094_24x2() MPE_094(24,2) #end
#macro CON_THT_MPE094_25x2() MPE_094(25,2) #end
#macro CON_THT_MPE094_26x2() MPE_094(26,2) #end
#macro CON_THT_MPE094_27x2() MPE_094(27,2) #end
#macro CON_THT_MPE094_28x2() MPE_094(28,2) #end
#macro CON_THT_MPE094_29x2() MPE_094(29,2) #end
#macro CON_THT_MPE094_30x2() MPE_094(30,2) #end
#macro CON_THT_MPE094_31x2() MPE_094(31,2) #end
#macro CON_THT_MPE094_32x2() MPE_094(32,2) #end
#macro CON_THT_MPE094_33x2() MPE_094(33,2) #end
#macro CON_THT_MPE094_34x2() MPE_094(34,2) #end
#macro CON_THT_MPE094_35x2() MPE_094(35,2) #end
#macro CON_THT_MPE094_36x2() MPE_094(36,2) #end
#macro CON_THT_MPE094_37x2() MPE_094(37,2) #end
#macro CON_THT_MPE094_38x2() MPE_094(38,2) #end
#macro CON_THT_MPE094_39x2() MPE_094(39,2) #end
#macro CON_THT_MPE094_40x2() MPE_094(40,2) #end
#macro CON_THT_MPE094_1x3()  MPE_094(1,3)  #end
#macro CON_THT_MPE094_2x3()  MPE_094(2,3)  #end
#macro CON_THT_MPE094_3x3()  MPE_094(3,3)  #end
#macro CON_THT_MPE094_4x3()  MPE_094(4,3)  #end
#macro CON_THT_MPE094_5x3()  MPE_094(5,3)  #end
#macro CON_THT_MPE094_6x3()  MPE_094(6,3)  #end
#macro CON_THT_MPE094_7x3()  MPE_094(7,3)  #end
#macro CON_THT_MPE094_8x3()  MPE_094(8,3)  #end
#macro CON_THT_MPE094_9x3()  MPE_094(9,3)  #end
#macro CON_THT_MPE094_10x3() MPE_094(10,3) #end
#macro CON_THT_MPE094_11x3() MPE_094(11,3) #end
#macro CON_THT_MPE094_12x3() MPE_094(12,3) #end
#macro CON_THT_MPE094_13x3() MPE_094(13,3) #end
#macro CON_THT_MPE094_14x3() MPE_094(14,3) #end
#macro CON_THT_MPE094_15x3() MPE_094(15,3) #end
#macro CON_THT_MPE094_16x3() MPE_094(16,3) #end
#macro CON_THT_MPE094_17x3() MPE_094(17,3) #end
#macro CON_THT_MPE094_18x3() MPE_094(18,3) #end
#macro CON_THT_MPE094_19x3() MPE_094(19,3) #end
#macro CON_THT_MPE094_20x3() MPE_094(20,3) #end
#macro CON_THT_MPE094_21x3() MPE_094(21,3) #end
#macro CON_THT_MPE094_22x3() MPE_094(22,3) #end
#macro CON_THT_MPE094_23x3() MPE_094(23,3) #end
#macro CON_THT_MPE094_24x3() MPE_094(24,3) #end
#macro CON_THT_MPE094_25x3() MPE_094(25,3) #end
#macro CON_THT_MPE094_26x3() MPE_094(26,3) #end
#macro CON_THT_MPE094_27x3() MPE_094(27,3) #end
#macro CON_THT_MPE094_28x3() MPE_094(28,3) #end
#macro CON_THT_MPE094_29x3() MPE_094(29,3) #end
#macro CON_THT_MPE094_30x3() MPE_094(30,3) #end
#macro CON_THT_MPE094_31x3() MPE_094(31,3) #end
#macro CON_THT_MPE094_32x3() MPE_094(32,3) #end
#macro CON_THT_MPE094_33x3() MPE_094(33,3) #end
#macro CON_THT_MPE094_34x3() MPE_094(34,3) #end
#macro CON_THT_MPE094_35x3() MPE_094(35,3) #end
#macro CON_THT_MPE094_36x3() MPE_094(36,3) #end
#macro CON_THT_MPE094_37x3() MPE_094(37,3) #end
#macro CON_THT_MPE094_38x3() MPE_094(38,3) #end
#macro CON_THT_MPE094_39x3() MPE_094(39,3) #end
#macro CON_THT_MPE094_40x3() MPE_094(40,3) #end



/*******************************************************************************
 * female header 2.00mm, 1-row, 2-row, 3-row.
 ******************************************************************************/
#macro MPE156_FEMALE(grid,H)
  union { 
     difference {
        box{<-grid/2,0,-2.20/2>
            <+grid/2,H,+2.20/2>}
        object{ Pyramid_N(4, grid, 0.0, grid)
                rotate <180,0,0>
                translate <0,H+grid/2,0>}
        box{<-0.9/2, -0.1,-0.9/2>
            <+0.9/2,H+0.1,+0.9/2>}
        }
     }
#end

#macro MPE156_FEMALE_PIN()
  intersection {
     box{<-0.45/2, 2.0,-0.2/2>
         <+0.45/2,-2.6,+0.2/2>}
     box{<-5/2,-5/2,-0.5/2>
         <+5/2,+5/2,+0.5/2>
        rotate <0,0,45> translate <0,0.8,0>
        }     
     texture{col_gold}
     }
#end


#macro MPE_156(X,Y)
#local grid = 2.00;
union {
  // plastic housing
  union {
     GRID(cylinder{<0,0.3,-0.75><0,0.3,0.75>0.3},grid,X-1,Y)
     difference {
        GRID(MPE156_FEMALE(grid,4.3),grid,X,Y)
        box {<-X/2*grid -0.1,-0.1,-Y/2*grid-0.1>
             <+X/2*grid +0.1,+0.3,+Y/2*grid+0.1>}
        }
     pigment{Gray25}
     }
  // straight pin
  GRID(MPE156_FEMALE_PIN(),grid,X,Y)
  }
#end

/*******************************************************************************
 * female header 2.00mm, 1-row, 2-row, 3-row.
 * - https://www.mpe-connector.de/de/produkte/
 *           buchsenleisten/buchsenleiste-200-mm/156-1
 *     parts 156 variant 1 and variant 3
 * or
 * - https://docs.rs-online.com/ed68/0900766b80da4106.pdf p.281,p.279
 *     Assmann A-BL-200-E G-x xx D (1-row)
 *     Assmann A-BL-200-D G-x xx D (2-row)
 ******************************************************************************/
#macro CON_THT_MPE156_1x1()  MPE_156(1,1)  #end
#macro CON_THT_MPE156_2x1()  MPE_156(2,1)  #end
#macro CON_THT_MPE156_3x1()  MPE_156(3,1)  #end
#macro CON_THT_MPE156_4x1()  MPE_156(4,1)  #end
#macro CON_THT_MPE156_5x1()  MPE_156(5,1)  #end
#macro CON_THT_MPE156_6x1()  MPE_156(6,1)  #end
#macro CON_THT_MPE156_7x1()  MPE_156(7,1)  #end
#macro CON_THT_MPE156_8x1()  MPE_156(8,1)  #end
#macro CON_THT_MPE156_9x1()  MPE_156(9,1)  #end
#macro CON_THT_MPE156_10x1() MPE_156(10,1) #end
#macro CON_THT_MPE156_11x1() MPE_156(11,1) #end
#macro CON_THT_MPE156_12x1() MPE_156(12,1) #end
#macro CON_THT_MPE156_13x1() MPE_156(13,1) #end
#macro CON_THT_MPE156_14x1() MPE_156(14,1) #end
#macro CON_THT_MPE156_15x1() MPE_156(15,1) #end
#macro CON_THT_MPE156_16x1() MPE_156(16,1) #end
#macro CON_THT_MPE156_17x1() MPE_156(17,1) #end
#macro CON_THT_MPE156_18x1() MPE_156(18,1) #end
#macro CON_THT_MPE156_19x1() MPE_156(19,1) #end
#macro CON_THT_MPE156_20x1() MPE_156(20,1) #end
#macro CON_THT_MPE156_21x1() MPE_156(21,1) #end
#macro CON_THT_MPE156_22x1() MPE_156(22,1) #end
#macro CON_THT_MPE156_23x1() MPE_156(23,1) #end
#macro CON_THT_MPE156_24x1() MPE_156(24,1) #end
#macro CON_THT_MPE156_25x1() MPE_156(25,1) #end
#macro CON_THT_MPE156_26x1() MPE_156(26,1) #end
#macro CON_THT_MPE156_27x1() MPE_156(27,1) #end
#macro CON_THT_MPE156_28x1() MPE_156(28,1) #end
#macro CON_THT_MPE156_29x1() MPE_156(29,1) #end
#macro CON_THT_MPE156_30x1() MPE_156(30,1) #end
#macro CON_THT_MPE156_31x1() MPE_156(31,1) #end
#macro CON_THT_MPE156_32x1() MPE_156(32,1) #end
#macro CON_THT_MPE156_33x1() MPE_156(33,1) #end
#macro CON_THT_MPE156_34x1() MPE_156(34,1) #end
#macro CON_THT_MPE156_35x1() MPE_156(35,1) #end
#macro CON_THT_MPE156_36x1() MPE_156(36,1) #end
#macro CON_THT_MPE156_37x1() MPE_156(37,1) #end
#macro CON_THT_MPE156_38x1() MPE_156(38,1) #end
#macro CON_THT_MPE156_39x1() MPE_156(39,1) #end
#macro CON_THT_MPE156_40x1() MPE_156(40,1) #end
#macro CON_THT_MPE156_1x2()  MPE_156(1,2)  #end
#macro CON_THT_MPE156_2x2()  MPE_156(2,2)  #end
#macro CON_THT_MPE156_3x2()  MPE_156(3,2)  #end
#macro CON_THT_MPE156_4x2()  MPE_156(4,2)  #end
#macro CON_THT_MPE156_5x2()  MPE_156(5,2)  #end
#macro CON_THT_MPE156_6x2()  MPE_156(6,2)  #end
#macro CON_THT_MPE156_7x2()  MPE_156(7,2)  #end
#macro CON_THT_MPE156_8x2()  MPE_156(8,2)  #end
#macro CON_THT_MPE156_9x2()  MPE_156(9,2)  #end
#macro CON_THT_MPE156_10x2() MPE_156(10,2) #end
#macro CON_THT_MPE156_11x2() MPE_156(11,2) #end
#macro CON_THT_MPE156_12x2() MPE_156(12,2) #end
#macro CON_THT_MPE156_13x2() MPE_156(13,2) #end
#macro CON_THT_MPE156_14x2() MPE_156(14,2) #end
#macro CON_THT_MPE156_15x2() MPE_156(15,2) #end
#macro CON_THT_MPE156_16x2() MPE_156(16,2) #end
#macro CON_THT_MPE156_17x2() MPE_156(17,2) #end
#macro CON_THT_MPE156_18x2() MPE_156(18,2) #end
#macro CON_THT_MPE156_19x2() MPE_156(19,2) #end
#macro CON_THT_MPE156_20x2() MPE_156(20,2) #end
#macro CON_THT_MPE156_21x2() MPE_156(21,2) #end
#macro CON_THT_MPE156_22x2() MPE_156(22,2) #end
#macro CON_THT_MPE156_23x2() MPE_156(23,2) #end
#macro CON_THT_MPE156_24x2() MPE_156(24,2) #end
#macro CON_THT_MPE156_25x2() MPE_156(25,2) #end
#macro CON_THT_MPE156_26x2() MPE_156(26,2) #end
#macro CON_THT_MPE156_27x2() MPE_156(27,2) #end
#macro CON_THT_MPE156_28x2() MPE_156(28,2) #end
#macro CON_THT_MPE156_29x2() MPE_156(29,2) #end
#macro CON_THT_MPE156_30x2() MPE_156(30,2) #end
#macro CON_THT_MPE156_31x2() MPE_156(31,2) #end
#macro CON_THT_MPE156_32x2() MPE_156(32,2) #end
#macro CON_THT_MPE156_33x2() MPE_156(33,2) #end
#macro CON_THT_MPE156_34x2() MPE_156(34,2) #end
#macro CON_THT_MPE156_35x2() MPE_156(35,2) #end
#macro CON_THT_MPE156_36x2() MPE_156(36,2) #end
#macro CON_THT_MPE156_37x2() MPE_156(37,2) #end
#macro CON_THT_MPE156_38x2() MPE_156(38,2) #end
#macro CON_THT_MPE156_39x2() MPE_156(39,2) #end
#macro CON_THT_MPE156_40x2() MPE_156(40,2) #end
#macro CON_THT_MPE156_1x3()  MPE_156(1,3)  #end
#macro CON_THT_MPE156_2x3()  MPE_156(2,3)  #end
#macro CON_THT_MPE156_3x3()  MPE_156(3,3)  #end
#macro CON_THT_MPE156_4x3()  MPE_156(4,3)  #end
#macro CON_THT_MPE156_5x3()  MPE_156(5,3)  #end
#macro CON_THT_MPE156_6x3()  MPE_156(6,3)  #end
#macro CON_THT_MPE156_7x3()  MPE_156(7,3)  #end
#macro CON_THT_MPE156_8x3()  MPE_156(8,3)  #end
#macro CON_THT_MPE156_9x3()  MPE_156(9,3)  #end
#macro CON_THT_MPE156_10x3() MPE_156(10,3) #end
#macro CON_THT_MPE156_11x3() MPE_156(11,3) #end
#macro CON_THT_MPE156_12x3() MPE_156(12,3) #end
#macro CON_THT_MPE156_13x3() MPE_156(13,3) #end
#macro CON_THT_MPE156_14x3() MPE_156(14,3) #end
#macro CON_THT_MPE156_15x3() MPE_156(15,3) #end
#macro CON_THT_MPE156_16x3() MPE_156(16,3) #end
#macro CON_THT_MPE156_17x3() MPE_156(17,3) #end
#macro CON_THT_MPE156_18x3() MPE_156(18,3) #end
#macro CON_THT_MPE156_19x3() MPE_156(19,3) #end
#macro CON_THT_MPE156_20x3() MPE_156(20,3) #end
#macro CON_THT_MPE156_21x3() MPE_156(21,3) #end
#macro CON_THT_MPE156_22x3() MPE_156(22,3) #end
#macro CON_THT_MPE156_23x3() MPE_156(23,3) #end
#macro CON_THT_MPE156_24x3() MPE_156(24,3) #end
#macro CON_THT_MPE156_25x3() MPE_156(25,3) #end
#macro CON_THT_MPE156_26x3() MPE_156(26,3) #end
#macro CON_THT_MPE156_27x3() MPE_156(27,3) #end
#macro CON_THT_MPE156_28x3() MPE_156(28,3) #end
#macro CON_THT_MPE156_29x3() MPE_156(29,3) #end
#macro CON_THT_MPE156_30x3() MPE_156(30,3) #end
#macro CON_THT_MPE156_31x3() MPE_156(31,3) #end
#macro CON_THT_MPE156_32x3() MPE_156(32,3) #end
#macro CON_THT_MPE156_33x3() MPE_156(33,3) #end
#macro CON_THT_MPE156_34x3() MPE_156(34,3) #end
#macro CON_THT_MPE156_35x3() MPE_156(35,3) #end
#macro CON_THT_MPE156_36x3() MPE_156(36,3) #end
#macro CON_THT_MPE156_37x3() MPE_156(37,3) #end
#macro CON_THT_MPE156_38x3() MPE_156(38,3) #end
#macro CON_THT_MPE156_39x3() MPE_156(39,3) #end
#macro CON_THT_MPE156_40x3() MPE_156(40,3) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-samtec:SSW-101-02-S-S=CON_THT_MPE094_1x1(:2.54mm grid socket terminal
//con-samtec:SSW-102-02-S-S=CON_THT_MPE094_2x1(:2.54mm grid socket terminal
//con-samtec:SSW-103-02-S-S=CON_THT_MPE094_3x1(:2.54mm grid socket terminal
//con-samtec:SSW-104-02-S-S=CON_THT_MPE094_4x1(:2.54mm grid socket terminal
//con-samtec:SSW-105-02-S-S=CON_THT_MPE094_5x1(:2.54mm grid socket terminal
//con-samtec:SSW-106-02-S-S=CON_THT_MPE094_6x1(:2.54mm grid socket terminal
//con-samtec:SSW-107-02-S-S=CON_THT_MPE094_7x1(:2.54mm grid socket terminal
//con-samtec:SSW-108-02-S-S=CON_THT_MPE094_8x1(:2.54mm grid socket terminal
//con-samtec:SSW-109-02-S-S=CON_THT_MPE094_9x1(:2.54mm grid socket terminal
//con-samtec:SSW-110-02-S-S=CON_THT_MPE094_10x1(:2.54mm grid socket terminal
//con-samtec:SSW-111-02-S-S=CON_THT_MPE094_11x1(:2.54mm grid socket terminal
//con-samtec:SSW-112-02-S-S=CON_THT_MPE094_12x1(:2.54mm grid socket terminal
//con-samtec:SSW-113-02-S-S=CON_THT_MPE094_13x1(:2.54mm grid socket terminal
//con-samtec:SSW-114-02-S-S=CON_THT_MPE094_14x1(:2.54mm grid socket terminal
//con-samtec:SSW-115-02-S-S=CON_THT_MPE094_15x1(:2.54mm grid socket terminal
//con-samtec:SSW-116-02-S-S=CON_THT_MPE094_16x1(:2.54mm grid socket terminal
//con-samtec:SSW-117-02-S-S=CON_THT_MPE094_17x1(:2.54mm grid socket terminal
//con-samtec:SSW-118-02-S-S=CON_THT_MPE094_18x1(:2.54mm grid socket terminal
//con-samtec:SSW-119-02-S-S=CON_THT_MPE094_19x1(:2.54mm grid socket terminal
//con-samtec:SSW-120-02-S-S=CON_THT_MPE094_20x1(:2.54mm grid socket terminal
//con-samtec:SSW-121-02-S-S=CON_THT_MPE094_21x1(:2.54mm grid socket terminal
//con-samtec:SSW-122-02-S-S=CON_THT_MPE094_22x1(:2.54mm grid socket terminal
//con-samtec:SSW-123-02-S-S=CON_THT_MPE094_23x1(:2.54mm grid socket terminal
//con-samtec:SSW-124-02-S-S=CON_THT_MPE094_24x1(:2.54mm grid socket terminal
//con-samtec:SSW-125-02-S-S=CON_THT_MPE094_25x1(:2.54mm grid socket terminal
//con-samtec:SSW-126-02-S-S=CON_THT_MPE094_26x1(:2.54mm grid socket terminal
//con-samtec:SSW-127-02-S-S=CON_THT_MPE094_27x1(:2.54mm grid socket terminal
//con-samtec:SSW-128-02-S-S=CON_THT_MPE094_28x1(:2.54mm grid socket terminal
//con-samtec:SSW-129-02-S-S=CON_THT_MPE094_29x1(:2.54mm grid socket terminal
//con-samtec:SSW-130-02-S-S=CON_THT_MPE094_30x1(:2.54mm grid socket terminal
//con-samtec:SSW-131-02-S-S=CON_THT_MPE094_31x1(:2.54mm grid socket terminal
//con-samtec:SSW-132-02-S-S=CON_THT_MPE094_32x1(:2.54mm grid socket terminal
//con-samtec:SSW-133-02-S-S=CON_THT_MPE094_33x1(:2.54mm grid socket terminal
//con-samtec:SSW-134-02-S-S=CON_THT_MPE094_34x1(:2.54mm grid socket terminal
//con-samtec:SSW-135-02-S-S=CON_THT_MPE094_35x1(:2.54mm grid socket terminal
//con-samtec:SSW-136-02-S-S=CON_THT_MPE094_36x1(:2.54mm grid socket terminal
//con-samtec:SSW-137-02-S-S=CON_THT_MPE094_37x1(:2.54mm grid socket terminal
//con-samtec:SSW-138-02-S-S=CON_THT_MPE094_38x1(:2.54mm grid socket terminal
//con-samtec:SSW-139-02-S-S=CON_THT_MPE094_39x1(:2.54mm grid socket terminal
//con-samtec:SSW-140-02-S-S=CON_THT_MPE094_40x1(:2.54mm grid socket terminal
//con-samtec:SSW-101-02-S-D=CON_THT_MPE094_1x2(:2.54mm grid socket terminal
//con-samtec:SSW-102-02-S-D=CON_THT_MPE094_2x2(:2.54mm grid socket terminal
//con-samtec:SSW-103-02-S-D=CON_THT_MPE094_3x2(:2.54mm grid socket terminal
//con-samtec:SSW-104-02-S-D=CON_THT_MPE094_4x2(:2.54mm grid socket terminal
//con-samtec:SSW-105-02-S-D=CON_THT_MPE094_5x2(:2.54mm grid socket terminal
//con-samtec:SSW-106-02-S-D=CON_THT_MPE094_6x2(:2.54mm grid socket terminal
//con-samtec:SSW-107-02-S-D=CON_THT_MPE094_7x2(:2.54mm grid socket terminal
//con-samtec:SSW-108-02-S-D=CON_THT_MPE094_8x2(:2.54mm grid socket terminal
//con-samtec:SSW-109-02-S-D=CON_THT_MPE094_9x2(:2.54mm grid socket terminal
//con-samtec:SSW-110-02-S-D=CON_THT_MPE094_10x2(:2.54mm grid socket terminal
//con-samtec:SSW-111-02-S-D=CON_THT_MPE094_11x2(:2.54mm grid socket terminal
//con-samtec:SSW-112-02-S-D=CON_THT_MPE094_12x2(:2.54mm grid socket terminal
//con-samtec:SSW-113-02-S-D=CON_THT_MPE094_13x2(:2.54mm grid socket terminal
//con-samtec:SSW-114-02-S-D=CON_THT_MPE094_14x2(:2.54mm grid socket terminal
//con-samtec:SSW-115-02-S-D=CON_THT_MPE094_15x2(:2.54mm grid socket terminal
//con-samtec:SSW-116-02-S-D=CON_THT_MPE094_16x2(:2.54mm grid socket terminal
//con-samtec:SSW-117-02-S-D=CON_THT_MPE094_17x2(:2.54mm grid socket terminal
//con-samtec:SSW-118-02-S-D=CON_THT_MPE094_18x2(:2.54mm grid socket terminal
//con-samtec:SSW-119-02-S-D=CON_THT_MPE094_19x2(:2.54mm grid socket terminal
//con-samtec:SSW-120-02-S-D=CON_THT_MPE094_20x2(:2.54mm grid socket terminal
//con-samtec:SSW-121-02-S-D=CON_THT_MPE094_21x2(:2.54mm grid socket terminal
//con-samtec:SSW-122-02-S-D=CON_THT_MPE094_22x2(:2.54mm grid socket terminal
//con-samtec:SSW-123-02-S-D=CON_THT_MPE094_23x2(:2.54mm grid socket terminal
//con-samtec:SSW-124-02-S-D=CON_THT_MPE094_24x2(:2.54mm grid socket terminal
//con-samtec:SSW-125-02-S-D=CON_THT_MPE094_25x2(:2.54mm grid socket terminal
//con-samtec:SSW-126-02-S-D=CON_THT_MPE094_26x2(:2.54mm grid socket terminal
//con-samtec:SSW-127-02-S-D=CON_THT_MPE094_27x2(:2.54mm grid socket terminal
//con-samtec:SSW-128-02-S-D=CON_THT_MPE094_28x2(:2.54mm grid socket terminal
//con-samtec:SSW-129-02-S-D=CON_THT_MPE094_29x2(:2.54mm grid socket terminal
//con-samtec:SSW-130-02-S-D=CON_THT_MPE094_30x2(:2.54mm grid socket terminal
//con-samtec:SSW-131-02-S-D=CON_THT_MPE094_31x2(:2.54mm grid socket terminal
//con-samtec:SSW-132-02-S-D=CON_THT_MPE094_32x2(:2.54mm grid socket terminal
//con-samtec:SSW-133-02-S-D=CON_THT_MPE094_33x2(:2.54mm grid socket terminal
//con-samtec:SSW-134-02-S-D=CON_THT_MPE094_34x2(:2.54mm grid socket terminal
//con-samtec:SSW-135-02-S-D=CON_THT_MPE094_35x2(:2.54mm grid socket terminal
//con-samtec:SSW-136-02-S-D=CON_THT_MPE094_36x2(:2.54mm grid socket terminal
//con-samtec:SSW-137-02-S-D=CON_THT_MPE094_37x2(:2.54mm grid socket terminal
//con-samtec:SSW-138-02-S-D=CON_THT_MPE094_38x2(:2.54mm grid socket terminal
//con-samtec:SSW-139-02-S-D=CON_THT_MPE094_39x2(:2.54mm grid socket terminal
//con-samtec:SSW-140-02-S-D=CON_THT_MPE094_40x2(:2.54mm grid socket terminal
//con-samtec:SSW-101-02-S-T=CON_THT_MPE094_1x3(:2.54mm grid socket terminal
//con-samtec:SSW-102-02-S-T=CON_THT_MPE094_2x3(:2.54mm grid socket terminal
//con-samtec:SSW-103-02-S-T=CON_THT_MPE094_3x3(:2.54mm grid socket terminal
//con-samtec:SSW-104-02-S-T=CON_THT_MPE094_4x3(:2.54mm grid socket terminal
//con-samtec:SSW-105-02-S-T=CON_THT_MPE094_5x3(:2.54mm grid socket terminal
//con-samtec:SSW-106-02-S-T=CON_THT_MPE094_6x3(:2.54mm grid socket terminal
//con-samtec:SSW-107-02-S-T=CON_THT_MPE094_7x3(:2.54mm grid socket terminal
//con-samtec:SSW-108-02-S-T=CON_THT_MPE094_8x3(:2.54mm grid socket terminal
//con-samtec:SSW-109-02-S-T=CON_THT_MPE094_9x3(:2.54mm grid socket terminal
//con-samtec:SSW-110-02-S-T=CON_THT_MPE094_10x3(:2.54mm grid socket terminal
//con-samtec:SSW-111-02-S-T=CON_THT_MPE094_11x3(:2.54mm grid socket terminal
//con-samtec:SSW-112-02-S-T=CON_THT_MPE094_12x3(:2.54mm grid socket terminal
//con-samtec:SSW-113-02-S-T=CON_THT_MPE094_13x3(:2.54mm grid socket terminal
//con-samtec:SSW-114-02-S-T=CON_THT_MPE094_14x3(:2.54mm grid socket terminal
//con-samtec:SSW-115-02-S-T=CON_THT_MPE094_15x3(:2.54mm grid socket terminal
//con-samtec:SSW-116-02-S-T=CON_THT_MPE094_16x3(:2.54mm grid socket terminal
//con-samtec:SSW-117-02-S-T=CON_THT_MPE094_17x3(:2.54mm grid socket terminal
//con-samtec:SSW-118-02-S-T=CON_THT_MPE094_18x3(:2.54mm grid socket terminal
//con-samtec:SSW-119-02-S-T=CON_THT_MPE094_19x3(:2.54mm grid socket terminal
//con-samtec:SSW-120-02-S-T=CON_THT_MPE094_20x3(:2.54mm grid socket terminal
//con-samtec:SSW-121-02-S-T=CON_THT_MPE094_21x3(:2.54mm grid socket terminal
//con-samtec:SSW-122-02-S-T=CON_THT_MPE094_22x3(:2.54mm grid socket terminal
//con-samtec:SSW-123-02-S-T=CON_THT_MPE094_23x3(:2.54mm grid socket terminal
//con-samtec:SSW-124-02-S-T=CON_THT_MPE094_24x3(:2.54mm grid socket terminal
//con-samtec:SSW-125-02-S-T=CON_THT_MPE094_25x3(:2.54mm grid socket terminal
//con-samtec:SSW-126-02-S-T=CON_THT_MPE094_26x3(:2.54mm grid socket terminal
//con-samtec:SSW-127-02-S-T=CON_THT_MPE094_27x3(:2.54mm grid socket terminal
//con-samtec:SSW-128-02-S-T=CON_THT_MPE094_28x3(:2.54mm grid socket terminal
//con-samtec:SSW-129-02-S-T=CON_THT_MPE094_29x3(:2.54mm grid socket terminal
//con-samtec:SSW-130-02-S-T=CON_THT_MPE094_30x3(:2.54mm grid socket terminal
//con-samtec:SSW-131-02-S-T=CON_THT_MPE094_31x3(:2.54mm grid socket terminal
//con-samtec:SSW-132-02-S-T=CON_THT_MPE094_32x3(:2.54mm grid socket terminal
//con-samtec:SSW-133-02-S-T=CON_THT_MPE094_33x3(:2.54mm grid socket terminal
//con-samtec:SSW-134-02-S-T=CON_THT_MPE094_34x3(:2.54mm grid socket terminal
//con-samtec:SSW-135-02-S-T=CON_THT_MPE094_35x3(:2.54mm grid socket terminal
//con-samtec:SSW-136-02-S-T=CON_THT_MPE094_36x3(:2.54mm grid socket terminal
//con-samtec:SSW-137-02-S-T=CON_THT_MPE094_37x3(:2.54mm grid socket terminal
//con-samtec:SSW-138-02-S-T=CON_THT_MPE094_38x3(:2.54mm grid socket terminal
//con-samtec:SSW-139-02-S-T=CON_THT_MPE094_39x3(:2.54mm grid socket terminal
//con-samtec:SSW-140-02-S-T=CON_THT_MPE094_40x3(:2.54mm grid socket terminal
//=CON_THT_MPE156_1x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_2x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_3x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_4x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_5x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_6x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_7x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_8x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_9x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_10x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_11x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_12x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_13x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_14x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_15x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_16x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_17x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_18x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_19x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_20x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_21x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_22x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_23x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_24x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_25x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_26x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_27x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_28x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_29x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_30x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_31x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_32x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_33x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_34x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_35x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_36x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_37x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_38x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_39x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_40x1(:2.00mm grid socket terminal
//=CON_THT_MPE156_1x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_2x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_3x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_4x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_5x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_6x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_7x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_8x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_9x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_10x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_11x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_12x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_13x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_14x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_15x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_16x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_17x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_18x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_19x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_20x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_21x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_22x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_23x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_24x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_25x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_26x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_27x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_28x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_29x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_30x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_31x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_32x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_33x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_34x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_35x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_36x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_37x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_38x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_39x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_40x2(:2.00mm grid socket terminal
//=CON_THT_MPE156_1x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_2x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_3x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_4x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_5x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_6x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_7x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_8x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_9x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_10x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_11x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_12x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_13x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_14x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_15x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_16x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_17x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_18x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_19x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_20x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_21x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_22x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_23x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_24x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_25x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_26x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_27x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_28x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_29x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_30x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_31x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_32x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_33x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_34x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_35x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_36x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_37x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_38x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_39x3(:2.00mm grid socket terminal
//=CON_THT_MPE156_40x3(:2.00mm grid socket terminal
// end assignment
