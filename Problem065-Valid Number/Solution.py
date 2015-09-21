"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 108ms
"""
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        length = len(s)
        l=0
        while l<length and s[l]==' ':l+=1
        j=l;ass=False
        for i in range(l,length):
            if s[i]=='-' or s[i]=='+':
                if i!=j:return False
            elif s[i]=='.':
                return self.testDot(s[i+1:],length-i-1,ass)
            elif s[i]=='e':
                return self.testE(s[i+1:],length-i-1) and ass
            elif s[i]==' ':
                while i<length and s[i]==' ':i+=1
                return i>=length and ass
            elif not (s[i]>='0' and s[i]<='9'):
                return False
            else:ass=True
        return ass
    def testDot(self,s,length,ass):
        for i in range(length):
            if s[i]=='e':
                return self.testE(s[i+1:],length-i-1) and ass
            elif s[i]==' ':
                while i<length and s[i]==' ':i+=1
                return i>=length and ass
            elif not (s[i]>='0' and s[i]<='9'):
                return False
            else:ass=True
        return ass
    def testE(self,s,length):
        ass=False
        for i in range(length):
            if s[i]=='-' or s[i]=='+':
                if i!=0:return False
            elif s[i]==' ':
                while i<length and s[i]==' ':i+=1
                return i>=length and ass
            elif not (s[i]>='0' and s[i]<='9'):
                return False
            else:ass=True
        return ass