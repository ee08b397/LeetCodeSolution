"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 320ms
"""
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        len1=len(word1);len2=len(word2)
        if len1==0 or len2==0:return len1+len2
        dp = [[0 for i in range(len2)] for j in range(len1)]
        for i in range(len1):
            for j in range(len2):
                if word1[i]==word2[j]:
                    if i==0 and j==0:dp[i][j]=0
                    elif i==0:dp[i][j]=j
                    elif j==0:dp[i][j]=i
                    else:dp[i][j]=dp[i-1][j-1]
                else:
                    if i==0 and j==0:dp[i][j]=1
                    elif i==0:dp[i][j]=dp[i][j-1]+1
                    elif j==0:dp[i][j]=dp[i-1][j]+1
                    else:dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1
        return dp[len1-1][len2-1]