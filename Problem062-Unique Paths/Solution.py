"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 40ms
"""
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                if i==0 and j==0:dp[i][j]=1
                elif i==0:dp[i][j]=dp[i][j-1]
                elif j==0:dp[i][j]=dp[i-1][j]
                else:dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]