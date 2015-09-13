"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 546ms
"""

class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if x<0:return False
        str=[]
        while x>0:
            str.append(x%10)
            x/=10
        i=0;j=len(str)-1
        while i<j:
            if str[i]!=str[j]:return False
            i+=1;j-=1;
        return True