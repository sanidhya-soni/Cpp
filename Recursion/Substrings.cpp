#include<iostream>
#include<vector>
using namespace std;

void subStrings(string s, string output, int i) {

    if(i == s.length()) {
        if(output == "") {
            cout << "null" << endl;
        }
        else {
            cout << output << endl;
        }
        return;
    }

    subStrings(s, output + s[i], i+1);
    subStrings(s, output, i+1);
    return;
}

int main() {

    string s;

    cout << "Enter the String: ";
    cin >> s;

    subStrings(s, "", 0);

    return 0;
}
