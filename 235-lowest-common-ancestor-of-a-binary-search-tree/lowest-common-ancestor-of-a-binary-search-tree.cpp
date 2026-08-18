/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){// if we do not have option to go right or left we will just return the root becz the path is perated which means one nod is oj right and one is on the left
            return NULL;
        }

        int curr=root->val;

        if(p->val<curr && q->val<curr){// we will find it on the left side
         return lowestCommonAncestor(root->left,p,q);
        }

        if(p->val>curr && q->val>curr){// we will go the right
       return lowestCommonAncestor(root->right,p,q);
        }

        // no option left to go we will just return the root 

        return root;
    }
};