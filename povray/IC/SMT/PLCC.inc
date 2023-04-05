/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * PLCC Pin
 ******************************************************************************/
#macro IC_SMD_PLCC_PIN()
union {
   intersection {
      difference {
         box { <0,0,0> <1.8,0.9,0.45> }
         cylinder { <0.9,0.9,-0.1> <0.9,0.9,0.5> 0.7}
         }
      cylinder { <0.9,0.9,-0.1> <0.9,0.9,0.5> 0.9}
      }
   box { <1.6,0.8,0> <1.8,1.2,0.45> }
   difference {
      box { <1.6,1.2,-0.125> <1.8,2.5,0.45+0.125> }
      box { <-0.1,0,0> <0.3,0.5,-0.5> rotate <-20,0,0> translate <1.55,1.2,0.00> }
      box { <-0.1,0,0> <0.3,0.5,+0.5> rotate <+20,0,0> translate <1.55,1.2,0.45> }
      }
   difference {
      cylinder { <1.5,2.5,-0.125> <1.5,2.5,0.45+0.125> 0.3 }
      box { <1.6,2.9,-1> <1,2,1> }
      }
   difference {
      box { <1.6,2.5,-0.125> <1.4,2.8,0.45+0.125> }
      cylinder { <1.45,2.45,-1> <1.45,2.45,1> 0.15 }
      }
   translate <-1.4,0,0>
   rotate <0,90,0>
   translate <-0.225,0,0>
   } // end: IC_SMD_PLCC_PIN
#end


/*******************************************************************************
 * PLCC
 ******************************************************************************/
#macro IC_SMD_PLCC_BASE(xsize,ysize,oupin,lrpin,valsize)
union {
   union {
      //Body
      difference {
         box { <0,0,0> <xsize,4.05,ysize> }
         box { <-0.1,0,0> <xsize+0.1,3,-1>  rotate <10,0,0>  translate <0,2.15,0>     }
         box { <-0.1,0,0> <xsize+0.1,3,1>   rotate <-10,0,0> translate <0,2.15,ysize> }
         box { <-1,-3,-0.1> <0,0,ysize+0.1> rotate <0,0,10>  translate <0,1.85,0>     }
         box { <1,-3,-0.1> <0,0,ysize+0.1>  rotate <0,0,-10> translate <xsize,1.85,0> }
         box { <-1,3,-0.1> <0,0,ysize+0.1>  rotate <0,0,-10> translate <0,2.15,0>     }
         box { <1,3,-0.1> <0,0,ysize+0.1>   rotate <0,0,10>  translate <xsize,2.15,0> }
         box { <-0.1,0,0> <xsize+0.1,-3,-1> rotate <-10,0,0> translate <0,1.85,0>     }
         box { <-0.1,0,0> <xsize+0.1,-3,1>  rotate <10,0,0>  translate <0,1.85,ysize> }
         box { <-0.1,0,0> <xsize+0.1,3,1>   rotate <-45,0,0> translate <0,3,ysize>    }
         box { <0,-0.1,-3> <-2,4.5,3>       rotate <0,45,0>  translate <0.8,0,ysize-0.8> }
         sphere { <xsize/2,4.05,ysize-2>0.5 texture{col_bright_marking}        }
         }     
      //Marking
      text{ttf besch_font value 0.2,0 scale<valsize,valsize,valsize> rotate <90,0,0> translate <1.5,4.051,ysize/2> texture{col_bright_marking} }
      translate <-xsize/2,0,-ysize/2>
      texture{col_ic_body_1}
      }
    
   union {
      //Pins
      #local i=0;
      #while(i<(oupin)/2)
         object{IC_SMD_PLCC_PIN()                  translate <+i*1.27,-0.7,-ysize/2> }
         object{IC_SMD_PLCC_PIN()                  translate <-i*1.27,-0.7,-ysize/2> }
         object{IC_SMD_PLCC_PIN() rotate <0,180,0> translate <+i*1.27,-0.7,+ysize/2> }
         object{IC_SMD_PLCC_PIN() rotate <0,180,0> translate <-i*1.27,-0.7,+ysize/2> }
         #local i=i+1;
      #end

      #local i=0;
      #while(i<(lrpin)/2)
         object{IC_SMD_PLCC_PIN() rotate <0,+90,0> translate <-xsize/2,-0.7,+i*1.27> }
         object{IC_SMD_PLCC_PIN() rotate <0,+90,0> translate <-xsize/2,-0.7,-i*1.27> }
         object{IC_SMD_PLCC_PIN() rotate <0,-90,0> translate <+xsize/2,-0.7,+i*1.27> }
         object{IC_SMD_PLCC_PIN() rotate <0,-90,0> translate <+xsize/2,-0.7,-i*1.27> }
         #local i=i+1;
      #end
      texture{col_silver}
      }
   } // end: IC_SMD_PLCC_BASE
#end

//------------------------------------------------------------------------------


#macro IC_SMD_PLCC20(value)
  IC_SMD_PLCC_BASE(9,9,5,5,1.2)
#end
//------------------------------------------------------------------------------
#macro IC_SMD_PLCC28(value)
  IC_SMD_PLCC_BASE(11.45,11.45,7,7,1.5)
#end
//------------------------------------------------------------------------------
#macro IC_SMD_PLCC32(value)
  IC_SMD_PLCC_BASE(11.45,14,7,9,1.5)
#end
//------------------------------------------------------------------------------
#macro IC_SMD_PLCC44(value)
  IC_SMD_PLCC_BASE(16.5,16.5,11,11,2)
#end
//------------------------------------------------------------------------------
#macro IC_SMD_PLCC52(value)
  IC_SMD_PLCC_BASE(19.1,19.1,13,13,2.5)
#end
//------------------------------------------------------------------------------
#macro IC_SMD_PLCC68(value)
  IC_SMD_PLCC_BASE(24.1,24.1,17,17,3)
#end
//------------------------------------------------------------------------------
#macro IC_SMD_PLCC84(value)
  IC_SMD_PLCC_BASE(29.25,29.25,21,21,3)
#end
//------------------------------------------------------------------------------



