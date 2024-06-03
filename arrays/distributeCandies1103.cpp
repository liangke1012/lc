//
// Created by Administrator on 2024/6/3.
//

#include <iostream>
#include <vector>
std::vector<int> distributeCandies(int candies, int num_people);
int main()
{
    int candies = 10;
    int num_people = 4;
    std::vector<int> res= distributeCandies(candies, num_people);
    for (int num : res) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::vector<int> distributeCandies(int candies, int num_people)
{
    std::vector<int> ans(num_people, 0);
    int i = 0;
    while (candies != 0) {
        ans[i % num_people] += std::min(candies, i + 1);
        candies -= std::min(candies, i + 1);
        ++i;
    }
    return ans;
}
