
#macro CON_THT_AMP_112536()
  union {
     union {
        difference {
           union {
              cylinder { // aeusserer Anschluss
                 <0,0,-3>,<0,0,12>,4.7
                 open
                 }
              difference {
                 cylinder {
                    <0,0,10.5>,<0,0,12>,4.7
                    }
                 cylinder {
                    <0,0,8>,<0,0,12.1>,4.4
                    }
                 }
              translate <7.25,6.25,5.5+14>
              }
           torus {
              6.0 2
              rotate <90,0,0>
              translate <7.25,6.25,5.0+22.5>
              }
           cylinder {
              <0,-1,0> <0,+1,0>
              2
              translate <7.25,11.00,5.0+22.5>
              }
           cylinder {
              <0,-1,0> <0,+1,0>
              2
              translate <7.25,1.45,5.0+22.5>
              }
           }
        difference {
           cylinder { // innerer Anschluss A
              <0,0,-5>,<0,0,1>,2.5
              translate <7.25,6.25,29>
              pigment { White * 0.75 }//Gray70 }
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
           <0,0,0>,<0,0,1.5>,1
           rotate <90,0,0>
           translate <7.25,11.5,5.0+22.5>
           texture {
              col_silver
              finish {
                 phong 1
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           }
        cylinder { // Einrastpunkt 2
           <0,0,0.5>,<0,0,2>,1
           rotate <90,0,0>
           translate <7.25,3,5.0+22.5>
           texture {
              col_silver
              finish {
                 phong 1
                 ambient (0.1 * global_ambient_mul)
                 }
              }
           }
        translate <-6,0,-20>
        rotate <-90,0,0>
        translate <-1.3,4.4,6.2>     
        }




     intersection {
        Round_Box (
           <-17.5/2,-4,-17.5/2>
           <+17.5/2,+8,+17.5/2>
           2/2 0
           )
        box {
           <-18.5/2,    0,-18.5/2>
           <+18.5/2,+2.36,+18.5/2>
           }
        }
     cylinder {
        <0, 0,0>
        <0,-3,0>
        0.94/2
        texture {
           col_gold
           }
        }
     GRID (
        cylinder {
           <0, 0,0>
           <0,-3,0>
           0.94/2
           texture {
              col_gold
              }
           },
        12.7,2,2
        )
     texture {
        T_Silver_1A
        finish {
           phong 1
           ambient (0.1 * global_ambient_mul)
           }
        }
     }
#end
