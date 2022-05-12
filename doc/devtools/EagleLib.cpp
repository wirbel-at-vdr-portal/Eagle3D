#include <sstream>
#include <iostream>
#include "../../../pugixml/src/pugixml.hpp"
#include "../../../librepfunc_git/repfunc.h"
#include "EagleLib.h"


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

template<class T>
void Flags(T& flags, bool yes, T flag) {
  if (yes)
     flags |= flag;
  else
     flags &= ~flag;
}

template<class T>
void Choice(T& result, std::string& value, std::vector<std::string> strs, std::vector<T> vals) {
  for(size_t i=0; i<strs.size(); i++) {
     if (value == strs[i]) {
        result = vals[i];
        return;
        }
     }
  std::cout << __PRETTY_FUNCTION__  << ": " << value << " not found." << std::endl;
}




/*******************************************************************************
 * class ARC
 ******************************************************************************/
//ARC::ARC() :
//  angle1(0.0), angle2(0.0), cap(0),layer(0),radius(0),width(0),
//  x1(0),y1(0),x2(0),y2(0),xc(0),yc(0) {}

/*******************************************************************************
 * class AREA
 ******************************************************************************/
AREA::AREA() : x1(0.0),y1(0.0),x2(0.0),y2(0.0) {}

/*******************************************************************************
 * class CIRCLE
 ******************************************************************************/
CIRCLE::CIRCLE() : 
  x(0.0),y(0.0),radius(0.0),width(0.0),layer(0) {}

void CIRCLE::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());
          if (name == "x")       x       = std::stod(value);
     else if (name == "y")       y       = std::stod(value);
     else if (name == "radius")  radius  = std::stod(value);
     else if (name == "width")   width   = std::stod(value);
     else if (name == "layer")   layer   = std::stoi(value);
     }
}

/*******************************************************************************
 * class GRID
 ******************************************************************************/
GRID::GRID() :
  distance(0.0),altdistance(0.0),dots(false),on(false),multiple(0),
  unit(0),altunit(0),unitdist(0),altunitdist(0) {}

/*******************************************************************************
 * class HOLE
 ******************************************************************************/
HOLE::HOLE() : x(0.0),y(0.0),drill(0.0) {}

void HOLE::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());
          if (name == "x")       x       = std::stod(value);
     else if (name == "y")       y       = std::stod(value);
     else if (name == "drill")   drill   = std::stod(value);
     }
}

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
  x(0.0),y(0.0),drill(0.0),diameter(0.0),shape(PAD_SHAPE_ROUND),angle(0.0),
  stop(true),thermals(true),first(false) {}

void PAD::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  diameter = 0.0;
  shape = PAD_SHAPE_ROUND;
  angle = 0.0;
  stop = true;
  thermals = true;
  first = false;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "name")     name     = value;
     else if (name == "x")        x        = std::stod(value);
     else if (name == "y")        y        = std::stod(value);
     else if (name == "drill")    drill    = std::stod(value);
     else if (name == "diameter") diameter = std::stod(value);
     else if (name == "rot")      angle    = std::stod(value.substr(value.find_first_of("0123456789")));
     else if (name == "stop")     stop     = (value != "no");
     else if (name == "thermals") thermals = (value != "no");
     else if (name == "first")    first    = (value == "yes");
     else if (name == "shape")
        Choice(shape, value,
           {"square","round","octagon",
            "long","offset"},
           {PAD_SHAPE_SQUARE,PAD_SHAPE_ROUND,PAD_SHAPE_OCTAGON,
            PAD_SHAPE_LONG,PAD_SHAPE_OFFSET});
     }
}

/*******************************************************************************
 * class WIRE
 ******************************************************************************/
WIRE::WIRE() :
  x1(0),y1(0),x2(0),y2(0),width(0),layer(0),style(WIRE_STYLE_CONTINUOUS),
  curve(0.0), cap(CAP_ROUND) {}

void WIRE::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  style = WIRE_STYLE_CONTINUOUS;
  curve = 0.0;
  cap = CAP_ROUND;

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
     else if (name == "style")
        Choice(style, value,{"continuous","longdash","shortdash","dashdot"},
           {WIRE_STYLE_CONTINUOUS,WIRE_STYLE_LONGDASH,
            WIRE_STYLE_SHORTDASH, WIRE_STYLE_DASHDOT});
     else if (name == "cap")
        Choice(cap, value,{"flat","round"},{CAP_FLAT,CAP_ROUND});
     }
}

/*******************************************************************************
 * class TEXT
 ******************************************************************************/
TEXT::TEXT() :
  x(0.0),y(0.0),size(0.0),layer(0),font(FONT_PROPORTIONAL),ratio(8),
  angle(0.0),mirror(false),spin(false),align(ALIGN_BOTTOM_LEFT),
  linedistance(50) {}

void TEXT::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  font = FONT_PROPORTIONAL;
  ratio = 8;
  angle = 0.0;
  align = ALIGN_BOTTOM_LEFT;
  linedistance = 50;

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
     else if (name == "align")
        Choice(align, value,
           {"bottom-left","bottom-center","bottom-right",
            "center-left","center","center-right","top-left",
           "top-center","top-right"},
           {ALIGN_BOTTOM_LEFT,ALIGN_BOTTOM_CENTER,ALIGN_BOTTOM_RIGHT,
            ALIGN_CENTER_LEFT,ALIGN_CENTER,ALIGN_CENTER_RIGHT,ALIGN_TOP_LEFT,
            ALIGN_TOP_CENTER,ALIGN_TOP_RIGHT});

     else if (name == "font")
        Choice(font, value,
           {"vector","proportional","fixed"},
           {FONT_VECTOR,FONT_PROPORTIONAL,FONT_FIXED});
     }
}

/*******************************************************************************
 * class ATTRIBUTE
 ******************************************************************************/
ATTRIBUTE::ATTRIBUTE() : constant(false), display(0) {}

/*******************************************************************************
 * class RECTANGLE
 ******************************************************************************/
RECTANGLE::RECTANGLE() : 
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),layer(0),angle(0.0) {}

void RECTANGLE::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  angle = 0.0;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "x1")       x1    = std::stod(value);
     else if (name == "y1")       y1    = std::stod(value);
     else if (name == "x2")       x2    = std::stod(value);
     else if (name == "y2")       y2    = std::stod(value);
     else if (name == "layer")    layer = std::stoi(value);
     else if (name == "rot") {
        angle  = std::stod(value.substr(value.find_first_of("0123456789")));
        }
     }
}

/*******************************************************************************
 * class SMD
 ******************************************************************************/
SMD::SMD() :
  x(0.0),y(0.0),dx(0.0),dy(0.0),layer(0),roundness(0),angle(0.0),
  stop(true),thermals(true),cream(true) {}

void SMD::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  roundness = 0;
  angle = 0.0;
  stop = true;
  thermals = true;
  cream = true;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "name")      name      = value;
     else if (name == "x")         x         = std::stod(value);
     else if (name == "y")         y         = std::stod(value);
     else if (name == "dx")        dx        = std::stod(value);
     else if (name == "dy")        dy        = std::stod(value);
     else if (name == "layer")     layer     = std::stoi(value);
     else if (name == "roundness") roundness = std::stoi(value);
     else if (name == "rot")       angle     = std::stod(value.substr(value.find_first_of("0123456789")));
     else if (name == "stop")      stop      = (value != "no");
     else if (name == "thermals")  thermals  = (value != "no");
     else if (name == "cream")     cream     = (value != "no");
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

void PACKAGE::Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end) {
  for(auto c = begin; c != end; ++c) {
     std::string name(c->name());
     std::string value(c->value());

     if (name == "description") {
        description = c->text().get();
        headline = HeadLine(description);
        }
     else if (name == "polygon") {
        POLYGON polygon;
        polygon.Parse(c->begin(), c->end());
        polygon.Parse(c->attributes_begin(), c->attributes_end());
        polygons.push_back(polygon);
        }
     else if (name == "wire") {
        WIRE wire;
        wire.Parse(c->attributes_begin(), c->attributes_end());
        wires.push_back(wire);
        }
     else if (name == "text") {
        TEXT text;
        text.value = c->text().get();
        text.Parse(c->attributes_begin(), c->attributes_end());
        texts.push_back(text);
        }
     else if (name == "dimension") {
        DIMENSION dimension;
        dimension.Parse(c->attributes_begin(), c->attributes_end());
        dimensions.push_back(dimension);
        }
     else if (name == "circle") {
        CIRCLE circle;
        circle.Parse(c->attributes_begin(), c->attributes_end());
        circles.push_back(circle);
        }
     else if (name == "rectangle") {
        RECTANGLE rectangle;
        rectangle.Parse(c->attributes_begin(), c->attributes_end());
        rectangles.push_back(rectangle);
        }
     else if (name == "frame") {
        FRAME frame;
        frame.Parse(c->attributes_begin(), c->attributes_end());
        frames.push_back(frame);
        }
     else if (name == "hole") {
        HOLE hole;
        hole.Parse(c->attributes_begin(), c->attributes_end());
        holes.push_back(hole);
        }
     else if (name == "pad") {
        PAD pad;
        pad.Parse(c->attributes_begin(), c->attributes_end());
        pads.push_back(pad);
        }
     else if (name == "smd") {
        SMD smd;
        smd.Parse(c->attributes_begin(), c->attributes_end());
        smds.push_back(smd);
        }
     }
}

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
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0),layer(0),
  dtype(DIMENSION_PARALLEL),width(0.0),extwidth(0.0),extlength(0.0),
  extoffset(0.0),size(0.0),ratio(8),unit(GRID_UNIT_MM),precision(2),
  visible(false) {}

void DIMENSION::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  dtype = DIMENSION_PARALLEL;
  extlength = 0.0;
  extoffset = 0.0;
  extwidth = 0.0;
  ratio = 8;
  unit = GRID_UNIT_MM;
  precision = 2;
  visible = false;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "x1")        x1         = std::stod(value);
     else if (name == "y1")        y1         = std::stod(value);
     else if (name == "x2")        x2         = std::stod(value);
     else if (name == "y2")        y2         = std::stod(value);
     else if (name == "x3")        x3         = std::stod(value);
     else if (name == "y3")        y3         = std::stod(value);
     else if (name == "layer")     layer      = std::stoi(value);
     else if (name == "width")     width      = std::stod(value);
     else if (name == "textsize")  size       = std::stod(value);
     else if (name == "extwidth")  extwidth   = std::stod(value);
     else if (name == "extlength") extlength  = std::stod(value);
     else if (name == "extoffset") extoffset  = std::stod(value);
     else if (name == "textratio") ratio      = std::stoi(value);
     else if (name == "visible")   visible    = (value == "yes");
     else if (name == "precision") precision  = std::stoi(value);
     else if (name == "dtype")
        Choice(dtype,value,
           {"parallel","horizontal","vertical",
            "radius","diameter","angle",
            "leader"},
           {DIMENSION_PARALLEL,DIMENSION_HORIZONTAL,DIMENSION_VERTICAL,
            DIMENSION_RADIUS,DIMENSION_DIAMETER,DIMENSION_ANGLE,
            DIMENSION_LEADER});
     else if (name == "unit")
        Choice(unit,value,
           {"mic","mm","mil","inch"},
           {GRID_UNIT_MIC,GRID_UNIT_MM,GRID_UNIT_MIL,GRID_UNIT_INCH});
     }
}

/*******************************************************************************
 * class FRAME
 ******************************************************************************/
FRAME::FRAME() :
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),columns(0),rows(0),layer(0),
  border_left(true),border_top(true),border_right(true),border_bottom(true) {}

void FRAME::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  border_left   = true;
  border_top    = true;
  border_right  = true;
  border_bottom = true;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "x1")            x1            = std::stod(value);
     else if (name == "y1")            y1            = std::stod(value);
     else if (name == "x2")            x2            = std::stod(value);
     else if (name == "y2")            y2            = std::stod(value);
     else if (name == "columns")       columns       = std::stoi(value);
     else if (name == "rows")          rows          = std::stoi(value);
     else if (name == "layer")         layer         = std::stoi(value);
     else if (name == "border-left")   border_left   = (value!="no");
     else if (name == "border-top")    border_top    = (value!="no");
     else if (name == "border-right")  border_right  = (value!="no");
     else if (name == "border-bottom") border_bottom = (value!="no");
     }
}

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
  width(0.0),layer(0),spacing(0),pour(POLYGON_POUR_SOLID),isolate(0),
  orphans(false),thermals(true),rank(0) {}

void POLYGON::Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end) {
  pour = POLYGON_POUR_SOLID;
  orphans = false;
  thermals = true;
  rank = 0;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "width")     width     = std::stod(value);
     else if (name == "layer")     layer     = std::stoi(value);
     else if (name == "spacing")   spacing   = std::stod(value);
     else if (name == "rank     ") rank      = std::stoi(value);
     else if (name == "pour")
        Choice(pour,value,
           {"solid","hatch","cutout"},
           {POLYGON_POUR_SOLID,POLYGON_POUR_HATCH,POLYGON_POUR_CUTOUT});
     else if (name == "isolate")   isolate   = std::stod(value);  // Only in <signal> or <package> context
     else if (name == "orphans")   orphans   = (value == "yes");  // Only in <signal> context
     else if (name == "thermals")  thermals  = (value != "no");   // Only in <signal> context
     }
}

void POLYGON::Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end) {
  vertices.clear();
  for(auto v = begin; v != end; ++v) {
     VERTEX vertex;
     for(auto a = v->attributes_begin(); a != v->attributes_end(); ++a) {
        std::string name(a->name());
        std::string value(a->value());
             if (name == "x")     vertex.x     = std::stod(value);
        else if (name == "y")     vertex.y     = std::stod(value);
        else if (name == "curve") vertex.curve = std::stod(value);
        }
     vertices.push_back(vertex);
     }
}





int main(int n, char** a) {
  if (n < 2) {
     std::cout << "usage: " << *a << " lib" << std::endl;
     return -1;
     }

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
  LIBRARY lib;

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
        Choice(u,value,
           {"mic","mm","mil","inch"},
           {GRID_UNIT_MIC,GRID_UNIT_MM,GRID_UNIT_MIL,GRID_UNIT_INCH});

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
     package.Parse(p->begin(),p->end());
     lib.packages.push_back(package);
/*
        {
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
           CIRCLE circle;
           circle.Parse(c->attributes_begin(), c->attributes_end());
           package.circles.push_back(circle);
           }
        else if (name == "rectangle") {
           RECTANGLE rectangle;
           rectangle.Parse(c->attributes_begin(), c->attributes_end());
           package.rectangles.push_back(rectangle);
           }
        else if (name == "frame") {
           FRAME frame;
           frame.Parse(c->attributes_begin(), c->attributes_end());
           package.frames.push_back(frame);
           }
        else if (name == "hole") {
           HOLE hole;
           hole.Parse(c->attributes_begin(), c->attributes_end());
           package.holes.push_back(hole);
           }
        else if (name == "pad") {
           PAD pad;
           pad.Parse(c->attributes_begin(), c->attributes_end());
           package.pads.push_back(pad);
           }
        else if (name == "smd") {
           SMD smd;
           smd.Parse(c->attributes_begin(), c->attributes_end());
           package.smds.push_back(smd);
           }
        }
*/
     }
  }




  return 0;
}

