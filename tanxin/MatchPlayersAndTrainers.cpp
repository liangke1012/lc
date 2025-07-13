//
// Created by liang on 2025/7/13.
// 2410. 运动员和训练师的最大匹配数
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers);

int main() {
    vector<int> players = {4,7,9};
    vector<int> trainers = {8,2,5,8};
    int res = matchPlayersAndTrainers(players, trainers);
    cout << res << endl;
    return 0;
}

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    int m = players.size();
    int n = trainers.size();
    int count = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && players[i] > trainers[j]) {
            j++;
        }
        if (j < n) {
            count++;
        }
    }
    return count;
}