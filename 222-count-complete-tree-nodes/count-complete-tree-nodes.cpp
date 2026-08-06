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
class Solution {// intution is, if both side have the same height then we can use formula (2 to the power height)-1, bbut if heigth is not equal, we will go to their child nd then againn check for the same hight form boh side , we do this becz we dont want to travrese the entire tree, tc=logn square
public:

    int findHeightL(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;

    }

    int findHeightR(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;

    }


    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int lh=findHeightL(root);
        int rh=findHeightR(root);

        // if bothh are equal at any level of recursion 

        if(lh==rh){
            return (1<<lh)-1;// 2 to the power lh and -1 from it
        }

     // if not then we will go to the left and right and perform the same oopreations , recursively


        return 1+countNodes(root->left)+countNodes(root->right);

    }

};