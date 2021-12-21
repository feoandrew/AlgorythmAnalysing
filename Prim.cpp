#include"Prim.h"
#include"graph.h"
#include<algorithm>
#include<vector>



int* Prim::Process(Graph& G) {
  VT = new int[G.getN()];
  a = new int[G.getN()];
  b = new int[G.getN()];
  ET = new int[G.getM()*2];
  

  
    
    int first = 0;
    int mt;
    for (int i = 0; i < G.getN(); i++) {
      a[i] = INF;
      VT[i] = 0;
    }
    VT[first] = 1;

    //a = new int[G.getN()];    
    
      for (int j = 0; j <G.getN()-1; j++) {
       
        Edge candidat;
        candidat.weight=INF;
        bool conn = false;
        for (int i = 0; i < G.getN(); i++) {
          if (VT[i] == 1) {
            std::vector<Edge> okr = G.getOkrOf(i);

           
            
            for (auto&& data : okr) {
              int tail;
              if (data.begin==i || data.end==i)
              {
                
                if (data.begin==i) {
                  tail = data.end;
                } else {
                  tail = data.begin;
                }
                if (VT[tail] == 1)
                {
                  if (data.weight < a[tail] && b[i] != tail) {
                    a[tail] = data.weight;
                    b[tail] = i;
                  }
                } 
                else {
                  conn = true;
                  if (data.weight < candidat.weight) {
                   
                    candidat.weight=data.weight;
                    if (data.begin == i) {
                      candidat.begin = data.begin;
                      candidat.end = data.end;
                    } else {
                      candidat.begin = data.end;
                      candidat.end = data.begin;
                    }
                    
                  }
                }
                
              }
            }
          }
        }
        if (!conn) {
          std::cout << "Ошибка: граф не связен";
          exit(1);
        }
        VT[candidat.end] = 1;
        a[candidat.end] = candidat.weight;
        b[candidat.end] = candidat.begin;
        

        

        
        
        
      }
    
    int offset = 0;
    for (int i = 0; i < G.getN(); i++) {
      if (i==first) {
        continue;
        offset = 1;
      }
      ET[((i-offset)*2)-2] = i;
      ET[((i-offset) * 2) - 1] = b[i];
    
    }

   
    
   
   


    
    

  

  return ET; }

int Prim::argmin(int* a, int vt, int n) {
  int val = a[0];
  int min = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] < val && VT[i] == vt) {
      val = a[i];
      min = i;
    }
  }
  return min;
}
Prim::Prim() {}

Prim::~Prim() {}
