/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMA jack (female)
 * written from scratch, 20.05.2023, wk
 *
 * starts at <0,0,0>
 * connector end goes up to <0,-11.6,0>
 ******************************************************************************/
#macro SMA_female(Long)
  union {
     #local inch = 25.40;
     #if (Long)
        #local L = 13.5;
        #local T = -7/2+6;
        #local TE = 9.6;
     #else
        #local L = 11;
        #local T = -7/2+2;
        #local TE = 0.17*inch;
     #end
     intersection {
        object {
           TOOLS_SCREW (6.35,L,-1,Gold)
           texture {
              pigment {
                 Gold
                 }
              normal {
                 bumps 0.001
                 scale 0.01
                 }
              finish {
                 ambient 0.7
                 diffuse 0.02
                 specular 0.3
                 roughness 0.01
                 reflection {
                    0.3,0.6 falloff 3
                    metallic 1
                    exponent 1.5
                    }
                 brilliance 2
                 }
              }
           rotate <90,0,0>
           translate <0,0,T>
           }
        union {
           difference {
              union {
                 cylinder {
                    <0,0,     +7/2>
                    <0,0,-15.1+7/2>
                    (0.212*inch)/2
                    }

                 cylinder {
                    <0,0,-15.1+7/2+TE>
                    <0,0,-15.1+7/2+0.03*inch>
                    (0.251*inch)/2
                    }
                 }        
              cylinder {
                 <0,0,         +0.1>
                 <0,0,-15.1+7/2-0.1>
                 (0.161*inch)/2
                 }
              cylinder {
                 <0,0,-15.1+7/2+0.076*inch>
                 <0,0,-15.1-0.1>
                 (0.183*inch)/2
                 }
              }
           difference {
              cylinder {
                 <0,0,-15.1+7/2+0.076*inch+0.1>
                 <0,0,-15.1+7/2+0.076*inch+3>
                 (0.05*inch)/2
                 }
              cylinder {
                 <0,0,-15.1+7/2+0.076*inch  -0.1>
                 <0,0,-15.1+7/2+0.076*inch+3+0.1>
                 (0.05*inch)/2*(15/21)
                 }
              box {
                 <-2/2,-0.05,-15.1+7/2+0.076*inch-0.1>
                 <+2/2,+0.05,-15.1+7/2+0.076*inch+2.5>
                 }
              }
           }
        texture {
           pigment {
              Gold
              }
           normal {
              bumps 0.001
              scale 0.01
              }
           finish {
              ambient 0.7
              diffuse 0.02
              specular 0.3
              roughness 0.01
              reflection {
                 0.3,0.6 falloff 3
                 metallic 1
                 exponent 1.5
                 }
              brilliance 2
              }
           }
        }
     difference {
        cylinder {
           <0,0,-15.1+7/2+0.076*inch+0.05>
           <0,0,0>
           (0.16*inch)/2
           }
        cylinder {
           <0,0,-15.1+7/2+0.076*inch-0.1>
           <0,0,0.1>
           (0.051*inch)/2
           }
        texture {
           pigment {
              White * 0.95
              }
           normal {
              bumps 0.05
              scale 0.1
              }
           finish {
              ambient 0.6
              diffuse 0.2
              }
           }
        }
     }
#end

/*******************************************************************************
 * SMA Nut for SMA female connectors
 * 21.05.2023, wk
 ******************************************************************************/
#macro SMA_Nut()
  intersection {
     difference {
        object {
           Hexagon
           scale <1,4,4>
           }
        object {
           TOOLS_SCREW (6.35,6,-1,Gold)
           texture {
              pigment {
                 Gold
                 }
              normal {
                 bumps 0.001
                 scale 0.01
                 }
              finish {
                 ambient 0.7
                 diffuse 0.02
                 specular 0.3
                 roughness 0.01
                 reflection {
                    0.3,0.6 falloff 3
                    metallic 1
                    exponent 1.5
                    }
                 brilliance 2
                 }
              }
           rotate <0,0,90>
           translate <-3,0,0>
           }
        }
     cylinder {
        <0,0,-1.1>
        <0,0, 1.1> 4.57
        rotate <0,90,0>
        }
     sphere {
        <0,0,0>
        5
        scale y*0.3
        rotate <0,0,90>
        }
     texture {
        pigment {
           Gold
           }
        normal {
           bumps 0.001
           scale 0.01
           }
        finish {
           ambient 0.7
           diffuse 0.02
           specular 0.3
           roughness 0.01
           reflection {
              0.3,0.6 falloff 3
              metallic 1
              exponent 1.5
              }
           brilliance 2
           }
        }
     }
#end

/*******************************************************************************
 * SMA jack (female), print, 90 deg
 * written from scratch, 20.05.2023, wk
 ******************************************************************************/
#macro CON_THT_SMA_H()
  union {
     object {
        SMA_female(off)
        translate <0,6.34,0>
        }
     intersection {
        box {
           <-7/2,-7/2,-7/2>
           <+7/2,+7/2,+7/2>
           }
        sphere {
           <0,0,0>
           7/2*1.2
           scale <1.5,0,1.5>
           }

        translate <0,6.34,0>
        }
     #local h1 = 0.35;
     #local h2 = 1.60;
     #local h3 = (2.84+0.01)-h2-h1;
     cylinder {
        <0,h1+h2,0> <0,h1+h2+h3,0> 6.35/2
        }
     box {
        <-7/2,h1   ,-7/2>
        <+7/2,h1+h2,+7/2>
        }
     GRID(
        box {
           #local X = 1.5;
           <-X/2, 0,-X/2>
           <+X/2,h1,+X/2>
           }
        7-X,2,2
        )
     GRID(
        box {
           <-1/2,   0,-1/2>
           <+1/2,-3.9,+1/2>
           }
        5.08,2,2
        )
     cylinder {
        <0,  h1,0>
        <0,-3.9,0>
        1.25/2
        }
     texture {
        pigment {
           Gold
           }
        normal {
           bumps 0.001
           scale 0.01
           }
        finish {
           ambient 0.7
           diffuse 0.02
           specular 0.3
           roughness 0.01
           reflection {
              0.3,0.6 falloff 3
              metallic 1
              exponent 1.5
              }
           brilliance 2
           }
        }
     rotate <0,-90,0>
     }
#end

/*******************************************************************************
 * SMA jack (female), print, 90 deg
 * 21.05.2023, wk
 ******************************************************************************/
#macro CON_THT_SMA_G()
  union {
     object {
        SMA_female(on)
        translate <0,6.4,-4.4>
        }
     object {
        SMA_Nut()
        rotate <16,90,0>
        translate <0,6.4,-7.8>
        }
     intersection {
        box {
           <-7/2,-7/2,-7/2>
           <+7/2,+7/2,+7/2>
           }
        sphere {
           <0,0,0>
           7/2*1.2
           scale <1.5,0,1.5>
           }
        translate <0,6.4,0>
        }
     cylinder {
        <0,6.4,-3.5>
        <0,6.4,-5.2>
        8.0/2
        }
     cylinder {
        <0,6.4,-5.2>
        <0,6.4,-5.7>
        7.0/2
        }
     box {
        <-7/2,  0,-7/2>
        <+7/2,6.4,+7/2>
        }
     GRID(
        box {
           <-1/2,   0,-1/2>
           <+1/2,-3.9,+1/2>
           }
        5.08,2,2
        )
     cylinder {
        <0,   0,0>
        <0,-3.9,0>
        1.25/2
        }
     texture {
        pigment {
           Gold
           }
        normal {
           bumps 0.001
           scale 0.01
           }
        finish {
           ambient 0.7
           diffuse 0.02
           specular 0.3
           roughness 0.01
           reflection {
              0.3,0.6 falloff 3
              metallic 1
              exponent 1.5
              }
           brilliance 2
           }
        }
     rotate <0,-90,0>
     }
#end

/*******************************************************************************
 * SMA jack (female), print, straight
 * written from scratch, 20.05.2023, wk
 ******************************************************************************/
#macro CON_THT_SMA_V()
  union {
     intersection {
        object {
           SMA_female(off)
           rotate <90,0,0>
           translate <0,-2.1,0>
           }
        cylinder {
           <0,  0,0>
           <0,9.5,0>
           7/2
           }
        }
     box {
        <-6.35/2,  0,-6.35/2>
        <+6.35/2,1.6,+6.35/2>
        }
     GRID(
        box {
           <-0.8/2,   0,-0.8/2>
           <+0.8/2,-3.9,+0.8/2>
           }
        5.08,2,2
        )
     cylinder {
        <0,+0.1,0>
        <0,-3.9,0>
        1.25/2
        }
     texture {
        pigment {
           Gold
           }
        normal {
           bumps 0.001
           scale 0.01
           }
        finish {
           ambient 0.7
           diffuse 0.02
           specular 0.3
           roughness 0.01
           reflection {
              0.3,0.6 falloff 3
              metallic 1
              exponent 1.5
              }
           brilliance 2
           }
        }
     }
#end

/*******************************************************************************
 * SMA jack (female), print, straight
 * 21.05.2023, wk
 ******************************************************************************/
#macro CON_SMT_SMA_STRAIGHT()
  union {
     intersection {
        object {
           SMA_female(off)
           rotate <90,0,0>
           translate <0,-2.76,0>
           }
        cylinder {
           <0,  0,0>
           <0,9.0,0>
           7/2
           }
        }
     box {
        <-6.35/2,    +1.27,-6.35/2>
        <+6.35/2,8.84-6.55,+6.35/2>
        }
     GRID(
        box {
           <-1.59/2,   0,-1.59/2>
           <+1.59/2,1.27,+1.59/2>
           }
        6.35-1.59,2,2
        )
     cylinder {
        <0,   0,0>
        <0,1.27,0>
        1.27/2
        }
     texture {
        pigment {
           Gold
           }
        normal {
           bumps 0.001
           scale 0.01
           }
        finish {
           ambient 0.7
           diffuse 0.02
           specular 0.3
           roughness 0.01
           reflection {
              0.3,0.6 falloff 3
              metallic 1
              exponent 1.5
              }
           brilliance 2
           }
        }
     }
#end


























/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-coax:BU-SMA-H=CON_THT_SMA_H(:SMA jack, 90 deg
//con-coax:BU-SMA-G=CON_THT_SMA_G(:SMA jack, 90 deg
//con-coax:BU-SMA-V=CON_THT_SMA_V(:SMA jack, straight
// end assignment
