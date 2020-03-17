//Dhruva Sogal Binary Tree Project Started 3/5/2020
#include<iostream>
#include<fstream>
using namespace std;
struct node{
  node* left;
  node* right;
  int value;

};
void insert(int a , node* current, node* &root);
void read(node* &root);
void print(node* current, int space);
void search(int key, node* current);
void deleteLeaf(int key, node* &current, node* &root);
node* findInorderSuccesor(node* c);
void deleteInorderSuccesor(node* c);
int main(){
  
  cout<<"This Program Creates a Binary Search Tree"<<endl;
  node* root = new node;
  //root->right = NULL;
  //root->left = NULL;
  root = NULL;        //0 used if node is empty as input must me 1 to 1000
  read(root);
  print(root, 0);
  search(4, root);
  deleteLeaf(4, root, root);
  print(root, 0);
  //cout<<"root"<<endl;



}
void read(node* &root){
  cout<<"Enter 1 for console entry or 2 for file input"<<endl;
  int entry = 0;
  //cin.ignore();
  cin>>entry;
  if(entry == 1){
    char* input = new char[100];
    cout<<"Enter up to 100 numbers seperated by spaces"<<endl;
    cin.ignore();
    cin.get(input, 100);
    ofstream file;
    file.open("treefile");
    file<<input;
    file.close();
    ifstream infile;
    infile.open("treefile");
    int a;
    while(infile >> a){
      //cout<<a<<endl;
      insert(a, root, root);   
    }

  }

  if(entry == 2){
    cout<<"Enter file name"<<endl;
    char* filename = new char[100];
    cin.ignore();
    cin.get(filename, 100);
    ifstream infile;
    infile.open(filename);
    int a;
    while(infile >> a){
      //sort into tree
      //call a method and recursively find spot
    }
  }
}//end read method
void insert(int a , node* current, node* &root){
  //cout<<a<<endl;
  if(root == NULL){ //if first node in tree
    cout<<"new root: "<<a<<endl;
    node* temp = new node;
    temp->value = a;
    root = temp;
    
  }
  else{
    if(a < current->value){
      if(current->left == NULL){
      node* temp = new node;
      temp->value = a;
      current->left = temp;
      }
      else{
	insert(a, current->left, root);
      }

    }
    else if(a > current->value){ //a is more than or equal to
      if(current->right == NULL){
      node* temp = new node;
      temp->value = a;
      current->right = temp;
      }
      else{
	insert(a, current->right, root);
      }



    }







  }
  
}


void print(node* current, int space){ //this method is taken from "Geeks for Geeks" https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
  if(current == NULL){
    return;
  }

  space += 10;
  
  print(current->right, space);
  cout<<endl;
  for (int i = 10; i < space; i++){  
    cout<<" ";
  }
    cout<<current->value<<"\n";  
    print(current->left, space); 


}
void search(int key, node* current){
  if(current == NULL){
    cout<<"No such element exists in the tree"<<endl;
    return;
  }
  if(key == current->value){
    cout<<"The searched number exists in the tree"<<endl;
  }
  else{
    if(key > current->value){
      search(key, current->right);
    }
    if(key < current->value){
      search(key, current->left);
    }
  }
  


  
}
void deleteLeaf(int key, node* &current, node* &root){
  

  //node is leaf

  //search to establish if in tree
  if(current == NULL){
    cout<<"No such element exists in the tree"<<endl;
    return;
  }
  
  if(key == current->value){
   if(current == root){
     if(current->left == NULL && current->right == NULL){
       current = NULL;

     }
     else if(current->left == NULL && current->right != NULL){
       root->value = current->right->value;
       current->right = NULL;
     }
     else if(current->right == NULL && current->left != NULL){
       root->value = current->left->value;
       current->left = NULL;
     }
     else if(current->right != NULL && current->left != NULL){
       root->value = findInorderSuccesor(root)->value;
       deleteInorderSuccesor(root);
       
     }



   }
    else{
    //located node
    if(current->right == NULL && current->left == NULL){ //if leafe delete
      //cout<<"leaf"<<endl;
      //delete (current);
      current = NULL;
    }
    else if(current->right == NULL && current->left != NULL){ //only has left child
      current->value = current->left->value;
      current->left = NULL;
    }
    else if(current->left == NULL && current->right != NULL){ //only has right child
      current->value = current->right->value;
      current->right = NULL;

    }
    else if(current->right != NULL && current->left != NULL){
    //if has two children find inorder succesor, copy value, delete successor
      
      
      
    
    }






    }



  }
  else{
    //cout<<findInorderSuccesor(current)->value<<endl;
    if(key > current->value){
      deleteLeaf(key, current->right, root);
    }
    if(key < current->value){
      deleteLeaf(key, current->left, root);
    }
  }

}

node* findInorderSuccesor(node* c){
  if(c->right == NULL){
    return c;
  }
  findInorderSuccesor(c->right);
  
}
void deleteInorderSuccesor(node* c){
  if(c->right == NULL){
    c = NULL;
    return;
  }
  deleteInorderSuccesor(c->right);

}


