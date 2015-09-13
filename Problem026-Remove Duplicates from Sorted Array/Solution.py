"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 94ms
"""

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        size=0;length=len(nums)
        for i in range(length):
            if i==0 or nums[i]!=nums[i-1]:nums[size]=nums[i];size+=1
        return size