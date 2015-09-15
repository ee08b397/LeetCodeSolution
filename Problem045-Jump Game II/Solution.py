"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 80ms
"""
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:return 0
        jumps = [0 for i in range(len(nums))]
        pos=0
        for i in range(len(nums)):
            if i+nums[i] > pos:
                if i+nums[i] >= len(nums)-1:return jumps[i]+1
                for j in range(pos+1,i+nums[i]+1):
                    jumps[j] = jumps[i]+1
                pos = i+nums[i]
        return jumps[len(nums)-1]