/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * MOLEX 53261 series SMT connector
 * CircuitSize: Number of Pins
 * Color      : "beige" or "black"
 ******************************************************************************/
#macro MOLEX_53261(CircuitSize, Color)
  union {
     #switch(CircuitSize)
        #case( 2)   #local E= 3.05; #local D= 4.25; #local C= 7.25; #local B= 1.25; #local A= 7.65; #break /* black: ---      , natural beige:532610271, circuit size: 2  */
        #case( 3)   #local E= 4.30; #local D= 5.50; #local C= 8.50; #local B= 2.50; #local A= 8.90; #break /* black: 532610327, natural beige:532610371, circuit size: 3  */
        #case( 4)   #local E= 5.55; #local D= 6.75; #local C= 9.75; #local B= 3.75; #local A=10.15; #break /* black: 532610427, natural beige:532610471, circuit size: 4  */
        #case( 5)   #local E= 6.80; #local D= 8.00; #local C=11.00; #local B= 5.00; #local A=11.40; #break /* black: 532610527, natural beige:532610571, circuit size: 5  */
        #case( 6)   #local E= 8.05; #local D= 9.25; #local C=12.25; #local B= 6.25; #local A=12.65; #break /* black: 532610627, natural beige:532610671, circuit size: 6  */
        #case( 7)   #local E= 9.30; #local D=10.50; #local C=13.50; #local B= 7.50; #local A=13.90; #break /* black: 532610727, natural beige:532610771, circuit size: 7  */
        #case( 8)   #local E=10.55; #local D=11.75; #local C=14.75; #local B= 8.75; #local A=15.15; #break /* black: 532610827, natural beige:532610871, circuit size: 8  */
        #case( 9)   #local E=11.80; #local D=13.00; #local C=16.00; #local B=10.00; #local A=16.40; #break /* black: 532610927, natural beige:532610971, circuit size: 9  */
        #case(10)   #local E=13.05; #local D=14.25; #local C=17.25; #local B=11.25; #local A=17.65; #break /* black: ---      , natural beige:532611071, circuit size: 10 */
        #case(11)   #local E=14.30; #local D=15.50; #local C=18.50; #local B=12.50; #local A=18.90; #break /* black: ---      , natural beige:532611171, circuit size: 11 */
        #case(12)   #local E=15.55; #local D=16.75; #local C=19.75; #local B=13.75; #local A=20.15; #break /* black: 532611227, natural beige:532611271, circuit size: 12 */
        #case(13)   #local E=16.80; #local D=18.00; #local C=21.00; #local B=15.00; #local A=21.40; #break /* black: ---      , natural beige:532611371, circuit size: 13 */
        #case(14)   #local E=18.05; #local D=19.25; #local C=22.25; #local B=16.25; #local A=22.65; #break /* black: 532611427, natural beige:532611471, circuit size: 14 */
        #case(15)   #local E=19.30; #local D=20.50; #local C=23.50; #local B=17.50; #local A=23.90; #break /* black: ---      , natural beige:532611571, circuit size: 15 */
        #case(17)   #local E=21.80; #local D=23.00; #local C=26.00; #local B=20.00; #local A=26.40; #break /* black: ---      , natural beige:532611771, circuit size: 17 */
        #end
     #local PCB_offset = 1.375;

     union {
        #local BackPin =
           union {
              IC_SMD_PIN(1.375,1.0,0.32,0.32)
              IC_SMD_PIN(1.15,0.5,0.32,0.16)
              box {
                 <-0.5,1.375,-0.32/2>
                 <0.00,0.975,+0.32/2>
                 }
              difference {
                 box {
                    <-3.45,0.6+0.725-0.75/2,-0.32/2>
                    <-0.30,0.6+0.725+0.75/2,+0.32/2>
                    }
                 #local cut = box { <-0.5,-0.5,-0.5> <0.5,0.5,0.5> };
                 object { cut rotate <0,+10,0> translate <-3.5,1.2,-0.56> }
                 object { cut rotate <0,-10,0> translate <-3.5,1.2,+0.56> }
                 object { cut rotate <0,0,+10> translate <-3.5,2.1,    0> }
                 object { cut rotate <0,0,-10> translate <-3.5,0.5,    0> }
                 }
              rotate <0,90,0>
              };
        GRID(BackPin,1.25,CircuitSize,1)
        #local SidePin =
           intersection {
              BENT_PLANE_OUTER(1.48,1,2.2,0.25,0.25,90)
              box {
                 <-2,-0.1,-2>
                 <+2,+1.0,+2>
                 rotate <0,45,0>
                 translate <-0.5,0,0>
                 }
              };
        object {
           SidePin
           translate <+C/2-1.48,0,2.1>
           }
        object {
           SidePin
           rotate <0,180,0>
           translate <-C/2+1.48,0,2.1>
           }
        texture {
           col_tin
           }
        }
     union {
        difference {
           Round_Box (
              <-D/2,0.2,  0>
              <+D/2,3.4,4.2>
              0.1 0
              )
           box {
              <-E/2,0.6,1.0>
              <+E/2,3.0,4.3>
              }
           GRID (
              box {
                 <-0.55/2,2.9,-0.1>
                 <+0.55/2,3.5,+0.5>
                 },
              1.25,CircuitSize+2,1
              )
           object {
              Pyramid2
              rotate <-90,0,0>
              scale <D,3.2,1>*0.5
              translate <0,(3.0+0.6)/2,3.95>
              }
           box {
              <-D/2-0.1,2.95,3.2>
              <+D/2+0.1,3.50,4.3>
              }
           box {
              <-E/2+0.5,2.95,2.7>
              <+E/2-0.5,3.50,4.3>
              }
           #if (CircuitSize < 4)
              #local nLockings = 1;
           #else
              #local nLockings = 2;
           #end
           GRID (
              box {
                 <-0.5/2,0,2.5>
                 <+0.5/2,2,4.3>
                 },
              (CircuitSize-2)*1.25,nLockings,1
              )
           }
        #local support =
            prism {
               linear_spline
               -1.4 1.4
               8
               <0.00,0.32>
               <1.00,0.32>
               <1.50,0.75>
               <1.50,2.00>
               <1.30,2.20>
               <0.50,2.20>
               <0.00,2.70>
               <0.00,0.32>
               //scale 2
               translate <0,0,0>
               rotate <-90,0,0>
               };
         object {
            support
            translate <D/2,0,2.4> 
            }
         object {
            support
            rotate <0,180,0>
            translate <-D/2,0,2.4> 
            }
        #if (Color = "beige")
           texture { col_nylon }
        #end
        #if (Color = "black")
           texture { col_nylon }
        #end
        }
     translate <0,0,-PCB_offset>
     }
#end

// beige, any size
#macro CON_SMT_MOLEX_532610271() MOLEX_53261(2 , "beige") #end
#macro CON_SMT_MOLEX_532610371() MOLEX_53261(3 , "beige") #end
#macro CON_SMT_MOLEX_532610471() MOLEX_53261(4 , "beige") #end
#macro CON_SMT_MOLEX_532610571() MOLEX_53261(5 , "beige") #end
#macro CON_SMT_MOLEX_532610671() MOLEX_53261(6 , "beige") #end
#macro CON_SMT_MOLEX_532610771() MOLEX_53261(7 , "beige") #end
#macro CON_SMT_MOLEX_532610871() MOLEX_53261(8 , "beige") #end
#macro CON_SMT_MOLEX_532610971() MOLEX_53261(9 , "beige") #end
#macro CON_SMT_MOLEX_532611071() MOLEX_53261(10, "beige") #end
#macro CON_SMT_MOLEX_532611171() MOLEX_53261(11, "beige") #end
#macro CON_SMT_MOLEX_532611271() MOLEX_53261(12, "beige") #end
#macro CON_SMT_MOLEX_532611371() MOLEX_53261(13, "beige") #end
#macro CON_SMT_MOLEX_532611471() MOLEX_53261(14, "beige") #end
#macro CON_SMT_MOLEX_532611571() MOLEX_53261(15, "beige") #end
#macro CON_SMT_MOLEX_532611771() MOLEX_53261(17, "beige") #end

// black only avail in certain circuit sizes
#macro CON_SMT_MOLEX_532610327() MOLEX_53261(3 , "black") #end
#macro CON_SMT_MOLEX_532610427() MOLEX_53261(4 , "black") #end
#macro CON_SMT_MOLEX_532610527() MOLEX_53261(5 , "black") #end
#macro CON_SMT_MOLEX_532610627() MOLEX_53261(6 , "black") #end
#macro CON_SMT_MOLEX_532610727() MOLEX_53261(7 , "black") #end
#macro CON_SMT_MOLEX_532610827() MOLEX_53261(8 , "black") #end
#macro CON_SMT_MOLEX_532610927() MOLEX_53261(9 , "black") #end
#macro CON_SMT_MOLEX_532611227() MOLEX_53261(12, "black") #end
#macro CON_SMT_MOLEX_532611427() MOLEX_53261(14, "black") #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-lex:53261-02=CON_SMT_MOLEX_532610271(:Molex 53261 SMT connector
//con-lex:53261-03=CON_SMT_MOLEX_532610371(:Molex 53261 SMT connector
//con-lex:53261-04=CON_SMT_MOLEX_532610471(:Molex 53261 SMT connector
//con-lex:53261-05=CON_SMT_MOLEX_532610571(:Molex 53261 SMT connector
//con-lex:53261-06=CON_SMT_MOLEX_532610671(:Molex 53261 SMT connector
//con-lex:53261-07=CON_SMT_MOLEX_532610771(:Molex 53261 SMT connector
//con-lex:53261-08=CON_SMT_MOLEX_532610871(:Molex 53261 SMT connector
//con-lex:53261-09=CON_SMT_MOLEX_532610971(:Molex 53261 SMT connector
//con-lex:53261-10=CON_SMT_MOLEX_532611071(:Molex 53261 SMT connector
//con-lex:53261-11=CON_SMT_MOLEX_532611171(:Molex 53261 SMT connector
//con-lex:53261-12=CON_SMT_MOLEX_532611271(:Molex 53261 SMT connector
//con-lex:53261-13=CON_SMT_MOLEX_532611371(:Molex 53261 SMT connector
//con-lex:53261-14=CON_SMT_MOLEX_532611471(:Molex 53261 SMT connector
//con-lex:53261-15=CON_SMT_MOLEX_532611571(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532611771(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610327(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610427(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610527(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610627(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610727(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610827(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532610927(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532611227(:Molex 53261 SMT connector
//=CON_SMT_MOLEX_532611427(:Molex 53261 SMT connector
// end assignment
