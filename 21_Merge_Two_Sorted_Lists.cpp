// https://leetcode.com/problems/merge-two-sorted-lists/
// Contributed by: prackode

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* nullpt=NULL;
        if(!l1 && !l2)
            return nullpt;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* cur1=l1, *cur2=l2;
        ListNode* prev=NULL;
        ListNode* head=NULL;
        if(cur1->val <= cur2->val)
            head=cur1;
        else
            head=cur2;
        
        while(cur1 && cur2)
        {
            if(cur1->val<=cur2->val)
            {
                if(prev)
                {
                    prev->next=cur1;
                }
                prev=cur1;
                cur1=cur1->next;
            }
            else
            {
                if(prev)
                {
                    prev->next=cur2;
                }
                prev=cur2;
                cur2=cur2->next;
            }
        }
        
        while(cur2)
        {prev->next=cur2;
         cur2=cur2->next;
        prev=prev->next;}
        
        while(cur1)
        {prev->next=cur1;
         cur1=cur1->next;
        prev=prev->next;}
        
        return head;
    }
};
