#include <iostream>
#include<ctime>
#include"graph.h"
#include"Prim.h"
#include"crascal.h"
#include "fstream"

using namespace std;
int main(){
  setlocale(LC_ALL, "rus");
  int n=10;
  int m=15;
  int* out;

  
  ifstream infile("Graph.txt");
 // infile >> n;
 // infile >> m;
  for (int n = 100; n <= 10000; n = n + 100) {
    // cout << "Введите кол-во вершин: ";

    // cout << "Введите кол-во ребер: ";
   m = n * n;
    Graph G(n, m);
   //  G.InputGraph(n, m, infile);
    G.generateFullGraph(n, 1, 10000000);
    cout << "count: " << n << endl;
    Prim prim;
    
    
    
//     for (int i = 0; i < (n - 1) * 2; i++) cout << out[i];
    
    Crascal crascal;
  
    out = crascal.Process(G);


    out = prim.Process(G);
   // 
  //   for (int i = 0; i<(n-1)*2; i++)
  //   cout << out[i];
   
  }
}


