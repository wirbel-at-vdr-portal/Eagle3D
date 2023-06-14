/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/********************************************************************************************************************************************
//AK-700 Klemme ohne Mittelanschluss RM 5.0 Uwe Lorenz <u.lorenz@er-dresden.net>
********************************************************************************************************************************************/
#macro CON_AK700_3_5_BASE()
union {
cylinder{<-5,-4,0><-5,1.1,0>0.6 texture{col_silver}}
cylinder{<5,-4,0><5,1.1,0>0.6 texture{col_silver}}
//  Grundkoerper
difference {
box{<-7.5,0,-5><7.5,19,5>}
// mittlerer Anschluss
box{<-2,3.9,-5.01><2,9.5,3.5>}
// linker Anschluss
box{<-6.5,3.9,-5.01><-2.5,9.5,3.5>}
// rechter Anschluss
box{<2.5,3.9,-5.01><6.5,9.5,3.5>}
//  vordere Schraege
box{<-7.6,9,-6.0><7.6,25,-1.1> rotate<20,0,0> translate<0,0,-8.7>}
//  hintere Kante
box{<-7.6,10,3><7.6,19.1,5.1> }
//  Aussparungen hinten
box{<-1.4,6,3.4><1.4,10.1,5.1> }
box{<-6.2,6,3.4><-3.1,10.1,5.1> }
box{<3.1,6,3.4><6.2,10.1,5.1> }
//  mittleres Borhloch
cylinder{<0,15.9,0><0,19.1,0>1.8}
//  linkes Borhloch
cylinder{<-5,15.9,0><-5,19.1,0>1.8}
//  rechtes Borhloch
cylinder{<5,15.9,0><5,19.1,0>1.8}
//  Nut an der rechten Seite
box{<7.0,0.0,-3.4><7.6,13.0,-4.0> }
}
//  Ende Grundkoerper
//
//  Steg an der linken Seite
box{<-7.4,1.0,-3.4><-8.0,13.0,-4.0> }
//  Silberfahnen hinten
box{<-6.0,6,3.8><-3.4,9.1,4.5> texture{col_silver} }
box{<3.4,6,3.8><6.0,9.1,4.5> texture{col_silver} }
//Silberknubbeln an den Silberfahnen
box{<-5.4,6.3,3.8><-4.0,7.3,4.8> texture{col_silver} }
box{<4.0,6.3,3.8><5.4,7.3,4.8> texture{col_silver} }
//  Ende hintere Silberfahnen
//
//  rechter Schraubenkopf
difference {
superellipsoid{<1,0.1> rotate<90,0,0> scale<1.5,0.5,1.5> texture{col_silver} translate<-5,18.2,0>}
box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> texture{col_silver} translate<-5,18.2,0>}}
//  linker Schraubenkopf
difference {
superellipsoid{<1,0.1> rotate<90,0,0> scale<1.5,0.5,1.5> texture{col_silver} translate<5,18.2,0>}
box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> texture{col_silver} translate<5,18.2,0>}}
//  Ende Schraubenkoepfe
//
//  linke Zugbuegelklemme
difference {
box{<-6.4,4.1,-3.5><-2.6,9.4,2.5>}
box{<-6.2,4.2,-3.6><-2.8,9.4,2.6>}
texture{col_silver}}
cylinder{<-5.8,9.0,-3.3><-3.1,9.0,-3.3>1.0 texture{col_silver}}
//  rechte Zugbuegelklemme
difference {
box{<2.6,4.1,-3.5><6.4,9.4,2.5>}
box{<2.8,4.2,-3.6><6.2,9.4,2.6>}
texture{col_silver}}
cylinder{<3.2,9.0,-3.3><5.8,9.0,-3.3>1.0 texture{col_silver}}
//  Ende Zugbuegelklemme
//
pigment{LimeGreen} translate<0,0.2,0>}
#end

#macro CON_AK700_3_5()
CON_AK700_3_5_BASE()
#end



/********************************************************************************************************************************************
//DC-Power-Connector by Nigel Eke
********************************************************************************************************************************************/
#macro CON_DCPOWERCONNECTOR_BASE()
  #local endcutaway = union { cylinder { <10,5,3> <11.01,5,3> 3.01 }
                              box { <10,1.99,-.01> <11.01,5,6.01> }
                              box { <10,-.01,2> <11.01,2.01,4> }
                              pigment { Gray20} }
  #local innercutaway = cylinder { <-.01,5,3> <9,5,3> 2 pigment { Gray75} }
  #local housing_rough = union { box { <0,0,0> <2,8,6> }
                                 cylinder { <2,5,3> <11,5,3> 3 }
                                 box { <2,0,0> <11,5,6> }
                                 pigment { Gray20 }
                                 finish { Shiny  ambient (0.1 * global_ambient_mul)} }
  #local housing_refined = difference { object { housing_rough }
                                        object { endcutaway }
                                        object { innercutaway } }
  #local innerconnector = union { cylinder { <1,5,3> <8.5,5,3> .25 }
                                  cylinder { <8.5,5,3> <9,5,3> .75 }
                                   texture { Silver_Metal } }
  #local pin = box { <-1,-4,-.25> <1,3.5,.25> texture { Silver_Metal } }
  #local endconnector = difference { union { cylinder { <0,0,-.25><0,0,.25> 2 }
                                             cylinder { <0,0,-.99><0,0,.7> .8 } }
                                     cylinder { <0,0,-1> <0,0,.71> .6 }
                                     texture { Silver_Metal }
                                     translate <0,5,0> }

  union { object { housing_refined }
          object { innerconnector }
          object { pin rotate<0,90,0> translate<6,0,3> }
          object { pin translate<8,0,1> }
          union { difference { object { pin }
                               cylinder { <0,2,-.26> <0,2,.26> .2
texture { Silver_Metal} } }
                  object { endconnector }
                  rotate<0,90,0>
                  translate<10,0,3> } }

  translate<-5.5,0,-3>
  rotate<0,-90,0>
  scale 2.54/2
#end
#macro CON_DCPOWERCONNECTOR()
CON_DCPOWERCONNECTOR_BASE()
#end

/*******************************************************************************
 * similar to CON_DCPOWERCONNECTOR
 ******************************************************************************/
#macro CON_DC21MM()
  union {
     difference {
        union {
           Round_Box( <-9/2,0,-7.5>, <9/2,11,-7.5+3>, 0.5, 0 )
           Round_Box( <-9/2,0,-7.5>, <9/2,6.5,3.2+2.5/2>, 0.5, 0 )
           cylinder { <0,6.5,-7.5> <0,6.5,3.2+2.5/2> 4.5 }
           box { <-8.8/2,0,3.2+2.5/2> <8.8/2,6.5,-7.5+14.2> }
           cylinder { <0,6.5,3.2+2.5/2> <0,6.5,-7.5+14.2> 4.4 }
           }
        box { <-9/2,3.5,-7.5+13.2> <9/2,11.2,-7.5+14.3> }
        box { <-2.5/2,-0.1,-7.5+13.2> <2.5/2,4,-7.5+14.3> }
        cylinder { <0,6.5,-8> <0,6.5,-7.5+10> 5.5/2 }
        pigment { Gray20 } finish { Shiny  ambient (0.1 * global_ambient_mul) }
        }
     union {
        cylinder { <0,6.5,-1.0> <0,6.5,3.2+2.5/2> 2.1/2 }
        sphere   { <0,6.5,-1.0> 2.1/2 }
        cylinder { <0,6.5,3.2+2.8-0.5/2> <0,6.5,3.2+2.8+0.5/2> 4/2 }
        cylinder { <0,6.5,3.2+2.8-0.5/2> <0,6.5,3.2+2.8+0.5  > 1.5/2 }

        difference {
           union {
              box      { <-2.5/2,6,3.2+2.8-0.5/2> <2.5/2,-4.1-2.5/2,3.2+2.8+0.5/2> }
              cylinder { <0,-4.1-2.5/2,3.2+2.8-0.5/2> <0,-4.1-2.5/2,3.2+2.8+0.5/2> 2.5/2 }
              }
           cylinder { <0,-4.1-2.5/2,3.2+2.8-0.6/2> <0,-4.1-2.5/2,3.2+2.8+0.6/2> 1.2/2 }
           }
        difference {
           union {
              box      { <-2.5/2,6,3.2+2.8-0.5/2> <2.5/2,-4.1-2.5/2,3.2+2.8+0.5/2> }
              cylinder { <0,-4.1-2.5/2,3.2+2.8-0.5/2> <0,-4.1-2.5/2,3.2+2.8+0.5/2> 2.5/2 }
              }
           cylinder { <0,-4.1-2.5/2,3.2+2.8-0.6/2> <0,-4.1-2.5/2,3.2+2.8+0.6/2> 1.2/2 }
           translate<0,0,-2.8-3.2>
           }
        difference {
           union {
              Round_Box( <4.8-0.5  ,0,3.2-2.5/2>, <4.8+0.5/2,2.5,3.2+2.5/2>  , 0.25, 0)
              box      { <4.8-0.5/2,1.0,3.2-2.5/2>, <4.8+0.5/2,-4.1-2.5/2,3.2+2.5/2> }
              cylinder { <4.8-0.5/2,-4.1-2.5/2,3.2> <4.8+0.5/2,-4.1-2.5/2,3.2> 2.5/2 }
              }
           cylinder { <4.8-0.5,-4.1-2.5/2,3.2> <4.8+0.5,-4.1-2.5/2,3.2> 1.2/2 }
           }
        texture { Silver_Metal }
        }
     rotate<0,180,0>
     }
#end

/********************************************************************************************************************************************
//Macro fuer Hohlstecker-Printeinbau (HEBO 13 - Reichelt.de)
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro CON_DC_JACK_HEBO_13_BASE()
union { 
 //Stift 
 union {
       cylinder{<0, 4.5, 0><5.5, 4.5, 0> 0.65}
       cylinder{<0, 4.5, 0><0.2, 4.5, 0> 0.9} 
       sphere {<5.5, 4.5, 0> 0.65}
       texture{col_silver}
       translate<-0.7, 0, 0>
 } 
 //Gehaeuse
 difference {
        union {
        box{<-5.75,0,-2.5><5.75,4.5,2.5>}
        cylinder{<-5.75, 4.5, 0><5.75, 4.5, 0> 2.5}
  }
  box{<-5.25,2.5,-10><-10, 20, 10>}
  box{<-0.75,2.5,-10><10, 20, 10>}
 } 
 //PIN
 union {
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<0,0,-90>
       translate<-1.05,0,0>
       texture{col_silver}
 }
 //PIN
 union {
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<0,0,-90>
       translate<-5.75,0,0>
       texture{col_silver}
 }
 //PIN
 union {
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<-90,0,-90>
       translate<-3.2,0,3.25>
       texture{col_silver}
 } 
 difference {
            cylinder{<0,0,0><1.8,0,0>0.75}
            cylinder{<-1,0,0><2.8,0,0>0.45} 
            box{<-10,0,-10><10,-10,10>}
            box{<-10,-10,0><10,10,-10>}
            texture{col_silver}
            translate<-4.1,0,2.5>
 }
 //Feder
 union { 
       difference {
                  cylinder{<0,0,0><2.6,0,0>0.75}
                  cylinder{<-1,0,0><3.6,0,0>0.45} 
                  box{<-10,0,-10><10,-10,10>}
                  box{<-10,-10,0><10,10,-10>}
       }
       box{<2.6,0,0.45><0,-3,0.75>}
       box{<0,0.45,0><2.6,0.75,-3>}
       texture{col_silver}
       rotate<0,90,45>
       translate<2.5,3,1.3>
 }
 //Heckplatte
 difference {
           union {
                 cylinder{<0,0,0><0,0.3,0>1.5}
                 cylinder{<0,0,0><0,0.4,0>0.75}
                 box{<0,0,-1.5><2.5,0.3,1.5>}
                 texture{col_silver}
           }
           cylinder{<0,-1,0><0,1,0>0.3}
           rotate<0,180,90>
           translate<-5.45,4.5,0>
 }
 translate<0,0.2,0>
}
#end

#macro CON_DC_JACK_HEBO_13()
CON_DC_JACK_HEBO_13_BASE()
#end




/********************************************************************************************************************************************
// Grundmakro: Stiftleiste nach DIN41617.
// J.Bartels@arcor.de, www.mec-krefeld.de
********************************************************************************************************************************************/
#macro CON_DIS_DIN41617_BASE(Pins)
// Grundmakro: Um 90° gebogener, runder Stift eines Steckverbinders nach DIN41617.
// Parameter: Staerke ueber/unter PCB, Biegeradius (Mitte), Hoehe ueber/unter PCB-Oberkante, Laenge nach vorn (-Z), Farbe
// J.Bartels@arcor.de, www.mec-krefeld.de
#macro PIN41617 (DO,DU,R,HO,HU,L,col)
union {
   intersection{ 
      torus{ R, DO/2 rotate<0,0,90> translate<0,HO-R,-R> }
      box{ <DO/2,HO-R,DO/2><-DO/2,HO+DO/2,-R> }
   }
   cylinder{<0,-HU,0><0,HO-R-0.1,0> DU/2}
   cone{ <0,HO-R-0.1,0> DU/2 <0,HO-R,0> DO/2 }
   cylinder{<0,HO,-L+1><0,HO,-R> DO/2}
   cone{ <0, HO,-L+1>,DO/2,<0,HO,-L>,DO/2-0.3}
   texture{col}
} 
#end

// Grundmakro: Reihe von Stiften eines Steckverbinders nach DIN41617.
// J.Bartels@arcor.de, www.mec-krefeld.de
#macro PIN41617_ROW (Pins)
union {
   #local i=0;
   #while(i<Pins) 
      object{PIN41617 (1,0.8,1.2,1.6,3.3,13.9,col_gold) translate<i*2.5,0,-1.25>} 
      #local i=i+2; 
   #end
   #local i=1;
   #while(i<Pins) 
      object{PIN41617 (1,0.8,1.2,1.6+3.8,3.3,13.9+2.5,col_gold) translate<i*2.5,0,1.25>} 
      #local i=i+2; 
   #end
   translate<-(Pins/2)*2.5+1.25,0,4.5/2+2.5>
}
#end

#local A=(Pins-1)*2.5+15.6;
#local D=(Pins-1)*2.5+10;
#local E=Pins*2.5;
union {
 PIN41617_ROW( Pins )
 box{ <-E/2,0,-4.5/2><E/2,8.5,4.5/2> }
 //Befestigungs-Ohr
difference { 
 box{ <A/2,0,-4.5/2><E/2,4.2,8.1-4.5/2> }
 intersection{
   cylinder{<D/2,-1,4.5/2><D/2,1+4.2,4.5/2>,1.6}
   box{ <D/2-1.6,-1,4.5/2-1.4><D/2+1.6,1+4.2,4.5/2+1.4>}
 }  
 box{ <-(A-E-5)/2,-1,0><0,1+4.2,8.1-4.5+10> rotate<0,20,0> translate<E/2,0,4.5/2> }
}
 //Befestigungs-Ohr
difference { 
 box{ <-A/2,0,-4.5/2><-E/2,4.2,8.1-4.5/2> }
 intersection{
   cylinder{<-D/2,-1,4.5/2><-D/2,1+4.2,4.5/2>,1.6}
   box{ <-D/2+1.6,-1,4.5/2-1.4><-D/2-1.6,1+4.2,4.5/2+1.4>}
 }  
 box{ <(A-E-5)/2,-1,0><0,1+4.2,8.1-4.5+10> rotate<0,-20,0> translate<-E/2,0,4.5/2> }
}
pigment{Gray80}
}
#end

#macro CON_DIS_DIN41617_13() CON_DIS_DIN41617_BASE(13) #end
#macro CON_DIS_DIN41617_21() CON_DIS_DIN41617_BASE(21) #end
#macro CON_DIS_DIN41617_31() CON_DIS_DIN41617_BASE(31) #end


/********************************************************************************************************************************************
//Macros for connector MATE-N-LOK vertical 9263 serie from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 31-12-05
********************************************************************************************************************************************/
#macro CON_DIS_MATNLOK_9263_BASE(n,c)
#switch(c)
#case(1)
#local col=Gray90;
#break
#case(2)
#local col=Gray10;
#break
#case(3)
#local col=Brown;
#break
#case(4)
#local col=Gray90;
#break
#case(5)
#local col=Orange;
#break
#end

union {
    
    difference {
        merge {
            //body
         box{<-6.35*n/2-.5,-3.8,0><6.35*n/2+.5,3.8,14>}

         
         //lateral grips
         box{<-6.35*n/2,-1.5,6><-6.35*n/2-2.5,1.5,13.99>}
         box{<6.35*n/2,-1.5,6><6.35*n/2+2.5,1.5,13.99>}
         

         //little blocs 
            #local i=0; #while (i<n+1) box{<-(6.35*n/2)+(i*6.35)-.5,-3.8,0><-(6.35*n/2)+(i*6.35)+.5,-4.6,2> } #local i=i+1; #end
         }
         
         merge {
            //Cylindrical holes
            #local i=0; #while (i<n) cylinder{<-(6.35/2*(n-1))+(i*6.35),0,1><-(6.35/2*(n-1))+(i*6.35),0,15> 3 } #local i=i+1; #end
            //Half square holes in the first hole
            #local i=0; 
            box{<-(6.35/2*(n-1))+(i*6.35)+3,0,1><-(6.35/2*(n-1))+(i*6.35)-3,-3,15> }
            //Half square holes in the last hole
            #local i=n-1;
            box{<-(6.35/2*(n-1))+(i*6.35)+3,0,1><-(6.35/2*(n-1))+(i*6.35)-3,-3,15> }
                        
         //lateral grips
         box{<-6.35*n/2-1.5,-1.6,5><-6.35*n/2-3.5,1.6,7.5> }
         box{<+6.35*n/2+1.5,-1.6,5><+6.35*n/2+3.5,1.6,7.5> }
         
         box{<-2.5,-1.6,5><+2.5,1.6,20>  rotate -25*y translate +(6.35*n/2+9.8)*x}
         box{<-2.5,-1.6,5><+2.5,1.6,20>  rotate +25*y translate -(6.35*n/2+9.8)*x}
         }
        #if(c=1)
             texture{
               pigment { rgbf <1,1,1,0.3> }
               normal{
                 agate 0.05
                 scale 0.1
               }
               finish{ phong 0.8 phong_size 200  ambient (0.1 * global_ambient_mul)}
             }
        #else
            pigment{col}
        #end
    }
    #local i=0; #while (i<n)
        difference {
            union {
                //Pin
                cylinder{<-(6.35/2*(n-1))+(i*6.35),0,-2><-(6.35/2*(n-1))+(i*6.35),0,4> 0.85  }
                cylinder{<-(6.35/2*(n-1))+(i*6.35),0,4><-(6.35/2*(n-1))+(i*6.35),0,10.5> 1.05  }
                //Top
                cone {<-(6.35/2*(n-1))+(i*6.35),0,+10.5>, 1.05, <-(6.35/2*(n-1))+(i*6.35),0,+12>, 0.3 }
                //Base
                cone {<-(6.35/2*(n-1))+(i*6.35),0,-2>, 0.85, <-(6.35/2*(n-1))+(i*6.35),0,-4>, 0.5 }
                
                texture { pigment{P_Silver2}}
            }
            //gap
            box{<+1,-0.1,7><-1,+0.1,14> texture{pigment{P_Silver2}} rotate(rand(global_seed)*180)*z translate<-(6.35/2*(n-1))+(i*6.35),0,0>   }
        }
    #local i=i+1; #end
    rotate <-90, 180,0>
}
#end


#macro CON_DIS_MATNLOK_9263_10_1() CON_DIS_MATNLOK_9263_BASE(2,1)  #end
#macro CON_DIS_MATNLOK_9263_10_2() CON_DIS_MATNLOK_9263_BASE(2,2)  #end
#macro CON_DIS_MATNLOK_9263_10_3() CON_DIS_MATNLOK_9263_BASE(2,3)  #end
#macro CON_DIS_MATNLOK_9263_10_4() CON_DIS_MATNLOK_9263_BASE(2,4)  #end
#macro CON_DIS_MATNLOK_9263_10_5() CON_DIS_MATNLOK_9263_BASE(2,5)  #end
#macro CON_DIS_MATNLOK_9263_11_1() CON_DIS_MATNLOK_9263_BASE(3,1)  #end
#macro CON_DIS_MATNLOK_9263_11_2() CON_DIS_MATNLOK_9263_BASE(3,2)  #end
#macro CON_DIS_MATNLOK_9263_11_3() CON_DIS_MATNLOK_9263_BASE(3,3)  #end
#macro CON_DIS_MATNLOK_9263_11_4() CON_DIS_MATNLOK_9263_BASE(3,4)  #end
#macro CON_DIS_MATNLOK_9263_11_5() CON_DIS_MATNLOK_9263_BASE(3,5)  #end
#macro CON_DIS_MATNLOK_9263_12_1() CON_DIS_MATNLOK_9263_BASE(4,1)  #end
#macro CON_DIS_MATNLOK_9263_12_2() CON_DIS_MATNLOK_9263_BASE(4,2)  #end
#macro CON_DIS_MATNLOK_9263_12_3() CON_DIS_MATNLOK_9263_BASE(4,3)  #end
#macro CON_DIS_MATNLOK_9263_12_4() CON_DIS_MATNLOK_9263_BASE(4,4)  #end
#macro CON_DIS_MATNLOK_9263_12_5() CON_DIS_MATNLOK_9263_BASE(4,5)  #end
#macro CON_DIS_MATNLOK_9263_13_1() CON_DIS_MATNLOK_9263_BASE(5,1)  #end
#macro CON_DIS_MATNLOK_9263_13_2() CON_DIS_MATNLOK_9263_BASE(5,2)  #end
#macro CON_DIS_MATNLOK_9263_13_3() CON_DIS_MATNLOK_9263_BASE(5,3)  #end
#macro CON_DIS_MATNLOK_9263_13_4() CON_DIS_MATNLOK_9263_BASE(5,4)  #end
#macro CON_DIS_MATNLOK_9263_13_5() CON_DIS_MATNLOK_9263_BASE(5,5)  #end
#macro CON_DIS_MATNLOK_9263_14_1() CON_DIS_MATNLOK_9263_BASE(6,1)  #end
#macro CON_DIS_MATNLOK_9263_14_2() CON_DIS_MATNLOK_9263_BASE(6,2)  #end
#macro CON_DIS_MATNLOK_9263_14_3() CON_DIS_MATNLOK_9263_BASE(6,3)  #end
#macro CON_DIS_MATNLOK_9263_14_4() CON_DIS_MATNLOK_9263_BASE(6,4)  #end
#macro CON_DIS_MATNLOK_9263_14_5() CON_DIS_MATNLOK_9263_BASE(6,5)  #end
#macro CON_DIS_MATNLOK_9263_15_1() CON_DIS_MATNLOK_9263_BASE(8,1)  #end
#macro CON_DIS_MATNLOK_9263_15_2() CON_DIS_MATNLOK_9263_BASE(8,2)  #end
#macro CON_DIS_MATNLOK_9263_15_3() CON_DIS_MATNLOK_9263_BASE(8,3)  #end
#macro CON_DIS_MATNLOK_9263_15_4() CON_DIS_MATNLOK_9263_BASE(8,4)  #end
#macro CON_DIS_MATNLOK_9263_15_5() CON_DIS_MATNLOK_9263_BASE(8,5)  #end
#macro CON_DIS_MATNLOK_9263_16_1() CON_DIS_MATNLOK_9263_BASE(10,1) #end
#macro CON_DIS_MATNLOK_9263_16_2() CON_DIS_MATNLOK_9263_BASE(10,2) #end
#macro CON_DIS_MATNLOK_9263_16_3() CON_DIS_MATNLOK_9263_BASE(10,3) #end
#macro CON_DIS_MATNLOK_9263_16_4() CON_DIS_MATNLOK_9263_BASE(10,4) #end
#macro CON_DIS_MATNLOK_9263_16_5() CON_DIS_MATNLOK_9263_BASE(10,5) #end









/********************************************************************************************************************************************
//Eurocard Verbinder
//Duane Clark <dclark@akamail.com>
********************************************************************************************************************************************/
#macro CON_EUROCARD_BASE(pins, rows)
union
{
  #local j = pins/rows;   // number of pins in row
  #local hs = 2.54;       // horizontal pin spacing
  #local hc = 0.9;        // horizontal centerline
  #local vs = 2.54;       // vertical pin spacing
  #local vc = 5.475;      // vertical centerline
  #local po = 7.63;       // offset to first pin
  #local ps = (j-1)*hs;   // total pin spacing
  #local mo = 2.55;       // offset to first mounting hole
  #local d = hc+10.1;     // overall body depth
  #local id = 6.4;        // inside depth
  #local w = ps+po*2;     // overall body width
  #local h = 10.95;       // overall body height
  #local io = 4.4;        // inner housing offset
  #local r = 0.5;         // pin inner radius
  #local pw = 0.60;       // pin width
  #local ph = 0.60;       // pin height
  #local pl = 8.5+vs;     // length of lower pins
  #local pcb = 1.625;     // pc board cutout height
  #local kh = 0.4;        // key height

  difference
  {
    union {
      box{<0,0,0><d,h,w> }
      // mounting hole tabs
      box{<d-12.5,0,0><0,7.125,5.1> }
      box{<d-12.5,0,w><0,7.125,w-5.1> }
    }
    // mounting hole cutouts
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> }
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> translate<0,0,w-5> }
    // mounting holes
    cylinder{<hc,-0.1,mo><hc,h,mo>1.4 }
    cylinder{<hc,-0.1,w-mo><hc,h,w-mo>1.4 }
    // pc board cutout
    box{<d-12.6,-0.1,-0.1><d-id-0.7,pcb,w+0.1> }
    // pin area cutout
    box{<d-id-0.001,1.125,io><d+0.1,h-3.625,w-io> }
    box{<d-id,2,io+1><d+0.1,h-1.125,w-io-1> }
    // upper side key outer cutouts
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> }
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> translate<0,0,w-4.175> }
    // front side cutouts
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> }
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> translate<0,0,w-3.175> }
    // front notches
    box{<d-1,-0.1,po+hs*0.5><d+0.1,h+0.1,po+hs*2.5> }
    box{<d-1,-0.1,po+hs*6.5><d+0.1,h+0.1,po+hs*8.5> }
    box{<d-1,-0.1,po+hs*16.5><d+0.1,h+0.1,po+hs*18.5> }
    box{<d-1,-0.1,po+ps-hs*6.5><d+0.1,h+0.1,po+ps-hs*8.5> }
    box{<d-1,-0.1,po+ps-hs*0.5><d+0.1,h+0.1,po+ps-hs*2.5> }
    // lower keys
    box{<d-id,1.126,po+hs*1><d,1.125-kh,po+hs*2> }
    box{<d-id,1.126,po+hs*7><d,1.125-kh,po+hs*8> }
    box{<d-id,1.126,po+hs*17><d,1.125-kh,po+hs*18> }
    box{<d-id,1.126,po+ps-hs*7><d,1.125-kh,po+ps-hs*8> }
    box{<d-id,1.126,po+ps-hs*1><d,1.125-kh,po+ps-hs*2> }
    // upper keys
    box{<d-id,h-1.126,po+hs*1><d,h-1.125+kh,po+hs*2> }
    box{<d-id,h-1.126,po+hs*7><d,h-1.125+kh,po+hs*8> }
    box{<d-id,h-1.126,po+hs*17><d,h-1.125+kh,po+hs*18> }
    box{<d-id,h-1.126,po+ps-hs*7><d,h-1.125+kh,po+ps-hs*8> }
    box{<d-id,h-1.126,po+ps-hs*1><d,h-1.125+kh,po+ps-hs*2> }
    pigment{Gray85}
  }

  // pins
  union
  {
    #local k = 0;
    #while(k<rows)
      #if (rows<3)
        #if (k>0)
          // if only two rows, then the center row is the one that is missing
          #local k = k+1;
        #end
      #end
      #local i = 0;
      #while(i<j)
        // horizontal pin
        box{<r+ph/2-pl-k*vs,0-ph/2,0-pw/2><0,ph/2,pw/2> translate<hc+8.5,vc+(k-1)*vs,po+i*hs>}
        // pin radius
        difference {
          cylinder{<0,0,0><0,0,pw>r+ph}
          cylinder{<0,0,-0.1><0,0,pw+0.1>r}
          box{<0,-2,-0.1><2,2,pw+0.1>}
          box{<-2,-2,-0.1><2,0,pw+0.1>}
          translate<hc-(k+1)*vs+r+ph/2,vc+(k-1)*vs-r-ph/2,po+i*hs-pw/2>
        }
        // vertical pin
        box{<-ph/2,-2,-pw/2><ph/2,vc+(k-1)*vs-r-ph/2,pw/2> translate<hc-(k+1)*vs,0,po+i*hs>}
        #local i = i+1;
      #end
      #local k = k+1;
    #end
    texture{col_gold}
  }

  translate<0-hc,0-pcb,0-w/2>
  translate<0,2,0>
}
#end
#macro CON_EUROCARD_96M_3_L()
CON_EUROCARD_BASE(96,3)
#end
#macro CON_EUROCARD_64M_2_L()
CON_EUROCARD_BASE(64,2)
#end




/********************************************************************************************************************************************
//FEMALE PRINT CONNECTOR DIN 45323 (34V/3A), ROKA, distributor Conrad
// Friedrich Bleikamp <fbleikamp@web.de>
********************************************************************************************************************************************/
#macro CON_FPCON65_BASE()
union {
//Kunstoff
difference {
merge {
cylinder{<0,6.5,0><10.5,6.5,0>4.25}
box {<0,0,-6>,<5.2,6.2,6>}
box {<0,0,-4>,<1.6,13,4> translate<-1.6,0,0>}
box {<0,0,-6>,<1.1,14,6> translate<-2.7,0,0>}
cylinder{<10.0,6.5,0><14.0,6.5,0>2.5}
}
cylinder{<-3,6.5,0><8.7,6.5,0>3.25}
cylinder{<8.5,6.5,0><14.6,6.5,0>2.25}
box {<0.1,-0.1,-3>,<9,14,3>}
box {<0.1,-0.1,-4.5>,<9,4.5,-5.5>}
box {<0.1,-0.1,4.5>,<9,4.5,5.5>}
pigment{Gray30}}

difference {
merge {
cylinder{<12.6,6.5,0><14,6.5,0>4.5}
box {<12.6,0,-4.5>,<14,6.5,4.5>}
box {<14,0,-4.5>,<15.5,2.5,4.5>}
}
cylinder{<12.5,6.5,0><14.1,6.5,0>2.55}
box {<0,0,-4.6>,<2,3.5,4.6> rotate <0, 0, 20> translate<15.4,-0.2,0>}
pigment{Gray30}}

//Mittenkontakt
difference {
merge {
sphere { <0, 6.5, 0>, 1.05}
cylinder{<0,6.5,0><6,6.5,0>1.05}
cylinder{<6,6.5,0><6.6,6.5,0>3}
cylinder{<6.6,6.5,0><12.1,6.5,0>2.1}
//Vernietung
difference {
torus { 2.1, 0.5 }
box {<-10,0,-10>,<10,-2.5,10> }
rotate <0, 0, -90> translate<12.0,6.5,0>}
translate<2.6,0,0> }
cone { <14.01, 6.5, 0>, 1.7, <13, 6.5, 0>, 0.0 }
cylinder{<14.0,6.5,0><18,6.5,0>1.7 }
texture{col_silver}}

//Loetanschluss Mitte
difference {
merge {
cylinder{<14,6.5,0><14.5,6.5,0>4}
box {<14,2.5,-4>,<14.5,6.5,4>}
object {TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25) rotate <90,90,180> translate<14.25,3.5,5.25>}
cylinder{<0.5,3.5,5><0.5,3.5,5.5>1 }
box {<1.25,0,5>,<3.75,2.5,5.5> }
object {TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25) rotate <-90,-90,180> translate<14.25,3.5,-5.25>}
box {<2,-2.5,5>,<3,0,5.5> }
cylinder{<0,3.5,-5><0,3.5,-5.5>1 translate<0.5,0,0>}
box {<1.25,0,-5>,<3.75,2.5,-5.5> }
box {<2,-2.5,-5>,<3,0,-5.5> }
}
cylinder{<13.9,6.5,0><14.6,6.5,0>2 }
texture{col_silver} }

//Loetanschluss Schalter
difference {
merge {
cylinder{<10.5,6.5,0><11.0,6.5,0>4 }
object {TOOLS_RECT_BOGEN(0.3,85,0.5,4,3,5) rotate <0,180,90> translate<10.75,11.75,0>}
sphere { <6.5, 11.6, 0>, 0.5 translate<0,0,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.5,3,3,2.2) rotate <0,0.0,90> translate<10.75,1.8,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.51,1,2.5,0.3) rotate <0,0,-90> translate<8.4,0.6,0>}
}
cylinder{<10.4,6.5,0><11.1,6.5,0>2.55}
texture{col_silver}}

//Isolierscheibe
difference {
cylinder{<11.0,6.5,0><11.5,6.5,0>4.5 }
cylinder{<10.9,6.5,0><11.6,6.5,0>2.51 }
pigment{Sienna}}

//Federkontakt Aussen
difference {
merge {
cylinder{<11.5,6.5,0><12.0,6.5,0>4 }
box {<11.5,4.5,-3.25>,<12.0,1.0,3.25>}
}
cylinder{<11.4,6.5,0><12.1,6.5,0>2.55 }
texture{col_silver}}

//Loetanschluss Aussen u. Schalter
difference {
merge {
cylinder{<12.05,6.5,0><12.6,6.5,0>4 }
object {TOOLS_RECT_BOGEN(0.75,39.85,0.5,4,4,0) rotate <0,180,90> translate<12.3,13.5,0>}
object {TOOLS_RECT_BOGEN(0.3,132.0,0.5,4,7.98,0) rotate <0,180,7.5> translate<10.7,13,0>}
object {TOOLS_RECT_BOGEN(0.3,90,0.5,4,0,1.65) rotate <180,0,7.5> translate<1.8,11.83,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.5,4,2,0) rotate <0,0,-27.5> translate<1.88,9.52,0>}
object {TOOLS_RECT_BOGEN(0.5,125,0.5,4,2,0) rotate <0,0,22.5> translate<4.08,8.03,0>}
box {<12.05,4.5,-1.5>,<12.6,0,1.5>}
box {<12.05,0,-0.5>,<12.5,-2.5,0.5>}
}
cylinder{<11.9,6.5,0><12.7,6.5,0>2.55 }
texture{col_silver}}
}
#end
#macro CON_FPCON65()
CON_FPCON65_BASE()
#end


/********************************************************************************************************************************************
//Macros for L115 100 junction bloc by LMI
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 du 04/01/06
********************************************************************************************************************************************/
#macro CON_LMI_L115_BASE(n)
// Macro for pin
#local CosseL115 =
union {
    difference {
        union {
            box{<-0.25,-4.5,-1.4><+0.25,+15,+1.4>  } 
            box{<-0.25,-4.5,-1.8><+0.25,+6.8,+1.4> }
        }
        
        union {  
            //connexion side pin bisel
            //length bisel
            box{<-1,-1,-3><+1,+1,+3>        rotate<0,0,45> translate<-1.1,15.4,0> }
            box{<-1,-1,-3><+1,+1,+3>        rotate<0,0,45> translate<+1.1,15.4,0> }
            //width bisel
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,15,+2.5> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,15,-2.5> }
            //solder side pin bisel
            box{<-0.8,0,-0.65><+0.8,-5,-5>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-0.8,0,+0.65><+0.8,-5,+5>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-1,-1,-1><+1,+1,+1>        rotate<120,0,0> translate<0,-4.5,+1.3> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<60,0,0> translate<0,-4.55,-1.3> }
            //holes
            cylinder { -2*x, +2*x, .4       translate <0, 12, 0> }
            cylinder { -2*x, +2*x, 1.1      translate <0, 3, 0> }
        }
    }
    texture{ pigment{P_Silver2} }
    rotate 90*y
}

#local PAS = 5.08;
union {
    //terminals
    #local i=0; 
    #while (i<n)
        //Pins
        object{CosseL115 translate<0,0,-(PAS/2*(n-1))+(i*PAS)>}
    #local i=i+1; #end
    //body
    difference {
        union {
            difference {
                box{<2.75,5,-PAS*n/2><-2.75,6,+PAS*n/2> }
                box{<1.6,5.6,-PAS*n/2-0.01><-2.0,6.01,+PAS*n/2+0.01> }
            }
            box{<-2.75,0,-PAS*n/2><-1.8,5,+PAS*n/2> }
        }  
        #local i=1; 
        #while (i<n)
            //rectangular holes
            box{<-1.2,4,-0.25><+0.8,7,+0.25> translate<0,0,-(PAS/2*(n-1))+(i*PAS)-PAS/2>}
        #local i=i+1; #end
    }
    pigment{Gray80}
    rotate 90*y

}
#end
#macro CON_LMI_L115_2()
CON_LMI_L115_BASE(2)
#end
#macro CON_LMI_L115_3()
CON_LMI_L115_BASE(3)
#end
#macro CON_LMI_L115_5()
CON_LMI_L115_BASE(5)
#end
#macro CON_LMI_L115_10()
CON_LMI_L115_BASE(10)
#end
#macro CON_LMI_L115_20()
CON_LMI_L115_BASE(20)
#end


/********************************************************************************************************************************************
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Loetoese 1.0mm Drill fuer Drahtanschluss oder Testklemme
********************************************************************************************************************************************/
#macro CON_LSP_BASE(s)
union {
   difference {
      box { <-0.8,0,-0.2>,<0.8,5,0.2> texture{col_silver} translate<0,0,0>}
      box { <-0.8,-0.2,-0.3>,<0.8,5.2,0.3> texture{col_silver} rotate<0,0,-3> translate<1.1,0,0>}
      box { <-0.8,-0.2,-0.3>,<0.8,5.2,0.3> texture{col_silver} rotate<0,0,3> translate<-1.1,0,0>}
      translate<0,-5.0,0>
   }
   difference {
      box { <-1.5,0,-0.2>,<1.5,3,0.2> texture{col_silver} translate<0,0,0>}
      box { <-0.5,1.5,-0.3>,<0.5,3.1,0.3> texture{col_silver} translate<0,0,0>}
      cylinder{<0,0,-0.3><0,0,0.3>0.5 texture{col_silver} translate<0,1.5,0>}
   }
   difference {
      cylinder{<0,0,-0.2><0,0,0.2>1.5 texture{col_silver} translate<0,3,0>}
      cylinder{<0,0,-0.3><0,0,0.3>0.5 texture{col_silver} translate<0,3,0>}
      box { <-1.5,0,-0.3>,<1.5,3,0.3> texture{col_silver} translate<0,0,0>}
   }
   scale (s/13)
}
#end
#macro CON_LSP_10()
CON_LSP_BASE(10)
#end
#macro CON_LSP_11()
CON_LSP_BASE(11)
#end
#macro CON_LSP_13()
CON_LSP_BASE(13)
#end


/********************************************************************************************************************************************
//Macros for Micro-Match female from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  16/12/07
********************************************************************************************************************************************/
#macro CON_MICROMATCH_FEMALE_BASE(pin)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6}};
#local pitch=1.27;
#local plastic_z=5;

#local plastic_x=pitch*(pin-1)+3.37;

union {
    difference {
        union {
            box{<-plastic_x/2,0.5,-plastic_z/2><plastic_x/2,2.1,plastic_z/2> } //Main box
            box{<-plastic_x/2+0.5,0.5,-plastic_z/2+0.5><plastic_x/2-0.5,4,plastic_z/2-0.5> } //Main box
        }
        box{<-plastic_x/2+0.5,0,-plastic_z/2+1><-plastic_x/2-0.1,4.1,plastic_z/2-1>}//Main box hollowing out
        box{<+plastic_x/2-0.5,0,-plastic_z/2+1><+plastic_x/2+0.1,4.1,plastic_z/2-1>}//Main box hollowing out
                #local i=0;
                #while(i<(pin/2)) //contacts apertures
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    #local i=0;
    #while(i<(pin/2))
    //pins
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        
        cylinder{<0,1,-1.4><0,3.9,-1.4> 0.15 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
        cylinder{<0,1,1.4><0,3.9,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
        difference {
            box{<-0.15,1,0><0.15,3.9,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
            box{<-0.2,1,0.5><0.2,4,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
        }
        difference {
            box{<-0.15,1,0><0.15,3.9,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> }
            box{<-0.2,1,-0.5><0.2,4,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> }
        }
        #local i=i+1;
    #end
    pigment {Silver}
}
        
#end


#macro CON_MICROMATCH_FEMALE_4()
CON_MICROMATCH_FEMALE_BASE(4)
#end
#macro CON_MICROMATCH_FEMALE_6()
CON_MICROMATCH_FEMALE_BASE(6)
#end
#macro CON_MICROMATCH_FEMALE_8()
CON_MICROMATCH_FEMALE_BASE(8)
#end
#macro CON_MICROMATCH_FEMALE_10()
CON_MICROMATCH_FEMALE_BASE(10)
#end
#macro CON_MICROMATCH_FEMALE_12()
CON_MICROMATCH_FEMALE_BASE(12)
#end
#macro CON_MICROMATCH_FEMALE_14()
CON_MICROMATCH_FEMALE_BASE(14)
#end
#macro CON_MICROMATCH_FEMALE_16()
CON_MICROMATCH_FEMALE_BASE(16)
#end
#macro CON_MICROMATCH_FEMALE_18()
CON_MICROMATCH_FEMALE_BASE(18)
#end
#macro CON_MICROMATCH_FEMALE_20()
CON_MICROMATCH_FEMALE_BASE(20)
#end


/********************************************************************************************************************************************
// Makro fuer AMP-tyco MicroMatch-Federleiste SMD-Ausfuehrung
// pin  - Anzahl Kontakte
// frm = 0 - smd, != 0 - Bedrahtet
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro CON_MICROMATCH_BASE(pin, frm)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6} finish{ambient (0.1 * global_ambient_mul)}};
#local pitch=1.27;
#local plastic_z=5;
#local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet
#if (frm = 0)
        #local plastic_Y=5.3;
#else
        #local plastic_Y=4.0;
#end

union   {
        difference {
                union   {
                        // Grundkoerper
                        box{<-plastic_x/2+0.5, 0 ,-plastic_z/2+0.5> <plastic_x/2-0.5, plastic_Y, plastic_z/2-0.5> }
                        
                        // Kranz

                        #if (frm = 0)
                                // SMD
                                difference {
                                        box{<-plastic_x/2,1.9,-plastic_z/2> <plastic_x/2    ,3.3,plastic_z/2>}
                                        #local i=0;
                                        #while(i<(pin/2))
                                                box{<-0.5,2.4,0><0.5,3.5,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                                box{<-0.5,2.4,-5><0.5,3.5,0> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                                #local i=i+1;
                                        #end
                                        box{<0,0,-plastic_z/4><plastic_x+1,5,plastic_z/4>}
                                }
                        #else                   
                                // Bedrahtet
                                box{<-plastic_x/2, 0.4 ,-plastic_z/2> <plastic_x/2, 2.0, -1.2>}
                                box{<-plastic_x/2, 0.4 , plastic_z/2> <plastic_x/2, 2.0, 1.2>}
                        #end
                }
                        
                // Ausschnitte im Kunststoff fuer SMD Pins
                #if (frm = 0)
                        #local i=0;
                        #while(i<(pin/2))
                                box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                #local i=i+1;
                        #end
                #end

                // Loecher fuer Stecker
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end

                texture{CON_MMTCH_PLASTIC_TEXTURE}
        }

        #if (frm = 0)
                // SMD Pins
                #local i=0;
                #while(i<(pin/2))
                        object{TOOLS_PCB_SMD(1,6,0.25,8) translate<0.5,-0.125,0.5> rotate<0,0,90> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture{col_silver}}
                        object{TOOLS_PCB_SMD(1,6,0.25,8) translate<-0.5,-0.125,-0.5> rotate<0,0,-90> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture{col_silver}}        
                        #local i=i+1;
                #end
        #else
                // Anschlussdraht
                #if(pin_short=off)
                        #local pp=3.0;
                #else
                        #local pp=pcb_height+pin_length;
                #end
        
                #local i=0;
                #local j=1;
                #while(i<(pin/2))
                        box{ <-pitch/2-pitch*i-0.1, 1,-pitch*j-0.25> <-pitch/2-pitch*i+0.1, -pp,-pitch*j+0.25> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
                        box{ < pitch/2+pitch*i+0.1, 1, pitch*j+0.25> < pitch/2+pitch*i-0.1, -pp, pitch*j-0.25> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
                        #local j=j*-1;
                        #local i=i+1;
                #end
        #end
}
        
#end
#macro CON_MICROMATCH_4()
CON_MICROMATCH_BASE(4,1)
#end
#macro CON_MICROMATCH_6()
CON_MICROMATCH_BASE(6,1)
#end
#macro CON_MICROMATCH_8()
CON_MICROMATCH_BASE(8,1)
#end
#macro CON_MICROMATCH_10()
CON_MICROMATCH_BASE(10,1)
#end
#macro CON_MICROMATCH_12()
CON_MICROMATCH_BASE(12,1)
#end
#macro CON_MICROMATCH_14()
CON_MICROMATCH_BASE(14,1)
#end
#macro CON_MICROMATCH_16()
CON_MICROMATCH_BASE(16,1)
#end
#macro CON_MICROMATCH_18()
CON_MICROMATCH_BASE(16,1)
#end
#macro CON_MICROMATCH_20()
CON_MICROMATCH_BASE(20,1)
#end


/********************************************************************************************************************************************
//Macros for Micro-Match male from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  16/12/07
********************************************************************************************************************************************/
#macro CON_MICROMATCH_MALE_BASE(pin)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6}};
#local pitch=1.27;
#local plastic_z=5;

#local plastic_x=pitch*(pin-1)+3.37;

union {
    difference {
        union {
            box{<-plastic_x/2,0,-plastic_z/2><plastic_x/2,3.6,plastic_z/2> } //Main box
            difference {//left hook
                box{<-0.5,-1,-0.5><0.5,1,0.5> rotate<0,0,30> translate<-plastic_x/2+0.2,2,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<-plastic_x/2,3.5,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<-plastic_x/2-1.5,2.5,0> }
            }
            difference {//right hook
                box{<-0.5,-1,-0.5><0.5,1,0.5> rotate<0,0,-30> translate<+plastic_x/2-0.2,2,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<+plastic_x/2,3.5,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<+plastic_x/2+1.5,2.5,0> }
            }
        }
        box{<-plastic_x/2+0.65,1.7,-plastic_z/2+0.5><plastic_x/2-0.65,3.61,plastic_z/2-0.5>}//Main box hollowing out
        box{<-plastic_x/2+0.65,-0.1,-plastic_z/2-0.5><plastic_x/2-0.65,0.4,plastic_z/2+0.5>}//Base hollowing out
        box{<-plastic_x/2-0.65,-0.1,-0.65><plastic_x/2+0.65,0.4,+0.65>}//Base hollowing out
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    difference {//Detrompeur
        union {
            box{<-plastic_x/2,3.6,-1.16><-plastic_x/2+0.65,7.1,1.16> } //top part
            box{<-plastic_x/2,3.6,-1.16-0.3><-plastic_x/2+0.65,3.6+0.3,1.16+0.3> } //down part        
        }
        cylinder{<-plastic_x/2-0.1,3.6+0.3,-1.16-0.3><-plastic_x/2+0.66,3.6+0.3,-1.16-0.3> 0.3}
        cylinder{<-plastic_x/2-0.1,3.6+0.3,+1.16+0.3><-plastic_x/2+0.66,3.6+0.3,+1.16+0.3> 0.3}
        box{<-plastic_x/2-0.1,5.5,0><-plastic_x/2+0.66,7.11,+1.161>}
        box{<-0.5,-0.82,-0.82><+0.5,+0.82,+0.82> rotate<45,0,0> translate<-plastic_x/2+0.3,5.5,+1.16>}                        
        box{<-0.5,-0.2,-0.2><+0.5,+0.2,+0.2> rotate<45,0,0> translate<-plastic_x/2+0.3,7.1+0.1,+0.1>}//biseaux
        box{<-0.5,-0.2,-0.2><+0.5,+0.2,+0.2> rotate<45,0,0> translate<-plastic_x/2+0.3,7.1+0.1,-1.16-0.1>}
        rotate 180*y    
            
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    #local i=0;
    #while(i<(pin/2))
    //pins
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
    //contacts    
        difference {
            box{<-0.35,1,-0.2><+0.35,3.6-0.2,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,0,0> translate<-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75+0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<+10,0,0> translate<-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75-0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,90,0> translate<-(plastic_x-3.37)/2+i*2.54+0.5,3.6-0.2,-0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,-90,0> translate<-(plastic_x-3.37)/2+i*2.54-0.5,3.6-0.2,-0.75> }
        }
        difference {
            box{<-0.35,1,-0.2><+0.35,3.6-0.2,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+0.75>}
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,0,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75+0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<+10,0,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75-0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,90,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54+0.5,3.6-0.2,+0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,-90,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54-0.5,3.6-0.2,+0.75> }
        }
        #local i=i+1;
    #end
    pigment {Silver}
}
        
#end


#macro CON_MICROMATCH_MALE_4()
CON_MICROMATCH_MALE_BASE(4)
#end
#macro CON_MICROMATCH_MALE_6()
CON_MICROMATCH_MALE_BASE(6)
#end
#macro CON_MICROMATCH_MALE_8()
CON_MICROMATCH_MALE_BASE(8)
#end
#macro CON_MICROMATCH_MALE_10()
CON_MICROMATCH_MALE_BASE(10)
#end
#macro CON_MICROMATCH_MALE_12()
CON_MICROMATCH_MALE_BASE(12)
#end
#macro CON_MICROMATCH_MALE_14()
CON_MICROMATCH_MALE_BASE(14)
#end
#macro CON_MICROMATCH_MALE_16()
CON_MICROMATCH_MALE_BASE(16)
#end
#macro CON_MICROMATCH_MALE_18()
CON_MICROMATCH_MALE_BASE(18)
#end
#macro CON_MICROMATCH_MALE_20()
CON_MICROMATCH_MALE_BASE(20)
#end


/********************************************************************************************************************************************
// Makro fuer AMP-tyco MicroMatch-Federleiste SMD-Ausfuehrung
// pin  - Anzahl Kontakte
********************************************************************************************************************************************/
#macro CON_MICROMATCH_SMD_BASE(pin)
#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6} finish{ambient (0.1 * global_ambient_mul)}};
#local pitch=1.27;
#local plastic_z=5;
#local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet

union   {
        difference {
                union   {
                        box{<-plastic_x/2+0.5,0,-plastic_z/2+0.5><plastic_x/2-0.5,5.3,plastic_z/2-0.5>}
                        difference {
                                box{<-plastic_x/2,1.9,-plastic_z/2>      <plastic_x/2    ,3.3,plastic_z/2>}
                                #local i=0;
                                #while(i<(pin/2))
                                        box{<-0.5,2.4,0><0.5,3.5,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                        box{<-0.5,2.4,-5><0.5,3.5,0> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                        #local i=i+1;
                                #end
                                box{<0,0,-plastic_z/4><plastic_x+1,5,plastic_z/4>}
                                }
                        }
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
                texture{CON_MMTCH_PLASTIC_TEXTURE}
                }
        #local i=0;
        #while(i<(pin/2))
                object{TOOLS_PCB_SMD(1,6,0.25,8) translate<0.5,-0.125,0.5> rotate<0,0,90> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture{col_silver}}
                object{TOOLS_PCB_SMD(1,6,0.25,8) translate<-0.5,-0.125,-0.5> rotate<0,0,-90> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture{col_silver}}        
                #local i=i+1;
        #end
        }    
#end

#macro CON_MICROMATCH_SMD_4()  CON_MICROMATCH_SMD_BASE(4)  #end
#macro CON_MICROMATCH_SMD_6()  CON_MICROMATCH_SMD_BASE(6)  #end
#macro CON_MICROMATCH_SMD_8()  CON_MICROMATCH_SMD_BASE(8)  #end
#macro CON_MICROMATCH_SMD_10() CON_MICROMATCH_SMD_BASE(10) #end
#macro CON_MICROMATCH_SMD_12() CON_MICROMATCH_SMD_BASE(12) #end
#macro CON_MICROMATCH_SMD_14() CON_MICROMATCH_SMD_BASE(14) #end
#macro CON_MICROMATCH_SMD_16() CON_MICROMATCH_SMD_BASE(16) #end
#macro CON_MICROMATCH_SMD_18() CON_MICROMATCH_SMD_BASE(16) #end
#macro CON_MICROMATCH_SMD_20() CON_MICROMATCH_SMD_BASE(20) #end


/********************************************************************************************************************************************
// Makro fuer einfache MODULAR-Buchsen RJ-45 (8pol) RJ-12 (6pol) RJ11 (4pol) u.ae.,    con-amp.lib ,     Joerg Bredendiek <sprut(replace with at)sprut.de>   
//
// plastik schwarz, Schirmung Silber
// Darstellung ist vereinfacht 
// 
//
// pins   = Anzahl der Pins , 2, 4, 6, 8
// a      = Abstand zwischen den Mitten der Montagestifte  
// o      = Abstand zwischen Mittlepunkt und Verbindungslinie der Befestigungszapfen (Offset)  
// schirm = 0-kein, 1-voll, 2-teilweise  
// stop   = 0-kein, 1-panel-stop
********************************************************************************************************************************************/
#macro CON_MODULAR_BASE(pins,a,o,schirm,stop)
#local tex_rj45_pastic1= texture { pigment{White*0.3} finish {specular 1 roughness 0.001 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;   //etwas glatter/glaenzender
#local tex_rj45_pastic = texture { pigment{White*0.3} finish {specular 0.1 roughness 0.1 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;
// Aussenabmasse 6 pins : 13.4  x  12.8  x  18.0 BHT   
// Breite ist bauformabhaengig

#local bb = a+3;
#local bh = 12.8;
#local bt = 18.0;          


// Ausbruch im Kunststoff
// 4 pin ??
// 6 pin - 10 mm
// 8 pin - 12 mm
#local stecker2 = 
      difference
      {
         union
         {
            box{<-bb/2+1.5,  3.7, -11.7><bb/2-1.5, 11.5, 4.8>}
            box{<-bb/2+3.1,  2.5, -11.7><bb/2-3.1, 11.5, 4.8>}
            box{<-bb/2+5.6,  0.7, -11.7><bb/2-5.6, 11.5, 4.8>}
            box{<-1  , -1  , -2><16      ,  1  ,  2  >rotate<-30,0,0>translate<-bb/2,4.4,-21.4/2> pigment{White*0.5}}
            box{<-1  ,  0  , -1><16      ,  0.5,  1  >rotate<-30,0,0>translate<-bb/20,2.0,-21.4/2> pigment{White*0.5}}
         }
         box{<-bb/2-1   , -1  ,  4.3 >< -bb/2+ 16  ,15 , 5.3>}
         box{<-bb/2-1   , -1  ,-11.7 >< -bb/2+ 1.6 ,15 , 5.3>}
         box{<-bb/2+14.2, -1  ,-11.7 >< -bb/2+ 16  ,15 , 5.3>}
      }; 
      

#local pin_intern =
   sphere_sweep {
      b_spline
      9,
      <-0.635, 10.0,  17-21.4/2>,   0.2
      <-0.635, 12.0,  17-21.4/2>,   0.2
      <-0.635, 12.5,  17-21.4/2>,   0.2
      <-0.635, 12.5,  6-21.4/2>,   0.2
      <-0.635, 11.7,  6-21.4/2>,   0.2
      <-0.635, 11.0,  6.5-21.4/2>, 0.2
      <-0.635, 10.3, 10-21.4/2>,  0.2
      <-0.635, 8.0, 16-21.4/2>,  0.2
      <-0.635, 8.0, 18-21.4/2>,  0.2
      texture{col_gold} 
   }              
   
#local pin_channel = box{<-0.635-0.31 , bh-0.5, -5>< -0.635+0.31 , bh+1 , -8+bt> texture{tex_rj45_pastic}}  
           
           
union
{                 
        #if (schirm=1)  
        // voll geschrimt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local bb = a+3;
        #local bh = 12.8;
        #local bt = 18.0;  
        #local sb = 14+1;
        #if (a>11)
                #local sb = 15.5+1;
        #end        
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten        
        union {          
                difference {
                        box{<-sb/2, 0, -8.5 > < sb/2, bh+1 , -8+bt+1> texture{T_Chrome_5B}}                      //Ummantelung                      
                        box{<-bb/2, 0, -8   > < bb/2, bh   , -8+bt  > texture{T_Chrome_5B}}                      //Aushoehlung
                        box{<-sb/2-0.1, bh+0.5, -8.6 > < -sb/2+0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}      //obere Seitenkannten ausfraesen                  
                        box{< sb/2+0.1, bh+0.5, -8.6 > <  sb/2-0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}  
                        box{<-sb/2-0.1, bh+0.5, -8+bt+1.1 > <  sb/2+0.1, bh+1.1, -8+bt+0.5> texture{T_Chrome_5B}}//obere hinterkannte     
                        box{<-sb/2-0.1, bh+0.5, -8        > <  sb/2+0.1, bh+1.1, -8.6   > texture{T_Chrome_5B}}  //obere vorderkannte
                        box{< sb/2+0.1, bh+1.1, -8+bt+0.5 > <  sb/2-0.5, -0.1, -8+bt+1.1> texture{T_Chrome_5B}}  //senkrechte hinterkannten
                        box{<-sb/2-0.1, bh+1.1, -8+bt+0.5 > < -sb/2+0.5, -0.1, -8+bt+1.1> texture{T_Chrome_5B}}                        
                        box{< sb/2+0.1, bh+1.1, -8        > <  sb/2-0.5, -0.1, -8.6> texture{T_Chrome_5B}}  //senkrechte vordererkannten
                        box{<-sb/2-0.1, bh+1.1, -8        > < -sb/2+0.5, -0.1, -8.6> texture{T_Chrome_5B}}  
                        stecker2                                           
                }                           
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                     // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                     // rechte Loetasche                   
                cylinder{<-sb/2+0.5, bh+0.5, -8        > < -sb/2+0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}  // obere Seitenkannten abrunden       
                cylinder{< sb/2-0.5, bh+0.5, -8        > <  sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}    
                cylinder{<-sb/2+0.5, bh+0.5, -8+bt+0.5 > <  sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}  // obere hinterkannte 
                cylinder{<-sb/2+0.5, bh+0.5, -8        > <  sb/2-0.5, bh+0.5, -8       > 0.5 texture{col_silver}}  // obere vorderkannte                                
                cylinder{<-sb/2+0.5, bh+0.5, -8+bt+0.5 > < -sb/2+0.5, 0, -8+bt+0.5> 0.5 texture{col_silver}}       // senkrechte hinterkannten   
                cylinder{< sb/2-0.5, bh+0.5, -8+bt+0.5 > <  sb/2-0.5, 0, -8+bt+0.5> 0.5 texture{col_silver}}  
                cylinder{<-sb/2+0.5, bh+0.5, -8        > < -sb/2+0.5, 0, -8       > 0.5 texture{col_silver}}       // senkrechte vorderkannten   
                cylinder{< sb/2-0.5, bh+0.5, -8        > <  sb/2-0.5, 0, -8       > 0.5 texture{col_silver}}  
                sphere{< sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5  texture{col_silver}} 
                sphere{<-sb/2+0.5, bh+0.5, -8+bt+0.5> 0.5  texture{col_silver}}                                    // Eck-Kugeln hinten
                sphere{< sb/2-0.5, bh+0.5, -8       > 0.5  texture{col_silver}} 
                sphere{<-sb/2+0.5, bh+0.5, -8       > 0.5  texture{col_silver}}                                    // Eck-Kugeln vorn
        }                                   
        #end
        
                   
           
        
        #if (schirm=2)        
        //teilgeschirmt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local sb = bb+0.8;
        #if (a>11)
                #local sb = 15.5+1;
        #end           
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten       
        union {          
                difference {
                        box{<-sb/2+0.5, 0, -8.5 > < sb/2-0.5, bh+0.5 ,  -8  > texture{T_Chrome_5B}}                // Frontplatte                                            
                        stecker2                                                                                   // Durchbrueche
                }                                                                                                     
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                     // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                     // rechte Loetasche        
                cylinder{<-sb/2+0.5, bh, -8        > <  sb/2-0.5, bh, -8       > 0.5 texture{col_silver}}  // obere vorderkannte                                
                cylinder{<-sb/2+0.5, bh, -8        > < -sb/2+0.5, 0, -8       > 0.5 texture{col_silver}}       // senkrechte vorderkannten   
                cylinder{< sb/2-0.5, bh, -8        > <  sb/2-0.5, 0, -8       > 0.5 texture{col_silver}}  

                box{<-sb/2, 0, -8 > < -sb/2+0.4, bh ,  -2  > texture{T_Chrome_5B}}                         // linkes Seitenblech                                    
                box{< sb/2, 0, -8 > <  sb/2-0.4, bh ,  -2  > texture{T_Chrome_5B}}                         // rechtes Seitenblech  
                
                box{<-sb/2+0.5, bh, -8 > < -sb/2+2.5, bh+0.5 ,  -2  > texture{T_Chrome_5B}}                // oben links
                box{< sb/2-2.5, bh, -8 > <  sb/2-0.5, bh+0.5 ,  -2  > texture{T_Chrome_5B}}                // oben rechts      
                
                box{<sb/2-2.7, -0.50, 0><-sb/2+2.7, 0, 6> rotate<-15,0,0> translate<0, bh+0.5, -8.3> texture{T_Chrome_5B} }                
        }               
        #end
        
           
           
        
        #if (schirm=3)        
        //teilgeschirmt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local sb = bb+0.8;
        #if (a>11)
                #local sb = 15.5+1;
        #end           
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten       
        union {          
                difference {
                        box{<-sb/2, 0, -8.2 > < sb/2, bh+0.4 ,  -2  > texture{T_Chrome_5B}}                      //Ummantelung                      
                        box{<-bb/2, 0, -8   > < bb/2, bh   , -8+bt  > texture{T_Chrome_5B}}                      //Aushoehlung
                        box{<-sb/2-0.1, bh+0.5, -8 > < -sb/2+0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}        //obere Seitenkannten ausfraesen                  
                        box{< sb/2+0.1, bh+0.5, -8 > <  sb/2-0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}} 
                        stecker2 
                }                           
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                  // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                  // rechte Loetasche 
        }               
        #end
        
           
           
           
   // Plastik
   difference
   {         
           union
           {             
              box{<-bb/2 , 0, -5>< bb/2 , bh , -8+bt> texture{tex_rj45_pastic}}  // hinterer Teil matter
              box{<-bb/2 , 0, -8>< bb/2 , bh , -5   > texture{tex_rj45_pastic1}} // vordere 3mm glaenzen mehr         
      }
      stecker2                                                                   // Ausspartungen fuer Stecker
      box{<-bb/2-1 , -2, -8+bt+5>< bb/2+1 , bh+2 , -8+bt+1> rotate<-20,0,0> texture{tex_rj45_pastic}}  //hintere Abschaegung  
      // Kanaele fuer Anschlussdraehte an der Oberseite der Buchse
           pin_channel  
           object{pin_channel  translate<+1.27     , 0, 0>}
           #if (pins>2)
           object { pin_channel  translate<+1.27-2.54, 0, 0>}
           object { pin_channel  translate< 2.54     , 0, 0>}                                                             
           #end
           #if (pins>4)
           object { pin_channel  translate<+1.27+2.54,0,0>}
           object { pin_channel  translate<-2.54,0,0>}
           #end                                                                                                   
           #if (pins=8)
           object { pin_channel  translate<+5.08,0,0>}
           object { pin_channel  translate<+1.27-5.08,0,0>}
                #end
   }       
       
   //Panel-stops 
   #if (schirm>1)  
             #local stop=1;
        #end

   #if (stop=1)   
   //seitliche plastik-laschen 1.4mm dick
   box{<-bb/2-1 , 3, -6.4>< -bb/2 , bh-3 , -5>  texture{tex_rj45_pastic}}
   box{< bb/2+1 , 3, -6.4><  bb/2 , bh-3 , -5>  texture{tex_rj45_pastic}}   
   #end
   
   
 
   // Plastikfuesse zur Befestigung
   difference
   {
      cylinder{< a/2, -3.5, 0>< a/2, 1, 0> 1.4}
      box{<a/2-0.3,-4,-5><a/2+0.3,-0.5,5>}
      texture{tex_rj45_pastic}
   }
   difference
   {
      cylinder{<-a/2, -3.5, 0><-a/2, 1, 0> 1.4}
      box{<-a/2-0.3,-4,-5><-a/2+0.3,-0.5,5>}
      texture{tex_rj45_pastic}
   }
     
   // Pins auf der Platine   
   // hintere Pinreihe liegt 8.89 mm hinter den Befestigungsstiften
   cylinder{<-0.635     , 1, 8.89     ><-0.635     , -3.5, 8.89     > 0.25 texture{col_gold}}   
   cylinder{<+0.635     , 1, 8.89-2.54><+0.635     , -3.5, 8.89-2.54> 0.25 texture{col_gold}}   
   #if (pins>2)   
   cylinder{<-0.635+2.54, 1, 8.89     ><-0.635+2.54, -3.5, 8.89     > 0.25 texture{col_gold}}
   cylinder{<+0.635-2.54, 1, 8.89-2.54><+0.635-2.54, -3.5, 8.89-2.54> 0.25 texture{col_gold}}  
   #end
   #if (pins>4)
   cylinder{<+0.635+2.54, 1, 8.89-2.54><+0.635+2.54, -3.5, 8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<-0.635-2.54, 1, 8.89     ><-0.635-2.54, -3.5, 8.89     > 0.25 texture{col_gold}}
   #end
   #if (pins=8)
   cylinder{<-0.635+5.08, 1, 8.89     ><-0.635+5.08, -3.5, 8.89     > 0.25 texture{col_gold}}
   cylinder{<+0.635-5.08, 1, 8.89-2.54><+0.635-5.08, -3.5, 8.89-2.54> 0.25 texture{col_gold}}
   #end
        
        //Pins innerhalb der Buchse
   object { pin_intern }   
   object { pin_intern  translate<+1.27     , 0, 0>}
   #if (pins>2)
   object { pin_intern  translate<+1.27-2.54, 0, 0>}
   object { pin_intern  translate< 2.54     , 0, 0>}                                                             
   #end
   #if (pins>4)
   object { pin_intern  translate<+1.27+2.54,0,0>}
   object { pin_intern  translate<-2.54,0,0>}
   #end                                                                                                   
   #if (pins=8)
   object { pin_intern  translate<+5.08,0,0>}
   object { pin_intern  translate<+1.27-5.08,0,0>}
   #end      
   
   translate<0, 0, -o>
}
#end



#macro CON_MODULAR_RJ45()     CON_MODULAR_BASE(8, 11.43, 0, 0, 0)  #end
#macro CON_MODULAR_RJ12()     CON_MODULAR_BASE(6, 11.43, 0, 0, 0)  #end
#macro CON_MODULAR_RJ11()     CON_MODULAR_BASE(4, 11.43, 0, 0, 0)  #end
#macro CON_MODULAR_RJ45_SCH() CON_MODULAR_BASE(8, 11.43, 0, 1, 0)  #end
#macro CON_MODULAR_RJ12_SCH() CON_MODULAR_BASE(6, 11.43, 0, 1, 0)  #end
#macro CON_MODULAR_RJ11_SCH() CON_MODULAR_BASE(4, 11.43, 0, 1, 0)  #end
#macro CON_MODULAR_215875_3() CON_MODULAR_BASE(4, 6*1.27, 0, 0, 0) #end
#macro CON_MODULAR_215876_6() CON_MODULAR_BASE(4, 8*1.27, 0, 0, 0) #end
#macro CON_MODULAR_215876_7() CON_MODULAR_BASE(2, 8*1.27, 0, 0, 0) #end
#macro CON_MODULAR_215877_4() CON_MODULAR_BASE(8, 9*1.27, 0, 0, 0) #end
#macro CON_MODULAR_215877_7() CON_MODULAR_BASE(8, 9*1.27, 0, 0, 0) #end
#macro CON_MODULAR_215878_2() CON_MODULAR_BASE(8, 9*1.27, 0, 0, 0) #end
#macro CON_MODULAR_555164_1() CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 0) #end
#macro CON_MODULAR_555165_1() CON_MODULAR_BASE(6, 8*1.27, 1.27, 0, 0) #end
#macro CON_MODULAR_555165_2() CON_MODULAR_BASE(4, 8*1.27, 1.27, 0, 0) #end
#macro CON_MODULAR_555165_5() CON_MODULAR_BASE(2, 8*1.27, 1.27, 0, 0) #end
#macro CON_MODULAR_555166_1() CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 1) #end
#macro CON_MODULAR_555165_3() CON_MODULAR_BASE(4, 9*1.27, 1.27, 0, 1) #end
#macro CON_MODULAR_555167_1() CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 0) #end
#macro CON_MODULAR_555167_2() CON_MODULAR_BASE(6, 9*1.27, 1.27, 0, 0) #end
#macro CON_MODULAR_555162_1() CON_MODULAR_BASE(8, 9*1.27, 1.27, 0, 1) #end
#macro CON_MODULAR_555163_1() CON_MODULAR_BASE(6, 8*1.27, 1.27, 0, 1) #end
#macro CON_MODULAR_555163_2() CON_MODULAR_BASE(4, 8*1.27, 1.27, 0, 1) #end
#macro CON_MODULAR_555140_1() CON_MODULAR_BASE(6, 8*1.27, 0, 2, 1)    #end
#macro CON_MODULAR_555140_2() CON_MODULAR_BASE(4, 8*1.27, 0, 2, 1)    #end
#macro CON_MODULAR_555153_1() CON_MODULAR_BASE(8, 9*1.27, 0, 2, 1)    #end
#macro CON_MODULAR_555154_1() CON_MODULAR_BASE(6, 8*1.27, 0, 2, 1)    #end
#macro CON_MODULAR_555154_2() CON_MODULAR_BASE(4, 8*1.27, 0, 2, 1)    #end


/********************************************************************************************************************************************
//Molex 53047 ( 1.25 pitch, vertical feeding, through holes )
//antoine.drouin@free.fr
//n      Number of Pins
********************************************************************************************************************************************/
#macro CON_MOLEX_53047_BASE(n)
union {
  #local L = n * 1.25 + 1.75;
  #local l = 3.2;
  #local h = 4.2;
   difference {
     box {<-L/2, 0, -l/2><L/2, h, l/2> }
     box {<-L/2+0.6, 1.3, -l/2+0.45><L/2-0.6, h+0.1, l/2-0.45>}
     box {<-L/2+1, 2.7, 0><L/2-1, h+0.1, l/2+0.1>}
     box {<-L/2+0.35, 1.31, -0.35><L/2-0.35, h+0.1, 0.35>}
     box {<-L/2-0.1, 3.21, l/2-0.46><L/2+0.1, h+0.1, l/2+0.1>}
     #local j = 0;
     #while(j<n)
     box {<-0.35, -0.1, -l/2-0.1><0.35, 0.3, l/2+0.1>  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
     #local j = j + 1;
     #end
     box {<-L/2+1.6, 1.6, -l/2+0.46><-L/2+2.9, 2.9, -l/2-0.1>}
     box {<L/2-1.6, 1.6, -l/2+0.46><L/2-2.9, 2.9, -l/2-0.1>}
     pigment{White}
   }
  #local pin =
  union {
    cylinder {<0, 0, -0.5> <0, -2, -0.5> 0.18}
    box{<-0.2, 0 , -1 > <0.2, 3.1, 0 > }
    cylinder {<0, 1.555, -1.> <0, 1.555, 0.> 0.2 scale < 1, 2, 1>}
    texture{col_gold}
  }  
  #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*1.25/2+i*1.25, 0, 0>}
  #local i = i + 1;
  #end

}
#end

#macro CON_MOLEX_53047_2()  CON_MOLEX_53047_BASE(2)  #end
#macro CON_MOLEX_53047_3()  CON_MOLEX_53047_BASE(3)  #end
#macro CON_MOLEX_53047_4()  CON_MOLEX_53047_BASE(4)  #end
#macro CON_MOLEX_53047_5()  CON_MOLEX_53047_BASE(5)  #end
#macro CON_MOLEX_53047_6()  CON_MOLEX_53047_BASE(6)  #end
#macro CON_MOLEX_53047_7()  CON_MOLEX_53047_BASE(7)  #end
#macro CON_MOLEX_53047_8()  CON_MOLEX_53047_BASE(8)  #end
#macro CON_MOLEX_53047_9()  CON_MOLEX_53047_BASE(9)  #end
#macro CON_MOLEX_53047_10() CON_MOLEX_53047_BASE(10) #end
#macro CON_MOLEX_53047_11() CON_MOLEX_53047_BASE(11) #end
#macro CON_MOLEX_53047_12() CON_MOLEX_53047_BASE(12) #end
#macro CON_MOLEX_53047_13() CON_MOLEX_53047_BASE(13) #end
#macro CON_MOLEX_53047_14() CON_MOLEX_53047_BASE(14) #end
#macro CON_MOLEX_53047_15() CON_MOLEX_53047_BASE(15) #end


/********************************************************************************************************************************************
// Molex 53048 ( 1.25 pitch, horizontal feeding, through holes )
//antoine.drouin@free.fr
//n      Number of Pins
********************************************************************************************************************************************/
#macro CON_MOLEX_53048_BASE(n)
union {
  #local L = n * 1.25 + 1.75;
  #local l = 5.5;
  #local h = 3.5;
  difference {
    box {<-L/2, 0, -2.3><L/2, h, 3.2> }
    box {<-L/2+0.6, 0.8, 0.3><L/2-0.6, h-0.4, 3.3>}
    box {<-L/2+1, h-0.5, 1.6><L/2-1, h+0.1, 3.3>}
    box {<-L/2-0.1, h-0.41, 2.3><L/2+0.1, h+0.1, 3.3>}
    box {<-L/2+0.6, -0.1, -2.4><L/2-0.6, 0.3, 3.3>}
    box {<-L/2+0.8, -0.1, -2.4><L/2-0.8, h+0.1, -1.58>}
    box {<-L/2+0.81, 1.3, -2.4><L/2-0.81, h+0.1, -1.>}
    box {<-L/2-0.1, h-1, -2.4><L/2+0.1, h+0.1, -1.01>}
    #local j = 0;
    #while(j<n)
        box {<-0.3, h-0.6, -1.1><0.3, h+0.1, -0.7>  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
   cylinder {<0, -0.1, -1.3> <0, h+0.1, -1.3> 0.3  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
    #local j = j + 1;
    #end
        box {<-L/2+1.6, 0, 2.7><-L/2+2.9, 0.9, 1.1>}
        box {<L/2-1.6, 0, 2.7><L/2-2.9, 2.9, 1.1>}
    pigment{White}
  }
  #local pin =
  union {
    cylinder {<0, -2.3, -1.25> <0, 1.27, -1.25> 0.18}
    cylinder {<0, 1.52, -1> <0, 1.52, -0.75> 0.18}
    intersection {
      torus { 0.25 0.18 rotate < 0, 0, 90> }
      box { < 1, 0, 0> <-1, 1, -11> }
      translate < 0, 1.27, -1>
    }
    union {
      box{<-0.2, 1.2 , -0.75 > <0.2, 2, 1.95 > }
      cylinder {<0, 1.2, 1.02> <0, 2., 1.02> 0.2 scale < 1, 1, 2>}
    }
    texture{col_gold}
  }  
  #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*1.25/2+i*1.25, 0, 0>}
  #local i = i + 1;
  #end

}
#end

#macro CON_MOLEX_53048_2()  CON_MOLEX_53048_BASE( 2) #end
#macro CON_MOLEX_53048_3()  CON_MOLEX_53048_BASE( 3) #end
#macro CON_MOLEX_53048_4()  CON_MOLEX_53048_BASE( 4) #end
#macro CON_MOLEX_53048_5()  CON_MOLEX_53048_BASE( 5) #end
#macro CON_MOLEX_53048_6()  CON_MOLEX_53048_BASE( 6) #end
#macro CON_MOLEX_53048_7()  CON_MOLEX_53048_BASE( 7) #end
#macro CON_MOLEX_53048_8()  CON_MOLEX_53048_BASE( 8) #end
#macro CON_MOLEX_53048_9()  CON_MOLEX_53048_BASE( 9) #end
#macro CON_MOLEX_53048_10() CON_MOLEX_53048_BASE(10) #end
#macro CON_MOLEX_53048_11() CON_MOLEX_53048_BASE(11) #end
#macro CON_MOLEX_53048_12() CON_MOLEX_53048_BASE(12) #end
#macro CON_MOLEX_53048_13() CON_MOLEX_53048_BASE(13) #end
#macro CON_MOLEX_53048_14() CON_MOLEX_53048_BASE(14) #end
#macro CON_MOLEX_53048_15() CON_MOLEX_53048_BASE(15) #end



/********************************************************************************************************************************************
// PC power connector male
********************************************************************************************************************************************/
#macro CON_PCPWR514M_BASE()
union {
        difference {
        box{<0,0,0><23.2,10,8.4> translate <-11.6,0.5,-4.20> }
        box{<0,0,0><21,8,6.4> translate <-10.5,2.6,-3.20> }
        }
     box{<0,0,0><1,3,3> translate <-12.6,0.5,-1.5> }
     box{<0,0,0><1,3,3> translate <11.6,0.5,-1.5> }

     box{<0,0,0><3,10,1.5> rotate <0,-45,0> translate <-10.5,0.5,1> }
     box{<0,0,0><3,10,1.5> rotate <0,45,0> translate <8.5,0.5,3.1> }


     #local p = 0;
     #while(p<5)    
        box{<0,0,0><1.5,3,1> translate <-11.6+p*5,0.5,-5.2> }
     #local p = p+1;
     #end


     #local p = 0;
     #while(p<4)    
             cylinder {<0,0,0><0,12.5,0> 0.8 translate <-7.5+p*5.08,-3.5,0> texture{col_gold}}
             sphere {<-7.5+p*5.08,9,0> 0.8 texture{col_gold}}   
     #local p = p+1;
     #end
 }        

 pigment{VLightGray}
 rotate <0,-90,0>
 
#end
#macro CON_PCPWR514M()
CON_PCPWR514M_BASE()
#end






/********************************************************************************************************************************************
//Macros for connector PHOENIX type MINICONNEC 5.08
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1  06/01/06
********************************************************************************************************************************************/
#macro CON_PHOENIX_508_BASE(n,vertical,a)
// n = pins ; Vertical = 1 if yes ; With border a = 1 / Whithout border a = 0
union {
    difference {
        union {
            #local PAS = 5.08;
            //body
         box{<-PAS*n/2-a,-4.15,0><+PAS*n/2+a,4.15,12> }
         //up additional thickness
         box{<-PAS*n/2-a,+4.15,9><+PAS*n/2+a,4.15+0.5,12> }
         }
         
         union {
            
            #local i=0; 
            #while (i<n)
                //Half Cylindrical holes
                intersection{
                    cylinder{<-(PAS/2*(n-1))+(i*PAS),0.35,2.5><-(PAS/2*(n-1))+(i*PAS),0.35,12.1> 4 }
                    box{<-(PAS/2*(n-1))+(i*PAS)+2.541,+0.1,2.51><-(PAS/2*(n-1))+(i*PAS)-2.541,-5.1,12.1> }
                }
                //Crenels at the top
                box{<-(PAS/2*(n-1))+(i*PAS)+1,3,11><-(PAS/2*(n-1))+(i*PAS)-1,6,12.5> }
                //Crenels for pins
                box{<-(PAS/2*(n-1))+(i*PAS)+0.5,0,-0.1><-(PAS/2*(n-1))+(i*PAS)-0.5,-6,2> }
                box{<-(PAS/2*(n-1))+(i*PAS)+1.5,-4,-0.1><-(PAS/2*(n-1))+(i*PAS)-1.5,-6,3> }
             #local i=i+1; #end
          
             //Half squared hole               
             box{<-PAS*n/2-0.01,0,2.5><+PAS*n/2+0.01,3.25,12.1> }
                                     
            //bisel   
         box{<-PAS*n/2-a-0.1,+4.15,9><+PAS*n/2+a+0.1,4.15+0.7,12> rotate 20*x translate 4*y}
         
         }
         pigment{ForestGreen}
    }
    #if(vertical)
        #local i=0; #while (i<n)
            union {
                //pin body
                box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,-4><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,9> }
                //pin top
                intersection{
                    box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,9><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,10> }
                    cone{<-(PAS/2*(n-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(n-1))+(i*PAS),0,10.01>, 0.25}
                }
                texture { pigment{P_Silver2} }
            }
        #local i=i+1; #end
        rotate <-90,180,0>
    #else
        #local i=0; #while (i<n)
            //inside part pin
            union {
                //pin body
                box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,2><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,9> texture { pigment{P_Silver2} }}
                //pin top
                intersection{
                    box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,9><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,10> }
                    cone{<-(PAS/2*(n-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(n-1))+(i*PAS),0,10.01>, 0.25}
                }
                texture { pigment{P_Silver2} }
            }


            //outside part pin
            box{<-(PAS/2*(n-1))+(i*PAS)-0.4,0,1.1><-(PAS/2*(n-1))+(i*PAS)+0.4,-7.5,1.9> texture { pigment{P_Silver2} }}
        #local i=i+1; #end
        translate <0,4.1,-5.08-1.5> //-1.5>
        rotate 180*y
    #end
}
#end

// Vertical whithout border
#macro CON_PHOENIX_508_MSTBV_2()  CON_PHOENIX_508_BASE( 2,1,0) #end
#macro CON_PHOENIX_508_MSTBV_3()  CON_PHOENIX_508_BASE( 3,1,0) #end
#macro CON_PHOENIX_508_MSTBV_4()  CON_PHOENIX_508_BASE( 4,1,0) #end
#macro CON_PHOENIX_508_MSTBV_5()  CON_PHOENIX_508_BASE( 5,1,0) #end
#macro CON_PHOENIX_508_MSTBV_6()  CON_PHOENIX_508_BASE( 6,1,0) #end
#macro CON_PHOENIX_508_MSTBV_7()  CON_PHOENIX_508_BASE( 7,1,0) #end
#macro CON_PHOENIX_508_MSTBV_8()  CON_PHOENIX_508_BASE( 8,1,0) #end
#macro CON_PHOENIX_508_MSTBV_9()  CON_PHOENIX_508_BASE( 9,1,0) #end
#macro CON_PHOENIX_508_MSTBV_10() CON_PHOENIX_508_BASE(10,1,0) #end
#macro CON_PHOENIX_508_MSTBV_11() CON_PHOENIX_508_BASE(11,1,0) #end
#macro CON_PHOENIX_508_MSTBV_12() CON_PHOENIX_508_BASE(12,1,0) #end
#macro CON_PHOENIX_508_MSTBV_13() CON_PHOENIX_508_BASE(13,1,0) #end
#macro CON_PHOENIX_508_MSTBV_14() CON_PHOENIX_508_BASE(14,1,0) #end
#macro CON_PHOENIX_508_MSTBV_15() CON_PHOENIX_508_BASE(15,1,0) #end
#macro CON_PHOENIX_508_MSTBV_16() CON_PHOENIX_508_BASE(16,1,0) #end
#macro CON_PHOENIX_508_MSTBV_17() CON_PHOENIX_508_BASE(17,1,0) #end
#macro CON_PHOENIX_508_MSTBV_18() CON_PHOENIX_508_BASE(18,1,0) #end
#macro CON_PHOENIX_508_MSTBV_19() CON_PHOENIX_508_BASE(19,1,0) #end
#macro CON_PHOENIX_508_MSTBV_20() CON_PHOENIX_508_BASE(20,1,0) #end
#macro CON_PHOENIX_508_MSTBV_21() CON_PHOENIX_508_BASE(21,1,0) #end
#macro CON_PHOENIX_508_MSTBV_22() CON_PHOENIX_508_BASE(22,1,0) #end
#macro CON_PHOENIX_508_MSTBV_23() CON_PHOENIX_508_BASE(23,1,0) #end
#macro CON_PHOENIX_508_MSTBV_24() CON_PHOENIX_508_BASE(24,1,0) #end

// Horizontal whithout border
#macro CON_PHOENIX_508_MSTB_2()  CON_PHOENIX_508_BASE( 2,0,0) #end
#macro CON_PHOENIX_508_MSTB_3()  CON_PHOENIX_508_BASE( 3,0,0) #end
#macro CON_PHOENIX_508_MSTB_4()  CON_PHOENIX_508_BASE( 4,0,0) #end
#macro CON_PHOENIX_508_MSTB_5()  CON_PHOENIX_508_BASE( 5,0,0) #end
#macro CON_PHOENIX_508_MSTB_6()  CON_PHOENIX_508_BASE( 6,0,0) #end
#macro CON_PHOENIX_508_MSTB_7()  CON_PHOENIX_508_BASE( 7,0,0) #end
#macro CON_PHOENIX_508_MSTB_8()  CON_PHOENIX_508_BASE( 8,0,0) #end
#macro CON_PHOENIX_508_MSTB_9()  CON_PHOENIX_508_BASE( 9,0,0) #end
#macro CON_PHOENIX_508_MSTB_10() CON_PHOENIX_508_BASE(10,0,0) #end
#macro CON_PHOENIX_508_MSTB_11() CON_PHOENIX_508_BASE(11,0,0) #end
#macro CON_PHOENIX_508_MSTB_12() CON_PHOENIX_508_BASE(12,0,0) #end
#macro CON_PHOENIX_508_MSTB_13() CON_PHOENIX_508_BASE(13,0,0) #end
#macro CON_PHOENIX_508_MSTB_14() CON_PHOENIX_508_BASE(14,0,0) #end
#macro CON_PHOENIX_508_MSTB_15() CON_PHOENIX_508_BASE(15,0,0) #end
#macro CON_PHOENIX_508_MSTB_16() CON_PHOENIX_508_BASE(16,0,0) #end
#macro CON_PHOENIX_508_MSTB_17() CON_PHOENIX_508_BASE(17,0,0) #end
#macro CON_PHOENIX_508_MSTB_18() CON_PHOENIX_508_BASE(18,0,0) #end
#macro CON_PHOENIX_508_MSTB_19() CON_PHOENIX_508_BASE(19,0,0) #end
#macro CON_PHOENIX_508_MSTB_20() CON_PHOENIX_508_BASE(20,0,0) #end
#macro CON_PHOENIX_508_MSTB_21() CON_PHOENIX_508_BASE(21,0,0) #end
#macro CON_PHOENIX_508_MSTB_22() CON_PHOENIX_508_BASE(22,0,0) #end
#macro CON_PHOENIX_508_MSTB_23() CON_PHOENIX_508_BASE(23,0,0) #end
#macro CON_PHOENIX_508_MSTB_24() CON_PHOENIX_508_BASE(24,0,0) #end

// Vertical whith border
#macro CON_PHOENIX_508_MSTBVA_2()  CON_PHOENIX_508_BASE( 2,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_3()  CON_PHOENIX_508_BASE( 3,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_4()  CON_PHOENIX_508_BASE( 4,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_5()  CON_PHOENIX_508_BASE( 5,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_6()  CON_PHOENIX_508_BASE( 6,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_7()  CON_PHOENIX_508_BASE( 7,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_8()  CON_PHOENIX_508_BASE( 8,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_9()  CON_PHOENIX_508_BASE( 9,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_10() CON_PHOENIX_508_BASE(10,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_11() CON_PHOENIX_508_BASE(11,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_12() CON_PHOENIX_508_BASE(12,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_13() CON_PHOENIX_508_BASE(13,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_14() CON_PHOENIX_508_BASE(14,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_15() CON_PHOENIX_508_BASE(15,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_16() CON_PHOENIX_508_BASE(16,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_17() CON_PHOENIX_508_BASE(17,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_18() CON_PHOENIX_508_BASE(18,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_19() CON_PHOENIX_508_BASE(19,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_20() CON_PHOENIX_508_BASE(20,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_21() CON_PHOENIX_508_BASE(21,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_22() CON_PHOENIX_508_BASE(22,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_23() CON_PHOENIX_508_BASE(23,1,1) #end
#macro CON_PHOENIX_508_MSTBVA_24() CON_PHOENIX_508_BASE(24,1,1) #end

// Horizontal whith border
#macro CON_PHOENIX_508_MSTBA_2()  CON_PHOENIX_508_BASE( 2,0,1) #end
#macro CON_PHOENIX_508_MSTBA_3()  CON_PHOENIX_508_BASE( 3,0,1) #end
#macro CON_PHOENIX_508_MSTBA_4()  CON_PHOENIX_508_BASE( 4,0,1) #end
#macro CON_PHOENIX_508_MSTBA_5()  CON_PHOENIX_508_BASE( 5,0,1) #end
#macro CON_PHOENIX_508_MSTBA_6()  CON_PHOENIX_508_BASE( 6,0,1) #end
#macro CON_PHOENIX_508_MSTBA_7()  CON_PHOENIX_508_BASE( 7,0,1) #end
#macro CON_PHOENIX_508_MSTBA_8()  CON_PHOENIX_508_BASE( 8,0,1) #end
#macro CON_PHOENIX_508_MSTBA_9()  CON_PHOENIX_508_BASE( 9,0,1) #end
#macro CON_PHOENIX_508_MSTBA_10() CON_PHOENIX_508_BASE(10,0,1) #end
#macro CON_PHOENIX_508_MSTBA_11() CON_PHOENIX_508_BASE(11,0,1) #end
#macro CON_PHOENIX_508_MSTBA_12() CON_PHOENIX_508_BASE(12,0,1) #end
#macro CON_PHOENIX_508_MSTBA_13() CON_PHOENIX_508_BASE(13,0,1) #end
#macro CON_PHOENIX_508_MSTBA_14() CON_PHOENIX_508_BASE(14,0,1) #end
#macro CON_PHOENIX_508_MSTBA_15() CON_PHOENIX_508_BASE(15,0,1) #end
#macro CON_PHOENIX_508_MSTBA_16() CON_PHOENIX_508_BASE(16,0,1) #end
#macro CON_PHOENIX_508_MSTBA_17() CON_PHOENIX_508_BASE(17,0,1) #end
#macro CON_PHOENIX_508_MSTBA_18() CON_PHOENIX_508_BASE(18,0,1) #end
#macro CON_PHOENIX_508_MSTBA_19() CON_PHOENIX_508_BASE(19,0,1) #end
#macro CON_PHOENIX_508_MSTBA_20() CON_PHOENIX_508_BASE(20,0,1) #end
#macro CON_PHOENIX_508_MSTBA_21() CON_PHOENIX_508_BASE(21,0,1) #end
#macro CON_PHOENIX_508_MSTBA_22() CON_PHOENIX_508_BASE(22,0,1) #end
#macro CON_PHOENIX_508_MSTBA_23() CON_PHOENIX_508_BASE(23,0,1) #end
#macro CON_PHOENIX_508_MSTBA_24() CON_PHOENIX_508_BASE(24,0,1) #end


/********************************************************************************************************************************************
//ChristophGraf@web.de
********************************************************************************************************************************************/
#macro CON_PHONE_JACK_BASE(value)

union {
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference {
                box{<-7.1882,-0.1,5.9182><7.1882,5,-5.9182> pigment{Black}}
                box{<-6.4882,-0.2,5.2182><6.4882,6,-5.2182> pigment{Black}}}

               box{<-7.1882,5,5.9182><7.1882,6,-5.9182> pigment{White filter 0.91}}
               box{<-7.1882,0,5.9182><7.1882,1,-5.9182> pigment{Black}}
           

        
        difference {
        cylinder { < -7.1882 , 3 , 0 >,< -10.7442, 3 , 0 >,2.6  pigment{White}}
        cylinder { < -7.1882 , 3 , 0 >,< -11.7442, 3 , 0 >,1.75  pigment{White}}
          }
        union {
                lathe { linear_spline 13,<2.6, -10.7442>,<2.9, -10.4442>, <2.6, -10.1442>,<2.9, -9.8442>,<2.6, -9.5442>,
                <2.9, -9.2442>,<2.6, -8.9442>,<2.9, -8.6442>,<2.6, -8.3442>,<2.9, -8.0442>,
                <2.6, -7.7442>,<2.9, -7.4442>,<2.6, -7.1442>pigment {Silver} } 
                rotate<0,0,-90>
                translate<0,3,0> 
             }

        
        union {
                cylinder{<2.8494,2,4.8996>,<2.8494,-pp,4.8996>,0.25 }
                cylinder{<-4.9979,2,-0.2035>,<-4.9979,-pp,-0.2035>,0.25 }
                cylinder{<1.4575,2,2.3985>,<1.4575,-pp,2.3985>,0.25 }  
                cylinder{<-1.75,2,-4.9032>,<-1.75,-pp,-4.9032>,0.25 }
                cylinder{<5.7543,2,-4.3787>,<5.7543,-pp,-4.3787>,0.25 }
                pigment{Silver}
        }
        union {
               box{<3.5543,1,-1.3><5.85,5,-1.6> pigment{Silver}}
               box{<5.5543,1,-4.3787><5.85,5,-0.4787> pigment{Silver}} 
               prism{linear_sweep 0,5,11,            // segment "A"
                <-1.45,-4.6032>,<-5.55,-4.6032>,<-1.25,-0.5332>,<-0.55,-2.1332>,<4.75,-2.1332>,
                <4.75,-1.8332>,<-0.35,-1.8332>,<-1.1436,-0.0194>,<-5.9492,-4.568>,<-5.8324,-4.9032>,<-1.45,-4.9032>
                pigment{Silver}}
               prism{linear_sweep 0,5,13,            // segment "A"
                <2.8494,5.1996>,<6.6829,5.1996>,<6.6829,2.8981>,<-2.2639,2.812>,<-3.2967,0.7465>,
                <-4.5539,3.0096>,<-4.2139,3.0152>,<-3.3106,1.3894>,<-2.4502,3.1104>,<6.2829,3.1954>,<6.2829,4.8996>,<2.8494,4.8996>,<2.8494,5.1996>
                pigment{Silver}} 
                 prism{linear_sweep 0,5,5,            // segment "A"
                <-2.2125,2.3985>,<2.5575,2.3985>,<2.5575,2.6985>,<-2.2125,2.6985>,<-2.2125,2.3985>
                pigment{Silver}}
        }

}
#end

#macro CON_PHONE_JACK(value)
CON_PHONE_JACK_BASE(value)
#end






/********************************************************************************************************************************************
// Makro fuer geschirmte Ethernet-Buchse RJ-45 8-polig
// Designed by Carsten Koegler, FTZ-Leipzig <koegler(replace with at)ftz-leipzig.de>
// Vorlage: MEBP 8-8PG Reichelt Elektronik
********************************************************************************************************************************************/
#macro CON_RJ45_BASE()
//#local tex_rj45_metal = texture { T_Chrome_3D } ;
#local tex_rj45_metal = texture { T_Chrome_5B } ;
#local tex_rj45_pastic = texture { pigment{White*0.3} finish {specular 1 roughness 0.001 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;

#macro body(B,H,T,R)
union {

    // Grundkoerper
    box{<-B/2+R,0  , T/2  > <B/2-R,H-R,-T/2  >}
    box{<-B/2  ,0  ,-T/2+R> <B/2  ,H-R, T/2-R>}
    box{<-B/2+R,0  ,-T/2+R> <B/2-R,H    , T/2-R>}


    // senkrechte Seiten als Zylinder
    // linke hintere Ecke
    cylinder{<-B/2+R, 0, 0> <-B/2+R, H-R> R
             translate <0, 0, T/2-R>}
    // linke vordere Ecke
    cylinder{<-B/2+R, 0, 0> <-B/2+R, H-R> R
             translate <0, 0,-T/2+R>}
    // rechte hintere Ecke
    cylinder{< B/2-R, 0, 0> < B/2-R, H-R> R
             translate <0, 0, T/2-R>}
    // rechte vordere Ecke
    cylinder{< B/2-R, 0, 0> < B/2-R, H-R> R
             translate <0, 0,-T/2+R>}

    sphere{< B/2-R, H-R, T/2-R> R scale <1,1,1>}
    sphere{< B/2-R, H-R,-T/2+R> R scale <1,1,1>}
    sphere{<-B/2+R, H-R, T/2-R> R scale <1,1,1>}
    sphere{<-B/2+R, H-R,-T/2+R> R scale <1,1,1>}


    cylinder{<-B/2+R,  H-R> < B/2-R, H-R> R
             translate <0, 0, T/2-R>}

    cylinder{<-B/2+R,  H-R> < B/2-R, H-R> R
             translate <0, 0,-T/2+R>}
    cylinder{<-T/2+R,  H-R> < T/2-R, H-R> R rotate<0, 90,0>
             translate < B/2-R, 0, 0>}
    cylinder{<-T/2+R,  H-R> < T/2-R, H-R> R rotate<0, 90,0>
             translate < -B/2+R, 0, 0>}
  }
#end 

// Ausbruch in der metallenen Vorderseite
#local stecker1 = 
      difference
      {
         box{<1.5,0.5,-1><15.8-1.5,11.5,15.0>}
         box{<0  ,0  ,-2><3.0     ,3.3 ,15.0>}
         box{<16 ,0  ,-2><15.8-3.0,3.3 ,15.0>}
         box{<0  ,0  ,-2><5.5     ,2.1 ,15.0>}
         box{<16 ,0  ,-2><15.8-5.5,2.1 ,15.0>}
      };

// Ausbruch im Kunststoff
#local stecker2 = 
      difference
      {
         union
         {
            box{<1.5, 3.7, -1><15.8-1.5, 11.5, 15.5>}
            box{<3.1, 2.5, -1><15.8-3.1, 11.5, 15.5>}
            box{<5.6, 0.7, -1><15.8-5.6, 11.5, 15.5>}
            box{<-1,-1,-2><16,1  ,2>rotate<-30,0,0>translate<0,4.4,0> pigment{White*0.5}}
            box{<-1,0 ,-1><16,0.5,1>rotate<-30,0,0>translate<0,2.0,0> pigment{White*0.5}}
         }
         box{<-1      ,-1  ,15.0><16  ,15 ,16.0>}
         box{<-1      ,-1  ,-1  ><1.6 ,15 ,16.0>}
         box{<15.8-1.6,-1  ,-1  ><16  ,15 ,16.0>}
      };

#local pin_intern =
   sphere_sweep {
      b_spline
      6,
      <15.8/2-0.635, 14.0, 6>,   0.2
      <15.8/2-0.635, 12.7, 6>,   0.2
      <15.8/2-0.635, 12.0, 6.5>, 0.2
      <15.8/2-0.635, 11.3, 10>,  0.2
      <15.8/2-0.635, 11.0, 16>,  0.2
      <15.8/2-0.635, 11.0, 18>,  0.2
      texture{col_gold}
   }

union
{
   difference
   {
      // Aussenabmasse : 15.8  x  13.0  x  21.4 mm
      union
      {
         object {body(15.8,13.0,21.4,0.3) translate<7.9,0,10.7>  }
         box{<0,12.0,0.2><0.5,13,7.7> }
         box{<15.5,12.0,0.2><15.8,13,7.7>}
      }
      // das Ganze aushoehlen
      box{<0.25 ,-1 , 0.2><15.8-0.25 ,13.0-0.25,21.4-0.25>}
      
      // Vorne typischer Ausbruch fuer Stecker
      stecker1

      // kleiner Schlitz hinten oben
      box{<3.5,13-0.35,21.4-0.35><15.8-3.5,13+0.35,21.4+0.35> }

      // Schlitze an den Seiten
      // Schraegen hinten (links und rechts)
      box{<-0.3,-0.1,-1.64><0.3,0.1,2.0> rotate<-45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02+11.2>}
      box{<15.8-0.3,-0.1,-1.64><16,0.1,2.0> rotate<-45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02+11.2>}
      // Senkrechten
      box{<-1,-1,18.8><20,10.6,19.00>}
      // waagerechte hinten
      box{<-1,10.45,10><20,10.65,18.8> }
      // Schraegen vorne
      box{<-1,-0.1,-1.52><20,0.1,1.64> rotate<45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02> }
      // waagerechte vorn
      box{<-1,12.6,0.2><20,12.8,7.82>}

      // Verbindungspunkte hinten
      box{<-1,1,19.7><20,1.8,20.5>}
      box{<-1,8,19.7><20,8.8,20.5>}
      texture{tex_rj45_metal}
   }

   // Verbindungspunkte hinten
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<     0.35,1.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<     0.35,8.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<15.8-0.35,1.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<15.8-0.35,8.4,20.1> texture{tex_rj45_metal}}

   // Schirmanschluesse
   box     {<0   , 1, 14-0.75><0.2     , -4,14+0.75> texture{tex_rj45_metal}}
   cylinder{<0   ,-4, 14     ><0.2     , -4,14     > 0.75 texture{tex_rj45_metal}}
   box     {<15.8, 1, 14-0.75><15.8-0.2, -4,14+0.75> texture{tex_rj45_metal}}
   cylinder{<15.8,-4, 14     ><15.8-0.2, -4,14     > 0.75 texture{tex_rj45_metal}}

   // Plastikinnenleben
   difference
   {
      box{<0.4 ,0 , 0.3><15.8-0.4 ,13.0-0.4,21.4-0.4>}
      stecker2

      texture{tex_rj45_pastic}
    }
 
   // Plastikfuesse zur Befestigung
   difference
   {
      cylinder{<2,-3.5,14-3.05><2,1,14-3.05> 1.5}
      box{<2-0.3,-4,0><2+0.3,-0.5,20>}
      texture{tex_rj45_pastic}
   }
   difference
   {
      cylinder{<15.8-2,-3.5,14-3.05><15.8-2,1,14-3.05> 1.5}
      box{<15.8-2-0.3,-4,0><15.8-2+0.3,-0.5,20>}
      texture{tex_rj45_pastic}
   }
   cylinder{<2,0,5><2,0,15> 0.5 texture{tex_rj45_pastic}}
   cylinder{<15.8-2,0,5><15.8-2,0,15> 0.5 texture{tex_rj45_pastic}}
   
      
   object {TOOLS_RECT_BOGEN(0.2, // i_radius
                            90 , // winkel
                            0.2, // dicke
                            2  , // breite
                            1 , // laenge1
                            5)  // laenge2
                            rotate<90,0,0>
                            translate <15.8-1.5-0.2,7,0.1>
                            texture{tex_rj45_metal}}
   object {TOOLS_RECT_BOGEN(0.2, // i_radius
                            90 , // winkel
                            0.2, // dicke
                            2  , // breite
                            5 , // laenge1
                            1)  // laenge2
                            rotate<90,0,0>
                            rotate<0,-90,0>
                            translate <1.5+0.2,7,0.1>
                            texture{tex_rj45_metal}}

   // Pins (8)
   cylinder{<15.8/2-0.635     ,1,14-3.05+8.89     ><15.8/2-0.635     ,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635+2.54,1,14-3.05+8.89     ><15.8/2-0.635+2.54,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635-2.54,1,14-3.05+8.89     ><15.8/2-0.635-2.54,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635+5.08,1,14-3.05+8.89     ><15.8/2-0.635+5.08,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}

   cylinder{<15.8/2+0.635     ,1,14-3.05+8.89-2.54><15.8/2+0.635     ,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635+2.54,1,14-3.05+8.89-2.54><15.8/2+0.635+2.54,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635-2.54,1,14-3.05+8.89-2.54><15.8/2+0.635-2.54,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635-5.08,1,14-3.05+8.89-2.54><15.8/2+0.635-5.08,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   
   object { pin_intern }
   object { pin_intern  translate< 2.54,0,0>}
   object { pin_intern  translate<-2.54,0,0>}
   object { pin_intern  translate<+5.08,0,0>}
   
   object { pin_intern  translate<+1.27,0,0>}
   object { pin_intern  translate<+1.27+2.54,0,0>}
   object { pin_intern  translate<+1.27-2.54,0,0>}
   object { pin_intern  translate<+1.27-5.08,0,0>}
 
   translate<0,0.5,0>  // Anhebung um hoehe der Plastikrollen
   translate<-15.8/2,0,-21.4/2>  // 0-Punkt in die Mitte der Buchse platzieren
}
#end
#macro CON_RJ45()
CON_RJ45_BASE()
#end



