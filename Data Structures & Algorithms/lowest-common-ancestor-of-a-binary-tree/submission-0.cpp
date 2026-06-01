/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool getPath(TreeNode * node,vector<TreeNode *> & arr,TreeNode * target){
        if(!node) return false;
        arr.push_back(node);
        if(node == target){
            return true;
        }
        if(getPath(node->left,arr,target) || getPath(node->right,arr,target)) return true;
        arr.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path1;
        getPath(root,path1,p);
        vector<TreeNode *> path2;
        getPath(root,path2,q);
        TreeNode * baap;
        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i] == path2[i]) baap = path1[i];
            i++;
        }
        return baap;
    }
};