/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * TT electronics/BI technology 25 series trim resistor
 * Bourns Series 3362 series trim resistor
 * written from scratch, 21.04.2023, wk
 ******************************************************************************/
#macro TRIM_25x_BASE(value, Type)
  #local X = 6.86;
  #local Y = 6.86;
  #local Z = 4.83;

  #if (substr(Type,1,2) = "25")
     LogoIndex("BI TECHNOLOGIES")
     #local series = "25";
  #end

  #if (substr(concat(Type, "  "),1,4) = "3362")
     LogoIndex("BOURNS")
     #local series = "3362";
  #end

  union {
     #local len = -(1.5 + 1.6);
     union {
        difference {
           union {
              box {
                 <-X/2,0.25,-Y/2+0.25>
                 <+X/2,   Z,+Y/2     >
                 }
              GRID(
                 union {
                    box {
                       <-0.5/2,0  ,-0.5/2>
                       <+0.5/2,0.6,+0.5/2>
                       translate <0,0,+Y/2-0.25>
                       }
                    box {
                       <-0.5/2,0  ,-0.5/2>
                       <+0.5/2,0.6,+0.5/2>
                       translate <0,0,-Y/2+1.0>
                       }
                    },
                 X-0.5, 2, 1)
              GRID(
                 box {
                    <-0.6/2,0.25,-Y/2     >
                    <+0.6/2,4.00,-Y/2+0.25>
                    },
                 4.6-0.6, 2, 1)
              }
           box {
              <-X/2-0.01,Z-0.21,-Y/2+0.6>
              <+X/2+0.01,Z+0.01,-Y/2-0.1>
              }
           cylinder {
              <0,Z-2.0,0>
              <0,Z+0.1,0>
              2.6/2
              }
           cylinder {
              <0,Z-0.2,0>
              <0,Z+0.1,0>
              3.2/2
              }
           #for(i,-1,1)
              object {
                 Round_Box (
                    <-0.4/2,Z-0.21,+Y/2-0.7>
                    <+0.4/2,Z+0.1,+Y/2-2.0>
                    0.1, 0
                    )
                 rotate y*135*i
                 }
           #end
           #for(i,-4,4)
              object {
                 Round_Box (
                    <-0.4/2,Z-0.2,+Y/2-1.1>
                    <+0.4/2,Z+0.1,+Y/2-2.0>
                    0.1, 0
                    )
                 rotate y*(135/5)*i
                 }
           #end
           GRID(
              box {
                 <-0.5/2,0.00,-Y/2+0.50>
                 <+0.5/2,4.00,-Y/2+0.00>
                 },
              2.54, 3, 1)
           cylinder {
              <-X/2+1.25,Z-0.2,-Y/2+1.25>
              <-X/2+1.25,Z+0.1,-Y/2+1.25>
              0.4/2
              }

           text {
              ttf global_fontfile_eagle3d LOGO_INDEX 1,0
              rotate <-270,0,0>
              scale <1.2,0.1,1.2> 
              translate <X/2-2,Z+0.05,Y/2-1.5>
              }
           text {
              ttf besch_font series 1,0
              scale <1.0,1.0,0.1>
              rotate <-270,0,0>
              translate <-0.6,Z+0.05,-Y/2+1.0>
              #if (series = "3362")
                 translate <-0.5,0,0>
              #end
              }
           #if ((Type = "25RX") | (Type = "3362W") | (Type = "3362Z"))
              text {
                 ttf besch_font "3" 1,0
                 scale <1.0,1.0,0.1>
                 rotate <-270,0,0>
                 translate <-X/2+0.3,Z+0.05,-Y/2+1.0>
                 }
              
              text {
                 ttf besch_font "1" 1,0
                 scale <1.0,1.0,0.1>
                 rotate <-270,0,0>
                 translate <+X/2-1.0,Z+0.05,-Y/2+1.0>
                 }
           #else
              text {
                 ttf besch_font "1" 1,0
                 scale <1.0,1.0,0.1>
                 rotate <-270,0,0>
                 translate <-X/2+0.3,Z+0.05,-Y/2+1.0>
                 }
              
              text {
                 ttf besch_font "3" 1,0
                 scale <1.0,1.0,0.1>
                 rotate <-270,0,0>
                 translate <+X/2-1.0,Z+0.05,-Y/2+1.0>
                 }
           #end
           pigment {
              NavyBlue * 1.5
              }
           }
        difference {
           cylinder {
              <0,Z-2.0,0>
              <0,Z-0.1,0>
              2.6/2
              }
           box {
              <-2.3/2,Z-0.89,-0.64/2>
              <+2.3/2,Z+0.10,+0.64/2>
              }
           box {
              <-0.64/2,Z-0.89,-2.3/2>
              <+0.64/2,Z+0.10,+2.3/2>
              }
           cylinder {
              <-1.2/2,Z-1.0,+1.2/2>
              <-1.2/2,Z+0.1,+1.2/2>
              0.4/2
              }
           cylinder {
              <+1.2/2,Z-1.0,+1.2/2>
              <+1.2/2,Z+0.1,+1.2/2>
              0.4/2
              }
           pigment {
              Gray50
              }
           rotate y*10
           }
        text {
           ttf besch_font value 1.5,0
           pigment {
              Black
              }
           rotate <180,0,0>
           scale <1.0,1.0,0.1>
           translate <-X/2+1,+Y/2-0.5,Z-1.3>
           }
        text {
           ttf besch_font Type 1.5,0
           pigment {
              Black
              }
           rotate <180,0,0>
           scale <1.0,1.0,0.1>
           translate <-X/2+4.5,+Y/2-0.5,Z-1.3>
           #if (series = "3362")
              translate <-0.7,0,0>
           #end
           }
        #if ((Type = "25S") | (Type = "25X") | (Type = "25RX") | (Type = "25V") |
             (Type = "3362M") | (Type = "3362S") | (Type = "3362S") | (Type = "3362W") | (Type = "3362X") | (Type = "3362Z"))
           rotate <-90,0,0>
           translate <0,Y/2,Z/2>
        #end
        }
     union {
        #if (Type = "3362F")
            cylinder {
               <0,0.25,+2.54>
               <0, len,+2.54>
               0.46/2
               }
            cylinder {
               <-2.54,0.25,-2.54>
               <-2.54, len,-2.54>
               0.46/2
               }
            cylinder {
               <+2.54,0.25,-2.54>
               <+2.54, len,-2.54>
               0.46/2
               }
        #end

        #if ((Type = "25P") | (Type = "25S") | (Type = "25X") | (Type = "25RX") |
             (Type = "3362P") | (Type = "3362R") | (Type = "3362S") | (Type = "3362W") | (Type = "3362X") | (Type = "3362Z"))
            cylinder {
               <-2.54,0.25,0>
               <-2.54,len,0>
               0.46/2
               }
            cylinder {
               <0,0.25,+2.54>
               <0,len ,+2.54>
               0.46/2
               }
            cylinder {
               <+2.54,0.25,0>
               <+2.54,len,0>
               0.46/2
               }
            #if ((Type = "25X") | (Type = "25RX") |
                 (Type = "3362R") | (Type = "3362W") | (Type = "3362X"))
                rotate y*180
                translate <0,0,+2.54>
            #end
            #if ((Type != "25P") & (Type != "3362P"))
                translate <0,0,-2.54/2>
            #end
        #end
        #if ((Type = "25U") | (Type = "25V") |
             (Type = "3362U") | (Type = "3362M"))
            cylinder {
               <-2.54,0.25,0>
               <-2.54,len,0>
               0.46/2
               }
            cylinder {
               <0,0.25,0>
               <0,len ,0>
               0.46/2
               }
            cylinder {
               <+2.54,0.25,0>
               <+2.54,len,0>
               0.46/2
               }
        #end
        #if ((Type = "25W") | (Type = "3362H"))
            cylinder {
               <-3.592/2,0.25,-1.796>
               <-3.592/2,len,-1.796>
               0.46/2
               }
            cylinder {
               <0,0.25,0>
               <0,len ,0>
               0.46/2
               }
            cylinder {
               <+3.592/2,0.25,-1.796>
               <+3.592/2,len,-1.796>
               0.46/2
               }
        #end
        texture {
           col_silver
           }
        }
     }
#end


#macro RES_THT_TRIM_25P(value)
  TRIM_25x_BASE(value, "25P")
#end

#macro RES_THT_TRIM_25U(value)
  TRIM_25x_BASE(value, "25U")
#end

#macro RES_THT_TRIM_25W(value)
  TRIM_25x_BASE(value, "25W")
#end

#macro RES_THT_TRIM_25S(value)
  TRIM_25x_BASE(value, "25S")
#end

#macro RES_THT_TRIM_25X(value)
  TRIM_25x_BASE(value, "25X")
#end

#macro RES_THT_TRIM_25RX(value)
  TRIM_25x_BASE(value, "25RX")
#end

#macro RES_THT_TRIM_25V(value)
  TRIM_25x_BASE(value, "25V")
#end

#macro RES_THT_TRIM_B25P(value)
  RES_THT_TRIM_25P(value)
#end

#macro RES_THT_TRIM_B25U(value)
  RES_THT_TRIM_25P(value)
  translate <0,0,-1> // eagle library (pot) package is off by ~1mm
#end

#macro RES_THT_TRIM_B25V(value)
  RES_THT_TRIM_25V(value)
#end

#macro RES_THT_TRIM_3362F(value)
  TRIM_25x_BASE(value, "3362F")
#end

#macro RES_THT_TRIM_3362H(value)
  TRIM_25x_BASE(value, "3362H")
#end

#macro RES_THT_TRIM_3362P(value)
  TRIM_25x_BASE(value, "3362P")
#end

#macro RES_THT_TRIM_3362R(value)
  TRIM_25x_BASE(value, "3362R")
#end

#macro RES_THT_TRIM_3362U(value)
  TRIM_25x_BASE(value, "3362U")
#end

#macro RES_THT_TRIM_3362M(value)
  TRIM_25x_BASE(value, "3362M")
#end

#macro RES_THT_TRIM_3362S(value)
  TRIM_25x_BASE(value, "3362S")
#end

#macro RES_THT_TRIM_3362W(value)
  TRIM_25x_BASE(value, "3362W")
#end

#macro RES_THT_TRIM_3362X(value)
  TRIM_25x_BASE(value, "3362X")
#end

#macro RES_THT_TRIM_3362Z(value)
  TRIM_25x_BASE(value, "3362Z")
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//pot:B25P=RES_THT_TRIM_B25P(:25/3362 series THT trim resistor
//pot:B25U=RES_THT_TRIM_B25U(:25/3362 series THT trim resistor
//=RES_THT_TRIM_25P:25/3362 series THT trim resistor
//=RES_THT_TRIM_25U:25/3362 series THT trim resistor
//=RES_THT_TRIM_25W:25/3362 series THT trim resistor
//=RES_THT_TRIM_25S:25/3362 series THT trim resistor
//=RES_THT_TRIM_25X:25/3362 series THT trim resistor
//=RES_THT_TRIM_25RX:25/3362 series THT trim resistor
//=RES_THT_TRIM_25V:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362F:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362H:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362P:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362R:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362U:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362M:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362S:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362W:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362X:25/3362 series THT trim resistor
//=RES_THT_TRIM_3362Z:25/3362 series THT trim resistor
// end assignment 
