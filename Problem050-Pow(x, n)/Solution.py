"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 44ms
"""
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        tmp =x;res = 1.0
        flag = False
        if n < 0:
            flag = True
            n = -n
        while n > 0:
            if n%2 ==1:
                res*=tmp
            tmp*=tmp
            n/=2
        if flag:return 1.0/res
        return res