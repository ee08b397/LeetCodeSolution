"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 144ms
"""
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates = sorted(candidates)
        returnColumn=[]
        prefix = [0 for i in range(10000)]
        self.DFS(candidates,0,target,prefix,0,returnColumn)
        return returnColumn
        
    def DFS(self,candidates,step,target,prefix,prefixSize,returnColumn):
        if step >= len(candidates):return
        if target <= 0:return
        for i in range(step,len(candidates)):
            if i>step and candidates[i] == candidates[i-1]:continue
            if target < candidates[i]:break
            elif target == candidates[i]:
                prefix[prefixSize] = candidates[i]
                newColumn = prefix[:prefixSize+1]
                returnColumn.append(newColumn)
                break
            else:
                prefix[prefixSize] = candidates[i]
                self.DFS(candidates,i+1,target - candidates[i],prefix,prefixSize+1,returnColumn)