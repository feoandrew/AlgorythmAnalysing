#pragma once
#include<iostream>
#include <set>
#include <vector>
#include<fstream>
struct Edge {
  int begin;
  int end;
  int weight;
};

struct custom_compare final {
  bool operator()(const Edge& left, const Edge& right) const {
    int nLeft = left.weight;
    int nRight = right.weight;
    return nLeft < nRight;
  }
};

class Graph {
 public:
 
  Graph(int n, int m);
  ~Graph();
  int W(int u, int v);
  void InputGraph(int n,int m, std::ifstream & file);
  void generateFullGraph(int n, int q, int r);
  void generateOkrsList();

  int getN();
  int getM();
  std::vector<Edge>* getOkrOf(int id);
  Edge getNextEdge();
  void show();
  

 private:
  int n;//����� ������
  int m;//����� �����
  int* V;//��������� ������
  std::vector<std::vector<Edge>> Okrs;
  std::multiset<Edge, custom_compare> tree;
  std::multiset<Edge>::iterator iter;
  int iter_position;
  int* weiths;//���� �����
  
  



};


