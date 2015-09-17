"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 56ms
"""
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max=-2147483648;sum=0
        for i in range(len(nums)):
            sum+=nums[i]
            max=max if max>sum else sum
            if sum<0:sum=0
        return max