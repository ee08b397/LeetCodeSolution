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
        ListNode l,r=head,pre=null;
        while(r!=null && ((pre!=null && pre.val==r.val)||(r.next!=null && r.next.val==r.val))){
            pre=r;
            r=r.next;
        }
        l=pre=head=r;
        if(r!=null)r=r.next;
        while(r!=null){
            if(!((pre!=null && pre.val==r.val)||(r.next!=null && r.next.val==r.val))){
                l.next=r;
                l=l.next;
            }
            pre=r;
            r=r.next;
            l.next=null;
        }
        return head;
    }
}