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
 * class CIRCLE
 ******************************************************************************/
CIRCLE::CIRCLE() : 
  x(0.0),y(0.0),radius(0.0),width(0.0),layer(0) {}

void CIRCLE::Parse(attributes begin, attributes end) {
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

void HOLE::Parse(attributes begin, attributes end) {
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

void LAYER::Parse(attributes begin, attributes end) {
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

void PAD::Parse(attributes begin, attributes end) {
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

void WIRE::Parse(attributes begin, attributes end) {
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

void TEXT::Parse(attributes begin, attributes end) {
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

void RECTANGLE::Parse(attributes begin, attributes end) {
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

void SMD::Parse(attributes begin, attributes end) {
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
 * class PACKAGE
 ******************************************************************************/
PACKAGE::PACKAGE() {}

void PACKAGE::Parse(childs begin, childs end) {
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
DEVICE::DEVICE() {}

void DEVICE::Parse(attributes begin, attributes end) {
  name.clear();
  package.clear();

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());
          if (name == "name")      name       = value;
     else if (name == "package")   package    = value;
     }
}

void DEVICE::Parse(childs begin, childs end) {
  connects.clear();
  technologies.clear();

  for(auto c = begin; c != end; ++c) {
     std::string name(c->name());

     if (name == "connects") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
        //POLYGON polygon;
        //polygon.Parse(c->begin(), c->end());
        //polygon.Parse(c->attributes_begin(), c->attributes_end());
        //polygons.push_back(polygon);
           }
        }
     else if (name == "technologies") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
        //WIRE wire;
        //wire.Parse(c->attributes_begin(), c->attributes_end());
        //wires.push_back(wire);
           }
        }
     }

}

/*******************************************************************************
 * class DEVICESET
 ******************************************************************************/
DEVICESET::DEVICESET() : uservalue(false) {}

void DEVICESET::Parse(attributes begin, attributes end) {
  prefix.clear();
  uservalue = false;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());
          if (name == "name")      name       = value;
     else if (name == "prefix")    prefix     = value;
     else if (name == "uservalue") uservalue  = (value == "yes");
     }
}

void DEVICESET::Parse(childs begin, childs end) {
  description.clear();
  headline.clear();
  devices.clear();
  gates.clear();

  for(auto c = begin; c != end; ++c) {
     std::string name(c->name());
     std::string value(c->value());

     if (name == "description") {
        description = c->text().get();
        headline = HeadLine(description);
        }
     else if (name == "devices") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
        //POLYGON polygon;
        //polygon.Parse(c->begin(), c->end());
        //polygon.Parse(c->attributes_begin(), c->attributes_end());
        //polygons.push_back(polygon);
           }
        }
     else if (name == "gates") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
        //WIRE wire;
        //wire.Parse(c->attributes_begin(), c->attributes_end());
        //wires.push_back(wire);
           }
        }
     }
}

/*******************************************************************************
 * class DIMENSION
 ******************************************************************************/
DIMENSION::DIMENSION() :
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0),layer(0),
  dtype(DIMENSION_PARALLEL),width(0.0),extwidth(0.0),extlength(0.0),
  extoffset(0.0),size(0.0),ratio(8),unit(GRID_UNIT_MM),precision(2),
  visible(false) {}

void DIMENSION::Parse(attributes begin, attributes end) {
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

void FRAME::Parse(attributes begin, attributes end) {
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

void SYMBOL::Parse(childs begin, childs end) {
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
     else if (name == "pin") {
        PIN pin;
        pin.Parse(c->attributes_begin(), c->attributes_end());
        pins.push_back(pin);
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
     }
}

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
  x(0.0),y(0.0),visible_pin(true),visible_pad(true),
  length(PIN_LENGTH_LONG),direction(PIN_DIRECTION_IO),
  inverted(false),clock(false),swaplevel(0),angle(0.0) {}

void PIN::Parse(attributes begin, attributes end) {
  visible_pin = true;
  visible_pad = true;
  length = PIN_LENGTH_LONG;
  direction = PIN_DIRECTION_IO;
  inverted = false;
  clock = false;
  swaplevel = 0;
  angle = 0.0;

  for(auto a = begin; a != end; ++a) {
     std::string name(a->name());
     std::string value(a->value());

          if (name == "name")      name      = value;
     else if (name == "x")         x         = std::stod(value);
     else if (name == "y")         y         = std::stod(value);
     else if (name == "swaplevel") swaplevel = std::stoi(value);
     else if (name == "rot")       angle     = std::stod(value.substr(value.find_first_of("0123456789")));

     else if (name == "visible") {
        visible_pin = (value == "pin") or (value == "both");
        visible_pad = (value == "pad") or (value == "both");
        }
     else if (name == "length")
        Choice(length,value,
           {"point","short",
            "middle","long"},
           {PIN_LENGTH_POINT,PIN_LENGTH_SHORT,
            PIN_LENGTH_MIDDLE,PIN_LENGTH_LONG});
     else if (name == "direction")
        Choice(direction,value,
           {"nc","in","out",
            "io","oc","pwr",
            "pas","hiz","sup"},
           {PIN_DIRECTION_NC,PIN_DIRECTION_IN,PIN_DIRECTION_OUT,
            PIN_DIRECTION_IO,PIN_DIRECTION_OC,PIN_DIRECTION_PWR,
            PIN_DIRECTION_PAS,PIN_DIRECTION_HIZ,PIN_DIRECTION_SUP});
     else if (name == "function") {
        inverted = (value == "dot") or (value == "dotclk");
        clock    = (value == "clk") or (value == "dotclk");
        }
     }
}


/*******************************************************************************
 * class POLYGON
 ******************************************************************************/
POLYGON::POLYGON() :
  width(0.0),layer(0),spacing(0),pour(POLYGON_POUR_SOLID),isolate(0),
  orphans(false),thermals(true),rank(0) {}

void POLYGON::Parse(attributes begin, attributes end) {
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

void POLYGON::Parse(childs begin, childs end) {
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
     }
  }

  { /* <symbols>..</symbols> */
  auto symbols = eagle.child("drawing").child("library").child("symbols");

  for(auto s = symbols.begin(); s != symbols.end(); ++s) {
     SYMBOL symbol;
     symbol.library = lib.name;
     symbol.name = s->attributes_begin()->value();
     symbol.Parse(s->begin(),s->end());
     lib.symbols.push_back(symbol);
     }
  }

  { /* <devicesets>..</devicesets> */
  auto devicesets = eagle.child("drawing").child("library").child("devicesets");

  for(auto d = devicesets.begin(); d != devicesets.end(); ++d) {
     DEVICESET deviceset;
     deviceset.library = lib.name;
     deviceset.Parse(d->attributes_begin(),d->attributes_end());
     deviceset.Parse(d->begin(),d->end());
     lib.devicesets.push_back(deviceset);
     }
  }

  return 0;
}

