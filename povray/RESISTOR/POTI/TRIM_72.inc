/*******************************************************************************
*  TT electronics Single Turn Trimmer 72 series
*  variant 72PT (with knob) 72PTR1MEGLF
*  Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
*  Rev. 1.0 29/12/05
 * *****************************************************************************/
#macro RES_THT_TRIM_72PT(value)
  union {
     difference {
        union {
           box {
              <-4.25,-4.2,0> <4.25,+4.2,4.8>
              }
           box {
              <-4.25,+4.2,0> <4.25,+5.2,4.5>
              }
           cylinder {
              <0,0,4.8> <0,0,5> 2.5
              }
           cone {
              <0,0,5>, 4,<0,0,10.4>, 3.3
              }
           pigment {
              Gray50
              }
           }
        union {
           #for(i,1,3)
              box {
                 <-4.25+(2.125*i)-0.2,+4.6,-0.1> <-4.25+(2.125*i)+0.2,+5.3,4.6>
                 }
           #end
           #for(i,0,3)
              cylinder {
                 <-4.25+1.06+(2.125*i),+5.2,-0.1> <-4.25+1.06+(2.125*i),+5.2,4.6> 0.5
                 }
           #end
           cylinder {
              <0,0,10.1> <0,0,10.5> 3
              }
           box {
              <-0.3,-3,9.7> <+0.3,+3,10.5>
              }
           prism {
              9.5 10.5 5 <1.2, -1>, <0.25, -3>, <-0.25, -3>, <-1.2, -1>, <1.2, -1>
              rotate 90*x
              }
           #for(i,1,9)
              box {
                 <-0.25,-0.4,5.5> <0.25,+0.4,11>
                 rotate 7.45*y translate -4.7*x rotate <0,0,360/9*i> pigment {
                    Gray50
                    }
                 }
           #end
           pigment {
              Gray50
              }
           }
        }
  union {
     #local hpin=4.6;
     cylinder {
        <0,0,0> <0,0,-min(hpin,(pin_length+pcb_height))> 0.2
        translate -2.5*y
        }
     cylinder {
        <0,0,0> <0,0,-min(hpin,(pin_length+pcb_height))> 0.2
        translate -2.5*x
        }
     cylinder {
        <0,0,0> <0,0,-min(hpin,(pin_length+pcb_height))> 0.2
        translate +2.5*x
        }
     pigment {
        Silver
        }
     }
     text {
       ttf global_fontfile_arial value 0.1, 0
       scale 2
       rotate <-90,180,0>
       translate <+2.5,-4.21,+1.6>
       }
     rotate <-90,180,0>
     }
#end


/*******************************************************************************
 * no typos below please.
 ******************************************************************************/
// begin assignment
//=RES_THT_TRIM_72PT:TT electronics Single Turn Trimmer 72 series
// end assignment
