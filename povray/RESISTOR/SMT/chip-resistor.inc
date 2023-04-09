/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * SMT chip resistor
 * b - Breite
 * l - Laenge
 * h - Hoehe
 * blf - Breite Loetflaeche
 * value - Text
 ******************************************************************************/
#macro RES_SMD_CHIP_BASE(l,b,h,blf,value)
  union {
     box {
        <0,0,0.01> <blf,h+0.05,b-0.01>
        }
     box {
        <l,0,0.01> <l-blf,h+0.05,b-0.01>
        }
     box {
        <0.05,0.05,0> <l-0.05,h,b>
        pigment {
           White
           }
        }
     box {
        <blf,h,0> <l-blf,h+0.07,b>
        texture {
           pigment {
              Gray20
              }
           finish {
              phong 0.5
              ambient (0.1 * global_ambient_mul)
              }
           }
        }
     text {
        ttf besch_font value 0.1, 0
        pigment {
           White
           }
        rotate <90,0,0>
        scale l/5 //<l/5,1,b/1.5>
        translate <l/3.8,h+0.08,b/3>
        }
     texture {
        col_silver
        }
     translate <-l/2,0,-b/2>
     }
#end




// metric size codes (mm)
#macro RES_SMD_CHIP_0201_metric(value) RES_SMD_CHIP_BASE(0.25,0.12,0.10,0.10,value) #end //!!
#macro RES_SMD_CHIP_0402_metric(value) RES_SMD_CHIP_BASE(0.40,0.20,0.20,0.10,value) #end
#macro RES_SMD_CHIP_0603_metric(value) RES_SMD_CHIP_BASE(0.60,0.30,0.30,0.20,value) #end //!!
#macro RES_SMD_CHIP_1005_metric(value) RES_SMD_CHIP_BASE(1.00,0.50,0.20,0.20,value) #end
#macro RES_SMD_CHIP_1310_metric(value) RES_SMD_CHIP_BASE(1.27,1.02,0.40,0.25,value) #end //!!
#macro RES_SMD_CHIP_1608_metric(value) RES_SMD_CHIP_BASE(1.60,0.80,0.40,0.25,value) #end
#macro RES_SMD_CHIP_2012_metric(value) RES_SMD_CHIP_BASE(2.00,1.25,0.45,0.35,value) #end
#macro RES_SMD_CHIP_3216_metric(value) RES_SMD_CHIP_BASE(3.20,1.60,0.45,0.45,value) #end
#macro RES_SMD_CHIP_3225_metric(value) RES_SMD_CHIP_BASE(3.20,2.50,0.45,0.50,value) #end
#macro RES_SMD_CHIP_3245_metric(value) RES_SMD_CHIP_BASE(3.20,4.50,0.45,0.50,value) #end
#macro RES_SMD_CHIP_4020_metric(value) RES_SMD_CHIP_BASE(4.00,2.00,0.45,0.50,value) #end //!!
#macro RES_SMD_CHIP_4520_metric(value) RES_SMD_CHIP_BASE(4.50,2.00,0.45,0.50,value) #end //!!
#macro RES_SMD_CHIP_4527_metric(value) RES_SMD_CHIP_BASE(4.50,2.70,0.45,0.50,value) #end //!!
#macro RES_SMD_CHIP_4532_metric(value) RES_SMD_CHIP_BASE(4.50,3.20,0.45,0.50,value) #end //!!
#macro RES_SMD_CHIP_4564_metric(value) RES_SMD_CHIP_BASE(4.50,6.40,0.45,0.50,value) #end //!!
#macro RES_SMD_CHIP_5025_metric(value) RES_SMD_CHIP_BASE(5.00,2.50,0.45,0.60,value) #end
#macro RES_SMD_CHIP_5650_metric(value) RES_SMD_CHIP_BASE(5.60,5.00,0.50,0.60,value) #end //!!
#macro RES_SMD_CHIP_5664_metric(value) RES_SMD_CHIP_BASE(5.60,6.40,0.50,0.60,value) #end //!!
#macro RES_SMD_CHIP_6032_metric(value) RES_SMD_CHIP_BASE(6.00,3.20,0.50,0.60,value) #end //!!
#macro RES_SMD_CHIP_6332_metric(value) RES_SMD_CHIP_BASE(6.30,3.20,0.55,0.60,value) #end


// imperial size codes (inches)
// The imperial code is more commonly used in the PCBA industry
#macro RES_SMD_CHIP_008004(value) RES_SMD_CHIP_0201_metric(value) #end
#macro RES_SMD_CHIP_01005(value)  RES_SMD_CHIP_0402_metric(value) #end
#macro RES_SMD_CHIP_0201(value)   RES_SMD_CHIP_0603_metric(value) #end
#macro RES_SMD_CHIP_0402(value)   RES_SMD_CHIP_1005_metric(value) #end
#macro RES_SMD_CHIP_0504(value)   RES_SMD_CHIP_1310_metric(value) #end
#macro RES_SMD_CHIP_0603(value)   RES_SMD_CHIP_1608_metric(value) #end
#macro RES_SMD_CHIP_0805(value)   RES_SMD_CHIP_2012_metric(value) #end
#macro RES_SMD_CHIP_1206(value)   RES_SMD_CHIP_3216_metric(value) #end
#macro RES_SMD_CHIP_1210(value)   RES_SMD_CHIP_3225_metric(value) #end
#macro RES_SMD_CHIP_1218(value)   RES_SMD_CHIP_3245_metric(value) #end
#macro RES_SMD_CHIP_1608(value)   RES_SMD_CHIP_4020_metric(value) #end
#macro RES_SMD_CHIP_1808(value)   RES_SMD_CHIP_4520_metric(value) #end
#macro RES_SMD_CHIP_1810(value)   RES_SMD_CHIP_4527_metric(value) #end
#macro RES_SMD_CHIP_1812(value)   RES_SMD_CHIP_4532_metric(value) #end
#macro RES_SMD_CHIP_1825(value)   RES_SMD_CHIP_4564_metric(value) #end
#macro RES_SMD_CHIP_2010(value)   RES_SMD_CHIP_5025_metric(value) #end
#macro RES_SMD_CHIP_2220(value)   RES_SMD_CHIP_5650_metric(value) #end
#macro RES_SMD_CHIP_2225(value)   RES_SMD_CHIP_5664_metric(value) #end
#macro RES_SMD_CHIP_2312(value)   RES_SMD_CHIP_6032_metric(value) #end
#macro RES_SMD_CHIP_2512(value)   RES_SMD_CHIP_6332_metric(value) #end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=RES_SMD_CHIP_008004(:SMT chip resistor 008004
//rcl:R01005=RES_SMD_CHIP_01005(:SMT chip resistor 01005
//rcl:R0201=RES_SMD_CHIP_0201(:SMT chip resistor 0201
//rcl:R0402=RES_SMD_CHIP_0402(:SMT chip resistor 0402
//rcl:R0603=RES_SMD_CHIP_0603(:SMT chip resistor 0603
//rcl:M0805,R0805W,R2012,R2012W=RES_SMD_CHIP_0805(:SMT chip resistor 0805
//rcl:M1206,R1206,R1206W,R3216,R3216W=RES_SMD_CHIP_1206(:SMT chip resistor 1206
//rcl:R1210,R1210W,R3225,R3225W=RES_SMD_CHIP_1210(:SMT chip resistor 1210
//rcl:R1218:=RES_SMD_CHIP_1218(SMT chip resistor 1218
//=RES_SMD_CHIP_1608(SMT chip resistor 1608
//=RES_SMD_CHIP_1808(SMT chip resistor 1808
//=RES_SMD_CHIP_1810(SMT chip resistor 1810
//=RES_SMD_CHIP_1812(SMT chip resistor 1812
//=RES_SMD_CHIP_1825(SMT chip resistor 1825
//rcl:R2010,R2010W,R5025,R5025W=RES_SMD_CHIP_2010(:SMT chip resistor 2010
//=RES_SMD_CHIP_2220(:SMT chip resistor 2220
//=RES_SMD_CHIP_2225(:SMT chip resistor 2225
//=RES_SMD_CHIP_2312(:SMT chip resistor 2312
//rcl:R2512,R2512W:=RES_SMD_CHIP_2512(:SMT chip resistor 2512
// end assignment
