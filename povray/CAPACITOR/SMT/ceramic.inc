/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMT ceramic chip cap
 * K = Anschlussbreite
 ******************************************************************************/
#macro CAP_SMD_CHIP_BASE(L,W,T,K)
  union {
     superellipsoid { // Body in brown
        <0.25-(L+W)/150, 0.25-(L+W)/150>
        texture {
           col_ceramic_cap
           }
        scale <L/2,W/2,T/2>
        }
     union { //Contacts
        superellipsoid {
           <0.25-(L+W)/200, 0.25-(L+W)/200>
           scale <(K+L/100)/2,W/2,T/2>
           translate <+(L-K)/2,0,0>
           }
        superellipsoid {
           <0.25-(L+W)/200, 0.25-(L+W)/200>
           scale <(K+L/100)/2,W/2,T/2>
           translate <-(L-K)/2,0,0>
           }
        texture {
           col_silver
           }
        }
     rotate <90,0,0>
     translate <0,T/2,0>
     }
#end



// metric size codes (mm)
#macro CAP_SMD_CHIP_0201_metric() CAP_SMD_CHIP_BASE(0.25,0.12,0.10,0.10) #end
#macro CAP_SMD_CHIP_0402_metric() CAP_SMD_CHIP_BASE(0.40,0.20,0.20,0.15) #end
#macro CAP_SMD_CHIP_0603_metric() CAP_SMD_CHIP_BASE(0.60,0.30,0.30,0.20) #end
#macro CAP_SMD_CHIP_1005_metric() CAP_SMD_CHIP_BASE(1.00,0.50,0.60,0.20) #end
#macro CAP_SMD_CHIP_1310_metric() CAP_SMD_CHIP_BASE(1.27,1.02,0.80,0.35) #end
#macro CAP_SMD_CHIP_1608_metric() CAP_SMD_CHIP_BASE(1.60,0.80,0.90,0.30) #end
#macro CAP_SMD_CHIP_2012_metric() CAP_SMD_CHIP_BASE(2.00,1.25,1.30,0.50) #end
#macro CAP_SMD_CHIP_3216_metric() CAP_SMD_CHIP_BASE(3.20,1.60,1.50,0.50) #end
#macro CAP_SMD_CHIP_3225_metric() CAP_SMD_CHIP_BASE(3.20,2.50,1.70,0.50) #end
#macro CAP_SMD_CHIP_4020_metric() CAP_SMD_CHIP_BASE(4.00,2.00,1.70,0.50) #end
#macro CAP_SMD_CHIP_4520_metric() CAP_SMD_CHIP_BASE(4.50,2.00,1.70,0.50) #end
#macro CAP_SMD_CHIP_4532_metric() CAP_SMD_CHIP_BASE(4.50,3.20,1.70,0.50) #end
#macro CAP_SMD_CHIP_4564_metric() CAP_SMD_CHIP_BASE(4.50,6.40,1.70,0.50) #end
#macro CAP_SMD_CHIP_5025_metric() CAP_SMD_CHIP_BASE(5.00,2.50,1.70,0.50) #end
#macro CAP_SMD_CHIP_5650_metric() CAP_SMD_CHIP_BASE(5.60,5.00,2.70,0.50) #end
#macro CAP_SMD_CHIP_5664_metric() CAP_SMD_CHIP_BASE(5.60,6.40,2.70,0.50) #end
#macro CAP_SMD_CHIP_6032_metric() CAP_SMD_CHIP_BASE(6.00,3.20,2.70,0.50) #end
#macro CAP_SMD_CHIP_6332_metric() CAP_SMD_CHIP_BASE(6.30,3.20,2.70,0.50) #end


// imperial size codes (inches)
// The imperial code is more commonly used in the PCBA industry
#macro CAP_SMD_CHIP_008004() CAP_SMD_CHIP_0201_metric() #end
#macro CAP_SMD_CHIP_01005()  CAP_SMD_CHIP_0402_metric() #end
#macro CAP_SMD_CHIP_0201()   CAP_SMD_CHIP_0603_metric() #end
#macro CAP_SMD_CHIP_0402()   CAP_SMD_CHIP_1005_metric() #end
#macro CAP_SMD_CHIP_0504()   CAP_SMD_CHIP_1310_metric() #end
#macro CAP_SMD_CHIP_0603()   CAP_SMD_CHIP_1608_metric() #end
#macro CAP_SMD_CHIP_0805()   CAP_SMD_CHIP_2012_metric() #end
#macro CAP_SMD_CHIP_1206()   CAP_SMD_CHIP_3216_metric() #end
#macro CAP_SMD_CHIP_1210()   CAP_SMD_CHIP_3225_metric() #end
#macro CAP_SMD_CHIP_1608()   CAP_SMD_CHIP_4020_metric() #end
#macro CAP_SMD_CHIP_1808()   CAP_SMD_CHIP_4520_metric() #end
#macro CAP_SMD_CHIP_1812()   CAP_SMD_CHIP_4532_metric() #end
#macro CAP_SMD_CHIP_1825()   CAP_SMD_CHIP_4564_metric() #end
#macro CAP_SMD_CHIP_2010()   CAP_SMD_CHIP_5025_metric() #end
#macro CAP_SMD_CHIP_2220()   CAP_SMD_CHIP_5650_metric() #end
#macro CAP_SMD_CHIP_2225()   CAP_SMD_CHIP_5664_metric() #end
#macro CAP_SMD_CHIP_2312()   CAP_SMD_CHIP_6032_metric() #end
#macro CAP_SMD_CHIP_2512()   CAP_SMD_CHIP_6332_metric() #end

// unknown:
#macro CAP_SMD_CHIP_1411()
  CAP_SMD_CHIP_BASE(3.5,2.8,1.7,0.5)
#end

#macro CAP_SMD_CHIP_1515()
  CAP_SMD_CHIP_BASE(3.81,3.81,1.7,0.5)
#end


/*
 other chip sizes:
2515 	6,30 ± 0,20 	3,81 ± 0,20
2716 	7,00 ± 0,20 	4,00 ± 0,20
2824 	7,20 ± 0,20 	6,10 ± 0,20
2917 	7,30 ± 0,20 	4,30 ± 0,20
2920 	7,30 ± 0,20 	5,00 ± 0,30
3111 	8,00 ± 0,20 	2,80 ± 0,20
3931 	10,00 ± 0,20 	8,00 ± 0,20
4018 	10,16 ± 0,20 	4,60 ± 0,20
4040 	10,2 ± 0,50 	10,2 ± 0,50
4320 	11,00 ± 0,20 	5,00 ± 0,20
4335 	11,00 ± 0,20 	9,00 ± 0,20
4349 	11,00 ± 0,20 	12,50 ± 0,20
4424 	11,10 ± 0,81 	6,10 ± 0,40
4527 	11,50 ± 0,20 	7,00 ± 0,20
4540 	11,4 ± 0,58 	10,2 ± 0,50
4723 	12,00 ± 0,20 	6,00 ± 0,20
4825 	12,20 ± 0,20 	6,35 ± 0,20
5550 	14,00 ± 0,71 	12,70 ± 0,63
5727 	14,40 ± 0,20 	7,00 ± 0,20
6145 	15,50 ± 0,20 	11,50 ± 0,20
6561 	16,50 ± 0,20 	15,50 ± 0,20
7565 	19,10 ± 0,96 	16,50 ± 0,83
*/

/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CAP_SMD_CHIP_008004(:ceramic SMT cap 008004
//rcl:C01005=CAP_SMD_CHIP_01005(:ceramic SMT cap 01005
//rcl:C0201=CAP_SMD_CHIP_0201(:ceramic SMT cap 0201
//rcl:C0402,C0402K=CAP_SMD_CHIP_0402(:ceramic SMT cap 0402
//rcl:C0504=CAP_SMD_CHIP_0504(:ceramic SMT cap 0504
//rcl:C0603,C0603K=CAP_SMD_CHIP_0603(:ceramic SMT cap 0603
//rcl:C0805,C0805K=CAP_SMD_CHIP_0805(:ceramic SMT cap 0805
//rcl:C1206,C1206K=CAP_SMD_CHIP_1206(:ceramic SMT cap 1206
//rcl:C1210,C1210K=CAP_SMD_CHIP_1210(:ceramic SMT cap 1210
//=CAP_SMD_CHIP_1411(:ceramic SMT cap 1411
//=CAP_SMD_CHIP_1515(:ceramic SMT cap 1515
//rcl:C1608=CAP_SMD_CHIP_1608(:ceramic SMT cap 1608
//rcl:C1808=CAP_SMD_CHIP_1808(:ceramic SMT cap 1808
//rcl:C1812,C1812K=CAP_SMD_CHIP_1812(:ceramic SMT cap 1812
//rcl:C1825,C1825K=CAP_SMD_CHIP_1825(:ceramic SMT cap 1825
//=CAP_SMD_CHIP_2010(:ceramic SMT cap 2010
//rcl:C2220K=CAP_SMD_CHIP_2220(:ceramic SMT cap 2220
//rcl:C2225K=CAP_SMD_CHIP_2225(:ceramic SMT cap 2225
//=CAP_SMD_CHIP_2312:ceramic cap 2312
// end assignment
