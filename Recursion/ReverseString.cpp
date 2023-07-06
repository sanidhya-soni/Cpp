#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;

void reverse(string& s, string& rev, int i) {
    if(i == s.length()) {
        return;
    }

    char ch = s[i];

    reverse(s, rev, i + 1);

    rev = rev + ch;
}

int main() {

    string s, rev = "";
    int i = 0;

    cout << "Enter a String to be Reversed: ";
    getline(cin, s);

    reverse(s, rev, i);

    cout << endl << "Reversed String: " << rev << endl;

    return 0;
}
