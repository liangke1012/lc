//
// Created by liang on 2025/6/15.
//
#include <iostream>
#include <vector>
#include <treeNode.h>
#include <queue>
#include <unordered_map>
using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* recur(int root, int left, int right);
vector<vector<int>> levelOrder(TreeNode* root); // 层序遍历二叉树
unordered_map<int, int> dic;
vector<int> pre;


int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    vector<vector<int>> res = levelOrder(root);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    pre = preorder;
    for (int i = 0; i < preorder.size(); i++) {
        dic[inorder[i]] = i;
    }
    return recur(0, 0, inorder.size() - 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        res.push_back(vector<int>());
        for (int i = 1; i <= size; i++) {
            auto node = q.front();
            q.pop();
            res.back().push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    return res;
}

TreeNode* recur(int root, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    TreeNode* node = new TreeNode(pre[root]);
    int i = dic[pre[root]];
    node->left = recur(root + 1, left, i - 1);
    node->right = recur(root + i - left + 1, i + 1, right);
    return node;
}