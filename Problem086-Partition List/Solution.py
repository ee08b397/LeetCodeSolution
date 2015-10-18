"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 56ms
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        node = ListNode(0)
        node.next = head
        l= node
        while l.next!=None and l.next.val < x: l = l.next
        r = l
        while r.next!=None:
            if r.next.val < x:
                tmp = r.next
                r.next = tmp.next
                tmp.next = l.next
                l.next = tmp
                l = l.next
            else: r = r.next
        return node.next