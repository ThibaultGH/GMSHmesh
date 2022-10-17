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

  int m_NbCorners = 0;
  int m_NbEdgesOnBorder = 0;
  int m_NbNodes;
  int m_NbElements;
  int m_NbTriangle = 0;
  int* m_EdgesOnBorder;
  float* m_Nodes;
  int* m_Elements;
  int* m_Triangle;
  // char* m_filename;

public:

  // Constructor and destructor of an item of the class mesh
  mesh(char* filename);
  ~mesh();

  // Some GETS function to read value of private members of an item of the class
  int NbCorners() const;
  int NbEdgesOnBorder() const;
  int NbNodes() const;
  int NbElements() const;
  int NbTriangle() const;
  int* EdgesOnBorder() const;
  float* Nodes() const;
  int* Elements() const;
  int* Triangle() const;

  



};

// Functions that computes the area of an element given its Nodes indexes
float ComputeAreaElement(const float* vec1, const float* vec2);

#endif
  
// void read_mesh_file(int &nb_corner, int* &corner, int &nb_border_edges, int* &border_edges, int &NbNodes, int &NbElements, float* &Nodes, int* Elements, const char* filename);
