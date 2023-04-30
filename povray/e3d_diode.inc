/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/




/********************************************************************************************************************************************
// Joerg Bredendiek
// SMD-Diodengehäuse SOD123/323/523
// Parameter: Länge, Breite, Höhe des Kunststoffkörpers, Länge incl. Pins, Breite der Anschlüsse.Pindicke
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

#macro DIODE_SMD_SOD123_1()
DIODE_SMD_SOD123_BASE(2.6, 1.6, 1.1, 3.5, 0.65, 0.2)
#end
#macro DIODE_SMD_SOD123_3()
DIODE_SMD_SOD123_BASE(1.7, 1.25, 1, 2.5, 0.35, 0.2)
#end
#macro DIODE_SMD_SOD123_5()
DIODE_SMD_SOD123_BASE(1.6, 1.8, 0.6, 1.6, 0.3, 0.15)
#end





/********************************************************************************************************************************************
//SOD87
********************************************************************************************************************************************/
#macro DIODE_SMD_SOD87_BASE(value)
union{
cylinder{<-1.45,0,0><1.45,0,0>0.9}
cylinder{<-1.45,0,0><-1.75,0,0>1.025 texture{col_silver}}
cylinder{<1.45,0,0><1.75,0,0>1.025 texture{col_silver}}
cylinder{<1.1,0,0><0.8,0,0>0.901 pigment{Gray80}}
intersection{
cylinder{<0.7,0,0><-1.5,0,0>0.9001 pigment{White}}
union{
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.95> rotate<0,0,0> pigment{White}}
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.95> rotate<90,0,0> pigment{White}}
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.95> rotate<180,0,0> pigment{White}}}}
rotate<0,180,0> translate<0,1.025,0> pigment{Gray30}}
#end
#macro DIODE_SMD_SOD87(value)
DIODE_SMD_SOD87_BASE(value)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//SOD64 Gehäuse liegend 
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


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//SOD81 Gehäuse liegend 
********************************************************************************************************************************************/
#macro DIODE_SOD81_BASE(value)
union{
   union{

      //Glaskoerper
      union{
         cylinder{<-1.9, 0, 0>< 1.9, 0, 0> 1.05-0.25 }
         cylinder{<-1.65,0, 0>< 1.65,0, 0> 1.05 }
         torus{0.8, 0.25 rotate<0,0,90> translate<-1.65, 0, 0>}
         torus{0.8, 0.25 rotate<0,0,90> translate< 1.65, 0, 0>}
         cone{<0,0,0>0.7 <-1,0,0> 0 translate<-1.8,0,0>}
         cone{<0,0,0>0.7 < 1,0,0> 0 translate< 1.8,0,0>}
         pigment{Col_Glass_General}
      }
      cylinder{<-1.5,0,0><-1.1,0,0> 1.06 pigment{Black} }    //Markierung

      //Beschriftung
      intersection{                                                                                                      
         cylinder{<1.8,0,0><-1.6,0,0>1.06 pigment{Col_Glass_General}}                                                               
         union{                                                                                                           
            text {ttf besch_font value 0.5, 0 scale<0.6,0.6,0.6> translate<-0.8,-0.4,-1.0> rotate<0,0,0> pigment{Black}}  
            text {ttf besch_font value 0.5, 0 scale<0.6,0.6,0.6> translate<-0.8,-0.4,-1.0> rotate<90,0,0> pigment{Black}} 
            text {ttf besch_font value 0.5, 0 scale<0.6,0.6,0.6> translate<-0.8,-0.4,-1.0> rotate<180,0,0> pigment{Black}}
         }                                                                                                              
      }  

      // innenleben
      cylinder{<-1.55, 0, 0>< -0.2, 0, 0> 0.9 pigment{color Red} } 
      cylinder{< 1.55, 0, 0><  0.2, 0, 0> 0.9 pigment{color Red} }
      cylinder{< 0.2,  0, 0>< -0.2, 0, 0> 0.1 texture{col_silver} }
      translate<0, 1.5, 0>
   }

   // anschluesse
   union{
           // pin unterteil
      #if  (pin_short=off)
         cylinder{<-5.08,0,0><-5.08,-12,0>0.3 }
         cylinder{< 5.08,0,0>< 5.08,-12,0>0.3 }
      #else
         cylinder{<-5.08,0,0><-5.08,-1*(pin_length+pcb_height),0>0.3 }
         cylinder{< 5.08,0,0>< 5.08,-1*(pin_length+pcb_height),0>0.3 }
      #end
           //pin oberteil                 
           #declare bends1=array[3] {<0, 1, 0>,  <90, 0.5, 0>,  <0,3,0> }  
           object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,0,0> translate<-5.08,0,0>}               
           object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,180,0> translate< 5.08,0,0>}               
      texture{col_silver}
   }
}
#end

#macro DIODE_SOD81_1(value)
DIODE_SOD81_BASE(value)
#end

