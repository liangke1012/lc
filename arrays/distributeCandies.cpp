//
// Created by Administrator on 2024/6/1.
//
#include <iostream>

int distributeCandies(int n, int limit);
int main()
{
    int n = 5;
    int limit = 2;
    int res = distributeCandies(n, limit);
    std::cout << res << std::endl;
}

int distributeCandies(int n, int limit)
{
    int res = 0;
    for (int i = 0; i <= limit; ++i) {
        for (int j = 0; j <= limit; ++j) {
            if (i + j > n) {
                break;
            }
            if (n - i - j <= limit) {
                res++;
            }
        }
    }
    return res;
}


