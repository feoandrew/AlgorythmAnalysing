#include "graph.h"
#include <set>
#include <vector>
#include<fstream>
#include<random>



Graph::Graph(int n, int m ) { 
 

 
 
  this->n = n;
  this->m = m;
  V = new int[n];
}

Graph::~Graph() {}

void Graph::InputGraph(int n, int m, std::ifstream& file) { 
  for (int i = 0; i < n; i++) {
    V[i] = i;

  }
  for (int i = 0; i < m*2; i=i+2) {
    
    int first;
    file >> first;
    if (std::find(V, V + n, first) == V + n) {
      i = i - 2;
      std::cout << "Ошибка: вершины не сущевствует" << std::endl;
      continue;
    }
   
      
      int second;
    file >> second;
      if (std::find(V, V+n, second) == V+n) {
        i = i - 2;
        std::cout << "Ошибка: вершины не сущевствует" << std::endl;
        continue;
      }
      Edge edge;
      edge.begin = first;
      edge.end = second; 
      
       
      file >> edge.weight;

      tree.insert(edge);

      
  }
  iter = tree.begin();
  
}

int Graph::getN() { return n; }

int Graph::getM() { return m; }



void Graph::show() {
  for (auto &&data : tree) std::cout << data.weight << std::endl;
}


std::vector<Edge>* Graph::getOkrOf(int id) { 
  
  return &Okrs[id];
}

Edge Graph::getNextEdge() {
  
  Edge res = *iter;
    iter++;
  
  return res;
}
void Graph::generateFullGraph(int n, int q, int r) {
  srand(time(0));
  tree.clear();
  m = 0;
  for (int i = 0; i < n; i++) {
    for (int j=1; j<n-i; j++) {
      Edge edge;
      edge.begin = i;
      edge.end = i+j; 
      edge.weight = q + rand()%r;
      tree.insert(edge);
      m++;
    }
  }
  iter = tree.begin();
}
void Graph::generateOkrsList() {

  for (int i = 0; i < n; i++) {
    std::vector<Edge> okr;
    Okrs.push_back(okr);
  }
    for (auto &&data : tree) {
      Okrs[data.begin].push_back(data);
      Okrs[data.end].push_back(data);
    }
}

