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
class Solution {// recursion
public:
    int cnt=0;

    void helper(TreeNode* root, int targetSum,long long sum){
         if(root==NULL){
            return;
         }

         sum+=root->val;
         
         if(sum==targetSum){
            cnt++;
           }

            helper(root->left,targetSum,sum);
            helper(root->right,targetSum,sum);

    }

    void travrse(TreeNode* root,int targetSum){
         if(root==NULL){
            return;
         }
         
         // tryin out the first root main idea is to try out all the nodes, so we can find out itt for evry node
        helper(root,targetSum,0);


        // we will also try the left and right subtree
        travrse(root->left,targetSum);
        travrse(root->right,targetSum);
    }

    
    int pathSum(TreeNode* root, int targetSum) {
        
       
travrse(root,targetSum);

        return cnt;
    }
};