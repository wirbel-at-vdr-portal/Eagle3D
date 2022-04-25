#include "PartTest.inc"



#declare pcb_rotate = <-25,0,0>;


#macro TEST_OBJ()
union {
  object { PCB() }


union {
#local obj = object {CON_MOLEX_PSL5G() };
#local sc  = 1;

object {obj scale sc rotate<0,  45,0> translate<  5,0,60>}
object {obj scale sc rotate<0,   0,0> translate< 25,0,60>}
object {obj scale sc rotate<0, -45,0> translate< 45,0,60>}
object {obj scale sc rotate<0, 135,0> translate< 65,0,60>}
object {obj scale sc rotate<0, 180,0> translate< 85,0,60>}
object {obj scale sc rotate<0,-135,0> translate<105,0,60>}


object {obj scale sc rotate<180,  45,0> translate<  5,2,40>}
object {obj scale sc rotate<180,   0,0> translate< 25,2,40>}
object {obj scale sc rotate<180, -45,0> translate< 45,2,40>}
object {obj scale sc rotate<180, 135,0> translate< 65,2,40>}
object {obj scale sc rotate<180, 180,0> translate< 85,2,40>}
object {obj scale sc rotate<180,-135,0> translate<105,2,40>}


object {obj scale sc rotate<90,   0,180> translate<  5,0,0>}
object {obj scale sc rotate<90,   0,  0> translate< 25,0,0>}
object {obj scale sc rotate<90,   0, 90> translate< 45,0,0>}
object {obj scale sc rotate<90,   0,-90> translate< 65,0,0>}
object {obj scale sc rotate<90, 180,  0> translate< 85,0,0>}
//object {obj scale sc rotate<90,-135,0> translate<105,0,0>}
}}

#end

object { TEST_OBJ()
  translate<-50.800000,0,-26.670000>
  rotate pcb_rotate
  }
