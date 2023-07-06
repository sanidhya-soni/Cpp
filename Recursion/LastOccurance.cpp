#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void lastOccurance(string& s, int i, char& ch, int& found) {
    // if(s.length() == 0) {
    //     return;
    // }

    // char c = s[s.length() - 1];
    // s.pop_back();
    // lastOccurance(s, i - 1, ch, found);

    // if(c == ch) {
    //     found = i;
    // }

    if(i == s.length()) {
        return;
    }

    if(ch == s[i]) {
        found = i;
    }

    lastOccurance(s, i + 1, ch, found);
}

int main() {

    string s;
    char ch;
    int found = -1;

    cout << "Enter a String: ";
    cin >> s;
    cout << endl << "Enter Character to be Searched: ";
    cin >> ch;

    lastOccurance(s, 0, ch, found);

    cout << endl << "Ans: " << found + 1 << endl;

    return 0;
}
