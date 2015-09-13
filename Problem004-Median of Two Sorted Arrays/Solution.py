"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 116ms
"""


class Solution:
    def findKth(self,a,b,k):
        len1=len(a)
        len2=len(b)
        if len1==0:return b[k-1]
        if len2==0:return a[k-1]
        if k==1:return min(a[0],b[0])
        mid1=min(k/2,len1)
        mid2=min(k/2,len2)
        if a[mid1-1] < b[mid2-1]:
            c=a[mid1:len1]
            return self.findKth(c,b,k-mid1)
        else:
            c=b[mid2:len2]
            return self.findKth(a,c,k-mid2)
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        len1=len(nums1)
        len2=len(nums2)
        if (len1+len2)%2 == 1:
            return self.findKth(nums1,nums2,(len1+len2+1)/2)
        else:
            return (self.findKth(nums1,nums2,(len1+len2+1)/2)+self.findKth(nums1,nums2,(len1+len2+1)/2+1))/2.0
    def min(self,a,b):
        return a if a<b else b