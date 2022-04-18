

/*******************************************************************************
 * resettable PTC fuse, MF-MSMF by Bourns
 * https://www.mouser.de/datasheet/2/54/mf_msmf-772347.pdf
 ******************************************************************************/
#macro MF_MSMF_style2(A,B,C)
  union {
    difference {
      box{<-A/2,0.05,-B/2><A/2,C,B/2>}
      cylinder{<+A/2,0,0><+A/2,C+0.1,0> B/6}
      cylinder{<-A/2,0,0><-A/2,C+0.1,0> B/6}
      texture{ Gold_Metal }
      }
    box{<-A/4,0,-B/2-0.05><+A/4,C+0.05,+B/2+0.05> pigment{Gray25}}
    text {ttf besch_font value 0.5,0  rotate<90,90,0> translate<-0.3,C+0.1,B/2-0.5> texture{e3d_tex_ic_marking_bright}}
    }
#end


#macro MF_MSMF050_style2()
union {
   #local value = "502I";
   MF_MSMF_style2(4.5,3.2,0.6)
   }
#end
