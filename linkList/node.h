#ifndef NODE_H
#define NODE_H
#include<iostream>
#include"student.h"
using namespace std;
class node{
 public: 
  node();
  ~node();
  void setValue(int);
  int getValue();
  void setNext(node*);
 private:
  student* value;
  node* next;
  





};


#endif
