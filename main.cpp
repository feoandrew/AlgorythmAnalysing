#include <iostream>
#include<ctime>
#include"graph.h"
#include"Prim.h"
#include"crascal.h"
#include "fstream"

using namespace std;
int main(){
  setlocale(LC_ALL, "rus");
  int n=0;
  int m=0;
  int* out;
  unsigned int start_time;
  unsigned int end_time;
  unsigned int search_time;
  
  ifstream infile("Graph.txt");
  //cout << "Введите кол-во вершин: ";
  infile >> n;
  //cout << "Введите кол-во ребер: ";
  infile >> m;
  Graph G(n,m);
  G.InputGraph(n, m, infile);
  
 
   
  

  Prim prim;
  start_time = clock();
  out = prim.Process(G);
  end_time = clock();
  for (int i = 0; i < (n - 1) * 2; i++) cout << out[i];
  search_time = end_time - start_time;

  cout << endl<<"Time: " <<search_time<<endl;
  Crascal crascal;
  start_time = clock();
  out = crascal.Process(G);
  end_time = clock();
  for (int i = 0; i<(n-1)*2; i++)
  cout << out[i];
  search_time = end_time - start_time;
  cout << endl << "Time: " << search_time << endl;
}


