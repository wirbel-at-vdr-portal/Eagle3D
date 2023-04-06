/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * axial CTS solid tantalum capacitor (EXXELIA?)
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0 du 06/01/06
 *   diam       = diameter of the main circumference
 *   Lg         = length
 *   value      = text on cap
 *   r          = Pitch
 *   lw         = pins length
 *   dw         = pins width
 ******************************************************************************/
#macro CAP_DIS_CTS_BASE(diam,Lg,Lt,r,lw,dw,value)
  union {
    #local rr=diam/2*0.7;
    #local rrr=0.8;
    difference {
       cylinder { //Body
          <-Lg/2,0,0> <+Lg/2,0,0> diam/2-0.1
          }
       union {   //Plus side
          torus {
             rr rrr
             rotate <90,90,0>
             translate<-Lg/2,0,0>
             }
          cylinder {
             <-Lg/2-rrr,0,0> <-Lg/2+rrr,0,0> rr
             }
          }
       texture {
          col_silver
          }
       }
    cylinder { //Plus pin
       <-Lg/2-Lt+rrr,0,0> <-Lg/2+1,0,0> dw*1.5
       texture {
          Aluminum
          }
       }
    object { //pins
       TOOLS_WIRE_LEADS(Lg,diam,lw*2,dw,r,global_res_bend_radius,0,"H")
       }
    //Text value
    intersection {
       cylinder {
          <-Lg/2,0,0> <+Lg/2,0,0> diam/2-0.1
          }
       union {
          text {
             ttf global_fontfile_arial "+" 2,0
             scale (Lg/20.8)*3
             rotate <-90,180,180>
             translate <-Lg/2.5,diam/2,-(diam/9.1)*1.5 >
             }
          text {
             ttf global_fontfile_arial value 2,0
             scale diam/9.1*3
             rotate <-90,180,180>
             translate <-Lg/3.5,diam/2,-(diam/9.1)*1.5>
             }
          }
       texture {
          col_black_marking
          }
       translate +0.01*y
       }
    translate diam/2*y
    }
#end


#macro CAP_DIS_CTS_A_15MM(value)
  CAP_DIS_CTS_BASE(3.6,8.1,2.1,6*2.54,30,0.5,value)
#end

#macro CAP_DIS_CTS_B_20MM(value)
  CAP_DIS_CTS_BASE(4.9,12.8,2.2,8*2.54,30,0.5,value)
#end

#macro CAP_DIS_CTS_C_25MM(value)
  CAP_DIS_CTS_BASE(7.5,18.2,2.3,10*2.54,30,0.6,value)
#end

#macro CAP_DIS_CTS_D_30MM(value)
  CAP_DIS_CTS_BASE(9.1,20.8,3.2,12*2.54,30,0.6,value)
#end



/*******************************************************************************
 * Tantalum cap, 2.5mm pitch
 ******************************************************************************/
#macro CAP_DIS_TT_2MM5_BASE(obj_dia,obj_hgt,sca_txt)
  union {
     sphere { //Body
        <0,0,0>obj_dia/2
        scale<1,obj_hgt/obj_dia,1>
        pigment { CoolCopper }
        }
     union { //Leads
        #if(pin_short=off)
           cylinder {
              <0,1,0> <0,-16,0> 0.25
              translate <-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
           cylinder {
              <0,1,0> <0,-14,0> 0.25
              translate <1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
        #else
           cylinder {
              <0,1,0> <0,-1*(pcb_height+pin_length)-1.2,0> 0.25
              translate <-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
           cylinder {
              <0,1,0> <0,-1*(pcb_height+pin_length)-1.2,0>0.25
              translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
        #end
        texture { col_silver}
        }
     union { //Marking
        intersection {
           sphere {
              <0,0,0> obj_dia/2
              scale<1,obj_hgt/obj_dia,1.001>
              translate <0,0,0>
              }
           text {
              ttf besch_font "+" obj_dia+0.4, 0
              rotate <0,0,00>
              translate <-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,-(obj_dia+0.4)/2>
              }
           }
        intersection {
           sphere {
              <0,0,0>obj_dia/2
              scale <1,obj_hgt/obj_dia,1.001>
              translate <0,0,0>
              }
           text {
              ttf besch_font value obj_dia+0.4,0
              scale <sca_txt,1,1>
              rotate <0,0,90>
              translate <0.25,-((obj_hgt/obj_dia)*obj_dia)/2+1.5,-(obj_dia+0.4)/2>
              }
           }
        texture {
           col_black_marking
           }
        }
     translate <0,((obj_hgt/obj_dia)*obj_dia)/2+0.2,0>
     }
#end

#macro CAP_DIS_TT_2MM5_4MM(value)
  CAP_DIS_TT_2MM5_BASE(4,8.5,1)
#end

#macro CAP_DIS_TT_2MM5_4MM5(value)
  CAP_DIS_TT_2MM5_BASE(4.5,8.5,1)
#end

#macro CAP_DIS_TT_2MM5_5MM(value)
  CAP_DIS_TT_2MM5_BASE(5,10,1.2)
#end

#macro CAP_DIS_TT_2MM5_5MM5(value)
  CAP_DIS_TT_2MM5_BASE(5.5,10.5,1.3)
#end

#macro CAP_DIS_TT_2MM5_6MM(value)
  CAP_DIS_TT_2MM5_BASE(6,11.5,1.4)
#end

#macro CAP_DIS_TT_2MM5_6MM5(value)
  CAP_DIS_TT_2MM5_BASE(6.5,11.5,1.5)
#end

#macro CAP_DIS_TT_2MM5_7MM(value)
  CAP_DIS_TT_2MM5_BASE(7,12,1.6)
#end

#macro CAP_DIS_TT_2MM5_8MM(value)
  CAP_DIS_TT_2MM5_BASE(8,13,1.8)
#end

#macro CAP_DIS_TT_2MM5_8MM5(value)
  CAP_DIS_TT_2MM5_BASE(8.5,14,1.8)
#end

#macro CAP_DIS_TT_2MM5_9MM(value)
  CAP_DIS_TT_2MM5_BASE(9,15,2)
#end

#macro CAP_DIS_TT_2MM5_10MM(value)
  CAP_DIS_TT_2MM5_BASE(10,18,2)
#end


/*******************************************************************************
 * Tantalum cap, 5mm pitch
 ******************************************************************************/
#macro CAP_DIS_TT_5MM_BASE(obj_dia,obj_hgt,sca_txt)
  union {
     sphere { //Body
        <0,0,0>obj_dia/2
        scale <1,obj_hgt/obj_dia,1>
        pigment { CoolCopper }
        }
     union { //Leads
        cylinder {
           <0,1,0> <0,-1,0>0.25
           translate <-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
           }
        cylinder {
           <0,1,0> <0,-1,0>0.25
           translate <1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
           }
        cylinder {
           <0,0,0> <-1.25,-1,0>0.25
           translate <-1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>
           }
        cylinder {
           <0,0,0> <1.25,-1,0>0.25
           translate <1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>
           }
        #if(pin_short=off)
           cylinder {
              <0,-14,0> <0,-2,0>0.25
              translate <-2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
           cylinder {
              <0,-12,0> <0,-2,0>0.25
              translate <2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
        #else
           cylinder {
              <0,-1*(pcb_height+pin_length)-2.5,0> <0,-2,0>0.25
              translate <-2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
           cylinder {
              <0,-1*(pcb_height+pin_length)-2.5,0> <0,-2,0>0.25
              translate <2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>
              }
        #end
        sphere {
           <0,0,0>0.25
           translate <-2.5,-((obj_hgt/obj_dia)*obj_dia)/2-1,0>
           }
        sphere {
           <0,0,0>0.25
           translate <2.5,-((obj_hgt/obj_dia)*obj_dia)/2-1,0>
           }
        sphere {
           <0,0,0>0.25
           translate <-1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>
           }
        sphere {
           <0,0,0>0.25
           translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>
           }
        texture {
           col_silver
           }
        }
     //Marking
     union {
        intersection {
           sphere {
              <0,0,0>obj_dia/2
              scale <1,obj_hgt/obj_dia,1.001>
              translate <0,0,0>
              }
           text {
              ttf besch_font "+" obj_dia+0.4, 0
              rotate <0,0,0>
              translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,-(obj_dia+0.4)/2>
              }
           }
        intersection {
           sphere {
              <0,0,0> obj_dia/2
              scale <1,obj_hgt/obj_dia,1.001>
              translate <0,0,0>
              }
           text {
              ttf besch_font value obj_dia+0.4,0
              scale <sca_txt,1,1>
              rotate <0,0,90>
              translate <0.25,-((obj_hgt/obj_dia)*obj_dia)/2+1.5,-(obj_dia+0.4)/2>
              }
           }
        texture {
           col_black_marking
           }
        }
     translate <0,((obj_hgt/obj_dia)*obj_dia)/2+1.5,0>
     }
#end


#macro CAP_DIS_TT_5MM_4MM5(value)
  CAP_DIS_TT_5MM_BASE(4.5,8.5,1)
#end

#macro CAP_DIS_TT_5MM_5MM(value)
  CAP_DIS_TT_5MM_BASE(5,10,1.2)
#end

#macro CAP_DIS_TT_5MM_5MM5(value)
  CAP_DIS_TT_5MM_BASE(5.5,10.5,1.3)
#end

#macro CAP_DIS_TT_5MM_6MM(value)
  CAP_DIS_TT_5MM_BASE(6,11.5,1.4)
#end

#macro CAP_DIS_TT_5MM_6MM5(value)
  CAP_DIS_TT_5MM_BASE(6.5,11.5,1.5)
#end

#macro CAP_DIS_TT_5MM_7MM(value)
  CAP_DIS_TT_5MM_BASE(7,12,1.6)
#end

#macro CAP_DIS_TT_5MM_8MM(value)
  CAP_DIS_TT_5MM_BASE(8,13,1.8)
#end

#macro CAP_DIS_TT_5MM_8MM5(value)
  CAP_DIS_TT_5MM_BASE(8.5,14,1.8)
#end

#macro CAP_DIS_TT_5MM_9MM(value)
  CAP_DIS_TT_5MM_BASE(9,15,2)
#end

#macro CAP_DIS_TT_5MM_10MM(value)
  CAP_DIS_TT_5MM_BASE(10,18,2)
#end

#macro CAP_DIS_TT_5MM_11MM(value)
  CAP_DIS_TT_5MM_BASE(11,18,2)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CAP_DIS_CTS_A_15MM(:Axial capacitor CTS case A grid 15mm
//=CAP_DIS_CTS_B_20MM(:Axial capacitor CTS case B grid 20mm
//=CAP_DIS_CTS_C_25MM(:Axial capacitor CTS case C grid 25mm
//=CAP_DIS_CTS_D_30MM(:Axial capacitor CTS case D grid 30mm
//rcl:TT2D4=CAP_DIS_TT_2MM5_4MM(:tantalum cap 2.5mm pitch 4.5mm diameter
//rcl:TT2D5=CAP_DIS_TT_2MM5_5MM(:tantalum cap 2.5mm pitch 5mm diameter
//rcl:TT2D6=CAP_DIS_TT_2MM5_6MM(:tantalum cap 2.5mm pitch 6mm diameter
//rcl:TT2D7=CAP_DIS_TT_2MM5_7MM(:tantalum cap 2.5mm pitch 7mm diameter
//=CAP_DIS_TT_2MM5_4MM5(:tantalum cap 2.5mm pitch
//=CAP_DIS_TT_2MM5_5MM5(:tantalum cap 2.5mm pitch
//=CAP_DIS_TT_2MM5_6MM5(:tantalum cap 2.5mm pitch
//=CAP_DIS_TT_2MM5_8MM(:tantalum cap 2.5mm pitch
//=CAP_DIS_TT_2MM5_8MM5(:tantalum cap 2.5mm pitch
//=CAP_DIS_TT_2MM5_9MM(:tantalum cap 2.5mm pitch
//=CAP_DIS_TT_2MM5_10MM(:tantalum cap 2.5mm pitch
//rcl:TT5D4=CAP_DIS_TT_5MM_4MM5(:tantalum cap 5mm pitch 4.5mm diameter
//rcl:TT5D6=CAP_DIS_TT_5MM_6MM(:tantalum cap 5mm pitch 6mm diameter
//rcl:TT5D7=CAP_DIS_TT_5MM_7MM(:tantalum cap 5mm pitch 7mm diameter
//rcl:TT5D9=CAP_DIS_TT_5MM_9MM(:tantalum cap 5mm pitch 9mm diameter
//rcl:TT5D10=CAP_DIS_TT_5MM_10MM(:tantalum cap 5mm pitch 10mm diameter
//rcl:TT5D11=CAP_DIS_TT_5MM_11MM(:tantalum cap 5mm pitch 11mm diameter
//=CAP_DIS_TT_5MM_4MM5(:tantalum cap 5mm pitch
//=CAP_DIS_TT_5MM_5MM(:tantalum cap 5mm pitch
//=CAP_DIS_TT_5MM_5MM5(:tantalum cap 5mm pitch
//=CAP_DIS_TT_5MM_6MM5(:tantalum cap 5mm pitch
//=CAP_DIS_TT_5MM_8MM(:tantalum cap 5mm pitch
//=CAP_DIS_TT_5MM_8MM5(:tantalum cap 5mm pitch
// end assignment
