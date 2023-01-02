#include <iostream>
using namespace std;

bool isPallindrome(string s, int l, int r)
{
    if(l >= r)
        return true;
    
    if(s[l] != s[r])
        return false;

    return isPallindrome(s, l + 1, r - 1);
}

int main()
{
    cout << isPallindrome("OKKO", 0, 3) << endl;
    return 0;
}
