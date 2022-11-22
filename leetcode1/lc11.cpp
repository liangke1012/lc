//
// Created by liangke on 2022/11/22.
//
#include <iostream>
#include "vector"
using namespace std;
int maxArea(vector<int>& height);
int main(){

    return 0;
}
int maxArea(vector<int>& height){
    int l = 0;
    int r = height.size() - 1;
    int res = 0;
    while(l < r){
        int area = min(height.at(l),height.at(r)) * (r - l);
        res = max(res,area);
        if(height.at(l) <= height.at(r)) l++;
        if(height.at(l) > height.at(r)) r--;

    }
    return res;
}