"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 76ms
"""
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        len1=len(a);len2=len(b);top=0
        lens = len1+2 if len1>len2 else len2+2
        str = [0 for i in range(lens)]
        i=len1-1;j=len2-1
        while True:
            if i<0 and j<0:break
            elif i<0:str[top]+=ord(b[j])-ord('0');top+=1;j-=1
            elif j<0:str[top]+=ord(a[i])-ord('0');top+=1;i-=1
            else:str[top]+=ord(b[j])-ord('0')+ord(a[i])-ord('0');top+=1;i-=1;j-=1
        i=0
        while i<lens-1:
            str[i+1]+=str[i]/2
            str[i]%=2
            i+=1
        while i>0 and str[i]==0:i-=1
        ret = []
        for i in range(i+1):ret.append(chr(str[i]+ord('0')))
        j=i;i=0;
        while i<j:
            tmp = ret[i]
            ret[i]=ret[j]
            ret[j]=tmp
            i+=1;j-=1
        return "".join(ret)