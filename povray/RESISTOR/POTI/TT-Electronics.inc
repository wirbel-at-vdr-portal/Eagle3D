




#macro TRIM_25x_BASE(value, Type)

  #local X = 6.86;
  #local Y = 6.86;
  #local Z = 4.83;












  union {
     difference {
        // body
        box {
           <-X/2,0,-Y/2>
           <+X/2,Z,+Y/2>
           }
        box {
           <-X/2-0.01,Z-0.51,-Y/2-0.5>
           <+X/2+0.01,Z+0.01,-Y/2-0.1>
           }

        box {
           <-(X-1)/2,-0.01,-(Y+0.1)/2>
           <+(X-1)/2,+0.25,+(Y+0.1)/2>
           }
        box {
           <-(X+1)/2,-0.01,-(Y-0.1)/2>
           <+(X+1)/2,+0.251,+(Y-0.1)/2>
           }





        pigment {
           NavyBlue
           }
        rotate<0,0,0>
        }
     }
#end


#macro RES_DIS_TRIM_B25X(value)
  TRIM_25x_BASE(value, "25X")
#end















/*******************************************************************************
 * Rf = 1.27 oder 0 (Dreieck oder Linie); D_schraube = Abstand der Schraube aus
 * der Mitte
 * *****************************************************************************
#macro RES_DIS_TRIM_W_BASE(X,Y,Z,col,D_schraube,Rf )
  #macro RES_DIS_TRIM_KOERPER(X,Y,Z,col)
     difference {
        // body
        Round_Box(
        <-X/2,0,-Y/2>
        <+X/2,Z,+Y/2>
        0.2 0
        )
        box {
           <-(X-1)/2,-0.01,-(Y+0.1)/2>
           <+(X-1)/2,+0.25,+(Y+0.1)/2>
           }
        pigment {
           col
           }
        rotate<0,0,0>
        }
  #end


  union {
     object {
        RES_DIS_TRIM_KOERPER(X,Y,Z,col)
        }
     //Anschlussbeine zuordnen
     union {
        cylinder {
           <-2.54,1,Rf-0.635> <-2.54,-3,Rf-0.635> 0.25
           }
        cylinder {
           <2.54,1,Rf-0.635> <2.54,-3,Rf-0.635> 0.25
           }
        cylinder {
           <0,1,1.27-0.635> <0,-3,1.27-0.635> 0.25
           }
        texture {
           col_silver
           }
        }
     difference {
        cylinder {
           <0,0,0> <0, 1.1> 1.015
           }
        box {
           <1.5,0.7,0.2> <-1.5,2.5,-0.2>
           }
        texture {
           col_silver
           }
        rotate<0,75,0>
        rotate<90,0,0>
        translate <D_schraube,Z-1.3,Y/2>
        }
     text {
        ttf besch_font  value     0.1,0
        scale<1.4,1.4,1.4> pigment {
           Black
           }
        rotate<-270,180,0> translate<X/2-1.0,  Z+0.1, Y/2-3.0>
        }
     text {
        ttf besch_font "3  2  1"  0.1,0
        scale<1.5,1.5,1.5> pigment {
           Black
           }
        rotate<0   ,180,0> translate<X/2-1.75, 0.52, Y/2+0.1>
        }
     }
#end

// waagerecht
#macro RES_DIS_TRIM_B25X(value)
  RES_DIS_TRIM_W_BASE(7,6.6,4.83,NavyBlue,0,-1.27)
#end

#macro RES_DIS_TRIM_B25V(value)
  RES_DIS_TRIM_W_BASE(7,6.6,4.83,NavyBlue,0,1.27)
#end
*/















