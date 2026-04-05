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
    int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxpath(root,ans);
    return ans;
    }
private: 
 int maxpath(TreeNode * node,int & lol){
    if(!node) return 0;
    int lsum = max(0,maxpath(node->left,lol));
    int rsum = max(0,maxpath(node->right,lol));
     lol = max(lol,node->val +lsum +rsum);
     return node->val + max(lsum,rsum);
 }
};
