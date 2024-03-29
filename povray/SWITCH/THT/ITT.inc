/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/

/*******************************************************************************
 * ITT-industries Sealed miniature THT toggle switch Series E
 * Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
 * Rev. 1.1 du 09/01/06
 *
 * Version supported:
 * Function     : 10x 20x 30x for 1,2,3 circuits
 *              : x01(actuator pos 1) x05(actuator pos 2)
 * Actuator     : M, S, L3 (L3 red by default, other color can be created)
 * Bushing      : D1, D9, Y only for termin. C (take D1 for F1) (D9 doesn't exist for 3 circuits)
 * Termination  : A, AV2, C, (V3, V2, V4, V6, V7, V8, V9)
 * Contact mat. : Gold by default (silver can be created)
 * Plastic Actuator Color : Red by default (White and Black can be created)
 *
 * Circuit=1-3 ActuatorType=1-3 ActuatorPos=1-3 Bushing=1-3 T=1..20 Material=1-2 PAC=1-3
 * parameters are took in the same order than datasheet
 * *****************************************************************************/
#macro SWITCH_ITTE_BASE(Circuit,ActuatorType,ActuatorPos,Bushing,T,Material,PAC)
  // Case
  #macro ITT_CASE(Circuit,Pos) // Pos=1 actuator on top Pos=2 actuator H  Pos=3 actuator V
     #if (Circuit=1)
        #local W=6.6;
        #local L=8.89;
     #end
     #if (Circuit=2)
        #local W=11.43;
        #local L=8.89;
     #end
     #if (Circuit=3)
        #local W=16.31;
        #local L=10.77;
     #end
     #local H=12.7;
     union {
        superellipsoid {
           <0.04,0.04>
           scale <L/2-0.5,H/2,W/2>
           translate (+0.5-t1/2)*x
           pigment {
              Redbody
              }
           }
        // large part
        superellipsoid {
           <0.04,0.04>
           scale <1/2,H/2,W/2>
           translate (-L/2+0.5-t1/2)*x
           pigment {
              Redbody
              }
           }
        // thin part
        #if (Pos=2 | Pos=3)
           superellipsoid {
              <0.04,0.04>
              scale <t1/2,H/2,W/2>
              translate (-L/2-t1)*x
              texture {
                 Silver2
                 }
              }
           // front plate
        #end
        #if (Circuit=2)
           superellipsoid {
              <0.05,0.5>
              scale <1.52/2,H/2,1.2/2>
              translate (L/2)*x
              pigment {
                 Redbody
                 }
              }
           // large part
        #end
        #if (Circuit=3)
           superellipsoid {
              <0.05,0.5>
              scale <1.52/2,H/2,1.2/2>
              translate <(L/2),0,-4.83/2>
              pigment {
                 Redbody
                 }
              }
           // large part
           superellipsoid {
              <0.05,0.5>
              scale <1.52/2,H/2,1.2/2>
              translate <(L/2),0,+4.83/2>
              pigment {
                 Redbody
                 }
              }
           // large part
        #end
        //marking
        #local OffsetX = 3.7;
        #local Oy = -6.5;
        #local Oz = 0;
        text {
           ttf global_fontfile_eagle3d "&" 0.05, 0
           pigment {
              Black
              }
           scale 2.2
           rotate <0,0,90>
           translate <OffsetX-5.2,Oy+3.9,-W/2-.05>
           }
        #if (Circuit=1)
           text {
              ttf global_fontfile_arial "C&K  CR  E 101" 0.05, 0
              pigment {
                 Black
                 }
              scale 1.5
              rotate <0,0,90>
              translate <OffsetX-3.5,Oy+1,-W/2-.05>
              }
        #end
        #if (Circuit=2)
           text {
              ttf global_fontfile_arial "C&K  CR  E 201" 0.05, 0
              pigment {
                 Black
                 }
              scale 1.5
              rotate <0,0,90>
              translate <OffsetX-3.5,Oy+1,-W/2-.05>
              }
        #end
        #if (Circuit=3)
           text {
              ttf global_fontfile_arial "C&K  CR  E 301" 0.05, 0
              pigment {
                 Black
                 }
              scale 1.5
              rotate <0,0,90>
              translate <OffsetX-3.5,Oy+1,-W/2-.05>
              }
        #end
        text {
           ttf global_fontfile_arial "0.4 VA MAX" 0.05, 0
           pigment {
              Black
              }
           scale 1.5 
           rotate <0,0,90>
           translate <OffsetX-1.75,Oy+2.5,-W/2-.05>
           }
        text {
           ttf global_fontfile_arial "0214" 0.05, 0
           pigment {
              Black
              }
           scale 1.5
           rotate <0,0,90>
           translate <OffsetX-0,Oy+4.7,-W/2-.05>
           }
        #if (Pos=1)
           rotate <0,0,-90>
           translate <0,L/2,0>
        #end
        #if (Pos=2)
           rotate <90,0,0>
           translate <L/2+0.25,W/2,0>
        #end
        #if (Pos=3)
           translate <L/2+0.25,H/2,0>
        #end
        }
  #end
  // Bushing
  #macro ITT_BUSHING(B,Pos,OffsetX,OffsetY) // Pos=1 actuator on top Pos=2 actuator H  Pos=3 actuator V
     #local r=0.2;
     #local e=0.1; // Epsilon
     #if (B=1 | B=2 | B=3)
        #local D=6.48;
     #end
     #if (B=1 | B=2)
        #local LB=6.35;
     #end
     #if (B=3)
        #local LB=7.11;
     #end
     #if (B=4)
        #local LB=8.89;
        #local D=6.2;
     #end
     difference {
        union {
           cylinder {
              <-LB+r,0,0> <0,0,0> D/2
              }
           torus {
              D/2-r, r
              rotate 90*z
              translate <-LB+r,0,0>
              }
           cylinder {
              <-LB,0,0> <0,0,0> D/2-r
              }
           }
        union {
           cylinder {
              <-LB-e,0,0> <0,0,0> 1.8
              }
           #if (B=1 | B=2 | B=3)
              box {
                 <-LB-e,-D/2,-2.78> <0,+D/2,-D/2-e>
                 }
              box {
                 <-LB-e,-D/2,+2.78> <0,+D/2,+D/2+e>
                 }
           #end
           #if (B=4)
              #ifdef (global_fine_drawing)
              #local Alpha=0;
              #local Pitch=0.47;
              #local xs=0;
              #local N=0;
              #while(xs> (-LB-1))
                 #local xs=-Alpha/360*Pitch;
                 sphere {
                    <xs,sin(Alpha*3.14/360)*D/2,cos(Alpha*3.14/360)*D/2> 0.66*Pitch
                    }
                 #local Alpha=Alpha+10;
              #end
           #else
              #local N=0;
              #while((N*0.635)<LB)
                 torus {
                    D/2,0.2
                    rotate 93*z translate <-N*0.635,0,0>
                    }
                 #local N=N+1;
              #end
           #end
           box {
              <0,-D/2+.56,-0.42> <-LB-1,-D/2-0.1,+0.42>
              }
        #end
        }
     #if (Pos=1)
        rotate -90*z
        translate OffsetY*y
     #end
     #if (Pos=2)
        rotate -90*x
        translate <-OffsetX,OffsetY,0>
     #end
     #if (Pos=3)
        translate <-OffsetX,OffsetY,0>
     #end
     #if (B=1 | B=2 | B=3)
        pigment {
           Redbody
           }
     #else
        texture {
           col_silver
           }
     #end
     }
#end

#macro ITT_ACTUATOR(Pos,ActuatorType,ActuatorPos,OffsetX,OffsetY,PAC,B) // Pos=1 actuator on top Pos=2 actuator H  Pos=3 actuator V
  #local k=3;
  #local col=Gray20;
  #if (B=1 | B=2)
     #local ofs=6.35-k;
  #end
  #if (B=3)
     #local ofs=7.11-k;
  #end
  #if (B=4)
     #local ofs=8.89-k;
  #end
  #if (ActuatorPos=1)
     #local Alpha = -25/360*3.14;
  #end
  #if (ActuatorPos=2)
     #local Alpha = 0;
  #end
  #if (ActuatorPos=3)
     #local Alpha = +25/360*3.14;
  #end
  union {
     #if (ActuatorType=1)
        #local L1=7.62+k;
        #local D=2.67;
        sphere {
           <-L1+D/2,-tan(Alpha)*(L1-D/2),0>, D/2
           texture {
              Chrome_Texture
              }
           }
        cone {
           <-L1+D/2,-tan(Alpha)*(L1-D/2), 0>, D/2, <0,0,0>, 1.2
           texture {
              Chrome_Texture
              }
           }
     #end
     #if (ActuatorType=2)
        #local L1=12.70+k;
        #local D=2.92;
        sphere {
           <-L1+D/2,-tan(Alpha)*(L1-D/2),0>, D/2
           texture {
              Chrome_Texture
              }
           }
        cone {
           <-L1+D/2,-tan(Alpha)*(L1-D/2), 0>, D/2, <0,0,0>, 1.2
           texture {
              Chrome_Texture
              }
           }
     #end
     #if (ActuatorType=3)
        #local L1=7.5+k;
        #local L2=23.30+k;
        #local L3=23.88+k;
        #local D1=2.92;
        #local D2=3.28;
        #local D3=2.78;
        #if (PAC=1)
           #local col=Gray20;
        #end
        #if (PAC=2)
           #local col=White;
        #end
        #if (PAC=3)
           #local col=Red;
        #end
        cone {
           <-L1,-tan(Alpha)*(L1), 0>, D1/2, <0,0,0>, 1.2
           texture {
              Chrome_Texture
              }
           }
        cone {
           <-L2,-tan(Alpha)*(L2), 0>, D2/2, <-L1,-tan(Alpha)*(L1), 0>, D1/2
           pigment {
              col
              }
           }
        cone {
           <-L3,-tan(Alpha)*(L3), 0>, D3/2, <-L2,-tan(Alpha)*(L2), 0>, D2/2
           pigment {
              col
              }
           }
     #end
     translate -ofs*x
     #if (Pos=1)
        rotate -90*z
        translate <0,OffsetY,0>
     #end
     #if (Pos=2)
        rotate -90*x
        translate <-OffsetX,OffsetY,0>
     #end
     #if (Pos=3)
        rotate 180*x
        translate <-OffsetX,OffsetY,0>
     #end
     }
#end

#macro ITT_SPRING(Pos,OffsetX,OffsetY)
  union {
     difference {
        intersection {
           box {
              <-2-9.636,-6.15,+3.25> <-9.043,6.15,-3.25>
              texture {
                 Silver2
                 }
              }
           cylinder {
              <0,0,-5> <0,0,+5> 30
              translate +20.0*x
              texture {
                 Silver2
                 }
              }
           }
        union {
           box {
              <-2-9.7,-4.85,+2.85> <-9.3,4.85,-2.85>
              texture {
                 Silver2
                 }
              }
           cylinder {
              <0,0,-5> <0,0,+5> 30
              translate +20.2*x
              texture {
                 Silver2
                 }
              }
           }
        }
     box {
        <-0.1,-1.3,-2.5> <+0.1,+1.3,+2.5>
        rotate -20*z
        translate <-9.95,3.58,0>
        texture {
           Silver2
           }
        }
     box {
        <-0.1,-1.3,-2.5> <+0.1,+1.3,+2.5>
        rotate +20*z
        translate <-10,-3.58,0>
        texture {
           Silver2
           }
        }
     #if (Pos=1)
        rotate -90*z
        translate OffsetY*y
     #end
     #if (Pos=2)
        rotate -90*x
        translate <OffsetX,OffsetY,0>
     #end
     #if (Pos=3)
        translate <OffsetX,OffsetY,0>
     #end
     }
#end

//front plate
#macro ITT_PLATE_PIN(Pos,OffsetX,OffsetY)
  #local t1 = 0.41;   // front plate thickness
  #if (Circuit=1)
     #local W=6.6;
     #local L=8.89;
  #end
  #if (Circuit=2)
     #local W=11.43;
     #local L=8.89;
  #end
  #if (Circuit=3)
     #local W=16.31;
     #local L=10.77;
  #end
  #local H  = 12.7;   // case height
  union {
     box {
        <-t1/2,0,+2.54-0.635> <+t1/2,-2.24,+2.54+0.635>
        }
     box {
        <-t1/2,0,-2.54-0.635> <+t1/2,-2.24,-2.54+0.635>
        }
     cylinder {
        <-t1/2,-2.24,+2.54> <+t1/2,-2.24,+2.54> .635
        }
     cylinder {
        <-t1/2,-2.24,-2.54> <+t1/2,-2.24,-2.54> .635
        }
     texture {
        Silver2
        }
     }
#end

//Bended E pin   L=lenght H=height R=ray h=pin height w=pin width
#macro ITT_PIN(L,H,R,h,w,Offset,Material)
  #local e=0.1; // Epsilon
  union {
     box {
        <-L,H-h/2,-w/2> <0-R,H+h/2,+w/2>
        }
     // horizontal pin part
     box {
        <-h/2,-3.18,-w/2> <+h/2,H-R,+w/2>
        }
     // vertical pin part
     difference {
        cylinder {
           <-R,H-R,-w/2> <-R,H-R,+w/2> R+h/2
           }
        // bended pin part
        union {
           cylinder {
              <-R,H-R,-w/2-e> <-R,H-R,+w/2+e> R-h/2
              }
           // delete central part of cylinder
           box {
              <-2*R-h/2-e,H+h/2+e,-w/2-e> <-R,H-2*R-h/2-e,+w/2+e>
              }
           // delete half of disc
           box {
              <-R-e,H-R,-w/2-e> <+h/2+e,H-2*R-h/2-e,+w/2+e>
              }
           // delete half of remaining half of disc
           }
        }
     translate Offset*x
     #if (Material=1 | Material=2)
        texture {
           col_gold
           }
     #else
        texture {
           col_silver
           }
     #end
     }
#end

#macro ITT_PIN_SET(Circuit,L,H,T,Material)
  #local h=0.76;
  #local w=1.27;
  #local MH=H/2;
  #local ST=3.81;
  #local Start=0;
  #local L1=12.70;
  #if (T=1) //A
     #if (Circuit=1)
        #local DH=3.81;
        #local DW=4.7;
        #local Start=0;
     #end
     #if (Circuit=2)
        #local DH=3.81;
        #local DW=4.7;
        #local Start=-DH/2;
     #end
     #if (Circuit=3)
        #local DH=3.81;
        #local DW=4.7;
        #local Start=-DH;
        #local L1=14.35;
     #end
  #else       //AV2
     #if (Circuit=1)
        #local DH=4.7;
        #local DW=4.83;
        #local Start=0;
     #end
     #if (Circuit=2)
        #local DH=4.7;
        #local DW=4.83;
        #local Start=-DW/2;
     #end
     #if (Circuit=3)
        #local DH=4.7;
        #local DW=4.83;
        #local Start=-DW;
        #local L1=14.35;
     #end
  #end
  union {
     #local N=1;
     #if (T=1)
        #while(N<(Circuit+1))
           union {
              object {
                 ITT_PIN(4+ST*(N-1),MH+Start+(N-1)*DH,1.1+(N-1),w,h,L1+ST*(N-1),Material)
                 translate -DW*z
                 }
              object {
                 ITT_PIN(4+ST*(N-1),MH+Start+(N-1)*DH,1.1+(N-1),w,h,L1+ST*(N-1),Material)
                 }
              object {
                 ITT_PIN(4+ST*(N-1),MH+Start+(N-1)*DH,1.1+(N-1),w,h,L1+ST*(N-1),Material)
                 translate +DW*z
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,1,0.6>
                 translate <L, MH+Start+(N-1)*DH, -DW>
                 pigment {
                    Redbody
                    }
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,1,0.6>
                 translate <L, MH+Start+(N-1)*DH, 0>
                 pigment {
                    Redbody
                    }
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,1,0.6>
                 translate <L, MH+Start+(N-1)*DH, +DW>
                 pigment {
                    Redbody
                    }
                 }
              }
           #local N=N+1;
        #end
     #end
     #if (T=2)
        #while(N<(Circuit+1))
           union {
              object {
                 ITT_PIN(4,MH-DH,1.1,h,w,L1,Material)
                 }
              object {
                 ITT_PIN(4+ST,MH,2.0,h,w,L1+ST,Material)
                 }
              object {
                 ITT_PIN(4+2*ST,MH+DH,3.0,h,w,L1+2*ST,Material)
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,0.6,1>
                 translate <L, MH-DH, 0>
                 pigment {
                    Redbody
                    }
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,0.6,1>
                 translate <L, MH, 0>
                 pigment {
                    Redbody
                    }
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,0.6,1>
                 translate <L, MH+DH, 0>
                 pigment {
                    Redbody
                    }
                 }
              translate z*(Start+(N-1)*DW)
              }
           #local N=N+1;
        #end
     #end
     #if (T=3)
        #while(N<(Circuit+1))
           union {
              box {
                 <-h/2,1.52,-w/2> <+h/2,1.52-6.35,+w/2>
                 translate <-4.70,0,0>
                 }
              box {
                 <-h/2,1.52,-w/2> <+h/2,1.52-6.35,+w/2>
                 }
              box {
                 <-h/2,1.52,-w/2> <+h/2,1.52-6.35,+w/2>
                 translate <+4.70,0,0>
                 }
              #if (Material=1 | Material=2)
                 texture {
                    col_gold
                    }
              #else
                 texture {
                    col_silver
                    }
              #end
              translate z*(Start+(N-1)*DW)
              }
           union {
              sphere {
                 <0,0,0>, 1.52
                 scale <1,0.6,1>
                 translate <-DH,1.52,0>
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,0.6,1>
                 translate <0,1.52,0>
                 }
              sphere {
                 <0,0,0>, 1.52
                 scale <1,0.6,1>
                 translate <+DH,1.52,0>
                 }
              translate z*(Start+(N-1)*DW)
              pigment {
                 Redbody
                 }
              }
           #local N=N+1;
        #end
     #end
     }
#end

#local Redbody = rgb <0.62, 0.32, 0.29>;
#local t1 = 0.41;   // front plate thickness
#local t2 = 0.51;   // V type plate thickness
#local sh = 1.52;   // Epoxy seal height
#local H  = 12.7;   // case height
#if (Circuit=1)
  #local W=6.6;
  #local L=8.89;
#end

#if (Circuit=2)
  #local W=11.43;
  #local L=8.89;
#end

#if (Circuit=3)
  #local W=16.31;
  #local L=10.77;
#end

#if (T=1)  // A
  union {
     object {
        ITT_CASE(Circuit,2)
        translate (t1/2)*x
        }
     object {
        ITT_BUSHING(Bushing,2,t1/2,W/2)
        }
     object {
        ITT_ACTUATOR(2,ActuatorType,ActuatorPos,2.86,W/2,PAC,Bushing)
        }
     object {
        ITT_SPRING(2,9,W/2)
        }
     object {
        ITT_PLATE_PIN(2,0,H/2)
        }
     object {
        ITT_PIN_SET(Circuit,L,W,T,Material)
        }
     }
#end

#if (T=2)  // AV2
  union {
     object {
        ITT_CASE(Circuit,3)
        translate <t1/2,0,0>
        }
     object {
        ITT_BUSHING(Bushing,3,t1/2,H/2)
        }
     object {
        ITT_ACTUATOR(3,ActuatorType,ActuatorPos,2.86,H/2,PAC,Bushing)
        }
     object {
        ITT_SPRING(3,9,H/2)
        }
     object {
        ITT_PLATE_PIN(3,0,H/2)
        }
     object {
        ITT_PIN_SET(Circuit,L,H,T,Material)
        }
     }
#end

#if (T=3) // C
  union {
     object {
        ITT_CASE(Circuit,1)
        translate sh*y
        }
     object {
        ITT_BUSHING(Bushing,1,0,L+sh)
        }
     object {
        ITT_ACTUATOR(1,ActuatorType,ActuatorPos,0,L+2.86,PAC,Bushing)
        }
     object {
        ITT_PIN_SET(Circuit,L,W,T,Material)
        }
     }
#end

#end

// Fonction 1 circuit pos 1, Actuator M, Bushing D1
#macro SWITCH_ITTE_E101MD1ABE()
  SWITCH_ITTE_BASE(1,1,1,1,1,1,0)
#end

#macro SWITCH_ITTE_E101MD1AV2BE()
  SWITCH_ITTE_BASE(1,1,1,1,2,1,0)
#end

#macro SWITCH_ITTE_E101MD1CBE()
  SWITCH_ITTE_BASE(1,1,1,1,3,1,0)
#end

// Fonction 2 circuits pos 1, Actuator M, Bushing D1
#macro SWITCH_ITTE_E201MD1ABE()
  SWITCH_ITTE_BASE(2,1,1,1,1,1,0)
#end

#macro SWITCH_ITTE_E201MD1AV2BE()
  SWITCH_ITTE_BASE(2,1,1,1,2,1,0)
#end

#macro SWITCH_ITTE_E201MD1CBE()
  SWITCH_ITTE_BASE(2,1,1,1,3,1,0)
#end

// Fonction 3 circuits pos 1, Actuator M, Bushing D1
#macro SWITCH_ITTE_E301MD1ABE()
  SWITCH_ITTE_BASE(3,1,1,1,1,1,0)
#end

#macro SWITCH_ITTE_E301MD1AV2BE()
  SWITCH_ITTE_BASE(3,1,1,1,2,1,0)
#end

#macro SWITCH_ITTE_E301MD1CBE()
  SWITCH_ITTE_BASE(3,1,1,1,3,1,0)
#end

// Fonction 1 circuit pos 1, Actuator M, Bushing D9
#macro SWITCH_ITTE_E101MD9ABE()
  SWITCH_ITTE_BASE(1,1,1,3,1,1,0)
#end

#macro SWITCH_ITTE_E101MD9AV2BE()
  SWITCH_ITTE_BASE(1,1,1,3,2,1,0)
#end

#macro SWITCH_ITTE_E101MD9CBE()
  SWITCH_ITTE_BASE(1,1,1,3,3,1,0)
#end

// Fonction 2 circuits pos 1, Actuator M, Bushing D9
#macro SWITCH_ITTE_E201MD9ABE()
  SWITCH_ITTE_BASE(2,1,1,3,1,1,0)
#end

#macro SWITCH_ITTE_E201MD9AV2BE()
  SWITCH_ITTE_BASE(2,1,1,3,2,1,0)
#end

#macro SWITCH_ITTE_E201MD9CBE()
  SWITCH_ITTE_BASE(2,1,1,3,3,1,0)
#end

// Fonction 1 circuit pos 1, Actuator M, Bushing Y
#macro SWITCH_ITTE_E101MYCBE()
  SWITCH_ITTE_BASE(1,1,1,4,3,1,0)
#end

// Fonction 2 circuits pos 1, Actuator M, Bushing Y
#macro SWITCH_ITTE_E201MYCBE()
  SWITCH_ITTE_BASE(2,1,1,4,3,1,0)
#end

// Fonction 3 circuits pos 1, Actuator M, Bushing Y
#macro SWITCH_ITTE_E301MYCBE()
  SWITCH_ITTE_BASE(3,1,1,4,3,1,0)
#end

// Fonction 1 circuit pos 1, Actuator S, Bushing D1
#macro SWITCH_ITTE_E101SD1ABE()
  SWITCH_ITTE_BASE(1,2,1,1,1,1,0)
#end

#macro SWITCH_ITTE_E101SD1AV2BE()
  SWITCH_ITTE_BASE(1,2,1,1,2,1,0)
#end

#macro SWITCH_ITTE_E101SD1CBE()
  SWITCH_ITTE_BASE(1,2,1,1,3,1,0)
#end

// Fonction 2 circuits pos 1, Actuator S, Bushing D1
#macro SWITCH_ITTE_E201SD1ABE()
  SWITCH_ITTE_BASE(2,2,1,1,1,1,0)
#end

#macro SWITCH_ITTE_E201SD1AV2BE()
  SWITCH_ITTE_BASE(2,2,1,1,2,1,0)
#end

#macro SWITCH_ITTE_E201SD1CBE()
  SWITCH_ITTE_BASE(2,2,1,1,3,1,0)
#end

// Fonction 3 circuits pos 1, Actuator S, Bushing D1
#macro SWITCH_ITTE_E301SD1ABE()
  SWITCH_ITTE_BASE(3,2,1,1,1,1,0)
#end

#macro SWITCH_ITTE_E301SD1AV2BE()
  SWITCH_ITTE_BASE(3,2,1,1,2,1,0)
#end

#macro SWITCH_ITTE_E301SD1CBE()
  SWITCH_ITTE_BASE(3,2,1,1,3,1,0)
#end

// Fonction 1 circuit pos 1, Actuator S, Bushing D9
#macro SWITCH_ITTE_E101SD9ABE()
  SWITCH_ITTE_BASE(1,2,1,3,1,1,0)
#end

#macro SWITCH_ITTE_E101SD9AV2BE()
  SWITCH_ITTE_BASE(1,2,1,3,2,1,0)
#end

#macro SWITCH_ITTE_E101SD9CBE()
  SWITCH_ITTE_BASE(1,2,1,3,3,1,0)
#end

// Fonction 2 circuits pos 1, Actuator S, Bushing D9
#macro SWITCH_ITTE_E201SD9ABE()
  SWITCH_ITTE_BASE(2,2,1,3,1,1,0)
#end

#macro SWITCH_ITTE_E201SD9AV2BE()
  SWITCH_ITTE_BASE(2,2,1,3,2,1,0)
#end

#macro SWITCH_ITTE_E201SD9CBE()
  SWITCH_ITTE_BASE(2,2,1,3,3,1,0)
#end

// Fonction 1 circuit pos 1, Actuator S, Bushing Y
#macro SWITCH_ITTE_E101SYCBE()
  SWITCH_ITTE_BASE(1,2,1,4,3,1,0)
#end

// Fonction 2 circuits pos 1, Actuator S, Bushing Y
#macro SWITCH_ITTE_E201SYCBE()
  SWITCH_ITTE_BASE(2,2,1,4,3,1,0)
#end

// Fonction 3 circuits pos 1, Actuator S, Bushing Y
#macro SWITCH_ITTE_E301SYCBE()
  SWITCH_ITTE_BASE(3,2,1,4,3,1,3)
#end

// Fonction 1 circuit pos 1, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E101L3D1ABE()
  SWITCH_ITTE_BASE(1,3,1,1,1,1,3)
#end

#macro SWITCH_ITTE_E101L3D1AV2BE()
  SWITCH_ITTE_BASE(1,3,1,1,2,1,3)
#end

#macro SWITCH_ITTE_E101L3D1CBE()
  SWITCH_ITTE_BASE(1,3,1,1,3,1,3)
#end

// Fonction 2 circuits pos 1, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E201L3D1ABE()
  SWITCH_ITTE_BASE(2,3,1,1,1,1,3)
#end

#macro SWITCH_ITTE_E201L3D1AV2BE()
  SWITCH_ITTE_BASE(2,3,1,1,2,1,3)
#end

#macro SWITCH_ITTE_E201L3D1CBE()
  SWITCH_ITTE_BASE(2,3,1,1,3,1,3)
#end

// Fonction 3 circuits pos 1, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E301L3D1ABE()
  SWITCH_ITTE_BASE(3,3,1,1,1,1,3)
#end

#macro SWITCH_ITTE_E301L3D1AV2BE()
  SWITCH_ITTE_BASE(3,3,1,1,2,1,3)
#end

#macro SWITCH_ITTE_E301L3D1CBE()
  SWITCH_ITTE_BASE(3,3,1,1,3,1,3)
#end

// Fonction 1 circuit pos 1, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E101L3D9ABE()
  SWITCH_ITTE_BASE(1,3,1,3,1,1,3)
#end

#macro SWITCH_ITTE_E101L3D9AV2BE()
  SWITCH_ITTE_BASE(1,3,1,3,2,1,3)
#end

#macro SWITCH_ITTE_E101L3D9CBE()
  SWITCH_ITTE_BASE(1,3,1,3,3,1,3)
#end

// Fonction 2 circuits pos 1, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E201L3D9ABE()
  SWITCH_ITTE_BASE(2,3,1,3,1,1,3)
#end

#macro SWITCH_ITTE_E201L3D9AV2BE()
  SWITCH_ITTE_BASE(2,3,1,3,2,1,3)
#end

#macro SWITCH_ITTE_E201L3D9CBE()
  SWITCH_ITTE_BASE(2,3,1,3,3,1,3)
#end

// Fonction 1 circuit pos 1, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E101L3YCBE()
  SWITCH_ITTE_BASE(1,3,1,4,3,1,3)
#end

// Fonction 2 circuits pos 1, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E201L3YCBE()
  SWITCH_ITTE_BASE(2,3,1,4,3,1,3)
#end

// Fonction 3 circuits pos 1, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E301L3YCBE()
  SWITCH_ITTE_BASE(3,3,1,4,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator M, Bushing D1
#macro SWITCH_ITTE_E105MD1ABE()
  SWITCH_ITTE_BASE(1,1,2,1,1,1,0)
#end

#macro SWITCH_ITTE_E105MD1AV2BE()
  SWITCH_ITTE_BASE(1,1,2,1,2,1,0)
#end

#macro SWITCH_ITTE_E105MD1CBE()
  SWITCH_ITTE_BASE(1,1,2,1,3,1,0)
#end

// Fonction 2 circuits pos 2, Actuator M, Bushing D1
#macro SWITCH_ITTE_E205MD1ABE()
  SWITCH_ITTE_BASE(2,1,2,1,1,1,0)
#end

#macro SWITCH_ITTE_E205MD1AV2BE()
  SWITCH_ITTE_BASE(2,1,2,1,2,1,0)
#end

#macro SWITCH_ITTE_E205MD1CBE()
  SWITCH_ITTE_BASE(2,1,2,1,3,1,0)
#end

// Fonction 3 circuits pos 2, Actuator M, Bushing D1
#macro SWITCH_ITTE_E305MD1ABE()
  SWITCH_ITTE_BASE(3,1,2,1,1,1,3)
#end

#macro SWITCH_ITTE_E305MD1AV2BE()
  SWITCH_ITTE_BASE(3,1,2,1,2,1,3)
#end

#macro SWITCH_ITTE_E305MD1CBE()
  SWITCH_ITTE_BASE(3,1,2,1,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator M, Bushing D9
#macro SWITCH_ITTE_E105MD9ABE()
  SWITCH_ITTE_BASE(1,1,2,3,1,1,3)
#end

#macro SWITCH_ITTE_E105MD9AV2BE()
  SWITCH_ITTE_BASE(1,1,2,3,2,1,3)
#end

#macro SWITCH_ITTE_E105MD9CBE()
  SWITCH_ITTE_BASE(1,1,2,3,3,1,3)
#end

// Fonction 2 circuits pos 2, Actuator M, Bushing D9
#macro SWITCH_ITTE_E205MD9ABE()
  SWITCH_ITTE_BASE(2,1,2,3,1,1,3)
#end

#macro SWITCH_ITTE_E205MD9AV2BE()
  SWITCH_ITTE_BASE(2,1,2,3,2,1,3)
#end

#macro SWITCH_ITTE_E205MD9CBE()
  SWITCH_ITTE_BASE(2,1,2,3,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator M, Bushing Y
#macro SWITCH_ITTE_E105MYCBE()
  SWITCH_ITTE_BASE(1,1,2,4,3,1,0)
#end

// Fonction 2 circuits pos 2, Actuator M, Bushing Y
#macro SWITCH_ITTE_E205MYCBE()
  SWITCH_ITTE_BASE(2,1,2,4,3,1,0)
#end

// Fonction 3 circuits pos 2, Actuator M, Bushing Y
#macro SWITCH_ITTE_E305MYCBE()
  SWITCH_ITTE_BASE(3,1,2,4,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator S, Bushing D1
#macro SWITCH_ITTE_E105SD1ABE()
  SWITCH_ITTE_BASE(1,2,2,1,1,1,0)
#end

#macro SWITCH_ITTE_E105SD1AV2BE()
  SWITCH_ITTE_BASE(1,2,2,1,2,1,0)
#end

#macro SWITCH_ITTE_E105SD1CBE()
  SWITCH_ITTE_BASE(1,2,2,1,3,1,0)
#end

// Fonction 2 circuits pos 2, Actuator S, Bushing D1
#macro SWITCH_ITTE_E205SD1ABE()
  SWITCH_ITTE_BASE(2,2,2,1,1,1,0)
#end

#macro SWITCH_ITTE_E205SD1AV2BE()
  SWITCH_ITTE_BASE(2,2,2,1,2,1,0)
#end

#macro SWITCH_ITTE_E205SD1CBE()
  SWITCH_ITTE_BASE(2,2,2,1,3,1,0)
#end

// Fonction 3 circuits pos 2, Actuator S, Bushing D1
#macro SWITCH_ITTE_E305SD1ABE()
  SWITCH_ITTE_BASE(3,2,2,1,1,1,0)
#end

#macro SWITCH_ITTE_E305SD1AV2BE()
  SWITCH_ITTE_BASE(3,2,2,1,2,1,0)
#end

#macro SWITCH_ITTE_E305SD1CBE()
  SWITCH_ITTE_BASE(3,2,2,1,3,1,0)
#end

// Fonction 1 circuit pos 2, Actuator S, Bushing D9
#macro SWITCH_ITTE_E105SD9ABE()
  SWITCH_ITTE_BASE(1,2,2,3,1,1,0)
#end

#macro SWITCH_ITTE_E105SD9AV2BE()
  SWITCH_ITTE_BASE(1,2,2,3,2,1,0)
#end

#macro SWITCH_ITTE_E105SD9CBE()
  SWITCH_ITTE_BASE(1,2,2,3,3,1,0)
#end

// Fonction 2 circuits pos 2, Actuator S, Bushing D9
#macro SWITCH_ITTE_E205SD9ABE()
  SWITCH_ITTE_BASE(2,2,2,3,1,1,0)
#end

#macro SWITCH_ITTE_E205SD9AV2BE()
  SWITCH_ITTE_BASE(2,2,2,3,2,1,0)
#end

#macro SWITCH_ITTE_E205SD9CBE()
  SWITCH_ITTE_BASE(2,2,2,3,3,1,0)
#end

// Fonction 1 circuit pos 2, Actuator S, Bushing Y
#macro SWITCH_ITTE_E105SYCBE()
  SWITCH_ITTE_BASE(1,2,2,4,3,1,0)
#end

// Fonction 2 circuits pos 2, Actuator S, Bushing Y
#macro SWITCH_ITTE_E205SYCBE()
  SWITCH_ITTE_BASE(2,2,2,4,3,1,0)
#end

// Fonction 3 circuits pos 2, Actuator S, Bushing Y
#macro SWITCH_ITTE_E305SYCBE()
  SWITCH_ITTE_BASE(3,2,2,4,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E105L3D1ABE()
  SWITCH_ITTE_BASE(1,3,2,1,1,1,3)
#end

#macro SWITCH_ITTE_E105L3D1AV2BE()
  SWITCH_ITTE_BASE(1,3,2,1,2,1,3)
#end

#macro SWITCH_ITTE_E105L3D1CBE()
  SWITCH_ITTE_BASE(1,3,2,1,3,1,3)
#end

// Fonction 2 circuits pos 2, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E205L3D1ABE()
  SWITCH_ITTE_BASE(2,3,2,1,1,1,3)
#end

#macro SWITCH_ITTE_E205L3D1AV2BE()
  SWITCH_ITTE_BASE(2,3,2,1,2,1,3)
#end

#macro SWITCH_ITTE_E205L3D1CBE()
  SWITCH_ITTE_BASE(2,3,2,1,3,1,3)
#end

// Fonction 3 circuits pos 2, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E305L3D1ABE()
  SWITCH_ITTE_BASE(3,3,2,1,1,1,3)
#end

#macro SWITCH_ITTE_E305L3D1AV2BE()
  SWITCH_ITTE_BASE(3,3,2,1,2,1,3)
#end

#macro SWITCH_ITTE_E305L3D1CBE()
  SWITCH_ITTE_BASE(3,3,2,1,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E105L3D9ABE()
  SWITCH_ITTE_BASE(1,3,2,3,1,1,3)
#end

#macro SWITCH_ITTE_E105L3D9AV2BE()
  SWITCH_ITTE_BASE(1,3,2,3,2,1,3)
#end

#macro SWITCH_ITTE_E105L3D9CBE()
  SWITCH_ITTE_BASE(1,3,2,3,3,1,3)
#end

// Fonction 2 circuits pos 2, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E205L3D9ABE()
  SWITCH_ITTE_BASE(2,3,2,3,1,1,3)
#end

#macro SWITCH_ITTE_E205L3D9AV2BE()
  SWITCH_ITTE_BASE(2,3,2,3,2,1,3)
#end

#macro SWITCH_ITTE_E205L3D9CBE()
  SWITCH_ITTE_BASE(2,3,2,3,3,1,3)
#end

// Fonction 1 circuit pos 2, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E105L3YCBE()
  SWITCH_ITTE_BASE(1,3,2,4,3,1,3)
#end

// Fonction 2 circuits pos 2, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E205L3YCBE()
  SWITCH_ITTE_BASE(2,3,2,4,3,1,3)
#end

// Fonction 3 circuits pos 2, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E305L3YCBE()
  SWITCH_ITTE_BASE(3,3,2,4,3,1,3)
#end



/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=SWITCH_THT_E101MD1ABE(:THT Switch ITT Industries E101MD1ABE
//=SWITCH_THT_E101MD1AV2BE(:THT Switch ITT Industries E101MD1AV2BE
//=SWITCH_THT_E101MD1CBE(:THT Switch ITT Industries E101MD1CBE
//=SWITCH_THT_E201MD1ABE(:THT Switch ITT Industries E201MD1ABE
//=SWITCH_THT_E201MD1AV2BE(:THT Switch ITT Industries E201MD1AV2BE
//=SWITCH_THT_E201MD1CBE(:THT Switch ITT Industries E201MD1CBE
//=SWITCH_THT_E301MD1ABE(:THT Switch ITT Industries E301MD1ABE
//=SWITCH_THT_E301MD1AV2BE(:THT Switch ITT Industries E301MD1AV2BE
//=SWITCH_THT_E301MD1CBE(:THT Switch ITT Industries E301MD1CBE
//=SWITCH_THT_E101MD9ABE(:THT Switch ITT Industries E101MD9ABE
//=SWITCH_THT_E101MD9AV2BE(:THT Switch ITT Industries E101MD9AV2BE
//=SWITCH_THT_E101MD9CBE(:THT Switch ITT Industries E101MD9CBE
//=SWITCH_THT_E201MD9ABE(:THT Switch ITT Industries E201MD9ABE
//=SWITCH_THT_E201MD9AV2BE(:THT Switch ITT Industries E201MD9AV2BE
//=SWITCH_THT_E201MD9CBE(:THT Switch ITT Industries E201MD9CBE
//=SWITCH_THT_E101MYCBE(:THT Switch ITT Industries E101MYCBE
//=SWITCH_THT_E201MYCBE(:THT Switch ITT Industries E201MYCBE
//=SWITCH_THT_E301MYCBE(:THT Switch ITT Industries E301MYCBE
//=SWITCH_THT_E101SD1ABE(:THT Switch ITT Industries E101SD1ABE
//=SWITCH_THT_E101SD1AV2BE(:THT Switch ITT Industries E101SD1AV2BE
//=SWITCH_THT_E101SD1CBE(:THT Switch ITT Industries E101SD1CBE
//=SWITCH_THT_E201SD1ABE(:THT Switch ITT Industries E201SD1ABE
//=SWITCH_THT_E201SD1AV2BE(:THT Switch ITT Industries E201SD1AV2BE
//=SWITCH_THT_E201SD1CBE(:THT Switch ITT Industries E201SD1CBE
//=SWITCH_THT_E301SD1ABE(:THT Switch ITT Industries E301SD1ABE
//=SWITCH_THT_E301SD1AV2BE(:THT Switch ITT Industries E301SD1AV2BE
//=SWITCH_THT_E301SD1CBE(:THT Switch ITT Industries E301SD1CBE
//=SWITCH_THT_E101SD9ABE(:THT Switch ITT Industries E101SD9ABE
//=SWITCH_THT_E101SD9AV2BE(:THT Switch ITT Industries E101SD9AV2BE
//=SWITCH_THT_E101SD9CBE(:THT Switch ITT Industries E101SD9CBE
//=SWITCH_THT_E201SD9ABE(:THT Switch ITT Industries E201SD9ABE
//=SWITCH_THT_E201SD9AV2BE(:THT Switch ITT Industries E201SD9AV2BE
//=SWITCH_THT_E201SD9CBE(:THT Switch ITT Industries E201SD9CBE
//=SWITCH_THT_E101SYCBE(:THT Switch ITT Industries E101SYCBE
//=SWITCH_THT_E201SYCBE(:THT Switch ITT Industries E201SYCBE
//=SWITCH_THT_E301SYCBE(:THT Switch ITT Industries E301SYCBE
//=SWITCH_THT_E101L3D1ABE(:THT Switch ITT Industries E101L3D1ABE
//=SWITCH_THT_E101L3D1AV2BE(:THT Switch ITT Industries E101L3D1AV2BE
//=SWITCH_THT_E101L3D1CBE(:THT Switch ITT Industries E101L3D1CBE
//=SWITCH_THT_E201L3D1ABE(:THT Switch ITT Industries E201L3D1ABE
//=SWITCH_THT_E201L3D1AV2BE(:THT Switch ITT Industries E201L3D1AV2BE
//=SWITCH_THT_E201L3D1CBE(:THT Switch ITT Industries E201L3D1CBE
//=SWITCH_THT_E301L3D1ABE(:THT Switch ITT Industries E301L3D1ABE
//=SWITCH_THT_E301L3D1AV2BE(:THT Switch ITT Industries E301L3D1AV2BE
//=SWITCH_THT_E301L3D1CBE(:THT Switch ITT Industries E301L3D1CBE
//=SWITCH_THT_E101L3D9ABE(:THT Switch ITT Industries E101L3D9ABE
//=SWITCH_THT_E101L3D9AV2BE(:THT Switch ITT Industries E101L3D9AV2BE
//=SWITCH_THT_E101L3D9CBE(:THT Switch ITT Industries E101L3D9CBE
//=SWITCH_THT_E201L3D9ABE(:THT Switch ITT Industries E201L3D9ABE
//=SWITCH_THT_E201L3D9AV2BE(:THT Switch ITT Industries E201L3D9AV2BE
//=SWITCH_THT_E201L3D9CBE(:THT Switch ITT Industries E201L3D9CBE
//=SWITCH_THT_E101L3YCBE(:THT Switch ITT Industries E101L3YCBE
//=SWITCH_THT_E201L3YCBE(:THT Switch ITT Industries E201L3YCBE
//=SWITCH_THT_E301L3YCBE(:THT Switch ITT Industries E301L3YCBE
//=SWITCH_THT_E105MD1ABE(:THT Switch ITT Industries E105MD1ABE
//=SWITCH_THT_E105MD1AV2BE(:THT Switch ITT Industries E105MD1AV2BE
//=SWITCH_THT_E105MD1CBE(:THT Switch ITT Industries E105MD1CBE
//=SWITCH_THT_E205MD1ABE(:THT Switch ITT Industries E205MD1ABE
//=SWITCH_THT_E205MD1AV2BE(:THT Switch ITT Industries E205MD1AV2BE
//=SWITCH_THT_E205MD1CBE(:THT Switch ITT Industries E205MD1CBE
//=SWITCH_THT_E305MD1ABE(:THT Switch ITT Industries E305MD1ABE
//=SWITCH_THT_E305MD1AV2BE(:THT Switch ITT Industries E305MD1AV2BE
//=SWITCH_THT_E305MD1CBE(:THT Switch ITT Industries E305MD1CBE
//=SWITCH_THT_E105MD9ABE(:THT Switch ITT Industries E105MD9ABE
//=SWITCH_THT_E105MD9AV2BE(:THT Switch ITT Industries E105MD9AV2BE
//=SWITCH_THT_E105MD9CBE(:THT Switch ITT Industries E105MD9CBE
//=SWITCH_THT_E205MD9ABE(:THT Switch ITT Industries E205MD9ABE
//=SWITCH_THT_E205MD9AV2BE(:THT Switch ITT Industries E205MD9AV2BE
//=SWITCH_THT_E205MD9CBE(:THT Switch ITT Industries E205MD9CBE
//=SWITCH_THT_E105MYCBE(:THT Switch ITT Industries E105MYCBE
//=SWITCH_THT_E205MYCBE(:THT Switch ITT Industries E205MYCBE
//=SWITCH_THT_E305MYCBE(:THT Switch ITT Industries E305MYCBE
//=SWITCH_THT_E105SD1ABE(:THT Switch ITT Industries E105SD1ABE
//=SWITCH_THT_E105SD1AV2BE(:THT Switch ITT Industries E105SD1AV2BE
//=SWITCH_THT_E105SD1CBE(:THT Switch ITT Industries E105SD1CBE
//=SWITCH_THT_E205SD1ABE(:THT Switch ITT Industries E205SD1ABE
//=SWITCH_THT_E205SD1AV2BE(:THT Switch ITT Industries E205SD1AV2BE
//=SWITCH_THT_E205SD1CBE(:THT Switch ITT Industries E205SD1CBE
//=SWITCH_THT_E305SD1ABE(:THT Switch ITT Industries E305SD1ABE
//=SWITCH_THT_E305SD1AV2BE(:THT Switch ITT Industries E305SD1AV2BE
//=SWITCH_THT_E305SD1CBE(:THT Switch ITT Industries E305SD1CBE
//=SWITCH_THT_E105SD9ABE(:THT Switch ITT Industries E105SD9ABE
//=SWITCH_THT_E105SD9AV2BE(:THT Switch ITT Industries E105SD9AV2BE
//=SWITCH_THT_E105SD9CBE(:THT Switch ITT Industries E105SD9CBE
//=SWITCH_THT_E205SD9ABE(:THT Switch ITT Industries E205SD9ABE
//=SWITCH_THT_E205SD9AV2BE(:THT Switch ITT Industries E205SD9AV2BE
//=SWITCH_THT_E205SD9CBE(:THT Switch ITT Industries E205SD9CBE
//=SWITCH_THT_E105SYCBE(:THT Switch ITT Industries E105SYCBE
//=SWITCH_THT_E205SYCBE(:THT Switch ITT Industries E205SYCBE
//=SWITCH_THT_E305SYCBE(:THT Switch ITT Industries E305SYCBE
//=SWITCH_THT_E105L3D1ABE(:THT Switch ITT Industries E105L3D1ABE
//=SWITCH_THT_E105L3D1AV2BE(:THT Switch ITT Industries E105L3D1AV2BE
//=SWITCH_THT_E105L3D1CBE(:THT Switch ITT Industries E105L3D1CBE
//=SWITCH_THT_E205L3D1ABE(:THT Switch ITT Industries E205L3D1ABE
//=SWITCH_THT_E205L3D1AV2BE(:THT Switch ITT Industries E205L3D1AV2BE
//=SWITCH_THT_E205L3D1CBE(:THT Switch ITT Industries E205L3D1CBE
//=SWITCH_THT_E305L3D1ABE(:THT Switch ITT Industries E305L3D1ABE
//=SWITCH_THT_E305L3D1AV2BE(:THT Switch ITT Industries E305L3D1AV2BE
//=SWITCH_THT_E305L3D1CBE(:THT Switch ITT Industries E305L3D1CBE
//=SWITCH_THT_E105L3D9ABE(:THT Switch ITT Industries E105L3D9ABE
//=SWITCH_THT_E105L3D9AV2BE(:THT Switch ITT Industries E105L3D9AV2BE
//=SWITCH_THT_E105L3D9CBE(:THT Switch ITT Industries E105L3D9CBE
//=SWITCH_THT_E205L3D9ABE(:THT Switch ITT Industries E205L3D9ABE
//=SWITCH_THT_E205L3D9AV2BE(:THT Switch ITT Industries E205L3D9AV2BE
//=SWITCH_THT_E205L3D9CBE(:THT Switch ITT Industries E205L3D9CBE
//=SWITCH_THT_E105L3YCBE(:THT Switch ITT Industries E105L3YCBE
//=SWITCH_THT_E205L3YCBE(:THT Switch ITT Industries E205L3YCBE
//=SWITCH_THT_E305L3YCBE(:THT Switch ITT Industries E305L3YCBE
// end assignment
