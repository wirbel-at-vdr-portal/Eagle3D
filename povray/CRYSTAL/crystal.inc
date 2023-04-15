/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * 32.768 Hz Crystal
 * Producer: Abracon
 * Web: www.abracon.com
 * Part: ABM3B
 * Carsten Koegler <koegler(replace with at)ftz-leipzig.de>
 * *****************************************************************************/
#macro SPC_XTAL_ABRACON_ABS13_BASE(value)
  union {
     //Grundkoerper
     difference {
        box {
           <-3.45,0.03,-0.7> <3.45,1.3,0.7>
           }
        box {
           <-3.45,0.03,-0.9> <3.45,1.3,0.9>
           rotate<0,0,45> translate<-4.2,0,0>
           }
        texture {
           pigment {
              White*0.2
              }
           }
        }
     text {
        ttf besch_font value 0.2, 0
        pigment {
           Gray60
           }
        rotate<90,0,0> scale 1.0 translate<-2.3, 1.31,-0.3>
        }
     //Anschlusspads
     box {
        <-0.3,0,-0.21> <0.3,0.4,0.21>
        texture {
           col_silver
           }
        translate<-3.28,0, 0.50>
        }
     box {
        <-0.3,0,-0.21> <0.3,0.4,0.21>
        texture {
           col_silver
           }
        translate<-3.28,0,-0.50>
        }
     box {
        <-0.3,0,-0.21> <0.3,0.4,0.21>
        texture {
           col_silver
           }
        translate< 3.28,0, 0.50>
        }
     box {
        <-0.3,0,-0.21> <0.3,0.4,0.21>
        texture {
           col_silver
           }
        translate< 3.28,0,-0.50>
        }
     }
#end

#macro SPC_XTAL_ABRACON_ABS13(value)
  SPC_XTAL_ABRACON_ABS13_BASE(value)
#end



/*******************************************************************************
 * EPSON SMD-Crystal MA505
 * everyone1@freenet.de
 * *****************************************************************************/
#macro SPC_XTAL_SMD_MA505_BASE(value)
  #macro SPC_XTAL_SMD_MA505_PIN(H,B,T,S,H2,R,rx,ry,rz,tx,ty,tz)
     difference {
        union {
           box {
              < 0, 0 ,-T/2> < B-S, S,T/2>
              }
           difference {
              cylinder {
                 < B-S-0.01, S+0.01, -T/2> <B-S-0.01, S+0.01 ,T/2> S+0.01
                 }
              box {
                 < B-2*S-0.1, S+0.01, -T/2-0.1> < B-S-0.01, S*2+0.1, T/2+0.1>
                 }
              }
           box {
              < B-S, S, -T/2> < B, H-S, T/2>
              }
           difference {
              cylinder {
                 < B-S-0.01, H-S-0.01, -T/2> <B-S-0.01, H-S-0.01 ,T/2> S+0.01
                 }
              box {
                 < B-2*S-0.1, H-S-0.01, -T/2-0.1> < B-S-0.01, H-S*2-0.1, T/2+0.1>
                 }
              }
           box {
              < 0, H-S, -T/2> < B-S, H, T/2>
              }
           translate <-B, 0, 0>
           }
        prism {
           -0.1, B+0.1, 5,
           <-T/2-0.1, H+0.1>, < 0, H+0.1>, < 0, H2+T/4>, <-T/2-0.1, H2-T/4>, <-T/2-0.1, H+0.1>
           rotate<-90, 90, 0>
           #if (R=1)
              scale < 1, 1,-1>
           #end
           }
        texture {
           col_silver
           finish {
              phong 1  ambient (0.1 * global_ambient_mul)
              }
           }
        rotate< rx, ry, rz>
        translate<tx,ty,tz>
        }
  #end

  union {
     SPC_XTAL_SMD_MA505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 1, 0,   0, 0,+6.73, 0, -1.65)
     SPC_XTAL_SMD_MA505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 0, 0,   0, 0,+6.73, 0, +1.65)
     SPC_XTAL_SMD_MA505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 1, 0, 180, 0,-6.73, 0, +1.65)
     SPC_XTAL_SMD_MA505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 0, 0, 180, 0,-6.73, 0, -1.65)
     difference {
        prism {
           -2.6, 2.6, 8,
           <-6.15, 0.3>, < 6.15, 0.3>, < 6.35, 2.0>, < 6.05, 4.7>,
           <-4.35, 4.7>, <-6.35, 2.6>, <-6.35, 2.0>, <-6.15, 0.3>
           rotate<-90, 0, 0>
           }
        prism {
           -7.5, 7.5, 9,
           <-3.0, 0>, < 3.0, 0>, < 3.0, 2.01>, < 2.54, 2.01>, < 2.44, 0.4>,
           <-2.44, 0.4>, <-2.54, 2.01>, <-3.0, 2.01>, <-3.0, 0>
           rotate<-90, 90, 0>
           }
        prism {
           -7.5, 7.5, 9,
           <-3.0, 5.0>, < 3.0, 5.0>, < 3.0, 2.0>, < 2.54, 2.0>, < 2.34, 4.6>,
           <-2.34, 4.6>, <-2.54, 2.0>, <-3.0, 2.0>, <-3.0, 5.0>
           rotate<-90, 90, 0>
           }
        texture {
           pigment {
              Gray20
              }
           }
        }
     text {
        ttf global_fontfile_arial value 0.1,0
        rotate <90,0,0>
        scale <1.8,1,1.8>
        translate <-4, 4.61, 0>
        pigment {
           Gray60
           }
        }
     }
#end

#macro SPC_XTAL_SMD_MA505(value)
  SPC_XTAL_SMD_MA505_BASE(value)
#end



/*******************************************************************************
 * Quarz mit veraenderbarer Hoehe und 4,9mm Pitch
 * basiert auf Modell von Andreas Fecht <info@aftec.de>
 * *****************************************************************************/
#macro SPC_XTAL_5MM_BASE(value,height)
  union {
     cylinder {
        <-3.35,0,0> <-3.35,0.7,0> 2.25
        }
     cylinder {
        <3.35,0,0> <3.35,0.7,0> 2.25
        }
     box {
        <-3.35,0,-2.25> <3.35,0.7,2.25>
        }
     cylinder {
        <-3.35,0.7,0> <-3.35,height,0>2
        }
     cylinder {
        <3.35,0,0> <3.35,height,0>2
        }
     box {
        <-3.35,0,-2> <3.35,height,2>
        }
     torus {
        1.6,0.4
        translate<-3.35,height,0>
        }
     torus {
        1.6,0.4
        translate<3.35,height,0>
        }
     cylinder {
        <-3.35,0,0> <3.35,0,0> 0.4
        translate<0,height,-1.6>
        }
     cylinder {
        <-3.35,0,0> <3.35,0,0> 0.4
        translate<0,height,1.6>
        }
     cylinder {
        <-3.35,height,0> <-3.35,height+0.4,0> 1.6
        }
     cylinder {
        <3.35,height,0> <3.35,height+0.4,0> 1.6
        }
     box {
        <-3.35,height,-1.6> <3.35,height+0.4,1.6>
        }
     #if (pin_short=off)
        cylinder {
           <-2.45,0,0> <-2.45,-12,0> 0.25
           }
        cylinder {
           <+2.45,0,0> <+2.45,-12,0> 0.25
           }
     #else
        cylinder {
           <-2.45,0,0> <-2.45,-1*(pin_length+pcb_height),0> 0.25
           }
        cylinder {
           <+2.45,0,0> <+2.45,-1*(pin_length+pcb_height),0> 0.25
           }
     #end
     #if (height> 5)
        text {
           ttf besch_font value 0.1, 0
           pigment {
              White*0.5
              }
           scale 1.5 translate<-3,height/2,-2.01>
           }
     #else
        text {
           ttf besch_font value 0.1, 0
           pigment {
              White*0.5
              }
           scale 2 rotate<90,0,0> translate<-4,height+0.401,-0.5>
           }
     #end
     texture {
        col_silver
        }
     }
#end

#macro SPC_XTAL_5MM(value,height)
  SPC_XTAL_5MM_BASE(value,height)
#end



/*******************************************************************************
 * Quarz mit veraenderbarer Hoehe und 4,9mm Pitch SMD
 * albi <azihlmann@gmx.net>
 * *****************************************************************************/
#macro SPC_XTAL_5MM_SMD_BASE(value,height)
  union {
     union {
        cylinder {
           <-3.35,0,0> <-3.35,0.7,0> 2.25
           }
        cylinder {
           <3.35,0,0> <3.35,0.7,0> 2.25
           }
        box {
           <-3.35,0,-2.25> <3.35,0.7,2.25>
           }
        cylinder {
           <-3.35,0.7,0> <-3.35,height,0>2
           }
        cylinder {
           <3.35,0,0> <3.35,height,0>2
           }
        box {
           <-3.35,0,-2> <3.35,height,2>
           }
        torus {
           1.6,0.4
           translate<-3.35,height,0>
           }
        torus {
           1.6,0.4
           translate<3.35,height,0>
           }
        cylinder {
           <-3.35,0,0> <3.35,0,0> 0.4
           translate<0,height,-1.6>
           }
        cylinder {
           <-3.35,0,0> <3.35,0,0> 0.4
           translate<0,height,1.6>
           }
        cylinder {
           <-3.35,height,0> <-3.35,height+0.4,0> 1.6
           }
        cylinder {
           <3.35,height,0> <3.35,height+0.4,0> 1.6
           }
        box {
           <-3.35,height,-1.6> <3.35,height+0.4,1.6>
           }
        #if (height> 5)
           text {
              ttf besch_font value 0.1, 0
              pigment {
                 White*0.5
                 }
              scale 1.5 translate<-3,height/2,-2.01>
              }
        #else
           text {
              ttf besch_font value 0.1, 0
              pigment {
                 White*0.5
                 }
              scale 2 rotate<90,0,0> translate<-4,height+0.401,-0.5>
              }
        #end
        texture {
           col_silver
           }
        translate 0.7*y
        }
     box {
        <-5.5,0.01,-2.20> <+5.5,1,2.20>
        pigment {
           White*0.3
           }
        }
     difference {
        box {
           <-6.0,0,-0.35> <+6.0,0.3,+0.35>
           }
        box {
           <-2.25,-0.1,-0.4> <+2.25,0.4,0.4>
           }
        texture {
           col_silver
           }
        }
     }
#end

#macro SPC_XTAL_5MM_SMD(value,height)
  SPC_XTAL_5MM_SMD_BASE(value,height)
#end



/*******************************************************************************
 * Clock crystal 2.5mm Pitch
 * *****************************************************************************/
#macro SPC_XTAL_CLOCK_025MM_BASE(value)
  #if (pin_short=off)
     #local spc_pin_length = -5;
  #else
     #local spc_pin_length = -1*(pin_length+pcb_height);
  #end
  union {
     superellipsoid {
        <1,0.12>
        rotate<90,0,0> scale<1,3,1> translate<0,5,0>
        }
     sphere_sweep {
        linear_spline 4
        <-0.5,2,0>, 0.18
        <-0.5,1.5,0>, 0.18
        <-1.27,0.3,0>, 0.18
        <-1.27,-5,0>, 0.18
        }
     sphere_sweep {
        linear_spline 4
        <0.5,2,0>, 0.18
        <0.5,1.5,0>, 0.18
        <1.27,0.3,0>, 0.18
        <1.27,-5,0>, 0.18
        }
     intersection {
        superellipsoid {
           <1,0.12>
           rotate<90,0,0> scale<1.001,3,1.001> translate<0,5,0> pigment {
              Black
              }
           }
        union {
           text {
              ttf besch_font value 0.5, 0
              pigment {
                 White*0.5
                 }
              rotate<0,0,90> translate<0.5,2.8,-1.1>
              }
           text {
              ttf besch_font value 0.5, 0
              pigment {
                 White*0.5
                 }
              rotate<0,0,90> translate<0.5,2.8,-1.1> rotate<0,180,0>
              }
           }
        }
     texture {
        col_silver
        }
     }
#end

#macro SPC_XTAL_CLOCK_025MM(value)
  SPC_XTAL_CLOCK_025MM_BASE(value)
#end



/*******************************************************************************
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 * Quarz HC49/18 liegend mit 4,9mm Pitch
 * basiert auf Modell von Andreas Fecht <info@aftec.de>
 * *****************************************************************************/
#macro SPC_XTAL_L_BASE(value, buegel, pin3, smd, shift, pinshift)
  union {
     #local height = 13.575;
     union {
        // bodenplatte
        cylinder {
           <-3.35,0,0> <-3.35,0.7,0> 2.25
           }
        cylinder {
           < 3.35,0,0> < 3.35,0.7,0> 2.25
           }
        box {
           <-3.35,0,-2.25> <3.35,0.7,2.25>
           }
        union {
           cylinder {
              <-2.45,-0.1,0> <-2.45,0.1,0>1
              }
           cylinder {
              < 2.45,-0.1,0> < 2.45,0.1,0>1
              }
           pigment {
              Gray30
              }
           }
        // koerper
        cylinder {
           <-3.35,0.7,0> <-3.35,height,0>2
           }
        cylinder {
           < 3.35,0  ,0> < 3.35,height,0>2
           }
        box {
           <-3.35,0,-2> <3.35,height,2>
           }
        //kappe
        torus {
           1.6,0.4
           translate<-3.35,height,0>
           }
        torus {
           1.6,0.4
           translate< 3.35,height,0>
           }
        cylinder {
           <-3.35,0,0> <3.35,0,0> 0.4
           translate<0,height,-1.6>
           }
        cylinder {
           <-3.35,0,0> <3.35,0,0> 0.4
           translate<0,height, 1.6>
           }
        cylinder {
           <-3.35,height,0> <-3.35,height+0.4,0> 1.6
           }
        cylinder {
           < 3.35,height,0> < 3.35,height+0.4,0> 1.6
           }
        box {
           <-3.35,height,-1.6> <3.35,height+0.4,1.6>
           }
        // beschriftung auf der seite
        text {
           ttf besch_font value 0.1, 0
           pigment {
              White*0.5
              }
           scale 1.5 translate<-3,height/3,-2.01>
           }
        rotate<90,0,0>
        translate<0, 2.25, shift>
        }
     #if (smd=0)
        // pin unterteil
        #if  (pin_short=off)
           cylinder {
              <-2.45,0,0> <-2.45,-12,0> 0.2
              translate<0, 0, pinshift>
              }
           cylinder {
              < 2.45,0,0> < 2.45,-12,0> 0.2
              translate<0, 0, pinshift>
              }
        #else
           cylinder {
              <-2.45,0,0> <-2.45,-1*(pin_length+pcb_height),0> 0.2
              translate<0, 0, pinshift>
              }
           cylinder {
              < 2.45,0,0> < 2.45,-1*(pin_length+pcb_height),0> 0.2
              translate<0, 0, pinshift>
              }
        #end
        //pin oberteil
        #declare bends1=array[3] {
           <0, 0.8, 0>,  <90, 1.5, 0>,  <0,2,0>
           }
        object {
           TOOLS_BENTPIPE( 0.2, <0,0,0>, y, bends1 )
           rotate<0,-90,0> translate<-2.45,0,pinshift>
           }
        object {
           TOOLS_BENTPIPE( 0.2, <0,0,0>, y, bends1 )
           rotate<0,-90,0> translate< 2.45,0,pinshift>
           }
        #if (pin3=1)
           cylinder {
              <0, 3, height+shift+0.575> <0, -1*(pin_length+pcb_height), height+shift+0.575> 0.2
              }
        #end
     #else
        //pin 1 und 2
        #declare bends2=array[5] {
           <0,0.8,0>, <-90,0.5,0>, <0, 1, 0>,  <90, 0.5, 0>,  <0,2,0>
           }
        object {
           TOOLS_BENTPIPE( 0.2, <0, 0, 0>, x, bends2 )
           rotate<0,-90,0> translate<-2.45,0.2,pinshift>
           }
        object {
           TOOLS_BENTPIPE( 0.2, <0, 0, 0>, x, bends2 )
           rotate<0,-90,0> translate< 2.45,0.2,pinshift>
           }
        //pin 3
        #declare bends3=array[3] {
           <0, 3, 0>,  <90, 0.5, 0>,  <0,1,0>
           }
        object {
           TOOLS_BENTPIPE( 0.2, <0,0,0>, y, bends3 )
           rotate<0,-90,0> rotate<0,0,180> translate<0,3.7,height+shift+0.575>
           }
     #end
     #if (buegel=1)
        //#declare bends=array[5] {
           <0, 5.5, 0>,  <90, 2.5, 0>,  <0,6.4,0>,  <90,2.5,0>,  <0, 5.5, 0>
           }
        #declare bends=array[5] {
           <0, 5.5, 0>,  <90, 2, 0>,  <0,7.4,0>,  <90,2,0>,  <0, 5.5, 0>
           }
        // <angle, radius, 0> or <0, distance, 0> for straight pipe
        // negative angles bend left, positive bend right.
        object {
           TOOLS_BENTPIPE( 0.25, <-2.25*2.54, -3, 1.5*2.54>, y, bends )
           }
     #end
     texture {
        col_silver
        }
     }
#end

#macro SPC_XTAL_L0(value)
  SPC_XTAL_L_BASE(value, 0, 0, 0, -3.81, -5.08)
#end

#macro SPC_XTAL_L1(value)
  SPC_XTAL_L_BASE(value, 0, 0, 1, -7, -9.1)
#end

#macro SPC_XTAL_L2(value)
  SPC_XTAL_L_BASE(value, 1, 0, 0, -3.81, -5.08)
#end

#macro SPC_XTAL_L3(value)
  SPC_XTAL_L_BASE(value, 0, 1, 0, -6.2, -7.62)
#end

#macro SPC_XTAL_L4(value)
  SPC_XTAL_L_BASE(value, 0, 0, 0, -6.2, -7.62)
#end























/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_XTAL_ABRACON_ABS13(:Abracon SMD Crystal
//=SPC_XTAL_SMD_MA505(:EPSON SMD Quartz
//crystal:HC49/S,HC49U-V,HC49U70,HC18U-V,QS=SPC_XTAL_5MM(:Quartz 4.9mm
//crystal:HC49UP,SM49=SPC_XTAL_5MM_SMD(:Quartz 4.9mm SMD
//crystal:TC26V=SPC_XTAL_CLOCK_025MM(:Clock crystal 2.5mm pitch
//crystal:HC18U-H=SPC_XTAL_L2(:Quartz 4.9mm
//crystal:HC49GW=SPC_XTAL_L1(:Quartz 4.9mm
//crystal:HC49U-H=SPC_XTAL_L0(:Quartz 4.9mm
//crystal:HC49U-LM=SPC_XTAL_L2(:Quartz 4.9mm
//crystal:HC49TL-H=SPC_XTAL_L3(:Quartz 4.9mm
//crystal:Q=SPC_XTAL_L4(:Quartz 4.9mm
// end assignment
