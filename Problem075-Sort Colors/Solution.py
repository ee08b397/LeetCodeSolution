"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 56ms
"""
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i=0;k=len(nums)-1
        while i<=k and nums[i]==0:i+=1
        while k>=0 and nums[k]==2:k-=1
        j=i
        while j<=k:
            if nums[j]==0:
                nums[i]^=nums[j]
                nums[j]^=nums[i]
                nums[i]^=nums[j]
                j+=1;i+=1
            elif nums[j]==2:
                nums[k]^=nums[j]
                nums[j]^=nums[k]
                nums[k]^=nums[j]
                while j<=k and nums[k]==2:k-=1
            else:j+=1