#include<iostream>
using namespace std;
class student{
  string name;
  int age;
  double degree;

  public:
   void input(){
    cout<<"Enter your name :"<<endl;
    cin>>name;
    cout<<"Enter your age"<<endl;
    cin>>age;
   }
  
   void output(){
    if(age<=20){
      degree = 1;
    }
    else if(age>30){
      degree = 0;
    }
    else{
      degree = (double)(30 - age)/10;
      
    }
    cout<<"The degree of membership is : "<<degree<<endl;
   }
};

int main(){
  student s[5];
  int i=0;
  for(i=0;i<5;++i){
    s[i].input();
    s[i].output();
  }
  return 0;
}