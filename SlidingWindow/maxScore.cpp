//
// Created by liang on 2025/8/17.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k);
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes);

int main() {
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    int res = maxScore(cardPoints, k);
    cout << res << endl;

    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    res = maxSatisfied(customers, grumpy, minutes);
    cout << res << endl;
    return 0;
}

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int windowSize = n - k;
    int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
    int minSum = sum;
    for (int i = windowSize; i < n; i++) {
        sum += cardPoints[i] - cardPoints[i - windowSize];
        minSum = min(minSum, sum);
    }
    return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
}

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int total = 0;
    int n = customers.size();
    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) {
            total += customers[i];
        }
    }

    int increase = 0;
    for (int i = 0; i < minutes; i++) {
        increase += customers[i] * grumpy[i];
    }
    int maxIncrease = increase;
    for (int i = minutes; i < n; i++) {
        increase = increase - customers[i - minutes] * grumpy[i - minutes] + customers[i] * grumpy[i];
        maxIncrease = max(maxIncrease, increase);
    }

    return total + maxIncrease;
}
