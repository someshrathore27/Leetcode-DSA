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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        k=k%cnt;
        if(k==cnt || k==0)
        {
            return head;
        }
        temp=head;
        ListNode* end=head;
        while(end->next!=NULL)
        {
            end=end->next;
        }
        int t=cnt-k;
        while(t!=1)
        {
            temp=temp->next;
            t--;
        }
        ListNode* currh=temp->next;
        temp->next=NULL;
        end->next=head;
        head=currh;
        return head;
    }
};