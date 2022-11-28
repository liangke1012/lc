//
// Created by liangke on 2022/11/26.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class mycomparsion {
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> map;
      for(int i = 0;i<nums.size();i++){
          map[nums[i]]++;
      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparsion> que;
      for(auto& [num,count] : map){
          if(que.size() == k){
              if(que.top().second < count){
                  que.pop();
                  que.emplace(num,count);
              }else{
                  que.emplace(num,count);
              }
          }
          vector<int> ret;
          while (!que.empty()) {
              ret.emplace_back(que.top().first);
              que.pop();
          }
          return ret;
      }
}
