"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 72ms
"""

class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        flag=1 if x>0 else -1
        x=x if x>0 else -x
        res=0
        while x>0:
            if res*10.0 + x%10 > 2147483647:return 0
            res = res*10+x%10
            x/=10
        return res*flag