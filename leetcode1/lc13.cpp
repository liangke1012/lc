//
// Created by liangke on 2022/11/24.
//
#include <iostream>
#include "unordered_map"
using namespace std;
int romanToInt(string s);
unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
};
int main(){

    return 0;
}
int romanToInt(string s){
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int value = symbolValues[s[i]];
        if (i < n - 1 && value < symbolValues[s[i + 1]]) {
            ans -= value;
        } else {
            ans += value;
        }
    }
    return ans;

}
