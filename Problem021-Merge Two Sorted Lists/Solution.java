/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 344ms
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head,p;
        if(l1==null)return l2;
        if(l2==null)return l1;
        if(l1.val > l2.val){
            p=l2;l2=l2.next;
        }else{
            p=l1;l1=l1.next;
        }
        head=p;
        while(l1!=null && l2!=null){
            if(l1.val > l2.val){
                p.next=l2;l2=l2.next;
            }else{
                p.next=l1;l1=l1.next;
            }
            p=p.next;
        }
        if(l1==null)p.next=l2;
        else p.next=l1;
        return head;
    }
}