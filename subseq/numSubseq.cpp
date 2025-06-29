//
// Created by liang on 2025/6/29.
// 1498. 满足条件的子序列数目
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MX = 100000;

int pow2[MX]; // 2^i

int numSubseq(vector<int>& nums, int target);
void pretreatment() {
    pow2[0] = 1;
    for (int i = 1; i < MX; ++i) {
        pow2[i] = (long long)pow2[i - 1] * 2 % MOD;
    }
}

int main() {
    vector<int> nums = {3,5,6,7};
    int target = 9;
    int res = numSubseq(nums, target);
    cout << res << endl;
    return 0;
}

int numSubseq(vector<int>& nums, int target) {
    pretreatment();
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            ans += pow2[right - left];
            left++;
        } else {
            right--;
        }
    }
    return ans % MOD;
}
