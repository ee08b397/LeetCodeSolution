"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 268ms
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} k
    # @return {ListNode}
    def reverseKGroup(self, head, k):
        p=ListNode(0)
        p.next=head;head=p;s=p
        len=k
        while k>0 and s!=None:k-=1;s=s.next
        while s!=None:
            flag=s.next;tail=p.next;l=p.next
            while l!=flag:
                tmp=p.next
                p.next=l
                l=l.next
                p.next.next=tmp
            tail.next=l
            p=tail;s=tail
            k=len
            while k>0 and s!=None:k-=1;s=s.next
        return head.next