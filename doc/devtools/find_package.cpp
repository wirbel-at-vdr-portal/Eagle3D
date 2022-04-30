/*******************************************************************************
 * Eagle3D - generates 3d images from Eagle PCB board files.
 *
 * See the README file for copyright information and how to reach the author.
 ******************************************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "repfunc.h"

int main(int n, char** args) {
  if (n < 3) {
     std::cerr << "usage:\n"
               << args[0] << " <EAGLE_LIB_DIR> <PATTERN>" << std::endl; 
     return -1;
     }

  std::string dir(args[1]);
  std::string pattern(args[2]);

  auto files = cFileList(dir, ".lbr").List();
  std::sort(files.begin(), files.end());

  for(auto file:files) {
     std::vector<std::string> lines = ReadFile(dir + "\\" + file);
     size_t LineNumber = 0;
     bool packages = false;
     bool package = false;
     size_t p,p2;
     std::string package_name;

     for(auto line:lines) {
        LineNumber++;

        if (line.find("<packages>") != std::string::npos)
           packages = true;
        else
           if (line.find("</packages>") != std::string::npos)
              packages = false;

        if (not packages)
           continue;

        if (line.find("<package ") != std::string::npos) {
           package = true;
           p = line.find("name=\"");
           if (p == std::string::npos) {
              std::cout << "ERROR: name not found in library '" << file << ": '" << line << "'" << std::endl;
              // this is either a serious bug in the eagle library, or, in this tool.
              return -1;
              }
           else {
              p+=6;
              p2 = line.find("\"",p);
              package_name = line.substr(p, p2-p);
              if (Matches(package_name, pattern))
                 std::cout << file << ':' << LineNumber << ": package '" << package_name << "'" << std::endl;
              }
           }
        }
     }

  return 0;
}
