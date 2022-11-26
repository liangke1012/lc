//
// Created by liangke on 2022/11/25.
//
#include <iostream>
#include "vector"
using namespace std;
bool isAnagram(string s, string t);
int main(){
    string s1 = "adfr";
    string s2 = "dfar";
    bool res = isAnagram(s1,s2);
    cout << res << endl;
    return 0;
}
bool isAnagram(string s, string t){
    int record[26] = {0};
    for(int i = 0;i<s.size();i++){
        record[s[i] - 'a']++;
    }
    for(int i = 0;i<t.size();i++){
        record[t[i] - 'a']--;
    }
    for(int i = 0; i < 26;i++){
        if(record[i] != 0){
            return false;
        }
    }
    return true;
}