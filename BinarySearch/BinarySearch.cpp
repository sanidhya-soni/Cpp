#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int binarySearch(int arr[], int size, int n) {
    int s = 0, e = size - 1, m;
    
    while(s <= e) {
        m = s + (e - s) / 2;
        if(arr[m] == n)
            return m + 1;
        if(arr[m] > n) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int main() {

    int x = 0;
    cout << "Enter number of elements: ";
    cin >> x;

    const int n = x;
    int arr[n];

    cout << endl << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a;
    cout << endl << "Enter number to be searched: ";
    cin >> a;

    cout << endl << "Found at Position: " << binarySearch(arr, n, a);

    return 0;
}
