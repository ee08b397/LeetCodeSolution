"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 72ms
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        while head!=None and head.next!=None and head.next.val==head.val:head=head.next
        l=r=head
        if r!=None:r=r.next
        while r!=None:
            if not(r.next!=None and r.next.val==r.val):
                l.next=r
                l=l.next
            r=r.next
            l.next=None
        return head