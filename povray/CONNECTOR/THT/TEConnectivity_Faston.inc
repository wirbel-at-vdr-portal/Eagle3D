/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


#macro Faston_Tab(Series)
  difference {
     #switch(Series)
        #case(187) // 4.75mm
           #local W = 0.187 * inch;        
           #local DiaHole = 0.055 * inch;
           #local DiaDist = 0.125 * inch;
           #local Thickness = 0.020 * inch;
           #local Chamfer = 2 * Thickness;
           #local L = 0.250 * inch;
           #local dY = 0.36;
           #local ChamferAngle = 8;
           #break
        #case(250) // 6.35mm
           #local W = 0.250 * inch;        
           #local DiaHole = 0.055 * inch;
           #local DiaDist = 0.125 * inch;
           #local Thickness = 0.032 * inch;
           #local Chamfer = 2 * Thickness;
           #local L = 8.50;
           #local dY = 0.55;
           #local ChamferAngle = 8;
           #break
     #end

     prism {
        -Thickness/2,
        +Thickness/2,
        8
        <0,0>,
        <+W/2,0>,
        <+W/2,L-Chamfer>,
        <+W/2-Chamfer,L>,
        <-W/2+Chamfer,L>,
        <-W/2,L-Chamfer>,
        <-W/2,0>,
        <0,0>
        rotate <0,90,90>
        rotate <0,90,0>
        }
     box {
        <-W/2,-Chamfer,+Thickness/2>
        <+W/2,+Chamfer,-Thickness/2>
        rotate <+ChamferAngle,0,0>
        translate <0,L,-dY>
        }
     box {
        <-W/2,-Chamfer,+Thickness/2>
        <+W/2,+Chamfer,-Thickness/2>
        rotate <-ChamferAngle,0,0>
        translate <0,L,+dY>
        }
     cylinder {
        <0,DiaDist,-1>
        <0,DiaDist,+1>
        DiaHole/2
        }        
     }
#end




/*******************************************************************************
 * Faston 0.187 dual stake terminal
 * TE Connectivity Series 187 part 062221-1
 * 23.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON187_62221()
  union {
     #local Thickness = 0.020 * inch;
     #local T = 0.303 * inch;
     #local W = 0.250 * inch;
     #local H = 0.332 * inch - W;
     #local BendRadius = 1.0;
     #local bx = 0.115 * inch;
     #local by = 0.200 * inch;
     difference {
        union {
           GRID(
              object {
                 Faston_Tab(187)
                 translate <0,H,0>
                 },
              T-Thickness,1,2
              )
           object {
              ARC(BendRadius,Thickness,0,90,W)
              rotate <0,0,-90>
              translate <-W/2,BendRadius+Thickness/2,+T/2-BendRadius-Thickness/2>
              }
           object {
              ARC(BendRadius,Thickness,0,90,W)
              rotate <180,0,-90>
              translate <+W/2,BendRadius+Thickness/2,-T/2+BendRadius+Thickness/2>
              }
           box {
              <-W/2,        0,-T/2+BendRadius>
              <+W/2,Thickness,+T/2-BendRadius>
              }
           GRID(
              box {
                 <-W/2,BendRadius,-Thickness/2>
                 <+W/2,         H,+Thickness/2>
                 },
              T-Thickness,1,2
              )
           }
        box {
           <-bx/2,         -0.01,-0.185*inch/2>
           <+bx/2,Thickness+0.01,+0.185*inch/2>
           }
        }
     GRID(
        cylinder {
           <-bx/2,0,0>
           <+bx/2,0,0>
           Thickness
           }
        0.185*inch,1,2
        )
     GRID(
        box {
           <-bx/2+0.1,Thickness/2,-Thickness/2>
           <+bx/2-0.1,  -by/2+0.1,+Thickness/2>
           }
        0.185*inch-Thickness,1,2
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * TE Connectivity Series 250 part 62409-1
 * 24.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_62409()
  union {
     #local Thickness = 0.032 * inch;
     #local T = 0.295 * inch;
     #local H = (15.8-3.18)-8.50;
     #local h = 5.0;
     #local PinWidth = 0.046 * inch;
     #local PinGrid = 0.200 * inch;
     object {
        Faston_Tab(250)
        translate <0,H,0>
        }
     box {
        <-2, h,-0.3/2>
        <+2,10,+0.3/2>
        }
     box {
        <-T/2,0,-Thickness/2>
        <+T/2,h,+Thickness/2>
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-4,+Thickness/2>
           }
        PinGrid,2,1
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * Vogt Verbindungstechnik 3866G.68
 * 23.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_3866G68()
  union {
     #local Thickness = 0.032 * inch;
     #local T = 8.0;
     #local H = 2.3;
     #local h = 1.0;
     #local PinWidth = 1.0;
     #local PinGrid = 5.0;

     object {
        Faston_Tab(250)
        translate <0,H,0>
        }
     difference {
        box {
           <-T/2,0,-Thickness/2>
           <+T/2,H,+Thickness/2>
           }
        box {
           <-(PinGrid-PinWidth)/2,-0.1,-Thickness/2-0.1>
           <+(PinGrid-PinWidth)/2,   h,+Thickness/2+0.1>
           }
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-4,+Thickness/2>
           }
        PinGrid,2,1
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * Vogt Verbindungstechnik 3866B.68
 * 23.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_3866B68()
  union {
     #local Thickness = 0.032 * inch;
     #local T = 0.250 * inch;
     #local H = 2.4+1.0;
     #local PinWidth = 1.0;
     #local PinGrid = 5.0;
     object {
        CON_THT_FASTON250_3866G68()
        translate <0,2.4,0>
        }
     box {
        <-T/2,    0,-Thickness/2>
        <+T/2,H+0.1,+Thickness/2>
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-4,+Thickness/2>
           }
        PinGrid,2,1
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * TE Connectivity Series 250 part 216843-3
 * 23.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_216843()
  union {
     #local Thickness = 0.032 * inch;
     #local T = 8.0;
     #local H = 2.75;
     #local h = 1.25;
     #local PinWidth = 1.0;
     #local PinGrid = 2.54;
     object {
        Faston_Tab(250)
        translate <0,H+h,0>
        }
     box {
        <-(T-2)/2,  0,-Thickness/2>
        <+(T-2)/2,H+h,+Thickness/2>
        }
     box {
        <-T/2,0,-Thickness/2>
        <+T/2,H,+Thickness/2>
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-4,+Thickness/2>
           }
        PinGrid,3,1
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * Vogt Verbindungstechnik 3867B.68
 * 23.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_3867B68()
  union {
     #local Thickness = 0.032 * inch;
     #local B1 = 8.0;
     #local H = 9.0;
     #local PinWidth = 1.3;
     #local PinGrid = 5.0;

     difference {
        union {
           object {
              Faston_Tab(250)
              translate <0,-8.5/2,0>
              rotate <0,0,-90>
              translate <8.0,H-6.35/2,0>
              }
           box {
              <-B1/2,0,-Thickness/2>
              <+B1/2,H,+Thickness/2>
              }
           }
        box {
           <-2.5,-2.5,-Thickness/2-0.1>
           <+2.5,+2.5,+Thickness/2+.01>
           rotate <0,0,45>
           translate <-4,9,0>
           }
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-3,+Thickness/2>
           }
        PinGrid,2,1
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * Vogt Verbindungstechnik 3868Y.68
 * 23.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_3868Y68()
  union {
     #local Thickness = 0.032 * inch;
     #local B1 = 8.0;
     #local H = 10.0;
     #local PinWidth = 1.1;
     #local PinGrid = 5.0;

     difference {
        union {
           object {
              Faston_Tab(250)
              translate <0,-8.5/2,0>
              rotate <0,0,-90>
              translate <13.3,H-6.35/2,0>
              }
           box {
              < 0,3.7,-Thickness/2>
              <10, 10,+Thickness/2>
              }
           box {
              <-B1/2,0,-Thickness/2>
              <+B1/2,H,+Thickness/2>
              }
           }
        box {
           <-2.5,-2.5,-Thickness/2-0.1>
           <+2.5,+2.5,+Thickness/2+.01>
           rotate <0,0,45>
           translate <-4,10,0>
           }
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-3,+Thickness/2>
           }
        PinGrid,2,1
        )
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * Buerklin 07F255, vendor unknown, vendor part-no 72890
 * 24.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_72890()
  union {
     object {
        Faston_Tab(250)
        translate <0,2,-3+0.81/2>
        }
     difference {
        object {
           BENT_PLANE_OUTER(9.0,2.0,8.3,0.81,0.1,90)
           rotate <0,-90,0>
           translate <0,0,-3>
           }
        box {
           <+4.2/2,-0.1,-1.0>
           <+8.4/2,+0.9,+6.1>
           }
        box {
           <-4.2/2,-0.1,-1.0>
           <-8.4/2,+0.9,+6.1>
           }
        box {
           <-1.5,-0.1,-1.5>
           <+1.5,+0.9,+1.5>
           rotate <0,+30,0>
           translate <+4.2,0,-0.5>
           }
        box {
           <-1.5,-0.1,-1.5>
           <+1.5,+0.9,+1.5>
           rotate <0,-30,0>
           translate <-4.2,0,-0.5>
           }
        }
     object {
        GRID (
           object {
              BENT_PLANE_OUTER(1.0,4.5,1.0,0.81,0.1,90)
              rotate <0,0,180>
              },
           5.0,1,2
           )
        translate <+4.2/2+0.81,0.81,5/2>
        }
     object {
        GRID (
           object {
              BENT_PLANE_OUTER(1.0,4.5,1.0,0.81,0.1,90)
              rotate <0,180,180>
              },
           5.0,1,2
           )
        translate <-4.2/2-0.81,0.81,5/2>
        }
     texture {
        col_silver
        }
     }
#end

/*******************************************************************************
 * Faston 0.250 terminal
 * For packages F061.040 and F061.060, no datasheets. Draw a default terminal.
 *
 * Grid = 5.3, D = 1.0
 * 24.05.2023, -wk
 ******************************************************************************/
#macro CON_THT_FASTON250_default()
  union {
     #local Thickness = 0.032 * inch;
     #local T = 0.295 * inch;
     #local H = (15.8-3.18)-8.50;
     #local h = 5.0;
     #local PinWidth = 1.0;
     #local PinGrid = 5.3;
     object {
        Faston_Tab(250)
        translate <0,H,0>
        }
     box {
        <-2, h,-0.3/2>
        <+2,10,+0.3/2>
        }
     box {
        <-T/2,0,-Thickness/2>
        <+T/2,h,+Thickness/2>
        }
     GRID (
        box {
           <-PinWidth/2, 0,-Thickness/2>
           <+PinWidth/2,-4,+Thickness/2>
           }
        PinGrid,2,1
        )
     texture {
        col_silver
        }
     }
#end







/*******************************************************************************
 * 6.35 Faston terminal
 * Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 du 09/01/06
 ******************************************************************************/
#macro FASTON_BASE()
  union {
     difference {
        union {
           box {
              <-0.4,0,-3.175> <+0.4,+15.8,+3.175>
              rotate <0,0,0>
              translate <0,0,0>
              }
           box {
              <-0.4,0,-3.75> <+0.4,+6.8,+3.75>
              rotate <0,0,0>
              translate <0,0,0>
              }
           }
        union {
           box {
              <-1,-1,-3.2> <+1,+1,+3.2>
              rotate <0,0,45>
              translate <-1.5,16,0>
              }
           box {
              <-1,-1,-3.2> <+1,+1,+3.2>
              rotate <0,0,45>
              translate <+1.5,16,0>
              }
           box {
              <-1,-1,-1> <+1,+1,+1>
              rotate <45,0,0>
              translate <0,16,3.8>
              }
           box {
              <-1,-1,-1> <+1,+1,+1>
              rotate <45,0,0>
              translate <0,16,-3.8>
              }
           box {
              <-1,-1,-1> <+1,+1,+1>
              rotate <45,0,0>
              translate <0,6.9,4.6>
              }
           box {
              <-1,-1,-1> <+1,+1,+1>
              rotate <45,0,0>
              translate <0,6.9,-4.6>
              }
           box {
              <-0.8,-0.1,-2> <+0.8,+3,+2>
              rotate <0,0,0>
              translate <0,0,0>
              }
           box {
              <-0.8,-0.1,-4> <+0.8,+3,-3>
              rotate <0,0,0>
              translate <0,0,0>
              }
           box {
              <-0.8,-0.1,+4> <+0.8,+3,+3>
              rotate <0,0,0>
              translate <0,0,0>
              }
           cylinder {
              -2*x, +2*x, 1
              translate <0, 12, 0>
              }
           text {
              ttf global_fontfile_arial_bold "AMP" 0.1, 0
              scale 1.5
              scale <1,0.6,1>
              rotate <180,+90,0>
              translate <0.45,4.8,1.55>
              }
           text {
              ttf global_fontfile_arial_bold "AMP" 0.1, 0
              pigment {
                 Silver
                 }
              scale 1.5
              scale <1,0.6,1>
              rotate <180,-90,0>
              translate <-0.45,4.8,-1.55>
              }
           }
        }
     texture {
        col_silver
        }
     translate -3*y
     rotate 90*y
     }
#end

#macro CON_THT_FASTON_V()
  FASTON_BASE()
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_FASTON_V(:Faston vertical 6.35 terminal
// end assignment
