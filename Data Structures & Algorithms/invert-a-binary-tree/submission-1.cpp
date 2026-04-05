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
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
private :
  TreeNode* invert(TreeNode * node){
    if(!node) return nullptr; // logic of swap same man
    TreeNode * temp =node->left;
    node->left = invert(node->right);
    node->right = invert(temp);
    return node;
  }
};
