/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * male DIN-41617 header.
 * J.Bartels@arcor.de, www.mec-krefeld.de
 *
 * modified, 15.06.2023, -wk
 ******************************************************************************/
#macro DIN41617(Pins)

  #macro aPIN(DO,DU,R,HO,HU,L)
     union {
        intersection {
           torus {
              R, DO/2
              rotate <0,0,90>
              translate <0,HO-R,-R>
              }
           box {
              <+DO/2,HO-R   ,DO/2>
              <-DO/2,HO+DO/2,-R  >
              }
           }
     cylinder {
        <0,-HU      ,0>
        <0,+HO-R-0.1,0>
        DU/2
        }
     cone {
        <0,HO-R-0.1,0> DU/2
        <0,HO-R    ,0> DO/2
        }
     cylinder {
        <0,HO,-L+1>
        <0,HO,-R  >
        DO/2
        }
     cone {
        <0,HO,-L+1> (DO/2)
        <0,HO,-L  > (DO/2-0.3)
        }
     }
  #end

  #macro PIN41617_ROW(Pins)
     union {
        #local PinTop = object {
           aPIN(1,0.8,1.2,1.6+3.8,3.3,13.9+2.5)
           translate <0,0,1.25>
           }
        #local PinBottom = object {
           aPIN(1,0.8,1.2,1.6,3.3,13.9)
           translate <0,0,-1.25>
           };
        GRID(PinTop   ,5,Pins / 2.0 - 0.5,1)
        GRID(PinBottom,5,Pins / 2.0 + 0.5,1)
        translate <0,0,4.5/2+2.5>
        texture {
           col_gold
           }
        }
  #end

  union {
     #local A = (Pins-1)*2.5+15.6;
     #local D = (Pins-1)*2.5+10;
     #local E = Pins*2.5;

     PIN41617_ROW(Pins)
     box {
        <-E/2,  0,-4.5/2>
        <+E/2,8.5,+4.5/2>
        }
     //Befestigungs-Ohren
     difference {
        box {
           <A/2,0,-4.5/2>
           <E/2,4.2,8.1-4.5/2>
           }
        intersection {
           cylinder {
              <D/2,-1    ,4.5/2>
              <D/2,+1+4.2,4.5/2>
              1.6
              }
           box {
              <D/2-1.6,-1    ,4.5/2-1.4>
              <D/2+1.6,+1+4.2,4.5/2+1.4>
              }
           }
        box {
           <-(A-E-5)/2,-1    ,0         >
           <0         ,+1+4.2,8.1-4.5+10>
           rotate <0,20,0>
           translate <E/2,0,4.5/2>
           }
        }
     difference {
        box {
           <-A/2,0,-4.5/2>
           <-E/2,4.2,8.1-4.5/2>
           }
        intersection {
           cylinder {
              <-D/2,-1,4.5/2>
              <-D/2,1+4.2,4.5/2>
              1.6
              }
           box {
              <-D/2+1.6,-1    ,4.5/2-1.4>
              <-D/2-1.6,+1+4.2,4.5/2+1.4>
              }
           }
        box {
           <(A-E-5)/2,-1    ,0         >
           <0        ,+1+4.2,8.1-4.5+10>
           rotate <0,-20,0>
           translate <-E/2,0,4.5/2>
           }
        }
     pigment {
        Gray80
        }
     }
#end


#macro CON_THT_DIN41617_13() DIN41617(13) #end
#macro CON_THT_DIN41617_21() DIN41617(21) #end
#macro CON_THT_DIN41617_31() DIN41617(31) #end

#macro CON_THT_DIN41617_31_R90()
   object {
      CON_THT_DIN41617_31()
      translate <-2.5,0,+0.5>
      rotate y*-90
      }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_DIN41617_13(:DIN-41617 connector
//=CON_THT_DIN41617_21(:DIN-41617 connector
//=CON_THT_DIN41617_31(:DIN-41617 connector
//con-vg:M617-31=CON_THT_DIN41617_31_R90(:DIN-41617 connector
// end assignment
