//
// Created by liang on 2025/6/22.
// 2138. 将字符串拆分为若干长度为 k 的组
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> divideString(string s, int k, char fill);

int main() {
    string s = "abcdefghife";
    vector<string> res = divideString(s, 3, 'x');
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}

vector<string> divideString(string s, int k, char fill) {
    int n = 0;
    vector<string> res;
    while (n < s.length()) {
        res.push_back(s.substr(n, k));
        n += k;
    }
    res.back() += string(k - res.back().length(), fill);
    return res;
}