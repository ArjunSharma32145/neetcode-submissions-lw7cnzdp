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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderr;
        inorder(root,inorderr);
        return inorderr[k-1];
    }
    void inorder(TreeNode * node,vector<int> & lol){
        if(node == NULL) return;
        inorder(node->left,lol);
        lol.push_back(node->val);
        inorder(node->right,lol);
    }
};
