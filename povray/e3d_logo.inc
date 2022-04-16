
/*
#declare global_fontfile_eagle3d        = "eagle3d.ttf"                                              e3d_tools:103

//The Eagle3D font has to exist                                                                      e3d_tools:110
#if(file_exists(global_fontfile_eagle3d) = 0) = 0) = 0)                                                        e3d_tools:111
    #error "Eagle3D font not found. Please specify the path to eagle3d.ttf in the ini-file"          e3d_tools:112
#end                                                                                                 e3d_tools:113
#macro TOOLS_LOGO_AND_CAPTION(caption, logo, min_p, max_p) = 0)                                           e3d_tools:1194
#end                                                                                                 e3d_tools:1287
*/


/*******************************************************************************
 * several logos at:
 *  - http://www.ecadata.de/herst/showlogo.php?F_SPRACHE=1
 ******************************************************************************/





/*******************************************************************************
 * translation from Logo Name to the character in e3d logo font.
 * 20220415, wk
 ******************************************************************************/

#macro LogoIndex(what)
  #declare LOGO_INDEX = what; // initialize for characters.
  #local S = strupr(what);

//#if (strcmp(S, "") = 0) // 20 leer
//    #declare LOGO_INDEX = " "
//#end

//#if (strcmp(S, "") = 0) // 21 schwarzes breites Logo 'C' mit weißen Pfeilspitzen recht/links <C>
//    #declare LOGO_INDEX = "!"
//#end

//#if (strcmp(S, "") = 0) // 22 leer
//    #declare LOGO_INDEX = "";
//#end

  #if (strcmp(S, "XILINX") = 0) // 23  
      #declare LOGO_INDEX = "#"
  #end

//#if (strcmp(S, "") = 0) // 24 'W' mit Punkt drüber im Kreis
//    #declare LOGO_INDEX = "$"
//#end

//#if (strcmp(S, "") = 0) // 25 eckiges 'S' im Kasten
//    #declare LOGO_INDEX = "%"
//#end

  #if (strcmp(S, "C&K TTI") = 0) // 26
      #declare LOGO_INDEX = "&"  
  #end

//#if (strcmp(S, ) = 0) // 27 LEER
//    #declare LOGO_INDEX = "'"
//#end

  #if (strcmp(S, "SCHRACK") = 0) // 28
      #declare LOGO_INDEX = "("
  #end

  #if (strcmp(S, "OMRON") = 0) // 29
      #declare LOGO_INDEX = ")"
  #end

//#if (strcmp(S, "") = 0) // 2A Kreis mit merkürdige 'E' und 'Seeanker'
//    #declare LOGO_INDEX = "*"
//#end

  #if (strcmp(S, "CRYDOM") = 0) // 2B
      #declare LOGO_INDEX = "+"
  #end

  #if (strcmp(S, "NAIS") = 0) // 2C NAiS LOGO e3d_special:2836
      #declare LOGO_INDEX = ","
  #end

  #if (strcmp(S, "MAXIM") = 0) // 2D e3d_tools:1215
      #declare LOGO_INDEX = "-"
  #end

  #if (strcmp(S, "SONG CHUAN") = 0) // 2E e3d_special:2895
      #declare LOGO_INDEX = "."
  #end

  #if (strcmp(S, "FREESCALE") = 0) // 2F e3d_ic.inc: 217, e3d_trafo:498/499
      #declare LOGO_INDEX = "/" 
  #end

  #if (strcmp(S, "VISHAY") = 0) // 30 e3d_resistor: 1647,1780,1859
      #declare LOGO_INDEX = "0"
  #end

  #if (strcmp(S, "GENERAL SEMICONDUCTOR") = 0) // 31 e3d_diode.inc:1559, NOTE: General Semiconductor is VISHAY.
      #declare LOGO_INDEX = "1"
  #end

  #if (strcmp(S, "ACTEL") = 0) // 32
      #declare LOGO_INDEX = "2"
  #end

  #if (strcmp(S, "ANALOG DEVICES") = 0) // 33
      #declare LOGO_INDEX = "3"
  #end

  #if (strcmp(S, "AGILENT") = 0) // 34
      #declare LOGO_INDEX = "4"
  #end

  #if (strcmp(S, "ALTERA") = 0) // 35
      #declare LOGO_INDEX = "5"
  #end

  #if (strcmp(S, "AMD") = 0) // 36 e3d_tools:1200
      #declare LOGO_INDEX = "6"
  #end

  #if (strcmp(S, "BURR-BROWN") = 0) // 37
      #declare LOGO_INDEX = "7"
  #end

  #if (strcmp(S, "MOTOROLA") = 0) // 38
      #declare LOGO_INDEX = "8"
  #end

  #if (strcmp(S, "LAMBDA") = 0) // 39
      #declare LOGO_INDEX = "9"
  #end

//#if (strcmp(S, "") = 0) // 3A ???
//    #declare LOGO_INDEX = ":"
//#end

  #if (strcmp(S, "TDK") = 0) // 3B
      #declare LOGO_INDEX = ";"
  #end

//#if (strcmp(S, "") = 0) // 3C Bourns e3d_trafo:582
//    #declare LOGO_INDEX = "<"
//#end

//#if (strcmp(S, "") = 0) // 3D ???
//    #declare LOGO_INDEX = "="
//#end

  #if (strcmp(S, "SIEMENS") = 0) // 3E e3d_resistor: 1354
      #declare LOGO_INDEX = ">"
  #end

//#if (strcmp(S, "") = 0) // 3F ???
//    #declare LOGO_INDEX = "?"
//#end

  #if (strcmp(S, "DALLAS") = 0) // 40
      #declare LOGO_INDEX = "@"
  #end

  #if (strcmp(S, "UL-SIGN") = 0) // 41 e3d_special: 2574, 2623, 2898, e3d_resistor: 1355, e3d_trafo:496
      #declare LOGO_INDEX = "A"
  #end

  #if (strcmp(S, "VDE-SIGN") = 0) // 42 e3d_special: 2576, 2625, e3d_trafo:357, e3d_resistor: 1355
      #declare LOGO_INDEX = "B"
  #end

  #if (strcmp(S, "TRADEMARK-SIGN") = 0) // 43
      #declare LOGO_INDEX = "C"
  #end

  #if (strcmp(S, "COPYRIGHT-SIGN") = 0) // 44
      #declare LOGO_INDEX = "D"
  #end

  #if (strcmp(S, "CE-SIGN") = 0) // 45 e3d_special: 2575, e3d_trafo:358
      #declare LOGO_INDEX = "E"
  #end

  #if (strcmp(S, "EX-SIGN") = 0) // 46
      #declare LOGO_INDEX = "F" 
  #end

  #if (strcmp(S, "CSA Group") = 0) // 47 e3d_special:2624, 2899 
      #declare LOGO_INDEX = "G" 
  #end

  #if (strcmp(S, "MYRRA") = 0) // 48 e3d_trafo:359, 494 
      #declare LOGO_INDEX = "H"
  #end

  #if (strcmp(S, "UL-SIGN") = 0) // 49 e3d_special: 2573, e3d_trafo:356, e3d_trafo:497
      #declare LOGO_INDEX = "I"
  #end

  #if (strcmp(S, "UL-SIGN1") = 0) // 4A
      #declare LOGO_INDEX = "J"
  #end

  #if (strcmp(S, "UL-SIGN2") = 0) // 4B
      #declare LOGO_INDEX = "K"
  #end

  #if (strcmp(S, "UL-SIGN3") = 0) // 4C
      #declare LOGO_INDEX = "L"
  #end

  #if (strcmp(S, "UL-SIGN4") = 0) // 4D
      #declare LOGO_INDEX = "M"
  #end

  #if (strcmp(S, "D-SIGN") = 0) // 4E e3d_trafo:355
      #declare LOGO_INDEX = "N"
  #end

  #if (strcmp(S, "FI-SIGN") = 0) // 4F e3d_trafo:349
      #declare LOGO_INDEX = "O" 
  #end

  #if (strcmp(S, "S-SIGN") = 0) // 50 e3d_trafo:351
      #declare LOGO_INDEX = "P"
  #end

  #if (strcmp(S, "N-SIGN") = 0) // 51 e3d_trafo:353
      #declare LOGO_INDEX = "Q"
  #end

//#if (strcmp(S, "") = 0) // 52 ??? rundes logo
//    #declare LOGO_INDEX = "R"
//#end

  #if (strcmp(S, "EMC-SIGN") = 0) // 53
      #declare LOGO_INDEX = "S"
  #end

  #if (strcmp(S, "PSE-SIGN") = 0) // 54
      #declare LOGO_INDEX = "T"
  #end

//#if (strcmp(S, "") = 0) // 55 ???
//    #declare LOGO_INDEX = "U"
//#end

//#if (strcmp(S, "") = 0) // 56 ???
//    #declare LOGO_INDEX = "V"
//#end

  #if (strcmp(S, "ÖVE-SIGN") = 0) // 57
      #declare LOGO_INDEX = "W"
  #end

//#if (strcmp(S, "") = 0) // 58 ???
//    #declare LOGO_INDEX = "X"
//#end

//#if (strcmp(S, "") = 0) // 59 ???
//    #declare LOGO_INDEX = "Y"
//#end

  #if (strcmp(S, "PS CLASS-2, NO-SHORT") = 0) // 5A e3d_trafo:495 Nicht kurzschlussfest mit Sicherheitsisolierung
      #declare LOGO_INDEX = "Z"
  #end

  #if (strcmp(S, "ENEC-SIGN") = 0) // 5B
      #declare LOGO_INDEX = "["
  #end

  #if (strcmp(S, "M-SIGN") = 0) // 5C VDE0712/EN61347 Montage in/an Einrichtungsgegenständen, z.B. Möbel-Montage
      #declare LOGO_INDEX = "\\" // careful here - backslash is a special char.
  #end

  #if (strcmp(S, "PS CLASS-2") = 0) // 5D
      #declare LOGO_INDEX = "]"
  #end

//#if (strcmp(S, "") = 0) // 5E ???
//    #declare LOGO_INDEX = "^"
//#end

//#if (strcmp(S, ) = 0) // 5F ???
//    #declare LOGO_INDEX = "_"
//#end

//#if (strcmp(S, "") = 0) // 60 LEER
//    #declare LOGO_INDEX = "`"
//#end

  #if (strcmp(S, "ATMEL") = 0) // 61 e3d_ic.inc: 310, e3d_qfp:205, e3d_tools:1205 
      #declare LOGO_INDEX = "a" 
  #end

  #if (strcmp(S, "BI TECHNOLOGIES") = 0) // 62 e3d_resistor: 375
      #declare LOGO_INDEX = "b"
  #end

//#if (strcmp(S, "") = 0) // 63 ??? wie '!', aber invers
//    #declare LOGO_INDEX = "c"
//#end

  #if (strcmp(S, "DATEL") = 0) // 64
      #declare LOGO_INDEX = "d"
  #end

  #if (strcmp(S, "C&D") = 0) // 65
      #declare LOGO_INDEX = "e"
  #end

  #if (strcmp(S, "FTDI") = 0) // 66 e3d_ic.inc: 319, e3d_qfp:198, e3d_tools:1210
      #declare LOGO_INDEX = "f"
  #end

//#if (strcmp(S, "") = 0) // 67 ???
//    #declare LOGO_INDEX = "g" 
//#end

//#if (strcmp(S, "") = 0) // 68 ???
//    #declare LOGO_INDEX = "h"
//#end

//#if (strcmp(S, "") = 0) // 69 ???
//    #declare LOGO_INDEX = "i"
//#end

  #if (strcmp(S, "INTERNATIONAL RECTIFIER") = 0) // 6A e3d_ic.inc: 99
      #declare LOGO_INDEX = "j"
  #end

  #if (strcmp(S, "LINEAR TECHNOLOGY") = 0) // 6B
      #declare LOGO_INDEX = "k"
  #end

  #if (strcmp(S, "LAMBDA") = 0) // 6C
      #declare LOGO_INDEX = "l"
  #end

  #if (strcmp(S, "MICROCHIP") = 0) // 6D e3d_ic.inc: 293, e3d_qfp:211
      #declare LOGO_INDEX = "m"
  #end

  #if (strcmp(S, "NATIONAL SEMICONDUCTOR") = 0) // 6E
      #declare LOGO_INDEX = "n"
  #end

//#if (strcmp(S, "") = 0) // 6F
//    #declare LOGO_INDEX = "o"
//#end

  #if (strcmp(S, "PHILIPS") = 0) // 70 e3d_ic.inc: 284  
      #declare LOGO_INDEX = "p"
  #end

  #if (strcmp(S, "EPCOS") = 0) // 71
      #declare LOGO_INDEX = "q"
  #end

  #if (strcmp(S, "SCHAFFNER") = 0) // 72
      #declare LOGO_INDEX = "r"
  #end

  #if (strcmp(S, "ST MICRO") = 0) // 73 e3d_ic.inc: 301 
      #declare LOGO_INDEX = "s" 
  #end

  #if (strcmp(S, "TEXAS INSTRUMENTS") = 0) // 74 e3d_ic.inc: 328 
      #declare LOGO_INDEX = "t"
  #end

  #if (strcmp(S, "TOSHIBA") = 0) // 75
      #declare LOGO_INDEX = "u"
  #end

  #if (strcmp(S, "VICOR") = 0) // 76
      #declare LOGO_INDEX = "v"
  #end

  #if (strcmp(S, "TDK") = 0) // 77
      #declare LOGO_INDEX = "w"
  #end

//#if (strcmp(S, "") = 0) // 78 ???
//    #declare LOGO_INDEX = "x"
//#end

  #if (strcmp(S, "ZETTLER") = 0) // 79
      #declare LOGO_INDEX = "y"
  #end

//#if (strcmp(S, ) = 0) // 7A ???
//    #declare LOGO_INDEX = "z"
//#end

  #if (strcmp(S, "VISHAY") = 0) // 7B
      #declare LOGO_INDEX = "{"
  #end

  #if (strcmp(S, "FINDER") = 0) // 7C
      #declare LOGO_INDEX = "|"
  #end

//#if (strcmp(S, "") = 0) // 7D ???
//    #declare LOGO_INDEX = "}"
//#end

//#if (strcmp(S, "") = 0) // 7E LEER
//    #declare LOGO_INDEX = "~"
//#end

  // end: LogoIndex()
#end


#macro Logo(NAME)   
  LogoIndex(NAME)

  // hint: LOGO_INDEX is set by logoIndex()
  text{ttf global_fontfile_eagle3d LOGO_INDEX 1,0 texture{e3d_tex_ic_marking_bright}}

  // end: Logo()
#end


