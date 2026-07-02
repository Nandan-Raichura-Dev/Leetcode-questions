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

    ListNode* reverseList(ListNode* head) {
        // recursive approch

        if(head==NULL || head->next==NULL){// last stage of the recursion base case
            return head;
        }

        ListNode* newHead=reverseList(head->next);// i will call for an next nodes , so they can solve the problem

        ListNode* front=head->next;// here head is the current head of the recursion level

        front->next=head;

        head->next=NULL;

        return newHead;// new head will remain same till last, becz we have only one head and after reverse it will come form the last recursion call
    }

    void reorderList(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        fast=fast->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        
        ListNode* middle=slow;
        ListNode* temp=middle->next;
        ListNode* temp2=middle->next;
        middle->next=NULL;
        
        

        temp2=reverseList(temp);
        ListNode* start=head;
        while(start!=NULL && temp2!=NULL){
           ListNode* t1=start->next;
           ListNode* t2=temp2->next;

           start->next=temp2;
           temp2->next=t1;

           start=t1;
           temp2=t2;

        }

        if(start){
            start->next=temp2;
        }

        
        

    }
};