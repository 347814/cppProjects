#include<iostream>
#include "node.h"
node::node(char k){
  token = k;

}
char :: node getToken(){
  return token;

}
void :: node setToken(char* k){
  token = k;

}
node* :: node getLeft(){
  return left;
}
node* :: node getRight(){
  return right;

}
node* :: node getNext(){
  return next;

}
void :: node setLeft(node* k){
  left = k;

}
void :: node setRight(node* k){
  right = k;

}
void :: node setNext(node* k){
  next = k;

}
