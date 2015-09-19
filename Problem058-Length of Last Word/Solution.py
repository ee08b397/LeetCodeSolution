"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 52ms
"""
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        sum=0;length=0;
        for i in range(len(s)):
            if s[i]==' ':
                if sum!=0:length=sum
                sum=0
            else:sum+=1
        if sum!=0:length=sum
        return length