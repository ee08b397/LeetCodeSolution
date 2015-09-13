"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 64ms
"""

class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        seq=['1'];top=1;
        while n-1>0:
            n-=1;index=0;bak=[]
            i=0
            while i<top:
                num=1
                while i+1<top and seq[i+1]==seq[i]:i+=1;num+=1
                bak.append(chr(num+ord('0')))
                bak.append(seq[i])
                i+=1
            seq=bak;top=len(bak)
        return ''.join(seq)