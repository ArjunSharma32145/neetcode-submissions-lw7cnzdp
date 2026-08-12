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
    int ans =0;
    void func(TreeNode * node,int count){
        if(!node) return;
        ans = max(ans,count);
        func(node->left,count+1);
        func(node->right,count+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        func(root,1);
       return ans;
    }
};
