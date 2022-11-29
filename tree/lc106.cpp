//
// Created by liangke on 2022/11/29.
//
#include <iostream>
#include "treeNode.h"
#include "vector"
#include "queue"
using namespace std;
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

TreeNode *traversal(vector<int> &inorder, int inorderbegin, int inorderend, vector<int> &postorder, int postorderbegin, int postorderend);

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() ==0 || postorder.size()==0) return NULL;
    return traversal(inorder,0,inorder.size(),postorder,0,postorder.size());
}

TreeNode *traversal(vector<int> &inorder, int inorderbegin, int inorderend, vector<int> &postorder, int postorderbegin, int postorderend) {
    if(postorderbegin == postorderend) return NULL;
    int rootValue = postorder[postorderend - 1];
    TreeNode* root = new TreeNode(rootValue);

    if(postorderend - postorderbegin == 1) return root;

    int index;
    for(index = inorderbegin; index < inorderend; index++) {
        if (inorder[index] == rootValue) {
            break;
        }
    }
    int left_inorder_begin  = inorderbegin;
    int left_inorder_end = inorderbegin + index;
    int right_inorder_begin = index + 1;
    int right_inorder_end = inorderend;

    int left_postorder_begin = postorderbegin;
    int left_postorder_end = postorderbegin + index - inorderbegin;
    int right_postorder_begin = postorderbegin + index - inorderbegin;
    int right_postorder_end = postorderend - 1;

    root->left = traversal(inorder,left_inorder_begin,left_inorder_end,postorder,left_postorder_begin,left_postorder_end);
    root->right = traversal(inorder,right_inorder_begin,right_inorder_end,postorder,right_postorder_begin,right_postorder_end);
    return root;
}
