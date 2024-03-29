/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


// TOOLS_BENTPIPE() depends on TOOLS_TORUS_SPLINE() :(
/*******************************************************************************
 * Creates a smooth spline of toruses connecting a sequence of points.
 * Author: Ron Parker
 *
 * TorRadius : the minor radius of the toruses to be used
 *             in creating the spline.
 * Points    : array of points through which the spline should pass.
 * StartVect : the direction vector to be used at the start of the spline.
 *             Varying this vector can have surprising results on the resulting
 *             object.  If the spline should leave another object at a specific
 *             angle, as with a lamp cord or rope, use this vector to show the
 *             angle.  If it is zero, The first torus will be calculated to
 *             pass through the first three points.  This is usually what you
 *             want, but you can get some neat effects if you override the
 *             default.
 *
 * To use it, use code like the following:
 * 
 * #declare Pts=array[5]{<0,0,0>, <1,1,1>, <-.5,1,2>, <.5,1,3>, <0,1,4>}
 * object {
 *   TOOLS_TORUS_SPLINE( .1, Pts, <1,0,.5> )
 *   texture {...}
 *   }
 * 
 * Achtung!!! Axis in MyAxis umbenannt, konflikt mit macro-name in special.inc
 *            <fbleikamp(replace with at)web.de>
 * Fehler in Verbindung mit bentpipe.mcr abgefangen bei vcross((B-A),V) = 0 und
 * den daraus folgenden Fehlern.
 ******************************************************************************/

#macro TOOLS_TORUS_SPLINE( TorRadius, Points, StartVect )
  union {
     // promote the start vector to a vector, even if they gave us a scalar (e.g. 0)
     #local V=<0,0,0>+StartVect;
     #local Numpoints = dimension_size( Points, 1 );
     #local Cur = 0;

     #while (Cur < Numpoints-1 )
        #local A=Points[Cur];
        #local B=Points[Cur+1];

        #if (V.x=0&V.y=0&V.z=0)
           #local C=Points[Cur+2];
           #if (vlength(vcross(C-A,B-A)) = 0)
              #local V=B-A;
              #local Cos=0;
              #local MyAxis=<0,0,0>;
           #else
              #local MyAxis=vnormalize(vcross((C-A),(B-A)));
              #local Base1=vnormalize(C-A);
              #local Base2=vnormalize(vcross(MyAxis,Base1));
              #local VB=<0.5*vlength(C-A),0,0>;
              #local VA=vcross(VB,z);
              #local VD=.5*<vdot(B-A,Base1),vdot(B-A,Base2),0>;
              #local VC=vcross(VD,z);
              #local Beta=((VD-VB).y*VA.x-(VD-VB).x*VA.y)/(VC.x*VA.y-VC.y*VA.x);
              #local Center=A+VD.x*Base1+VD.y*Base2+Beta*(VC.x*Base1+VC.y*Base2);
              #local Radius=vlength(Center-A);
              #local Cos=1;
              #local V=vcross( MyAxis,Center-A );
           #end
           #local B=C;
           #local Cur=Cur+1;
        #else
           #local C=vcross((B-A),V);  // fbleikamp(replace with at)web.de
           #if ( C.x!=0|C.y!=0|C.z!=0)
              #local MyAxis=vnormalize(vcross((B-A),V));
              #local Dir=vnormalize(vcross(V, MyAxis ));
              #local Cos=vdot(vnormalize(B-A), Dir);
              #local Radius=abs(.5*vlength(B-A)/Cos);
              #local Center=A+Radius*Dir;
           #else
              #local MyAxis=<0,0,0>;
              #local Center=A;
              #local Cos=0;
           #end
        #end

        #local V1=V;

        #if ( Cos & (MyAxis.x!=0|MyAxis.y!=0|MyAxis.z!=0))
            #if (MyAxis.y = 0 & vlength(<MyAxis.x,0,MyAxis.z>) = 0)
                #local RZ=0;
            #else
                #local RZ=-degrees(atan2(vlength(<MyAxis.x,0,MyAxis.z>), MyAxis.y));
            #end

            #if (MyAxis.z = 0 & MyAxis.x = 0 )
                #local RY=0;
            #else
                #local RY=-degrees(atan2(MyAxis.z, MyAxis.x));
            #end

            #local V1=vcross(B-Center, MyAxis);

            #if ( vdot(vcross(V,A-Center),vcross(V, V1))>0 )
                #local Planes =  union {
                    plane{-V, vdot( A-.0001*TorRadius*V, vnormalize(-V) ) }
                    plane{V1, vdot( .0001*TorRadius*V1+B, vnormalize(V1))}
                    }
            #else
                #local Planes =  intersection {
                    plane{-V, vdot( A-.0001*TorRadius*V, vnormalize(-V) ) }
                    plane{V1, vdot( .0001*TorRadius*V1+B, vnormalize(V1))}
                    }
            #end

            intersection {
               object {Planes}
               torus{ Radius, TorRadius rotate RZ*z rotate RY*y translate Center }
               }
        #else
           cylinder {A-.0001*TorRadius*V, B+.0001*TorRadius*V, TorRadius}
        #end
        #declare Cur=Cur+1;
        #declare V=V1;
    #end
  }
#end

/*******************************************************************************
 * This macro allows you to specify a TorusSpline as a series of "turtle-like"
 * moves rather than as a series of points.
 * You tell it to start at a particular position and orientation and give it
 * a series of commands (go straight x units, turn left/right x degrees with
 * radius r) and a radius for the pipe and it creates the specified pipe.
 * It does assume you are operating in the X-Y plane.
 *
 * Author: Ron Parker
 *
 * Sample usage:
 * #declare bends=array[6] {
 *    // <angle, radius, 0> or <0, distance, 0> for straight pipe
 *    // negative angles bend left, positive bend right.
 *    <0, 10, 0>,  <-45, 5, 0>,  <225,5,0>,  <-225,5,0>,  <45, 5, 0>,  <0, 10, 0>
 *    }
 * object {
 *    // this pipe has a radius of 1, starts at the origin, and initially goes in the x direction
 *    TOOLS_BENTPIPE( 1, <0,0,0>, x, bends )
 *    texture {pigment {color rgb 1}}
 *    }
*******************************************************************************/

#macro TOOLS_BENTPIPE(PipeRadius, Loc, Dir, Bends)
  #local Pts=array[dimension_size( Bends, 1 )+1]
  #local Pts[0] = <0,0,0>+Loc;
  #local StartDir = <0,0,0>+Dir;
  #local Cur = 0;

  #while ( Cur < dimension_size( Bends, 1 ) )
      #if (Bends[Cur].u = 0 )
          #local Pts[Cur+1] = Pts[Cur]+Bends[Cur].v*vnormalize(Dir);
      #else
          #local Offset = Bends[Cur].v * vnormalize(vcross( Dir, -Bends[Cur].u*z ));
          #local Pts[Cur+1]=Pts[Cur]-Offset+vrotate(Offset, -Bends[Cur].u*z);
          #local Dir = vrotate( Dir, -Bends[Cur].u*z );
      #end
      #local Cur=Cur+1;
  #end

  TOOLS_TORUS_SPLINE( PipeRadius, Pts, StartDir )
#end
