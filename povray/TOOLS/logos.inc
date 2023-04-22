/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Author: wk
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

// #if (S = "") // 20 leer
//    #declare LOGO_INDEX = " "
//#end

// #if (S = "") // 21 schwarzes breites Logo 'C' mit weißen Pfeilspitzen recht/links <C>
//    #declare LOGO_INDEX = "!"
//#end

// #if (S = "") // 22 leer
//    #declare LOGO_INDEX = "";
//#end

  #if (S = "XILINX") // 23
      #declare LOGO_INDEX = "#"
  #end

// #if (S = "") // 24 'W' mit Punkt drüber im Kreis
//    #declare LOGO_INDEX = "$"
//#end

// #if (S = "") // 25 eckiges 'S' im Kasten
//    #declare LOGO_INDEX = "%"
//#end

  #if (S = "C&K TTI") // 26
      #declare LOGO_INDEX = "&"
  #end

// #if (S = ) // 27 LEER
//    #declare LOGO_INDEX = "'"
//#end

  #if (S = "SCHRACK") // 28
      #declare LOGO_INDEX = "("
  #end

  #if (S = "OMRON") // 29
      #declare LOGO_INDEX = ")"
  #end

// #if (S = "") // 2A Kreis mit merkürdige 'E' und 'Seeanker'
//    #declare LOGO_INDEX = "*"
//#end

  #if (S = "CRYDOM") // 2B
      #declare LOGO_INDEX = "+"
  #end

  #if (S = "NAIS") // 2C NAiS LOGO e3d_special:2836
      #declare LOGO_INDEX = ","
  #end

  #if (S = "MAXIM") // 2D e3d_tools:1215
      #declare LOGO_INDEX = "-"
  #end

  #if (S = "SONG CHUAN") // 2E e3d_special:2895
      #declare LOGO_INDEX = "."
  #end

  #if (S = "FREESCALE") // 2F e3d_ic.inc: 217, e3d_trafo:498/499
      #declare LOGO_INDEX = "/" 
  #end

  #if (S = "VISHAY") // 30 e3d_resistor: 1647,1780,1859
      #declare LOGO_INDEX = "0"
  #end

  #if (S = "GENERAL SEMICONDUCTOR") // 31 e3d_diode.inc:1559, NOTE: General Semiconductor is VISHAY.
      #declare LOGO_INDEX = "1"
  #end

  #if (S = "ACTEL") // 32
      #declare LOGO_INDEX = "2"
  #end

  #if (S = "ANALOG DEVICES") // 33
      #declare LOGO_INDEX = "3"
  #end

  #if (S = "AGILENT") // 34
      #declare LOGO_INDEX = "4"
  #end

  #if (S = "ALTERA") // 35
      #declare LOGO_INDEX = "5"
  #end

  #if (S = "AMD") // 36 e3d_tools:1200
      #declare LOGO_INDEX = "6"
  #end

  #if (S = "BURR-BROWN") // 37
      #declare LOGO_INDEX = "7"
  #end

  #if (S = "MOTOROLA") // 38
      #declare LOGO_INDEX = "8"
  #end

  #if (S = "LAMBDA") // 39
      #declare LOGO_INDEX = "9"
  #end

// #if (S = "") // 3A ???
//    #declare LOGO_INDEX = ":"
//#end

  #if (S = "TDK") // 3B
      #declare LOGO_INDEX = ";"
  #end

  #if (S = "BOURNS") // 3C
      #declare LOGO_INDEX = "<"
  #end

// #if (S = "") // 3D ???
//    #declare LOGO_INDEX = "="
//#end

  #if (S = "SIEMENS") // 3E e3d_resistor: 1354
      #declare LOGO_INDEX = ">"
  #end

// #if (S = "") // 3F ???
//    #declare LOGO_INDEX = "?"
//#end

  #if (S = "DALLAS") // 40
      #declare LOGO_INDEX = "@"
  #end

  #if (S = "UL-SIGN") // 41 e3d_special: 2574, 2623, 2898, e3d_resistor: 1355, e3d_trafo:496
      #declare LOGO_INDEX = "A"
  #end

  #if (S = "VDE-SIGN") // 42 e3d_special: 2576, 2625, e3d_trafo:357, e3d_resistor: 1355
      #declare LOGO_INDEX = "B"
  #end

  #if (S = "TRADEMARK-SIGN") // 43
      #declare LOGO_INDEX = "C"
  #end

  #if (S = "COPYRIGHT-SIGN") // 44
      #declare LOGO_INDEX = "D"
  #end

  #if (S = "CE-SIGN") // 45 e3d_special: 2575, e3d_trafo:358
      #declare LOGO_INDEX = "E"
  #end

  #if (S = "EX-SIGN") // 46
      #declare LOGO_INDEX = "F" 
  #end

  #if (S = "CSA Group") // 47 e3d_special:2624, 2899 
      #declare LOGO_INDEX = "G" 
  #end

  #if (S = "MYRRA") // 48 e3d_trafo:359, 494 
      #declare LOGO_INDEX = "H"
  #end

  #if (S = "UL-SIGN") // 49 e3d_special: 2573, e3d_trafo:356, e3d_trafo:497
      #declare LOGO_INDEX = "I"
  #end

  #if (S = "UL-SIGN1") // 4A
      #declare LOGO_INDEX = "J"
  #end

  #if (S = "UL-SIGN2") // 4B
      #declare LOGO_INDEX = "K"
  #end

  #if (S = "UL-SIGN3") // 4C
      #declare LOGO_INDEX = "L"
  #end

  #if (S = "UL-SIGN4") // 4D
      #declare LOGO_INDEX = "M"
  #end

  #if (S = "D-SIGN") // 4E e3d_trafo:355
      #declare LOGO_INDEX = "N"
  #end

  #if (S = "FI-SIGN") // 4F e3d_trafo:349
      #declare LOGO_INDEX = "O" 
  #end

  #if (S = "S-SIGN") // 50 e3d_trafo:351
      #declare LOGO_INDEX = "P"
  #end

  #if (S = "N-SIGN") // 51 e3d_trafo:353
      #declare LOGO_INDEX = "Q"
  #end

// #if (S = "") // 52 ??? rundes logo
//    #declare LOGO_INDEX = "R"
//#end

  #if (S = "EMC-SIGN") // 53
      #declare LOGO_INDEX = "S"
  #end

  #if (S = "PSE-SIGN") // 54
      #declare LOGO_INDEX = "T"
  #end

// #if (S = "") // 55 ???
//    #declare LOGO_INDEX = "U"
//#end

// #if (S = "") // 56 ???
//    #declare LOGO_INDEX = "V"
//#end

  #if (S = "ÖVE-SIGN") // 57
      #declare LOGO_INDEX = "W"
  #end

// #if (S = "") // 58 ???
//    #declare LOGO_INDEX = "X"
//#end

// #if (S = "") // 59 ???
//    #declare LOGO_INDEX = "Y"
//#end

  #if (S = "PS CLASS-2, NO-SHORT") // 5A e3d_trafo:495 Nicht kurzschlussfest mit Sicherheitsisolierung
      #declare LOGO_INDEX = "Z"
  #end

  #if (S = "ENEC-SIGN") // 5B
      #declare LOGO_INDEX = "["
  #end

  #if (S = "M-SIGN") // 5C VDE0712/EN61347 Montage in/an Einrichtungsgegenständen, z.B. Möbel-Montage
      #declare LOGO_INDEX = "\\" // careful here - backslash is a special char.
  #end

  #if (S = "PS CLASS-2") // 5D
      #declare LOGO_INDEX = "]"
  #end

// #if (S = "") // 5E ???
//    #declare LOGO_INDEX = "^"
//#end

// #if (S = ) // 5F ???
//    #declare LOGO_INDEX = "_"
//#end

// #if (S = "") // 60 LEER
//    #declare LOGO_INDEX = "`"
//#end

  #if (S = "ATMEL") // 61 e3d_ic.inc: 310, e3d_qfp:205, e3d_tools:1205 
      #declare LOGO_INDEX = "a" 
  #end

  #if (S = "BI TECHNOLOGIES") // 62 e3d_resistor: 375
      #declare LOGO_INDEX = "b"
  #end

// #if (S = "") // 63 ??? wie '!', aber invers
//    #declare LOGO_INDEX = "c"
//#end

  #if (S = "DATEL") // 64
      #declare LOGO_INDEX = "d"
  #end

  #if (S = "C&D") // 65
      #declare LOGO_INDEX = "e"
  #end

  #if (S = "FTDI") // 66 e3d_ic.inc: 319, e3d_qfp:198, e3d_tools:1210
      #declare LOGO_INDEX = "f"
  #end

// #if (S = "") // 67 ???
//    #declare LOGO_INDEX = "g" 
//#end

// #if (S = "") // 68 ???
//    #declare LOGO_INDEX = "h"
//#end

// #if (S = "") // 69 ???
//    #declare LOGO_INDEX = "i"
//#end

  #if (S = "INTERNATIONAL RECTIFIER") // 6A e3d_ic.inc: 99
      #declare LOGO_INDEX = "j"
  #end

  #if (S = "LINEAR TECHNOLOGY") // 6B
      #declare LOGO_INDEX = "k"
  #end

  #if (S = "LAMBDA") // 6C
      #declare LOGO_INDEX = "l"
  #end

  #if (S = "MICROCHIP") // 6D e3d_ic.inc: 293, e3d_qfp:211
      #declare LOGO_INDEX = "m"
  #end

  #if (S = "NATIONAL SEMICONDUCTOR") // 6E
      #declare LOGO_INDEX = "n"
  #end

// #if (S = "") // 6F
//    #declare LOGO_INDEX = "o"
//#end

  #if (S = "PHILIPS") // 70 e3d_ic.inc: 284
      #declare LOGO_INDEX = "p"
  #end

  #if (S = "EPCOS") // 71
      #declare LOGO_INDEX = "q"
  #end

  #if (S = "SCHAFFNER") // 72
      #declare LOGO_INDEX = "r"
  #end

  #if (S = "STMICROELECTRONICS") // 73 e3d_ic.inc: 301
      #declare LOGO_INDEX = "s" 
  #end

  #if (S = "TEXAS INSTRUMENTS") // 74 e3d_ic.inc: 328
      #declare LOGO_INDEX = "t"
  #end

  #if (S = "TOSHIBA") // 75
      #declare LOGO_INDEX = "u"
  #end

  #if (S = "VICOR") // 76
      #declare LOGO_INDEX = "v"
  #end

  #if (S = "TDK") // 77
      #declare LOGO_INDEX = "w"
  #end

// #if (S = "") // 78 ???
//    #declare LOGO_INDEX = "x"
//#end

  #if (S = "ZETTLER") // 79
      #declare LOGO_INDEX = "y"
  #end

// #if (S = ) // 7A ???
//    #declare LOGO_INDEX = "z"
//#end

  #if (S = "VISHAY") // 7B
      #declare LOGO_INDEX = "{"
  #end

  #if (S = "FINDER") // 7C
      #declare LOGO_INDEX = "|"
  #end

// #if (S = "") // 7D ???
//    #declare LOGO_INDEX = "}"
//#end

// #if (S = "") // 7E LEER
//    #declare LOGO_INDEX = "~"
//#end

  // end: LogoIndex()
#end



/*******************************************************************************
 * draws a logo centered at current position into a window
 * of size WIDTH x HEIGHT. NOTE: center of drawn image, not fonts.
 * 20220415, wk
 ******************************************************************************/
#macro Logo(NAME,HEIGHT,WIDTH)
  LogoIndex(NAME) // sets LOGO_INDEX

  #local Obj = text{ttf global_fontfile_eagle3d LOGO_INDEX 1,0 texture{col_bright_marking}}
  #local MinE = min_extent ( Obj );
  #local MaxE = max_extent ( Obj );
  #local XLen = (MaxE.x - MinE.x);
  #local YLen = (MaxE.y - MinE.y);
  #local XScale = WIDTH  / XLen;
  #local YScale = HEIGHT / YLen;
  #local Scale = min(XScale,YScale);

 union {
    text {
       ttf global_fontfile_eagle3d LOGO_INDEX 1,0
       scale <Scale,Scale,1>
       translate <-0.5*XLen*Scale,-0.5*YLen*Scale,0>
       texture {
          col_bright_marking
          }
       }
    }
#end
