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
public:
     int path(TreeNode * node, int & ans){
        if(!node) return 0 ;
        int ls = max(0,path(node->left,ans));
        int rs = max(0,path(node->right,ans));
        ans = max(ans,ls + node->val + rs);
        return node->val + max(ls,rs);
     }
    int maxPathSum(TreeNode* root) {
  // agar kisi side mein mujhe dikh ra ki negative sum aa rha mein literally wo path lunga hi nhi simple 
  if(!root) return 0;
  int ans = root->val;
      path(root,ans);
      return ans;
    }
};
