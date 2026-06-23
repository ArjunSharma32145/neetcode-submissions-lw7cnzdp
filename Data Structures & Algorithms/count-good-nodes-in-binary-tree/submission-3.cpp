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
    void solve(TreeNode * node,int & ans,vector<int> & arr){
        if(!node) return;
      int check = -101;
     if(arr.size()) check = *max_element(arr.begin(),arr.end());
     if(node->val >= check) ans++;
     arr.push_back(node->val);
     solve(node->left,ans,arr);
     solve(node->right,ans,arr);
     arr.pop_back();
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        vector<int> arr;
        solve(root,ans,arr);
        return ans;
    }
};
