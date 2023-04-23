/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Philips ARC241/242 and ARV241 chip array
 * 4 × 0603 sized resistors in one 1206-sized package
 * 10.04.2023, wk.
 ******************************************************************************/            
#macro RES_SMD_CHIP_ARRAY_BASE(L,W,T,A,B,P,E,G,C,termination,value)
  union {
     difference {
        // ceramics body with black top layer
        union {
           object {
              Round_Box_Union(
                 <-L/2,0.01,-W/2>
                 <+L/2,T   ,+W/2>
                 0.1)
              pigment {
                 White * 0.6
                 }
              }
           #if (termination = "convex")
              box {
                 <-(2*P-0.15),T     ,-(W-2*B)/2>
                 <+(2*P-0.15),T+0.02,+(W-2*B)/2>
                 pigment {
                    Black
                    }
                 }
              object { GRID(box { <-L/2,0,-B/4-0.01> <+L/2,T+0.02,+B/4+0.01> },W-B/2,1,2)
                 texture {
                    col_silver
                    }
                 }
           #else
              box {
                 <-L/2+0.05,T     ,-(W-2*B)/2>
                 <+L/2-0.05,T+0.02,+(W-2*B)/2>
                 pigment {
                    Black
                    }
                 }
              box {
                 <-(P+1.5*C),T     ,-W/2>
                 <+(P+1.5*C),T+0.02,+W/2>
                 pigment {
                    Black
                    }
                 }
           #end
           }
        #if (termination = "convex")
           object { GRID(GRID(box {<-C/2,-0.1,-B> <+C/2,T+0.1,+B>},P,3,1),W,1,2) }
        #else
           object { GRID(GRID(cylinder {<0,-0.1,0> <0,T+0.1,0> (A-0.1)/2},P,4,1),W,1,2) }
        #end
        }
     union {
        #if (termination = "convex")
           object { GRID(box {<-A/2,0,+W/2-B> <+A/2,T+0.01,+W/2>},P,4,1) }
           object { GRID(box {<-A/2,0,-W/2+B> <+A/2,T+0.01,-W/2>},P,4,1) }
        #else
           #local contact = difference {
              box { <-A/2,0,-G/2> <+A/2,T+0.03,+G/2-0.02> }
              cylinder { <0,-0.1,+G/2> <0,T+0.2,+G/2> A/4 }
              }
            object { GRID(contact,P,4,1) rotate <0,180,0> translate <0,0,-W/2+G/2> }
            object { GRID(contact,P,4,1)                  translate <0,0,+W/2-G/2> }
        #end

        texture {
           col_silver
           }
        }
     #local marking = text {
        ttf besch_font value 0.1, 0
        texture {
           col_bright_marking
           }
        }
     object {
        marking
        scale 0.8
        rotate <90,0,0>
        translate <-L/4,T+0.05,-W/5>
        }
     }
#end

#macro RES_SMD_CHIP_ARRAY_4x0603_convex(value)
  RES_SMD_CHIP_ARRAY_BASE(3.20,1.60,0.60,0.60,0.35,0.80,0.50,0.50,0.10,"convex",value)
#end

#macro RES_SMD_CHIP_ARRAY_4x0603_concave(value)
  RES_SMD_CHIP_ARRAY_BASE(3.20,1.60,0.55,0.40,0.30,0.80,0.00,0.30,0.10,"concave",value)
#end

// provide upscaled 4x0805 packages.
#macro RES_SMD_CHIP_ARRAY_4x0805_convex(value)
  RES_SMD_CHIP_ARRAY_4x0603_convex(value)  scale <5.08/3.20, 0.8/0.8, 2.20/1.60>
#end

#macro RES_SMD_CHIP_ARRAY_4x0805_concave(value)
  RES_SMD_CHIP_ARRAY_4x0603_concave(value) scale <5.08/3.20, 0.8/0.8, 2.20/1.60>
#end

// provide downscaled 4x0402 packages.
#macro RES_SMD_CHIP_ARRAY_4x0402_convex(value)
  RES_SMD_CHIP_ARRAY_4x0603_convex(value)  scale <2.00/3.20, 0.5/0.8, 1.00/1.60>
#end

#macro RES_SMD_CHIP_ARRAY_4x0402_concave(value)
  RES_SMD_CHIP_ARRAY_4x0603_concave(value) scale <2.00/3.20, 0.5/0.8, 1.00/1.60>
#end


// provide downscaled 4x0201 packages.
#macro RES_SMD_CHIP_ARRAY_4x0201_convex(value)
  RES_SMD_CHIP_ARRAY_4x0603_convex(value)  scale <1.40/3.20, 0.35/0.8, 0.60/1.60>
#end

#macro RES_SMD_CHIP_ARRAY_4x0201_concave(value)
  RES_SMD_CHIP_ARRAY_4x0603_concave(value) scale <1.40/3.20, 0.35/0.8, 0.60/1.60>
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//resistor-dil:EXB18V=RES_SMD_CHIP_ARRAY_4x0201_convex(:SMD cap array 4x0201 convex
//resistor-dil:EXB28V=RES_SMD_CHIP_ARRAY_4x0402_convex(:SMD cap array 4x0402 convex
//resistor-dil:EXB38V=RES_SMD_CHIP_ARRAY_4x0603_convex(:SMD cap array 4x0603 convex
//resistor-dil:EXBN8V=RES_SMD_CHIP_ARRAY_4x0402_concave(:SMD cap array 4x0402 concave
//resistor-dil:EXBS8V=RES_SMD_CHIP_ARRAY_4x0805_concave(:SMD cap array 4x0805 concave
//resistor-dil:EXBV8V=RES_SMD_CHIP_ARRAY_4x0603_concave(:SMD cap array 4x0603 concave:
//resistor-dil:YC124=RES_SMD_CHIP_ARRAY_4x0402_convex(:SMD cap array 4x0402 convex:
//resistor-dil:4X0402ARV341=RES_SMD_CHIP_ARRAY_4x0402_convex(:SMD cap array 4x0402 convex
//resistor-dil:CAT16=RES_SMD_CHIP_ARRAY_4x0603_concave(:SMD cap array 4x0603 concave
//resistor-dil:CAY16=RES_SMD_CHIP_ARRAY_4x0603_convex(:SMD cap array 4x0603 convex
//resistor-dil:0603-ARC=RES_SMD_CHIP_ARRAY_4x0603_concave(:SMD cap array 4x0603 concave
//resistor-dil:0603-ARV=RES_SMD_CHIP_ARRAY_4x0603_convex(:SMD cap array 4x0603 convex
//resistor-net:CTS742C083=RES_SMD_CHIP_ARRAY_4x0603_concave(:SMD cap array 4x0603 concave
// end assignment
