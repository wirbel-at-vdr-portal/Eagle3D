/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * an SO(*) pin or similar; (copy of QFP-Pin)
 * H: pin height
 * B: pin width
 * T: pin depth
 * S: material strength
 * used by:
 *  - IC_SMD_DFS_GRND
 *  - IC_SMD_GRND
 *  - IC_SMD_MB2S_GRND
 *  - IC_SMD_SOT143_GRND
 ******************************************************************************/
#macro IC_SMD_PIN(H,B,T,S)
  union {
     box{<0,H,T/2> <B/4,H-S,-T/2>}
     difference{
        cylinder{<B/4,H-S,-T/2> <B/4,H-S,T/2> S}
        box{<-1,H-S,-T/2-0.01> <B/2,H-S-3,T/2+0.01>}
        }
     box{<B/4,H-S,-T/2> <B/4+S,S,T/2>}
     difference{
        cylinder{<B/4+S,S,-T/2> <B/4+S,S,T/2> S}
        box{<0,S,-T/2-0.01> <B,S+3,T/2+0.01>}
     }
     box{<B/4+S,0,-T/2> <B,S,T/2>}
     difference{
        box{<B/4+S,S,-T/2> <B/4+S+S/2,1.5*S, T/2>}
        cylinder{<B/4+S+S/2,S+S/2,T/2+0.01> <B/4+S+S/2,S+S/2,-T/2-0.01>, S/2}
     }
  }
#end
