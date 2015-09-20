/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 284ms
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
    public ListNode rotateRight(ListNode head, int k) {
        ListNode p,s,t;
        p=head;
        int len=0;
        while(p!=null){
            p=p.next;
            len++;
        }
        if(len==0 || k%len==0)return head;
        k%=len;
        p=head;s=head;
        while(k-->0 && p!=null)p=p.next;
        while(p.next != null){
            s=s.next;
            p=p.next;
        }
        t=s.next;
        s.next=null;
        p.next=head;
        return t;
    }
}