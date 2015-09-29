"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 80ms
"""
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        left=0
        right = 46340 if 46340<x else x
        while left < right:
            mid = left+(right-left)/2
            if mid*mid == x:return mid
            elif mid*mid > x: right = mid-1
            else:left = mid+1
        return left-1 if left*left>x else left