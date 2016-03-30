
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Node{//using nodes for graph representation
int number=-1;
int color=-1;
vector <Node*> *links = new vector<Node*>;//addresses of all vertices that this vertice is linked to

};
//defining functions and global variables
void input(char* infileName);// Reads input and updates vertices and links
vector <Node*> sortbyValence(vector <Node*> *arr);//Sorts the vector with quicksort according to their adjacency list size;
int N;//Number of vertices
vector<Node*> vertices;//Vector of addresses of all vertices

int main(int argc, char *argv[]){
if(argc!=3){
		printf("Usage: ./four_color infile outfile\n");
		return 0;
	}
input(argv[1]);
//beginning of Welsh-Powell algorithm
vector<Node*> vertices_sorted= sortbyValence(&vertices);
for(int color=1;color<5;color++){

for(int i=0;i<N;i++){

if(vertices_sorted[i]->color==-1){
for(size_t j=0;j<static_cast<size_t>(N);j++){
if(j<vertices_sorted[i]->links->size()){
if(vertices_sorted[i]->links->at(j)->color==color){goto skip;//if one of the links has the same color, dont color
}
}

}

vertices_sorted[i]->color=color;
skip:;
}
}
}
//end of Welsh-Powell algorithm, beginning of output process
ofstream myfile;//start file stream
myfile.open (argv[2]);

for(int i=0;i<N;i++){
if(vertices[i]->color==-1){
myfile  << "Graph cannot be four colored";
goto over;
}
}

for(int i=0;i<N;i++){
if(vertices[i]->color==1){
myfile  << "red" << endl;
}else if(vertices[i]->color==2){
myfile  << "blue" << endl;
}else if(vertices[i]->color==3){
myfile  << "green" << endl;
}else if(vertices[i]->color==4){
myfile  << "orange" << endl;
}
}


over:
myfile.close();

return 0;
}


void input(char* infileName){
 ifstream myfile(infileName);//start file stream
	 string line;
	 getline(myfile, line);
	 stringstream data(line);

	 int K;
data >> N;
for(int i=0; i<N; i++){
Node* x=new Node;
x->number=i;
vertices.push_back(x);
//;
}


for(int i=0; i<N; i++){
	getline(myfile, line);
	 stringstream data(line);

for(int j=0; j<N; j++){
data >> K;
if(K){
vertices[i]->links->push_back(vertices[j]);
}


}

}}


vector <Node*> sortbyValence(vector<Node*> *arr){


vector <Node*> ls;
vector <Node*> eq;
vector <Node*> gr;
if(arr->size()<=1){
return *arr;
}
size_t pivot=arr->at(0)->links->size();
for(size_t i = 0;  i<arr->size(); i++){
if(arr->at(i)->links->size()>pivot){
ls.push_back(arr->at(i));
}
if(arr->at(i)->links->size()==pivot){
eq.push_back(arr->at(i));
}

if(arr->at(i)->links->size()<pivot){
gr.push_back(arr->at(i));
}}

vector<Node*> lsf= sortbyValence(&ls);
vector<Node*> grf=sortbyValence(&gr);
lsf.insert( lsf.end(), eq.begin(), eq.end() );
lsf.insert(lsf.end(), grf.begin(),grf.end());
return lsf;
}
