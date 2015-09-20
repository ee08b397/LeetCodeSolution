"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 68ms
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        p=head;len=0
        while p!=None:
            p=p.next
            len+=1
        if len==0 or k%len==0:return head
        k%=len
        p=head;s=head;
        while k>0 and p != None:
            k-=1
            p=p.next
        while p.next!=None:
            p=p.next
            s=s.next
        t = s.next
        s.next = None
        p.next = head
        return t