//
// Created by liangke on 2022/11/1.
//
#include "iostream"
#include "vector"
using namespace std;
string longestPalindrome(string s);
int expandAroundCenter(const string& s, int left, int right);

int main(){
    string s = "abcaba";
    string s1 = longestPalindrome(s);
    cout << s1 << endl;
    return 0;
}

string longestPalindrome(string s){
    int n = s.size();
    if(n<2){
        return s;
    }
    int start = 0;
    int end = 0;
    for(int i = 0;i < n;i++){
        int len1 = expandAroundCenter(s,i,i);
        int len2 = expandAroundCenter(s,i,i+1);
        int len = max(len1,len2);
        if(len > end - start){
            start = i - (len -1)/2;
            end = i + len/2;
        }
    }
    return s.substr(start, end - start + 1);
}
int expandAroundCenter(const string& s, int left, int right) {
    while(left >= 0 && right < s.size() && s[left] == s[right]){
        --left;
        ++right;
    }
    return right - left - 1;
}