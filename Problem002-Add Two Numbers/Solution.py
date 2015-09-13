"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 228ms
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        high = (l1.val+l2.val)/10;
        head = ListNode((l1.val+l2.val)%10)
        p=head;
        l1=l1.next
        l2=l2.next
        while l1!=None or l2!=None:
            a =0 if l1==None else l1.val
            b =0 if l2==None else l2.val
            s = ListNode((a+b+high)%10)
            s.next=None
            p.next=s
            p=s
            high = (a+b+high)/10
            l1 =None if l1==None else l1.next
            l2 =None if l2==None else l2.next
        if high!=0:
            s = ListNode(high)
            s.next=None
            p.next=s
        return head