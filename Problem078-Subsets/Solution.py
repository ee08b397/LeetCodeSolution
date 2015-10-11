"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 60ms
"""
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        returnColumn = []
        tmp = [0 for i in range(len(nums))]
        nums = sorted(nums)
        for i in range(0,len(nums)+1):
            self.getSubset(returnColumn,tmp,0,-1,nums,i)
        return returnColumn
    def getSubset(self,returnColumn,tmp,step,index,nums,k):
        if step==k:
            returnColumn.append(tmp[:k])
            return
        for i in range(index+1,len(nums)-k+step+1):
            tmp[step]=nums[i]
            self.getSubset(returnColumn,tmp,step+1,i,nums,k)