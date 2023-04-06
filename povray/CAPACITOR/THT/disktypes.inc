/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Disk style capacitors
 * David Harris
 *  diam1      = diam of the main circumference
 *  value      = text on the cap
 *  leadspc    = lead spacing
 *  bcolour    = body colour
 *  tcolour    = text colour
 ******************************************************************************/
#macro CAP_DIS_CERAMIC_DISK_BASE(diam1, value, leadspc, bcolour, tcolour)
  #local diam = diam1/2;
  #local cap = object {superellipsoid{ <1, 1>scale<diam,diam*0.25,diam>rotate <-90,-7.5,0>translate<0,diam*1.1,0> } }
  #local txt = text{ ttf besch_font ,value,40,0 scale<diam/3,diam/3,diam/3> translate<-diam/1.5,diam,-20> }
  #local leg = object{ cylinder {  <0,diam*0.2,0>,<0,-10.0>,0.25 texture{col_silver}}}
  #local ls2 = leadspc/2;
  union {
     object{ intersection{ object{txt} object{cap} } translate <0,0,-0.05> pigment{tcolour} }
     object {cap pigment{bcolour}}
     difference {
        torus { leadspc/2, 0.25 rotate -90*x  pigment{bcolour} }
        box { <-leadspc,0,0.5>, <leadspc,-leadspc,-0.5> }
        translate <0,diam*0.2,0>
        }
     object{ leg translate<-ls2,0,0> }
     object{ leg translate< ls2,0,0> }
     translate <0,0,0>
     pigment{bcolour}
     }
#end


#macro CAP_DIS_CERAMIC_DISK_64MM_50MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(5.0, value, 6.35, Brown, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_64MM_65MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(6.5, value, 6.35, Red, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_64MM_74MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(7.37, value, 6.35, Orange, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_64MM_100MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(10.01, value, 6.35, Yellow, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_64MM_120MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(11.99, value, 6.35, Green, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_05MM_06MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(6, value, 5.08, Brown, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_05MM_08MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(8, value, 5.08, Red, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_05MM_10MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(10, value, 5.08, Orange, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_05MM_13MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(13, value, 5.08, Yellow, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_10MM_13MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(13.5, value, 10.16, Green, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_10MM_18MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(18, value, 10.16, Blue, Black)
#end

#macro CAP_DIS_CERAMIC_DISK_10MM_25MM(value)
  CAP_DIS_CERAMIC_DISK_BASE(25, value, 10.16, Gray, Blue)
#end



/*******************************************************************************
 * Ceramic capacitors
 * David Harris
 *  diam1      = diam of the main circumference
 *  value      = text on the cap
 *  leadspc    = lead spacing
 *  bcolour    = body colour
 *  tcolour    = text colour
 ******************************************************************************/
#macro CAP_DIS_CERAMIC_BASE(diam1,value,leadspc,bcolour,tcolour)
  #local diam = diam1/2;
  #local cap = object {
     superellipsoid {
        <1, 1>
        scale <diam, diam*0.25 ,diam>
        rotate <-90,-7.5,0>
        translate<0,diam*1.1,0>
        }
     }

  #local txt = text {
     ttf besch_font, value, 40, 0
     scale <diam/3,diam/3,diam/3>
     translate<-diam/1.5,diam,-20>
     }

  #local leg = object {
     cylinder {
        <0,diam*0.2,0>, <0,-10.0>, 0.25
        texture { col_silver }
        }
     }

  #local ls2 = leadspc/2;

  union { 
     object {
        intersection {
           object { txt }
           object { cap }
           }
        translate <0,0,-0.05> pigment{tcolour}
        }

     object { cap pigment { bcolour } }
     difference {
        torus { leadspc/2, 0.25 rotate -90*x  pigment{bcolour} }
        box { <-leadspc,0,0.5>, <leadspc,-leadspc,-0.5> }
        translate <0,diam*0.2,0>  
        }
     object { leg translate<-ls2,0,0> }
     object { leg translate< ls2,0,0> }
     pigment { bcolour }
     translate <0,0,0> 
     }
#end


#macro CAP_DIS_CERAMIC_25MM_38MM(value)
  CAP_DIS_CERAMIC_BASE(3.81,value,2.54,Red,Black)
#end

#macro CAP_DIS_CERAMIC_25MM_44MM(value)
  CAP_DIS_CERAMIC_BASE(4.4,value,2.54,Red,Black)
#end

#macro CAP_DIS_CERAMIC_25MM_50MM(value)
  CAP_DIS_CERAMIC_BASE(5.08,value,2.54,Yellow,Black)
#end

#macro CAP_DIS_CERAMIC_50MM_38MM(value)
  CAP_DIS_CERAMIC_BASE(3.81,value,5.08,Orange,Black)
#end

#macro CAP_DIS_CERAMIC_50MM_44MM(value)
  CAP_DIS_CERAMIC_BASE(4.40,value,5.08,Red,Black)
#end

#macro CAP_DIS_CERAMIC_50MM_50MM(value)
  CAP_DIS_CERAMIC_BASE(5.08,value,5.08,Blue,Black)
#end

#macro CAP_DIS_CERAMIC_50MM_76MM(value)
  CAP_DIS_CERAMIC_BASE(7.62,value,5.08,Yellow,Black)
#end

#macro CAP_DIS_CERAMIC_50MM_100MM(value)
  CAP_DIS_CERAMIC_BASE(10.16,value,5.08,Gray,Black) 
#end

#macro CAP_DIS_CERAMIC_75MM_100MM(value)
  CAP_DIS_CERAMIC_BASE(10.16,value,7.62,Gray,Black)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=CAP_DIS_CERAMIC_DISK_64MM_50MM(:ceramic disc cap 6.4mm spacing 5mm diam
//=CAP_DIS_CERAMIC_DISK_64MM_65MM(:ceramic disc cap 6.4mm spacing 6.5mm diam
//=CAP_DIS_CERAMIC_DISK_64MM_74MM(:ceramic disc cap 6.4mm spacing 7.4mm diam
//=CAP_DIS_CERAMIC_DISK_64MM_100MM(:ceramic disc cap 6.4mm spacing 10mm diam
//=CAP_DIS_CERAMIC_DISK_64MM_120MM(:ceramic disc cap 6.4mm spacing 12mm diam
//=CAP_DIS_CERAMIC_DISK_05MM_06MM(:ceramic disc cap 5mm spacing 6mm diam
//=CAP_DIS_CERAMIC_DISK_05MM_08MM(:ceramic disc cap 5mm spacing 8mm diam
//=CAP_DIS_CERAMIC_DISK_05MM_10MM(:ceramic disc cap 5mm spacing 10mm diam
//=CAP_DIS_CERAMIC_DISK_05MM_13MM(:ceramic disc cap 5mm spacing 13mm diam
//=CAP_DIS_CERAMIC_DISK_10MM_13MM(:ceramic disc cap 10mm spacing 13mm diam
//=CAP_DIS_CERAMIC_DISK_10MM_18MM(:ceramic disc cap 10mm spacing 18mm diam
//=CAP_DIS_CERAMIC_DISK_10MM_25MM(:ceramic disc cap 10mm spacing 25mm diam
// end assignment
