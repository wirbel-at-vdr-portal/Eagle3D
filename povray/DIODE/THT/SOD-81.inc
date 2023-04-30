/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * THT glass diode SOD-81
 * 30.04.2023, wk
 ******************************************************************************/
#macro SOD81(value,pitch)
  #local A = 28.0;
  #local B = 3.80;
  #local C = 0.81;
  #local D = 2.15;
  #local E = (5.00 - B)/2;

  axial_diode(value,A,B,C,D,E,pitch,"Glass")
#end

#macro DIODE_THT_SOD81_102mm(value)
  SOD81(value, 4*2.54)
  translate <0,0.5,0>
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//diode:SOD81=DIODE_THT_SOD81_102mm(:THT diode SOD-81
//diode:SOD81Z=DIODE_THT_SOD81_102mm(:THT diode SOD-81
// end assignment
