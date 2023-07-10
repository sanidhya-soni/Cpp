#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<int, string>> mp = {
    {1000000000, "Billion"},
    {1000000, "Million"},
    {1000, "Thousand"},
    {100, "Hundred"},
    {90, "Ninety"},
    {80, "Eighty"},
    {70, "Sevety"},
    {60, "Sixty"},
    {50, "Fifty"},
    {40, "Fourty"},
    {30, "Thirty"},
    {20, "Twenty"},
    {19, "Nineteen"},
    {18, "Eightteen"},
    {17, "Seventeen"},
    {16, "Sixteen"},
    {15, "Fifteen"},
    {14, "Fourteen"},
    {13, "Thirteen"},
    {12, "Twelve"},
    {11, "Eleven"},
    {10, "Ten"},
    {9, "Nine"},
    {8, "Eight"},
    {7, "Seven"},
    {6, "Six"},
    {5, "Five"},
    {4, "Four"},
    {3, "Three"},
    {2, "Two"},
    {1, "One"}
};

string number(int num) {
    if(num == 0) {
        return "Zero";
    }
    for(auto i: mp) {
        if(num >= i.first) {
            string a = "";
            if(num >= 100) {
                a = number(num / i.first) + " ";
            }

            string b = i.second;

            string c = "";
            if(num % i.first != 0) {
                c = " " + number(num % i.first);
            }
            return a + b + c;
        }
    }
    return "";
}

int main() {

    cout << endl << number(12) << endl;
    
    return 0;
}
