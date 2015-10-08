"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 80ms
"""
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        length = len(path)
        newpath=['' for i in range(length)]
        top=0;i=0
        while i<length:
            while i<length and path[i]=='/':i+=1
            if i>=length:break
            if path[i]=='.' and (i+1>=length or path[i+1]=='/'):i+=1
            elif path[i]=='.' and path[i+1]=='.' and (i+2>=length or path[i+2]=='/'):
                i+=2
                top=top-1 if top>0 else 0
                while top>0 and newpath[top]!='/':top-=1
            else:
                newpath[top]='/'
                top+=1
                while i<length and path[i]!='/':
                    newpath[top]=path[i]
                    top+=1
                    i+=1
        if top==0:return "/"
        else:return ''.join(newpath[:top])