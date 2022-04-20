/*******************************************************************************
 * Creates a bar with four of its edges rounded.
 * Needs to be compatible to old implementation below.
 * 20220420, wk
 ******************************************************************************/
#macro TOOLS_ROUNDED_BAR(p1,p2,R)
   intersection {
      #local margin = 0.1;
      #local x1 = min(p1.x,p2.x)-margin;
      #local x2 = max(p1.x,p2.x)+margin;
      #local y1 = min(p1.y,p2.y)-margin;
      #local y2 = max(p1.y,p2.y)+margin;
      #local z1 = min(p1.z,p2.z);
      #local z2 = max(p1.z,p2.z);       
      object { Round_Box(p1,p2,R,0) scale <1,1,2> }
      box{<x1,y1,z1>,<x2,y2,z2>}
      }
#end


/*******************************************************************************
 * old implementation follows.
 *******************************************************************************
 *
 *  ***********************************************************************
 *  //By John van Sickle
 *  //
 *  //    This macro creates a bar with four of its edges rounded. It fills the same
 *  //space as box { Startcorner,EndCorner }, except that the edges running along the
 *  //y-axis are rounded. StartCorner and EndCorner are opposite corners of the box,
 *  //and Radius is the radius of the rounded edges.
 *  //   The bar is made up of a prism object and four cylinder objects that run
 *  //parallel to the y-axis. If you want the bar to run along any other axis, you
 *  //will have to transform it just as you would any prism object. There is no merge
 *  //or union declared around them, to leave the choice up to the user; merge is
 *  //better for applications with transparency, union is better for others. Here is
 *  //an example of the macro's use:
 *  //
 *  //object {
 *  //  TOOLS_ROUNDED_BAR(<-10,0,0>,<10,40,20>,2)
 *  //  pigment { rgb .75 }
 *  //}
 *  //
 *  //Although the example code uses vector literals for StartCorner and EndCorner,
 *  //you can use any vector expression, and scalars will be promoted to full vectors.
 *  //
 *  //Modified by fbleikamp(replace with at)web.de for Eagle3D objects
 *  //
 *  ***********************************************************************
 *  
 *  #macro TOOLS_ROUNDED_BAR(v_SP,v_EP,R)
 *    #local vSP=(v_SP)*<1,1,1>;
 *    #local vEP=(v_EP)*<1,1,1>;
 *  #if (vSP.x > vEP.x)
 *    #local tSave=vSP.x;
 *    #local vSP=<vEP.x,vSP.y,vSP.z>;
 *    #local vEP=<tSave,vEP.y,vEP.z>;
 *  #end
 *  #if (vSP.y > vEP.y)
 *    #local tSave=vSP.y;
 *    #local vSP=<vSP.x,vEP.y,vSP.z>;
 *    #local vEP=<vEP.x,tSave,vEP.z>;
 *  #end
 *  #if (vSP.z > vEP.z)
 *    #local tSave=vSP.z;
 *    #local vSP=<vSP.x,vSP.y,vEP.z>;
 *    #local vEP=<vEP.x,vEP.y,tSave>;
 *  #end
 *  #union{
 *    box {<vSP.x+R,vSP.y,vSP.z>,<vEP.x-R,vEP.y,vEP.z>}
 *    box {<vSP.x,vSP.y+R,vSP.z>,<vEP.x,vEP.y-R,vEP.z>}
 *  
 *    cylinder { <vSP.x+R,vSP.y+R,vSP.z>,<vSP.x+R,vSP.y+R,vEP.z>,R }
 *    cylinder { <vEP.x-R,vSP.y+R,vSP.z>,<vEP.x-R,vSP.y+R,vEP.z>,R }
 *    cylinder { <vSP.x+R,vEP.y-R,vSP.z>,<vSP.x+R,vEP.y-R,vEP.z>,R }
 *    cylinder { <vEP.x-R,vEP.y-R,vSP.z>,<vEP.x-R,vEP.y-R,vEP.z>,R }
 *     }
 *  
 *  #end
 *
 *******************************************************************************
 * end old implementation
 ******************************************************************************/
