//
// Created by liangke on 2022/11/27.
//

#ifndef LC_TREENODE_H
#define LC_TREENODE_H
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr);
};
#endif //LC_TREENODE_H
