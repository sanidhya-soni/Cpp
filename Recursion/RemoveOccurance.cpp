#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void remove(string& s, string& part) {
    if(s.find(part) == string::npos) {
        return;
    }
    int x = s.find(part);
    string a = "";
    for(int i = 0; i < s.length(); i++) {
        if(i == x) {
            i += part.length();
        }
        a.push_back(s[i]);
    }
    s = a;
    remove(s, part);
}

int main() {

    string s, part;

    cout << "Enter String: ";
    cin >> s;

    cout << endl << "Enter Part: ";
    cin >> part;

    remove(s, part);

    cout << endl << "Modified String: " << s << endl;

    return 0;
}
