#version 3.5;
global_settings{charset utf8}

#declare global_res_shape = 1;                              //changes the apperance of resistors (1 Blob / 0 real)
#declare global_res_colselect = 0;                          //randomize color of resistors 1=random 0=same color
#declare global_res_col = 1;                                //Number of the color for the resistors 0=Green, 1="normal color" 2=Blue 3=Brown
#declare pin_length = 2.5;                                  //Set the length off short pins over the PCB
#declare global_diode_bend_radius = 1;
#declare global_res_bend_radius = 1;
#declare global_solder = on;
#declare global_show_screws = on;
#declare global_show_washers = on;
#declare global_show_nuts = on;
#declare global_use_radiosity = on;
#declare global_ambient_mul = 1;
#declare global_ambient_mul_emit = 0;
#declare global_fast_mode = off;
#declare col_preset = 2;
#declare pin_short = on;

//Do not change these values
#declare pcb_height = 1.5;
#declare pcb_cuheight = 0.035;
#declare pcb_x_size = 100;
#declare pcb_y_size = 80;
#declare pcb_layer1_used = 1;
#declare pcb_layer16_used = 1;
#declare inc_testmode = off;
#declare global_seed=seed(521);
#declare global_pcb_layer_dis = array[16] {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.535, }
#declare global_pcb_real_hole = 2.000000;

#include "Eagle3D_main.inc"

camera {
  #local cam_loc = <0,325,-122>;
  #local cam_a = 20;
  #local cam_look_at = <0,-5,0>;

  location cam_loc
  look_at  cam_look_at
  angle    cam_a
	//versetzt die Kamera, sodass <0,0,0> über dem Eagle-Nullpunkt ist
	//translate<-50.800000,0,-26.670000>
  }

background{col_bgr}

#local lgt1_pos = < 38,57,28>;
#local lgt2_pos = <-38,57,28>;
#local lgt3_pos = < 38,57,-19>;
#local lgt4_pos = <-38,57,-19>;
#local lgt1_intense = 0.777419;
#local lgt2_intense = 0.777419;
#local lgt3_intense = 0.777419;
#local lgt4_intense = 0.777419;

light_source{lgt1_pos White*lgt1_intense}
light_source{lgt2_pos White*lgt2_intense}
light_source{lgt3_pos White*lgt3_intense}
light_source{lgt4_pos White*lgt4_intense}

#macro PCB()
union {
  prism{ -1.5,0.0, 5 <0,0> <100,0> <100,80> <0,80> <0,0> texture{col_brd} }

  union{
    box{<0,0,-0.05>< 80,0.035,0.05> rotate<0,90,0> translate<25,0,80>}
    box{<0,0,-0.05>< 80,0.035,0.05> rotate<0,90,0> translate<75,0,80>}
    box{<0,0,-0.05><100,0.035,0.05> rotate<0, 0,0> translate< 0,0,20>}
    box{<0,0,-0.05><100,0.035,0.05> rotate<0, 0,0> translate< 0,0,60>}
    pigment{Yellow}
    }
}
#end
