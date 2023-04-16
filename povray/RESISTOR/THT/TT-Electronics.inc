/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * TT Electronics BPC series power ceramic resistors
 * Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * Rev. 1.0  12/05/06
 ******************************************************************************/
#macro RESISTOR_BPC_BASE(value,A,B,positionH,pRot,pTra)
  #local jc=6;
  #local col_gn = color red 0.55 green 0.53 blue 0.30;

  union {
     box {
        <-A/2,2.2,-0.127> <+A/2,27.686,-0.727>
        pigment {
           Gray90
           }
        }
     box {
        <-A/2*0.9,jc,0> <-A/2*0.9+2,27.6,-0.73>
        pigment {
           col_gn
           }
        }
     box {
        <+A/2*0.9,jc,0> <+A/2*0.9-2,27.6,-0.73>
        pigment {
           col_gn
           }
        }
     box {
        <-A/2*0.9,25,0> <+A/2*0.9,27.6,-0.73>
        pigment {
           col_gn
           }
        }
     // extrude a closed 2-D shape along an axis
     prism {
        linear_sweep
        linear_spline
        0.72, 0.73, 4, <+A/2*0.9,jc>, <+A/2*0.9-2,jc>, <+B/2-1,4>, <+B/2+1,4>
        pigment {
           col_gn
           }
        rotate -90*x
        }
     prism {
        linear_sweep
        linear_spline
        0.72, 0.73, 4, <-A/2*0.9,jc>, <-A/2*0.9+2,jc>, <-B/2+1,4>, <-B/2-1,4>
        pigment {
           col_gn
           }
        rotate -90*x
        }
     box {
        <-B/2+1,2.5,0> <-B/2-1,4,-0.73>
        pigment {
           col_gn
           }
        }
     box {
        <+B/2-1,2.5,0> <+B/2+1,4,-0.73>
        pigment {
           col_gn
           }
        }
     box {
        <-A/2*0.75,12.4,0> <+A/2*0.75,26.6,-0.74>
        pigment {
           DarkGreen
           }
        }    

     text {
        ttf global_fontfile_arial_bold value 0.5,0
        pigment {
           Black
           }
        scale <1.5,1.5,0.1>
        translate <-2,7,-0.73>
        }
     text {
        ttf global_fontfile_eagle3d "b" 0.5,0
        pigment {
           Black
           }
        scale <2,2,0.1>
        translate <-1.5,10.5,-0.73>
        }

     #local sx = 2;
     #local dx = -3;
     #local code = "BPC XX"

     #switch(A)
         #range (10,11)
            #local sx=1.5;
            #local dx=-2;
            #local code = "BPC 3";
            #break
         #range (12,13)
            #local code = "BPC 5";
            #break
         #range (19,20)
            #local code = "BPC 7";
            #break
         #range (25,26)
            #local code = "BPC 10";
            #break
         #end

     text {
        ttf global_fontfile_arial_bold code 0.5,0
        pigment {
           Black
           }
        scale <sx,2,0.1>
        translate <dx,8.5,-0.73>
        }
 
     union {
        #if(positionH=off)
           box {
              <-B/2-0.25,-3.175,-0.127> <-B/2+0.25,4,+0.127>
              }
           box {
              <+B/2+0.25,-3.175,-0.127> <+B/2-0.25,4,+0.127>
              }
        #end        
        difference{
           box {
              <-B/2-0.7,0,-0.127> <-B/2+0.7,4,+0.127>
              }
           box {
              <-0.5,-1,-1> <+0.5,+1,+1>
              rotate +30*z
              translate <-B/2-0.83,-0,0>
              }
           box {
              <-0.5,-1,-1> <+0.5,+1,+1>
              rotate -30*z
              translate <-B/2+0.83,-0,0>
              }
           }        
        difference{
           box {
              <+B/2+0.7,0,-0.127>
              <+B/2-0.7,4,+0.127>
              }
           box {
              <-0.5,-1,-1><+0.5,+1,+1>
              rotate -30*z
              translate<+B/2-0.83,-0,0>
              }
           box {
              <-0.5,-1,-1> <+0.5,+1,+1>
              rotate +30*z
              translate<+B/2+0.83,-0,0>
              }
           }
        
        box {
           <-B/2-0.7,2.2-0.254,-0.127-0.6-0.254> <-B/2+0.7,4,+0.127-0.6-0.254>
           }
        box {
           <+B/2+0.7,2.2-0.254,-0.127-0.6-0.254> <+B/2-0.7,4,+0.127-0.6-0.254>
           }
        box {
           <-B/2-0.7,2.2,-0.127-0.6-0.254> <-B/2+0.7,2.2-0.254,0>
           }
        texture {
           col_silver
           }
        }
    
     rotate pRot 
     translate pTra
     }
#end


#macro RES_THT_BPC3V(value)
  RESISTOR_BPC_BASE(value,10.16,5.08,off,0,0)
#end

#macro RES_THT_BPC5V(value)
  RESISTOR_BPC_BASE(value,12.70,5.08,off,0,0)
#end

#macro RES_THT_BPC7V(value)
  RESISTOR_BPC_BASE(value,19.05,12.70,off,0,0)
#end

#macro RES_THT_BPC10V(value)
  RESISTOR_BPC_BASE(value,25.40,20.32,off,0,0)
#end

#macro RES_THT_BPC3H(value)
  RESISTOR_BPC_BASE(value,10.16,5.08,on,90*x,-1.27*z)
#end

#macro RES_THT_BPC5H(value)
  RESISTOR_BPC_BASE(value,12.70,5.08,on,90*x,-1.27*z)
#end

#macro RES_THT_BPC7H(value)
  RESISTOR_BPC_BASE(value,19.05,12.70,on,90*x,-1.27*z)
#end

#macro RES_THT_BPC10H(value)
  RESISTOR_BPC_BASE(value,25.40,20.32,on,90*x,-1.27*z)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=RES_THT_BPC3V(:3W ceramic resistor
//=RES_THT_BPC5V(:5W ceramic resistor
//=RES_THT_BPC7V(:7W ceramic resistor
//=RES_THT_BPC10V(:10W ceramic resistor
//=RES_THT_BPC3H(:3W ceramic resistor
//=RES_THT_BPC5H(:5W ceramic resistor
//=RES_THT_BPC7H(:7W ceramic resistor
//=RES_THT_BPC10H(:10W ceramic resistor
// end assignment
