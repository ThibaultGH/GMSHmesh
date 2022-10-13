// Some includes from the Standard C++ library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Other includes
#include "mesh.hpp"
#include "FileManagerCPP.hpp"

using namespace std;


int main(int argc, char *argv[])
{

  char *filename = "/home/tcimic/Projects/GMSHmesh/mesh/square.msh";

  mesh Th(filename);
  
  return 0;
}
