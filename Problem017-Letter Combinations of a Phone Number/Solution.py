"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 69ms
"""

class Solution:
    map=[" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    length=0;res=[]
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        self.length=len(digits)
        self.res=[]
        if self.length==0:return self.res;
        tmp=['' for i in range(self.length)]
        self.getLetterCom(0,digits,tmp)
        return self.res
    def getLetterCom(self,index,digits,tmp):
        if index>=self.length:
            letters=''.join(tmp)
            self.res.append(letters)
            return
        digit=ord(digits[index])-ord('0')
        for i in range(len(self.map[digit])):
            tmp[index]=self.map[digit][i]
            self.getLetterCom(index+1,digits,tmp)