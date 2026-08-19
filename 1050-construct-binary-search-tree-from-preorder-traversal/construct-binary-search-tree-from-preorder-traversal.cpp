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
class Solution {// approch 1 is to sort the preorder traversal and then we get the inorder so we can make unique tree form it

// 2nd approch is to go preoder wiswe but also carray the upperbound upto which we can assing the noode to the subterees

public:

    TreeNode* helper(vector<int> &preorder,int &i,int bound){// we do not that bound remain fix ebca we want to take bound value as per the lvel of the recursion so thats why we do not pass it by refrence

    if(i==preorder.size() || preorder[i]>bound) return NULL;

    TreeNode* root=new TreeNode(preorder[i++]);

    root->left=helper(preorder,i,root->val);// we are going left side so we have to pass val of curr node as bound, becz left should be lesss then the parant node

    root->right=helper(preorder,i,bound);// right side needes the biger value the curr root it self, so bound stays the unchanged

    return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return  helper(preorder,i,INT_MAX);// at the start upperbound is as muchh as large value, 

    }
};