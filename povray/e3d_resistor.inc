/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/









/********************************************************************************************************************************************
// Auth: Joseph Zeglinski
// POWER RESISTORS:   DALE COMPONENTS INC. RH-Series / CLAROSTAT MFGG. CO CMC-Series - ALUMINUM HOUSED WIREWOUND RESISTORS
// PARAMETERS: (value, raster WATTS, A, B, C, D, E, F, G, H, J, K, L, M, N)   // Standard industry dimensions A - N (mm)
********************************************************************************************************************************************/
#macro RES_DIS_ALUMINUM_POWER_BASE(value, raster, WATTS, A, B, C, D, E, F, G, H, J, K, L, M, N)
union{

#local Wirethickness = 1.024;      // AWG-18 (1.024 mm) is standard for all Aluminum-Housed Wirewound Resistors.

#if (raster < C+5.08)                        // Make sure wires leave the resistor body ends, by at least 2.54 per side.
    #local raster = ceil( (C+5.08)/2.54 ) * 2.54;  // Calculate the nearest multiple of 2.54 mm (10 mils) raster.
#end

// Build HIGH POWER RESISTOR (Vertically)
#local T = (G-H-E/4)/6;
#local Bodycolor = pigment {P_Brass4};
#local Bend_Radius = global_res_bend_radius;  // wire bending radius for ALL resistors - set globally


    difference{
    // Make the main body (make it slightly brighter than slots)
        prism{0, C, 6, <0,0> <0,G-E/4> <E/4,G> <0.75*E,G> <E,G-E/4> <E,0>   pigment{Bodycolor} finish {diffuse 0.8 ambient (0.1 * global_ambient_mul)} }

        union{
    // Slots: make them a bit darker than main body
            box{ <-1,-1,H>     <T/2,C+1,  H+T>}
            box{ <-1,-1,H+2*T> <T/2,C+1,H+3*T>}
            box{ <-1,-1,H+4*T> <T/2,C+1,H+5*T>}

            box{ <E+1,-1,H>     <E-T/2,C+1,  H+T>}
            box{ <E+1,-1,H+2*T> <E-T/2,C+1,H+3*T>}
            box{ <E+1,-1,H+4*T> <E-T/2,C+1,H+5*T>}
            pigment{Bodycolor}  finish {diffuse 0.7 ambient (0.1 * global_ambient_mul)}
        }

    // Wire lead, end-caps
        cylinder{ <E/2,C-0.1,J> <E/2,C+0.01,J> E/3 pigment{Black} }
        cylinder{ <E/2,-0.01,J> <E/2,0.1,J> E/3 pigment{Black} }

        translate <-E/2,-C/2,-J> rotate<-90,90,0>
           }

    // Make screw-mount tabs
        difference{
        union{
                box{ <0,0,0> <2*K,H, (B-E)/2> }                // the solid tab
                cylinder{<K,0,(B-E)/2> <K,H,(B-E)/2> K }
             }
                cylinder{<K,-0.01,(B-E)/2> <K,H+0.01,(B-E)/2> L/2 }  // the hole
                  translate <C/2-2*K,-J ,E/2>  // stick it on the body
                  pigment{Bodycolor}  
                  finish {diffuse 0.8 ambient (0.1 * global_ambient_mul)}        
        }

        difference{
            union{
                box{ <0,0,0> <2*K,H, (B-E)/2> }
                cylinder{<K,0(B-E)/2> <K,H,(B-E)/2> K }
             }
                cylinder{<K,-0.01,(B-E)/2> <K,H+0.01,(B-E)/2> L/2 }
                rotate <180,0,0> 
                translate <-2*K-(C/2-2*K),-J+H ,-E/2> 
                pigment{Bodycolor}  
                finish {diffuse 0.8 ambient (0.1 * global_ambient_mul)}
        }


//
// Print IDENT (value) on TOP surface:

#local Pwr = concat( value,  str(WATTS,3,0), "W" );
#local S = 2;  // Scale the letter size upto 2 mm., and print

 // ID: XZ Top surface
        text {ttf besch_font Pwr 0.01, 0 scale<S,S,S> rotate<90,0,0> translate<-6,(G-J)+0.01,-S/4 >  pigment{Black}}


// Go build the wires
//


//     macro TOOLS_WIRE_LEADS(Length, Width, Wirelength, Wirewidth,  raster,  WireBendRadius, Seperation, H_V)

     object{ TOOLS_WIRE_LEADS( C, (2*J), (D-C), Wirethickness,  raster,  Bend_Radius, 0.0, "H")  }

     // Position the resistor on surface of PCB
     translate< 0,J,0>



   } // Unioned Resistor and it's pins

// ALL DONE: Vertical RESISTOR is positioned.

pigment{Gray50}
finish { phong 1  ambient (0.1 * global_ambient_mul) }

#end
#macro RES_DIS_ALUMINIUM_POWER_RH5_304MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value,  30.48,   5,  11.28, 12.45,  15.24,  28.58,  8.48, 16.41,  8.13, 1.65, 3.56, 1.98, 2.36, 1.98, 1.27)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH10_355MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value,  35.56,  10,  14.27, 15.88,  19.10,  34.93, 10.92, 20.30, 10.20, 1.91, 4.83, 2.40, 2.40, 2.59, 2.18)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH25_508MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value,  50.80,  25,  18.26, 19.84,  26.97,  49.23, 13.46, 27.43, 14.22, 2.16, 6.60, 4.37, 3.18, 2.92, 2.18)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH50_711MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value,  71.12,  50,  39.70, 21.44,  49.99,  70.64, 15.62, 28.96, 15.62, 2.16, 7.62, 4.97, 3.18, 2.71, 2.18)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH75_939MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value,  93.98,  75,  39.70, 21.44,  72.40,  93.00, 15.62, 28.96, 15.62, 2.16, 7.62, 4.97, 3.18, 2.71, 2.18)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH100_863MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value,  86.36, 100,  35.00, 37.00,  65.50,  85.90, 26.70, 46.70, 24.40, 3.50, 7.62, 4.97, 4.40, 2.71, 2.18)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH100X_1397MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value, 139.70, 100,  69.85, 57.15,  88.90, 139.14, 46.00, 71.42, 44.45, 4.78, 7.62, 4.97, 4.78, 2.71, 2.18)
#end
#macro RES_DIS_ALUMINIUM_POWER_RH250_1778MM(value)
RES_DIS_ALUMINUM_POWER_BASE(value, 177.80, 250,  98.42, 63.50, 114.30, 177.80, 53.98, 76.20, 55.58, 6.35, 7.62, 4.97, 4.78, 2.71, 2.18)
#end




/********************************************************************************************************************************************
// Auth: Joseph Zeglinski
// This macro creates "CERAMIC" RECTANGULAR  HORIZONTAL mount POWER resisitors - (short ones can be mounted vertically)
********************************************************************************************************************************************/
#macro RES_DIS_CERAMIC_AXIAL_BASE(value, Length, Width, Wirelength, Wirewidth,  raster,  H_V, WATTS)
union {

// ********************
// PWB Assembly Pratice:  For Components drawing LESS than 1 watt, should be in contact with PCB.
//                        Seperation must NOT exceed 3.0 mm (CLASS 1 and CLASS 2),
//                        or 0.7 mm for CLASS 3 components

//  I choose, an average seperation should be 1.5 mm for WATTS >= 1.0

        #if (WATTS >= 1.)
        #local Seperation = 1.5 ;   // Best compromise for all types.
        #else
        #local Seperation = 0.0 ;
        #end
// *********************

union   {

#local L=Length/2;
#local W=Width/2;
#local LW=Wirewidth/2;
#local Horizontal = !(strcmp(strupr(H_V), "H") ); // string compare returns "0" (false) if equal; therefore, Negate this.
#local Stub = max( 0.8, Wirewidth );    // Set the component's "Stub Length" from the body to the start of bending
#local Bend_Radius = global_res_bend_radius;  // wire bending radius for ALL resistors - set globally

// Build HIGH POWER RESISTOR Horizontally
     union{
            // Make a bevelled box rsistor, cement colour & texture
            //superellipsoid {<0.05, 0.05>   scale <L,W,W> texture{T_Grnt1}  }

            Round_Box_Merge(<L,W,W> <-L,-W,-W> W/8 )  // Create rounded edges, flat, resistor body; edge radius = Width/16 mm

            box{<-(L-1.0), -(W+0.005), -(W-1.0)> <(L-1.0), -W, (W-1.0)>  pigment{ Gray65 }}  // make cement "filler" on bottom

            #if(Length <= raster) box{<-(L+0.01), -(W+0.01), -2*LW> <(L+0.01), 2*LW, 2*LW>  pigment{ Gray65 }} #end
            #if(Horizontal=no) box{<-(L+0.01), -(W+0.01), -2*LW> <(L+0.01), 2*LW, 2*LW>  pigment{ Gray65 }} #end
            texture{T_Grnt1}
           }
union{
//
// Print IDENT (value) on 2 (or optionally, 4) sides, for viewability:

#local Pwr1 = concat( "RCD   PW",  str(WATTS,0,0) );
#local Pwr2 = concat( value,  str(WATTS,3,0), "W" );
#local S = 2;  // Scale the letter size upto 2 mm., and print at top & bottom edges

#if( Horizontal = yes)
 // ID: XZ Top surface
        text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,W-S,-(W+0.01)> rotate<270,0,180> pigment{Black}}
 // XZ Top surface
        text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(W-S),-(W+0.01)> rotate<270,0,180> pigment{Black}}

#else

 // ID: XY Front surface
        text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,W-S,-(W+0.01)> rotate<180,0,180> pigment{Black}}
 // XY Front surface
        text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(W-S),-(W+0.01)> rotate<180,0,180> pigment{Black}}
 // ID: XY Back surface
        text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,W-S,-(W+0.01)> rotate<0,0,(Horizontal ? 0:180)> pigment{Black}}
 // XY Back surface
        text {ttf besch_font Pwr2 0.10, 0 scale<S,S,S> translate<-5,-(W-S),-(W+0.01)> rotate<0,0,(Horizontal ? 0:180)> pigment{Black}}

  #if (!Horizontal)
 // ID: XZ Bottom surface
       // text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,W-S,-(W+0.01)> rotate<90,0,180> pigment{Black}}
  // XZ Bottom surface
       // text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(W-S),-(W+0.01)> rotate<90,0,180> pigment{Black}}
  #end
#end
     }  // Unioned Text blocks

pigment{Black}

//

// ORIENTATION: *** Horizontal or Vertical *** RESISTOR?

# if (Horizontal=no)
rotate<0,0,90>
#else
rotate<0,180,0>
#end


    } // Unioned Text block and Resistor block

// Go build the wires

     object{ TOOLS_WIRE_LEADS(Length, Width, Wirelength, Wirewidth,  raster,  Bend_Radius, Seperation, H_V)  }

// Position the component above the PCB

        //#local Seperation = 1.5 ;    // Best compromise for all types.

        #if (Horizontal=no)
                translate < -raster/2, (L+Stub+Seperation) ,0 >
        #else
                translate < 0, (W+Seperation ), 0 >
        #end

     }  // Unioned Resistor and it's pins

// ALL DONE: Horizontal or Vertical RESISTOR is positioned.

pigment{Gray50}
finish { phong 1  ambient (0.1 * global_ambient_mul)}

#end 
#macro RES_DIS_CERAMIC_AXIAL_PW1_228MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 15.0, 6.4, 25.4,  0.7,  22.86, "H", 1 )
#end
#macro RES_DIS_CERAMIC_AXIAL_PW2_254MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 17.8, 6.8, 25.4,  0.7,  25.40, "H", 2 )
#end
#macro RES_DIS_CERAMIC_AXIAL_PW3_304MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 22.4, 7.9, 28.4,  0.8,  30.48, "H", 3 )
#end
#macro RES_DIS_CERAMIC_AXIAL_PW5_330MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 22.4, 9.7, 28.4,  0.8,  33.02, "H", 5 )
#end
#macro RES_DIS_CERAMIC_AXIAL_PW7_457MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 36.0, 9.7, 31.8,  0.8,  45.72, "H", 7 )
#end
#macro RES_DIS_CERAMIC_AXIAL_PW10_609MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 50.0, 9.7, 31.8,  0.8,  60.96, "H", 10)
#end
#macro RES_DIS_CERAMIC_AXIAL_PW15_635MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 50.0, 12.7, 31.8,  0.8, 63.50, "H", 15)
#end
#macro RES_DIS_CERAMIC_AXIAL_PW20_812MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 65.0, 14.2, 31.8,  0.8, 81.28, "H", 20)
#end
#macro RES_DIS_CERAMIC_AXIAL_PW22_812MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 65.0, 14.2, 31.8,  0.8, 81.28, "H", 22)
#end
#macro RES_DIS_CERAMIC_AXIAL_PW25_812MM_H(value)
RES_DIS_CERAMIC_AXIAL_BASE(value, 65.0, 14.2, 31.8,  0.8, 81.28, "H", 25)
#end





/********************************************************************************************************************************************
//Macros for TRIMMER 72PT by BI Technologies
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 29/12/05
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_72_BASE(Value,Type)
union{
    difference{
        union{
            box{<-4.25,-4.2,0><4.25,+4.2,4.8>}  
            box{<-4.25,+4.2,0><4.25,+5.2,4.5>}  
            cylinder{<0,0,4.8> <0,0,5> 2.5}   
            cone{<0,0,5>,4,<0,0,10.4>,3.3}   
            pigment{Gray50}
        }
        union{
            #local i=1; 
            #while (i<4) box{<-4.25+(2.125*i)-0.2,+4.6,-0.1><-4.25+(2.125*i)+0.2,+5.3,4.6>} #local i=i+1; #end
            #local i=0; 
            #while (i<4) cylinder{<-4.25+1.06+(2.125*i),+5.2,-0.1><-4.25+1.06+(2.125*i),+5.2,4.6> 0.5} #local i=i+1; #end
            cylinder{<0,0,10.1> <0,0,10.5> 3}   
            box{<-0.3,-3,9.7><+0.3,+3,10.5>}  
            prism {9.5 10.5 5 <1.2, -1>, <0.25, -3>, <-0.25, -3>, <-1.2, -1>, <1.2, -1> rotate 90*x}                                
            #local i=1; 
            #while (i<10)
                box{<-0.25,-0.4,5.5><0.25,+0.4,11> rotate 7.45*y translate -4.7*x rotate <0,0,360/9*i> pigment{Gray50}}  
            #local i=i+1; #end 
    
            pigment{Gray50}
        }
    }    
    union{
        #local hpin=4.6;
        //
        cylinder{<0,0,0><0,0,-min(hpin,(pin_length+pcb_height))> 0.2 translate -2.5*y}
        cylinder{<0,0,0><0,0,-min(hpin,(pin_length+pcb_height))> 0.2 translate -2.5*x}
        cylinder{<0,0,0><0,0,-min(hpin,(pin_length+pcb_height))> 0.2 translate +2.5*x}
        pigment{Silver}
    }
    text {ttf global_fontfile_arial value 0.1, 0 scale 2 rotate<-90,180,0> translate<+2.5,-4.21,+1.6>}
    rotate <-90,180,0>

}
#end
#macro RES_DIS_TRIM_72_PT(value)
RES_DIS_TRIM_72_BASE(value,0)
#end































