"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 58ms
"""

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def searchRange(self, nums, target):
        length=len(nums);l=0;r=length-1;mid=0
        res=[-1,-1]
        while l<=r:
            mid=(l+r)>>1;
            if nums[mid]==target:break
            elif nums[mid]>target:r=mid-1
            else:l=mid+1
        if l<=r:
            l=mid-1
            while l>=0 and nums[l]==nums[mid]:l-=1
            r=mid+1
            while r<length and nums[r]==nums[mid]:r+=1
            res[0]=l+1;res[1]=r-1
        return res