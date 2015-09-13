/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 308ms
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode s,p=new ListNode(0);
        s=head;p.next=head;
        while(n>0 && s!=null){
            s=s.next;
            n--;
        }
        while(s!=null){
            s=s.next;
            p=p.next;
        }
        if(p.next==head){
            head=head.next;
        }else{
            p.next=p.next.next;
        }
        return head;
    }
}