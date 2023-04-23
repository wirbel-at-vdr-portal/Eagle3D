/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SECME 1K2 series THT switch
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  26/03/06
 * *****************************************************************************/
#macro SECME1K2_BASE(Cnx,Act,Au)
  union {
     union {
        difference {
           union {
              superellipsoid {
                 <0.05, 0.05>
                 scale <5, 2.25,1.25>
                 translate <0, 0.5+2.25, 0>
                 }
              cylinder {
                 <-4,0,0> <-4,0.5,0> 0.5
                 }
              cylinder {
                 <+4,0,0> <+4,0.5,0> 0.5
                 }
              }
           cylinder {
              <+4,4.9,0> <+4,5.1,0> 0.5
              }
           box {
              <-1.5,3.5,-1.3> <+1.5,4,+1.3>
              }
           box {
              <-4.9,3.4,-1.3> <-5.1,4.1,+1.3>
              }
           box {
              <-3.7,2,-1.2> <+3.7,3.3,-1.3>
              }
           }
        text {
           ttf global_fontfile_arial_bold "SECME" 0.1, 0
           scale 1.3
           rotate <0,0,0>
           translate <-2.3,2.2,-1.25>
           }
        // Marking
        #if (Au = 0)
           pigment {
              Gray80
              }
        #else
           pigment {
              Gray15
              }
        #end
        finish {
           diffuse 0.5
           specular 0.5
           ambient (0.1 * global_ambient_mul)
           }
        }
     #if (Act = 0) // High actuator
        union {
           superellipsoid {
              <0.05, 0.05>
              scale <4, 0.3,1.25>
              translate <-0.8, 0.5+4.5+0.3, 0>
              }
           box {
              <-3.9,0,-1.25> <1,0.4,+1.25>
              rotate +4*z
              translate <-0.8, 0.5+4.5+0.5, 0>
              }
           box {
              <+3.9,0,-1.25> <1,0.4,+1.25>
              rotate -4*z
              translate <-0.8, 0.5+4.5+0.5, 0>
              }
           difference {
              superellipsoid {
                 <0.05, 0.05>
                 scale <1.2, 0.4,1.25>
                 }
              cylinder {
                 <0,0.2,0> <0,0.5,0> 0.5
                 }
              translate <-0.8, 0.5+4.5+0.6+0.2+0.2, 0>
              }
           box {
              <-1.5,3.5,-1.2> <+1.5,4,+1.2>
              }
           pigment {
              Red
              }
           finish {
              diffuse 0.5
              specular 0.5
              ambient (0.1 * global_ambient_mul)
              }
           }
     #else // low actuator
        union {
           superellipsoid {
              <0.05, 0.05>
              scale <4, 0.4,1.25>
              translate <-0.8, 0.5+4.5+0.4, 0>
              }
           difference {
              superellipsoid {
                 <0.05, 0.05>
                 scale <1.2, 1.05,1.25>
                 }
              cylinder {
                 <0,0.9,0> <0,1.1,0> 0.5
                 }
              translate <-0.8, 0.5+4.5+1.05, 0>
              }
           box {
              <-1.5,3.5,-1.2> <+1.5,4,+1.2>
              }
           pigment {
              Gray15
              }
           finish {
              diffuse 0.5
              specular 0.5
              ambient (0.1 * global_ambient_mul)
              }
           }
     #end
     #if (Cnx = 0) // Straight connection
        #local pin = union {
           cylinder {
              <0, -5, 0> <0, 1, 0> 0.3
              }
           sphere {
              <0,-5,0> 0.3
              }
           texture {
              col_gold
              }
           }
     #else
        #local pin = union {
           cylinder {
              <0, -0.4, 0> <0, 1, 0> 0.3
              }
           cylinder {
              <0, -0.7, 0.4> <0, -0.7, 4.45> 0.3
              }
           sphere {
              <0,-0.7,4.45> 0.3
              }
           intersection {
              torus {
                 0.4 0.3
                 rotate < 0, 0, 90>
                 }
              box {
                 < -0.3, -0, 0> <+0.3, -2, -2>
                 }
              translate < 0, -0.3, +0.4>
              }
           texture {
              col_gold
              }
           }
     #end
     #for(i,0,2)
        object {
           pin
           translate < -(3-1)*2.54/2+i*2.54, 0, 0>
           }
     #end

     rotate 180 * y
     #if (Cnx = 1)
        rotate -90*x
        translate <0,1.25,-1.2>
     #end
     }
#end

// Straight connection - Low actuator
#macro SWITCH_THT_SECME_1K2_SL()
  SECME1K2_BASE(0,0,0)
#end

// Straight connection - High actuator
#macro SWITCH_THT_SECME_1K2_SH()
  SECME1K2_BASE(0,1,0)
#end

// Right-angled connection - Low actuator
#macro SWITCH_THT_SECME_1K2_RL()
  SECME1K2_BASE(1,0,0)
#end

// Right-angled connection - High actuator
#macro SWITCH_THT_SECME_1K2_RH()
  SECME1K2_BASE(1,1,0)
#end

// Straight connection - Low actuator
#macro SWITCH_THT_SECME_1K2_SLB()
  SECME1K2_BASE(0,0,1)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SWITCH_THT_SECME_1K2_SH(:THT Switch 1K2
//=SWITCH_THT_SECME_1K2_SL(:THT Switch 1K2
//=SWITCH_THT_SECME_1K2_SLB(:THT Switch 1K2
//=SWITCH_THT_SECME_1K2_RH(:THT Switch 1K2
//=SWITCH_THT_SECME_1K2_RL(:THT Switch 1K2
// end assignment
