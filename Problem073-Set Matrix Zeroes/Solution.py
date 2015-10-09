"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 188ms
"""
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        row=len(matrix)
        col=0 if row==0 else len(matrix[0])
        R=0;C=0
        for i in range(row):
            for j in range(col):
                if matrix[i][j]==0:
                    if i==0:R=1
                    if j==0:C=1
                    matrix[i][0]=0
                    matrix[0][j]=0
        for i in range(1,row):
            if matrix[i][0]==0:
                for j in range(1,col):matrix[i][j]=0
        for j in range(1,col):
            if matrix[0][j]==0:
                for i in range(1,row):matrix[i][j]=0
        if R==1:
            for j in range(1,col):matrix[0][j]=0
        if C==1:
            for i in range(1,row):matrix[i][0]=0