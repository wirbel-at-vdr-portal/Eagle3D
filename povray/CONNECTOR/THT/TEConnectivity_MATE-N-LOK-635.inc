/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * TE connectivity, vertical MATE-N-LOK connector (0.25 inch = 6.35mm)
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0 31-12-05
 *
 * renamed & modified for use of GRID(), 15.06.2023, -wk
 ******************************************************************************/
#macro MATE_N_LOK_635(n,c)
  #switch(c)
     #case(1) #local col=Gray90;     #break
     #case(2) #local col=Gray10;     #break
     #case(3) #local col=Brown;      #break
     #case(4) #local col=Gray90;     #break
     #case(5) #local col=Orange;     #break
     #case(6) #local col=col_nylon;  #break
     #case(7) #local col=White*0.97; #break
  #end

  union {
     difference {
        merge {
           box {
              <-6.35*n/2-0.5,-3.8,0 >
              <+6.35*n/2+0.5,+3.8,14>
              }
           box {
              <-6.35*n/2    ,-1.5,6    >
              <-6.35*n/2-2.5,+1.5,13.99>
              }
           box {
              <6.35*n/2    ,-1.5,6    >
              <6.35*n/2+2.5,+1.5,13.99>
              }
           #local bloc = box {
              <-0.5,-3.8,0>
              <+0.5,-4.6,2>
              };
           GRID(bloc,6.35,n+1,1)
           }
        merge {
           #local CylindricalHole = cylinder {
              <0,0,1 >
              <0,0,15>
              3
              };
           GRID(CylindricalHole,6.35,n,1)
           #local HalfSquareHole = box {
              <+3, 0,1 >
              <-3,-3,15>
              };
           GRID(HalfSquareHole,(n-1)*6.35,2,1)
           box {
              <-6.35*n/2-1.5,-1.6,5  >
              <-6.35*n/2-3.5,+1.6,7.5>
              }
           box {
              <+6.35*n/2+1.5,-1.6,5  >
              <+6.35*n/2+3.5,+1.6,7.5>
              }
           box {
              <-2.5,-1.6,5 >
              <+2.5,+1.6,20>
              rotate -25*y
              translate +(6.35*n/2+9.8)*x
              }
           box {
              <-2.5,-1.6,5 >
              <+2.5,+1.6,20>
              rotate +25*y
              translate -(6.35*n/2+9.8)*x
              }
           }
        #if ((c = 1) | (c = 6))
           texture {
              pigment {
                 rgbf <1,1,1,0.3>
                 }
              normal {
                 agate 0.05
                 scale 0.1
                 }
              finish {
                 phong 0.8
                 phong_size 200
                 ambient (0.1 * global_ambient_mul)
                 }
              }
        #else
           pigment {
              col
              }
        #end
        }
     #local pin = difference {
        union {
           cylinder {
              <0,0,-2>
              <0,0,+4>
              0.85
              }
           cylinder {
              <0,0,4>
              <0,0,10.5>
              1.05
              }
           cone {
              <0,0,+10.5> 1.05
              <0,0,+12  > 0.3
              }
           cone {
              <0,0,-2> 0.85
              <0,0,-4> 0.5
              }
           }
        box {
           <+1,-0.1,7 >
           <-1,+0.1,14>
           rotate 80*z
           }
        pigment {
           P_Silver2
           }
        };
     GRID(pin,6.35,n,1)
     rotate <-90,180,0>
     }
#end

#macro CON_THT_MATE_N_LOK_350428_1() MATE_N_LOK_635(2,6)  #end
#macro CON_THT_MATE_N_LOK_350429_1() MATE_N_LOK_635(3,6)  #end
#macro CON_THT_MATE_N_LOK_350792_1() MATE_N_LOK_635(4,7)  #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-amp:350428-1=CON_THT_MATE_N_LOK_350428_1(:THT MATE-N-LOK connector
//con-amp:350429-1=CON_THT_MATE_N_LOK_350429_1(:THT MATE-N-LOK connector
//con-amp:350792-1=CON_THT_MATE_N_LOK_350792_1(:THT MATE-N-LOK connector
// end assignment
