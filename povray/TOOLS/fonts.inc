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


#declare global_fontfile_fallback     = "DejaVuLGCSansMono-Bold.ttf";
#declare besch_font                   = "DejaVuLGCSansMono-Bold.ttf"
#declare global_fontfile_courier      = "DejaVuLGCSansMono.ttf";
#declare global_fontfile_courier_bold = "DejaVuLGCSansMono-Bold.ttf";
#declare global_fontfile_arial        = "DejaVuLGCSans.ttf";
#declare global_fontfile_arial_bold   = "DejaVuLGCSans-Bold.ttf";
#declare global_fontfile_alphalcd     = "alphalcd.ttf"
#declare global_fontfile_eagle3d      = "eagle3d.ttf"

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
