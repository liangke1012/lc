//
// Created by Administrator on 2024/6/2.
//
#include <iostream>
#include <vector>
#include <unordered_set>

int distributeCandies(std::vector<int>& candyType);
int main()
{
    std::vector<int> candyType = {1,1,2,2,3,3};

    int res = distributeCandies(candyType);
    std::cout << res << std::endl;
}

int distributeCandies(std::vector<int>& candyType)
{
    return std::min(std::unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
}
