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

    long long fmin=LONG_MAX;
    long long smin=LONG_MAX;

    void helper(TreeNode* root){
        if(root==NULL){
            return;
        }


        if(root->val<fmin){
            fmin=root->val;
            
        }else if(root->val> fmin && root->val <smin){
            smin=root->val;
        }

        helper(root->left);
        helper(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        helper(root);

        if(smin==LONG_MAX) return -1;
        

        return smin;
        

        
        
    }
};