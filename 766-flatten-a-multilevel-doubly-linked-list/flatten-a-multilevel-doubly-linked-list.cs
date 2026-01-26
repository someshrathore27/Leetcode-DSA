/*
// Definition for a Node.
public class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
}
*/

public class Solution {
    public Node Flatten(Node head) {
        Node curr=head;
        while(curr!=null)
        {
            if(curr.child!=null)
            {
                Node fow=curr.next;
                curr.next=Flatten(curr.child);
                curr.next.prev=curr;
                curr.child=null;
                while(curr.next!=null)
                {
                    curr=curr.next;
                }
                if(fow!=null)
                {
                    curr.next=fow;
                    fow.prev=curr;
                }
            }
            curr=curr.next;
        }
        return head;
    }
}