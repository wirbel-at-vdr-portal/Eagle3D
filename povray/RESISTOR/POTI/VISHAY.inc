/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Trimmer VISHAY Spectrol Series 64
 * - col   colour variant
 * - Type  type identifier, see below
 * 19.04.2023, wk
 ******************************************************************************/
#macro RES_DIS_TRIM_SPECTROL1_BASE(X,Y,Z,col,Type)
  union {
     #local horizontal = off;
     #local screw_hor = off;

     // spectrol poti variants
     #if (Type = "64X")
         #local y1 = +1.27;
         #local y2 = +1.27;
         #local screw_hor = on;
     #end
     #if (Type = "64Z")
         #local y1 = +1.27;
         #local y2 = -1.27;
         #local screw_hor = on;
     #end
     #if (Type = "64W")
         #local y1 = -1.27;
         #local y2 = -1.27;
     #end
     #if (Type = "64Y")
         #local y1 = -1.27;
         #local y2 = +1.27;
     #end
     #if (Type = "64P")
         #local y1 = -1.27;
         #local y2 = +1.27;
         #local horizontal = on;
         #local screw_hor = off;
     #end
     #if (Type = "S64Y")
         #local y1 = -1.27;
         #local y2 = +1.27;
     #end
     #if (Type = "S64W")
         #local y1 = 0;
         #local y2 = 0;
     #end

     union {
        difference { // body
           Round_Box(
              <-X/2,0,-Y/2>
              <+X/2,Z,+Y/2>
              0.2 0
              )
           box {
              <-(X-1)/2,-0.01,-(Y+0.1)/2>
              <+(X-1)/2,+0.25,+(Y+0.1)/2>
              }
           pigment {
              col
              }
           rotate<0,0,0>
           }

        difference { // screw
           cylinder {
              <0,0,0> <0,1.32,0> 1.015
              }
           box {
              <1.5,0.7,0.2> <-1.5,2.5,-0.2>
              }
           texture {
              col_silver
              }
           #if (screw_hor = on)
              rotate <0,75,90>
              translate <-X/2,Z-1.6,-Y/2+1.3>
           #else
              rotate <0,75,0>
              translate <-3.1,Z,+Y/2-1.3>
           #end
           }
        text {
           ttf besch_font value 0.1,0
           scale <1.4,1.4,1.4>
           pigment {
              Black
              }
           rotate <-270,180,0>
           translate <X/2-1.0, Z+0.1, Y/2-3.0>
           }
        text {
           ttf besch_font Type 0.1,0
           scale <1.4,1.4,1.4>
           pigment {
              Black
              }
           rotate <-270,180,0>
           translate <X/2-6.0, Z+0.1, Y/2-3.0>
           }
        text {
           ttf besch_font "3  2  1"  0.1,0
           scale <1.5,1.5,1.5>
           pigment {
              Black
              }
        rotate <0,180,0>
        translate <X/2-1.75, 0.52, Y/2+0.1>
        }
        #if (horizontal = on)
            rotate <+90,0,180>
            translate <0,2.5,-6>
        #end
        }
     union { // pins
        cylinder {
           <-2.54,1,y1> <-2.54,-3,y1> 0.25
           }
        cylinder {
           <+2.54,1,y1> <+2.54,-3,y1> 0.25
           }
        cylinder {
           <0,1,y2> <0,-3,y2> 0.25
           }
        texture {
           col_silver
           }
        }
     }
#end

#macro RES_THT_TRIM_64Y(value)
  RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,"64Y")
  rotate <0,-90,0>
  translate <-1.27,0,0>
#end

#macro RES_THT_TRIM_64W(value)
  RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,"64W")
  rotate <0,-90,0>
#end

#macro RES_THT_TRIM_64X(value)
  RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,"64X")
  rotate <0,90,0>
  translate <0.2,0,0>
#end

#macro RES_THT_TRIM_64Z(value)
  RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,"64Z")
  rotate <0,90,0>
  translate <-1.27,0,0>
#end

#macro RES_THT_TRIM_64P(value)
  RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,"64P")
  rotate <0,90,0>
  translate <1.27,0,0>
#end



/*******************************************************************************
 * Spectrol Series S64
 * - col   colour variant
 * - Type  type identifier, see below
 * 20.04.2023, wk
 ******************************************************************************/
#macro RES_DIS_TRIM_SPECTROL2_BASE(X,Y,Z,col,Type)
  union {
     object {
        RES_DIS_TRIM_SPECTROL1_BASE(X,Y,Z,col,Type)
        }
     sphere {
        <-X/2+4.75, Z+5.85,Y+.01>  2.5
        scale <1.70,0.5,0.01>
        pigment {
           col
           }
        translate <0,0,2.40>
        }
     text {
        ttf besch_font "Spectrol" 0.1,0
        scale <1.5,1.5,1.5>
        pigment {
           Black
           }
        rotate <0,180,0>
        translate <X/2-1.2, Z-2.3, Y/2+0.1>
        }
     rotate <0,180,0>
     }
#end

#macro RES_THT_TRIM_S64Y(value)
  RES_DIS_TRIM_SPECTROL2_BASE(9.52,4.83,9.52,OldGold,"S64Y")
#end

#macro RES_THT_TRIM_S64W(value)
  RES_DIS_TRIM_SPECTROL2_BASE(9.52,4.83,9.52,OldGold,"S64W")
  translate <0,0,1.27>
#end



/*******************************************************************************
 * VISHAY TRIMMER T7YA && T7YB
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1  25/12/05
 ******************************************************************************/
#macro RES_DIS_TRIM_T7_BASE(Typetext,Value)
  #local Bluetrim = rgb <0, 0.2, 1>;
  #local Bluestamp = rgb <0, 0, 0.5>;
  union {
     union {  
        union {
           difference {
              //body 
              union {
                 cylinder {
                    <0,0,0> <0,5.86,0> 3.5
                    pigment {
                       Bluetrim
                       }
                    }
                 // Marking
                 intersection {
                    cylinder {
                       <0,0,0> <0,5.86,0> 3.5
                       }
                    text {
                       ttf global_fontfile_arial Typetext 1.5, 0
                       pigment {
                          White
                          }
                       scale 1.5
                       rotate <0,0,90>
                       translate <0.5,1.3,-4>
                       } // Marking
                    pigment {
                       White
                       }
                    }
                 intersection {
                    cylinder {
                       <0,0,0> <0,5.86,0> 3.5
                       }
                    text {
                       ttf global_fontfile_arial Value 1.5, 0
                       pigment {
                          White
                          }
                       scale 1.5
                       rotate <0,0,90>
                       translate <0.5,1.3,-4>
                       rotate <0,-30,0>
                       } // Marking
                    pigment {
                       White
                       }
                    }
                 }
              union {
                 //removal White central part
                 cylinder {
                    <0,3,0> <0,6,0> 2.3
                    }
                 //grade stamps
                 box {
                    <-0.25,5.8,-2.5><+0.25,7,-3.3>
                    }
                 box {
                    <-2.5,5.8,-0.25><-3.3,7,+0.25>
                    }
                 box {
                    <+2.5,5.8,-0.25><+3.3,7,+0.25>
                    }
                 box {
                    <-0.15,5.8,-2.5><+0.15,7,-3.3>
                    rotate +30*y
                    }
                 box {
                    <-0.15,5.8,-2.5><+0.15,7,-3.3>
                    rotate +60*y
                    }
                 box {
                    <-0.15,5.8,-2.5><+0.15,7,-3.3>
                    rotate +120*y
                    }
                 box {
                    <-0.25,5.8,-2.5><+0.25,7,-3.3>
                    rotate +135*y
                    }
                 box {
                    <-0.15,5.8,-2.5><+0.15,7,-3.3>
                    rotate -30*y
                    }
                 box {
                    <-0.15,5.8,-2.5><+0.15,7,-3.3>
                    rotate -60*y
                    }
                 box {
                    <-0.15,5.8,-2.5><+0.15,7,-3.3>
                    rotate -120*y
                    }
                 box {
                    <-0.25,5.8,-2.5><+0.25,7,-3.3>
                    rotate -135*y
                    }

                 #local i=0; 
                 #while (i<45)
                    box {
                       <-0.15,5.7999-(i*0.00001),-2.65> <+0.15,7,-3.3>
                       rotate (135+i*2)*y
                       pigment {
                          Blue
                          }
                       } 
                    #local i=i+1;
                 #end

                 //Base
                 cylinder {
                    <0,-0.01,0> <0,0.4,0> 2.3
                    }
                 #local i=0; 
                 #while (i<3)
                    box {
                       <-0.6,-0.01,-0.6><-5,0.4,-4>
                       rotate (120*i)*y
                       }
                    box {
                       <+0.6,-0.01,-0.6><+5,0.4,-4>
                       rotate (120*i)*y
                       }
                    #local i=i+1;
                 #end
                 pigment {
                    Bluestamp
                    } //stamping color
                 }
              }
           difference {                       
              //White central part with stamped arrow
              cylinder {<0,3,0> <0,6,0> 2.3 }   
              union {
                 prism {5.8 7 4 <0.6, -0.5>, <0, -1.6>, <-0.6, -0.5>, <0.6, -0.5>}  
                 box {<-0.25,5.801,-1><+0.25,7,1.5>}  
                 }
              pigment {
                 Gray80
                 }
              }
           #if(Typetext = "T7YB")
              rotate -45*y
              translate <-0.3182,0,0.3182>
           #end
           }
        #local hpin=4.5;
        #if (Typetext = "T7YA")
           box {<-0.25,0,-0.2><+0.25,-min(hpin,(pin_length+pcb_height)),+0.2> translate -2.54*z  texture { Aluminum }}
           box {<-0.25,0,-0.2><+0.25,-min(hpin,(pin_length+pcb_height)),+0.2> translate -2.54*x  texture { Aluminum }}
           box {<-0.25,0,-0.2><+0.25,-min(hpin,(pin_length+pcb_height)),+0.2> translate +2.54*x  texture { Aluminum }}
        #else //pins T7YB  
           union {
              box {<-0.25,0,-0.2><+0.25,-min(hpin,(pin_length+pcb_height)),+0.2> texture { Aluminum }}
              box {<-0.25,0,-0.2><+0.25,-min(hpin,(pin_length+pcb_height)),+0.2> translate <-1.8,0,+1.8>  texture { Aluminum }}
              box {<-0.25,0,-0.2><+0.25,-min(hpin,(pin_length+pcb_height)),+0.2> translate <+1.8,0,+1.8>  texture { Aluminum }}
              rotate -45*y
              }
        #end
        }
     }
#end

#macro RES_THT_TRIM_T7_YA(value)
  RES_DIS_TRIM_T7_BASE("T7YA",value)
#end

#macro RES_THT_TRIM_T7_YB(value)
  RES_DIS_TRIM_T7_BASE("T7YB",value)
#end



/*******************************************************************************
 * SP19 Resistor Trimmer
 * wk
 ******************************************************************************/
#macro RES_THT_TRIM_SP19L(value)
  union {
     #local VishayBlue = color red 0.0 green 0.4453 blue 0.73;

     difference {
        cylinder {
           <-8.25,4.8,0> <-9.75,4.8,0> 1.25
           }
        box {
           <-9.15,5.1,-2> <-10,4.5,+2>
           }   
        texture {
           T_Brass_2A
           }
        }
     difference {
        box {
           <-8.25    ,   0,-2.35> <+10.75    ,+6.4,+2.35>
           }  // case
        box {
           <-8.25+0.8,-0.1,-2.36> <+10.75-0.8,+0.5,+2.36>
           }
        pigment {
           VishayBlue
           }
        }

     #local hpin = -min(4.5,(pin_length+pcb_height));

     union {
        text {
           ttf global_fontfile_arial "T18" 0.1, 0
           scale 2
           rotate <90,180,0>
           translate <+8,6.45,-0.4>
           }
        text {
           ttf global_fontfile_arial value 0.1, 0
           scale 2
           rotate <90,180,0>
           translate <+8,6.45,+1.6>
           }
        text {
           ttf global_fontfile_arial "3" 0.1, 0
           scale 2
           rotate <90,180,0>
           translate <-5,6.45,-0.4>
           }
        text {
           ttf global_fontfile_arial "0302" 0.1, 0
           scale 2
           rotate <90,180,0>
           translate <-1.8,6.45,+1.6>
           }
        text {
           ttf global_fontfile_eagle3d "0" 0.1, 0
           scale 2
           rotate <90,180,0>
           translate <+2,6.45,-0>
           }
        pigment {Black}
        }
     scale x*19/18
     translate <-2,0,0>
     }
#end



/*******************************************************************************
 * Vishay T18 Resistor Trimmer
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0 29/12/05
 ******************************************************************************/
#macro RES_THT_TRIM_T18(value)
  union {
     #local VishayBlue = color red 0.0 green 0.4453 blue 0.73;
     difference {
        cylinder {
           <-8.25,4.8,0> <-9.75,4.8,0> 1.25
           }
        box {
           <-9.15,5.1,-2> <-10,4.5,+2>
           }
        texture { T_Brass_2A }
        }
     difference {
        box { <-8.25,0,-2.35> <+10.75,+6.4,+2.35> }  // case
        box { <-8.25+0.8,-0.1,-2.36> <+10.75-0.8,+0.5,+2.36> }
        pigment { VishayBlue }
        }
     #local hpin = -min(4.5,(pin_length+pcb_height));
     difference {
        union {
           prism { 0 0.2 5 <-0.5,+0.5>, <-0.1,-5>,<+.1,-5>, <+0.5,+0.5>,<-0.5,+0.5> rotate -90*x translate 1.27*z         pigment { Silver } }
           prism { 0 0.2 5 <-0.5,+0.5>, <-0.1,-5>,<+.1,-5>, <+0.5,+0.5>,<-0.5,+0.5> rotate -90*x translate <-5.1,0,-1.27> pigment { Silver } }
           prism { 0 0.2 5 <-0.5,+0.5>, <-0.1,-5>,<+.1,-5>, <+0.5,+0.5>,<-0.5,+0.5> rotate -90*x translate <+7.6,0,-1.27> pigment { Silver } }
           }
        box {
           <-10,hpin,-3> <+10,-10,+3>
           pigment { Silver }
           }
        }
     union {
       text { ttf global_fontfile_arial "T18"  0.1, 0 scale 2 rotate<90,180,0> translate<+8,6.45,-0.4>}
       text { ttf global_fontfile_arial value  0.1, 0 scale 2 rotate<90,180,0> translate<+8,6.45,+1.6>}
       text { ttf global_fontfile_arial "3"    0.1, 0 scale 2 rotate<90,180,0> translate<-5,6.45,-0.4>}
       text { ttf global_fontfile_arial "0302" 0.1, 0 scale 2 rotate<90,180,0> translate<-1.8,6.45,+1.6>}
       text { ttf global_fontfile_eagle3d "0"  0.1, 0 scale 2 rotate<90,180,0> translate<+2,6.45,-0>}
       pigment { Black }
       }
     rotate 180*y
     }
#end



/*******************************************************************************
 * Vishay TSM4 series
 * 5 mm Square Surface Mount Miniature Trimmers Multi-Turn Cermet Sealed
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  26/03/06
 ******************************************************************************/
#macro TSM4series_BASE(Type,Lg)
  union {
     difference {
        box {
           <-2.4,0.2,-1.75> <+2.4,Lg+0.2,+1.75>
           }
        cylinder {
           <1.55,4,0.95> <1.55,Lg+0.3,0.95> 0.75
           }
        box {
           <-2.1,0.5,0> <+2.1,Lg+0.2-0.3,-1.8>
           }
        pigment {
           Gray70
           }
        finish {
           diffuse 0.5
           specular 0.5
           ambient (0.1 * global_ambient_mul)
           }
        }
     difference {
        cylinder {
           <1.55,4.4,0.95> <1.55,Lg+0.2,0.95> 0.73
           }
        box {
           <1.55-0.2,4.5,-1.75> <1.55+0.2,Lg+0.3,+1.75>
           }
        texture {
           col_gold
           }
        }
     box {
        <-2.1,0.5,0> <+2.1,Lg+0.2-0.3,-1.74>
        texture {
           pigment {
              Brown
              }
           finish {
              diffuse 0.5
              specular 0.5
              ambient (0.1 * global_ambient_mul)
              }
           normal {
              waves 0.1 frequency 3000.0
              scale 800.0
              }
           }
        }
     text {
        ttf global_fontfile_eagle3d "0" 0.01, 0
        pigment {
           Black
           }
        scale 1.5
        rotate <0,180,0>
        translate <-0.6,+3.1,+1.76>
        }
     // Marking
     text {
        ttf global_fontfile_arial value 0.05, 0
        pigment {
           Black
           }
        scale 1.6
        rotate <0,180,0>
        translate <+2,3.1,+1.76>
        }
     // Marking
     text {
        ttf global_fontfile_arial "9941" 0.01, 0
        pigment {
           Black
           }
        scale 1.6
        rotate <0,180,0>
        translate <+2,1.3,+1.76>
        }
     // Marking
     #if (Type = "TSM4 YL")
        #local pin = union {
           box {
              <-0.3, 0, -0.75> <+0.3, 0.2, +0.75>
              }
           pigment {
              Silver
              }
           }

        object {
           pin
           translate <-1.25,0,-1.8>
           }
        object {
           pin
           translate <+1.25,0,-1.8>
           }
        object {
           pin
           translate <0,0,+1.8>
           }
     #end
     #if (Type = "TSM4 YJ")
        #local pin = union {
           box {
              <-0.3, 0, -0.3> <+0.3, 0.2, +0.3>
              }
           box {
              <-0.3, 0, -0.15> <+0.3, 1, -0.3>
              }
           pigment {
              Silver
              }
           }

        object {
           pin
           translate <-1.25,0,-1.6>
           }
        object {
           pin
           translate <+1.25,0,-1.6>
           }
        object {
           pin
           rotate 180*y
           translate <0,0,+1.6>
           }
     #end
     #if (Type = "TSM4 ZL")
        #local pin = union {
           box {
              <-0.3, -0.75,0> <+0.3, +0.75,0.2>
              }
           pigment {
              Silver
              }
           }

        object {
           pin
           translate <-1.25,0.05,-1.95>
           }
        object {
           pin
           translate <+1.25,0.05,-1.95>
           }
        object {
           pin
           translate <0,4.75,-1.95>
           }
        rotate <-90,180,0>
        translate <0,1.95,-Lg/2-0.1>
     #end
     #if (Type = "TSM4 ZJ")
        #local pin = union {
           box {
              <-0.3, 0, -0.3> <+0.3, 0.2, +0.3>
              }
           box {
              <-0.3, 0, -0.15> <+0.3, 1, -0.3>
              }
           pigment {
              Silver
              }
           }

        object {
           pin
           translate <-1.25,0,-1.6>
           }
        object {
           pin
           translate <+1.25,0,-1.6>
           }
        object {
           pin
           rotate 180*z
           translate <0,5,-1.6>
           }
        rotate <-90,180,0>
        translate <0,1.95,-Lg/2-0.1>
     #end
     }
#end

#macro RES_SMT_TRIM_TSM4_YL(value)
  TSM4series_BASE("TSM4 YL",5.1)
#end

#macro RES_SMT_TRIM_TSM4_YJ(value)
  TSM4series_BASE("TSM4 YJ",5.1)
#end

#macro RES_SMT_TRIM_TSM4_ZL(value)
  TSM4series_BASE("TSM4 ZL",4.6)
#end

#macro RES_SMT_TRIM_TSM4_ZJ(value)
  TSM4series_BASE("TSM4 ZJ",4.6)
#end

// same style of trimmers, by Nidec Copal.
#macro RES_SMT_TRIM_SM42A(value)
  TSM4series_BASE("TSM4 ZJ",4.6)
  rotate <0,-90,0>
#end

#macro RES_SMT_TRIM_SM42B(value)
  TSM4series_BASE("TSM4 ZL",4.6)
  rotate <0,-90,0>
#end

#macro RES_SMT_TRIM_SM42W(value)
  TSM4series_BASE("TSM4 YJ",5.1)
#end

#macro RES_SMT_TRIM_SM42X(value)
  TSM4series_BASE("TSM4 YL",5.1)
#end



/*******************************************************************************
 * Vishay 5mm Square Surface Mount Miniature Trimmers Single-Turn
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  12/04/06
 ******************************************************************************/
#macro TS53series_BASE (Type)
  union {
     difference {
        box {
           <-2.5, +0.4, -2.5>, <2.5, 2.7, 2.5>
           }
        box {
           <-2.3, +0.1, -2.6>, <2.3, 2.5, 2.6>
           }
        box {
           <-0.1, +1.4, -1.25>, <0.21, 2.8, 1.25>
           translate -2.5*x
           }
        box {
           <-0.1, +1.4, -1.25>, <0.21, 2.8, 1.25>
           translate +2.5*x
           }
        cylinder {
           <0, 2.4, 0>, <0, 2.8, 0>, 1.25
           }
        pigment {
           color red 0.758 green 0.694 blue 0.48
           }
        }
     text {
        ttf global_fontfile_eagle3d "0" 0.01, 0
        pigment {
           Black
           }
        scale 1
        rotate <90,0,0>
        translate <+1,+2.701,-2.1>
        }
     // Marking
     text {
        ttf global_fontfile_arial value 0.05, 0
        pigment {
           Black
           }
        scale 1
        rotate <90,0,0>
        translate <-2.2,+2.701,-2.1>
        }
     // Marking
     text {
        ttf global_fontfile_arial "99" 0.01, 0
        pigment {
           Black
           }
        scale 1
        rotate <90,0,0>
        translate <-2.2,+2.701,+1.5>
        }
     // Marking
     text {
        ttf global_fontfile_arial "18" 0.01, 0
        pigment {
           Black
           }
        scale 1
        rotate <90,0,0>
        translate <+1.2,+2.701,+1.5>
        }
     // Marking
     difference {
        union {
           box {
              <-2.3, +0.2, -2.5>, <2.3, 2.5, 2.5>
              }
           box {
              <-0.05, +1.4, -1.25>, <0.21, 2.5, 1.25>
              translate -2.5*x
              }
           box {
              <-0.05, +1.4, -1.25>, <0.21, 2.5, 1.25>
              translate +2.5*x
              }
           }
        box {
           <-0.25, +2.2, -1>, <0.25, 2.7, 1>
           }
        box {
           <-1, +2.2, -0.25>, <1, 2.7, 0.25>
           }
        pigment {
           color red 0.937 green 0.878 blue 0.776
           }
        finish {
           diffuse 0.5
           specular 0.5
           ambient (0.1 * global_ambient_mul)
           }
        }
     union {
        box {
           <-0.45, 0, -2.5> <+0.45, 1.4, -2.7>
           translate -1.15*x
           }
        box {
           <-0.45, 0, -2.5> <+0.45, 1.4, -2.7>
           translate +1.15*x
           }
        box {
           <-0.5, 0, +2.5> <+0.5, 1.4, +2.7>
           }
        #if (Type = "TS53YL")
           box {
              <-0.45, 0, -2.5> <+0.45, 0.2, -3.2>
              translate -1.15*x
              }
           box {
              <-0.45, 0, -2.5> <+0.45, 0.2, -3.2>
              translate +1.15*x
              }
           box {
              <-0.5, 0, +2.5> <+0.5, 0.2, +3.2>
              }
        #end
        #if (Type = "TS53YJ")
           box {
              <-0.45, 0, -2.7> <+0.45, 0.2, -1.2>
              translate -1.15*x
              }
           box {
              <-0.45, 0, -2.7> <+0.45, 0.2, -1.2>
              translate +1.15*x
              }
           box {
              <-0.5, 0, +2.7> <+0.5, 0.2, +1.2>
              }
        #end
        pigment {
           Silver
           }
        }
     }
#end

#macro RES_SMT_TRIM_TS53YL(value)
  TS53series_BASE("TS53YL")
#end

#macro RES_SMT_TRIM_TS53YJ(value)
  TS53series_BASE("TS53YJ")
#end




/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:RTRIM64W=RES_THT_TRIM_64W(:Vishay Spectrol 64 series trim resistor
//rcl:RTRIM64X=RES_THT_TRIM_64X(:Vishay Spectrol 64 series trim resistor
//rcl:RTRIM64Y=RES_THT_TRIM_64Y(:Vishay Spectrol 64 series trim resistor
//rcl:RTRIM64Z=RES_THT_TRIM_64Z(:Vishay Spectrol 64 series trim resistor
//rcl:RTRIM64P=RES_THT_TRIM_64P(:Vishay Spectrol 64 series trim resistor
//pot:S64W=RES_THT_TRIM_S64W(:Vishay Spectrol S64 series trim resistor
//pot:S64Y=RES_THT_TRIM_S64Y(:Vishay Spectrol S64 series trim resistor
//rcl:RTRIM3339P=RES_THT_TRIM_T7_YA(:Vishay trimmer T7YA
//=RES_THT_TRIM_T7_YB(:Vishay trimmer T7YB
//pot:SP19L=RES_THT_TRIM_SP19L(:Vishay SP19 Resistor Trimmer
//rcl:RTRIMT18,RTRIM43P=RES_THT_TRIM_T18(:Vishay T18 Resistor Trimmer
//=RES_SMT_TRIM_TSM4_YL(:Vishay TSM4 series SMT trim resistor
//=RES_SMT_TRIM_TSM4_YJ(:Vishay TSM4 series SMT trim resistor
//=RES_SMT_TRIM_TSM4_ZL(:Vishay TSM4 series SMT trim resistor
//rcl:RTRIM5X=RES_SMT_TRIM_TSM4_ZJ(:Vishay TSM4 series SMT trim resistor
//SM-42/43A=RES_SMT_TRIM_SM42A(:SMT trim resistor SM42/SM43:
//SM-42/43B=RES_SMT_TRIM_SM42B(:SMT trim resistor SM42/SM43:
//SM-42/43W=RES_SMT_TRIM_SM42W(:SMT trim resistor SM42/SM43:
//SM-42/43X=RES_SMT_TRIM_SM42X(:SMT trim resistor SM42/SM43:
//rcl:RTRIM4G/J=RES_SMT_TRIM_TS53YL(:Vishay TS53YL SMT trim resistor
//=RES_SMT_TRIM_TS53YJ(:Vishay TS53YJ SMT trim resistor
// end assignment 
