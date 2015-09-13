/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 330ms
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode s,p=new ListNode(0);
        p.next=head;head=p;s=p;
        int len=k;
        while(k-->0 && s!=null)s=s.next;
        while(s!=null){
            ListNode tmp,l=p.next,flag=s.next,tail=p.next;
            p.next=null;
            while(l!=flag){
                tmp=p.next;
                p.next=l;
                l=l.next;
                p.next.next=tmp;
            }
            tail.next=l;
            p=tail;
            s=tail;
            k=len;
            while(k-->0 && s!=null)s=s.next;
        }
        return head.next;
    }
}