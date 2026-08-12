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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(r1==NULL) return r2;
        if(r2==NULL) return r1;// if the root1 one not exist we will return the root2 so the tree can have the all node 

        TreeNode* newR=new TreeNode(r1->val+r2->val);

        newR->left=  mergeTrees(r1->left,r2->left);
       newR->right= mergeTrees(r1->right,r2->right);

        return newR;
    }
};