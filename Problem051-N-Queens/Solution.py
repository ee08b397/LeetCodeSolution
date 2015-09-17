"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 176ms
"""
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        returnColumn = []
        column = [['.' for i in range(n)] for j in range(n)]
        queens = [0 for i in range(n)]
        self.DFS(column,0,n,queens,returnColumn)
        return returnColumn
    def DFS(self,column,step,n,queens,returnColumn):
        if step == n:
            newColumn = []
            for i in range(n):
                newColumn.append("".join(column[i]))
            returnColumn.append(newColumn)
            return
        for i in range(n):
            j=0
            while j<step:
                x = abs(step - j)
                y = abs(i - queens[j])
                if x==y:break
                if x==0 or y==0:break
                j+=1
            if j>=step:
                queens[step] = i
                column[step][i] = 'Q'
                self.DFS(column,step+1,n,queens,returnColumn)
                column[step][i] = '.'