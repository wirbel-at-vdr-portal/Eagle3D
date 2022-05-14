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
  ReplaceAll(headline, "&lt;", ""); ReplaceAll(headline, "&gt;", "");
  ReplaceAll(headline, "&LT;", ""); ReplaceAll(headline, "&GT;", "");
  return headline;
}

template<class T> void Choice(T& result, std::string& value, std::vector<std::string> strs, std::vector<T> vals) {
  for(size_t i=0; i<strs.size(); i++) {
     if (value == strs[i]) {
        result = vals[i];
        return;
        }
     }
  std::cout << __PRETTY_FUNCTION__  << ": " << value << " not found." << std::endl;
}

/*******************************************************************************
 * class ATTRIBUTE
 ******************************************************************************/
ATTRIBUTE::ATTRIBUTE() :
  x(0.0),y(0.0),size(0.0),layer(0),font("proportional"),ratio(0),
  angle(0.0),showvalue(true),showname(false),constant(false) {}

void ATTRIBUTE::Parse(attributes begin, attributes end) {
  x = 0.0;
  y = 0.0;
  size = 0.0;
  layer = 0;
  font = "proportional";
  ratio = 0;
  angle = 0.0;
  showvalue = true;
  showname = false;
  constant = false;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "name")     name     = Value;
     else if (Name == "value")    value    = Value;
     else if (Name == "x")        x        = std::stod(Value);
     else if (Name == "y")        y        = std::stod(Value);
     else if (Name == "size")     size     = std::stod(Value);
     else if (Name == "layer")    layer    = std::stoi(Value);
     else if (Name == "font")     font     = Value;
     else if (Name == "ratio")    ratio    = std::stoi(Value);
     else if (Name == "rot")      angle    = std::stod(Value.substr(Value.find_first_of("0123456789")));
     else if (Name == "display") {
        showvalue = (Value == "value") or (Value == "both");
        showname  = (Value == "name")  or (Value == "both");
        }
     else if (Name == "constant") constant = (Value == "yes");
     }
}

/*******************************************************************************
 * class CIRCLE
 ******************************************************************************/
CIRCLE::CIRCLE() : 
  x(0.0),y(0.0),radius(0.0),width(0.0),layer(0) {}

void CIRCLE::Parse(attributes begin, attributes end) {
  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "x")       x       = std::stod(Value);
     else if (Name == "y")       y       = std::stod(Value);
     else if (Name == "radius")  radius  = std::stod(Value);
     else if (Name == "width")   width   = std::stod(Value);
     else if (Name == "layer")   layer   = std::stoi(Value);
     }
}

/*******************************************************************************
 * class CONNECT
 ******************************************************************************/
CONNECT::CONNECT() : route_all(true) {}

void CONNECT::Parse(attributes begin, attributes end) {
  gate.clear();
  pin.clear();
  pad.clear();
  route_all = true;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "gate")      gate       = Value;
     else if (Name == "pin")       pin        = Value;
     else if (Name == "pad")       pad        = Value;
     else if (Name == "route")     route_all  = (Value != "any");
     }
}

/*******************************************************************************
 * class DIMENSION
 ******************************************************************************/
DIMENSION::DIMENSION() :
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0),layer(0),
  dtype("parallel"),width(0.0),extwidth(0.0),extlength(0.0),
  extoffset(0.0),size(0.0),ratio(8),unit("mm"),precision(2),
  visible(false) {}

void DIMENSION::Parse(attributes begin, attributes end) {
  dtype = "parallel";
  extlength = 0.0;
  extoffset = 0.0;
  extwidth = 0.0;
  ratio = 8;
  unit = "mm";
  precision = 2;
  visible = false;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "x1")        x1         = std::stod(Value);
     else if (Name == "y1")        y1         = std::stod(Value);
     else if (Name == "x2")        x2         = std::stod(Value);
     else if (Name == "y2")        y2         = std::stod(Value);
     else if (Name == "x3")        x3         = std::stod(Value);
     else if (Name == "y3")        y3         = std::stod(Value);
     else if (Name == "layer")     layer      = std::stoi(Value);
     else if (Name == "dtype")     dtype      = Value;
     else if (Name == "width")     width      = std::stod(Value);
     else if (Name == "textsize")  size       = std::stod(Value);
     else if (Name == "extwidth")  extwidth   = std::stod(Value);
     else if (Name == "extlength") extlength  = std::stod(Value);
     else if (Name == "extoffset") extoffset  = std::stod(Value);
     else if (Name == "textratio") ratio      = std::stoi(Value);
     else if (Name == "unit")      unit       = Value;
     else if (Name == "precision") precision  = std::stoi(Value);
     else if (Name == "visible")   visible    = (Value == "yes");
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
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "x1")            x1            = std::stod(Value);
     else if (Name == "y1")            y1            = std::stod(Value);
     else if (Name == "x2")            x2            = std::stod(Value);
     else if (Name == "y2")            y2            = std::stod(Value);
     else if (Name == "columns")       columns       = std::stoi(Value);
     else if (Name == "rows")          rows          = std::stoi(Value);
     else if (Name == "layer")         layer         = std::stoi(Value);
     else if (Name == "border-left")   border_left   = (Value!="no");
     else if (Name == "border-top")    border_top    = (Value!="no");
     else if (Name == "border-right")  border_right  = (Value!="no");
     else if (Name == "border-bottom") border_bottom = (Value!="no");
     }
}

/*******************************************************************************
 * class GATE
 ******************************************************************************/
GATE::GATE() : x(0.0),y(0.0),addlevel("next"),swaplevel(0) {}

void GATE::Parse(attributes begin, attributes end) {
  name.clear();
  symbol.clear();
  x = 0.0;
  y = 0.0;
  addlevel = "next";
  swaplevel = 0;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "name")      name      = Value;
     else if (Name == "symbol")    symbol    = Value;
     else if (Name == "x")         x         = std::stod(Value);
     else if (Name == "y")         y         = std::stod(Value);
     else if (Name == "addlevel")  addlevel  = Value;
     else if (Name == "swaplevel") swaplevel = std::stoi(Value);
     }
}

/*******************************************************************************
 * class GRID
 ******************************************************************************/
GRID::GRID() :
  distance(0.0),unitdist("mm"),unit("mm"),style("lines"),multiple(1),
  display(false),altdistance(0.0),altunitdist("mm"),altunit("mm") {}

void GRID::Parse(attributes begin, attributes end) {
  style = "lines";
  multiple = 1;
  display = false;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "distance")      distance      = std::stod(Value);
     else if (Name == "unitdist")      unitdist      = Value;
     else if (Name == "unit")          unit          = Value;
     else if (Name == "style")         style         = Value;
     else if (Name == "multiple")      multiple      = std::stoi(Value);
     else if (Name == "display")       display       = (Value == "yes");
     else if (Name == "altdistance")   altdistance   = std::stod(Value);
     else if (Name == "altunitdist")   altunitdist   = Value;
     else if (Name == "altunit")       altunit       = Value;
     }
}

/*******************************************************************************
 * class HOLE
 ******************************************************************************/
HOLE::HOLE() : x(0.0),y(0.0),drill(0.0) {}

void HOLE::Parse(attributes begin, attributes end) {
  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "x")       x       = std::stod(Value);
     else if (Name == "y")       y       = std::stod(Value);
     else if (Name == "drill")   drill   = std::stod(Value);
     }
}

/*******************************************************************************
 * class LAYER
 ******************************************************************************/
LAYER::LAYER() : number(0),color(0),fill(0),visible(true),active(true) {}

void LAYER::Parse(attributes begin, attributes end) {
  visible = true;
  active  = true;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "number")  number  = std::stod(Value);
     else if (Name == "name")    name    = Value;
     else if (Name == "color")   color   = std::stoi(Value);
     else if (Name == "fill")    fill    = std::stoi(Value);
     else if (Name == "visible") visible = (Value != "no");
     else if (Name == "active")  active  = (Value != "no");
     }
}

/*******************************************************************************
 * class PAD
 ******************************************************************************/
PAD::PAD() :
  x(0.0),y(0.0),drill(0.0),diameter(0.0),shape("round"),angle(0.0),
  stop(true),thermals(true),first(false) {}

void PAD::Parse(attributes begin, attributes end) {
  diameter = 0.0;
  shape = "round";
  angle = 0.0;
  stop = true;
  thermals = true;
  first = false;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "name")     name     = Value;
     else if (Name == "x")        x        = std::stod(Value);
     else if (Name == "y")        y        = std::stod(Value);
     else if (Name == "drill")    drill    = std::stod(Value);
     else if (Name == "diameter") diameter = std::stod(Value);
     else if (Name == "shape")    shape    = Value;
     else if (Name == "rot")      angle    = std::stod(Value.substr(Value.find_first_of("0123456789")));
     else if (Name == "stop")     stop     = (Value != "no");
     else if (Name == "thermals") thermals = (Value != "no");
     else if (Name == "first")    first    = (Value == "yes");
     }
}

/*******************************************************************************
 * class PIN
 ******************************************************************************/
PIN::PIN() :
  x(0.0),y(0.0),showpin(true),showpad(true),length(3.0*2.54),direction("io"),
  inverted(false),clock(false),swaplevel(0),angle(0.0) {}

void PIN::Parse(attributes begin, attributes end) {
  showpin = true;
  showpad = true;
  length = 3.0*2.54;
  direction = "io";
  inverted = false;
  clock = false;
  swaplevel = 0;
  angle = 0.0;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "name")      name      = Value;
     else if (Name == "x")         x         = std::stod(Value);
     else if (Name == "y")         y         = std::stod(Value);
     else if (Name == "visible") {
        showpin = (Value == "pin") or (Value == "both");
        showpad = (Value == "pad") or (Value == "both");
        }
     else if (Name == "length")    Choice(length,Value,{"point","short","middle","long"},{0.0,2.54,5.08,7.62});
     else if (Name == "direction") direction = Value;
     else if (Name == "function") {
        inverted = (Value == "dot") or (Value == "dotclk");
        clock    = (Value == "clk") or (Value == "dotclk");
        }
     else if (Name == "swaplevel") swaplevel = std::stoi(Value);
     else if (Name == "rot")       angle     = std::stod(Value.substr(Value.find_first_of("0123456789")));
     }
}

/*******************************************************************************
 * class POLYGON
 ******************************************************************************/
POLYGON::POLYGON() :
  width(0.0),layer(0),spacing(0.0),pour("solid"),isolate(0.0),
  orphans(false),thermals(true),rank(0) {}

void POLYGON::Parse(attributes begin, attributes end) {
  pour = "solid";
  orphans = false;
  thermals = true;
  rank = 0;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "width")     width     = std::stod(Value);
     else if (Name == "layer")     layer     = std::stoi(Value);
     else if (Name == "spacing")   spacing   = std::stod(Value);
     else if (Name == "pour")      pour      = Value;
     else if (Name == "isolate")   isolate   = std::stod(Value);  // Only in <signal> or <package> context
     else if (Name == "orphans")   orphans   = (Value == "yes");  // Only in <signal> context
     else if (Name == "thermals")  thermals  = (Value != "no");   // Only in <signal> context
     else if (Name == "rank     ") rank      = std::stoi(Value);  // 1..6 in <signal> context, 0 or 7 in <package> context
     }
}

void POLYGON::Parse(childs begin, childs end) {
  vertices.clear();
  for(auto v = begin; v != end; ++v) {
     VERTEX vertex;
     for(auto a = v->attributes_begin(); a != v->attributes_end(); ++a) {
        std::string Name(a->name());
        std::string Value(a->value());
             if (Name == "x")     vertex.x     = std::stod(Value);
        else if (Name == "y")     vertex.y     = std::stod(Value);
        else if (Name == "curve") vertex.curve = std::stod(Value);
        }
     vertices.push_back(vertex);
     }
}

/*******************************************************************************
 * class RECTANGLE
 ******************************************************************************/
RECTANGLE::RECTANGLE() : 
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),layer(0),angle(0.0) {}

void RECTANGLE::Parse(attributes begin, attributes end) {
  angle = 0.0;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "x1")       x1    = std::stod(Value);
     else if (Name == "y1")       y1    = std::stod(Value);
     else if (Name == "x2")       x2    = std::stod(Value);
     else if (Name == "y2")       y2    = std::stod(Value);
     else if (Name == "layer")    layer = std::stoi(Value);
     else if (Name == "rot")      angle = std::stod(Value.substr(Value.find_first_of("0123456789")));
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
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "name")      name      = Value;
     else if (Name == "x")         x         = std::stod(Value);
     else if (Name == "y")         y         = std::stod(Value);
     else if (Name == "dx")        dx        = std::stod(Value);
     else if (Name == "dy")        dy        = std::stod(Value);
     else if (Name == "layer")     layer     = std::stoi(Value);
     else if (Name == "roundness") roundness = std::stoi(Value);
     else if (Name == "rot")       angle     = std::stod(Value.substr(Value.find_first_of("0123456789")));
     else if (Name == "stop")      stop      = (Value != "no");
     else if (Name == "thermals")  thermals  = (Value != "no");
     else if (Name == "cream")     cream     = (Value != "no");
     }
}

/*******************************************************************************
 * class TECHNOLOGY
 ******************************************************************************/
TECHNOLOGY::TECHNOLOGY() {}

void TECHNOLOGY::Parse(childs begin, childs end) {
  Attributes.clear();

  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());

     if (Name == "attribute") {
        ATTRIBUTE Attribute;
        Attribute.Parse(c->attributes_begin(), c->attributes_end());
        Attributes.push_back(Attribute);
        }
     }
}

/*******************************************************************************
 * class TEXT
 ******************************************************************************/
TEXT::TEXT() :
  x(0.0),y(0.0),size(0.0),layer(0),font("proportional"),ratio(8),
  angle(0.0),mirror(false),spin(false),align("bottom-left"),
  distance(50) {}

void TEXT::Parse(attributes begin, attributes end) {
  font = "proportional";
  ratio = 8;
  angle = 0.0;
  mirror = false;
  spin = false;
  align = "bottom-left";
  distance = 50;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());

          if (Name == "x")        x            = std::stod(Value);
     else if (Name == "y")        y            = std::stod(Value);
     else if (Name == "size")     size         = std::stod(Value);
     else if (Name == "layer")    layer        = std::stoi(Value);
     else if (Name == "font")     font         = Value;
     else if (Name == "ratio")    ratio        = std::stoi(Value);
     else if (Name == "rot") {
        angle  = std::stod(Value.substr(Value.find_first_of("0123456789")));
        mirror = Value.find("M") != std::string::npos;
        spin   = Value.find("S") != std::string::npos;
        }
     else if (Name == "align")    align        = Value;
     else if (Name == "distance") distance     = std::stoi(Value);
     }
}

/*******************************************************************************
 * class WIRE
 ******************************************************************************/
WIRE::WIRE() :
  x1(0.0),y1(0.0),x2(0.0),y2(0.0),width(0.0),layer(0),style("continuous"),
  curve(0.0), cap_round(true) {}

void WIRE::Parse(attributes begin, attributes end) {
  style = "continuous";
  curve = 0.0;
  cap_round = true;

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "x1")     x1        = std::stod(Value);
     else if (Name == "y1")     y1        = std::stod(Value);
     else if (Name == "x2")     x2        = std::stod(Value);
     else if (Name == "y2")     y2        = std::stod(Value);
     else if (Name == "width")  width     = std::stod(Value);
     else if (Name == "layer")  layer     = std::stoi(Value);
     else if (Name == "extent") extent    = Value;
     else if (Name == "curve")  curve     = std::stod(Value);
     else if (Name == "style")  style     = Value;
     else if (Name == "cap")    cap_round = Value != "flat";
     }
}




/*******************************************************************************
 * !!! higher classes with dependencies
 ******************************************************************************/




/*******************************************************************************
 * class DEVICE
 ******************************************************************************/
DEVICE::DEVICE() {}

void DEVICE::Parse(attributes begin, attributes end) {
  name.clear();
  package.clear();

  for(auto a = begin; a != end; ++a) {
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "name")      name       = Value;
     else if (Name == "package")   package    = Value;
     }
}

void DEVICE::Parse(childs begin, childs end) {
  connects.clear();
  technologies.clear();

  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());

     if (Name == "connects") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           CONNECT connect;
           connect.Parse(ch->attributes_begin(), ch->attributes_end());
           connects.push_back(connect);
           }
        }
     else if (Name == "technologies") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           TECHNOLOGY technology;
           technology.name = ch->attribute("name").value();
           technology.Parse(ch->begin(), ch->end());
           technologies.push_back(technology);
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
     std::string Name(a->name());
     std::string Value(a->value());
          if (Name == "name")      name       = Value;
     else if (Name == "prefix")    prefix     = Value;
     else if (Name == "uservalue") uservalue  = (Value == "yes");
     }
}

void DEVICESET::Parse(childs begin, childs end) {
  description.clear();
  headline.clear();
  gates.clear();
  devices.clear();

  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());
     std::string Value(c->value());

     if (Name == "description") {
        description = c->text().get();
        headline = HeadLine(description);
        }
     else if (Name == "gates") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           GATE gate;
           gate.Parse(ch->attributes_begin(), ch->attributes_end());
           gates.push_back(gate);
           }
        }
     else if (Name == "devices") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           DEVICE device;
           device.Parse(ch->begin(), ch->end());
           device.Parse(ch->attributes_begin(), ch->attributes_end());
           devices.push_back(device);
           }
        }
     }
}

/*******************************************************************************
 * class PACKAGE
 ******************************************************************************/
PACKAGE::PACKAGE() {}

void PACKAGE::Parse(childs begin, childs end) {
  description.clear();
  headline.clear();
  polygons.clear();
  wires.clear();
  texts.clear();
  dimensions.clear();
  circles.clear();
  rectangles.clear();
  frames.clear();
  holes.clear();
  pads.clear();
  smds.clear();

  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());

     if (Name == "description") {
        description = c->text().get();
        headline = HeadLine(description);
        }
     else if (Name == "polygon") {
        POLYGON polygon;
        polygon.Parse(c->begin(), c->end());
        polygon.Parse(c->attributes_begin(), c->attributes_end());
        polygons.push_back(polygon);
        }
     else if (Name == "wire") {
        WIRE wire;
        wire.Parse(c->attributes_begin(), c->attributes_end());
        wires.push_back(wire);
        }
     else if (Name == "text") {
        TEXT text;
        text.value = c->text().get();
        text.Parse(c->attributes_begin(), c->attributes_end());
        texts.push_back(text);
        }
     else if (Name == "dimension") {
        DIMENSION dimension;
        dimension.Parse(c->attributes_begin(), c->attributes_end());
        dimensions.push_back(dimension);
        }
     else if (Name == "circle") {
        CIRCLE circle;
        circle.Parse(c->attributes_begin(), c->attributes_end());
        circles.push_back(circle);
        }
     else if (Name == "rectangle") {
        RECTANGLE rectangle;
        rectangle.Parse(c->attributes_begin(), c->attributes_end());
        rectangles.push_back(rectangle);
        }
     else if (Name == "frame") {
        FRAME frame;
        frame.Parse(c->attributes_begin(), c->attributes_end());
        frames.push_back(frame);
        }
     else if (Name == "hole") {
        HOLE hole;
        hole.Parse(c->attributes_begin(), c->attributes_end());
        holes.push_back(hole);
        }
     else if (Name == "pad") {
        PAD pad;
        pad.Parse(c->attributes_begin(), c->attributes_end());
        pads.push_back(pad);
        }
     else if (Name == "smd") {
        SMD smd;
        smd.Parse(c->attributes_begin(), c->attributes_end());
        smds.push_back(smd);
        }
     }
}

/*******************************************************************************
 * class SYMBOL
 ******************************************************************************/
SYMBOL::SYMBOL() {}

void SYMBOL::Parse(childs begin, childs end) {
  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());
     std::string Value(c->value());

     if (Name == "description") {
        description = c->text().get();
        headline = HeadLine(description);
        }
     else if (Name == "polygon") {
        POLYGON polygon;
        polygon.Parse(c->begin(), c->end());
        polygon.Parse(c->attributes_begin(), c->attributes_end());
        polygons.push_back(polygon);
        }
     else if (Name == "wire") {
        WIRE wire;
        wire.Parse(c->attributes_begin(), c->attributes_end());
        wires.push_back(wire);
        }
     else if (Name == "text") {
        TEXT text;
        text.value = c->text().get();
        text.Parse(c->attributes_begin(), c->attributes_end());
        texts.push_back(text);
        }
     else if (Name == "dimension") {
        DIMENSION dimension;
        dimension.Parse(c->attributes_begin(), c->attributes_end());
        dimensions.push_back(dimension);
        }
     else if (Name == "pin") {
        PIN pin;
        pin.Parse(c->attributes_begin(), c->attributes_end());
        pins.push_back(pin);
        }
     else if (Name == "circle") {
        CIRCLE circle;
        circle.Parse(c->attributes_begin(), c->attributes_end());
        circles.push_back(circle);
        }
     else if (Name == "rectangle") {
        RECTANGLE rectangle;
        rectangle.Parse(c->attributes_begin(), c->attributes_end());
        rectangles.push_back(rectangle);
        }
     else if (Name == "frame") {
        FRAME frame;
        frame.Parse(c->attributes_begin(), c->attributes_end());
        frames.push_back(frame);
        }
     }
}

/*******************************************************************************
 * class LIBRARY
 ******************************************************************************/
LIBRARY::LIBRARY() {}

void LIBRARY::Parse(childs begin, childs end) {
  description.clear();
  headline.clear();
  packages.clear();
  symbols.clear();
  devicesets.clear();

  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());

     if (Name == "description") {
        description = c->text().get();
        headline = HeadLine(description);
        }
     else if (Name == "packages") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           PACKAGE package;
           package.name = ch->attribute("name").value();
           package.Parse(ch->begin(),ch->end());
           packages.push_back(package);
           }
        }
     else if (Name == "symbols") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           SYMBOL symbol;
           symbol.name = ch->attribute("name").value();
           symbol.Parse(ch->begin(),ch->end());
           symbols.push_back(symbol);
           }
        }
     else if (Name == "devicesets") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           DEVICESET deviceset;
           deviceset.Parse(ch->attributes_begin(),ch->attributes_end());
           deviceset.Parse(ch->begin(),ch->end());
           devicesets.push_back(deviceset);
           }
        }
     }
}

/*******************************************************************************
 * class DRAWING
 ******************************************************************************/
DRAWING::DRAWING() :
  verticaltextup(true),isLibrary(false),isSchematic(false),isBoard(false) {}

void DRAWING::Parse(childs begin, childs end) {
  verticaltextup = true;
  isLibrary = false;
  isSchematic = false;
  isBoard = false;

  for(auto c = begin; c != end; ++c) {
     std::string Name(c->name());

     if (Name == "settings") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           for(auto a = ch->attributes_begin(); a != ch->attributes_end(); ++a) {
              std::string Name(a->name());
              std::string Value(a->value());
              if (Name == "alwaysvectorfont")  alwaysvectorfont = (Value == "yes");
              else if (Name == "verticaltext") verticaltextup   = (Value == "up");
              }
           }
        }
     else if (Name == "grid")
        grid.Parse(c->attributes_begin(), c->attributes_end());
     else if (Name == "layers") {
        for(auto ch = c->begin(); ch != c->end(); ++ch) {
           LAYER layer;
           layer.Parse(ch->attributes_begin(),ch->attributes_end());
           layers.push_back(layer);
           }
        }
     else if (Name == "library") {
        isLibrary = true;
        library.name = c->attribute("name").value();
        library.Parse(c->begin(), c->end());
        }
     else if (Name == "schematic") {
        isSchematic = true;
        //schematic.Parse(c->begin(), c->end());
        }
     else if (Name == "board") {
        isBoard = true;
        //board.Parse(c->begin(), c->end());
        }
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

  DRAWING drawing;
  drawing.Parse(doc.child("eagle").child("drawing").begin(),
                doc.child("eagle").child("drawing").end());

  return 0;
}
