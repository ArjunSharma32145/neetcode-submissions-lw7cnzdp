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
    void getPath(TreeNode * node,int & x, vector<int> & arr,int & maxi){
        if(!node) return;
        arr.push_back(node->val);
        if(node->val >= maxi) x++;
        int oldmax = maxi;
        maxi = max(maxi,node->val);
        getPath(node->left,x,arr,maxi);
        getPath(node->right,x,arr,maxi);
        arr.pop_back();
        if(maxi == node->val) maxi = oldmax;
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        int x = 0;
        int maxi = INT_MIN;
        vector<int> arr;
        getPath(root,x,arr,maxi);
        return x;
    }

};
