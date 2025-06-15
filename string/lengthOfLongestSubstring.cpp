//
// LCR 016. 无重复字符的最长子串
// Created by liang on 2025/6/14.
//

#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s);

int main() {
    string str = "abcabcbb";
    int res = lengthOfLongestSubstring(str);
    cout << res << endl;
    return 0;
}

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n <= 1) {
        return n;
    }
    int left = 0, right = 0, res = 0;
    unordered_set<char> window;
    while (right < n) {
        char cur = s[right];
        if (!window.count(cur)) {
            res = max(res, right - left + 1);
            window.insert(cur);
            right++;
        } else {
            window.erase(s[left]);
            left++;
        }
    }
    return res;
}