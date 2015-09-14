"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 52ms
"""
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        while i<len(nums):
            if nums[i]>0 and nums[i] <= len(nums):
                if nums[nums[i]-1] == nums[i]:
                    i+=1
                    continue
                tmp = nums[nums[i]-1]
                nums[nums[i]-1] = nums[i]
                nums[i] = tmp
                i-=1
            i+=1
        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1
        return len(nums)+1