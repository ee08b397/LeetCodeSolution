/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queens(n);
        int* returnSize = (int*)malloc(sizeof(int));
        *returnSize = 0;
        DFS(0,n,queens,returnSize);
        return *returnSize;
    }
private:
    void DFS(int step,int n,vector<int>& queens,int* returnSize){
        if(step == n){
            returnSize[0]++;
            return;
        }
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<step;j++){
                int x = abs(step - j);
                int y = abs(i - queens[j]);
                if(x==y || x==0 || y==0)break;
            }
            if(j>=step){
                queens[step] = i;
                DFS(step+1,n,queens,returnSize);
            }
        }
    }
};
