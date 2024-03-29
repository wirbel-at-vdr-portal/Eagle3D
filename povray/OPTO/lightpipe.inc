/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * light pipe from dialight
 * Philippe Boucheny <philippe.boucheny(at)numericable.fr>
 * Rev. 1.0  24/12/06
 *
 * THIS ONE LOOKS ODD, DONT ADD TO 3dpack.dat.
 ******************************************************************************/
#macro SPC_LIGHTPIPE_5151049F()
  #macro LPIPEFOOT()
     #local l1=0.8;

     intersection {
        merge {
            cylinder { <0,-2.1,0> <0,0.5,0> 0.97 }
            cone     { <0,-2.4,0>, 0.7,<0,-2.1,0> 0.97 }
            }
        box { <-l1,-2.5,-l1> <+l1,0.51,+l1> rotate 45*y }
        }
     #end

  #local Ray=9;
  #local Ray1=8.9;
  #local rr1=0.6;
  #local ff=1.7;
  #local x1=-1.5;

  merge {
     intersection {
        cylinder { <-4.13,2.62,0> <-21.2,2.62,0> 1.75 }
         sphere  { <0, 0, 0>, 5.3 translate<-6.28,2.62,0> }
        }
     difference {
        merge {
           intersection {
              cylinder{<0,5.14-Ray,-1.74><0,5.14-Ray,+1.74> Ray }
              box { <-4.13,0,-1.73> <0,5.14,1.73> }
              }
           cylinder { <-4.13,2.62,0> <-11.2,2.62,0> 1.75 }
           intersection {
              cylinder{<x1,5.14-Ray1,-1.74><x1,5.14-Ray1,+1.74> Ray}
              box{<-0.01,0,-1.73><4.89,5.14,1.73>}
              }
           }
        merge {
           cylinder{< ff,2.35-rr1,-1.74><ff,2.35-rr1,+1.74> rr1}
           box{<ff,-0.1,-1.74><5,2.35,+1.74>}
           box{<ff-rr1,-0.1,-1.74><2,2.35-rr1,+1.74>}
           }
        box{<-5.6,-1,-1><0,+1,+1> rotate<45,0,40> translate<-1,7.8,-1.73>}
        box{<-5.6,-1,-1><0,+1,+1> rotate<45,0,40> translate<-1,7.8,+1.73>}
        box{<-5,-0.1,-1.3><+5,0.2,+1.3>}
        }
     object { LPIPEFOOT() }
     object { LPIPEFOOT() translate -2.9*x }
        
     texture {
        pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
        finish  {
           ambient (0.6 * global_ambient_mul)
           diffuse 0.5
           reflection 0.7
           specular 0.8
           roughness 0.0003
           phong 0.3 
           phong_size 400
           }
        }
     rotate 180*y
     translate 3.76*x
     }
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
// end assignment
