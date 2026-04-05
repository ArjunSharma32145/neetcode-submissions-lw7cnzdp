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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> result;
        vector<int> result1;
        cmp(p,result);
        cmp(q,result1);
      return result == result1;
    }
private:
  void  cmp(TreeNode* node,vector<int> & res){
        if(!node){
        res.push_back(INT_MIN);
         return ;}
        res.push_back(node->val);
        cmp(node->left,res);
        cmp(node->right,res);
    }
};
