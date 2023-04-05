/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.                    
 *                                                                              
 * See the README file for copyright information and how to reach the author.   
 ******************************************************************************/

/*******************************************************************************
 * This is the global texture definition file.
 ******************************************************************************/
#declare tex_elko = pigment {
   image_map {
      png "TOOLS/textures/elko.png"
      }
   }


#declare tex_elko_axial = pigment {
   image_map {
      png "TOOLS/textures/elko_axial.png"
      map_type 2
      interpolate 4
      }
   }
