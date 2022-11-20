//
// Created by liangke on 2022/11/20.
//
#include <iostream>
#include <unordered_set>
using namespace std;
int myAtoi(string s);
int main(){
    string str = " 456";
    int num = myAtoi(str);
    cout << num << endl;
    return 0;
}
int myAtoi(string str) {
    if(str.length() == 0) return 0;
    long ret = 0;
    bool flag = false;
    int i = 0;
    while(str[i] == ' ') ++i;
    if(str[i] == '-') flag = true;
    if(str[i] == '+' || str[i] == '-') ++i;
    while(i < str.length() && str[i] >= '0' && str[i] <= '9') {
        ret = ret * 10 + str[i] - '0';
        if(!flag && ret > INT_MAX) return INT_MAX;
        else if(flag && ret-1 > INT_MAX) return INT_MIN;
        ++i;
    }
    return flag?-ret:ret;


}