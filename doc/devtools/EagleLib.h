#pragma once
#include <string>
#include <vector>

/*******************************************************************************
 * consts here:
 ******************************************************************************/
constexpr int CAP_FLAT              = 0; // flache Kreisbogen-Enden
constexpr int CAP_ROUND             = 1; // runde Kreisbogen-Enden
constexpr int GATE_ADDLEVEL_MUST    = 0;
constexpr int GATE_ADDLEVEL_CAN     = 1;
constexpr int GATE_ADDLEVEL_NEXT    = 2;
constexpr int GATE_ADDLEVEL_REQUEST = 3;
constexpr int GATE_ADDLEVEL_ALWAYS  = 4; 
constexpr int GRID_UNIT_MIC         = 0; // micron
constexpr int GRID_UNIT_MM          = 1; // mm
constexpr int GRID_UNIT_MIL         = 2; // mil
constexpr int GRID_UNIT_INCH        = 3; // inch
constexpr int LAYER_TOP             = 1;
constexpr int LAYER_BOTTOM          = 16;
constexpr int LAYER_PADS            = 17;
constexpr int LAYER_VIAS            = 18;
constexpr int LAYER_UNROUTED        = 19;
constexpr int LAYER_DIMENSION       = 20;
constexpr int LAYER_TPLACE          = 21;
constexpr int LAYER_BPLACE          = 22;
constexpr int LAYER_TORIGINS        = 23;
constexpr int LAYER_BORIGINS        = 24;
constexpr int LAYER_TNAMES          = 25;
constexpr int LAYER_BNAMES          = 26;
constexpr int LAYER_TVALUES         = 27;
constexpr int LAYER_BVALUES         = 28;
constexpr int LAYER_TSTOP           = 29;
constexpr int LAYER_BSTOP           = 30;
constexpr int LAYER_TCREAM          = 31;
constexpr int LAYER_BCREAM          = 32;
constexpr int LAYER_TFINISH         = 33;
constexpr int LAYER_BFINISH         = 34;
constexpr int LAYER_TGLUE           = 35;
constexpr int LAYER_BGLUE           = 36;
constexpr int LAYER_TTEST           = 37;
constexpr int LAYER_BTEST           = 38;
constexpr int LAYER_TKEEPOUT        = 39;
constexpr int LAYER_BKEEPOUT        = 40;
constexpr int LAYER_TRESTRICT       = 41;
constexpr int LAYER_BRESTRICT       = 42;
constexpr int LAYER_VRESTRICT       = 43;
constexpr int LAYER_DRILLS          = 44;
constexpr int LAYER_HOLES           = 45;
constexpr int LAYER_MILLING         = 46;
constexpr int LAYER_MEASURES        = 47;
constexpr int LAYER_DOCUMENT        = 48;
constexpr int LAYER_REFERENCE       = 49;
constexpr int LAYER_TDOCU           = 51;
constexpr int LAYER_BDOCU           = 52;
constexpr int LAYER_NETS            = 91;
constexpr int LAYER_BUSSES          = 92;
constexpr int LAYER_PINS            = 93;
constexpr int LAYER_SYMBOLS         = 94;
constexpr int LAYER_NAMES           = 95;
constexpr int LAYER_VALUES          = 96;
constexpr int LAYER_INFO            = 97;
constexpr int LAYER_GUIDE           = 98;
constexpr int LAYER_USER            = 100;
constexpr int PAD_FLAG_STOP         = 1; // Loetstopmaske generieren
constexpr int PAD_FLAG_THERMALS     = 4; // Thermals generieren
constexpr int PAD_FLAG_FIRST        = 8; // spezielle Form fuer "erstes Pad" verwenden
constexpr int PAD_SHAPE_SQUARE      = 0;
constexpr int PAD_SHAPE_ROUND       = 1;
constexpr int PAD_SHAPE_OCTAGON     = 2;
constexpr int PAD_SHAPE_LONG        = 3;
constexpr int PAD_SHAPE_OFFSET      = 4;
constexpr int SMD_FLAG_STOP         = 1;
constexpr int SMD_FLAG_CREAM        = 2;
constexpr int SMD_FLAG_THERMALS     = 4;
constexpr int WIRE_STYLE_CONTINUOUS = 0; // durchgezogen
constexpr int WIRE_STYLE_LONGDASH   = 1; // lang gestrichelt
constexpr int WIRE_STYLE_SHORTDASH  = 2; // kurz gestrichelt
constexpr int WIRE_STYLE_DASHDOT    = 3; // Strich-Punkt-Linie

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
  double angle1; // Startwinkel, 0.0...359.9
  double angle2; // Endwinkel, 0.0...719.9
  int cap;
  int layer;
  int radius;
  int width;
  int x1, y1; // Startpunkt
  int x2, y2; // Endpunkt
  int xc, yc; // Mittelpunkt
};

class AREA {
public:
  int x1, y1;
  int x2, y2;
};

class CIRCLE {
public:
  int layer;
  int radius;
  int width;
  int x, y;
};

class GATE {
public:
  int color;
  int fill;
  std::string name;
  int number;
  bool used;    // int (0=unbenutzt, 1=benutzt)
  bool visible; // int (0=off, 1=on)
};

class GRID {
public:
  double distance;
  bool dots;     // int, 0=lines, 1=dots
  int multiple;
  bool on;       // int, 0=off, 1=on
  int unit;
  int unitdist;
};

class LAYER {
public:
  std::string name;
  int color;
  int fill;
  int number;
  bool used;    // int (0=unbenutzt, 1=benutzt)
  bool visible; // int (0=off, 1=on)
};

class PAD {
public:
  std::string name;
  std::string signal;
  double angle; // (0.0...359.9)
  int diameter[101];
  int shape[101];
  int drill;
  int drillsymbol;
  int elongation;
  int flags;
  int x, y;
};

class SMD {
public:
  std::string name;
  std::string signal;
  double angle; // (0.0...359.9)
  int dx[101], dy[101];
  int flags;
  int layer;
  int roundness;
  int x, y;
};

class WIRE {
public:
  ARC arc;
  int cap;
  double curve;
  int layer;
  int style;
  int width;
  int x1, y1; // Anfangspunkt
  int x2, y2; // Endpunkt

  // Loop members
  std::vector<WIRE> pieces;
};





class DEVICESET {
public:
  std::string library;
  std::string description; // vollstaendiger Beschreibungstext, der mit dem DESCRIPTION-Befehl erzeugt wurde
  std::string headline;    // erste Zeile der Beschreibung ohne HTML-Tags ausgibt
  std::string name;
  std::string prefix;
  DEVICE* activedevice;
  AREA area;
  bool value; // string ("On" oder "Off")

  // Loop members
  std::vector<DEVICE> devices;
  std::vector<GATE> gates;
};


/*
ulp720_de.pdf:p27: Objekt-Hierarchie einer Bibliothek:
LIBRARY
   GRID             // :)
   LAYER            // :)
   DEVICESET        //!
      DEVICE        //!
      GATE          // :)
   PACKAGE          //!
      CONTACT       //!
         PAD        // :)
         SMD        // :)
      CIRCLE        // :)
      HOLE          //!        
      RECTANGLE     //!
      FRAME         //!
      DIMENSION     //!
      TEXT          //!
      WIRE          // :)
      POLYGON       //!
         WIRE       // :)
   SYMBOL           //!
      PIN           //!
      CIRCLE        // :)
      RECTANGLE     //!
      FRAME         //!
      DIMENSION     //!
      TEXT          //!
      WIRE          // :)
      POLYGON       //!
         WIRE       // :)
*/


class LIBRARY {
public:
  std::string description; // vollstaendiger Beschreibungstext, der mit dem DESCRIPTION-Befehl erzeugt wurde
  std::string headline;    // erste Zeile der Beschreibung ohne HTML-Tags ausgibt
  std::string name;
  GRID grid;

  // Loop members
  std::vector<DEVICE> devices;
  std::vector<DEVICESET> devicesets; 
  std::vector<LAYER> layers;
  std::vector<PACKAGE> packages;
  std::vector<SYMBOL> symbols;
};




int main() {
  LIBRARY lib;


  return 0;
}
