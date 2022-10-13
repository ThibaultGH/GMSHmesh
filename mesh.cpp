// Some includes from the Standard C++ library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Other includes
#include "mesh.hpp"
#include "FileManagerCPP/FileManagerCPP.hpp"
using namespace std;

mesh::mesh(char* filename){

  // Construct a flux to read the mesh file in :
  ifstream my_file(filename);
  
  // Some local variables :
  string line_my_file;
  // string char_line;
  
  // string temp_str;
  // int line_size;
  char space = ' ';
  // int* save_spaces_pos;
  bool found_nb_nodes = false;
  bool found_nb_elements = false;
  vector<string> splitted_line;

  // save_spaces_pos = (int *) malloc(sizeof(int)*50);

  // Start reading the mesh file
  if (my_file.is_open()) {
    // my_file >> nb_nodes;

    while (getline(my_file,line_my_file)) {

      /*This while loop works this way :
	     _ if a line "$Nodes" or "$Elements" is found, the next line gets us the number of nodes and elements respectively.
	     _ Once we got them, we will read the lines of the file exactly this number of times.
	     _ For the nodes : 
	           _ The first number we encounter is the number of the nodes that we discard, the next three are the coordinates that we but into an array nodes[nb_nodes*3].
	       For the elements :
	           _ The three integer number we get are the number of the nodes forming a triangle, starting from 1 we need to do -1 to respect indexation in C++ starting at 0.*/
      
      if (found_nb_nodes) {
	
	nb_nodes = stoi(line_my_file);
	found_nb_nodes = false;

	nodes = (float* ) malloc(sizeof(float)*nb_nodes*3);

	for (int i0 = 0; i0 < nb_nodes; ++i0) {

	  getline(my_file,line_my_file);

	  splitted_line = split(line_my_file,space); // splitted_line = {"node_number","node_1st_coor","node_2nd_coor","node_3rd_coor"}

	  // cout << "We are writting node " << splitted_line[0] << " with coordinate : ";

	  for (int i1 = 0; i1 < splitted_line.size()-1; ++i1) {
	    nodes[(stoi(splitted_line[0])-1)*3+i1] = stof(splitted_line[i1+1]);
	    // cout << splitted_line[i1+1] << " ";

	  }

	  // cout << endl;



	}
      }
      else if (found_nb_elements) { // We will enter once here after we've crossed the expression "$Elements" and load all the elements in the array elements.
	nb_elements = stoi(line_my_file);
	found_nb_elements = false;

	elements = (int* ) malloc(sizeof(int)*nb_elements*3);

	for (int i2 = 0; i2 < nb_elements; ++i2) {
	  getline(my_file,line_my_file);

	  splitted_line = split(line_my_file,space);

	  for (int i3 = 0; i3 < splitted_line.size(); ++i3) {
	    cout << splitted_line[i3] << " ";
	  }
	  cout << endl;

	}


      }

      if (line_my_file == "$Nodes") {
	found_nb_nodes = true;
      }
      else if (line_my_file == "$Elements"){
	found_nb_elements = true;
      }

      

      
    } 
  }
  else {
    cout << "ERROR : file " << filename << " NOT open !" << endl;
  }

  // deallocate

  
}

mesh::~mesh(){

  // cout << "~mesh() called !" << endl;

  // delete[] corners;
  // delete[] border_edges;
  
  delete[] nodes;
  delete[] elements;


}
