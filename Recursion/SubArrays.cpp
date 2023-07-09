#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void printSubarrays(vector<int> arr, int lower, int& upper) {
    if(lower > upper) {
        return;
    }

    for(int i = lower; i <=  upper; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    printSubarrays(arr, ++lower, upper);
}

void subarrays(vector<int> arr, int& i) {
    if(i == arr.size()) {
        return;
    }
    int upper = arr.size() - 1;
    printSubarrays(arr, i, upper);
    subarrays(arr, ++i);
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

    int i = 0;
    subarrays(arr, i);

    return 0;
}
