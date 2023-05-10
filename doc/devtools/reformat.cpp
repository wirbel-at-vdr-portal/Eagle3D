/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include "repfunc.h"


size_t NextKeyword(std::string& s, size_t p = 0) {
  const char* keywords[] = {
     "#macro", "#if", "#else", "#end","#switch","#case","#break","#while",
     "object","union","difference","intersection","append","component","composite",
     "merge",
     "concat","cone","interpolate","lathe","linear_spline","linear_sweep",
     "cylinder","box","torus","text","bezier_spline","bicubic_patch","cube","prism",
     "cubic_spline","cubic_wave","cubic","cylindrical","hexagon","polygon","sphere",
     "hollow","hypercomplex","height_field","repeat"
     "texture","pigment","rgbft","rgbf","rgbt","rgb","finish","ambient_light",
     "ambient","absorption","diffuse","reflection","specular","roughness","phong_size","phong","metallic",
     "alpha","aperture","brightness","brilliance","colour",
     "material_map","material",
     "translate","rotate","scale","transform","while",
    };

  size_t n = sizeof(keywords)/sizeof(keywords[0]);
  size_t pos = std::string::npos;
  for(size_t i=0; i<n; i++)
     pos = std::min(pos, s.find(keywords[i], p));
  return pos;
}

void SplitString(std::string& s, size_t pos, std::string& before, std::string& after) {
  if (pos >= s.size())
     return;

  if (&s != &before) {
     before = s.substr(0,pos);
     after  = s.substr(pos);
     }
  else {
     std::string t = s.substr(0,pos);
     after  = s.substr(pos);
     before = t;
     }
}

void Comment(std::string& s, bool& isComment) {
  bool begin = s.find("/*") == 0;
  bool end   = s.find("*/",2) != std::string::npos;

  if (begin and not end) {
     if (s.find_first_not_of(" /*") == std::string::npos and s.size() != 80)
        s = "/*******************************************************************************";
     }
  if (end and not begin) {
     if (s.find_first_not_of(" /*") == std::string::npos and s.size() != 80)
        s = " ******************************************************************************/";
     }
  if (isComment and s.find("//") == 0) {
     s.replace(0,2," *");
     }
  if (isComment and s.size() > 2) {
     while(s.find("--") != std::string::npos)
        ReplaceAll(s, "--", "");
     if (not begin and s[2] != ' ')
        s.insert(2,1,' ');
     }
  if (end)
     isComment = false;
}


std::string Indent(std::string s) {
  static int this_indent = 0;
  static int next_indent = 0;
  static bool isCase = false;

  int step = next_indent == 0 ? 2 : 3;
  if (this_indent != next_indent)
     this_indent = next_indent;

  if (s.find('{') != std::string::npos) {
     next_indent = this_indent + step;
     }
  if (s.find('}') != std::string::npos) {
     next_indent = std::max(this_indent - step,0);
     }

  if (s.find('#') == 0) {
     if (s.find("#macro") == 0)
        next_indent = this_indent + step;
     else if (s.find("#while") == 0)
        next_indent = this_indent + step;
     else if (s.find("#switch") == 0)
        next_indent = this_indent + step;
     else if (s.find("#case") == 0) {
        next_indent = this_indent + step;
        isCase = true;
        }
     else if (s.find("#break") == 0) {
        next_indent = std::max(this_indent - step,0);
        }
     else if (s.find("#if") == 0) {
        char c = s[3];
        if (c == '(') {
           s.insert(3, 1, ' ');
           c = s[3];
           }
        if (c == ' ')
           next_indent = this_indent + step;
        }
     else if (s.find("#else") == 0) {
        if (not isCase)
           this_indent = std::max(this_indent - step,0);
        next_indent = this_indent + step;
        isCase = false;
        }
     else if (s.find("#end") == 0) {
        if (not isCase)
           this_indent = std::max(this_indent - step,0);
        next_indent = this_indent;
        isCase = false;
        }
     }

  if (this_indent == 0)
     return s;

  return std::string(this_indent, ' ') + s;
}







int main(int n, char** args) {
  if (n < 3) {
     std::cerr << "usage:\n"
               << args[0] << " <from> <to>" << std::endl; 
     return -1;
     }


  auto lines = ReadFile(args[1]);

  std::stringstream ss;
  std::vector<std::string> newlines;

  for(auto line:lines) {
     size_t count = 0;

     ReplaceAll(line, "ß", "ss");
     ReplaceAll(line, "ä", "ae");
     ReplaceAll(line, "ö", "oe");
     ReplaceAll(line, "ü", "ue");
     ReplaceAll(line, "Ä", "Ae");
     ReplaceAll(line, "Ö", "Oe");
     ReplaceAll(line, "Ü", "Ue");
     ReplaceAll(line, "scale<", "scale <");
     ReplaceAll(line, "rotate<", "rotate <");
     ReplaceAll(line, "translate<", "translate <");
     ReplaceAll(line, "><", "> <");

     for(size_t i=0; i<line.size(); i++) {
        if (line[i] == '{')
           count++;
        }
     auto openings = SplitStr(line, '{');


     for(size_t i=0; i<count; i++) {
        std::string&s = openings[i];
        s = Trim(s);
        s += " {";
        }
     for(size_t i=count; i<openings.size(); i++) {
        std::string&s = openings[i];
        s = Trim(s);
        }

     for(auto op:openings) {
        count = 0;
        for(size_t i=0; i<op.size(); i++) {
           if (op[i] == '}')
              count++;
           }
        for(auto& s:SplitStr(op, '}')) {
           s = Trim(s);
           if (not s.empty())
              ss << s << std::endl;
           if (count > 0) {
              ss << '}' << std::endl;
              count--;
              }
           }
        }
     }
  lines.clear();


  std::string s;
  static bool isComment = false;
  while(std::getline(ss, s)) {
     if (not isComment and Trim(s).find("//") == 0) {
        s = Indent(Trim(s));
        newlines.push_back(s);
        continue;
        }

     if (Trim(s) == "{") {
        newlines.back() += " {";
        continue;
        }

     if (Trim(s) == ";") {
        newlines.back() += s;
        continue;
        }

     if (s.find("/*") == 0)
        isComment = true;

     if (isComment)
        Comment(s, isComment);

     if (s.size() > 7) {
        for(size_t i=0; i<s.size()-2; i++) {
           if (s[i] == '>') {
              if (s[i+1] == ',')
                 i++;
              if (s[i+1] != ' ')
                 s.insert(i+1, 1, ' ');
              }
           }
        }

     size_t pos = NextKeyword(s);
     std::string next;

     if (pos != std::string::npos) {
        SplitString(s, pos, s, next);
        s = Trim(s);
        }

     if (not s.empty()) {
        s = Indent(s);
        newlines.push_back(s);
        if (s == "#end")
           newlines.push_back("");
        }
     if (not next.empty()) {
        next = Indent(next);
        newlines.push_back(next);
        if (next == "#end")
           newlines.push_back("");
        }
     }


  std::remove(args[2]);
  WriteFile(args[2],newlines);


  return 0;
}
