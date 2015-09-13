"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 64ms
"""

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        index=0;length=len(nums)
        while index<length-1 and nums[index]<nums[index+1]:index+=1
        if target>=nums[0] and target<=nums[index]:return self.find(nums,0,index,target)
        else:return self.find(nums,index+1,length-1,target)
    def find(self,nums,start,end,target):
        if start>end:return -1;
        l=start;r=end
        while l<=r:
            mid=(l+r)/2
            if nums[mid]==target:return mid
            elif target>nums[mid]:l=mid+1
            else:r=mid-1
        return -1