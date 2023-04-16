/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * wired resistor. Arguments
 *   - Value1
 *   - Value2
 *   - Multiplier
 *   - Tolerance
 * are 4 band resistor value colour codes,
 *   see -> doc/Resistor Color Codes/resistor_color_codes_chart.png
 *   see -> TOOLS/colors.inc, "Resistor value color codes"
 *
 * - l length
 * - d diameter
 * - r pitch
 * - lw wire length
 * - dw wire diameter
 * - op rise of part above pcb
 * - h:  "V"=vertical, "H"=horizontal
 * - w:  rise part by 1.5mm
 ******************************************************************************/
#macro THT_RESISTOR_BASE(l,d,Value1,Value2,Multiplier,Tolerance,r,lw,dw,op,h,w)
  union {
     #local res_col = array[4]
     #local res_col[0] = texture {
        pigment {
           DarkGreen
           }
        finish {
           phong 0.1
           ambient (0.1 * global_ambient_mul)
           }
        };
     #local res_col[1] = texture {
        pigment {
           rgb <1,0.83,0.61> * 0.8
           }
        finish {
           phong 0.1
           ambient (0.1 * global_ambient_mul)
           }
        };
     #local res_col[2] = texture {
        pigment {
           SummerSky
           }
        finish {
           phong 0.1
           ambient (0.1 * global_ambient_mul)
           }
        };
     #local res_col[3] = texture {
        pigment {
           DarkBrown
           }
        finish {
           phong 0.1
           ambient (0.1 * global_ambient_mul)
           }
        };

  #local is_horizontal = (strcmp(strupr(h),"H"));

  #if(global_res_colselect)
     #local res_act_col = res_col[rand(global_seed)*4];
  #else
     #local res_act_col = res_col[global_res_col];
  #end

  #if (w >= 1.0)
     #local separation = 1.5;
  #else
     #local separation = 0.0;
  #end

  //Widerstandskoerper
  union {
     #if(global_res_shape=1)
        blob {
           threshold 0.01
           cylinder {
              <-2.5,0,0> <+2.50,0,0>, 1.2,0.1
              }
           cylinder {
              <-2.3,0,0> <-2.29,0,0>, 1.5,0.1
              }
           cylinder {
              <+2.3,0,0> <+2.29,0,0>, 1.5,0.1
              }
           }
        torus {
           0.915,0.1
           texture {
              Value1
              }
           scale <1,3,1>
           rotate <90,90,0>
           translate <1,0,0>
           }
        torus {
           0.915,0.1
           texture {
              Value2
              }
           scale <1,3,1>
           rotate <90,90,0>
           translate <0.4,0,0>
           }
        torus {
           0.915,0.1
           texture {
              Multiplier
              }
          scale <1,3,1>
           rotate <90,90,0>
           translate <-0.2,0,0>
           }
        torus {
           0.915,0.1
           texture {
              Tolerance
              }
           scale <1,3,1>
           rotate <90,90,0>
           translate <-1.0,0,0>
           }
        scale <1.4,1.615,1.615>   //Scale to 5 unit long and 2 unit wide
        scale <l/2/5,d/2/2,d/2/2> //Scale back to given size
     #else
        superellipsoid {
           <1.0, 0.25>
           scale <1,1,1/2>
           rotate <0,90,0>
           translate <-2,0,0>
           } // Right endcap
        superellipsoid {
           <1.0, 0.25>
           scale <1,1,1/2>
           rotate <0,90,0>
           translate <2,0,0>
           }  // Left endcap
        cylinder {
           <-(2),0,0> <(2),0,0>,1*0.95
           } // MELF typically has 95% smaller body radius than end caps
        cylinder {
           <1.37,0,0>  <((1.37-(1.5)/10)),0,0>, 0.951
           texture {
              Value1
              }
           }
        cylinder {
           <(1.37- 2*(1.5)/6),0,0> <((1.37- 2*(1.5)/6-(1.5)/10) ),0,0>, 0.951
           texture {
              Value2
              }
           }
        cylinder {
           <(1.37- 4*(1.5)/6),0,0> <((1.37- 4*(1.5)/6-(1.5)/10) ),0,0>, 0.951
           texture {
              Multiplier
              }
           }
        cylinder {
           <(1.37- 8*(1.5)/6),0,0> <((1.37- 8*(1.5)/6-(1.5)/10) ),0,0>, 0.951
           texture {
              Tolerance
              }
           }
        scale <2.01,2,2>          //Scale to 5 unit long and 2 unit wide
        scale <l/2/5,d/2/2,d/2/2> //Scale back to given size
     #end

     texture {
        res_act_col
        }

     #if(is_horizontal)
        rotate<0,0,90>
     #end
     }

  #if(is_horizontal)
     object{TOOLS_WIRE_LEADS(l,d,lw*2,dw,r,global_res_bend_radius,0,"V")}
     translate<-r/2,l/2+0.1+op,0>
  #else
     object{TOOLS_WIRE_LEADS(l,d,lw*2,dw,r,global_res_bend_radius,0,"H")}
     translate<0,d/2+0.1+op,0>
  #end

  translate<0,separation,0>
  }
#end


#macro RES_THT_0204_025mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(3.3,1.6,Value1,Value2,Multiplier,Tolerance,2.54*1,20,0.6,0,"V",0.2)
#end

#macro RES_THT_0204_054mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(3.3,1.6,Value1,Value2,Multiplier,Tolerance,2.54*2,20,0.6,0,"H",0.2)
#end

#macro RES_THT_0204_075mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(3.3,1.6,Value1,Value2,Multiplier,Tolerance,2.54*3,20,0.6,0,"H",0.2)
#end

#macro RES_THT_0207_025mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(5.8,2.2,Value1,Value2,Multiplier,Tolerance,2.54,20,0.6,0,"V",0.3)
#end

#macro RES_THT_0207_050mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(5.8,2.2,Value1,Value2,Multiplier,Tolerance,2.54*2,20,0.6,0,"V",0.3)
#end

#macro RES_THT_0207_075mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(5.8,2.2,Value1,Value2,Multiplier,Tolerance,2.54*3,20,0.6,0,"H",0.3)
#end

#macro RES_THT_0207_10mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(5.8,2.2,Value1,Value2,Multiplier,Tolerance,2.54*4,20,0.6,0,"H",0.3)
#end

#macro RES_THT_0207_12mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(5.8,2.2,Value1,Value2,Multiplier,Tolerance,2.54*5,20,0.6,0,"H",0.3)
#end

#macro RES_THT_0207_15mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(5.8,2.2,Value1,Value2,Multiplier,Tolerance,2.54*6,20,0.6,0,"H",0.3)
#end

#macro RES_THT_0309_10mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(8,3,Value1,Value2,Multiplier,Tolerance,2.54*4,20,0.6,0,"H",0.35)
#end

#macro RES_THT_0309_12mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(8,3,Value1,Value2,Multiplier,Tolerance,2.54*5,20,0.6,0,"H",0.35)
#end

#macro RES_THT_0309_025mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(8,3,Value1,Value2,Multiplier,Tolerance,2.54,20,0.6,0,"V",0.35)
#end

#macro RES_THT_0411_037mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(12,3.9,Value1,Value2,Multiplier,Tolerance,2.54*1.5,20,0.78,0,"V",0.5)
  translate <-2.54/4,0,0>
#end

#macro RES_THT_0411_12mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(12,3.9,Value1,Value2,Multiplier,Tolerance,2.54*5,20,0.78,0,"H",0.5)
#end

#macro RES_THT_0411_15mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(12,3.9,Value1,Value2,Multiplier,Tolerance,2.54*6,20,0.78,0,"H",0.5)
#end

#macro RES_THT_0414_15mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(11,3.9,Value1,Value2,Multiplier,Tolerance,2.54*6,20,0.8,0,"H",0.5)
#end

#macro RES_THT_0414_050mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(11,3.9,Value1,Value2,Multiplier,Tolerance,2.54*2,20,0.8,0,"V",0.5)
#end

#macro RES_THT_0613_050mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(13,5.5,Value1,Value2,Multiplier,Tolerance,2.54*2,20,0.8,0,"V",0.8)
#end

#macro RES_THT_0613_15mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(13,5.5,Value1,Value2,Multiplier,Tolerance,2.54*6,20,0.8,0,"H",0.8)
#end

#macro RES_THT_0617_17mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(15.5,5.8,Value1,Value2,Multiplier,Tolerance,2.54*7,20,0.8,0,"H",1.0)
#end

#macro RES_THT_0617_22mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(15.5,5.8,Value1,Value2,Multiplier,Tolerance,2.54*9,20,0.8,0,"H",1.0)
#end

#macro RES_THT_0617_050mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(15.5,5.8,Value1,Value2,Multiplier,Tolerance,2.54*2,20,0.8,0,"V",1.0)
#end

#macro RES_THT_0817_050mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(17,7.5,Value1,Value2,Multiplier,Tolerance,2.54*2.5,20,0.78,0,"V",1.0)
  translate <-2.54*0.75,0,0>
#end

#macro RES_THT_0817_22mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(17,7.5,Value1,Value2,Multiplier,Tolerance,2.54*9,20,0.78,0,"H",1.0)
#end

#macro RES_THT_0922_22mm(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(19,8.8,Value1,Value2,Multiplier,Tolerance,2.54*9,20,0.8,0,"H",1.3)
#end

#macro RES_THT_0922_075mm_vertical(Value1,Value2,Multiplier,Tolerance)
  THT_RESISTOR_BASE(19,8.8,Value1,Value2,Multiplier,Tolerance,2.54*3,20,0.8,0,"V",1.3)
  translate <-2.54/2,0,0>
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:0204V=RES_THT_0204_025mm_vertical(:THT resistor 0204 vertical
//rcl:0204/5=RES_THT_0204_054mm(:THT resistor 0204
//rcl:0204/7=RES_THT_0204_075mm(:THT resistor 0204
//rcl:0207/2V=RES_THT_0207_025mm_vertical(:THT resistor 0207 vertical
//rcl:0207/5V=RES_THT_0207_050mm_vertical(:THT resistor 0207 vertical
//rcl:0207/7=RES_THT_0207_075mm(:THT resistor 0207
//rcl:0207/10=RES_THT_0207_10mm(:THT resistor 0207
//rcl:0207/12=RES_THT_0207_12mm(:THT resistor 0207
//rcl:0207/15=RES_THT_0207_15mm(:THT resistor 0207
//rcl:0309/10=RES_THT_0309_10mm(:THT resistor 0309
//rcl:0309/12=RES_THT_0309_12mm(:THT resistor 0309:
//rcl:0309V=RES_THT_0309_025mm_vertical(:THT resistor 0309 vertical
//rcl:0411V=RES_THT_0411_037mm_vertical(:THT resistor 0411 vertical
//rcl:0411/12=RES_THT_0411_12mm(:THT resistor 0411
//rcl:0411/15=RES_THT_0411_15mm(:THT resistor 0411
//rcl:0414/15=RES_THT_0414_15mm(:THT resistor 0414
//rcl:0414V=RES_THT_0414_050mm_vertical(:THT resistor 0414
//rcl:P0613V=RES_THT_0613_050mm_vertical(:THT resistor 0613 vertical
//rcl:P0613/15=RES_THT_0613_15mm(:THT resistor 0613
//rcl:0617/17=RES_THT_0617_17mm(:THT resistor 0617
//rcl:0617/22=RES_THT_0617_22mm(:THT resistor 0617
//rcl:0617V=RES_THT_0617_050mm_vertical(:THT resistor 0617 vertical
//rcl:P0817V=RES_THT_0817_050mm_vertical(:THT resistor 0817 vertical
//rcl:P0817/22=RES_THT_0817_22mm(:THT resistor 0817
//rcl:0922/22=RES_THT_0922_22mm(:THT resistor 0922
//rcl:0922V=RES_THT_0922_075mm_vertical(:THT resistor 0922 vertical
// end assignment
