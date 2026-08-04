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
class Solution {// here col means the vertical , and the row means the levels, each level,  imagine in the form of the x axis y axis graph or in the form of  the matrix with col as verticel and row as the level stored
 
 // multiset stores the element and mantian sorted and also handels for the dups
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;// to store vertices and the nodes at that level, we use multiset so we can store multiple nodes form the mutltiple levles 

        queue<pair<TreeNode*,pair<int,int>>> q;  // to store the node,vertices,level

        q.push({root,{0,0}});

        while(!q.empty()){// here lvel = row, and vertices=col
            TreeNode* node=q.front().first;
            int level=q.front().second.first;
            int vertices=q.front().second.second;

            q.pop();

            mpp[vertices][level].insert(node->val);

            if(node->left){
                q.push({node->left,{level+1,vertices-1}});
            }
            if(node->right){
                q.push({node->right,{level+1,vertices+1}});
            }

           

           
            
        }

          vector<vector<int>> result;

         for(auto& element:mpp){// already sorted by the vertices
             vector<int> values;
            // inner map already sorted by row, multiset already sorted by value

            for(auto& el:element.second){// for every level there will be node

            for(auto& val:el.second){
                    values.push_back(val);
            }

            }
             result.push_back(values);
            }

            return result;
    }
};