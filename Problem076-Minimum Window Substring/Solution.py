"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 164ms
"""
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        hash = [-1 for i in range(128)]
        hash1= [0 for i in range(128)]
        hash2= [0 for i in range(128)]
        length = len(t)
        for i in range(length):
            k=ord(t[i])
            hash[k]=0
            hash1[k]+=1
            hash2[k]+=1
        start=0;minstart=0;minend=2147483647
        for i in range(len(s)):
            k=ord(s[i])
            if hash[k]!=-1:
                if hash1[k]>0:
                    hash1[k]-=1
                    length-=1
                hash[k]+=1
                k=ord(s[start])
                while hash[k] > hash2[k] or hash[k]==-1:
                    if hash[k] > hash2[k]:hash[k]-=1
                    start+=1
                    k=ord(s[start])
                if length==0:
                    end=i
                    if minend-minstart > end-start:
                        minstart=start
                        minend=end
        if minend==2147483647:return ""
        return s[minstart:minend+1]