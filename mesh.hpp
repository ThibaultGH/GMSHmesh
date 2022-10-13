#ifndef MESH_HPP
#define MESH_HPP

// Some STL C++ includes
#include <map>
#include <string>
#include <list>

using namespace std;

class mesh{

private :

  // int nb_corners;
  // int* corners;
  // int nb_border_edges;
  // int* border_edges;
  int NbNodesOnBorder;
  int* NodesOnBorder;
  int NbEdgesOnBorder;
  int* EdgesOnBorder;

  map<string,list<int>> Labels;
  
  int nb_nodes;
  float *nodes;
  int nb_elements;
  int* elements;
  char* filename;

public:

  // Constructor of an item of the class mesh
  mesh(char* filename);

  //Destructor of an item of the class mesh
  ~mesh();



};

// Functions that computes the area of an element given its nodes indexes
float ComputeAreaElement(const int s1, const int s2, const int s3, const float* nodes);
#endif
  
// void read_mesh_file(int &nb_corner, int* &corner, int &nb_border_edges, int* &border_edges, int &nb_nodes, int &nb_elements, float* &nodes, int* elements, const char* filename);
