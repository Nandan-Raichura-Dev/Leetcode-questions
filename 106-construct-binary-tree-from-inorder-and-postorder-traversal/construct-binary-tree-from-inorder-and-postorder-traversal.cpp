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
    
    TreeNode* helper(vector<int>& inorder,int inStart,int inEnd, vector<int>& postorder,int preStart,int preEnd,map<int,int> &mpp){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;// connnect last nodes leaf node with the tree and the leaf node to null

        }

        TreeNode* root=new TreeNode(postorder[preEnd]);

        int inRoot=mpp[postorder[preEnd]];// findin thhat root in the inorder traversal
        int numsLeft=inRoot-inStart;

        // calloing samme funnc for the left nd right subtree

        root->left=helper(inorder,inStart,inRoot-1,postorder,preStart,preStart+numsLeft-1,mpp);

        root->right=helper(inorder,inRoot+1,inEnd,postorder,preStart+numsLeft,preEnd-1,mpp);

        return root;

    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int> mpp;

        for(int i=0;i<inorder.size();i++){// for fast acces of the element in the inorder
            mpp[inorder[i]]=i;
        }

        TreeNode* root= helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        
        return root;
    }
};