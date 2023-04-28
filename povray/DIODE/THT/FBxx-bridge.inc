/*******************************************************************************
*  Eagle3D - generates 3d images from Eagle PCB board files.
*
*  See the README file for copyright information and how to reach the author.
 * *****************************************************************************/

/*******************************************************************************
 * full bridge rectifier
 * Thomas Wirtgen  29.10.2006   V1.0
 * Arguments:
 *    - value1 text (value from Eagle)
 *    - value2 : second text line
 *    - outer1 : outer dimensions x,y,z - left,bottom,back
 *    - outer2 : outer dimensions x,y,z - right,top,front
 *    - rad    : radius of rounded edges
 *    - tri    : triangle length in x- and y-direction, can also be 0
 *    - t1x    : x-coodinate of terminal 1 ("+")
 *    - t2x    : x-coodinate of terminal 2 ("~1")
 *    - t3x    : x-coodinate of terminal 3 ("~2")
 *    - t4x    : x-coodinate of terminal 4 ("-")
 ******************************************************************************/
#macro FBxx_BASE(value1, value2, outer1, outer2, rad, tri, t1x, t2x, t3x, t4x)
  #local inner1 = outer1 + <rad, rad, rad>;
  #local inner2 = outer2 - <rad, rad, rad>;
  #local outer_size = outer2 - outer1;
  #local outer_center = (outer1 + outer2) / 2;
  #local epsilon = 0.001;

  union {
     cylinder {
        <0, 0, 0> <0, outer_center.y, 0> 0.24*2
        texture {
           pigment {
              color Silver
              }
           }
        translate <t1x, 0, 0>
        }
     cylinder {
        <0, 0, 0> <0, outer_center.y, 0> 0.24*2
        texture {
           pigment {
              color Silver
              }
           }
        translate <t2x, 0, 0>
        }
     cylinder {
        <0, 0, 0> <0, outer_center.y, 0> 0.24*2
        texture {
           pigment {
              color Silver
              }
           }
        translate <t3x, 0, 0>
        }
     cylinder {
        <0, 0, 0> <0, outer_center.y, 0> 0.24*2
        texture {
           pigment {
              color Silver
              }
           }
        translate <t4x, 0, 0>
        }

     #macro frame(z1, T, R)
        merge {
           cylinder {
              <inner1.x, outer1.y, z1> <inner1.x, inner2.y, z1> R
              }
           #if (T)
              // if we have a triangle
              cylinder {
                 <inner2.x, outer1.y, z1> <inner2.x, inner2.y-T, z1> R
                 }
              cylinder {
                 <inner1.x, inner2.y, z1> <inner2.x-T, inner2.y, z1> R
                 }
              cylinder {
                 <inner2.x-T, inner2.y, z1> <inner2.x, inner2.y-T, z1> R
                 }
              sphere {
                 <inner2.x-T, inner2.y, z1> R
                 }
              sphere {
                 <inner2.x, inner2.y-T, z1> R
                 }
           #else
              // no triangle
              cylinder {
                 <inner2.x, outer1.y, z1> <inner2.x, inner2.y, z1> R
                 }
              cylinder {
                 <inner1.x, inner2.y, z1> <inner2.x, inner2.y, z1> R
                 }
              sphere {
                 <inner2.x, inner2.y, z1> R
                 }
           #end
           sphere {
              <inner1.x, inner2.y, z1> R
              }
           }
     #end

     object {
        difference {
           merge {
              frame(inner1.z, tri, rad)
              frame(inner2.z, tri, rad)
              #if (tri)
                 // if we have to cut out a triangle on one side
                 cylinder {
                    <inner1.x, inner2.y, inner1.z> <inner1.x, inner2.y, inner2.z> rad
                    }
                 cylinder {
                    <inner2.x-tri, inner2.y, inner1.z> <inner2.x-tri, inner2.y, inner2.z> rad
                    }
                 cylinder {
                    <inner2.x, inner2.y-tri, inner1.z> <inner2.x, inner2.y-tri, inner2.z> rad
                    }
                 #local dx1 = rad/sqrt(2);
                 #local dy1 = dx1;
                 prism {
                    linear_sweep linear_spline
                    inner1.z, inner2.z, 8+1
                    <outer1.x, outer1.y>
                    <outer1.x, inner2.y>
                    <inner1.x, outer2.y>
                    <inner2.x-tri, outer2.y>
                    <inner2.x-tri+dx1, inner2.y+dy1>
                    <inner2.x    +dx1, inner2.y-tri+dy1>
                    <outer2.x, inner2.y-tri>
                    <outer2.x, outer1.y>
                    <outer1.x, outer1.y>
                    rotate <-90, 0, 0>
                    }
                 prism {
                    linear_sweep linear_spline
                    outer1.z, outer2.z, 5+1
                    <inner1.x, outer1.y>
                    <inner1.x, inner2.y>
                    <inner2.x-tri, inner2.y>
                    <inner2.x, inner2.y-tri>
                    <inner2.x, outer1.y>
                    <inner1.x, outer1.y>
                    rotate <-90, 0, 0>
                    }
              #else
                 cylinder {
                    <inner1.x, inner2.y, inner1.z> <inner1.x, inner2.y, inner2.z> rad
                    }
                 cylinder {
                    <inner2.x, inner2.y, inner1.z> <inner2.x, inner2.y, inner2.z> rad
                    }
                 box {
                    <inner1.x, outer1.y, inner1.z> <inner2.x, outer2.y, inner2.z>
                    }
                 box {
                    <inner1.x, outer1.y, outer1.z> <inner2.x, inner2.y, outer2.z>
                    }
                 box {
                    <outer1.x, outer1.y, inner1.z> <outer2.x, inner2.y, inner2.z>
                    }
              #end
              }
           merge {
              cylinder {
                 <outer1.x+3*rad, + outer1.y, outer1.z-epsilon> <outer1.x+3*rad, + outer1.y, outer2.z+epsilon> rad
                 }
              cylinder {
                 <outer2.x-3*rad, + outer1.y, outer1.z-epsilon> <outer2.x-3*rad, + outer1.y, outer2.z+epsilon> rad
                 }
              box {
                 <outer1.x+3*rad, + outer1.y-rad, outer1.z-epsilon> <outer2.x-3*rad, + outer1.y+rad, outer2.z+epsilon>
                 }
              }
           cutaway_textures
           }
        texture {
           pigment {
              color
              rgb 0.30
              }
           normal {
              bumps 0.2
              scale 0.15
              }
           finish {
              ambient 0.1 diffuse 0.6 brilliance 1.0  ambient (0.1 * global_ambient_mul)
              }
           }
        }

     #local large_font_size = 2 + outer_size.x / 36 * 2;
     #local small_font_size = 2 + outer_size.x / 36 * 1;
     #local large_font_line = large_font_size * 5/4;
     #local small_font_line = small_font_size * 4/3;
     #local t0x = inner1.x + rad * 1.5;
     #local t1y = outer2.y - rad * 1.0 - small_font_size * 1.25;
     #local t3y = outer1.y + rad * 1.0 + large_font_size * 0.25;
     #local t2y = (t1y+t3y) / 2;

     union {
        text {
           ttf besch_font value1 0.1, 0
           scale <small_font_size, small_font_size, 1>
           translate <t0x, t1y, outer1.z-epsilon>
           }
        text {
           ttf besch_font value2 0.1, 0
           scale <small_font_size, small_font_size, 1>
           translate <t0x, t2y, outer1.z-epsilon>
           }
        text {
           ttf besch_font "+" 0.1, 0
           scale <large_font_size, large_font_size, 1>
           translate <t1x, t3y, outer1.z-epsilon>
           }
        text {
           ttf besch_font "~" 0.1, 0
           scale <large_font_size, large_font_size, 1>
           translate <t2x, t3y, outer1.z-epsilon>
           }
        text {
           ttf besch_font "~" 0.1, 0
           scale <large_font_size, large_font_size, 1>
           translate <t3x, t3y, outer1.z-epsilon>
           }
        text {
           ttf besch_font "-" 0.1, 0
           scale <large_font_size, large_font_size, 1>
           translate <t4x, t3y, outer1.z-epsilon>
           }
        pigment {
           color
           rgb 0.95
           }
        }
     }
#end


#macro DIODE_THT_BRIDGE_FB15(value)
  FBxx_BASE(value, "FB15", <-10, +3, -2.5>, <+10, +15, +2.5>, 1, 3.5, -7.6200, 2.5600, -2.5600, 7.6200)
  translate <0,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_FB15A(value)
  FBxx_BASE(value, "FB15A", <-11.7, +3, -2.5>, <+9.4, +15, +2.5>, 1, 3.5, -7.6200, 2.5600, -2.5600, 7.6200)
  translate <0,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_FB32(value)
  FBxx_BASE(value, "FB32", <-16, +3, -3>, <+16, +20, +3>,  0.5, 5, -13.600, -3.5600, 3.2000, 11.4500)
  translate <0,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_FB100(value)
  FBxx_BASE(value, "B40 C 5000/3300", <-6, +3, -3>, <+30, +20, +3>, 0.5, 5, 00.0000, 10.0076, 17.3656, 24.9836)
  translate <-14,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_2KBP(value)
  FBxx_BASE(value, "2KBP", <-9.5, +3, -3.5>, <+9.5, +15, +3.5>, 0.5, 4, 05.7150, 01.9050, -1.9050, -5.7150)
  translate <0,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_2KBB_R(value)
  FBxx_BASE(value, "2KBB-R", <-9.5, +3, -3.5>, <+9.5, +15, +3.5>, 0.5, 3, -7.6200, -2.5600, 2.5600, 7.6200)
  translate <0,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_2KBB(value)
  FBxx_BASE(value, "2KBB", <-9.5, +3, -3.5>, <+9.5, +15, +3.5>, 0.5, 3, -2.5600, -7.6200, 2.5600, 7.6200)
  translate <0,-2.8,0>
#end

#macro DIODE_THT_BRIDGE_SKBB(value)
  FBxx_BASE(value, "SKBB", <-9.5, +3, -2.5>, <+9.5, +15, +2.5>, 0.5, 3.5, -2.5600, 2.5600, -7.6200, 7.6200)
  translate <0,-2.8,0>
#end

#macro DIODE_REC_GBU4(value)
  difference {
     union {
        FBxx_BASE(value, "", <-11, +3, -1.0>, <+11, +21.5, +1.0>, 0.5, 5, 7.6200, -2.5600, 2.5600, -7.6200)
        object {
           FBxx_BASE(value, "GBU4", <-11, +3, -1.0>, <+11, +21.5, +1.0>, 0.5, 5, 7.6200, -2.5600, 2.5600, -7.6200)
           translate <0,0,-0.3>
           }
        }
     cylinder {
        <0,11,+2> <0,11,-2> 1.9
        }
     cylinder {
        <0,13,+2> <0,13,-2> 1.9
        }
     box {
        <-1.9,11,-2> <+1.9,13,+2>
        }
     translate <0,-2.8,0>
     }
#end


/*******************************************************************************
*  no typos below please.
 * *****************************************************************************/
// begin assignment
//rectifier:FB15=DIODE_THT_BRIDGE_FB15(:THT full bridge rectifier
//rectifier:FB15A=DIODE_THT_BRIDGE_FB15A(:THT full bridge rectifier
//rectifier:FB32=DIODE_THT_BRIDGE_FB32(:THT full bridge rectifier
//rectifier:FB100=DIODE_THT_BRIDGE_FB100(:THT full bridge rectifier
//rectifier:2KBP=DIODE_THT_BRIDGE_2KBP(:THT full bridge rectifier
//rectifier:2KBB-R=DIODE_THT_BRIDGE_2KBB_R(:THT full bridge rectifier
//rectifier:2KBB=DIODE_THT_BRIDGE_2KBB(:THT full bridge rectifier
//rectifier:SKBB=DIODE_THT_BRIDGE_SKBB(:THT full bridge rectifier
//rectifier:SKBB=DIODE_THT_BRIDGE_SKBB(:THT full bridge rectifier
//rectifier:GBU4=DIODE_REC_GBU4(:THT full bridge rectifier
//rectifier:GBU4S=DIODE_REC_GBU4(:THT full bridge rectifier
// end assignment
