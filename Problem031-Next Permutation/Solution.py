"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 136ms
"""

class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def nextPermutation(self, nums):
        length=len(nums);i=length-1
        while i>0 and nums[i]<=nums[i-1]:i-=1
        if i>0:
            j=length-1
            while nums[j]<=nums[i-1]:j-=1
            tmp=nums[j]
            nums[j]=nums[i-1]
            nums[i-1]=tmp
        j=length-1
        while i<j:
            tmp=nums[i]
            nums[i]=nums[j]
            nums[j]=tmp
            i+=1;j-=1