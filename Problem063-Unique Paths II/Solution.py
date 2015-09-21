"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 48ms
"""
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        for i in range(row):
            for j in range(col):
                if obstacleGrid[i][j]==1:obstacleGrid[i][j]=0
                elif i==0 and j==0:obstacleGrid[i][j]=1
                elif i==0:obstacleGrid[i][j]=obstacleGrid[i][j-1]
                elif j==0:obstacleGrid[i][j]=obstacleGrid[i-1][j]
                else:obstacleGrid[i][j]=obstacleGrid[i][j-1]+obstacleGrid[i-1][j]
        return obstacleGrid[row-1][col-1]