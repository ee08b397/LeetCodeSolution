"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 148ms
"""
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        row = len(matrix)
        col = 0 if row==0 else len(matrix[0])
        map = [0 for i in range(col)]
        stack = [0 for i in range(col)]
        top=0;max=0
        for i in range(row):
            for j in range(col):
                if matrix[i][j]=='1':map[j]+=1
                else:map[j]=0
                while top>0 and map[stack[top-1]]>map[j]:
                    index = stack[top-1]
                    top-=1
                    area = (j if top==0 else j-stack[top-1]-1)*map[index]
                    max = max if max>area else area
                stack[top]=j
                top+=1
            while top>0:
                index = stack[top-1]
                top-=1
                area = (col if top==0 else col-stack[top-1]-1)*map[index]
                max = max if max>area else area
        return max