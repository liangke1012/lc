//
// Created by liangke on 2022/11/26.
//
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
bool isValid(string s);
//leetcode150
int evalRPN(vector<string>& tokens);
int main(){
    string s ="(){}[]";
    bool fa = isValid(s);
    vector<string> s1 = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    int res = evalRPN(s1);
    cout << res << endl;
    return 0;
}
bool isValid(string s) {
   int n = s.size();
   if(n % 2 == 1){
       return false;
   }
    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    stack<char> stk;
    for(char  ch : s){
        if (pairs.count(ch)) {
            if (stk.empty() || stk.top() != pairs[ch]) {
                return false;
            }
            stk.pop();
        }
        else {
            stk.push(ch);
        }
    }
    return stk.empty();
}
/**
 * leetcode 150:逆波兰表示法，求表达式的值。

 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 注意 两个整数之间的除法只保留整数部分。

 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

 * @param tokens
 * @return
 */
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(int i = 0;i <tokens.size();i++){
        if(tokens[i] == "+" || tokens[i] == "-" ||tokens[i] == "*" ||tokens[i] == "/" ){
            int nums1 = stk.top();
            stk.pop();
            int nums2 = stk.top();
            stk.pop();
            if(tokens[i] == "+") stk.push(nums2+nums1);
            if(tokens[i] == "-") stk.push(nums2-nums1);
            if(tokens[i] == "*") stk.push((long)nums2*(long)nums1);
            if(tokens[i] == "/") stk.push(nums2/nums1);
        }else{
            stk.push(stoi(tokens[i]));
        }

    }
    int res = stk.top();
    return res;
}