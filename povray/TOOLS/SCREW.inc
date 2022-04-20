/*******************************************************************************
 * Macros for Screws :
 * Author: Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 - 04/01/06
 *
 * SCREWSIZE  : {2,2.5,3,4,5} for M2 M2.5 M3 M4 M5
 * LENGTH     : length
 * SCREWCOLOR : color
 * HEAD       : head style, as table
 *         0  = PAN
 *         1  = PHILIPS-ROUND-PAN
 *         10 = SLOTTED HEXA
 *         11 = FULL-BEARING
 *         20 = CHEESE
 *         21 = RAISED-CHEESE
 *         30 = RAISED-COUNTER-SUNK
 *         31 = PHILIPS-RAISED-COUNTER-SUNK
 *         32 = COUNTER-SUNK
 *         33 = PHILIPS-COUNTER-SUNK
 *         34 = COUNTER-SUNK-HEXA-SOCKET
 *
 * NOTE: zero is under head for #0 to #21 headed screws and on top for all
 *       counter sunk headed screws
 ******************************************************************************/
#macro TOOLS_SCREW (SCREWSIZE,LENGTH,HEAD,SCREWCOLOR)
  union {
     #switch (SCREWSIZE)
        #case(2)
           #local R = 1.6;  //4 0.8
           #local r = 0.4;
           #local ep = 1.3;
           #local r1 = 0.65;
           #local A = 3.6;
           #local delta = 1.12;
           #local B = 1.2;
           #local H = 1.5;
           #local T = 0.4;
           #local S = 1.3;
           #break
        #case(2.5)
           #local R = 2;
           #local r = 0.5; //5  0.8
           #local ep = 1.6;
           #local r1 = 0.8;
           #local A = 4.4;
           #local delta = 1.32;
           #local B = 1.5;
           #local H = 2;
           #local T = 0.45;
           #local S = 1.6;
           #break
        #case(3)
           #local R = 2.4;  // 6  0.8
           #local r = 0.6;
           #local ep = 2;
           #local r1 = 1;
           #local A = 5.3;
           #local delta = 1.52;
           #local B = 1.65;
           #local H = 2.5;
           #local T = 0.5;
           #local S = 1.94;
           #break
        #case(4)
           #local R = 3.2; //8 0.8
           #local r = 0.8;
           #local ep = 2.6;
           #local r1 = 1.3;
           #local A = 6.6;
           #local delta = 1.82;
           #local B = 2.2;
           #local H = 3;
           #local T = 0.7;
           #local S = 2.42;
           #break
        #case(5)
           #local R = 4; //10 0.8
           #local r = 1;
           #local ep = 3.3;
           #local r1 = 1.65;
           #local A = 8;
           #local delta = 2.05;
           #local B = 2.5;
           #local H = 4;
           #local T = 0.8;
           #local S = 2.92;
           #break
        #end

     #if (HEAD >= 0)
        difference {
           #switch (HEAD)
              #range(0,1)
                  // 0:PAN HEAD
                  // 1:PHILIPS ROUND-PAN
                  union {
                     torus {R+r-r1,r1 translate (ep-r1)*y}        // round edge
                     cylinder {<0,0,0>, <0,ep,0>, R+r-r1}       // base
                     cylinder {<0,0.1,0>, <0,ep-r1,0>, R+r}   // top
                     }
                  #if (HEAD=0)
                      // 0:PAN HEAD
                      box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                  #else
                      // 1:PHILIPS ROUND-PAN
                      box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep*y  } // Grove
                      box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep*y  rotate 90*y} // Grove
                  #end
                  #break

              #range(10,11)
                  // 10:SLOTTED HEXA
                  // 11:FULL-BEARING
                  intersection {
                     //3 boxes for Hexa nut
                     box {<-A/2,0,-2*SCREWSIZE>, <+A/2,+ep+0.1,+2*SCREWSIZE> }
                     box {<-A/2,0,-2*SCREWSIZE>, <+A/2,+ep+0.1,+2*SCREWSIZE> rotate -60*y}
                     box {<-A/2,0,-2*SCREWSIZE>, <+A/2,+ep+.01,+2*SCREWSIZE> rotate +60*y}
                     sphere {  <0, -delta, 0>  0.83*A }
                     }
                  union {
                     cylinder {<0,+ep,0>, <0,+ep+0.2,0> A/2+r } // to get spotless surface
                     #if (HEAD = 10) // 10: SLOTTED HEXA
                         box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  rotate -30*y } // Grove
                     #end
                     }
                  #break

              #case(20)
                 // 20:CHEESE
                 #local R=0.8*R;
                 cylinder {<0,0,0>, <0,ep,0>, R+r}       // base
                 box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                 #break

              #case(21)
                 // 21:RAISED CHEESE
                 #local R=0.8*R;
                 intersection {
                    sphere {<0,-R/2,0> 1.7*R}
                    cylinder {<0,0,0>, <0,2*ep,0>, R+r}       // base
                    }
                 box {<-r,ep*.4,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                 #break

              #range(30,31)
                 // 30:RAISED-COUNTER-SUNK
                 // 31:PHILIPS-RAISED-COUNTER-SUNK
                 union {
                    intersection {
                       sphere {<0,-A/2-S,0> A}
                       cylinder {<0,0,0>, <0,2*ep,0>, A*0.5}       // base
                       }
                    cone{0*y, A*0.5, -B*y,SCREWSIZE/2}
                    }
                 #if (HEAD = 30)
                     // 30:RAISED-COUNTER-SUNK
                     box {<-r,-ep*.4,-R-2*r>, <+r,A,R+2*r>  } // Grove
                 #else
                     // 31:PHILIPS-RAISED-COUNTER-SUNK
                     box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep/3*y  } // Grove
                     box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep/3*y  rotate 90*y} // Grove
                 #end
                 #break

              #range(32,34)
                 // 32: COUNTER-SUNK
                 // 33: PHILIPS-COUNTER-SUNK
                 // 34: COUNTER-SUNK-HEXA-SOCKET
                 cone {0*y, A*0.5, -B*y, SCREWSIZE/2.1 }
                 #switch (HEAD)
                     #case(32)
                         // 32: COUNTER-SUNK
                         box {<-r,-ep*.4,-R-2*r>, <+r,0.1,R+2*r>  } // Grove
                         #break
                     #case(33)
                         // 33: PHILIPS-COUNTER-SUNK
                         box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate 0*y  } // Grove
                         box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate 0*y  rotate 90*y} // Grove
                         #break
                     #case(34)
                         // 34: COUNTER-SUNK-HEXA-SOCKET
                         difference {
                            intersection {
                               box {<-H/2,0.1,-2*SCREWSIZE>, <+H/2,-ep,+2*SCREWSIZE> }
                               box {<-H/2,0.1,-2*SCREWSIZE>, <+H/2,-ep,+2*SCREWSIZE> rotate -60*y}
                               box {<-H/2,0.1,-2*SCREWSIZE>, <+H/2,-ep,+2*SCREWSIZE> rotate +60*y}
                               }
                            cylinder {<0,-ep*.6,0>, <0,-ep,0> A/2+r } // to get spotless surface
                            }
                         #break
                     // end switch HEAD
                     #end
                 #break

              #end
              rotate(rand(global_seed)*180)*y
           }

        //end: #if (HEAD >= 0)
        #end

  #if (HEAD < 30)
      // 0  = PAN
      // 1  = PHILIPS-ROUND-PAN
      // 10 = SLOTTED HEXA
      // 11 = FULL-BEARING
      // 20 = CHEESE
      // 21 = RAISED-CHEESE
      #local B1=0;
      #local N=2;
  #else
      // 30 = RAISED-COUNTER-SUNK
      // 31 = PHILIPS-RAISED-COUNTER-SUNK
      // 32 = COUNTER-SUNK
      // 33 = PHILIPS-COUNTER-SUNK
      // 34 = COUNTER-SUNK-HEXA-SOCKET
      #local B1=B;
      #local N=0;
  #end

  // body
  difference {
     union {
        cylinder { <0,-B1,0>, <0,-LENGTH+r,0>, SCREWSIZE/2 }
        cone { <0,-LENGTH+r,0>, SCREWSIZE/2, <0,-LENGTH,0>, SCREWSIZE/3 }
        }
     union {
        #while (N < (LENGTH/T+1))
            torus { SCREWSIZE/1.95, T/2.6 translate (-B1-N*T) * y}
            #local N = N + 1;
        #end
        }
     }

  pigment { SCREWCOLOR }
  }
#end
