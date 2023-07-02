#include<iostream>
using namespace std;

bool isSorted(int arr[], int i, int n) {
    if(i == n - 2) {
        return true;
    }
    if(arr[i] < arr[i + 1]) {
        return isSorted(arr, i + 1, n);
    }
    else {
        return false;
    }
}

int main() {

    int n = 10;

    // int arr[] = {10, 11, 15, 9, 7, 6, 44, 14, 78, 25};
    int arr[] = {1, 2, 3, 4, 5};

    bool isSort = isSorted(arr, 0, n);

    cout << isSort << endl;;

    return 0;
}
