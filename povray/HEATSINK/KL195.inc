/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Macros for TO220 heatsink type KL195 and KL195i SEIFERT
 * Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 - 04/01/06
 * *****************************************************************************/
#macro SPC_HEATSINK_KL195_BASE(Lg,Iso)
  #macro half_KL195(Lg, Iso)
     union {
        difference {
           union {
              //body with sharp edges
              prism {
                 0 Lg 38 <0,0>, <0,1.1>, <8.4,1.1>, <11.63,12.29>, <12.78,11.95>, <11.11,4.55>, <12.88,4.2>, <15.725,12.28>,
                 <16.88,11.94>, <14.44,4.68>, <16.15,4.1>,
                 <19.97,11.28>, <21.05,10.76>, <17.35,4.1>, <18.00,3.42>, <20.415,4.194>, <20.69,3.237>, <13.75,0.6>, <13.75,0>,
                 <-13.75,0>, <-13.75,0.6>, <-20.69,3.237>, <-20.415,4.194>, <-18.00,3.42>, <-17.25,4.1>, <-21.05,10.76>, <-19.97,11.28>,
                 <-16.15,4.1>, <-14.44,4.68>, <-16.88,11.94>, <-15.725,12.28>,
                 <-12.88,4.2>, <-11.11,4.55>, <-12.78,11.95>, <-11.63,12.29>, <-8.4,1.1>, <-0,1.1>, <0,0>
                 }
              //make external round edges
              cylinder {
                 <12.2,0,12.1> <12.2,Lg,12.1> .6
                 }
              cylinder {
                 <16.3,0,12.1> <16.3,Lg,12.1> .6
                 }
              cylinder {
                 <20.5,0,11> <20.5,Lg,11> .6
                 }
              cylinder {
                 <20.5,0,3.7> <20.5,Lg,3.7> .5
                 }
              cylinder {
                 <-12.2,0,12.1> <-12.2,Lg,12.1> .6
                 }
              cylinder {
                 <-16.3,0,12.1> <-16.3,Lg,12.1> .6
                 }
              cylinder {
                 <-20.5,0,11> <-20.5,Lg,11> .6
                 }
              cylinder {
                 <-20.5,0,3.7> <-20.5,Lg,3.7> .5
                 }
              }
           union {
              cylinder {
                 <-14,-0.01,0> <-14,Lg+0.01,0> 0.65
                 }
              //make internal round edges
              cylinder {
                 <12,-0.01,4.4> <12,Lg+0.01,4.4> 0.9
                 }
              cylinder {
                 <15.3,-0.01,4.4> <15.3,Lg+0.01,4.4> 0.9
                 }
              cylinder {
                 <17.8,-0.01,3.88> <17.8,Lg+0.01,3.88> 0.5
                 }
              cylinder {
                 <14,0,-0.01> <14,Lg,0> 0.65
                 }
              cylinder {
                 <-12,-0.01,4.4> <-12,Lg+0.01,4.4> 0.9
                 }
              cylinder {
                 <-15.3,-0.01,4.4> <-15.3,Lg+0.01,4.4> 0.9
                 }
              cylinder {
                 <-17.8,-0.01,3.88> <-17.8,Lg+0.01,3.88> 0.5
                 }
              }
           pigment {
              Gray30
              }
           }
        //insulation rings and pins
        #if (Iso=1)
           cylinder {
              <12.7,-3,0> <12.7,0,0> 3
              pigment {
                 Gray80
                 }
              }
           // ring
           cylinder {
              <12.7,-6,0> <12.7,0,0> 1.25
              pigment {
                 Silver
                 }
              }
           // pin
        #else
           cylinder {
              <12.7,-4,0> <12.7,0,0> 1.25
              pigment {
                 Silver
                 }
              }
           // pin
        #end
        }
  #end

  union {
     #local hole_height=18.3;
     #local KL195_thickness=2.2;
     #local TO220_thickness=1.27;
     #local washer_thickness=0.8;
     #if (Iso=0) // Screws is used only with no insolated version (should to use clips instead)
        #if (global_show_screws=on)
           object {
              TOOLS_SCREW(3,8,0,Silver)
              rotate -90*x translate <0,hole_height,-KL195_thickness/2>
              }
        #end
        #if (global_show_washers=on)
           object {
              TOOLS_WASHER(3,1,Silver)
              rotate 90*x translate <0,hole_height,+KL195_thickness/2+TO220_thickness>
              }
        #end
        #if (global_show_nuts=on)
           object {
              TOOLS_NUT(3,0,Silver)
              rotate 90*x translate <0,hole_height,+KL195_thickness/2+TO220_thickness+washer_thickness>
              }
        #end
     #end
     difference {
        union {
           object {
              half_KL195(Lg, Iso)
              }
           object {
              half_KL195(Lg, Iso)
              rotate 180*y
              }
           }
        //holes
        union {
           cylinder {
              <0,18.3,-5> <0,18.3,+5> 1.6
              }
           #if (Lg> 25.4)
              cylinder {
                 <0,25.4,-5> <0,25.4,+5> 1.6
                 }
           #end
           }
        pigment {
           Gray20
           }
        }
     translate <0,Iso*3,-1.1> // shift 3 if insulation ring exist, shift 1.1 to set zero on heatsink surface
     }
#end

#macro SPC_HEATSINK_KL195_25()
  SPC_HEATSINK_KL195_BASE(25.4,0)
#end

#macro SPC_HEATSINK_KL195_38()
  SPC_HEATSINK_KL195_BASE(38.4,0)
#end

#macro SPC_HEATSINK_KL195_50()
  SPC_HEATSINK_KL195_BASE(50.8,0)
#end

#macro SPC_HEATSINK_KL195_63()
  SPC_HEATSINK_KL195_BASE(63.5,0)
#end

#macro SPC_HEATSINK_KL195_25I()
  SPC_HEATSINK_KL195_BASE(25.4,1)
#end

#macro SPC_HEATSINK_KL195_38I()
  SPC_HEATSINK_KL195_BASE(38.4,1)
#end

#macro SPC_HEATSINK_KL195_50I()
  SPC_HEATSINK_KL195_BASE(50.8,1)
#end

#macro SPC_HEATSINK_KL195_63I()
  SPC_HEATSINK_KL195_BASE(63.5,1)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_HEATSINK_KL195_25(:TO220 heatsink 6.2°C/W
//=SPC_HEATSINK_KL195_38(:TO220 heatsink 5.0°C/W:
//=SPC_HEATSINK_KL195_50(:TO220 heatsink 4.2°C/W:
//=SPC_HEATSINK_KL195_63(:TO220 heatsink 3.6°C/W:
//=SPC_HEATSINK_KL195_25I(:TO220 heatsink 6.2°C/W isolated
//=SPC_HEATSINK_KL195_38I(:TO220 heatsink 5.0°C/W isolated
//=SPC_HEATSINK_KL195_50I(:TO220 heatsink 4.2°C/W isolated
//=SPC_HEATSINK_KL195_63I(:TO220 heatsink 3.6°C/W isolated
// end assignment
