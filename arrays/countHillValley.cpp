//
// Created by liang on 2025/7/27.
// 2210. 统计数组中峰和谷的数量
//
#include <iostream>
#include <vector>
using namespace std;

int countHillValley(vector<int>& nums);

int main() {
    vector<int> nums = {2,4,1,1,6,5};
    int res = countHillValley(nums);
    cout << res;
    return 0;
}

int countHillValley(vector<int>& nums) {
    int cnt = 0;
    int pre = nums[0];
    for (int i = 1; i < nums.size() - 1; i++) {
        int cur = nums[i];
        int next = nums[i + 1];
        if (cur == next) {
            continue;
        }
        if (pre != cur && (pre < cur) == (cur > next)) {
            cnt++;
        }
        pre = cur;
    }
    return cnt;
}
