"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 176ms
"""
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        returnColumn = []
        prefix = [0 for i in range(len(nums))]
        self.DFS(nums,0,prefix,0,returnColumn)
        return returnColumn
    def DFS(self,nums,step,prefix,prefixSize,returnColumn):
        if step >= len(nums):return
        if step == len(nums)-1:
            prefix[step] = nums[step]
            newColumn = prefix[0:]
            returnColumn.append(newColumn)
            return
        for i in range(step,len(nums)):
            if i != step:
                nums[i] = nums[i]^nums[step]
                nums[step] = nums[i]^nums[step]
                nums[i] = nums[i]^nums[step]
            prefix[prefixSize] = nums[step]
            self.DFS(nums,step+1,prefix,prefixSize+1,returnColumn)
            if i!=step:
                nums[i] = nums[i]^nums[step]
                nums[step] = nums[i]^nums[step]
                nums[i] = nums[i]^nums[step]