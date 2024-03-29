/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Kuehlkoerper SK96/84
 * *****************************************************************************/
#macro SPC_HEATSINK_SK96_BASE(l)
  union {
     #local black_al =
        texture {
           pigment {
              Black
              }
           finish {
              specular .7
              roughness .03
              reflection .05
              ambient (0.2 * global_ambient_mul)
              diffuse .5
              brilliance 4
              }
           }

     difference {
        union {
           prism {
              0,l,9 <0,0>, <8,0>, <8,12.5>, <9.5,12.5>, <9.5,14>, <54,14>, <54,27>, <0,27>, <0,0>
              }
           // Grundkoerper
           cylinder {
              <54,0,15> <54,l,15>1
              }
           // gerundete Ecken
           cylinder {
              <54,0,19> <54,l,19>1
              }
           cylinder {
              <54,0,23> <54,l,23>1
              }
           cylinder {
              <54,0,27> <54,l,27>1
              }
           // Rundung der Kuehlrippen
           cylinder {
              <1,0,27> <1,l,27>1
              }
           cylinder {
              <6,0,27> <6,l,27>1
              }
           cylinder {
              <11,0,27> <11,l,27>1
              }
           cylinder {
              <16,0,27> <16,l,27>1
              }
           cylinder {
              <21,0,27> <21,l,27>1
              }
           cylinder {
              <26,0,27> <26,l,27>1
              }
           cylinder {
              <31,0,27> <31,l,27>1
              }
           cylinder {
              <36,0,27> <36,l,27>1
              }
           cylinder {
              <41,0,27> <41,l,27>1
              }
           cylinder {
              <46,0,27> <46,l,27>1
              }
           // Flaeche ueber den horiz. Kuehlrippen
           box {
              <46,0,28> <54,l,26.9>
              }
           }
        union {
           cylinder {
              <9.5,0-0.01,12.5> <9.5,l+0.01,12.5> 1.5
              }
           // Innenecke unterhalb
           box {
              <2,-0.1,25> <5,l+0.1,28.1>
              }
           // Erste 2 senkrechte Kuehlrippen
           cylinder {
              <3.5,-0.1,25> <3.5,l+0.1,25> 1.5
              }
           box {
              <7,-0.1,25> <10,l+0.1,28.1>
              }
           cylinder {
              <8.5,-0.1,25> <8.5,l+0.1,25> 1.5
              }
           box {
              <12,-0.1,19> <15,l+0.1,28.1>
              }
           // Die restlichen senkrechten Kuehlrippen
           cylinder {
              <13.5,-0.1,19> <13.5,l+0.1,19> 1.5
              }
           box {
              <17,-0.1,19> <20,l+0.1,28.1>
              }
           cylinder {
              <18.5,-0.1,19> <18.5,l+0.1,19> 1.5
              }
           box {
              <22,-0.1,19> <25,l+0.1,28.1>
              }
           cylinder {
              <23.5,-0.1,19> <23.5,l+0.1,19> 1.5
              }
           box {
              <27,-0.1,19> <30,l+0.1,28.1>
              }
           cylinder {
              <28.5,-0.1,19> <28.5,l+0.1,19> 1.5
              }
           box {
              <32,-0.1,19> <35,l+0.1,28.1>
              }
           cylinder {
              <33.5,-0.1,19> <33.5,l+0.1,19> 1.5
              }
           box {
              <37,-0.1,19> <40,l+0.1,28.1>
              }
           cylinder {
              <38.5,-0.1,19> <38.5,l+0.1,19> 1.5
              }
           box {
              <42,-0.1,19> <45,l+0.1,28.1>
              }
           cylinder {
              <43.5,-0.1,19> <43.5,l+0.1,19> 1.5
              }
           box {
              <55.1,-0.1,16> <50,l+0.1,18>
              }
           // Die horizontalen Kuehlrippen
           cylinder {
              <50,-0.1,17> <50,l+0.1,17>1
              }
           box {
              <55.1,-0.1,20> <50,l+0.1,22>
              }
           cylinder {
              <50,-0.1,21> <50,l+0.1,21>1
              }
           box {
              <55.1,-0.1,24> <50,l+0.1,26>
              }
           cylinder {
              <50,-0.1,25> <50,l+0.1,25>1
              }
           box {
              <-0.1,-0.1,17> <6.5,l+0.1,19>
              }
           // Die Montageloecher
           box {
              <3,-0.1,-0.1> <5,l+0.1,8>
              }
           }
        rotate<-90,-90,0>
        translate<-l/2,0,0>
        }
     texture {
        black_al
        }
     }
#end

#macro SPC_HEATSINK_SK96_84()
  SPC_HEATSINK_SK96_BASE(84)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//heatsink:SK96/84=SPC_HEATSINK_SK96_84(:Extruded Heatsink Fischer-Elektronik SK96/84
// end assignment
