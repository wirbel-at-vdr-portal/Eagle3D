/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Buzzer Grundmakro
 * bearbeitet von Ronny Schulz
 * val_size      Groesse der Beschriftung
 * dis           Abstand der Pins
 * dia           Radius des Buzzers
 * hig           Hoehe des Buzzers
 * hole          Radius des sound emission hole
 * dia_b         Radius des Anschlussdrahtes
 * *****************************************************************************/
#macro ROUND_BUZZER(val_size,dis,dia,hig,hole,dia_b)
  union {
     union {
        cylinder {
           <0,0,0> <0,hig,0> dia
           pigment {
              Gray20
              }
           }
        //Buzzer Koerper
        cylinder {
           <0,hig-1,0> <0,hig+0.1,0> hole
           pigment {
              Black
              }
           }
        //Oeffnung oben
        }
     union {
        //Plus Symbol
        torus {
           (dia-hole)/3.5,0.15
           }
        box {
           <-(dia-hole)/3.5,-0.15,-0.15> <(dia-hole)/3.5,0.15,0.15>
           }
        box {
           <-0.1,-0.15,-(dia-hole)/3.5> <0.15,0.15,(dia-hole)/3.5>
           }
        translate<(dia+hole)/2,hig,0>
        pigment {
           Gray20
           }
        }
     #if (pin_short=off)
        cylinder {
           <0,0,0> <0,-14.5,0> dia_b
           texture {
              col_silver
              }
           translate<dis/2,0,0>
           }
        //Beinchen rechts
        cylinder {
           <0,0,0> <0,-17.5,0> dia_b
           texture {
              col_silver
              }
           translate<-dis/2,0,0>
           }
        //Beinchen links
     #else
        cylinder {
           <0,0,0> <0,-1*(pcb_height+pin_length)-0.2,0> dia_b
           texture {
              col_silver
              }
           translate<dis/2,0,0>
           }
        //Beinchen rechts
        cylinder {
           <0,0,0> <0,-1*(pcb_height+pin_length)-0.2,0> dia_b
           texture {
              col_silver
              }
           translate<-dis/2,0,0>
           }
        //Beinchen links
     #end
     }
#end

#macro SPC_BUZZER_TDB()
  ROUND_BUZZER(1,7.62,12/2,9.5,2.5/2,1/2)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//buzzer:F/TMB=SPC_BUZZER_TDB(:Round THT Buzzer
// end assignment
