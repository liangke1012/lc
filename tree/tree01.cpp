//
// Created by liangke on 2022/11/27.
//
#include <iostream>
/**
 * leetcode144:前序 遍历。
 */
#include "treeNode.h"
#include "vector"
#include "queue"
using namespace std;
vector<int> preorderTraversal(TreeNode* root);
//前序 遍历。
void traversal(TreeNode* cur,vector<int>& vec);
//中序遍历
void inordertraversal(TreeNode* cur,vector<int>& vec);
//leetcode102：层序遍历
vector<vector<int>> levelOrder(TreeNode* root);
int main(){

    return 0;
}

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    traversal(root,res);
    return res;
}
void traversal(TreeNode* cur,vector<int>& vec){
    if(cur == NULL) return;
    vec.push_back(cur->val);
    traversal(cur->left,vec);
    traversal(cur->right,vec);
}
vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    inordertraversal(root,res);
    return res;
}
void inordertraversal(TreeNode* cur,vector<int>& vec){
    if(cur == NULL) return;
    traversal(cur->left,vec);
    vec.push_back(cur->val);
    traversal(cur->right,vec);
}
vector<vector<int>> levelOrder(TreeNode* root) {
   queue<TreeNode*> que;
   if(root != NULL) que.push(root);
    vector<vector<int>> res;
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0;i<size;i++){
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);

        }
        res.push_back(vec);
    }
    return res;
}
