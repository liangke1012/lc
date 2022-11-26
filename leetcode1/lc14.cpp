//
// Created by liangke on 2022/11/24.
//
#include <iostream>
#include "vector"
using namespace std;
string longestCommonPrefix(vector<string>& strs);
string longestCommonPrefix(const string& str1, const string& str2);
int main(){
    vector<string> strs = {"flower","flow","flight"};
    string res = longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
}
string longestCommonPrefix(vector<string>& strs){
    if(strs.empty()){
        return "";
    }
    string prefix = strs[0];
    int count = strs.size();
    for (int i = 1; i < count; ++i) {
        prefix = longestCommonPrefix(prefix, strs[i]);
        if (!prefix.size()) {
            break;
        }
    }
    return prefix;
}
string longestCommonPrefix(const string& str1, const string& str2){
    int len = min(str1.length(),str2.length());
    int index = 0;
    while(index < len && str1[index] == str2[index]){
        index++;
    }
    return str1.substr(0,index);

}

