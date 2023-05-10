/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * CENTRONICS connector female, print (con-amp-champ.lbr)
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * Andreas Fecht <info(replace with at)vetter-und-fecht.de>
 * Duane Clark <dclark(replace with at)akamail.com>
 *
 * pitch 2.159mm
 * Nullpunkt linke Ecke des auesseren Plastikkoerpers
 * Plastikkoerperbreite = ps + 29
 * Dshellbreite = ps+10
 ******************************************************************************/
#macro CON_CENTRONICS_BASE(pin, female)
  #local PlasticBlue = color red 0.24 green 0.41 blue 0.81;
  #local j  = pin/2;      // number of pins in bottom row
  #local hs = 2.159;      // horizontal pin spacing
  #local hc = 9.525;      // horizontal centerline
  #local vs = 2*hs;       // vertical pin spacing
  #local vc = 7.5;        // vertical centerline
  #local ps = (j-1)*hs;   // total pin spacing
  #local bo = 31.3;       // body offset = body size - ps
  #local po = bo/2;       // offset to first pin
  #local so = 4.064;      // screwlock offset from body sides

  #macro D_shaped_shell(ps, vc)
     union {
        #local do = 12.5;       // dshell offset,   the dshell offset is (body size - dshell size)/2 + radius
        #local ds = do+6.3;     // do + dshell size - ps - (radius*2)     12.5 + ps+12.3 -ps -6
        
        cylinder {
           <do, vc+3, 0> <do, vc+3, -9> 3
           }
        cylinder {
           <ds+ps, vc+3, 0> <ds+ps, vc+3, -9> 3
           }
        cylinder {
           <do+1, vc-3, 0> <do+1, vc-3, -9> 3
           }
        cylinder {
           <ds+ps-1,vc-3, 0> <ds+ps-1,vc-3, -9> 3
           }
        box {
           <do, vc-0.1, 0> <ds+ps, vc+6, -9>
           }
        box {
           <do+1,vc  ,  0> <ds+ps-1,vc-6, -9>
           }
        box {
           <-2, vc+3, 0> <3.5, vc-3, -9>
           rotate <0,0,-9.62>
           translate <ds+ps-2.20,0,0>
           }
        box {
           <-2, vc+3, 0> <3.5, vc-3, -9>
           rotate <0,0, 9.62>
           translate <do+0.65, 0,0>
           }
        }
  #end

  //Metalloese in Frontplatte fuer den Buegel
  #macro MetalEyelet(ho,vo)
     difference {
        cylinder {
           <ho,vo-1.5,-1> <ho,vo+1.5,-1> 1.8
           }
        cylinder {
           <ho,vo-1.6,-1> <ho,vo+1.6,-1> 1.2
           }
        texture {
           T_Chrome_5B
           }
        }
  #end

  //Buegel an Frontplatte
  #macro MetalClip()
     #local bends=array[15] {
        <  0, 3, 0>,
        <-90, 1, 0>,
        <  0,10, 0>,
        <-45, 1, 0>,
        <  0, 6, 0>,
        <+90, 1, 0>,
        <  0, 9, 0>,
        <+90, 1, 0>,
        <  0, 9, 0>,
        <+90, 1, 0>,
        <  0, 6, 0>,
        <-45, 1, 0>,
        <  0,10, 0>,
        <-90, 1, 0>,
        <  0, 3, 0>
        }
     // this pipe has a radius of 0.4, starts at the origin,
     // and initially goes in the x direction
     TOOLS_BENTPIPE( 0.4, <0,0,0>, y, bends )
  #end

  union {
     difference {
        object {
           D_shaped_shell(ps, vc)
           translate <-0.6,-0.25,0>
           scale <1.05-(0.0014*j),1.04,1>
           }
        object {
           D_shaped_shell(ps, vc)
           scale <1,1,1.1>
           }
        texture {
           T_Chrome_5B
           }
        }
     #if (female)
        difference {
           object {
              D_shaped_shell(ps, vc)
              translate <0.7,0,+0.5>
              }
           box {
              <po-2.5, vc-vs/2, -2> <po+ps+2.5, vc+vs/2, -9.2>
              }
           // 5 mm breiter Schacht in der Mitte, 5mm breiter als pin spacing
           // Loecher ueber/unter den Pins
           #local i = 0;
           #while(i<j)
              box {
                 <po+hs*i-0.5, vc+vs/2+0.5, -2> <po+hs*i+0.5, vc+vs/2+1.5, -9.2>
                 }
              box {
                 <po+hs*i-0.5, vc-vs/2-0.5, -2> <po+hs*i+0.5, vc-vs/2-1.5, -9.2>
                 }
              #local i = i+1;
           #end
           pigment {
              PlasticBlue
              }
           }
        // buchsenpins
        #local i = 0;
        #while(i<j)
           cylinder {
              <po+hs*i, vc+vs/2, -2> <po+hs*i, vc+vs/2    , -7.5> 0.5
              texture {
                 col_gold
                 }
              }
           sphere {
              <po+hs*i, vc+vs/2    , -7.5> 0.5
              texture {
                 col_gold
                 }
              }
           sphere {
              <po+hs*i, vc+vs/2+0.5, -8  > 0.5
              texture {
                 col_gold
                 }
              }
           cylinder {
              <po+hs*i, vc-vs/2, -2> <po+hs*i, vc-vs/2    , -7.5> 0.5
              texture {
                 col_gold
                 }
              }
           sphere {
              <po+hs*i, vc-vs/2    , -7.5> 0.5
              texture {
                 col_gold
                 }
              }
           sphere {
              <po+hs*i, vc-vs/2-0.5, -8  > 0.5
              texture {
                 col_gold
                 }
              }
           #local i = i+1;
        #end
     #else
        // male
        box {
           <po-1.5, vc-vs/2, -0.5> <po+ps+1.5, vc+vs/2, -7>
           }
        // 4 mm breiter Steg in der Mitte , 3mm breiter asl pinspacing
        pigment {
           PlasticBlue
           }
        union {
           #local i = 0;
           #while(i<j)
              cylinder {
                 <po+hs*i,vc+vs/2,-0.5> <po+hs*i, vc+vs/2, -7> 0.5
                 texture {
                    col_gold
                    }
                 }
              sphere {
                 <po+hs*i, vc+vs/2, -7> 0.5
                 texture {
                    col_gold
                    }
                 }
              cylinder {
                 <po+hs*i,vc-vs/2,-0.5> <po+hs*i, vc-vs/2, -7> 0.5
                 texture {
                    col_gold
                    }
                 }
              sphere {
                 <po+hs*i, vc-vs/2, -7> 0.5
                 texture {
                    col_gold
                    }
                 }
              #local i = i+1;
           #end
           }
     #end

     // board pins
     union {
        #local i = 0;
        #while(i<j)
          cylinder {
             <po+hs*i,0,hc+vs/2> <po+hs*i,-3,hc+vs/2> 0.3
             texture {
                col_gold
                }
             }
          cylinder {
             <po+hs*i,0,hc-vs/2> <po+hs*i,-3,hc-vs/2> 0.3
             texture {
                col_gold
                }
             }
          #local i = i+1;
        #end
        }
     // screwlock backplates
     box {
        <bo+ps-so+2.5,3,4> <bo+ps-so+2.5,9.5,4.5>
        texture {
           T_Chrome_5B
           }
        }
     box {
        <so-2.5,3,4> <so+2.5,9.5,4.5>
        texture {
           T_Chrome_5B
           }
        }
     // lower plates
     box {
        <bo+ps-so-1.5,3,4> <bo+ps-so+1.5,3.25,hc+0.5>
        texture {
           T_Chrome_5B
           }
        }
     box {
        <so-1.5,3,4> <so+1.5,3.25,hc+0.5>
        texture {
           T_Chrome_5B
           }
        }
     // mounting tabs
     box {
        <bo+ps-so-1.5,-4,hc-0.5> <bo+ps-so-0.5,3.25,hc+0.5>
        texture {
           col_silver
           }
        }
     box {
        <so-1.5,-4,hc-0.5> <so-0.5,3.25,hc+0.5>
        texture {
           col_silver
           }
        }
     box {
        <bo+ps-so+1.5,-4,hc-0.5> <bo+ps-so+0.5,3.25,hc+0.5>
        texture {
           col_silver
           }
        }
     box {
        <so+1.5,-4,hc-0.5> <so+0.5,3.25,hc+0.5>
        texture {
           col_silver
           }
        }
     // main plastic body
     difference {
        box {
           < 0,      0, 0> <bo+ps,    13.5, 15>
           }
        //alles
        box {
           <bo-7+ps, 3, 4> <bo+0.1+ps,13.6, 15.1>
           }
        // 1. ecke ab
        box {
           <-0.1,    3, 4> <7,        13.6, 15.1>
           }
        // 2. ecke ab
        cylinder {
           <bo-7+ps, 13, 4>  <bo-7+ps, 13, 15.1> 1
           }
        // seitliche obere kanten ausbohren
        cylinder {
           <7,       13, 4>  <7,       13, 15.1> 1
           }
        cylinder {
           <bo-so+ps, 3.1,  hc> <bo-so+ps, -0.1, hc>   1.7
           }
        // vertikale 3.4 mm Loecher fuer Platinenbefestigung
        cylinder {
           <so,       3.1,  hc> <so,       -0.1, hc>   1.7
           }
        }
     // seitliche obere ausgebohrte Kanten abrunden
     cylinder {
        <bo-8+ps,12.5,4> <bo-8+ps,12.5,15> 1
        }
     cylinder {
        <8,12.5,4> <8,12.5,15> 1
        }
     // duenne plastik-Lage hinter Frontplatte oberhalb des main body,
     // mit runden ecken, 2mm dick
     box {
        <1.5,13,0> <bo+ps-1.5,15,2>
        }
     cylinder {
        <bo-1.5+ps,13.5,0> <bo-1.5+ps,13.5,2> 1.5
        }
     cylinder {
        <1.5,13.5,0> <1.5,13.5,2> 1.5
        }
     // Blech hinter der D shell , 1 mm dick,
     // Rundungsradius 1,5 mm an allen ecken
     box {
        <0,1.5,0> <bo+ps,13.5,-1>
        texture {
           T_Chrome_5B
           }
        }
     box {
        <1.5,13.5,0> <bo+ps-1.5,15,-1>
        texture {
           T_Chrome_5B
           }
        }
     cylinder {
        <bo+ps-1.5,13.5,0> <bo+ps-1.5,13.5,-1> 1.5
        texture {
           T_Chrome_5B
           }
        }
     cylinder {
        <1.5,13.5,0> <1.5,13.5,-1> 1.5
        texture {
           T_Chrome_5B
           }
        }
     box {
        <1.5,0,0> <bo+ps-1.5,1.5,-1>
        texture {
           T_Chrome_5B
           }
        }
     cylinder {
        <bo+ps-1.5,1.5,0> <bo+ps-1.5,1.5,-1> 1.5
        texture {
           T_Chrome_5B
           }
        }
     cylinder {
        <1.5,1.5,0> <1.5,1.5,-1> 1.5
        texture {
           T_Chrome_5B
           }
        }
     //Schrauben
     object {
        TOOLS_SCREW (2.5,7,1,PlasticBlue)
        rotate <-90,0,0>
        translate <so,vc,-1>
        texture {
           col_silver
           }
        }
     object {
        TOOLS_SCREW (2.5,7,1,PlasticBlue)
        rotate <-90,0,0>
        translate <bo+ps-so,vc,-1>
        texture {
           col_silver
           }
        }
     //Oesen
     object {
        MetalEyelet(so+2      , vc-4.5)
        texture {
           T_Chrome_5B
           }
        }
     object {
        MetalEyelet(so+2      , vc+4.5)
        texture {
           T_Chrome_5B
           }
        }
     object {
        MetalEyelet(bo+ps-so-2, vc-4.5)
        texture {
           T_Chrome_5B
           }
        }
     object {
        MetalEyelet(bo+ps-so-2, vc+4.5)
        texture {
           T_Chrome_5B
           }
        }
     //Buegel
     object {
        MetalClip()
        rotate <0,-30,0>
        translate <so+2, vc-6.5,-1.5>
        texture {
           T_Chrome_5B
           }
        }
     object {
        MetalClip()
        rotate <0,210,0>
        translate <bo+ps-so-2, vc-6.5,-1.5>
        texture {
           T_Chrome_5B
           }
        }
     translate <0-po-ps/2,0,0-hc>
     rotate <0,180,0>
     pigment {
       PlasticBlue
       }
     }
#end

#macro CON_CENTRONICS_F14() CON_CENTRONICS_BASE(14, true) #end
#macro CON_CENTRONICS_F24() CON_CENTRONICS_BASE(24, true) #end
#macro CON_CENTRONICS_F36() CON_CENTRONICS_BASE(36, true) #end
#macro CON_CENTRONICS_F50() CON_CENTRONICS_BASE(50, true) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-amp-champ:14H=CON_CENTRONICS_F14(:Centronics 14-pin 90deg female
//con-amp-champ:14HP=CON_CENTRONICS_F14(:Centronics 14-pin 90deg female
//con-amp-champ:24H=CON_CENTRONICS_F24(:Centronics 24-pin 90deg female
//con-amp-champ:24HP=CON_CENTRONICS_F24(:Centronics 24-pin 90deg female
//con-amp-champ:36H=CON_CENTRONICS_F36(:Centronics 36-pin 90deg female
//con-amp-champ:36HP=CON_CENTRONICS_F36(:Centronics 36-pin 90deg female
//con-amp-champ:50H=CON_CENTRONICS_F50(:Centronics 50-pin 90deg female
//con-amp-champ:50HP=CON_CENTRONICS_F50(:Centronics 50-pin 90deg female
// end assignment
