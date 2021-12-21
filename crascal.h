#pragma once
#include<iostream>
#include"graph.h"
#include<vector>
class Crascal {
 public:
  Crascal();
  ~Crascal();
  int* Process(Graph& G);
 private:
  std::vector<std::vector<int>> parts;
  void unite(int first, int second);
  int* ET;
 
};


