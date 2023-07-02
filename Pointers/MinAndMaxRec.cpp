#include<iostream>
using namespace std;

void minAndMax(int arr[], int& min, int& max, int i, int n) {
    if(i == n) {
        return;
    }
    if(arr[i] < min) {
        min = arr[i];
    }
    if(arr[i] > max) {
        max = arr[i];
    }
    minAndMax(arr, min, max, i + 1, n);
}

int main() {

    int n;

    int arr[] = {10, 11, 15, 9, 7, 6, 44, 14, 78, 25};

    int max = INT32_MIN;
    int min = INT32_MAX;

    minAndMax(arr, min, max, 0, 10);

    cout << max << " " << min;

    return 0;
}
