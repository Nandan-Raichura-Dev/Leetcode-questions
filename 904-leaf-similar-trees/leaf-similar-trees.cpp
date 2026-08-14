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
    vector<int> ans1;
    vector<int> ans2;

    void helper1(TreeNode* root){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            ans1.push_back(root->val);
        }

        helper1(root->left);
        helper1(root->right);


    }

     void helper2(TreeNode* root){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            ans2.push_back(root->val);
        }

        helper2(root->left);
        helper2(root->right);


    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        helper1(root1);
        helper2(root2);

        if(ans1.size()!=ans2.size()){
            return false;
        }

        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i]){
                return false;
            }
        }


        return true;

        
    }
};