#pragma once
#include <iostream>
#include "graph.h"

struct okr {
  int name;
  int w;
  okr* next;
};

class Prim {
 public:
  Prim();
  
  ~Prim();
  // CreateADJ(Graph& G); 
  int* Process(Graph& G);
 
 private:
  int argmin(int* a, int vt, int n);
  okr** ADJ;//Массив списков смежности
  int* VT;//(VT[i]=1, если вершина y входит в построенный фрагмент минимального остова)
  int* a; //(a[i] - вес минимального по весу ребра, соединяющего вершину x с построенным фрагментом минимального остова) 
  int* b;//(b[i] - имя второй вершины этого ребра)
  int INF = INT_MAX;
  int* ET;

};

