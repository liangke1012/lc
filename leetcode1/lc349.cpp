//
// Created by liangke on 2022/11/25.
//
#include <iostream>
#include "vector"
#include "unordered_set"
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
int main(){
    vector<int> nums1 = {1,2,3,3,4,5,5,7};
    vector<int> nums2 = {2,3,3};
    vector<int> res = intersection(nums1,nums2);
    return 0;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     unordered_set<int> result;
    unordered_set<int> nums_set(nums1.begin(),nums1.end());
    for(int num : nums2){
        if(nums_set.find(num) != nums_set.end()){
            result.insert(num);
        }
    }
    return vector<int>(result.begin(),result.end());
}