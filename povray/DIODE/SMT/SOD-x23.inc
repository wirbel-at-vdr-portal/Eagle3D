/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SOD-123,SOD-323,SOD-523,SOD-723,SOD-923 and variants
 * 02.05.2023, wk
 ******************************************************************************/
#macro SODx23_BASE(value,Type,Variant)
  union {
     #if (Type = "SOD-123")
        #local A  = (1.00 + 1.35)/2; // hoehe
        #local A1 = (0.00 + 0.10)/2; // hoehe über PCB
        #local A2 = (1.05 + 1.15)/2; // A - A1
        #local b  = (0.45 + 0.65)/2; // pin breite
        #local c  = (0.10 + 0.15)/2; // pin material dicke
        #local D  = (1.40 + 1.70)/2; // breite
        #local E  = (2.55 + 2.85)/2; // gehaeuse laenge
        #local E1 = (3.55 + 3.85)/2; // laenge mit pins
        #local L  =  0.50;           // pin laenge
        #local L1 = (0.25 + 0.45)/2; // laenge pin mit rundung
        #local T  = (0 + 8)/2;       // pin winkel zum pcb
     #end
     #if (Type = "SOD-323")
        #local A  = (0.80 + 1.15)/2; // hoehe
        #local A1 = (0.00 + 0.10)/2; // hoehe über PCB
        #local A2 = (0.70 + 1.25)/2; // A - A1
        #local b  = (0.20 + 0.40)/2; // pin breite
        #local c  = (0.10 + 0.15)/2; // pin material dicke
        #local D  = (1.10 + 1.50)/2; // breite
        #local E  = (1.95 + 1.60)/2; // gehaeuse laenge
        #local E1 = (2.85 + 2.50)/2; // laenge mit pins
        #local L  = (E1 - E)/2;      // pin laenge
        #local L1 = (0.25 + 0.40)/2; // laenge pin mit rundung
        #local T  = (0 + 8)/2;       // pin winkel zum pcb
        #if (Variant = "POWERDI")
           #local b  = (0.78 + 0.98)/2; // pin breite
        #end
     #end
     #if (Type = "SOD-523") // vereinfachtes gehause && pins
        #local A  = (0.55 + 0.75)/2; // hoehe
        #local A1 = (0.00 + 0.00)/2; // hoehe über PCB
        #local A2 = (0.55 + 0.75)/2; // A - A1
        #local b  = (0.18 + 0.35)/2; // pin breite
        #local c  = (0.10 + 0.20)/2; // pin material dicke
        #local D  = (0.70 + 0.90)/2; // breite
        #local E  = (1.10 + 1.30)/2; // gehaeuse laenge
        #local E1 = (1.50 + 1.70)/2; // laenge mit pins
        #local L  = (E1 - E)/2;      // pin laenge
        #local L1 = (0.25 + 0.40)/2; // laenge pin mit rundung
        #local T  = (0 + 0)/2;       // pin winkel zum pcb
     #end
     #if (Type = "SOD-723") // vereinfachtes gehause && pins
        #local A  = (0.49 + 0.55)/2; // hoehe
        #local A1 = (0.00 + 0.00)/2; // hoehe über PCB
        #local A2 = (0.49 + 0.55)/2; // A - A1
        #local b  = (0.25 + 0.32)/2; // pin breite
        #local c  = (0.08 + 0.15)/2; // pin material dicke
        #local D  = (0.55 + 0.65)/2; // breite
        #local E  = (0.95 + 1.05)/2; // gehaeuse laenge
        #local E1 = (1.35 + 1.45)/2; // laenge mit pins
        #local L  = (0.13 + 0.27)/2; // pin laenge
        #local L1 = (0.13 + 0.27)/2; // laenge pin mit rundung
        #local T  = (0 + 0)/2;       // pin winkel zum pcb
     #end
     #if (Type = "SOD-923") // vereinfachtes gehause && pins
        #local A  = (0.40 + 0.40)/2; // hoehe
        #local A1 = (0.00 + 0.00)/2; // hoehe über PCB
        #local A2 = (0.40 + 0.40)/2; // A - A1
        #local b  = (0.30 + 0.30)/2; // pin breite
        #local c  = (0.14 + 0.14)/2; // pin material dicke
        #local D  = (0.60 + 0.60)/2; // breite
        #local E  = (0.80 + 0.80)/2; // gehaeuse laenge
        #local E1 = (1.00 + 1.00)/2; // laenge mit pins
        #local L  = (0.10 + 0.10)/2; // pin laenge
        #local L1 = (0.10 + 0.10)/2; // laenge pin mit rundung
        #local T  = (0 + 0)/2;       // pin winkel zum pcb
     #end

     #local FontScale = 0.30 * (E/2.70);

     intersection {
        object {
           IC_SMD_BASE(D,E,A,E1,
                       1,1,0,0,
                       b,b,c,A1,
                       0,0,0,0,
                       FontScale,1,"")
           rotate <0,90,0>
           }
        #if ((Variant = "FL") | (Variant = "POWERDI"))
           // cut standard pins
           box {
             <-E/2, -0.1,-D/2-0.1>
             <+E/2,A+0.1,+D/2+0.1>
             texture {
                col_ic_body_1
                }
             }
        #end
        }
     #if ((Variant = "FL") | (Variant = "POWERDI"))
        // draw flat pins
        GRID(
           box {
              <-(L/2)*1.5,0,-b/2>
              <+(L/2)*1.5,c,+b/2>
              texture {
                 col_silver
                 }
              }
              E+L-0.5*L,2,1
           )
     #end
     #if (Variant = "POWERDI")
        // cooling pad
        box {
           <-(E1/2)    ,0,-(b/2)*0.8>
           <+(E1/2)*0.1,c,+(b/2)*0.8>
           texture {
              col_silver
              }
           }
     #end
     box {
        <-(E/2)*0.9, A-0.05   , -(D/2)*0.9>
        <-(E/2)*0.6, A+A1+0.01, +(D/2)*0.9>
        pigment {
           White * 0.7
           }
        }
     }
#end

#macro DIODE_SMT_SOD123(value)
  SODx23_BASE(value,"SOD-123","")
#end

#macro DIODE_SMT_SOD123FL(value)
  SODx23_BASE(value,"SOD-123","FL")
#end

#macro DIODE_SMT_SOD323(value)
  SODx23_BASE(value,"SOD-323","")
#end

#macro DIODE_SMT_POWERDI323(value)
  SODx23_BASE(value,"SOD-323","POWERDI")
#end

#macro DIODE_SMT_SOD523(value)
  SODx23_BASE(value,"SOD-523","")
#end

#macro DIODE_SMT_SOD723(value)
  SODx23_BASE(value,"SOD-723","")
#end

#macro DIODE_SMT_SOD923(value)
  SODx23_BASE(value,"SOD-923","")
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//diode:SOD123=DIODE_SMT_SOD123(:SMT diode SOD-123
//diode:SOD123FL=DIODE_SMT_SOD123FL(:SMT diode SOD-123 flat pin
//diode:SOD-123_MINI-SMA=DIODE_SMT_SOD123FL(:SMT diode SOD-123 flat pin
//diode:SOD323-R=DIODE_SMT_SOD323(:SMT diode SOD-323
//diode:SOD323-W=DIODE_SMT_SOD323(:SMT diode SOD-323
//diode:SOD323_ST=DIODE_SMT_SOD323(:SMT diode SOD-323
//diode:SOD323R_INFINEON=DIODE_SMT_SOD323(:SMT diode SOD-323
//diode:SOD323W_INFINEON=DIODE_SMT_SOD323(:SMT diode SOD-323
//diode:POWERDI323=DIODE_SMT_POWERDI323(:SMT diode POWERDI-323
//diode:SOD523=DIODE_SMT_SOD523(:SMT diode SOD-523
//diode:SOD523-W=DIODE_SMT_SOD523(:SMT diode SOD-523
//diode:SOD723=DIODE_SMT_SOD723(:SMT diode SOD-723
//diode:SOD923=DIODE_SMT_SOD923(:SMT diode SOD-923
// end assignment
