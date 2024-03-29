/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Kupferlackspule um Ringkern
 * Joerg Bredendiek <sprut(replace with at)sprut.de>
 *
 * Nullpunkt:
 *      stehende Spule: zwischen den Anschluessen
 *      liegende Spule: in Ringkernmitte
 *
 * a = Abstand der Anschluesse
 * b = Breite des Kerns
 * d = Durchmesser des Kerns
 * dd= Drahtdicke
 * e = Abstand vom Ringkernmittelpunkt zum ersten Anschluss, nur bei liegender Spule
 * o = 0 == liegend, sonst stehend
 ******************************************************************************/
#macro SPC_L_TOROIDAL_BASE(a,b,d,dd,e,o)

  #macro L_TOROIDAL_KERN(b,d) // gelber Ringkern
     union {
        object {
           torus { radmaj, radmin }
           translate <0, -delta/2, 0>
           }
        object {
           torus { radmaj, radmin }
           translate <0, delta/2, 0>
           }
        difference {
           cylinder {<0,-delta/2    , 0> <0,+delta/2    , 0> radmaj+radmin}
           cylinder {<0,-delta/2-0.1, 0> <0,+delta/2+0.1, 0> radmaj-radmin}
           }
        texture {
           pigment {
              color Yellow
              }
           }
        }
     #end

  #macro L_TOROIDAL_WINDUNG() // eine einzelne Windung
     torus {
        radmin+dd/2, dd/2
        texture {
           T_Gold_1A
           }
        }
     #end


  #macro L_TOROIDAL_SPULE() // Windungen um den Kern
     union {
        #local i=1;
        #local ss = 0;
        #local ss=int((radmaj-radmin-dd/2)*2*3.14/dd-0.5); //Anzahl der Windungen um den Kern zu fuellen
        #while(i<ss)
           union {
              difference {
                 union {
                    object { L_TOROIDAL_WINDUNG() translate <-delta/2, 0, 0> }
                    object { L_TOROIDAL_WINDUNG() translate < delta/2, 0, 0> }
                    }
                 box { <-delta/2, -dd, radmin+dd><delta/2, dd, -radmin-dd> }
                 }
              cylinder{<-delta/2, 0, radmin+dd/2>< delta/2, 0, radmin+dd/2> dd/2 texture {T_Gold_1A }}
              cylinder{<-delta/2, 0,-radmin-dd/2>< delta/2, 0,-radmin-dd/2> dd/2 texture {T_Gold_1A }}
              translate <0, 0, radmaj>
              rotate <90+i*360/ss, 0, 0>
              }
           #local i=i+1;
           #end
        }
        #end

  #macro L_TOROIDAL_CONTV() // Anschluesse fuer stehende Spule
     #local ra=1;
     #local bends=array[5] {
     // <angle, radius, 0> or <0, distance, 0> for straight pipe,  negative angles bend left, positive bend right.
     <0, 3+1.5*dd-ra+2*radmin, 0>,  <-90, ra, 0>,  <0,a-2*ra,0>,  <-90,ra,0>,  <0, 3+1.5*dd-ra+2*radmin, 0> }

     // this pipe has a radius of dd/2, starts at the origin, and initially goes in the y direction
     TOOLS_BENTPIPE( dd/2, <0,0,0>, y, bends )
     #end

  //Anschluesse fuer liegende Spule
  #macro L_TOROIDAL_CONTH()
     #local ra=a/2;
     #if (ra>b)
        #local ra=b;
     #end
     #local bends=array[5] {
        // <angle, radius, 0> or <0, distance, 0> for straight pipe, negative angles bend left, positive bend right.
        <0, 3+1.5*dd+b-ra, 0>,  <-90, ra, 0>,  <0,a-2*ra,0>,  <-90,ra,0>,  <0, 3+1.5*dd+b-ra, 0>
        }
     // this pipe has a radius of dd/2, starts at the origin, and initially goes in the y direction
     TOOLS_BENTPIPE( dd/2, <0,0,0>, y, bends )
     #end


  #macro L_TOROIDAL_SFT(a,b,d,dd) //Makro fuer stehende Spule
     #local radmin = d/10;
     #local radmaj = d/2-radmin;
     #local delta  = b- 2*radmin;
     union {
        object { L_TOROIDAL_KERN(b,d) rotate<0,0,90> translate<0,radmaj+radmin+dd,0> }
        object { L_TOROIDAL_SPULE()                  translate<0,radmaj+radmin+dd,0> }
        object { L_TOROIDAL_CONTV()   translate<a/2, -3, 0> texture { T_Gold_1A }    }
        }
     #end

  #macro L_TOROIDAL_ED(a,b,d,dd,e) // Makro fuer liegende Spule
     #local radmin = d/10;
     #local radmaj = d/2-radmin;
     #local delta  = b- 2*radmin;
     union {
        object {L_TOROIDAL_KERN(b,d) rotate<0,0, 0>  translate<0,b/2+dd,0>}
        object {L_TOROIDAL_SPULE()   rotate<0,0,-90>  translate<0,b/2+dd,0>}
        object {L_TOROIDAL_CONTH()   translate<-e, -3, 0> texture {T_Gold_1A }}
        }
     #end

  #if(o=0)
     object{L_TOROIDAL_SFT(a,b,d,dd)}
  #else
     object{L_TOROIDAL_ED(a,b,d,dd,e)}
  #end
#end


#macro SPC_L_TOROIDAL_SFT830D()
  SPC_L_TOROIDAL_BASE(10.16, 6.35, 15.875, 1,0,1)
#end

#macro SPC_L_TOROIDAL_SFT830S()
  SPC_L_TOROIDAL_BASE(10.16, 8.255, 15.875, 1,0,1)
#end

#macro SPC_L_TOROIDAL_SFT840D()
  SPC_L_TOROIDAL_BASE(12.7 , 8.89, 15.24, 1,0,1)
#end

#macro SPC_L_TOROIDAL_SFT1030()
  SPC_L_TOROIDAL_BASE(12.7 , 8.255, 20.32, 1,0,1)
#end

#macro SPC_L_TOROIDAL_SFT1040()
  SPC_L_TOROIDAL_BASE(15.24 , 10.8, 20.32, 1,0,1)
#end

#macro SPC_L_TOROIDAL_SFT1240()
  SPC_L_TOROIDAL_BASE(15.24 , 10.8, 22.86, 1,0,1)
#end

#macro SPC_L_TOROIDAL_ED16()
  SPC_L_TOROIDAL_BASE(3.5*1.27 , 10.8, 12*1.27, 0.6, 3*1.27,0)
#end

#macro SPC_L_TOROIDAL_ED22()
  SPC_L_TOROIDAL_BASE(4*1.27 , 10.8, 16*1.27, 0.8, 4.5*1.27,0)
#end

#macro SPC_L_TOROIDAL_ED26()
  SPC_L_TOROIDAL_BASE(5.5*1.27 , 10.8, 19*1.27, 1, 5*1.27,0)
#end

#macro SPC_L_TOROIDAL_ED38()
  SPC_L_TOROIDAL_BASE(9*1.27 , 15, 26*1.27, 0.6, 6*1.27,0)
#end

#macro SPC_L_TOROIDAL_ED43()
  SPC_L_TOROIDAL_BASE(10*1.27 , 15, 30*1.27, 1.4, 7*1.27,0)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//inductor:SFT830D=SPC_L_TOROIDAL_SFT830D(:toroid coil
//inductor:SFT830S=SPC_L_TOROIDAL_SFT830S(:toroid coil
//inductor:SFT1030=SPC_L_TOROIDAL_FT1030(:toroid coil
//inductor:SFT840D=SPC_L_TOROIDAL_SFT840D(:toroid coil
//inductor:SFT1040=SPC_L_TOROIDAL_SFT1040(:toroid coil
//inductor:SFT1240=SPC_L_TOROIDAL_SFT1240(:toroid coil
//inductor:ED16=SPC_L_TOROIDAL_ED16(:toroid coil
//inductor:ED22=SPC_L_TOROIDAL_ED22(:toroid coil
//inductor:ED26=SPC_L_TOROIDAL_ED26(:toroid coil
//inductor:ED38=SPC_L_TOROIDAL_ED38(:toroid coil
//inductor:ED43=SPC_L_TOROIDAL_ED43(:toroid coil
// end assignment
