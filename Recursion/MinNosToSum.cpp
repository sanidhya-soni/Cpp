#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int reccursive(vector<int>& arr, int x) {
    if(x < 0) {
        return INT_MAX;
    }
    if(x == 0) {
        return 0;
    }

    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++) {
        int ans = reccursive(arr, x - arr[i]);
        if(ans != INT_MAX)
        mini = min(mini, ans + 1);
    }

    return mini;
}

int main() {

    vector<int> arr, vrr;

    int n, x;

    cout << "Enter N: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Enter the number to be Formed: ";
    cin >> x;

    int ans = reccursive(arr, x);

    cout << "Ans: " << ans << endl;

    return 0;
}
