"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 68ms
"""
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        return self.find(nums,0,len(nums)-1,target)
    def find(self,nums,left,right,target):
        if left>right:return False
        mid=left+(right-left)/2
        if nums[mid]==target:return True
        elif nums[mid]>target:
            if nums[mid]<nums[0]:return self.find(nums,left,mid-1,target)
            else:return self.find(nums,left,mid-1,target) or self.find(nums,mid+1,right,target)
        else:
            if nums[mid]>nums[0]:return self.find(nums,mid+1,right,target)
            else: return self.find(nums,left,mid-1,target) or self.find(nums,mid+1,right,target)
        