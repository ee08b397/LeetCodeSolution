"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 196ms
"""
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        len1=len(num1);len2=len(num2)
        mul = [0 for i in range(len1+len2+1)]
        for i in range(len1):
            for j in range(len2):
                mul[(len1-1-i)+(len2-1-j)] += (ord(num1[i])-ord('0')) * (ord(num2[j])-ord('0'))
        i=0
        while i<len1+len2:
            mul[i+1] += mul[i]/10;
            mul[i] = mul[i]%10
            i+=1
        i=len1+len2-1
        while i>=0 and mul[i]==0:
            i-=1
        if i==-1:
            return "0"
        multi =['' for j in range(i+1)]
        for j in range(i+1):
            multi[i-j] = chr(ord('0')+mul[j])
        return "".join(multi)