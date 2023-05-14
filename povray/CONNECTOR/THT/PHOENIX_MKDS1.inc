
/*******************************************************************************
 * PCB terminal block 3.5mm pitch
 * Phoenix Contact MKDS 1/ 2-3,5
 * https://www.phoenixcontact.com/gb/products/1751248
 *
 * con-phoenix-350.lbr
 ******************************************************************************/

#macro MKDS1(pins)
  union {
     #local light_green = rgb <0.427,0.643,0.419>;
     #local a = (pins - 1) * 3.50;
     #local A = a + 3.80;


     }
#end
https://de.rs-online.com/web/p/leiterplatten-printklemmen/8024849?cm_mmc=DE-PLA-DS3A-_-google-_-CSS_DE_DE_Steckverbinder_Whoop-_-(DE:Whoop!)+Leiterplatten+Printklemmen-_-8024849&matchtype=&pla-341733767421&gclid=CjwKCAjwjYKjBhB5EiwAiFdSfoWVuuIw1PFL7JLWfkpRzopmXMct2R50zRcuczHYsAo7NoobGYDvsxoCyXEQAvD_BwE&gclsrc=aw.ds