"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 48ms
"""
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        length = len(digits)
        digits[length-1]+=1
        for i in range(length-1,0,-1):
            if digits[i]>9:
                digits[i-1]+=digits[i]/10;
                digits[i]%=10
        if digits[0] > 9:
            newDigits = [0 for i in range(length+1)]
            newDigits[0]=digits[0]/10
            newDigits[1]=digits[0]%10
            for i in range(2,length+1):
                newDigits[i]=digits[i-1]
            return newDigits
        return digits