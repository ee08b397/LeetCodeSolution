"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 48ms
"""
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        returnColumn = [[0 for i in range(n)] for j in range(n)]
        i=0;x=0;y=-1;xmin=0;xmax=n-1;ymin=0;ymax=n-1
        while True:
            while y+1 <= ymax:y+=1;i+=1;returnColumn[x][y] = i
            xmin+=1
            if xmin > xmax:break
            while x+1 <= xmax:x+=1;i+=1;returnColumn[x][y] = i
            ymax-=1
            if ymax < ymin:break
            while y-1 >= ymin:y-=1;i+=1;returnColumn[x][y] = i
            xmax-=1
            if xmax < xmin:break
            while x-1 >= xmin:x-=1;i+=1;returnColumn[x][y] = i
            ymin+=1
            if ymin > ymax:break
        return returnColumn