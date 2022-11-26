//
// Created by liangke on 2022/11/25.
//
#include <iostream>
using namespace std;
string reverseStr(string s, int k);
int main(){
    string s = "abcdfedfrdd";
    string s1 = reverseStr(s,3);
    cout << s1 <<endl;
    return 0;
}
string reverseStr(string s, int k) {
    for(int i = 0;i < s.size();i+= 2*k){
        if(i + k <= s.size()){
            reverse(s.begin()+i,s.begin()+i +k);
            continue;
        }
        reverse(s.begin()+i,s.begin()+s.size());
    }
    return s;
}