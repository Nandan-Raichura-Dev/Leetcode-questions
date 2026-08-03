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
public:// same concept as we used for the checking the height of the bt


   int bbt(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lHeight=bbt(root->left);
        if(lHeight==-1){
            return -1;// even if any one node gives use -1 ,wew ill return it -1 from there and there only
        }


        int rHeight=bbt(root->right);
        if(rHeight==-1){
            return -1;
        }

        if(abs(lHeight-rHeight)>1){
            return -1;
        }
        return 1+max(lHeight,rHeight);

    }

    bool isBalanced(TreeNode* root) {
        return bbt(root)!=-1;
    }
};