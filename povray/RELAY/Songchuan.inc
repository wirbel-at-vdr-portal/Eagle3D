/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Songchuan G90 type 30A relay
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 du 05/01/06
 * Form: 0=A 1=B 2=C
 * *****************************************************************************/
#macro SPC_RELAY_PB_G90_BASE(Value,Form,Com)
  union {
     #local H=20.4;
     difference {
        union {
           superellipsoid {
              <0.08, 0.08>
              scale <16.1,H/2+2,10>  translate <0.9, H/2-2, 0>
              }
           superellipsoid {
              <0.08, 0.08>
              scale <8.8,H/2+2,10>  translate <-6.4, H/2-2, -3.7>
              }
           superellipsoid {
              <0.08, 0.08>
              scale <6.4,H/2+2,10>  translate <-8.8, H/2-2, +3.7>
              }
           }
        union {
           box {
              <50,-5,50> <-50,0.4,-50>
              }
           cylinder {
              <0,H-0.6,0> <0,H+0.1,0> 1.5
              }
           }
        pigment {
           Gray30
           }
        }
     cylinder {
        <0,H-0.6,0> <0,H-0.3,0> 0.6
        pigment {
           Gray30
           }
        }
     cylinder { //pin1
        <+10.16,+1,+5.08> <+10.16,-3.6,+5.08> .5
        pigment {
           Silver
           }
        }
     cylinder { //pin2
        <+10.16,+1,-5.08> <+10.16,-3.6,-5.08> .5
        pigment {
           Silver
           }
        }
     cylinder { //pin4
        <-2.54,+1,-8.9> <-2.54,-2.8,-8.9> .9
        pigment {
           Silver
           }
        }
     cone {
        <-2.54,-2.8,-8.9>, 0.9, <-2.54,-3.3,-8.9>, 0.6
        pigment {
           Silver
           }
        }

     #if (Form!=1)
        cylinder { //pin5
           <-5.08,+1,+8.9> <-5.08,-2.8,+8.9> 0.9
           pigment {
              Silver
              }
           }
        cone {
           <-5.08,-2.8,+8.9>, 0.9, <-5.08,-3.3,+8.9>, 0.5
           pigment {
              Silver
              }
           }
     #end

     #if (Form!=0)
        cylinder { //pin3
           <-12.7,+1,+8.9> <-12.7,-2.8,+8.9> 0.9
           pigment {
              Silver
              }
           }
        cone {
           <-12.7,-2.8,+8.9>, 0.9, <-12.7,-3.3,+8.9>, 0.5
           pigment {
              Silver
              }
           }
     #end

     #if (Com=2)
        cylinder { //pin6
           <+12.7,+1,0> <+12.7,-2.8,0> 0.9
           pigment {
              Silver
              }
           }
        cone {
           <+12.7,-2.8,0>, 0.9, <+12.7,-3.3,0>, 0.5
           pigment {
              Silver
              }
           }
     #end

     text {
        ttf global_fontfile_eagle3d "." 0.05, 0
        pigment {
           White
           }
        scale 3.5 rotate<90,-90,0> translate<-11,H+0.05,-5>
        }
     text {
        ttf global_fontfile_arial Value 0.05, 0
        pigment {
           White
           }
        scale 2.2 rotate<90,-90,0> translate<-8.5,H+0.05,-7>
        }
     text {
        ttf global_fontfile_arial "COIL-12VDC" 0.05, 0
        pigment {
           White
           }
        scale 2.2 rotate<90,-90,0> translate<-6,H+0.05,-7>
        }
     text {
        ttf global_fontfile_eagle3d "A" 0.05, 0
        pigment {
           White
           }
        scale 3 rotate<90,-90,0> translate<-2,H+0.05,-7>
        }
     text {
        ttf global_fontfile_eagle3d "G" 0.05, 0
        pigment {
           White
           }
        scale 3 rotate<90,-90,0> translate<-2,H+0.05,+0>
        }
     text {
        ttf global_fontfile_arial "20A 250VAC 30VDC" 0.05, 0
        pigment {
           White
           }
        scale <1.5,2,2> rotate<90,-90,0> translate<+5,H+0.05,-7>
        }
     text {
        ttf global_fontfile_arial "2HP 250VAC" 0.05, 0
        pigment {
           White
           }
        scale <1.5,2,2> rotate<90,-90,0> translate<+7,H+0.05,-7>
        }
     text {
        ttf global_fontfile_arial "1HP 125VAC" 0.05, 0
        pigment {
           White
           }
        scale <1.5,2,2> rotate<90,-90,0> translate<+9,H+0.05,-7>
        }
     }
#end

// Form A, 1 common terminal
#macro SPC_RELAY_G90_1A_1(value)
  SPC_RELAY_PB_G90_BASE(value,0,1)
#end

// Form B, 1 common terminal
#macro SPC_RELAY_G90_1B_1(value)
  SPC_RELAY_PB_G90_BASE(value,1,1)
#end

// Form C, 1 common terminal
#macro SPC_RELAY_G90_1C_1(value)
  SPC_RELAY_PB_G90_BASE(value,2,1)
#end

// Form A, 2 common terminals
#macro SPC_RELAY_G90_1A_2(value)
  SPC_RELAY_PB_G90_BASE(value,0,2)
#end

// Form B, 2 common terminals
#macro SPC_RELAY_G90_1B_2(value)
  SPC_RELAY_PB_G90_BASE(value,1,2)
#end

// Form C, 2 common terminals
#macro SPC_RELAY_G90_1C_2(value)
  SPC_RELAY_PB_G90_BASE(value,2,2)
#end




/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_RELAY_G90_1A_1(:Songchuan  Relay
//=SPC_RELAY_G90_1B_1(:Songchuan  Relay
//=SPC_RELAY_G90_1C_1(:Songchuan  Relay
//=SPC_RELAY_G90_1A_2(:Songchuan  Relay
//=SPC_RELAY_G90_1B_2(:Songchuan  Relay
//=SPC_RELAY_G90_1C_2(:Songchuan  Relay
// end assignment
