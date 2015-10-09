"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 44ms
"""
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        row=len(matrix)
        col=0 if row==0 else len(matrix[0])
        start=0;end=row*col-1
        while start<=end:
            mid=start+(end-start)/2
            i=mid/col;j=mid%col
            if target==matrix[i][j]:return True
            elif target>matrix[i][j]:start=mid+1;
            else:end=mid-1
        return False