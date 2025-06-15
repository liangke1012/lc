//
// Created by liangke on 2022/11/27.
//

#ifndef LC_TREENODE_H
#define LC_TREENODE_H
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif //LC_TREENODE_H
