/**
 *  leetcode 3576 数组元素相等转换
 */

#include <iostream>
#include <vector>
using namespace std;

bool canMakeEqual(vector<int>& nums, int k);
bool check(vector<int>& nums, int k, int target);


int main() {
    vector<int> nums = {-1,-1,-1,1,1,1};
    int k = 5;
    bool res = canMakeEqual(nums, k);
    cout << res << endl;
    return 0;
}

bool canMakeEqual(vector<int> &nums, int k) {
    return check(nums, k, 1) || check(nums, k, -1);
}

bool check(vector<int>& nums, int k, int target) {
    int n = nums.size();
    int left = k;
    int mul = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] * mul == target) {
            mul = 1;
            continue;
        }
        if (left == 0 || i == n -1 ) {
            return false;
        }
        left--;
        mul = -1;
    }
    return true;
}

