#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int profit(vector<int>& arr, int& maxi, int i, int x) {
    if(i == arr.size()) {
        return maxi;
    }

    maxi = max(maxi, (arr[i] - x));

    return profit(arr, maxi, ++i, x);
}

void bestProfit(vector<int>& arr, int& p, int i, int maxi) {
    if(i == arr.size() - 1) {
        return;
    }

    p = max(p, profit(arr, maxi, i + 1, arr[i]));

    bestProfit(arr, p, ++i, maxi);
}

int main() {

    int n, x;
    vector<int> arr;

    int p = INT_MIN;

    cout << "Enter no. of Days: ";
    cin >> n;

    cout << "Enter prices on " << n << " days respectively: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    bestProfit(arr, p, 0, INT_MIN);

    if(p < 0)
        p = 0;

    cout << endl << "Best Profit: " << p << endl;

    return 0;
}
