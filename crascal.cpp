#include"graph.h"
#include"crascal.h"



int* Crascal::Process(Graph& G) {
  unsigned int start_time;
  unsigned int end_time;
  unsigned int search_time;
  ET = new int[G.getM() * 2];
  start_time = clock();
  
  
 
  Edge candidat;
  
  for (int i=0; i<G.getN(); i++) {
    Part* newpart = new Part();
    newpart->push_back(i);

    parts.push_back(newpart);
  }

  
  int outiter = 2;
  for (int i = 0; i < G.getM(); i++) {
    candidat = G.getNextEdge();
   
    Part* begpart = nullptr;
    Part* endpart = nullptr;
    bool correct = true;
    for (auto&& data : parts) {
      bool begin = data->find(candidat.begin);
      bool end = data->find(candidat.end);
          
      
      if (begin && end) {
        correct = false; 
       break;
      }
      if (begin) {
        begpart = data;
      }
      if (end) {
        endpart = data;
      }
      if (begpart !=nullptr && endpart!=nullptr) {
        break;
      }
     

      

    
      
      
    }
    if (correct) {
      if (begpart != nullptr && endpart!= nullptr) {
        begpart->unite(endpart);
        parts.remove(endpart);
         
        ET[outiter] = candidat.begin;
        ET[outiter + 1] = candidat.end;
        outiter+=2;
        continue;
      }
      if (begpart != nullptr) {
        begpart->push_back(candidat.end);
        ET[outiter] = candidat.begin;
        ET[outiter + 1] = candidat.end;
        outiter+=2;
        continue;
      }
      if (endpart != nullptr) {
        endpart->push_back(candidat.begin);
        ET[outiter] = candidat.begin;
        ET[outiter + 1] = candidat.end;
        outiter+=2;
        continue;
      }
      }
      
    
      
    
  }
  end_time = clock();
  search_time = end_time - start_time;
  std::cout << std::endl << "CrascalTime: " << search_time << std::endl;
  return ET;
}



Crascal::Crascal() {}

Crascal::~Crascal() {}
