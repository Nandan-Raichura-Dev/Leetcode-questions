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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int s=q.size();
        vector<int> temp;
            for(int i=0;i<s;i++){
                TreeNode* currNode=q.front();
             
                q.pop();
                temp.push_back(currNode->val);

                if(currNode->left){
                    q.push(currNode->left);
                }

                if(currNode->right){
                    q.push(currNode->right);    
                     }
            }

            ans.push_back(temp);



        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};