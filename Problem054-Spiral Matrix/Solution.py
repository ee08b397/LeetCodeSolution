"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 40ms
"""
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res = []
        if len(matrix)==0 or len(matrix[0])==0:return res
        x=0;y=-1;xmin=0;xmax=len(matrix)-1;ymin=0;ymax=len(matrix[0])-1
        while True:
            while y+1 <= ymax:
                y+=1
                res.append(matrix[x][y])
            xmin+=1
            if xmin > xmax:break
            while x+1 <= xmax:
                x+=1
                res.append(matrix[x][y])
            ymax-=1
            if ymax < ymin:break
            while y-1 >= ymin:
                y-=1
                res.append(matrix[x][y])
            xmax-=1
            if xmax < xmin:break
            while x-1 >= xmin:
                x-=1
                res.append(matrix[x][y])
            ymin+=1
            if ymin > ymax:break
        return ress