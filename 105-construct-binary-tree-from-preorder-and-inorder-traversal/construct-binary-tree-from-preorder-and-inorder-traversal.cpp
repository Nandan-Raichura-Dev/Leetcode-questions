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
    TreeNode* devlopeTree(vector<int> &preorder,vector<int> &inorder,int &preIdx,int left,int right,map<int,int> &mpp){
        if(left>right){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[preIdx]);
        

        int idx=mpp[preorder[preIdx]];
        preIdx++;
        
        
        root->left=devlopeTree(preorder,inorder,preIdx,left,idx-1,mpp);// lrft part
        root->right=devlopeTree(preorder,inorder,preIdx,idx+1,right,mpp);// lrft part




        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;// to store the index of the inorder 
        int preIdx=0;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root=devlopeTree(preorder,inorder,preIdx,0,inorder.size()-1,mpp);

        return root;
    }
};