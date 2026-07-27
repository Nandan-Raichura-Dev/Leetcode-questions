class Node{
    public:
    Node* prev;
    Node* next;
    string url;

    Node(string url){
        this->url=url;
        prev=NULL;
        next=NULL;
    }
};

class BrowserHistory {
public:

    Node* curr;
    

    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=newNode;
    }
    
    string back(int steps) {
        while(steps>0 && curr->prev!=NULL){
            curr=curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps>0 && curr->next!=NULL){
            curr=curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */