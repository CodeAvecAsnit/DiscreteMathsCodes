#include<iostream>
using namespace std;
int main(){
  int a = 0;
  cout<<"enter the size of the first sets"<<endl;
  cin>>a;

  int set1[50],set2[50];

  cout<<"Enter the data of the first set"<<endl;
  for(int i = 0;i<a;++i){
    cin>>set1[i];
  }
    cout<<"Enter the data of the second set"<<endl;
    for(int i = 0;i<a;++i){
    cin>>set2[i];
  }

  int j = 0,intersection[50];
  for(int i = 0;i<a;++i){
    for(int s = 0;s<a;++s){
      if(set1[i]==set2[s]){
        intersection[j]= set1[i];
        ++j;
      }
  }
}
  cout<<"The intersection of the set is "<<endl;

  for(int i=0;i<j;++i){
    cout<<intersection[i]<<endl;
  }
  int temp;
  int nest = a ;
 
 for(int i=0;i<j;++i){
  for (int s=0;s<nest;++s){
    if( intersection[i]==set1[s]){
      temp = set1[nest-1];
      set1[nest-1]=set1[s];
      set1[s]=temp;
      --nest;

    }
  }
temp=0;
 }
 cout<<("The set a-b is :")<<endl;
 for(int i =0 ;i<nest;++i){
  cout<<set1[i]<<endl;
 }

 int unionset[50];
 for(int i=0;i<nest;++i){
  unionset[i]=set1[i];
 }
 for(int i=nest;i<(nest+a);++i){
  unionset[i]=set2[i-nest];
 }
 cout<<"The union of the sets is"<<endl;
  for(int i = 0;i<(nest+a);++i){
    cout<<unionset[i]<<endl;
  }

int k =(a+nest);
 for(int i=0;i<j;++i){
  for (int s=0;s<k;++s){
    if( intersection[i]==unionset[s]){
      temp = unionset[k-1];
      unionset[k-1]=unionset[s];
      unionset[s]=temp;
      --k;
    }
  }
}

cout<<"The symmetric difference is"<<endl;
for(int i=0;i<k;++i){
  cout<<unionset[i]<<endl;
}
return 0;
}
