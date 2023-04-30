/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/




/********************************************************************************************************************************************
// Joerg Bredendiek
// SMD-Diodengehaeuse SOD123/323/523
// Parameter: Laenge, Breite, Hoehe des Kunststoffkoerpers, Laenge incl. Pins, Breite der Anschluesse.Pindicke
********************************************************************************************************************************************/
#macro DIODE_SMD_SOD123_BASE(L,B,H,LG,BP,DP)
union{
   difference{
      box{<-L/2,0.2,-B/2><L/2,H,B/2>}
      box{<0,0,-B><H,H,B> rotate<0,0,10> translate<L/2,H/2+DP/2,0>}
      box{<0,0,-B><-H,H,B> rotate<0,0,-10> translate<-L/2,H/2+DP/2,0>}
      box{<0,0,-B><H,-H,B> rotate<0,0,-10> translate<L/2,H/2-DP/2,0>}
      box{<0,0,-B><-H,-H,B> rotate<0,0,10> translate<-L/2,H/2-DP/2,0>}
      box{<-L,0,0><L,H,H> rotate<-10,0,0> translate<0,H/2+DP/2,B/2>}
      box{<-L,0,0><L,H,-H> rotate<10,0,0> translate<0,H/2+DP/2,-B/2>}
      box{<-L,0,0><L,-H,H> rotate<10,0,0> translate<0,H/2-DP/2,B/2>}
      box{<-L,0,0><L,-H,-H> rotate<-10,0,0> translate<0,H/2-DP/2,-B/2>}
      box{<0,0,-B><1.2,1.5*DP,B> translate<-L/2,0,0>}
      box{<0,0,-B><-1.2,1.5*DP,B> translate<L/2,0,0>}}

   box{<-L/2+L/10,H,-B/2+B/10><-L/2+L/10+L/10,H+0.01,B/2-B/10> pigment{White}}

   box{<-1, 0, -BP/2><1, DP, BP/2> translate<-(LG/2-1), 0, 0> texture{col_silver}}
   box{<-1, 0, -BP/2><1, DP, BP/2> translate< (LG/2-1), 0, 0> texture{col_silver}}

   pigment{Gray20}}
#end

#macro DIODE_SMD_SOD123()
DIODE_SMD_SOD123_BASE(2.6, 1.6, 1.1, 3.5, 0.65, 0.2)
#end
#macro DIODE_SMD_SOD323()
DIODE_SMD_SOD123_BASE(1.7, 1.25, 1, 2.5, 0.35, 0.2)
#end
#macro DIODE_SMD_SOD523()
DIODE_SMD_SOD123_BASE(1.6, 1.8, 0.6, 1.6, 0.3, 0.15)
#end

/*
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
     #local t  = (0 + 8)/2;       // pin winkel zum pcb
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
     #local t  = (0 + 8)/2;       // pin winkel zum pcb
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
     #local t  = (0 + 0)/2;       // pin winkel zum pcb
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
     #local t  = (0 + 0)/2;       // pin winkel zum pcb
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
     #local t  = (0 + 0)/2;       // pin winkel zum pcb
  #end
*/


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//SOD64 Gehaeuse liegend
********************************************************************************************************************************************/
#macro DIODE_SOD64_BASE(value, L, BD, BL)
union{

   //Beschriftung
   intersection{                                                                                                      
      sphere{<0,0,0> BD/2+0.01 scale<BL/BD,1,1>  pigment{Gray30}}                                                               
      union{                                                                                                           
         text {ttf besch_font value 3, 0  translate<-BL/2+1.2,-0.4,-BD/2-0.5> rotate<90,0,0>} 
         pigment{Gray30}
      }  
         translate<0, 2.5, 0>                                                                                                         
   }  
                  
        //ring
   intersection{                                                                                                      
      sphere{<0,0,0> BD/2+0.01 scale<BL/BD,1,1>  pigment{Gray30}}                                                               
      cylinder{<-BL/2+0.5, 0, 0><-BL/2+1, 0, 0> BD/2+0.05 pigment{Black} }
         translate<0, 2.5, 0> 
        }
                          
        // koerper          
   union{
      cylinder{<-BL/2, 0, 0>< BL/2, 0, 0> 0.5 texture{col_silver} }  
      sphere{<0,0,0> BD/2 scale<BL/BD,1,1> pigment{LightBlue} finish { phong 0.5 }}
      translate<0, 2.5, 0>
   }

   // anschluesse
   union{
           // pin unterteil
      #if  (pin_short=off)
         cylinder{<-L/2,0,0><-L/2,-12,0>0.3 }
         cylinder{< L/2,0,0>< L/2,-12,0>0.3 }
      #else
         cylinder{<-L/2,0,0><-L/2,-1*(pin_length+pcb_height),0>0.3 }
         cylinder{< L/2,0,0>< L/2,-1*(pin_length+pcb_height),0>0.3 }
      #end
           //pin oberteil                 
           #declare bends1=array[3] {<0, 2, 0>,  <90, 0.5, 0>,  <0,4,0> }  
           object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,0,0> translate<-L/2,0,0>}               
           object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,180,0> translate< L/2,0,0>}               
      texture{col_silver}
   }
}
#end

#macro DIODE_SOD64_1(value)
DIODE_SOD64_BASE(value, 10.16, 4.5, 5)
#end
#macro DIODE_SOD64_2(value)
DIODE_SOD64_BASE(value, 12.7, 4.5, 5)
#end
#macro DIODE_SOD57_3(value)
DIODE_SOD64_BASE(value, 10.16, 3.8, 6.1)          
#end
#macro DIODE_SOD61_A(value)
DIODE_SOD64_BASE(value, 10.16, 2.5, 5.5)   
#end
#macro DIODE_SOD61_B(value)
DIODE_SOD64_BASE(value, 15.24, 2.5, 8.7)
#end
#macro DIODE_SOD61_C(value)
DIODE_SOD64_BASE(value, 17.78, 2.5, 11.5)
#end
#macro DIODE_SOD61_D(value)
DIODE_SOD64_BASE(value, 15.24, 2.5, 9.9)
#end
#macro DIODE_SOD61_E(value)
DIODE_SOD64_BASE(value, 20.32, 2.5, 13.5)
#end

