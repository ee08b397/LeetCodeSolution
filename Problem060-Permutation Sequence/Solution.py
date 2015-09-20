"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 40ms
"""
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        per = [1 for i in range(n)]
        for i in range(1,n):
            per[i] = per[i-1]*i
        str = [chr(ord('0')+i) for i in range(1,n+1)]
        i=0
        while i<n:
            j=i
            while j<n and k > per[n-i-1]:
                k-=per[n-i-1]
                j+=1
            tmp = str[j]
            while j>i:
                str[j] = str[j-1]
                j-=1
            str[j] = tmp
            i+=1
        return "".join(str)