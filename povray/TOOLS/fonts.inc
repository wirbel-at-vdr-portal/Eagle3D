/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Here we declare all fonts and their fallbacks, if a font cannot be found.
 *
 * The last fallback font for all fonts is courbd.ttf, as we used this font in
 * earlier versions of Eagle3D.
 ******************************************************************************/

#macro CheckFont(FONT, FALLBACK)
   #if (file_exists(FONT) = 0)
       #warning concat("-------- Eagle3D: ", FONT, " not found: ",
                       "using fallback ", FALLBACK, ". --------")
       #declare FONT = FALLBACK;
   #end
#end


#declare global_fontfile_fallback     = "TOOLS/fonts/DejaVuLGCSansMono-Bold.ttf";
#declare besch_font                   = "TOOLS/fonts/DejaVuLGCSansMono-Bold.ttf"
#declare global_fontfile_courier      = "TOOLS/fonts/DejaVuLGCSansMono.ttf";
#declare global_fontfile_courier_bold = "TOOLS/fonts/DejaVuLGCSansMono-Bold.ttf";
#declare global_fontfile_arial        = "TOOLS/fonts/DejaVuLGCSans.ttf";
#declare global_fontfile_arial_bold   = "TOOLS/fonts/DejaVuLGCSans-Bold.ttf";
#declare global_fontfile_alphalcd     = "TOOLS/fonts/alphalcd.ttf"
#declare global_fontfile_eagle3d      = "TOOLS/fonts/eagle3d.ttf"

CheckFont(global_fontfile_fallback     , "cyrvetic.ttf")
CheckFont(global_fontfile_fallback     , "courbd.ttf")
CheckFont(global_fontfile_fallback     , "")



CheckFont(global_fontfile_eagle3d      , "")
CheckFont(besch_font                   , global_fontfile_fallback)
CheckFont(global_fontfile_courier      , global_fontfile_fallback)
CheckFont(global_fontfile_courier_bold , global_fontfile_fallback)
CheckFont(global_fontfile_arial        , global_fontfile_fallback)
CheckFont(global_fontfile_arial_bold   , global_fontfile_fallback)
CheckFont(global_fontfile_alphalcd     , global_fontfile_fallback)
