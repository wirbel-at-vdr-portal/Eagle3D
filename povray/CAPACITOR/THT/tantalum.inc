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
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CAP_DIS_CTS_A_15MM(:Axial capacitor CTS case A grid 15mm
//=CAP_DIS_CTS_B_20MM(:Axial capacitor CTS case B grid 20mm
//=CAP_DIS_CTS_C_25MM(:Axial capacitor CTS case C grid 25mm
//=CAP_DIS_CTS_D_30MM(:Axial capacitor CTS case D grid 30mm
// end assignment
