#pragma once
#include <string>
#include <vector>

/*******************************************************************************
 * consts here:
 ******************************************************************************/
constexpr int CONTACT_ROUTE_ALL              = 0;  // PIN; any contact has to be connected
constexpr int CONTACT_ROUTE_ANY              = 1;  // PIN; any contact may to be connected
constexpr int FONT_VECTOR                    = 0;  // TEXT; Vector-Font
constexpr int FONT_PROPORTIONAL              = 1;  // TEXT; Proportional-Font
constexpr int FONT_FIXED                     = 2;  // TEXT; Fixed-Font
constexpr int GATE_ADDLEVEL_MUST             = 0;  // GATE;
constexpr int GATE_ADDLEVEL_CAN              = 1;  // GATE;
constexpr int GATE_ADDLEVEL_NEXT             = 2;  // GATE;
constexpr int GATE_ADDLEVEL_REQUEST          = 3;  // GATE;
constexpr int GATE_ADDLEVEL_ALWAYS           = 4;  // GATE;
constexpr int LAYER_TOP                      = 1;  // integer consts for layer. 
constexpr int LAYER_BOTTOM                   = 16; // integer consts for layer.
constexpr int LAYER_PADS                     = 17; // integer consts for layer.
constexpr int LAYER_VIAS                     = 18; // integer consts for layer.
constexpr int LAYER_UNROUTED                 = 19; // integer consts for layer.
constexpr int LAYER_DIMENSION                = 20; // integer consts for layer.
constexpr int LAYER_TPLACE                   = 21; // integer consts for layer.
constexpr int LAYER_BPLACE                   = 22; // integer consts for layer.
constexpr int LAYER_TORIGINS                 = 23; // integer consts for layer.
constexpr int LAYER_BORIGINS                 = 24; // integer consts for layer.
constexpr int LAYER_TNAMES                   = 25; // integer consts for layer.
constexpr int LAYER_BNAMES                   = 26; // integer consts for layer.
constexpr int LAYER_TVALUES                  = 27; // integer consts for layer.
constexpr int LAYER_BVALUES                  = 28; // integer consts for layer.
constexpr int LAYER_TSTOP                    = 29; // integer consts for layer.
constexpr int LAYER_BSTOP                    = 30; // integer consts for layer.
constexpr int LAYER_TCREAM                   = 31; // integer consts for layer.
constexpr int LAYER_BCREAM                   = 32; // integer consts for layer.
constexpr int LAYER_TFINISH                  = 33; // integer consts for layer.
constexpr int LAYER_BFINISH                  = 34; // integer consts for layer.
constexpr int LAYER_TGLUE                    = 35; // integer consts for layer.
constexpr int LAYER_BGLUE                    = 36; // integer consts for layer.
constexpr int LAYER_TTEST                    = 37; // integer consts for layer.
constexpr int LAYER_BTEST                    = 38; // integer consts for layer.
constexpr int LAYER_TKEEPOUT                 = 39; // integer consts for layer.
constexpr int LAYER_BKEEPOUT                 = 40; // integer consts for layer.
constexpr int LAYER_TRESTRICT                = 41; // integer consts for layer.
constexpr int LAYER_BRESTRICT                = 42; // integer consts for layer.
constexpr int LAYER_VRESTRICT                = 43; // integer consts for layer.
constexpr int LAYER_DRILLS                   = 44; // integer consts for layer.
constexpr int LAYER_HOLES                    = 45; // integer consts for layer.
constexpr int LAYER_MILLING                  = 46; // integer consts for layer.
constexpr int LAYER_MEASURES                 = 47; // integer consts for layer.
constexpr int LAYER_DOCUMENT                 = 48; // integer consts for layer.
constexpr int LAYER_REFERENCE                = 49; // integer consts for layer.
constexpr int LAYER_TDOCU                    = 51; // integer consts for layer.
constexpr int LAYER_BDOCU                    = 52; // integer consts for layer.
constexpr int LAYER_NETS                     = 91; // integer consts for layer.
constexpr int LAYER_BUSSES                   = 92; // integer consts for layer.
constexpr int LAYER_PINS                     = 93; // integer consts for layer.
constexpr int LAYER_SYMBOLS                  = 94; // integer consts for layer.
constexpr int LAYER_NAMES                    = 95; // integer consts for layer.
constexpr int LAYER_VALUES                   = 96; // integer consts for layer.
constexpr int LAYER_INFO                     = 97; // integer consts for layer.
constexpr int LAYER_GUIDE                    = 98; // integer consts for layer.
constexpr int LAYER_USER                     = 100;// integer consts for layer.
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


/*******************************************************************************
 * types and using directives here:
 ******************************************************************************/
using childs     = pugi::xml_node_iterator;
using attributes = pugi::xml_attribute_iterator;


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
class CONNECT;
class DEVICE;
class DEVICESET;


/*******************************************************************************
 * classes
 ******************************************************************************/
class CIRCLE {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x, y;                          // #REQUIRED
  double radius;                        // #REQUIRED
  double width;                         // #REQUIRED
  int layer;                            // #REQUIRED
private:
  void Parse(attributes begin, attributes end);
public:
  CIRCLE();
};

class DIMENSION {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // #REQUIRED (erster Bezugspunkt)
  double x2, y2;                        // #REQUIRED (zweiter Bezugspunkt)
  double x3, y3;                        // #REQUIRED (Hilfspunkt für die Ausrichtung)
  int layer;                            // #REQUIRED 
  std::string dtype;                    // "parallel",  ("parallel","horizontal","vertical","radius","diameter","angle","leader")
                                        //       parallel   - lineare Bemassung mit paralleler Masslinie
                                        //       horizontal - lineare Bemassung mit waagerechter Masslinie
                                        //       vertical   - lineare Bemassung mit senkrechter Masslinie
                                        //       radius     - Radius-Bemassung
                                        //       diameter   - Durchmesser-Bemassung
                                        //       angle      - Winkel-Bemassung
                                        //       leader     - ein beliebiger Pfeil
  double width;                         // #REQUIRED 
  double extwidth;                      // 0
  double extlength;                     // 0
  double extoffset;                     // 0
  double size;                          // #REQUIRED textsize
  int ratio;                            // 8    textratio
  std::string unit;                     // mm   Einheit: "mic","mm","mil","inch"
  int precision;                        // 2    Nachkommastellen,Genauigkeit der Massangabe
  bool visible;                         // no   int (0=off, 1=on)
private:
  void Parse(attributes begin, attributes end);
public:
  DIMENSION();
};

class FRAME {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // #REQUIRED lower left
  double x2, y2;                        // #REQUIRED upper right
  int columns;                          // #REQUIRED (-127...127)
  int rows;                             // #REQUIRED (-26...26)
  int layer;                            // #REQUIRED
  bool border_left;                     // yes  draw border?
  bool border_top;                      // yes  draw border?
  bool border_right;                    // yes  draw border?
  bool border_bottom;                   // yes  draw border?
private:
  void Parse(attributes begin, attributes end);
public:
  FRAME();
};

class GRID {
friend class DRAWING;
public:
  double distance;                      // #IMPLIED
  std::string unitdist;                 // #IMPLIED Einheit: "mic","mm","mil","inch"
  std::string unit;                     // #IMPLIED Einheit: "mic","mm","mil","inch"
  std::string style;                    // "lines"   lines | dots
  int multiple;                         // "1"
  bool display;                         // "no"
  double altdistance;                   // #IMPLIED
  std::string altunitdist;              // #IMPLIED Einheit: "mic","mm","mil","inch"
  std::string altunit;                  // #IMPLIED Einheit: "mic","mm","mil","inch"
private:
  void Parse(attributes begin, attributes end);
public:
  GRID();
};

class HOLE {
friend class PACKAGE;
public:
  double x, y;                          // #REQUIRED
  double drill;                         // #REQUIRED
private:
  void Parse(attributes begin, attributes end);
public:
  HOLE();
};

class LAYER {
friend class DRAWING;
public:
  int number;                           // #REQUIRED
  std::string name;                     // #REQUIRED
  int color;                            // #REQUIRED
  int fill;                             // #REQUIRED
  bool visible;                         // "yes"
  bool active;                          // "yes" (false=unbenutzt, true=benutzt)
private:
  void Parse(attributes begin, attributes end);
public:
  LAYER();
};

class PAD {
friend class PACKAGE;
public:
  std::string name;                     // #REQUIRED
  double x, y;                          // #REQUIRED
  double drill;                         // #REQUIRED
  double diameter;                      // 0
  std::string shape;                    // "round"  {SQUARE,ROUND,OCTAGON,LONG,OFFSET}
  double angle;                         // "rot"="R0" (0.0...359.9)
  bool stop;                            // "yes" Loetstopmaske generieren
  bool thermals;                        // "yes" Thermals generieren
  bool first;                           // "no" spezielle Form fuer "erstes Pad" verwenden 
private:
  void Parse(attributes begin, attributes end);
public:
  PAD();
};

class POLYGON {
friend class PACKAGE;
friend class SYMBOL;
public:
  class VERTEX {
  public:
     double x,y;                        // #REQUIRED
     double curve;                      // 0 The curvature from this vertex to the next one
  public:
     VERTEX() : curve(0.0) {}
  };
public:
  double width;                         // #REQUIRED
  int layer;                            // #REQUIRED  LAYER_(*)
  double spacing;                       // #IMPLIED
  std::string pour;                     // "solid"
  double isolate;                       // #IMPLIED   Only in <signal> or <package> context
  bool orphans;                         // "no"       Only in <signal> context
  bool thermals;                        // "yes"      Only in <signal> context
  int rank;                             // 0          1..6 in <signal> context, 0 or 7 in <package> context
  std::vector<VERTEX> vertices;         // (vertex)*
private:
  void Parse(attributes begin, attributes end);
  void Parse(childs begin, childs end);
public:
  POLYGON();
};

class RECTANGLE {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // #REQUIRED lower left
  double x2, y2;                        // #REQUIRED upper right
  int layer;                            // #REQUIRED
  double angle;                         // "R0" (0.0...359.9)
private:
  void Parse(attributes begin, attributes end);
public:
  RECTANGLE();
};

class SMD {
friend class PACKAGE;
public:
  std::string name;                     // #REQUIRED
  double x, y;                          // #REQUIRED
  double dx, dy;                        // #REQUIRED
  int layer;                            // #REQUIRED LAYER_(*)
  int roundness;                        // 0
  double angle;                         // "rot"="R0" (0.0...359.9)
  bool stop;                            // "yes"
  bool thermals;                        // "yes"
  bool cream;                           // "yes"
private:
  void Parse(attributes begin, attributes end);
public:
  SMD();
};

class TEXT {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x, y;                          // #REQUIRED
  double size;                          // #REQUIRED
  int layer;                            // #REQUIRED  LAYER_(*)
  std::string font;                     // "proportional"
  int ratio;                            // 8
  double angle;                         // "rot"=R0 (0.0...359.9)
  bool mirror;                          // "rot" M
  bool spin;                            // "rot" S
  std::string align;                    // "bottom-left"
  int distance;                         // 50  linedistance
  std::string value;                    // (#PCDATA)
private:
  void Parse(attributes begin, attributes end);
public:
  TEXT();
};

class WIRE {
friend class PACKAGE;
friend class SYMBOL;
public:
  double x1, y1;                        // #REQUIRED   Anfangspunkt
  double x2, y2;                        // #REQUIRED   Endpunkt
  double width;                         // #REQUIRED
  int layer;                            // #REQUIRED   LAYER_(*)
  std::string extent;                   // #IMPLIED    Only airwires, the layers a via or airwire extends through, given as "topmost-bottommost"
  std::string style;                    // "continuous" {continuous,longdash,shortdash,dashdot}
  double curve;                         // 0
  bool cap_round;                       // "round" -> true, needs (curve!=0)
private:
  void Parse(attributes begin, attributes end);
public:
  WIRE();
};

class PACKAGE {
friend class LIBRARY;
public:
  std::string description;              // #PCDATA?
  std::string headline;                 // first line of description.
  std::string name;                     // #REQUIRED
  std::vector<POLYGON> polygons;        // polygon*
  std::vector<WIRE> wires;              // wire*
  std::vector<TEXT> texts;              // text*
  std::vector<DIMENSION> dimensions;    // dimension*
  std::vector<CIRCLE> circles;          // circle*
  std::vector<RECTANGLE> rectangles;    // rectangle*
  std::vector<FRAME> frames;            // frame*
  std::vector<HOLE> holes;              // hole*
  std::vector<PAD> pads;                // pad*
  std::vector<SMD> smds;                // smd*
private:
  void Parse(childs begin, childs end);
public:
  PACKAGE();
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
private:
  void Parse(attributes begin, attributes end);
public:
  PIN();
};

class SYMBOL {
public:
  std::string name;
  std::string description;
  std::string headline;
  std::string library;
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
  void Parse(childs begin, childs end);
};













class ATTRIBUTE {
friend class TECHNOLOGY;
public:
  std::string name;                     // #REQUIRED 
  std::string value;                    // #IMPLIED
  double x, y;                          // #IMPLIED
  double size;                          // #IMPLIED: textsize
  int layer;                            // #IMPLIED
  int font;                             // #IMPLIED: FONT_{VECTOR,PROPORTIONAL,FIXED}
  int ratio;                            // #IMPLIED: textratio
  double angle;                         // rot %Rotation; "R0"
  bool show_value;                      // value (off | value | name | both) -> true ; Only in <element> or <instance> context
  bool show_name;                       // value (off | value | name | both) -> false; Only in <element> or <instance> context
  bool constant;                        // false; Only in <device> context; false:may be modified true:const
private:
  void Parse(attributes begin, attributes end);
public:
  ATTRIBUTE();
};

class TECHNOLOGY {
friend class DEVICE;
public:
  std::string name;                     // %String;       #REQUIRED 
  std::vector<ATTRIBUTE> Attributes;    // (attribute)*
private:
  void Parse(childs begin, childs end);
public:
  TECHNOLOGY();
};

class CONNECT {
friend class DEVICE;
public:
  std::string gate;                     // #REQUIRED
  std::string pin;                      // #REQUIRED
  std::string pad;                      // #REQUIRED
  bool route_all;                       // "all" (all | any) -> default: true
  /* NOTE: "all" means every one of the available choices.
   *       "any" means some subset of the available choices; Depending on
   *        context, it may mean just one, or it could mean that more than one
   *        is allowed. */
private:
  void Parse(attributes begin, attributes end);
public:
  CONNECT();
};

class DEVICE {
friend class DEVICESET;
public:
  std::string name;                     // %String;       ""
  std::string package;                  // %String;       #IMPLIED
  std::vector<CONNECT> connects;        //
  std::vector<TECHNOLOGY> technologies; //
private:
  void Parse(attributes begin, attributes end);
  void Parse(childs begin, childs end);
public:
  DEVICE();
};

class GATE {
friend class DEVICESET;
public:
  std::string name;                     // #REQUIRED
  std::string symbol;                   // #REQUIRED
  double x, y;                          // #REQUIRED, Aufhaengepunkt
  int addlevel;                         // GATE_ADDLEVEL_NEXT; GATE_ADDLEVEL_{MUST,CAN,NEXT,REQUEST,ALWAYS}
  int swaplevel;                        // 0
//SYMBOL symbol;                        //
private:
  void Parse(attributes begin, attributes end);
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
  // Loop members
  std::vector<DEVICE> devices;
  std::vector<GATE> gates;
public:
  DEVICESET();
  void Parse(attributes begin, attributes end);
  void Parse(childs begin, childs end);
};



//<!ELEMENT library (description?, packages?, symbols?, devicesets?)>

class LIBRARY {
friend class DRAWING;
public:
  std::string description;              // #PCDATA?    vollstaendiger Beschreibungstext, der mit dem DESCRIPTION-Befehl erzeugt wurde
  std::string headline;                 //             erste Zeile der Beschreibung ohne HTML-Tags ausgibt
  std::string name;                     // #REQUIRED   name: Only in libraries used inside boards or schematics
  std::vector<PACKAGE> packages;        // packages?
  std::vector<SYMBOL> symbols;          // symbols?
  std::vector<DEVICESET> devicesets;    // devicesets?
private:
  void Parse(childs begin, childs end);
public:
  LIBRARY();
};

class DRAWING {
public:
  bool alwaysvectorfont;                // settings?
  bool verticaltextup;                  // settings?
  GRID grid;                            // grid?
  std::vector<LAYER> layers;            // layers
  LIBRARY library;                      // (library | schematic | board)
//SCHEMATIC schematic;                  // (library | schematic | board)
//BOARD board;                          // (library | schematic | board)
 
  bool isLibrary;
  bool isSchematic;
  bool isBoard;
public:
  DRAWING();
  void Parse(childs begin, childs end);
};
