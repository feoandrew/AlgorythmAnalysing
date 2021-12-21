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
  okr** ADJ;//������ ������� ���������
  int* VT;//(VT[i]=1, ���� ������� y ������ � ����������� �������� ������������ ������)
  int* a; //(a[i] - ��� ������������ �� ���� �����, ������������ ������� x � ����������� ���������� ������������ ������) 
  int* b;//(b[i] - ��� ������ ������� ����� �����)
  int INF = INT_MAX;
  int* ET;

};

