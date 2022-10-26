//
// Created by liangke on 2022/10/25.
//
#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s);

int main(){
    //unordered_set用法
    unordered_set<char> str1 = {'a','b'};
    str1.insert('c');
    str1.erase('a');
    for (auto iter = str1.begin(); iter != str1.end(); ++iter) {
        cout << *iter << endl;
    }

    string s = "abcabcdefabcaa";
    int n = lengthOfLongestSubstring(s);
    cout << n <<endl;
    return 0;
}
int lengthOfLongestSubstring(string s){
    if(s.size() == 0) return 0;
    unordered_set<char> str;
    int maxStr = 0;
    int left = 0;
    for(int i =0;i<s.size();i++){
        while(str.find(s[i]) != str.end()){
            str.erase(s[left]);
            left++;
        }
        maxStr = max(maxStr,i-left+1);
        str.insert(s[i]);
    }
    return maxStr;
}