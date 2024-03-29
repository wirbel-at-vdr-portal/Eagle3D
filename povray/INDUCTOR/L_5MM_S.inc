/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Inductor d=8mm, h=10mm
 * A. Zihlmann, 12.2002, www.wueschomania.org
 ******************************************************************************/
#macro SPC_L_5MM_S(value)
  // Die Oberflaechenstruktur:
  #local OBERFLAECHE = texture {
     pigment {
        White * 0.3
        }
     }

  // Objekte des Spulenkoerpers
  #local L_PHASE = torus {
     4,0.5
     texture {
        OBERFLAECHE
        }
     }

  #local L_KABELNUT = cylinder {
     <0,-4,0>,
     <0,+4,0>,
     0.75
     texture {
        OBERFLAECHE
        }
     }

  #local L_BODEN = difference {
     cylinder {
        <0, 0, 0>,
        <0, 2, 0>,
        4
        texture {
           OBERFLAECHE
           }
        }
     union {
         object { L_PHASE}
         object { L_KABELNUT translate -4*x }
         object { L_KABELNUT translate +4*x }
         }
     }

  #local L_DECKEL = object {
     L_BODEN
     rotate x*180
     translate 2*y
     }

  #local L_CORE = cylinder {
     <0, 0, 0>,
     <0, 6, 0>,
     2
     texture {
        OBERFLAECHE
        }
     }

  #local L_KERN = union {
     object { L_BODEN }
     object { L_CORE   translate y*2 }
     object { L_DECKEL translate y*8 }
     }

  // Kupferlackkabelemente
  #local Drahtstaerke = 0.5;

  #local L_WINDUNG = torus {
     3, Drahtstaerke/2
     texture {
        T_Gold_1A
        }
     }

  #local L_ANSCHLUSS = torus {
     0.5, Drahtstaerke/2
     texture {
        T_Gold_1A
        }
     }

  #local L_BOGEN = difference {
     torus {
        1, Drahtstaerke/2
        rotate -90*x
        }
     union {
        box { <5, 5, -1>, <-5, 0, 1> }
        box { <0, 5, -1>, <5, -5, 1> }
        }
     texture {
        T_Gold_1A
        }
     }

  #local L_VERBINDUNG = cylinder {
     <0,0,0>
     <0,2,0>
     Drahtstaerke/2
     texture {
        T_Gold_1A
        }
     }

  #local L_SPULE = union {
     #local i=0;
     #while(i < 11)
        object {
           L_WINDUNG
           translate i*Drahtstaerke*y
           }
        #local i=i+1;
        #end
     }

  // Die Beinchen
  #local L_Beinchen = cylinder {
     <0,0,0>
     <0,6,0>
     0.25
     texture {
        T_Silver_1A
        }
     }

  // Zusammenbau der Spule:
  #local L_BAUTEIL = union {
     object { L_KERN }
     object { L_SPULE       translate (2+Drahtstaerke/2)*y }
     object { L_Beinchen    translate <-2.5,-6,0> }
     object { L_Beinchen    translate <2.5,-6,0> }
     object { L_ANSCHLUSS   translate <-2.5,-1,0> }
     object { L_ANSCHLUSS   translate <-2.5,-0.5,0> }
     object { L_BOGEN       translate -3*x }
     object { L_VERBINDUNG  translate -4*x }
     object { L_BOGEN       rotate -90*z translate <-3,2,0> }
     object { L_ANSCHLUSS   translate <2.5,-1,0> }
     object { L_ANSCHLUSS   translate <2.5,-0.5,0> }
     object { L_BOGEN       rotate 180*y translate 3*x }
     object { L_VERBINDUNG  translate 4*x }
     object { L_BOGEN       rotate 180*z translate <3,2,0> }
     text {
        ttf
        besch_font
        value
        0.01, 0
        pigment {
           White
           }
        scale 2
        rotate 90*x rotate 180*y
        translate <2,10+0.1,-0.5>
        }
     }

  object {
     L_BAUTEIL
     translate 2*y
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_L_5MM_S:Inductor d=8mm h=10mm
// end assignment
