/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Simple wire jumper(len,colour)
 *
 * Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * modified: Adriano Gandolfo <adrirobot(at)yahoo.it>
 * modified: Emil Crisbaseanu <emilcrisba(at)gmail.com>
 * modified: wk
 * *****************************************************************************/
#macro SPC_JUMPER_WIRE_BASE(Lg,value)
  #local h = 0.9;
  #local Dia = -1;
  #local Col = Brown;

  #if (strcmp(value,"1") = 0)
     #local Dia = 0.6;
     #local Col = Brown;
  #end

  #if (strcmp(value,"2") = 0)
     #local Dia = 0.6;
     #local Col = Red;
  #end

  #if (strcmp(value,"3") = 0)
     #local Dia = 0.6;
     #local Col = Orange;
  #end

  #if (strcmp(value,"4") = 0)
     #local Dia = 0.6;
     #local Col = Yellow;
  #end

  #if (strcmp(value,"5") = 0)
     #local Dia = 0.6;
     #local Col = Blue;
  #end

  #if (strcmp(value,"6") = 0)
     #local Dia = 0.6;
     #local Col = Green;
  #end

  #if (strcmp(value,"7") = 0)
     #local Dia = 0.6;
     #local Col = Pink;
  #end

  #if (strcmp(value,"8") = 0)
     #local Dia = 0.6;
     #local Col = Gray60;
  #end

  #if (strcmp(value,"9") = 0)
     #local Dia = 0.6;
     #local Col = White;
  #end

  union {
     object {
        TOOLS_WIRE_LEADS(0, 1, 1, 0.4,  Lg,  0.5, 0, "H")
        translate <0,h,0>
        }
     #if (Dia > 0)
        cylinder {
           <-(Lg-1)/2,h,0>,
           <+(Lg-1)/2,h,0>,
           Dia
           pigment {
              Col
              }
           finish {
              Shiny
              }
           }
     #end
     }
#end

#macro SPC_JUMPER_WIRE_5MM(value)
  SPC_JUMPER_WIRE_BASE(5.08,value)
#end

#macro SPC_JUMPER_WIRE_7MM(value)
  SPC_JUMPER_WIRE_BASE(7.62,value)
#end

#macro SPC_JUMPER_WIRE_10MM(value)
  SPC_JUMPER_WIRE_BASE(10.16,value)
#end

#macro SPC_JUMPER_WIRE_12MM(value)
  SPC_JUMPER_WIRE_BASE(12.7,value)
#end

#macro SPC_JUMPER_WIRE_15MM(value)
  SPC_JUMPER_WIRE_BASE(15.24,value)
#end

#macro SPC_JUMPER_WIRE_17MM(value)
  SPC_JUMPER_WIRE_BASE(17.78,value)
#end

#macro SPC_JUMPER_WIRE_20MM(value)
  SPC_JUMPER_WIRE_BASE(20.32,value)
#end

#macro SPC_JUMPER_WIRE_22MM(value)
  SPC_JUMPER_WIRE_BASE(22.86,value)
#end

#macro SPC_JUMPER_WIRE_25MM(value)
  SPC_JUMPER_WIRE_BASE(25.40,value)
#end

#macro SPC_JUMPER_WIRE_27MM(value)
  SPC_JUMPER_WIRE_BASE(27.94,value)
#end

#macro SPC_JUMPER_WIRE_30MM(value)
  SPC_JUMPER_WIRE_BASE(30.48,value)
#end



/*******************************************************************************
 * generate simple wire jumpers
 * Gary French <gary@chromiteblue.com>
 *
 * Uses existing TOOLS_WIRE_LEADS macro to generate simple wire jumpers.
 * SPC_SIMPLE_WIRE_JUMPER_BASE(l,d,r,lw,dw,op,w)
 *   l:  length, passed to TOOLS_WIRE_LEADS:Length
 *   d:  diameter, passed to TOOLS_WIRE_LEADS:Width
 *   r:  raster, passed to TOOLS_WIRE_LEADS:Raster
 *   lw: length of wire, 2 * value passed to TOOLS_WIRE_LEADS:Wirelength
 *   dw:
 *   op: offset?
 *   w:
 * Defined values:
 *   jumper_diameter: wire diameter (defaults to AWG-24)
 *   jumper_bend_radius: radius of jumper corners
 *   jumper_seperation: distance of jumper from board surface
 * *****************************************************************************/
#macro SPC_SIMPLE_WIRE_JUMPER_BASE(l,d,r,lw,dw,op,w)
  #local user_pcb_hole_pitch = 2.54;

  // typical wire gauges scaled to Eagle3D
  #local dim_mm_awg_16 = 1.290; // AWG-16
  #local dim_mm_awg_18 = 1.024; // AWG-18
  #local dim_mm_awg_20 = 0.812; // AWG-20
  #local dim_mm_awg_22 = 0.644; // AWG-22
  #local dim_mm_awg_24 = 0.511; // AWG-24 (standard)
  #local dim_mm_awg_26 = 0.405; // AWG-26

  #local jumper_diameter = dim_mm_awg_24;
  #local jumper_bend_radius = 0.200;
  #local jumper_seperation = 0.0;

  object {
     TOOLS_WIRE_LEADS(l,d,lw*2,dim_mm_awg_24,r,
                      jumper_bend_radius,jumper_seperation,"H")
     translate <0,dim_mm_awg_24/2+op,0>
     }
#end

#macro SPC_SIMPLE_WIRE_JUMPER_05MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*2, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_07MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*3, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_10MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*4, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_12MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*5, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_15MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*6, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_20MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*8, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_25MM()
  SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*10, 20, 0.6, 0, 0.3)
#end

#macro SPC_SIMPLE_WIRE_JUMPER_30MM()
SPC_SIMPLE_WIRE_JUMPER_BASE(5.8, 2.2, 2.54*12, 20, 0.6, 0, 0.3)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/

// begin assignment
//=SPC_JUMPER_WIRE_5MM(:wire jumper 5.08mm
//=SPC_JUMPER_WIRE_7MM(:wire jumper 7.62mm
//=SPC_JUMPER_WIRE_10MM(:wire jumper 10.16mm
//=SPC_JUMPER_WIRE_12MM(:wire jumper 12.7mm
//=SPC_JUMPER_WIRE_15MM(:wire jumper 15.24mm
//=SPC_JUMPER_WIRE_17MM(:wire jumper 17.78mm
//=SPC_JUMPER_WIRE_20MM(:wire jumper 20.32mm
//=SPC_JUMPER_WIRE_22MM(:wire jumper 22.86mm
//=SPC_JUMPER_WIRE_25MM(:wire jumper 25.4mm
//=SPC_JUMPER_WIRE_27MM(:wire jumper 27.94mm
//=SPC_JUMPER_WIRE_30MM(:wire jumper 30.48mm
//jumper:05=SPC_SIMPLE_WIRE_JUMPER_05MM(:Wire jumper 5mm
//jumper:05C=SPC_SIMPLE_WIRE_JUMPER_05MM(:Wire jumper 5mm
//jumper:07=SPC_SIMPLE_WIRE_JUMPER_07MM(:Wire jumper 7mm
//jumper:10=SPC_SIMPLE_WIRE_JUMPER_10MM(:Wire jumper 10mm
//jumper:10E=SPC_SIMPLE_WIRE_JUMPER_10MM(:Wire jumper 10mm
//jumper:12=SPC_SIMPLE_WIRE_JUMPER_12MM(:Wire jumper 12mm
//jumper:15=SPC_SIMPLE_WIRE_JUMPER_15MM(:Wire jumper 15mm
//jumper:20=SPC_SIMPLE_WIRE_JUMPER_20MM(:Wire jumper 20mm
//jumper:25=SPC_SIMPLE_WIRE_JUMPER_25MM(:Wire jumper 25mm
//jumper:30=SPC_SIMPLE_WIRE_JUMPER_30MM(:Wire jumper 30mm
// end assignment
