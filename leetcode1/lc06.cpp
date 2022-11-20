//
// Created by liangke on 2022/11/18.
//
#include <iostream>
#include <unordered_set>
using namespace std;
string convert(string s, int numRows);
int main(){
    string str = "abcde";
    string res = convert(str,4);
    cout << res << endl;
    return 0;
}
string convert(string s, int numRows){
    int n =s.length(),r = numRows;
    if(r == 1 || r >=n){
        return s;
    }
    int t = 2 * r - 2;
    string ans;
    for(int i = 0;i < r;i++){
        for(int j = 0;j + i < n;j = j + t){
            ans += s[j + i];
            if( i > 0 && i < r -1 && j + t - i < n){
                ans += s[j + t - i];
            }
        }
    }
    return ans;
}