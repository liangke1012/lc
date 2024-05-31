//
// Created by Administrator on 2024/5/31.
//
#include <iostream>
#include <vector>

using namespace std;
std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& pVector);

int main()
{
    vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> res = findMissingAndRepeatedValues(grid);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}

std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    vector<int> count(n * n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            count[grid[i][j]]++;
        }
    }
    vector<int> res(2);
    for (int i = 1; i <= n * n; ++i) {
        if (count[i] == 2) {
            res[0] = i;
        }
        if (count[i] == 0) {
            res[1] = i;
        }
    }
    return res;
}
