// Some includes from the Standard C++ library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Other includes
#include "mesh.hpp"
#include "FileManagerCPP/FileManagerCPP.hpp"
#include <gsl/gsl_cblas.h>

using namespace std;

mesh::mesh(char* filename){

  // Construct a flux to read the mesh file in :
  ifstream MyFile(filename);
  
  // Some local variables :
  string LineMyFile;
  char space = ' ';
  bool FoundNbNodes = false;
  bool FoundNbElements = false;
  vector<string> SplittedLine;
  int s1,s2,s3; // integer to right down the indexes of the nodes that forms a triangle
  float *s2s1;
  s2s1 = (float *) malloc(sizeof(float)*2);
  float *s3s1;
  s3s1 = (float *) malloc(sizeof(float)*2);

  // Start reading the mesh file
  if (MyFile.is_open()) {

    while (getline(MyFile,LineMyFile)) {

      /*This while loop works this way :
	     _ if a line "$Nodes" or "$Elements" is found, the next line gets us the number of Nodes and Elements respectively.
	     _ Once we got them, we will read the lines of the file exactly this number of times.
	     _ For the Nodes : 
	           _ The first number we encounter is the number of the Nodes that we discard, the next three are the coordinates that we but into an array Nodes[NbNodes*3].
	       For the Elements :
	           _ The three integer number we get are the number of the Nodes forming a triangle, starting from 1 we need to do -1 to respect indexation in C++ starting at 0.*/
      
      if (FoundNbNodes) {
	
	m_NbNodes = stoi(LineMyFile);
	FoundNbNodes = false;

	m_Nodes = (float* ) malloc(sizeof(float)*m_NbNodes*3);

	for (int i0 = 0; i0 < m_NbNodes; ++i0) {

	  getline(MyFile,LineMyFile);

	  SplittedLine = split(LineMyFile,space); // SplittedLine = {"node_number","node_1st_coor","node_2nd_coor","node_3rd_coor"}

	  // cout << "We are writting node " << SplittedLine[0] << " with coordinate : ";

	  for (int i1 = 0; i1 < SplittedLine.size()-1; ++i1) {
	    m_Nodes[(stoi(SplittedLine[0])-1)*3+i1] = stof(SplittedLine[i1+1]);
	    // cout << SplittedLine[i1+1] << " ";

	  }

	  // cout << endl;

	}
      }
      else if (FoundNbElements) { // We will enter once here after we've crossed the expression "$Elements" and load all the Elements in the array Elements.
	m_NbElements = stoi(LineMyFile);
        
	
	m_Elements = (int* ) malloc(sizeof(int)*m_NbElements*3);
	
	FoundNbElements = false;

	for (int i2 = 0; i2 < m_NbElements; ++i2) {
	  getline(MyFile,LineMyFile);

	  SplittedLine = split(LineMyFile,space);
	  
	  s1 = stoi(SplittedLine[SplittedLine.size()-3]);
	  s2 = stoi(SplittedLine[SplittedLine.size()-2]);
	  s3 = stoi(SplittedLine[SplittedLine.size()-1]);
	  

	  if (s1*s2*s3 == 0) {
	    // cout << " its a corner" << endl;

	    m_Elements[3*i2] = -1;
	    m_Elements[3*i2+1] = s3;
	    m_Elements[3*i2+2] = -1;

	    ++m_NbCorners;
	    	    
	  }
	  else {
	    
	    --s1;
	    --s2;
	    --s3;
	    
	    s2s1[0] = m_Nodes[3*s2]-m_Nodes[3*s1];
	    s2s1[1] = m_Nodes[3*s2+1]-m_Nodes[3*s1+1];
	    
	    s3s1[0] = m_Nodes[3*s3]-m_Nodes[3*s1];
	    s3s1[1] = m_Nodes[3*s3+1]-m_Nodes[3*s1+1];

	    // cout << "Triangle " << s1 << " " << s2 << " " << s3 << endl;
	    // cout << "with coordinates : " << endl;
	    // cout << "s1 : " << m_Nodes[3*s1] << " " << m_Nodes[3*s1+1] << endl;
	    // cout << "s2 : " << m_Nodes[3*s2] << " " << m_Nodes[3*s2+1] << endl;
	    // cout << "s3 : " << m_Nodes[3*s3] << " " << m_Nodes[3*s3+1] << endl;

	  
	  
	    // cout << "has an area of : " << ComputeAreaElement(s2s1,s3s1) << endl;

	    if (ComputeAreaElement(s2s1,s3s1) == 0) {
	      // cout << "it's a flat triangle, so each of its summits and edges are on the border !" << endl; Exactly (s2,s3) forms an edge on the boarder.

	      m_Elements[3*i2] = -2;
	      m_Elements[3*i2+1] = s2;
	      m_Elements[3*i2+2] = s3;
	      
	      ++m_NbEdgesOnBorder;

	    }
	    else {

	      m_Elements[3*i2] = s1;
	      m_Elements[3*i2+1] = s2;
	      m_Elements[3*i2+2] = s3;

	      ++m_NbTriangle;
	      
	    }

	  }

	}

      }
      

      if (LineMyFile == "$Nodes") {
	FoundNbNodes = true;
      }
      else if (LineMyFile == "$Elements"){
	FoundNbElements = true;
      }

      

      
    } 
  }
  else {
    cout << "ERROR : file " << filename << " NOT open !" << endl;
  }

  m_EdgesOnBorder = (m_Elements+3*m_NbCorners);
  m_Triangle = (m_Elements+3*(m_NbCorners+m_NbEdgesOnBorder));

  // cout << "There are " << m_NbElements << " elements with " << m_NbCorners << " corners, " << m_NbEdgesOnBorder << " edges on border, " << m_NbTriangle << " triangles." << endl;

  // cout << "Here are the corners : " << endl;

  // for (int k0 = 0; k0 < m_NbCorners; ++k0) {
  //   cout << "c" << k0 << " : " << m_Elements[3*k0] << " " << m_Elements[3*k0+1] << " " << m_Elements[3*k0+2] << endl;
  // }

  // cout << "Here are the edges :" << endl;

  // for (int k2 = 0; k2 < m_NbEdgesOnBorder; ++k2) {
  //   cout << "e" << k2 << " : " << m_EdgesOnBorder[3*k2] << " " << m_EdgesOnBorder[3*k2+1] << " " << m_EdgesOnBorder[3*k2+2] << endl;
  // }

  // cout << "Here are the triangles :" << endl;
  
  // for (int k2 = 0; k2 < m_NbTriangle; ++k2) {
  //   cout << "e" << k2 << " : " << m_Triangle[3*k2] << " " << m_Triangle[3*k2+1] << " " << m_Triangle[3*k2+2] << endl;
  // }



  // deallocate
  free(s2s1);
  free(s3s1);
  
}

mesh::~mesh(){

  // cout << "~mesh() called !" << endl;

  // delete[] corners;
  // delete[] border_edges;
  
  delete[] m_Nodes;
  delete[] m_Elements;


}

int mesh::NbCorners() const {return m_NbCorners;}
int mesh::NbEdgesOnBorder() const {return m_NbEdgesOnBorder;}
int mesh::NbNodes() const {return m_NbNodes;}
int mesh::NbElements() const {return m_NbElements;}
int mesh::NbTriangle() const {return m_NbTriangle;}
int* mesh::EdgesOnBorder() const {return m_EdgesOnBorder;}
float* mesh::Nodes() const {return m_Nodes;}
int* mesh::Elements() const {return m_Elements;}
int* mesh::Triangle() const {return m_Triangle;}

// Functions that computes the area of an element given its Nodes indexes
float ComputeAreaElement(const float* vec1, const float* vec2){

  float out;

  out = vec1[0]*vec2[1]-vec1[1]*vec2[0];

  if (out < 0) {
    return -out/2;
  }
  else {
    return out/2;
  }  

}
