/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Panasonic Relay DK1a-L2
 * Uwe Lorenz <u.lorenz@er-dresden.net>
 * *****************************************************************************/
#macro SPC_RELAY_DK1A_L2()
  union {
     // Loetstift
     cylinder {
        <-3.76,-3.5,-11.5> <-3.76,1.1,-11.5> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,-11.5> <3.76,1.1,-11.5> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <-3.76,-3.5,-8.96> <-3.76,1.1,-8.96> 0.3
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,-8.96> <3.76,1.1,-8.96> 0.3
        texture {
           col_silver
           }
        }
     //
     cylinder {
        <-3.76,-3.5,11.5> <-3.76,1.1,11.5> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,11.5> <3.76,1.1,11.5> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <-3.76,-3.5,3.88> <-3.76,1.1,3.88> 0.5
        texture {
           col_silver
           }
        }
     cylinder {
        <3.76,-3.5,3.88> <3.76,1.1,3.88> 0.5
        texture {
           col_silver
           }
        }
     //  Ende Loetstifte


     difference { // Grundkoerper
        box {
           <-6.25,0.5,-12.5> <6.25,12.0,12.5>
           }
        box {
           <-2.0,10.8,8.5> <2.0,12.1,12.6>
           }
        }

     box {
        <-6.25,0.0,-6.5> <-6.25,0.5,-5.0>
        }
     box {
        <6.25,0.0,-6.5> <6.25,0.5,-5.0>
        }
     box {
        <-6.25,0.0,7.5> <-6.25,0.5,6.0>
        }
     box {
        <6.25,0.0,7.5> <6.25,0.5,6.0>
        }
     cylinder {
        <0.0,10.7,10.5> <0.0,11.5,10.5> 1.0
        }
     //
     text {
        ttf besch_font "NAIS" 0, 0
        pigment {
           Gray80
           }
        scale<4,4,4> rotate<90,-90,0>
        translate<-1.5,12.05,-10>
        }
     text {
        ttf besch_font "DK1a-L2-5V" 0, 0
        pigment {
           Gray80
           }
        scale<2,2,2> rotate<90,-90,0>
        translate<1.5,12.05,-10>
        }
     text {
        ttf besch_font "ADE129" 0, 0
        pigment {
           Gray80
           }
        scale<1,1,1> rotate<90,-90,0>
        translate<3.0,12.05,-10>
        }
     text {
        ttf besch_font "10A250V~(COS°=1.0)" 0, 0
        pigment {
           Gray80
           }
        scale<1,1,1> rotate<90,-90,0>
        translate<4.0,12.05,-10>
        }
     text {
        ttf besch_font "SPULE:5V=" 0, 0
        pigment {
           Gray80
           }
        scale<1,1,1> rotate<90,-90,0>
        translate<5.0,12.05,-10>
        }
     text {
        ttf besch_font "JAPAN" 0, 0
        pigment {
           Gray80
           }
        scale<2,2,2> rotate<90,-90,0>
        translate<-3.4,12.05,5>
        }
     pigment {
        Gray20
        }
     translate<0,0.2,0>
     }
#end



/*******************************************************************************
 * Panasonic JJ-M RELAYS
 * Emil Crisbaseanu <emilcrisba(at)gmail.com>
 * for the free use and viewing pleasure
 * *****************************************************************************/
#macro SPC_RELAY_JJM_BASE(value,dual)
  // case supports
  #macro CUTS(xa,za)
     prism {
        linear_sweep linear_spline
        0
        0.5
        5
        <-1,0>, <-0.6,0.4>, <0.6,0.4>, <1,0>, <-1,0>
        rotate <90,0,0>
        translate<xa,0.40,za>
        }
  #end

  // pins
  #macro PIN_REL(xp,zp,dx,dz)
     union {
        box {
           <xp-(dx/2),-3.2,zp-(dz/2)> <xp+(dx/2),1,zp+(dz/2)>
           }
        prism {
           linear_sweep linear_spline (-dz/2) (dz/2) 5 <(-dx/2),0>, <(dx/2),0>, <(dx/4),0.3>, <(-dx/4),0.3>, <(-dx/2),0> rotate <90,0,0> translate <xp,-3.2,zp>
           }
        texture {
           col_silver
           }
        }
  #end

  union {
     //of case and pins
     union {
        //case
        object {
           CUTS(-4.75,-6.00)
           }
        //legs of case, (botom side)
        object {
           CUTS(+5.75,-6.00)
           }
        object {
           CUTS(-4.75,+5.50)
           }
        object {
           CUTS(+5.75,+5.50)
           }
        difference {
           #local L = 15;   //on x
           #local W = 12;   //on z
           #local H = 27.8; //on y

           superellipsoid { //top box of case
              <0.06,0.06>
              scale<L/2,H/2,W/2>
              }           
           box { //low cut
              <-7.8,-14,-6.1> <7.8,0.4,6.1>
              }
           box { //low inner cut
              <-7.00,-0.1,-5.50> <7.00,+0.60,5.50>
              }
           box { //top box cut
              <4.4,13.8,-1.3> <6,14,1.3>
              }
           sphere { //top central round cut
              <0,15,0> 1.5
              }
           }
        pigment { //case pigment
           color <1,0.6,0.2>
           }
        finish {
           phong 0.5
           }
        }
     object {
        PIN_REL(-6,5,1,0.400)
        }
     object {
        PIN_REL(4,5,1,0.300)
        }
     object {
        PIN_REL(4,-5,1,0.300)
        }
     object {
        PIN_REL(0,0,1.20,0.300)
        rotate<0,90,0> translate<6.5,0,0>
        }

     #if (dual=1)
        object {
           PIN_REL(-6,-5,1,0.400)
           }
     #end

     text {
        ttf besch_font value 0.1, 0
        pigment {
           White
           }
        scale 1.5 rotate<90,180,0> translate<6,13.92,5>
        }
     text { //NAiS LOGO
        ttf global_fontfile_eagle3d "," 0.1, 0
        pigment {
           White
           }
        scale 1.5 rotate<90,180,0> translate<6,13.92,-3.5>
        }
     }
#end

#macro SPC_RELAY_JJM_1A(value)
  SPC_RELAY_JJM_BASE(value, 0)
#end

#macro SPC_RELAY_JJM_1C(value)
  SPC_RELAY_JJM_BASE(value, 1)
#end

#macro SPC_RELAY_JJM_2W(value)
  SPC_RELAY_JJM_BASE(value, 1)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_RELAY_DK1A_L2(:Panasonic Relay DK1a-L2
//=JJM_REL_TYPE_2W(:Panasonic Relay JJM2W-12V
//=JJM_REL_TYPE_1C(:Panasonic Relay JJM1C-12V
//=JJM_REL_TYPE_1A(:Panasonic Relay JJM1A-12V
// end assignment
