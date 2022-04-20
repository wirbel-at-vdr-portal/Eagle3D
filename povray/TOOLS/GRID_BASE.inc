/*******************************************************************************
 * This macro repeats the povray object OBJ in a MxN grid with spacing GRID.
 * 20220418, wk
 ******************************************************************************/

#macro GRID_BASE(OBJ, GRID, M, N)
union {
   #for(X, 1, M)
       #for(Y, 1, N)
           object { OBJ translate<X*GRID,0,Y*GRID> }
       #end
   #end
   translate<-(1+M)/2*GRID,0,-(1+N)/2*GRID>
   }
#end
