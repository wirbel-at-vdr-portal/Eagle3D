/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SOD-57
 * 01.05.2023, wk
 ******************************************************************************/
#macro SOD57(value,pitch)
  #local A = 26.00; // pin length
  #local B =  4.00; // body length
  #local C =  0.82; // pin diameter
  #local D =  3.60; // body diameter
  #local E = (D - B)/2; // min distance from body where C is expected
  axial_spherical_diode(value,A,B,C,D,E,pitch,"SinteredGlass")
#end

#macro DIODE_THT_SOD57_102mm(value)
  SOD57(value, 4*2.54)
#end


/*******************************************************************************
 * SOD-61, looks outdated.
 * 01.05.2023, wk
 ******************************************************************************/
#macro SOD61(value,B,pitch)
  #local A = 30.40; // pin length
  #local C =  0.60; // pin diameter
  #local D =  2.50; // body diameter
  #local E = (D - B)/2; // min distance from body where C is expected
  axial_spherical_diode(value,A,B,C,D,E,pitch,"SinteredGlass")
#end

#macro SOD61A(value,pitch)  #local B =  4.90; SOD61(value,B,pitch) #end // BY505, BY584
#macro SOD61AB(value,pitch) #local B =  5.50; SOD61(value,B,pitch) #end // BY8404
#macro SOD61AC(value,pitch) #local B =  8.30; SOD61(value,B,pitch) #end // BY8406
#macro SOD61AD(value,pitch) #local B =  8.70; SOD61(value,B,pitch) #end // BY609, BY610, BY8408
#macro SOD61AE(value,pitch) #local B =  9.10; SOD61(value,B,pitch) #end // BY8410
#macro SOD61AF(value,pitch) #local B =  9.50; SOD61(value,B,pitch) #end // BY707, BY8412
#macro SOD61AG(value,pitch) #local B =  9.90; SOD61(value,B,pitch) #end // BY8414
#macro SOD61AH(value,pitch) #local B = 10.50; SOD61(value,B,pitch) #end // BY8416
#macro SOD61AI(value,pitch) #local B = 11.50; SOD61(value,B,pitch) #end // BY619, BY620, BY8418
#macro SOD61AJ(value,pitch) #local B = 12.50; SOD61(value,B,pitch) #end // BY8420
#macro SOD61AK(value,pitch) #local B = 13.50; SOD61(value,B,pitch) #end // BY712, BY713, BY714, BY8424

#macro DIODE_THT_SOD61A_102mm(value)
  SOD61A(value, 4*2.54)
#end

#macro DIODE_THT_SOD61AD_152mm(value)
  SOD61AD(value, 6*2.54)
#end

#macro DIODE_THT_SOD61AF_152mm(value)
  SOD61AF(value, 6*2.54)
#end

#macro DIODE_THT_SOD61AI_178mm(value)
  SOD61AI(value, 7*2.54)
#end

#macro DIODE_THT_SOD61AK_203mm(value)
  SOD61AK(value, 8*2.54)
#end


/*******************************************************************************
 * SOD-64
 * 01.05.2023, wk
 ******************************************************************************/
#macro SOD64(value,pitch)
  #local A = 26.00; // pin length
  #local B =  4.00; // body length
  #local C =  1.35; // pin diameter
  #local D =  4.30; // body diameter
  #local E = (D - B)/2; // min distance from body where C is expected
  axial_spherical_diode(value,A,B,C,D,E,pitch,"SinteredGlass")
#end

#macro DIODE_THT_SOD64_102mm(value)
  SOD57(value, 4*2.54)
#end

#macro DIODE_THT_SOD64_127mm(value)
  SOD64(value, 5*2.54)
#end


/*******************************************************************************
 * SOD-83, rare case.
 * 01.05.2023, wk
 ******************************************************************************/
#macro SOD83(value,pitch)
  #local A = 26.50; // pin length
  #local B =  7.50; // body length
  #local C =  1.35; // pin diameter
  #local D =  4.50; // body diameter
  #local E = (D - B)/2; // min distance from body where C is expected
  axial_spherical_diode(value,A,B,C,D,E,pitch,"SinteredGlass")
#end

#macro DIODE_THT_SOD83_127mm(value)
  SOD83(value, 5*2.54)
#end


/*******************************************************************************
 * Vishay G4 case. BYW772 && FE3A to FE3D.
 * Rare case - refers to which standard?
 * 01.05.2023, wk
 ******************************************************************************/
#macro DIODE_G4(value,pitch)
  #local A = 25.40; // pin length
  #local B =  3.75; // body length
  #local C =  1.01; // pin diameter
  #local D =  3.75; // body diameter
  #local E = (7.60 - B)/2; // min distance from body where C is expected
  axial_spherical_diode(value,A,B,C,D,E,pitch,"SinteredGlass")
#end

#macro DIODE_THT_G4_127mm(value)
  DIODE_G4(value, 5*2.54)
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//diode:SOD57-10=DIODE_THT_SOD57_102mm(:THT diode SOD-57
//diode:SOD57Z10=DIODE_THT_SOD57_102mm(:THT diode SOD-57
//diode:SGA-10=DIODE_THT_SOD57_102mm(:THT diode SOD-57
//diode:DO204-10=DIODE_THT_SOD57_102mm(:THT diode SOD-57
//diode:SOD61A=DIODE_THT_SOD61A_102mm(:THT diode SOD-61A
//diode:SOD61B=DIODE_THT_SOD61AD_152mm(:THT diode SOD-61AD
//diode:SOD61C=DIODE_THT_SOD61AI_178mm(:THT diode SOD-61AI
//diode:SOD61D=DIODE_THT_SOD61AF_152mm(:THT diode SOD-61AF
//diode:SOD61E=DIODE_THT_SOD61AK_203mm(:THT diode SOD-61AK
//diode:SOD64-10=DIODE_THT_SOD64_102mm(:THT diode SOD-64
//diode:SOD64Z10=DIODE_THT_SOD64_102mm(:THT diode SOD-64
//diode:SOD64-12=DIODE_THT_SOD64_127mm(:THT diode SOD-64
//diode:SOD64Z12=DIODE_THT_SOD64_127mm(:THT diode SOD-64
//diode:SOD83-12=DIODE_THT_SOD83_127mm(:THT diode SOD-83
//diode:G4-12=DIODE_THT_G4_127mm(:THT diode Vishay G4:
// end assignment
