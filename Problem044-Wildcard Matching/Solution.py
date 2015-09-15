"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 120ms
"""
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i=0;j=0;p_pos=-1;s_pos=-1
        while i < len(s):
            if j < len(p):
                if p[j]=='?' or p[j] == s[i]:
                    i+=1;j+=1;continue
                if p[j]=='*':
                    j+=1
                    p_pos = j
                    s_pos = i
                    continue
            if s_pos != -1:
                s_pos +=1
                i = s_pos
                j = p_pos
                continue
            return False
        while j < len(p) and p[j] == '*':j+=1
        return j>=len(p)