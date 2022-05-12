#pragma once
#include <string>
#include <vector>

/*******************************************************************************
 * consts here:
 ******************************************************************************/
constexpr int ALIGN_BOTTOM_LEFT              = 0;  // TEXT; unten/links ausgerichtet
constexpr int ALIGN_BOTTOM_CENTER            = 1;  // TEXT; unten/mittig ausgerichtet
constexpr int ALIGN_BOTTOM_RIGHT             = 2;  // TEXT; unten/rechts ausgerichtet
constexpr int ALIGN_CENTER_LEFT              = 3;  // TEXT; mittig/links ausgerichtet
constexpr int ALIGN_CENTER                   = 4;  // TEXT; zentriert
constexpr int ALIGN_CENTER_RIGHT             = 5;  // TEXT; mittig/rechts ausgerichtet
constexpr int ALIGN_TOP_LEFT                 = 6;  // TEXT; oben/links ausgerichtet
constexpr int ALIGN_TOP_CENTER               = 7;  // TEXT; oben/mittig ausgerichtet
constexpr int ALIGN_TOP_RIGHT                = 8;  // TEXT; oben/rechts ausgerichtet
constexpr int ATTRIBUTE_DISPLAY_FLAG_OFF     = 0;  // ATTRIBUTE; name and value hidden
constexpr int ATTRIBUTE_DISPLAY_FLAG_VALUE   = 1;  // ATTRIBUTE; value is shown
constexpr int ATTRIBUTE_DISPLAY_FLAG_NAME    = 2;  // ATTRIBUTE; name is shown
constexpr int CAP_FLAT                       = 0;  // WIRE; flache Kreisbogen-Enden
constexpr int CAP_ROUND                      = 1;  // WIRE; runde Kreisbogen-Enden
constexpr int CONTACT_ROUTE_ALL              = 0;  // PIN; any contact has to be connected
constexpr int CONTACT_ROUTE_ANY              = 1;  // PIN; any contact may to be connected
constexpr int DIMENSION_PARALLEL             = 0;  // DIMENSION; lineare Bemassung mit paralleler Masslinie
constexpr int DIMENSION_HORIZONTAL           = 1;  // DIMENSION; lineare Bemassung mit waagerechter Masslinie
constexpr int DIMENSION_VERTICAL             = 2;  // DIMENSION; lineare Bemassung mit senkrechter Masslinie
constexpr int DIMENSION_RADIUS               = 3;  // DIMENSION; Radius-Bemassung
constexpr int DIMENSION_DIAMETER             = 4;  // DIMENSION; Durchmesser-Bemassung
constexpr int DIMENSION_ANGLE                = 5;  // DIMENSION; Winkel-Bemassung
constexpr int DIMENSION_LEADER               = 6;  // DIMENSION; ein beliebiger Pfeil
constexpr int FONT_VECTOR                    = 0;  // TEXT; Vector-Font
constexpr int FONT_PROPORTIONAL              = 1;  // TEXT; Proportional-Font
constexpr int FONT_FIXED                     = 2;  // TEXT; Fixed-Font
constexpr int GATE_ADDLEVEL_MUST             = 0;  // GATE;
constexpr int GATE_ADDLEVEL_CAN              = 1;  // GATE;
constexpr int GATE_ADDLEVEL_NEXT             = 2;  // GATE;
constexpr int GATE_ADDLEVEL_REQUEST          = 3;  // GATE;
constexpr int GATE_ADDLEVEL_ALWAYS           = 4;  // GATE;
constexpr int GRID_UNIT_MIC                  = 0;  // GRID; micron
constexpr int GRID_UNIT_MM                   = 1;  // GRID; mm
constexpr int GRID_UNIT_MIL                  = 2;  // GRID; mil
constexpr int GRID_UNIT_INCH                 = 3;  // GRID; inch
constexpr int LAYER_TOP                      = 1;  // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer. 
constexpr int LAYER_BOTTOM                   = 16; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_PADS                     = 17; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_VIAS                     = 18; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_UNROUTED                 = 19; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_DIMENSION                = 20; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TPLACE                   = 21; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BPLACE                   = 22; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TORIGINS                 = 23; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BORIGINS                 = 24; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TNAMES                   = 25; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BNAMES                   = 26; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TVALUES                  = 27; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BVALUES                  = 28; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TSTOP                    = 29; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BSTOP                    = 30; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TCREAM                   = 31; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BCREAM                   = 32; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TFINISH                  = 33; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BFINISH                  = 34; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TGLUE                    = 35; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BGLUE                    = 36; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TTEST                    = 37; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BTEST                    = 38; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TKEEPOUT                 = 39; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BKEEPOUT                 = 40; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TRESTRICT                = 41; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BRESTRICT                = 42; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_VRESTRICT                = 43; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_DRILLS                   = 44; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_HOLES                    = 45; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_MILLING                  = 46; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_MEASURES                 = 47; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_DOCUMENT                 = 48; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_REFERENCE                = 49; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TDOCU                    = 51; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BDOCU                    = 52; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_NETS                     = 91; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BUSSES                   = 92; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_PINS                     = 93; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_SYMBOLS                  = 94; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_NAMES                    = 95; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_VALUES                   = 96; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_INFO                     = 97; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_GUIDE                    = 98; // CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_USER                     = 100;// CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int PAD_SHAPE_SQUARE               = 0;  // PAD;
constexpr int PAD_SHAPE_ROUND                = 1;  // PAD;
constexpr int PAD_SHAPE_OCTAGON              = 2;  // PAD;
constexpr int PAD_SHAPE_LONG                 = 3;  // PAD;
constexpr int PAD_SHAPE_OFFSET               = 4;  // PAD;
constexpr int PIN_DIRECTION_NC               = 0;  // PIN; Not connected
constexpr int PIN_DIRECTION_IN               = 1;  // PIN; Input
constexpr int PIN_DIRECTION_OUT              = 2;  // PIN; Output (totem-pole)
constexpr int PIN_DIRECTION_IO               = 3;  // PIN; In/Output (bidirectional)
constexpr int PIN_DIRECTION_OC               = 4;  // PIN; Open Collector
constexpr int PIN_DIRECTION_PWR              = 5;  // PIN; Power-Input-Pin
constexpr int PIN_DIRECTION_PAS              = 6;  // PIN; Passiv
constexpr int PIN_DIRECTION_HIZ              = 7;  // PIN; High-Impedance-Output
constexpr int PIN_DIRECTION_SUP              = 8;  // PIN; Supply-Pin
constexpr int PIN_LENGTH_POINT               = 0;  // PIN; no wire at pin, just a dot
constexpr int PIN_LENGTH_SHORT               = 1;  // PIN; 100mil wire at pin
constexpr int PIN_LENGTH_MIDDLE              = 2;  // PIN; 200mil wire at pin
constexpr int PIN_LENGTH_LONG                = 3;  // PIN; 300mil wire at pin
constexpr int POLYGON_POUR_SOLID             = 0;  // POLYGON; solid
constexpr int POLYGON_POUR_HATCH             = 1;  // POLYGON; hatch
constexpr int POLYGON_POUR_CUTOUT            = 2;  // POLYGON; cutout
constexpr int WIRE_STYLE_CONTINUOUS          = 0;  // WIRE; durchgezogen
constexpr int WIRE_STYLE_LONGDASH            = 1;  // WIRE; lang gestrichelt
constexpr int WIRE_STYLE_SHORTDASH           = 2;  // WIRE; kurz gestrichelt
constexpr int WIRE_STYLE_DASHDOT             = 3;  // WIRE; Strich-Punkt-Linie

/*******************************************************************************
 * forward decls
 ******************************************************************************/

class CIRCLE;
class DIMENSION;
class FRAME;
class GRID;
class HOLE;
class LAYER;
class PAD;
class PACKAGE;
class POLYGON;
class RECTANGLE;
class SMD;
class TEXT;
class WIRE;
class PIN;
class SYMBOL;

class GATE;
class DEVICE;
class DEVICESET;



/*******************************************************************************
 * classes and types
 ******************************************************************************/

// (POLYGON | WIRE | TEXT | DIMENSION | PIN | CIRCLE | RECTANGLE | FRAME)


class CIRCLE {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x, y;
  double radius;
  double width;
  int layer;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  CIRCLE();
};

class DIMENSION {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // (erster Bezugspunkt)
  double x2, y2;                        // (zweiter Bezugspunkt)
  double x3, y3;                        // (Hilfspunkt für die Ausrichtung)
  int layer;                            //
  int dtype;                            // DIMENSION_{PARALLEL,HORIZONTAL,VERTICAL,RADIUS,DIAMETER,ANGLE,LEADER}
  double width;                         //
  double extwidth;                      //
  double extlength;                     //
  double extoffset;                     //
  double size;                          // textsize
  int ratio;                            // textratio
  int unit;                             // Einheit: GRID_UNIT_{MIC,MM,MIL,INCH}
  int precision;                        // default:2. Nachkommastellen,Genauigkeit der Massangabe
  bool visible;                         // int (0=off, 1=on)
  // Loop members
  //std::vector<TEXT> texts;
  //std::vector<WIRE> wires;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  DIMENSION();
};

class FRAME {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // lower left
  double x2, y2;                        // upper right
  int columns;                          // (-127...127)
  int rows;                             // (-26...26)
  int layer;                            //
  bool border_left;                     //
  bool border_top;                      //
  bool border_right;                    //
  bool border_bottom;                   //
  // Loop members
  //std::vector<TEXT> texts;
  //std::vector<WIRE> wires;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  FRAME();
};

class GRID {
public:
  double distance, altdistance;
  bool dots;                            // int, 0=lines, 1=dots
  bool on;                              // int, 0=off, 1=on
  int multiple;                         //
  int unit, altunit;                    // GRID_UNIT_{MIC,MM,MIL,INCH}
  int unitdist, altunitdist;            // GRID_UNIT_{MIC,MM,MIL,INCH}
public:
  GRID();
};

class HOLE {
friend class PACKAGE;
public:
  double x, y;                          //
  double drill;                         //
  //int diameter[101];                  // defined only for {LAYER_TSTOP, LAYER_BSTOP} &&  defines the stop masks diameter there.
  //int drillsymbol;                    // number of drill symbol, that is assigned acc. to diameter. See handbook. 0 = none.
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  HOLE();
};

class LAYER {
public:
  std::string name;                     //
  bool used;                            // int (0=unbenutzt, 1=benutzt)
  bool visible;                         // int (0=off, 1=on)
  int color;                            //
  int fill;                             //
  int number;                           //
public:
  LAYER();
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
};

class PAD {
friend class PACKAGE;
public:
  std::string name;                     //
  double x, y;                          //
  double drill;                         //
  double diameter;                      //
  int shape;                            // PAD_SHAPE_{SQUARE,ROUND,OCTAGON,LONG,OFFSET}
  double angle;                         // "rot" (0.0...359.9)
  bool stop;                            //
  bool thermals;                        // Loetstopmaske generieren
  bool first;                           // Thermals generieren
  int flags;                            // spezielle Form fuer "erstes Pad" verwenden
  //int drillsymbol;                    //
  //int elongation;                     //
  //std::string signal;                 //
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  PAD();
};

class POLYGON {
friend class PACKAGE;
friend class SYMBOL;
public:
  class VERTEX {
  public:
     double x,y;
     double curve;                      //  The curvature from this vertex to the next one
  public:
     VERTEX() : curve(0.0) {}
  };
public:
  double width;
  int layer;                            // LAYER_(*)
  int spacing;                          //
  int pour;                             // POLYGON_POUR_{SOLID,HATCH,CUTOUT}
  int isolate;                          //
  bool orphans;                         // int (0=off, 1=on)
  bool thermals;                        // int (0=off, 1=on)
  int rank;                             //
  std::vector<VERTEX> vertices;

  // Loop members
  //std::vector<WIRE> contours;         // not set in lbr
  //std::vector<WIRE> fillings;         // not set in lbr
  //std::vector<WIRE> wires;            // not set in lbr
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
  void Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end);
public:
  POLYGON();
};

class RECTANGLE {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // lower left
  double x2, y2;                        // upper right
  int layer;                            //
  double angle;                         // (0.0...359.9)
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  RECTANGLE();
};

class SMD {
friend class PACKAGE;
public:
  std::string name;                     //
  double x, y;                          //
  double dx, dy;                        //
  int layer;                            // LAYER_(*)
  int roundness;                        //
  double angle;                         // "rot" (0.0...359.9)
  bool stop;                            //
  bool thermals;                        //
  bool cream;                           //
  //std::string signal;                 // member not in *.lbr initialized.
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  SMD();
};

class TEXT {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x, y;                          //
  double size;                          //
  int layer;                            // LAYER_(*)
  int font;                             // FONT_VECTOR, FONT_PROPORTIONAL, FONT_FIXED
  int ratio;                            //
  double angle;                         // "rot" (0.0...359.9)
  bool mirror;                          // "rot" M
  bool spin;                            // "rot" S
  int align;                            // ALIGN_{BOTTOM_LEFT,BOTTOM_CENTER,BOTTOM_RIGHT,CENTER_LEFT,CENTER,CENTER_RIGHT,TOP_LEFT,TOP_CENTER,TOP_RIGHT}
  int linedistance;                     // "distance"
  std::string value;
  // Loop members
  //std::vector<WIRE> wires;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  TEXT();
};

class WIRE {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // Anfangspunkt
  double x2, y2;                        // Endpunkt
  double width;                         //
  int layer;                            // LAYER_(*)
  std::string extent;                   // Only airwires, the layers a via or airwire extends through, given as "topmost-bottommost"
  int style;                            // WIRE_STYLE_{CONTINUOUS,LONGDASH,SHORTDASH,DASHDOT}
  double curve;                         //
  int cap;                              // CAP_FLAT,CAP_ROUND
  //ARC arc;
  // Loop members
  //std::vector<WIRE> pieces;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  WIRE();
};

class PACKAGE {
public:
  std::string description;
  std::string headline;
  std::string library;
  std::string name;
  //AREA area;
  // Loop members
  std::vector<POLYGON> polygons;
  std::vector<WIRE> wires;
  std::vector<TEXT> texts;
  std::vector<DIMENSION> dimensions;
  std::vector<CIRCLE> circles;
  std::vector<RECTANGLE> rectangles;
  std::vector<FRAME> frames;
  std::vector<HOLE> holes;
  std::vector<PAD> pads;
  std::vector<SMD> smds;

public:
  PACKAGE();
  void Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end);
};

class PIN {
friend class SYMBOL;
public:
  std::string name;                     //
  double x, y;
  bool visible_pin;                     // "visible" = "pin"
  bool visible_pad;                     // "visible" = "pad"
  int length;                           // PIN_LENGTH_{POINT,SHORT,MIDDLE,LONG}
  int direction;                        // PIN_DIRECTION_{NC,IN,OUT,IO,OC,PWR,PAS,HIZ,SUP}
  bool inverted;                        // "function" = "dot"
  bool clock;                           // "function" = "clock"
  int swaplevel;
  double angle;                         // "rot" = "R(0,90,180,270)"
  //int route;                          // CONTACT_ROUTE_{ANY,ALL}
  //std::string net;                    //
  //CONTACT contact;                    // deprecated.
  // Loop members
  // std::vector<CIRCLE> circles;
  // std::vector<CONTACT> contacts;
  // std::vector<TEXT> texts;
  // std::vector<WIRE> wires;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
public:
  PIN();
};

class SYMBOL {
public:
  std::string name;
  std::string description;
  std::string headline;
  std::string library;
  //AREA area;
  // Loop members
  std::vector<CIRCLE> circles;
  std::vector<DIMENSION> dimensions;
  std::vector<FRAME> frames;
  std::vector<RECTANGLE> rectangles;
  std::vector<PIN> pins;
  std::vector<POLYGON> polygons;
  std::vector<TEXT> texts;
  std::vector<WIRE> wires;
public:
  SYMBOL();
  void Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end);
};





//class ARC;
class AREA;
class CONTACT;

//class ARC {
//public:
//  double angle1;                        // Startwinkel, 0.0...359.9
//  double angle2;                        // Endwinkel, 0.0...719.9
//  int cap;                              // CAP_FLAT,CAP_ROUND
//  int layer;                            //
//  int radius;                           //
//  int width;                            //
//  int x1, y1;                           // Startpunkt
//  int x2, y2;                           // Endpunkt
//  int xc, yc;                           // Mittelpunkt
//public:
//  ARC();
//};

class AREA {
public:
  int x1, y1;
  int x2, y2;
public:
  AREA();
};








class ATTRIBUTE {
  std::string name;
  std::string value;                    //
  std::string defaultvalue;             //
  bool constant;                        //  int (0=no, may be modified, 1=const)
  int display;                          // flag of: ATTRIBUTE_DISPLAY_FLAG_{OFF,NAME.VALUE}
  TEXT text;
public:
  ATTRIBUTE();
};


class CONTACT {
public:
  std::string name;
  std::string signal;
  PAD pad;
  SMD smd;
  int x, y;
  // Loop members
  std::vector<POLYGON> polygons;
  std::vector<WIRE> wires;
public:
  CONTACT();
};



class DEVICE {
friend class DEVICESET;
public:
  std::string name;                     //
  std::string package;                  //



//<!ELEMENT device (connects?, technologies?)>
//<!ATTLIST device
//        name          %String;       ""
//        package       %String;       #IMPLIED
//        >
//
//
//std::string activetechnology;         //
//std::string description;              //
//std::string headline;                 //
//std::string library;                  //
//
//std::string prefix;                   //
//std::string technologies;             // all techologies, separated by a SPACE
//bool value;                           // string ("On" oder "Off")
//AREA area;                            //
//PACKAGE package;
//
////Loop members
//std::vector<ATTRIBUTE> attributes(std::string technology);
//std::vector<GATE> gates;
private:
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
  void Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end);
public:
  DEVICE();
};

class GATE {
public:
  std::string name;                     //
  int addlevel;                         // GATE_ADDLEVEL_{MUST,CAN,NEXT,REQUEST,ALWAYS}
  int swaplevel;                        //
  int x, y;                             // Aufhaengepunkt
  SYMBOL symbol;                        //
public:
  GATE();
};

class DEVICESET {
public:
  std::string library;                  //
  std::string name;                     //
  std::string prefix;                   //
  bool uservalue;
  std::string description;              //
  std::string headline;                 //
  //DEVICE* activedevice;               // if a set is currently beeing edited, this one is delivered here.
  //AREA area;                          //
  // Loop members
  std::vector<DEVICE> devices;
  std::vector<GATE> gates;
public:
  DEVICESET();
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
  void Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end);
};







class LIBRARY {
public:
  std::string description;              // vollstaendiger Beschreibungstext, der mit dem DESCRIPTION-Befehl erzeugt wurde
  std::string headline;                 // erste Zeile der Beschreibung ohne HTML-Tags ausgibt
  std::string name;                     //
  GRID grid;                            //
  bool alwaysvectorfont;
  bool verticaltextdown;

  // Loop members
  std::vector<DEVICE> devices;
  std::vector<DEVICESET> devicesets; 
  std::vector<LAYER> layers;
  std::vector<PACKAGE> packages;
  std::vector<SYMBOL> symbols;
public:
  LIBRARY();
};


















/*
p27: Objekt-Hierarchie einer Bibliothek:
LIBRARY
  +-GRID
  +-LAYER
  +-DEVICESET
  |  +-DEVICE
  |  +-GATE
  +-PACKAGE
  |  +-CONTACT
  |  |   +-PAD
  |  |   +-SMD
  |  +-CIRCLE
  |  +-HOLE
  |  +-RECTANGLE
  |  +-FRAME
  |  +-DIMENSION
  |  +-TEXT
  |  +-WIRE
  |  +-POLYGON
  |  |   +-WIRE
  +-SYMBOL
  |  +-PIN
  |  +-CIRCLE
  |  +-RECTANGLE
  |  +-FRAME
  |  +-DIMENSION
  |  +-TEXT
  |  +-WIRE
  |  +-POLYGON
  |  |   +-WIRE
*/








