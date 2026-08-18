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
class Solution {// inorder trav is always sorted
public:

    int count=0;
    int res=-1;
    void helper(TreeNode* root,int k){
        if(root==NULL || count>k){
            return;
        }


        helper(root->left,k);

        count++;
        if(count==k){
           res=root->val;

        }

        helper(root->right,k);
    
        
    }

    int kthSmallest(TreeNode* root, int k) {
       int count=0;
      helper(root,k);

      return res;


    }
};