/*******************************************************************************
 * Draws wire bend lead.
 * Erzeugt Drahtbuegel fuer ein Bauteil.
 * Author: Joseph Zeglinski
 * -----------------------------------------------------------------------------
 * Length    : length of body part     , Bauteil Laenge
 * Width     : diameter of body part   , Bauteil Durchmesser
 * Wirelength: length of one wire lead , Draht Laenge
 * Wirewidth : diameter of the wire    , Draht Durchmesser
 * Raster    : grid                    , Raster
 * BendRadius: bending radius          , Biegeradius
 * Separation: Distance between component bottom and pcb for heat dissipation
 * H_V       : Part Orientation horizontal or vertical - "H","V" (needs quotes)
 *------------------------------------------------------------------------------
 * Adds Resistor (or any component), Horizontal or Vertical wire leads,
 * based on (raster,body & wire) dimensions.
 * It forms a semi-circular bend with a radius with the value of "BendRadius".
 * The component making the call must be centred at the origin, at that point.
 * Lead clipping is also handled.
 * 
 * This macro will handle "RADIAL LEAD COMPONENTS as well.
 * Here, the "Raster" argument is set equal to, or narrower than the
 * body "Length" argument, and "H_V" is specified as "H" - for horizontal orien-
 * tation. For "tall" components, the "body Length" is the horizontal width, as
 * mounted. Similarly, the "body Width", is the height of the fully mounted
 * radial-leaded component (e.g  capacitor, or vertical ceramic block
 * resistor PVxx).
 * 
 * Finally, "Separation" - (height above the PCB, after attaching wires), is
 * also accounted for, in the wires.
 * This seperation is typically for raising power components >= 1 watt,
 * 1.5 mm above the surface to prevent scorching the PCB. However, for items
 * like Radial Lead Capacitors, this value can be any size. The calling module
 * must perform the actual "translate" of the fully assembled part, from the
 * origin, to the final position, upon return.
 ******************************************************************************/
#macro TOOLS_WIRE_LEADS (Length, Width, Wirelength, Wirewidth,  Raster,  BendRadius, Separation, H_V)
  #if (Width > Wirewidth)
     #local W = Width/2;
  #else
     #local W = Wirewidth/2;
  #end

  #local L = Length / 2;
  #local LW = Wirewidth / 2;
  #local WA = (Width - Wirewidth) / 2;
  #local Stub = max(0.8, Wirewidth);                // Set the component's "Stub Length" from the body to the start of bending
  #local Horizontal = !(strcmp(strupr(H_V), "H"));  // string compare returns "0" (false) if equal; therefore, Negate this.


  // Special section to handle "RADIAL LEAD" components, like capacitors, inductors, or ceramic block vertical power resistors.
  #if (Horizontal = yes)
      #if ( Raster <= Length )
          // Special case for "Leads inside of the body length" (e.g. "RADIAL LEAD" Components)    
          #local BendRadius = 0.0;        
          #local Stub = 0.0;
      #end
  #end

  union {
     // Attach the wire leads to the "COMPONENT" body:
     #if (Horizontal = no)
         /*************************
          * Vertical
          ************************/
         //TOP axial stub
         cylinder{<0,L/2,0> <0, (L+Stub) ,0> Wirewidth/2}

         //TOP (Perpendicular to body,  WIRE)
         cylinder{<BendRadius, (L+BendRadius+Stub),0> <(Raster-BendRadius), (L+BendRadius+Stub), 0> Wirewidth/2 }
         //LEFT-TOP (wire elbow bend)
         difference{
            torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
            box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
            box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>}
            translate <BendRadius, (L+Stub), 0>
            }
         //RIGHT-TOP (second wire elbow bend)
         difference{
            torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
            box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
            box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>} rotate<0,180,0>
            translate <(Raster-BendRadius), (L+Stub), 0>
            }

         #if(pin_short = on)
         difference{union{
         #end

         //RIGHT (vertical wire) - if "Raster" happens to be LONGER than remaining lead wire length, then
         //      "solder-on an extension wire", to reach the PCB cutoff position
         #local cutoff = (pin_length+pcb_height) + (L+Stub+Separation) ;
         cylinder{<Raster, min(-cutoff, (L+Stub)-(Wirelength-(pi*BendRadius+Raster)) ) ,0 > <Raster,(L+Stub),0> Wirewidth/2}
         //LEFT-BOTTOM (axial wire)
         cylinder{<0,-(L),0> <0,min(-cutoff, -(Wirelength+(L+Stub)) ),0> Wirewidth/2 }

         #if(pin_short = on)
         }box{<-LW,-cutoff,LW><Raster+LW,-(cutoff+Wirelength),-LW> }}
         #end

     #else
         /*************************
          * Horizontal
          ************************/
        //LEFT (wire elbow bend)
        difference{
           torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
           box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
           box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>}
           translate <-(Raster/2-BendRadius), -BendRadius, 0>
           }
        //RIGHT (second wire elbow bend)
        difference{
           torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
           box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
           box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>} rotate<0,180,0>
           translate <(Raster/2-BendRadius), -BendRadius, 0>
           }
        //Horizontal WIRE end-to-end, between elbows
        cylinder{<-(Raster/2-BendRadius), 0, 0> <(Raster/2-BendRadius), 0, 0> Wirewidth/2}

        #if(pin_short = on)
        difference{union{
        #end

        // If lead wire is somehow specified too short,
        // then "solder-on an extension wire",
        // to reach the PCB cutoff position, anyway
        #local cutoff = (pin_length+pcb_height) + (W + Separation);

        //RIGHT vertical wire
        cylinder{<Raster/2,-BendRadius,0 > <Raster/2, min(-cutoff, -(Wirelength-pi*BendRadius/2) ),0> Wirewidth/2 }

        //LEFT  vertical wire
        cylinder{<-Raster/2,-BendRadius,0> <-Raster/2, min(-cutoff, -(Wirelength-pi*BendRadius/2) ),0> Wirewidth/2 }

        #if(pin_short = on)
        }box{<-Raster/2-LW, -cutoff, LW> <Raster/2+LW,  -(cutoff+Wirelength),-LW>}}
        #end

     // end horizontal or vertical
     #end
     texture{col_silver}
     }    
#end
