#include"Prim.h"
#include"graph.h"
#include<algorithm>
#include<vector>



int* Prim::Process(Graph& G) {
  VT = new int[G.getN()];
  a = new int[G.getN()];
  b = new int[G.getN()];
  ET = new int[G.getM()*2];
 
  std::vector<int> blue;
  unsigned int start_time;
  unsigned int end_time;
  unsigned int search_time;

  start_time = clock();
  G.generateOkrsList();
  
    
    int first = 0;
    
    for (int i = 0; i < G.getN(); i++) {
      a[i] = INF;
      VT[i] = 0;
    }
    VT[first] = 1;
   
    std::vector<Edge>* start = G.getOkrOf(first);
    for (auto&& data : *start) {
      if (data.begin == first || data.end == first) {
        if (data.begin == first) {
          a[data.end] = data.weight;
          b[data.end] = first;
        } else {
          a[data.begin] = data.weight;
          b[data.begin] = first;
        }
      }

    }

    
    //a = new int[G.getN()]; 
    
      for (int j = 0; j <G.getN()-1; j++) {
       
        int candidat = argmin(a, 0,G.getN());
        
        
       if (a[candidat]==INF) {
          exit(1);
       }
       int host = b[candidat]; 
       VT[candidat] = 1;

            
          
          std::vector<Edge>* okr = G.getOkrOf(candidat);

           
            
            for (auto&& data : *okr) {
              int tail;
              if (data.begin == candidat || data.end == candidat)
              {
                
                if (data.begin == candidat) {
                  tail = data.end;
                } else {
                  tail = data.begin;
                }
                if (VT[tail] == 0)
                {
                  if (data.weight < a[tail] ) {
                    a[tail] = data.weight;
                    b[tail] = candidat;
                  }
                } 
                
                
              }
            }
          
        
       
        

        

        
        
        
      }
    end_time = clock();
      search_time = end_time - start_time;
      std::cout << std::endl << "PrimTime: " << search_time << std::endl;
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
