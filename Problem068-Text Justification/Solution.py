"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 40ms
"""
class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        returnWords=[]
        i=0
        while i<len(words):
            sum=-1
            j=i
            while i<len(words) and sum+1+len(words[i])<=maxWidth:
                sum+=1+len(words[i])
                i+=1
            tmp=words[j]
            if i>=len(words) or i-j==1:
                for k in range(j+1,i):
                    tmp+=" "+words[k]
                tmp+=" "*(maxWidth-sum)
            else:
                m = (maxWidth-sum)/(i-j-1)
                n = (maxWidth-sum)%(i-j-1)
                for k in range(j+1,i):
                    tmp+=" "*(m+1)
                    if n>0:
                        n-=1
                        tmp+=" "
                    tmp+=words[k]
            returnWords.append(tmp)
        return returnWords