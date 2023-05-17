/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * generate simple wire jumpers
 * Gary French <gary@chromiteblue.com>
 *
 * Uses existing TOOLS_WIRE_LEADS macro to generate simple wire jumpers.
 * WireJumper(l,d,r,lw,dw,op,w)
 *   l:  length, passed to TOOLS_WIRE_LEADS:Length
 *   d:  diameter, passed to TOOLS_WIRE_LEADS:Width
 *   r:  raster, passed to TOOLS_WIRE_LEADS:Raster
 *   lw: length of wire, 2 * value passed to TOOLS_WIRE_LEADS:Wirelength
 *   dw:
 *   op: offset?
 *   w:
 ******************************************************************************/
#macro WireJumper(l,d,r,lw,dw,op,w)
  //#local dim_mm_awg_16 = 1.290; // AWG-16
  //#local dim_mm_awg_18 = 1.024; // AWG-18
  //#local dim_mm_awg_20 = 0.812; // AWG-20
  //#local dim_mm_awg_22 = 0.644; // AWG-22
    #local dim_mm_awg_24 = 0.511; // AWG-24 (standard)
  //#local dim_mm_awg_26 = 0.405; // AWG-26
  object { 
     TOOLS_WIRE_LEADS(l,d,lw*2,dim_mm_awg_24,r,1.2,0,"H")
     translate <0,dim_mm_awg_24/2+op,0>
     }
#end

#macro CON_THT_WIRE_JUMPER_04mm() WireJumper(2.8, 2.2, 2.00*2 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_05mm() WireJumper(2.8, 2.2, 2.54*2 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_07mm() WireJumper(5.8, 2.2, 2.54*3 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_10mm() WireJumper(5.8, 2.2, 2.54*4 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_12mm() WireJumper(5.8, 2.2, 2.54*5 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_15mm() WireJumper(5.8, 2.2, 2.54*6 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_20mm() WireJumper(5.8, 2.2, 2.54*8 , 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_25mm() WireJumper(5.8, 2.2, 2.54*10, 20, 0.6, 1.5, 0.3) #end
#macro CON_THT_WIRE_JUMPER_30mm() WireJumper(5.8, 2.2, 2.54*12, 20, 0.6, 1.5, 0.3) #end

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//jumper:04C=CON_THT_WIRE_JUMPER_04mm(:Wire jumper 4mm
//jumper:05=CON_THT_WIRE_JUMPER_05mm(:Wire jumper 5mm
//jumper:05C=CON_THT_WIRE_JUMPER_05mm(:Wire jumper 5mm
//jumper:07=CON_THT_WIRE_JUMPER_07mm(:Wire jumper 7mm
//jumper:10=CON_THT_WIRE_JUMPER_10mm(:Wire jumper 10mm
//jumper:10E=CON_THT_WIRE_JUMPER_10mm(:Wire jumper 10mm
//jumper:12=CON_THT_WIRE_JUMPER_12mm(:Wire jumper 12mm
//jumper:15=CON_THT_WIRE_JUMPER_15mm(:Wire jumper 15mm
//jumper:20=CON_THT_WIRE_JUMPER_20mm(:Wire jumper 20mm
//jumper:25=CON_THT_WIRE_JUMPER_25mm(:Wire jumper 25mm
//jumper:30=CON_THT_WIRE_JUMPER_30mm(:Wire jumper 30mm
// end assignment
