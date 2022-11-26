//
// Created by liangke on 2022/11/24.
//
#include <iostream>
#include "vector"
using namespace std;
string intToRoman(int num);
const pair<int, string> valueSymbols[] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
};
int main(){
    int num = 2444;
    string roman = intToRoman(num);
    return 0;
}
string intToRoman(int num){
    string roman;
    for (const auto &[value, symbol] : valueSymbols) {
        while (num >= value) {
            num -= value;
            roman += symbol;
        }
        if (num == 0) {
            break;
        }
    }
    return roman;
}