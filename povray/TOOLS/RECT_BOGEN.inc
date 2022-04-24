/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Draws a bended rectangular profile, with angle 1-179 deg.
 * Author: Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
 *------------------------------------------------------------------------------
 * Macro fuer gebogene Rechteckprofile mit Oeffnungswinkel von 1-179 Grad
 * i_radius : inner radius, >= 0
 * winkel   : bend angle. greather 0 and less 180
 * dicke    : thickness
 * breite   : width
 * laenge1  : length 1
 * laenge2  : length 2
 *------------------------------------------------------------------------------
 * Der Schenkel mit der laenge1 liegt mittig auf der x-Achse
 * bei einem Winkel von 90Grad der andere auf der y-Achse
 * der Innenradius muss >= 0 sein,
 * der Winkel zwischen den Schenkeln 0 > Winkel <180,
 * mittlerer Biegeradius = i_radius + dicke/2
 ******************************************************************************/
#macro TOOLS_RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
union {
   difference {
      cylinder{<(breite/2) * -1,0,0><breite/2,0,0>(i_radius + dicke)}
      cylinder{<(breite/2 + 0.1) * -1,0,0><breite/2 + 0.1,0,0>i_radius}
      box{<-(breite/2 + 0.1), -(i_radius + dicke + 0.1), 0>,
          < (breite/2 + 0.1),  (i_radius + dicke + 0.1), (i_radius + dicke + 0.1)>}
      box{<-(breite/2 + 0.1), -(i_radius + dicke + 0.1), 0>,
          < (breite/2 + 0.1),  (i_radius + dicke + 0.1), (i_radius + dicke + 0.1)>
          rotate <winkel,0,0>}
      }
   box{<-(breite/2),i_radius        , 0>,
       < (breite/2),i_radius + dicke, laenge1 >}
   box{<-(breite/2), 0          , -(i_radius)>,
       < (breite/2),laenge2 * -1, -(i_radius + dicke)> rotate <-(90 - winkel),0,0>}
   translate < 0,(i_radius + dicke/2) * -1,(i_radius + dicke/2)>
   rotate <0,-90,180>
   }
#end
