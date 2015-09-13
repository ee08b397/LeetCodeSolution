"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 42ms
"""

class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        length=len(s);top=-1;index=0
        stack=[' ' for i in range(length)]
        while index < length:
            if s[index]==')':
                if top>=0 and stack[top]=='(':top-=1;
                else:return False
            elif s[index]=='}':
                if top>=0 and stack[top]=='{':top-=1;
                else:return False
            elif s[index]==']':
                if top>=0 and stack[top]=='[':top-=1;
                else:return False
            else:top+=1;stack[top]=s[index]
            index+=1
        return top==-1