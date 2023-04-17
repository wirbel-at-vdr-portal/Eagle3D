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
        #if(positionH = off)
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
        difference {
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
 * TT Electronics RB57/58/59/60/61 Vitreous enamelled - Wirewound resistors
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 01/01/06
 *  - l Length
 *  - d Diameter
 *  - r Pitch
 *  - lw pin length
 *  - dw pin diameter
 *  - op extra height above PCB
 * *****************************************************************************/
#macro RES_THT_RBxx_BASE(value,l,d,r,lw,dw,op)
  union {
     #if (op = 0)
        #local space = 1.5; //default space
     #else
        #local space = 0.0;
     #end

     union {
        superellipsoid {
           <1.0, 0.1>
           scale <1,1,2>
           rotate <0,90,0>
           translate <0,0,0>
           }
        // body
        intersection {
           cylinder {
              <-2,0,0> <2,0,0>, 1
              }
           union {
              #switch(l)
                 #case(22.5)
                    text {
                       ttf global_fontfile_arial "RB57" 20, 0
                       scale <0.6,0.7,0.7> * 0.8
                       rotate <-90,180,180>
                       translate <-0.6,2,-0.25>
                       rotate <+18,0,0>
                       }
                    text {
                       ttf global_fontfile_arial value 20, 0
                       scale <0.6,0.7,0.7> * 0.8
                       rotate <-90,180,180>
                       translate <-0.6,2,-0.25>
                       rotate <-18,0,0>
                       }
                    #break
                 #case(47)
                    text {
                       ttf global_fontfile_arial "RB58" 20, 0
                       scale <0.6,0.7,0.7> * 0.5
                       rotate <-90,180,180>
                       translate <-0.4,2,-0.25>
                       rotate<+12,0,0>
                       }
                    text {
                       ttf global_fontfile_arial value 20, 0
                       scale <0.6,0.7,0.7> * 0.5
                       rotate <-90,180,180>
                       translate <-0.4,2,-0.25>
                       rotate <-12,0,0>
                       }
                    #break
                 #case(12.7)
                    text {
                       ttf global_fontfile_arial "RB59" 20, 0
                       scale <0.6,0.7,0.7>
                       rotate <-90,180,180>
                       translate <-0.8,2,-0.25>
                       rotate <+20,0,0>
                       }
                    text {
                       ttf global_fontfile_arial value 20, 0
                       scale <0.6,0.7,0.7>
                       rotate <-90,180,180>
                       translate <-0.8,2,-0.25>
                       rotate <-20,0,0>
                       }
                    #break
                 #case(36)
                    text {
                       ttf global_fontfile_arial "RB60" 20, 0
                       scale <0.6,0.7,0.7> * 0.6
                       rotate <-90,180,180>
                       translate <-0.55,2,-0.25>
                       rotate <+16,0,0>
                       }
                    text {
                       ttf global_fontfile_arial value 20, 0
                       scale <0.6,0.7,0.7> * 0.6
                       rotate <-90,180,180>
                       translate <-0.55,2,-0.25>
                       rotate <-16,0,0>
                       }
                    #break
                 #case(23)
                    text {
                       ttf global_fontfile_arial "RB61" 20, 0
                       scale <0.6,0.7,0.7> * 0.8
                       rotate <-90,180,180>
                       translate <-0.7,2,-0.25>
                       rotate <+20,0,0>
                       }
                    text {
                       ttf global_fontfile_arial value 20, 0
                       scale <0.6,0.7,0.7> * 0.8
                       rotate <-90,180,180>
                       translate <-0.7,2,-0.25>
                       rotate <-20,0,0>
                       }
                    #break
                 #end
                 }
              pigment {
                 White
                 }
              translate 0.01*y
              }
           scale <2,2,2>
           scale <l/2/4,d/2/2,d/2/2>      //Scale back to given size
           texture {
              pigment {
                 color red 0.013 green 0.094 blue 0.030
                 }
              finish {
                 ambient (1 * global_ambient_mul)
                 specular 0.1
                 reflection {
                    0.08, 1 fresnel
                    }
                 conserve_energy
                 }
              }
           }
        object {
           TOOLS_WIRE_LEADS(l,d,lw*2,dw,r,global_res_bend_radius,op+space,"H")
           }
        #if (op > 0)
           difference {
              union {
                 cylinder {
                    <0,-0.5,0> <0,-op-d/2,0> 1.3
                    translate <-r/2,0,0>
                    pigment {
                       Gray95
                       }
                    }
                 cylinder {
                    <0,-0.5,0> <0,-op-d/2,0> 1.3
                    translate <+r/2,0,0>
                    pigment {
                       Gray95
                       }
                    }
                 }
              union {
                 cylinder {
                    <0,0.5,0> <0,-op-d/2-1,0> 0.5
                    translate <-r/2,0,0>
                    pigment {
                       Gray95
                       }
                    }
                 cylinder {
                    <0,0.5,0> <0,-op-d/2-1,0> 0.5
                    translate <+r/2,0,0>
                       pigment {
                       Gray95
                       }
                    }
                 }
              }
        #end
        translate <0,d/2+0.1+op,0>
        }
     translate <0,space,0>
#end


//RB57 30.48mm
#macro RES_THT_RB57_30mm(value)
   RES_THT_RBxx_BASE(value,22.5,8,12*2.54,30,0.88,8)
#end

//RB58 55.88mm
#macro RES_THT_RB58_55mm(value)
   RES_THT_RBxx_BASE(value,47,11,22*2.54,30,0.88,8)
#end

//RB59 22.86mm
#macro RES_THT_RB59_22mm(value)
   RES_THT_RBxx_BASE(value,12.7,5.6,9*2.54,30,0.88,8)
#end

//RB60 45.72mm
#macro RES_THT_RB60_45mm(value)
   RES_THT_RBxx_BASE(value,36,10,18*2.54,30,0.88,8)
#end

//RB61 30.48mm
#macro RES_THT_RB61_30mm(value)
   RES_THT_RBxx_BASE(value,23,7,12*2.54,30,0.88,8)
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
//=RES_THT_RB57_30mm(:THT 7W resistor
//=RES_THT_RB58_55mm(:THT 11W resistor
//=RES_THT_RB59_22mm(:THT 3W resistor
//=RES_THT_RB60_45mm(:THT 8W resistor
//=RES_THT_RB61_30mm(:THT 5W resistor
// end assignment
