//
// Created by liangke on 2022/11/25.
//
#include <iostream>
#include "vector"
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums);
int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = threeSum(nums);
    for(const auto &itr : res){
       for(auto &it : itr){
           cout << it << "," ;
       }
       cout << endl;
    }
    return 0;
}
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int i = 0;i < nums.size();i++){
        if(nums[i] > 0){
            return result;
        }
        if(i > 0 && nums[i] == nums[i -1]){
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            if(nums[i] + nums[left] + nums[right]> 0){
                right--;
            }else if(nums[i] + nums[left] + nums[right] < 0){
                left++;
            }else{
                result.push_back({nums[i],nums[left],nums[right]});
                while(right > left && nums[left] == nums[left + 1])left++;
                while(right > left && nums[right] == nums[right - 1])right--;

                right--;
                left++;
            }
        }
    }
    return result;
}