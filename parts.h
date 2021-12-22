#pragma once

class PartNode {
 public:
  PartNode();
  PartNode(int val);
  ~PartNode();
  int value;
  


  PartNode* next;
};
class Part {
 public:
  Part();
  ~Part();

  PartNode* first;
  PartNode* tail;
  Part* next;
  void unite(Part* part);
  void push_back(int value);
  bool find(int val);

};




