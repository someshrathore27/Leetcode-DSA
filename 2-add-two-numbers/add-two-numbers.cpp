class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nh=new ListNode(0);
        ListNode* t=nh;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL)
        {
            int val1=(temp1!=NULL?temp1->val:0);
            int val2=(temp2!=NULL?temp2->val:0);
            int sum=val1+val2+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            t->next=temp;
            t=t->next;
            if(temp1!=NULL) temp1=temp1->next;
            if(temp2!=NULL) temp2=temp2->next;
        }
        if(carry>0)
        {
            ListNode* temp=new ListNode(carry);
            t->next=temp;
            t=t->next;
        }
        return nh->next;
    }
};