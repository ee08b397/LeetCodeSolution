"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 706ms
"""

class Solution:
    # @param {string} s
    # @param {string[]} words
    # @return {integer[]}
    def findSubstring(self, s, words):
        lens=len(s);lenw=len(words[0]);length=len(words)
        map={};res=[]
        for i in range(length):
            if words[i] in map:map[words[i]]+=1
            else:map[words[i]]=1
            if not words[i] in s:return res
        for i in range(lens-lenw*length+1):
            tmp={};j=0;flag=True
            for j in range(length):
                pos=i+j*lenw
                sub=s[pos:pos+lenw]
                if sub in map:
                    num=0
                    if sub in tmp:num=tmp[sub]
                    if map[sub] < num+1:flag=False;break
                    tmp[sub]=num+1
                else:flag=False;break
            if flag:res.append(i)
        return res