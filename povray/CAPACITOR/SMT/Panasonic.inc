/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMD Elko Panasonic A..G
 * Panasonic SMD-Elko base.
 * L = Laenge
 * W = Breite
 * H = Hoehe
 * D = Durchmesser Elkokoerper
 * B = Breite Anschlusspin
 * S = Abstand Anschlusspins unten
 * C = Laenge Anschlusspins
 ******************************************************************************/
#macro CAP_SMD_ELKO_BASE(L,W,H,D,B,S,C)
  union {
     #local col_smd_elko = texture {
         pigment {
            Gray30
            }
         finish {
            ambient (0.10 * global_ambient_mul)
            }
         }

    //Contacts
    box { <-S/2,0,-B/2> <-S/2-C,0.3,B/2> }
    box { <+S/2,0,-B/2> <+S/2+C,0.3,B/2> }
    //The base plastic
    difference {
       box { <-L/2,0.3,-W/2> <L/2,2,W/2> }
       box { <0,0,0> <6,3,-5> rotate<0,-45,0> translate<L/2-L/4,0,-W/2> }
       box { <0,0,0> <6,3,+5> rotate<0,+45,0> translate<L/2-L/4,0,+W/2> }
       texture { col_smd_elko }
       }
    //Body
    difference {
       cylinder { <0,2,0> <0,H-0.4,0>D/2 }
       torus { D/2+0.2,0.4 translate<0,3,0> }
       }
    torus { D/2-0.4,0.4 translate<0,H-0.4,0> }
    cylinder { <0,H-0.4,0> <0,H,0>D/2-0.4}
    //Top marking
    union {        
       difference {
          cylinder { <0,H-0.4,0> <0,H+0.01,0>D/2-0.4 }
          box { <-D/6,H-0.5,-D/2> <D/2,H+0.1,D/2> }            
          }
       text { ttf besch_font value 0.5,0 scale D/7 rotate<90,-90,0> translate<D/16,H+0.01,-D/2+D/8> }
       texture { col_black_marking }
       }
    rotate <0,180,0>
    texture { col_silver }
    }
#end


#macro CAP_SMD_ELKO_0405(value)
  CAP_SMD_ELKO_BASE(4.5,4.5,5.5,4.0,0.8,1.0,2.0)
#end

#macro CAP_SMD_ELKO_0505(value)
  CAP_SMD_ELKO_BASE(5.5,5.5,5.5,5.0,0.8,1.4,2.3)
#end

#macro CAP_SMD_ELKO_0605(value)
  CAP_SMD_ELKO_BASE(6.8,6.8,5.5,6.3,0.8,2.0,2.7)
#end

#macro CAP_SMD_ELKO_0807(value)
  CAP_SMD_ELKO_BASE(8.6,8.6,6.8,8.0,0.8,2.3,3.4)
#end

#macro CAP_SMD_ELKO_0808(value)
  CAP_SMD_ELKO_BASE(8.4,8.4,8.7,8,1,4.7,2.2)
#end

#macro CAP_SMD_ELKO_0810(value)
  CAP_SMD_ELKO_BASE(8.6,8.6,10.5,8.0,1.1,3.1,3.0)
#end

#macro CAP_SMD_ELKO_1010(value)
  CAP_SMD_ELKO_BASE(10.6,10.6,10.5,10.0,1.1,4.7,3.3)
#end

#macro CAP_SMD_ELKO_1012(value)
  CAP_SMD_ELKO_BASE(10.6,10.6,12.3,10.0,1.2,4.5,3.9)
#end

#macro CAP_SMD_ELKO_1014(value)
  CAP_SMD_ELKO_BASE(10.6,10.6,14.3,10.0,1.2,4.5,3.9)
#end

#macro CAP_SMD_ELKO_1212(value)
  CAP_SMD_ELKO_BASE(12.8,12.8,12.5,12.5,1.2,4.7,4)
#end

#macro CAP_SMD_ELKO_1214(value)
  CAP_SMD_ELKO_BASE(12.8,12.8,14.5,12.5,1.2,4.7,4)
#end



#macro panasonic_elko_ABCDEFG(L,W,H,D,B,S,C)
  union {
     #switch (D)
         #range (3.9,4.1)
            #local sc=0.6;
            #local dx=0.5;
            #break
         #range (4.9,5.1)
            #local sc=0.7;
            #local dx=0.6;
            #break
         #range (6.2,6.4)
            #local sc=0.9;
            #local dx=0.7;
            #break
         #range (7.9,8.1)
            #local sc=1.2;
            #local dx=0.9;
            #break
         #range (9.9,10.1)
            #local sc=1.3;
            #local dx=1.0;
         #range (12.4,12.5)
            #local sc=1.4;
            #local dx=1.0;
         #range (15.9,16.1)
            #local sc=1.4;
            #local dx=1.0;
         #range (17.9,18.1)
            #local sc=1.4;
            #local dx=1.0;
         #else
            #local sc=1.4;
            #local dx=1.0;
         #end

     text {
        ttf besch_font value 0.5,0
        scale sc
        rotate <90,180,0>
        translate <dx,H+0.01,0>
        pigment {
           Gray20
           }
        }
     #local value="";
     CAP_SMD_ELKO_BASE(L,W,H,D,B,S,C) // no label.
     }
#end

#macro CAP_SMD_ELKO_PANASONIC_B(value)
  panasonic_elko_ABCDEFG(4.3,4.3,5.8,4.0,0.65,1.0,1.8)
#end

#macro CAP_SMD_ELKO_PANASONIC_C(value)
  panasonic_elko_ABCDEFG(5.3,5.3,5.8,5.0,0.65,1.5,2.2)
#end

#macro CAP_SMD_ELKO_PANASONIC_D(value)
  panasonic_elko_ABCDEFG(6.6,6.6,5.8,6.3,0.65,1.8,2.6)
#end

#macro CAP_SMD_ELKO_PANASONIC_D8(value)
  panasonic_elko_ABCDEFG(6.6,6.6,7.7,6.3,0.65,1.8,2.6)
#end

#macro CAP_SMD_ELKO_PANASONIC_E(value)
  panasonic_elko_ABCDEFG(8.3,8.3,6.2,8.0,0.65,2.2,3.4)
#end

#macro CAP_SMD_ELKO_PANASONIC_F(value)
  panasonic_elko_ABCDEFG(8.3,8.3,10.2,8.0,0.9,3.1,3.4)
#end

#macro CAP_SMD_ELKO_PANASONIC_G(value)
  panasonic_elko_ABCDEFG(10.3,10.3,10.2,10.0,0.9,4.6,3.5)
#end


// 05.04.2023, wk; add H13, J16, K16
#macro to__panasonic(D,L,AB,H,I,W,P,K)
  panasonic_elko_ABCDEFG(AB,AB,L,D,W,P,I)
#end

#macro CAP_SMD_ELKO_PANASONIC_H13(value)
  to__panasonic(12.5,13.5,13.5,15,4.7,0.9,4.4,0.7)
#end

#macro CAP_SMD_ELKO_PANASONIC_J16(value)
  to__panasonic(16,16.5,17,19,5.5,1.2,6.7,0.7)
#end

#macro CAP_SMD_ELKO_PANASONIC_K16(value)
  to__panasonic(18,16.5,19,21,6.7,1.2,6.7,0.7)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:153CLV-0405=CAP_SMD_ELKO_0405(:Vishay SMD Elko
//rcl:153CLV-0505=CAP_SMD_ELKO_0505(:Vishay SMD Elko
//rcl:153CLV-0605=CAP_SMD_ELKO_0605(:Vishay SMD Elko
//rcl:153CLV-0807=CAP_SMD_ELKO_0807(:Vishay SMD Elko
//rcl:175TMP-0808=CAP_SMD_ELKO_0808(:Vishay SMD Elko
//rcl:140CLH-0810=CAP_SMD_ELKO_0810(:Vishay SMD Elko
//rcl:150CLZ-0810=CAP_SMD_ELKO_0810(:Vishay SMD Elko
//rcl:153CLV-0810=CAP_SMD_ELKO_0810(:Vishay SMD Elko
//rcl:175TMP-0810=CAP_SMD_ELKO_0810(:Vishay SMD Elko
//rcl:140CLH-1010=CAP_SMD_ELKO_1010(:Vishay SMD Elko
//rcl:150CLZ-1010=CAP_SMD_ELKO_1010(:Vishay SMD Elko
//rcl:153CLV-1010=CAP_SMD_ELKO_1010(:Vishay SMD Elko
//rcl:153CLV-1012=CAP_SMD_ELKO_1012(:Vishay SMD Elko
//rcl:140CLH-1014=CAP_SMD_ELKO_1014(:Vishay SMD Elko
//rcl:153CLV-1014=CAP_SMD_ELKO_1014(:Vishay SMD Elko
//rcl:150CLZ-1014=CAP_SMD_ELKO_1014(:Vishay SMD Elko
//=CAP_SMD_ELKO_1212(:Vishay SMD Elko
//=CAP_SMD_ELKO_1214(:Vishay SMD Elko
//=CAP_SMD_ELKO_PANASONIC_A(:SMD Elko Panasonic A (rcl.lib)
//rcl:PANASONIC_B=CAP_SMD_ELKO_PANASONIC_B(:SMD Elko Panasonic B (rcl.lib)
//rcl:PANASONIC_C=CAP_SMD_ELKO_PANASONIC_C(:SMD Elko Panasonic C (rcl.lib)
//rcl:PANASONIC_D=CAP_SMD_ELKO_PANASONIC_D(:SMD Elko Panasonic D (rcl.lib)
//rcl:PANASONIC_D8=CAP_SMD_ELKO_PANASONIC_D8(:SMD Elko Panasonic D8 (rcl.lib)
//rcl:PANASONIC_E=CAP_SMD_ELKO_PANASONIC_E(:SMD Elko Panasonic E (rcl.lib)
//rcl:PANASONIC_F=CAP_SMD_ELKO_PANASONIC_F(:SMD Elko Panasonic F (rcl.lib)
//rcl:PANASONIC_G=CAP_SMD_ELKO_PANASONIC_G(:SMD Elko Panasonic G (rcl.lib)
//=CAP_SMD_ELKO_PANASONIC_H13(:SMD Elko Panasonic H13
//=CAP_SMD_ELKO_PANASONIC_J16(:SMD Elko Panasonic J16
//=CAP_SMD_ELKO_PANASONIC_K16(:SMD Elko Panasonic K16
// end assignment
