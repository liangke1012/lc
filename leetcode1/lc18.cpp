//
// Created by liangke on 2022/11/25.
//
#include <iostream>
#include "vector"
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target);
int main(){
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    vector<vector<int>> res = fourSum(nums,target);
    return 0;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int k = 0;k < nums.size();k++){
        if(k > 0 && nums[k] == nums[k-1]){
            continue;
        }
        for(int i = k + 1;i < nums.size();i++){
            if(i > k +1 && nums[i] == nums[i -1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if((long)nums[i]+nums[k]+nums[left]+nums[right] > target){
                    right--;
                }else if((long)nums[i]+nums[k]+nums[left]+nums[right] < target){
                    left++;
                }else{
                    result.push_back({nums[i],nums[k],nums[left],nums[right]});
                    while(right > left && nums[left] == nums[left + 1])left++;
                    while(right > left && nums[right] == nums[right - 1])right--;

                    right--;
                    left++;
                }
            }
        }
    }
    return result;
}