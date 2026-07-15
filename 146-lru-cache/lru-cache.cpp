// key rule is that , if we use any node we have to put it to the front

class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
        }
    };
    
    Node* head = new Node(-1, -1); // intializing
    Node* tail = new Node(-1, -1); // intializing
    int cap;

    unordered_map<int, Node*> mpp;


    LRUCache(int capacity) {
      cap=capacity;
      
      head->next=tail;
      tail->prev=head; 
    }

    void addNewNode(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
    }
    
    void deleteNode(Node* node){
        Node* prevv=node->prev;
        Node* nextt=node->next;

        prevv->next=nextt;
        nextt->prev=prevv;
    }

    int get(int key) {
        if(mpp.find(key)!=mpp.end()){// if we found the key in the map we will take the value of it and return , and then make it the leatest enterd node in ll
            Node* resNode=mpp[key];// when we delete the node , and add it to the new place,at the start, at that time we have to also store the new position of the node in the mapp, so thats why we we delete it form the mapp also
            int res=resNode->val;
            mpp.erase(key);
            deleteNode(resNode);//delet from the end and i will add to the frontside , latest side
            addNewNode(resNode);
            mpp[key]=head->next;//after the addnode func, we will have our node at the next of the head, 
            return res; 


        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
                Node* node=mpp[key];
                node->val=value;
                mpp.erase(key);
                deleteNode(node);
                addNewNode(node);
                mpp[key]=head->next;

        }else{// if it is not in the mapp

            if(mpp.size()==cap){
                // we have to delete the least reccnet element
                Node* node=tail->prev;
                int key=node->key;
                mpp.erase(key);
                deleteNode(node);

            }
            Node* newNode=new Node(key,value);
                mpp[key]=newNode;// adding it to the hashmap
                // adding it in ll
                addNewNode(newNode);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */