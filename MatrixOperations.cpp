
#include <iostream>
using namespace std;

int getInputMatrix(){
	int n;
	cin>>n;
	return n;
}

int main()
{
	int arrA[2][2],arrB[2][2],arrJoin[2][2],arrMeet[2][2],arrP[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<"Enter N"<<i+1<<j+1<<" of Matrix A : ";
			arrA[i][j]=getInputMatrix();
//			arrA[i][j]=1;
		}
	}
	cout<<endl;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<"Enter N"<<i+1<<j+1<<" of Matrix B : ";
			arrB[i][j]=getInputMatrix();
		}
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(arrA[i][j]||arrB[i][j]==1){
				arrJoin[i][j]=1;
			}
			else{
				arrJoin[i][j]=0;
			}
		}
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(arrA[i][j]&&arrB[i][j]==1){
				arrMeet[i][j]=1;
			}
			else{
				arrMeet[i][j]=0;
			}
		}
	}
	 for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrP[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                arrP[i][j] = arrP[i][j] || (arrA[i][k] && arrB[k][j]);
            }
//            cout << arrP[i][j] << "\t";
        }
        cout <<endl;
    }
	
	cout<<endl<<"Joined Matrix is : "<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arrJoin[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"Meet of A and B is : "<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arrMeet[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"Product of A and B is : "<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arrP[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}