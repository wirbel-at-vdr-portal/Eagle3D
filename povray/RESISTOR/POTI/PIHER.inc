/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * PIHER PT-10 series 10mm Carbon potentiometer.
 * Carsten Koegler <koegler@ftz-leipzig.de>
 *
 * NOTE: should be extended to the series of other PT10 variants,
 * see 'PIHER10-L_PIHER10-S#PIH.pdf'
 ******************************************************************************/
#macro RES_THT_TRIM_PT10_BASE(value)
  union {
     #local pt10_pin =
        difference {
           box {
              <-0.5,0,-0.05> <0.5,3.5,0.05>
              texture {
                 col_silver
                 }
              }
           box {
              <-0.5+0.6,0,-0.1> <0.5+0.6,4,0.1>
              rotate <0,0,-30>
              texture {
                 col_silver
                 }
              }
           box {
              <-0.5-0.6,0,-0.1> <0.5-0.6,4,0.1>
              rotate <0,0,+30>
              texture {
                 col_silver
                 }
              }
           translate <0,-3.5,0>
           };
     #local pt10_body =
        union {
           // black body
           difference {
              union {
                 superellipsoid {
                    <1,0.08>
                    scale <5.15,5.15,2.2>
                    rotate <90,0,0>
                    translate<0,2.2,0>
                    }
                 cylinder {
                    <0,2,0> <0,4.5,0> 2.5
                    }
                 }
              cylinder {
                 <0,-1,0> <0,5.0,0> 1.5
                 }
              cylinder {
                 <0,-1,0> <0,2.0,0> 4.5
                 }
              box {
                 <-6,-1,-1.5> <6,0.6,1.5>
                 }
              box {
                 <-1.0,-1,-6> <1.0,0.6,6>
                 }
              }
           superellipsoid {
              <0.03,0.08>
              scale <4.4,0.5,1.825>
              translate <0,3.9,-3.325>
              }
           box {
              <-0.5,4.0,-5.15> <0.5,4.5,-1.5>
              }
           #local nrPositions = 11;
           #local chars = "PIHER SPAIN";
           #local charNr = 0;
           #while (charNr < nrPositions)
              text {
                 ttf besch_font substr(chars, charNr+1, 1) .1, 0
                 pigment {
                    Gray20
                    }
                 scale 1.5
                 rotate <90,0,0>
                 rotate <0,2,0>
                 translate <0,4.45,0>
                 translate <0,0,3.5>
                 rotate <0,charNr*180/nrPositions-90,0>
                 }
              #local charNr = charNr + 1;
           #end

           difference {
              cylinder {
                 <0,0.5,0> <0,0.6,0> 4.75
                 texture {
                    col_silver
                    }
                 }
              cylinder {
                 <0,0,0> <0,1.0,0> 2.0
                 texture {
                    col_silver
                    }
                 }
              }
           #local my_angle = rand(global_seed)*270;
           difference {
              union {
                 cylinder {
                    <0,0,0> <0,4.5,0> 1.5
                    pigment {
                       White
                       }
                    }
                 cylinder {
                    <0,0,0> <0,2.0,0> 2.5
                    pigment {
                       White
                       }
                    }
                 }
              cylinder {
                 <0,-1,0> <0,0.5,0>2.0
                 pigment {
                    White
                    }
                 }
              difference {
                 box {
                    <-0.6,0,-0.6> <0.6,5,0.6>
                    pigment {
                       White
                       }
                    }
                 box {
                    <-1.0,0,-0.6> <1.0,5,0.6>
                    rotate <0,45,0>
                    translate <0.424,0,0.424>
                    pigment {
                       White
                       }
                    }
                 translate <0.2,0,0.2>
                 rotate <0,my_angle,0>
                 }
              box {
                 <-0.3,3.9,-2> <0.3,5.0,2>
                 rotate <0,my_angle+45,0>
                 pigment {
                    White
                    }
                 }
              box {
                 <-0.3,-1,-2> <0.3,0.5,2>
                 rotate <0,my_angle+45,0>
                 pigment {
                    White
                    }
                 }
              box {
                 <-0.3,-1,-1> <0.3,4,1>
                 rotate <0,my_angle+45,0>
                 pigment {
                    White
                    }
                 }
              }
           difference {
              box {
                 <-3.5,4.4,-5.15> <3.5,4.5,-1>
                 texture {
                    col_silver
                    }
                 }
              cylinder{
                 <0,2,0> <0,5.0,0> 2.55
                 texture {
                    col_silver
                    }
                 }
              box {<-1.5,4.0,-6> <1.5,5.0,-3.6>
                 texture {
                    col_silver
                    }
                 }
              box {<-0.6,4.0,-6> <0.6,5.0,0>
                 texture {
                    col_silver
                    }
                 }
              box {<-5,4.0,-2> <5,5.0,2>
                 rotate <0,-35,0>
                 translate <-3.5,0,0>
                 texture {
                    col_silver
                    }
                 }
              box {<-5,4.0,-2><5,5.0,2>
                 rotate <0,35,0>
                 translate <3.5,0,0>
                 texture {
                    col_silver
                    }
                 }
              }
           cylinder {
              <0.6,4.4,-3.6> <0.6,4.4,-2.5> 0.1
              texture {
                 col_silver
                 }
              }
           cylinder {<-0.6,4.4,-3.6> <-0.6,4.4,-2.5> 0.1
              texture {
                 col_silver
                 }
              }
           cylinder {<0,4.4,-0.85> <0,4.4,0.85> 0.1
              translate <0,0,-3.4>
              rotate <0,55,0>
              texture {
                 col_silver
                 }
              }
           cylinder {<0,4.4,-0.85> <0,4.4,0.85> 0.1
              translate <0,0,-3.4>
              rotate <0,-55,0>
              texture {
                 col_silver
                 }
              }
           superellipsoid {
              <0.3,0.3>
              scale <0.3,0.8,0.8>
              translate <2.65,3.9,-4.0>
              }
           superellipsoid {
              <0.3,0.3>
              scale <0.3,0.8,0.8>
              translate <-2.65,3.9,-4.0>
              }
           intersection {
              cylinder {
                 <0,0,0> <0,4.4,0> 5.17
                 pigment {
                    White
                    }
                 }
              union {
                 #local nrPositions = strlen(value);
                 #local chars = value;
                 #local charNr = 0;
                 #while (charNr < nrPositions)
                   text {
                      ttf besch_font substr(chars, charNr+1, 1) 0.3, 0
                      pigment {
                         White
                         }
                      scale 1.5
                      rotate <180,0,0>
                      translate <0,3,5.2>
                      rotate <0,(-nrPositions*10)/2+charNr*10,0>
                      }
                   #local charNr = charNr + 1;
                 #end
                 }
              }
           pigment {
              Gray20
              }
           };

     object {
        pt10_body
        translate <0,1.5,0.2>
        }
     object {
        pt10_pin
        translate <2.5,0,-5>
        }
     object {
        pt10_pin
        translate <-2.5,0,-5>
        }
     object {
        pt10_pin
        translate <0,0,5>
        }

     box {
        <-1.0,0,-0.05> <1.0,5.9,0.05>
        translate<-2.5,0,-5>
        texture {
           col_silver
           }
        }
     cylinder {
        <-1,5.9,0> <1,5.9,0>0.1
        translate <-2.5,0,-4.95>
        texture {
           col_silver
           }
        }
     box {
        <-1.0,0,-0.05> <1.0,5.9,0.05>
        translate <+2.5,0,-5>
        texture {
           col_silver
           }
        }
     cylinder {
        <-1,5.9,0> <1,5.9,0>0.1
        translate <+2.5,0,-4.95>
        texture {
           col_silver
           }
        }
     box {
        <-1.0,0,-0.05> <1.0,2.0,0.05>
        translate <0,0,5>
        texture {
           col_silver
           }
        }
     difference {
        cylinder {
           <-1,2.0,0> <1,2.0,0> 0.1
           translate <0,0,4.95>
           texture {
              col_silver
              }
           }
        box {
           <-1.0,0,-0.05> <1.0,2.0,0.05>
           translate <0,0,4.9>
           texture {
              col_silver
              }
           }
        }
     }
#end


/*******************************************************************************
 * for naming conventions, pls follow the datasheets order code.
 * for now, only the variant
 *   Series   = PT10  (PT-10, 10mm Carbon Potentiometer)
 *   Rotor    = L     (screw driver)
 *   Mounting = V(10) (v = horizontal mount – vertical adjust, size 10x5mm)
 * is supported. -> PT10LV10
 ******************************************************************************/
#macro RES_THT_TRIM_PT10LV10(value)
  RES_THT_TRIM_PT10_BASE(value)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//pot:PT-10=RES_THT_TRIM_PT10LV10(:PIHER PT-10 resistor trimmer PT10LV10
// end assignment
