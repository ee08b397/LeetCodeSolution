"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 81ms
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def swapPairs(self, head):
        p=ListNode(0)
        p.next=head;head=p
        while p.next!=None and p.next.next!=None:
            s=p.next.next
            p.next.next=s.next
            s.next=p.next
            p.next=s
            p=s.next
        return head.next