"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 564ms
"""
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        row = len(board)
        col = 0 if row==0 else len(board[0])
        for i in range(row):
            for j in range(col):
                if board[i][j]==word[0]:
                    board[i][j]=0
                    if self.wordSearch(board,word[1:],i,j):return True
                    board[i][j]=word[0]
        return False
    def wordSearch(self,board,word,x,y):
        row = len(board)
        col = 0 if row==0 else len(board[0])
        if len(word)==0:return True
        step=[[-1,0],[0,1],[1,0],[0,-1]]
        for i in range(4):
            sx=x+step[i][0]
            sy=y+step[i][1]
            if sx<0 or sx>=row:continue
            if sy<0 or sy>=col:continue
            if board[sx][sy]==word[0]:
                board[sx][sy]=0
                if self.wordSearch(board,word[1:],sx,sy):return True
                board[sx][sy]=word[0]
        return False