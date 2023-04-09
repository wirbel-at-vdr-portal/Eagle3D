/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

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

#macro RES_DIS_TRIM_T7_YA(value)
  RES_DIS_TRIM_T7_BASE("T7YA",value)
#end

#macro RES_DIS_TRIM_T7_YB(value)
  RES_DIS_TRIM_T7_BASE("T7YB",value)
#end



/*******************************************************************************
 * SP19 Resistor Trimmer
 * wk
 ******************************************************************************/
#macro R_POTI_SP19L(value)
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
#macro RES_DIS_TRIM_T18(value)
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
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:RTRIM3339P=RES_DIS_TRIM_T7_YA(:Vishay trimmer T7YA
//=RES_DIS_TRIM_T7_YB(:Vishay trimmer T7YB
//pot:SP19L=R_POTI_SP19L(:Vishay SP19 Resistor Trimmer
//rcl:RTRIMT18,RTRIM43P=RES_DIS_TRIM_T18(:Vishay T18 Resistor Trimmer
// end assignment
