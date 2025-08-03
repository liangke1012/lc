//
// Created by liang on 2025/8/2.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold);
vector<int> getAverages(vector<int>& nums, int k); // 2090. 半径为 k 的子数组平均值
long long maxSum(vector<int>& nums, int m, int k); // 2841. 几乎唯一子数组的最大和
long long maximumSubarraySum(vector<int>& nums, int k); // 2461. 长度为 K 子数组中的最大和

int main() {
    vector<int> nums = {2,2,2,2,5,5,5,8};
    int k = 3;
    int threshold = 4;
    int res = numOfSubarrays(nums, k, threshold);
    cout << res << endl;
    nums = {7,4,3,9,1,8,5,2,6};
    vector<int> res1 = getAverages(nums, k);
    for (auto &a : res1) {
        cout << a << " ";
    }
    cout << endl;
    nums = {2,6,7,3,1,7};
    int m = 3;
    k = 4;
    long long res2 = maxSum(nums, m, k);
    cout << res2 << endl;

    nums = {1,5,4,2,9,9,9};
    k = 3;
    long long res3 = maximumSubarraySum(nums, k);
    cout << res3 << endl;
    return 0;
}

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (i < k - 1) {
            continue;
        }
        cnt += sum >= threshold * k;
        sum -= arr[i - k + 1];
    }

    return cnt;
}

vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res(n, -1);
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        s += nums[i];
        if (i < k * 2) {
            continue;
        }
        res[i - k] = s / (2 * k + 1);
        s -= nums[i - k * 2];
    }
    return res;
}

long long maxSum(vector<int>& nums, int m, int k) {
    long long res = 0;
    long long s = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); ++i) {
        s += nums[i];
        cnt[nums[i]]++;
        int left = i - k + 1;
        if (left < 0) {
            continue;
        }
        if (cnt.size() >= m) {
            res = max(res, s);
        }
        int out = nums[left];
        s -= out;
        if (--cnt[out] == 0) {
            cnt.erase(out);
        }
    }
    return res;
}

long long maximumSubarraySum(vector<int>& nums, int k) {
    long long res = 0;
    long long sum = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        cnt[nums[i]]++;

        int left = i - k + 1;
        if (left < 0) {
            continue;
        }
        if (cnt.size() == k) {
            res = max(res, sum);
        }

        int out = nums[left];
        sum -= out;
        if (--cnt[out] == 0) {
            cnt.erase(out);
        }
    }
    return res;
}