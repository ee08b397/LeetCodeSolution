/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> returnColumn;
        char** column = (char**)malloc(sizeof(char*)*n);
        int* queens = (int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            column[i] = (char*)malloc(sizeof(char)*(n+1));
            queens[i] = 0;
            for(int j=0;j<n;j++){
                column[i][j] = '.';
            }
            column[i][n]=0;
        }
        DFS(column,0,n,queens,returnColumn);
        return returnColumn;
    }
private:
    void DFS(char** column,int step,int n,int* queens,vector<vector<string>>& returnColumn){
        if(step == n){
            vector<string> newColumn;
            for(int i=0;i<n;i++){
                string col(column[i]);
                newColumn.push_back(col);
            }
            returnColumn.push_back(newColumn);
            return;
        }
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<step;j++){
                int x = abs(j - step);
                int y = abs(i - queens[j]);
                if(x == y)break;
                if(x==0 || y==0)break;
            }
            if(j>=step){
                queens[step] = i;
                column[step][i] = 'Q';
                DFS(column,step+1,n,queens,returnColumn);
                column[step][i] = '.';
            }
        }
    }
};
