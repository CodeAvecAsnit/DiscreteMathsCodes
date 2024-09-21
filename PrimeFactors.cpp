#include <iostream>
using namespace std;

void primeFactors(int n, int div){
    if (n <= 1) {
        return;
    }
    if (n % div == 0) {
        cout << div << "  ";
        primeFactors(n / div, div);
    } else {
        primeFactors(n, div + 1);
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Prime factors of " << num << " are: ";
    primeFactors(num, 2); 
    cout << endl;

    return 0;
}
