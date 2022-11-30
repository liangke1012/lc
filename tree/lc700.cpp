//
// Created by liangke on 2022/11/30.
//
#include <iostream>
#include "treeNode.h"
#include "vector"
using namespace std;
class Solution{
private:
    int count;
    int maxCount;
    TreeNode* pre;
    vector<int> result;
    void searchBST(TreeNode* root){
        if(root == NULL) return;
        searchBST(root->left);

        if(pre == NULL){
            count = 1;
        }else if(pre->val == root->val){
            count++;
        }else{
            count = 1;
        }
        pre = root;
        if(count == maxCount){
            result.push_back(root->val);
        }
        if(count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(root->val);
        }
        searchBST(root->right);
        return;
    }

public:
    /**
 * 给定二叉搜索树（BST）的根节点
 root 和一个整数值
 val。
 * @param root
 * @param val
 * @return
 */
    TreeNode* searchBST(TreeNode* root, int val){
        if(root == NULL || root->val == val) return root;
        if(root->val > val) return searchBST(root->left,val);
        if(root->val < val) return searchBST(root->right,val);
        return NULL;
    }
    /**
 * leetcode : 501
 * @param root
 * @return
 */
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = NULL;
        result.clear();

        searchBST(root);
        return result;
    }

    /**
     * leetcode 236:给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left != NULL && right != NULL) return root;

        if(left == NULL && right != NULL){
            return right;
        }else if(left != NULL && right == NULL){
            return left;
        }else{
            return NULL;
        }
    }
/**
 * leetcode 450:给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节
 * @param root
 * @param key
 * @return
 */
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key){
            //root 为空，代表未搜索到值为 key的节点，返回空。
            if(!root->left && !root->right){
                return NULL;
            }
            if(!root->right){
                return root->left;
            }
            if(!root->left){
                return root->right;
            }
            //root 有左右子树，这时可以将 root的后继节点（比 root大的最小节点，即它的右子树中的最小节点，记为 successor）作为新的根节点替代 root，
            // 并将 successor 从 root 的右子树中删除，使得在保持有序性的情况下合并左右子树。
           TreeNode* successor = root->right;
            while (successor->left){
                successor = successor->left;
            }
            root->right = deleteNode(root->right,successor->val);
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
/**
 * leetcode669:给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 不应该
 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
 *
 * @param root
 * @param low
 * @param high
 * @return
 */
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if(root == nullptr){
           return nullptr;
       }
       if(root->val < low){
           return trimBST(root->right,low,high);
       }else if(root->val > high){
           return trimBST(root->left,low,high);
       }else{
           root->left = trimBST(root->left,low,high);
           root->right = trimBST(root->right,low,high);
           return root;
       }
    }

    TreeNode *ArrayToBST(vector<int> &nums, int left, int right) {
        if(left>right) return nullptr;
        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = ArrayToBST(nums,left,mid-1);
        root->right = ArrayToBST(nums,mid+1,right);
        return root;
    }

/**
 * leetcode108:给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
 * @param nums
 * @return
 */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       TreeNode* root = ArrayToBST(nums,0,nums.size()-1);
        return root;
    }
};


