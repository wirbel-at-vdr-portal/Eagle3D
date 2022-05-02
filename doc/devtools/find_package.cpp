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


typedef struct {
  std::string lbr;
  std::string name;
  std::string desc;  
} tPackage;


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
     bool description = false;
     bool deviceset = false;
     size_t p,p2;
     std::string package_name;
     std::string package_desc;

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
           package_name.clear();
           description = false;
           p = line.find("name=\"");
           if (p == std::string::npos) {
              // this is either a serious bug in the eagle library, or, in this tool.
              std::cerr << "ERROR: name not found in library '" << file << ": '" << line << "'" << std::endl;
              return -1;
              }
           else {
              p+=6;
              p2 = line.find("\"",p);
              package_name = line.substr(p, p2-p);
              if (not Matches(package_name, pattern))
                 package = false;
              }
           }

        if (not package)
           continue;

        if (not description) {
           p = line.find("<description>");
           if (p != std::string::npos) {
              description = true;
              package_desc = line.substr(p + 13);
              }
           continue;
           }

        p = line.find("</description>");
        if (p != std::string::npos) {
           if (p != 0)
              package_desc += line.substr(0,p);

           ReplaceAll(package_desc,"  "," ");
           ReplaceAll(package_desc,"&lt;","<");
           ReplaceAll(package_desc,"&gt;",">");
           ReplaceAll(package_desc,"<b>","");
           ReplaceAll(package_desc,"<B>","");
           ReplaceAll(package_desc,"</b>","");
           ReplaceAll(package_desc,"</B>","");
           ReplaceAll(package_desc,"<i>","");
           ReplaceAll(package_desc,"<I>","");
           ReplaceAll(package_desc,"</i>","");
           ReplaceAll(package_desc,"</I>","");
           ReplaceAll(package_desc,"<p>","");
           ReplaceAll(package_desc,"<P>","");
           ReplaceAll(package_desc,"</p>","");
           ReplaceAll(package_desc,"</P>","");
           ReplaceAll(package_desc,"<br>","");
           ReplaceAll(package_desc,"<BR>","");
           ReplaceAll(package_desc,"https://","");
           ReplaceAll(package_desc,"http://","");
           ReplaceAll(package_desc,"ftp://","");

           deviceset = false;
           std::string devnames;
           std::string deviceset_name;
           for(auto line:lines) {
              if (not deviceset) {
                 p = line.find("<deviceset");
                 if (p == std::string::npos)
                    continue;
                 p += 10;
                 deviceset = true;

                 p = line.find("name=\"");
                 if (p == std::string::npos) {
                    deviceset = false;
                    continue;
                    }
                 p += 6;
                 p2 = line.find("\"",p);
                 deviceset_name = line.substr(p,p2-p);
                 }

              p = line.find("</deviceset>");
              if (p != std::string::npos) {
                 deviceset = false;
                 deviceset_name.clear();
                 continue;
                 }

              if (not deviceset)
                 continue;

              p = line.find("<device ");
              if (p == std::string::npos)
                 continue;

              p += 8;
              p = line.find("package=\"",p);

              if (p == std::string::npos)
                 continue;

              p += 9;
              p2 = line.find("\"",p);

              std::string ThisPackage = line.substr(p,p2-p);
              if (ThisPackage != package_name) {
                 continue;
                 }
              devnames += deviceset_name + ",";
              }

/*
<deviceset name="BTS428L2" prefix="IC">
<description>&lt;b&gt;Smart High-Side Power Switch&lt;/b&gt;&lt;p&gt;
One Channel: 60mOhm Status Feedback&lt;br&gt;
Source: Source: www.infineon.com .. BTS428L2_20030912.pdf</description>
<gates>
<gate name="G$1" symbol="BTS428L2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TO252-5-11">
<connects>
<connect gate="G$1" pin="GND" pad="1"/>
<connect gate="G$1" pin="IN" pad="2"/>
<connect gate="G$1" pin="OUT" pad="5"/>
<connect gate="G$1" pin="ST" pad="4"/>
<connect gate="G$1" pin="VBB" pad="TAB"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>

*/

           std::cout << BackFill(file + ':' + std::to_string(LineNumber) + ":", 35) 
                     << BackFill("package: '" + package_name + "'", 30)
                     << BackFill("description: '" + package_desc + "'", 100)
                     << "devices: " << devnames
                     << std::endl;

           package = false;
           }
        }
     }

  return 0;
}
