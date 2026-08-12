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
vector<vector<int>> ans;
   void findNum(TreeNode* root, vector<int> num){
        if(root==NULL){
            return;
        }

        num.push_back(root->val);
        if(root->left==NULL && root->right==NULL){// leaf node
            // we will puch the entier path num in the ans
            ans.push_back(num);

        }

        findNum(root->left,num);
        findNum(root->right,num);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> num;
        findNum(root,num);


        int sumNum=0;
        for(int i=0;i<ans.size();i++){
            int number=0;
            for(int j=0;j<ans[i].size();j++){
                number=(number*10)+ans[i][j];

            }
            sumNum+=number;
        }

        return sumNum;
    }
};