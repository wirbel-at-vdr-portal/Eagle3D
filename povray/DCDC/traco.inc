
/********************************************************************************************************************************************
//Macros for DC-DC CONVERTERs DIP series from TRACO
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 - 24/12/05
********************************************************************************************************************************************/
#macro SPC_VCONV_DIP_GRND(value,M,Lb,Tp,L,W,H,p1,p2,p3,p9,p10,p11,p12,p13,p14,p15,p16,p22,p23,p24,offsetX,pw,hpin)
union{
    #if(M=0)  // Plastic
        #local inner = 1;
        box{<-L/2,+0,-W/2><+L/2,H,+W/2> pigment{Gray20}}
    #else     // Metalic
        #if(L>33) 
            #local inner = 2.5; 
        #else
            #local inner = 1.5; 
        #end
        difference{
            superellipsoid { <0.1, 0.1> scale <L/2, H/2+2,W/2> translate <0, H/2-2, 0> texture{Silver1}}
            box{<-L/2,0,-W/2><+L/2,-H,+W/2>}            
        }
    #end
     
    #if(Lb=0)  // WHITE 
        #local col=White;
        box{<-L/2+inner,H,-W/2+inner><+L/2-inner,H+0.01,+W/2-inner> pigment{SpicyPink}} // Label
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 5 rotate<90,0,0> translate<-9,H+0.05,3.5>}  // Marking
        text {ttf global_fontfile_arial "POWER" 0.05, 0 pigment{col} scale 5 rotate<90,0,0> translate<-10,H+0.05,-1>}  // Marking
        text {ttf global_fontfile_arial "DC/DC CONVERTER" 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-13,H+0.05,-4.2>}  // Marking
        text {ttf global_fontfile_arial pw  0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<+8,H+0.05,-4.2>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-5.5+offsetX,H+0.05,-7>}  // Marking
        text {ttf global_fontfile_arial "TM" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<+8.5,H+0.05,6.8>}  // Marking
    #end
    #if(Lb=1) // BLACK
        #local col=Black;
        box{<-L/2+inner,H,-W/2+inner><+L/2-inner,H+0.01,+W/2-inner> pigment{SpicyPink}} // Label
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 5 rotate<90,0,0> translate<-9+offsetX,H+0.05,3>}  // Marking
        text {ttf global_fontfile_arial "DC/DC CONVERTER" 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-13+offsetX,H+0.05,-1.5>}  // Marking
        text {ttf global_fontfile_arial pw  0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<+8+offsetX,H+0.05,-1.5>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-7+offsetX,H+0.05,-6>}  // Marking
        text {ttf global_fontfile_arial "R" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<+9,H+0.05,6.78>}  // Marking
        disc {<9.45, H+0.05, 7.28> y,1.0,0.8 pigment{col}}
    #end
    #if(Lb=2) // DIL16
        #local col=White;
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 4 rotate<90,0,0> translate<-8+offsetX,H+0.05,3>}  // Marking
        text {ttf global_fontfile_arial "POWER" 0.05, 0 pigment{col} scale 4 rotate<90,0,0> translate<-8.5+offsetX,H+0.05,-0.5>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-6+offsetX,H+0.05,-3.5>}  // Marking
        text {ttf global_fontfile_arial_bold "0341" 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-3+offsetX,H+0.05,-6>}  // Marking
        text {ttf global_fontfile_arial "R" 0.05, 0 pigment{col} scale 1 rotate<90,0,0> translate<+9.1-2.5,H+0.05,6.9-2>}  // Marking
        disc {<9.45-2.5, H+0.05, 7.28-2> y,0.7,0.65 pigment{col}}
    #end
    #if(Lb=3)  // 5W 
        #local col=Black;
        box{<-L/2+inner,H,-W/2+inner><+L/2-inner,H+0.01,+W/2-inner> pigment{SpicyPink}} // Label
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 9 rotate<90,0,0> translate<-16,H+0.05,13>}  // Marking
        text {ttf global_fontfile_arial "POWER PRODUCTS" 0.05, 0 pigment{col} scale 3 rotate<90,0,0> translate<-15,H+0.05,8>}  // Marking
        text {ttf global_fontfile_arial "DC/DC CONVERTER" 0.05, 0 pigment{col} scale 3.2 rotate<90,0,0> translate<-20,H+0.05,-3>}  // Marking
        text {ttf global_fontfile_arial pw  0.05, 0 pigment{col} scale 3.2 rotate<90,0,0> translate<+14,H+0.05,-3>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 3 rotate<90,0,0> translate<-8+offsetX,H+0.05,-15>}  // Marking
        text {ttf global_fontfile_arial "R" 0.05, 0 pigment{col} scale 2.5 rotate<90,0,0> translate<+16,H+0.05,19>}  // Marking
        disc {<16.7, H+0.05, 19.8> y,1.5,1.2 pigment{col}}
    #end
    
    #if(Tp=0) // DIP24 pins
        #if(p1=1)
            cylinder{<-13.97,0,-7.62><-13.97,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
            cylinder{<-13.50,H,-7.62><-13.50,H+0.05,-7.62> 0.5 pigment{col}}
            text {ttf global_fontfile_arial_bold "1" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<-13.8,H+0.05,-6.8>}  // Marking
        #end
        #if(p2=1)
            cylinder{<-11.43,0,-7.62><-11.43,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
            #if(p1=0)
                cylinder{<-11.43,H,-7.62><-11.43,H+0.05,-7.62> 0.5 pigment{col}}
                text {ttf global_fontfile_arial_bold "2" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<-11.8,H+0.05,-6.8>}  // Marking
            #end
        #end
        #if(p3=1)
            cylinder{<-8.89,0,-7.62><-8.89,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p9=1)
            cylinder{<+6.35,0,-7.62><+6.35,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p10=1)
            cylinder{<+8.89,0,-7.62><+8.89,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p11=1)
            cylinder{<+11.43,0,-7.62><+11.43,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p12=1)
            cylinder{<+13.97,0,-7.62><+13.97,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end

        #if(p24=1)
            cylinder{<-13.97,0,+7.62><-13.97,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p23=1)
            cylinder{<-11.43,0,+7.62><-11.43,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p22=1)
            cylinder{<-8.89,0,+7.62><-8.89,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p16=1)
            cylinder{<+6.35,0,+7.62><+6.35,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p15=1)
            cylinder{<+8.89,0,+7.62><+8.89,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p14=1)
            cylinder{<+11.43,0,+7.62><+11.43,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p13=1)
            cylinder{<+13.97,0,+7.62><+13.97,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
    #end

    #if(Tp=1) // DIL16 pins
        cylinder{<-8.89,H,-5.08><-8.89,H+0.05,-5.08> 0.75 pigment{col}}
        cylinder{<-8.89,0,-5.08><-8.89,-min(hpin,(pin_length+pcb_height)),-5.08> 0.25 pigment{Silver}} //pin1
        cylinder{<+6.35,0,-5.08><+6.35,-min(hpin,(pin_length+pcb_height)),-5.08> 0.25 pigment{Silver}} //pin7
        cylinder{<+8.89,0,-5.08><+8.89,-min(hpin,(pin_length+pcb_height)),-5.08> 0.25 pigment{Silver}} //pin8
        cylinder{<+8.89,0,+5.08><+8.89,-min(hpin,(pin_length+pcb_height)),+5.08> 0.25 pigment{Silver}} //pin9
        cylinder{<+6.35,0,+5.08><+6.35,-min(hpin,(pin_length+pcb_height)),+5.08> 0.25 pigment{Silver}} //pin10
        cylinder{<-8.89,0,+5.08><-8.89,-min(hpin,(pin_length+pcb_height)),+5.08> 0.25 pigment{Silver}} //pin16
    #end

    #if(Tp=2) // TVL pins
        cylinder{<-10.16,0,-2.54><-10.16,-min(hpin,(pin_length+pcb_height)),-2.54> 0.25 pigment{Silver}} //pin2
        cylinder{<-10.16,0,+2.54><-10.16,-min(hpin,(pin_length+pcb_height)),+2.54> 0.25 pigment{Silver}} //pin1
        cylinder{<+10.16,0,-10.16><+10.16,-min(hpin,(pin_length+pcb_height)),-10.16> 0.25 pigment{Silver}} //pin3
        cylinder{<+10.16,0,0><+10.16,-min(hpin,(pin_length+pcb_height)),0> 0.25 pigment{Silver}}           //pin4
        cylinder{<+10.16,0,+10.16><+10.16,-min(hpin,(pin_length+pcb_height)),+10.16> 0.25 pigment{Silver}} //pin5
    #end
}
#end


#macro SPC_VCONV_DIP_TYL(value)
  SPC_VCONV_DIP_GRND(value,1,1,0,32.6,20.4,10.3,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,"1.5W",5)
#end

#macro SPC_VCONV_DIP_TEM2(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,"2W",3.8)
#end

#macro SPC_VCONV_DIP_TEL2(value)
  SPC_VCONV_DIP_GRND(value,0,2,1,23.8,13.7,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"2W",4)
#end

#macro SPC_VCONV_DIP_THI_S(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,"2W",4)
#end

#macro SPC_VCONV_DIP_THI_D(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,0,0,1,1,0,1,0,0,0,0,1,1,0,"2W",4)
#end

#macro SPC_VCONV_DIP_THP3_S(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,"2W",4)
#end

#macro SPC_VCONV_DIP_THP3_D(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,0,0,0,0,1,0,1,0,1,0,0,1,1,0,"2W",4)
#end

#macro SPC_VCONV_DIP_TEM3(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,"3W",3.8)
#end

#macro SPC_VCONV_DIP_TEL3(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,"3W",4.5)
#end

#macro SPC_VCONV_DIP_TEL3NP_S(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"3W",4.5)
#end

#macro SPC_VCONV_DIP_TEL3NP_D(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"3W",4.5)
#end

#macro SPC_VCONV_DIP_TEN3_S(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"3W",5)
#end

#macro SPC_VCONV_DIP_TEN3_D(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"3W",5)
#end

#macro SPC_VCONV_DIP_TEN4_S(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"4W",5)
#end

#macro SPC_VCONV_DIP_TEN4_D(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"4W",5)
#end

#macro SPC_VCONV_DIP_TVL(value)
  SPC_VCONV_DIP_GRND(value,1,3,2,51.3,51.3,8,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",6)
#end

#macro SPC_VCONV_DIP_TEL5_S(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20.3,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end

#macro SPC_VCONV_DIP_TEL5_D(value)
  SPC_VCONV_DIP_GRND(value,0,0,0,32,20.3,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end

#macro SPC_VCONV_DIP_TEN5_S(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end

#macro SPC_VCONV_DIP_TEN5_D(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end

#macro SPC_VCONV_DIP_TEN5WI_S(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end

#macro SPC_VCONV_DIP_TEN5WI_D(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end

#macro SPC_VCONV_DIP_TEN6_S(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end

#macro SPC_VCONV_DIP_TEN6_D(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end

#macro SPC_VCONV_DIP_TEN8(value)
  SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,1,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"8W",3.8)
#end



/********************************************************************************************************************************************
//Macros for DC-DC CONVERTERs SIP series from TRACO
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 - 21/12/05
********************************************************************************************************************************************/
#macro SPC_VCONV_SIP_GRND(value,s,Lg,lg1,lg,h,p1,p2,p3,p4,p5,p6,p7,p8,os,pl)
union{
    #local s = -((5*1.27)+s);
    #local lg1 = lg1+0.125;
    difference{
        box{<s,0,lg1-lg><s+Lg,+h,lg1>}
        union{
            box{<s+0.5,-0.1,-lg><s+Lg-0.5,+0.5,lg1+0.5>}
            cylinder{<-6.35,2.5,lg1-lg-0.2><-6.35,2.5,lg1-lg+0.15> 0.6}
        }
    pigment{Gray20}
    }

    #if(p1=1)
    box{<-5*1.27-0.25,0.6,-0.125><-5*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p2=1)
    box{<-3*1.27-0.25,0.6,-0.125><-3*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p3=1)
    box{<-1*1.27-0.25,0.6,-0.125><-1*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p4=1)
    box{<+1*1.27-0.25,0.6,-0.125><+1*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p5=1)
    box{<+3*1.27-0.25,0.6,-0.125><+3*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p6=1)
    box{<+5*1.27-0.25,0.6,-0.125><+5*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p7=1)
    box{<+7*1.27-0.25,0.6,-0.125><+7*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p8=1)
    box{<+9*1.27-0.25,0.6,-0.125><+9*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end

    text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-3.0+os,h+0.01,lg1-(lg/2)-0.5>}  // Marking on top surface
    text {ttf besch_font "TRACO" 0.1, 0 pigment{White} scale 3 rotate<0,0,0> translate<-3.5+os,6.81,lg1-lg-0.01>}    // Markings front surface
    text {ttf besch_font value 0.1, 0 pigment{White} scale 2 rotate<0,0,0> translate<-3.8+os,4.8,lg1-lg-0.01>}       // Markings front surface
    text {ttf besch_font "9815" 0.1, 0 pigment{White} scale 1.75 rotate<0,0,0> translate<-1.3+os,2.8,lg1-lg-0.01>}   // Markings front surface

    cylinder{<-6.35,2.5,lg1-lg+0.15><-6.35,2.5,lg1-lg+0.1> 0.6 pigment{White}}

    rotate<0,90,0>
}
#end

//TMA single/dual voltage, less or equal to 24V input voltage
#macro SPC_VCONV_SIP_TMA_S(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end

#macro SPC_VCONV_SIP_TMA_D(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end

#macro SPC_VCONV_SIP_TMA_S_24V(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end

#macro SPC_VCONV_SIP_TMA_D_24V(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end

//TME less or equal to 24V input voltage
#macro SPC_VCONV_SIP_TME(value)
  SPC_VCONV_SIP_GRND(value,1.9,+11.5,4.2,6,10.2,1,1,1,1,0,0,0,0,-3.5,3.2)
#end

#macro SPC_VCONV_SIP_TME_24V(value)
  SPC_VCONV_SIP_GRND(value,1.9,+11.5,5.2,7,10.2,1,1,1,1,0,0,0,0,-3.5,3.2)
#end

//TMV single/dual voltage, less or equal to 24V input voltage
#macro SPC_VCONV_SIP_TMV_S(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,0,1,0,1,0,0.5,3.2)
#end

#macro SPC_VCONV_SIP_TMV_D(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,0,1,1,1,0,0.5,3.2)
#end

#macro SPC_VCONV_SIP_TMV_S_24V(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,0,1,0,1,0,0.5,3.2)
#end

#macro SPC_VCONV_SIP_TMV_D_24V(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,0,1,1,1,0,0.5,3.2)
#end

// TMVEN  single/dual voltage
#macro SPC_VCONV_SIP_TMVEN_S(value)
  SPC_VCONV_SIP_GRND(value,3.5,+22,1.75,7.5,12.5,1,1,0,0,1,0,1,0,0.5,4)
#end

#macro SPC_VCONV_SIP_TMVEN_D(value)
  SPC_VCONV_SIP_GRND(value,3.5,+22,1.75,7.5,12.5,1,1,0,0,1,1,1,0,0.5,4)
#end

// TMH  single/dual voltage
#macro SPC_VCONV_SIP_TMH_S(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7.5,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end

#macro SPC_VCONV_SIP_TMH_D(value)
  SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7.5,10.2,1,1,0,1,1,1,0,0,0,3.2)
#end
// TMR  single/dual voltage
#macro SPC_VCONV_SIP_TMR(value)
  SPC_VCONV_SIP_GRND(value,2,+21.8,3.2,9.2,11.1,1,1,0,0,0,1,1,1,1.5,4)
#end



/*******************************************************************************
 * Traco DC/DC: TEN 6N, TEN 6WIN
 * 06.04.2022, wirbel
 ******************************************************************************/

#macro TEN6_xxxx_GRND(has_pin9,metal_case,value)
union {

  // Gehaeuse
  difference {
     object { Round_Box(<-31.8/2, 0, -20.3/2>, <+31.8/2, 10.2, +20.3/2> 1.0, 0) }
     box {<-3.5/2,-0.1,-3.5/2> <3.5/2,10.3,3.5/2> rotate<0,45,0> translate<-31.8/2,0,-10.2> }
     #if (metal_case=1)
     #else 
        pigment { Gray20 } finish { Shiny  ambient (0.05 * global_ambient_mul)}
     #end
     }
  // Label
  union {
     #local Rounding = 1.5;
     #local RedColor   = color rgb <233/255, 66/255, 87/255>;
     #local BlackColor = color rgb <  5/255,  5/255,  5/255>;
     intersection {
        object { Round_Box(<-29/2, 10.2 - Rounding, -19/2>, <+29/2, 10.2 + 0.1 + Rounding, +19/2> Rounding, 0) }
        box {              <-30/2, 10.1           ,     0>  <+30/2, 10.28                , +20/2> }
        pigment { BlackColor } 
        }
     intersection {
        object { Round_Box(<-29/2, 10.2 - Rounding, -19/2>, <+29/2, 10.2 + 0.1 + Rounding, +19/2> Rounding, 0) }
        box {              <-30/2, 10.1           , -20/2>  <+30/2, 10.3                 , 0> }
        pigment { RedColor } 
        }
     union {
        box { <-1.30/2      , 10.1,-3.2/2> <+1.30/2      , 10.3,+3.2/2> }
        box { <-1.30/2 +2.0 , 10.1,-3.2/2> <+1.30/2 +2.0 , 10.3,+3.2/2> }
        box { <-0.15/2 +1.00, 10.1,-3.2/2> <+0.15/2  +1.00, 10.3,+3.2/2> }
        translate <-12.0,0,6.5>
        pigment { RedColor }
        }

     text {ttf global_fontfile_arial "TRACO" 0.08 0 pigment{White} scale<6,4,4> rotate<90,0,0> translate<-8,10.32,5>}
     text {ttf global_fontfile_arial "POWER" 0.08 0 pigment{White} scale<6,4,4> rotate<90,0,0> translate<-8,10.32,1>}
     text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{White} scale 3  rotate<90,0,0> translate<-12,10.32,-8.5>}
     cylinder{ <-13.5, 10.0, -8.5> <-13.5, 10.32, -8.5> 0.3 pigment{White}}
     }
  #for(PIN, 1, 24)
     #if ( PIN=2 | PIN=3 | PIN=9 | PIN=11 | PIN=14 | PIN=16 | PIN=22 | PIN=23 )
        #if (PIN <= 12)
           #local XOFFS = -6.5*2.56;
           #local YOFFS = -3 * 2.54;
           #if ((PIN=9) & (has_pin9=0))
              // TEN_SINGLE: skip pin9              
           #else
              object { cylinder{ <0,0,0> <0,-3,> 0.25 translate<XOFFS + PIN*2.54,0,YOFFS> texture{e3d_tex_silver}} }
           #end
        #else
           #local XOFFS = +18.5*2.54; 
           #local YOFFS = +3 * 2.54;
           object { cylinder{ <0,0,0> <0,-3,> 0.25 translate<XOFFS - PIN*2.54,0,YOFFS> texture{e3d_tex_silver}} }
        #end
     #end
  #end
  
}
// end: TEN6_xxxx_GRND(sd,value)
#end

#macro TEN6_1210N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_1211N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_1212N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_1213N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_1215N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_1221N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_1222N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_1223N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_2410N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2411N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2412N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2413N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2415N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2421N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_2422N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_2423N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_4810N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4811N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4812N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4813N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4815N(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4821N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_4822N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_4823N(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_2410WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2411WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2412WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2413WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2415WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_2421WIN(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_2422WIN(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_2423WIN(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_4810WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4811WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4812WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4813WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4815WIN(value)
   TEN6_xxxx_GRND(0, 0, value)
#end

#macro TEN6_4821WIN(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_4822WIN(value)
   TEN6_xxxx_GRND(1, 0, value)
#end

#macro TEN6_4823WIN(value)
   TEN6_xxxx_GRND(1, 0, value)
#end
