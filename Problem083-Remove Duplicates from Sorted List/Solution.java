/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 1ms
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
    public ListNode deleteDuplicates(ListNode head) {
        while(head!=null && head.next!=null && head.next.val==head.val)head=head.next;
        ListNode l=head,r=head;
        if(r!=null)r=r.next;
        while(r!=null){
            if(!(r.next!=null && r.next.val==r.val)){
                l.next=r;
                l=l.next;
            }
            r=r.next;
            l.next=null;
        }
        return head;
    }
}