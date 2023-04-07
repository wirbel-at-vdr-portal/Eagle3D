/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * MYRRA EI Transformer
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.0  29/12/05
 ******************************************************************************/
#macro TRAFO_MYRRA_EI_BASE(L,W,H,L1,W1,H1,Lp,Wp,D,Sw,Fx,Pl,Lh)
  #local MyrraBrown = color red 0.7 green 0.3 blue 0.164706;
  #local r = 0.4;     //pin ray

  #if(L1=0)
     #local L1=L/1.2;  //20% if unknown
  #end

  #if(W1=0)
     #local W1=W/1.2;  //20% if unknown
  #end

  #if(H1=0)
     #local H1=H/1.2;  //20% if unknown
  #end

  union {
     difference {
        union {
           difference {
              superellipsoid {
                 <0.06, 0.06>
                 scale <L/2, H1/2+2,W/2>
                 translate <0, H1/2-2, 0>
                 }
              box {
                 <-L/2-1,-4.5,-W/2-1> <+L/2+1,0,+W/2+1>
                 }
              }
           superellipsoid {
              <0.06, 0.06>
              scale <L1/2,H/2,W1/2>
              translate <0, H/2, 0>
              }
           pigment {
              MyrraBrown
              }
           }
        union {
           cylinder {
              <-Lh/2,-1,0> <-Lh/2,10,0> D/2
              }
           cylinder {
              <+Lh/2,-1,0> <+Lh/2,10,0> D/2
              }
           pigment {
              Gray50
              }
           }
        }
     //Pins #1 & 5
     cylinder {
        <-Lp/2,0,-Wp/2> <-Lp/2,-Pl,-Wp/2> r
        texture {
           pigment {
              Silver
              }
           }
        }
     cylinder {
        <+Lp/2,0,-Wp/2> <+Lp/2,-Pl,-Wp/2> r
        texture {
           pigment {
              Silver
              }
           }
        }
     //Pins #7 & 9
     cylinder {
        <-Lp/2+5,0,+Wp/2> <-Lp/2+5,-Pl,+Wp/2> r
        texture {
           pigment {
              Silver
              }
           }
        }
     cylinder {
        <+Lp/2-5,0,+Wp/2> <+Lp/2-5,-Pl,+Wp/2> r
        texture {
           pigment {
              Silver
              }
           }
        }
     #if (Sw = 2)
        //Pins #6 & 10
        cylinder {
           <-Lp/2,0,+Wp/2> <-Lp/2,-Pl,+Wp/2> r
           texture {
              pigment {
                 Silver
                 }
              }
           }
        cylinder {
           <+Lp/2,0,+Wp/2> <+Lp/2,-Pl,+Wp/2> r
           texture {
              pigment {
                 Silver
                 }
              }
           }
     #end

     // Top marking
     union {
        box {
           <-12,H,+2> <+8,H+0.01,+8>
           pigment {
              White
              }
           }
        box {
           <-12+0.3,H+0.01,+2+0.3> <+8-0.3,H+0.02,+8-0.3>
           pigment {
              MyrraBrown
              }
           }
        text {
           ttf global_fontfile_arial "myrra" 0.05, 0
           pigment {
              White
              }
           scale 5
           rotate <90,0,0>
           translate <-10.5,H+0.05,4>
           } // Marking
        text {
           ttf global_fontfile_eagle3d "O" 0.05, 0
           pigment {
              White
              }
           scale 4.5
           rotate <90,0,0>
           translate <-12,H+0.05,-10>
           } // Marking
        text {
           ttf global_fontfile_eagle3d "P" 0.05, 0
           pigment {
              White
              }
           scale 4.5
           rotate <90,0,0>
           translate <-12+5.1,H+0.05,-10>
           } // Marking
        text {
           ttf global_fontfile_eagle3d "Q" 0.05, 0
           pigment {
              White
              }
           scale 4.5
           rotate <90,0,0>
           translate <-12+10.4,H+0.05,-10>
           } // Marking
        text {
           ttf global_fontfile_eagle3d "N" 0.05, 0
           pigment {
              White
              }
           scale 4.5
           rotate <90,0,0>
           translate <-12+15.6,H+0.05,-10>
           } // Marking
        text {
           ttf global_fontfile_eagle3d "I" 0.05, 0
           pigment {
              White
              }
           scale 5
           rotate <90,0,0>
           translate <+2,H+0.08,-4>
           } // RU Marking
        text {
           ttf global_fontfile_eagle3d "B" 0.05, 0
           pigment {
              White
              }
           scale 5
           rotate <90,0,0>
           translate <-4.5,H+0.08,-4>
           } // DVE Marking
        text {
           ttf global_fontfile_eagle3d "E" 0.05, 0
           pigment {
              White
              }
           scale 6
           rotate <90,0,0>
           translate <-13,H+0.08,-4.5>
           } // CE Marking
        text {
           ttf global_fontfile_eagle3d "H" 0.05, 0
           pigment {
              White
              }
           scale 6
           rotate <90,0,0>
           translate <+3,H+0.08,+2.3>
           } // MYRRA LOGO Marking 
        translate 2*x
        scale <L1/33,0,L1/33>
        }
     rotate 90*y
     }
#end

#macro TRAFO_MYRRA_EI_30_1_005()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,15.8,0,0,11.5,20,20,0,1,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_2_005()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,15.8,0,0,11.5,20,20,0,2,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_1_105()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,22.2,0,0,18.4,20,20,0,1,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_2_105()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,22.2,0,0,18.4,20,20,0,2,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_1_125()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,24.5,0,0,20.5,20,20,0,1,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_2_125()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,24.5,0,0,20.5,20,20,0,2,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_1_155()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,27.3,0,0,23.5,20,20,0,1,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_2_155()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,27.3,0,0,23.5,20,20,0,2,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_1_180()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,29.8,0,0,26.0,20,20,0,1,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_30_2()
  TRAFO_MYRRA_EI_BASE(32.6,27.6,29.8,0,0,26.0,20,20,0,2,0,4.5,0)
#end

#macro TRAFO_MYRRA_EI_38_1()
  TRAFO_MYRRA_EI_BASE(41.0,35.0,28.0,30.5,25.7,23.0,20,25,0,1,0,4,0)
#end

#macro TRAFO_MYRRA_EI_38_2()
  TRAFO_MYRRA_EI_BASE(41.0,35.0,28.0,30.5,25.7,23.0,20,25,0,2,0,4,0)
#end

#macro TRAFO_MYRRA_EI_42_1()
  TRAFO_MYRRA_EI_BASE(44.25,37.0,32.25,32.25,27.70,26.0,25,25,0,1,0,4,0)
#end

#macro TRAFO_MYRRA_EI_42_2()
  TRAFO_MYRRA_EI_BASE(44.25,37.0,32.25,32.25,27.70,26.0,25,25,0,2,0,4,0)
#end

#macro TRAFO_MYRRA_EI_48_1()
  TRAFO_MYRRA_EI_BASE(50.50,42.5,34.75,33.60,25.6,0,25,27.5,2.5,1,0,3.5,40)
#end

#macro TRAFO_MYRRA_EI_48_2()
  TRAFO_MYRRA_EI_BASE(50.50,42.5,34.75,33.60,25.6,0,25,27.5,2.5,2,0,3.5,40)
#end

#macro TRAFO_MYRRA_EI_54_1()
  TRAFO_MYRRA_EI_BASE(56.50,47.25,38.75,37.50,29.25,33,30,30,2.5,1,0,4,45)
#end

#macro TRAFO_MYRRA_EI_54_2()
  TRAFO_MYRRA_EI_BASE(56.50,47.25,38.75,37.50,29.25,33,30,30,2.5,2,0,4,45)
#end

#macro TRAFO_MYRRA_EI_60_1()
  TRAFO_MYRRA_EI_BASE(63.5,53.5,45.5,0,0,36.5,30,32.5,2.5,1,0,4,50)
#end

#macro TRAFO_MYRRA_EI_60_2()
  TRAFO_MYRRA_EI_BASE(63.5,53.5,45.5,0,0,36.5,30,32.5,2.5,2,0,4,50)
#end

#macro TRAFO_MYRRA_EI_66_1()
  TRAFO_MYRRA_EI_BASE(70,59,48.75,0,0,0,35,35,2.5,1,0,4.5,55)
#end

#macro TRAFO_MYRRA_EI_66_2()
  TRAFO_MYRRA_EI_BASE(70,59,48.75,0,0,0,35,35,2.5,2,0,4.5,55)
#end



/*******************************************************************************
 * MYRRA UI48 Transformer
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1  10/01/06
 ******************************************************************************/
#macro TRAFO_MYRRA_UI48_BASE(value,pw)
  #macro LABEL_R(L,W,R)
     #local e=0.005;
     union {
        cylinder {
           <-L/2+R,0,-W/2+R> <-L/2+R,e,-W/2+R> R
           }
        cylinder {
           <+L/2-R,0,-W/2+R> <+L/2-R,e,-W/2+R> R
           }
        cylinder {
           <-L/2+R,0,+W/2-R> <-L/2+R,e,+W/2-R> R
           }
        cylinder {
           <+L/2-R,0,+W/2-R> <+L/2-R,e,+W/2-R> R
           }
        box {
           <-L/2+R,0,-W/2> <+L/2-R,e,+W/2>
           }
        box {
           <-L/2,0,-W/2+R> <+L/2,e,+W/2-R>
           }
        texture {
           col_silver
           }
        }
  #end

  #if (pw = 60)
     #local A = 24.25;
     #local B = 7.25;
     #local C = 43;
     #local D = A; //3*A/4;
     #local E = 34;
  #else
     #local A = 19.25;
     #local B = 6.75;
     #local C = 41.5;
     #local D = 15;  //3*A/4;
     #local E = 27.5;
  #end

  union {
     difference {
        union {
           superellipsoid {
              <0.05, 0.05>
              scale <E, A,35>
              translate <0, A, 0>
              pigment {
                 Gray50
                 }
              }
           superellipsoid {
              <0.05, 0.05>
              scale <C, D, 26.25>
              translate <0, D, 0>
              pigment {
                 Gray50
                 }
              }
           superellipsoid {
              <0.05, 0.05>
              scale <C, B, 35>
              translate <0, B, 0>
              pigment {
                 Gray50
                 }
              }
           }
        union{
            cylinder{<-37.5,15,30><-37.5,-1,30> 1.55 }
            cylinder{<37.5,15,-30><37.5,-1,-30> 1.55 }
            cylinder{<-37.5,15,-30><-37.5,-1,-30> 1.55 }
            cylinder{<37.5,15,30><37.5,-1,30> 1.55 }
            cylinder{<0,2*A-0.5,0><0,2*A+0.5,0> 0.5 }
            pigment{Gray20}
        }
    }
    #if(global_show_screws=on)
        object {
           TOOLS_SCREW(4,5,1,Silver)
           rotate 180*x
           translate <-37.5,-pcb_height,+30>
           }
        object {
           TOOLS_SCREW(4,5,1,Silver)
           rotate 180*x
           translate <-37.5,-pcb_height,-30>
           }
        object {
           TOOLS_SCREW(4,5,1,Silver)
           rotate 180*x
           translate <+37.5,-pcb_height,+30>
           }
        object {
           TOOLS_SCREW(4,5,1,Silver)
           rotate 180*x
           translate <+37.5,-pcb_height,-30>
           }
    #end

    union {
        object {
           LABEL_R(15,30,1.5)
           }
        text {
           ttf global_fontfile_eagle3d "H" 0.05, 0
           pigment {
              Black
              }
           scale 4.5
           rotate <90,0,0>
           translate <-6.5,0.05,10.5>
           } // Myrra logo
        text {
           ttf global_fontfile_eagle3d "Z" 0.05, 0
           pigment {
              Black
              }
           scale 3.5
           rotate <90,0,0>
           translate <-5.8,0.05,7>
           } // logo
        text {
           ttf global_fontfile_eagle3d "A" 0.05, 0
           pigment {
              Black
              }
           scale 3.5
           rotate <90,0,0>
           translate <-5.8,0.05,-8>
           } // UL Marking
        text {
           ttf global_fontfile_eagle3d "I" 0.05, 0
           pigment {
              Black
              }
           scale 3.5
           rotate <90,0,0>
           translate <-6.5,0.05,-12.5>
           } // Canada UL Marking
        text {
           ttf global_fontfile_eagle3d "/" 0.05, 0
           pigment {
              Black
              }
           scale 1
           rotate <90,0,0>
           translate <-6.5,0.05,5.5>
           } // Fuse Marking
        text {
           ttf global_fontfile_eagle3d "/" 0.05, 0
           pigment {
              Black
              }
           scale 1 rotate <90,0,0>
           translate <-6.5,0.05,2.5>
           } // Fuse Marking
        box {
           <2.5,0,-7> <5.5,0.05,-13>
           pigment {
              Black
              }
           }
        text {
           ttf global_fontfile_arial_bold "63801" 0.05, 0
           pigment {
              White
              }
           scale <1.8,2.2,1>
           rotate <90,90,0>
           translate <3.2,0.07,-7.7>
           } // Marking
        
        text {
           ttf global_fontfile_arial_bold value 0.05, 0
           pigment {
              Black
              }
           scale 2
           rotate <90,0,0>
           translate <-0.8,0.05,12.8>
           } // Ref Marking
        text {
           ttf global_fontfile_arial_bold "2x115V" 0.05, 0
           pigment {
              Black
              }
           scale 2
           rotate <90,0,0>
           translate <-1,0.05,10.8>
           } // Marking
        text {
           ttf global_fontfile_arial_bold "50/60Hz" 0.05, 0
           pigment {
              Black
              }
           scale 2
           rotate <90,0,0>
           translate <-2,0.05,7.7>
           } // Marking
        #if(pw=60)
           text { ttf global_fontfile_arial_bold "315mA(230V)" 0.05, 0 pigment { Black } scale 1.5 rotate<90,0,0> translate<-5,0.05,4> } // Marking
           text { ttf global_fontfile_arial_bold "630mA(115V)" 0.05, 0 pigment { Black } scale 1.5 rotate<90,0,0> translate<-5,0.05,1> } // Marking
        #else
           text { ttf global_fontfile_arial_bold "200mA(230V)" 0.05, 0 pigment { Black } scale 1.5 rotate<90,0,0> translate<-5,0.05,4> } // Marking
           text { ttf global_fontfile_arial_bold "400mA(115V)" 0.05, 0 pigment { Black } scale 1.5 rotate<90,0,0> translate<-5,0.05,1> } // Marking
        #end
        text {ttf global_fontfile_arial_bold "T" 0.05, 0 pigment{Black} scale 0.8 rotate<90,0,0> translate<-3,0.05,6.2>} // Marking
        text {ttf global_fontfile_arial_bold "T" 0.05, 0 pigment{Black} scale 0.8 rotate<90,0,0> translate<-3,0.05,3.2>} // Marking
        text {ttf global_fontfile_arial_bold "1           4           9           12" 0.05, 0 pigment{Black} scale 1 rotate<90,0,0> translate<-6,0.05,-14>} // Marking
        #if(pw=60)
           text {ttf global_fontfile_arial_bold "15V 30VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-1.5>}      // Marking
           text {ttf global_fontfile_arial_bold "15V 30VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-4>}      // Marking
        #else
           text {ttf global_fontfile_arial_bold "15V 20VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-1.5>}      // Marking
           text {ttf global_fontfile_arial_bold "15V 20VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-4>}      // Marking
        #end
        text {ttf global_fontfile_arial_bold "ta 50/B" 0.05, 0 pigment{Black} scale 1.5 rotate<90,0,0> translate<1,0.05,-6>} // Marking
        rotate 180*y
        #if(pw=60)
           translate<34-8,2*A,35-17-2>
        #else
           translate<27.5-3,2*A,35-17-8>
        #end
        rotate -90*y
        }
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,-28.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,+28.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,-13.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,+13.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,-23.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,+23.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,-8.5> texture{col_silver}}
     box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,+8.5> texture{col_silver}}
     }
#end

#macro TRAFO_MYRRA_UI48_40(value)
  TRAFO_MYRRA_UI48_BASE(value,40)
#end

#macro TRAFO_MYRRA_UI48_60(value)
  TRAFO_MYRRA_UI48_BASE(value,60)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=TRAFO_MYRRA_EI_30_1_005(:IE30-5 Transformer 1 secondary wiring
//=TRAFO_MYRRA_EI_30_2_005(:IE30-5 Transformer 2 secondary wirings
//=TRAFO_MYRRA_EI_30_1_105(:IE30-10.5 Transformer 1 secondary wiring
//=TRAFO_MYRRA_EI_30_2_105(:IE30-10.5 Transformer 2 secondary wirings
//=TRAFO_MYRRA_EI_30_1_125(:IE30-12.5 Transformer 1 secondary wiring
//=TRAFO_MYRRA_EI_30_2_125(:IE30-12.5 Transformer 2 secondary wirings
//=TRAFO_MYRRA_EI_30_1_155(:IE30-15.5 Transformer 1 secondary wiring
//=TRAFO_MYRRA_EI_30_2_155(:IE30-15.5 Transformer 2 secondary wirings
//=TRAFO_MYRRA_EI_30_1_180(:IE30-18 Transformer 1 secondary wiring
//=TRAFO_MYRRA_EI_30_2(:IE30-18 Transformer 1 secondary wiring
//=TRAFO_MYRRA_EI_66_2(:IE30-18 Transformer 2 secondary wirings
//trafo:EI30-1=TRAFO_MYRRA_EI_30_1_125(:IE30-12.5 Transformer 1 secondary wiring
//trafo:EI30-2=TRAFO_MYRRA_EI_30_2_125(:IE30-12.5 Transformer 2 secondary wirings
//trafo:EI38-1=TRAFO_MYRRA_EI_38_1(:IE38-13.6 Transformer 1 secondary wiring
//trafo:EI38-2=TRAFO_MYRRA_EI_38_2(:IE38-13.6 Transformer 2 secondary wirings
//trafo:EI42-1=TRAFO_MYRRA_EI_42_1(:IE42-14.8 Transformer 1 secondary wiring
//trafo:EI42-2=TRAFO_MYRRA_EI_42_2(:IE42-14.8 Transformer 2 secondary wirings
//trafo:EI48-1=TRAFO_MYRRA_EI_48_1(:IE48-16.8 Transformer 1 secondary wiring
//trafo:EI48-2=TRAFO_MYRRA_EI_48_2(:IE48-16.8 Transformer 2 secondary wirings
//trafo:EI54-1=TRAFO_MYRRA_EI_54_1(:IE54-18.8 Transformer 1 secondary wiring
//trafo:EI54-2=TRAFO_MYRRA_EI_54_2(:IE54-18.8 Transformer 2 secondary wirings
//trafo:EI60-1=TRAFO_MYRRA_EI_60_1(:IE60-21 Transformer 1 secondary wiring
//trafo:EI60-2=TRAFO_MYRRA_EI_60_2(:IE60-21 Transformer 2 secondary wirings
//trafo:EI66-1=TRAFO_MYRRA_EI_66_1(:IE66-23 Transformer 1 secondary wiring
//trafo:EI66-2=TRAFO_MYRRA_EI_60_2(:IE66-23 Transformer 2 secondary wirings
//=TRAFO_MYRRA_UI48_40(:UI48 Transformer 40VA
//UI48=TRAFO_MYRRA_UI48_60(:UI48 Transformer 60VA
// end assignment
