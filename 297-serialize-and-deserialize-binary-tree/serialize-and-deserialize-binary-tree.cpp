/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string s="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node==NULL){
                s.append("#,");
            }else{
                s.append(to_string(node->val)+',');
            }

            if(node!=NULL){
                q.push(node->left);// we will push the node even if it is child becz ewe want to add the # in the place of thhe null point connnectd
                q.push(node->right);
            }

        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }

        stringstream s(data);// to travrser in the string

        string str;

        getline(s,str,',');

        // make root of the first element(fixed)

        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        // whenever we will add the new node in bt, we will also add it inn the q, so we can check for its left and right child

        while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        // we will take its left chhild(is the child is not null)

        getline(s,str,',');
        if(str=="#"){// left child is null
            node->left=NULL;
        }else{
            TreeNode* newNode=new TreeNode(stoi(str));
            node->left=newNode;
            q.push(newNode);
        }

        // for right child

        getline(s,str,',');

        if(str=="#"){
            node->right=NULL;
        }else{

            TreeNode* newNode=new TreeNode(stoi(str));
            node->right=newNode;
            q.push(newNode);
        }

        
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));