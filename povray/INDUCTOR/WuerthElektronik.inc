/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Macros for LF type inductors from WE
 * Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
 * Rev. 1.1  17/01/08
 * pin=pin diamenter
 * ep=thickness
 ******************************************************************************/
#macro WE_GI_LF_BASE(a,b,c,d1,ep,pin,value,lpin,dd,os)
  #local dd=(b-ep)/2;//dd=(a-d1)/2; //pin holder diameter
  #if(d1=0)
      #local d1=a-dd;
  #end
  #local d=1.5;      //edge diameter
  #local LA=c/4;     //bisel lenght
  #local tc=7;       //pin holder cylinders top
  #local bc=1;       //pin holder cylindres base
  #local dm=0.2;     //pin holder cylinder edge diameter
  #local hb=4;       //base height
  #local lp=4.5;     //wedge width
  #local LT=a-d-(LA*sqrt(2));//top length
  #local LH=c-d/2-(sqrt(2)*LA/2);//zero to bisel height
  #local bends1=array[9] { <0,LH, 0>, <+45, 0.001, 0>, <0,LA,0>, <45,0.001,0>, <0, LT, 0>, <45, 0.001, 0>, <0,LA,0>, <45,0.001,0>,<0, LH, 0> }
  #local bends2=array[9] { <0,LA/2, 0>, <+90, 0.001, 0>, <0,ep-d,0>, <90,0.001,0>, <0, LA, 0>, <90, 0.001, 0>, <0,ep-d,0>, <90,0.001,0>, <0,LA/2, 0> }

  union {
     difference {
        union {
           object {
              TOOLS_BENTPIPE( d/2, <-a/2+d/2,0,0>, +y, bends1 )
              translate (-ep/2+d/2)*z
              }
           object {
              TOOLS_BENTPIPE( d/2, <-a/2+d/2,0,0>, +y, bends1 )
              translate (+ep/2-d/2)*z
              }
           object {
              TOOLS_BENTPIPE( d/2, <-ep/2+d/2,0,0>, +y, bends2 )
              rotate <45,90,0>
              translate <-a/2+d/2+(sqrt(2)/2*LA)/2,LH+(sqrt(2)/2*LA)/2,0>
              }
           object {
              TOOLS_BENTPIPE( d/2, <+ep/2-d/2,0,0>, +y, bends2 )
              rotate <45,-90,0>
              translate <+a/2-d/2-(sqrt(2)/2*LA)/2,LH+(sqrt(2)/2*LA)/2,-ep+d>
              }
           box {<-a/2+d/2,0,-ep/2> <+a/2-d/2,LH,+ep/2>} //inside
           box {<-a/2,0,-ep/2+d/2> <+a/2,LH,+ep/2-d/2>} //inside
           box {<-LT/2,0,-ep/2+d/2> <+LT/2,c,+ep/2-d/2>}//top
           box {<-LT/2,0,-ep/2> <+LT/2,c-d/2,+ep/2>}//top inside
           box {<-LA/2,LA/2,-ep/2> <+LA/2,-LA/2,+ep/2> rotate 45*z translate <-a/2+(sqrt(2)/2*LA)+d/2,c-(sqrt(2)/2*LA)-d/2,0> }
           box {<-LA/2,LA/2,-ep/2> <+LA/2,-LA/2,+ep/2> rotate 45*z translate <+a/2-(sqrt(2)/2*LA)-d/2,c-(sqrt(2)/2*LA)-d/2,0> }
           box {<-LA/2,-LA/2,-ep/2+d/2> <+LA/2,LA/2,+ep/2-d/2> rotate 45*z translate <+a/2-(sqrt(2)/2*LA)-0.22,c-(sqrt(2)/2*LA)-0.22,0> }
           box {<-LA/2,-LA/2,-ep/2+d/2> <+LA/2,LA/2,+ep/2-d/2> rotate 45*z translate <-a/2+(sqrt(2)/2*LA)+0.22,c-(sqrt(2)/2*LA)-0.22,0> }
           box {<-a/2+d/2,2,-ep/2-0.5> <+a/2-d/2,hb,+ep/2-0.5>} //base
           box {<+a/2,0,-ep/2> <+a/2-dd/2,tc-dm/2,+ep/2>}
           box {<-a/2,0,-ep/2> <-a/2+dd/2,tc-dm/2,+ep/2>}
           }
        box {<-a/2-10,-0.1,-ep/2-10> <+a/2+10,2,+ep/2+10>}
        text { ttf global_fontfile_arial_bold "WE" 0.07, 0  scale <3,5,4> rotate <45,90,0> translate <-a/2+0.7+os,c-(sqrt(2)/2*LA)-0.22+0.7+os,2.6>}
        }

     //wedges
     box {<-a/2+0.2,0,-lp/2> <-a/2+1,3,+lp/2>}
     box {<+a/2+0.2,0,-lp/2> <+a/2-1,3,+lp/2>}
     //pins
     cylinder {<-d1/2+dd/2+lpin,bc,-ep/2> <-d1/2+dd/2+lpin,-4,-ep/2> pin/2 texture{col_silver}}
     cylinder {<+d1/2-dd/2-lpin,bc,-ep/2> <+d1/2-dd/2-lpin,-4,-ep/2> pin/2 texture{col_silver}}
     cylinder {<-d1/2+dd/2+lpin,bc,+ep/2> <-d1/2+dd/2+lpin,-4,+ep/2> pin/2 texture{col_silver}}
     cylinder {<+d1/2-dd/2-lpin,bc,+ep/2> <+d1/2-dd/2-lpin,-4,+ep/2> pin/2 texture{col_silver}}
     #if(lpin=0)
        #local lpin=5.21;
     #end

     //pin holder cylinders
     cylinder { <-d1/2+dd/2,bc,-ep/2> <-d1/2+dd/2,tc-dm/2,-ep/2>, dd }
     cylinder { <+d1/2-dd/2,bc,-ep/2> <+d1/2-dd/2,tc-dm/2,-ep/2>, dd }
     cylinder { <-d1/2+dd/2,bc,+ep/2> <-d1/2+dd/2,tc-dm/2,+ep/2>, dd }
     cylinder { <+d1/2-dd/2,bc,+ep/2> <+d1/2-dd/2,tc-dm/2,+ep/2>, dd }
     cylinder { <-d1/2+dd/2+lpin,bc,-ep/2> <-d1/2+dd/2+lpin,tc-dm/2,-ep/2>, dd }
     cylinder { <+d1/2-dd/2-lpin,bc,-ep/2> <+d1/2-dd/2-lpin,tc-dm/2,-ep/2>, dd }
     cylinder { <-d1/2+dd/2+lpin,bc,+ep/2> <-d1/2+dd/2+lpin,tc-dm/2,+ep/2>, dd }
     cylinder { <+d1/2-dd/2-lpin,bc,+ep/2> <+d1/2-dd/2-lpin,tc-dm/2,+ep/2>, dd }
     //top of pin holder cylinders
     torus { dd-dm,dm translate <-d1/2+dd/2,tc-dm/2, -ep/2> }
     torus { dd-dm,dm translate <+d1/2-dd/2,tc-dm/2, -ep/2> }
     torus { dd-dm,dm translate <-d1/2+dd/2,tc-dm/2, +ep/2> }
     torus { dd-dm,dm translate <+d1/2-dd/2,tc-dm/2, +ep/2> }
     torus { dd-dm,dm translate <-d1/2+dd/2+lpin,tc-dm/2, -ep/2> }
     torus { dd-dm,dm translate <+d1/2-dd/2-lpin,tc-dm/2, -ep/2> }
     torus { dd-dm,dm translate <-d1/2+dd/2+lpin,tc-dm/2, +ep/2> }
     torus { dd-dm,dm translate <+d1/2-dd/2-lpin,tc-dm/2, +ep/2> }
     cylinder { <-d1/2+dd/2,bc,-ep/2> <-d1/2+dd/2,tc+dm/2,-ep/2>, dd-dm }
     cylinder { <+d1/2-dd/2,bc,-ep/2> <+d1/2-dd/2,tc+dm/2,-ep/2>, dd-dm }
     cylinder { <-d1/2+dd/2,bc,+ep/2> <-d1/2+dd/2,tc+dm/2,+ep/2>, dd-dm }
     cylinder { <+d1/2-dd/2,bc,+ep/2> <+d1/2-dd/2,tc+dm  ,+ep/2>, dd-dm }
     cylinder { <-d1/2+dd/2+lpin,bc,-ep/2> <-d1/2+dd/2+lpin,tc+dm/2,-ep/2>, dd-dm }
     cylinder { <+d1/2-dd/2-lpin,bc,-ep/2> <+d1/2-dd/2-lpin,tc+dm/2,-ep/2>, dd-dm }
     cylinder { <-d1/2+dd/2+lpin,bc,+ep/2> <-d1/2+dd/2+lpin,tc+dm/2,+ep/2>, dd-dm }
     cylinder { <+d1/2-dd/2-lpin,bc,+ep/2> <+d1/2-dd/2-lpin,tc+dm/2,+ep/2>, dd-dm }

     //marks
     text { ttf global_fontfile_alphalcd value 0.01, 0  pigment {Black} scale <2.3,2.3,2> rotate <0,0,0> translate <-a/2+1+(a-18.5)/2,tc+1+(c-20.5)/2,-ep/2-0.05>}
     text { ttf global_fontfile_alphalcd " WE  1OO7" 0.01, 0  pigment {Black} scale <2.3,2.3,2> rotate <0,0,0> translate <-a/2+1+(a-18.5)/2,tc+3.8+(c-20.5)/2,-ep/2-0.05>}
     text { ttf global_fontfile_alphalcd "2*39mHO,4A" 0.01, 0  pigment {Black} scale <2.3,2.3,2> rotate <0,0,0> translate <-a/2+1+(a-18.5)/2,tc+6.6+(c-20.5)/2,-ep/2-0.05>}
     //solded wire
     /*
     sphere { <-d1/2+lpin,bc/2,-ep/2>, pin  texture{col_silver}}
     sphere { <-d1/2+lpin,bc/2,+ep/2>, pin  texture{col_silver}}
     sphere { <+d1/2-lpin,bc/2,-ep/2>, pin  texture{col_silver}}
     sphere { <+d1/2-lpin,bc/2,+ep/2>, pin  texture{col_silver}}
     */

     pigment {Brown}
     }
#end

#macro SPC_L_WE_LF612SV(value)  WE_GI_LF_BASE(18.5,13.5,20.5,15.5+1.5,10  ,0.6,value,0   ,3  ,0   ) #end
#macro SPC_L_WE_SV(value)       WE_GI_LF_BASE(18.5,13.5,20.5,       0,10  ,0.6,value,5.21,3  ,0   ) #end
#macro SPC_L_WE_LF622MV(value)  WE_GI_LF_BASE(23.5,16.0,25.5,       0,12.5,0.6,value,5   ,3  ,0.45) #end
#macro SPC_L_WE_LF632LV(value)  WE_GI_LF_BASE(26.5,18.5,30.5,       0,15  ,0.6,value,5.25,3  ,0.9 ) #end
#macro SPC_L_WE_LF642XV(value)  WE_GI_LF_BASE(32.5,21.5,35.5,       0,17.5,0.8,value,8   ,3.5,1.4 ) #end



/*******************************************************************************
 * by Anderas Fecht
 ******************************************************************************/
#macro SPC_L_WE_PD4(value)
  #local OBERFLAECHE = texture { // Die Oberflaechenstruktur
      pigment {White*.3}
      }

  #local L_QUAD = union { // Objekte des Spulenkoerpers
     cylinder {<0,-0.175,0> <0,0.175,0> 1.15 texture { OBERFLAECHE } }
     torus { 1.15 0.175 texture { OBERFLAECHE } }
     }

  #local Drahtstaerke = 0.025;

  #local L_Boden = difference {
     union {
        box {<-1.5,0,-1.45> <1.5,0.275,1.45> texture { OBERFLAECHE }}
        box {<-2,0,-1.5> <-1.5,0.3,1.5> texture{T_Silver_1A}}
        box {<2,0,-1.5> <1.5,0.325,1.5> texture{T_Silver_1A}}
        union {
           difference {
              cylinder {<0,0,0> <0,0.45,0>1.4 texture{ OBERFLAECHE }}
              cylinder {<-2,0.45,1> <0,0.45,0.5> 0.2}
              cylinder {<2,0.45,-1> <0,0.45,-0.5> 0.2}
              }
           cylinder {<-1.8,0.2,1> <0,0.5,0.5> Drahtstaerke texture{T_Gold_1A }}
           cylinder {<1.8,0.2,-1> <0,0.5,-0.5> Drahtstaerke texture{T_Gold_1A }}
           }
        }
     box {<3,-0.5,-1.5> <1.5,0.5,1.5> rotate <0,60,0>  texture { OBERFLAECHE }}
     box {<3,-0.5,-1.5> <1.5,0.5,1.5> rotate <0,-60,0> texture { OBERFLAECHE }}
     box {<-3,-0.5,-1.5> <-1.5,0.5,1.5> rotate <0,60,0> texture { OBERFLAECHE }}
     box {<-3,-0.5,-1.5> <-1.5,0.5,1.5> rotate <0,-60,0> texture { OBERFLAECHE }}
     }

  #local L_CORE = cylinder {
     <0, 0, 0> <0, 1, 0>1 texture {OBERFLAECHE }
     }

  #local L_KERN = union {
     object{L_Boden}
     object{L_CORE translate y*0.25}
     object{L_QUAD translate y*1.25}
     }


  #local L_WINDUNG = torus { // Kupferlackkabelemente
     1.1, Drahtstaerke/2
     texture {T_Gold_1A }
     }

  #local L_SPULE = union {
     #local i=0;
     #while(i<33)
        object{L_WINDUNG translate i*Drahtstaerke*y}
        #local i=i+1;
     #end
     }

  #local L_BAUTEIL = union { // Zusammenbau der Spule:
     object{L_KERN}
     object{L_SPULE translate (0.3+Drahtstaerke/2)*y}
     text { ttf besch_font value 0.1, 0 pigment {White} scale 0.5 rotate 90*x rotate 180*y translate <0.7,1.45,0.2>}
     scale 3
     }

  object{L_BAUTEIL}
#end


/*******************************************************************************
 * by Anderas Fecht
 ******************************************************************************/
#macro SPC_L_WE_PDM(value)
  union {
     difference {
        union {
           difference {
              box {<-3.65,0.5,-3.65> <3.65,4,3.65> }
              cylinder { < 3.65,0, 3.65> < 3.65,5, 3.65> 1 }
              cylinder { <-3.65,0, 3.65> <-3.65,5, 3.65> 1 }
              cylinder { < 3.65,0,-3.65> < 3.65,5,-3.65> 1 }
              cylinder { <-3.65,0,-3.65> <-3.65,5,-3.65> 1 }
              }
           cylinder { < 2.65,0.5, 2.65> < 2.65,4, 2.65> 1 }
           cylinder { <-2.65,0.5, 2.65> <-2.65,4, 2.65> 1 }
           cylinder { < 2.65,0.5,-2.65> < 2.65,4,-2.65> 1 }
           cylinder { <-2.65,0.5,-2.65> <-2.65,4,-2.65> 1 }
           pigment { rgb <0.3, 0.3, 0.3> }
           }
        box {<-3.5,3.9,-0.7> <3.5,4.5,0.7> rotate <0, 45, 0>}
        box {<-3.5,3.9,-0.7> <3.5,4.5,0.7> rotate <0, -45, 0>}
        cylinder { <0,3.9,0> <0,5,0> 2.7 }
        pigment {rgb <0.3, 0.3, 0.3>}
        }
     text { ttf besch_font value 0, 0 pigment {White} scale<1.5,2,2> rotate <90,-90,0> translate <1,3.95,-2>}
     }

#end



/*******************************************************************************
 * dahamm(at)gmx.net
 ******************************************************************************/
#macro SPC_L_WE_PD_BASE(value, A, B, C, D)
  #local r = 2;          //Kantenradius
  #local s = 0.5;        //Gehaeuseanhebung
  #local ri = A / 2 - 1; //Kernradius
  #local rx = A / 10;

  union {
     difference {
        union {
           cylinder {<A/2 - r, s, A/2 - r> <A/2 - r, s + B, A/2 - r> r}
           cylinder {<-A/2 + r, s, A/2 - r> <-A/2 + r, s + B, A/2 - r> r}
           cylinder {<A/2 - r, s, -A/2 + r> <A/2 - r, s + B, -A/2 + r> r}
           cylinder {<-A/2 + r, s, -A/2 + r> <-A/2 + r, s + B, -A/2 + r> r}
           box {<A/2, s, A/2 - r> <-A/2, s + B, -A/2 + r>}
           box {<A/2 - r, s, A/2> <-A/2 + r, s + B, -A/2>}
           }
        cylinder {<0.707 * ri, 0, 0.7 * ri> <0.7 * ri, s + B + 1, 0.7 * ri> rx}
        cylinder {<-0.707 * ri, 0, 0.7 * ri> <-0.7 * ri, s + B + 1, 0.7 * ri> rx}
        cylinder {<0.707 * ri, 0, -0.7 * ri> <0.7 * ri, s + B + 1, -0.7 * ri> rx}
        cylinder {<-0.707 * ri, 0, -0.7 * ri> <-0.7 * ri, s + B + 1, -0.7 * ri> rx}
        }
     torus {ri - 0.5, 0.5 translate <0, s + B, 0>}
     cylinder {<0, s + B, 0> <0, s + B + 0.5, 0> ri - 0.5}
     box {<-D/2, 0, A/2> <D/2, s, A/2 - C/2> texture{col_silver}}
     box {<-D/2, 0, -A/2> <D/2, s, -A/2 + C/2> texture{col_silver}}
     text { ttf besch_font value 1, 0 pigment {Gray80} scale 2  rotate <90,0,0> translate <-2,s + B + 0.8, 0>}
     pigment {Gray20}
     rotate <0, 90, 0>
     }
#end

#macro SPC_L_WE_PD_S(value)
  SPC_L_WE_PD_BASE(value, 7.3, 3.2, 1.5, 1.5)
#end

#macro SPC_L_WE_PD_M(value)
  SPC_L_WE_PD_BASE(value, 7.3, 4.5, 2.0, 1.5)
#end

#macro SPC_L_WE_PD_L(value)
  SPC_L_WE_PD_BASE(value, 12.0, 6.0, 8.0, 5.0)
#end

#macro SPC_L_WE_PD_XL(value)
  SPC_L_WE_PD_BASE(value, 12.0, 8.0, 8.0, 5.0)
#end

#macro SPC_L_WE_PD_XXL(value)
  SPC_L_WE_PD_BASE(value, 12.0, 10.0, 7.6, 5.0)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SPC_L_WE_SV(:Inductor SV           
//=SPC_L_WE_LF612SV(:Inductor LF612/VS
//=SPC_L_WE_LF622MV(:Inductor LF622/MS
//=SPC_L_WE_LF632LV(:Inductor LF632/MS
//=SPC_L_WE_LF642XV(:Inductor LF642/MS
//=SPC_L_WE_PD4(:Wuerth Chip Coil
//=SPC_L_WE_PDM(:Wuerth SMT Coil
//=SPC_L_WE_PD_S(:Inductor WE-PD Wuerth Elektronik
//=SPC_L_WE_PD_M(:Inductor WE-PD Wuerth Elektronik
//=SPC_L_WE_PD_L(:Inductor WE-PD Wuerth Elektronik
//=SPC_L_WE_PD_XL(:Inductor WE-PD Wuerth Elektronik
//=SPC_L_WE_PD_XXL(:Inductor WE-PD Wuerth Elektronik
// end assignment
