//
// Created by liang on 2025/7/12.
// 3439. 重新安排会议得到最多空余时间 I
//
#include <iostream>
#include <vector>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime);
int maxFreeTime2(int eventTime, vector<int>& startTime, vector<int>& endTime);

int main() {
    int eventTime = 5, k = 1;
    vector<int> startTime = {1,3};
    vector<int> endTime = {2,5};
    int res = maxFreeTime(eventTime, k, startTime, endTime);
    cout << res << endl;

    eventTime = 10;
    startTime = {0,3,7,9};
    endTime = {1,4,8,10};
    res = maxFreeTime2(eventTime, startTime, endTime);
    cout << res << endl;
    return 0;
}


int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    vector<int> free(n + 1);
    free[0] = startTime[0];
    for (int i = 1; i < n; ++i) {
        free[i] = startTime[i] - endTime[i - 1];
    }
    free[n] = eventTime - endTime[n - 1];

    int res = 0, s = 0;
    for (int i = 0; i <= n; ++i) {
        s += free[i];
        if (i < k) {
            continue;
        }
        res = max(res, s);
        s -= free[i - k];
    }
    return res;
}

int maxFreeTime2(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    int res = 0;
    for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
        int left = i == 0 ? 0 : endTime[i - 1];
        int right = i == n - 1 ? eventTime : startTime[i + 1];
        if (endTime[i] - startTime[i] <= t1) {
            res = max(res, right - left);
        }
        t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

        res = max(res, right - left - (endTime[i] - startTime[i]));

        int left2 = i == n - 1 ? 0 : endTime[n - i - 2];
        int right2 = i == 0 ? eventTime : startTime[n - i];
        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            res = max(res, right2 - left2);
        }
        t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }
    return res;
}