"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 68ms
"""
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        for i in range(row):
            for j in range(col):
                if i==0 and j==0:continue
                elif i==0:grid[i][j]+=grid[i][j-1]
                elif j==0:grid[i][j]+=grid[i-1][j]
                else:grid[i][j]+=min(grid[i][j-1],grid[i-1][j])
        return grid[row-1][col-1]