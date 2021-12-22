#include "parts.h"

Part::Part() {}



Part::~Part() {
  while (first != nullptr) {
    PartNode* next = first->next;
    delete first;
    first = next;
  }
}
void Part::push_back(int value) {
  PartNode* val = new PartNode(value);
  if (first == nullptr) {
       first = val;
       tail = val;
       return;
     }
     tail->next = val;
     tail = val;
}
bool Part::find(int val) {
  bool res = false;
    if (first == nullptr) return res;
  PartNode* p = first;
    while (p) {  // p != nullptr
    if (p->value == val) {
        res = true;
        return res;
    }
    
      p = p->next;
    }
    return res;
  
}
void Part::unite(Part* part) {

 
    tail->next = part->first;
    tail = part->tail;
    part->first = nullptr;
    part->tail = nullptr;
  }


PartNode::PartNode() {}

PartNode::PartNode(int val) { value = val; }

PartNode::~PartNode() {}