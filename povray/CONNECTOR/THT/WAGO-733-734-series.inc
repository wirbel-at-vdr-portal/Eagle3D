/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * WAGO 733/734
 * Stefan Seegel <dahamm@gmx.net>
 *
 * Not in Eagle libs.
 ******************************************************************************/
#macro CON_WAGO73X_PINHEADER_BASE(pins, rm, wo, height, depth, h1, h2, h3, n1, n2, p1, p2, pw, ph)
  #macro WAGOSTIFT(w, h)
     difference {
        box {
           <-w/2,0,-w/2>
           <+w/2,h,+w/2>
           }
        texture {
           col_silver
           }
        }
  #end

  union {
     #local WIDTH = pins * rm + wo;

     difference {
        box {
           <-WIDTH/2,     0,-depth/2>
           <+WIDTH/2,height,+depth/2>
           }
        box {
           <-WIDTH/2+1,      h1,-depth/2+1.9>
           <+WIDTH/2-1,height+1,+depth/2-1.7>
           }
        box {
           <-WIDTH/2-0.5,        -1,-2.5>
           <-WIDTH/2+0.4,height-1.9,+2.5>
           }
        box {
           <+WIDTH/2+0.5,        -1,-2.5>
           <+WIDTH/2-0.4,height-1.9,+2.5>
           }
        box {
           <-WIDTH/2+0.7,      -1,-0.75>
           <-WIDTH/2+1.3,height+1,+0.75>
           }
        box {
           <+WIDTH/2-0.7,      -1,-0.75>
           <+WIDTH/2-1.3,height+1,+0.75>
           }
        box {
           <-WIDTH/2+0.7,      -1,-0.75>
           <-WIDTH/2+1.3,height+1,+0.75>
           }
        box {
           <WIDTH/2-0.7,      -1,-0.75>
           <WIDTH/2-1.3,height+1,+0.75>
           }
        box {
           <-WIDTH/2-0.1,       2.0,-0.75>
           <-WIDTH/2+1.1,height-1.9,+0.75>
           }
        box {
           <WIDTH/2+0.1,       2.0,-0.75>
           <WIDTH/2-1.1,height-1.9,+0.75>
           }
        box {
           <WIDTH/2-1.0,height-5.9,-depth/2+0.3>
           <WIDTH/2-2.4,height+1.0,-depth/2+2.0>
           }
        box {
           <-WIDTH/2+n1   ,height-5.9,-depth/2+0.3>
           <-WIDTH/2+n1+n2,height+1.0,-depth/2+2.0>
           }
        box {
           <-(pins-1)*rm/2-0.5,      +2,depth/2+1.0>
           <-(pins-1)*rm/2+0.5,height-2,depth/2-1.8>
           }
        box {
           <+(pins-1)*rm/2-0.5,      +2,depth/2+1.0>
           <+(pins-1)*rm/2+0.5,height-2,depth/2-1.8>
           }
        box {
           <-(pins-1)*rm/2-p1/2,-1,-depth/2-1.0>
           <-(pins-1)*rm/2+p1/2,h3,-depth/2+0.3>
           }
        box {
           <+(pins-1)*rm/2-p1/2,-1,-depth/2-1.0>
           <+(pins-1)*rm/2+p1/2,h3,-depth/2+0.3>
           }
        box {
           <-(pins-1)*rm/2-p2/2,-1,-depth/2-1>
           <-(pins-1)*rm/2+p2/2,h3,-depth/2+2>
           }
        box {
           <+(pins-1)*rm/2-p2/2,-1,-depth/2-1>
           <+(pins-1)*rm/2+p2/2,h3,-depth/2+2>
           }

        #local pin=0;
        #while (pin < pins)
           box {
              <-(pins-1)*rm/2+pin*rm-p1/2,       -1,depth/2+1>
              <-(pins-1)*rm/2+pin*rm+p1/2,height-h2,depth/2-1>
              }
           #local pin=pin+1;
        #end

        #local pin=1;
        #while (pin < pins - 1)
           box {
              <-(pins-1)*rm/2+pin*rm-p1/2,       -1,-depth/2-1.0>
              <-(pins-1)*rm/2+pin*rm+p1/2,height-h2,-depth/2+0.3>
              }
           box {
              <-(pins-1)*rm/2+pin*rm-p2/2,       -1,-depth/2-1>
              <-(pins-1)*rm/2+pin*rm+p2/2,height-h2,-depth/2+2>
              }
           #local pin=pin+1;
        #end

        pigment {
           Gray70
           }
        }
     #local pin=0;
     #while (pin < pins)
        box {
           <-(pins-1)*rm/2+pin*rm-1,0,-1>
           <-(pins-1)*rm/2+pin*rm+1,3,+1>
           pigment {
              Gray70
              }
           }
        object {
           WAGOSTIFT(pw, ph)
           translate <-(pins-1)*rm/2+pin*rm,height-ph-1.2,0>
           }
        #local pin=pin+1;
     #end
     }
#end

#macro WAGO733(pins)
  CON_WAGO73X_PINHEADER_BASE(pins, 2.5, 2.5,  8.9, 7.8, 2.0, 0.7, 3, 2.4, 1.4, 2.0, 0.8, 0.6, 12.3)
#end

#macro WAGO734(pins)
  CON_WAGO73X_PINHEADER_BASE(pins, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1.0, 0.8, 13.6)
#end


#macro CON_THT_WAGO733_332() WAGO733( 2) #end
#macro CON_THT_WAGO733_333() WAGO733( 3) #end
#macro CON_THT_WAGO733_334() WAGO733( 4) #end
#macro CON_THT_WAGO733_335() WAGO733( 5) #end
#macro CON_THT_WAGO733_336() WAGO733( 6) #end
#macro CON_THT_WAGO733_337() WAGO733( 7) #end
#macro CON_THT_WAGO733_338() WAGO733( 8) #end
#macro CON_THT_WAGO733_340() WAGO733(10) #end
#macro CON_THT_WAGO733_342() WAGO733(12) #end
#macro CON_THT_WAGO734_132() WAGO734( 2) #end
#macro CON_THT_WAGO734_133() WAGO734( 3) #end
#macro CON_THT_WAGO734_134() WAGO734( 4) #end
#macro CON_THT_WAGO734_135() WAGO734( 5) #end
#macro CON_THT_WAGO734_136() WAGO734( 6) #end
#macro CON_THT_WAGO734_137() WAGO734( 7) #end
#macro CON_THT_WAGO734_138() WAGO734( 8) #end
#macro CON_THT_WAGO734_139() WAGO734( 9) #end
#macro CON_THT_WAGO734_140() WAGO734(10) #end
#macro CON_THT_WAGO734_142() WAGO734(12) #end
#macro CON_THT_WAGO734_143() WAGO734(13) #end
#macro CON_THT_WAGO734_146() WAGO734(16) #end
#macro CON_THT_WAGO734_148() WAGO734(18) #end
#macro CON_THT_WAGO734_150() WAGO734(20) #end
#macro CON_THT_WAGO734_154() WAGO734(24) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CON_THT_WAGO733_332(:WAGO-733 Pinheader
//=CON_THT_WAGO733_333(:WAGO-733 Pinheader
//=CON_THT_WAGO733_334(:WAGO-733 Pinheader
//=CON_THT_WAGO733_335(:WAGO-733 Pinheader
//=CON_THT_WAGO733_336(:WAGO-733 Pinheader
//=CON_THT_WAGO733_337(:WAGO-733 Pinheader
//=CON_THT_WAGO733_338(:WAGO-733 Pinheader
//=CON_THT_WAGO733_340(:WAGO-733 Pinheader
//=CON_THT_WAGO733_342(:WAGO-733 Pinheader
//=CON_THT_WAGO734_132(:WAGO-734 Pinheader
//=CON_THT_WAGO734_133(:WAGO-734 Pinheader
//=CON_THT_WAGO734_134(:WAGO-734 Pinheader
//=CON_THT_WAGO734_135(:WAGO-734 Pinheader
//=CON_THT_WAGO734_136(:WAGO-734 Pinheader
//=CON_THT_WAGO734_137(:WAGO-734 Pinheader
//=CON_THT_WAGO734_138(:WAGO-734 Pinheader
//=CON_THT_WAGO734_139(:WAGO-734 Pinheader
//=CON_THT_WAGO734_140(:WAGO-734 Pinheader
//=CON_THT_WAGO734_142(:WAGO-734 Pinheader
//=CON_THT_WAGO734_143(:WAGO-734 Pinheader
//=CON_THT_WAGO734_146(:WAGO-734 Pinheader
//=CON_THT_WAGO734_148(:WAGO-734 Pinheader
//=CON_THT_WAGO734_150(:WAGO-734 Pinheader
//=CON_THT_WAGO734_154(:WAGO-734 Pinheader
// end assignment
