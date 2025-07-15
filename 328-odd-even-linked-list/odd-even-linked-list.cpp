class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next) {
            return head;  
        }
        ListNode*odd=head;
        ListNode*even=odd->next;
        ListNode*evenhead=even;
        ListNode*oddhead=odd;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};