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
  int edgheight(TreeNode * node){
    if(node == NULL) return 0;
    int lh = edgheight(node->left);
    int rh = edgheight(node->right);
    if(!node->left && !node->right) return 0;
    return 1 + max(lh,rh);
  }
  void dia(TreeNode * node,int & ans){
    if(node == NULL) return;
    int left = edgheight(node->left);
    int right = edgheight(node->right);
    int curans = 0;
    if(node->left !=0 && node->right != 0) curans  = left+right+2;
    else if(node->left ||node->right) curans = left+right+1;
    else curans = left+right;
    ans = max(ans,curans);
    dia(node->left,ans);
    dia(node->right,ans);
  }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dia(root,ans);
        return ans;
    }
};
