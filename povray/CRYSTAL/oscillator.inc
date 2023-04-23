/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * ASE series (ASEseries.pdf)
 * 3.3V CMOS compatible 3.2 x 2.5 mm SMD Crystal Oscillator
 * 20230325, wk
 ******************************************************************************/
#macro SPC_XTAL_OSZ_ASE()
union {
   object {
      Round_Box( <+2.8/2,+1.2,+2.0/2>,
                 <-2.8/2, 0.0,-2.0/2>,
                 0.25,0)
      texture { col_gold }
      }
   cylinder { <+2.0/2,+1.10,+1.1/2>
              <+2.0/2,+1.22,+1.1/2>
              0.1 rotate<0,180,0> translate<0,0,0>
              pigment { Black }
      }
   difference {
      union {
         box { <+3.2/2,+0.9,+2.5/2>
               <-3.2/2, 0.0,-2.5/2>
               pigment { Gray20 }
             }
         GRID( box { <+0.9/2,+0.2 ,+0.65/2> <-0.9/2,-0.01,-0.65/2> translate<0,0,+0.825> texture { col_silver }}, 2.1, 2,1)
         GRID( box { <+0.9/2,+0.2 ,+0.65/2> <-0.9/2,-0.01,-0.65/2> translate<0,0,-0.825> texture { col_silver }}, 2.1, 2,1)
         }

      GRID(cylinder { <0,-0.1,0> <0,2,0> 0.25 rotate<0,180,0> translate<0,0,+2.5/2> texture { col_silver }}, 3.2, 2,1)
      GRID(cylinder { <0,-0.1,0> <0,2,0> 0.25 rotate<0,180,0> translate<0,0,-2.5/2> texture { col_silver }}, 3.2, 2,1)
      GRID(box { <+0.5/2,-0.1,+0.2/2> <-0.5/2,+1.0,-0.2/2> }, 2.5, 1,2)
      }
   }
#end



/*******************************************************************************
 * Macros for SMD TCVCXO CFPT-37 CFPT125 and CFPT126 from C-MAC
 * Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  25/03/06
 * *****************************************************************************/
#macro SPC_XTAL_OSZ_CFPT_BASE(Type)
  #macro LM_OSC_CAPSMDCHIP(color_sub,L,W,T,K)
     union {
        superellipsoid {
           <0.25-(L+W)/150, 0.25-(L+W)/150>
           pigment {
              color_sub
              }
           scale<L/2,W/2,T/2>
           }
        //Grundkoerper braun
        superellipsoid {
           <0.25-(L+W)/200, 0.25-(L+W)/200>
           scale<(K+L/100)/2,W/2,T/2> translate <(L-K)/2,0,0> texture {
              col_silver
              }
           }
        //rechter Anschluss
        superellipsoid {
           <0.25-(L+W)/200, 0.25-(L+W)/200>
           scale<(K+L/100)/2,W/2,T/2> translate <-(L-K)/2,0,0> texture {
              col_silver
              }
           }
        //linker Anschluss
        rotate<90,0,0>
        translate<0,T/2,0>
        }
  #end

  union {
     difference {
        box {
           <-3.5,0,-2.5> <+3.5,0.6,+2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+3.5,0,0> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-3.5,0,0> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<0,0,+2.5> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<0,0,-2.5> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+3.5,0,+2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-3.5,0,+2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+3.5,0,-2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-3.5,0,-2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-2.54,0,+2.5> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+2.54,0,+2.5> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-2.54,0,-2.5> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+2.54,0,-2.5> texture {
              T_Brass_3A
              }
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-1.17,0,+2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+1.17,0,+2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-1.17,0,-2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+1.17,0,-2.5>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+3.5,0,-1.12>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-3.5,0,-1.12>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<+3.5,0,+1.12>
           }
        cylinder {
           <0,-0.2,0> <0,0.8,0> 0.16
           translate<-3.5,0,+1.12>
           }
        pigment {
           rgb <0.44, 0.37, 0.40>
           }
        }
     union {
        superellipsoid {
           <0.15, 0.15>
           scale <2.7, 0.455,1.7> translate <0, 0.6+0.455, 0> texture {
              T_Brass_5A
              }
           }
        superellipsoid {
           <0.15, 0.15>
           scale <2.55, 0.55,1.55> translate <0, 0.6+0.55, 0> texture {
              T_Brass_5A
              }
           }
        superellipsoid {
           <0.15, 0.15>
           scale <2.5, 0.61,1.5> translate <0, 0.6+0.61, 0> texture {
              T_Brass_5A
              }
           }
        superellipsoid {
           <0.05, 0.05>
           scale <0.05, 0.2,0.3> translate <-2.75, 0.2+0.55, -1.1> texture {
              col_silver
              }
           }
        superellipsoid {
           <0.05, 0.05>
           scale <0.05, 0.2,0.3> translate <-2.75, 0.2+0.55, +1.1> texture {
              col_silver
              }
           }
        superellipsoid {
           <0.05, 0.05>
           scale <0.05, 0.2,0.3> translate <+2.75, 0.2+0.55, -1.1> texture {
              col_silver
              }
           }
        superellipsoid {
           <0.05, 0.05>
           scale <0.05, 0.2,0.3> translate <+2.75, 0.2+0.55, +1.1> texture {
              col_silver
              }
           }
        box {
           <-2.3,1.8,-1> <+2.3,1.83,+1>
           pigment {
              Gray50
              }
           }
        box {
           <-2,1.8,-1.3> <+2,1.83,+1.3>
           pigment {
              Gray50
              }
           }
        cylinder {
           <0,1.8,0> <0,1.83,0> 0.3
           translate<-2,0,+1> pigment {
              Gray50
              }
           }
        cylinder {
           <0,1.8,0> <0,1.83,0> 0.3
           translate<-2,0,-1> pigment {
              Gray50
              }
           }
        cylinder {
           <0,1.8,0> <0,1.83,0> 0.3
           translate<+2,0,+1> pigment {
              Gray50
              }
           }
        cylinder {
           <0,1.8,0> <0,1.83,0> 0.3
           translate<+2,0,-1> pigment {
              Gray50
              }
           }
        text {
           ttf global_fontfile_arial_bold "CMAC" 0.05, 0
           pigment {
              Gray30
              }
           scale <1,0,.8> rotate<90,0,0> translate<-2,1.84,+0.4>
           }
        // Marking
        text {
           ttf global_fontfile_arial_bold Type 0.05, 0
           pigment {
              Gray20
              }
           scale <0.8,1,1> rotate<90,0,0> translate<-1.5,1.84,-0.9>
           }
        // Marking
        translate 0.3*z
        }
     object {
        LM_OSC_CAPSMDCHIP(DarkWood,1.0,0.5,0.6,0.2)
        translate<0,0.6,-1.9>
        }
     object {
        LM_OSC_CAPSMDCHIP(DarkWood,1.0,0.5,0.6,0.2)
        translate<-2.2,0.6,-1.9>
        }
     object {
        LM_OSC_CAPSMDCHIP(Gray30,1.0,0.5,0.6,0.2)
        translate<+2.2,0.6,-1.9>
        }
     }
#end

#macro SPC_XTAL_OSZ_CFPT_37()
  SPC_XTAL_OSZ_CFPT_BASE("CFPT-37")
#end

#macro SPC_XTAL_OSZ_CFPT_125()
  SPC_XTAL_OSZ_CFPT_BASE("CFPT-125")
#end

#macro SPC_XTAL_OSZ_CFPT_126()
  SPC_XTAL_OSZ_CFPT_BASE("CFPT-126")
#end



/*******************************************************************************
 * Quartz oscillator DIP14
 * *****************************************************************************/
#macro SPC_XTAL_OSZ_DIP14(value)
  union {
     box {
        <-10.15,1,-5.6> <10.15,2,5.6>
        }
     box {
        <-9.15,1,-6.6> <9.15,2,6.6>
        }
     box {
        <-9.15,1,-5.6> <-10.15,2,-6.6>
        }
     cylinder {
        <9.15,1,-5.6> <9.15,2,-5.6>1
        }
     cylinder {
        <-9.15,1,5.6> <-9.15,2,5.6>1
        }
     cylinder {
        <9.15,1,5.6> <9.15,2,5.6>1
        }
     box {
        <-9.5,2,-4.95> <9.5,5,4.95>
        }
     box {
        <-8.5,2,-5.95> <8.5,5,5.95>
        }
     box {
        <-8.5,5,-4.95> <8.5,6,4.95>
        }
     sphere_sweep {
        linear_spline
        6
        <-8.5,2,-4.95>1
        <-8.5,5,-4.95>1
        <8.5,5,-4.95>1
        <8.5,5,4.95>1
        <-8.5,5,4.95>1
        <-8.5,5,-4.95>1
        }
     cylinder {
        <8.5,5,-4.95> <8.5,2,-4.95>1
        }
     cylinder {
        <8.5,5,4.95> <8.5,2,4.95>1
        }
     cylinder {
        <-8.5,5,4.95> <-8.5,2,4.95>1
        }
     cylinder {
        <-3*2.54,5,-3.8> <-3*2.54,6.01,-3.8> 0.4
        pigment {
           Black
           }
        }
     text {
        ttf besch_font value 0.5, 0
        pigment {
           White*0.5
           }
        scale<2,2,2> rotate<90,0,0> translate<-3*2.54,6.01,0>
        }
     cylinder {
        <-3*2.54,1,-3.8> <-3*2.54,-1*(pin_length+pcb_height)+0.2,-3.8> 0.2
        }
     cylinder {
        <3*2.54,1,-3.8> <3*2.54,-1*(pin_length+pcb_height)+0.2,-3.8> 0.2
        }
     cylinder {
        <3*2.54,1,3.8> <3*2.54,-1*(pin_length+pcb_height)+0.2,3.8> 0.2
        }
     cylinder {
        <-3*2.54,1,3.8> <-3*2.54,-1*(pin_length+pcb_height)+0.2,3.8> 0.2
        }
     sphere {
        <3*2.54-1,1,3.8-1> 0.8
        pigment {
           Gray20
           }
        }
     sphere {
        <3*2.54-1,1,-3.8+1> 0.8
        pigment {
           Gray20
           }
        }
     sphere {
        <-3*2.54+1,1,-3.8+1> 0.8
        pigment {
           Gray20
           }
        }
     sphere {
        <-3*2.54+1,1,3.8-1> 0.8
        pigment {
           Gray20
           }
        }
     translate<0,-0.2,0>
     texture {
        col_silver
        }
     }
#end




/*******************************************************************************
 * Quarz Oszillator im DIP8
 * *****************************************************************************/
#macro SPC_XTAL_OSZ_DIP8(value)
  union {
     box {
        <-10.15+1.5*2.54,1,-5.6> <10.15-1.5*2.54,2,5.6>
        }
     box {
        <-9.15+1.5*2.54,1,-6.6> <9.15-1.5*2.54,2,6.6>
        }
     box {
        <-9.15+1.5*2.54,1,-5.6> <-10.15+1.5*2.54,2,-6.6>
        }
     cylinder {
        <9.15-1.5*2.54,1,-5.6> <9.15-1.5*2.54,2,-5.6>1
        }
     cylinder {
        <-9.15+1.5*2.54,1,5.6> <-9.15+1.5*2.54,2,5.6>1
        }
     cylinder {
        <9.15-1.5*2.54,1,5.6> <9.15-1.5*2.54,2,5.6>1
        }
     box {
        <-9.5+1.5*2.54,2,-4.95> <9.5-1.5*2.54,5,4.95>
        }
     box {
        <-8.5+1.5*2.54,2,-5.95> <8.5-1.5*2.54,5,5.95>
        }
     box {
        <-8.5+1.5*2.54,5,-4.95> <8.5-1.5*2.54,6,4.95>
        }
     sphere_sweep {
        linear_spline
        6
        <-8.5+1.5*2.54,2,-4.95>1
        <-8.5+1.5*2.54,5,-4.95>1
        <8.5-1.5*2.54,5,-4.95>1
        <8.5-1.5*2.54,5,4.95>1
        <-8.5+1.5*2.54,5,4.95>1
        <-8.5+1.5*2.54,5,-4.95>1
        }
     cylinder {
        <8.5-1.5*2.54,5,-4.95> <8.5-1.5*2.54,2,-4.95>1
        }
     cylinder {
        <8.5-1.5*2.54,5,4.95> <8.5-1.5*2.54,2,4.95>1
        }
     cylinder {
        <-8.5+1.5*2.54,5,4.95> <-8.5+1.5*2.54,2,4.95>1
        }
     cylinder {
        <-3*2.54+1.5*2.54,5,-3.8> <-3*2.54+1.5*2.54,6.01,-3.8> 0.4
        pigment {
           Black
           }
        }
     text {
        ttf besch_font value 0.5, 0
        pigment {
           Black
           }
        scale 1.3 rotate<90,0,0> translate<-3*2.54+1.5*2.54,6.01,0>
        }
     cylinder {
        <-3*2.54+1.5*2.54,1,-3.8> <-3*2.54+1.5*2.54,-1*(pin_length+pcb_height)+0.2,-3.8> 0.2
        }
     cylinder {
        <3*2.54-1.5*2.54,1,-3.8> <3*2.54-1.5*2.54,-1*(pin_length+pcb_height)+0.2,-3.8> 0.2
        }
     cylinder {
        <3*2.54-1.5*2.54,1,3.8> <3*2.54-1.5*2.54,-1*(pin_length+pcb_height)+0.2,3.8> 0.2
        }
     cylinder {
        <-3*2.54+1.5*2.54,1,3.8> <-3*2.54+1.5*2.54,-1*(pin_length+pcb_height)+0.2,3.8> 0.2
        }
     sphere {
        <3*2.54-1-1.5*2.54,1,3.8-1> 0.8
        pigment {
           Gray20
           }
        }
     sphere {
        <3*2.54-1-1.5*2.54,1,-3.8+1> 0.8
        pigment {
           Gray20
           }
        }
     sphere {
        <-3*2.54+1+1.5*2.54,1,-3.8+1> 0.8
        pigment {
           Gray20
           }
        }
     sphere {
        <-3*2.54+1+1.5*2.54,1,3.8-1> 0.8
        pigment {
           Gray20
           }
        }
     translate<0,-0.2,0>
     texture {
        col_silver
        }
     }
#end



/*******************************************************************************
 * PLASTIC DIP8 & DIP14 CRYSTAL OSCILLATORS
 * J. ZEGLINSKI <JAZeglinski@rogers.com>
 * *****************************************************************************/
#macro SPC_XTAL_OSZ_PDIP_BASE(p,value)
  #macro OSZ_SYMBOL(Symbol_Color, Background_Color)
     // Create the "classic Oscillator symbol" at origin on X-Z Plane
     //    Basic symbol is (2.4mm wide x 1.2mm tall) - use "scale" on macro call to fit other size XTAL bodies
     #local T=0.15; // Symbol line thickness
     union {
        box {
           <(-0.1-T),0,(-0.6-T)> <(0.1+T),0,(0.6+T)>
           }
        box {
           <-0.1,0.01,-0.6> <0.1,0.01,0.6>
           pigment {
              Symbol_Color
              }
           }
        // set inside of box to IC body color to create a square "O"
        box {
           <(-0.5-T),0,-0.6-T> <-0.5,0.01,0.6+T>
           }
        box {
           <-0.5,0,-T/2> <-1.2,0,T/2>
           }
        box {
           <0.5+T,0,-0.6-T> <0.5,0,0.6+T>
           }
        box {
           <0.5,0,-T/2> <1.2,0,T/2>
           }
        texture {
           pigment {
              Background_Color
              }
           }
        }
  #end

  #if (p=8)
     union {
        object {
           IC_DIS_DIP8A4(value,"")
           }
        // use "IC.inc" macro to create PLASTIC DIP8 with 4 corner pins and "IC Name"
        // Add the "Crystal Oscillator Symbol" to IC created by macro with Name already on it.
        #local V=(3.2+0.01+0.25);   // vertical translation distance to final IC surface created in DIP08A4 macro
        object {
           OSZ_SYMBOL(Gray30,Gray60)
           scale<1.5,1,1> translate<0,V,2>
           }
        // Plot & scale the symbol, and move up into DIP surface position
        }
  #else
     union {
        object {
           IC_DIS_DIP14A4(value,"")
           }
        // use "IC.inc" macro to create PLASTIC DIP14 with 4 corner pins and "IC Name"
        // Add the "Crystal Oscillator Symbol" to IC created by macro with Name already on it.
        #local V=(3.2+0.01+0.25);   // vertical translation distance to final IC surface created in DIP14A4 macro
        object {
           OSZ_SYMBOL(Gray30,Gray60)
           scale<1.5,1,1> translate<0,V,2>
           }
        // Plot & scale the symbol, and elevate into DIP surface position
        }
  #end
#end

#macro SPC_XTAL_OSZ_PDIP8(value)
  SPC_XTAL_OSZ_PDIP_BASE(8,value)
#end

#macro SPC_XTAL_OSZ_PDIP14(value)
  SPC_XTAL_OSZ_PDIP_BASE(14,value)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//crystal:ASE=SPC_XTAL_OSZ_ASE(:ASE series 3.2 x 2.5 mm SMD Crystal Oscillator
//=SPC_XTAL_OSZ_CFPT_37(:SMD TCVCXO CFPT-37
//=SPC_XTAL_OSZ_CFPT_125(:SMD TCVCXO CFPT-125
//=SPC_XTAL_OSZ_CFPT_126(:SMD TCVCXO CFPT-126
//crystal:DIL14S=SPC_XTAL_OSZ_DIP14(:Quartz oscillator DIP14
//crystal:DIL08S=SPC_XTAL_OSZ_DIP8(:Quartz oscillator DIP8
//crystal:DIL08-4=SPC_XTAL_OSZ_PDIP8(:Quartz oscillator PLASTIC DIP8
//crystal:SG51=SPC_XTAL_OSZ_PDIP14(:Quartz oscillator PLASTIC DIP14
// end assignment
