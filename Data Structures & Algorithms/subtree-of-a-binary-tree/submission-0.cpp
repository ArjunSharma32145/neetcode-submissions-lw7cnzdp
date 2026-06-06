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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return root == subRoot;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
          if(isSameTree(node,subRoot)) return true;
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);

       }
       return false;
    }
    bool isSameTree(TreeNode * p,TreeNode * q){
        if(p == NULL || q == NULL) return p == q;
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
