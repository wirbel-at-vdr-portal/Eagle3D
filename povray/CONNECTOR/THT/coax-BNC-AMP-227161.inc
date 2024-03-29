/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * BNC Buchse liegend isoliert weiss
 * wk
 ******************************************************************************/
#macro CON_THT_AMP_227161()
  union {
     union { // Korpus
        difference {
           box {
              <0,0,0> <14.5,12.5,14>
              pigment {
                 Gray70
                 }
              clipped_by {
                 plane { <1,0,0>,0 rotate<0,0,45> translate<0,25,0> }
                 plane { <-1,0,0>,0 rotate<0,0,-45>translate<0,10.5,0>}
                 }
              }
           cylinder { // Mittlerer Ausschnitt fuer Anschlusspins
              <0,0,0>, <0,2,0>, 4
              open
              rotate <90,0,0>
              translate <7.5,6.25,0>
              pigment {
                 Gray50
                 }
              }
           box { // unterer Aussschnitt fuer Anschlusspins
              <0,0,-1> <8,7,20>
              translate <3.5,-0.51,-6.5>
              pigment {
                 Gray70
                 }
              }
           }
        // freigeschnittene Aussenbereiche der Box fuellen
        cylinder {
           <14.5-2,12.5-2,0> <14.5-2,12.5-2,14>, 2
           translate <0,0,0>
           pigment {
              Gray70
              }
           }
        cylinder {
           <0   +2,12.5-2,0> <   0+2,12.5-2,14>, 2
           translate <0,0,0>
           pigment {
              Gray70
              }
           }
        disc {
           <0,0,0>, <0,0,-1>, 3
           translate <7.5,6.25,2>
           texture {
              T_Silver_1A
              }
           }

        cylinder {
           <0,0,0>, <0,2,0>, 1.6
           rotate <90,0,0>
           translate <7.5,6.25,1.8>
           pigment {
              Gray70
              }
           }
        } // Ende Korpus
     object { // Massepin
        TOOLS_RECT_BOGEN(1,90,0.8,0.8,8,1)
        rotate <90,0,-90>
        translate <4.75,6.5,2>
        texture {
           col_silver
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     object { // Signalpin
        TOOLS_RECT_BOGEN(1,90,0.8,0.8,8,1)
        rotate <90,0,-90>
        translate <4.75+2.54,6.5,2>
        texture {
           col_gold
           }
        }
     union { // Haltebolzen 1
        cylinder {
           <0,1,0><0,-4,0>,1
           translate<2.75,0,4.45>
           }
        sphere {
           <0,0,0>, 1
           translate <2.75,-3.9,4.45>
           }
        texture {
           T_Silver_1A
           finish {
              phong 1.0
              ambient (0.1 * global_ambient_mul)
              }
           }
           translate <-0.6,2.5,2.5>
        }
     union { // Haltebolzen 2
        cylinder {
           <0,1,0><0,-4,0>,1
           translate <2.75+10.2,0,4.45>
           }
        sphere {
           <0,0,0>,1
           translate <2.75+10.2,-3.9,4.45>
           }
        texture {
           T_Silver_1A
           finish {
              phong 1.0
              ambient (0.1 * global_ambient_mul)
              }
           }
           translate <-0.6,2.5,2.5>
        }
     difference {
        union {
           cylinder { // Verschraubung
              <0,0,0>,<0,0,9>,5.5
              translate <7.25,6.25,14>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,16>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,17>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,18>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,19>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,20>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,21>
              }
           cylinder { // 'Schraubenlinien'
              <0,0,0>,<0,0,0.2>,5.7
              translate <7.25,6.25,22>
              }
           pigment{Gray70}
           } // end inner union
        box {
          <0,0,0>,<16,3.3,9>
          translate <2.25,11.5,14>
          pigment {
             Gray70
             }
          }
        } // end difference
     cylinder { // aeusserer Anschluss
        <0,0,0>,<0,0,12>,4.7
        open
        translate <7.25,6.25,5.5+14>
        texture {
           T_Silver_1A
           finish {
              phong 1
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     difference {
        cylinder { // innerer Anschluss A
           <0,0,-8>,<0,0,1>,2.5
           translate <7.25,6.25,29>
           pigment { Gray70 }
           }
        cylinder { // innerer Anschluss B
           <0,0,0>,<0,0,1>,1
           translate <7.25,6.25,29.1>
           texture { col_gold }
           }
        cylinder { // innerer Anschluss C
           <0,0,0>,<0,0,1>,0.5
           translate <7.25,6.25,29>
           pigment { Black }
           }
        }
        cylinder { // Einrastpunkt 1
           <0,0,0>,<0,0,1>,1
           rotate <90,0,0>
           translate <7.25,12,29>
           texture {
              col_silver
              finish {
                 phong 1
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           }
        cylinder { // Einrastpunkt 2
           <0,0,0>,<0,0,1>,1
           rotate <90,0,0>
           translate <7.25,1.5,29>
           texture {
              col_silver
              finish {
                 phong 1
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           }
        translate <-7.25,0,-7>
     }

#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-coax:AMP_227161=CON_THT_AMP_227161(:BNC right angle jack
// end assignment
