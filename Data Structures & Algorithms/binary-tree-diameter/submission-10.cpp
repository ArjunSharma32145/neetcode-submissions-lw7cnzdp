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
        if(!node) return 0;
        int ls = path(node->left,ans);
        int rs = path(node->right,ans);
        ans = max(ans,ls + rs );
        return 1 + max(ls,rs);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        path(root,ans);
        return ans;
    }
};
