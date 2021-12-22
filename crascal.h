#pragma once
#include<iostream>
#include"graph.h"
#include<vector>
#include<list>
#include"parts.h"
class Crascal {
 public:
  Crascal();
  ~Crascal();
  int* Process(Graph& G);
  std::list<int>& getPartByID(int id) ;
 private:
   
  std::list<Part*> parts;
  std::list<Part*>::iterator iter;
  void unite(int first, int second);
  int* ET;
 
};






