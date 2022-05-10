#include "EagleLib.h"

/*******************************************************************************
 * class ARC
 ******************************************************************************/
ARC::ARC() :
  angle1(0.0), angle2(0.0), cap(0),layer(0),radius(0),width(0),
  x1(0),y1(0),x2(0),y2(0),xc(0),yc(0) {}

/*******************************************************************************
 * class AREA
 ******************************************************************************/
AREA::AREA() : x1(0),y1(0),x2(0),y2(0) {}

/*******************************************************************************
 * class CIRCLE
 ******************************************************************************/
CIRCLE::CIRCLE() : layer(0),radius(0),width(0),x(0),y(0) {}

/*******************************************************************************
 * class GRID
 ******************************************************************************/
GRID::GRID() :
  distance(0.0),altdistance(0.0),dots(false),on(false),multiple(0),
  unit(0),altunit(0),unitdist(0),altunitdist(0) {}

/*******************************************************************************
 * class HOLE
 ******************************************************************************/
HOLE::HOLE() : diameter(),drill(0),drillsymbol(0),x(0),y(0) {}

/*******************************************************************************
 * class LAYER
 ******************************************************************************/
LAYER::LAYER() : used(false),visible(false),color(0),fill(0),number(0) {}

/*******************************************************************************
 * class PAD
 ******************************************************************************/
PAD::PAD() :
  angle(0.0),diameter(),shape(),drill(0),drillsymbol(0),
  elongation(0),flags(0),x(0),y(0) {}

/*******************************************************************************
 * class WIRE
 ******************************************************************************/
WIRE::WIRE() :
  cap(0),curve(0.0),layer(0),style(0),width(0),
  x1(0),y1(0),x2(0),y2(0) {}


/*******************************************************************************
 * class TEXT
 ******************************************************************************/
TEXT::TEXT() :
  align(0),angle(0.0),font(0),layer(0),linedistance(0),mirror(0),
  ratio(0),size(0),spin(0),x(0),y(0) {}

/*******************************************************************************
 * class ATTRIBUTE
 ******************************************************************************/
ATTRIBUTE::ATTRIBUTE() : constant(false), display(0) {}

/*******************************************************************************
 * class RECTANGLE
 ******************************************************************************/
RECTANGLE::RECTANGLE() : angle(0.0),layer(0),x1(0),y1(0),x2(0),y2(0) {}

/*******************************************************************************
 * class SMD
 ******************************************************************************/
SMD::SMD() : angle(0.0),dx(),dy(),flags(0),layer(0),roundness(0),x(0),y(0) {}

/*******************************************************************************
 * class CONTACT
 ******************************************************************************/
CONTACT::CONTACT() : x(0),y(0) {}

/*******************************************************************************
 * class PACKAGE
 ******************************************************************************/
PACKAGE::PACKAGE() {}

/*******************************************************************************
 * class DEVICE
 ******************************************************************************/
DEVICE::DEVICE() : value(false) {}

/*******************************************************************************
 * class DEVICESET
 ******************************************************************************/
DEVICESET::DEVICESET() : activedevice(nullptr),value(false) {}

/*******************************************************************************
 * class DIMENSION
 ******************************************************************************/
DIMENSION::DIMENSION() :
  visible(false),dtype(0),extlength(0),extoffset(0),
  extwidth(0),layer(0),precision(0),ratio(0),size(0),
  unit(0),width(0),x1(0),y1(0),x2(0),y2(0),x3(0),y3(0) {}

/*******************************************************************************
 * class FRAME
 ******************************************************************************/
FRAME::FRAME() : columns(0),rows(0),border(0),layer(0),x1(0),y1(0),x2(0),y2(0) {}

/*******************************************************************************
 * class SYMBOL
 ******************************************************************************/
SYMBOL::SYMBOL() {}

/*******************************************************************************
 * class GATE
 ******************************************************************************/
GATE::GATE() : addlevel(0),swaplevel(0),x(0),y(0) {}

/*******************************************************************************
 * class LIBRARY
 ******************************************************************************/
LIBRARY::LIBRARY() : alwaysvectorfont(false), verticaltextdown(false) {}

/*******************************************************************************
 * class PIN
 ******************************************************************************/
PIN::PIN() :
  angle(0.0),direction(0),function(0),length(0),route(0),swaplevel(0),
  visible(0),x(0),y(0) {}

/*******************************************************************************
 * class POLYGON
 ******************************************************************************/
POLYGON::POLYGON() :
  isolate(0),layer(0),orphans(false),pour(0),rank(0),
  spacing(0),thermals(false),width(0) {}




#include <sstream>
#include <iostream>
#include "../../../pugixml/src/pugixml.hpp"
#include "../../../librepfunc_git/repfunc.h"

int main(int n, char** a) {
  LIBRARY lib;
  std::string progname(*a);
  std::vector<std::string> args;
  for(int i=1; i<n; i++)
     args.push_back(a[i]);



  //std::cout << args[0] << std::endl;

  pugi::xml_document doc;
  auto result = doc.load_file(args[0].c_str());

  if (not result) {
     std::cerr << "Parsing " << args[0] << "failed. :-(" << std::endl;
     return -1;
     }

  ReplaceAll(args[0], ".lbr", "");
  
  pugi::xml_node eagle = doc.child("eagle");


  { /* <settings>..</settings> */
  auto settings = eagle.child("drawing").child("settings");
  for(auto s = settings.begin(); s != settings.end(); ++s) {
     auto a = s->attributes_begin();
     std::string name(a->name());
     std::string value(a->value());
          if (name == "alwaysvectorfont") lib.alwaysvectorfont = (value == "yes");
     else if (name == "verticaltext")     lib.verticaltextdown = (value == "down");
     }
  }

  { /* <grid .. /> */
  auto grid = eagle.child("drawing").child("grid");
  for(auto a = grid.attributes_begin(); a != grid.attributes_end(); ++a) {
     std::string name(a->name());
     std::string value(a->value());
     if ((name == "distance") or (name == "altdistance")) {
        double d = std::stod(value);
        if (name == "distance") lib.grid.distance    = d;
        else                    lib.grid.altdistance = d;
        }
     else if ((name == "unit")     or (name == "altunit") or
              (name == "unitdist") or (name == "altunitdist")) {
        int u;

             if (value == "inch") u = GRID_UNIT_INCH;
        else if (value == "mm")   u = GRID_UNIT_MM;
        else if (value == "mil")  u = GRID_UNIT_MIL;
        else                      u = GRID_UNIT_MIC;

             if (name == "unit")       lib.grid.unit        = u;
        else if (name == "altunit")    lib.grid.altunit     = u;
        else if (name == "unitdist")   lib.grid.unitdist    = u;
        else                           lib.grid.altunitdist = u;
        }
     else if (name == "style") {
        lib.grid.dots = value != "lines";
        }
     else if (name == "multiple") {
        lib.grid.multiple = std::stoi(value);
        }
     else if (name == "display") {
        lib.grid.on = (value != "no");
        }
     }

  }

  { /* <layers>..</layers> */
  auto layers = eagle.child("drawing").child("layers");
  for(auto l = layers.begin(); l != layers.end(); ++l) {
     LAYER layer;
     for(auto a = l->attributes_begin(); a != l->attributes_end(); ++a) {
        std::string name(a->name());
        std::string value(a->value());

        if (name == "number")
           layer.number = std::stod(value);
        else if (name == "name")
           layer.name = value;
        else if (name == "color")
           layer.color = std::stod(value);
        else if (name == "fill")
           layer.fill = std::stod(value);
        else if (name == "visible")
           layer.visible = (value != "no");
        else if (name == "active")
           layer.used = (value != "no");
        }
     lib.layers.push_back(layer);
     }
  }

  { /* <description>..</description> */
  auto libname = args[0];
  ReplaceAll(libname, ".lbr", "");
  lib.name = SplitStr(libname, '/').back();

  auto description = eagle.child("drawing").child("library").child("description");
  std::string text(description.text().get());
  lib.description = text;

  std::stringstream ss;
  ss << text;

  std::getline(ss, text);
  ReplaceAll(text, "<b>", ""); ReplaceAll(text, "</b>", "");
  ReplaceAll(text, "<B>", ""); ReplaceAll(text, "</B>", "");
  ReplaceAll(text, "<i>", ""); ReplaceAll(text, "</i>", "");
  ReplaceAll(text, "<I>", ""); ReplaceAll(text, "</I>", "");
  ReplaceAll(text, "<p>", ""); ReplaceAll(text, "</p>", "");
  ReplaceAll(text, "<P>", ""); ReplaceAll(text, "</P>", "");
  ReplaceAll(text, "<br>", ""); ReplaceAll(text, "</br>", "");
  ReplaceAll(text, "<BR>", ""); ReplaceAll(text, "</BR>", "");
  lib.headline = text;
  }

  { /* <packages>..</packages> */
  auto packages = eagle.child("drawing").child("library").child("packages");

  for(auto p = packages.begin(); p != packages.end(); ++p) {
     PACKAGE package;

     package.library = lib.name;

     for(auto a = p->attributes_begin(); a != p->attributes_end(); ++a) {
        if (std::string(a->name()) == "name")
           package.name = a->value();
        }

     for(auto c = p->begin(); c != p->end(); ++c) {
        std::string name(c->name());
        std::string value(c->value());

        if (name == "description") {
           package.description = c->text().get();
           std::stringstream ss;
           std::string text;
           ss << package.description;
           std::getline(ss, text);
           ReplaceAll(text, "<b>", ""); ReplaceAll(text, "</b>", "");
           ReplaceAll(text, "<B>", ""); ReplaceAll(text, "</B>", "");
           ReplaceAll(text, "<i>", ""); ReplaceAll(text, "</i>", "");
           ReplaceAll(text, "<I>", ""); ReplaceAll(text, "</I>", "");
           ReplaceAll(text, "<p>", ""); ReplaceAll(text, "</p>", "");
           ReplaceAll(text, "<P>", ""); ReplaceAll(text, "</P>", "");
           ReplaceAll(text, "<br>", ""); ReplaceAll(text, "</br>", "");
           ReplaceAll(text, "<BR>", ""); ReplaceAll(text, "</BR>", "");
           package.headline = text;
           }


/*
<wire x1="-3.65" y1="1.15" x2="3.65" y2="1.15" width="0.2032" layer="21"/>
<wire x1="3.65" y1="1.15" x2="3.65" y2="-1.15" width="0.2032" layer="21"/>
<wire x1="3.65" y1="-1.15" x2="-3.65" y2="-1.15" width="0.2032" layer="21"/>
<wire x1="-3.65" y1="-1.15" x2="-3.65" y2="1.15" width="0.2032" layer="21"/>
<smd name="1A" x="-1.95" y="-0.725" dx="1" dy="1.45" layer="1"/>
<smd name="1B" x="-3.05" y="0.725" dx="1" dy="1.45" layer="1"/>
<smd name="2A" x="0.55" y="-0.725" dx="1" dy="1.45" layer="1"/>
<smd name="2B" x="-0.55" y="0.725" dx="1" dy="1.45" layer="1"/>
<smd name="3A" x="3.05" y="-0.725" dx="1" dy="1.45" layer="1"/>
<smd name="3B" x="1.95" y="0.725" dx="1" dy="1.45" layer="1"/>
<text x="-3.81" y="1.905" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>

<rectangle x1="-3.048" y1="-3.048" x2="3.048" y2="3.048" layer="39"/>

<polygon width="0" layer="94">
<vertex x="-6.35" y="-5.08"/>
<vertex x="-6.35" y="-2.54"/>
<vertex x="-2.54" y="-3.81"/>
</polygon>

<hole x="1.15" y="0" drill="0.95"/>


<frame x1="0" y1="11.049" x2="284.48" y2="200.66" columns="19" rows="8" layer="94" border-right="no" border-bottom="no"/>

<dimension x1="-6" y1="-3" x2="0" y2="-2.75" x3="-3" y3="-4.75" textsize="1.27" layer="47" dtype="horizontal" width="0.05" extwidth="0.01" visible="yes"/>

*/



        }

/*
class PACKAGE {
public:


  AREA area;

  // Loop members
  std::vector<CIRCLE> circles;
  std::vector<CONTACT> contacts;
  std::vector<DIMENSION> dimensions;
  std::vector<FRAME> frames;
  std::vector<HOLE> holes;
  std::vector<POLYGON> polygons;
  std::vector<RECTANGLE> rectangles;
  std::vector<TEXT> texts;
  std::vector<WIRE> wires;
public:
  PACKAGE();
};


*/




/*     LAYER layer;
     for(auto a = l->attributes_begin(); a != l->attributes_end(); ++a) {
        std::string name(a->name());
        std::string value(a->value());

        if (name == "number")
           layer.number = std::stod(value);
        else if (name == "name")
           layer.name = value;
        else if (name == "color")
           layer.color = std::stod(value);
        else if (name == "fill")
           layer.fill = std::stod(value);
        else if (name == "visible")
           layer.visible = (value != "no");
        else if (name == "active")
           layer.used = (value != "no");
        }
     lib.layers.push_back(layer);
*/
     }
  }




  return 0;
}

