/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMT chip array
 * Tiefe, Breite, Hoehe, Breite Loetflaechen, Abstand Pin zu Pin,
 * Anzahl Kondensatoren,Farbe des Koerpers
 ******************************************************************************/
#macro CAP_SMD_CHIP_ARRAY_BASE(b,l,h,blf,pitch,n)
  union {
     object { //Body
        Round_Box_Union(<0,0.05,0>, <l,h,b>, min(b,l,h)/6)
        translate <-l/2,0,-b/2>
        texture { col_ceramic_cap }
        }

     // Pins
     #local i = 0;
     #local x_pos = -(n-1)/2*pitch;
     union {
        #while(i<n)
            box {
               <-blf/2,0,b/2+0.01>
               <+blf/2,h,b/2-b/10>
               translate<x_pos,0,0>
               }
            box {
               <-blf/2,0,-b/2-0.01>
               <+blf/2,h,-b/2+b/10>
               translate<x_pos,0,0>
               }
            #local i = i+1;
            #local x_pos = x_pos + pitch;
            #end
        texture { col_silver }
        }
     }
#end

#macro CAP_SMD_CHIP_ARRAY_4X0603_0612()
  CAP_SMD_CHIP_ARRAY_BASE(1.60,3.20,0.8,0.4,0.8,4)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CAP_SMD_CHIP_ARRAY_4X0603_0612(:SMT Cap array 4x0603 0612
// end assignment
