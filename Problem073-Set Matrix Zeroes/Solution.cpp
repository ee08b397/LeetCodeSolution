/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 88ms
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R=0,C=0;
        int row = matrix.size();
        int col = row==0?0:matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    if(i==0)R=1;
                    if(j==0)C=1;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<col;j++)matrix[i][j]=0;
            }
        }
        for(int j=1;j<col;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<row;i++)matrix[i][j]=0;
            }
        }
        if(R==1){
            for(int j=1;j<col;j++)matrix[0][j]=0;
        }
        if(C==1){
            for(int i=1;i<row;i++)matrix[i][0]=0;
        }
    }
};
