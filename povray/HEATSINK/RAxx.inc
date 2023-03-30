/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Macros for TO220 heatsink RAWA-400 from Seifert and RA 37/3 from Seem
 * Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 - 01/01/06
 * *****************************************************************************/
#macro SPC_HEATSINK_RAWA400_GRND(L1,D,Type)
  union {
     #local rawa_height=2;
     #local TO220_height=1.27;
     #local washer_height=0.8;

     #if (global_show_screws=on)
        object {
           TOOLS_SCREW(3,10,0,Silver)
           rotate 180*x translate <0,-pcb_height,0>
           }
     #end

     #if (global_show_washers=on)
        object {
           TOOLS_WASHER(3,1,Silver)
           translate <0,+rawa_height+TO220_height,0>
           }
     #end

     #if (global_show_nuts=on)
        object {
           TOOLS_NUT(3,0,Silver)
           translate <0,+rawa_height+TO220_height+washer_height,0>
           }
     #end

     difference {
        union {
           box {
              <-8,0,-6> <17,02,+6>
              pigment {
                 Gray20
                 }
              }
           // base
           box {
              <-8,0,-6> <17,11,-8>
              pigment {
                 Gray20
                 }
              }
           // side
           box {
              <-8,0,+6> <17,11,+8>
              pigment {
                 Gray20
                 }
              }
           // side
           }
        union {
           box {
              <L1,-0.1,-5.5> <17.1,2.1,+5.5>
              pigment {
                 Gray20
                 }
              }
           cylinder {
              <0,-.1,0> <0,2.1,0> D/2
              pigment {
                 Gray20
                 }
              }
           #if (Type=2)
              cylinder {
                 <-2.5,-.1,0> <-2.5,2.1,0> D/2
                 pigment {
                    Gray20
                    }
                 }
              box {
                 <-2.5,-0.1,-D/2> <0,2.1,D/2>
                 pigment {
                    Gray20
                    }
                 }
           #end
           }
        }
     }
#end

#macro SPC_HEATSINK_RAWA400_8P()
  SPC_HEATSINK_RAWA400_GRND(13,3.8,0)
#end

#macro SPC_HEATSINK_RAWA400_9P()
  SPC_HEATSINK_RAWA400_GRND(9,3.2,1)
#end

#macro SPC_HEATSINK_RAWA400_11P()
  SPC_HEATSINK_RAWA400_GRND(9,3.2,2)
#end



/*******************************************************************************
 * Macros for TO220 heatsink RA 37/3 from Seem
 * Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 - 01/01/06
 * *****************************************************************************/
#macro SPC_HEATSINK_RA37_3()
  difference {
     union {
        object {
           SPC_HEATSINK_RAWA400_9P()
           translate -17*x
           }
        object {
           SPC_HEATSINK_RAWA400_9P()
           translate +8*x
           }
        }
     box {
        <-8,-0.1,-5.5> <+3,2.1,+5.5>
        pigment {
           Gray20
           }
        }
     translate +17*x
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_HEATSINK_RA37_3(:TO220 heatsink RA 37/3 from SEEM
//=SPC_HEATSINK_RAWA400_8P(:TO220 heatsink RAWA400-8P
//=SPC_HEATSINK_RAWA400_9P(:TO220 heatsink RAWA400-9P
//=SPC_HEATSINK_RAWA400_11P(:TO220 heatsink RAWA400-11P
// end assignment
