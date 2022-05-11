#include <sstream>
#include <iostream>
#include "../../../pugixml/src/pugixml.hpp"
#include "../../../librepfunc_git/repfunc.h"
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
LAYER::LAYER() : used(true),visible(true),color(0),fill(0),number(0) {}

void LAYER::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  used    = true;
  visible = true;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());
          if (name == "number")  number  = std::stod(value);
     else if (name == "name")    name    = value;
     else if (name == "color")   color   = std::stod(value);
     else if (name == "fill")    fill    = std::stod(value);
     else if (name == "visible") visible = (value != "no");
     else if (name == "active")  used    = (value != "no");
     }
}

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
  cap(CAP_ROUND),curve(0.0),layer(0),style(WIRE_STYLE_CONTINUOUS),width(0),
  x1(0),y1(0),x2(0),y2(0) {}

void WIRE::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());
          if (name == "x1")     x1    = std::stod(value);
     else if (name == "y1")     y1    = std::stod(value);
     else if (name == "x2")     x2    = std::stod(value);
     else if (name == "y2")     y2    = std::stod(value);
     else if (name == "width")  width = std::stod(value);
     else if (name == "layer")  layer = std::stoi(value);
     else if (name == "curve")  curve = std::stod(value);
     else if (name == "extent") extent = value; // Only applicable for airwires
     else if (name == "style") {
        if      (value == "continuous") style = WIRE_STYLE_CONTINUOUS;
        else if (value == "longdash")   style = WIRE_STYLE_LONGDASH;
        else if (value == "shortdash")  style = WIRE_STYLE_SHORTDASH;
        else if (value == "dashdot")    style = WIRE_STYLE_DASHDOT;
        }
     else if (name == "cap") {
        // Only applicable if 'curve' is not zero
        if (value == "flat") cap = CAP_FLAT;
        else                 cap = CAP_ROUND;
        }
     else {
        std::cerr << __PRETTY_FUNCTION__ << " unknown attribute '" << name << "'" << std::endl;
        exit(-1);
        }
     }
}

/*******************************************************************************
 * class TEXT
 ******************************************************************************/
TEXT::TEXT() :
  align(ALIGN_BOTTOM_LEFT),angle(0.0),font(FONT_PROPORTIONAL),layer(0),
  linedistance(50),mirror(false),ratio(8),size(0.0),spin(false),x(0.0),y(0.0) {}

void TEXT::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "x")        x     = std::stod(value);
     else if (name == "y")        y     = std::stod(value);
     else if (name == "size")     size  = std::stod(value);
     else if (name == "layer")    layer = std::stoi(value);
     else if (name == "distance") linedistance = std::stoi(value);
     else if (name == "ratio")    ratio = std::stoi(value);
     else if (name == "rot") {
        angle  = std::stod(value.substr(value.find_first_of("0123456789")));
        mirror = value.find("M") != std::string::npos;
        spin   = value.find("S") != std::string::npos;
        }
     else if (name == "align") {
             if (value == "bottom-left")   align = ALIGN_BOTTOM_LEFT;
        else if (value == "bottom-center") align = ALIGN_BOTTOM_CENTER;
        else if (value == "bottom-right")  align = ALIGN_BOTTOM_RIGHT;
        else if (value == "center-left")   align = ALIGN_CENTER_LEFT;
        else if (value == "center")        align = ALIGN_CENTER;
        else if (value == "center-right")  align = ALIGN_CENTER_RIGHT;
        else if (value == "top-left")      align = ALIGN_TOP_LEFT;
        else if (value == "top-center")    align = ALIGN_TOP_CENTER;
        else if (value == "top-right")     align = ALIGN_TOP_RIGHT;
        }
     else if (name == "font") {
             if (value == "vector")       font = FONT_VECTOR;
        else if (value == "proportional") font = FONT_PROPORTIONAL;
        else if (value == "fixed")        font = FONT_FIXED;
        }
     else {
        std::cerr << "TEXT unknown: " << name << "=\"" << value << "\"" << std::endl;
        }
     }
}

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
SMD::SMD() : angle(0.0),dx(0.0),dy(0.0),flags(7),layer(0),roundness(0),x(0),y(0) {}

void SMD::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "name")      name      = value;
     else if (name == "x")         x         = std::stod(value);
     else if (name == "y")         y         = std::stod(value);
     else if (name == "dx")        dx        = std::stod(value);
     else if (name == "dy")        dy        = std::stoi(value);
     else if (name == "layer")     layer     = std::stoi(value);
     else if (name == "roundness") roundness = std::stoi(value);
     else if (name == "rot")       angle     = std::stod(value.substr(1));
     else if ((name == "stop")     and (value == "no")) flags &= ~SMD_FLAG_STOP;
     else if ((name == "thermals") and (value == "no")) flags &= ~SMD_FLAG_THERMALS;
     else if ((name == "cream")    and (value == "no")) flags &= ~SMD_FLAG_CREAM;
     }
}

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
  extwidth(0),layer(0),precision(0),ratio(0),size(0.0),
  unit(0),width(0.0),x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0) {}

void DIMENSION::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

     // textsize="0.8" layer="47" dtype="horizontal" width="0.05" extwidth="0.01" visible="yes"/>
          if (name == "x1")        x1        = std::stod(value);
     else if (name == "y1")        y1        = std::stod(value);
     else if (name == "x2")        x2        = std::stod(value);
     else if (name == "y2")        y2        = std::stod(value);
     else if (name == "x3")        x3        = std::stod(value);
     else if (name == "y3")        y3        = std::stod(value);



     }
}

/*



          if (name == "width")     width     = std::stod(value);
     else if (name == "layer")     layer     = std::stoi(value);
     else if (name == "spacing")   spacing   = std::stod(value);
     else if (name == "rank     ") rank      = std::stoi(value);
     else if (name == "pour") {
        if      (value == "solid")   pour = POLYGON_POUR_SOLID;
        else if (value == "hatch")   pour = POLYGON_POUR_HATCH;
        else if (value == "cutout")  pour = POLYGON_POUR_CUTOUT;
        }
     else if (name == "isolate")   isolate   = std::stod(value);           // Only in <signal> or <package> context
     else if ((name == "orphans")  and (value == "yes")) orphans  = true;  // Only in <signal> context
     else if ((name == "thermals") and (value == "no"))  thermals = false; // Only in <signal> context


<!ELEMENT dimension EMPTY>
<!ATTLIST dimension

          layer         %Layer;        #REQUIRED
          dtype         %DimensionType; "parallel"
          width         %Dimension;    #REQUIRED
          extwidth      %Dimension;    "0"
          extlength     %Dimension;    "0"
          extoffset     %Dimension;    "0"
          textsize      %Dimension;    #REQUIRED
          textratio     %Int;          "8"
          unit          %GridUnit;     "mm"
          precision     %Int;          "2"
          visible       %Bool;         "no"
          >
  bool visible;                         // int (0=off, 1=on)
  int dtype;                            // DIMENSION_{PARALLEL,HORIZONTAL,VERTICAL,RADIUS,DIAMETER,ANGLE,LEADER}
  int extlength;                        //
  int extoffset;                        //
  int extwidth;                         //
  int layer;                            //
  int precision;                        // (Genauigkeit der Massangabe)
  int ratio;                            //
  int size;                             //
  int unit;                             // Einheit: GRID_UNIT_{MIC,MM,MIL,INCH}
  int width;                            //
  int x1, y1;                           // (erster Bezugspunkt)
  int x2, y2;                           // (zweiter Bezugspunkt)
  int x3, y3;                           // (Hilfspunkt für die Ausrichtung)
"(parallel | horizontal | vertical | radius | diameter | leader)">
*/

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
 * class VERTEX {
 ******************************************************************************/
VERTEX::VERTEX() : curve(0) {}

/*******************************************************************************
 * class POLYGON
 ******************************************************************************/
POLYGON::POLYGON() :
  isolate(0),layer(0),orphans(false),pour(POLYGON_POUR_SOLID),rank(0),
  spacing(0),thermals(true),width(0.0) {}

void POLYGON::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "width")     width     = std::stod(value);
     else if (name == "layer")     layer     = std::stoi(value);
     else if (name == "spacing")   spacing   = std::stod(value);
     else if (name == "rank     ") rank      = std::stoi(value);
     else if (name == "pour") {
        if      (value == "solid")   pour = POLYGON_POUR_SOLID;
        else if (value == "hatch")   pour = POLYGON_POUR_HATCH;
        else if (value == "cutout")  pour = POLYGON_POUR_CUTOUT;
        }
     else if (name == "isolate")   isolate   = std::stod(value);           // Only in <signal> or <package> context
     else if ((name == "orphans")  and (value == "yes")) orphans  = true;  // Only in <signal> context
     else if ((name == "thermals") and (value == "no"))  thermals = false; // Only in <signal> context
     }
}

void POLYGON::Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end) {
  std::vector<VERTEX> vertexes;
  for(auto v = begin; v != end; ++v) {
     VERTEX vertex;

     for(auto a = v->attributes_begin(); a != v->attributes_end(); ++a) {
        std::string name(a->name());
        std::string value(a->value());
             if (name == "x")     vertex.x     = std::stod(value);
        else if (name == "y")     vertex.y     = std::stod(value);
        else if (name == "curve") vertex.curve = std::stod(value);
        }
     vertexes.push_back(vertex);
     }

  for(auto it=vertexes.begin(); it!=(vertexes.end()-1); it++) {
     WIRE wire;
     wire.layer = layer;
     wire.width = width;
     wire.x1    = it->x;
     wire.y1    = it->y;
     wire.x2    = (it+1)->x;
     wire.y2    = (it+1)->y;
     wire.curve = it->curve;
     wires.push_back(wire);
     }  
}





/*******************************************************************************
 * extract headline from description.
 ******************************************************************************/

std::string HeadLine(std::string& Description) {
  std::stringstream ss;
  ss << Description;

  std::string headline;
  std::getline(ss, headline);
  ReplaceAll(headline, "<b>", ""); ReplaceAll(headline, "</b>", "");
  ReplaceAll(headline, "<B>", ""); ReplaceAll(headline, "</B>", "");
  ReplaceAll(headline, "<i>", ""); ReplaceAll(headline, "</i>", "");
  ReplaceAll(headline, "<I>", ""); ReplaceAll(headline, "</I>", "");
  ReplaceAll(headline, "<p>", ""); ReplaceAll(headline, "</p>", "");
  ReplaceAll(headline, "<P>", ""); ReplaceAll(headline, "</P>", "");
  ReplaceAll(headline, "<br>", ""); ReplaceAll(headline, "</br>", "");
  ReplaceAll(headline, "<BR>", ""); ReplaceAll(headline, "</BR>", "");
  return headline;
}


int main(int n, char** a) {
  LIBRARY lib;
  std::string progname(*a);
  std::vector<std::string> args;
  for(int i=1; i<n; i++)
     args.push_back(a[i]);



  std::cout << args[0] << std::endl;

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
     layer.Parse(l->attributes_begin(),l->attributes_end());
     lib.layers.push_back(layer);
     }
  }

  { /* <description>..</description> */
  auto libname = args[0];
  ReplaceAll(libname, ".lbr", "");
  lib.name = SplitStr(libname, '/').back();

  auto description = eagle.child("drawing").child("library").child("description");
  lib.description = description.text().get();
  lib.headline = HeadLine(lib.description);
  }

  { /* <packages>..</packages> */
  auto packages = eagle.child("drawing").child("library").child("packages");

  for(auto p = packages.begin(); p != packages.end(); ++p) {
     PACKAGE package;

     package.library = lib.name;
     package.name = p->attributes_begin()->value();

     for(auto c = p->begin(); c != p->end(); ++c) {
        std::string name(c->name());
        std::string value(c->value());

        if (name == "description") {
           package.description = c->text().get();
           package.headline = HeadLine(package.description);
           }
        else if (name == "polygon") {
           POLYGON polygon;
           polygon.Parse(c->begin(), c->end());
           polygon.Parse(c->attributes_begin(), c->attributes_end());
           package.polygons.push_back(polygon);
           }
        else if (name == "wire") {
           WIRE wire;
           wire.Parse(c->attributes_begin(), c->attributes_end());
           package.wires.push_back(wire);
           }
        else if (name == "text") {
           TEXT text;
           text.value = c->text().get();
           text.Parse(c->attributes_begin(), c->attributes_end());
           package.texts.push_back(text);
           }
        else if (name == "dimension") {
           DIMENSION dimension;
           dimension.Parse(c->attributes_begin(), c->attributes_end());
           package.dimensions.push_back(dimension);
           }
        else if (name == "circle") {
      //   CIRCLE circle;
      //   circle.Parse(c->attributes_begin(), c->attributes_end());
      //   package.circles.push_back(circle);
           }
        else if (name == "rectangle") {
      //   RECTANGLE rectangle;
      //   rectangle.Parse(c->attributes_begin(), c->attributes_end());
      //   package.rectangles.push_back(rectangle);
           }
        else if (name == "frame") {
      //   FRAME frame;
      //   frame.Parse(c->attributes_begin(), c->attributes_end());
      //   package.frames.push_back(frame);
           }
        else if (name == "hole") {
      //   HOLE hole;
      //   hole.Parse(c->attributes_begin(), c->attributes_end());
      //   package.holes.push_back(hole);
           }
        else if (name == "pad") {
      //   PAD pad;
      //   pad.Parse(c->attributes_begin(), c->attributes_end());
      //   package.pads.push_back(pad);
           }
        else if (name == "smd") {
           SMD smd;
           smd.Parse(c->attributes_begin(), c->attributes_end());
           package.smds.push_back(smd);
           }
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

