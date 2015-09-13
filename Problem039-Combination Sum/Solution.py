"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 176ms
"""

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates = sorted(candidates)
        returnColumn = []
        prefix = [0 for i in range(10000)]
        self.DFS(candidates,0,target,prefix,0,returnColumn)
        return returnColumn
        
    def DFS(self,candidates,step,target,prefix,prefixSize,returnColumn):
        if step > len(candidates):
            return
        if target <= 0:
            return
        for i in range(step,len(candidates)):
            if candidates[i] > target:
                break
            elif candidates[i] == target:
                newColumn = prefix[:prefixSize]
                newColumn.append(candidates[i])
                returnColumn.append(newColumn)
                return
            else:
                prefix[prefixSize] = candidates[i]
                self.DFS(candidates,i,target - candidates[i],prefix,prefixSize+1,returnColumn)