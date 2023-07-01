#include<iostream>
using namespace std;

void printDigits(int n) {
    if(n == 0) {
        return;
    }

    printDigits(n / 10);

    cout << n % 10 << " ";
}

int main() {

    int n;

    cout << "Enter N: ";
    cin >> n;

    printDigits(n);

    return 0;
}
