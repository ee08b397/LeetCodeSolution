"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 636ms
"""

class Solution:
    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solveSudoku(self, board):
        self.SudoKu(board,0,0)
    def SudoKu(self,board,i,j):
        if i==8 and j==9:return True
        if j==9:i+=1;j=0
        if board[i][j]!='.':
            if self.SudoKu(board,i,j+1):return True
        else:
            map=self.getValidNum(board,i,j)
            for k in range(1,10):
                if map[k]==0:
                    board[i][j]=chr(k+ord('0'))
                    if self.SudoKu(board,i,j+1):return True
                    board[i][j]='.'
        return False
    def getValidNum(self,board,i,j):
        map=[0 for k in range(10)]
        for k in range(9):
            if board[i][k]!='.':map[ord(board[i][k])-ord('0')]=1
            if board[k][j]!='.':map[ord(board[k][j])-ord('0')]=1
        for k in range(3*(i/3),3*(i/3)+3):
            for l in range(3*(j/3),3*(j/3)+3):
                if board[k][l]!='.':map[ord(board[k][l])-ord('0')]=1
        return map