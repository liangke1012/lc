//
// Created by Administrator on 2024/6/6.
//
#include <iostream>
#include <string>
long long minimumSteps(std::string s);
int main()
{
    std::string s = "101";
    long long res = minimumSteps(s);
    std::cout << res << std::endl;
    return 0;
}


long long minimumSteps(std::string s)
{
    long long ans = 0;
    int cnt = 0;
    for (char c : s) {
        if (c == '1') {
            cnt++;
        } else {
            ans += cnt;
        }
    }
    return ans;
}