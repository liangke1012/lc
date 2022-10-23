//
// Created by liang on 2022/10/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
int main(){
    vector<int> nums = {2,7,11,15};

    vector<int> result = twoSum(nums,9);
    for(int i =0;i<result.size();i++){
        cout << result[i] << "   ";
    }
    return 0;
}
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> map;
    for(int i = 0;i<nums.size();i++){
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            return {it->second, i};
        }
        map[nums[i]] = i;
    }
    return {};
}
