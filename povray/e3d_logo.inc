/*
  several logos at:
    * http://www.ecadata.de/herst/showlogo.php?F_SPRACHE=1

  " " , ""                        ,20 // leer
  "!" , ""                        ,21 // schwarzes breites Logo 'C' mit weißen Pfeilspitzen recht/links <C>
  """", ""                        ,22 // leer
  "#" , "XILINX"                  ,23 //  
  "$" , ""                        ,24 // 'W' mit Punkt drüber im Kreis 
  "%" , ""                        ,25 //  eckiges 'S' im Kasten
  "&" , "C&K TTI"                 ,26 //  
  "'" , ""                        ,27 // LEER 
  "(" , "SCHRACK"                 ,28 // 
  ")" , "OMRON"                   ,29 // 
  "*" , ""                        ,2A // Kreis mit merkürdige 'E' und 'Seeanker' 
  "+" , "CRYDOM"                  ,2B //  
  "," , "NAiS"                    ,2C // text {ttf global_fontfile_eagle3d ","  0.1,  0 } // NAiS LOGO, G2RL relais, e3d_special:2836 
  "-" , "MAXIM"                   ,2D // text {ttf global_fontfile_eagle3d "-"  0.01, 0 } // MAXIM                 , e3d_tools:1215 
  "." , "SONG CHUAN"              ,2E // text {ttf global_fontfile_eagle3d "."  0.05, 0 } // Global Components rela, e3d_special:2895
  "/" , "Freescale"               ,2F // text {ttf global_fontfile_eagle3d "/"  0.2 , 0 } // FREESCALE             , e3d_ic.inc: 217, e3d_trafo:498/499 
  "0" , "Vishay"                  ,30 // text {ttf global_fontfile_eagle3d "0"  0.1 , 0 } // Vishay                , e3d_resistor: 1647,1780,1859
  "1" , "General Semiconductor"   ,31 // text {ttf global_fontfile_eagle3d "1" -0.05, 0 } // General Semiconductor , e3d_diode.inc:1559
  "2" , "Actel"                   ,32 // LEER
  "3" , "Analog Devices"          ,33 // LEER
  "4" , "Agilent"                 ,34 // LEER
  "5" , "ALTERA"                  ,35 // LEER
  "6" , "AMD"                     ,36 // text {ttf global_fontfile_eagle3d "6"  0.01, 0 } // AMD                   , e3d_tools:1200
  "7" , "Burr-Brown"              ,37 // LEER
  "8" , "Motorola"                ,38 // LEER
  "9" , "Lambda"                  ,39 // LEER
  ":" , ""                        ,3A // ???
  ";" , "TDK"                     ,3B // 
  "<" , ""                        ,3C // text {ttf global_fontfile_eagle3d "<" 0.05, 0  } // Bourns ?              , e3d_trafo:582
  "=" , ""                        ,3D // ???
  ">" , "SIEMENS"                 ,3E // text {ttf global_fontfile_eagle3d ">"  1   , 0 } // EPCOS                , e3d_resistor: 1354
  "?" , ""                        ,3F // ???
  "@" , "Dallas"                  ,40 // 
  "A" , "UL-SIGN"                 ,41 // text {ttf global_fontfile_eagle3d "A"  0.1, 0  } // UL marking            , e3d_special: 2574, 2623, 2898, e3d_resistor: 1355, e3d_trafo:496
  "B" , "VDE-SIGN"                ,42 // text {ttf global_fontfile_eagle3d "B"  0.1, 0  } // DVE marking           , e3d_special: 2576, 2625, e3d_trafo:357, e3d_resistor: 1355
  "C" , "TRADEMARK-SIGN"          ,43 //  
  "D" , "COPYRIGHT-SIGN"          ,44 //  
  "E" , "CE-SIGN"                 ,45 // text {ttf global_fontfile_eagle3d "E"  0.1, 0  } // CE marking            , e3d_special: 2575, e3d_trafo:358
  "F" , "EX-SIGN"                 ,46 //  
  "G" , "CSA Group"               ,47 // text {ttf global_fontfile_eagle3d "G"  0.05, 0 } //                       , e3d_special:2624, 2899 
  "H" , "myrra"                   ,48 // text {ttf global_fontfile_eagle3d "H"  0.05, 0 } // MYRRA LOGO            , e3d_trafo:359, 494
  "I" , "UL-SIGN"                 ,49 // text {ttf global_fontfile_eagle3d "I"  0.1, 0  } // canada UL marking     , e3d_special: 2573, e3d_trafo:356, e3d_trafo:497
  "J" , "UL-SIGN"                 ,4A //  
  "K" , "UL-SIGN"                 ,4B //  
  "L" , "UL-SIGN"                 ,4C // 
  "M" , "UL-SIGN"                 ,4D //
  "N" , "D-SIGN"                  ,4E // text {ttf global_fontfile_eagle3d "N" 0.05, 0  } // ?                     , e3d_trafo:355
  "O" , "FI-SIGN"                 ,4F // text {ttf global_fontfile_eagle3d "O" 0.05, 0  } // ?                     , e3d_trafo:349 
  "P" , "S-SIGN"                  ,50 // text {ttf global_fontfile_eagle3d "P" 0.05, 0  } // ?                     , e3d_trafo:351 
  "Q" , "N-SIGN"                  ,51 // text {ttf global_fontfile_eagle3d "Q" 0.05, 0  } // ?                     , e3d_trafo:353
  "R" , ""                        ,52 // ??? rundes logo 
  "S" , "EMC-SIGN"                ,53 // ???
  "T" , "PSE-SIGN"                ,54 // ???
  "U" , ""                        ,55 // ???
  "V" , ""                        ,56 // ???
  "W" , "ÖVE-SIGN"                ,57 //  
  "X" , ""                        ,58 // ??? 
  "Y" , ""                        ,59 // ??? 
  "Z" , "PS Class-2, NO-SHORT"    ,5A // text {ttf global_fontfile_eagle3d "Z" 0.05, 0  } // , e3d_trafo:495 Nicht kurzschlussfest mit Sicherheitsisolierung
  "[" , "ENEC-SIGN"               ,5B //  
  "\" , "M-SIGN"                  ,5C // VDE0712/EN61347 Montage in/an Einrichtungsgegenständen, z.B. Möbel-Montage
  "]" , "PS Class-2"              ,5D //  
  "^" , ""                        ,5E // ???
  "_" , ""                        ,5F // ???
  "`" , ""                        ,60 // LEER
  "a" , "ATMEL"                   ,61 // text {ttf global_fontfile_eagle3d "a"  0.2 , 0 }  // ATMEL                , e3d_ic.inc: 310, e3d_qfp:205, e3d_tools:1205 
  "b" , "BI Technologies"         ,62 // text {ttf global_fontfile_eagle3d "b"  0.5 , 0 }  // BI Technologies      , e3d_resistor: 375
  "c" , ""                        ,63 // ??? wie '!', aber invers 
  "d" , "DATEL"                   ,64 // 
  "e" , "C&D"                     ,65 //
  "f" , "FTDI"                    ,66 // text {ttf global_fontfile_eagle3d "f"  0.2 , 0 }  // FTDI                 , e3d_ic.inc: 319, e3d_qfp:198, e3d_tools:1210 
  "g" , ""                        ,67 // ??? 
  "h" , ""                        ,68 // ??? 
  "i" , ""                        ,69 // ??? 
  "j" , "International Rectifier" ,6A // text {ttf global_fontfile_eagle3d "j"  0.02, 0 }  // Int. Rectifier       , e3d_ic.inc: 99 
  "k" , "Linear Technology"       ,6B // ??? 
  "l" , "Lambda"                  ,6C // ??? 
  "m" , "Microchip"               ,6D // text {ttf global_fontfile_eagle3d "m"  0.2 , 0 }  // MICROCHIP            , e3d_ic.inc: 293, e3d_qfp:211 
  "n" , "National Semiconductor"  ,6E //  
  "o" , ""                        ,6F //  
  "p" , "Philips"                 ,70 // text {ttf global_fontfile_eagle3d "p"  0.2 , 0 }  // PHILIPS              , e3d_ic.inc: 284 
  "q" , "EPCOS"                   ,71 //  
  "r" , "SCHAFFNER"               ,72 //  
  "s" , "STMicroelectronics"      ,73 // text {ttf global_fontfile_eagle3d "s"  0.2 , 0 }  // STMicroelectronics   , e3d_ic.inc: 301 
  "t" , "Texas Instruments"       ,74 // text {ttf global_fontfile_eagle3d "t"  0.2 , 0 }  // TEXAS                , e3d_ic.inc: 328 
  "u" , "TOSHIBA"                 ,75 //  
  "v" , "VICOR"                   ,76 //  
  "w" , "TDK"                     ,77 //  
  "x" , ""                        ,78 // ??? 
  "y" , "ZETTLER"                 ,79 // 
  "z" , ""                        ,7A // ??? 
  "{" , "VISHAY"                  ,7B //  
  "|" , "finder"                  ,7C //  
  "}" , ""                        ,7D // ??? 
  "~" , ""                        ,7E // LEER 
  "␡" , ""                        ,7F // LEER 














#declare global_fontfile_eagle3d        = "eagle3d.ttf"                                              e3d_tools:103

//The Eagle3D font has to exist                                                                      e3d_tools:110
#if(file_exists(global_fontfile_eagle3d) = 0)                                                        e3d_tools:111
    #error "Eagle3D font not found. Please specify the path to eagle3d.ttf in the ini-file"          e3d_tools:112
#end                                                                                                 e3d_tools:113


#macro TOOLS_LOGO_AND_CAPTION(caption, logo, min_p, max_p)                                           e3d_tools:1194
#end                                                                                                 e3d_tools:1287

*/