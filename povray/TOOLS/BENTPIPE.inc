// TOOLS_BENTPIPE() depends on TOOLS_TORUS_SPLINE() :(
#include "TOOLS/TORUS_SPLINE.inc"

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
