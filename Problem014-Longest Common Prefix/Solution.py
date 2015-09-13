"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 66ms
"""

class Solution:
    # @param {string[]} strs
    # @return {string}
    def longestCommonPrefix(self, strs):
        if len(strs)==0:return ""
        str=strs[0]
        Min=len(str)
        for i in range(1,len(strs)):
            j=0;p=strs[i]
            while j<Min and j<len(p) and p[j]==str[j]:j+=1
            Min = Min if Min<j else j
        return str[:Min]