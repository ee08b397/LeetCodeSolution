"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 60ms
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
        r=head;pre=None
        while r!=None and ((pre!=None and pre.val==r.val)or(r.next!=None and r.next.val==r.val)):
            pre=r;r=r.next
        l=pre=head=r;
        if r!=None:r=r.next
        while r!=None:
            if not((pre!=None and pre.val==r.val)or(r.next!=None and r.next.val==r.val)):
                l.next=r
                l=l.next
            pre=r
            r=r.next
            l.next=None
        return head