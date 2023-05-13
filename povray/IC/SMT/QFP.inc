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


/*******************************************************************************
 * PQFP
 ******************************************************************************/
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
  #local A  = 4.07;              // seated height
  #local A1 = ( 0.25 +  0.50)/2; // distance pcb to case
  #local A2 = ( 3.17 +  3.67)/2; // package height
  #local D  = (30.95 + 31.45)/2; // Y, or, package length w. pins
  #local D1 = (27.90 + 28.10)/2; // Y, or, package length w/o. pins
  #local E  = (30.95 + 31.45)/2; // X, or, package width w. pins
  #local E1 = (27.90 + 28.10)/2; // X, or, package width w/o. pins
  #local e  = 0.65;              // pitch
  #local L  = ( 0.65 +  0.95)/2; // len pin on pad
  #local b  = ( 0.22 +  0.38)/2; // pin width
  #local c  = ( 0.13 +  0.23)/2; // pin height
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

#macro IC_SMT_PQFP128_080_24x16(value)
  #local A  = 3.04;             // seated height
  #local A1 = ( 0.18 +  0.28)/2; // distance pcb to case
  #local A2 = ( 2.66 +  2.76)/2; // package height
  #local D  = (17.70 + 18.10)/2; // Y, or, package length w. pins
  #local D1 = (13.95 + 14.05)/2; // Y, or, package length w/o. pins
  #local E  = (23.70 + 24.10)/2; // X, or, package width w. pins
  #local E1 = (19.95 + 20.05)/2; // X, or, package width w/o. pins
  #local e  = 0.80;              // pitch
  #local L  = ( 0.80 +  1.00)/2; // len pin on pad
  #local b  = ( 0.22 +  0.38)/2; // pin width
  #local c  = ( 0.13 +  0.23)/2; // pin height
  #local nx = 24;                // number of pins in x axis
  #local ny = 16;                // number of pins in y axis

  QFP_BASE(A,A1,A2,D,D1,E,E1,e,L,b,c,nx,ny,value)
#end

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

#macro IC_SMT_MQFP44_080(value)
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

#macro IC_SMT_PQFP64_100(value)
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

#macro IC_SMT_TQFP128_050_30x20(value)
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
 * versions rotated by +90 deg
 ******************************************************************************/
#macro IC_SMT_LQFP256_040_R90(value)       IC_SMT_LQFP256_040(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP64_050_R90(value)        IC_SMT_LQFP64_050(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP80_050_R90(value)        IC_SMT_LQFP80_050(value)        rotate <0,90,0> #end
#macro IC_SMT_LQFP100_050_R90(value)       IC_SMT_LQFP100_050(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP176_050_R90(value)       IC_SMT_LQFP176_050(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP208_050_R90(value)       IC_SMT_LQFP208_050(value)       rotate <0,90,0> #end
#macro IC_SMT_LQFP32_080_R90(value)        IC_SMT_LQFP32_080(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP52_065_R90(value)        IC_SMT_PQFP52_065(value)        rotate <0,90,0> #end
#macro IC_SMT_PQFP100_065_30x20_R90(value) IC_SMT_PQFP100_065_30x20(value) rotate <0,90,0> #end
#macro IC_SMT_PQFP144_065_R90(value)       IC_SMT_PQFP144_065(value)       rotate <0,90,0> #end
#macro IC_SMT_PQFP160_065_R90(value)       IC_SMT_PQFP160_065(value)       rotate <0,90,0> #end
#macro IC_SMT_MQFP208_050_R90(value)       IC_SMT_MQFP208_050(value)       rotate <0,90,0> #end
#macro IC_SMT_MQFP240_050_R90(value)       IC_SMT_MQFP240_050(value)       rotate <0,90,0> #end
#macro IC_SMT_RQFP304_050_R90(value)       IC_SMT_RQFP304_050(value)       rotate <0,90,0> #end
#macro IC_SMT_MQFP52_065_R90(value)        IC_SMT_MQFP52_065(value)        rotate <0,90,0> #end
#macro IC_SMT_MQFP44_080_R90(value)        IC_SMT_MQFP44_080(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP48_050_R90(value)        IC_SMT_TQFP48_050(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP100_050_R90(value)       IC_SMT_TQFP100_050(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP144_050_R90(value)       IC_SMT_TQFP144_050(value)       rotate <0,90,0> #end
#macro IC_SMT_TQFP80_065_R90(value)        IC_SMT_TQFP80_065(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP32_080_R90(value)        IC_SMT_TQFP32_080(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP44_080_R90(value)        IC_SMT_TQFP44_080(value)        rotate <0,90,0> #end
#macro IC_SMT_TQFP64_080_R90(value)        IC_SMT_TQFP64_080(value)        rotate <0,90,0> #end


/*******************************************************************************
 * versions translated by dX,dY
 ******************************************************************************/
#macro IC_SMT_MQFP52_065_T035(value)   IC_SMT_MQFP52_065(value)   translate <0.35,0,-0.35> #end
