/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Static Relay SK series from Celduc
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0 30/12/05
 * *****************************************************************************/
#macro SPC_RELAY_CELDUC_SK_BASE(Value,L,W,H,L1,W1,Led,Type)
  #local stp=1.27;
  union {
     difference {
        // case
        union {
           superellipsoid {
              <0.08, 0.08>
              scale <L/2, H/2+1, W/2> translate <0, H/2-1, -W/2+(W-W1)> pigment {
                 Gray20
                 }
              }
           #if (Led=1)
              merge {
                 cylinder {
                    <0,0.75,0> <0,5.48,0> 1.5
                    }
                 sphere {
                    <0,5.48,0> 1.5
                    }
                 pigment {
                    Red
                    }
                 translate <L/2-5,H-5.5,-W/2+(W-W1)>
                 }
           #end
           }
        union {
           box {
              <-L/2-1,0,-W1-1> <+L/2+1,-3,-W1+W+1>
              }
           // delete base
           box {
              <-L/2+1.6,-0.1,-W1-1> <+L/2-1.6,0.8,-W1+W+1>
              }
           #if (Type=1)
              box {
                 <-L/2-1,0,-5> <+L/2+1,2,+5>
                 rotate -45*x translate<0,H-0.2,-W/2>
                 }
              box {
                 <-L/2+4,1,-W/2-1> <+L/2-4,H-1.7,-W/2-2>
                 }
           #end
           pigment {
              Gray20
              }
           }
        translate (L/2-12.7-L1)*x
        }

     #if (Type=1)
        box {
           <-L/2+4,1,-W/2-1> <+L/2-4,H-1.7,-W/2-1.45>
           translate (L/2-12.7-L1)*x pigment {
              Black
              }
           }
        box {
           <-L/2+3,2,+1.4> <+L/2-3,H-2,+1.7>
           translate (L/2-12.7-L1)*x pigment {
              White
              }
           }
        box {
           <-L/2+6,5,+1.4> <+L/2-6,H-5,+1.71>
           translate (L/2-12.7-L1)*x pigment {
              Gray25
              }
           }
     #end

     // pins
     cylinder {
        <-10*stp,2,0> <-10*stp,-min(6.5,(pin_length+pcb_height)),0> .5
        texture {
           col_silver
           }
        }
     cylinder {
        <-6*stp,2,0> <-6*stp,-min(6.5,(pin_length+pcb_height)),0> .5
        texture {
           col_silver
           }
        }
     cylinder {
        <+4*stp,2,0> <+4*stp,-min(6.5,(pin_length+pcb_height)),0> .5
        texture {
           col_silver
           }
        }
     cylinder {
        <+12*stp,2,0> <+12*stp,-min(6.5,(pin_length+pcb_height)),0> .5
        texture {
           col_silver
           }
        }

     #if (Type=1)
        #local H=H-1;
     #end

     // marking
     text {
        ttf global_fontfile_arial_bold "celduc" 0.1, 0
        pigment {
           White
           }
        scale 5 rotate<0,0,0> translate<-L/2+8,H-6.1,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial "France" 0.1, 0
        pigment {
           White
           }
        scale 4 rotate<0,0,0> translate<-L/2+25,H-6.1,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial "input" 0.1, 0
        pigment {
           White
           }
        scale 3 rotate<0,0,0> translate<-12,H-16.5,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial "output" 0.1, 0
        pigment {
           White
           }
        scale 3 rotate<0,0,0> translate<+5,H-16.5,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial_bold Value 0.1, 0
        pigment {
           White
           }
        scale 4 rotate<0,0,0> translate<-10,H-11.5,-W1-0.01>
        }

     #if (Type=0)
        text {
           ttf global_fontfile_eagle3d "I" 0.1, 0
           pigment {
              White
              }
           scale 3 rotate<0,0,0> translate<-18,H-10,-W1-0.01>
           }
        // canada UL marking
        text {
           ttf global_fontfile_eagle3d "A" 0.1, 0
           pigment {
              White
              }
           scale 3 rotate<0,0,0> translate<-17,H-14,-W1-0.01>
           }
        // UL marking
        text {
           ttf global_fontfile_eagle3d "E" 0.1, 0
           pigment {
              White
              }
           scale 5 rotate<0,0,0> translate<+12,H-12.5,-W1-0.01>
           }
        // CE marking
        text {
           ttf global_fontfile_eagle3d "B" 0.1, 0
           pigment {
              White
              }
           scale 5 rotate<0,0,0> translate<-3,H-18.5,-W1-0.01>
           }
        // DVE marking
     #end

     #local l1=3;
     cylinder {
        <-12.7,l1,-W1-0.01> <-12.7,l1,-W1> 0.5
        pigment {
           White
           }
        }
     cylinder {
        <-12.7+4*stp,l1,-W1-0.01> <-12.7+4*stp,l1,-W1> 0.5
        pigment {
           White
           }
        }
     cylinder {
        <-12.7+13*stp,l1,-W1-0.01> <-12.7+13*stp,l1,-W1> 0.5
        pigment {
           White
           }
        }
     cylinder {
        <-12.7+21*stp,l1,-W1-0.01> <-12.7+21*stp,l1,-W1> 0.5
        pigment {
           White
           }
        }
     text {
        ttf global_fontfile_arial "4-" 0.1, 0
        pigment {
           White
           }
        scale 2.8 rotate<0,0,0> translate<-12,l1-1,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial "3+" 0.1, 0
        pigment {
           White
           }
        scale 2.8 rotate<0,0,0> translate<-12+4*stp,l1-1,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial "2" 0.1, 0
        pigment {
           White
           }
        scale 2.8 rotate<0,0,0> translate<-12+13*stp,l1-1,-W1-0.01>
        }
     text {
        ttf global_fontfile_arial "1" 0.1, 0
        pigment {
           White
           }
        scale 2.8 rotate<0,0,0> translate<-12+21*stp,l1-1,-W1-0.01>
        }
     }
#end

#macro SPC_RELAY_CELDUC_SK_ABD(value)
  SPC_RELAY_CELDUC_SK_BASE(value,43.2,10.2,25.4,7.63,7.62,0,0)
#end

#macro SPC_RELAY_CELDUC_SK_AL(value)
  SPC_RELAY_CELDUC_SK_BASE(value,43.2,10.2,25.4,7.63,7.62,1,0)
#end

#macro SPC_RELAY_CELDUC_SK_L(value)
  SPC_RELAY_CELDUC_SK_BASE(value,43.6,6.0,24.5,7.83,4.60,0,1)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_RELAY_CELDUC_SK_ABD(:SKA,B,D Celduc STATIC RELAY
//=SPC_RELAY_CELDUC_SK_AL(:SKA,B,D Celduc STATIC RELAY with LED
//=SPC_RELAY_CELDUC_SK_L(:SKL Celduc STATIC RELAY
// end assignment
