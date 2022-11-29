//
// Created by liangke on 2022/11/28.
//
#include <iostream>
#include "treeNode.h"
#include "vector"
#include "queue"
using namespace std;

TreeNode* invertTree(TreeNode* root);
bool isSymmetric(TreeNode* root);
int maxDepth(TreeNode* root);
bool compare(TreeNode *left, TreeNode *right);
bool isBalanced(TreeNode* root);
int getDepth(TreeNode *node);
vector<string> binaryTreePaths(TreeNode* root);
int getBalanceDepth(TreeNode *node);
void traversal(TreeNode *node, vector<int> path, vector<string> result);
bool hasPathSum(TreeNode* root, int targetSum);
TreeNode* invertTree(TreeNode* root) {
    if(root ==NULL) return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
/**
 * leetcode 101 : 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * @param root
 * @return
 */
bool isSymmetric(TreeNode* root){
    if(root ==NULL) return true;
    return compare(root->left,root->right);
}

bool compare(TreeNode *left, TreeNode *right) {
    if(left!=NULL && right==NULL) return false;
    else if(left == NULL && right != NULL) return false;
    else if(left == NULL && right == NULL) return tree;
    else if(left->val != right->val) return false;
    bool outside = compare(left->left,right->right);
    bool inside = compare(left->right,right->left);
    bool issame = outside && inside;
    return issame;
}
/**
 * leetcode104:
 * @param root
 * @return
 */
int maxDepth(TreeNode* root){
    return getDepth(root);
}

int getDepth(TreeNode *node) {
    if(node == NULL) return 0;
    int leftDepth = getDepth(node->left);
    int rightDepth = getDepth(node->right);
    int depth = 1 + max(leftDepth,rightDepth);
    return depth;
}
/**
 * leeetcode 110:给定一个二叉树，判断它是否是高度平衡的二叉树。
 * @param root
 * @return
 */
bool isBalanced(TreeNode* root){
    return getBalanceDepth(root) == -1 ? false: true;
}

int getBalanceDepth(TreeNode *node) {
    if(node == NULL) return 0;
    int leftDepth = getBalanceDepth(node->left);
    if(leftDepth == -1) return -1;
    int rightDepth = getBalanceDepth(node->right);
    if(rightDepth == -1) return -1;
    return abs(leftDepth - rightDepth) > 1? -1 :1 + max(leftDepth,rightDepth);

}
/**
 * leetcode 257:
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 叶子节点 是指没有子节点的节点。
 * @param root
 * @return
 */
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    vector<int> path;
    if(root == NULL) return res;
    traversal(root,path,res);
    return res;
}
void traversal(TreeNode *node, vector<int>& path, vector<string>& result) {
      path.push_back(node->val);
      if(node->left == NULL && node->right ==NULL){
          string sPath;
          for(int i =0;i<path.size()-1;i++){
              sPath += to_string(path[i]);
              sPath += "->";
          }
          sPath += to_string(path[path.size()-1]);
          result.push_back(sPath);
      }
      if(node->left){
          traversal(node->left,path,result);
          path.pop_back();
      }
      if(node->right){
          traversal(node->right,path,result);
          path.pop_back();
      }
}

