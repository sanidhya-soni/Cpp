#include <iostream>
#include<vector>
#include <limits.h>
using namespace std;

void merge(int arr[], int s, int e) {

    int mid = s + (e - s) / 2;
    int const len1 = mid - s + 1;
    int const len2 = e - mid;
    int* leftArr = new int[len1];
    int* rightArr = new int[len2];
    int left = 0, right = 0;

    for(int i = s; i <= e; i++)
        (i <= mid)? leftArr[left++] = arr[i]: rightArr[right++] = arr[i];

    left = 0;
    right = 0;

    int k = s;

    while(left < len1 && right < len2)
        (leftArr[left] <= rightArr[right])? arr[k++] = leftArr[left++]: arr[k++] = rightArr[right++];

    while(left < len1)
        arr[k++] = leftArr[left++];

    while(right < len2)
        arr[k++] = rightArr[right++];

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e)
        return;
    
    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {

    int arr[] = {5, 4, 3, 78, 2, 1, 20, 21, 15, 13};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);

    cout << endl;

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
