/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * PCB Standard Terminal Block, Wire to Board, 5mm grid
 * Author: Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
 *
 * 20220422 wk: renamed macro from CON_ARK_5MM (Anreihklemme) to
 *              CON_TERMINALBLOCK_5mm, converted to GRID()
 *
 * NOTE: available from multiple suppliers, ie. CAMBLOCK CTB1202/BK
 ******************************************************************************/
#macro CON_TERMINALBLOCK_PIN()
  union {
     cylinder{<0,-3,0><0,1.1,0>0.4 texture{col_silver}}
     cone{<0,-3,0>0.4<0,-3.5,0>0.1 texture{col_silver}}
     difference {
        box{<-2.54,0,-4><2.54,10,4>}
        box{<-2.04,1,-4.01><2.04,6,3>}
        box{<-0.75,-0.1,-4.01><0.75,1.1,1>}
        box{<-2.6,5,0><2.6,0,-3> rotate<30,0,0> translate<0,7,-4>}
        box{<-2.6,5,0><2.6,0,3> rotate<-30,0,0> translate<0,7,4>}
        cylinder{<0,5.9,0><0,10.1,0>1.4}
        cone{<0,9,0>1.4<0,10.1,0>1.8}
        }
     superellipsoid{<1,0.1> rotate<90,0,0> scale<1,2.3,1> texture{col_silver} translate<0,7,0>}
     difference {
        superellipsoid{<1,0.1> rotate<90,0,0> scale<1.3,0.5,1.3> texture{col_silver} translate<0,9.5,0>}
        box{<0.25,0,-2><-0.25,1,2>rotate<0,rand(global_seed)*180,0> translate<0,9.8,0>}
        }
     difference {
        box{<-2,1.1,-2.5><2,5.9,2.5>}
        cylinder{<0,3.5,-2.6><0,3.5,2.6>1.4}
        cylinder{<0,3.5,0><0,6,0>1.4}
        texture{col_silver}
        }
     pigment{Gray60}
     translate<0,0.2,0>
     }
#end

/*******************************************************************************
 * Grundmakro fuer Anreihklemme 5mm
 ******************************************************************************/
#macro CON_TERMINALBLOCK_5mm_base(j)
  union {
     GRID(CON_TERMINALBLOCK_PIN(),5.08,j,1)
     union {
        #local i = 0;
        #while(i<j)
            text {ttf besch_font str(j-i,0,0) 0.2,0  scale<3,3,3> rotate<30,0,0> translate<-i*5.08-1.27,7.21,-4> translate<0,0.3,0.1> pigment{Black}}
            #local i=i+1;
        #end
        translate<(i-1)*5.08 -j*2.54+2.54,0,0>
        }
     }
#end

#macro CON_TERMINALBLOCK_5mm_2()
  CON_TERMINALBLOCK_5mm_base(2)
#end

#macro CON_TERMINALBLOCK_5mm_3()
  CON_TERMINALBLOCK_5mm_base(3)
#end

#macro CON_TERMINALBLOCK_5mm_4()
  CON_TERMINALBLOCK_5mm_base(4)
#end

#macro CON_TERMINALBLOCK_5mm_5()
  CON_TERMINALBLOCK_5mm_base(5)
#end

#macro CON_TERMINALBLOCK_5mm_6()
  CON_TERMINALBLOCK_5mm_base(6)
#end

#macro CON_TERMINALBLOCK_5mm_7()
  CON_TERMINALBLOCK_5mm_base(7)
#end

#macro CON_TERMINALBLOCK_5mm_8()
  CON_TERMINALBLOCK_5mm_base(8)
#end

#macro CON_TERMINALBLOCK_5mm_9()
  CON_TERMINALBLOCK_5mm_base(9)
#end

#macro CON_TERMINALBLOCK_5mm_10()
  CON_TERMINALBLOCK_5mm_base(10)
#end

#macro CON_TERMINALBLOCK_5mm_11()
  CON_TERMINALBLOCK_5mm_base(11)
#end

#macro CON_TERMINALBLOCK_5mm_12()
  CON_TERMINALBLOCK_5mm_base(12)
#end
