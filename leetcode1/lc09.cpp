//
// Created by liangke on 2022/11/22.
//
#include <iostream>
using namespace std;
bool isPalindrome(int x);
int main(){
    int num = 12321;
    bool hhh = isPalindrome(num);
    cout << "is:" << hhh << endl;
    return 0;
}
bool isPalindrome(int x){
     if(x < 0 || (x % 10 == 0 && x != 0)){
         return false;
     }
     int revertNumber = 0;
    while (x > revertNumber){
        revertNumber = revertNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertNumber || x == revertNumber / 10;


}