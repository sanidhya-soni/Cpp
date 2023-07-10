#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int robbing(vector<int>& arr, int i) {
    if(i >= arr.size())
        return 0;
    
    int robAmt1 = arr[i] + robbing(arr, i + 2);
    int robAmt2 = 0 + robbing(arr, i + 1);

    return max(robAmt1, robAmt2);
}

int main() {

    int n, x;
    vector<int> arr;

    cout << "Enter length of Array: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    int robAmt = robbing(arr, 0);

    cout << endl << "Maximum Amount that can be Robbed: " << robAmt << endl;

    return 0;
}
