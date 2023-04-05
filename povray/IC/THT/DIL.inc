/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * DIP Pin
 ******************************************************************************/
#macro IC_DIS_PIN()
union {
   difference {
      box{<0,0,0><0.455,3.4,0.3>}
      box{<0,0,0><0.5,0.5,0.5> rotate<0,0,-20> translate<0.305,0,-0.1>}
      box{<0,0,0><-0.5,0.5,0.5> rotate<0,0,20> translate<0.15,0,-0.1>}
      }
   box{<0,0,0><1.43,0.3,0.33> translate<-0.4875,5.3,0.5>}
   difference {
      box{<0,0,0><1.43,0.25,0.25> translate<-0.4875,5.05,0.3>}
      cylinder{<0,0,0><2,0,0>0.25 translate<-0.6,5.05,0.55>}
      }
   difference {
      box{<0,0,0><1.43,1.7,0.3> translate<-0.4875,3.4,0>}
      box{<0,0,0><1,2.2,0.5> rotate<0,0,-20> translate<0.55,3.4,-0.1>}
      box{<0,0,0><-1,2.2,0.5> rotate<0,0,20> translate<-0.095,3.40,-0.1>}
      }
   difference {
      cylinder{<0,0,0><1.43,0,0>0.5 translate<-0.4875,5.1,0.5> }
      box{<0,0,0><2,2.2,2> translate<-0.8,3.1,0.3>}
      box{<0,0,0><2,2.2,2> translate<-0.7,4,0.5>}
      }
   translate <-0.455/2,0,0>
   } // end: IC_DIS_PIN
#end

//------------------------------------------------------------------------------



/*******************************************************************************
 * The following is a modified module section by Joseph Zeglinski
 * Aug. 20, 2003
 *
 * This macro now produces either a fully pin populated DIL,  or a DIL with
 * fewer "quads" of pins.
 * Example: Some IC's, FET's, Optoisolators and Crystal Oscillators - (8, 14,
 *  16, or 24) pin body, with only 4, 8 or 12 outer pins.
 * The " a= Available Pins" parameter is how many pins (modulo 4), are present
 * on the intended DIP.
 *
 * Grundmakro für DIP's
 * p=Pincount of a full DIL
 * a=Count of available pins, ( less than or equal to "p" )
 * b=breite (in Raster)
 * h=höhe
 * n=Beschriftung
 ******************************************************************************/
#macro IC_DIS_DIP_BASE(p,a,b,h,n,logo)
union{
    //Body
    difference{
        box{<0,0,0><(p/2)*2.54-0.2,h,b*2.54-1>}
        box{<-0.1,0,0><(p/2)*2.54+2,-2,-2> rotate<-15,0,0> translate<0,h/2-0.3,0>}
        box{<-0.1,0,0><(p/2)*2.54+2,2,-2> rotate<15,0,0> translate<0,h/2+0.3,0>}
        box{<-0.1,0,0><(p/2)*2.54+2,-2,2> rotate<15,0,0> translate<0,h/2-0.3,b*2.54-1>}
        box{<-0.1,0,0><(p/2)*2.54+2,2,2> rotate<-15,0,0> translate<0,h/2+0.3,b*2.54-1>}
        box{<0,0,b*2.54><-2,-2,-b*2> rotate<0,0,15> translate<0,h/2-0.3,0>}
        box{<0,0,b*2.54><-2,2,-b*2> rotate<0,0,-15> translate<0,h/2+0.3,0>}
        box{<0,0,b*2.54><2,-2,-b*2> rotate<0,0,-15> translate<p/2*2.54-0.2,h/2-0.3,0>}
        box{<0,0,b*2.54><2,2,-b*2> rotate<0,0,15> translate<p/2*2.54-0.2,h/2+0.3,0>}
        cylinder{<0,h-0.3,(b*2.54-1)/2><0,h+0.3,(b*2.54-1)/2>1}
        translate<-(p/2*2.54-0.2)/2,0,-(b*2.54-1)/2>
    }
    
    //Pins
    union{
        
        #local i=0;
        #while(i<(p/2))

            // Check for special  "Partial Pin Population" DIL condition
            #if( (p>a) & (i=a/4) )
                #local i=i+(p-a)/2;
            #end

            object{IC_DIS_PIN() rotate<0,180,0> translate<i*2.54,-3.75,b*2.54/2>}
            object{IC_DIS_PIN() translate<i*2.54,-3.75,-b*2.54/2>}
            #local i=i+1;
        #end
        translate<-p/2*1.27+1.27,0,0>
        texture{col_silver}
    }

    // ADAPTIVE print scaling for small IC's
    // Check if printing will fall off the end of the DIP surface
    // Automatically size the X-scaling factor for the value (n) to fit the DIP IC surface:
    // DIP4 - because it is so short, printing will be "rotated to fit" the width (b) of this IC

    //Marking
    union{
        // create a TrueType text shape
        #local astring = text {ttf besch_font,n,0.2,0}
        #local L=(max_extent(astring).x); // MM width of text string (n)
        #local astrscale = ( (p=4) ? (b*2-1.0)/L : ((p/2)*2.54-0.2 -2.5 )/L );  //scale to width for tiny DIP4
        #if(p=4)
            #local astrscale = (astrscale<1.5 ? astrscale : 1.5);    // Leave normal scaling, if a short label will fit
            object{astring rotate<90,-90,0,>  scale <1.5,1,astrscale>  translate<0.3,h+0.01,-L*astrscale/2>  }
        #else
            #if(astrscale < 1.5) // For DP6 & DIP8 check if a normal scale label will still fit
                object{astring rotate<90,0,0,>  scale <astrscale,1,1.5>  translate<-(p/4)*2.54+1.5,h+0.01,-0.3> } //No - shrink in X-direction
            #else
                text{ttf global_fontfile_arial_bold n 0.2, 0 rotate <90,0,0> scale<b/2,1,b/2> translate<-b,h+0.01,0.6>}
            #end
        #end

        #if(p>12)
            #if(strcmp(logo,"MICROCHIP")=0.0)
                text{ttf global_fontfile_eagle3d "m" 0.2,0 scale<b+1,b+1,b+1> rotate<90,0,0> translate<-(p/5)*2.54+0.5,h+0.01,-b/1.8>}
                text{ttf besch_font "Microchip" 0.2,0 rotate<90,0,0> scale<b/1.5,b/1.5,b/1.5> translate<-b,h+0.01,-b/2> }
                #if(p>14)
                    text{ttf besch_font "Microchip" 0.2,0 rotate<90,0,0> scale<b/1.5,b/1.5,b/1.5> translate<-b,h+0.01,-b/2> }
                #end
            #end

            #if(strcmp(logo,"PHILIPS")=0.0)
                text{ttf global_fontfile_eagle3d "p" 0.2,0 scale<b*1.5,b*1.5,b*1.5> rotate<90,0,0> translate<-(p/5)*2.54+1.5,h+0.01,-b/1.5>}
            #end

            #if(strcmp(logo,"MAXIM")=0.0)
                text{ttf global_fontfile_eagle3d "-" 0.2,0 scale<b/2.5,b/2.5,b/2.5> rotate<90,0,0> translate<-(p/5)*2.54,h+0.01,-b/2.2>}
            #end

            #if(strcmp(logo,"ST")=0.0)
                text{ttf global_fontfile_eagle3d "s" 0.2,0 scale<b,b,b> rotate<90,0,0> translate<-(p/5)*2.54+0.5,h+0.01,-b/2.2>}
            #end

            #if(strcmp(logo,"TEXAS")=0.0)
                text{ttf global_fontfile_eagle3d "t" 0.2,0 scale<b*0.9,b*0.9,b*0.9> rotate<90,0,0> translate<-(p/5)*2.54,h+0.01,-b/2.2>}
            #end
        #end
        texture{col_bright_marking}
    }
    translate<0,0.25,0>
    texture{col_ic_body_1}
   } // end: IC_DIS_DIP_BASE
#end

//------------------------------------------------------------------------------
#macro IC_DIS_DIP8A4(name,logo)  // DIP8 with 4 corner pins
  IC_DIS_DIP_BASE(8,4,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP14A4(name,logo) // DIP14 with 4 corner pins
  IC_DIS_DIP_BASE(14,4,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP14A8(name,logo) // DIP14 with 8 corner pins
  IC_DIS_DIP_BASE(14,8,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP16A4(name,logo) // DIP16 with 4 corner pins
  IC_DIS_DIP_BASE(16,4,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP16A8(name,logo) // DIP16 with 8 corner pins
  IC_DIS_DIP_BASE(16,8,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP24A12(name,logo) // DIP24 with 12 corner pins
  IC_DIS_DIP_BASE(24,12,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP2(name,logo) // DIP2
  IC_DIS_DIP_BASE(2,2,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP4(name,logo) // DIP4
  IC_DIS_DIP_BASE(4,4,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP6(name,logo) // DIP6
  IC_DIS_DIP_BASE(6,6,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP6_4(name,logo) // DIP6-4
  IC_DIS_DIP_BASE(6,6,4,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP8(name,logo) // DIP8
  IC_DIS_DIP_BASE(8,8,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP14(name,logo) // DIP14
  IC_DIS_DIP_BASE(14,14,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP16(name,logo) // DIP16
  IC_DIS_DIP_BASE(16,16,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP18(name,logo) // DIP18
  IC_DIS_DIP_BASE(18,18,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP20(name,logo) // DIP20
  IC_DIS_DIP_BASE(20,20,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP22(name,logo) // DIP22
  IC_DIS_DIP_BASE(22,22,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP22_4(name,logo) // DIP22-4
  IC_DIS_DIP_BASE(22,22,4,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP24(name,logo) // DIP24
  IC_DIS_DIP_BASE(24,24,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP24_4(name,logo) // DIP24-4
  IC_DIS_DIP_BASE(24,24,4,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP24_9(name,logo)
  IC_DIS_DIP_BASE(24,24,9,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP28(name,logo) // DIP28
  IC_DIS_DIP_BASE(28,28,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP24_W(name,logo) // DIP24 600mil
  IC_DIS_DIP_BASE(24,24,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP28_4(name,logo) // DIP28 400mil
  IC_DIS_DIP_BASE(28,28,4,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP28_W(name,logo) // DIP28 600mil
  IC_DIS_DIP_BASE(28,28,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP32_3(name,logo) // DIP32 300mil
  IC_DIS_DIP_BASE(32,32,3,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP32_W(name,logo) // DIP32 600mil
  IC_DIS_DIP_BASE(32,32,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP36_W(name,logo) // DIP36 600mil
  IC_DIS_DIP_BASE(36,36,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP40_W(name,logo) // DIP40 600mil
  IC_DIS_DIP_BASE(40,40,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP42_W(name,logo) // DIP42 600mil
  IC_DIS_DIP_BASE(42,42,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP48_W(name,logo) // DIP48 600mil
  IC_DIS_DIP_BASE(48,48,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP52_W(name,logo) // DIP52 600mil
  IC_DIS_DIP_BASE(52,52,6,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP64_9(name,logo) // DIP64 900mil
  IC_DIS_DIP_BASE(64,64,9,3.2,name,logo)
#end
//------------------------------------------------------------------------------
#macro IC_DIS_DIP68_9(name,logo) // DIP68 900mil
  IC_DIS_DIP_BASE(68,68,9,3.2,name,logo)
#end
//------------------------------------------------------------------------------



/*******************************************************************************
 * Macros for Beck SC12
 * Designed by Stefan Seegel <dahamm(replace with at)gmx.net>
 ******************************************************************************/
#macro IC_BECK_SC12()
union {
   // plastic package
   difference {
      union {
         difference {
            box{<-22,0,-11>,<22,9.5,11>}
            box{<-23,8.5,-7.5>,<9.5,10,7.5>}
            }
         box{<0,0,-8>,<-5,-5,8> rotate<0,0,18.43> translate<9.5,9.5,0>}       //Schraege innen rechts
         box{<0,0,-7.5>,<20,-5,7.5> rotate<0,0,-3.81> translate<-21.5,9.5,0>} //Schraege innen links
         box{<-22,0,0>,<22,-1,-5> rotate<-26.57,0,0> translate<0,9.5,7.5>}    //Schraege innen oben
         box{<-22,0,0>,<22,-1,5> rotate<26.57,0,0> translate<0,9.5,-7.5>}     //Schraege innen unten
         }
      box{<-23,-1,-10>,<23,0.5,10>} //Bodennocken
      box{<-21,-1,-12>,<21,0.5,12>} //Bodennocken
      box{<-5,-1,-12>,<0,10,12> rotate<0,0,-3> translate<-22,0,0>} //Schraege kurze Seite
      box{<5,-1,-12>,<0,10,12> rotate<0,0,3> translate<22,0,0>}    //Schraege kurze Seite
      box{<-23,-1,0><23,10,-5> rotate<3,0,0> translate<0,0,-11>}   //Schraege lange Seite
      box{<-23,-1,0><23,10,5> rotate<-3,0,0> translate<0,0,11>}    //Schraege lange Seite
      box{<-6,8.3,-5>,<6,10,5>} //Aufkleberfläche*/
      cylinder{<-20.5,9.0,-9.5>,<-20.5,10.0,-9.5> 0.25}
      texture{col_ic_body_1}
      }

   // Holo-Aufkleber
   #local w=0.1;
   union {
      cylinder{<5.25,8.3,4.25>,<5.25,8.3+w,4.25>0.5}
      cylinder{<5.25,8.3,-4.25>,<5.25,8.3+w,-4.25>0.5}
      cylinder{<-5.25,8.3,4.25>,<-5.25,8.3+w,4.25>0.5}
      cylinder{<-5.25,8.3,-4.25>,<-5.25,8.3+w,-4.25>0.5}
      box{<-5.25,8.3,-4.75>,<5.25,8.3+w,4.75>}
      box{<-5.75,8.3,-4.25>,<5.75,8.3+w,4.25>}
      texture{T_Chrome_5C}
      }
   text{ttf global_fontfile_arial_bold "@CHIP" 1, 0 scale<3.3,3.3,0> rotate<90,0,0> translate<-5.5,8.3+w,1.5> texture{col_black_marking}}
   text{ttf global_fontfile_arial_bold "License SL01" 1, 0 scale<1.2,1.2,0> rotate<90,0,0> translate<-3.5,8.3+w,-2.0> texture{col_black_marking}}
   text{ttf global_fontfile_arial_bold "2001 BECK IPC" 1, 0 scale<1.2,1.2,0> rotate<90,0,0> translate<-4.0,8.3+w,-3.5> texture{col_black_marking}}

   // Pins
   union {
      #local i=-8;
      #while (i<8)
         cylinder{<i*2.54+1.27,0.5,7.62>,<i*2.54+1.27,-4.5,7.62> 0.25}
         cylinder{<i*2.54+1.27,0.5,-7.62>,<i*2.54+1.27,-4.5,-7.62> 0.25}
         #local i=i+1;
      #end

      texture{col_silver}
      }
   } // end: IC_BECK_SC12
#end

//------------------------------------------------------------------------------



/*******************************************************************************
 * Designed by Friedrich Bleikamp, fbleikamp@web.de>
 * Macro fuer B-DIL rectifier aus rectifier.lib
 * benutzt Macro DIC_PIN() aus ic.inc
 ******************************************************************************/
#macro IC_DIS_DIP4S_RECTIFIER(value)
union {
   difference{
      box{<0,0,0><9.4,3.2,6.0>}
      box{<-0.1,0,0><12,2,-2> rotate<5,0,0> translate<0,2,0>}
      box{<-0.1,0,0><12.2,2,2> rotate<-5,0,0> translate<0,2,6.6>}
      box{<0,0,6.7><-2,2,0> rotate<0,0,-35> translate<0,2,0>}
      translate<-4.7,0,-3.0>
      }
   union{
      object{IC_DIS_PIN() rotate<0,180,0> translate<2.54,-3.75,3.81>}
      object{IC_DIS_PIN() rotate<0,180,0> translate<-2.54,-3.75,3.81>}
      object{IC_DIS_PIN() translate<-2.54,-3.75,-3.81>}
      object{IC_DIS_PIN() translate<2.54,-3.75,-3.81>}
      texture{col_silver}
      }
   union{    
      text {ttf besch_font value 0.2, 0     rotate <90,0,0> scale<1.5,1,1.5> translate<-3.1,3.21,-0.3>}
      text {ttf besch_font "~     ~" 0.2, 0 rotate <90,0,0> scale<1.5,1,1.5> translate<-3.0,3.21,1.8>}
      text {ttf besch_font "+     -" 0.2, 0 rotate <90,0,0> scale<1.5,1,1.5> translate<-3.0,3.21,-2.5>}
      texture{col_bright_marking}
      }
   translate<0,0.25,0>
   texture{col_ic_body_1}
   } // end: IC_DIS_DIP4S_RECTIFIER
#end

//------------------------------------------------------------------------------

