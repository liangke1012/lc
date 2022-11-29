//
// Created by liangke on 2022/11/29.
//
#include <iostream>
#include "treeNode.h"
#include "vector"
#include "queue"
using namespace std;
bool hasPathSum(TreeNode* root, int targetSum);
bool traversal(TreeNode *node, int count);
void getPathSum(TreeNode* cur,int count);
/**
 * leetcode 112 : 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和
targetSum 。如果存在，返回 true ；否则，返回 false 。
 * @param root
 * @param targetSum
 * @return
 */
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL) return false;
    return traversal(root,targetSum - root->val);
}

bool traversal(TreeNode *node, int count) {
    if(!node->left && !node->right && count == 0) return true;
    if(!node->left && !node->right) return false;
    if(node->left){
        count -= node->left->val;
        if(traversal(node->left,count)) return true;
        count +=node->left->val;
    }
    if(node->right){
        count -= node->right->val;
        if(traversal(node->right,count)) return true;
        count +=node->right->val;
    }

    return false;
}
/**
 * leetcode 113 : 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * @param root
 * @param targetSum
 * @return
 */
vector<vector<int>> result;
vector<int> path;
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    if(root == NULL) return result;
    path.push_back(root->val);
    getPathSum(root,targetSum - root->val);
    return result;
}
void getPathSum(TreeNode* cur,int count){
    if(!cur->left && !cur->right && count == 0){
        result.push_back(path);
        return;
    }
    if(!cur->left && !cur->right)return;
    if(cur->left){
        path.push_back(cur->left->val);
        count -= cur->left->val;
        getPathSum(cur->left,count);
        count += cur->left->val;
        path.pop_back();
    }
    if(cur->right){
        path.push_back(cur->right->val);
        count -= cur->right->val;
        getPathSum(cur->right,count);
        count += cur->right->val;
        path.pop_back();
    }
    return;

}