"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 104ms
"""

class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        if len(board)!=9 or len(board[0])!=9:return False
        for i in range(9):
            map=[0 for k in range(10)]
            for j in range(9):
                if board[i][j]=='.':continue
                if board[i][j]<'0' or board[i][j]>'9':return False
                num = ord(board[i][j])-ord('0')
                if map[num]==1:return False
                map[num]=1
        for j in range(9):
            map=[0 for k in range(10)]
            for i in range(9):
                if board[i][j]=='.':continue
                num = ord(board[i][j])-ord('0')
                if map[num]==1:return False
                map[num]=1
        for i in range(0,9,3):
            for j in range(0,9,3):
                map=[0 for k in range(10)]
                for k in range(i,i+3):
                    for l in range(j,j+3):
                        if board[k][l]=='.':continue
                        num = ord(board[k][l])-ord('0')
                        if map[num]==1:return False
                        map[num]=1
        return True