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
public:// imaginne tge level , and the last node of  that level will be the right view of bt, so we will travrse with preorder and first travel right nd then left, becz the we will traverse the last most node.
    
    void helper(TreeNode* root, int level,vector<int> &res){
        if(root==NULL){
            return;
        }

        if(res.size()==level){
            res.push_back(root->val);
        }
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);


    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
    }
};