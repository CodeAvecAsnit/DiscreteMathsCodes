#include <iostream>
using namespace std;

void nextPermutation(int arr[], int n) {
    int j = n - 2;
    while (j >= 0 && arr[j] >= arr[j+1]) {
        j--;
    }
    if (j < 0) {
        return;
    }
    int k = n - 1;
    while (arr[j] >= arr[k]) {
        k--;
    }
    int temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;

    int r = n - 1;
    int s = j + 1;
    while (r > s) {
        temp = arr[r];
        arr[r] = arr[s];
        arr[s] = temp;
        r--;
        s++;
    }
}

int main() {
    int n;
    cout<<"Enter the size of permutation: ";
    cin>>n;

    int permutation[n];

    cout<<"Enter the permutation elements: ";
    for (int i = 0; i < n; i++) {
        cin>>permutation[i];
    }

    nextPermutation(permutation, n);

    cout<<"The next permutation is: ";
    for (int i = 0; i < n; i++) {
        cout<<permutation[i];
    }

    return 0;
}