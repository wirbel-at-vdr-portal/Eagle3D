

#ifdef(col_preset)
  #switch(col_preset) // Verschiedene Farb-Presets
     #case(1) // Standard PCB Loetstop
        // PCB material
        #declare col_brd = texture{pigment{DarkGreen}}    // Farbe der Platine
        // Wires
        #declare col_wrs = texture{pigment{ForestGreen}}  // Farbe der Leiterbahnen
        // Pads and SMDs
        #declare col_pds = texture{T_Silver_5A}           // Farbe der Pad's und SMD's
        // Simulated holes
        #declare col_hls = texture{pigment{Black}}        // Farbe der Pseudobohrungen
        // Background color
        #declare col_bgr = White;                         // Hintergrundfarbe wenn keine Umgebung aktiviert
        // Silkscreen
        #declare col_slk = texture{pigment{White}}        // Farbe des Bestueckungsdrucks
        // Vias
        #declare col_thl = texture{T_Silver_5A}           // Farbe der Durchkontaktierungen
        // Polygons
        #declare col_pol = col_wrs                        // Farbe der Polygone
        #break

     #case(2) // PCB Loetstop Maske
        // PCB material
        #declare col_brd = texture{pigment{rgb<0.117647,0.243137,0.015686>} finish{ambient (0.1 * global_ambient_mul)} }
        // Wires
        #declare col_wrs = texture{pigment{rgb<0.368627,0.352941,0.054902>} finish{ambient (0.1 * global_ambient_mul)} }
        // Pads and SMDs
        #declare col_pds = texture{pigment{Gray70} finish{F_MetalB ambient (0.3 * global_ambient_mul)} }
        // Simulated holes
        #declare col_hls = texture{pigment{Black} finish{ambient (0.1 * global_ambient_mul)} }
        // Background color
        #declare col_bgr = White;
        // Silkscreen
        #declare col_slk = texture{pigment{White} finish{ambient (0.1 * global_ambient_mul)} }
        // Vias
        #declare col_thl = texture{pigment{Gray70} finish{F_MetalB ambient (0.3 * global_ambient_mul)} }
        // Polygons
        #declare col_pol = col_wrs
        #break

     #case(3) // PCB Loetstop Maske 2
        // PCB material
        #declare col_brd = texture{pigment{rgb<0.117647,0.243137,0.015686>} normal{bumps 0.2 scale 0.00015} finish{ambient 0.2 diffuse 0.5 phong 0.1} }
        // Wires
        #declare col_wrs = texture{pigment{rgb<0.368627,0.352941,0.054902>} normal{bumps 0.1 scale 0.0001 } finish{ambient 0.2 diffuse 0.5 phong 0.1} }
        // Pads and SMDs
        #declare col_pds = texture{pigment{Gray70} finish{F_MetalB} }
        // Simulated holes
        #declare col_hls = texture{pigment{Black}}
        // Background color
        #declare col_bgr = Gray50;
        // Silkscreen
        #declare col_slk = texture{pigment{White}}
        // Vias
        #declare col_thl = texture{pigment{Gray70} finish{F_MetalB} }
        // Polygons
        #declare col_pol = col_wrs
        #break

     #case(4) // Homemade PCB (with black silkscreen)
        // PCB material
        #declare col_brd = texture{pigment{rgb< 0.470588,0.313725,0.000000>}}
        // Wires
        #declare col_wrs = texture{col_gold}
        // Pads and SMDs
        #declare col_pds = texture{col_gold}
        // Simulated holes
        #declare col_hls = texture{pigment{Black}}
        // Background color
        #declare col_bgr = White;
        // Silkscreen
        #declare col_slk = texture{pigment{Black}}
        // Vias
        #declare col_thl = texture{col_silver}
        // Polygons
        #declare col_pol = texture{T_Stone1}
        #break

     #case(5) // Bunt
        // PCB material
        #declare col_brd = texture{pigment{Red}}
        // Wires
        #declare col_wrs = texture{pigment{Blue}}
        // Pads and SMDs
        #declare col_pds = texture{T_Silver_5A}
        // Simulated holes
        #declare col_hls = texture{pigment{Black}}
        // Background color
        #declare col_bgr = White;
        // Silkscreen
        #declare col_slk = texture{pigment{Green}}
        // Vias
        #declare col_thl = texture{pigment{White}}
        // Polygons
        #declare col_pol = texture{T_Stone1}
        #break

     #case(6) // Glass
        // PCB material
        #declare col_brd = texture{T_Dark_Green_Glass}
        // Wires
        #declare col_wrs = texture{pigment{rgb<0.368627,0.352941,0.054902>}}
        // Pads and SMDs
        #declare col_pds = texture{pigment{Gray70} finish{F_MetalB}}
        // Simulated holes
        #declare col_hls = texture{pigment{Black}}
        // Background color
        #declare col_bgr = White;
        // Silkscreen
        #declare col_slk = texture{pigment{White}}
        // Vias
        #declare col_thl = texture{pigment{Gray70} finish{F_MetalB}}
        // Polygons
        #declare col_pol = col_wrs
        #break

     #range(7,2000) // default
        // PCB material
        #declare col_brd = texture{pigment{DarkGreen}}
        // Wires
        #declare col_wrs = texture{pigment{ForestGreen}}
        // Pads and SMDs
        #declare col_pds = texture{T_Silver_5A}
        // Simulated holes
        #declare col_hls = texture{pigment{Black}}
        // Background color
        #declare col_bgr = White;
        // Silkscreen
        #declare col_slk = texture{pigment{White}}
        // Vias
        #declare col_thl = texture{T_Silver_5A}
        // Polygons
        #declare col_pol = col_wrs
        #break

     #end
#end
