/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


#declare e3d_environment = off;   

  





/********************************************************************************************************************************************
// SMD Trimmer Murata TZB4
********************************************************************************************************************************************/
#macro CAP_SMD_TRIM_BASE(L,W,H,LT,WT,HT,P,value)
union{
    
    //Body
    box{<0,0,0><LT,H,W> pigment{rgb(<0.400, 0.320, 0.220>)*1.2} translate<-LT/2,(L-LT)/2,-W/2>}            //GrundkÃ¶rper braun
    
    //Marking
    text{ttf besch_font value 0.1,0 scale L/8 rotate<90,0,0> translate<-LT/4,H+(L-LT)/2+0.01,0> pigment{DarkWood*0.7}}
    
    //
    box{<0,0,0><(L-2*P)-0.3,(L-LT)/2,W> pigment{rgb(<0.400, 0.320, 0.220>)*1.2} translate<-((L-2*P)-0.3)/2,0,-W/2>}
    box{<0,0,0><0.4/exp(-LT/10),0.002,W> pigment{DarkWood*0.7} translate<-LT/2.1,H+(L-LT)/2,-W/2>}        //Markierung
    
    union{
        //rechter Anschluss
        difference{
            box{<0,0,0><-P,HT,WT>}
            box{<0,(L-LT)/2,-0.002><-P-0.002,HT-(L-LT)/2,WT+0.002> translate<-(L-LT)/2,0,0>}
            cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
            cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //rechter Anschlus
        difference{
            cylinder{<-(L-LT)/2,HT-(L-LT)/2,><-(L-LT)/2,HT-(L-LT)/2,WT>(L-LT)/2}
            cylinder{<-3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><-3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<-(L-LT)/2,HT-3*(L-LT)/4,-0.04><-(L-LT),HT-5,WT+0.002>}
            box{<-3*(L-LT)/4,HT-(L-LT)/2,-0.04><-(L-LT),HT-5,WT+0.002>}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //rechter Anschlus
        difference{
            cylinder{<-(L-LT)/2,(L-LT)/2,0><-(L-LT)/2,(L-LT)/2,WT>(L-LT)/2}
            cylinder{<-3*(L-LT)/4,3*(L-LT)/4,-0.04><-3*(L-LT)/4,3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<(-L-LT)/2,3*(L-LT)/4,-0.04><-(L-LT),5,WT+0.002>}
            box{<0,0,-0.04><(L-LT)/2,(L-LT)/2,WT+0.002> translate<-(L-LT),0.75*(L-LT),0>}
            box{<(L-LT)/2,(L-LT)/2,-0.04><(L-LT),L-LT,WT+0.002> translate<-1.75*(L-LT),0,0>}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference{
            box{<0,0,0><P,HT,WT>}
            box{<(L-LT)/2,(L-LT)/2,-0.002><P+0.002,HT-(L-LT)/2,WT+0.002>}
            cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
            cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
            box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
            translate<-L/2-0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference{
            cylinder{<(L-LT)/2,HT-(L-LT)/2,-0.002><(L-LT)/2,HT-(L-LT)/2,WT+0.002>(L-LT)/2}
            cylinder{<3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<(L-LT)/2,HT-3*(L-LT)/4,-0.04><L-LT,HT-5,WT+0.002>}
            box{<3*(L-LT)/4,HT-(L-LT)/2,-0.04><L-LT,HT-5,WT+0.002>}
            box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
            translate<-L/2-0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference{
            cylinder{<(L-LT)/2,(L-LT)/2,-0.002><(L-LT)/2,(L-LT)/2,WT+0.002>(L-LT)/2}
            cylinder{<3*(L-LT)/4,3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<(L-LT)/2,3*(L-LT)/4,-0.04><L-LT,5,WT+0.002>}
            box{<3*(L-LT)/4,(L-LT)/2,-0.04><L-LT,L-LT,WT+0.002>}
            translate<-L/2-0.02,0,-WT/2>
        }
        texture{col_silver}
    }
    
    rotate<0,180,0>
}
#end 
                 

#macro CAP_SMD_TRIM_TZB4(value)

union {
   difference {
     object{CAP_SMD_TRIM_BASE( 3.5/*?*/,
                              4.0/*breite*/,
                              3.0/*hoehe */,
                              3.3/*?*/,
                              1.2/*pinbreite*/,
                              1.0/*pinhoehe*/,
                              0.8,value) /*translate<-2.54,0,0>*/ rotate<0,-90,0>}


     union {
        cylinder{<0,1.5,0><0,5,0> 1.15  /*1.25*/}                           //central hole
       // box{<+0.1,-1,-0.55><-0.1,6,+0.55> translate -2.9*x }    //front pin groove on round side
       // box{<+0.1,-1,-0.6><-0.1,1.1,0.6> translate +2.91*x}     //back pin groove on flat side
        } texture{col_ic_body_1} //pigment{col}

     }
      

   difference {
     //cylinder{<0,2.6,0><0,2.9,0> 1.22  /*1.25*/}
     cylinder{<0,4,0><0,4.5,0> 1.1}                  //metalic axe
     union{
        box{<+0.7,4.1,-0.25>
            <-0.7,4.51,+0.25>}      //axe cross grooves
        box{<-0.25,4.11,-0.7>
            <+0.25,4.51,+0.7>}
        } translate <0,-1.6,0>

     } texture{col_silver}

}

#end




/********************************************************************************************************************************************
 * DC-Power-Connector, SMD
 *******************************************************************************************************************************************/
#macro CON_PWR_RASM722PX()
  union {
     union {
        difference {
            box { <-9/2,0,-3> <9/2,11.0,14.5-3>  translate<0,0,0>} // aussenmasse
            cylinder { <0,6.5,-4> <0,6.5,14.5-3+1> 6.3/2 }         // innere bohrung.
            box { <-5,6.5,-3+4.5> <5,6.5+3.15,20>  translate<0,0,0>} // ausschnitt um Zylinder.
            box { <-5,-1,14.5-3-2> <5,12.0,14.5-3+1>  translate<0,0,0>}      
            }
        cylinder { <0,6.5,-2> <0,6.5,14.5-4> 8/2 }         // außenhuelle fuer stecker
        box { <-8/2,0,14.5-3-2> <8/2,6.5,14.5-4>  translate<0,0,0>}
        box { <-8/2,0,14.5-3-2> <-4/2,3.0,14.5-3>  translate<0,0,0>}
        box { < 4/2,0,14.5-3-2> < 8/2,3.0,14.5-3>  translate<0,0,0>}

        prism { -1.6, 0, 4 < 0.00, 1.50>, < 1.06,-1.06>, <-1.06,-1.06>, < 0.00, 1.50> rotate<0,180,0> }
        //      texture { Silver_Metal }
        pigment { Gray20 } finish { Shiny  ambient (0.1 * global_ambient_mul)}
        }
     sphere   { <0,6.5,-1.5>, 2.1/2  texture { Silver_Metal } }                  // innerer kontakt
     cylinder { <0,6.5,-1.5> <0,6.5,11.5> 2.1/2 texture { Silver_Metal } }       // innerer kontakt
     cylinder { <0,6.5,10.5> <0,6.5,11.0> 4/2 texture { Silver_Metal } }         // innerer kontakt
     box      { <-3.2/2,6.5,10.5> < 3.2/2,0.0,11.0> texture { Silver_Metal } }       // innerer kontakt

     // anschluesse     
     box      { <-15.2/2,0.0,3.76-4.6/2> < 15.2/2,0.5,3.76+4.6/2> texture { Silver_Metal } }             // masse kontakt
     box      { <0.76-1.7/2,0.0,12.90-2.4/2-0.5> <0.76+1.7/2,0.5,12.90+2.4/2> texture { Silver_Metal } } // innerer kontakt
     }



#end






/********************************************************************************************************************************************
 * SOT-223(5) package.
 *******************************************************************************************************************************************/
#macro IC_SMD_SOT223_5(value,logo)
   object{IC_SMD_BASE(
                6.5,    //LK      = Laenge des Kunststoff(Seite der Pins)
                3.56,   //BK      = Breite des Kunststoff(Seite ohne Pins)                
                1.675,  //HK      = Hoehe des Kunststoff
                6.96,   //B       = Laenge der Seite ohne Pins ueber alles
                4,      //pin_u   = Pins auf der "unteren" Seite
                1,      //pin_o   = Pins auf der "oberen" Seite
               1.5,     //ptch_u  = Pitch der Pins auf der "unteren" Seite
               1.9,     //ptch_o  = Pitch der Pins auf der "oberen" Seite
               0.74,    //pinb_u  = Breite der Pins auf der "unteren" Seite
               3.0,     //pinb_o  = Breite der Pins auf der  "oberen" Seite
               0.3,     //pin_s   = Staerke des Pinmaterials
               0.05,    //di_pcb  = Abstand des Kunststoff zur Platine
               0,       //kor_w   = Korrekturwinkel
               0,       //pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
               0,       //pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45Â° statt 10Â° verwendet (SO)
               1.5,     //pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
               0.75,     //besch_s = Scalefaktor der Beschriftung
               0,       //besch_w = Wenn != 0 wird Beschriftung gedreht
               logo     //logo  = Name of the logo
               ) }
#end