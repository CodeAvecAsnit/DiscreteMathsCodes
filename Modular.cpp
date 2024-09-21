#include<iostream>
using namespace std;

int power(int x,int y){
	if(y==0){
		return 1;
	}
	else{
		return x * power(x,y-1);
	}
}

int floor(int x){
	return x/2;
}

int rec(int b,int n,int m){
	if(n==0){
		return 1;
	}
	else if(n%2==0){
		return (rec(b,n/2,m) * rec(b,n/2,m))%m;
	}
	else{
		return ((rec(b,floor(n/2),m) * rec(b,floor(n/2),m))%m*(b%m))%m;
	}
}

int main(){
	int a,n,m;
	cout<<"Enter 3 values in form of a^n mod m : "<<endl;
	cout<<"a = ";
	cin>>a;
	cout<<"n = ";
	cin>>n;
	cout<<"m = ";
	cin>>m;
	cout<<"The result is : "<<rec(a,n,m);
	
	return 0;
}