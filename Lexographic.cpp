#include <iostream>
using namespace std;
void nextCombination(int a[], int r, int n)
{
    int i = r - 1;
    while (i >= 0 && a[i] == n - r + i + 1)
    {
        i--;
    }
    if (i >= 0)
    {
        a[i]++;
        for (int j = i + 1; j < r; j++)
        {
            a[j] = a[i] + j - i;
        }
    }
}

int main(){
    int r, n;
    cout<<"Enter the value of r: ";
    cin>>r;
    cout<<"Enter the value of n: ";
    cin>>n;
    int combination[r];
    cout<<"Enter the combination elements: ";
    for (int i = 0; i < r; i++)
    {
        cin>>combination[i];
    }
    nextCombination(combination, r, n);
    cout<<"The next combination is: ";
    for (int i = 0; i < r; i++)
    {
        cout<<combination[i];
    }
    return 0;
}