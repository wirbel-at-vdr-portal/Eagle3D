/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Murata Chip Coil: 2012 LQH3C/N
 * R. Klenner
 ******************************************************************************/
#macro SPC_L_MURATA_2012_LQH3C(value)
  #local OBERFLAECHE = texture { // Die Oberflaechenstruktur:
     pigment {
        White * 0.3
        }
     }

  #local L_QUAD= box { // Objekte des Spulenkoerpers
     <-1.3,0,-1.3> <1.3,0.35,1.3>
     texture {
        OBERFLAECHE
        }
     }

  #local Drahtstaerke = 0.025;

  #local L_Boden = union {
     box { <-1.5,0,-1.45> <1.5,0.275,1.45>
        texture {
           OBERFLAECHE
           }
        }
     box { <-2,0,-1.5> <-1.5,0.3,1.5>
        texture {
           T_Silver_1A
           }
        }
     box { <2,0,-1.5> <1.5,0.325,1.5>
        texture {
           T_Silver_1A
           }
        }
     union {
        difference {
           cylinder { <0,0,0> <0,0.45,0>1.4
              texture {
                 OBERFLAECHE
                 }
              }
           cylinder { <-2,0.45,1> <0,0.45,0.5> 0.2}
           cylinder { <2,0.45,-1> <0,0.45,-0.5> 0.2}
           }
        cylinder { <-1.8,0.2,1> <0,0.5,+0.5> Drahtstaerke texture {T_Gold_1A }}
        cylinder { <1.8,0.2,-1> <0,0.5,-0.5> Drahtstaerke texture {T_Gold_1A }}
        }
     }

    #local L_CORE = cylinder { <0, 0, 0> <0, 1, 0>1 texture {OBERFLAECHE }
    }

  #local L_KERN = union {
     object { L_Boden }
     object { L_CORE translate y*0.25 }
     object { L_QUAD translate y*1.25 }
     }

  #local L_WINDUNG = torus { // Kupferlackkabelemente
     1.1, Drahtstaerke/2
     texture {
        T_Gold_1A
        }
     }

  #local L_SPULE = union {
     #local i=0;
     #while(i<33)
        object {
           L_WINDUNG
           translate i * Drahtstaerke * y
           }
        #local i=i+1;
        #end
     }


  #local L_BAUTEIL = union { // Zusammenbau der Spule:
     object { L_KERN }
     object { L_SPULE translate (0.3+Drahtstaerke/2)*y }
     text {
        ttf besch_font value 0.01, 0
        pigment {
           Red
           }
        scale 0.5
        rotate 90*x rotate 180*y
        translate <0.35,1.51,0>
        }
     }

  object { L_BAUTEIL }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_L_MURATA_2012_LQH3C:MURATA Chip Coil
// end assignment
