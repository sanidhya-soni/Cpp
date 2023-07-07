#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void add(string& x, string& y, string& sum, int& carry) {
    if(x.length() == 0 && y.length() == 0) {
        if(carry != 0) {
            sum = char(carry + 48) + sum;
        }
        return;
    }

    int a = 0, b = 0;

    if(x.length() != 0) {
        a = x[x.length() - 1] - 48;
        x.pop_back();
    }
    if(y.length() != 0) {
        b = y[y.length() - 1] - 48;
        y.pop_back();
    }

    int c = a + b + carry;
    carry = c / 10;
    c = c % 10;

    sum = char(c + 48) + sum;

    add(x, y, sum, carry);
}

int main() {

    string x, y, sum = "";
    int carry = 0;

    cout << "Enter 1st Number: ";
    cin >> x;
    cout << "Enter 2nd Number: ";
    cin >> y;

    add(x, y, sum, carry);

    cout << sum << endl;

    return 0;
}
