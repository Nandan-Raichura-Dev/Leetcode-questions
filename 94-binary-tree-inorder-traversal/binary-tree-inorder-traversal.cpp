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
public:// moris trversal
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr!=NULL){
           
            if(curr->left==NULL){// node its self is  the root
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{// if left subtree exist

            // we will go to the left most guy of the lleft subtree and make tem link too curr

            TreeNode* prev=curr->left;
            while( prev->right && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){// link is not created, we have to create
                prev->right=curr;
                curr=curr->left;
            }else{// the link is always being created

                prev->right=NULL;
                ans.push_back(curr->val);// it is root 
                curr=curr->right;
                }

            }



        }

        return ans;
    }
};