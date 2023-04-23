/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Vishay Wirewound, Industrial Power, Aluminum Housed and Chassis Mount
 * resistors; RH/NH series
 * params
 *  - Type  see examples below
 *  - A..P  as per datasheet
 * rewritten from scratch, 22.04.2023, wk
 ******************************************************************************/
#macro RES_RHxxx_BASE(value,Type, A, B, C, D, E, F, G, H, J, K, L, M, N, P)
  union {
     #local cd = 0.8;
     #local dconn = 1.0;
     #if (Type = "DALE RH-10 10W")
        #local cd = 1.0;
        #local dconn = 1.6;
     #end
     #if (Type = "DALE RH-25 25W")
        #local cd = 1.5;
        #local dconn = 2.0;
     #end
     #if (Type = "DALE RH-50 50W")
        #local cd = 1.5;
        #local dconn = 2.0;
     #end
     #if (Type = "DALE RH-100 100W")
        #local cd = 3.0;
     #end
     #if (Type = "DALE RH-250 250W")
        #local cd = 4.5;
     #end
     difference {
        union {
           prism {
              -C/2, +C/2,
              27
              <   +E/2, 0.00>,  // first point
              <   +E/2, H>,
              <-cd+E/2, H>,
              <-cd+E/2, J>,
              <-cd+E/2, J>,
              <-cd+E/2 * 0.98, J + 1 * (G-J)/8>,
              <-cd+E/2 * 0.96, J + 2 * (G-J)/8>,
              <-cd+E/2 * 0.94, J + 3 * (G-J)/8>,
              <-cd+E/2 * 0.92, J + 4 * (G-J)/8>,
              <-cd+E/2 * 0.88, J + 5 * (G-J)/8>,
              <-cd+E/2 * 0.83, J + 6 * (G-J)/8>,
              <-cd+E/2 * 0.75, J + 7 * (G-J)/8>,
              <-cd+E/2 * 0.62, J + 8 * (G-J)/8>,
              <+cd-E/2 * 0.62, J + 8 * (G-J)/8>,
              <+cd-E/2 * 0.75, J + 7 * (G-J)/8>,
              <+cd-E/2 * 0.83, J + 6 * (G-J)/8>,
              <+cd-E/2 * 0.88, J + 5 * (G-J)/8>,
              <+cd-E/2 * 0.92, J + 4 * (G-J)/8>,
              <+cd-E/2 * 0.94, J + 3 * (G-J)/8>,
              <+cd-E/2 * 0.96, J + 2 * (G-J)/8>,
              <+cd-E/2 * 0.98, J + 1 * (G-J)/8>,
              <+cd-E/2, J>,
              <+cd-E/2, J>,
              <+cd-E/2, H>,
              <   -E/2, H>,
              <   -E/2, 0.00>,
              <   +E/2, 0.00>  // first point
              rotate <-90,90,0>
              }
           intersection {
              union {
                 object { GRID(Round_Box(<-C/2-1,-cd/2,-cd> <+C/2+1,+cd/2,+cd>, 0.3, 0), E*0.75, 1,2) translate <0,-cd/2 + H + 2*(G-H)/10,0> }
                 object { GRID(Round_Box(<-C/2-1,-cd/2,-cd> <+C/2+1,+cd/2,+cd>, 0.3, 0), E*0.72, 1,2) translate <0,-cd/2 + H + 4*(G-H)/10,0> }
                 object { GRID(Round_Box(<-C/2-1,-cd/2,-cd> <+C/2+1,+cd/2,+cd>, 0.3, 0), E*0.68, 1,2) translate <0,-cd/2 + H + 6*(G-H)/10,0> }
                 object { GRID(Round_Box(<-C/2-1,-cd/2,-cd> <+C/2+1,+cd/2,+cd>, 0.3, 0), E*0.62, 1,2) translate <0,-cd/2 + H + 8*(G-H)/10,0> }
                 object { GRID(Round_Box(<-C/2-1,-cd/2,-cd> <+C/2+1,+cd/2,+cd>, 0.3, 0), E*0.52, 1,2) translate <0,-cd/2 + H + 10*(G-H)/10,0> }
                 }
              box {
                 <-C/2,    0,-E/2>
                 <+C/2,G+0.1,+E/2>
                 }
              #if (Type = "DALE RH-100 100W")
                 scale <1,1,1.15>
              #end
              #if (Type = "DALE RH-250 250W")
                 scale <1,1,1.1>
              #end
              }
           #if (Type = "DALE RH-250 250W")
              Round_Box(
                 <+22.23-C/2,0,+F/2>
                 <+22.23-C/2+2*K,H,0>
                 0.3, 0
                 )
              Round_Box(
                 <-22.23+C/2,0,-F/2>
                 <-22.23+C/2-2*K,H,0>
                 0.3, 0
                 )
           #end
           Round_Box(
              <-C/2,0,-F/2>
              <-C/2+2*K,H,0>
              0.3, 0
              )
           Round_Box(
              <+C/2,0,+F/2>
              <+C/2-2*K,H,0>
              0.3, 0
              )

           #if ((Type = "DALE RH-100 100W") | (Type = "DALE RH-250 250W"))
              #local ds = 5.4;

              #if (Type = "DALE RH-250 250W")
                 #local ds = 6.35;
              #end

              object {
                 TOOLS_SCREW(5,D/2,1,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <0,J,0>
                 }
              object {
                 TOOLS_SCREW(5,D/2,1,Silver)
                 scale ds/5.0
                 rotate <0,0,-90>
                 translate <0,J,0>
                 }
              object {
                 TOOLS_NUT(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <-C/2-3,J,0>
                 }
              object {
                 TOOLS_NUT(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <-C/2-10,J,0>
                 }
              object {
                 TOOLS_NUT(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <+C/2+6,J,0>
                 }
              object {
                 TOOLS_NUT(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <+C/2+13,J,0>
                 }
              object {
                 TOOLS_WASHER(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <-C/2-7.5,J,0>
                 }
              object {
                 TOOLS_WASHER(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <-C/2-8.5,J,0>
                 }
              object {
                 TOOLS_WASHER(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <+C/2+7.5,J,0>
                 }
              object {
                 TOOLS_WASHER(5,0,Silver)
                 scale ds/5.0
                 rotate <0,0,90>
                 translate <+C/2+8.5,J,0>
                 }
           #else
              union {
                 cylinder {
                    <-(D-5.5*N)/2,J,0>
                    <+(D-5.5*N)/2,J,0>
                    dconn/2
                    }
                 Round_Box(
                    <-D/2    ,J-N,+dconn/4>
                    <-D/2+3*N,J+N,-dconn/4>
                    dconn/8, 0
                    )
                 Round_Box(
                    <+D/2    ,J-N,+dconn/4>
                    <+D/2-3*N,J+N,-dconn/4>
                    dconn/8, 0
                    )
                 texture {
                    col_silver
                    }
                 }
           #end
           }
        cylinder {
           <-C/2-0.1,J,0>
           <+C/2+0.1,J,0>
           (J-H)
           }
        cylinder {
           <-A/2,-0.1,-B/2>
           <-A/2,H+0.1,-B/2>
           L/2
           }
        cylinder {
           <+A/2,-0.1,+B/2>
           <+A/2,H+0.1,+B/2>
           L/2
           }
        #if (Type = "DALE RH-250 250W")
           cylinder {
              <+A/2-22.23,-0.1,-B/2>
              <+A/2-22.23,H+0.1,-B/2>
              L/2
              }
           cylinder {
              <-A/2+22.23,-0.1,+B/2>
              <-A/2+22.23,H+0.1,+B/2>
              L/2
              }
        #end
        cylinder {
           <-D/2+N/2+1,J,-2>
           <-D/2+N/2+1,J,+2>
           N/2
           }
        cylinder {
           <+D/2-N/2-1,J,-2>
           <+D/2-N/2-1,J,+2>
           N/2
           }

        pigment {
          P_Brass4
          }
        finish {
           diffuse 0.8
           ambient (0.1 * global_ambient_mul)
           }
        }
     cylinder {
        <-C/2+0.1,J,0>
        <+C/2-0.1,J,0>
        (J-H)
        pigment {
           Gray30
           }
        }
     text {
        ttf besch_font Type 1 0
        scale 1.5
        #if ((Type = "DALE RH-100 100W") | (Type = "DALE RH-250 250W"))
           scale 5
           translate <10,5,0>
        #end
        rotate <90,0,0>
        translate <-C/2+1.5,G+0.1,+1.0>
        pigment {
           Black
           }
        }
     text {
        ttf besch_font value 1 0
        scale 1.5
        #if (Type = "DALE RH-100 100W")
           scale 5
           translate <10,-5,0>
        #end
        #if (Type = "DALE RH-250 250W")
           scale 5
           translate <10,-5,0>
        #end

        rotate <90,0,0>
        translate <-C/2+1.5,G+0.1,-1.5>
        pigment {
           Black
           }
        }
     }
#end


#macro RES_THT_RH005(value)
  RES_RHxxx_BASE(value, "DALE RH-5 5W", 11.28, 12.45, 15.24, 28.58, 8.48, 16.41, 8.13, 1.65, 3.56, 1.98, 2.36, 1.98, 1.27, 6.76)
#end

#macro RES_THT_RH010(value)
  RES_RHxxx_BASE(value, "DALE RH-10 10W", 14.27, 15.88, 19.05, 34.93, 10.67, 20.32,  9.91, 1.91, 4.19, 2.36, 2.39, 2.59, 2.16, 7.92)
#end

#macro RES_THT_RH025(value)
  RES_RHxxx_BASE(value, "DALE RH-25 25W", 18.26, 19.84, 26.97, 49.23, 13.97, 27.43, 13.87, 1.91, 5.87, 4.37, 3.18, 2.92, 2.16, 11.13)
#end

#macro RES_THT_RH050(value)
  RES_RHxxx_BASE(value, "DALE RH-50 50W", 39.67, 21.44, 49.99, 70.64, 16.00, 28.96, 15.49, 2.24, 6.60, 4.98, 3.18, 2.72, 2.16, 11.13)
#end

#macro RES_THT_RH100(value)
  RES_RHxxx_BASE(value, "DALE RH-100 100W", 69.85, 57.15, 88.90, 139.14, 46.02, 71.42, 44.45, 4.78, 19.56, 9.52, 4.78, (57.15-46.02)/2, 2.16, 25.12)
#end

#macro RES_THT_RH250(value)
  RES_RHxxx_BASE(value, "DALE RH-250 250W", 98.42, 63.50, 114.30, 177.80, 53.98, 76.20, 55.58, 6.35, 24.26, 7.92, 4.78, (63.50-53.98)/2, 2.16, 31.75) 
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=RES_THT_RH005(:RH series power resistor
//=RES_THT_RH010(:RH series power resistor
//=RES_THT_RH025(:RH series power resistor
//=RES_THT_RH050(:RH series power resistor
//=RES_THT_RH100(:RH series power resistor
//=RES_THT_RH250(:RH series power resistor
// end assignment
