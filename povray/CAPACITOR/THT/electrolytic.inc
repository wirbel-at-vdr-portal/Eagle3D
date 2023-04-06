/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * Axial-Elko
 ******************************************************************************/
#macro CAP_DIS_ELKO_AXIAL_BASE(val_size,dis,dia,dia_b,value)
  union {
     union {
        difference {
           union {
              cylinder { //Elko Koerper
                 <0,dis/2-3.5,0> <0,-(dis/2-3.5),0> dia
                 }
              torus { //Elko Rundung oben
                 dia-0.5,0.5
                 translate <0,-(dis/2-3.5),0>
                 }
              difference {
                 cylinder { <0,-(dis/2-3.5),0> <0,-(dis/2-3.0),0> dia-0.5 }
                 cylinder { <0,-(dis/2-3.5),0> <0,-(dis/2-2.9),0> dia*0.8*pow(dia/16,0.11) }
                 }
              torus { //Elko Rundung unten
                 dia-0.5,0.5
                 translate <0,dis/2-3.5,0>
                 }
              difference {
                 cylinder { <0,dis/2-3.5,0> <0,dis/2-3.0,0> dia-0.5 }
                 cylinder { <0,dis/2-3.5,0> <0,dis/2-2.9,0> dia*0.8*pow(dia/16,0.11) }
                 }
              }
           torus { //Aussparung unten
              dia+0.85,1
              translate <0,dis/2-5,0>
              }
           pigment { //Textur fuer Minusmarkierung
              tex_elko_axial
              scale <dia*2*pi*1.35,dia*2*pi,dia*2*pi*1.35>
              }
           finish {
              reflection {
                 0.03, 0.1
                 }
              phong 0.4
              crand 0.05
              ambient (0.1 * global_ambient_mul)
              }
           }
        cylinder { //Abdeckung oben
           <0,-(dis/2-3.6),0> <0,-(dis/2-3.1),0> dia*0.8*pow(dia/16,0.11)
           texture {
              col_silver
              }
           }
        cylinder { //Abdeckung unten
           <0,dis/2-3.2,0> <0,dis/2-3.5,0> dia-0.5
           pigment {
              Black
              }
           }
        cylinder { //Kontakt
           <0,-(dis/2-3.2),0> <0,-(dis/2-2),0> 1.5
           texture {
              col_silver
              }
           }
        intersection{
           cylinder { <0,dis/2,0> <0,-dis/2 + val_size + 3.5,0>dia}
           text { ttf besch_font value 0.2, 0 scale val_size rotate<0,0,-90> translate<0, dis/4,-dia> }
           rotate<0,10,0>
           translate<0,-val_size,-0.001>
           pigment {rgb<0.4,0.6,1> }
           }
        intersection{
           cylinder { <0,dis/2,0> <0,-dis/2 + val_size + 3.5,0>dia}
           text { ttf besch_font value 0.2, 0 scale val_size rotate<0,0,-90> translate<0, dis/4,-dia> }
           rotate<0,100,0>
           translate<-0.001,-val_size,0>
           pigment {rgb<0.4,0.6,1> }
           }
        intersection{
           cylinder { <0,dis/2,0> <0,-dis/2 + val_size + 3.5,0>dia}
           text { ttf besch_font value 0.2, 0 scale val_size rotate<0,0,-90> translate<0, dis/4,-dia> }
           rotate<0,190,0>
           translate<0,-val_size,0.001>
           pigment {rgb<0.4,0.6,1> }
           }
        rotate <0,180,>
        rotate <0,0,90>
        }
     object {
        TOOLS_WIRE_LEADS(dis-7, dia, 35, dia_b,  dis,  global_res_bend_radius, 0, "H")
        }
     pigment{Red}
     finish{F_MetalE ambient (0.1 * global_ambient_mul)}
     translate<0,dia,0>
     }
#end

#macro CAP_DIS_ELKO_AXIAL_15MM_5MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(2,15.24,5/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_15MM_6MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(2,15.24,6/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_15MM_9MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(2,15.24,9/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_22MM_6MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(2,22.86,6/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_22MM_9MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(2,22.86,9/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_22MM_10MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(2,22.86,10/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_25MM_9MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(3,25.4,9/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_25MM_10MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(3,25.4,10/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_30MM_10MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(3,30.48,10/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_30MM_12MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(3,30.48,12/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_30MM_16MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(3,30.48,16/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_35MM_12MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(4,35.56,12/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_35MM_14MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(4,35.56,14/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_35MM_16MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(4,35.56,16/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_35MM_18MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(4,35.56,18/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_45MM_16MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,45.72,16/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_45MM_18MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,45.72,18/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_45MM_21MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,45.72,21/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_45MM_22MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,45.72,22/2,0.8/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_45MM_25MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,45.72,25/2,1/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_50MM_25MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,50,25/2,1/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_50MM_30MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,50,30/2,1/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_55MM_25MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,55.88,25/2,1/2,value)
#end

#macro CAP_DIS_ELKO_AXIAL_55MM_30MM(value)
  CAP_DIS_ELKO_AXIAL_BASE(5,55.88,30/2,1/2,value)
#end



/*******************************************************************************
 * Elko
 * Walter Muecke
 * tex_scale     vector um die Textur zu strecken/stauchen
 * val_size      Groesse der Beschriftung
 * dis           Abstand der Pins      
 * dia           Radius des Elkos 
 * hig           Hoehe des Kondensator 
 * dia_b         Radius des Anschlussdrahtes
 * value         Beschriftungstext 
 ******************************************************************************/
#macro CAP_DIS_ELKO_BASE(tex_scale,val_size,dis,dia,hig,dia_b,value)
  union {
     difference { //Elko Koerper
        union {
           cylinder {
              <0,0.5,0> <0,hig-0.5,0> dia
              }
           torus { //Elko Rundung oben
              dia-0.5,0.5
              translate<0,hig-0.5,0>
              }
           difference {
              cylinder {
                 <0,hig-0.5,0> <0,hig,0> dia-0.5
                 }
              cylinder {
                 <0,hig-0.5,0> <0,hig+0.1,0> dia*0.8*pow(dia/16,0.11)
                 }
              }
           torus { //Elko Rundung unten
              dia-0.5,0.5
              translate <0,0.5,0>
              }
           }
        torus { //Aussparung unten
           dia+0.85,1
           translate<0,2.5,0>
           }
        pigment { //Textur fuer Minusmarkierung
           tex_elko
           scale tex_scale
           }
        finish {
           reflection { 0.03, 0.1}
           phong 0.4
           crand 0.05
           ambient (0.1 * global_ambient_mul)
           }
        }
     difference { //Abdeckung oben
        cylinder {
           <0,hig-0.5,0> <0,hig-0.1,0> dia*0.8*pow(dia/16,0.11)
           }
        box {
           <0,hig-0.35,-0.1> <dia,hig,0.1>
           } 
        box {
           <0,hig-0.35,-0.1> <dia,hig,0.1>
           rotate<0,120,0>
           }
        box {
           <0,hig-0.35,-0.1> <dia,hig,0.1>
           rotate<0,240,0>
           } 
        texture {
           col_silver
           }
        }
     cylinder { //Abdeckung unten
        <0,0.2,0> <0,0.5,0> dia-0.5
        pigment { Black }
        }
     union {
        #if(pin_short=off)
           cylinder { <0,0,0> <0,-14.5,0>dia_b translate<dis/2,0,0> }    //Beinchen rechts
           cylinder { <0,0,0> <0,-17.5,0>dia_b translate<-dis/2,0,0> }   //Beinchen links
        #else
           cylinder { <0,0,0> <0,-1*(pcb_height+pin_length)-0.2,0>dia_b translate<dis/2,0,0> }    //Beinchen rechts
           cylinder { <0,0,0> <0,-1*(pcb_height+pin_length)-0.2,0>dia_b translate<-dis/2,0,0> }   //Beinchen links
        #end
        texture { col_silver }
        }
     intersection { //Beschriftung
        cylinder {
           <0,0,0> <0,hig,0> dia
           }
        text {
           ttf besch_font value 0.2, 0
           scale val_size
           rotate <0,0,90>
           translate <0,0,-dia>
           }
        rotate <0,0,180>
        rotate <0,10,0>
        translate <0,hig-val_size,-0.001>
        pigment {
           rgb <0.4,0.6,1>
           }
        }
     intersection {
        cylinder {
           <0,0,0> <0,hig,0> dia
           }
        text {
           ttf besch_font value 0.2, 0
           scale val_size
           rotate <0,0,90>
           translate <0,0,-dia>
           }
        rotate <0,0,180>
        rotate <0,100,0>
        translate <-0.001,hig-val_size,0>
        pigment {
           rgb <0.4,0.6,1>
           }
        }
     intersection{
        cylinder {
           <0,0,0> <0,hig,0> dia
           }
        text {
           ttf besch_font value 0.2, 0 
           scale val_size
           rotate <0,0,90>
           translate <0,0,-dia>
           }
        rotate <0,0,180>
        rotate <0,190,0>
        translate <0,hig-val_size,0.001>
        pigment {
           rgb <0.4,0.6,1>
           }
        }
     finish {
        F_MetalE
        ambient (0.1 * global_ambient_mul)
        }
     translate <0,0.2,0>
     }
#end

#macro CAP_DIS_ELKO_2MM_5MM(value)
  CAP_DIS_ELKO_BASE(<6.39,20,6.39>,1,2,5/2,11,0.5/2,value)
#end

#macro CAP_DIS_ELKO_2MM5_5MM(value)
  CAP_DIS_ELKO_BASE(<6.39,20,6.39>,1,2.5,5/2,11.2,0.5/2,value)
#end

#macro CAP_DIS_ELKO_2MM5_6MM3(value)
  CAP_DIS_ELKO_BASE(<8.04,22,8.04>,1,2.5,6.3/2,11.2,0.5/2,value)
#end

#macro CAP_DIS_ELKO_3MM5_8MM(value)
  CAP_DIS_ELKO_BASE(<10.225,22,10.225>,1.1,3.5,8/2,11.5,0.6/2,value)
#end

#macro CAP_DIS_ELKO_5MM_10MM(value)
  CAP_DIS_ELKO_BASE(<12.77,25,12.77>,1.8,5,10/2,13,0.6/2,value)
#end

#macro CAP_DIS_ELKO_5MM_10MM(value)
  CAP_DIS_ELKO_BASE(<12.77,25,12.77>,1.8,5,10/2,16,0.6/2,value)
#end

#macro CAP_DIS_ELKO_5MM_10MM_2(value)
  CAP_DIS_ELKO_BASE(<12.77,25,12.77>,1.8,5,10/2,25.5,0.6/2,value)
#end

#macro CAP_DIS_ELKO_5MM_12MM5_2(value)
  CAP_DIS_ELKO_BASE(<15.95,30,15.95>,2.8,5,12.5/2,16.5,0.6/2,value)
#end

#macro CAP_DIS_ELKO_5MM_12MM5(value)
  CAP_DIS_ELKO_BASE(<15.95,30,15.95>,2.8,5,12.5/2,22.5,0.6/2,value)
#end

#macro CAP_DIS_ELKO_5MM_12MM5_3(value)
  CAP_DIS_ELKO_BASE(<15.95,30,15.95>,2.8,5,12.5/2,25.5,0.6/2,value)
#end

#macro CAP_DIS_ELKO_7MM5_16MM_2(value)
  CAP_DIS_ELKO_BASE(<20.45,38,20.45>,3,7.5,16/2,16.5,0.8/2,value)
#end

#macro CAP_DIS_ELKO_7MM5_16MM_3(value)
  CAP_DIS_ELKO_BASE(<20.45,38,20.45>,3,7.5,16/2,25.5,0.8/2,value)
#end

#macro CAP_DIS_ELKO_7MM5_16MM(value)
  CAP_DIS_ELKO_BASE(<20.45,38,20.45>,3,7.5,16/2,28,0.8/2,value)
#end

#macro CAP_DIS_ELKO_7MM5_18MM(value)
  CAP_DIS_ELKO_BASE(<23,40,23>,4,7.5,18/2,35.5,0.8/2,value)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//rcl:E15-5=CAP_DIS_ELKO_AXIAL_15MM_5MM(:Elko 15.24mm pitch 5mm diameter
//rcl:E15-6=CAP_DIS_ELKO_AXIAL_15MM_6MM(:Elko 15.24mm pitch 6mm diameter
//rcl:E15-9=CAP_DIS_ELKO_AXIAL_15MM_9MM(:Elko 15.24mm pitch 9mm diameter
//rcl:E22-6=CAP_DIS_ELKO_AXIAL_22MM_6MM(:Elko 22.86mm pitch 6mm diameter
//rcl:E22-9=CAP_DIS_ELKO_AXIAL_22MM_9MM(:Elko 22.86mm pitch 9mm diameter
//rcl:E22-10=CAP_DIS_ELKO_AXIAL_22MM_10MM(:Elko 22.86mm pitch 10mm diameter
//rcl:E25-9=CAP_DIS_ELKO_AXIAL_25MM_9MM(:Elko 25.4mm pitch 9mm diameter
//rcl:E25-10=CAP_DIS_ELKO_AXIAL_25MM_10MM(:Elko 25.4mm pitch 10mm  diameter
//rcl:E30-10=CAP_DIS_ELKO_AXIAL_30MM_10MM(:Elko 30.48mm pitch 10mm diameter
//rcl:E30-12=CAP_DIS_ELKO_AXIAL_30MM_12MM(:Elko 30.48mm pitch 12mm diameter
//rcl:E30-16=CAP_DIS_ELKO_AXIAL_30MM_16MM(:Elko 30.48mm pitch 16mm diameter
//rcl:E35-12=CAP_DIS_ELKO_AXIAL_35MM_12MM(:Elko 35.56mm pitch 12mm diameter
//rcl:E35-14=CAP_DIS_ELKO_AXIAL_35MM_14MM(:Elko 35.56mm pitch 14mm diameter
//rcl:E35-16=CAP_DIS_ELKO_AXIAL_35MM_16MM(:Elko 35.56mm pitch 16mm diameter
//rcl:E35-18=CAP_DIS_ELKO_AXIAL_35MM_18MM(:Elko 35.56mm pitch 18mm diameter
//rcl:E45-16=CAP_DIS_ELKO_AXIAL_45MM_16MM(:Elko 45.72mm pitch 16mm diameter
//rcl:E45-18=CAP_DIS_ELKO_AXIAL_45MM_18MM(:Elko 45.72mm pitch 18mm diameter
//rcl:E45-21=CAP_DIS_ELKO_AXIAL_45MM_21MM(:Elko 45.72mm pitch 21mm diameter
//rcl:E45-22=CAP_DIS_ELKO_AXIAL_45MM_22MM(:Elko 45.72mm pitch 22mm diameter
//rcl:E45-25=CAP_DIS_ELKO_AXIAL_45MM_25MM(:Elko 45.72mm pitch 25mm diameter
//rcl:E50-25=CAP_DIS_ELKO_AXIAL_50MM_25MM(:Elko 50mm pitch 25mm diameter
//rcl:E50-30=CAP_DIS_ELKO_AXIAL_50MM_30MM(:Elko 50mm pitch 30mm diameter
//rcl:E55-25=CAP_DIS_ELKO_AXIAL_55MM_25MM(:Elko 55.88mm pitch 25mm diameter
//rcl:E55-30=CAP_DIS_ELKO_AXIAL_55MM_30MM(:Elko 55.88mm pitch 30mm diameter
//rcl:E2-5=CAP_DIS_ELKO_2MM_5MM(:Elko 2mm pitch 5mm diameter 11mm height
//rcl:E2,5-5=CAP_DIS_ELKO_2MM5_5MM(:Elko 2.5mm pitch 5mm diameter 11.2mm height
//rcl:E2,5-6,3=CAP_DIS_ELKO_2MM5_6MM3(:Elko 2.5mm pitch 6.3mm diameter 11.2mm Height
//rcl:E2,5-6=CAP_DIS_ELKO_2MM5_6MM3(:Elko 2.5mm pitch 6mm diameter 11.2mm height
//rcl:E3,5-8=CAP_DIS_ELKO_3MM5_8MM(:Elko 3.5mm pitch 8mm diameter 11.5mm height
//rcl:E5-10,5=CAP_DIS_ELKO_5MM_10MM(:Elko 5mm pitch 10mm diameter 16mm height
//rcl:E5-13=CAP_DIS_ELKO_5MM_12MM5(:Elko 5mm pitch 12,5mm diameter 22.5mm height
//rcl:E7,5-16=CAP_DIS_ELKO_7MM5_16MM(:Elko 7.5mm pitch 16mm diameter 28mm height
//rcl:E7,5-18=CAP_DIS_ELKO_7MM5_18MM(:Elko 7.5mm pitch 18mm diameter 35.5mm height
// end assignment
