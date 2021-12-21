#include"graph.h"
#include"crascal.h"


int* Crascal::Process(Graph& G) {
  ET = new int[G.getM() * 2];
  std::vector<int> part = {G.getEdgeById(0).begin, G.getEdgeById(0).end};
  Edge candidat;
  ET[0] = part[0];
  ET[1] = part[1];
  parts.push_back(part);
  int outiter = 2;
  for (int i = 1; i < G.getM(); i++) {
    candidat = G.getEdgeById(i);
   
    int begpart = -1;
    int endpart = -1;
    int partnum = 0;
    for (auto&& data : parts) {
      bool begin =
          std::find(data.begin(), data.end(), candidat.begin) != data.end();
      bool end =
          std::find(data.begin(), data.end(), candidat.end) != data.end();
      
      if (begin && end) {
        int begpart = -2;
        int endpart = -2;
       break;
      }
      if (begin) {
        begpart = partnum;
      }
      if (end) {
        endpart = partnum;
      }
      partnum++;

      

    
      
      
    }
    if (begpart >=-1 || endpart >=-1) {
      if (begpart >= 0 && endpart >= 0) {
        unite(begpart, endpart);
        ET[outiter] = candidat.begin;
        ET[outiter + 1] = candidat.end;
        outiter+=2;
        continue;
      }
      if (begpart >= 0) {
        parts[begpart].push_back(candidat.end);
        ET[outiter] = candidat.begin;
        ET[outiter + 1] = candidat.end;
        outiter+=2;
        continue;
      }
      if (endpart >= 0) {
        parts[endpart].push_back(candidat.begin);
        ET[outiter] = candidat.begin;
        ET[outiter + 1] = candidat.end;
        outiter+=2;
        continue;
      }
      }
    std::vector<int> newpart = {candidat.begin, candidat.end};

    parts.push_back(newpart);
    ET[outiter] = candidat.begin;
    ET[outiter + 1] = candidat.end;
    outiter+=2;
      
    
  }
  return ET;
}
void Crascal::unite(int first, int second) {
  int donor;
  int acceptor;
  if (parts[first].size() > parts[second].size()) {
    donor = second;
    acceptor = first;
  } else {
    donor = first;
    acceptor = second;
  }

  
  for (int i = 0; i < parts[donor].size(); i++) {
    parts[acceptor].push_back( parts[donor][i]);
  }
  parts[donor].clear();

}
Crascal::Crascal() {}

Crascal::~Crascal() {}
