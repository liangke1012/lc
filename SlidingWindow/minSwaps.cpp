//
// Created by liang on 2025/8/17.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int minSwaps(vector<int>& nums);

int main() {
    vector<int> nums = {0,1,0,1,1,0,0};
    int res = minSwaps(nums);
    cout << res << endl;
    return 0;
}

int minSwaps(vector<int>& nums) {
    int k = reduce(nums.begin(), nums.end(), 0);
    if (k == 0) {
        return 0;
    }

    int n = nums.size();
    int max1 = 0, cnt1 = 0;
    for (int i = 0; i < n + k - 1; i++) {
        // 1. 进入窗口
        cnt1 += nums[i % n];
        if (i < k - 1) { // 窗口大小不足 k
            continue;
        }
        // 2. 更新答案
        max1 = max(max1, cnt1);
        // 3. 离开窗口，为下一个循环做准备
        cnt1 -= nums[i - k + 1]; // 由于我们保证 i < n+k-1，所以 i-k+1 < n，无需取模
    }
    return k - max1;
}
