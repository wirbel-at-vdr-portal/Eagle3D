/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


#declare e3d_environment = off;   

#include "e3d_tools.inc"    

/********************************************************************************************************************************************
 * BNC Buchse liegend isoliert weiss
 *******************************************************************************************************************************************/

#macro AMP_227161()
  union{
        union { // Korpus
                difference {
                        box {
                                <0,0,0><14.5,12.5,14>
                                pigment{Gray70}
                                clipped_by {
                                        plane { <1,0,0>,0 rotate<0,0,45> translate<0,25,0> }
                                        plane { <-1,0,0>,0 rotate<0,0,-45>translate<0,10.5,0>}
                                }
                            }

                        cylinder { // Mittlerer Ausschnitt fuer Anschlusspins
                                <0,0,0>,<0,2,0>,4
                                open
                                rotate<90,0,0>
                                translate <7.5,6.25,0>
                                pigment{Gray50}
                            }
                        box { // unterer Aussschnitt fuer Anschlusspins
                                <0,0,-1><8,7,20>
                                translate <3.5,-0.51,-6.5>
                                pigment{Gray70}
                            }

                }
               // freigeschnittene Aussenbereiche der Box fuellen
               cylinder {<14.5-2,12.5-2,0><14.5-2,12.5-2,14>,2  translate<0,0,0> pigment{Gray70} }
               cylinder {<0   +2,12.5-2,0><   0+2,12.5-2,14>,2  translate<0,0,0> pigment{Gray70} }

                disc {
                        <0,0,0>, <0,0,-1>, 3
                        translate <7.5,6.25,2>
                        texture{T_Silver_1A}

                }

                cylinder {
                        <0,0,0>,<0,2,0>,1.6
                        rotate<90,0,0>
                        translate <7.5,6.25,1.8>
                        pigment{Gray70}
                }

        } // Ende Korpus

        //TOOLS_RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
        object { // Massepin
                TOOLS_RECT_BOGEN(1,90,0.8,0.8,7,1)
                rotate<90,0,-90>
                translate<4.75,6.5,2>
                texture { col_silver finish { phong 1 ambient (0.1 * global_ambient_mul) }}
        }
        #include "metals.inc"
        object { // Signalpin
                TOOLS_RECT_BOGEN(1,90,0.8,0.8,7,1)
                rotate<90,0,-90>
                translate<4.75+2.54,6.5,2>
                texture{col_gold}


        }

        union { // Haltebolzen 1
          cylinder {<0,1,0><0,-4,0>,1  translate<2.75,0,4.45> }
          sphere   {<0,0,0>,1          translate<2.75,-3.9,4.45>
          }
          texture{T_Silver_1A finish {phong 1.0 ambient (0.1 * global_ambient_mul)}}  translate <-0.5,2.5,2.8>
        }

        union { // Haltebolzen 2
          cylinder {<0,1,0><0,-4,0>,1  translate<2.75+10.2,0,4.45> }
          sphere   {<0,0,0>,1          translate<2.75+10.2,-3.9,4.45> }
        texture{T_Silver_1A finish {phong 1.0 ambient (0.1 * global_ambient_mul)}}    translate <-0.5,2.5,2.8>
}


        difference {
                union {
                        cylinder { // Verschraubung
                                <0,0,0>,<0,0,9>,5.5
                                translate<7.25,6.25,14>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,16>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,17>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,18>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,19>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,20>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,21>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,22>
                        }
                        pigment{Gray70}

                } // end inner union

                box {
                        <0,0,0>,<16,3.3,9>
                        translate<2.25,11.5,14>
                        pigment{Gray70}
                }
        } // end difference


        cylinder { // aeusserer Anschluss
                <0,0,0>,<0,0,12>,4.7
                open
                translate<7.25,6.25,5.5+14>
                texture{T_Silver_1A finish { phong 1 ambient (0.1 * global_ambient_mul)}}
        }

        difference{
                cylinder { // innerer Anschluss A
                        <0,0,0>,<0,0,1>,3.8
                        translate<7.25,6.25,29>
                        pigment{Gray70}
                }

                cylinder { // innerer Anschluss B
                        <0,0,0>,<0,0,1>,1
                        translate<7.25,6.25,29.1>
                        texture{col_gold}
                }

                cylinder { // innerer Anschluss C
                        <0,0,0>,<0,0,1>,0.5
                        translate<7.25,6.25,29>
                        pigment{Black}
                }
        }
        cylinder { // Einrastpunkt 1
                <0,0,0>,<0,0,1>,1
                rotate<90,0,0>
                translate<7.25,12,29>
                texture { col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }

        cylinder { // Einrastpunkt 2
                <0,0,0>,<0,0,1>,1
                rotate<90,0,0>
                translate<7.25,1.5,29>
                texture { col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }


  translate <-7.25,0,-7>
  }

#end




/********************************************************************************************************************************************
 * 19mm poti
 *******************************************************************************************************************************************/

#macro SP19L(value)
union{
#local VishayBlue=color red 0.0 green 0.4453 blue 0.73;
    difference{
        cylinder{<-8.25,4.8,0> <-9.75,4.8,0> 1.25}
        box{<-9.15,5.1,-2><-10,4.5,+2>}   
        texture {T_Brass_2A}
    }
    difference{
        box{<-8.25    ,   0,-2.35>       <+10.75    ,+6.4,+2.35>}  // case
        box{<-8.25+0.8,-0.1,-2.36>       <+10.75-0.8,+0.5,+2.36>}       
        pigment{VishayBlue}
    }
    #local hpin=-min(4.5,(pin_length+pcb_height));
    
    union{
      text {ttf global_fontfile_arial "T18" 0.1, 0 scale 2 rotate<90,180,0> translate<+8,6.45,-0.4>}
      text {ttf global_fontfile_arial value 0.1, 0 scale 2 rotate<90,180,0> translate<+8,6.45,+1.6>}
      text {ttf global_fontfile_arial "3" 0.1, 0 scale 2 rotate<90,180,0> translate<-5,6.45,-0.4>}
      text {ttf global_fontfile_arial "0302" 0.1, 0 scale 2 rotate<90,180,0> translate<-1.8,6.45,+1.6>}
      text {ttf global_fontfile_eagle3d "0" 0.1, 0 scale 2 rotate<90,180,0> translate<+2,6.45,-0>}
        pigment{Black}
    }
    scale x*19/18  translate <-2,0,0>
}
#end


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
        texture{e3d_tex_silver}
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
        } texture{e3d_tex_ic_body_1} //pigment{col}

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

     } texture{e3d_tex_silver}

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
 * LEMO_EPA.00.250.NTN_L
 *******************************************************************************************************************************************/
#macro LEMO_EPA_00_250_NTN_L()
  union {
     //cylinder{<-5,0, 0> <5,0,0> 0.1 pigment{Black} }  cylinder{< 0,0,-5> <0,0,5> 0.1 pigment{Black} }
      intersection {
        box{<-3.5,0,-3.5> <3.5,7,3.5>}
        sphere{<0,2.2,0> 6}
        }

     difference {
       Round_Cylinder(<0,3.5,3.5>, <0,3.5,14>, 6.8/2, 0.20, 0)
       cylinder{<0,3.5,4  > <0,3.5,15> 5/2   }
       }

     difference {
       object { Round_Cylinder(<0,3.5,3.5>, <0,3.5,13>, 2/2, 0.20, 0) pigment{White} }
       cylinder{<0,3.5,4  > <0,3.5,15> 0.7/2   }
       }

     cylinder{< 0,0,0> <0,-3+0.7/2,0> 0.7/2 }  sphere{<0,-3+0.7/2,0> 0.7/2}
     cylinder{<+5.08/2,0,+5.08/2> <+5.08/2,-3+0.7/2,+5.08/2> 0.7/2 }  sphere{<+5.08/2,-3+0.7/2,+5.08/2> 0.7/2}
     cylinder{<+5.08/2,0,-5.08/2> <+5.08/2,-3+0.7/2,-5.08/2> 0.7/2 }  sphere{<+5.08/2,-3+0.7/2,-5.08/2> 0.7/2}
     cylinder{<-5.08/2,0,+5.08/2> <-5.08/2,-3+0.7/2,+5.08/2> 0.7/2 }  sphere{<-5.08/2,-3+0.7/2,+5.08/2> 0.7/2}
     cylinder{<-5.08/2,0,-5.08/2> <-5.08/2,-3+0.7/2,-5.08/2> 0.7/2 }  sphere{<-5.08/2,-3+0.7/2,-5.08/2> 0.7/2}
     texture{e3d_tex_silver}  rotate <0,180,0>
     }
// end: LEMO_EPA_00_250_NTN_L
#end


/********************************************************************************************************************************************
 * Avago HFBR-x4x4TZ transmitter/receiver with ST connector.
 *******************************************************************************************************************************************/
#macro HFBR_x4x4(value)
union {
   //cylinder{< 0,0,0> <0,10,0> 0.7/2 }
   
   
   union {
      object{ // Round_Box(A, B, WireRadius, UseMerge)
         Round_Box(<-12.7/2, 0  ,-(3.81+2.54)     >,
                   < 12.7/2,10.2,-(3.81+2.54)+12.7>, 1.0, 0)        
         }
      difference {
         union {
            object  { Round_Cylinder(< 0,5.1,-(3.81+2.54)>, < 0,5.1,-(3.81+2.54) +12.7 - 27.1>, 7.1/2, 0.5, 0)  }
            cylinder{               <-8.4/2, 5.1,-15>
                                    < 8.4/2, 5.1,-15> 1.5/2 }
            union {                              
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-7.2>,<0,5.1,-7.5>, 9.4/2 /*translate<7.25,6.25,18> */ }
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-7.8>,<0,5.1,-8.1>, 9.4/2 /*translate<7.25,6.25,18> */ }
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-8.4>,<0,5.1,-8.7>, 9.4/2 /*translate<7.25,6.25,18> */ }
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-9.0>,<0,5.1,-9.3>, 9.4/2 /*translate<7.25,6.25,18> */ }
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-9.6>,<0,5.1,-9.9>, 9.4/2 /*translate<7.25,6.25,18> */ }
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-10.2>,<0,5.1,-10.5>, 9.4/2 /*translate<7.25,6.25,18> */ }
            cylinder { /* 'Schraubenlinien' */ <0,5.1,-10.8>,<0,5.1,-11.1>, 9.4/2 /*translate<7.25,6.25,18> */ }
            rotate <0,-1,-1> translate<-0.25,-0.25,0> }
            
            
            }
         object { Round_Cylinder(< 0,5.1,-(3.81+2.54) -1>, < 0,5.1,-(3.81+2.54) +12.7 - 27.1 -1>, 5.5/2, 0.5, 0)  }
         box    {                <-1/2,-20, -14.8>
                                 < 1/2, 20, -20.8> }
         cylinder{               < 0,-20, -14.8>
                                 < 0, 20, -14.8>
                                   1.0/2 }   
     
         }
    
     //texture{e3d_tex_silver}
     texture{ pigment{ color rgb<0.721,0.686,0.651>} finish { phong 0.4 } }
     }
     
   union {
      cylinder{  <-2.54/2,0, 0  >  <-2.54/2,-3.6, 0  > 0.46/2 }       
      cylinder{  <+2.54/2,0, 0  >  <+2.54/2,-3.6, 0  > 0.46/2 }
      cylinder{  <-2.54/2,0,2.54>  <-2.54/2,-3.6,2.54> 0.46/2 }       
      cylinder{  <+2.54/2,0,2.54>  <+2.54/2,-3.6,2.54> 0.46/2 }
      
      box      { <-7.62/2 - 0.51/2,0,-0.38/2>  <-7.62/2 + 0.51/2,-3.6,+0.38/2>  }
      box      { <+7.62/2 - 0.51/2,0,-0.38/2>  <+7.62/2 + 0.51/2,-3.6,+0.38/2>  }      
      box      { <-7.62/2 - 0.51/2,0,2.54-0.38/2>  <-7.62/2 + 0.51/2,-3.6,2.54+0.38/2>  }      
      box      { <+7.62/2 - 0.51/2,0,2.54-0.38/2>  <+7.62/2 + 0.51/2,-3.6,2.54+0.38/2>  }      
      
      
      
      texture{ Gold_Metal finish { phong 0.1  } scale 0.5 }
      }
   text {ttf global_fontfile_arial "AVAGO" 0.2, 0 scale 1.8 rotate<90,0,0> translate<-3.5,10.22,2.6>}      
   text {ttf global_fontfile_arial value 0.2, 0 scale 1.5 rotate<90,0,0> translate<-5,10.22,-1>}
}  
// end: HFBR_x4x4
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