"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 84ms
"""
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        returnColumn=[]
        tmp=[0 for i in range(k)]
        self.getCombine(returnColumn,tmp,0,n,k)
        return returnColumn
    def getCombine(self,returnColumn,tmp,step,n,k):
        if step==k:
            returnColumn.append(tmp[0:])
            return
        for i in range(1 if step==0 else tmp[step-1]+1,n+1):
            tmp[step]=i
            self.getCombine(returnColumn,tmp,step+1,n,k)