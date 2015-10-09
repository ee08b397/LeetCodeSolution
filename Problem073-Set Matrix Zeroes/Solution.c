/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 44ms
 */
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,R=0,C=0;
    for(i=0;i<matrixRowSize;i++){
        for(j=0;j<matrixColSize;j++){
            if(matrix[i][j]==0){
                if(i==0)R=1;
                if(j==0)C=1;
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(i=1;i<matrixRowSize;i++){
        if(matrix[i][0]==0){
            for(j=0;j<matrixColSize;j++)matrix[i][j]=0;
        }
    }
    for(j=1;j<matrixColSize;j++){
        if(matrix[0][j]==0){
            for(i=0;i<matrixRowSize;i++)matrix[i][j]=0;
        }
    }
    if(R==1){
        for(j=0;j<matrixColSize;j++)matrix[0][j]=0;
    }
    if(C==1){
        for(i=0;i<matrixRowSize;i++)matrix[i][0]=0;
    }
}
