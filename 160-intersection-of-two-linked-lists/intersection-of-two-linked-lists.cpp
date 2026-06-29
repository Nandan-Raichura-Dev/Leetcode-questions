/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL || headB==NULL){
            return NULL;
        }// is the ll is empty

        
        ListNode* t1=headA;
        ListNode* t2=headB;

        while(t1!=t2){// we will move the t1 and t2 simultensly until they reach(both at same time) to the null(when the linkded list is not innterconnected ) also it get stops when the t1 and t2 combines , point of interscation

        t1=t1->next;
        t2=t2->next;

        if(t1==t2)
            return t1;// primarty check , it manages every thing

        if(t1==NULL){// to cover the distance bettween the another t, we will place it at tthe head2 so they botth got  the simulatnus point to travell along ll
            t1=headB;
        }
        if(t2==NULL){
            t2=headA;
        }
        }

        

        // if the t1 or 12 gets reached to NULL,end pf the linled list, and they still dont find the intresection we will return null orr t1

        return t1;

       
    }
};