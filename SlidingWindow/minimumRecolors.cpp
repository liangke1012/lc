//
// Created by liang on 2025/8/3.
// 2379. 得到 K 个黑块的最少涂色次数
//

#include <iostream>
using namespace std;

int minimumRecolors(string blocks, int k);

int main() {
    string blocks = "WBBWWBBWBW";
    int k = 7;
    int res = minimumRecolors(blocks, k);
    cout << res << endl;
    return 0;
}

int minimumRecolors(string blocks, int k) {
    int cnt = 0;
    int l = 0, r = 0;
    while (r < k) {
        cnt += blocks[r] == 'W' ? 1 : 0;
        r++;
    }
    int res = cnt;
    while (r < blocks.length()) {
        cnt -= blocks[l] == 'W' ? 1 : 0;
        cnt += blocks[r] == 'W' ? 1 : 0;
        res = min(res, cnt);
        l++;
        r++;
    }
    return res;
}
