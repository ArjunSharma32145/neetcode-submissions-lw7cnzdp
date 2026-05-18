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
    int path(TreeNode * node,int & ans){
        if(!node) return 0;
        int ls = max(0,path(node->left,ans));
        int rs = max(0,path(node->right,ans));
        ans = max(ans,ls+node->val+rs);
        return node->val + max(ls,rs);
    }
public:
    int maxPathSum(TreeNode* root) {
      if(!root) return 0;
      int ans = INT_MIN;
    path(root,ans);
    return ans;
    }
};
