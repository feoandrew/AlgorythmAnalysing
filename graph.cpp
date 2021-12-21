#include "graph.h"
#include <set>
#include <vector>
#include<fstream>



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

std::vector<Edge> Graph::getOkrOf(int id) { 
  std::vector<Edge> res;
  for (auto &&data : tree) {
    if (data.begin == id || data.end == id) res.push_back(data);
  }
  return res;
}

Edge Graph::getEdgeById(int id) {
  iter = tree.begin();
  for (int i=0; i<id; i++) {
    iter++;
  }
  return *iter;
}


