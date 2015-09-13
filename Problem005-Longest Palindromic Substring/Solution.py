"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 1434ms
"""


class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        Max=1;Maxf=0;Maxe=0
        for i in range(0,len(s)):
            end = self.findOdd(s,i)
            if Max < (end-i)*2+1:
                Max = (end-i)*2+1
                Maxf = i+i-end
                Maxe = end
            end = self.findEven(s,i)
            if Max < (end-i)*2:
                Max = (end-i)*2
                Maxf = i+i+1-end
                Maxe = end
        return s[Maxf:Maxe+1]
    def findOdd(self,s,center):
        i=center-1;j=center+1
        while i>=0 and j<len(s):
            if s[i]!=s[j]:return j-1
            i=i-1;j=j+1
        return j-1
    def findEven(self,s,center):
        i=center;j=center+1
        while i>=0 and j<len(s):
            if s[i]!=s[j]:return j-1
            i=i-1;j=j+1
        return j-1