/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Macros for TO220 heatsink type HS-1.25GY-50 from Viewcom
 * Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 30/12/05
 * *****************************************************************************/
#macro SPC_HEATSINK_VIEWCOM_HS_1_25GY_50()
  union {
     #local hole_height=19;
     #local Heatsink_thickness=4.2;
     #local TO220_thickness=1.27;
     #local washer_thickness=0.8;

     #if (global_show_screws=on)
        object {
           TOOLS_SCREW(3,10,0,Silver)
           rotate -90*x translate <0,hole_height,-Heatsink_thickness>
           }
     #end
     #if (global_show_washers=on)
        object {
           TOOLS_WASHER(3,1,Silver)
           rotate 90*x translate <0,hole_height,+TO220_thickness>
           }
     #end
     #if (global_show_nuts=on)
        object {
           TOOLS_NUT(3,0,Silver)
           rotate 90*x translate <0,hole_height,+TO220_thickness+washer_thickness>
           }
     #end
     difference {
        union {
           // main shap with sharp edges
           prism {
              0 32 56 <0,0>, <5.55,0>, <5.55,0.5>, <16.8,0.5>, <16.8,10>, <18.2,10>, <18.4,3.4>, <21.4,5.8>, <21.6,11.1>, <23.4,11.1>, <23.5,7.6>,
              <25.3,9.2>, <25.4,12.2>, <26.9,12.2>, <27.1,10.5>, <29,12>, <30.1,11.2>, <27.7,8.1>, <29.3,8.1>, <29.3,6.6>, <26.1,6.4>, <23.5,3.1>,
              <28.9,2.5>, <28.9,0.8>, <21.1,0.4>, <19.3,-1.6>, <28.9,-2.5>, <28.9,-4.2>,
              <-28.9,-4.2>, <-28.9,-2.5>, <-19.3,-1.6> ,<-21.1,0.4>, <-28.9,0.8>, <-28.9,2.5>, <-23.5,3.1>, <-26.1,6.4>, <-29.3,6.6>, <-29.3,8.1>, <-27.7,8.1>,
              <-30.1,11.2>, <-29,12>, <-27.1,10.5>, <-26.9,12.2>, <-25.4,12.2>, <-25.3,9.2>, <-23.5,7.6>, <-23.4,11.1>, <-21.6,11.1>, <-21.4,5.8>, <-18.4,3.4>,
              <-18.2,10>, <-16.8,10>, <-16.8,0.5>, <-5.55,0.5>, <-5.55,0>, <0,0>
              }
           // round edges
           cylinder {
              <28.9,0,-3.4> <28.9,32,-3.4> .85
              }
           cylinder {
              <28.9,0,1.6> <28.9,32,1.6> .85
              }
           cylinder {
              <29.2,0,7.4> <29.2,32,7.4> .75
              }
           cylinder {
              <29.5,0,11.5> <29.5,32,11.5> .7
              }
           cylinder {
              <26.2,0,12.2> <26.2,32,12.2> .75
              }
           cylinder {
              <22.5,0,11.1> <22.5,32,11.1> .85
              }
           cylinder {
              <17.7,0,10.8> <17.7,32,10.8> 1.7
              }
           cylinder {
              <-28.9,0,-3.4> <-28.9,32,-3.4> .85
              }
           cylinder {
              <-28.9,0,1.6> <-28.9,32,1.6> .85
              }
           cylinder {
              <-29.2,0,7.4> <-29.2,32,7.4> .75
              }
           cylinder {
              <-29.5,0,11.5> <-29.5,32,11.5> .7
              }
           cylinder {
              <-26.2,0,12.2> <-26.2,32,12.2> .75
              }
           cylinder {
              <-22.5,0,11.1> <-22.5,32,11.1> .85
              }
           cylinder {
              <-17.7,0,10.8> <-17.7,32,10.8> 1.7
              }
           pigment {
              Gray20
              }
           }
        union {
           // to make half cylinder
           box {
              <15.5,-0.1,8.4> <16.8,32.1,12.8>
              }
           box {
              <-15.5,-0.1,8.4> <-16.8,32.1,12.8>
              }
           //round groove
           cylinder {
              <17.2,-0.1,10.6> <17.2,32.1,10.6> .75
              }
           cylinder {
              <-17.2,-0.1,10.6> <-17.2,32.1,10.6> .75
              }
           // hole
           cylinder {
              <0,19,-5> <0,19,+5> 1.8
              }
           pigment {
              Gray20
              }
           }
        }
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_HEATSINK_VIEWCOM_HS_1_25GY_50(:TO220 Heatsink Viewcom HS-1.25GY-50:
// end assignment
