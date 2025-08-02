//
// Created by liang on 2025/8/2.
//
#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k);

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double res = findMaxAverage(nums, k);
    cout << res << endl;
    return 0;
}

double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    int maxSum = sum;
    for (int i = k; i < nums.size(); ++i) {
        sum = sum - nums[i - k] + nums[i];
        maxSum = max(maxSum, sum);
    }
    return (double)maxSum / k;
}