#include<iostream>
#include<fstream>
#include <stdlib.h> 
using namespace std;
struct student{
  char* firstName;
  char* lastName;
  float gpa;
  int id;
  student* next;


};

void chaining(student* k, student* current, int count);
void addStudent(student* k, int &indecies, student** students);
void randomStudent(student** students, int indecies, int &namecount, int &lastnamecount);

int main(){
  int namecount = 0; //tracks the number of randomly generated names. Knows how many spaces to pass over
  int lastnamecount = 0;
  int indecies = 100;
  student** students =  new student* [100];

  for(int i = 0; i < 2 ; i++){
  randomStudent(students, indecies, namecount, lastnamecount);
  }
  
  
  
  /*cout<<"Type a for add, d for delte, p for print"<<endl;
  char com;
  cin>>com;
  
  
  if(com == 'a'){
    student* s = new student;
    cout<<"Enter the student name";
    char* name = new char[100];
    cin.ignore();
    cin.get(name, 99);
    s->firstName = name;
    cout<<"Enter the student last name"<<endl;
    cin.get(name, 99);
    s->lastName = name;
    cout<<"Enter the student GPA"<<endl;
    float studentGPA;
    cin>>studentGPA;
    s->gpa = studentGPA;
    cout<<"Enter the student ID"<<endl;
    int x;
    cin>>x;
    s->id = x;
    addStudent(s, indecies, students);
    


  }

  */

}







void addStudent(student* k, int &indecies, student** students){
  int sum;
  sum = (k->firstName[0] * k->lastName[0]) % indecies;
  while( sum > indecies){
    sum = sum / 2 ;
  }
  if(students[sum] != NULL){
    students[sum] = k;

  }
  else{


  }


}

void randomStudent(student** students, int indecies, int &namecount, int &lastnamecount){
  student* random = new student;
  ifstream infile;
  infile.open("firstnames.txt.txt");
  char a;
  int spacecount = 0;
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
	namecount++;
	break;
      }
      

    }


    


  }

  readName[sizeof(readName) / sizeof(readName[0])] = '\0';
  cout<<sizeof(readName) / sizeof(readName[0])<<endl;
  

  random->firstName = readName;
  
  cout<<random->firstName<<endl;

  //now do the same for last name
  char b;
  spacecount = 0;
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
	lastnamecount++;
	break;
      }
      

    }


    


  }

  readLastName[sizeof(readLastName) / sizeof(readLastName[0])] = '\0';

  random->lastName = readLastName;


  
  cout<<random->lastName<<endl;;  

  

}























void chaining(student* k, student* current, int count){
  if(current->next == NULL){
    current->next = k;
  }
  else{
    count++;
    if(count < 3){
      chaining(k, current->next, count);
    }
    else{
      //void rehash

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
  




}
