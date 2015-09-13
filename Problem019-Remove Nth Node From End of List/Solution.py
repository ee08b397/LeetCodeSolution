"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 67ms
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} n
    # @return {ListNode}
    def removeNthFromEnd(self, head, n):
        s=head;p=ListNode(0)
        p.next=head
        while n>0 and s!=None:
            n-=1;s=s.next
        while s!=None:
            s=s.next;p=p.next
        if p.next==head:head=head.next
        else:p.next=p.next.next
        return head