"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 40ms
"""
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        a=[0 for i in range(50)]
        a[1]=1
        for i in range(2,n+2):
            a[i]=a[i-1]+a[i-2]
        return a[n+1]