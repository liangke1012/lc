//
// Created by liang on 2025/7/19.
// 1233. 删除子文件夹
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> removeSubfolders(vector<string>& folder);

int main() {
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> res = removeSubfolders(folder);
    for (auto a : res) {
        cout << a << endl;
    }
    return 0;
}

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> res = {folder[0]};
    for (int i = 1; i <folder.size(); i++) {
        int pre = res.end()[-1].size();
        if (!(pre < folder[i].size() && res.end()[-1] == folder[i].substr(0, pre) && folder[i][pre] == '/')) {
            res.push_back(folder[i]);
        }
    }
    return res;
}