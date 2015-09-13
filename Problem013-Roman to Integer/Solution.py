"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 138ms
"""

class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        index=0;num=0;temp=0
        while index<len(s):
            c = s[index];index+=1
            if c=='I':num+=1;temp=1
            elif c=='V':num+=3 if temp==1 else 5
            elif c=='X':num+=8 if temp==1 else 10;temp=10
            elif c=='L':num+=30 if temp==10 else 50
            elif c=='C':num+=80 if temp==10 else 100;temp=100
            elif c=='D':num+=300 if temp==100 else 500
            elif c=='M':num+=800 if temp==100 else 1000
        return num