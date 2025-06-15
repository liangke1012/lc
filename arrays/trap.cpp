//
// leetcode 42 接雨水
// Created by liang on 2025/6/14.
//
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height);

int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(height);
    cout << res << endl;
    return 0;
}

int trap(vector<int>& height) {
    int res = 0;
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (height[left] < height[right]) {
            res += leftMax - height[left];
            left++;
        } else {
            res += rightMax - height[right];
            right--;
        }
    }
    return res;
}
