//
// Created by Administrator on 2024/5/30.
//
#include <iostream>
#include <vector>
#include <ranges>

int maximumLength(std::string s);
int main()
{
    std::string s = "abcaba";
    int res = maximumLength(s);
    std::cout << res << std::endl;
    return 0;
}

int maximumLength(std::string s)
{
    std::vector<int> group[26];
    int cnt = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        cnt++;
        if (i + 1 == n || s[i] != s[i + 1]) {
            group[s[i] - 'a'].push_back(cnt);
            cnt = 0;
        }
    }
    int ans = 0;
    for (auto &a : group) {
        if (a.empty()) continue;
        std::ranges::sort(a, std::greater());
        a.push_back(0);
        a.push_back(0); // 假设还有两个空串
        ans = max({ans, a[0] - 2, min(a[0] - 1, a[1]), a[2]});
    }
    return ans ? ans : -1;
}
