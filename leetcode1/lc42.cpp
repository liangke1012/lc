//
// Created by liangke on 2022/11/26.
//
#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int>& height);
int main(){
    vector<int> nums = {1,0,2,1,0,1,3,2,1,2,1};
    int area = trap(nums);
    cout<< area << endl;
    return 0;
}
int trap(vector<int>& height) {
    int ans = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        } else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;

}