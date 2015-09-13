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
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        if numRows==1:return s
        res=["" for i in range(numRows)]
        i=0;gap=numRows-2
        while i<len(s):
            j=0
            while i<len(s) and j<numRows:res[j]+=s[i];i+=1;j+=1
            j=gap
            while i<len(s) and j>0:res[j]+=s[i];i+=1;j-=1
        chs=''
        for i in range(numRows):
            chs+=res[i]
        return chs