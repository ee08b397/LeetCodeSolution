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
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def mergeTwoLists(self, l1, l2):
        if l1==None:return l2
        if l2==None:return l1
        p=l1
        if l1.val > l2.val:
            p=l2;l2=l2.next
        else:p=l1;l1=l1.next
        head=p
        while l1!=None and l2!=None:
            if l1.val > l2.val:
                p.next=l2;l2=l2.next
            else:p.next=l1;l1=l1.next
            p=p.next
        if l1==None:p.next=l2
        else:p.next=l1
        return head