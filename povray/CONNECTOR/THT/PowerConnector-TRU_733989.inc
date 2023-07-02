/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * FEMALE PRINT CONNECTOR DIN 45323 (34V/3A), TRU COMPONENTS 733989,
 *    Conrad 1571231
 *
 * Aussen-Ø 4,2 mm, Innen 1.1 mm
 * EAN: 2050004886962
 * con-conrad
 * 02.07.2023, -wk
 *
 * NOTE: lbr drawing pin3 is off by 0.1mm
 ******************************************************************************/
#macro CON_THT_Power_733989()
  union {
     difference {
        union {
           #local pin = union {
              box {
                 <-2/2,       1,-0.4/2>
                 <+2/2,-3.6+2/2,+0.4/2>
                 }
              cylinder {
                 <0,-3.6+2/2,-0.4/2>
                 <0,-3.6+2/2,+0.4/2>
                 2/2
                 }
              texture {
                 col_silver
                 }
              };
           object { pin rotate<0,0,0>  translate <0,0,0> }
           object { pin rotate<0,0,0>  translate <0,0,4.9> }
           object { pin rotate<0,90,0> translate <2.8,0,2.5> }
           Round_Box (
              <-5/2,  0,-6  >
              <+5/2,7.4,-4.2>
              0.2 0
              )
           Round_Box (
              <-5/2,  0,-5  >
              <+5/2,4.7,+4.8>
              0.2 0
              )
           Round_Cylinder (
              <0,4.7,-5  >
              <0,4.7,+1.4>
              4.8/2
              0.2 0
              )
           Round_Cylinder (
              <0,4.7,+1>
              <0,4.7,+4.8>
              2.6/2
              0.2 0
              )
           }
        cylinder {
           <0,4.7,-7>
           <0,4.7,+1>
           4.2/2
           }
        pigment {
           White * 0.3
           }
        }
     union {
        Round_Cylinder (
           <0,4.7,-5  >
           <0,4.7,+1.4>
           1.1/2
           1.1/2 0
           )
        cylinder {
           <-3/2,2.5,-2>
           <+3/2,2.5,-2>
           2/2
           }
        cylinder {
           <0,4.7,4.5>
           <0,4.7,4.9>
           2.6/2
           }
        cylinder {
           <0,4.7,4.5>
           <0,4.7,5.1>
           1.3/2
           }
        box {
           <-2.6/2,  0,4.5>
           <+2.6/2,4.7,4.9>
           }
        Round_Box (
           <2.8-0.4/2,0,2.5-2/2>
           <2.8+0.4/2,2.5,2.5+2/2>
           0.2 0
           )
        texture {
           col_silver
           }
        }
     translate <0,0,0.92>
     }
#end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-conrad:733989-5=CON_THT_Power_733989(:Power Connector DIN 45323
// end assignment
