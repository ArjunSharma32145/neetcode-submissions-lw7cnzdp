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
    void getPath(TreeNode * node,int & x, vector<int> & arr){
        if(!node) return;
        int check = INT_MIN;
        if(arr.size()) check = *max_element(arr.begin(),arr.end());
        arr.push_back(node->val);
        if(node->val >= check) x++;
        getPath(node->left,x,arr);
        getPath(node->right,x,arr);
        arr.pop_back();
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        int x = 0;
        vector<int> arr;
        getPath(root,x,arr);
        return x;
    }

};
