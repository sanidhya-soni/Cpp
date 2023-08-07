#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    if(nums[0] >= 0) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        return nums;
    }
    vector<int> nums2(nums.size(), -1);
    int p1, p2, p2_backup, p3 = 0;
    int size = nums.size();
    for(p2 = 0; p2 < nums.size(); p2++) {
        if(nums[p2] == 0) {
            p1 = p2 - 1;
            p2++;
            nums2[p3++] = 0;
            break;
        }
        if(nums[p2] > 0) {
            p1 = p2 - 1;
            break;
        }
    }
    p2_backup = p2;
    // cout << p2;
    int n1, n2;
    while(p1 >= 0 || p2 < nums.size()) {
        n1 = (p1 >= 0)? nums[p1] * nums[p1]: INT_MAX;
        n2 = (p2 < nums.size())? nums[p2] * nums[p2]: INT_MAX;
        if(n1 < n2) {
            nums2[p3++] = n1;
            p1--;
        } else {
            nums2[p3++] = n2;
            p2++;
        }
    }
    return nums2;
}

int main() {

    vector<int> nums{-4,-1,0,3,10};
    vector<int> ans = sortedSquares(nums);
    for(int i : ans) {
        cout << i << endl;
    }
    return 0;
}
