/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Ceramic Resonator
 * Producer: Abracon
 * Web: www.abracon.com
 * Part: ABM3B
 * Carsten Koegler <koegler(replace with at)ftz-leipzig.de>
 * *****************************************************************************/
#macro SPC_CRES_ABRACON_ABM3B_BASE(value)
  #local SPC_CRES_METAL_TEXTURE =
  texture {
     T_Chrome_5B
     };

  #local SPC_CRES_TEXT_PIGMENT =
  pigment {
     White*0.5
     };

  union {
     //Grundkoerper
     union {
        Round_Box_Union(<-2.5,0.03,-1.6>, <2.5,0.9, 1.6>, 0.05 )
        pigment {
           White*0.1
           }
        }
     //Anschlusspads
     box {
        <-0.5,0,-0.45> <0.5,0.3,0.45>
        texture {
           col_gold
           }
        translate<-2.05,0, 1.1>
        }
     box {
        <-0.5,0,-0.45> <0.5,0.3,0.45>
        texture {
           col_gold
           }
        translate<-2.05,0,-1.1>
        }
     box {
        <-0.5,0,-0.45> <0.5,0.3,0.45>
        texture {
           col_gold
           }
        translate< 2.05,0, 1.1>
        }
     box {
        <-0.5,0,-0.45> <0.5,0.3,0.45>
        texture {
           col_gold
           }
        translate< 2.05,0,-1.1>
        }
     Round_Box_Union(<-2.5,0.85,-1.6>, <2.5,1.0, 1.6>, 0.05 )
     Round_Box_Union(<-2.5+0.5,0.5,-1.6+0.5>, <2.5-0.5,1.1, 1.6-0.5>, 0.05 )
     text {
        ttf besch_font value 0.02, 0
        pigment {
           SPC_CRES_TEXT_PIGMENT
           }
        rotate<90,0,0> scale 1.0 translate<-1.5, 1.11,-0.1>
        }
     texture {
        SPC_CRES_METAL_TEXTURE
        }
     }
#end

#macro SPC_CRES_ABRACON_ABM3B(value)
  SPC_CRES_ABRACON_ABM3B_BASE(value)
#end



/*******************************************************************************
 * Murata cstce*g*a, Ceramic Resonator (discontinued)
 * *****************************************************************************/
#macro SPC_CRES_MURATA_CSTCE_G_A_BASE(value)
  union {
     //Grundkoerper
     box {
        <-1.6,0,-0.65> <1.6,0.4,0.65>
        pigment {
           White
           }
        }
     //Anschlussflaechen
     box {
        <-0.25,0,-0.6501> <0.25,0.3,0.6501>
        texture {
           col_gold
           }
        }
     box {
        <-0.25,0,-0.6501> <0.25,0.41,0.6501>
        texture {
           col_gold
           }
        translate<-1.2,0,0>
        }
     box {
        <-0.25,0,-0.6501> <0.25,0.41,0.6501>
        texture {
           col_gold
           }
        translate<1.2,0,0>
        }
     difference {
        Round_Box_Union(<-1.5,0.1,-0.55>, <1.5,0.7,0.55>, 0.1)
        text {
           ttf besch_font value 0.02, 0
           rotate<90,0,0> scale 0.5 translate<-1,0.701,-0.1>
           }
        texture {
           col_silver
           }
        }
     }
#end

#macro SPC_CRES_MURATA_CSTCE_G_A(value)
  SPC_CRES_MURATA_CSTCE_G_A_BASE(value)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_CRES_ABRACON_ABM3B(:Abracon Ceramic Resonator ABM3B
//=SPC_CRES_MURATA_CSTCE_G_A(:Murata cstce*g*a, Ceramic Resonator (discontinued)
// end assignment
