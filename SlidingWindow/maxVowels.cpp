//
// Created by liang on 2025/8/2.
// 1456. 定长子串中元音的最大数目
//
#include <iostream>
using namespace std;

int maxVowels(string s, int k);

int main() {
    string s = "abciiidef";
    int k = 3;
    int res = maxVowels(s, k);
    cout << res << endl;
    return 0;
}

int maxVowels(string s, int k) {
    int res = 0;
    int vowels = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels++;
        }
        if (i < k - 1) {
            continue;
        }
        res = max(res, vowels);
        char out = s[i - k + 1];
        if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u') {
            vowels--;
        }
    }
    return res;
}
