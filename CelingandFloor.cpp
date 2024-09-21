#include<iostream>
using namespace std;

int main(){
    cout << "Enter any number:" << endl;
    double a;
    int floor, ceil;

    cin >> a;
    floor = (int)a;
    if (floor == a) {
        ceil = floor;  
    } else {
        if (a > 0) {
            ceil = floor + 1; 
        } else {
            ceil = floor; 
        }
    }
    cout << "The ceiling integer of the number is " << ceil << endl;
    cout << "The floor integer of the number is " << floor << endl;
    return 0;
}