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
    vector<vector<int>> finalAns;

    void helper(TreeNode* root,int targetSum,int sum,vector<int>preAns){
        if(root==NULL){
            return;
        }

        preAns.push_back(root->val);
        sum+=root->val;

        if(root->left==NULL && root->right==NULL){// if leaf node
            if(sum==targetSum){
                finalAns.push_back(preAns);
            }
        }

        helper(root->left,targetSum,sum,preAns);
        helper(root->right,targetSum,sum ,preAns);

      
    }
    


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> preAns;
        int sum=0;
        helper(root,targetSum,sum,preAns);

        return finalAns;
    }
};