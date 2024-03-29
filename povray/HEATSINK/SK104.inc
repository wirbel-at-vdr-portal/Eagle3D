/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Macros for SK 104 heatsink for TO220, SOT32, TO3P
 * Designed by Stefan Seegel <dahamm(replace with at)@gmx.net>
 * 17/10/06
 *
 * h:     height of heatsink
 * typ:      0 = mounting clip,
 *           1 = solder pins,
 *           2 = solder pins and insulation washer,
 *           3 = M3 threaded bolts, brass
 * gap:   leave out gap on bottom if heatsink
 * d:     make drills
 * *****************************************************************************/
#macro SPC_HEATSINK_SK104_BASE(h, typ, gap)
  #macro SK104_MOUNTINGCLIP_HALF()
     union {
        #local bw1 = 11;
        #local bw2 = 95;
        #local bw3 = 80;
        #local bw4 = 160;
        #local brm = 7;
        #local br = 1;
        #local d = 0.5;
        #local rm = (2*br-d)/2;
        #local rmm = (2*brm-d)/2;
        #local s1 = 16.5;
        #local s2 = 5.0;
        #local s3 = 1.5;
        #local s4 = 1.0;
        #local hc = 6.4;

        difference {
           cylinder {
              <0,-hc/2,0> <0,hc/2,0> brm
              }
           cylinder {
              <0,-hc,0> <0,hc,0> brm-d
              }
           box {
              <0, -hc, -brm>, <-brm, hc, brm>
              rotate<0,0,0>
              }
           box {
              <0, -hc, -brm>, <brm, hc, brm>
              rotate<0,bw1,0>
              }
           }

        #local dx=sin(bw1/180*pi)*rmm;
        #local dy=cos(bw1/180*pi)*rmm;
        box {
           <-d/2, -hc/2, 0>, <d/2, hc/2, -s1>
           rotate<0,-90+bw1,0> translate<dx,0,dy>
           }

        #local dx=dx+s1*cos(bw1/180*pi);
        #local dy=dy-s1*sin(bw1/180*pi);

        union {
           difference {
              cylinder {
                 <0,-hc/2,0> <0,hc/2,0> br
                 }
              cylinder {
                 <0,-hc,0> <0,hc,0> br-d
                 }
              box {
                 <0, -hc, -br>, <-br, hc, br>
                 rotate<0,bw1,0>
                 }
              #local bwx = bw1-bw2;
              box {
                 <0, -hc, -br>, <br, hc, br>
                 rotate<0,bwx,0>
                 }
              }
           box {
              <-d/2, -hc/2, 0>, <d/2, hc/2, s2>
              rotate<0,bwx+90,0> translate<-sin(bwx/180*pi)*rm,0,-cos(bwx/180*pi)*rm>
              }

           #local dx=dx+sin(bw1/180*pi)*rm;
           #local dy=dy+cos(bw1/180*pi)*rm;
           translate<dx,0,dy>
           }
        #local dx = dx-rm*sin(bwx/180*pi) + s2*cos(bwx/180*pi);
        #local dy = dy-rm*cos(bwx/180*pi) - s2*sin(bwx/180*pi);

        union {
           difference {
              cylinder {
                 <0,-hc/2,0> <0,hc/2,0> br
                 }
              cylinder {
                 <0,-hc,0> <0,hc,0> br-d
                 }
              box {
                 <0, -hc, -br>, <-br, hc, br>
                 rotate<0,bwx,0>
                 }
              #local bwx = bwx-bw3;
              box {
                 <0, -hc, -br>, <br, hc, br>
                 rotate<0,bwx,0>
                 }
              }
           box {
              <-d/2, -hc/2, 0>, <d/2, hc/2, s3>
              rotate<0,bwx+90,0> translate<-sin(bwx/180*pi)*rm,0,-cos(bwx/180*pi)*rm>
              }
           #local dx = dx - rm*cos(bw1/180*pi);
           #local dy = dy + rm*sin(bw1/180*pi);
           translate<dx,0,dy>
           }

        #local dx = dx -rm*sin(bwx/180*pi) + s3*cos(bwx/180*pi);
        #local dy = dy -rm*cos(bwx/180*pi) - s3*sin(bwx/180*pi);
        union {
           difference {
              cylinder {
                 <0,-hc/2,0> <0,hc/2,0> br
                 }
              cylinder {
                 <0,-hc> <0,hc,0> br-d
                 }
              box {
                 <0, -hc, -br>, <-br, hc, br>
                 rotate<0,bwx,0>
                 }
              #local bwx = bwx+bw4;
              box {
                 <0, -hc, -br>, <br, hc, br>
                 rotate<0,bwx,0>
                 }
              }
           box {
              <-d/2, -hc/2, 0>, <d/2, hc/2, s4>
              rotate<0,bwx+90,0> translate<sin(bwx/180*pi)*rm,0,cos(bwx/180*pi)*rm>
              }
           #local dx = dx - rm*sin((bwx-bw4)/180*pi);
           #local dy = dy - rm*cos((bwx-bw4)/180*pi);
           translate<dx,0,dy>
           }
        texture {
          col_gold
          }
        }
     #end

  #macro SK104_QUARTER(h)
     union {
        prism {
           0, h, 15,
           <-7.5,0.75>,
           <-8,5.7>, <-9.2,5.6>,
           <-9.6,2.1>,
           <-12.5,6>, <-13.3,5.2>,
           <-12.3,3.4>,
           <-16.8,6>, <-17.6,5.1>,
           <-14.7,2.9>,
           <-17.0,3.6>, <-17.6,2.7>,
           <-12.7,0>, <0,0>, <0,0.75>
           }
        cylinder {
          <-8.6,0,5.65>, <-8.6,h,5.65> 0.6
          }
        cylinder {
          <-12.9,0,5.6>, <-12.9,h,5.6> 0.56
          }
        cylinder {
          <-17.2,0,5.55>, <-17.2,h,5.55> 0.6
          }
        cylinder {
          <-17.3,0,3.15>, <-17.3,h,3.15> 0.54
          }
        }
     #end

  union {
     difference {
        union {
           object {
             SK104_QUARTER(h)
             }
           object {
             SK104_QUARTER(h)
             rotate<0,180,0>
             }
           object {
             SK104_QUARTER(h)
             rotate<180,0,0> translate<0,h,0>
             }
           object {
             SK104_QUARTER(h)
             rotate<180,180,0> translate<0,h,0>
             }
           }
        cylinder {
          <-12.7,-1,0>, <-12.7,h+1,0> 1.15
          }
        cylinder {
          <12.7,0,0>, <12.7,h+1,0> 1.15
          }
        #if (typ != 0)
          cylinder {
             <0,13.5,-1>, <0,13.5,1> 1.6
             }
          cylinder {
             <0,18.3,-1>, <0,18.3,1> 1.6
             }
          cylinder {
             <0,25.4,-1>, <0,25.4,1> 1.6
             }
        #end

        #if (gap=on)
          box {
             <-5.4,-1,-1>, <5.4,6.5,1>
             }
        #end

        pigment {
          Gray30
          }
        }
     #if (typ=3) //SK104 xx STSB (M3 threaded bolts, brass)
        cylinder {
           <-12.7,0,0>, <-12.7,-1.5,0> 3.5
           texture {
              col_gold
              }
           }
        cylinder {
           <12.7,0,0>, <12.7,-1.5,0> 3.5
           texture {
              col_gold
              }
           }
        object {
           TOOLS_SCREW(3,13.5,-1,Brass)
           translate<-12.7,7,0> texture {
              col_gold
              }
           }
        object {
           TOOLS_SCREW(3,13.5,-1,Brass)
           translate<12.7,7,0> texture {
              col_gold
              }
           }
        object {
           TOOLS_WASHER(3,1,Silver)
           translate<12.7,-pcb_height-2.3>
           }
        object {
           TOOLS_NUT(3,0,Silver)
           translate<12.7,-pcb_height-4.3,0>
           }
        object {
           TOOLS_WASHER(3,1,Silver)
           translate<-12.7,-pcb_height-2.3,0>
           }
        object {
           TOOLS_NUT(3,0,Silver)
           translate<-12.7,-pcb_height-4.3,0>
           }
        translate<0,1.5,0>
     #end

     #if (typ=2) //SK104 xx STIS (solder pins and insulation washer)
        //insulating washers
        cylinder {
           <-12.7,0,0>, <-12.7,-3,0> 3
           pigment {
              White
              }
           }
        cylinder {
           <12.7,0,0>, <12.7,-3,0> 3
           pigment {
              White
              }
           }
        //solder pins
        cylinder {
           <-12.7,7,0>, <-12.7,-6,0> 1.15
           texture {
              col_gold
              }
           }
        cylinder {
           <12.7,7,0>, <12.7,-6,0> 1.15
           texture {
              col_gold
              }
           }
        translate<0,3,0>
     #end

     #if (typ=1 | typ=0) //SK104 xx STS (solder pins)
        //solder pins
        cylinder {
           <-12.7,7,0>, <-12.7,-4.5,0> 1.15
           texture {
              col_gold
              }
           }
        cylinder {
           <12.7,7,0>, <12.7,-4.5,0> 1.15
           texture {
              col_gold
              }
           }
     #end

     #if (typ=0) //Mounting clip
        union {
           object {
              SK104_MOUNTINGCLIP_HALF()
              rotate<0,180,0>
              }
           object {
              SK104_MOUNTINGCLIP_HALF()
              rotate<0,180,180>
              }
           translate<0,9,12>
           }
     #end

   }
#end

#macro SPC_HEATSINK_SK104_254_STS()
  SPC_HEATSINK_SK104_BASE(25.4, 1, on)
#end

#macro SPC_HEATSINK_SK104_381_STS()
  SPC_HEATSINK_SK104_BASE(38.1, 1, on)
#end

#macro SPC_HEATSINK_SK104_508_STS()
  SPC_HEATSINK_SK104_BASE(50.8, 1, on)
#end

#macro SPC_HEATSINK_SK104_635_STS()
  SPC_HEATSINK_SK104_BASE(63.5, 1, on)
#end

#macro SPC_HEATSINK_SK104_254_STIS()
  SPC_HEATSINK_SK104_BASE(25.4, 2, on)
#end

#macro SPC_HEATSINK_SK104_381_STIS()
  SPC_HEATSINK_SK104_BASE(38.1, 2, on)
#end

#macro SPC_HEATSINK_SK104_508_STIS()
  SPC_HEATSINK_SK104_BASE(50.8, 2, on)
#end

#macro SPC_HEATSINK_SK104_635_STIS()
  SPC_HEATSINK_SK104_BASE(63.5, 2, on)
#end

#macro SPC_HEATSINK_SK104_254_STSB()
  SPC_HEATSINK_SK104_BASE(25.4, 3, on)
#end

#macro SPC_HEATSINK_SK104_381_STSB()
  SPC_HEATSINK_SK104_BASE(38.1, 3, on)
#end

#macro SPC_HEATSINK_SK104_508_STSB()
  SPC_HEATSINK_SK104_BASE(50.8, 3, on)
#end

#macro SPC_HEATSINK_SK104_635_STSB()
  SPC_HEATSINK_SK104_BASE(63.5, 3, on)
#end

#macro SPC_HEATSINK_SK104_254_MC()
  SPC_HEATSINK_SK104_BASE(25.4, 0, on)
#end

#macro SPC_HEATSINK_SK104_381_MC()
  SPC_HEATSINK_SK104_BASE(38.1, 0, on)
#end

#macro SPC_HEATSINK_SK104_508_MC()
  SPC_HEATSINK_SK104_BASE(50.8, 0, on)
#end

#macro SPC_HEATSINK_SK104_635_MC()
  SPC_HEATSINK_SK104_BASE(63.5, 0, on)
#end




/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_HEATSINK_SK104_254_STS(:Heatsink SK104 STS 25.4mm
//=SPC_HEATSINK_SK104_254_STIS(:Heatsink SK104 STIS 25.4mm
//=SPC_HEATSINK_SK104_254_STSB(:Heatsink SK104 STSB 25.4mm
//=SPC_HEATSINK_SK104_254_MC(:Heatsink SK104 with mounting clamp 25.4mm
//=SPC_HEATSINK_SK104_381_STS(:Heatsink SK104 STS 38.1mm
//=SPC_HEATSINK_SK104_381_STIS(:Heatsink SK104 STIS 38.1mm
//=SPC_HEATSINK_SK104_381_STSB(:Heatsink SK104 STSB 38.1mm
//=SPC_HEATSINK_SK104_381_MC(:Heatsink SK104 with mounting clamp 38.1mm
//=SPC_HEATSINK_SK104_508_STS(:Heatsink SK104 STS 50.8mm
//=SPC_HEATSINK_SK104_508_STIS(:Heatsink SK104 STIS 50.8mm
//=SPC_HEATSINK_SK104_508_STSB(:Heatsink SK104 STSB 50.8mm
//=SPC_HEATSINK_SK104_508_MC(:Heatsink SK104 with mounting clamp 50.8mm
//=SPC_HEATSINK_SK104_635_STS(:Heatsink SK104 STS 63.5mm
//=SPC_HEATSINK_SK104_635_STIS(:Heatsink SK104 STIS 63.5mm
//=SPC_HEATSINK_SK104_635_STSB(:Heatsink SK104 STSB 63.5mm
//=SPC_HEATSINK_SK104_635_MC(:Heatsink SK104 with mounting clamp 63.5mm
// end assignment
