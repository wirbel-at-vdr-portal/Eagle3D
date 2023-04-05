/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * MOLEX econ connect Board-to-Wire Connectors
 *    PSL - Identifier        : Wafer Series CV Pitch 2.54 mm single row
 *    #   - Number of contacts: 2..20
 *    x   - G or W            : straight or elbow
 * 
 * Author: Tilmann Reh <tilmann.reh@autometer.de>
 ******************************************************************************/


/*******************************************************************************
 * Kunststoffkoerper von geraden und abgewinkelten Molex-Stiftleisten
 ******************************************************************************/
#macro CON_MOLEX_PSL_XX_X_housing(PinCount)
  union {
     #local white_plastic = texture {
         pigment {Wheat}
         finish { ambient(0.1 * global_ambient_mul)}
         };

     difference {
        box { <-2.54/2*PinCount,0,-2.5> <+2.54/2*PinCount,3,+3.0> }
        #local slot = box {<-1/2,-0.1,-3> <+1/2,+0.8,+4>};
        GRID_BASE(slot,2.54,PinCount,1)
        }
     box { <-2.54*(PinCount-1)/2,2,-2.5> <+2.54*(PinCount-1)/2,11.3,-1.7> }
     box { <-2.54*(PinCount-1)/2,5.8,-2> <+2.54*(PinCount-1)/2, 7.5,-1.4> }
     texture {white_plastic}
     }
#end


/*******************************************************************************
 * straight version.
 ******************************************************************************/
#macro CON_MOLEX_PSL_XX_G_BASE(PinCount)
  union {
     object{CON_MOLEX_PSL_XX_X_housing(PinCount)}
     object{PIN_STRAIGHT_ROW(PinCount,2.54,0.635,11,3,col_silver)}
     }
#end


/*******************************************************************************
 * 90deg elbow version.
 ******************************************************************************/
#macro CON_MOLEX_PSL_XX_W_BASE(PinCount)
  union {
     object{CON_MOLEX_PSL_XX_X_housing(PinCount) rotate<-90,0,0> translate<0,2.5,-1.8>}
     object{PIN_BENDED_ROW(PinCount,2.54,0.635,0.8,2.5,3,12.5,col_silver) translate<0,0,0>}
     }
#end



/******************************************************************************
 * produced parts here:
 ******************************************************************************/

#macro CON_MOLEX_PSL2G()
  CON_MOLEX_PSL_XX_G_BASE(2)
#end

#macro CON_MOLEX_PSL3G()
  CON_MOLEX_PSL_XX_G_BASE(3)
#end

#macro CON_MOLEX_PSL4G()
  CON_MOLEX_PSL_XX_G_BASE(4)
#end

#macro CON_MOLEX_PSL5G()
  CON_MOLEX_PSL_XX_G_BASE(5)
#end

#macro CON_MOLEX_PSL6G()
  CON_MOLEX_PSL_XX_G_BASE(6)
#end

#macro CON_MOLEX_PSL7G()
  CON_MOLEX_PSL_XX_G_BASE(7)
#end

#macro CON_MOLEX_PSL8G()
  CON_MOLEX_PSL_XX_G_BASE(8)
#end

#macro CON_MOLEX_PSL9G()
  CON_MOLEX_PSL_XX_G_BASE(9)
#end

#macro CON_MOLEX_PSL10G()
  CON_MOLEX_PSL_XX_G_BASE(10)
#end

//---

#macro CON_MOLEX_PSL2W()
  CON_MOLEX_PSL_XX_W_BASE(2)
#end

#macro CON_MOLEX_PSL3W()
  CON_MOLEX_PSL_XX_W_BASE(3)
#end

#macro CON_MOLEX_PSL4W()
  CON_MOLEX_PSL_XX_W_BASE(4)
#end

#macro CON_MOLEX_PSL5W()
  CON_MOLEX_PSL_XX_W_BASE(5)
#end

#macro CON_MOLEX_PSL6W()
  CON_MOLEX_PSL_XX_W_BASE(6)
#end

#macro CON_MOLEX_PSL7W()
  CON_MOLEX_PSL_XX_W_BASE(7)
#end

#macro CON_MOLEX_PSL8W()
  CON_MOLEX_PSL_XX_W_BASE(8)
#end

#macro CON_MOLEX_PSL9W()
  CON_MOLEX_PSL_XX_W_BASE(9)
#end

#macro CON_MOLEX_PSL10W()
  CON_MOLEX_PSL_XX_W_BASE(10)
#end
