"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 120ms
"""


class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        left=0
        Max=0
        hash={}
        for i in range(len(s)):
            ch = s[i]
            if hash.has_key(ch) and hash[ch]>=left:
                left=hash[ch]+1
            hash[ch]=i
            Max= Max if Max>i-left+1 else i-left+1
        return Max
                
            