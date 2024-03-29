/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * FEMALE PRINT CONNECTOR DIN 45323 (34V/3A), ROKA, distributor Conrad
 * Friedrich Bleikamp <fbleikamp@web.de>
 *
 * seems to be 1:1 Lumberg NEB1R (Distrelec 300-68-533)
 * renamed && formatted, 16.06.2023, -wk
 * rotated && translated, 16.06.2023, -wk
 ******************************************************************************/
#macro CON_THT_Power_NEB1R()
  union {
     //Kunstoff
     difference {
        merge {
           cylinder {
              <0,6.5,0> <10.5,6.5,0> 4.25
              }
           box {
              <0,0,-6>, <5.2,6.2,6>
              }
           box {
              <0,0,-4>, <1.6,13,4>
              translate <-1.6,0,0>
              }
           box {
              <0,0,-6>, <1.1,14,6>
              translate <-2.7,0,0>
              }
           cylinder {
              <10.0,6.5,0> <14.0,6.5,0> 2.5
              }
           }
        cylinder {
           <-3,6.5,0> <8.7,6.5,0> 3.25
           }
        cylinder {
           <8.5,6.5,0> <14.6,6.5,0> 2.25
           }
        box {
           <0.1,-0.1,-3>, <9,14,3>
           }
        box {
           <0.1,-0.1,-4.5>, <9,4.5,-5.5>
           }
        box {
           <0.1,-0.1,4.5>, <9,4.5,5.5>
           }
        pigment {
           Gray30
           }
        }
     difference {
        merge {
           cylinder {
              <12.6,6.5,0> <14,6.5,0> 4.5
              }
           box {
              <12.6,0,-4.5>, <14,6.5,4.5>
              }
           box {
              <14,0,-4.5>, <15.5,2.5,4.5>
              }
           }
        cylinder {
           <12.5,6.5,0> <14.1,6.5,0> 2.55
           }
        box {
           <0,0,-4.6>, <2,3.5,4.6>
           rotate <0, 0, 20>
           translate <15.4,-0.2,0>
           }
        pigment {
           Gray30
           }
        }
     //Mittenkontakt
     difference {
        merge {
           sphere {
              <0, 6.5, 0>, 1.05
              }
           cylinder {
              <0,6.5,0> <6,6.5,0> 1.05
              }
           cylinder {
              <6,6.5,0> <6.6,6.5,0> 3
              }
           cylinder {
              <6.6,6.5,0> <12.1,6.5,0> 2.1
              }
           //Vernietung
           difference {
              torus {
                 2.1, 0.5
                 }
              box {
                 <-10,0,-10>, <10,-2.5,10>
                 }
              rotate <0, 0, -90> translate <12.0,6.5,0>
              }
           translate <2.6,0,0>
           }
        cone {
           <14.01, 6.5, 0> 1.7
           <13, 6.5, 0>, 0.0
           }
        cylinder {
           <14.0,6.5,0> <18,6.5,0> 1.7
           }
        texture {
           col_silver
           }
        }
     //Loetanschluss Mitte
     difference {
        merge {
           cylinder {
              <14,6.5,0> <14.5,6.5,0> 4
              }
           box {
              <14,2.5,-4>, <14.5,6.5,4>
              }
           object {
              TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25)
              rotate <90,90,180>
              translate <14.25,3.5,5.25>
              }
           cylinder {
              <0.5,3.5,5> <0.5,3.5,5.5> 1
              }
           box {
              <1.25,0,5>, <3.75,2.5,5.5>
              }
           object {
              TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25)
              rotate <-90,-90,180>
              translate <14.25,3.5,-5.25>
              }
           box {
              <2,-2.5,5>, <3,0,5.5>
              }
           cylinder {
              <0,3.5,-5> <0,3.5,-5.5> 1
              translate <0.5,0,0>
              }
           box {
              <1.25,0,-5>, <3.75,2.5,-5.5>
              }
           box {
              <2,-2.5,-5>, <3,0,-5.5>
              }
           }
        cylinder {
           <13.9,6.5,0> <14.6,6.5,0> 2
           }
        texture {
           col_silver
           }
        }
     //Loetanschluss Schalter
     difference {
        merge {
           cylinder {
              <10.5,6.5,0> <11.0,6.5,0> 4
              }
           object {
              TOOLS_RECT_BOGEN(0.3,85,0.5,4,3,5)
              rotate <0,180,90>
              translate <10.75,11.75,0>
              }
           sphere {
              <6.5, 11.6, 0>, 0.5
              translate <0,0,0>
              }
           object {
              TOOLS_RECT_BOGEN(0.3,125,0.5,3,3,2.2)
              rotate <0,0.0,90>
              translate <10.75,1.8,0>
              }
           object {
              TOOLS_RECT_BOGEN(0.3,125,0.51,1,2.5,0.3)
              rotate <0,0,-90>
              translate <8.4,0.6,0>
              }
           }
        cylinder {
           <10.4,6.5,0> <11.1,6.5,0> 2.55
           }
        texture {
           col_silver
           }
        }
     //Isolierscheibe
     difference {
        cylinder {
           <11.0,6.5,0> <11.5,6.5,0> 4.5
           }
        cylinder {
           <10.9,6.5,0> <11.6,6.5,0> 2.51
           }
        pigment {
           Sienna
           }
        }
     //Federkontakt Aussen
     difference {
        merge {
           cylinder {
              <11.5,6.5,0> <12.0,6.5,0> 4
              }
           box {
              <11.5,4.5,-3.25>, <12.0,1.0,3.25>
              }
           }
        cylinder {
           <11.4,6.5,0> <12.1,6.5,0> 2.55
           }
        texture {
           col_silver
           }
        }
     //Loetanschluss Aussen u. Schalter
     difference {
        merge {
           cylinder {
              <12.05,6.5,0> <12.6,6.5,0> 4
              }
           object {
              TOOLS_RECT_BOGEN(0.75,39.85,0.5,4,4,0)
              rotate <0,180,90>
              translate <12.3,13.5,0>
              }
           object {
              TOOLS_RECT_BOGEN(0.3,132.0,0.5,4,7.98,0)
              rotate <0,180,7.5>
              translate <10.7,13,0>
              }
           object {
              TOOLS_RECT_BOGEN(0.3,90,0.5,4,0,1.65)
              rotate <180,0,7.5>
              translate <1.8,11.83,0>
              }
           object {
              TOOLS_RECT_BOGEN(0.3,125,0.5,4,2,0)
              rotate <0,0,-27.5>
              translate <1.88,9.52,0>
              }
           object {
              TOOLS_RECT_BOGEN(0.5,125,0.5,4,2,0)
              rotate <0,0,22.5>
              translate <4.08,8.03,0>
              }
           box {
              <12.05,4.5,-1.5>, <12.6,0,1.5>
              }
           box {
              <12.05,0,-0.5>, <12.5,-2.5,0.5>
              }
           }
        cylinder {
           <11.9,6.5,0> <12.7,6.5,0> 2.55
           }
        texture {
           col_silver
           }
        }
     translate <-2.5,0,0>
     rotate <0,-90,0>
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-conrad:737992-5=CON_THT_Power_NEB1R(:Power Connector DIN 45323
// end assignment
