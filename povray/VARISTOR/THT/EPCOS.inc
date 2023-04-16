/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * EPCOS THT metal oxide varistor, SIOV Series
 * Philippe Boucheny <philippe.boucheny(at)free.fr>
 * Rev. 1.0  14/01/06
 * rewrite, 16.04.2023, wk
 *
 * For params
 *   - e,a,b,s,h,l,d -> see epcos datasheet.
 ******************************************************************************/
#macro EPSON_VARISTOR_SIOV_BASE(value,e,a,b,s,h,l,d)
  union {
     union {
        superellipsoid {<1.0, 0.6> scale <b/2,b/2,s/2> }
        intersection {
           superellipsoid {
              <1.0, 0.6>
              scale <b/2,b/2,s/2+0.01>
              }
           union {
              text {
                 ttf global_fontfile_arial value 1, 0
                 translate <-2,+1,-s/2>
                 }
              text {
                 ttf global_fontfile_eagle3d ">" 1, 0
                 scale 2
                 translate <-3,-1.5,-s/2>
                 }
              text {
                 ttf global_fontfile_eagle3d "AG" 1, 0
                 translate <0.5,-1,-s/2>
                 }
              text {
                 ttf global_fontfile_arial "9235" 1, 0
                 translate <-1,-2.5,-s/2>
                 }
              scale <b/9,b/9,1>
              }
           pigment {
              White
              }
           }
        sphere {
           <+e/2,+b/2-h+d/2,-a/2> (s/2-a/2)/2
           }
        sphere {
           <-e/2,+b/2-h+d/2,+a/2> (s/2-a/2)/2
           }

        #if(b=7)
           cone {
              <+e/3,-b/4,-a/3> (s/2-a/2) <+e/2,+b/2-h+d/2,-a/2> (s/2-a/2)/2
              }
           cone {
              <-e/3,-b/4,+a/3> (s/2-a/2) <-e/2,+b/2-h+d/2,+a/2> (s/2-a/2)/2
              }
        #else
           sphere {
              <+e/2,-b/4,-a/3> (s/2-a/2)
              }
           cone {
              <+e/2,-b/4,-a/3> (s/2-a/2) <+e/2,+b/2-h+d/2,-a/2> (s/2-a/2)/2
              }
           sphere {
              <-e/2,-b/4,+a/3> (s/2-a/2)
              }
           cone {
              <-e/2,-b/4,+a/3> (s/2-a/2) <-e/2,+b/2-h+d/2,+a/2> (s/2-a/2)/2
              }
        #end
        texture {
           pigment {
              color red 0.17 green 0.24 blue 0.88
              }
           finish {
              ambient (0.3 * global_ambient_mul)
              diffuse 0.7
              specular 0.4
              }
           }
        }

     #if(pin_short=off)
        cylinder {
           <+e/2,+b/2-h+d/2,-a/2><+e/2,+b/2-h-l,-a/2> d/2
           texture {
              col_silver
              }
           }
        cylinder {
           <-e/2,+b/2-h+d/2,+a/2><-e/2,+b/2-h-l,+a/2> d/2
           texture {
              col_silver
              }
           }
     #else
        cylinder {
           <+e/2,+b/2-h+d/2,-a/2><+e/2,+b/2-h-1*(pcb_height+pin_length)-0.2,-a/2> d/2
           texture {
              col_silver
              }
           }
        cylinder {
           <-e/2,+b/2-h+d/2,+a/2><-e/2,+b/2-h-1*(pcb_height+pin_length)-0.2,+a/2> d/2
           texture {
              col_silver
              }
           }
     #end

     translate <0,h-b/2,0>
     }
#end


// To add a missing SIOV varistor, copy parameters from EPCOS datasheet.
// They are in the same order.

// copy && paste from datasheet - too many different otherwise.               e,   a,    b,    s,    h,    l,   d
#macro VARISTOR_THT_B72205S0110K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  7.0,  3.3,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0110K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  9.0,  3.4, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0110K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.4, 12.0,  4.0, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0110K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.4, 15.5,  4.0, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0110K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.5, 21.5,  4.5, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0140K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  7.0,  3.4,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0140K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  9.0,  3.5, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0140K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 12.0,  4.2, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0140K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 15.5,  4.2, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0140K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.6, 21.5,  4.6, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0170K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.4,  7.0,  3.5,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0170K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.4,  9.0,  3.6, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0170K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.6, 12.0,  4.4, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0170K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.7, 15.5,  4.4, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0170K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.8, 21.5,  4.8, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0200K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  7.0,  3.5,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0200K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  9.0,  3.6, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0200K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.8, 12.0,  4.5, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0200K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.9, 15.5,  4.6, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0200K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.1, 21.5,  5.1, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0250K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  7.0,  3.6,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0250K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  9.0,  3.7, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0250K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.6, 12.0,  4.2, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0250K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.7, 15.5,  4.2, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0250K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.8, 21.5,  4.7, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0300K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.5,  7.0,  3.6,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0300K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.5,  9.0,  3.7, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0300K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.7, 12.0,  4.4, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0300K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.8, 15.5,  4.4, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0300K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.0, 21.5,  4.9, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0350K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.6,  7.0,  3.7,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0350K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.6,  9.0,  3.9, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0350K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.8, 12.0,  4.4, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0350K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 15.5,  4.5, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0350K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.2, 21.5,  5.1, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0400K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  7.0,  3.9,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0400K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  9.0,  4.1, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0400K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.1, 12.0,  4.8, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0400K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.2, 15.5,  4.9, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0400K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.4, 21.5,  5.4, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0500K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  7.0,  3.3,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0500K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  9.0,  3.3, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0500K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.4, 12.0,  3.9, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0500K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.4, 15.5,  3.9, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0500K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.5, 21.5,  4.3, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0600K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  7.0,  3.3,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0600K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.2,  9.0,  3.3, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0600K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.4, 12.0,  4.0, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0600K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 15.5,  4.0, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0600K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.6, 21.5,  4.4, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0750K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  7.0,  3.4,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0750K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  9.0,  3.6, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0750K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 12.0,  4.2, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0750K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 15.5,  4.2, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0750K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.6, 21.5,  4.6, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0950K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  7.0,  3.4,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0950K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.3,  9.0,  3.4, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0950K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 12.0,  4.0, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0950K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.5, 15.5,  4.0, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0950K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.6, 21.5,  4.5, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0111K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.5,  7.0,  3.6,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0111K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.5,  9.0,  3.6, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0111K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.6, 12.0,  4.2, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0111K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.7, 15.5,  4.2, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0111K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 1.8, 21.5,  4.6, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0131K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.6,  7.0,  3.6,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0131K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.6,  9.0,  3.6, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0131K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.8, 12.0,  4.2, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0131K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.9, 15.5,  4.2, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0131K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.0, 21.5,  4.7, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0141K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.7,  7.0,  3.7,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0141K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.7,  9.0,  3.7, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0141K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 1.9, 12.0,  4.3, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0141K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 15.5,  4.3, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0141K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.1, 21.5,  4.8, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0151K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  7.0,  3.8,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0151K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  9.0,  3.8, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0151K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 12.0,  4.4, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0151K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.1, 15.5,  4.4, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0151K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.2, 21.5,  4.9, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0171K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.0,  7.0,  3.9,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0171K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.0,  9.0,  4.0, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0171K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.2, 12.0,  4.6, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0171K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.2, 15.5,  4.6, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0171K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.3, 21.5,  5.0, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0231K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  7.0,  4.0,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0231K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  9.0,  4.0, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0231K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 12.0,  4.7, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0231K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 15.5,  4.7, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0231K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.1, 21.5,  5.1, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0251K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  7.0,  4.2,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0251K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 1.8,  9.0,  4.2, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0251K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 12.0,  4.8, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0251K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.0, 15.5,  4.8, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0251K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.2, 21.5,  5.3, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0271K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.0,  7.0,  4.3,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0271K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.0,  9.0,  4.4, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0271K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.2, 12.0,  5.0, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0271K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.2, 15.5,  5.0, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0271K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.3, 21.5,  5.4, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0301K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.1,  7.0,  4.5,  8.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0301K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.1,  9.0,  4.5, 11.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0301K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.3, 12.0,  5.1, 14.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0301K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.3, 15.5,  5.2, 18.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0301K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.4, 21.5,  5.6, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72210S0321K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.4, 12.0,  5.4, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0321K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.4, 15.5,  5.4, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0321K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.6, 21.5,  5.8, 25.5, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0381K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.5,  7.0,  5.1,  9.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0381K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.5,  9.0,  5.2, 11.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0381K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.7, 12.0,  5.8, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0381K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.7, 15.5,  5.9, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0381K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 2.8, 21.5,  6.3, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0421K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.8,  7.0,  5.4,  9.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0421K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.8,  9.0,  5.4, 11.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0421K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.9, 12.0,  6.1, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0421K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 2.9, 15.5,  6.1, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0421K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 3.1, 21.5,  6.5, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0441K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.8,  7.0,  5.5,  9.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0441K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 2.8,  9.0,  5.5, 11.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0441K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.0, 12.0,  6.2, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0441K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.0, 15.5,  6.3, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0441K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 3.1, 21.5,  6.7, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72205S0461K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 3.0,  7.0,  5.7,  9.0, 25.0, 0.6) #end
#macro VARISTOR_THT_B72207S0461K101(value) EPSON_VARISTOR_SIOV_BASE(value,  5.0, 3.0,  9.0,  5.7, 11.5, 25.0, 0.6) #end
#macro VARISTOR_THT_B72210S0461K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.1, 12.0,  6.3, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0461K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.1, 15.5,  6.4, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0461K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 3.3, 21.5,  6.8, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72210S0511K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.4, 12.0,  6.7, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0511K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.4, 15.5,  6.8, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0511K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 3.5, 21.5,  7.1, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72210S0551K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.7, 12.0,  7.1, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0551K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 3.7, 15.5,  7.2, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0551K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 3.9, 21.5,  7.5, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72210S0621K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 4.0, 12.0,  7.5, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0621K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 4.0, 15.5,  7.5, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0621K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 4.2, 21.5,  7.9, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72210S0681K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 4.4, 12.0,  7.9, 15.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72214S0681K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 4.4, 15.5,  8.0, 19.0, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0681K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 4.5, 21.5,  8.4, 26.0, 25.0, 1.0) #end
#macro VARISTOR_THT_B72214S0102K101(value) EPSON_VARISTOR_SIOV_BASE(value,  7.5, 6.7, 15.5, 11.0, 20.5, 25.0, 0.8) #end
#macro VARISTOR_THT_B72220S0102K101(value) EPSON_VARISTOR_SIOV_BASE(value, 10.0, 6.9, 21.5, 11.4, 28.5, 25.0, 1.0) #end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=VARISTOR_THT_B72205S0110K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0110K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0110K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0110K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0110K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0140K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0140K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0140K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0140K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0140K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0170K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0170K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0170K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0170K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0170K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0200K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0200K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0200K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0200K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0200K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0250K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0250K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0250K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0250K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0250K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0300K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0300K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0300K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0300K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0300K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0350K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0350K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0350K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0350K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0350K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0400K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0400K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0400K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0400K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0400K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0500K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0500K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0500K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0500K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0500K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0600K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0600K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0600K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0600K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0600K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0750K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0750K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0750K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0750K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0750K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0950K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0950K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0950K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0950K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0950K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0111K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0111K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0111K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0111K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0111K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0131K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0131K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0131K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0131K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0131K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0141K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0141K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0141K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0141K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0141K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0151K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0151K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0151K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0151K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0151K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0171K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0171K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0171K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0171K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0171K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0231K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0231K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0231K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0231K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0231K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0251K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0251K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0251K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0251K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0251K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0271K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0271K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0271K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0271K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0271K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0301K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0301K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0301K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0301K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0301K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0321K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0321K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0321K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0381K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0381K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0381K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0381K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0381K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0421K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0421K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0421K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0421K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0421K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0441K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0441K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0441K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0441K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0441K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72205S0461K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72207S0461K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0461K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0461K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0461K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0511K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0511K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0511K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0551K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0551K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0551K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0621K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0621K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0621K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72210S0681K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0681K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0681K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72214S0102K101(:THT varistor EPSON SIOV series
//=VARISTOR_THT_B72220S0102K101(:THT varistor EPSON SIOV series
// end assignment
