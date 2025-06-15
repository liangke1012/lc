//
// Created by liang on 2025/6/15.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <treeNode.h>
#include <queue>
#include <unordered_map>
using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* recur(int root, int left, int right);
vector<vector<int>> levelOrder(TreeNode* root); // 层序遍历二叉树
int maxDepth(TreeNode* root);  // 二叉树的 最大深度
vector<vector<int>> zigzagLevelOrder(TreeNode* root); // 二叉树锯齿形层序遍历
vector<vector<int>> levelOrderBottom(TreeNode* root); // 二叉树返回其节点值 自底向上的层序遍历
unordered_map<int, int> dic;
vector<int> pre;


int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    int depth = maxDepth(root);
    cout << "depth: " << depth << endl;
    cout << "preorder: ";
    vector<vector<int>> res = levelOrder(root);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << ";";
    }
    cout << endl << "zigzag order:";
    vector<vector<int>> res1 = zigzagLevelOrder(root);
    for (auto a : res1) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << ";";
    }

    cout << endl << "bottom order: ";
    vector<vector<int>> res2 = levelOrderBottom(root);
    for (auto a : res2) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << ";";
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

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool isLeft = true;
    while (!q.empty()) {
        deque<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();
            if (isLeft) {
                level.push_back(node->val);
            } else {
                level.push_front(node->val);
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        res.emplace_back(vector<int>{level.begin(), level.end()});
        isLeft = !isLeft;
    }
    return res;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto tmp = vector<int>();
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();
            tmp.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        res.emplace_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
}