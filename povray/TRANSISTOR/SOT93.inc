/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Macro TR_SOT93_base - SOT93 Transistor package
 * SOT93 package for horizontal and vertical mounting.
 *
 * Author      : Sven-Mortem Resch (sven-mortem.resch(replace with at)gmx.de
 * Version     : 1.0, modified 18.03.2006
 * M: mounting position, "H" horizontal, "V" vertical
 * O: Z offset
 * S: Y offset
 * B: Pin bend position in Y
 * V: marking (Value)
 ******************************************************************************/
#macro TR_SOT93_base(M, O, S, B, V, L)
  union {
     #local Horizontal =! (strcmp(strupr(M), "H") );
     #local ww = 1.3; 
     #local wt = 0.78;

     difference {
        union {
           box {<-7.5, 0, -2.45><7.5, 12.2, 2.45>} //Koerper
           pigment{Gray30}
           }
        union {
           cylinder{<0, 3, -2><0, 3, -2.5> 1.2}                                          //Vertiefung in der Mitte
           cone {<-7, 3, 1.08>, 1, <-7, 3, -2.5>, 1.2}                                   //Aussparung links
           cone {<7, 3, 1.08>, 1, <7, 3, -2.5>, 1.2}                                     //Aussparung rechts
           box {<-8, 0, 0><8, 1, -4> rotate <-7,0,0> translate <0, 12.1, 1.08>}          //Abschraegung Gehaeuse oben
           box {<-7.6, 0, 0><7.6, 1, -2.6> rotate <7,0,0> translate <0, -1, 0>}          //Abschraegung Gehaeuse unten vorn
           box {<-7.6, 0, 0><7.6, 1, -2.6> rotate <-7,0,0> translate <0, -0.65, 2.6>}    //Abschraegung Gehaeuse unten hinten
           box {<-0.5, 0, -2.6><0.5, 12.2, 2.5> rotate <0,-7,0> translate <-7.87, 0, 0>} //Abschraegung Gehaeuse links
           box {<-0.5, 0, -2.6><0.5, 12.2, 2.5> rotate <0,7,0> translate <7.87, 0, 0>}   //Abschraegung Gehaeuse rechts
           pigment{Gray30}
           }
        } 

     difference {
        box {<-7.5, 12.2, 2.45><7.5, 20.35, 1.08>}                        //Kuehlfahne
        cylinder {<0, 16.2, 2.5><0, 16.2, 0>, 2}                          //Bohrung Kuehlfahne
        box {<0, 0, 0><3, 3, 3> rotate <0,0,45> translate <-7.5,18.23,0>} //Abschraegung links Kuehlfahne
        box {<0, 0, 0><3, 3, 3> rotate <0,0,45> translate < 7.5,18.23,0>} //Abschraegung rechts Kuehlfahne
        texture {col_silver}
        }

     //Pins
     #if(pin_short=off)
        #local p_height = 8.85;
     #else
        #local p_height = pcb_height+S;
     #end

     #if (Horizontal = no)
         //Pins vertikale Version
         union {
            union {
               box{<0, 0, 0><1.8, -1.8, wt>}
               box{<0, -1.8, 0><1.3, -p_height, wt>}
               texture {col_silver}
               }
            union {
               box{<0, 0, 0><1.8, -1.8, wt>}
               box{<0.25, -1.8, 0><1.55, -p_height, wt>}
               texture {col_silver}
               translate <5.55, 0, 0>
               }
            union {
               box{<0, 0, 0><1.8, -1.8, wt>}
               box{<0.5, -1.8, 0><1.8, -p_height, wt>}
               texture {col_silver}
               translate <11.1, 0, 0>
               }
            translate <-6.45,0,-wt/2>
            }
     #else
         //Pins horizontale Version
         union {
            difference {
               union {
                  box{<0, 0, 0><1.8, -1.8, wt>}
                  box{<0, -1.8, 0><ww, -B-wt, wt>}
                  box{<0, -B-(wt/2),wt/2><ww, -B-(wt/2)-wt, 4+S>}
                  box{<0, -B, wt/2><1.3, -B-0.9, (wt/2)+0.9>} 
                  cylinder{<0, -B-wt, wt/2><1.3, -B-wt, wt/2>, wt/2}
                  }
               cylinder{<-0.1, -B, wt+(wt/2)><1.4, -B, wt+(wt/2)>, wt/2}
               }
            difference {
               union {
                  box{<0, 0, 0><1.8, -1.8, wt>}
                  box{<0.25, -1.8, 0><ww+0.25, -B-wt, wt>}
                  box{<0.25, -B-(wt/2),wt/2><ww+0.25, -B-(wt/2)-wt, 4+S>}
                  box{<0.25, -B, wt/2><1.55, -B-0.9, (wt/2)+0.9>} 
                  cylinder{<0.25, -B-wt, wt/2><1.55, -B-wt, wt/2>, wt/2} 
                  }
               cylinder{<0.24, -B, wt+(wt/2)><1.55, -B, wt+(wt/2)>, wt/2}
               translate <5.55, 0, 0>
               }
            difference {
               union {
                  box{<0, 0, 0><1.8, -1.8, wt>}
                  box{<0.5, -1.8, 0><ww+0.5, -B-wt, wt>}
                  box{<0.5, -B-(wt/2),wt/2><ww+0.5, -B-(wt/2)-wt, 4+S>}
                  box{<0.5, -B, wt/2><1.8, -B-0.9, (wt/2)+0.9>} 
                  cylinder{<0.5, -B-wt, wt/2><1.8, -B-wt, wt/2>, wt/2}
                  }
               cylinder{<0.49, -B, wt+(wt/2)><1.81, -B, wt+(wt/2)>, wt/2}
               translate <11.1, 0, 0>
               }
            texture {col_silver}
            translate <-6.45,0,-wt/2>    
            translate <0,L,0>
            }
      #end 

     //Beschriftung
     text {ttf global_fontfile_arial V 1, 0 scale 2.5 translate <-4.5,6,-2.455> pigment{Gray70}}
 
     //In endgueltige Position bringen
     #if (Horizontal = yes)
         rotate <90,0,0> translate <0,2.45+S, O>
     #else
         translate <0,1.8+S, O>
     #end
  }
#end


#macro TR_SOT93_H(value)
  TR_SOT93_base("H",-3.3,0,3.6,value, 0)  
#end

#macro TR_SOT93_H1(value)
  TR_SOT93_base("H",-3.3,0,3.6,value,2.54)
#end

#macro TR_SOT93_H2(value)
TR_SOT93_base("H",-3.3-3.0,0,3.6,value,0)
#end

#macro TR_SOT93_V(value)
  TR_SOT93_base("V",-3.18,0,0,value, 0)
#end
