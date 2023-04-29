/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/





// ////////////////////////////////////////////////////////////
// Original file: ./1_DIODE_DIS_LED_7SEG_SYMBOL.inc.src
// 7 segment Symbol
// BuFran <BuFran@hi-web.cz>
// //////////
#macro DIODE_DIS_LED_7SEG_SYMBOL(tra, sca)
union{
        prism{  linear_spline 0,0.036,6,            // segment "A"
                <8.890000,30.480000>,<9.753600,31.165800>,<8.991600,31.750000>,
                <3.886200,31.750000>,<3.479800,31.394400>,<4.241800,30.480000>
        }
        prism{  linear_spline 0,0.036,6,            // segment "B"
                <9.2456,30.1498>,<10.1346,30.8610>,<10.5918,30.5308>,
                <9.7028,25.8064>,<8.5598,26.4414>,<9.2456,30.1498>
         }
        prism{  linear_spline 0,0.036,6,            // segment "C"
         <8.178800,24.206200>,<9.525000,24.892000>,<8.636000,19.989800>,
         <8.305800,19.710400>,<7.518400,20.650200>,<8.178800,24.206200>
        }
        prism{  linear_spline 0,0.036,6,            // segment "D"
          <7.188200,20.320000>,<7.950200,19.405600>,<7.543800,19.050000>,
          <2.438400,19.050000>,<1.676400,19.634200>, <2.540000,20.320000>
        }
        prism{  linear_spline 0,0.036,6,            // segment "E"
          <2.184400,20.650200>,<1.295400,19.939000>,<0.838200,20.269200>,
          <1.727200,24.993600>,<2.870200,24.358600>,<2.184400,20.650200>
        }
        prism{  linear_spline 0,0.036,6,            // segment "F"
          <3.251200,26.593800>,<1.905000,25.908000>,<2.794000,30.810200>,
          <3.124200,31.089600>,<3.911600,30.149800>,<3.251200,26.593800>
        }
        prism{  linear_spline 0,0.036,6,            // segment "G"
          <8.255000,26.035000>,<9.398000,25.400000>,<8.128000,24.765000>,
          <3.175000,24.765000>,<2.032000,25.400000>,<3.302000,26.035000>
        }
   union{
      cylinder{<10.287000,0,19.685000><10.287000,0.036000,19.685000>0.762000 translate<0,0.000000,0>} // Segment DP
   }
        translate tra
        scale sca
}
#end



/********************************************************************************************************************************************
//Macros Laser Diode or Receiver pigtail from PD-LD
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/04/06   
********************************************************************************************************************************************/
#macro DIODE_DIS_LASER_PDLD_PIGTAIL_BASE()
#macro DIODE_DIS_LASER_PDLD_PIGTAIL_PIN(L1,L2,Dx,Dy,Case)
union{
    #declare bends=array[3] {<0, L1, 0>,  <-90, 0.5, 0>,  <0,L2,0>}
    
    #object {
        TOOLS_BENTPIPE( 0.225, <0,0,0>, x, bends )
        rotate <180,90,0> translate <Dx,3.7+Dy,-12> texture {Gold_Texture}
    }
    #if(Case=0)
    cylinder{<Dx,3.7+Dy,-12><Dx,3.7+Dy,-12.05> 0.4 pigment{Black}}
    #end
}
#end

union{
    difference{
        union{
            box{<-8.35,0,-2><+8.35,+1,+2>}
            box{<-3.7,0,-2><+3.7,7.4,+2> }
        }
        cylinder{<-6.35,-0.1,0><-6.35,2.1,0> 1.1}
        cylinder{<+6.35,-0.1,0><+6.35,2.1,0> 1.1}
        cylinder{<0,3.7,-2.1><0,3.7,+2.1> 3}
        box{<-1.5,+1.5,-2.1><+1.5,-1.5,+2.1> rotate 45*z translate<-3.7,7.4,0>}
        box{<-1.5,+1.5,-2.1><+1.5,-1.5,+2.1> rotate 45*z translate<+3.7,7.4,0>}
        box{<-0.75,+3.7,-2.1><+0.75,+7.5,+2.1>}
    
        pigment{Gray15}
        finish {
           diffuse 0.5 
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }  
    
    cylinder{<0,3.7,15><0,3.7,40> 0.45 pigment{White}} 
       
    union{
       cylinder{<0,3.7,12.6><0,3.7,15> 1.5} 
       cone{<0,3.7,11.6>,1.95,<0,3.7,12.6> 1.5} 
       cylinder{<0,3.7,8><0,3.7,11.6> 1.95} 
       cone{<0,3.7,6>,3,<0,3.7,8> 1.95} 
       cylinder{<0,3.7,6><0,3.7,-5.5> 3} 
       cylinder{<0,3.7,-10.5><0,3.7,-10.3> 2.8} 
        pigment{Gray10}
        finish {
           diffuse 0.5
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }  
    
    cylinder{<0,3.7,-10.5><0,3.7,-12> 3 texture {Gold_Texture}} 
    cylinder{<0,3.7,-5.5><0,3.7,-10.3> 3 texture{Aluminum}} 
       
    #if(global_show_screws=on)
        object { TOOLS_SCREW(2,6,1,Silver) translate <+6.35,1,0> }
        object { TOOLS_SCREW(2,6,1,Silver) translate <-6.35,1,0> }
    #end
    #if(global_show_washers=on)
        object { TOOLS_WASHER(2,0,Silver)  translate <+6.35,-1.6-0.7,0> }
        object { TOOLS_WASHER(2,0,Silver)  translate <-6.35,-1.6-0.7,0> }
    #end
    #if(global_show_nuts=on)
        object { TOOLS_NUT(2,0,Silver)     translate <+6.35,-1.6-0.7-1.4,0> }
        object { TOOLS_NUT(2,0,Silver)     translate <-6.35,-1.6-0.7-1.4,0> }
    #end
    
    #declare bends=array[3] {<0, 3, 0>, <-90, 0.5, 0>, <0,5,0>}
    #local Dp = 1;
    #local Lp = 4.5;
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5+2.54,Lp+2*Dp,+Dp,+Dp,0 ) }
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5+2.54,Lp+2*Dp,-Dp,+Dp,1 ) }
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5,Lp,+Dp,-Dp,0 ) }
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5,Lp,-Dp,-Dp,0 ) }
    
    //rotate 180*y
}
#end

#macro DIODE_DIS_LASER_PDLD_PIGTAIL()
DIODE_DIS_LASER_PDLD_PIGTAIL_BASE()
#end


/********************************************************************************************************************************************
//7 segment Grundmakro
//BuFran <BuFran@hi-web.cz>
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_BASE(value)
union{
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference{
                box{<-17.9,0,-12.9><17.9,10.5,12.9> pigment{White}}
                box{<-18,10,-13><18,10.7,13> pigment{Gray30}}
                box{<-18,-0.1,-11><18,1,11> pigment{Gray70}}
                box{<-16,-0.2,-13><16,1.1,13> pigment{Gray70}}        
        }
        
        union{
                DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,1,0.09>)
                scale<16,1,16>
                translate<-9,10,0>
                pigment{Red}
        }
        
        union{
                DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,1,0.09>)
                scale<16,1,16>
                translate<9,10,0>
                pigment{Red}
        }
        
        text{ttf besch_font "M" 0.5,0 pigment{Black} scale<3,5.5,3> translate<-7.5,3,-13>}
        text{ttf besch_font "KINGBRIGHT" 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,5,-13>}
        text{ttf besch_font value 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,3,-13>}
        
        union{
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<10.16,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<7.62,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<5.08,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<2.54,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-2.54,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-5.08,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-7.62,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-10.16,0,0>}
                
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<10.16,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<7.62,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<5.08,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<2.54,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-2.54,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-5.08,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-7.62,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-10.16,0,0>}

                pigment{Silver}
        }
        
}
#end
#macro DIODE_DIS_LED_7SEG_2(value)
DIODE_DIS_LED_7SEG_BASE(value)
#end


/********************************************************************************************************************************************
//7 segment Grundmakro
//ChristophGraf(replace with at)web.de
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_HDSP_Q_BASE(value)

#macro DIODE_DIS_LED_7SEG_20CM_EAGLE_SYMBOL()
union{
        prism{  linear_spline 0,0.036,6,            // segment "A"
                <8.890000,30.480000>,<9.753600,31.165800>,<8.991600,31.750000>,
                <3.886200,31.750000>,<3.479800,31.394400>,<4.241800,30.480000>
        }
        prism{  linear_spline 0,0.036,6,            // segment "B"
                <9.2456,30.1498>,<10.1346,30.8610>,<10.5918,30.5308>,
                <9.7028,25.8064>,<8.5598,26.4414>,<9.2456,30.1498>
         }
        prism{  linear_spline 0,0.036,6,            // segment "C"
         <8.178800,24.206200>,<9.525000,24.892000>,<8.636000,19.989800>,
         <8.305800,19.710400>,<7.518400,20.650200>,<8.178800,24.206200>       
        }
        prism{  linear_spline 0,0.036,6,            // segment "D"
          <7.188200,20.320000>,<7.950200,19.405600>,<7.543800,19.050000>,
          <2.438400,19.050000>,<1.676400,19.634200>, <2.540000,20.320000>     
        }
        prism{  linear_spline 0,0.036,6,            // segment "E"
          <2.184400,20.650200>,<1.295400,19.939000>,<0.838200,20.269200>,
          <1.727200,24.993600>,<2.870200,24.358600>,<2.184400,20.650200>
        }
        prism{  linear_spline 0,0.036,6,            // segment "F"
          <3.251200,26.593800>,<1.905000,25.908000>,<2.794000,30.810200>,
          <3.124200,31.089600>,<3.911600,30.149800>,<3.251200,26.593800>
        }
        prism{  linear_spline 0,0.036,6,            // segment "G"
          <8.255000,26.035000>,<9.398000,25.400000>,<8.128000,24.765000>,
          <3.175000,24.765000>,<2.032000,25.400000>,<3.302000,26.035000>     
        }
   union{
      cylinder{<10.287000,0,19.685000><10.287000,0.036000,19.685000>0.762000 translate<0,0.000000,0>} // Segment DP
   }
       translate<-10.9869,0,-25.4092>
        scale<0.1,1,0.1>
}
#end

union{
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        difference{
             box{<-10.1092,0,13.9192><10.1092,8.9,-13.9192> pigment{White}}            
             box{<-10.9092,8.4,14.4192><11.1092,9.1,-14.1192> pigment{Gray30}}
             box{<-9.1092,-0.1,13.1192><9.1092,1,-13.1192> pigment{Gray70}}
             box{<-8.1092,-0.2,14.9192><8.1092,1.1,-14.9192> pigment{Gray70}}    
        }     

      

        
        union{
                DIODE_DIS_LED_7SEG_20CM_EAGLE_SYMBOL()
                scale<16,1,16>
               translate<9,8.4,0>
                pigment{Red}
           }
        
        text{ttf besch_font "M" 0.5,0 pigment{Black} scale<3,5.5,3> translate<-7.5,3,-14.1338>}
        text{ttf besch_font "KINGBRIGHT" 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,5,-14.1338>}
        text{ttf besch_font value 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,3,-14.1338>}
        
        union{
                cylinder{<-11.1331,2,18.9992>,<-11.1331,-pp,18.9992>,0.25 }
                cylinder{<-11.1331,2,16.4592>,<-11.1331,-pp,16.4592>,0.25 }
                cylinder{<-11.1331,2,13.9192>,<-11.1331,-pp,13.9192>,0.25 }
                cylinder{<-11.1331,2,11.3792>,<-11.1331,-pp,11.3792>,0.25 }
                cylinder{<-11.1331,2,8.8392>,<-11.1331,-pp,8.8392>,0.25}
                cylinder{<4.1069,2,18.9992>,<4.1069,-pp,18.9992>,0.25 }
                cylinder{<4.1069,2,13.9192>,<4.1069,-pp,13.9192>,0.25 }
                cylinder{<4.1069,2,11.3792>,<4.1069,-pp,11.3792>,0.25 }
                cylinder{<4.1069,2,8.8392>,<4.1069,-pp,8.8392>,0.25 }  
                cylinder{<4.1069,2,6.2992>,<4.1069,-pp,6.2992>,0.25 }
                cylinder{<4.1069,2,3.7592>,<4.1069,-pp,3.7592>,0.25 }
                cylinder{<4.1069,2,1.2192>,<4.1069,-pp,1.2192>,0.25 }
                
                  translate<3.5131,0,-10.1092>
     
                pigment{Silver}
        }
        
}
#end


#macro DIODE_DIS_LED_7SEG_20CM_EAGLE(value)
DIODE_DIS_LED_7SEG_HDSP_Q_BASE(value)
#end


/********************************************************************************************************************************************
// TOT 4301FE-1N  -  3 stelliges LED-Display rot                       Joerg Bredendiek <sprut(replace with at)sprut.de>   
// TOT 4301NG-1   -  2 1/2 stelliges LED-Display gruen     
// 
// verwendet segment Grundmakro DIODE_DIS_LED_7SEG_SYMBOL() von BuFran <BuFran(replace with at)hi-web.cz>              
//
// Mittelpunkt in geometrischer Mitte
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_TOT_BASE(value)
#local tot_pastic= texture { pigment{Gray40} finish {specular 1 roughness 0.001 reflection 0.2 ambient (0.1 * global_ambient_mul)} } ;   //etwas glatter/glaenzender

union{
        #if(pin_short=off)
                #local pp=5.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference{
                box{<-15  ,  0  , -8  ><15  , 7  , 8  > pigment{White}}     // weisser Grundkoerper
                box{<-16  ,  7.1, -9  ><16  , 6.9, 9  > pigment{Gray30}}    // graue Platte oben
                box{<-16  , -0.1, -3.5><16  , 1  , 3.5> pigment{White}}     // Ausspartung unten
                box{<-13.5, -0.1, -9  ><13.5, 1  , 9  > pigment{White}}     // Ausspartung unten    
                //3 Anzeigestellen
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<7,1,9>
                        translate<-10,6.8,0>
                        texture{tot_pastic} 
                }        
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<7,1,9>
                        translate< 0,6.8,0>
                        texture{tot_pastic} 
                }        
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<7,1,9>
                        translate<+10,6.8,0>
                        texture{tot_pastic} 
                } 
        }
         
        // Beschriftung      
        text{ttf besch_font value 0.5,0.1*x pigment{Black} scale<3,4,1> translate<-12.5,2.5,-8.02>}
        
        //pins
        union{    
                //untere Pinreihe
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate<-5*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate<-3*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate<-1*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate< 1*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate< 3*1.27,0,0>}
                //obere Pinreihe                
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate<-5*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate<-3*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate<-1*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate< 1*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate< 3*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate< 5*1.27,0,0>}
                pigment{Silver}
        }
}
#end


#macro DIODE_DIS_LED_7SEG_TOT4301(value)
DIODE_DIS_LED_7SEG_TOT_BASE(value)
#end


/********************************************************************************************************************************************
// LED-7-Segment-Anzeigen aus DDR-Bestaenden                       Joerg Bredendiek <sprut(replace with at)sprut.de>   
// VQE14 VQE24 u.s.w.        
//
// VQE13  rot  , gemeinsame Kathode, 2-stellig    (= Toshiba TLR324)
// VQE14  rot  , gemeinsame Anode,   2-stellig    (= Toshiba TLR325)
// VQE11  rot  , gemeinsame Kathode, 1.5-stellig  (= Toshiba TLR326)
// VQE12  rot  , gemeinsame Anode,   1.5-stellig  (= Toshiba TLR327)
// VQE23  gruen, gemeinsame Kathode, 2-stellig    (= Toshiba TLG324)
// VQE24  gruen, gemeinsame Anode,   2-stellig    (= Toshiba TLG325)
// VQE21  gruen, gemeinsame Kathode, 1.5-stellig  (= Toshiba TLG326)
// VQE22  gruen, gemeinsame Anode,   1.5-stellig  (= Toshiba TLG327)
// 
// benutzt das segment Grundmakro DIODE_DIS_LED_7SEG_SYMBOL() von BuFran <BuFran(replace with at)hi-web.cz>              
//
// Mittelpunkt in geometrischer Mitte
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_VQE_BASE(value, col, tra, height)
#local vqe_col=col*0.3;        //Farbe abdunkeln
#local tra=0.9;                //Transparenz fest einstellen
#local vqe_pastic= texture { pigment{vqe_col filter tra} finish {roughness 0.5 diffuse 0.7 crand 0.1  ambient (0.1 * global_ambient_mul)} } ;   // rauh

union{
        #if(pin_short=off)
                #local pp=3.1;
        #else
                #local pp=pcb_height+pin_length;
        #end   
        
        // transparenter Koerper        
        // offizielle Aussenmasse sind 24.8 x 20 x 9.5 mm
        // offizielle Pinlaenge ist 3.1 mm
        difference{                                                                                   
                union{
                        box{<-12.4  ,  0.5  , -10  >< 12.4  , 9.5  , 10  >}     // Grundkoerper in rot oder gruen
                        box{<-12.4  ,  9.5  , -10  >< 12.4  , 9.7  ,-8.5 > texture{vqe_pastic}}     // rauer Streifen
                        box{<-12.4  ,  9.5  ,  10  >< 12.4  , 9.7  , 8.5 > texture{vqe_pastic}}     // 
                        box{<-12.2  ,  0.5  , -7.5 ><-12    , 0    ,-4   >}     // Fuss
                        box{<-12.2  ,  0.5  ,  7.5 ><-12    , 0    , 4   >}     // Fuss
                        box{< 12.2  ,  0.5  , -7.5 >< 12    , 0    ,-4   >}     // Fuss
                        box{< 12.2  ,  0.5  ,  7.5 >< 12    , 0    , 4   >}     // Fuss
                }
                box{<-2  , -2, -2><2  , 10, 2> rotate <0,45,0> translate <13.5,  0  ,-10  >}     // Ecke ab  
                box{<-4.5, -2, -2><4.5,  2, 2> rotate <45,0,0> translate < 0  , 10.7,-11.2>}     // Vorderkante ab 
                pigment{vqe_col filter tra}
        }     
            
        // weisser Chiptraeger    
        difference{
                box{<-11.6, 6, -8.8><11.6, 8.5, 8.8> pigment{Gray50}}      //keramischer Grundkoerper
                //2 Anzeigestellen
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<9,1,12>
                        translate<-6.35,8.4,0>
                        pigment{White} 
                }        
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<9,1,12>
                        translate< 6.35,8.4,0>
                        pigment{White}
                }        
        }
         
        // Beschriftung      
        text{ttf besch_font "WF"  0.5,0.1*x pigment{White} scale<2,3,0.1> translate<-10, 4,-10.02>}
        text{ttf besch_font value 0.5,0.1*x pigment{White} scale<2,3,0.1> translate< -4, 4,-10.02>}
        
        //pins
        union{    
                //untere Pinreihe
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-8*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-6*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-4*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-2*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 0*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 2*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 4*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 6*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 8*1.27,0,0>}
                //obere Pinreihe                
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-8*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-6*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-4*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-2*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 0*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 2*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 4*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 6*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 8*1.27,0,0>}
                pigment{Silver}
        }  
}
#end

#macro DIODE_DIS_LED_7SEG_VQE(value, col, tra, height)
DIODE_DIS_LED_7SEG_VQE_BASE(value, col, tra, height)
#end




/********************************************************************************************************************************************
//Macros for horizontal TO220 diodes with bended pins
//Modified by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//from Tobias Mueller's TO220 transistor package : TR_TO220_L
//Rev. 1.0  04/06/07
********************************************************************************************************************************************/
#macro DIODE_DIS_TO220_S_BASE(value)
union{union{union{
#if(pin_short=off)
#local tr_to220_s_pin = 9.5;
#else
#local tr_to220_s_pin = 9.5-(pcb_height+pin_length);
#end
difference{
box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
translate<-2.54,0,0>}
difference{
box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
translate<2.54,0,0>}
box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<2.54,9.8,0>}
box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<-2.54,9.8,0>}
translate<-0.75/2,0,1.6>}
difference{
box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<+5.1,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<-5.1,26.2,2.6>}
}
box{<-4,22.6,4.5><4,16,4.501>}
texture{col_silver}}
difference{
box{<-5.1,13.5,0><5.1,22.6,4.5>}
box{<-5.5,0,0><5.5,3,-2> rotate<45,0,0> translate<0,22.6-1.8,0> }
box{<-5.5,0,0><5.5,-1,2> rotate<-20,0,0> translate<0,13.5,3.7> }
pigment{Gray30}}
text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
translate<0,-9.5,-4.5>}
#end

#macro DIODE_DIS_TO220_S(value)
DIODE_DIS_TO220_S_BASE(value)
#end


/********************************************************************************************************************************************
// SMD-LED die zur Seite leuchtet - EVERLIGHT 12-215SURC/S530-A2/TR8
// col = Farbe
// tra = Durchsichtigkeit
// height = Höhe
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro DIODE_LED_SMD_SIDE_BASE(col,tra,height)

union{
        difference{
                merge{
                        cylinder{ <-0.35, 0.01, 0.25> <-0.35, 0.61, 0.25> 0.5 }
                        cylinder{ < 0.35, 0.01, 0.25> < 0.35, 0.61, 0.25> 0.5 }
                        box{ <-0.35, 0.01, 0.25> < 0.35, 0.61, 0.75> }
                                texture{
                                pigment{col filter tra}
                   }
           }
           box{ <-1.0, 0, -0.25> < 1.0, 0.62, 0.25>}
                texture{ pigment{col filter tra}}
        }
   
   difference{
         union{
                   box{ <-1.05, 0.015,-0.27> <-0.75, 0.605, 0.27> }
                   box{ < 1.05, 0.015,-0.27> < 0.75, 0.605, 0.27> }
           }
           box{ <-1.03, 0.0, -0.25> < 1.03, 0.62, 0.25>}
           texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
   }
   box{ <-1.03, 0.01, -0.25> < 1.03, 0.61, 0.25> texture{ pigment{ White }}}
 
        box{<-0.65, 0.02,-0.251> < 0, 0.60,-0.25> texture{ pigment{ color rgb< 0, 0.5, 0> }}}
}
#end
#macro DIODE_LED_SMD_SIDE(col,tra,height)
DIODE_LED_SMD_SIDE_BASE(col,tra,height)
#end








/********************************************************************************************************************************************
//LED 0805
********************************************************************************************************************************************/
#macro DIODE_SMD_LED_CHIP_BASE(s,col,tra)
union{
//The light emitting part of the led
box{
    <0.1,0,0.1> <1.9,0.60,1.15> 
    translate<0,0.05,0>
    texture{
        pigment{col filter tra} 
        #if(global_use_radiosity = on)
            finish{ambient (1.0 * global_ambient_mul_emit)}
        #else
            finish{ambient (0.7 * global_ambient_mul)}
        #end
        
    }
}

box{<0,0.0,0><0.6,0.3,1.25> }                                        //Metall links
box{<0,0.0,0><0.6,0.3,1.25> translate<2.0-0.6,0,0>}                 //Metall rechts
box{<0.4,0.3,0.5><0.6,0.5,0.75>}
box{<1.4,0.3,0.5><1.6,0.5,0.75>}
box{<0.85,0.3,0.475><1.15,0.4,0.775> pigment{col} finish{ ambient (1 * global_ambient_mul)}}
lathe{linear_spline 4, <0, 0>, <0.4, 0.4>, <0.5,0.4>,<0.05,0>
translate<1,0.1,0.625>}
texture{col_silver} 
translate<-1,0,-0.625>
scale s
}
#end
#macro DIODE_SMD_LED_CHIP_1206(col,tra,height)
DIODE_SMD_LED_CHIP_BASE(<1.5,1.5,1.2>,col,tra)
#end
#macro DIODE_SMD_LED_CHIP_0805(col,tra,height)
DIODE_SMD_LED_CHIP_BASE(<1.0,1.0,1.0>,col,tra)
#end
#macro DIODE_SMD_LED_CHIP_0603(col,tra,height)
DIODE_SMD_LED_CHIP_BASE(<0.75,0.6,0.6>,col,tra)
#end


/********************************************************************************************************************************************
//LED PLCC2
********************************************************************************************************************************************/
#macro DIODE_SMD_LED_PLCC2_BASE(typeOfCase)
union{

   //default to PLCC2
   #local L = 3.7;
   #local W = 3.0;
   #local H = 2.0;
   #local LT = 3.3;
   #local WT = 2.6;
   #local HT = 1.6;
   #local P = 2;
   
   #if(strcmp(typeOfCase,"PLCC2")=0.0)

      #local L = 3.7;
      #local W = 3.0;
      #local H = 2.0;
      #local LT = 3.3;
      #local WT = 2.6;
      #local HT = 1.6;
      #local P = 2;
      
   #end

   #if(strcmp(typeOfCase,"MiniTopled")=0.0)

      #local L = 2.3;
      #local W = 1.5;
      #local H = 1.4;
      #local LT = 2.1;
      #local WT = 1.3;
      #local HT = 1.2;
      #local P = 2;
      
   #end
      
   difference{
      
      object{Round_Box(<0,0,0>, <LT,H,W>, 0.1, no) translate<-LT/2,(L-LT)/2,-W/2>}
      cylinder{<0,H+(L-LT)/2-0.4,0> <0,H+(L-LT)/2+0.1,0>W/3.5}
      cone{ <0,H+(L-LT)/2-0.4,0> W/2.9 <0,H+(L-LT)/2+0.1,0>W/2.2}
           pigment{White}
   }
   
   box{<-0.2,H+(L-LT)/2-0.4,-0.2><0.2,H+(L-LT)/2-0.3,0.2> pigment{Gray80}}
   
   //rechter Anschluss
   difference{
      box{<0,0,0><-P,HT,WT>}
      box{<0,(L-LT)/2,-0.002><-P-0.002,HT-(L-LT)/2,WT+0.002> translate<-(L-LT)/2,0,0>}
      cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
      cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
      texture{col_silver} 
      translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
   }
   //rechter Anschlus
   difference{
      cylinder{<-(L-LT)/2,HT-(L-LT)/2,><-(L-LT)/2,HT-(L-LT)/2,WT>(L-LT)/2}
      cylinder{<-3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><-3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
      box{<-(L-LT)/2,HT-3*(L-LT)/4,-0.04><-(L-LT),HT-5,WT+0.002>}
      box{<-3*(L-LT)/4,HT-(L-LT)/2,-0.04><-(L-LT),HT-5,WT+0.002>}
      texture{col_silver}
      translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
   }
   //rechter Anschlus
   difference{
      cylinder{<-(L-LT)/2,(L-LT)/2,0><-(L-LT)/2,(L-LT)/2,WT>(L-LT)/2}
      cylinder{<-3*(L-LT)/4,3*(L-LT)/4,-0.04><-3*(L-LT)/4,3*(L-LT)/4,WT+0.002>(L-LT)/4}
      box{<(-L-LT)/2,3*(L-LT)/4,-0.04><-(L-LT),5,WT+0.002>}
      box{<0,0,-0.04><(L-LT)/2,(L-LT)/2,WT+0.002> translate<-(L-LT),0.75*(L-LT),0>}
      box{<(L-LT)/2,(L-LT)/2,-0.04><(L-LT),L-LT,WT+0.002> translate<-1.75*(L-LT),0,0>}
      texture{col_silver}
      translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
   }
   //linker (positiver) Anschlus
   difference{
      box{<0,0,0><P,HT,WT>}
      box{<(L-LT)/2,(L-LT)/2,-0.002><P+0.002,HT-(L-LT)/2,WT+0.002>}
      cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
      cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
      box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
      texture{col_silver}
      translate<-L/2-0.02,0,-WT/2>
   }
   //linker (positiver) Anschlus
   difference{
      cylinder{<(L-LT)/2,HT-(L-LT)/2,-0.002><(L-LT)/2,HT-(L-LT)/2,WT+0.002>(L-LT)/2}
      cylinder{<3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
      box{<(L-LT)/2,HT-3*(L-LT)/4,-0.04><L-LT,HT-5,WT+0.002>}
      box{<3*(L-LT)/4,HT-(L-LT)/2,-0.04><L-LT,HT-5,WT+0.002>}
      box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
      texture{col_silver}
      translate<-L/2-0.02,0,-WT/2>
   }
   //linker (positiver) Anschlus
   difference{
      cylinder{<(L-LT)/2,(L-LT)/2,-0.002><(L-LT)/2,(L-LT)/2,WT+0.002>(L-LT)/2}
      cylinder{<3*(L-LT)/4,3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
      box{<(L-LT)/2,3*(L-LT)/4,-0.04><L-LT,5,WT+0.002>}
      box{<3*(L-LT)/4,(L-LT)/2,-0.04><L-LT,L-LT,WT+0.002>}
      texture{col_silver} 
      translate<-L/2-0.02,0,-WT/2>
   }
}
#end   
#macro DIODE_SMD_LED_PLCC2()
DIODE_SMD_LED_PLCC2_BASE("PLCC2")
#end
#macro DIODE_SMD_LED_MINITOPLED()
DIODE_SMD_LED_PLCC2_BASE("MiniTopled")
#end





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

