/*******************************************************************************
 * Jumper, new implementation 20220422
 * Author: wk
 ******************************************************************************/
#macro CON_JUMPER()
  union {
     #local hoffset = 2.5;
     #local pt = 0.5;
     difference {
        Round_Box(<-2.54   ,0.0+hoffset   ,-2.2/2>
                  <+2.54   ,6.0+hoffset   ,+2.2/2> 0.3 0)
        Round_Box(<-2.54+pt,0.0+hoffset-pt,-2.2/2+pt>
                  <+2.54-pt,6.0+hoffset+pt,+2.2/2-pt> 0.3 0)
        Round_Box(<-2.54-pt,4.0+hoffset,-2.2/2+0.2>
                  <+2.54+pt,5.2+hoffset,-2.2/2-pt> 0.1 0)
        Round_Box(<-2.54-pt,4.0+hoffset,+2.2/2-0.2>
                  <+2.54+pt,5.2+hoffset,+2.2/2+pt> 0.1 0)
        Round_Box(<-2.54-pt ,4.0+hoffset,-2.2/2-pt>
                  <-2.54+0.2,5.2+hoffset,+2.2/2+pt> 0.1 0)
        Round_Box(<+2.54+pt ,4.0+hoffset,-2.2/2-pt>
                  <+2.54-0.2,5.2+hoffset,+2.2/2+pt> 0.1 0)
        cylinder {<0,4.0+hoffset,-3> <0,4.0+hoffset,+3> 1 }
        box      {<-1, 4.0+hoffset-1+1, -3>
                  <+1, 4.0+hoffset+1+1, +3> }
        pigment{MediumBlue * 0.5}
        }
     union {
        difference {
           box {<-2.3,+pt+hoffset+0.0,-1.8/2>
                <+2.3,-pt+hoffset+6.0,+1.8/2>}
           box {<-1.7, 0,-0.9/2>
                <+1.7,10,+0.9/2>}
           box      {<-1, 4.0+hoffset-2+1, -3>
                     <+1, 4.0+hoffset+0+1, +3> }
           }
        box {<-0.2,+pt+hoffset+0.5,-1/2> <+0.2,-pt+hoffset+2.5,+1/2> rotate<0,+20,0> translate<+0.7,0,0> }
        box {<-0.2,+pt+hoffset+0.5,-1/2> <+0.2,-pt+hoffset+2.5,+1/2> rotate<0,-20,0> translate<-0.7,0,0> }
        texture{col_silver}
        }
     }
#end
