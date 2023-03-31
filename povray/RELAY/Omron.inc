/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * OMRON G2RL relay 
 * Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
 * Rev. 1.1  23/01/08
 * *****************************************************************************/
#macro SPC_RELAY_G2R_BASE(value,typ)
  union {
     difference {
        #local L=29; // longueur
        #local W=12.7; // largeur
        #local H=16.7; // hauteur+1

        superellipsoid {
           <0.02, 0.02>
           scale <L/2, H/2, W/2>
           }
        box {
           <-1,-1,-W/2> <1,1,+W/2>
           rotate -45*z translate<+L/2,H/2,0>
           }
        box {
           <-L/2-0.1,-H/2+1,-W/2-0.1> <+L/2+0.1,-H/2-1,+W/2+0.1>
           }
        box {
           <-1.5,H/2+0.1,-3.5> <+1.5,H/2-0.5,+3.5>
           translate -5*x
           }
        translate (H/2-1)*y
        pigment {
           Gray20
           }
        }
     cylinder {
        <-5,H-1,2.25> <-5,H/2-1.5,2.25> 0.5
        pigment {
           Gray20
           }
        }
     cylinder {
        <-5,H-1,-2.25> <-5,H/2-1.5,-2.25> 0.5
        pigment {
           Gray20
           }
        }
     union {
        text {
           ttf global_fontfile_eagle3d "A" 0.05, 0
           scale <1.5,1.5,1> rotate<90,0,0> translate<-L/2+1,H-0.95,+W/2-4>
           }
        text {
           ttf global_fontfile_eagle3d "G" 0.05, 0
           scale <3,3,1> rotate<90,0,0> translate<-L/2+4.5,H-0.95,+W/2-4.8>
           }
        text {
           ttf global_fontfile_eagle3d "B" 0.05, 0
           scale <3,3,1> rotate<90,0,0> translate<-L/2+4.5,H-0.95,+W/2-8>
           }
        text {
           ttf global_fontfile_arial_bold "OMRON" 0.05, 0
           scale <2,2,1> rotate<90,0,0> translate<-2,H-0.95,+W/2-2.4>
           }
        text {
           ttf global_fontfile_arial_bold "JAPAN" 0.05, 0
           scale <1.5,1.5,1> rotate<90,0,0> translate<+7,H-0.95,+W/2-2.4>
           }
        text {
           ttf global_fontfile_arial value 0.05, 0
           scale <3,3.5,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-7.7>
           }
        text {
           ttf global_fontfile_arial_bold "2817Y1" 0.05, 0
           scale <1.5,1.5,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-9.3>
           }
        text {
           ttf global_fontfile_arial_bold "16A / 250V~ / AC1" 0.05, 0
           scale <1.5,1.5,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-11.1>
           }
        text {
           ttf global_fontfile_arial_bold "°" 0.05, 0
           scale <3,3,1> rotate<90,0,0> translate<-L/2+1.5,H-0.95,+W/2-13>
           }
        box {
           <-L/2+1,H-0.95,-0.05> <-7,H-1,+0.05>
           translate +1.3*z
           }
        box {
           <+7,H-0.95,-0.05> <+L/2-2,H-1,+0.05>
           translate +0.8*z
           }
        box {
           <+7,H-0.95,-0.05> <+8.5,H-1,+0.05>
           translate -0.3*z
           }
        box {
           <+9,H-0.95,-0.05> <+10.5,H-1,+0.05>
           translate -0.3*z
           }
        box {
           <+11,H-0.95,-0.05> <+12.5,H-1,+0.05>
           translate -0.3*z
           }
        union {
           box {
              <-1,H-0.95,-0.05> <+1,H-1,+0.05>
              translate +0.5*z
              }
           box {
              <-1,H-0.95,-0.05> <+1,H-1,+0.05>
              translate -0.5*z
              }
           box {
              <-0.05,H-0.95,-0.5> <+0.05,H-1,+0.5>
              translate +1*x
              }
           box {
              <-0.05,H-0.95,-0.5> <+0.05,H-1,+0.5>
              translate -1*x
              }
           box {
              <-0.05,H-0.95,-0.5> <+0.05,H-1,-2.5>
              }
           box {
              <-0.05,H-0.95,+0.5> <+0.05,H-1,+2.5>
              }
           translate <-L/2+3,0,-1.5>
           }
        pigment {
           Gray50
           }
        }
     box {
        <+0.4,0,-0.25> <-0.4,-4,+0.25>
        translate<-12.5,0,-3.5> texture {
           col_silver
           }
        }
     box {
        <+0.4,0,-0.25> <-0.4,-4,+0.25>
        translate<-12.5,0,+3.5> texture {
           col_silver
           }
        }
     #switch (typ)
        #case (0)
           text {
              ttf global_fontfile_arial "G2RL-1A" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+23.5,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,+3.25> texture {
                 col_silver
                 }
              }
           #break //First case ends

        #case (1)
           text {
              ttf global_fontfile_arial "G2RL-1" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+23.5,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+16.5,0,-3.25> texture {
                 col_silver
                 }
              }
           #break //Second case ends

        #case (2)
           text {
              ttf global_fontfile_arial "G2RL-1A-E" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,-3.25> texture {
                 col_silver
                 }
              }
           #break //Third case ends

        #case (3)
           text {
              ttf global_fontfile_arial "G2RL-1-E" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+15,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+15,0,-3.25> texture {
                 col_silver
                 }
              }
           #break //Fourth case ends

        #case (4)
           text {
              ttf global_fontfile_arial "G2RL-2A" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,-3.25> texture {
                 col_silver
                 }
              }
           #break //fifth case ends

        #case (5)
           text {
              ttf global_fontfile_arial "G2RL-2" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+20,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+25,0,-3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+15,0,+3.25> texture {
                 col_silver
                 }
              }
           box {
              <+0.4,0,-0.25> <-0.4,-4,+0.25>
              translate<-12.5+15,0,-3.25> texture {
                 col_silver
                 }
              }
           #break //sixth case ends

        #else
           text {
              ttf global_fontfile_arial "G2RL" 0.05, 0
              pigment {
                 Gray50
                 }
              scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>
              }
        #end // End of conditional part

     #if (typ=0)              //because origine offset in the footprint
        #local tl=10.16-1.27;
     #else
        #local tl=10.16;
     #end

     translate <tl,0,0>
     }
#end


#macro SPC_RELAY_G2RL_1A(value)
   SPC_RELAY_G2R_BASE(value,0)
#end
#macro SPC_RELAY_G2RL_1(value)
   SPC_RELAY_G2R_BASE(value,1)
#end
#macro SPC_RELAY_G2RL_1A_E(value)
   SPC_RELAY_G2R_BASE(value,2)
#end
#macro SPC_RELAY_G2RL_1_E(value)
   SPC_RELAY_G2R_BASE(value,3)
#end
#macro SPC_RELAY_G2RL_2A(value)
   SPC_RELAY_G2R_BASE(value,4)
#end
#macro SPC_RELAY_G2RL_2(value)
   SPC_RELAY_G2R_BASE(value,5)
#end


/*******************************************************************************
 * Omron Relay G6D
 * Anderas Fecht
 * *****************************************************************************/
#macro SPC_RELAY_G6D(value)
  union {
     difference {
     box {
        <-8.75,0.5,-3.25> <8.75,12,3.25>
        }
     // Body
     box {
        <-8,11.8,-2.5> <-7,12.5,2.5>
        }
     // Pin 1 Mark
     cylinder {
        < 0,11.7,0>  < 0 12.5,0> 0.8
        }
     //Angusszapfenloch
     }
  cylinder {
     < 0,11.5,0>  < 0 12.1,0> 0.3
     }
  //Angusszapfen
  difference {
     box {
        <-9.25,0.5,-1.5> <-7,3,1.5>
        }
     box {
        <-9.3,1,-1.0> <-7,3.1,1.0>
        }
     }
  // Snapin
  difference {
     box {
        <9.25,0.5,-1.5> <7,3,1.5>
        }
     box {
        <9.3,1,-1.0> <7,3.1,1.0>
        }
     }

  // Snapin
  box {
     <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125 >
     texture {
        col_silver
        }
     translate<-7.62,0,-2.54>
     }
  box {
     <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125 >
     texture {
        col_silver
        }
     translate< 7.62,0,-2.54>
     }
  box {
     <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125 >
     texture {
        col_silver
        }
     translate< 2.54,0,-2.54>
     }
  box {
     <-0.25,0.5,-0.125> <0.25,-min(4.1,(pin_length+pcb_height)),0.125 >
     texture {
        col_silver
        }
     translate<-5.08,0, 2.54>
     }

  text {
     ttf besch_font "OMRON" 0.1, 0
     pigment {
        White
        }
     scale 1.5 rotate<90,0,0> translate<-6,12.01,1.2>
     }
  // Value on top surface
  text {
     ttf besch_font value 0.1, 0
     pigment {
        White
        }
     scale 1.5 rotate<90,0,0> translate<-6,12.01,-2.2>
     }
  // Value on top surface
  text {
     ttf besch_font "OMRON" 0.1, 0
     pigment {
        White
        }
     scale 1.75 translate<-7,9,-3.26>
     }
  // Markings on vertical front face
  text {
     ttf besch_font value 0.1, 0
     pigment {
        White
        }
     scale 1.75 translate<-7,6,-3.26>
     }
  // Markings on vertical front face
  pigment {
     Gray20
     }
  rotate<0,-90,0>
  }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//relay:G2RA=SPC_RELAY_G2RL_1A(:OMRON G2RL Relay
//relay:G2R=SPC_RELAY_G2RL_1(:OMRON G2RL Relay
//relay:G2REA=SPC_RELAY_G2RL_1A_E(:OMRON G2RL Relay
//relay:G2RE=SPC_RELAY_G2RL_1_E(:OMRON G2RL Relay
//relay:G2R2A=SPC_RELAY_G2RL_2A(:OMRON G2RL Relay
//relay:G2R2=SPC_RELAY_G2RL_2(:OMRON G2RL Relay
//=SPC_RELAY_G6D(:Omron Relay G6D
// end assignment
