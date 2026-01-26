/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MiddleNode(ListNode head) {
        ListNode sl=head;
        ListNode fs=head;
        while(fs!=null && fs.next!=null)
        {
            sl=sl.next;
            fs=fs.next.next;
        }
        return sl;
    }
}