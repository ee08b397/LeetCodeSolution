"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 48ms
"""
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        #(i,j)--->>(j,m-1-i)--->>(m-1-i,m-1-j)--->>(m-1-j,i)--->>(i,j)
        N= len(matrix)-1
        for i in range((N+1)/2):
            for j in range(i,N-i):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[N-j][i]
                matrix[N-j][i] = matrix[N-i][N-j]
                matrix[N-i][N-j] = matrix[j][N-i]
                matrix[j][N-i] = tmp;