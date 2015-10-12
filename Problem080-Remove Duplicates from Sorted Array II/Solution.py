"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 140ms
"""
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur=0 if len(nums)==0 else nums[0]+1
        num=0;j=0
        for i in range(len(nums)):
            if cur!=nums[i]:
                cur=nums[i]
                num=1
            else:num+=1
            if num<=2:
                nums[j]=nums[i]
                j+=1
        return j