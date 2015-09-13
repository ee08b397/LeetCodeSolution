"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 72ms
"""

class Solution:
    # @param {integer} dividend
    # @param {integer} divisor
    # @return {integer}
    def divide(self, dividend, divisor):
        flag=0
        if dividend>0 and divisor>0:flag=1
        elif dividend<0 and divisor<0:flag=1
        if dividend==0:return 0
        dividend=abs(dividend)
        divisor=abs(divisor)
        map=[0 for i in range(33)]
        times=[1 for i in range(33)]
        i=0
        map[0]=divisor;times[0]=1
        while map[i]<=dividend:
            i+=1
            map[i]=map[i-1]+map[i-1]
            times[i]=times[i-1]+times[i-1]
        j=i-1;sum=0
        while j>=0:
            while map[j]<=dividend:
                dividend-=map[j]
                sum+=times[j]
            j-=1
        sum = -sum if flag==0 else sum
        if sum>2147483647:return 2147483647
        return sum