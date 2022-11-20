//
// Created by liangke on 2022/11/20.
//
#include <iostream>
#include <unordered_set>
using namespace std;
int reverse(int x);
int main(){
    int x = 134;
    int rex = reverse(x);
    cout << rex << endl;
    return 0;
}
int reverse(int x) {
     int rev = 0;
     while(x != 0){
         if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
             return 0;
         }
         int dig = x % 10;
         x /= 10;
         rev = rev * 10 + dig;
     }
    return rev;
}