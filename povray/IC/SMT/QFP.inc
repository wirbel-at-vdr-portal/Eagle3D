/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Quad Flat Packages (QFP), square and rectangular.
 * For rectangular packages, check dimensions twice!
 *
 * written from scratch, replaces old e3d_qfp.inc
 * 04/2023-05/2023, wk
 ******************************************************************************/



/*******************************************************************************
 * LQFP
 ******************************************************************************/
#macro IC_SMT_LQFP80_040(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (11.80 + 12.20)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (11.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.40;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.13 +  0.23)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 20;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP100_040(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (13.80 + 14.20)/2; // Y, or, package length w. pins
  #local D1 = (11.80 + 12.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.80 + 14.20)/2; // X, or, package width w. pins
  #local E1 = (11.80 + 12.20)/2; // X, or, package width w/o. pins
  #local e  = 0.40;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = (0.157 + 0.167)/2; // pin width
  #local c  = (0.080 + 0.080)/2; // pin height
  #local nx = 25;                // number of pins in x axis
  #local ny = 25;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP128_040(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (15.80 + 16.20)/2; // X, or, package width w. pins
  #local E1 = (13.80 + 14.20)/2; // X, or, package width w/o. pins
  #local e  = 0.40;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = (0.180 + 0.180)/2; // pin width
  #local c  = (0.080 + 0.080)/2; // pin height
  #local nx = 32;                // number of pins in x axis
  #local ny = 32;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP256_040(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (29.80 + 30.20)/2; // Y, or, package length w. pins
  #local D1 = (27.80 + 28.20)/2; // Y, or, package length w/o. pins
  #local E  = (29.80 + 30.20)/2; // X, or, package width w. pins
  #local E1 = (27.80 + 28.20)/2; // X, or, package width w/o. pins
  #local e  = 0.40;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = (0.175 + 0.185)/2; // pin width
  #local c  = (0.135 + 0.145)/2; // pin height
  #local nx = 64;                // number of pins in x axis
  #local ny = 64;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP32_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = ( 6.80 +  7.20)/2; // Y, or, package length w. pins
  #local D1 = ( 4.80 +  5.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 6.80 +  7.20)/2; // X, or, package width w. pins
  #local E1 = ( 4.80 +  5.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 8;                 // number of pins in x axis
  #local ny = 8;                 // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP48_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = ( 8.80 +  9.20)/2; // Y, or, package length w. pins
  #local D1 = ( 6.80 +  7.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 8.80 +  9.20)/2; // X, or, package width w. pins
  #local E1 = ( 6.80 +  7.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 12;                // number of pins in x axis
  #local ny = 12;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP64_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (11.80 + 12.20)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (11.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 16;                // number of pins in x axis
  #local ny = 16;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP80_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (13.80 + 14.20)/2; // Y, or, package length w. pins
  #local D1 = (11.80 + 12.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.80 + 14.20)/2; // X, or, package width w. pins
  #local E1 = (11.80 + 12.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 20;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP100_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (15.80 + 16.20)/2; // X, or, package width w. pins
  #local E1 = (13.80 + 14.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 25;                // number of pins in x axis
  #local ny = 25;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP144_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (21.80 + 22.20)/2; // Y, or, package length w. pins
  #local D1 = (19.80 + 20.20)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 36;                // number of pins in x axis
  #local ny = 36;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP120_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (17.80 + 18.20)/2; // Y, or, package length w. pins
  #local D1 = (15.80 + 16.20)/2; // Y, or, package length w/o. pins
  #local E  = (17.80 + 18.20)/2; // X, or, package width w. pins
  #local E1 = (15.80 + 16.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = (0.115 + 0.195)/2; // pin height
  #local nx = 30;                // number of pins in x axis
  #local ny = 30;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP128_050_38x26(value)
  #local A  =  1.50;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 21.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 38;                // number of pins in x axis
  #local ny = 26;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP176_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (25.80 + 26.20)/2; // Y, or, package length w. pins
  #local D1 = (23.80 + 24.20)/2; // Y, or, package length w/o. pins
  #local E  = (25.80 + 26.20)/2; // X, or, package width w. pins
  #local E1 = (23.80 + 24.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 44;                // number of pins in x axis
  #local ny = 44;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP208_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (29.80 + 30.20)/2; // Y, or, package length w. pins
  #local D1 = (27.80 + 28.20)/2; // Y, or, package length w/o. pins
  #local E  = (29.80 + 30.20)/2; // X, or, package width w. pins
  #local E1 = (27.80 + 28.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 52;                // number of pins in x axis
  #local ny = 52;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP80_065(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (15.80 + 16.20)/2; // X, or, package width w. pins
  #local E1 = (13.80 + 14.20)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.22 +  0.38)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 20;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP112_065(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (21.80 + 22.20)/2; // Y, or, package length w. pins
  #local D1 = (19.80 + 20.20)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.27 +  0.37)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 28;                // number of pins in x axis
  #local ny = 28;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP32_080(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = ( 8.80 +  9.20)/2; // Y, or, package length w. pins
  #local D1 = ( 6.80 +  7.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 8.80 +  9.20)/2; // X, or, package width w. pins
  #local E1 = ( 6.80 +  7.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.30 +  0.40)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 8;                 // number of pins in x axis
  #local ny = 8;                 // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_LQFP44_080(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (12.00 + 12.40)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (12.00 + 12.40)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.30 +  0.40)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 11;                // number of pins in x axis
  #local ny = 11;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end


/*******************************************************************************
 * PQFP
 ******************************************************************************/
#macro IC_SMT_PQFP32_050(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = ( 6.80 +  7.20)/2; // Y, or, package length w. pins
  #local D1 = ( 4.80 +  5.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 6.80 +  7.20)/2; // X, or, package width w. pins
  #local E1 = ( 4.80 +  5.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 8;                 // number of pins in x axis
  #local ny = 8;                 // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP48_050(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = ( 8.80 +  9.20)/2; // Y, or, package length w. pins
  #local D1 = ( 6.80 +  7.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 8.80 +  9.20)/2; // X, or, package width w. pins
  #local E1 = ( 6.80 +  7.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 12;                // number of pins in x axis
  #local ny = 12;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP64_050(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (11.80 + 12.20)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (11.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 16;                // number of pins in x axis
  #local ny = 16;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP80_050(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (13.80 + 14.20)/2; // Y, or, package length w. pins
  #local D1 = (11.80 + 12.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = (11.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 20;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP100_050(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (15.80 + 16.20)/2; // X, or, package width w. pins
  #local E1 = (13.80 + 14.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 25;                // number of pins in x axis
  #local ny = 25;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP144_050(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (21.80 + 22.20)/2; // Y, or, package length w. pins
  #local D1 = (19.80 + 20.20)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 36;                // number of pins in x axis
  #local ny = 36;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP208_050(value)
  #local A  =  3.70;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 3.20 +  3.60)/2; // package height
  #local D  = (30.60 + 30.60)/2; // Y, or, package length w. pins
  #local D1 = (27.80 + 28.20)/2; // Y, or, package length w/o. pins
  #local E  = (30.60 + 30.60)/2; // X, or, package width w. pins
  #local E1 = (27.80 + 28.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.50 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 52;                // number of pins in x axis
  #local ny = 52;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP240_050(value)
  #local A  =  3.78;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 3.20 +  3.60)/2; // package height
  #local D  = (34.60 + 34.60)/2; // Y, or, package length w. pins
  #local D1 = (31.80 + 32.20)/2; // Y, or, package length w/o. pins
  #local E  = (34.60 + 34.60)/2; // X, or, package width w. pins
  #local E1 = (31.80 + 32.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.50 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 60;                // number of pins in x axis
  #local ny = 60;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP52_065(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.95 +  2.10)/2; // package height
  #local D  = (13.65 + 14.15)/2; // Y, or, package length w. pins
  #local D1 = ( 9.91 + 10.11)/2; // Y, or, package length w/o. pins
  #local E  = (13.65 + 14.15)/2; // X, or, package width w. pins
  #local E1 = ( 9.91 + 10.11)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.22 +  0.38)/2; // pin width
  #local c  = ( 0.13 +  0.23)/2; // pin height
  #local nx = 13;                // number of pins in x axis
  #local ny = 13;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP100_065(value)
  #local A  =  3.00;             // seated height
  #local A1 = ( 0.10 +  0.25)/2; // distance pcb to case
  #local A2 = ( 2.85 +  2.95)/2; // package height
  #local D  = (17.90 + 17.90)/2; // Y, or, package length w. pins
  #local D1 = (14.00 + 14.00)/2; // Y, or, package length w/o. pins
  #local E  = (23.90 + 23.90)/2; // X, or, package width w. pins
  #local E1 = (20.00 + 20.00)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.60 +  1.00)/2; // len pin on pad
  #local b  = ( 0.32 +  0.32)/2; // pin width
  #local c  = ( 0.17 +  0.17)/2; // pin height
  #local nx = 30;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP100_065_30x20(value)
  #local A  = ( 1.75 +  2.15)/2; // seated height
  #local A1 = ( 0.00 +  0.20)/2; // distance pcb to case
  #local A2 = ( 1.75 +  1.95)/2; // package height
  #local D  = (17.90 + 18.70)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (23.90 + 24.70)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 1.20 +  1.20)/2; // len pin on pad
  #local b  = ( 0.20 +  0.40)/2; // pin width
  #local c  = ( 0.10 +  0.20)/2; // pin height
  #local nx = 30;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP144_065(value)
  #local A  =  2.75;             // seated height
  #local A1 = ( 0.10 +  0.25)/2; // distance pcb to case
  #local A2 = ( 2.30 +  2.50)/2; // package height
  #local D  = (31.00 + 31.40)/2; // Y, or, package length w. pins
  #local D1 = (27.90 + 28.10)/2; // Y, or, package length w/o. pins
  #local E  = (31.00 + 31.40)/2; // X, or, package width w. pins
  #local E1 = (27.90 + 28.10)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.60 +  1.00)/2; // len pin on pad
  #local b  = ( 0.32 +  0.32)/2; // pin width
  #local c  = ( 0.17 +  0.17)/2; // pin height
  #local nx = 36;                // number of pins in x axis
  #local ny = 36;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP160_065(value)
  #local A  = 4.10;              // seated height
  #local A1 = ( 0.25 +  0.50)/2; // distance pcb to case
  #local A2 = ( 3.20 +  3.60)/2; // package height
  #local D  = (31.00 + 31.40)/2; // Y, or, package length w. pins
  #local D1 = (27.80 + 28.20)/2; // Y, or, package length w/o. pins
  #local E  = (31.00 + 31.40)/2; // X, or, package width w. pins
  #local E1 = (27.80 + 28.20)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.50 +  1.03)/2; // len pin on pad
  #local b  = ( 0.22 +  0.40)/2; // pin width
  #local c  = ( 0.09 +  0.23)/2; // pin height
  #local nx = 40;                // number of pins in x axis
  #local ny = 40;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP32_080(value)
  #local A  =  2.45;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.80 +  2.20)/2; // package height
  #local D  = ( 8.80 +  9.20)/2; // Y, or, package length w. pins
  #local D1 = ( 6.80 +  7.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 8.80 +  9.20)/2; // X, or, package width w. pins
  #local E1 = ( 6.80 +  7.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.73 +  1.03)/2; // len pin on pad
  #local b  = ( 0.30 +  0.40)/2; // pin width
  #local c  = ( 0.09 +  0.16)/2; // pin height
  #local nx = 8;                 // number of pins in x axis
  #local ny = 8;                 // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP44_080(value)
  #local A  =  2.45;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.80 +  2.20)/2; // package height
  #local D  = (13.65 + 14.15)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.65 + 14.15)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.73 +  1.03)/2; // len pin on pad
  #local b  = ( 0.30 +  0.45)/2; // pin width
  #local c  = ( 0.11 +  0.23)/2; // pin height
  #local nx = 11;                // number of pins in x axis
  #local ny = 11;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP80_080_24x16(value)
  #local A  =  3.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 2.57 +  2.87)/2; // package height
  #local D  = (17.60 + 18.20)/2; // Y, or, package length w. pins
  #local D1 = (13.90 + 14.10)/2; // Y, or, package length w/o. pins
  #local E  = (23.60 + 24.20)/2; // X, or, package width w. pins
  #local E1 = (19.90 + 20.10)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.60 +  1.00)/2; // len pin on pad
  #local b  = ( 0.30 +  0.45)/2; // pin width
  #local c  = ( 0.13 +  0.25)/2; // pin height
  #local nx = 24;                // number of pins in x axis
  #local ny = 16;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_PQFP64_100_14x20(value)
  #local A  =  3.35;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 3.15 +  3.25)/2; // package height
  #local D  = (18.50 + 18.90)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (24.50 + 24.90)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 1.00;              // pitch
  #local L  = ( 1.15 +  1.25)/2; // len pin on pad
  #local b  = ( 0.30 +  0.50)/2; // pin width
  #local c  = ( 0.10 +  0.20)/2; // pin height
  #local nx = 19;                // number of pins in x axis
  #local ny = 13;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end


/*******************************************************************************
 * TQFP
 ******************************************************************************/
#macro IC_SMT_TQFP100_040(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = (13.80 + 14.20)/2; // Y, or, package length w. pins
  #local D1 = (11.80 + 12.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.80 + 14.20)/2; // X, or, package width w. pins
  #local E1 = (11.80 + 12.20)/2; // X, or, package width w/o. pins
  #local e  = 0.40;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = (0.130 + 0.230)/2; // pin width
  #local c  =  (0.09 + 0.20)/2;  // pin height
  #local nx = 25;                // number of pins in x axis
  #local ny = 25;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP48_050(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = ( 8.80 +  9.20)/2; // Y, or, package length w. pins
  #local D1 = ( 6.80 +  7.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 8.80 +  9.20)/2; // X, or, package width w. pins
  #local E1 = ( 6.80 +  7.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 12;                // number of pins in x axis
  #local ny = 12;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP64_050(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = (11.80 + 12.20)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (11.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 16;                // number of pins in x axis
  #local ny = 16;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP80_050(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = (13.80 + 14.20)/2; // Y, or, package length w. pins
  #local D1 = (11.80 + 12.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = (11.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 20;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP100_050(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (15.80 + 16.20)/2; // X, or, package width w. pins
  #local E1 = (13.80 + 14.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 25;                // number of pins in x axis
  #local ny = 25;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP128_050(value)
  #local A  =  1.40;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.25 +  1.35)/2; // package height
  #local D  = (21.80 + 22.20)/2; // Y, or, package length w. pins
  #local D1 = (19.80 + 20.20)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 32;                // number of pins in x axis
  #local ny = 32;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP128_050_38x26(value)
  #local A  =  1.40;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.25 +  1.35)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.90 + 14.10)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 38;                // number of pins in x axis
  #local ny = 26;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP144_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (21.80 + 22.20)/2; // Y, or, package length w. pins
  #local D1 = (19.80 + 20.20)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 36;                // number of pins in x axis
  #local ny = 36;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP160_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (25.80 + 26.20)/2; // Y, or, package length w. pins
  #local D1 = (23.80 + 24.20)/2; // Y, or, package length w/o. pins
  #local E  = (25.80 + 26.20)/2; // X, or, package width w. pins
  #local E1 = (23.80 + 24.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 40;                // number of pins in x axis
  #local ny = 40;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP176_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (25.80 + 26.20)/2; // Y, or, package length w. pins
  #local D1 = (23.80 + 24.20)/2; // Y, or, package length w/o. pins
  #local E  = (25.80 + 26.20)/2; // X, or, package width w. pins
  #local E1 = (23.80 + 24.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 44;                // number of pins in x axis
  #local ny = 44;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP240_050(value)
  #local A  =  1.60;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (33.80 + 34.20)/2; // Y, or, package length w. pins
  #local D1 = (31.80 + 32.20)/2; // Y, or, package length w/o. pins
  #local E  = (33.80 + 34.20)/2; // X, or, package width w. pins
  #local E1 = (31.80 + 32.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 60;                // number of pins in x axis
  #local ny = 60;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP52_065(value)
  #local A  = ( 1.40 +  1.60)/2; // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (11.80 + 12.20)/2; // Y, or, package length w. pins
  #local D1 = ( 9.90 + 10.10)/2; // Y, or, package length w/o. pins
  #local E  = (11.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = ( 9.90 + 10.10)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 13;                // number of pins in x axis
  #local ny = 13;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP80_065(value)
  #local A  = ( 1.40 +  1.60)/2; // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (15.80 + 16.20)/2; // Y, or, package length w. pins
  #local D1 = (13.90 + 14.10)/2; // Y, or, package length w/o. pins
  #local E  = (15.80 + 16.20)/2; // X, or, package width w. pins
  #local E1 = (13.90 + 14.10)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 20;                // number of pins in x axis
  #local ny = 20;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP112_065(value)
  #local A  = ( 1.40 +  1.60)/2; // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.35 +  1.45)/2; // package height
  #local D  = (21.80 + 22.20)/2; // Y, or, package length w. pins
  #local D1 = (19.90 + 20.10)/2; // Y, or, package length w/o. pins
  #local E  = (21.80 + 22.20)/2; // X, or, package width w. pins
  #local E1 = (19.90 + 20.10)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 28;                // number of pins in x axis
  #local ny = 28;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP32_080(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = ( 8.80 +  9.20)/2; // Y, or, package length w. pins
  #local D1 = ( 6.80 +  7.20)/2; // Y, or, package length w/o. pins
  #local E  = ( 8.80 +  9.20)/2; // X, or, package width w. pins
  #local E1 = ( 6.80 +  7.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.30 +  0.45)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 8;                 // number of pins in x axis
  #local ny = 8;                 // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP44_080(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = (11.80 + 12.20)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (11.80 + 12.20)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.30 +  0.45)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 11;                // number of pins in x axis
  #local ny = 11;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_TQFP64_080(value)
  #local A  =  1.20;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 0.95 +  1.05)/2; // package height
  #local D  = (15.75 + 16.25)/2; // Y, or, package length w. pins
  #local D1 = (13.90 + 14.10)/2; // Y, or, package length w/o. pins
  #local E  = (15.75 + 16.25)/2; // X, or, package width w. pins
  #local E1 = (13.90 + 14.10)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.30 +  0.45)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 16;                // number of pins in x axis
  #local ny = 16;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

/*******************************************************************************
 * MQFP
 ******************************************************************************/
#macro IC_SMT_MQFP208_050(value)
  #local A  =  4.10;             // seated height
  #local A1 = ( 0.25 +  0.50)/2; // distance pcb to case
  #local A2 = ( 3.20 +  3.60)/2; // package height
  #local D  = (30.35 + 30.85)/2; // Y, or, package length w. pins
  #local D1 = (27.80 + 28.20)/2; // Y, or, package length w/o. pins
  #local E  = (30.35 + 30.85)/2; // X, or, package width w. pins
  #local E1 = (27.80 + 28.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 52;                // number of pins in x axis
  #local ny = 52;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_MQFP240_050(value)
  #local A  =  4.10;             // seated height
  #local A1 = ( 0.25 +  0.50)/2; // distance pcb to case
  #local A2 = ( 3.30 +  3.50)/2; // package height
  #local D  = (34.35 + 34.85)/2; // Y, or, package length w. pins
  #local D1 = (31.80 + 32.20)/2; // Y, or, package length w/o. pins
  #local E  = (34.35 + 34.85)/2; // X, or, package width w. pins
  #local E1 = (31.80 + 32.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 60;                // number of pins in x axis
  #local ny = 60;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_RQFP304_050(value)
  #local A  =  4.50;             // seated height
  #local A1 = ( 0.25 +  0.50)/2; // distance pcb to case
  #local A2 = ( 3.55 +  4.05)/2; // package height
  #local D  = (42.40 + 42.80)/2; // Y, or, package length w. pins
  #local D1 = (39.80 + 40.20)/2; // Y, or, package length w/o. pins
  #local E  = (42.40 + 42.80)/2; // X, or, package width w. pins
  #local E1 = (39.80 + 40.20)/2; // X, or, package width w/o. pins
  #local e  = 0.50;              // pitch
  #local L  = ( 0.45 +  0.75)/2; // len pin on pad
  #local b  = ( 0.17 +  0.27)/2; // pin width
  #local c  = ( 0.09 +  0.20)/2; // pin height
  #local nx = 76;                // number of pins in x axis
  #local ny = 76;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

#macro IC_SMT_MQFP52_065(value)
  #local A  =  2.45;             // seated height
  #local A1 = ( 0.10 +  0.25)/2; // distance pcb to case
  #local A2 = ( 1.95 +  2.10)/2; // package height
  #local D  = (13.65 + 14.15)/2; // Y, or, package length w. pins
  #local D1 = ( 9.80 + 10.20)/2; // Y, or, package length w/o. pins
  #local E  = (13.65 + 14.15)/2; // X, or, package width w. pins
  #local E1 = ( 9.80 + 10.20)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.73 +  1.03)/2; // len pin on pad
  #local b  = ( 0.22 +  0.38)/2; // pin width
  #local c  = ( 0.11 +  0.23)/2; // pin height
  #local nx = 13;                // number of pins in x axis
  #local ny = 13;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end


/*******************************************************************************
 * unusual QFPs
 ******************************************************************************/
#macro IC_SMT_PQFP67_080(value)
  #local A  =  2.30;             // seated height
  #local A1 = ( 0.05 +  0.15)/2; // distance pcb to case
  #local A2 = ( 1.95 +  2.10)/2; // package height
  #local D  = (17.70 + 20.50)/2; // Y, or, package length w. pins
  #local D1 = (13.80 + 14.20)/2; // Y, or, package length w/o. pins
  #local E  = (23.70 + 24.50)/2; // X, or, package width w. pins
  #local E1 = (19.80 + 20.20)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.15 +  1.55)/2; // len pin on pad
  #local b  = ( 0.20 +  0.40)/2; // pin width
  #local c  = ( 0.15 +  0.30)/2; // pin height
  #local nx = 23;                // number of pins in x axis
  #local ny = 13;                // number of pins in y axis
  difference {
     QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
     union {
        box { <+E1/2 ,-1,4.5*e> <+E/2+2 , A,+6.5*e> }
        box { <-E/2  ,-1,+D1/2> <-10.5*e, A,+D/2+1> }
        box { <-E/2  ,-1,-D1/2> <-10.5*e, A,-D/2-1> }
        box { <+E/2  ,-1,-D1/2> <+10.5*e, A,-D/2-1> }
        texture { col_ic_body_1 }
        }
     }
#end




/*******************************************************************************
 * versions rotated by +90 deg
 ******************************************************************************/
#macro IC_SMT_LQFP80_040_R90(value)        IC_SMT_LQFP80_040(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP256_040_R90(value)       IC_SMT_LQFP256_040(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP48_050_R90(value)        IC_SMT_LQFP48_050(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP64_050_R90(value)        IC_SMT_LQFP64_050(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP80_050_R90(value)        IC_SMT_LQFP80_050(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP100_050_R90(value)       IC_SMT_LQFP100_050(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP176_050_R90(value)       IC_SMT_LQFP176_050(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP208_050_R90(value)       IC_SMT_LQFP208_050(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP80_065_R90(value)        IC_SMT_LQFP80_065(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP32_080_R90(value)        IC_SMT_LQFP32_080(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP44_080_R90(value)        IC_SMT_LQFP44_080(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP32_050_R90(value)        IC_SMT_PQFP32_050(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP48_050_R90(value)        IC_SMT_PQFP48_050(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP64_050_R90(value)        IC_SMT_PQFP64_050(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP100_050_R90(value)       IC_SMT_PQFP100_050(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP144_050_R90(value)       IC_SMT_PQFP144_050(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP208_050_R90(value)       IC_SMT_PQFP208_050(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP240_050_R90(value)       IC_SMT_PQFP240_050(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP52_065_R90(value)        IC_SMT_PQFP52_065(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP100_065_30x20_R90(value) IC_SMT_PQFP100_065_30x20(value) rotate <0,90,0> #end
#macro IC_SMT_PQFP144_065_R90(value)       IC_SMT_PQFP144_065(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP160_065_R90(value)       IC_SMT_PQFP160_065(value)       rotate <0,90,0> #end
#macro IC_SMT_RQFP304_050_R90(value)       IC_SMT_RQFP304_050(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP32_080_R90(value)        IC_SMT_PQFP32_080(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP44_080_R90(value)        IC_SMT_PQFP44_080(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP100_040_R90(value)       IC_SMT_TQFP100_040(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP48_050_R90(value)        IC_SMT_TQFP48_050(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP64_050_R90(value)        IC_SMT_TQFP64_050(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP80_050_R90(value)        IC_SMT_TQFP80_050(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP100_050_R90(value)       IC_SMT_TQFP100_050(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP144_050_R90(value)       IC_SMT_TQFP144_050(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP160_050_R90(value)       IC_SMT_TQFP160_050(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP240_050_R90(value)       IC_SMT_TQFP240_050(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP80_065_R90(value)        IC_SMT_TQFP80_065(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP112_065_R90(value)       IC_SMT_TQFP112_065(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP32_080_R90(value)        IC_SMT_TQFP32_080(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP44_080_R90(value)        IC_SMT_TQFP44_080(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP64_080_R90(value)        IC_SMT_TQFP64_080(value)        rotate <0,90,0> #end
#macro IC_SMT_MQFP208_050_R90(value)       IC_SMT_MQFP208_050(value)       rotate <0,90,0> #end
#macro IC_SMT_MQFP240_050_R90(value)       IC_SMT_MQFP240_050(value)       rotate <0,90,0> #end
#macro IC_SMT_MQFP52_065_R90(value)        IC_SMT_MQFP52_065(value)        rotate <0,90,0> #end

/*******************************************************************************
 * versions translated by dX,dY
 ******************************************************************************/
#macro IC_SMT_PQFP80_080_24x16_T040(value) IC_SMT_PQFP80_080_24x16(value) translate < 0.40,0, 0.47> #end
#macro IC_SMT_TQFP128_050_T127(value)      IC_SMT_TQFP128_050(value)      translate < 1.27,0, 0.00> #end
#macro IC_SMT_MQFP52_065_T035(value)       IC_SMT_MQFP52_065(value)       translate < 0.35,0,-0.35> #end




/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
//:64-QFP-1420F=IC_SMT_PQFP64_100_14x20(:PQFP-64 14x20
//:EQFP144=IC_SMT_TQFP144_050_R90(:TQFP-144
//:FQFP208-2=IC_SMT_MQFP208_050_R90(:MQFP-208
//:HQ240=IC_SMT_PQFP240_050_R90(:PQFP-240
//:HTQFP-64-PAP=IC_SMT_TQFP64_050_R90(:TQFP-64
//:LQFP_ST-80-1=IC_SMT_LQFP80_050_R90(:LQFP-80
//:LQFP100=IC_SMT_LQFP100_050_R90(:LQFP-100
//:LQFP100_14X14=IC_SMT_LQFP100_050_R90(:LQFP-100
//:LQFP100-0.5-13.8X13.8MM=IC_SMT_TQFP100_050_R90(:TQFP-100
//:LQFP120=IC_SMT_LQFP120_050(:LQFP-120
//:LQFP144-0.5-20X20M=IC_SMT_LQFP144_050(:LQFP-144
//:LQFP160=IC_SMT_TQFP160_050_R90(:TQFP-160
//:LQFP208=IC_SMT_LQFP208_050_R90(:LQFP-208
//:LQFP-32=IC_SMT_LQFP32_050(:LQFP-32
//:LQFP32-7X7=IC_SMT_LQFP32_080_R90(:LQFP-32
//:LQFP32-7X7MM=IC_SMT_LQFP32_080_R90(:LQFP-32
//:LQFP44-10X10=IC_SMT_LQFP44_080_R90(:LQFP-44
//national-semiconductor:LQFP48=IC_SMT_LQFP48_050_R90(:LQFP-48 (national-semiconductor.lbr)
//:LQFP48=IC_SMT_LQFP48_050(:LQFP-48
//:LQFP48-0.5-7X7MM=IC_SMT_LQFP48_050_R90(:LQFP-48
//:LQFP48-7X7=IC_SMT_LQFP48_050_R90(:LQFP-48
//:LQFP-64=IC_SMT_LQFP64_050(:LQFP-64
//:LQFP64-0.5-10X10MM=IC_SMT_LQFP64_050_R90(:PQFP-64
//:LQFP80=IC_SMT_LQFP80_065(:LQFP-64
//:LQFP80-0.4-10X10MM=IC_SMT_LQFP80_040_R90(:LQFP-80
//:LQFP-ST-64-2=IC_SMT_LQFP64_050_R90(:LQFP-64
//:MLF44;MLF44-TH=IC_SMD_QFP44_050MM(:QFP44 Package 0.5mm pitch
//:MQFP100=IC_SMT_PQFP100_065_30x20(:PQFP-100
//:MQFP144=IC_SMT_PQFP144_065(:PQFP-144
//:MQFP144-RND=IC_SMT_PQFP144_065(:PQFP-144
//:MQFP44-2=IC_SMT_PQFP44_080(:PQFP-44
//:MQFP52=IC_SMT_MQFP52_065_R90(:MQFP-52
//:MQFP80-1=IC_SMT_LQFP80_065_R90(:LQFP-80
//:MQFP80-2=IC_SMT_PQFP80_080_24x16(:PQFP-80
//:PAP_S-PQFP-G64=IC_SMT_PQFP64_050_R90(:PQFP-64
//:PFB_S-PQFP-G48=IC_SMT_PQFP48_050_R90(:PQFP-48
//:PG-LQFP-176-2=IC_SMT_LQFP176_050_R90(:LQFP-208
//:P-LFQFP100-14X14=IC_SMT_LQFP100_050_R90(:LQFP-100
//:P-LFQFP48-7X7=IC_SMT_LQFP48_050_R90(:LQFP-48
//:P-LFQFP64-10X10=IC_SMT_LQFP64_050_R90(:LQFP-64
//:P-LFQFP80-12X12=IC_SMT_LQFP80_050_R90(:LQFP-80
//:P-LQFP-176-2=IC_SMT_TQFP176_050(:TQFP-176
//:PLQFP64-1=IC_SMT_LQFP64_050_R90(:LQFP-64
//:PMQFP64-2=IC_SMT_PQFP64_050_R90(:PQFP-64
//:PN_S-PQFP-G80=IC_SMT_PQFP80_050(:PQFP-80
//:PQ208=IC_SMT_PQFP208_050_R90(:PQFP-208
//:PQ240=IC_SMT_PQFP240_050_R90(:PQFP-240
//:PQFP_208=IC_SMT_MQFP208_050_R90(:MQFP-208
//:PQFP100=IC_SMT_PQFP100_065_30x20_R90(:PQFP-100
//texas:PQFP144=IC_SMT_PQFP144_050_R90(:PQFP-144 (texas.lbr)
//:PQFP144=IC_SMT_PQFP144_065_R90(:PQFP-144
//:PQFP144-28X28=IC_SMT_PQFP144_065(:PQFP-144
//:PQFP160=IC_SMT_PQFP160_065_R90(:PQFP-160
//:PQFP208=IC_SMT_MQFP208_050_R90(:MQFP-208
//:PQFP240=IC_SMT_MQFP240_050_R90(:MQFP-240
//:PQFP44=IC_SMT_PQFP44_080_R90(:PQFP-44
//:PQFP44=IC_SMT_PQFP44_080_R90(:PQFP-44
//:PQFP48=IC_SMT_PQFP48_050_R90(:PQFP-48
//:P-QFP48-7X7MM=IC_SMT_PQFP48_050_R90(:PQFP-48
//:PQFP52=IC_SMT_PQFP52_065_R90(:MQFP-52
//:PQFP80=IC_SMT_PQFP80_080_24x16(:PQFP-80
//:P-TQFP-128=IC_SMT_TQFP128_050_T127(:TQFP-128
//:P-TQFP144=IC_SMT_TQFP144_050_R90(:TQFP-144
//:P-TQFP-144-19=IC_SMT_TQFP144_050_R90(:TQFP-144
//:PZ_S-PQFP-G100=IC_SMT_PQFP100_050(:PQFP-100
//:QF100L-20X14=IC_SMT_PQFP100_065_30x20(:PQFP-100
//:QFP100=IC_SMT_PQFP100_065(:PQFP-100
//:QFP100R=IC_SMT_PQFP100_065_30x20(:PQFP-100
//:QFP-12X12-80E=IC_SMT_LQFP80_050(:LQFP-80
//:QFP160=IC_SMT_PQFP160_065_R90(:PQFP-160
//:QFP256-28X28=IC_SMT_LQFP256_040_R90(:LQFP-256
//:QFP32=IC_SMT_TQFP32_080_R90(:TQFP-32
//:QFP-32=IC_SMT_TQFP32_080(:TQFP-32
//:QFP3232-240CU=IC_SMT_TQFP240_050_R90(:TQFP-240
//:QFP44=IC_SMT_PQFP44_080(:PQFP-44
//:QFP44=IC_SMT_PQFP44_080_R90(:PQFP-44 (micro-intel)
//:QFP-44=IC_SMT_PQFP44_080(:PQFP-44
//:QFP44_SOT307-2=IC_SMT_TQFP44_080(:TQFP-44
//:QFP-52=IC_SMT_MQFP52_065_T035(:MQFP-52
//:QFP64=IC_SMT_PQFP64_100_14x20(:PQFP-64 14x20
//:QFP67-P-1420-0.80=IC_SMT_PQFP67_080(:PQFP67 with skipped pins
//:QFP-7X7-48=IC_SMT_LQFP48_050(:LQFP-48
//micro-philips:QFP80=IC_SMT_PQFP80_080_24x16_T040:PQFP-80 (micro-philips.lbr)
//:QFP80=IC_SMT_TQFP80_065_R90(:TQFP-80
//:QFP80-841=IC_SMT_LQFP80_065_R90(:LQFP-80
//:QFP80-C1=IC_SMT_PQFP80_080_24x16(:PQFP-80
//:RFP_S-PQFP-G144-EXP=IC_SMT_PQFP144_050_R90(:PQFP-144
//:RFP_S-PQFP-G144-EXPAD=IC_SMT_PQFP144_050_R90(:PQFP-144
//:RHB_S-PQFP-N32=IC_SMT_LQFP32_050_R90(:PQFP-32
//:RQFP208=IC_SMT_MQFP208_050_R90(:MQFP-208
//:RQFP240=IC_SMT_MQFP240_050_R90(:RQFP-240
//:RQFP304=IC_SMT_RQFP304_050_R90(:RQFP-304
//:S-PQFP-G48=IC_SMT_PQFP48_050_R90(:PQFP-48
//:SQFP-R-14X20-100=IC_SMT_PQFP100_065_30x20(:PQFP-100
//:SQFP-R-14X20-128=IC_SMT_LQFP128_050_38x26(:LQFP-128
//micro-cyrod:SQFP-S-10X10-44=IC_SMT_TQFP44_080(:TQFP-44 (micro-cyrod.lbr)
//xilinx-xc18v:SQFP-S-10X10-44=IC_SMT_TQFP44_080(:TQFP-44 (xilinx-xc18v.lbr)
//xilinx-xc9:SQFP-S-10X10-44=IC_SMT_TQFP44_080(:TQFP-44 (xilinx-xc9.lbr)
//:SQFP-S-10X10-44=IC_SMT_TQFP44_080_R90(:TQFP-44
//:SQFP-S-10X10-64=IC_SMT_LQFP64_050(:LQFP-64
//:SQFP-S-12X12-100=IC_SMT_LQFP100_040(:LQFP-100
//:SQFP-S-14X14-128=IC_SMT_LQFP128_040(:LQFP-128
//:SQFP-S-20X20-112=IC_SMT_LQFP112_065(:LQFP-112
//:SQFP-S-20X20-144=IC_SMT_TQFP144_050(:TQFP-144
//:TQ144=IC_SMT_TQFP144_050_R90(:TQFP-144
//maxim:TQFP100=IC_SMT_TQFP100_050(:TQFP-100 (maxim.lbr)
//micro-siemens:TQFP100=IC_SMT_TQFP100_050(:TQFP-100 (micro-siemens.lbr)
//:TQFP100=IC_SMT_TQFP100_050_R90(:TQFP-100
//:TQFP100-0.5-14X14MM=IC_SMT_TQFP100_050_R90(:TQFP-100
//:TQFP100-12X12=IC_SMT_TQFP100_040_R90(:TQFP-100
//microchip:TQFP100-14X14=IC_SMT_TQFP100_050(:TQFP-100 (microchip.lbr)
//:TQFP100-14X14=IC_SMT_TQFP100_050_R90(:TQFP-100
//:TQFP-10X10-52=IC_SMT_TQFP52_065(:TQFP-52
//:TQFP112=IC_SMT_TQFP112_065_R90(:TQFP-112
//:TQFP-12X12-80=IC_SMT_TQFP80_050(:TQFP-80
//:TQFP144=IC_SMT_TQFP144_050_R90(:TQFP-144
//:TQFP32=IC_SMT_TQFP32_080_R90(:TQFP-32
//:TQFP32-0.8-7X7MM=IC_SMT_TQFP32_080_R90(:TQFP-32
//:TQFP32-08=IC_SMT_TQFP32_080_R90(:TQFP-32
//:TQFP44=IC_SMT_TQFP44_080_R90(:TQFP-44
//:TQFP44-0.8-9.6X9.6MM=IC_SMT_TQFP44_080_R90(:TQFP-44
//:TQFP48=IC_SMT_TQFP48_050_R90(:TQFP-48
//:TQFP48_7X7=IC_SMT_TQFP48_050(:TQFP-48
//:TQFP52=IC_SMT_TQFP52_065(:TQFP-52
//plxtech:TQFP64=IC_SMT_TQFP64_080(:TQFP-64 (plxtech.lbr)
//:TQFP64=IC_SMT_TQFP64_080_R90(:TQFP-64
//:TQFP64-0.5-12X12MM=IC_SMT_TQFP64_050_R90(:TQFP-64
//:TQFP64-0.8-14X14MM=IC_SMT_TQFP64_080_R90(:TQFP-64
//:TQFP64-10X10=IC_SMT_TQFP64_050_R90(:TQFP-64
//:TQFP64-10X10X1MM=IC_SMT_TQFP64_050_R90(:TQFP-64
//:TQFP64L-10X10X2.0MM=IC_SMT_LQFP64_050_R90(:LQFP-64
//:TQFP80=IC_SMT_TQFP80_065_R90(:TQFP-80
//:TQFP80-12X12=IC_SMT_TQFP80_050_R90(:TQFP-80
//:VF_S-PQFP-G32=IC_SMT_PQFP32_080_R90(:PQFP-32
//:VQ100=IC_SMT_TQFP100_050_R90(:TQFP-100
//:VQFP32=IC_SMT_TQFP32_080_R90(:TQFP-32
//:VQFP64=IC_SMT_LQFP64_050_R90(:LQFP-64
// end assignment
