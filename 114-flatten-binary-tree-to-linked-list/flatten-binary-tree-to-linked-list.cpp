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
class Solution {// we will do reverse preorder traversal, so we can join the left subtree durectly with the preready left subtree
public:


    TreeNode* nextRight=NULL;// it will stores the pointer that will get connected with the next nodes, it will get update with every recursion call/stack

    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }

        // now doin the preorder traversal

        flatten(root->right);
        flatten(root->left);

        root->left=NULL;
        root->right=nextRight;

        nextRight=root;// this will store this root so next node in the recursion can be directly conncted with this node
        


    }
};