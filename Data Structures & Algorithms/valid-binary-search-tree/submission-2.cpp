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
    void inorder(TreeNode * node,vector<int> & inord){
        if(!node) return ;
        inorder(node->left,inord);
        inord.push_back(node->val);
        inorder(node->right,inord);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        for(int i=1;i<arr.size();i++){
            if(arr[i] <= arr[i-1]) return false;
        }
        return true;

    }   
};
