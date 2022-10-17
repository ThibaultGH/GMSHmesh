#ifndef MESH_HPP
#define MESH_HPP

// Some STL C++ includes
#include <string>
#include <set>

using namespace std;

class mesh{

private :

  // int nb_corners;
  // int* corners;
  // int nb_border_edges;
  // int* border_edges;
  // int NbNodesOnBorder;
  // int* NodesOnBorder;
  // int NbEdgesOnBorder;
  // int* EdgesOnBorder;

  int NbCorners = 0;
  int NbEdgesOnBorder = 0;
  int* EdgesOnBorder;
  
  int NbNodes;
  float *Nodes;
  int NbElements;
  int NbTriangle = 0;
  int* Elements;
  int* Triangle;
  char* filename;

public:

  // Constructor of an item of the class mesh
  mesh(char* filename);

  //Destructor of an item of the class mesh
  ~mesh();



};

// Functions that computes the area of an element given its Nodes indexes
float ComputeAreaElement(const float* vec1, const float* vec2);

#endif
  
// void read_mesh_file(int &nb_corner, int* &corner, int &nb_border_edges, int* &border_edges, int &NbNodes, int &NbElements, float* &Nodes, int* Elements, const char* filename);
