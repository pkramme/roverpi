#ifndef __VERSION_H_INCLUDED__
#define __VERSION_H_INCLUDED__

#include<fstream>

void version()
{
     std::string version;
     std::ifstream version_file("version.txt");
     if(version_file.is_open())
     {
          getline(version_file, version);
          std::cout << version << std::endl;
          version_file.close();
     }
     else
     {
          std::cout << "Cannot read version file" << std::endl;
     }
}
#endif
