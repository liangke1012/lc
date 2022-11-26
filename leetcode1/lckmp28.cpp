//
// Created by liangke on 2022/11/26.
//
/**
 * kmp算法
 */
#include <iostream>
#include <unordered_set>
using namespace std;
int strStr(string haystack, string needle);
bool repeatedSubstringPattern(string s);
void getNext(int* next, const string& s);
int main(){
    string a1 = "abcdfabcdacd";
    string a2 = "abcda";
    int res = strStr(a1,a2);
    cout << res << endl;

    string s1 = "abcabcdf";
    bool f = repeatedSubstringPattern(s1);
    cout << f <<endl;
}
int strStr(string haystack, string needle) {
   if(needle.size() == 0){
       return 0;
   }
   int next[needle.size()];
    getNext(next,needle);
    int j = 0;
    for(int i = 0;i<haystack.size();i++){
        while(j > 0 && haystack[i] != needle[j]){
            j = next[j-1];
        }
        if(haystack[i] == needle[j]){
            j++;
        }
        if(j == needle.size()){
            return (i - needle.size() +1);
        }
    }
    return -1;
}
/**
 * kmp核心算法，构建next数组
 * @param next
 * @param s
 */
void getNext(int* next, const string& s){
    int j = 0;
    next[0] = 0;
    for(int i = 1;i<s.size();i++){
        while(j > 0 && s[i] != s[j]){
            j = next[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        next[i] = j;
    }
}
/**
 * leetcode 459: 给定一个非空的字符串s ，检查是否可以通过由它的一个子串重复多次构成。
 * @param s
 * @return
 */
bool repeatedSubstringPattern(string s){
    if(s.size() == 0){
        return false;
    }
    int next[s.size()];
    getNext(next,s);
    int len = s.size();
    if(next[len-1] !=0 && len % (len-next[len-1]) == 0){
        return true;
    }
    return false;
}
