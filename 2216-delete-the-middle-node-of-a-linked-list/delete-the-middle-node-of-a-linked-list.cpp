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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;

        fast=head->next->next;// we are skiping the step or the tuen of the slow pointer becz we want that slow end up being stop at just exactly one step before the middle node , intution from the finding out the middle node


        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // so now the slow pointer will pointes to the just before the middle node

     

        slow->next=slow->next->next;
        

        return head;
    }
};