/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 472ms
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int high=(l1.val+l2.val)/10;
        ListNode head = new ListNode((l1.val+l2.val)%10);
        ListNode p=head;
        l1=l1.next;l2=l2.next;
        while(l1!=null|| l2!=null){
            int a = l1==null?0:l1.val;
            int b = l2==null?0:l2.val;
            ListNode s=new ListNode((a+b+high)%10);
            high = (a+b+high)/10;
            p.next=s;
            p=s;
            l1 = l1==null?null:l1.next;
            l2 = l2==null?null:l2.next;
        }
        if(high!=0){
            ListNode s=new ListNode(high);
            p.next=s;
            p=s;
        }
        return head;
    }
}