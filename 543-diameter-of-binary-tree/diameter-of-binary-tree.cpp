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

    int findDia(TreeNode* root,int &dia){
        if(root==NULL){
            return 0;
        }

        int lHeight=findDia(root->left,dia);
        int rHeight=findDia(root->right,dia);

        dia=max(dia,lHeight+rHeight);

        return 1+max(lHeight,rHeight);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        findDia(root,dia);
        return dia;
    }
};