/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/


/*******************************************************************************
 * Macros for Screw Washers :
 * Author: Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 - 04/01/06
 *
 * SCREWSIZE  : {2,2.5,3,4,5} for M2 M2.5 M3 M4 M5
 * WASHERTYPE : 0=Z, 1=M, 2=L, 3=LL
 * WASHERCOLOR: color
 ******************************************************************************/

#macro TOOLS_WASHER(SCREWSIZE,WASHERTYPE,WASHERCOLOR)
  #switch (SCREWSIZE)
     #case(2)
        #local AZ = 4;
        #local AM = 6;
        #local AL = 8;
        #local ALL = 10;
        #local C = 0.6;
        #local B = 2.25;
        #break

     #case(2.5)
        #local AZ = 5;
        #local AM = 7;
        #local AL = 9;
        #local ALL = 11;
        #local C = 0.7;
        #local B = 2.75;
        #break

     #case(3)
        #local AZ = 6;
        #local AM = 8;
        #local AL = 12;
        #local ALL = 14;
        #local C = 0.8;
        #local B = 3.25;
        #break

     #case(4)
        #local AZ = 8;
        #local AM = 10;
        #local AL = 14;
        #local ALL = 16;
        #local C = 0.8;
        #local B = 4.25;
        #break

     #case(5)
        #local AZ = 10;
        #local AM = 12;
        #local AL = 16;
        #local ALL = 20;
        #local C = 1;
        #local B = 5.25;
        #break
  #end

  #switch (WASHERTYPE)
     #case(0)
        // WASHERTYPE Z
        #local A=AZ;
        #break

     #case(1)
        // WASHERTYPE M
        #local A=AM;
        #break

     #case(2)
        // WASHERTYPE L
        #local A=AL;
        #break

     #case(3)
        // WASHERTYPE LL
        #local A=ALL;
        #break
  #end

  difference {
     cylinder {<0,0,0>, <0,C,0>, A/2}
     cylinder {<0,-0.1,0>, <0,C+0.1,0>, B/2}
     pigment{WASHERCOLOR}
     }

  #end
