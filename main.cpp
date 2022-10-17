// Some includes from the Standard C++ library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Other includes
#include "mesh.hpp"
#include "FileManagerCPP/FileManagerCPP.hpp"

using namespace std;


int main(int argc, char *argv[])
{

  char filename[100] = "/home/tcimic/Projects/GMSHmesh/mesh/pipeline_step.msh";

  mesh Th(filename);

  cout << Th.NbCorners() << endl;
  
  for (int i0 = 0; i0 < Th.NbEdgesOnBorder(); ++i0) {
    cout << "e" << i0 << " : " << Th.EdgesOnBorder()[3*i0] << " " << Th.EdgesOnBorder()[3*i0+1] << " " << Th.EdgesOnBorder()[3*i0+2] << endl;
  }
  
  return 0;
}
