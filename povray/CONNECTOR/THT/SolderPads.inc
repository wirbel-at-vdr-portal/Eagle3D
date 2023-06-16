/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Solder Pads rectangular shape, with one hole and one slot.
 *
 * Arguments in same meaning & order as given in datasheets, www.osterrath.de
 *    B1 - width of wire part
 *    B2 - width of pcb part
 *    L2 - length of pcb part
 *    L3 - length of wire part
 *    L1 - total length (L2+L3)
 *    S - thickness
 * 16.06.2023, -wk
 ******************************************************************************/
#macro SP_Type1(B2,L2,L3,B1,L1,S)
  difference {
     #local d = 0.555 * 2.5;
     #local L4 = 0.35 * 5.5;
     #local L5 = 0.65 * 5.5;
     union {
        box {
           <-B1/2, 0,-S/2>
           <+B1/2,L3,+S/2>
           }
        box {
           <-B2/2,         0,-S/2>
           <+B2/2,-(L2-B2/2),+S/2>
           }
        cylinder {
           <0,-(L2-B2/2),-S/2>
           <0,-(L2-B2/2),+S/2>
           B2/2
           }
        }
     cylinder {
        <0,L4,-S/2-0.1>
        <0,L4,+S/2+0.1>
        d/2
        }
     cylinder {
        <0,L5+d/2,-S/2-0.1>
        <0,L5+d/2,+S/2+0.1>
        d/2
        }
     box {
        <-d/2,L5+d/2,-S/2-0.1>
        <+d/2,L3+0.1,+S/2+0.1>
        }
     texture {
        col_silver
        }
     translate <0,0.2,0>
     }
#end


#macro CON_THT_SolderPad_LSP10() SP_Type1(1.0,3.0,5.5,2.5, 8.5,0.5) #end // www.osterrath.de, 60-1493-11
#macro CON_THT_SolderPad_LSP11() SP_Type1(1.1,3.5,5.8,3.0, 9.0,0.5) #end // no type or details in lbr
#macro CON_THT_SolderPad_LSP13() SP_Type1(1.4,4.0,6.0,3.5,10.0,0.6) #end // www.osterrath.de, 60-1055-11


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//solpad:LSP10=CON_THT_SolderPad_LSP10(:Solder Pad 1.0mm drill
//solpad:LSP11=CON_THT_SolderPad_LSP11(:Solder Pad 1.1mm drill
//solpad:LSP13=CON_THT_SolderPad_LSP13(:Solder Pad 1.3mm drill
// end assignment
