"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 140ms
"""
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        queens = [0 for i in range(n)]
        returnSize = [0]
        self.DFS(0,n,queens,returnSize)
        return returnSize[0]
    def DFS(self,step,n,queens,returnSize):
        if step == n:
            returnSize[0]+=1
            return
        for i in range(n):
            j=0
            while j<step:
                x = abs(step - j)
                y = abs(i - queens[j])
                if x==y or x==0 or y==0:break
                j+=1
            if j>=step:
                queens[step] = i
                self.DFS(step+1,n,queens,returnSize)