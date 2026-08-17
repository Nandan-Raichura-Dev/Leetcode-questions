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
      TreeNode* searchBst(TreeNode* root,int vall){
            if(root==NULL){
                
                 return NULL;

            }

            if(root->val==vall){
               return root;
            }

            if(root->val<vall){
                return searchBst(root->right,vall);
            }
            if(root->val>vall){
                return searchBst(root->left,vall);
            }
            return root;

        }

    TreeNode* searchBST(TreeNode* root, int vall) {
        
       return searchBst(root,vall);
    }
};