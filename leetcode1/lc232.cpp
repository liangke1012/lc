//
// Created by liangke on 2022/11/26.
//
/**
 * 请你仅使用两个栈实现先入先出队列
 */
#include <iostream>
#include <stack>
using namespace std;

int main(){

    return 0;
}
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }

    void push(int x) {
      stIn.push(x);
    }

    int pop() {
        if(stOut.empty()){
            while (!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
      int res = this->pop();
      stOut.push(res);
      return res;
    }

    bool empty() {
        return stIn.empty() &&stOut.empty();
    }
};