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
    TreeNode * build(vector<int> & preorder,int prestart,int preend,vector<int> & inorder,int instart,int inend,unordered_map<int,int> & mpp){
        if(prestart > preend || instart > inend) return nullptr;
        TreeNode * root =  new TreeNode(preorder[prestart]);
        int index = mpp[preorder[prestart]];
        int numsleft = index - instart;
         root->left = build(preorder,prestart+1,prestart+numsleft,inorder,instart,index-1,mpp);
         root->right = build(preorder,prestart+numsleft+1,preend,inorder,index+1,inend,mpp);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int, int> mpp;
      int insize = inorder.size();
      int presize = preorder.size();
      for(int i=0;i<insize;i++){
        mpp[inorder[i]] = i;
      }  
       TreeNode * root = build(preorder,0,presize-1,inorder,0,insize-1,mpp);
       return root;
    }
    
};
