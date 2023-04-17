/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/




// ////////////////////////////////////////////////////////////
// Original file: ./1_RES_DIS_TRIM_KOERPER.inc.src
// Grundmakro für Spektrol-Potis
// Andreas Rebmann <A.Rebmann-Elektrotechnik@t-online.de>
// geteilt und modifiziert ich@ossiostborn.de alias CArt
// Grundmacro des Quaders - Breite=B , Tiefe = T, Hoehe = H
// Spektrol-Poti
// //////////
#macro RES_DIS_TRIM_KOERPER(B,T,H, Farbe)
union {
    // Grundkörper
    box{<-B/2+0.2, 0.15 , T/2    > <B/2-0.2,H-0.2,-T/2>     pigment{Farbe}}
    box{<-B/2,     0.15 ,-T/2+0.2> <B/2,    H-0.2, T/2-0.2> pigment{Farbe}}
    box{<-B/2+0.2, H-0.2,-T/2+0.2> <B/2-0.2,H    , T/2-0.2> pigment{Farbe}}

    // Rundungen
    cylinder{<-B/2+0.2, 0.15, 0> <-B/2+0.2, H-0.2> 0.20  pigment{Farbe}
             translate <0, 0, T/2-0.2>}
    cylinder{<-B/2+0.2, 0.15, 0> <-B/2+0.2, H-0.2> 0.20  pigment{Farbe}
             translate <0, 0,-T/2+0.2>}
    cylinder{< B/2-0.2, 0.15, 0> < B/2-0.2, H-0.2> 0.20  pigment{Farbe}
             translate <0, 0, T/2-0.2>}
    cylinder{< B/2-0.2, 0.15, 0> < B/2-0.2, H-0.2> 0.20  pigment{Farbe}
             translate <0, 0,-T/2+0.2>}

    sphere{< B/2-0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  pigment{Farbe}}
    sphere{< B/2-0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  pigment{Farbe}}
    sphere{<-B/2+0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  pigment{Farbe}}
    sphere{<-B/2+0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  pigment{Farbe}}

    cylinder{<-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 pigment{Farbe}
             translate <0, 0, T/2-0.2>}
    cylinder{<-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 pigment{Farbe}
             translate <0, 0,-T/2+0.2>}
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 pigment{Farbe} rotate<0, 90,0>
             translate <-B/2+0.2, 0, 0>}
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 pigment{Farbe} rotate<0,-90,0>
             translate <-B/2+0.2, 0, 0>}
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 pigment{Farbe} rotate<0, 90,0>
             translate < B/2-0.2, 0, 0>}
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 pigment{Farbe} rotate<0,-90,0>
             translate < B/2-0.2, 0, 0>}

    cylinder{<-T/2+0.2,  0.3> < 0, 0.3> 0.30 pigment{Farbe}
             rotate<0, 90,0> translate <-B/2+0.3, 0, 0>}
    cylinder{<-T/2+0.2,  0.3> < 0, 0.3> 0.30 pigment{Farbe}
             rotate<0,-90,0> translate <-B/2+0.3, 0, 0>}
    cylinder{<-T/2+0.2,  0.3> < 0, 0.3> 0.30 pigment{Farbe}
             rotate<0, 90,0> translate < B/2-0.3, 0, 0>}
    cylinder{<-T/2+0.2,  0.3> < 0, 0.3> 0.30 pigment{Farbe}
             rotate<0,-90,0> translate < B/2-0.3, 0, 0>}
  }
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_RES_DIS_TRIM_PT10_BODY.inc.src
// Body of Piher-pot
// Grundmakro für Piher-Potentiometer PT-10
// Carsten Kögler <koegler@ftz-leipzig.de>
// //////////
#macro RES_DIS_TRIM_PT10_BODY(value)
union {

    // Plastikkörper
    difference{
       union{
          // Grundkörper-  10.3 x 10.3 x 4.4 mm
          superellipsoid{<1,0.08> scale<5.15,5.15,2.2> rotate<90,0,0> translate<0,2.2,0>  }

          // Erhöhung in der Mitte oben
          cylinder{<0,2,0><0,4.5,0>2.5 }
       }
       cylinder{<0,-1,0><0,5.0,0>1.5}
       cylinder{<0,-1,0><0,2.0,0>4.5}
       box{<-6,-1,-1.5><6,0.6,1.5>}
       box{<-1.0,-1,-6><1.0,0.6,6>}
    }
    superellipsoid{<0.03,0.08> scale<4.4,0.5,1.825> translate<0,3.9,-3.325> }
    box{<-0.5,4.0,-5.15><0.5,4.5,-1.5> }


    // Schriftzug auf der Oberseite
    #local nrPositions = 11;
    #local chars = "PIHER SPAIN";
    #local charNr = 0;
    #while (charNr < nrPositions)
      text {
        ttf besch_font substr(chars, charNr+1, 1) .1, 0
        pigment { Gray20 }
        scale 1.5
        rotate<90,0,0>
        rotate<0,2,0>
        translate<0,4.45,0>
        translate<0,0,3.5>
        rotate<0,charNr*180/nrPositions-90,0>
      }
      #local charNr = charNr + 1;
    #end

    // Metallplatte auf der Unterseite
    difference{
       cylinder{<0,0.5,0><0,0.6,0>4.75 texture{col_silver}}
       cylinder{<0,0,0><0,1.0,0>2.0 texture{col_silver}}

    }
    // weißes Innenteil
    #local my_angle = rand(global_seed)*270;
    difference{
       union{
          cylinder{<0,0,0><0,4.5,0>1.5 pigment{White}}
          cylinder{<0,0,0><0,2.0,0>2.5 pigment{White}}
       }
       cylinder{<0,-1,0><0,0.5,0>2.0 pigment{White}}
       difference{
          box{<-0.6,0,-0.6><0.6,5,0.6>pigment{White}}
          box{<-1.0,0,-0.6><1.0,5,0.6> rotate<0,45,0> translate<0.424,0,0.424> pigment{White}}
          translate<0.2,0,0.2>
          rotate<0,my_angle,0>
       }
       box{<-0.3,3.9,-2><0.3,5.0,2> rotate<0,my_angle+45,0> pigment{White}}
       box{<-0.3,-1,-2><0.3,0.5,2> rotate<0,my_angle+45,0> pigment{White}}
       box{<-0.3,-1,-1><0.3,4,1> rotate<0,my_angle+45,0> pigment{White}}
    }

    // Teil der Anschlussbeine
    difference{
       box{<-3.5,4.4,-5.15><3.5,4.5,-1> texture{col_silver}}
       cylinder{<0,2,0><0,5.0,0>2.55 texture{col_silver}}
       box{<-1.5,4.0,-6><1.5,5.0,-3.6> texture{col_silver}}
       box{<-0.6,4.0,-6><0.6,5.0,0> texture{col_silver}}
       box{<-5,4.0,-2><5,5.0,2> rotate<0,-35,0> translate<-3.5,0,0> texture{col_silver}}
       box{<-5,4.0,-2><5,5.0,2> rotate<0,35,0> translate<3.5,0,0> texture{col_silver}}
    }
    cylinder{<0.6,4.4,-3.6><0.6,4.4,-2.5> 0.1 texture{col_silver}}
    cylinder{<-0.6,4.4,-3.6><-0.6,4.4,-2.5> 0.1 texture{col_silver}}
    cylinder{<0,4.4,-0.85><0,4.4,0.85> 0.1 translate<0,0,-3.4> rotate<0,55,0> texture{col_silver}}
    cylinder{<0,4.4,-0.85><0,4.4,0.85> 0.1 translate<0,0,-3.4> rotate<0,-55,0> texture{col_silver}}


    // Plastikbippsel
    superellipsoid{<0.3,0.3> scale<0.3,0.8,0.8> translate<2.65,3.9,-4.0> }
    superellipsoid{<0.3,0.3> scale<0.3,0.8,0.8> translate<-2.65,3.9,-4.0> }


    // Beschriftung
    intersection{
       cylinder{<0,0,0><0,4.4,0>5.17 pigment {White}}
       union{
          #local nrPositions = strlen(value);
          #local chars = value;
          #local charNr = 0;
          #while (charNr < nrPositions)
            text {
              ttf besch_font substr(chars, charNr+1, 1) 0.3, 0
              pigment { White }
              scale 1.5
              rotate<180,0,0>
              translate<0,3,5.2>
              rotate<0,(-nrPositions*10)/2+charNr*10,0>
            }
            #local charNr = charNr + 1;
          #end
       }

    }
    pigment{Gray20}
  }
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_RES_DIS_TRIM_PT10_PIN.inc.src
// Pin of Piher-pot
// Beinchen für Piher-Potentiometer PT-10
// Carsten Kögler <koegler@ftz-leipzig.de>
// //////////
#macro RES_DIS_TRIM_PT10_PIN()
difference{
   box{<-0.5,0,-0.05><0.5,3.5,0.05> texture{col_silver}}
   box{<-0.5+0.6,0,-0.1><0.5+0.6,4,0.1> rotate<0,0,-30> texture{col_silver}}
   box{<-0.5-0.6,0,-0.1><0.5-0.6,4,0.1> rotate<0,0,+30> texture{col_silver}}
   translate<0,-3.5,0>
}
#end
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
// Auth: Joseph Zeglinski
// This macro creates "CERAMIC" RECTANGULAR shaped, VERTICAL mount POWER resisitors
********************************************************************************************************************************************/
#macro RES_DIS_CERAMIC_RADIAL_BASE(value, Front_width, Front_height, Depth, Wire_Sep, Wirelength, Wirewidth, WATTS)
union   {

// ********************
// PWB Assembly Pratice:  For Components drawing LESS than 1 watt, should be in contact with PCB.
//                        Seperation must NOT exceed 3.0 mm (CLASS 1 and CLASS 2),
//                        or 0.7 mm for CLASS 3 components.
//
// This particular resistor style requires zero vertical seperation, since it has built-in ceramic standoffs.

// *********************


#local C = Front_height;
#local A = Front_width;
#local B = Depth;

#local L = C/2; // subtract the ceramic legs/stubs, first, to simplify "Horizontal" build.
#local W = A/2;
#local D = Depth/2;
#local Stub = max( 0.8, Wirewidth );    // Set the component's "Stub Length" from the body to the start of bending
#local Bend_Radius = global_res_bend_radius;  // wire bending radius for ALL resistors - set globally


#local Horizontal=no;  // It will actually, end up vertical when finished

  union{

// Build HIGH POWER RESISTOR (Vertically)

 difference{
      // Make a bevelled box resistor, flat on the X-Z plane for a cut-out

        Round_Box_Merge(<W,D,L> <-W,-D,-L> D/4)  // Create rounded edges, flat, resistor body; edge radius = Depth/8 mm
        Round_Box_Merge(<W-1,3*D,L-1> <-(W-1),(D-0.1),-(L-3.81-1)> D/8)   // Create indentations Front & Back faces
        Round_Box_Merge(<W-1,-3*D,L-1> <-(W-1),-(D-0.1),-(L-3.81-1)> D/8)

      // Cut out slot at resistor block base, to create PCB standoff legs
        prism{ -(D+0.01), (D+0.01), 4, <A/2-0.5, -0.01> <(A/2-2.0), 3.81>, <-(A/2-2.0), 3.81>, <-(A/2-0.5), -0.01>
              translate<0,0,-L>    }
              texture{T_Grnt1}                       // Cement coloured & textured resistor body

        rotate<-90,0,0> translate<0,L,0>             // Raise cut block to upright position, at origin, standing on PCB
           } //Differenced Resistor block and base cutout

// Print IDENT (value) on 2 (or optionally, 4) sides, for viewability:
   union{
            #local Pwr1 = concat( "RCD   PV",  str(WATTS,0,0) );
            #local Pwr2 = concat( value,  str(WATTS,3,0), "W" );
            #local S = 2;

       // ID: XZ Top surface (resistor narrow depth side)
          //  text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,D-S,-(W+0.01)> rotate<270,0,90> pigment{Black}}
       // XZ Top surface
          //  text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(D-S),-(W+0.01)> rotate<270,0,90> pigment{Black}}
       // ID: XY Front surface
            text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,D-S,-(D-0.08)> rotate<180,0,90> pigment{Black}}
       // XY Front surface
            text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(D-S),-(D-0.08)> rotate<180,0,90> pigment{Black}}
       // ID: XZ Bottom surface
           // text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,D-S,-(W+0.01)> rotate<90,0,90> pigment{Black}}
       // XZ Bottom surface (resistor narrow depth side)
           // text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(D-S),-(W+0.01)> rotate<90,0,90> pigment{Black}}
       // ID: XY Back surface
            text {ttf besch_font Pwr1 0.01, 0 scale<S,S,S> translate<-6,D-S,-(D-0.08 ) > rotate<0,0,(Horizontal ? 0:90)> pigment{Black}}
       // XY Back surface
            text {ttf besch_font Pwr2 0.01, 0 scale<S,S,S> translate<-5,-(D-S),-(D-0.08)> rotate<0,0,(Horizontal ? 0:90)> pigment{Black}}

            rotate<0,0,180>  translate<0,(L+3.81/2),0> // Raise lettering into centre of cut block
        } // Unioned TEXT

          translate< 0,-L,0>  // translate the assembled block down to the ORIGIN, for pin attachment, next

      } // Unioned Text with Resistor block


// Go build the wires : Treat this like a "special case" of a horizontal cylindrical, low power, carbon film resistor
//                      with a narrowed raster equal to it's pin-seperation, that fits "inside" the body.


     object{ TOOLS_WIRE_LEADS(Front_width, Front_height, Wirelength, Wirewidth,  Wire_Sep,  Bend_Radius, 0.0, "H")  }
     translate< 0,L,0>



   } // Unioned Resistor and it's pins

// ALL DONE: Vertical RESISTOR is positioned.

pigment{Gray50}
finish { phong 1  ambient (0.1 * global_ambient_mul)}
#end
#macro RES_DIS_CERAMIC_RADIAL_PV2_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 11.0, 20.3,  7.6,  5.08,  3.81,  1.02,  2 )
#end
#macro RES_DIS_CERAMIC_RADIAL_PV2B_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 11.0, 20.3,  7.6,  5.08,  3.81,  1.02,  3 )
#end
#macro RES_DIS_CERAMIC_RADIAL_PV3_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 12.0, 24.9,  8.9,  5.08,  3.81,  1.02,  3 )
#end
#macro RES_DIS_CERAMIC_RADIAL_PV4_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 12.0, 24.9,  8.9,  5.08,  3.81,  1.02,  4 )
#end
#macro RES_DIS_CERAMIC_RADIAL_PV5_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 12.7, 25.4,  10.0, 5.08,  3.81,  1.02,  5 )
#end
#macro RES_DIS_CERAMIC_RADIAL_PV7_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 12.7, 38.6,  10.0, 5.08,  3.81,  1.02,  7 )
#end
#macro RES_DIS_CERAMIC_RADIAL_PV10_050MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 12.7, 51.2,  10.0, 5.08,  3.81,  1.02,  10)
#end
#macro RES_DIS_CERAMIC_RADIAL_PV10S_076MM(value)
RES_DIS_CERAMIC_RADIAL_BASE(value, 15.9, 35.0,  12.7, 7.62,  3.81,  1.02,  10)
#end








/********************************************************************************************************************************************
//Macros for RB57 RB58 RB59 RB60 RB61 Vitreous enamelled - Wirewound resistors
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 01/01/06
//-------------------------------------------------------------------------------------------------
//l:Length d:Diameter r:Pitch lw:pins length dw:pins width op:extra height
********************************************************************************************************************************************/
#macro RES_DIS_RB_BASE(value,l,d,r,lw,dw,op)
#local RB_Green = color red 0.013 green 0.094 blue 0.030;
union{

#if (op=0)
    #local space = 1.5 ; //default space
#else
   #local space = 0.0 ;
#end  

union{
      superellipsoid {<1.0, 0.1>  scale <1,1,2> rotate <0,90,0> translate <0,0,0>} // body
        intersection{
         cylinder {<-2,0,0> <2,0,0>,1}
         union{
                #switch(l)    
                #case(22.5)
                    text {ttf global_fontfile_arial "RB57" 20, 0  scale <0.6,0.7,0.7> scale 0.8 rotate<-90,180,180> translate<-0.6,2,-0.25> rotate<+18,0,0>}  // Marking 
                    text {ttf global_fontfile_arial value 20, 0  scale <0.6,0.7,0.7> scale 0.8 rotate<-90,180,180> translate<-0.6,2,-0.25> rotate<-18,0,0>}  // Marking  
                #break
                #case(47)
                    text {ttf global_fontfile_arial "RB58" 20, 0  scale <0.6,0.7,0.7> scale 0.5 rotate<-90,180,180> translate<-0.4,2,-0.25> rotate<+12,0,0>}  // Marking 
                    text {ttf global_fontfile_arial value 20, 0  scale <0.6,0.7,0.7> scale 0.5 rotate<-90,180,180> translate<-0.4,2,-0.25> rotate<-12,0,0>}  // Marking  
                #break
                #case(12.7)
                    text {ttf global_fontfile_arial "RB59" 20, 0  scale <0.6,0.7,0.7> rotate<-90,180,180> translate<-0.8,2,-0.25> rotate<+20,0,0>}  // Marking 
                    text {ttf global_fontfile_arial value 20, 0  scale <0.6,0.7,0.7> rotate<-90,180,180> translate<-0.8,2,-0.25> rotate<-20,0,0>}  // Marking  
                #break
                #case(36)
                    text {ttf global_fontfile_arial "RB60" 20, 0  scale <0.6,0.7,0.7> scale 0.6 rotate<-90,180,180> translate<-0.55,2,-0.25> rotate<+16,0,0>}  // Marking 
                    text {ttf global_fontfile_arial value 20, 0  scale <0.6,0.7,0.7> scale 0.6 rotate<-90,180,180> translate<-0.55,2,-0.25> rotate<-16,0,0>}  // Marking  
                #break
                #case(23)
                    text {ttf global_fontfile_arial "RB61" 20, 0  scale <0.6,0.7,0.7> scale 0.8 rotate<-90,180,180> translate<-0.7,2,-0.25> rotate<+20,0,0>}  // Marking 
                    text {ttf global_fontfile_arial value 20, 0  scale <0.6,0.7,0.7> scale 0.8 rotate<-90,180,180> translate<-0.7,2,-0.25> rotate<-20,0,0>}  // Marking  
                #break
                #end 
            }
            pigment{White}
            translate 0.01*y
        }
      
      scale<2,2,2>
      scale<l/2/4,d/2/2,d/2/2>      //Scale back to given size
        texture {
            pigment {RB_Green }
            finish {
                 ambient (1 * global_ambient_mul)
                specular 0.1
                reflection {0.08, 1 fresnel}
                conserve_energy
            }
        }
     }
   object{TOOLS_WIRE_LEADS(l,d,lw*2,dw,r,global_res_bend_radius,op+space,"H")}
   #if (op>0)   
       difference{  
           union{
             cylinder {<0,-0.5,0> <0,-op-d/2,0> 1.3 translate <-r/2,0,0> pigment {Gray95}}
             cylinder {<0,-0.5,0> <0,-op-d/2,0> 1.3 translate <+r/2,0,0> pigment {Gray95}} 
         }
         union{
             cylinder {<0,0.5,0> <0,-op-d/2-1,0> 0.5 translate <-r/2,0,0> pigment {Gray95}}
             cylinder {<0,0.5,0> <0,-op-d/2-1,0> 0.5 translate <+r/2,0,0> pigment {Gray95}} 
         }
       }
   #end
   translate<0,d/2+0.1+op,0>
}
translate<0,space,0>
#end
//RB57 30.48mm
#macro RES_DIS_RB_57_30MM_H(value)
RES_DIS_RB_BASE(value,22.5,8,12*2.54,30,0.88,8)
#end
//RB58 55.88mm
#macro RES_DIS_RB_58_55MM_H(value)
RES_DIS_RB_BASE(value,47,11,22*2.54,30,0.88,8)
#end
//RB59 22.86mm
#macro RES_DIS_RB_59_22MM_H(value)
RES_DIS_RB_BASE(value,12.7,5.6,9*2.54,30,0.88,8)
#end
//RB60 45.72mm
#macro RES_DIS_RB_60_45MM_H(value)
RES_DIS_RB_BASE(value,36,10,18*2.54,30,0.88,8)
#end
//RB61 30.48mm
#macro RES_DIS_RB_61_30MM_H(value)
RES_DIS_RB_BASE(value,23,7,12*2.54,30,0.88,8)
#end


/********************************************************************************************************************************************
//SIL-Netzwerk
********************************************************************************************************************************************/
#macro RES_DIS_SIL_BASE(pin)
union{
    box{<-pin*1.27+0.5,0.5,-0.5><pin*1.27-0.5,3,0.5> pigment{rgb<1,0.83,0.61>}}
    sphere_sweep{
      linear_spline,5,
      <-pin*1.27+0.5,0.5,0>, 0.5
      <-pin*1.27+0.5,3,0>, 0.5
      <pin*1.27-0.5,3,0>, 0.5
      <pin*1.27-0.5,0.5,0>, 0.5
      <-pin*1.27+0.5,0.5,0>, 0.5
      pigment{rgb<1,0.83,0.61>}}
  union{
    #local i = 0;
    #while(i<pin)
      box{<-0.2,-4,-0.1><0.2,-1,0.1> translate<2.54*i,0,0>}
      box{<-0.3,-1,-0.1><0.3,0,0.1> translate<2.54*i,0,0>}
      #local i = i+1;
    #end
    translate<-(pin-1)/2*2.54,0,0>}
    intersection{
        box{<-pin*1.27+0.5,0.5,-0.501><pin*1.27-0.5,3,0.501>}
        union{
                text{ttf besch_font value 0.8, 0 scale<2,2,1> translate<-pin/2*2.54+2.5,1.2,-0.7>}
                cylinder{<0,0,0><0,0,-2>0.4 translate<-(pin-1)*1.27,1.2,0>}}
        pigment{Black}}
  texture{col_silver} translate<0,1.2,0>}
#end

#macro RES_DIS_SIL_4(value)
RES_DIS_SIL_BASE(4)
#end
#macro RES_DIS_SIL_5(value)
RES_DIS_SIL_BASE(5)
#end
#macro RES_DIS_SIL_6(value)
RES_DIS_SIL_BASE(6)
#end
#macro RES_DIS_SIL_7(value)
RES_DIS_SIL_BASE(7)
#end
#macro RES_DIS_SIL_8(value)
RES_DIS_SIL_BASE(8)
#end
#macro RES_DIS_SIL_9(value)
RES_DIS_SIL_BASE(9)
#end
#macro RES_DIS_SIL_10(value)
RES_DIS_SIL_BASE(10)
#end
#macro RES_DIS_SIL_11(value)
RES_DIS_SIL_BASE(11)
#end
#macro RES_DIS_SIL_12(value)
RES_DIS_SIL_BASE(12)
#end
#macro RES_DIS_SIL_13(value)
RES_DIS_SIL_BASE(13)
#end
#macro RES_DIS_SIL_14(value)
RES_DIS_SIL_BASE(14)
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


/********************************************************************************************************************************************
// Piher-Potentiometer PT-10 Horizontal Rastermaß 10mm
// Carsten Kögler <koegler@ftz-leipzig.de>
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_PT10_H_10_BASE(value)
union{
    object {RES_DIS_TRIM_PT10_BODY(value) translate<0,1.5,0.2>}
    // vorderer rechter pin
    object {RES_DIS_TRIM_PT10_PIN() translate<2.5,0,-5>}
    // vorderer linker pin
    object {RES_DIS_TRIM_PT10_PIN() translate<-2.5,0,-5>}
    // hinterer pin
    object {RES_DIS_TRIM_PT10_PIN() translate<0,0,5>}

    // verlängerung linker Pin
    box{<-1.0,0,-0.05><1.0,5.9,0.05> translate<-2.5,0,-5> texture{col_silver}}
    // Abrunden
    cylinder{<-1,5.9,0><1,5.9,0>0.1 translate<-2.5,0,-4.95> texture{col_silver}}
    
    // verlängerung rechter Pin
    box{<-1.0,0,-0.05><1.0,5.9,0.05> translate<+2.5,0,-5> texture{col_silver}}
    // Abrunden
    cylinder{<-1,5.9,0><1,5.9,0>0.1 translate<+2.5,0,-4.95> texture{col_silver}}
    
    // verlängerung hinterer Pin
    box{<-1.0,0,-0.05><1.0,2.0,0.05> translate<0,0,5> texture{col_silver}}
    // Abrunden
    difference{
        cylinder{<-1,2.0,0><1,2.0,0>0.1 translate<0,0,4.95> texture{col_silver}}
        box{<-1.0,0,-0.05><1.0,2.0,0.05> translate<0,0,4.9> texture{col_silver}}
    }
}
#end
//PT10 Horizontal 10mm
#macro RES_DIS_TRIM_PT10_H_10(value)
RES_DIS_TRIM_PT10_H_10_BASE(value)
#end


/********************************************************************************************************************************************
//Trimmer
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_SPECTROL1_BASE(B,T,H,Farbe,D_schraube,Rf)
union {
    object{RES_DIS_TRIM_KOERPER(B,T,H,Farbe)}
    //Anschlußbeine zuordnen
    union{
      cylinder{<-2.54,1,-1.27> <-2.54,-3,-1.27> 0.25}
      cylinder{< 2.54,1,-1.27> < 2.54,-3,-1.27> 0.25}
      cylinder{<  0,1,Rf> < 0,-3,Rf> 0.25}
      texture{col_silver}
    }
    difference{
      cylinder{<0,0,0> <0, 1.32> 1.015}
      box     {<1.5,0.7,0.2> <-1.5,2.5,-0.2>}
      texture{col_silver}
      rotate<0,75,0>
      translate <D_schraube,H,T/2-1.3>
    }
    text {ttf besch_font  value     0.1,0 scale<1.4,1.4,1.4> pigment{Black}
          rotate<-270,180,0> translate<B/2-1.0,  H+0.1, T/2-3.0>}
    text {ttf besch_font "64Y"      0.1,0 scale<1.4,1.4,1.4> pigment{Black}
          rotate<-270,180,0> translate<B/2-6.5,  H+0.1, T/2-3.0>}
    text {ttf besch_font "3  2  1"  0.1,0 scale<1.5,1.5,1.5> pigment{Black}
          rotate<0   ,180,0> translate<B/2-1.75, 0.52, T/2+0.1>}
  }
#end
//senkrecht
#macro RES_DIS_TRIM_64W(value)
RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,3.1,1.27) rotate <0,-90,0>
#end
#macro RES_DIS_TRIM_64Y(value)
RES_DIS_TRIM_SPECTROL1_BASE(9.52,4.83,9.52,Khaki,-3.1,-1.27) rotate <0,-90,0>
#end


/********************************************************************************************************************************************
//Grundmacro stehend - Breite=B , Tiefe = T, Hoehe = H, Raster = Ra?, Farbe
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_SPECTROL2_BASE(B,T,H,Ra,Farbe)
  union{
    object{RES_DIS_TRIM_SPECTROL1_BASE(B,T,H,Farbe,-3.1,1.27)}
    sphere{<-B/2+4.75, H+5.85,T+.01>  2.5   scale<1.70,0.5,0.01> pigment{Farbe}
           translate<0,0,2.40>}  //Oval bei Spectrol Schrift
    text {ttf besch_font "Spectrol" 0.1,0 scale<1.5,1.5,1.5> pigment{Black}
          rotate<0   ,180,0> translate<B/2-1.2,  H-2.3, T/2+0.1>}
    rotate<0,180,0>
  }
#end
// Raster 5.08
#macro RES_DIS_TRIM_S64Y(value)
RES_DIS_TRIM_SPECTROL2_BASE(9.52,4.83,9.52,5.08,OldGold)
#end






/********************************************************************************************************************************************
//Macros for TS53Y serie, SMD Trimmer Single Turn Cermet Sealed from Vishay
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  12/04/06  
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_TS53_BASE (Type)
union{

    difference{
        box { <-2.5, +0.4, -2.5>, <2.5, 2.7, 2.5> }
        box { <-2.3, +0.1, -2.6>, <2.3, 2.5, 2.6> }
        box { <-0.1, +1.4, -1.25>, <0.21, 2.8, 1.25>  translate -2.5*x}
        box { <-0.1, +1.4, -1.25>, <0.21, 2.8, 1.25>  translate +2.5*x}
        cylinder { <0, 2.4, 0>, <0, 2.8, 0>, 1.25 }
        pigment{color red 0.758 green 0.694 blue 0.48}
    }
    
    text {ttf global_fontfile_eagle3d "0" 0.01, 0 pigment{Black} scale 1 rotate<90,0,0> translate<+1,+2.701,-2.1>}      // Marking
    text {ttf global_fontfile_arial value 0.05, 0 pigment{Black} scale 1 rotate<90,0,0> translate<-2.2,+2.701,-2.1>}  // Marking
    text {ttf global_fontfile_arial "99" 0.01, 0 pigment{Black} scale 1 rotate<90,0,0> translate<-2.2,+2.701,+1.5>}  // Marking
    text {ttf global_fontfile_arial "18" 0.01, 0 pigment{Black} scale 1 rotate<90,0,0> translate<+1.2,+2.701,+1.5>}  // Marking

    difference{
        union {
            box { <-2.3, +0.2, -2.5>, <2.3, 2.5, 2.5> }
            box { <-0.05, +1.4, -1.25>, <0.21, 2.5, 1.25>  translate -2.5*x}
            box { <-0.05, +1.4, -1.25>, <0.21, 2.5, 1.25>  translate +2.5*x}
        }
        box { <-0.25, +2.2, -1>, <0.25, 2.7, 1> }
        box { <-1, +2.2, -0.25>, <1, 2.7, 0.25> }
        pigment{color red 0.937 green 0.878 blue 0.776}
        finish {diffuse 0.5 specular 0.5  ambient (0.1 * global_ambient_mul)}
    }
    
    union{
        box{<-0.45, 0, -2.5> <+0.45, 1.4, -2.7> translate -1.15*x}
        box{<-0.45, 0, -2.5> <+0.45, 1.4, -2.7> translate +1.15*x}
        box{<-0.5, 0, +2.5> <+0.5, 1.4, +2.7>}
        #if(Type=0)
            box{<-0.45, 0, -2.5> <+0.45, 0.2, -3.2> translate -1.15*x}
            box{<-0.45, 0, -2.5> <+0.45, 0.2, -3.2> translate +1.15*x}
            box{<-0.5, 0, +2.5> <+0.5, 0.2, +3.2>}
        #end
        #if(Type=1)
            box{<-0.45, 0, -2.7> <+0.45, 0.2, -1.2> translate -1.15*x}
            box{<-0.45, 0, -2.7> <+0.45, 0.2, -1.2> translate +1.15*x}
            box{<-0.5, 0, +2.7> <+0.5, 0.2, +1.2>}
        #end
        pigment{Silver}
    }
}
#end
#macro RES_DIS_TRIM_TS53_YL(value)
RES_DIS_TRIM_TS53_BASE (0)
#end
#macro RES_DIS_TRIM_TS53_YJ(value)
RES_DIS_TRIM_TS53_BASE (1)
#end


/********************************************************************************************************************************************
//Macros for TSM4 serie, SMD Trimmer Multiturn Cermet Sealed from Vishay
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  26/03/06
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_TSM_BASE(TrimType,Lg)
union{
    difference{
        box{<-2.4,0.2,-1.75><+2.4,Lg+0.2,+1.75>}
        cylinder{<1.55,4,0.95><1.55,Lg+0.3,0.95> 0.75}     
        box{<-2.1,0.5,0><+2.1,Lg+0.2-0.3,-1.8>}
        pigment { Gray70 }
        finish {
            diffuse 0.5 
            specular 0.5
            ambient (0.1 * global_ambient_mul)
        }
    }
    difference{
        cylinder{<1.55,4.4,0.95><1.55,Lg+0.2,0.95> 0.73}     
        box{<1.55-0.2,4.5,-1.75><1.55+0.2,Lg+0.3,+1.75>}
        texture{col_gold}
    }
    
    box{<-2.1,0.5,0><+2.1,Lg+0.2-0.3,-1.74>
        texture{
        pigment {Brown}
        finish {
            diffuse 0.5 
            specular 0.5
            ambient (0.1 * global_ambient_mul)
        }
        normal{waves 0.1 frequency 3000.0 scale 800.0}
        }
    }
    
    text {ttf global_fontfile_eagle3d "0" 0.01, 0 pigment{Black} scale 1.5 rotate<0,180,0> translate<-0.6,+3.1,+1.76>}      // Marking
    text {ttf global_fontfile_arial value 0.05, 0 pigment{Black} scale 1.6 rotate<0,180,0> translate<+2,3.1,+1.76>}  // Marking
    text {ttf global_fontfile_arial "9941" 0.01, 0 pigment{Black} scale 1.6 rotate<0,180,0> translate<+2,1.3,+1.76>}  // Marking
    
    #if(TrimType=0) //YL
        #local pin =
        union{
            box{<-0.3, 0, -0.75> <+0.3, 0.2, +0.75>}
            pigment{Silver}
        }  
      object {pin translate<-1.25,0,-1.8>}
      object {pin translate<+1.25,0,-1.8>}
      object {pin translate<0,0,+1.8>}
   #end
    #if(TrimType=1) //YJ
        #local pin =
        union{
            box{<-0.3, 0, -0.3> <+0.3, 0.2, +0.3>}
            box{<-0.3, 0, -0.15> <+0.3, 1, -0.3>}
            pigment{Silver}
        }  
      object {pin translate<-1.25,0,-1.6>}
      object {pin translate<+1.25,0,-1.6>}
      object {pin rotate 180*y translate<0,0,+1.6>}
   #end
    #if(TrimType=2) //ZL
        #local pin =
        union{
            box{<-0.3, -0.75,0> <+0.3, +0.75,0.2>}
            pigment{Silver}
        }  
      object {pin translate<-1.25,0.05,-1.95>}
      object {pin translate<+1.25,0.05,-1.95>}
      object {pin translate<0,4.75,-1.95>}
      rotate <-90,180,0>
      translate<0,1.95,-Lg/2-0.1>
   #end
    #if(TrimType=3) //ZJ
        #local pin =
        union{
            box{<-0.3, 0, -0.3> <+0.3, 0.2, +0.3>}
            box{<-0.3, 0, -0.15> <+0.3, 1, -0.3>}
            pigment{Silver}
        }  
      object {pin translate<-1.25,0,-1.6>}
      object {pin translate<+1.25,0,-1.6>}
      object {pin rotate 180*z translate<0,5,-1.6>}
      rotate <-90,180,0>
      translate<0,1.95,-Lg/2-0.1>
   #end
}
#end

#macro RES_DIS_TRIM_TSM_4YL(value)
RES_DIS_TRIM_TSM_BASE(0,5.1)
#end
#macro RES_DIS_TRIM_TSM_4YJ(value)
RES_DIS_TRIM_TSM_BASE(1,5.1)
#end
#macro RES_DIS_TRIM_TSM_4ZL(value)
RES_DIS_TRIM_TSM_BASE(2,4.6)
#end
#macro RES_DIS_TRIM_TSM_4ZJ(value)
RES_DIS_TRIM_TSM_BASE(3,4.6)
#end


/********************************************************************************************************************************************
// Rf = 1.27 oder 0 (Dreieck oder Linie); D_schraube = Abstand der Schraube aus
// der Mitte
********************************************************************************************************************************************/
#macro RES_DIS_TRIM_W_BASE(B,T,H,Farbe,D_schraube,Rf )
union {
    object{RES_DIS_TRIM_KOERPER(B,T,H,Farbe)}
    //Anschlußbeine zuordnen
    union {
      cylinder{<-2.54,1,Rf-0.635> <-2.54,-3,Rf-0.635> 0.25}
      cylinder{<2.54,1,Rf-0.635> <2.54,-3,Rf-0.635> 0.25}
      cylinder{<0,1,1.27-0.635> <0,-3,1.27-0.635> 0.25}
      texture{col_silver}
    }
    difference{
      cylinder{<0,0,0> <0, 1.1> 1.015}
      box     {<1.5,0.7,0.2> <-1.5,2.5,-0.2>}
      texture{col_silver}
      rotate<0,75,0>
      rotate<90,0,0>
      translate <D_schraube,H-1.3,T/2>
    }
    text {ttf besch_font  value     0.1,0 scale<1.4,1.4,1.4> pigment{Black}
          rotate<-270,180,0> translate<B/2-1.0,  H+0.1, T/2-3.0>}
    text {ttf besch_font "3  2  1"  0.1,0 scale<1.5,1.5,1.5> pigment{Black}
          rotate<0   ,180,0> translate<B/2-1.75, 0.52, T/2+0.1>}
  }
#end
// waagerecht
#macro RES_DIS_TRIM_B25X(value)
RES_DIS_TRIM_W_BASE(7,6.6,4.83,NavyBlue,0,-1.27)
#end
#macro RES_DIS_TRIM_B25V(value)
RES_DIS_TRIM_W_BASE(7,6.6,4.83,NavyBlue,0,1.27)
#end













