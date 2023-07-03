#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int s, int e, int& x) {
    if(s > e) {
        return -2;
    }

    int m = s + (e - s) / 2;

    if(arr[m] == x)
        return m;

    return (arr[m] > x)? binarySearch(arr, s, m - 1, x): binarySearch(arr, m + 1, e, x);


    // else if(arr[m] > x) {
    //     e = m - 1;
    // }
    // else {
    //     s = m + 1;
    // }

    // return binarySearch(arr, s, e, x);
}

int main() {

    vector<int> arr;

    int n, x;

    cout << "Enter N: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Enter the number to be Searched: ";
    cin >> x;

    int s = 0, e = n - 1;

    int ans = binarySearch(arr, s, e, x);

    cout << ans + 1 << endl;

    return 0;
}
