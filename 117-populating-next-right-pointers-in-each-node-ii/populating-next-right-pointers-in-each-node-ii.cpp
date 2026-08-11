/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //we will mantain the prev poniter so we can connnect that node with our currrnt one

        queue<Node*> q;
        q.push(root);
        q.push(NULL);// it marks the end of the one level in the bt

        Node* prev=NULL;
        if(root == NULL){
        return NULL;
         }
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            if(curr==NULL){// the curr cam be the null or the it contains node

            if(q.size()==0){
                break;
            }

            q.push(NULL);// to mark the end o f the another lvel

            }else{

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
               
            }

             if(prev!=NULL){
                prev->next=curr;
                }


            prev=curr;
        }
        return root;
    }
};