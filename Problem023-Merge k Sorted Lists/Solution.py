"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 618ms
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    tree=[]
    # @param {ListNode[]} lists
    # @return {ListNode}
    def mergeKLists(self, lists):
        length=len(lists)
        if length==0:return None
        elif length==1:return lists[0]
        self.tree=[0 for i in range(length)]
        self.initTree(lists,length)
        if lists[self.tree[1]]==None:return None
        p=lists[self.tree[1]]
        lists[self.tree[1]]=lists[self.tree[1]].next
        head=p
        self.adjustToRoot(lists,(self.tree[1]+length)/2,length)
        while lists[self.tree[1]]!=None:
            p.next=lists[self.tree[1]]
            lists[self.tree[1]]=lists[self.tree[1]].next
            p=p.next
            self.adjustToRoot(lists,(self.tree[1]+length)/2,length)
        return head
    def adjustToRoot(self,lists,tar,length):
        while tar>0:
            self.adjustTree(lists,tar,length)
            tar=tar/2
    def initTree(self,lists,length):
        for i in range(length-1,0,-1):
            self.adjustTree(lists,i,length)
    def adjustTree(self,lists,i,length):
        l=0;r=0
        if i+i < length:l=self.tree[i+i]
        else:l=i+i-length
        if i+i+1 < length:r=self.tree[i+i+1]
        else:r=i+i+1-length
        if lists[l]==None:self.tree[i]=r
        elif lists[r]==None:self.tree[i]=l
        else:self.tree[i]=r if lists[l].val > lists[r].val else l