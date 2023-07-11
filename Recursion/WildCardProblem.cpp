#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

bool isMatchHelper(string& s, int si, string& p, int pi) {
        if(si == s.length() && pi == s.length())
            return true;
        if(si == s.length() && pi < p.length()) {
            while(pi < p.length()) {
                if(p[pi] != '*')
                    return false;
                pi+=1;
            }
            return true;
        }
        if(s[si] == p[pi] || p[pi] == '?') {
            return isMatchHelper(s, si + 1, p, pi + 1);
        }
        if(p[pi] == '*') {
            bool case1 = isMatchHelper(s, si, p, pi + 1);
            bool case2 = isMatchHelper(s, si + 1, p, pi);
            return case1 || case2;
        }
        return false;
    }

int main() {

    string s, p;

    cout << "Enter String S: ";
    cin >> s;

    cout << "Enter String P: ";
    cin >> p;

    int si = 0;
    int pi = 0;
    cout << endl << isMatchHelper(s, si, p, pi) << endl;
    return 0;
}
