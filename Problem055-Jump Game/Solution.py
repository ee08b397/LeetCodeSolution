"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 56ms
"""
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max=0
        for i in range(len(nums)):
            if i > max:return False
            max = max if max > i+nums[i] else i+nums[i]
        return max >= len(nums)-1