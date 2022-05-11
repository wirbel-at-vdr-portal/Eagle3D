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
constexpr int CAP_FLAT                       = 0;  // ARC,WIRE; flache Kreisbogen-Enden
constexpr int CAP_ROUND                      = 1;  // ARC,WIRE; runde Kreisbogen-Enden
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
constexpr int FRAME_BORDER_BOTTOM            = 1;  // FRAME; unterer Rand wird dargestellt
constexpr int FRAME_BORDER_RIGHT             = 2;  // FRAME; rechter Rand wird dargestellt
constexpr int FRAME_BORDER_TOP               = 4;  // FRAME; oberer Rand wird dargestellt
constexpr int FRAME_BORDER_LEFT              = 8;  // FRAME; linker Rand wird dargestellt
constexpr int GATE_ADDLEVEL_MUST             = 0;  // GATE;
constexpr int GATE_ADDLEVEL_CAN              = 1;  // GATE;
constexpr int GATE_ADDLEVEL_NEXT             = 2;  // GATE;
constexpr int GATE_ADDLEVEL_REQUEST          = 3;  // GATE;
constexpr int GATE_ADDLEVEL_ALWAYS           = 4;  // GATE;
constexpr int GRID_UNIT_MIC                  = 0;  // GRID; micron
constexpr int GRID_UNIT_MM                   = 1;  // GRID; mm
constexpr int GRID_UNIT_MIL                  = 2;  // GRID; mil
constexpr int GRID_UNIT_INCH                 = 3;  // GRID; inch
constexpr int LAYER_TOP                      = 1;  // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer. 
constexpr int LAYER_BOTTOM                   = 16; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_PADS                     = 17; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_VIAS                     = 18; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_UNROUTED                 = 19; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_DIMENSION                = 20; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TPLACE                   = 21; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BPLACE                   = 22; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TORIGINS                 = 23; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BORIGINS                 = 24; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TNAMES                   = 25; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BNAMES                   = 26; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TVALUES                  = 27; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BVALUES                  = 28; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TSTOP                    = 29; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BSTOP                    = 30; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TCREAM                   = 31; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BCREAM                   = 32; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TFINISH                  = 33; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BFINISH                  = 34; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TGLUE                    = 35; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BGLUE                    = 36; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TTEST                    = 37; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BTEST                    = 38; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TKEEPOUT                 = 39; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BKEEPOUT                 = 40; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TRESTRICT                = 41; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BRESTRICT                = 42; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_VRESTRICT                = 43; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_DRILLS                   = 44; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_HOLES                    = 45; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_MILLING                  = 46; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_MEASURES                 = 47; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_DOCUMENT                 = 48; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_REFERENCE                = 49; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_TDOCU                    = 51; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BDOCU                    = 52; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_NETS                     = 91; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_BUSSES                   = 92; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_PINS                     = 93; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_SYMBOLS                  = 94; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_NAMES                    = 95; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_VALUES                   = 96; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_INFO                     = 97; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_GUIDE                    = 98; // ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int LAYER_USER                     = 100;// ARC,CIRCLE,POLYGON,RECTANGLE,SMD,TEXT,WIRE; integer consts for layer.
constexpr int PAD_FLAG_STOP                  = 1;  // PAD; Loetstopmaske generieren
constexpr int PAD_FLAG_THERMALS              = 4;  // PAD; Thermals generieren
constexpr int PAD_FLAG_FIRST                 = 8;  // PAD; spezielle Form fuer "erstes Pad" verwenden
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
constexpr int PIN_FUNCTION_FLAG_NONE         = 0;  // PIN; standard pin
constexpr int PIN_FUNCTION_FLAG_DOT          = 1;  // PIN; inverted pin
constexpr int PIN_FUNCTION_FLAG_CLK          = 2;  // PIN; clock pin
constexpr int PIN_LENGTH_POINT               = 0;  // PIN; no wire at pin, just a dot
constexpr int PIN_LENGTH_SHORT               = 1;  // PIN; 100mil wire at pin
constexpr int PIN_LENGTH_MIDDLE              = 2;  // PIN; 200mil wire at pin
constexpr int PIN_LENGTH_LONG                = 3;  // PIN; 300mil wire at pin
constexpr int PIN_VISIBLE_FLAG_OFF           = 0;  // PIN; pad name and pin name are hidden
constexpr int PIN_VISIBLE_FLAG_PAD           = 1;  // PIN; pad name visible
constexpr int PIN_VISIBLE_FLAG_PIN           = 2;  // PIN; pin name visible
constexpr int POLYGON_POUR_SOLID             = 0;  // POLYGON; solid
constexpr int POLYGON_POUR_HATCH             = 1;  // POLYGON; hatch
constexpr int POLYGON_POUR_CUTOUT            = 2;  // POLYGON; cutout
constexpr int SMD_FLAG_STOP                  = 1;  // SMD;
constexpr int SMD_FLAG_CREAM                 = 2;  // SMD;
constexpr int SMD_FLAG_THERMALS              = 4;  // SMD;
constexpr int WIRE_STYLE_CONTINUOUS          = 0;  // WIRE; durchgezogen
constexpr int WIRE_STYLE_LONGDASH            = 1;  // WIRE; lang gestrichelt
constexpr int WIRE_STYLE_SHORTDASH           = 2;  // WIRE; kurz gestrichelt
constexpr int WIRE_STYLE_DASHDOT             = 3;  // WIRE; Strich-Punkt-Linie

/*******************************************************************************
 * forward decls
 ******************************************************************************/
class ARC;
class AREA;
class CIRCLE;
class CONTACT;
class GATE;
class DEVICE;
class DEVICESET;
class DIMENSION;
class FRAME;
class GRID;
class HOLE;
class LAYER;
class PACKAGE;
class PAD;
class PIN;
class POLYGON;
class RECTANGLE;
class SMD;
class SYMBOL;
class TEXT;
class WIRE;


/*******************************************************************************
 * classes and types
 ******************************************************************************/

class ARC {
public:
  double angle1;                        // Startwinkel, 0.0...359.9
  double angle2;                        // Endwinkel, 0.0...719.9
  int cap;                              // CAP_FLAT,CAP_ROUND
  int layer;                            //
  int radius;                           //
  int width;                            //
  int x1, y1;                           // Startpunkt
  int x2, y2;                           // Endpunkt
  int xc, yc;                           // Mittelpunkt
public:
  ARC();
};

class AREA {
public:
  int x1, y1;
  int x2, y2;
public:
  AREA();
};

class CIRCLE {
public:
  int layer;
  int radius;
  int width;
  int x, y;
public:
  CIRCLE();
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
public:
  int diameter[101];                    // defined only for {LAYER_TSTOP, LAYER_BSTOP} &&  defines the stop masks diameter there.
  int drill;                            //
  int drillsymbol;                      // number of drill symbol, that is assigned acc. to diameter. See handbook. 0 = none.
  int x, y;                             //
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
public:
  std::string name;                     //
  std::string signal;                   //
  double angle;                         // (0.0...359.9)
  int diameter[101];                    //
  int shape[101];                       // PAD_SHAPE_{SQUARE,ROUND,OCTAGON,LONG,OFFSET}
  int drill;                            //
  int drillsymbol;                      //
  int elongation;                       //
  int flags;                            // PAD_FLAG_{STOP,THERMALS,FIRST}
  int x, y;                             //
public:
  PAD();
};

class WIRE {
public:
  std::string extent;                   // Only airwires, the layers a via or airwire extends through, given as "topmost-bottommost"
//ARC arc;
  int cap;                              // CAP_FLAT,CAP_ROUND
  double curve;                         //
  int layer;                            // LAYER_(*)
  int style;                            // WIRE_STYLE_{CONTINUOUS,LONGDASH,SHORTDASH,DASHDOT}
  int width;                            //
  int x1, y1;                           // Anfangspunkt
  int x2, y2;                           // Endpunkt

  // Loop members
  std::vector<WIRE> pieces;
public:
  WIRE();
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
};

class TEXT {
public:
  std::string value;
  int align;                            // ALIGN_{BOTTOM_LEFT,BOTTOM_CENTER,BOTTOM_RIGHT,CENTER_LEFT,CENTER,CENTER_RIGHT,TOP_LEFT,TOP_CENTER,TOP_RIGHT}
  double angle;                         // (0.0...359.9)
  int font;                             // FONT_VECTOR, FONT_PROPORTIONAL, FONT_FIXED
  int layer;                            // LAYER_(*)
  int linedistance;                     //
  bool mirror;                          //
  int ratio;                            //
  double size;                          //
  bool spin;                            //
  double x, y;                          //

  // Loop members
  std::vector<WIRE> wires;
public:
  TEXT();
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
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

class RECTANGLE {
public:
  double angle;                         // (0.0...359.9)
  int layer;                            //
  int x1, y1;                           // lower left
  int x2, y2;                           // upper right
public:
  RECTANGLE();
};

class SMD {
public:
  std::string name;                     //
  std::string signal;                   // member not in *.lbr initialized.
  double angle;                         // (0.0...359.9)
  int dx, dy;                           //
  int flags;                            // flags of SMD_FLAG_{STOP,CREAM,THERMALS}
  int layer;                            // LAYER_(*)
  int roundness;                        //
  int x, y;                             //
public:
  SMD();
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
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

class PACKAGE {
public:
  std::string description;
  std::string headline;
  std::string library;
  std::string name;
  AREA area;

  // Loop members
  std::vector<CIRCLE> circles;
  std::vector<CONTACT> contacts;
  std::vector<DIMENSION> dimensions;
  std::vector<FRAME> frames;
  std::vector<HOLE> holes;
  std::vector<POLYGON> polygons;
  std::vector<RECTANGLE> rectangles;
  std::vector<SMD> smds;
  std::vector<TEXT> texts;
  std::vector<WIRE> wires;
public:
  PACKAGE();
};

class DEVICE {
public:
  std::string activetechnology;         //
  std::string description;              //
  std::string headline;                 //
  std::string library;                  //
  std::string name;                     //
  std::string prefix;                   //
  std::string technologies;             // all techologies, separated by a SPACE
  bool value;                           // string ("On" oder "Off")
  AREA area;                            //
  PACKAGE package;

  //Loop members
  std::vector<ATTRIBUTE> attributes(std::string technology);
  std::vector<GATE> gates;
public:
  DEVICE();
};

class DEVICESET {
public:
  std::string library;                  //
  std::string description;              // vollstaendiger Beschreibungstext, der mit dem DESCRIPTION-Befehl erzeugt wurde
  std::string headline;                 // erste Zeile der Beschreibung ohne HTML-Tags ausgibt
  std::string name;                     //
  std::string prefix;                   //
  DEVICE* activedevice;                 // if a set is currently beeing edited, this one is delivered here.
  AREA area;                            //
  bool value;                           // string ("On" oder "Off")

  // Loop members
  std::vector<DEVICE> devices;
  std::vector<GATE> gates;
public:
  DEVICESET();
};

class DIMENSION {
  bool visible;                         // int (0=off, 1=on)
  int dtype;                            // DIMENSION_{PARALLEL,HORIZONTAL,VERTICAL,RADIUS,DIAMETER,ANGLE,LEADER}
  int extlength;                        //
  int extoffset;                        //
  int extwidth;                         //
  int layer;                            //
  int precision;                        // (Genauigkeit der Massangabe)
  int ratio;                            //
  double size;                          //
  int unit;                             // Einheit: GRID_UNIT_{MIC,MM,MIL,INCH}
  double width;                         //
  double x1, y1;                        // (erster Bezugspunkt)
  double x2, y2;                        // (zweiter Bezugspunkt)
  double x3, y3;                        // (Hilfspunkt für die Ausrichtung)

  // Loop members
  std::vector<TEXT> texts;
  std::vector<WIRE> wires;
public:
  DIMENSION();
};

class FRAME {
public:
  int columns;                          // (-127...127)
  int rows;                             // (-26...26)
  int border;                           // FRAME_BORDER_{BOTTOM,RIGHT,TOP,LEFT}
  int layer;                            //
  int x1, y1;                           // lower left
  int x2, y2;                           // upper right

  // Loop members
  std::vector<TEXT> texts;
  std::vector<WIRE> wires;
public:
  FRAME();
};

class SYMBOL {
public:
  std::string name;
  std::string description;
  std::string headline;
  std::string library;
  AREA area;

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

class PIN {
public:
  std::string name;                     //
  std::string net;                      //
  double angle;                         // (0,90,180,270)
  CONTACT contact;                      // deprecated.
  int direction;                        // PIN_DIRECTION_{NC,IN,OUT,IO,OC,PWR,PAS,HIZ,SUP}
  int function;                         // PIN_FUNCTION_FLAG_{NONE,DOT,CLK}
  int length;                           // PIN_LENGTH_{POINT,SHORT,MIDDLE,LONG}
  int route;                            // CONTACT_ROUTE_{ANY,ALL}
  int swaplevel;
  int visible;                          // or'ed flags: PIN_VISIBLE_FLAG_{OFF,PIN,PAD}
  int x, y;

  // Loop members
  std::vector<CIRCLE> circles;
  std::vector<CONTACT> contacts;
  std::vector<TEXT> texts;
  std::vector<WIRE> wires;
public:
  PIN();
};

class VERTEX {
public:
  int x,y;
  double curve;                         //  The curvature from this vertex to the next one
public:
  VERTEX();
};

class POLYGON {
public:
  int isolate;                          //
  int layer;                            // LAYER_(*)
  bool orphans;                         // int (0=off, 1=on)
  int pour;                             // POLYGON_POUR_{SOLID,HATCH,CUTOUT}
  int rank;                             //
  int spacing;                          //
  bool thermals;                        // int (0=off, 1=on)
  double width;

  // Loop members
  std::vector<WIRE> contours;
  std::vector<WIRE> fillings;
  std::vector<WIRE> wires;
public:
  POLYGON();
  void Parse(pugi::xml_attribute_iterator begin, pugi::xml_attribute_iterator end);
  void Parse(pugi::xml_node_iterator begin, pugi::xml_node_iterator end);
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








