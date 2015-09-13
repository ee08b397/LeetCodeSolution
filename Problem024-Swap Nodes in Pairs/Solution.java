/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 272ms
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
    public ListNode swapPairs(ListNode head) {
        ListNode p=new ListNode(0),s;
        p.next=head;
        head=p;
        while(p.next!=null && p.next.next!=null){
            s=p.next.next;
            p.next.next=s.next;
            s.next=p.next;
            p.next=s;
            p=s.next;
        }
        return head.next;
    }
}