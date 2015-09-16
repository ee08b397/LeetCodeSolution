/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,tmp,N=matrixRowSize-1;
    for(i=0;i<matrixRowSize/2;i++){
        for(j=i;j<matrixColSize-1-i;j++){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[N-j][i];
            matrix[N-j][i] = matrix[N-i][N-j];
            matrix[N-i][N-j] = matrix[j][N-i];
            matrix[j][N-i] = tmp;
        }
    }
}
