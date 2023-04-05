/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Murata TZ03 type F capacitor trimmer
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0 du 23/12/05
 ******************************************************************************/
#macro TRIM_TZ03F_BASE(col,dot)
  union {
     difference {
        union { 
           difference {          
              union {
                 torus { 2.5, 0.5 translate 4.3*y }  //top round
                 cylinder { <0,0,0> <0,4.3,0> 3 }    //main case   
                 cylinder { <0,0,0> <0,4.8,0> 2.5 }  //top cover 
                 } 
              union {    
                 box { <0,-0.2,-3.2> <+3.2,5.0,3.2> } //delete back side (flat side)
                }
              } 
           cylinder { <2.5,0,+1.75> <2.5,4.3,+1.75> 0.5 }       //back bottom to top edges
           cylinder { <2.5,0,-1.75> <2.5,4.3,-1.75> 0.5 }
           sphere { <2.5,4.3,-1.75>, 0.5}                       //back top corners
           sphere { <2.5,4.3,+1.75>, 0.5}           
           cylinder { <2.5,4.3,+1.75> <2.5,4.3,-1.75> 0.5}      //back top corner to corner edge
           box { <-1.3,0,-0.25> <+1.3,4.3,+0.25> rotate -16.7*y translate<1.3,0,-2.3709>}     //flanks
           box { <-1.3,0,-0.25> <+1.3,4.3,+0.25> rotate +16.7*y translate<1.3,0,+2.3709>}     //flanks
           prism {0 4.8 4 <0, 2.5>, <2.5, 1.75>, <2.5, -1.75>, <0,-2.5>}  //top cover             
           box { <0,0,+1.75> <3,4.3,-1.75>}               //back
           cylinder { <-1.35,4.3,0> <+1.3,4.3,0> 0.5 rotate -16.7*y translate<1.3,0,-2.11>}   //back top corner to main case edges
           cylinder { <-1.35,4.3,0> <+1.3,4.3,0> 0.5 rotate +16.7*y translate<1.3,0,+2.11>}
           cylinder { <0,0,+2.5> <0,4.3,+2.5> 0.5}        //back bottom to top edges
           cylinder { <0,0,-2.5> <0,4.3,-2.5> 0.5}
           sphere { <0,4.3,-2.5>, 0.5}                  //main case junctions
           sphere { <0,4.3,+2.5>, 0.5}
           }
        union {
           cylinder { <0,4,0> <0,5,0> 1.25}                           //central hole
           box { <+0.1,-1,-0.55> <-0.1,6,+0.55> translate -2.9*x }    //front pin groove on round side
           box { <+0.1,-1,-0.6> <-0.1,1.1,0.6> translate +2.91*x}     //back pin groove on flat side
           }
        pigment{col}   
        }
     union {        
        difference {
           cylinder { <0,4,0> <0,4.5,0> 1.1}                  //metalic axe
           union {
              box { <+1.1,4.1,-0.25> <-1.1,4.51,+0.25>}      //axe cross grooves
              box { <-0.25,4.11,-1.1> <+0.25,4.51,+1.1>}
              }
           }
        box { <+0.1,0,-0.5> <-0.1,4.2,+0.5> translate -2.9*x}          //visible front pin allong the case
        difference {
           cylinder { <+0.1,0,0> <-0.1,0,0> 0.5 rotate -15*z translate <-2.9,4.2,0>} //top front pin
           box { <+0.1,0,-0.5> <-0.1,4.2,+0.5> translate -3.1*x }    
           }
        box { <+0.1,0,-0.5> <-0.1,1,+0.5> translate +2.91*x }          //visible back pin allong the case
        box { <+0.1,-3,-0.5> <-0.1,4.3,+0.5> translate 2.54*x}        //flat side pin
        box { <+0.125,-3,-0.5> <-0.125,3.0,+0.5> translate -2.54*x}   //round side pin
        box { <+0.1,-0.35355,-0.35355> <-0.1,0.35355,+0.35355> rotate 45*x translate <2.54,-3,0>}         //flat side pin
        box { <+0.125,-0.35355,-0.35355> <-0.125,0.35355,+0.35355> rotate 45*x translate <-2.54,-3,0>}    //round side pin
        texture{col_silver}
        }
     #if(dot=1)
        cylinder { <2.2,0,0> <2.2,4.81,0> 0.4 pigment{White}} //White dot on the top
     #end
     rotate 90*y
}
#end


#macro CAP_TRIM_TZ03F_BLUE()
  TRIM_TZ03F_BASE(Blue,0)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:CTRIMTZ03=CAP_TRIM_TZ03F_BLUE(:TZ03 muRata capacitor trimmer
// end assignment
