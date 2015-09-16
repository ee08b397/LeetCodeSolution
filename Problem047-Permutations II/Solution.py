"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 156ms
"""
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        returnColumn = []
        prefix = [0 for i in range(len(nums))]
        visited = [0 for i in range(len(nums))]
        self.DFS(nums,0,prefix,visited,returnColumn)
        return returnColumn
    def DFS(self,nums,step,prefix,visited,returnColumn):
        if step >= len(nums):
            newColumn = prefix[0:]
            returnColumn.append(newColumn)
            return
        for i in range(len(nums)):
            if visited[i]==1:continue
            if i>0 and nums[i]==nums[i-1] and visited[i-1]==0:continue
            prefix[step] = nums[i]
            visited[i] = 1
            self.DFS(nums,step+1,prefix,visited,returnColumn)
            visited[i] = 0