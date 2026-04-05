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
    int diameterOfBinaryTree(TreeNode* root) {
       int ans=0;
       if(!root) return ans;
      diacalc(root,ans);
      return ans;
    }
private:
   int diacalc(TreeNode* node, int & diameter){
    if(!node) return 0;
    int lh =diacalc(node->left,diameter);
    int rh= diacalc(node->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
   }
};
