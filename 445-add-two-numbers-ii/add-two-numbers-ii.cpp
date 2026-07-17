/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        ListNode* dummy=new ListNode(-1);

    ListNode* temp1=l1;
    ListNode* temp2=l2;

    while(temp1!=NULL){
        s1.push(temp1->val);
        temp1=temp1->next;
    }

    while(temp2!=NULL){
        s2.push(temp2->val);
        temp2=temp2->next;
    }

    int crry=0;

    while(!s1.empty() && !s2.empty()){
        int digit1=s1.top();
        int digit2=s2.top();
        s1.pop();
        s2.pop();

        int sum=digit1+digit2+crry;

        crry=sum/10;

        int toBePlaced=sum%10;

        ListNode* newNode=new ListNode(toBePlaced);

        if(dummy->next==NULL){
            dummy->next=newNode;
            newNode->next=NULL;
        }else{
                ListNode* tempo=dummy->next;
                dummy->next=newNode;
                newNode->next=tempo;
        }
    }

    while(!s1.empty()){
        int digit1=s1.top();
        s1.pop();

        int sum=digit1+crry;

        crry=sum/10;

        int toBePlaced=sum%10;

        ListNode* newNode=new ListNode(toBePlaced);

        if(dummy->next==NULL){
            dummy->next=newNode;
            newNode->next=NULL;
        }else{
                ListNode* tempo=dummy->next;
                dummy->next=newNode;
                newNode->next=tempo;
        }

    }

     while(!s2.empty()){
        int digit1=s2.top();
        s2.pop();

        int sum=digit1+crry;

        crry=sum/10;

        int toBePlaced=sum%10;

        ListNode* newNode= new ListNode(toBePlaced);

        if(dummy->next==NULL){
            dummy->next=newNode;
            newNode->next=NULL;
        }else{
                ListNode* tempo=dummy->next;
                dummy->next=newNode;
                newNode->next=tempo;
        }

    }

        if(crry){
             ListNode* newNode= new ListNode(crry);

        if(dummy->next==NULL){
            dummy->next=newNode;
            newNode->next=NULL;
        }else{
                ListNode* tempo=dummy->next;
                dummy->next=newNode;
                newNode->next=tempo;
        }
        }

        return dummy->next;

    }
};