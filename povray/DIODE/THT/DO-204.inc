/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/
//#include "DIODE/THT/axial.inc"

/*******************************************************************************
 * DO-204xx THT diode family
 * for table and A..E, see https://en.wikipedia.org/wiki/DO-204
 * see also https://www.topline.tv/DO.html
 * 27.04.2023, wk
 *
 * known obsolete packages:
 * - DO-1
 * - DO-2
 * - DO-3
 * - DO-4
 * - DO-6
 * - DO-8
 * - DO-9
 * - DO-10
 * - DO-11
 * - DO-12
 * - DO-14
 * - DO-16
 * - DO-17
 * - DO-18
 * - DO-19
 * - DO-20
 * - DO-21
 * - DO-22
 * - DO-23
 * - DO-24
 * - DO-25
 * - DO-26
 * - DO-27
 * - DO-28
 * - DO-30
 * - DO-31
 * - DO-32
 * - DO-33
 * - DO-36
 * - DO-37
 * - DO-38
 * - DO-39
 * - DO-40
 * - DO-42
 * - DO-43
 * - DO-44
 * - DO-45
 * - D0-202
 * - DO-206
 * - DO-207
 * - DO-210
 * - DO-211
 * - DO-212
 ******************************************************************************/
#macro DO204(value,Type,pitch,BodyColor)
  object {
     #if ((Type = "DO204-AA") | (Type = "DO-7 ")) #local A = (25.40 + 38.10)/2; #local B = (5.85 + 7.62 )/2; #local C = (0.46 + 0.55)/2; #local D = (2.16 + 2.71)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AB") | (Type = "DO-14")) #local A = (25.40 + 38.10)/2; #local B = (5.85 + 7.62 )/2; #local C = (0.46 + 0.55)/2; #local D = (2.75 + 3.55)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AC") | (Type = "DO-15")) #local A = (25.40 + 38.10)/2; #local B = (5.85 + 7.62 )/2; #local C = (0.69 + 0.88)/2; #local D = (2.65 + 3.55)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AD") | (Type = "DO-16")) #local A = (11.43 + 19.05)/2; #local B = (1.27 + 2.54 )/2; #local C = (0.23 + 0.33)/2; #local D = (1.27 + 1.27)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AE") | (Type = "DO-26")) #local A = (35.56 + 38.10)/2; #local B = (8.75 + 10.41)/2; #local C = (0.69 + 0.99)/2; #local D = (5.59 + 6.60)/2; #local E = 2.03; #end
     #if ((Type = "DO204-AF") | (Type = "DO-29")) #local A = (25.40 + 38.10)/2; #local B = (8.00 + 9.14 )/2; #local C = (0.74 + 0.83)/2; #local D = (3.05 + 3.81)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AG") | (Type = "DO-34")) #local A = (25.40 + 38.10)/2; #local B = (2.16 + 3.04 )/2; #local C = (0.46 + 0.55)/2; #local D = (1.27 + 1.90)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AH") | (Type = "DO-35")) #local A = (25.40 + 38.10)/2; #local B = (3.05 + 5.08 )/2; #local C = (0.46 + 0.55)/2; #local D = (1.53 + 2.28)/2; #local E = 1.27; #end
     #if  (Type = "DO204-AJ")                     #local A = (11.43 + 13.97)/2; #local B = (5.85 + 7.62 )/2; #local C = (0.49 + 0.53)/2; #local D = (2.16 + 2.66)/2; #local E = 1.27; #end
     #if  (Type = "DO204-AK")                     #local A = (11.43 + 13.97)/2; #local B = (3.81 + 4.45 )/2; #local C = (0.36 + 0.40)/2; #local D = (1.66 + 1.90)/2; #local E = 1.27; #end
     #if ((Type = "DO204-AL") | (Type = "DO-41")) #local A = (25.40 + 25.40)/2; #local B = (4.07 + 5.20 )/2; #local C = (0.72 + 0.86)/2; #local D = (2.04 + 2.71)/2; #local E = 1.27; #end
     #if  (Type = "DO204-AM")                     #local A = (17.53 + 38.10)/2; #local B = (3.18 + 5.20 )/2; #local C = (0.64 + 0.91)/2; #local D = (1.27 + 2.79)/2; #local E = 1.27; #end
     #if  (Type = "DO204-AN")                     #local A = (25.40 + 25.40)/2; #local B = (5.08 + 5.84 )/2; #local C = (0.71 + 0.86)/2; #local D = (2.54 + 3.05)/2; #local E = 1.27; #end
     #if  (Type = "DO204-AP")                     #local A = (25.40 + 38.10)/2; #local B = (3.18 + 4.57 )/2; #local C = (0.74 + 0.89)/2; #local D = (2.54 + 3.81)/2; #local E = 1.27; #end
     #if  (Type = "DO204-AR")                     #local A = (27.95 + 38.10)/2; #local B = (9.27 + 9.52 )/2; #local C = (1.22 + 1.32)/2; #local D = (6.10 + 6.35)/2; #local E = 2.54; #end

     axial_diode(value,A,B,C,D,E,pitch,BodyColor)
     }
#end

#macro DO204AA(value,pitch) DO204(value,"DO204-AA",pitch,"Glass")   #end
#macro DO204AB(value,pitch) DO204(value,"DO204-AB",pitch,"Plastic") #end
#macro DO204AC(value,pitch) DO204(value,"DO204-AC",pitch,"Plastic") #end
#macro DO204AD(value,pitch) DO204(value,"DO204-AD",pitch,"Plastic") #end
#macro DO204AE(value,pitch) DO204(value,"DO204-AE",pitch,"Plastic") #end
#macro DO204AF(value,pitch) DO204(value,"DO204-AF",pitch,"Glass")   #end
#macro DO204AG(value,pitch) DO204(value,"DO204-AG",pitch,"Glass")   #end
#macro DO204AH(value,pitch) DO204(value,"DO204-AH",pitch,"Glass")   #end
#macro DO204AJ(value,pitch) DO204(value,"DO204-AJ",pitch,"Plastic") #end
#macro DO204AK(value,pitch) DO204(value,"DO204-AK",pitch,"Plastic") #end
#macro DO204AL(value,pitch) DO204(value,"DO204-AL",pitch,"Plastic") #end
#macro DO41G(value,pitch)   DO204(value,"DO204-AL",pitch,"Glass")   #end
#macro DO204AM(value,pitch) DO204(value,"DO204-AM",pitch,"Plastic") #end
#macro DO204AN(value,pitch) DO204(value,"DO204-AN",pitch,"Plastic") #end
#macro DO204AP(value,pitch) DO204(value,"DO204-AP",pitch,"Plastic") #end
#macro DO204AR(value,pitch) DO204(value,"DO204-AR",pitch,"Plastic") #end


#macro DIODE_THT_DO204AA_025mm(value) DO204AA(value, 1*2.54) #end
#macro DIODE_THT_DO204AA_102mm(value) DO204AA(value, 4*2.54) #end
#macro DIODE_THT_DO204AB_025mm(value) DO204AB(value, 1*2.54) #end
#macro DIODE_THT_DO204AB_102mm(value) DO204AB(value, 4*2.54) #end
#macro DIODE_THT_DO204AC_025mm(value) DO204AC(value, 1*2.54) #end
#macro DIODE_THT_DO204AC_050mm(value) DO204AC(value, 2*2.54) #end
#macro DIODE_THT_DO204AC_102mm(value) DO204AC(value, 4*2.54) #end
#macro DIODE_THT_DO204AC_127mm(value) DO204AC(value, 5*2.54) #end
#macro DIODE_THT_DO204AC_152mm(value) DO204AC(value, 6*2.54) #end
#macro DIODE_THT_DO204AD_025mm(value) DO204AD(value, 1*2.54) #end
#macro DIODE_THT_DO204AD_050mm(value) DO204AD(value, 2*2.54) #end
#macro DIODE_THT_DO204AG_025mm(value) DO204AG(value, 1*2.54) #end
#macro DIODE_THT_DO204AG_050mm(value) DO204AG(value, 2*2.54) #end
#macro DIODE_THT_DO204AG_076mm(value) DO204AG(value, 3*2.54) #end
#macro DIODE_THT_DO204AH_025mm(value) DO204AH(value, 1*2.54) #end
#macro DIODE_THT_DO204AH_050mm(value) DO204AH(value, 2*2.54) #end
#macro DIODE_THT_DO204AH_076mm(value) DO204AH(value, 3*2.54) #end
#macro DIODE_THT_DO204AH_102mm(value) DO204AH(value, 4*2.54) #end
#macro DIODE_THT_DO204AL_025mm(value) DO204AL(value, 1*2.54) #end
#macro DIODE_THT_DO204AL_050mm(value) DO204AL(value, 2*2.54) #end
#macro DIODE_THT_DO204AL_076mm(value) DO204AL(value, 3*2.54) #end
#macro DIODE_THT_DO204AL_102mm(value) DO204AL(value, 4*2.54) #end
#macro DIODE_THT_DO204AP_050mm(value) DO204AP(value, 2*2.54) #end
#macro DIODE_THT_DO204AP_127mm(value) DO204AP(value, 5*2.54) #end
#macro DIODE_THT_DO204AR_152mm(value) DO204AR(value, 6*2.54) #end
#macro DIODE_THT_DO41G_102mm(value)   DO204(value,"DO204-AL",4*2.54,"Glass") #end


/*******************************************************************************
 * DO-201xx THT diode family
 * datasheets are rare here..
 * 27.04.2023, wk
 ******************************************************************************/
#macro DO201(value,Type,pitch,BodyColor)
  object {
     #if  (Type = "DO201")                        #local A = (25.40 + 25.40)/2; #local B = (8.50 + 9.53 )/2; #local C = (0.96 + 1.06)/2; #local D = (4.80 + 5.21)/2; #local E = 1.27; #end
     #if  (Type = "DO201-AD")                     #local A = (25.40 + 25.40)/2; #local B = (7.24 + 9.53 )/2; #local C = (1.22 + 1.32)/2; #local D = (4.83 + 5.60)/2; #local E = 1.27; #end

     axial_diode(value,A,B,C,D,E,pitch,BodyColor)
     }
#end

#macro DIODE_THT_DO201_152mm(value)     DO201(value, "DO201"   , 6*2.54, "Plastic") #end
#macro DIODE_THT_DO201_178mm(value)     DO201(value, "DO201"   , 7*2.54, "Plastic") #end
#macro DIODE_THT_DO201AD_050mm(value)   DO201(value, "DO201-AD", 2*2.54, "Plastic") #end // 1.5KE, 1.5KA
#macro DIODE_THT_DO201AD_127MM_H(value) DO201(value, "DO201-AD", 5*2.54, "Plastic") #end // 1.5KE, 1.5KA
#macro DIODE_THT_DO201AD_152mm(value)   DO201(value, "DO201-AD", 6*2.54, "Plastic") #end // 1.5KE, 1.5KA
#macro DIODE_THT_DO201AD_178mm(value)   DO201(value, "DO201-AD", 7*2.54, "Plastic") #end // 1.5KE, 1.5KA


/*******************************************************************************
 * R-6 THT diode package
 * 27.04.2023, wk
 ******************************************************************************/
#macro R6(value,Type,pitch,BodyColor)
  object {
     #if  (Type = "R-6")                          #local A = (25.40 + 25.40)/2; #local B = (8.60 + 9.10 )/2; #local C = (1.22 + 1.32)/2; #local D = (8.60 + 9.10)/2; #local E = 1.27; #end

     axial_diode(value,A,B,C,D,E,pitch,BodyColor)
     }
#end

#macro DIODE_THT_R6_152mm(value) R6(value, "R-6", 6*2.54, "Plastic") #end



/*******************************************************************************
*  no typos below please.
 * *****************************************************************************/
// begin assignment
//=DIODE_THT_DO204AA_025mm(:Diode DO204-AA
//diode:DO07=DIODE_THT_DO204AA_102mm(:Diode DO204-AA
//=DIODE_THT_DO204AB_025mm(:Diode DO204-AB
//=DIODE_THT_DO204AB_102mm(:Diode DO204-AB
//=DIODE_THT_DO204AC_025mm(:Diode DO204-AC
//diode:C1702-05=DIODE_THT_DO204AC_050mm(:Diode DO204-AC
//diode:P1-10=DIODE_THT_DO204AC_102mm(:Diode DO204-AC
//diode:F126Z10A=DIODE_THT_DO204AC_102mm(:Diode DO204-AC
//diode:F126Z10=DIODE_THT_DO204AC_102mm(:Diode DO204-AC 
//diode:F126-10=DIODE_THT_DO204AC_102mm(:Diode DO204-AC
//diode:DO15-12=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:P1Z12=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:ZDIO12.5=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:D-12.5=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:F126Z12A=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:F126Z12=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:CB417-12=DIODE_THT_DO204AC_127mm(:Diode DO204-AC
//diode:C1702-15=DIODE_THT_DO204AC_152mm(:Diode DO204-AC
//diode:CB417-15=DIODE_THT_DO204AC_152mm(:Diode DO204-AC
//diode:RAD2,5=DIODE_THT_DO204AD_025mm(:Diode DO204-AD
//diode:RAD2,5L=DIODE_THT_DO204AD_025mm(:Diode DO204-AD
//=DIODE_THT_DO204AD_050mm(:Diode DO204-AD
//diode:D-2.5=DIODE_THT_DO204AG_025mm(:Diode DO204-AG
//diode:ZDIO-2.5=DIODE_THT_DO204AG_025mm(:Diode DO204-AG
//diode:DO34-5=DIODE_THT_DO204AG_050mm(:Diode DO204-AG
//diode:ZDIO-5=DIODE_THT_DO204AG_050mm(:Diode DO204-AG
//diode:D-5=DIODE_THT_DO204AG_050mm(:Diode DO204-AG
//diode:DO34-7=DIODE_THT_DO204AG_076mm(:Diode DO204-AG
//diode:DO34Z7=DIODE_THT_DO204AG_076mm(:Diode DO204-AG
//diode:ZDIO-7.5=DIODE_THT_DO204AG_076mm(:Diode DO204-AG
//diode:D-7.5=DIODE_THT_DO204AG_076mm(:Diode DO204-AG
//=DIODE_THT_DO204AH_025mm(:Diode DO204-AH
//diode:DO35-7=DIODE_THT_DO204AH_076mm(:Diode DO204-AH
//diode:DO35-7A=DIODE_THT_DO204AH_076mm(:Diode DO204-AH
//diode:DO35-7B=DIODE_THT_DO204AH_076mm(:Diode DO204-AH
//diode:DO35Z7=DIODE_THT_DO204AH_076mm(:Diode DO204-AH
//diode:GT32=DIODE_THT_DO204AH_076mm(:Diode DO204-AH
//diode:DO35-10=DIODE_THT_DO204AH_102mm(:Diode DO204-AH
//diode:DO35Z10=DIODE_THT_DO204AH_102mm(:Diode DO204-AH
//diode:ZDIO-10=DIODE_THT_DO204AH_102mm(:Diode DO204-AH
//diode:D-10=DIODE_THT_DO204AH_102mm(:Diode DO204-AH
//=DIODE_THT_DO204AL_025mm(:Diode DO204-AL
//diode:RAD5G=DIODE_THT_DO204AL_050mm(:Diode DO204-AL
//diode:DO41-7.6=DIODE_THT_DO204AL_076mm(:Diode DO204-AL
//diode:DO41-7=DIODE_THT_DO204AL_076mm(:Diode DO204-AL
//diode:DO41-10=DIODE_THT_DO204AL_102mm(:Diode DO204-AL
//diode:DO41Z10=DIODE_THT_DO41G_102mm(:Diode DO204-AL glass
//=DIODE_THT_DO204AP_050mm(:Diode DO204-AP
//=DIODE_THT_DO204AP_127mm(:Diode DO204-AP
//diode:DO201-15=DIODE_THT_DO201_152mm(:Diode DO201
//diode:DO201T15=DIODE_THT_DO201_152mm(:Diode DO201
//diode:C2673=DIODE_THT_DO201_152mm(:Diode DO201
//diode:C4111-15=DIODE_THT_DO201_152mm(:Diode DO201
//diode:P2-15=DIODE_THT_DO201_152mm(:Diode DO201
//diode:P3-15=DIODE_THT_DO201_152mm(:Diode DO201
//diode:CB429-15=DIODE_THT_DO201AD_152mm(:Diode DO201
//diode:CB429-17=DIODE_THT_DO201AD_178mm(:Diode
//diode:P6-15=DIODE_THT_R6_152mm(:Diode R-6
//diode:P6T15=DIODE_THT_R6_152mm(:Diode R-6
//diode:AG=DIODE_THT_R6_152mm(:Diode R-6
//=DIODE_THT_DO201AD_050mm(:Suppressor Diode 1.5KE/1.5KA DO-201AD
//=DIODE_THT_DO201AD_127MM_H(:Suppressor Diode 1.5KE/1.5KA DO-201AD
// end assignment
