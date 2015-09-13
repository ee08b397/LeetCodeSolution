"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 127ms
"""

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def threeSumClosest(self, nums, target):
        length=len(nums);Min=2147483647
        nums.sort()
        for i in range(length-2):
            if i>0 and nums[i]==nums[i-1]:continue
            begin=i+1;end=length-1
            while begin<end:
                sum=nums[i]+nums[begin]+nums[end]
                if abs(sum-target)<abs(Min):Min=sum-target
                if sum==target:return target
                elif sum>target:end-=1
                else:begin+=1
        return Min+target