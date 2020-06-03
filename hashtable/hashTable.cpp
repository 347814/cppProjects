#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <string.h>
using namespace std;
struct student{
  char* firstName;
  char* lastName;
  float gpa;
  int id;
  student* next;


};
void chainPrint(student* current);
void chaining(student* k, student* current, int count, student** students, int indecies);
void addStudent(student* k, int &indecies, student** students);
void randomStudent(student** students, int indecies, int &namecount, int &lastnamecount);
void chaining(student* k, student* current, int count, student** students, int indecies);
void rehash(int indecies, student* k, student** students);
void print(student** students, int indecies);
void deleteStudent(student** students, int indecies);
void chainDelete(student* head, student* current, char* searchFirstName, char* searchLastName, int predictedIndex);
int main(){
  int namecount = 0; //tracks the number of randomly generated names. Knows how many spaces to pass over
  int lastnamecount = 0;
  int indecies = 100;
  student** students =  new student* [100];
  srand(time(NULL));
  /*  for(int i = 0; i < 20 ; i++){
  randomStudent(students, indecies, namecount, lastnamecount);
  }
  print(students, indecies);
  */
  
  while(true){
  cout<<"Type a for add, d for delte, p for print, r for random"<<endl;
  char com;
  cin>>com;
  
  
  if(com == 'a'){
    student* s = new student;
    cout<<"Enter the student name"<<endl;
    char* name = new char[100];
    cin.ignore();
    cin.get(name, 99);
    s->firstName = name;
    cout<<"Enter the student last name"<<endl;
    char* last = new char[100];
    cin.ignore();
    cin.get(last, 99);
    s->lastName = last;
    cout<<"Enter the student GPA"<<endl;
    float studentGPA;
    cin.ignore();
    cin>>studentGPA;
    s->gpa = studentGPA;
    cout<<"Enter the student ID"<<endl;
    int x;
    cin.ignore();
    cin>>x;
    s->id = x;
    s->next = NULL;
    addStudent(s, indecies, students);
    


  }

  
  if(com == 'd'){
    deleteStudent(students, indecies);

  }
  if(com == 'p'){
    print(students, indecies);
  }
  if(com == 'q'){
    break;
  }
  if(com == 'r'){
    cout<<"How many random students"<<endl;
    int h;
    cin>>h;
  for(int i = 0; i < h ; i++){
  randomStudent(students, indecies, namecount, lastnamecount);
  } 

  }
  }
}







void addStudent(student* k, int &indecies, student** students){
  int sum;
  sum = (k->firstName[0] * k->lastName[0]) % indecies;
  while( sum > indecies){
    sum = sum / 2 ;
  }
  if(students[sum] == NULL){
    students[sum] = k;

  }
  else{
    chaining(k, students[sum], 0, students, indecies); //call the chaining function

  }


}

void randomStudent(student** students, int indecies, int &namecount, int &lastnamecount){
  student* random = new student;
  ifstream infile;
  infile.open("firstnames.txt.txt");
  ifstream count;
  
  //this loop determines the number of names in the file for bounds for a random number
  count.open("firstnames.txt.txt");
  char c;
  int names = 0;
  
  while(count >> noskipws >> c){
    if(c == ' '){
      names++;
    }

  }
  // cout<<names<<endl;
  count.close();





  //  cout<<names<<endl;

  namecount = rand() % names; //get a random number for the namecount
  
  char a;
  int spacecount = 0; //create a random number between 0 and the counted number of names
  int j = 0;
  char* readName = new char[100];
  while(infile >> noskipws >> a){
    if(a != ' '){
      if(spacecount == namecount){
	readName[j] = a;
	j++;
      }
      
      else if(spacecount < namecount){
	//do nothing?
      }
      

    }
    else{     // a = ' '
      spacecount ++;
      if(spacecount > namecount){
	//namecount++;
	readName[j] = '\0';
	break;
      }
      

    }


    


  }

  //readName[sizeof(readName) / sizeof(readName[0])] = '\0';
  //cout<<sizeof(readName) / sizeof(readName[0])<<endl;
  

  random->firstName = readName;
  
  //cout<<random->firstName<<" ";

  //now do the same for last name

  
  char x;
  ifstream lastcount;
  int lastnames = 0;
  lastcount.open("lastnames.txt.txt");
  while(lastcount >> noskipws >> x){
    if(x == ' '){
      lastnames++;
    }

  }
  











  
  char b;
  spacecount = 0;
  lastnamecount = rand() % lastnames;
  j = 0;
  ifstream lastNameFile;
  char* readLastName = new char[100];
  lastNameFile.open("lastnames.txt.txt");
  while(lastNameFile >> noskipws >> a){
    if(a != ' '){
      if(spacecount == lastnamecount){
	readLastName[j] = a;
	j++;
      }
      
      else if(spacecount < lastnamecount){
	//do nothing?
      }
      

    }
    else{     // a = ' '
      spacecount ++;
      if(spacecount > lastnamecount){
	//lastnamecount++;
	readLastName[j] = '\0';
	break;
      }
      

    }


    


  }

  readLastName[sizeof(readLastName) / sizeof(readLastName[0])] = '\0';

  random->lastName = readLastName;


  
  //cout<<random->lastName<<endl;;  





  //now iterate the student id

  int maxid = 0;
  for(int i = 0; i < indecies; i ++){
    if(students[i] != NULL){
      if(students[i]->id > maxid){
	maxid = students[i]->id;
      }
      

  }






  }

  random->id = maxid + 1;
  //cout<<random->id<<endl;

  //create a random GPA
  
  double u;
  u = (double)rand() / (RAND_MAX ) * (5);
  // cout<<u<<endl;
  random->gpa = u;
  //cout<<random->gpa<<endl;
  random->next = NULL;
  addStudent(random, indecies, students);

  
  

}



void chaining(student* k, student* current, int count, student** students, int indecies){
  if(current->next == NULL){
    current->next = k;
  }
  else{
    count++;
    if(count < 3){
      chaining(k, current->next, count, students, indecies);
    }
    else{
      rehash(indecies, k, students);

    }

  }

}

void rehash(int indecies, student* k, student** students){
  student** temp = new student*[indecies];
  temp = students;
  indecies = indecies * 2; //double the number of indecies
  int elements = sizeof(students) / sizeof(students[0]);
  for(int i = 0; i < elements; i++){
    students[i] = temp[i];

  }
  students = new student* [indecies*2];
  //use hashing algorithm to re hash everything
  for(int i = 0; i < elements; i++){
   
      
  }




}

void print(student** students, int indecies){
  for(int i = 0 ; i < indecies; i++){
    if(students[i] != NULL){
      if(students[i]->next == NULL){
      cout<<students[i]->firstName<<" "<<students[i]->lastName<<", "<<students[i]->id<<", "<<students[i]->gpa<<endl;
      }
    else{
      //call a recursive function to keep printing linked list
      chainPrint(students[i]);
    }
    }

  }

}

void chainPrint(student* current){
  cout<<current->firstName<<" "<<current->lastName<<", "<<current->id<<", "<<current->gpa<<" chain"<<endl;
 if(current->next != NULL){
   chainPrint(current->next);
 }
}
void deleteStudent(student** students, int indecies){
  cout<<"Enter the First name of the student you wish to delete"<<endl;

  char* searchFirstName = new char[100];
  cin.ignore();
  cin.get(searchFirstName, 100);

  cout<<"Enter the Last name of the student you wish to delete"<<endl;

  char* searchLastName = new char[100];
  cin.ignore();
  cin.get(searchLastName, 100);

  int predictedIndex;
  predictedIndex = (searchFirstName[0] * searchLastName[0]) % indecies; //use the hashing algorithm to find the index
  while(predictedIndex > indecies){
    predictedIndex = predictedIndex / 2;
  }
  

  if(strcmp(students[predictedIndex]->firstName, searchFirstName) == 0 && strcmp(students[predictedIndex]->lastName, searchLastName) == 0){

    if(students[predictedIndex]->next == NULL){
      students[predictedIndex]->firstName = NULL;
      students[predictedIndex]->lastName = NULL;
      delete students[predictedIndex];
    }
    else{
      students[predictedIndex]->next = students[predictedIndex];   //set the next thing to be in the array no chained
    }
    

  }
  else{
    chainDelete(students[predictedIndex], students[predictedIndex], searchFirstName, searchLastName, predictedIndex);


  }



}

void chainDelete(student* head, student* current, char* searchFirstName, char* searchLastName, int predictedIndex){
  if(current->next == NULL && strcmp(current->firstName, searchFirstName) != 0){
    cout<<"No such student exists"<<endl;
  }
  
 //end of chain must be deleted
  
  else if(current->next != NULL && strcmp(current->next->firstName, searchFirstName) == 0 && strcmp(current->next->lastName, searchLastName) == 0 && current->next->next == NULL){
   delete current->next;


  }
  //something in the middle must be deleted
  else if(current->next != NULL && strcmp(current->next->firstName, searchFirstName) == 0 && strcmp(current->next->lastName, searchLastName) == 0 && current->next != NULL){
    student* k = current->next;
    current->next = current->next->next;
    delete k;

  }
  else{
    if(current->next != NULL){
      chainDelete(head, current->next, searchFirstName, searchLastName, predictedIndex);
    }

  }

}



  
  

