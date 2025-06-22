//
// Created by liang on 2025/6/22.
// 3443. K 次修改后的最大曼哈顿距离
//

#include <algorithm>
#include <iostream>
using namespace std;

int maxDistance(string s, int k);
int count(int drt1, int drt2, int times);

int main() {
    const string s = "NSWWEW";
    const int k = 3;
    const int res = maxDistance(s, k);
    cout << res << endl;
    return 0;
}

int maxDistance(string s, int k) {
    int ans = 0;
    int north = 0, west = 0, east = 0, south = 0;
    for (auto c : s) {
        switch (c) {
            case 'N':
                north++;
                break;
            case 'S':
                south++;
                break;
            case 'W':
                west++;
                break;
            case 'E':
                east++;
                break;
        }
        int times1 = min({north, south, k});
        int times2 = min({east, west, k - times1});
        ans = max(ans, count(north, south, times1) + count(west, east, times2));
    }
    return ans;
}

int count(int drt1, int drt2, int times) {
    return abs(drt1 - drt2) + times * 2;
}
