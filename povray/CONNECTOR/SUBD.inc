/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Sub-D connectors
 * Andreas Fecht <info@vetter-und-fecht.de>
 * Duane Clark <dclark@akamail.com>
 * Wolfgang Moser <womo (a) d81.de>
 * Stefan Seegel
 *
 * completly rewritten: 05/2023, wk
 * *****************************************************************************/
#macro SUBD_BASE(pin, gender)
  #macro DSHELLD(ps, vc)
     union {
        // the dshell offset is (body size - dshell size)/2 + radius
        #local do = 8.33;    // dshell offset
        #local ds = 11.61;   // do + dshell size - ps - (radius*2)
        cylinder {
           <do,vc+3,4> <do,vc+3,0> 1
           }
        cylinder {
           <ds+ps,vc+3,4> <ds+ps,vc+3,0> 1
           }
        cylinder {
           <do+1,vc-3,4> <do+1,vc-3,0> 1
           }
        cylinder {
           <ds+ps-1,vc-3,4> <ds+ps-1,vc-3,0> 1
           }
        box {
           <do,vc+2,4> <ds+ps,vc+4,0>
           }
        box {
           <do+1,vc-2,4> <ds+ps-1,vc-4,0>
           }
        box {
           <0,vc+3,4> <1.5,vc-3,0>
           rotate <0,0,-9.62>
           translate <ds+ps-2.10,0,0>
           }
        box {
           <0,vc+3,4> <1.5,vc-3,0>
           rotate <0,0,9.62>
           translate <do+0.55,0,0>
           }
        }
  #end

  #macro DSHELL(ps, vc)
     union {
     // the dshell offset is (body size - dshell size)/2 + radius
     #local do = 8.33;    // dshell offset
     #local ds = 11.61;   // do + dshell size - ps - (radius*2)
     cylinder {
        <do,vc+3,0> <do,vc+3,-5.8> 1
        }
     cylinder {
        <ds+ps,vc+3,0> <ds+ps,vc+3,-5.8> 1
        }
     cylinder {
        <do+1,vc-3,0> <do+1,vc-3,-5.8> 1
        }
     cylinder {
        <ds+ps-1,vc-3,0> <ds+ps-1,vc-3,-5.8> 1
        }
     box {
        <do,vc+2,-0.5> <ds+ps,vc+4,-5.8>
        }
     box {
        <do+1,vc-2,-0.5> <ds+ps-1,vc-4,-5.8>
        }
     box {
        <0,vc+3,-0.5> <1.5,vc-3,-5.8>
        rotate <0,0,-9.62>
        translate <ds+ps-2.10,0,0>
        }
     box {
        <0,vc+3,-0.5> <1.5,vc-3,-5.8>
        rotate <0,0,9.62>
        translate <do+0.55,0,0>
        }
     }
  #end

  union {
     #local j = (pin-1)/2; // number of pins in bottom row
     #local hs = 2.758;    // horizontal pin spacing
     #local hc = 0;//9.525;    // horizontal centerline
     #local vs = 2.845;    // vertical pin spacing
     #local vc = 6.274;    // vertical centerline
     #local po = 9.97;     // offset to first pin
     #local ps = j*hs;     // total pin spacing
     #local bo = 20;       // body offset = body size - ps
     #local so = 3;        // screwlock offset from body sides

     #local A = 31.19;
     #switch(pin)
         #case (9)  #local A = 31.19; #break
         #case (15) #local A = 39.52; #break
         #case (25) #local A = 53.42; #break
         #case (37) #local A = 69.70; #break
     #end

     // the D shaped shell
     difference {
        object {
           DSHELLD(ps, vc)
           translate <-0.5,-0.25,0>
           scale <1.04-(0.0015*j),1.04,1>
           }
        object {
           DSHELLD(ps, vc)
           scale <1,1,1.1>
           }
        texture {
           col_silver
           }
        }
     difference {
        object {
           DSHELL(ps, vc)
           translate <-0.5,-0.25,0>
           scale <1.04-(0.0015*j),1.04,1>
           }
        object {
           DSHELL(ps, vc)
           scale <1,1,1.1>
           }
        texture {
           col_silver
           }
        }
     #if (gender = "female")
        // the plastic piece inside the female dshell
        union {
           object {
              DSHELLD(ps, vc)
              scale z*1.3
              translate <0,0,-0.6>
              }
           DSHELL(ps, vc)
           }
        // dshell sockets
        difference {
           box {
              <po-1,vc-4,-0.5> <po+ps+1,vc+4,-5.8>
              }
           #local PinHole = union {
               cylinder {
                  <0,vc,0.5> <0,vc,-5.5> 0.5
                  }
               sphere {
                  <0,vc,-5.5> 0.65
                  }
               texture {
                  col_gold
                  }
               };
           object {
              GRID(PinHole, hs, j+1,1)
              translate <A/2,+vs/2,0>
              }
           object {
              GRID(PinHole, hs, j,1)
              translate <A/2,-vs/2,0>
              }
           }
     #else // male
        object {
           DSHELLD(ps, vc)
           scale z*1.3
           translate <0,0,-0.6>
           }
        // dshell pins
        union {
           #local Pin = union {
               cylinder {
                  <0,vc,0.5> <0,vc,-5.3> 0.5
                  }
               sphere {
                  <0,vc,-5.3> 0.5
                  }
               texture {
                  col_gold
                  }
               };
           object {
              GRID(Pin, hs, j+1,1)
              translate <A/2,+vs/2,0>
              }
           object {
              GRID(Pin, hs, j,1)
              translate <A/2,-vs/2,0>
              }
           }
     #end

     box {
        <po-1.0,vc-4,0> <po+ps+1,vc+4,5.2>
        translate <0,0,-0.6>
        }

     // thin metal plate backing D shell
     difference {
        box {
           <0,1.5,0> <bo+ps,11,-0.5>
           texture {
              col_silver
              }
           }
        cylinder {
           <0,0,0> <0,0,-0.5> 1.5 open
           texture {
              col_silver
              }
           translate <so,vc,0>
           }
        cylinder {
           <0,0,0> <0,0,-0.5> 1.5 open
           texture {
              col_silver
              }
           translate <bo+ps-so,vc,0>
           }
        }
     box {
       <1.5,12.5,0> <bo+ps-1.5,10.5,-0.5>
       texture {
          col_silver
          }
       }
     cylinder {
       <bo+ps-1.5,11,0> <bo+ps-1.5,11,-0.5> 1.5
       texture {
          col_silver
          }
       }
     cylinder {
       <1.5,11,0> <1.5,11,-0.5> 1.5
       texture {
          col_silver
          }
       }
     box {
       <1.5,0,0> <bo+ps-1.5,1.5,-0.5>
       texture {
          col_silver
          }
       }
     cylinder {
       <bo+ps-1.5,1.5,0> <bo+ps-1.5,1.5,-0.5> 1.5
       texture {
          col_silver
          }
       }
     cylinder {
       <1.5,1.5,0> <1.5,1.5,-0.5> 1.5
       texture {
          col_silver
          }
       }
     translate <0-po-ps/2,-7.0,-1-hc>
     rotate <0,180,0>
       pigment {
       White * 0.1
       }
     }
#end


#macro SubD_wired(pins,gender)
  union {
     object {
        SUBD_BASE(pins, gender)
        }
     #local len = 7.3;     // Pin length (from plate)
     #local Dout = 1.4;    // Pin outer diameter
     #local Din = 1.2;     // Pin inner diameter
     #local hs = 2.758;    // horizontal pin spacing
     #local vs = 2.845;    // vertical pin spacing
     #local vc = 6.274;    // vertical centerline
     union {
        #local Pin1 = difference {
            cylinder {
               <0,vc,0.5> <0,vc,len> Dout/2
               }
            cylinder {
               <0,vc,0.5+0.1> <0,vc,len+0.1> Din/2
               }
            cylinder {
               <-1,vc+Dout/2,len-1.5> <+1,vc+Dout/2,len-1.5> Din/2
               }
            box {
               <-1,vc,len-1.5> <+1,vc+1,len+0.1>
               }
            texture {
               col_gold
               }
            };
        #local Pin2 = difference {
            cylinder {
               <0,vc,0.5> <0,vc,len> Dout/2
               }
            cylinder {
               <0,vc,0.5+0.1> <0,vc,len+0.1> Din/2
               }
            cylinder {
               <-1,vc-Dout/2,len-1.5> <+1,vc-Dout/2,len-1.5> Din/2
               }
            box {
               <-1,vc,len-1.5> <+1,vc-1,len+0.1>
               }
            texture {
               col_gold
               }
            };
        object {
           GRID(Pin1, hs, (pins-1)/2 + 1,1)
           translate <0,+vs/2,0>
           }
        object {
           GRID(Pin2, hs, (pins-1)/2,1)
           translate <0,-vs/2,0>
           }
        rotate <0,180,0>
        translate <0,-7.0,0>
        }
     }
#end

#macro SubD_vertical(pins,gender)
  union {
     object {
        SUBD_BASE(pins, gender)
        }
     #local len = 9.5;     // Pin length (from plate)
     #local D = 0.6;       // Pin diameter
     #local hs = 2.758;    // horizontal pin spacing
     #local vs = 2.845;    // vertical pin spacing
     #local vc = 6.274;    // vertical centerline
     union {
        #local Pin = union {
            cylinder {
               <0,vc,0.5> <0,vc,len-D/2> D/2
               }
            sphere {
               <0,vc,len-D/2> D/2
               }
            texture {
               col_gold
               }
            };
        object {
           GRID(Pin, hs, (pins-1)/2 + 1,1)
           translate <0,+vs/2,0>
           }
        object {
           GRID(Pin, hs, (pins-1)/2,1)
           translate <0,-vs/2,0>
           }
        rotate <0,180,0>
        translate <0,-7.0,0>
        }
     rotate <-90,180,0>
     translate <0,-1.0 + 7.4,+0.75>
     }
#end

#macro SubD_vertical_screw(pins,gender)
  union {
     object {
        SubD_vertical(pins, gender)
        }

     #local A = 31.19;
     #switch(pins)
         #case (9)  #local A = 31.19; #break
         #case (15) #local A = 39.52; #break
         #case (25) #local A = 53.42; #break
         #case (37) #local A = 69.70; #break
     #end

     #local mount = union {
         difference {
            cylinder {
               <0,0,0> <0,7.4,0> 4.5/2
               }
            object {
               TOOLS_SCREW(3,5,1,Silver)
               translate <0,10,0>
               }
            }
         object {
            TOOLS_SCREW(3,5,1,Silver)
            rotate <180,0,0>
            translate <0,-1.6,0>
            }
         texture {
            col_silver
            }
         };
     GRID(mount,A-2*3,2,1)
     }
#end

#macro SubD_vertical_clip(pins,gender)
  union {
     object {
        SubD_vertical(pins, gender)
        }

     #local A = 31.19;
     #switch(pins)
         #case (9)  #local A = 31.19; #break
         #case (15) #local A = 39.52; #break
         #case (25) #local A = 53.42; #break
         #case (37) #local A = 69.70; #break
     #end

     #local mount = difference {
         lathe {
            linear_spline
            9,
            < 0.00/2,-3.50>,
            < 2.90/2,-3.50>,
            < 3.50/2,-1.60>,
            < 2.90/2, 0.00>,
            < 4.50/2, 0.00>,
            < 4.50/2, 5.40>,
            < 5.50/2, 5.40>,
            < 5.50/2, 7.40>,
            < 0.00/2, 7.40>
            }
         box {
            <-3,-4.0,-0.6/2>
            <+3,+1.6,+0.6/2>
            }
         box {
            <-0.6/2,-4.0,-3>
            <+0.6/2,+1.6,+3>
            }

         object {
            TOOLS_SCREW(3,5,1,Silver)
            rotate <0,0,0>
            translate <0,8,0>
            }
         texture {
            col_silver
            }
         };
     GRID(mount,A-2*3,2,1)
     }
#end

#macro SubD_horizontal(pins,gender)
  union {
     object {
        SUBD_BASE(pins, gender)
        }
     #local len1 = 7.5;      // Pin length (from plate)
     #local len2 = 2.5;      // Pin length (from PCB)

     #local D1 = 1.0;      // Pin thick part
     #local D  = 0.6;      // Pin diameter
     #local hs = 2.758;    // horizontal pin spacing
     #local vs = 2.845;    // vertical pin spacing
     #local vc = 6.274;    // vertical centerline
     union {
        #local Pin1 = union {
            cylinder {
               <0,vc,0.5> <0,vc,len1> D1/2
               }
            cylinder {
               <0,-1.6,11.25> <0,len2,11.25> D1/2
               }
            cylinder {
               <0,-2.0,11.25> <0,-4.2,11.25> D/2
               }
            object {
               Segment_of_Torus(
                  4,
                  D1/2,
                  90
                  )
               rotate <0,-90,90>
               translate <0,2.30,7.25>
               }
            texture {
               col_gold
               }
            };


        #local Pin2 = union {
            cylinder {
               <0,vc,0.5> <0,vc,len1-0.40> D1/2
               }
            cylinder {
               <0,-1.6+2.84,11.25-2.84> <0,len2+2.24,11.25-2.84> D1/2
               }
            cylinder {
               <0,-2.0+2.84,11.25-2.84> <0,-4.2+2.84,11.25-2.84> D/2
               }
            object {
               Segment_of_Torus(
                  1.6,
                  D1/2,
                  90
                  )
               rotate <0,-90,90>
               translate <0,4.70,6.80>
               }
            texture {
               col_gold
               }
            };



        object {
           GRID(Pin1, hs, (pins-1)/2 + 1,1)
           translate <0,+vs/2,0>
           }
        object {
           GRID(Pin2, hs, (pins-1)/2,1)
           translate <0,-vs/2,0>
           }


        rotate <0,180,0>
        translate <0,-7.0,0>
        }
     translate <0,7.5,10>
     }
#end

#macro SubD_horizontal_screw(pins,gender)
  union {
     object {
        SubD_horizontal(pins, gender)
        }

     #local A = 31.19;
     #switch(pins)
         #case (9)  #local A = 31.19; #break
         #case (15) #local A = 39.52; #break
         #case (25) #local A = 53.42; #break
         #case (37) #local A = 69.70; #break
     #end

     #local mount = union {
         difference {
            union {
               Round_Box_Union(
                  <-6/2,0  ,-3.00>
                  <+6/2,1.5,+11.0>
                  0.25
                  )
               Round_Box_Union(
                  <-6/2,0 ,+9.50>
                  <+6/2,10,+11.0>
                  0.25
                  )
               }
            object {
               TOOLS_SCREW(3,5,1,Silver)
               rotate <90,0,0>
               translate <0,6.6,12>
               }

            }
         object {
            TOOLS_SCREW(3,5,1,Silver)
            rotate <180,0,0>
            translate <0,-1.6,0>
            }
         texture {
            col_silver
            }
         };
     GRID(mount,A-2*3,2,1)
     }
#end

#macro SubD_horizontal_clip(pins,gender)
  union {
     object {
        SubD_horizontal(pins, gender)
        }
     #local A = 31.19;
     #switch(pins)
         #case (9)  #local A = 31.19; #break
         #case (15) #local A = 39.52; #break
         #case (25) #local A = 53.42; #break
         #case (37) #local A = 69.70; #break
     #end

     #local mount = union {
         difference {
            union {
               Round_Box_Union(
                  <-6/2,0  ,-3.00>
                  <+6/2,1.5,+11.0>
                  0.25
                  )
               Round_Box_Union(
                  <-6/2,0 ,+9.50>
                  <+6/2,10,+11.0>
                  0.25
                  )
               }
            object {
               TOOLS_SCREW(3,5,1,Silver)
               rotate <90,0,0>
               translate <0,6.6,12>
               }
            }
         difference {
            lathe {
               linear_spline
               7,
               < 0.00/2,-3.50>,
               < 2.90/2,-3.50>,
               < 3.50/2,-1.60>,
               < 2.90/2, 0.00>,
               < 4.50/2, 0.00>,
               < 4.50/2, 4.00>,
               < 0.00/2, 4.00>
               }
            box {
               <-3,-4.0,-0.6/2>
               <+3,+1.6,+0.6/2>
               }
            box {
               <-0.6/2,-4.0,-3>
               <+0.6/2,+1.6,+3>
               }



            translate <0,-1.6,0>
            }
         texture {
            col_silver
            }
         };
     GRID(mount,A-2*3,2,1)
     }
#end

#macro CON_SUBD_F9D()    SubD_wired( 9, "female") #end
#macro CON_SUBD_F15D()   SubD_wired(15, "female") #end
#macro CON_SUBD_F25D()   SubD_wired(25, "female") #end
#macro CON_SUBD_F37D()   SubD_wired(37, "female") #end
#macro CON_SUBD_M9D()    SubD_wired(9,  "male"  ) #end
#macro CON_SUBD_M15D()   SubD_wired(15, "male"  ) #end
#macro CON_SUBD_M25D()   SubD_wired(25, "male"  ) #end
#macro CON_SUBD_M37D()   SubD_wired(37, "male"  ) #end

#macro CON_SUBD_F9V()    SubD_vertical_screw( 9, "female") #end
#macro CON_SUBD_F15V()   SubD_vertical_screw(15, "female") #end
#macro CON_SUBD_F25V()   SubD_vertical_screw(25, "female") #end
#macro CON_SUBD_F37V()   SubD_vertical_screw(37, "female") #end
#macro CON_SUBD_M9V()    SubD_vertical_screw(9,  "male"  ) #end
#macro CON_SUBD_M15V()   SubD_vertical_screw(15, "male"  ) #end
#macro CON_SUBD_M25V()   SubD_vertical_screw(25, "male"  ) #end
#macro CON_SUBD_M37V()   SubD_vertical_screw(37, "male"  ) #end

#macro CON_SUBD_F9VB()   SubD_vertical( 9, "female") #end
#macro CON_SUBD_F15VB()  SubD_vertical(15, "female") #end
#macro CON_SUBD_F25VB()  SubD_vertical(25, "female") #end
#macro CON_SUBD_F37VB()  SubD_vertical(37, "female") #end
#macro CON_SUBD_M9VB()   SubD_vertical(9,  "male"  ) #end
#macro CON_SUBD_M15VB()  SubD_vertical(15, "male"  ) #end
#macro CON_SUBD_M25VB()  SubD_vertical(25, "male"  ) #end
#macro CON_SUBD_M37VB()  SubD_vertical(37, "male"  ) #end

#macro CON_SUBD_F9VP()   SubD_vertical_clip( 9, "female") #end
#macro CON_SUBD_F15VP()  SubD_vertical_clip(15, "female") #end
#macro CON_SUBD_F25VP()  SubD_vertical_clip(25, "female") #end
#macro CON_SUBD_F37VP()  SubD_vertical_clip(37, "female") #end
#macro CON_SUBD_M9VP()   SubD_vertical_clip(9,  "male"  ) #end
#macro CON_SUBD_M15VP()  SubD_vertical_clip(15, "male"  ) #end
#macro CON_SUBD_M25VP()  SubD_vertical_clip(25, "male"  ) #end
#macro CON_SUBD_M37VP()  SubD_vertical_clip(37, "male"  ) #end

#macro CON_SUBD_F9H()    SubD_horizontal_screw( 9, "female") #end
#macro CON_SUBD_F15H()   SubD_horizontal_screw(15, "female") #end
#macro CON_SUBD_F25H()   SubD_horizontal_screw(25, "female") #end
#macro CON_SUBD_F37H()   SubD_horizontal_screw(37, "female") #end
#macro CON_SUBD_M9H()    SubD_horizontal_screw(9,  "male"  ) #end
#macro CON_SUBD_M15H()   SubD_horizontal_screw(15, "male"  ) #end
#macro CON_SUBD_M25H()   SubD_horizontal_screw(25, "male"  ) #end
#macro CON_SUBD_M37H()   SubD_horizontal_screw(37, "male"  ) #end


#macro CON_SUBD_F9HP()   SubD_horizontal_clip( 9, "female") #end
#macro CON_SUBD_F15HP()  SubD_horizontal_clip(15, "female") #end
#macro CON_SUBD_F25HP()  SubD_horizontal_clip(25, "female") #end
#macro CON_SUBD_F37HP()  SubD_horizontal_clip(37, "female") #end
#macro CON_SUBD_M9HP()   SubD_horizontal_clip(9,  "male"  ) #end
#macro CON_SUBD_M15HP()  SubD_horizontal_clip(15, "male"  ) #end
#macro CON_SUBD_M25HP()  SubD_horizontal_clip(25, "male"  ) #end
#macro CON_SUBD_M37HP()  SubD_horizontal_clip(37, "male"  ) #end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//con-subd:F09D=CON_SUBD_F9D(:Sub-D connector 9-pin female
//con-subd:F15D=CON_SUBD_F15D(:Sub-D connector 15-pin female
//con-subd:F25D=CON_SUBD_F25D(:Sub-D connector 25-pin female
//con-subd:F37D=CON_SUBD_F37D(:Sub-D connector 37-pin female
//con-subd:M09D=CON_SUBD_M9D(:Sub-D connector 9-pin male
//con-subd:M15D=CON_SUBD_M15D(:Sub-D connector 15-pin male
//con-subd:M25D=CON_SUBD_M25D(:Sub-D connector 25-pin male
//con-subd:M37D=CON_SUBD_M37D(:Sub-D connector 37-pin male
//con-subd:F09V=CON_SUBD_F9V(:Sub-D connector 9-pin female
//con-subd:F15V=CON_SUBD_F15V(:Sub-D connector 15-pin female
//con-subd:F25V=CON_SUBD_F25V(:Sub-D connector 25-pin female
//con-subd:F37V=CON_SUBD_F37V(:Sub-D connector 37-pin female
//con-subd:M09V=CON_SUBD_M9V(:Sub-D connector 9-pin male
//con-subd:M15V=CON_SUBD_M15V(:Sub-D connector 15-pin male
//con-subd:M25V=CON_SUBD_M25V(:Sub-D connector 25-pin male
//con-subd:M37V=CON_SUBD_M37V(:Sub-D connector 37-pin male
//con-subd:F09VB=CON_SUBD_F9VB(:Sub-D connector 9-pin female
//con-subd:F15VB=CON_SUBD_F15VB(:Sub-D connector 15-pin female
//con-subd:F25VB=CON_SUBD_F25VB(:Sub-D connector 25-pin female
//con-subd:F37VB=CON_SUBD_F37VB(:Sub-D connector 37-pin female
//con-subd:M09VB=CON_SUBD_M9VB(:Sub-D connector 9-pin male
//con-subd:M15VB=CON_SUBD_M15VB(:Sub-D connector 15-pin male
//con-subd:M25VB=CON_SUBD_M25VB(:Sub-D connector 25-pin male
//con-subd:M37VB=CON_SUBD_M37VB(:Sub-D connector 37-pin male
//con-subd:F09VP=CON_SUBD_F9VP(:Sub-D connector 9-pin female
//con-subd:F15VP=CON_SUBD_F15VP(:Sub-D connector 15-pin female
//con-subd:F25VP=CON_SUBD_F25VP(:Sub-D connector 25-pin female
//con-subd:F37VP=CON_SUBD_F37VP(:Sub-D connector 37-pin female
//con-subd:M09VP=CON_SUBD_M9VP(:Sub-D connector 9-pin male
//con-subd:M15VP=CON_SUBD_M15VP(:Sub-D connector 15-pin male
//con-subd:M25VP=CON_SUBD_M25VP(:Sub-D connector 25-pin male
//con-subd:M37VP=CON_SUBD_M37VP(:Sub-D connector 37-pin male
//con-subd:F09H=CON_SUBD_F9H(:Sub-D connector 9-pin weiblich:
//con-subd:F15H=CON_SUBD_F15H(:Sub-D connector 15-pin female
//con-subd:F25H=CON_SUBD_F25H(:Sub-D connector 25-pin female
//con-subd:F37H=CON_SUBD_F37H(:Sub-D connector 37-pin female
//con-subd:M09H=CON_SUBD_M9H(:Sub-D connector 9-pin male
//con-subd:M15H=CON_SUBD_M15H(:Sub-D connector 15-pin male
//con-subd:M25H=CON_SUBD_M25H(:Sub-D connector 25-pin male
//con-subd:M37H=CON_SUBD_M37H(:Sub-D connector 37-pin male
//con-subd:F09HP=CON_SUBD_F9HP(:Sub-D connector 9-pin female
//con-subd:F15HP=CON_SUBD_F15HP(:Sub-D connector 15-pin female
//con-subd:F25HP=CON_SUBD_F25HP(:Sub-D connector 25-pin female
//con-subd:F37HP=CON_SUBD_F37HP(:Sub-D connector 37-pin female
//con-subd:M09HP=CON_SUBD_M9HP(:Sub-D connector 9-pin male
//con-subd:M15HP=CON_SUBD_M15HP(:Sub-D connector 15-pin male
//con-subd:M25HP=CON_SUBD_M25HP(:Sub-D connector 25-pin male
//con-subd:M37HP=CON_SUBD_M37HP(:Sub-D connector 37-pin male
// end assignment
