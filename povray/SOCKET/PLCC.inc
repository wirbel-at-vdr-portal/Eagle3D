/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * B        : width in z axis        Breite (Z-Achse)
 * pin_l    : pins on L side         Pins auf einer L-Seite
 * pin_b    : pins on B side         Pins auf einer B-Seite
 * Li       : inner length           Laenge innen
 * Bi       : inner width            Breite innen
 * totalPins: total number of pins   Anzahl der Pins komplett
 * pincL    : pin correction L side  Korrektur für Pinausrichtung auf L-Seite
 * pincB    : pin correction B side  Korrektur für Pinausrichtung auf L-Seite
 * chip     : socketed chip name     Der Chip für den Sockel
 ******************************************************************************/
#macro SOCKET_PLCC_base(L,B,pin_l,pin_b,Li,Bi,totalPins,pincL,pincB,chip)

#local plcc20_pina = array[13][13]
       {{0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,2,1,1,1,2,0,0,0,0}
        {0,0,0,0,1,1,1,1,1,0,0,0,0}
        {0,0,0,0,1,1,0,1,1,0,0,0,0}
        {0,0,0,0,1,1,1,1,1,0,0,0,0}
        {0,0,0,0,2,1,1,1,2,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}}

#local plcc28_pina = array[13][13]
       {{0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}}

#local plcc32_pina = array[13][13]
       {{0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}}

#local plcc44_pina = array[13][13]
       {{0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,2,1,1,1,1,1,1,2,0,0}
        {0,0,0,1,1,1,1,1,1,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,1,1,1,1,1,1,0,0}
        {0,0,0,2,1,1,1,1,1,1,2,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}}

#local plcc52_pina = array[13][13]
       {{0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,2,1,1,1,1,1,1,1,2,0,0}
        {0,0,1,1,1,1,1,1,1,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,1,1,1,1,1,1,1,0,0}
        {0,0,2,1,1,1,1,1,1,1,2,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}}

#local plcc68_pina = array[13][13]
       {{0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,2,1,1,1,1,1,1,1,1,1,2,0}
        {0,1,1,1,1,1,1,1,1,1,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,1,1,1,1,1,1,1,1,1,0}
        {0,2,1,1,1,1,1,1,1,1,1,2,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}}

#local plcc84_pina = array[13][13]
       {{2,1,1,1,1,1,1,1,1,1,1,1,2}
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
        {2,1,1,1,1,1,1,1,1,1,1,1,2}}

  #switch(totalPins)
     #case (20)
        #local pinar = plcc20_pina;
        #break
     #case (28)
        #local pinar = plcc28_pina;
        #break
     #case (32)
        #local pinar = plcc32_pina;
        #break
     #case (44)
        #local pinar = plcc44_pina;
         #break
     #case (52)
        #local pinar = plcc52_pina;
        #break
     #case (68)
        #local pinar = plcc68_pina;
        #break
     #case (84)
        #local pinar = plcc84_pina;
        #break
     #else
        #local pinar = plcc20_pina;
     #end

  union {
     difference {
        union {
           box{<-L/2,0.6,-B/2+2><L/2,7.5,B/2-2>}
           box{<-L/2+2,0.6,-B/2><L/2-2,7.5,B/2>}
           cylinder{<-L/2+2,0.6,-B/2+2><-L/2+2,7.5,-B/2+2>,2}
           cylinder{<L/2-2,0.6,-B/2+2><L/2-2,7.5,-B/2+2>,2}
           cylinder{<-L/2+2,0.6,B/2-2><-L/2+2,7.5,B/2-2>,2}
           cylinder{<L/2-2,0.6,B/2-2><L/2-2,7.5,B/2-2>,2}
           }
        box{<-Li/2,2.6,-Bi/2><Li/2,7.6,Bi/2>}
        box{<sqrt(pow(L,2)+pow(B,2))/2-2.5,2.61,-0.8><-sqrt(pow(L,2)+pow(B,2))/2+2.5,7.6,0.8> rotate<0,-45,0>}

        #local i=0;
        #while (i<pin_l)
           box{<-0.3,2.61,0><0.3,7.6,-3> translate<1.27*i/2,0,Bi/2+2>}
           #if (i!=0) 
               box{<-0.3,2.61,0><0.3,7.6,-3> translate<-1.27*i/2,0,Bi/2+2>} 
           #end
           box{<-0.3,2.61,0><0.3,7.6,3> translate<1.27*i/2,0,-Bi/2-2>}
           #if (i!=0) 
               box{<-0.3,2.61,0><0.3,7.6,3> translate<-1.27*i/2,0,-Bi/2-2>} 
           #end
           #local i=i+2;
        #end

        #local i=0;
        #while (i<pin_b)
           box{<-3,2.61,0.3><0,7.6,-0.3> translate<Li/2+2,0,1.27*i/2>}
           #if (i!=0)
               box{<-3,2.61,0.3><0,7.6,-0.3> translate<Li/2+2,0,-1.27*i/2>} 
           #end
           box{<3,2.61,0.3><0,7.6,-0.3> translate<-Li/2-2,0,1.27*i/2>}
           #if (i!=0) 
               box{<3,2.61,0.3><0,7.6,-0.3> translate<-Li/2-2,0,-1.27*i/2>} 
           #end
           #local i=i+2;
        #end

        cylinder{<0,0,0><0,4,0>1.5}
        box{<-3,0,0><3,7.6,3> rotate<0,-45,0> translate<-L/2+1,0,B/2-1>}
        box{<-1,2.61,-1><1,7.6,1> rotate<0,-45,0> translate<-L/2+2.5,0,B/2-2.5>}
        box{<-1,2.61,-1><1,7.6,1> rotate<0,-45,0> translate<L/2-2,0,-B/2+2>}
        }
     box{<-1,1.5,0><1,7.5,1> rotate<0,-45,0> translate<-Li/2+0.5,0,Bi/2-0.5>}

     //Innere Kontaktfedern
     #local i=0;
     #while (i<pin_l)
        cylinder{<-0.25,5.5,Bi/2+1><0.25,5.5,Bi/2+1>0.8 texture{col_silver} translate<1.27*i/2,0,0>}
        #if (i!=0) 
            cylinder{<-0.25,5.5,Bi/2+1><0.25,5.5,Bi/2+1>0.8 texture{col_silver} translate<-1.27*i/2,0,0>} 
        #end
        cylinder{<-0.25,5.5,-Bi/2-1><0.25,5.5,-Bi/2-1>0.8 texture{col_silver} translate<1.27*i/2,0,0>}
        #if (i!=0) 
            cylinder{<-0.25,5.5,-Bi/2-1><0.25,5.5,-Bi/2-1>0.8 texture{col_silver} translate<-1.27*i/2,0,0>} 
        #end
        #local i=i+2;
     #end

     #local i=0;
     #while (i<pin_b)
         cylinder{<Li/2+1,5.5,-0.25><Li/2+1,5.5,0.25>0.8 texture{col_silver} translate<0,0,1.27*i/2>}
         #if (i!=0)
             cylinder{<Li/2+1,5.5,-0.25><Li/2+1,5.5,0.25>0.8 texture{col_silver} translate<0,0,-1.27*i/2>} 
         #end
         cylinder{<-Li/2-1,5.5,-0.25><-Li/2-1,5.5,0.25>0.8 texture{col_silver} translate<0,0,1.27*i/2>}
         #if (i!=0) 
             cylinder{<-Li/2-1,5.5,-0.25><-Li/2-1,5.5,0.25>0.8 texture{col_silver} translate<0,0,-1.27*i/2>} 
         #end
         #local i=i+2;
      #end

      //Pinplatzierung per Arrays
      union {
         #local i=-6;
         #while(i<7)
            #local j=-6;
            #while(j<7)
                #if (pinar[i+6][j+6]=1)
                    box{<-0.25,0.6,-0.1><0.25,-3,0.1> texture{col_silver} translate<j*2.54,0,i*2.54>}
                #end
                #if (pinar[i+6][j+6]=2)
                    cylinder{<0,0.05,0><0,0.6,0>1 translate<j*2.54,0,i*2.54>}
                #end
                #local j=j+1;
            #end
            #local i=i+1;
         #end

      object{chip translate<0,3.5,0> translate<-pincL,0,-pincB>}
      translate<pincL,0,pincB>}
      pigment{Gray40}
      }
#end


#macro SOCKET_PLCC20(value)
  SOCKET_PLCC_base(15.5,15.5,5,5,9,9,20,0,0,IC_SMD_PLCC20(value))
#end

#macro SOCKET_PLCC28(value)
  SOCKET_PLCC_base(18,18,7,7,11.5,11.5,28,-1.27,-1.27,IC_SMD_PLCC28(value))
#end

#macro SOCKET_PLCC32(value)
  SOCKET_PLCC_base(18,22.34,7,9,11.5,14,32,-1.27,0,IC_SMD_PLCC32(value))
#end

#macro SOCKET_PLCC44(value)
  SOCKET_PLCC_base(23.6,23.6,11,11,16.5,16.4,44,-1.27,-1.27,IC_SMD_PLCC44(value))
#end

#macro SOCKET_PLCC52(value)
  SOCKET_PLCC_base(25.9,25.9,13,13,19.2,19.2,52,0,0,IC_SMD_PLCC52(value))
#end

#macro SOCKET_PLCC68(value)
  SOCKET_PLCC_base(31.8,31.8,16,16,24.1,24.1,68,0,0,IC_SMD_PLCC68(value))
#end

#macro SOCKET_PLCC84(value)
  SOCKET_PLCC_base(36.7,36.7,21,21,29.3,29.3,84,0,0,IC_SMD_PLCC84(value))
#end
