/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * PCB terminal block 3.5mm pitch
 * Phoenix Contact MKDS 1/<num>-<pitch>
 * with num = (2..16)
 * with pitch = (3,5 ; 3,81)
 *   part numbers: 1751248, 1751251, 1751264, 1751277, 1751280,
 *                 1751293, 1751303, 1751316, 1751329, 1751332,
 *                 1751345, 1751358, 1751361, 1751374, 1751387,
 *                 1727010, 1727023, 1727036, 1727049, 1727052,
 *                 1727065, 1727078, 1727081, 1727094, 1727104,
 *                 1727117, 1931754
 * con-phoenix-350.lbr
 * con-phoenix-3.81.lbr
 * 15.05.2023, wk
 ******************************************************************************/

#macro MKDS1(pitch,pins)
  union {
     #local LightGreen = rgb <0.427,0.643,0.419>;
     #local a = (pins - 1) * pitch;
     difference {
        #local W = a + 3.80;
        #local x1 = 7.3-3.6;
        #local x2 = x1-2.0;
        #local x3 = x2-4.0;
        #local x5 = -3.6;
        #local x4 = x5+0.8;
        #local y1 = 3.50;
        #local y2 = 8.50;
        #local y3 = 5.00;
        prism {
           linear_sweep
           linear_spline
           -W/2,+W/2,
           8,
           <x1,0>,
           <x1,y1>,
           <x2,y2>,
           <x3,y2>,
           <x4,y3>,
           <x5,y3>,
           <x5,0>,
           <x1,0>
           rotate <-90,-90,0>
           }
        GRID (
           union {
              cylinder {
                 <0,2,0> <0,9,0> 1.55
                 }
              box {
                 <-3.0/2,0.2,-2.3>
                 <+3.0/2,4.6,+2.3>
                 }
              box {
                 <-1.5/2,1.2,+4.0>
                 <+1.5/2,3.1,-4.0>
                 }
              object {
                 Pyramid2
                 rotate <90,0,90>
                 scale <3.2,5,3>
                 translate<0,2.3,-3.6>
                 }
              }
           pitch,pins,1
           )
        pigment { LightGreen }
        }
     GRID (
        union {
           object {
              TOOLS_SCREW(2,5,0,Silver)
              scale 0.7
              translate <0,7.5,0>
              }
           difference {
              box {
                 <-2.9/2,0.3,-2.2>
                 <+2.9/2,4.5,+2.2>
                 }
              box {
                 <-2.2/2,1.5,-2.5>
                 <+2.2/2,3.0,+2.0>
                 }
              }
           prism {
              linear_sweep
              linear_spline
              -0.5/2,+0.5/2,
              7,
              <+0.9/2,0>,
              <+0.9/2,-2.0>,
              <+0.3/2,-2.5>,
              <-0.3/2,-2.5>,
              <-0.9/2,-2.0>,
              <-0.9/2,0>,
              <+0.9/2,0>
              rotate <-90,0,0>
              }
           texture {
              col_silver
              }
           }
        pitch,pins,1
        )
     #local number = 1;
     #while (number <= pins)
        text {
           ttf besch_font str(number,0,0) 0.2,0
           rotate <158,0,0>
           scale 2
           translate<-0.5 + (-pins/2 + number - 0.5) * pitch,8,1.95>
           texture {
              col_black_marking
              }
           }
        #local number = number + 1;
     #end
     #if (pitch = 3.50)
         #switch(pins)
            #case (2)  #local partNo = "1751248"; #break
            #case (3)  #local partNo = "1751251"; #break
            #case (4)  #local partNo = "1751264"; #break
            #case (5)  #local partNo = "1751277"; #break
            #case (6)  #local partNo = "1751280"; #break
            #case (7)  #local partNo = "1751293"; #break
            #case (8)  #local partNo = "1751303"; #break
            #case (9)  #local partNo = "1751316"; #break
            #case (10) #local partNo = "1751329"; #break
            #case (11) #local partNo = "1751332"; #break
            #case (12) #local partNo = "1751345"; #break
            #case (13) #local partNo = "1751358"; #break
            #case (14) #local partNo = "1751361"; #break
            #case (15) #local partNo = "1751374"; #break
            #case (16) #local partNo = "1751387"; #break
            #else #local partNo = "part no?";     #break
         #end
     #end
     #if (pitch = 3.81)
         #switch(pins)
            #case (2)  #local partNo = "1727010"; #break
            #case (3)  #local partNo = "1727023"; #break
            #case (4)  #local partNo = "1727036"; #break
            #case (5)  #local partNo = "1727049"; #break
            #case (6)  #local partNo = "1727052"; #break
            #case (7)  #local partNo = "1727065"; #break
            #case (8)  #local partNo = "1727078"; #break
            #case (9)  #local partNo = "1727081"; #break
            #case (10) #local partNo = "1727094"; #break
            #case (11) #local partNo = "1727104"; #break
            #case (12) #local partNo = "1727117"; #break
            #case (13) #local partNo = "1931754"; #break
            #else #local partNo = "part no?";     #break
         #end
     #end
     text {
        ttf besch_font partNo 0.2,0
        rotate <158,0,0>
        scale 1
        translate <-2,6,2.75>
        texture {
           col_black_marking
           }
        }
     }
#end

#macro CON_THT_PHOENIX_MKDS1_2_35()   MKDS1(3.50,2)  #end
#macro CON_THT_PHOENIX_MKDS1_3_35()   MKDS1(3.50,3)  #end
#macro CON_THT_PHOENIX_MKDS1_4_35()   MKDS1(3.50,4)  #end
#macro CON_THT_PHOENIX_MKDS1_5_35()   MKDS1(3.50,5)  #end
#macro CON_THT_PHOENIX_MKDS1_6_35()   MKDS1(3.50,6)  #end
#macro CON_THT_PHOENIX_MKDS1_7_35()   MKDS1(3.50,7)  #end
#macro CON_THT_PHOENIX_MKDS1_8_35()   MKDS1(3.50,8)  #end
#macro CON_THT_PHOENIX_MKDS1_9_35()   MKDS1(3.50,9)  #end
#macro CON_THT_PHOENIX_MKDS1_10_35()  MKDS1(3.50,10) #end
#macro CON_THT_PHOENIX_MKDS1_11_35()  MKDS1(3.50,11) #end
#macro CON_THT_PHOENIX_MKDS1_12_35()  MKDS1(3.50,12) #end
#macro CON_THT_PHOENIX_MKDS1_13_35()  MKDS1(3.50,13) #end
#macro CON_THT_PHOENIX_MKDS1_14_35()  MKDS1(3.50,14) #end
#macro CON_THT_PHOENIX_MKDS1_15_35()  MKDS1(3.50,15) #end
#macro CON_THT_PHOENIX_MKDS1_16_35()  MKDS1(3.50,16) #end
#macro CON_THT_PHOENIX_MKDS1_2_381()  MKDS1(3.81,2)  #end
#macro CON_THT_PHOENIX_MKDS1_3_381()  MKDS1(3.81,3)  #end
#macro CON_THT_PHOENIX_MKDS1_4_381()  MKDS1(3.81,4)  #end
#macro CON_THT_PHOENIX_MKDS1_5_381()  MKDS1(3.81,5)  #end
#macro CON_THT_PHOENIX_MKDS1_6_381()  MKDS1(3.81,6)  #end
#macro CON_THT_PHOENIX_MKDS1_7_381()  MKDS1(3.81,7)  #end
#macro CON_THT_PHOENIX_MKDS1_8_381()  MKDS1(3.81,8)  #end
#macro CON_THT_PHOENIX_MKDS1_9_381()  MKDS1(3.81,9)  #end
#macro CON_THT_PHOENIX_MKDS1_10_381() MKDS1(3.81,10) #end
#macro CON_THT_PHOENIX_MKDS1_11_381() MKDS1(3.81,11) #end
#macro CON_THT_PHOENIX_MKDS1_12_381() MKDS1(3.81,12) #end
#macro CON_THT_PHOENIX_MKDS1_13_381() MKDS1(3.81,13) #end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-phoenix-350:1751248=CON_THT_PHOENIX_MKDS1_2_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751251=CON_THT_PHOENIX_MKDS1_3_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751264=CON_THT_PHOENIX_MKDS1_4_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751277=CON_THT_PHOENIX_MKDS1_5_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751280=CON_THT_PHOENIX_MKDS1_6_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751293=CON_THT_PHOENIX_MKDS1_7_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751303=CON_THT_PHOENIX_MKDS1_8_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751316=CON_THT_PHOENIX_MKDS1_9_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751329=CON_THT_PHOENIX_MKDS1_10_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751332=CON_THT_PHOENIX_MKDS1_11_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751345=CON_THT_PHOENIX_MKDS1_12_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751358=CON_THT_PHOENIX_MKDS1_13_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751361=CON_THT_PHOENIX_MKDS1_14_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751374=CON_THT_PHOENIX_MKDS1_15_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-350:1751387=CON_THT_PHOENIX_MKDS1_16_35(:Phoenix-Contact PCB terminal block 3.5mm
//con-phoenix-3.81:1727010=CON_THT_PHOENIX_MKDS1_2_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727023=CON_THT_PHOENIX_MKDS1_3_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727036=CON_THT_PHOENIX_MKDS1_4_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727049=CON_THT_PHOENIX_MKDS1_5_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727052=CON_THT_PHOENIX_MKDS1_6_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727065=CON_THT_PHOENIX_MKDS1_7_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727078=CON_THT_PHOENIX_MKDS1_8_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727081=CON_THT_PHOENIX_MKDS1_9_381(:Phoenix-Contact PCB terminal block 3.81mm 
//con-phoenix-3.81:1727094=CON_THT_PHOENIX_MKDS1_10_381(:Phoenix-Contact PCB terminal block 3.81mm
//con-phoenix-3.81:1727104=CON_THT_PHOENIX_MKDS1_11_381(:Phoenix-Contact PCB terminal block 3.81mm
//con-phoenix-3.81:1727117=CON_THT_PHOENIX_MKDS1_12_381(:Phoenix-Contact PCB terminal block 3.81mm
//con-phoenix-3.81:1931754=CON_THT_PHOENIX_MKDS1_13_381(:Phoenix-Contact PCB terminal block 3.81mm
// end assignment
