/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  int height(TreeNode * node){
    if(node == NULL) return 0;
    int left = height(node->left);
    int right = height(node->right);
    return 1 + max(left,right);
  }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = height(root->left);
        int right= height(root->right);
        if(abs(left-right) > 1) return false;
        int checkl = isBalanced(root->left);
        int checkr = isBalanced(root->right);
        return checkl && checkr; 
    }
};
