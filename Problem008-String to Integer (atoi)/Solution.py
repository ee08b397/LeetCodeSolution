"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 80ms
"""

class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
        INT_MAX=2147483647;INT_MIN=-2147483648
        index=0
        while index<len(str) and str[index]==' ':index+=1
        flag=1
        if index<len(str) and str[index]=='-':
            index+=1
            flag=-1
        elif index<len(str) and str[index]=='+':
            index+=1
        res=0
        while index<len(str):
            if str[index]<'0' or str[index]>'9':return flag*res
            digit=ord(str[index])-ord('0')
            if flag==1 and res*10+digit>INT_MAX:return INT_MAX
            if flag==-1 and res*10+digit>-INT_MIN:return INT_MIN
            res=res*10+digit
            index+=1
        return flag*res
        